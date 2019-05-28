/************************************************************************
*  IntervalMatrix.h (Definition of type INTERVAL_MATRIX)
*
*  Version:                     1.16
*  Date:                        1/30/95
*  Author:                      O. Knueppel
*************************************************************************/

#ifndef __INTERVAL_MATRIX__
#define __INTERVAL_MATRIX__

#include "Bias1.h"
#include "error.h"
#include "matrix.h"
#include "ivalvec.h"

class INTERVAL_MATRIX {
  INT nRows;
  INT nCols;
#ifdef __DONTCOPY__
  INT IsTemporary;
#endif
public:
  PBIASINTERVAL theElements;
  INTERVAL_MATRIX ()
    {
#ifdef __DONTCOPY__
      IsTemporary = 0;
#endif
      nRows = nCols = 0; theElements = NULL; }
  INTERVAL_MATRIX (INT r, INT c)
    {
#ifdef __DONTCOPY__
      IsTemporary = 0;
#endif
      CheckMatrixRange (r, c);
      nRows = r; nCols = c;
      theElements = new BIASINTERVAL[r * c];
      CheckMemory (theElements);
    }
  ~INTERVAL_MATRIX ()
    { if (theElements != NULL) delete theElements; }
  INTERVAL_MATRIX (INTERVAL_MATRIX &);
  INTERVAL & operator () (INT i, INT j)
    { CheckMatrixIndex (i, j, *this); return * ((INTERVAL *)(theElements + (i-1) * nCols + (j-1))); }
  INTERVAL_MATRIX & operator =  (INTERVAL_MATRIX &);
  INTERVAL_MATRIX & operator =  (MATRIX &);
  INTERVAL_MATRIX & operator += (INTERVAL_MATRIX &);
  INTERVAL_MATRIX & operator -= (INTERVAL_MATRIX &);
  INTERVAL_MATRIX & operator *= (INTERVAL &);
  INTERVAL_MATRIX & operator /= (INTERVAL &);
  INTERVAL_MATRIX & operator += (MATRIX &);
  INTERVAL_MATRIX & operator -= (MATRIX &);
  INTERVAL_MATRIX & operator *= (REAL);
  INTERVAL_MATRIX & operator /= (REAL);
  friend INT RowDimension (INTERVAL_MATRIX & x) { return x.nRows; }
  friend INT ColDimension (INTERVAL_MATRIX & x) { return x.nCols; }
  friend VOID Resize (INTERVAL_MATRIX &, INT, INT);
#ifdef __DONTCOPY__
  friend VOID MakeTemporary (INTERVAL_MATRIX & x) { x.IsTemporary = 1; }
  friend VOID MakePermanent (INTERVAL_MATRIX & x) { x.IsTemporary = 0; }
#else
  friend VOID MakeTemporary (INTERVAL_MATRIX & x) { }
  friend VOID MakePermanent (INTERVAL_MATRIX & x) { }
#endif
  friend VOID Clear (INTERVAL_MATRIX &);
  friend VOID Initialize (INTERVAL_MATRIX &, INTERVAL &);
  friend INTERVAL_VECTOR Row (INTERVAL_MATRIX &, INT);
  friend INTERVAL_VECTOR Col (INTERVAL_MATRIX &, INT);
  friend VOID SetRow (INTERVAL_MATRIX &, INT, INTERVAL_VECTOR &);
  friend VOID SetCol (INTERVAL_MATRIX &, INT, INTERVAL_VECTOR &);
  friend MATRIX Inf (INTERVAL_MATRIX &);
  friend MATRIX Sup (INTERVAL_MATRIX &);
  friend MATRIX Mid (INTERVAL_MATRIX &);
  friend MATRIX Diam (INTERVAL_MATRIX &);
  friend MATRIX Abs (INTERVAL_MATRIX &);
  friend INT Intersection (INTERVAL_MATRIX &, INTERVAL_MATRIX &, INTERVAL_MATRIX &);
  friend INT operator <= (MATRIX &, INTERVAL_MATRIX &);
  friend INT operator <= (INTERVAL_MATRIX &, INTERVAL_MATRIX &);
  friend INT operator <  (MATRIX &, INTERVAL_MATRIX &);
  friend INT operator <  (INTERVAL_MATRIX &, INTERVAL_MATRIX &);
  friend INT operator == (INTERVAL_MATRIX &, INTERVAL_MATRIX &);
  friend INT operator != (INTERVAL_MATRIX &, INTERVAL_MATRIX &);
  friend INTERVAL_MATRIX Hull (MATRIX &);
  friend INTERVAL_MATRIX Hull (MATRIX &, MATRIX &);
  friend INTERVAL_MATRIX Hull (MATRIX &, INTERVAL_MATRIX &);
  friend INTERVAL_MATRIX Hull (INTERVAL_MATRIX &, MATRIX &);
  friend INTERVAL_MATRIX Hull (INTERVAL_MATRIX &, INTERVAL_MATRIX &);
  friend INTERVAL_MATRIX SymHull (MATRIX & x) { return Hull (-x, x); }
  friend INTERVAL_MATRIX operator + (INTERVAL_MATRIX & a) { return a; }
  friend INTERVAL_MATRIX operator - (INTERVAL_MATRIX &);
  friend INTERVAL_MATRIX operator + (MATRIX &, INTERVAL_MATRIX &);
  friend INTERVAL_MATRIX operator + (INTERVAL_MATRIX &, MATRIX &);
  friend INTERVAL_MATRIX operator + (INTERVAL_MATRIX &, INTERVAL_MATRIX &);
  friend INTERVAL_MATRIX AddBounds  (MATRIX &, MATRIX &);
  friend INTERVAL_MATRIX operator - (MATRIX &, INTERVAL_MATRIX &);
  friend INTERVAL_MATRIX operator - (INTERVAL_MATRIX &, MATRIX &);
  friend INTERVAL_MATRIX operator - (INTERVAL_MATRIX &, INTERVAL_MATRIX &);
  friend INTERVAL_MATRIX SubBounds  (MATRIX &, MATRIX &);
  friend INTERVAL_MATRIX operator * (REAL, INTERVAL_MATRIX &);
  friend INTERVAL_MATRIX operator * (INTERVAL &, MATRIX &);
  friend INTERVAL_MATRIX operator * (INTERVAL &, INTERVAL_MATRIX &);
  friend INTERVAL_MATRIX MulBounds  (REAL, MATRIX &);
  friend INTERVAL_MATRIX operator / (INTERVAL_MATRIX &, REAL);
  friend INTERVAL_MATRIX operator / (MATRIX &, INTERVAL &);
  friend INTERVAL_MATRIX operator / (INTERVAL_MATRIX &, INTERVAL &);
  friend INTERVAL_MATRIX DivBounds  (MATRIX &, REAL);
  friend INTERVAL_VECTOR operator * (MATRIX &, INTERVAL_VECTOR &);
  friend INTERVAL_VECTOR operator * (INTERVAL_MATRIX &, VECTOR &);
  friend INTERVAL_VECTOR operator * (INTERVAL_MATRIX &, INTERVAL_VECTOR &);
  friend INTERVAL_VECTOR MulBounds  (MATRIX &, VECTOR &);
  friend INTERVAL_MATRIX operator * (MATRIX &, INTERVAL_MATRIX &);
  friend INTERVAL_MATRIX operator * (INTERVAL_MATRIX &, MATRIX &);
  friend INTERVAL_MATRIX operator * (INTERVAL_MATRIX &, INTERVAL_MATRIX &);
  friend INTERVAL_MATRIX MulBounds  (MATRIX &, MATRIX &);
  friend ostream & operator << (ostream &, INTERVAL_MATRIX &);
  friend istream & operator >> (istream &, INTERVAL_MATRIX &);
};

#endif /* __INTERVAL_MATRIX__ */
