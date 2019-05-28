/************************************************************************
*  Matrix.C (Implementation of type MATRIX)
*
*  Version:                     1.13
*  Date:                        10/25/93
*  Author:                      O. Knueppel
*************************************************************************/

static char sccs_id[] = "@(#)Matrix.C 1.13 93/10/25 OK";

//#include "stdafx.h"
#include "matrix.h"
#include "realop.h"
#include <memory.h>
#include <math.h>
#include <stdlib.h>

MATRIX::MATRIX(MATRIX & x)
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
    theElements = new REAL[nRows * nCols];
    CheckMemory (theElements);
    memcpy (theElements, x.theElements, nRows * nCols * sizeof (REAL));
  }
#else
  nRows = x.nRows; nCols = x.nCols;
  theElements = new REAL[nRows * nCols];
  CheckMemory (theElements);
  memcpy (theElements, x.theElements, nRows * nCols * sizeof (REAL));
#endif
}

MATRIX & MATRIX::operator = (MATRIX & x)
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
      theElements = new REAL[x.nRows * x.nCols];
      CheckMemory (theElements);
      nRows = x.nRows; nCols = x.nCols;
    }
    else CheckMatrixDimensions (*this, x);
    memcpy (theElements, x.theElements, nRows * nCols * sizeof (REAL));
  }
#else
  if (theElements == NULL) {
    theElements = new REAL[x.nRows * x.nCols];
    CheckMemory (theElements);
    nRows = x.nRows; nCols = x.nCols;
  }
  else CheckMatrixDimensions (*this, x);
  memcpy (theElements, x.theElements, nRows * nCols * sizeof (REAL));
#endif
  return *this;
}

MATRIX & MATRIX::operator += (MATRIX & x)
{
  CheckMatrixDimensions (*this, x);
  RealOpAddTo (theElements, x.theElements,
	       RowDimension (x) * ColDimension (x));
  return *this;
}

MATRIX & MATRIX::operator -= (MATRIX & x)
{
  CheckMatrixDimensions (*this, x);
  RealOpSubFrom (theElements, x.theElements,
		 RowDimension (x) * ColDimension (x));
  return *this;
}

MATRIX & MATRIX::operator *= (REAL a)
{
  RealOpMulWith (theElements, a,
		 RowDimension (*this) * ColDimension (*this));
  return *this;
}

MATRIX & MATRIX::operator /= (REAL a)
{
  RealOpDivBy (theElements, a,
	       RowDimension (*this) * ColDimension (*this));
  return *this;
}

VOID Resize (MATRIX & x, INT r, INT c)
{
  CheckMatrixRange (r, c);
  if ((r * c) && (x.nRows == r) && (x.nCols == c)) return;
  if (x.theElements != NULL) delete x.theElements;
  x.nRows = r; x.nCols = c;
  if (r * c != 0) {
    x.theElements = new REAL[r * c];
    CheckMemory (x.theElements);
  }
  else x.theElements = NULL;
}

MATRIX operator - (MATRIX & a)
{
  INT dim = RowDimension (a) * ColDimension (a);
  MATRIX t (RowDimension (a), ColDimension (a));

  MakeTemporary (t);
  RealOpNeg (t.theElements, a.theElements, dim);
  return t;
}

MATRIX operator + (MATRIX & a, MATRIX & b)
{
  INT dim = RowDimension (a) * ColDimension(a);
  MATRIX t (RowDimension (a), ColDimension (a));

  CheckMatrixDimensions (a, b);
  MakeTemporary (t);
  RealOpAdd (t.theElements, a.theElements, b.theElements, dim);
  return t;
}

MATRIX operator - (MATRIX & a, MATRIX & b)
{
  INT dim = RowDimension (a) * ColDimension(a);
  MATRIX t (RowDimension (a), ColDimension (a));

  CheckMatrixDimensions (a, b);
  MakeTemporary (t);
  RealOpSub (t.theElements, a.theElements, b.theElements, dim);
  return t;
}

MATRIX operator * (REAL a, MATRIX & b)
{
  INT dim = RowDimension (b) * ColDimension(b);
  MATRIX t (RowDimension (b), ColDimension (b));

  MakeTemporary (t);
  RealOpMul (t.theElements, a, b.theElements, dim);
  return t;
}

MATRIX operator / (MATRIX & a, REAL b)
{
  INT dim = RowDimension (a) * ColDimension(a);
  MATRIX t (RowDimension (a), ColDimension (a));

  MakeTemporary (t);
  RealOpDiv (t.theElements, a.theElements, b, dim);
  return t;
}

VECTOR operator * (MATRIX & a, VECTOR & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  VECTOR t (rows);

  CheckColumnDimensions (a, b);
  MakeTemporary (t);
  RealOpVecMul (t.theElements, a.theElements, b.theElements, rows, cols);
  return t;
}

MATRIX operator * (MATRIX & a, MATRIX & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (b);
  INT a_cols = ColDimension (a);
  MATRIX t (rows, cols);

  CheckMatrixMatrixDimensions (a, b);
  MakeTemporary (t);
  RealOpMatMul (t.theElements, a.theElements, b.theElements,
		rows, a_cols, cols);
  return t;
}

INT operator < (MATRIX & a, MATRIX & b)
{
  CheckMatrixDimensions (a, b);
  return RealOpLessThan (a.theElements, b.theElements,
			 RowDimension (a) * ColDimension(a));
}

INT operator <= (MATRIX & a, MATRIX & b)
{
  CheckMatrixDimensions (a, b);
  return RealOpLessEqual (a.theElements, b.theElements,
			  RowDimension (a) * ColDimension(a));
}

INT operator > (MATRIX & a, MATRIX & b)
{
  CheckMatrixDimensions (a, b);
  return RealOpGreaterThan (a.theElements, b.theElements,
			    RowDimension (a) * ColDimension(a));
}

INT operator >= (MATRIX & a, MATRIX & b)
{
  CheckMatrixDimensions (a, b);
  return RealOpGreaterEqual (a.theElements, b.theElements,
			     RowDimension (a) * ColDimension(a));
}

MATRIX Abs (MATRIX & a)
// Calculates  |x_ij|
{
  INT i;
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  MATRIX t (rows, cols);
  PREAL pa, pt;

  MakeTemporary (t);
  pa = a.theElements; pt = t.theElements;
  for (i = 0; i < rows * cols; i++) *(pt++) = fabs(*(pa++));
  return t;
}

VOID Clear (MATRIX & a)
{
  if (a.theElements != NULL)
    memset (a.theElements, 0, RowDimension (a) * ColDimension (a) * sizeof (REAL));
}

VOID Initialize (MATRIX & a, REAL r)
{
  INT dim = RowDimension (a) * ColDimension (a);
  INT i;
  PREAL pa = a.theElements;

  for (i = 0; i < dim; i++) *(pa++) = r;
}

VECTOR Row (MATRIX & a, INT i)
{
  INT dim = ColDimension (a);
  VECTOR t(dim);

  CheckMatrixRowIndex (i, a);
  MakeTemporary (t);
  memcpy (t.theElements, a.theElements + (i - 1) * dim, dim * sizeof (REAL));
  return t;
}

VECTOR Col (MATRIX & a, INT k)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INT i;
  PREAL pa, pt;
  VECTOR t(rows);

  CheckMatrixColIndex (k, a);
  MakeTemporary (t);
  pa = a.theElements + k - 1;
  pt = t.theElements;
  for (i = 0; i < rows; i++, pa += cols) *(pt++) = *pa;
  return t;
}

VOID SetRow (MATRIX & a, INT i, VECTOR & t)
{
  INT dim = ColDimension (a);

  CheckMatrixRowIndex (i, a);
  CheckColumnDimensions (a, t);
  memcpy (a.theElements + (i - 1) * dim, t.theElements, dim * sizeof (REAL));
}

VOID SetCol (MATRIX & a, INT k, VECTOR & t)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INT i;
  PREAL pa, pt;

  CheckMatrixColIndex (k, a);
  CheckRowDimensions (a, t);
  pa = a.theElements + k - 1;
  pt = t.theElements;
  for (i = 0; i < rows; i++, pa += cols) *pa = *(pt++);
}

ostream & operator << (ostream & os, MATRIX & x)
{
  INT i, j;
  INT rows = RowDimension (x);
  INT cols = ColDimension (x);
  PREAL px = x.theElements;

  os << '(';
  for (i = 0; i < rows; i++) {
    os << '(';
    for (j = 0; j < cols; j++) {
      os << (*(px++));
      if (j < cols - 1) os << " ; ";
    }
    os << ')';
    if (i < rows - 1) os << endl << ' ';
  }
  return os << ')';
}

istream & operator >> (istream & is, MATRIX & x)
{
  INT i, j;
  INT rows = RowDimension (x);
  INT cols = ColDimension (x);
  PREAL px = x.theElements;

  for (i = 0; i < rows; i++)
    for (j = 0; j < cols; j++)
      is >> (*(px++));
  return is;
}
