/************************************************************************
*  IntervalVector.C (Implementation of type INTERVAL_VECTOR)
*
*  Version:                     1.17
*  Date:                        10/15/93
*  Author:                      O. Knueppel
*************************************************************************/

static char sccs_id[] = "@(#)IntervalVector.C 1.17 93/10/15 OK";

//#include "stdafx.h"
#include "ivalvec.h"
#include "func.h"
#include <memory.h>
#include <stdlib.h>

INTERVAL_VECTOR::INTERVAL_VECTOR(INTERVAL_VECTOR & x)
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
    theElements = new BIASINTERVAL[nElements];
    CheckMemory (theElements);
    memcpy (theElements, x.theElements, nElements * sizeof (BIASINTERVAL));
  }
#else
  nElements = x.nElements;
  theElements = new BIASINTERVAL[nElements];
  CheckMemory (theElements);
  memcpy (theElements, x.theElements, nElements * sizeof (BIASINTERVAL));
#endif
}

INTERVAL_VECTOR & INTERVAL_VECTOR::operator = (INTERVAL_VECTOR & x)
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
      theElements = new BIASINTERVAL[x.nElements];
      CheckMemory (theElements);
      nElements = x.nElements;
    }
    else CheckDimensions (*this, x);
    memcpy (theElements, x.theElements, nElements * sizeof (BIASINTERVAL));
  }
#else
  if (theElements == NULL) {
    theElements = new BIASINTERVAL[x.nElements];
    CheckMemory (theElements);
    nElements = x.nElements;
  }
  else CheckDimensions (*this, x);
  memcpy (theElements, x.theElements, nElements * sizeof (BIASINTERVAL));
#endif
  return *this;
}

// Because the appropiate routines are missing in Bias, a temporary
// variable is needed for +=, -=, *=, /=.

INTERVAL_VECTOR & INTERVAL_VECTOR::operator += (INTERVAL_VECTOR & x)
{
  INT dim = Dimension (x);
  INTERVAL_VECTOR t(dim);

  CheckDimensions (*this, x);
  MakeTemporary (t);
  BiasAddVIVI (t.theElements, theElements, x.theElements, dim);
  *this = t; return *this;
}

INTERVAL_VECTOR & INTERVAL_VECTOR::operator -= (INTERVAL_VECTOR & x)
{
  INT dim = Dimension (x);
  INTERVAL_VECTOR t(dim);

  CheckDimensions (*this, x);
  MakeTemporary (t);
  BiasSubVIVI (t.theElements, theElements, x.theElements, dim);
  *this = t; return *this;
}

INTERVAL_VECTOR & INTERVAL_VECTOR::operator *= (INTERVAL & x)
{
  INT dim = Dimension (*this);
  INTERVAL_VECTOR t(dim);

  MakeTemporary (t);
  BiasMulIVI (t.theElements, Bias (x), theElements, dim);
  *this = t; return *this;
}

INTERVAL_VECTOR & INTERVAL_VECTOR::operator /= (INTERVAL & x)
{
  INT dim = Dimension (*this);
  INTERVAL_VECTOR t(dim);

  MakeTemporary (t);
  BiasDivVII (t.theElements, theElements, Bias (x), dim);
  *this = t; return *this;
}

INTERVAL_VECTOR & INTERVAL_VECTOR::operator = (VECTOR & x)
{
  INT i;
  PREAL px = x.theElements;
  PBIASINTERVAL pt;

  if (theElements == NULL) {
    theElements = new BIASINTERVAL[Dimension (x)];
    CheckMemory (theElements);
    nElements = Dimension (x);
  }
  else CheckDimensions (*this, x);
  pt = theElements;
  for (i = 0; i < nElements; i++) BiasHullR (pt++, px++);
  return *this;
}

INTERVAL_VECTOR & INTERVAL_VECTOR::operator += (VECTOR & x)
{
  INT dim = Dimension (x);
  INTERVAL_VECTOR t(dim);

  CheckDimensions (*this, x);
  MakeTemporary (t);
  BiasAddVIVR (t.theElements, theElements, x.theElements, dim);
  *this = t; return *this;
}

INTERVAL_VECTOR & INTERVAL_VECTOR::operator -= (VECTOR & x)
{
  INT dim = Dimension (x);
  INTERVAL_VECTOR t(dim);

  CheckDimensions (*this, x);
  MakeTemporary (t);
  BiasSubVIVR (t.theElements, theElements, x.theElements, dim);
  *this = t; return *this;
}

INTERVAL_VECTOR & INTERVAL_VECTOR::operator *= (REAL x)
{
  INT dim = Dimension (*this);
  INTERVAL_VECTOR t(dim);

  MakeTemporary (t);
  BiasMulRVI (t.theElements, & x, theElements, dim);
  *this = t; return *this;
}

INTERVAL_VECTOR & INTERVAL_VECTOR::operator /= (REAL x)
{
  INT dim = Dimension (*this);
  INTERVAL_VECTOR t(dim);

  MakeTemporary (t);
  BiasDivVIR (t.theElements, theElements, & x, dim);
  *this = t; return *this;
}

VOID Resize (INTERVAL_VECTOR & x, INT n)
{
  CheckVectorRange (n);
  if (n && (x.nElements == n)) return;
  if (x.theElements != NULL) delete x.theElements;
  x.nElements = n;
  if (n != 0) {
    x.theElements = new BIASINTERVAL[n];
    CheckMemory (x.theElements);
  }
  else x.theElements = NULL;
}

INTERVAL_VECTOR operator - (INTERVAL_VECTOR & a)
{
  INT dim = Dimension (a);
  INTERVAL_VECTOR t (dim);

  MakeTemporary (t);
  BiasNegV (t.theElements, a.theElements, dim);
  return t;
}

INTERVAL_VECTOR Hull (VECTOR & a)
{
  INT dim = Dimension (a);
  INTERVAL_VECTOR t (dim);

  MakeTemporary (t);
  BiasHullVR (t.theElements, a.theElements, dim);
  return t;
}

INTERVAL_VECTOR Hull (VECTOR & a, VECTOR & b)
{
  INT dim = Dimension (a);
  INTERVAL_VECTOR t (dim);

  CheckDimensions (a, b);
  MakeTemporary (t);
  BiasHullVRVR (t.theElements, a.theElements, b.theElements, dim);
  return t;
}

INTERVAL_VECTOR Hull (VECTOR & a, INTERVAL_VECTOR & b)
{
  INT dim = Dimension (a);
  INTERVAL_VECTOR t (dim);

  CheckDimensions (a, b);
  MakeTemporary (t);
  BiasHullVRVI (t.theElements, a.theElements, b.theElements, dim);
  return t;
}

INTERVAL_VECTOR Hull (INTERVAL_VECTOR & a, VECTOR & b)
{
  INT dim = Dimension (a);
  INTERVAL_VECTOR t (dim);

  CheckDimensions (a, b);
  MakeTemporary (t);
  BiasHullVIVR (t.theElements, a.theElements, b.theElements, dim);
  return t;
}

INTERVAL_VECTOR Hull (INTERVAL_VECTOR & a, INTERVAL_VECTOR & b)
{
  INT dim = Dimension (a);
  INTERVAL_VECTOR t (dim);

  CheckDimensions (a, b);
  MakeTemporary (t);
  BiasHullVIVI (t.theElements, a.theElements, b.theElements, dim);
  return t;
}

INTERVAL_VECTOR AddBounds (VECTOR & a, VECTOR & b)
{
  INT dim = Dimension (a);
  INTERVAL_VECTOR t (dim);

  CheckDimensions (a, b);
  MakeTemporary (t);
  BiasAddVRVR (t.theElements, a.theElements, b.theElements, dim);
  return t;
}

INTERVAL_VECTOR operator + (VECTOR & a, INTERVAL_VECTOR & b)
{
  INT dim = Dimension (a);
  INTERVAL_VECTOR t (dim);

  CheckDimensions (a, b);
  MakeTemporary (t);
  BiasAddVRVI (t.theElements, a.theElements, b.theElements, dim);
  return t;
}

INTERVAL_VECTOR operator + (INTERVAL_VECTOR & a, VECTOR & b)
{
  INT dim = Dimension (a);
  INTERVAL_VECTOR t (dim);

  CheckDimensions (a, b);
  MakeTemporary (t);
  BiasAddVIVR (t.theElements, a.theElements, b.theElements, dim);
  return t;
}

INTERVAL_VECTOR operator + (INTERVAL_VECTOR & a, INTERVAL_VECTOR & b)
{
  INT dim = Dimension (a);
  INTERVAL_VECTOR t (dim);

  CheckDimensions (a, b);
  MakeTemporary (t);
  BiasAddVIVI (t.theElements, a.theElements, b.theElements, dim);
  return t;
}

INTERVAL_VECTOR SubBounds (VECTOR & a, VECTOR & b)
{
  INT dim = Dimension (a);
  INTERVAL_VECTOR t (dim);

  CheckDimensions (a, b);
  MakeTemporary (t);
  BiasSubVRVR (t.theElements, a.theElements, b.theElements, dim);
  return t;
}

INTERVAL_VECTOR operator - (VECTOR & a, INTERVAL_VECTOR & b)
{
  INT dim = Dimension (a);
  INTERVAL_VECTOR t (dim);

  CheckDimensions (a, b);
  MakeTemporary (t);
  BiasSubVRVI (t.theElements, a.theElements, b.theElements, dim);
  return t;
}

INTERVAL_VECTOR operator - (INTERVAL_VECTOR & a, VECTOR & b)
{
  INT dim = Dimension (a);
  INTERVAL_VECTOR t (dim);

  CheckDimensions (a, b);
  MakeTemporary (t);
  BiasSubVIVR (t.theElements, a.theElements, b.theElements, dim);
  return t;
}

INTERVAL_VECTOR operator - (INTERVAL_VECTOR & a, INTERVAL_VECTOR & b)
{
  INT dim = Dimension (a);
  INTERVAL_VECTOR t (dim);

  CheckDimensions (a, b);
  MakeTemporary (t);
  BiasSubVIVI (t.theElements, a.theElements, b.theElements, dim);
  return t;
}

INTERVAL_VECTOR MulBounds (REAL a, VECTOR & b)
{
  INT dim = Dimension (b);
  INTERVAL_VECTOR t (dim);

  MakeTemporary (t);
  BiasMulRVR (t.theElements, &a, b.theElements, dim);
  return t;
}

INTERVAL_VECTOR operator * (REAL a, INTERVAL_VECTOR & b)
{
  INT dim = Dimension (b);
  INTERVAL_VECTOR t (dim);

  MakeTemporary (t);
  BiasMulRVI (t.theElements, &a, b.theElements, dim);
  return t;
}

INTERVAL_VECTOR operator * (INTERVAL & a, VECTOR & b)
{
  INT dim = Dimension (b);
  INTERVAL_VECTOR t (dim);

  MakeTemporary (t);
  BiasMulIVR (t.theElements, Bias (a), b.theElements, dim);
  return t;
}

INTERVAL_VECTOR operator * (INTERVAL & a, INTERVAL_VECTOR & b)
{
  INT dim = Dimension (b);
  INTERVAL_VECTOR t (dim);

  MakeTemporary (t);
  BiasMulIVI (t.theElements, Bias (a), b.theElements, dim);
  return t;
}

INTERVAL_VECTOR DivBounds (VECTOR & a, REAL b)
{
  INT dim = Dimension (a);
  INTERVAL_VECTOR t (dim);

  MakeTemporary (t);
  BiasDivVRR (t.theElements, a.theElements, &b, dim);
  return t;
}

INTERVAL_VECTOR operator / (VECTOR & a, INTERVAL & b)
{
  INT dim = Dimension (a);
  INTERVAL_VECTOR t (dim);

  MakeTemporary (t);
  BiasDivVRI (t.theElements, a.theElements, Bias (b), dim);
  return t;
}

INTERVAL_VECTOR operator / (INTERVAL_VECTOR & a, REAL b)
{
  INT dim = Dimension (a);
  INTERVAL_VECTOR t (dim);

  MakeTemporary (t);
  BiasDivVIR (t.theElements, a.theElements, &b, dim);
  return t;
}

INTERVAL_VECTOR operator / (INTERVAL_VECTOR & a, INTERVAL & b)
{
  INT dim = Dimension (a);
  INTERVAL_VECTOR t (dim);

  MakeTemporary (t);
  BiasDivVII (t.theElements, a.theElements, Bias (b), dim);
  return t;
}

INTERVAL operator * (VECTOR & a, INTERVAL_VECTOR & b)
{
  INT dim = Dimension (a);
  INTERVAL t;

  CheckDimensions (a, b);
  BiasMacVRVI (Bias (t), a.theElements, b.theElements, dim);
  return t;
}

INTERVAL operator * (INTERVAL_VECTOR & a, VECTOR & b)
{
  INT dim = Dimension (a);
  INTERVAL t;

  CheckDimensions (a, b);
  BiasMacVIVR (Bias (t), a.theElements, b.theElements, dim);
  return t;
}

INTERVAL operator * (INTERVAL_VECTOR & a, INTERVAL_VECTOR & b)
{
  INT dim = Dimension (a);
  INTERVAL t;

  CheckDimensions (a, b);
  BiasMacVIVI (Bias (t), a.theElements, b.theElements, dim);
  return t;
}

INTERVAL MulBounds (VECTOR & a, VECTOR & b)
{
  INT dim = Dimension (a);
  INTERVAL t;

  CheckDimensions (a, b);
  BiasMacVRVR (Bias (t), a.theElements, b.theElements, dim);
  return t;
}

VECTOR Inf (INTERVAL_VECTOR & a)
{
  INT dim = Dimension (a);
  VECTOR t (dim);

  MakeTemporary (t);
  BiasInfV (t.theElements, a.theElements, dim);
  return t;
}

VECTOR Sup (INTERVAL_VECTOR & a)
{
  INT dim = Dimension (a);
  VECTOR t (dim);

  MakeTemporary (t);
  BiasSupV (t.theElements, a.theElements, dim);
  return t;
}

VECTOR Mid (INTERVAL_VECTOR & a)
{
  INT dim = Dimension (a);
  VECTOR t (dim);

  MakeTemporary (t);
  BiasMidV (t.theElements, a.theElements, dim);
  return t;
}

VECTOR Diam (INTERVAL_VECTOR & a)
{
  INT dim = Dimension (a);
  VECTOR t (dim);

  MakeTemporary (t);
  BiasDiamV (t.theElements, a.theElements, dim);
  return t;
}

VECTOR Abs (INTERVAL_VECTOR & a)
{
  INT dim = Dimension (a);
  VECTOR t (dim);

  MakeTemporary (t);
  BiasAbsV (t.theElements, a.theElements, dim);
  return t;
}

INT Intersection (INTERVAL_VECTOR & r, INTERVAL_VECTOR & a, INTERVAL_VECTOR & b)
{
  INT dim = Dimension (a);

  CheckDimensions (a, b);
  if (r.theElements == NULL) Resize (r, dim);
  else CheckDimensions (a, r);
  return BiasIntersectionV (r.theElements, a.theElements, b.theElements, dim);
}

VOID Clear (INTERVAL_VECTOR & a)
{
  if (a.theElements != NULL)
    memset (a.theElements, 0, Dimension (a) * sizeof (BIASINTERVAL));
}

VOID Initialize (INTERVAL_VECTOR & a, INTERVAL & b)
{
  INT i;
  PBIASINTERVAL pa = a.theElements;

  for (i = 0; i < Dimension (a); i++) *(pa++) = *(Bias (b));
}

INT operator <= (VECTOR & a, INTERVAL_VECTOR & b)
{
  CheckDimensions (a, b);
  return BiasInVR (a.theElements, b.theElements, Dimension (a));
}

INT operator <= (INTERVAL_VECTOR & a, INTERVAL_VECTOR & b)
{
  CheckDimensions (a, b);
  return BiasInVI (a.theElements, b.theElements, Dimension (a));
}

INT operator < (VECTOR & a, INTERVAL_VECTOR & b)
{
  CheckDimensions (a, b);
  return BiasInInteriorVR (a.theElements, b.theElements, Dimension (a));
}

INT operator < (INTERVAL_VECTOR & a, INTERVAL_VECTOR & b)
{
  CheckDimensions (a, b);
  return BiasInInteriorVI (a.theElements, b.theElements, Dimension (a));
}

INT operator == (INTERVAL_VECTOR & a, INTERVAL_VECTOR & b)
{
  CheckDimensions (a, b);
  return BiasIsEqualV (a.theElements, b.theElements, Dimension (a));
}

INT operator != (INTERVAL_VECTOR & a, INTERVAL_VECTOR & b)
{
  CheckDimensions (a, b);
  return !BiasIsEqualV (a.theElements, b.theElements, Dimension (a));
}

INTERVAL Sqr (INTERVAL_VECTOR & x)
// Calculates  Sum_i (x_i^2)
{
  INT i;
  INT dim = Dimension (x);
  PBIASINTERVAL px = x.theElements;
  INTERVAL sum, tmp;

  sum = 0.0;
  for (i = 0; i < dim; i++) {
    BiasSqr (Bias (tmp), px++);
    sum += tmp;
  }
  return sum;
}

INTERVAL Norm (INTERVAL_VECTOR & x)
{
  return Sqrt (Sqr (x));
}

ostream & operator << (ostream & os, INTERVAL_VECTOR & x)
{
  INT i;
  INT dim = Dimension (x);
  PBIASINTERVAL px = x.theElements;
  INTERVAL iv;

  os << '(';
  for (i = 0; i < dim; i++, px++) {
    *(Bias(iv)) = *px;
    os << iv;
    if (i < dim - 1) os << " ; ";
  }
  return os << ')';
}

istream & operator >> (istream & is, INTERVAL_VECTOR & x)
{
  INT i;
  INT dim = Dimension (x);
  PBIASINTERVAL px = x.theElements;
  INTERVAL iv;

  for (i = 0; i < dim; i++) {
    is >> iv;
    *(px++) = *(Bias(iv));
  }
  return is;
}
