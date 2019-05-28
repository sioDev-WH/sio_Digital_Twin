/************************************************************************
*  IntervalMatrix.C (Implementation of type INTERVAL_MATRIX)
*
*  Version:                     1.16
*  Date:                        1/26/94
*  Author:                      O. Knueppel
*************************************************************************/

static char sccs_id[] = "@(#)IntervalMatrix.C 1.16 94/01/26 OK";

//#include "stdafx.h"
#include "ivalmat.h"
#include "Bias2.h"
#include <memory.h>
#include <stdlib.h>

INTERVAL_MATRIX::INTERVAL_MATRIX(INTERVAL_MATRIX & x)
{
#ifdef __DONTCOPY__
  IsTemporary = 1;
  nRows = x.nRows; nCols = x.nCols;
  if (x.IsTemporary) {
    theElements = x.theElements;
    x.theElements = NULL;
    x.nRows = x.nCols = 0;
  }
  else {
    theElements = new BIASINTERVAL[nRows * nCols];
    CheckMemory (theElements);
    memcpy (theElements, x.theElements, nRows * nCols * sizeof (BIASINTERVAL));
  }
#else
  nRows = x.nRows; nCols = x.nCols;
  theElements = new BIASINTERVAL[nRows * nCols];
  CheckMemory (theElements);
  memcpy (theElements, x.theElements, nRows * nCols * sizeof (BIASINTERVAL));
#endif
}

INTERVAL_MATRIX & INTERVAL_MATRIX::operator = (INTERVAL_MATRIX & x)
{
#ifdef __DONTCOPY__
  if (x.IsTemporary) {
    if (theElements != NULL) delete theElements;
    theElements = x.theElements;
    nRows = x.nRows; nCols = x.nCols;
    x.theElements = NULL;
    x.nRows = x.nCols = 0;
  }
  else {
    if (theElements == NULL) {
      theElements = new BIASINTERVAL[x.nRows * x.nCols];
      CheckMemory (theElements);
      nRows = x.nRows; nCols = x.nCols;
    }
    else CheckMatrixDimensions (*this, x);
    memcpy (theElements, x.theElements, nRows * nCols * sizeof (BIASINTERVAL));
  }
#else
  if (theElements == NULL) {
    theElements = new BIASINTERVAL[x.nRows * x.nCols];
    CheckMemory (theElements);
    nRows = x.nRows; nCols = x.nCols;
  }
  else CheckMatrixDimensions (*this, x);
  memcpy (theElements, x.theElements, nRows * nCols * sizeof (BIASINTERVAL));
#endif
  return *this;
}

// Because the appropiate routines are missing in Bias, a temporary
// variable is needed for +=, -=, *=, /=.

INTERVAL_MATRIX & INTERVAL_MATRIX::operator += (INTERVAL_MATRIX & x)
{
  INT rows = RowDimension (x);
  INT cols = ColDimension (x);
  INTERVAL_MATRIX t(rows, cols);

  CheckMatrixDimensions (*this, x);
  MakeTemporary (t);
  BiasAddMIMI (t.theElements, theElements, x.theElements, rows, cols);
  *this = t; return *this;
}

INTERVAL_MATRIX & INTERVAL_MATRIX::operator -= (INTERVAL_MATRIX & x)
{
  INT rows = RowDimension (x);
  INT cols = ColDimension (x);
  INTERVAL_MATRIX t(rows, cols);

  CheckMatrixDimensions (*this, x);
  MakeTemporary (t);
  BiasSubMIMI (t.theElements, theElements, x.theElements, rows, cols);
  *this = t; return *this;
}

INTERVAL_MATRIX & INTERVAL_MATRIX::operator *= (INTERVAL & x)
{
  INT rows = RowDimension (*this);
  INT cols = ColDimension (*this);
  INTERVAL_MATRIX t(rows, cols);

  MakeTemporary (t);
  BiasMulIMI (t.theElements, Bias (x), theElements, rows, cols);
  *this = t; return *this;
}

INTERVAL_MATRIX & INTERVAL_MATRIX::operator /= (INTERVAL & x)
{
  INT rows = RowDimension (*this);
  INT cols = ColDimension (*this);
  INTERVAL_MATRIX t(rows, cols);

  MakeTemporary (t);
  BiasDivMII (t.theElements, theElements, Bias (x), rows, cols);
  *this = t; return *this;
}

INTERVAL_MATRIX & INTERVAL_MATRIX::operator = (MATRIX & x)
{
  INT i;
  PREAL px = x.theElements;
  INT dim = RowDimension (x) * ColDimension (x);
  PBIASINTERVAL pt;

  if (theElements == NULL) {
    theElements = new BIASINTERVAL[dim];
    CheckMemory (theElements);
    nRows = RowDimension (x); nCols = ColDimension (x);
  }
  else CheckMatrixDimensions (*this, x);
  pt = theElements;
  for (i = 0; i < dim; i++) BiasHullR (pt++, px++);
  return *this;
}

INTERVAL_MATRIX & INTERVAL_MATRIX::operator += (MATRIX & x)
{
  INT rows = RowDimension (x);
  INT cols = ColDimension (x);
  INTERVAL_MATRIX t(rows, cols);

  CheckMatrixDimensions (*this, x);
  MakeTemporary (t);
  BiasAddMIMR (t.theElements, theElements, x.theElements, rows, cols);
  *this = t; return *this;
}

INTERVAL_MATRIX & INTERVAL_MATRIX::operator -= (MATRIX & x)
{
  INT rows = RowDimension (x);
  INT cols = ColDimension (x);
  INTERVAL_MATRIX t(rows, cols);

  CheckMatrixDimensions (*this, x);
  MakeTemporary (t);
  BiasSubMIMR (t.theElements, theElements, x.theElements, rows, cols);
  *this = t; return *this;
}

INTERVAL_MATRIX & INTERVAL_MATRIX::operator *= (REAL x)
{
  INT rows = RowDimension (*this);
  INT cols = ColDimension (*this);
  INTERVAL_MATRIX t(rows, cols);

  MakeTemporary (t);
  BiasMulRMI (t.theElements, & x, theElements, rows, cols);
  *this = t; return *this;
}

INTERVAL_MATRIX & INTERVAL_MATRIX::operator /= (REAL x)
{
  INT rows = RowDimension (*this);
  INT cols = ColDimension (*this);
  INTERVAL_MATRIX t(rows, cols);

  MakeTemporary (t);
  BiasDivMIR (t.theElements, theElements, & x, rows, cols);
  *this = t; return *this;
}

VOID Resize (INTERVAL_MATRIX & x, INT r, INT c)
{
  CheckMatrixRange (r, c);
  if ((r * c) && (x.nRows == r) && (x.nCols == c)) return;
  if (x.theElements != NULL) delete x.theElements;
  x.nRows = r; x.nCols = c;
  if (r * c != 0) {
    x.theElements = new BIASINTERVAL[r * c];
    CheckMemory (x.theElements);
  }
  else x.theElements = NULL;
}

INTERVAL_MATRIX operator - (INTERVAL_MATRIX & a)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_MATRIX t (rows, cols);

  MakeTemporary (t);
  BiasNegM (t.theElements, a.theElements, rows, cols);
  return t;
}

INTERVAL_MATRIX Hull (MATRIX & a)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_MATRIX t (rows, cols);

  MakeTemporary (t);
  BiasHullMR (t.theElements, a.theElements, rows, cols);
  return t;
}

INTERVAL_MATRIX Hull (MATRIX & a, MATRIX & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_MATRIX t (rows, cols);

  CheckMatrixDimensions (a, b);
  MakeTemporary (t);
  BiasHullMRMR (t.theElements, a.theElements, b.theElements, rows, cols);
  return t;
}

INTERVAL_MATRIX Hull (MATRIX & a, INTERVAL_MATRIX & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_MATRIX t (rows, cols);

  CheckMatrixDimensions (a, b);
  MakeTemporary (t);
  BiasHullMRMI (t.theElements, a.theElements, b.theElements, rows, cols);
  return t;
}

INTERVAL_MATRIX Hull (INTERVAL_MATRIX & a, MATRIX & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_MATRIX t (rows, cols);

  CheckMatrixDimensions (a, b);
  MakeTemporary (t);
  BiasHullMIMR (t.theElements, a.theElements, b.theElements, rows, cols);
  return t;
}

INTERVAL_MATRIX Hull (INTERVAL_MATRIX & a, INTERVAL_MATRIX & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_MATRIX t (rows, cols);

  CheckMatrixDimensions (a, b);
  MakeTemporary (t);
  BiasHullMIMI (t.theElements, a.theElements, b.theElements, rows, cols);
  return t;
}

INTERVAL_MATRIX AddBounds (MATRIX & a, MATRIX & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_MATRIX t (rows, cols);

  CheckMatrixDimensions (a, b);
  MakeTemporary (t);
  BiasAddMRMR (t.theElements, a.theElements, b.theElements, rows, cols);
  return t;
}

INTERVAL_MATRIX operator + (MATRIX & a, INTERVAL_MATRIX & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_MATRIX t (rows, cols);

  CheckMatrixDimensions (a, b);
  MakeTemporary (t);
  BiasAddMRMI (t.theElements, a.theElements, b.theElements, rows, cols);
  return t;
}

INTERVAL_MATRIX operator + (INTERVAL_MATRIX & a, MATRIX & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_MATRIX t (rows, cols);

  CheckMatrixDimensions (a, b);
  MakeTemporary (t);
  BiasAddMIMR (t.theElements, a.theElements, b.theElements, rows, cols);
  return t;
}

INTERVAL_MATRIX operator + (INTERVAL_MATRIX & a, INTERVAL_MATRIX & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_MATRIX t (rows, cols);

  CheckMatrixDimensions (a, b);
  MakeTemporary (t);
  BiasAddMIMI (t.theElements, a.theElements, b.theElements, rows, cols);
  return t;
}

INTERVAL_MATRIX SubBounds (MATRIX & a, MATRIX & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_MATRIX t (rows, cols);

  CheckMatrixDimensions (a, b);
  MakeTemporary (t);
  BiasSubMRMR (t.theElements, a.theElements, b.theElements, rows, cols);
  return t;
}

INTERVAL_MATRIX operator - (MATRIX & a, INTERVAL_MATRIX & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_MATRIX t (rows, cols);

  CheckMatrixDimensions (a, b);
  MakeTemporary (t);
  BiasSubMRMI (t.theElements, a.theElements, b.theElements, rows, cols);
  return t;
}

INTERVAL_MATRIX operator - (INTERVAL_MATRIX & a, MATRIX & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_MATRIX t (rows, cols);

  CheckMatrixDimensions (a, b);
  MakeTemporary (t);
  BiasSubMIMR (t.theElements, a.theElements, b.theElements, rows, cols);
  return t;
}

INTERVAL_MATRIX operator - (INTERVAL_MATRIX & a, INTERVAL_MATRIX & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_MATRIX t (rows, cols);

  CheckMatrixDimensions (a, b);
  MakeTemporary (t);
  BiasSubMIMI (t.theElements, a.theElements, b.theElements, rows, cols);
  return t;
}

INTERVAL_MATRIX MulBounds (REAL a, MATRIX & b)
{
  INT rows = RowDimension (b);
  INT cols = ColDimension (b);
  INTERVAL_MATRIX t (rows, cols);

  MakeTemporary (t);
  BiasMulRMR (t.theElements, &a, b.theElements, rows, cols);
  return t;
}

INTERVAL_MATRIX operator * (REAL a, INTERVAL_MATRIX & b)
{
  INT rows = RowDimension (b);
  INT cols = ColDimension (b);
  INTERVAL_MATRIX t (rows, cols);

  MakeTemporary (t);
  BiasMulRMI (t.theElements, &a, b.theElements, rows, cols);
  return t;
}

INTERVAL_MATRIX operator * (INTERVAL & a, MATRIX & b)
{
  INT rows = RowDimension (b);
  INT cols = ColDimension (b);
  INTERVAL_MATRIX t (rows, cols);

  MakeTemporary (t);
  BiasMulIMR (t.theElements, Bias (a), b.theElements, rows, cols);
  return t;
}

INTERVAL_MATRIX operator * (INTERVAL & a, INTERVAL_MATRIX & b)
{
  INT rows = RowDimension (b);
  INT cols = ColDimension (b);
  INTERVAL_MATRIX t (rows, cols);

  MakeTemporary (t);
  BiasMulIMI (t.theElements, Bias (a), b.theElements, rows, cols);
  return t;
}

INTERVAL_MATRIX DivBounds (MATRIX & a, REAL b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_MATRIX t (rows, cols);

  MakeTemporary (t);
  BiasDivMRR (t.theElements, a.theElements, &b, rows, cols);
  return t;
}

INTERVAL_MATRIX operator / (MATRIX & a, INTERVAL & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_MATRIX t (rows, cols);

  MakeTemporary (t);
  BiasDivMRI (t.theElements, a.theElements, Bias (b), rows, cols);
  return t;
}

INTERVAL_MATRIX operator / (INTERVAL_MATRIX & a, REAL b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_MATRIX t (rows, cols);

  MakeTemporary (t);
  BiasDivMIR (t.theElements, a.theElements, &b, rows, cols);
  return t;
}

INTERVAL_MATRIX operator / (INTERVAL_MATRIX & a, INTERVAL & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_MATRIX t (rows, cols);

  MakeTemporary (t);
  BiasDivMII (t.theElements, a.theElements, Bias (b), rows, cols);
  return t;
}

INTERVAL_VECTOR MulBounds (MATRIX & a, VECTOR & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_VECTOR t (rows);

  CheckColumnDimensions (a, b);
  MakeTemporary (t);
  BiasMulMRVR (t.theElements, a.theElements, b.theElements, rows, cols);
  return t;
}

INTERVAL_VECTOR operator * (MATRIX & a, INTERVAL_VECTOR & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_VECTOR t (rows);

  CheckColumnDimensions (a, b);
  MakeTemporary (t);
  BiasMulMRVI (t.theElements, a.theElements, b.theElements, rows, cols);
  return t;
}

INTERVAL_VECTOR operator * (INTERVAL_MATRIX & a, VECTOR & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_VECTOR t (rows);

  CheckColumnDimensions (a, b);
  MakeTemporary (t);
  BiasMulMIVR (t.theElements, a.theElements, b.theElements, rows, cols);
  return t;
}

INTERVAL_VECTOR operator * (INTERVAL_MATRIX & a, INTERVAL_VECTOR & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INTERVAL_VECTOR t (rows);

  CheckColumnDimensions (a,b);
  MakeTemporary (t);
  BiasMulMIVI (t.theElements, a.theElements, b.theElements, rows, cols);
  return t;
}

INTERVAL_MATRIX MulBounds (MATRIX & a, MATRIX & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (b);
  INTERVAL_MATRIX t (rows, cols);

  CheckMatrixMatrixDimensions (a, b);
  MakeTemporary (t);
  BiasMulMRMR (t.theElements, a.theElements, b.theElements,
	       rows, ColDimension (a), cols);
  return t;
}

INTERVAL_MATRIX operator * (MATRIX & a, INTERVAL_MATRIX & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (b);
  INTERVAL_MATRIX t (rows, cols);

  CheckMatrixMatrixDimensions (a, b);
  MakeTemporary (t);
  BiasMulMRMI (t.theElements, a.theElements, b.theElements,
	       rows, ColDimension (a), cols);
  return t;
}

INTERVAL_MATRIX operator * (INTERVAL_MATRIX & a, MATRIX & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (b);
  INTERVAL_MATRIX t (rows, cols);

  CheckMatrixMatrixDimensions (a, b);
  MakeTemporary (t);
  BiasMulMIMR (t.theElements, a.theElements, b.theElements,
	       rows, ColDimension (a), cols);
  return t;
}

INTERVAL_MATRIX operator * (INTERVAL_MATRIX & a, INTERVAL_MATRIX & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (b);
  INTERVAL_MATRIX t (rows, cols);

  CheckMatrixMatrixDimensions (a, b);
  MakeTemporary (t);
  BiasMulMIMI (t.theElements, a.theElements, b.theElements,
	       rows, ColDimension (a), cols);
  return t;
}

MATRIX Inf (INTERVAL_MATRIX & a)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  MATRIX t (rows, cols);

  MakeTemporary (t);
  BiasInfM (t.theElements, a.theElements, rows, cols);
  return t;
}

MATRIX Sup (INTERVAL_MATRIX & a)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  MATRIX t (rows, cols);

  MakeTemporary (t);
  BiasSupM (t.theElements, a.theElements, rows, cols);
  return t;
}

MATRIX Mid (INTERVAL_MATRIX & a)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  MATRIX t (rows, cols);

  MakeTemporary (t);
  BiasMidM (t.theElements, a.theElements, rows, cols);
  return t;
}

MATRIX Diam (INTERVAL_MATRIX & a)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  MATRIX t (rows, cols);

  MakeTemporary (t);
  BiasDiamM (t.theElements, a.theElements, rows, cols);
  return t;
}

MATRIX Abs (INTERVAL_MATRIX & a)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  MATRIX t (rows, cols);

  MakeTemporary (t);
  BiasAbsM (t.theElements, a.theElements, rows, cols);
  return t;
}

INT Intersection (INTERVAL_MATRIX & r, INTERVAL_MATRIX & a, INTERVAL_MATRIX & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);

  CheckMatrixDimensions (a, b);
  if (r.theElements == NULL) Resize (r, rows, cols);
  else CheckMatrixDimensions (a, r);
  return BiasIntersectionM (r.theElements, a.theElements,
			 b.theElements, rows, cols);
}

INT operator <= (MATRIX & a, INTERVAL_MATRIX & b)
{
  CheckMatrixDimensions (a, b);
  return BiasInMR (a.theElements, b.theElements,
		   RowDimension (a), ColDimension (a));
}

INT operator <= (INTERVAL_MATRIX & a, INTERVAL_MATRIX & b)
{
  CheckMatrixDimensions (a, b);
  return BiasInMI (a.theElements, b.theElements,
		   RowDimension (a), ColDimension (a));
}

INT operator < (MATRIX & a, INTERVAL_MATRIX & b)
{
  CheckMatrixDimensions (a, b);
  return BiasInInteriorMR (a.theElements, b.theElements,
			   RowDimension (a), ColDimension (a));
}

INT operator < (INTERVAL_MATRIX & a, INTERVAL_MATRIX & b)
{
  CheckMatrixDimensions (a, b);
  return BiasInInteriorMI (a.theElements, b.theElements,
			   RowDimension (a), ColDimension (a));
}

INT operator == (INTERVAL_MATRIX & a, INTERVAL_MATRIX & b)
{
  CheckMatrixDimensions (a, b);
  return BiasIsEqualM (a.theElements, b.theElements,
		       RowDimension (a), ColDimension (a));
}

INT operator != (INTERVAL_MATRIX & a, INTERVAL_MATRIX & b)
{
  CheckMatrixDimensions (a, b);
  return !BiasIsEqualM (a.theElements, b.theElements,
			RowDimension (a), ColDimension (a));
}

VOID Clear (INTERVAL_MATRIX & a)
{
  if (a.theElements != NULL)
    memset (a.theElements, 0,
	    RowDimension (a) * ColDimension (a) * sizeof (BIASINTERVAL));
}

VOID Initialize (INTERVAL_MATRIX & a, INTERVAL & r)
{
  INT dim = RowDimension (a) * ColDimension (a);
  INT i;
  PBIASINTERVAL pa = a.theElements;
  PBIASINTERVAL pr = Bias (r);

  for (i = 0; i < dim; i++) *(pa++) = *pr;
}

INTERVAL_VECTOR Row (INTERVAL_MATRIX & a, INT i)
{
  INT dim = ColDimension (a);
  INTERVAL_VECTOR t(dim);

  CheckMatrixRowIndex (i, a);
  MakeTemporary (t);
  memcpy (t.theElements, a.theElements + (i - 1) * dim, dim * sizeof (BIASINTERVAL));
  return t;
}

INTERVAL_VECTOR Col (INTERVAL_MATRIX & a, INT k)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INT i;
  PBIASINTERVAL pa, pt;
  INTERVAL_VECTOR t(rows);

  CheckMatrixColIndex (k, a);
  MakeTemporary (t);
  pa = a.theElements + k - 1;
  pt = t.theElements;
  for (i = 0; i < rows; i++, pa += cols) *(pt++) = *pa;
  return t;
}

VOID SetRow (INTERVAL_MATRIX & a, INT i, INTERVAL_VECTOR & t)
{
  INT dim = ColDimension (a);

  CheckMatrixRowIndex (i, a);
  CheckColumnDimensions (a, t);
  memcpy (a.theElements + (i - 1) * dim, t.theElements, dim * sizeof (BIASINTERVAL));
}

VOID SetCol (INTERVAL_MATRIX & a, INT k, INTERVAL_VECTOR & t)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INT i;
  PBIASINTERVAL pa, pt;

  CheckMatrixColIndex (k, a);
  CheckRowDimensions (a, t);
  pa = a.theElements + k - 1;
  pt = t.theElements;
  for (i = 0; i < rows; i++, pa += cols) *pa = *(pt++);
}

ostream & operator << (ostream & os, INTERVAL_MATRIX & x)
{
  INT i, j;
  INT rows = RowDimension (x);
  INT cols = ColDimension (x);
  PBIASINTERVAL px = x.theElements;
  INTERVAL iv;

  os << '(';
  for (i = 0; i < rows; i++) {
    os << '(';
    for (j = 0; j < cols; j++, px++) {
      *(Bias(iv)) = *px;
      os << iv;
      if (j < cols - 1) os << " ; ";
    }
    os << ')';
    if (i < rows - 1) os << endl << ' ';
  }
  return os << ')';
}

istream & operator >> (istream & is, INTERVAL_MATRIX & x)
{
  INT i, j;
  INT rows = RowDimension (x);
  INT cols = ColDimension (x);
  PBIASINTERVAL px = x.theElements;
  INTERVAL iv;

  for (i = 0; i < rows; i++)
    for (j = 0; j < cols; j++) {
      is >> iv;
      *(px++) = *(Bias(iv));
    }
  return is;
}
