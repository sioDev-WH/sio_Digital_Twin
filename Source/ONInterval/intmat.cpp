/************************************************************************
*  IntegerMatrix.C (Implementation of type INTEGER_MATRIX)
*
*  Version:                     1.11
*  Date:                        10/15/93
*  Author:                      O. Knueppel
*************************************************************************/

static char sccs_id[] = "@(#)IntegerMatrix.C 1.11 93/10/15 OK";

//#include "stdafx.h"
#include "intmat.h"
#include <memory.h>
#include <stdlib.h>

INTEGER_MATRIX::INTEGER_MATRIX(INTEGER_MATRIX & x)
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
    theElements = new INT[nRows * nCols];
    CheckMemory (theElements);
    memcpy (theElements, x.theElements, nRows * nCols * sizeof (INT));
  }
#else
  nRows = x.nRows; nCols = x.nCols;
  theElements = new INT[nRows * nCols];
  CheckMemory (theElements);
  memcpy (theElements, x.theElements, nRows * nCols * sizeof (INT));
#endif
}

INTEGER_MATRIX & INTEGER_MATRIX::operator = (INTEGER_MATRIX & x)
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
      theElements = new INT[x.nRows * x.nCols];
      CheckMemory (theElements);
      nRows = x.nRows; nCols = x.nCols;
    }
    else CheckMatrixDimensions (*this, x);
    memcpy (theElements, x.theElements, nRows * nCols * sizeof (INT));
  }
#else
  if (theElements == NULL) {
    theElements = new INT[x.nRows * x.nCols];
    CheckMemory (theElements);
    nRows = x.nRows; nCols = x.nCols;
  }
  else CheckMatrixDimensions (*this, x);
  memcpy (theElements, x.theElements, nRows * nCols * sizeof (INT));
#endif
  return *this;
}

INTEGER_MATRIX & INTEGER_MATRIX::operator += (INTEGER_MATRIX & x)
{
  INT i;
  INT dim = RowDimension (x) * ColDimension (x);
  PINT px, pt;

  CheckMatrixDimensions (*this, x);
  pt = theElements; px = x.theElements;
  for (i = 0; i < dim; i++) *(pt++) += *(px++);
  return *this;
}

INTEGER_MATRIX & INTEGER_MATRIX::operator -= (INTEGER_MATRIX & x)
{
  INT i;
  INT dim = RowDimension (x) * ColDimension (x);
  PINT px, pt;

  CheckMatrixDimensions (*this, x);
  pt = theElements; px = x.theElements;
  for (i = 0; i < dim; i++) *(pt++) -= *(px++);
  return *this;
}

INTEGER_MATRIX & INTEGER_MATRIX::operator *= (INT a)
{
  INT i;
  INT dim = RowDimension (*this) * ColDimension (*this);
  PINT pt;

  pt = theElements;
  for (i = 0; i < dim; i++) *(pt++) *= a;
  return *this;
}

INTEGER_MATRIX & INTEGER_MATRIX::operator /= (INT a)
{
  INT i;
  INT dim = RowDimension (*this) * ColDimension (*this);
  PINT pt;

  pt = theElements;
  for (i = 0; i < dim; i++) *(pt++) /= a;
  return *this;
}

VOID Resize (INTEGER_MATRIX & x, INT r, INT c)
{
  CheckMatrixRange (r, c);
  if ((r * c) && (x.nRows == r) && (x.nCols == c)) return;
  if (x.theElements != NULL) delete x.theElements;
  x.nRows = r; x.nCols = c;
  if (r * c != 0) {
    x.theElements = new INT[r * c];
    CheckMemory (x.theElements);
  }
  else x.theElements = NULL;
}

INTEGER_MATRIX operator + (INTEGER_MATRIX & a, INTEGER_MATRIX & b)
{
  INT i;
  INT dim = RowDimension (a) * ColDimension(a);
  INTEGER_MATRIX t (RowDimension (a), ColDimension (a));
  PINT pa, pb, pt;

  CheckMatrixDimensions (a, b);
  MakeTemporary (t);
  pa = a.theElements; pb = b.theElements; pt = t.theElements;
  for (i = 0; i < dim; i++) *(pt++) = *(pa++) + *(pb++);
  return t;
}

INTEGER_MATRIX operator - (INTEGER_MATRIX & a, INTEGER_MATRIX & b)
{
  INT i;
  INT dim = RowDimension (a) * ColDimension(a);
  INTEGER_MATRIX t (RowDimension (a), ColDimension (a));
  PINT pa, pb, pt;

  CheckMatrixDimensions (a, b);
  MakeTemporary (t);
  pa = a.theElements; pb = b.theElements; pt = t.theElements;
  for (i = 0; i < dim; i++) *(pt++) = *(pa++) - *(pb++);
  return t;
}

INTEGER_MATRIX operator * (INT a, INTEGER_MATRIX & b)
{
  INT i;
  INT dim = RowDimension (b) * ColDimension(b);
  INTEGER_MATRIX t (RowDimension (b), ColDimension (b));
  PINT pb, pt;

  MakeTemporary (t);
  pb = b.theElements; pt = t.theElements;
  for (i = 0; i < dim; i++) *(pt++) = a * *(pb++);
  return t;
}

INTEGER_MATRIX operator / (INTEGER_MATRIX & a, INT b)
{
  INT i;
  INT dim = RowDimension (a) * ColDimension(a);
  INTEGER_MATRIX t (RowDimension (a), ColDimension (a));
  PINT pa, pt;

  MakeTemporary (t);
  pa = a.theElements; pt = t.theElements;
  for (i = 0; i < dim; i++) *(pt++) = *(pa++) / b;
  return t;
}

INTEGER_VECTOR operator * (INTEGER_MATRIX & a, INTEGER_VECTOR & b)
{
  INT rows = RowDimension (a);
  INT cols = ColDimension (a);
  INT i, j;
  INTEGER_VECTOR t (rows);
  INT s;
  PINT pa, pb, pb_start, pt;

  CheckColumnDimensions (a, b);
  MakeTemporary (t);
  pa = a.theElements; pb_start = b.theElements; pt = t.theElements;
  for (i = 0; i < rows; i++) {
    s = 0; pb = pb_start;
    for (j = 0; j < cols; j++)
      s += *(pa++) * *(pb++);
    *(pt++) = s;
    }
  return t;
}

VOID Clear (INTEGER_MATRIX & a)
{
  if (a.theElements != NULL)
    memset (a.theElements, 0, RowDimension (a) * ColDimension (a) * sizeof (INT));
}

VOID Initialize (INTEGER_MATRIX & a, INT ini)
{
  INT i;
  PINT pa = a.theElements;

  for (i = 0; i < RowDimension (a) * ColDimension (a); i++) *(pa++) = ini;
}

ostream & operator << (ostream & os, INTEGER_MATRIX & x)
{
  INT i, j;
  INT rows = RowDimension (x);
  INT cols = ColDimension (x);
  PINT px = x.theElements;

  os << '(';
  for (i = 0; i < rows; i++) {
    os << '(';
    for (j = 0; j < cols; j++) {
      os << *(px++);
      if (j < cols - 1) os << " ; ";
    }
    os << ')';
    if (i < rows - 1) os << endl << ' ';
  }
  return os << ')';
}

istream & operator >> (istream & is, INTEGER_MATRIX & x)
{
  INT i, j;
  INT rows = RowDimension (x);
  INT cols = ColDimension (x);
  PINT px = x.theElements;

  for (i = 0; i < rows; i++)
    for (j = 0; j < cols; j++)
      is >> (*(px++));
  return is;
}
