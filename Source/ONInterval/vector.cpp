/************************************************************************
*  Vector.C (Implementation of type VECTOR)
*
*  Version:                     1.18
*  Date:                        10/15/93
*  Author:                      O. Knueppel
*************************************************************************/

static char sccs_id[] = "@(#)Vector.C 1.18 93/10/15 OK";

//#include "stdafx.h"
#include "vector.h"
#include "realop.h"
#include <memory.h>
#include <stdlib.h>
#include <math.h>

VECTOR::VECTOR(VECTOR & x)
{
#ifdef __DONTCOPY__
  IsTemporary = 1;
  nElements = x.nElements;
  if (x.IsTemporary) {
    theElements = x.theElements;
    x.theElements = NULL;
    x.nElements = 0;
  }
  else {
    theElements = new REAL[nElements];
    CheckMemory (theElements);
    memcpy (theElements, x.theElements, nElements * sizeof (REAL));
  }
#else
  nElements = x.nElements;
  theElements = new REAL[nElements];
  CheckMemory (theElements);
  memcpy (theElements, x.theElements, nElements * sizeof (REAL));
#endif
}

VECTOR & VECTOR::operator = (VECTOR & x)
{
#ifdef __DONTCOPY__
  if (x.IsTemporary) {
    if (theElements != NULL) delete theElements;
    theElements = x.theElements;
    nElements = x.nElements;
    x.theElements = NULL;
    x.nElements = 0;
  }
  else {
    if (theElements == NULL) {
      theElements = new REAL[x.nElements];
      CheckMemory (theElements);
      nElements = x.nElements;
    }
    else CheckDimensions (*this, x);
    memcpy (theElements, x.theElements, nElements * sizeof (REAL));
  }
#else
  if (theElements == NULL) {
    theElements = new REAL[x.nElements];
    CheckMemory (theElements);
    nElements = x.nElements;
  }
  else CheckDimensions (*this, x);
  memcpy (theElements, x.theElements, nElements * sizeof (REAL));
#endif
  return *this;
}

VECTOR & VECTOR::operator += (VECTOR & x)
{
  CheckDimensions (*this, x);
  RealOpAddTo (theElements, x.theElements, Dimension (x));
  return *this;
}

VECTOR & VECTOR::operator -= (VECTOR & x)
{
  CheckDimensions (*this, x);
  RealOpSubFrom (theElements, x.theElements, Dimension (x));
  return *this;
}

VECTOR & VECTOR::operator *= (REAL a)
{
  RealOpMulWith (theElements, a, Dimension (*this));
  return *this;
}

VECTOR & VECTOR::operator /= (REAL a)
{
  RealOpDivBy (theElements, a, Dimension (*this));
  return *this;
}

VOID Resize (VECTOR & x, INT n)
{
  CheckVectorRange (n);
  if (n && (x.nElements == n)) return;
  if (x.theElements != NULL) delete x.theElements;
  x.nElements = n;
  if (n != 0) {
    x.theElements = new REAL[n];
    CheckMemory (x.theElements);
  }
  else x.theElements = NULL;
}

VECTOR operator - (VECTOR & a)
{
  INT dim = Dimension (a);
  VECTOR t (dim);

  MakeTemporary (t);
  RealOpNeg (t.theElements, a.theElements, dim);
  return t;
}

VECTOR operator + (VECTOR & a, VECTOR & b)
{
  INT dim = Dimension (a);
  VECTOR t (dim);

  CheckDimensions (a, b);
  MakeTemporary (t);
  RealOpAdd (t.theElements, a.theElements, b.theElements, dim);
  return t;
}

VECTOR operator - (VECTOR & a, VECTOR & b)
{
  INT dim = Dimension (a);
  VECTOR t (dim);

  CheckDimensions (a, b);
  MakeTemporary (t);
  RealOpSub (t.theElements, a.theElements, b.theElements, dim);
  return t;
}

VECTOR operator * (REAL a, VECTOR & b)
{
  INT dim = Dimension (b);
  VECTOR t (dim);

  MakeTemporary (t);
  RealOpMul (t.theElements, a, b.theElements, dim);
  return t;
}

VECTOR operator / (VECTOR & a, REAL b)
{
  INT dim = Dimension (a);
  VECTOR t (dim);

  MakeTemporary (t);
  RealOpDiv (t.theElements, a.theElements, b, dim);
  return t;
}

REAL operator * (VECTOR & a, VECTOR & b)
{
  CheckDimensions (a, b);
  return RealOpScalp (a.theElements, b.theElements, Dimension (a));
}

INT operator < (VECTOR & a, VECTOR & b)
{
  CheckDimensions (a, b);
  return RealOpLessThan (a.theElements, b.theElements, Dimension (a));
}

INT operator <= (VECTOR & a, VECTOR & b)
{
  CheckDimensions (a, b);
  return RealOpLessEqual (a.theElements, b.theElements, Dimension (a));
}

INT operator > (VECTOR & a, VECTOR & b)
{
  CheckDimensions (a, b);
  return RealOpGreaterThan (a.theElements, b.theElements, Dimension (a));
}

INT operator >= (VECTOR & a, VECTOR & b)
{
  CheckDimensions (a, b);
  return RealOpGreaterEqual (a.theElements, b.theElements, Dimension (a));
}

VECTOR Abs (VECTOR & a)
// Calculates  |x_i|
{
  INT i;
  INT dim = Dimension (a);
  VECTOR t (dim);
  PREAL pa, pt;

  MakeTemporary (t);
  pa = a.theElements; pt = t.theElements;
  for (i = 0; i < dim; i++) *(pt++) = fabs(*(pa++));
  return t;
}

REAL Sqr (VECTOR & x)
// Calculates  Sum_i (x_i^2)
{
  return RealOpScalp (x.theElements, x.theElements,
		      Dimension (x));
}

REAL Norm (VECTOR & x)
{
  return sqrt (Sqr (x));
}

REAL Max (VECTOR & x)
{
  INT dim = Dimension (x);
  INT i;
  REAL m;
  PREAL px;

  if (dim == 0) Error ("Illegal Dimension in Max()", 1, ErrorHandler::FatalError);
  px = x.theElements;
  m = *(px++);
  for (i = 1; i < dim; i++, px++)
    if (*px > m) m = *px;
  return m;
}

REAL Min (VECTOR & x)
{
  INT dim = Dimension (x);
  INT i;
  REAL m;
  PREAL px;

  if (dim == 0) Error ("Illegal Dimension in Min()", 1, ErrorHandler::FatalError);
  px = x.theElements;
  m = *(px++);
  for (i = 1; i < dim; i++, px++)
    if (*px < m) m = *px;
  return m;
}

VOID Clear (VECTOR & a)
{
  if (a.theElements != NULL)
    memset (a.theElements, 0, Dimension (a) * sizeof (REAL));
}

VOID Initialize (VECTOR & a, REAL b)
{
  INT i;
  PREAL pa = a.theElements;

  for (i = 0; i < Dimension (a); i++) *(pa++) = b;
}

ostream & operator << (ostream & os, VECTOR & x)
{
  INT i;
  INT dim = Dimension (x);
  PREAL px = x.theElements;

  os << '(';
  for (i = 0; i < dim; i++) {
    os << (*(px++));
    if (i < dim - 1) os << " ; ";
  }
  return os << ')';
}

istream & operator >> (istream & is, VECTOR & x)
{
  INT i;
  INT dim = Dimension (x);
  PREAL px = x.theElements;

  for (i = 0; i < dim; i++)
    is >> (*(px++));
  return is;
}

// The following code is only used to force Constants.C to be
// always included in the executable code.

extern VOID RegisterConstants ();

VOID RegisterVector () { RegisterConstants (); }
