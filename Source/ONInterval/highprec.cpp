/************************************************************************
*  HighPrec.C (Implementation of operations with exact scalar product)
*
*  Version:                     1.6
*  Date:                        1/5/95
*  Author:                      O. Knueppel
*************************************************************************/

static char sccs_id[] = "@(#)HighPrec.C 1.6 95/01/05 OK";

//#include "stdafx.h"
#include "highprec.h"
#include "error.h"
#include "Li.h"
#include "DynMem.h"

#if !defined (__BIASIEEE__)
#error High Precision Arithmetic only available for IEEE format
#endif

VOID AccuInit ();

class HIGHPREC_INIT {
public:
  HIGHPREC_INIT () { LrInit (); AccuInit (); }
  ~HIGHPREC_INIT () { };
};

static HIGHPREC_INIT HighPrecInit; // Allocates memory for all accumulators

static LREAL laccu1, laccu2, laccu3;
static LREAL lprod1, lprod2, lprod;
static LIREAL liaccu1, liaccu2, liaccu3;
static LIREAL liprod, lifac1, lifac2;
static PVOID  lwrk;

// The following definitions assume that REAL == double (IEEE)

#define ACCU_DIGITS    266 // # of accumulator digits (base 2^16)
#define PRODUCT_DIGITS   8 // # of intermediate result digits (base 2^16)

VOID AccuInit ()
{
  if (sizeof (REAL) != sizeof (DOUBLE))
    FatalError ("REAL must be double precision for high precision package");
  laccu1  = LrNewTemp (ACCU_DIGITS, 3);
  laccu2  = LrNewTemp (ACCU_DIGITS, 3);
  laccu3  = LrNewTemp (ACCU_DIGITS, 3);
  lprod1  = LrNewVar  (PRODUCT_DIGITS);
  lprod2  = LrNewVar  (PRODUCT_DIGITS);
  lprod   = LrNewTemp (PRODUCT_DIGITS, 3);
  liaccu1 = LiNewTemp (ACCU_DIGITS, 3);
  liaccu2 = LiNewTemp (ACCU_DIGITS, 3);
  liaccu3 = LiNewTemp (ACCU_DIGITS, 3);
  liprod  = LiNewTemp (PRODUCT_DIGITS, 3);
  lifac1  = LiNewTemp (PRODUCT_DIGITS, 3);
  lifac2  = LiNewTemp (PRODUCT_DIGITS, 3);
  lwrk    = (PVOID) LrNewTemp (PRODUCT_DIGITS, 3);
}

// The following implementations are straight forward and not very
// efficient in terms of good cache usage or efficient long real arithmetic
// usage. This might be acceptable as a first try but should be improved
// in later versions.
// If a subroutine returns a pointer to a long real or long interval number,
// the memory occupied by this number MUST NOT be freed, because these
// pointers point to static memory which is allocated once and reused
// in the routines below.

LREAL HighPrecScalpLr (PREAL pa, PREAL pb, INT bstride, INT dim)
// Multiplies the vector a with the vector b (both dimension dim)
// using a long accumulator and returning a pointer to the long accumulator
// The elements of b are accessed with stride bstride.
{
  INT i;

  if (dim == 0) {
    LrSetPosZero (laccu1);
    return laccu1;
  }
  for (i = 0; i < dim; i++, pa++, pb += bstride) {
    LrSetPosDigits (lprod, PRODUCT_DIGITS);
    ddtolr (*pa, *pb, lprod);
    if (i == 0) {
      LrSetPosDigits (laccu1, ACCU_DIGITS);
      LrAssign (laccu1, lprod, 1);
    }
    else if (i & 1) {
      LrSetPosDigits (laccu2, ACCU_DIGITS);
      LrAdd (lprod, laccu1, laccu2, 1);
    }
    else  {
      LrSetPosDigits (laccu1, ACCU_DIGITS);
      LrAdd (lprod, laccu2, laccu1, 1);
    }
  }
  return (dim & 1) ? laccu1 : laccu2;
}

LIREAL HighPrecScalpLi (PREAL pa, PREAL pb,
			INT bstride, INT dim)
// same as above, but returns a long interval accumulator
// as result
{
  LREAL laccu;

  laccu = HighPrecScalpLr (pa, pb, bstride, dim);
  LiInfo (liaccu1) = ACCU_DIGITS;
  LiHull (laccu, laccu, liaccu1, 0);
  return liaccu1;
}

LIREAL HighPrecScalpLi (PREAL pa, PBIASINTERVAL pB,
			INT bstride, INT dim)
// Multiplies the vector a with the vector B (both dimension dim)
// using a long accumulator and returning a pointer to the long accumulator
// The elements of B are accessed with stride bstride.
{
  INT i;

  if (dim == 0) {
    LiDiamLength (liaccu1) = 0;
    LrSetPosZero (LiPlr (liaccu1));
    LrSetPosZero (LiUpperBound (liaccu1));
    return liaccu1;
  }
  for (i = 0; i < dim; i++, pa++, pB += bstride) {
    LrSetPosDigits (lprod1, PRODUCT_DIGITS);
    LrSetPosDigits (lprod2, PRODUCT_DIGITS);
    LiInfo (liprod) = PRODUCT_DIGITS;
    ddtolr (*pa, BiasInf (pB), lprod1);
    ddtolr (*pa, BiasSup (pB), lprod2);
    LiHull (lprod1, lprod2, liprod, 0);
    if (i == 0) {
      LiInfo (liaccu1) = ACCU_DIGITS;
      LiAssign (liprod, liaccu1, 0);
    }
    else if (i & 1) {
      LiInfo (liaccu2) = ACCU_DIGITS;
      LiAdd (liprod, liaccu1, liaccu2, 0);
    }
    else  {
      LiInfo (liaccu1) = ACCU_DIGITS;
      LiAdd (liprod, liaccu2, liaccu1, 0);
    }
  }
  return (dim & 1) ? liaccu1 : liaccu2;
}

LIREAL HighPrecScalpLi (PBIASINTERVAL pA, PREAL pb,
			INT bstride, INT dim)
// Multiplies the vector A with the vector a (both dimension dim)
// using a long accumulator and returning a pointer to the long accumulator
// The elements of b are accessed with stride bstride.
{
  INT i;

  if (dim == 0) {
    LiDiamLength (liaccu1) = 0;
    LrSetPosZero (LiPlr (liaccu1));
    LrSetPosZero (LiUpperBound (liaccu1));
    return liaccu1;
  }
  for (i = 0; i < dim; i++, pA++, pb += bstride) {
    LrSetPosDigits (lprod1, PRODUCT_DIGITS);
    LrSetPosDigits (lprod2, PRODUCT_DIGITS);
    LiInfo (liprod) = PRODUCT_DIGITS;
    ddtolr (*pb, BiasInf (pA), lprod1);
    ddtolr (*pb, BiasSup (pA), lprod2);
    LiHull (lprod1, lprod2, liprod, 0);
    if (i == 0) {
      LiInfo (liaccu1) = ACCU_DIGITS;
      LiAssign (liprod, liaccu1, 0);
    }
    else if (i & 1) {
      LiInfo (liaccu2) = ACCU_DIGITS;
      LiAdd (liprod, liaccu1, liaccu2, 0);
    }
    else  {
      LiInfo (liaccu1) = ACCU_DIGITS;
      LiAdd (liprod, liaccu2, liaccu1, 0);
    }
  }
  return (dim & 1) ? liaccu1 : liaccu2;
}

LIREAL HighPrecScalpLi (PBIASINTERVAL pA, PBIASINTERVAL pB,
			INT bstride, INT dim)
// Multiplies the vector A with the vector B (both dimension dim)
// using a long accumulator and returning a pointer to the long accumulator
// The elements of B are accessed with stride bstride.
{
  INT i;
  REAL inf, sup;

  if (dim == 0) {
    LiDiamLength (liaccu1) = 0;
    LrSetPosZero (LiPlr (liaccu1));
    LrSetPosZero (LiUpperBound (liaccu1));
    return liaccu1;
  }
  for (i = 0; i < dim; i++, pA++, pB += bstride) {
    LrSetPosDigits (lprod1, PRODUCT_DIGITS);
    LrSetPosDigits (lprod2, PRODUCT_DIGITS);
    LiInfo (lifac1) = PRODUCT_DIGITS;
    inf = BiasInf (pA); sup = BiasSup (pA);
    dtolr (lprod1, & inf); dtolr (lprod2, & sup);
    LiHull (lprod1, lprod2, lifac1, 0);
    LrSetPosDigits (lprod1, PRODUCT_DIGITS);
    LrSetPosDigits (lprod2, PRODUCT_DIGITS);
    LiInfo (lifac2) = PRODUCT_DIGITS;
    inf = BiasInf (pB); sup = BiasSup (pB);
    dtolr (lprod1, & inf); dtolr (lprod2, & sup);
    LiHull (lprod1, lprod2, lifac2, 0);
    LiInfo (liprod) = PRODUCT_DIGITS;
    LiMul (lifac1, lifac2, liprod, lwrk, 0);
    if (i == 0) {
      LiInfo (liaccu1) = ACCU_DIGITS;
      LiAssign (liprod, liaccu1, 0);
    }
    else if (i & 1) {
      LiInfo (liaccu2) = ACCU_DIGITS;
      LiAdd (liprod, liaccu1, liaccu2, 0);
    }
    else  {
      LiInfo (liaccu1) = ACCU_DIGITS;
      LiAdd (liprod, liaccu2, liaccu1, 0);
    }
  }
  return (dim & 1) ? liaccu1 : liaccu2;
}

static VOID HighPrecSpecial (PBIASINTERVAL pR, LREAL laccu, INT f)
// Modifies the result in the long accumulator "laccu"
// depending on the setting of f:
//   if f ==  0, (A * B) is calculated
//   if f ==  1, (1.0 - A * B) is calculated
//   if f == -1, (- A * B) is calculated
// and returns the rounded result in R.
{
  REAL inf, sup, temp;

  if (f == 1) {
    inf = -1.0;
    dtolr (lprod, & inf);
    LrSetPosDigits (laccu3, ACCU_DIGITS);
    LrAdd (lprod, laccu, laccu3, 1);
    lrtod (& inf, laccu3, LR_RND_DOWN);
    lrtod (& sup, laccu3, LR_RND_UP);
  }
  else {
    lrtod (& inf, laccu, LR_RND_DOWN);
    lrtod (& sup, laccu, LR_RND_UP);
  }
  if (f) {
    temp = inf;
    inf = -sup;
    sup = -temp;
  }
  BiasHullRR (pR, & inf, & sup);
}

static VOID HighPrecSpecial (PBIASINTERVAL pR, LIREAL liaccu, INT f)
// Modifies the result in the long accumulator "liaccu"
// depending on the setting of f:
//   if f ==  0, (A * B) is calculated
//   if f ==  1, (1.0 - A * B) is calculated
//   if f == -1, (- A * B) is calculated
// and returns the rounded result in R.
{
  REAL inf, sup, temp;

  if (f == 1) {
    inf = -1.0;
    dtolr (lprod1, & inf);
    LiInfo (liprod) = PRODUCT_DIGITS;
    LiHull (lprod1, lprod1, liprod, 0);
    LiInfo (liaccu3) = ACCU_DIGITS;
    LiAdd (liprod, liaccu, liaccu3, 0);
    LrSetPosDigits (lprod1, PRODUCT_DIGITS);
    LrSetPosDigits (lprod2, PRODUCT_DIGITS);
    LiInfSup (liaccu3, lprod1, 0, 0);
    LiInfSup (liaccu3, lprod2, 1, 0);
  }
  else {
    LrSetPosDigits (lprod1, PRODUCT_DIGITS);
    LrSetPosDigits (lprod2, PRODUCT_DIGITS);
    LiInfSup (liaccu, lprod1, 0, 0);
    LiInfSup (liaccu, lprod2, 1, 0);
  }
  lrtod (& inf, lprod1, LR_RND_DOWN);
  lrtod (& sup, lprod2, LR_RND_UP);
  if (f) {
    temp = inf;
    inf = -sup;
    sup = -temp;
  }
  BiasHullRR (pR, & inf, & sup);
}

static VOID HighPrecScalp (PREAL pr, PREAL pa, PREAL pb,
			   INT bstride, INT dim)
// Multiplies the vector a with the vector b (both dimension dim)
// using a long accumulator and storing the result in r.
// The elements of b are accessed with stride bstride.
{
  LREAL laccu;

  if (bstride == 1) {
    LrSetPosDigits (laccu1, ACCU_DIGITS);
    LrScalp (dim, pa, pb, laccu1, 1);
    lrtod (pr, laccu1, LR_RND_NEAR);
  }
  else {
    laccu = HighPrecScalpLr (pa, pb, bstride, dim);
    lrtod (pr, laccu, LR_RND_NEAR);
  }
}

static VOID HighPrecScalp (PBIASINTERVAL pR, PREAL pa, PREAL pb,
			   INT bstride, INT dim, INT f)
// Multiplies the vector a with the vector b (both dimension dim)
// using a long accumulator and storing the enclosure of the
// result in R. The elements of b are accessed with stride bstride.
// The calculation depends on the setting of f:
// if f ==  0, (A * B) is calculated
// if f ==  1, (1.0 - A * B) is calculated
// if f == -1, (- A * B) is calculated
{
  LREAL laccu;
  REAL inf, sup;

  if ((bstride == 1) && !f) {
    LrSetPosDigits (laccu1, ACCU_DIGITS);
    LrScalp (dim, pa, pb, laccu1, 1);
    lrtod (& inf, laccu1, LR_RND_DOWN);
    lrtod (& sup, laccu1, LR_RND_UP);
    BiasHullRR (pR, & inf, & sup);
  }
  else {
    laccu = HighPrecScalpLr (pa, pb, bstride, dim);
    HighPrecSpecial (pR, laccu, f);
  }
}

static VOID HighPrecScalp (PBIASINTERVAL pR,
			   PREAL pa, PBIASINTERVAL pB,
			   INT bstride, INT dim, INT f)
// Multiplies the vector a with the vector B (both dimension dim)
// using a long accumulator and storing the enclosure of the
// result in R. The elements of B are accessed with stride bstride.
// The calculation depends on the setting of f:
// if f ==  0, (A * B) is calculated
// if f ==  1, (1.0 - A * B) is calculated
// if f == -1, (- A * B) is calculated
{
  LIREAL liaccu;

  liaccu = HighPrecScalpLi (pa, pB, bstride, dim);
  HighPrecSpecial (pR, liaccu, f);
}

static VOID HighPrecScalp (PBIASINTERVAL pR,
			   PBIASINTERVAL pA, PREAL pb,
			   INT bstride, INT dim, INT f)
// Multiplies the vector A with the vector b (both dimension dim)
// using a long accumulator and storing the enclosure of the
// result in R. The elements of b are accessed with stride bstride.
// The calculation depends on the setting of f:
// if f ==  0, (A * B) is calculated
// if f ==  1, (1.0 - A * B) is calculated
// if f == -1, (- A * B) is calculated
{
  LIREAL liaccu;

  liaccu = HighPrecScalpLi (pA, pb, bstride, dim);
  HighPrecSpecial (pR, liaccu, f);
}

static VOID HighPrecScalp (PBIASINTERVAL pR,
			   PBIASINTERVAL pA, PBIASINTERVAL pB,
			   INT bstride, INT dim, INT f)
// Multiplies the vector A with the vector B (both dimension dim)
// using a long accumulator and storing the enclosure of the
// result in R. The elements of B are accessed with stride bstride.
// The calculation depends on the setting of f:
// if f ==  0, (A * B) is calculated
// if f ==  1, (1.0 - A * B) is calculated
// if f == -1, (- A * B) is calculated
{
  LIREAL liaccu;

  liaccu = HighPrecScalpLi (pA, pB, bstride, dim);
  HighPrecSpecial (pR, liaccu, f);
}

REAL HighPrecMul (VECTOR & a, VECTOR & b)
{
  INT dim = Dimension (a);
  REAL s;

  CheckDimensions (a, b);
  HighPrecScalp (& s, a.theElements, b.theElements, 1, dim);
  return s;
}

VECTOR HighPrecMul (MATRIX & a, VECTOR & b)
{
  INT i;
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  VECTOR t(rows);
  PREAL pa = a.theElements;
  PREAL pt = t.theElements;

  CheckColumnDimensions (a, b);
  MakeTemporary (t);
  for (i = 0; i < rows; i++, pa += cols, pt++)
    HighPrecScalp (pt, pa, b.theElements, 1, cols);
  return t;
}

MATRIX HighPrecMul (MATRIX & a, MATRIX & b)
{
  INT i, j;
  INT rows = RowDimension (a);
  INT cols = ColDimension (b);
  INT a_cols = ColDimension (a);
  MATRIX t(rows, cols);
  PREAL pa = a.theElements;
  PREAL pb;
  PREAL pt = t.theElements;

  CheckMatrixMatrixDimensions (a, b);
  MakeTemporary (t);
  for (i = 0; i < rows; i++, pa += a_cols) {
    pb = b.theElements;
    for (j = 0; j < cols; j++, pb++, pt++)
      HighPrecScalp (pt, pa, pb, cols, a_cols);
  }
  return t;
}

INTERVAL HighPrecMulBounds (VECTOR & a, VECTOR & b)
{
  INT dim = Dimension (a);
  INTERVAL s;

  CheckDimensions (a, b);
  HighPrecScalp (Bias (s), a.theElements, b.theElements, 1, dim, 0);
  return s;
}

INTERVAL HighPrecMul (VECTOR & a, INTERVAL_VECTOR & b)
{
  INT dim = Dimension (a);
  INTERVAL s;

  CheckDimensions (a, b);
  HighPrecScalp (Bias (s), a.theElements, b.theElements, 1, dim, 0);
  return s;
}

INTERVAL HighPrecMul (INTERVAL_VECTOR & a, VECTOR & b)
{
  INT dim = Dimension (a);
  INTERVAL s;

  CheckDimensions (a, b);
  HighPrecScalp (Bias (s), a.theElements, b.theElements, 1, dim, 0);
  return s;
}

INTERVAL HighPrecMul (INTERVAL_VECTOR & a, INTERVAL_VECTOR & b)
{
  INT dim = Dimension (a);
  INTERVAL s;

  CheckDimensions (a, b);
  HighPrecScalp (Bias (s), a.theElements, b.theElements, 1, dim, 0);
  return s;
}

INTERVAL_VECTOR HighPrecMulBounds (MATRIX & a, VECTOR & b)
{
  INT i;
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_VECTOR t(rows);
  PREAL pa = a.theElements;
  PBIASINTERVAL pt = t.theElements;

  CheckColumnDimensions (a, b);
  MakeTemporary (t);
  for (i = 0; i < rows; i++, pa += cols, pt++)
    HighPrecScalp (pt, pa, b.theElements, 1, cols, 0);
  return t;
}

INTERVAL_VECTOR HighPrecMul (MATRIX & a, INTERVAL_VECTOR & b)
{
  INT i;
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_VECTOR t(rows);
  PREAL pa = a.theElements;
  PBIASINTERVAL pt = t.theElements;

  CheckColumnDimensions (a, b);
  MakeTemporary (t);
  for (i = 0; i < rows; i++, pa += cols, pt++)
    HighPrecScalp (pt, pa, b.theElements, 1, cols, 0);
  return t;
}

INTERVAL_VECTOR HighPrecMul (INTERVAL_MATRIX & a, VECTOR & b)
{
  INT i;
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_VECTOR t(rows);
  PBIASINTERVAL pa = a.theElements;
  PBIASINTERVAL pt = t.theElements;

  CheckColumnDimensions (a, b);
  MakeTemporary (t);
  for (i = 0; i < rows; i++, pa += cols, pt++)
    HighPrecScalp (pt, pa, b.theElements, 1, cols, 0);
  return t;
}

INTERVAL_VECTOR HighPrecMul (INTERVAL_MATRIX & a, INTERVAL_VECTOR & b)
{
  INT i;
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_VECTOR t(rows);
  PBIASINTERVAL pa = a.theElements;
  PBIASINTERVAL pt = t.theElements;

  CheckColumnDimensions (a, b);
  MakeTemporary (t);
  for (i = 0; i < rows; i++, pa += cols, pt++)
    HighPrecScalp (pt, pa, b.theElements, 1, cols, 0);
  return t;
}

INTERVAL_MATRIX HighPrecMulBounds (MATRIX & a, MATRIX & b)
{
  INT i, j;
  INT rows = RowDimension (a);
  INT cols = ColDimension (b);
  INT a_cols = ColDimension (a);
  INTERVAL_MATRIX t(rows, cols);
  PREAL pa = a.theElements;
  PREAL pb;
  PBIASINTERVAL pt = t.theElements;

  CheckMatrixMatrixDimensions (a, b);
  MakeTemporary (t);
  for (i = 0; i < rows; i++, pa += a_cols) {
    pb = b.theElements;
    for (j = 0; j < cols; j++, pb++, pt++)
      HighPrecScalp (pt, pa, pb, cols, a_cols, 0);
  }
  return t;
}

INTERVAL_MATRIX HighPrecMul (MATRIX & a, INTERVAL_MATRIX & b)
{
  INT i, j;
  INT rows = RowDimension (a);
  INT cols = ColDimension (b);
  INT a_cols = ColDimension (a);
  INTERVAL_MATRIX t(rows, cols);
  PREAL pa = a.theElements;
  PBIASINTERVAL pb;
  PBIASINTERVAL pt = t.theElements;

  CheckMatrixMatrixDimensions (a, b);
  MakeTemporary (t);
  for (i = 0; i < rows; i++, pa += a_cols) {
    pb = b.theElements;
    for (j = 0; j < cols; j++, pb++, pt++)
      HighPrecScalp (pt, pa, pb, cols, a_cols, 0);
  }
  return t;
}

INTERVAL_MATRIX HighPrecMul (INTERVAL_MATRIX & a, MATRIX & b)
{
  INT i, j;
  INT rows = RowDimension (a);
  INT cols = ColDimension (b);
  INT a_cols = ColDimension (a);
  INTERVAL_MATRIX t(rows, cols);
  PBIASINTERVAL pa = a.theElements;
  PREAL pb;
  PBIASINTERVAL pt = t.theElements;

  CheckMatrixMatrixDimensions (a, b);
  MakeTemporary (t);
  for (i = 0; i < rows; i++, pa += a_cols) {
    pb = b.theElements;
    for (j = 0; j < cols; j++, pb++, pt++)
      HighPrecScalp (pt, pa, pb, cols, a_cols, 0);
  }
  return t;
}

INTERVAL_MATRIX HighPrecMul (INTERVAL_MATRIX & a, INTERVAL_MATRIX & b)
{
  INT i, j;
  INT rows = RowDimension (a);
  INT cols = ColDimension (b);
  INT a_cols = ColDimension (a);
  INTERVAL_MATRIX t(rows, cols);
  PBIASINTERVAL pa = a.theElements;
  PBIASINTERVAL pb;
  PBIASINTERVAL pt = t.theElements;

  CheckMatrixMatrixDimensions (a, b);
  MakeTemporary (t);
  for (i = 0; i < rows; i++, pa += a_cols) {
    pb = b.theElements;
    for (j = 0; j < cols; j++, pb++, pt++)
      HighPrecScalp (pt, pa, pb, cols, a_cols, 0);
  }
  return t;
}

INTERVAL_MATRIX IdMinusHighPrecMul (MATRIX & a, MATRIX & b)
{
  INT i, j;
  INT rows = RowDimension (a);
  INT cols = ColDimension (b);
  INT a_cols = ColDimension (a);
  INTERVAL_MATRIX t(rows, cols);
  PREAL pa = a.theElements;
  PREAL pb;
  PBIASINTERVAL pt = t.theElements;

  CheckMatrixMatrixDimensions (a, b);
  MakeTemporary (t);
  for (i = 0; i < rows; i++, pa += a_cols) {
    pb = b.theElements;
    for (j = 0; j < cols; j++, pb++, pt++)
      HighPrecScalp (pt, pa, pb, cols, a_cols, (i == j) ? 1 : -1);
  }
  return t;
}

INTERVAL_MATRIX IdMinusHighPrecMul (MATRIX & a, INTERVAL_MATRIX & b)
{
  INT i, j;
  INT rows = RowDimension (a);
  INT cols = ColDimension (b);
  INT a_cols = ColDimension (a);
  INTERVAL_MATRIX t(rows, cols);
  PREAL pa = a.theElements;
  PBIASINTERVAL pb;
  PBIASINTERVAL pt = t.theElements;

  CheckMatrixMatrixDimensions (a, b);
  MakeTemporary (t);
  for (i = 0; i < rows; i++, pa += a_cols) {
    pb = b.theElements;
    for (j = 0; j < cols; j++, pb++, pt++)
      HighPrecScalp (pt, pa, pb, cols, a_cols, (i == j) ? 1 : -1);
  }
  return t;
}

INTERVAL_MATRIX IdMinusHighPrecMul (INTERVAL_MATRIX & a, MATRIX & b)
{
  INT i, j;
  INT rows = RowDimension (a);
  INT cols = ColDimension (b);
  INT a_cols = ColDimension (a);
  INTERVAL_MATRIX t(rows, cols);
  PBIASINTERVAL pa = a.theElements;
  PREAL pb;
  PBIASINTERVAL pt = t.theElements;

  CheckMatrixMatrixDimensions (a, b);
  MakeTemporary (t);
  for (i = 0; i < rows; i++, pa += a_cols) {
    pb = b.theElements;
    for (j = 0; j < cols; j++, pb++, pt++)
      HighPrecScalp (pt, pa, pb, cols, a_cols, (i == j) ? 1 : -1);
  }
  return t;
}

INTERVAL_MATRIX IdMinusHighPrecMul (INTERVAL_MATRIX & a, INTERVAL_MATRIX & b)
{
  INT i, j;
  INT rows = RowDimension (a);
  INT cols = ColDimension (b);
  INT a_cols = ColDimension (a);
  INTERVAL_MATRIX t(rows, cols);
  PBIASINTERVAL pa = a.theElements;
  PBIASINTERVAL pb;
  PBIASINTERVAL pt = t.theElements;

  CheckMatrixMatrixDimensions (a, b);
  MakeTemporary (t);
  for (i = 0; i < rows; i++, pa += a_cols) {
    pb = b.theElements;
    for (j = 0; j < cols; j++, pb++, pt++)
      HighPrecScalp (pt, pa, pb, cols, a_cols, (i == j) ? 1 : -1);
  }
  return t;
}
