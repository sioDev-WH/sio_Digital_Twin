/************************************************************************
*  IntegerVector.C (Implementation of type INTEGER_VECTOR)
*
*  Version:                     1.9
*  Date:                        10/15/93
*  Author:                      O. Knueppel
*************************************************************************/

static char sccs_id[] = "@(#)IntegerVector.C 1.9 93/10/15 OK";

//#include "stdafx.h"
#include "intvec.h"
#include <memory.h>
#include <stdlib.h>

INTEGER_VECTOR::INTEGER_VECTOR(INTEGER_VECTOR & x)
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
    theElements = new INT[nElements];
    CheckMemory (theElements);
    memcpy (theElements, x.theElements, nElements * sizeof (INT));
  }
#else
  nElements = x.nElements;
  theElements = new INT[nElements];
  CheckMemory (theElements);
  memcpy (theElements, x.theElements, nElements * sizeof (INT));
#endif
}

INTEGER_VECTOR & INTEGER_VECTOR::operator = (INTEGER_VECTOR & x)
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
      theElements = new INT[x.nElements];
      CheckMemory (theElements);
      nElements = x.nElements;
    }
    else CheckDimensions (*this, x);
    memcpy (theElements, x.theElements, nElements * sizeof (INT));
  }
#else
  if (theElements == NULL) {
    theElements = new INT[x.nElements];
    CheckMemory (theElements);
    nElements = x.nElements;
  }
  else CheckDimensions (*this, x);
  memcpy (theElements, x.theElements, nElements * sizeof (INT));
#endif
  return *this;
}

INTEGER_VECTOR & INTEGER_VECTOR::operator += (INTEGER_VECTOR & x)
{
  INT i;
  INT dim = Dimension (x);
  PINT px, pt;

  CheckDimensions (*this, x);
  pt = theElements; px = x.theElements;
  for (i = 0; i < dim; i++) *(pt++) += *(px++);
  return *this;
}

INTEGER_VECTOR & INTEGER_VECTOR::operator -= (INTEGER_VECTOR & x)
{
  INT i;
  INT dim = Dimension (x);
  PINT px, pt;

  CheckDimensions (*this, x);
  pt = theElements; px = x.theElements;
  for (i = 0; i < dim; i++) *(pt++) -= *(px++);
  return *this;
}

INTEGER_VECTOR & INTEGER_VECTOR::operator *= (INT a)
{
  INT i;
  INT dim = Dimension (*this);
  PINT pt;

  pt = theElements;
  for (i = 0; i < dim; i++) *(pt++) *= a;
  return *this;
}

INTEGER_VECTOR & INTEGER_VECTOR::operator /= (INT a)
{
  INT i;
  INT dim = Dimension (*this);
  PINT pt;

  pt = theElements;
  for (i = 0; i < dim; i++) *(pt++) /= a;
  return *this;
}

VOID Resize (INTEGER_VECTOR & x, INT n)
{
  CheckVectorRange (n);
  if (n && (x.nElements == n)) return;
  if (x.theElements != NULL) delete x.theElements;
  x.nElements = n;
  if (n != 0) {
    x.theElements = new INT[n];
    CheckMemory (x.theElements);
  }
  else x.theElements = NULL;
}

INTEGER_VECTOR operator + (INTEGER_VECTOR & a, INTEGER_VECTOR & b)
{
  INT i;
  INT dim = Dimension (a);
  INTEGER_VECTOR t (dim);
  PINT pa, pb, pt;

  CheckDimensions (a, b);
  MakeTemporary (t);
  pa = a.theElements; pb = b.theElements; pt = t.theElements;
  for (i = 0; i < dim; i++) *(pt++) = *(pa++) + *(pb++);
  return t;
}

INTEGER_VECTOR operator - (INTEGER_VECTOR & a, INTEGER_VECTOR & b)
{
  INT i;
  INT dim = Dimension (a);
  INTEGER_VECTOR t (dim);
  PINT pa, pb, pt;

  CheckDimensions (a, b);
  MakeTemporary (t);
  pa = a.theElements; pb = b.theElements; pt = t.theElements;
  for (i = 0; i < dim; i++) *(pt++) = *(pa++) - *(pb++);
  return t;
}

INTEGER_VECTOR operator * (INT a, INTEGER_VECTOR & b)
{
  INT i;
  INT dim = Dimension (b);
  INTEGER_VECTOR t (dim);
  PINT pb, pt;

  MakeTemporary (t);
  pb = b.theElements; pt = t.theElements;
  for (i = 0; i < dim; i++) *(pt++) = a * *(pb++);
  return t;
}

INTEGER_VECTOR operator / (INTEGER_VECTOR & a, INT b)
{
  INT i;
  INT dim = Dimension (a);
  INTEGER_VECTOR t (dim);
  PINT pa, pt;

  MakeTemporary (t);
  pa = a.theElements; pt = t.theElements;
  for (i = 0; i < dim; i++) *(pt++) = *(pa++) / b;
  return t;
}

INT operator * (INTEGER_VECTOR & a, INTEGER_VECTOR & b)
{
  INT i;
  INT dim = Dimension (a);
  INT t;
  PINT pa, pb;

  CheckDimensions (a, b);
  pa = a.theElements; pb = b.theElements; t = 0;
  for (i = 0; i < dim; i++) t += *(pa++) * *(pb++);
  return t;
}

VOID Clear (INTEGER_VECTOR & a)
{
  if (a.theElements != NULL)
    memset (a.theElements, 0, Dimension (a) * sizeof (INT));
}

VOID Initialize (INTEGER_VECTOR & a, INT b)
{
  INT i;
  PINT pa = a.theElements;

  for (i = 0; i < Dimension (a); i++) *(pa++) = b;
}

ostream & operator << (ostream & os, INTEGER_VECTOR & x)
{
  INT i;
  INT dim = Dimension (x);
  PINT px = x.theElements;

  os << '(';
  for (i = 0; i < dim; i++) {
    os << (*px++);
    if (i < dim - 1) os << " ; ";
  }
  return os << ')';
}

istream & operator >> (istream & is, INTEGER_VECTOR & x)
{
  INT i;
  INT dim = Dimension (x);
  PINT px = x.theElements;

  for (i = 0; i < dim; i++)
    is >> (*(px++));
  return is;
}
