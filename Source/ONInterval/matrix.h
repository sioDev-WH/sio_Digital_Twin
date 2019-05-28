/************************************************************************
*  Matrix.h (Definition of type MATRIX)
*
*  Version:                     1.15
*  Date:                        1/30/95
*  Author:                      O. Knueppel
*************************************************************************/

#ifndef __MATRIX__
#define __MATRIX__

#include "Portab.h"
#include "error.h"
#include "vector.h"

class MATRIX {
  INT nRows;
  INT nCols;
#ifdef __DONTCOPY__
  INT IsTemporary;
#endif
public:
  PREAL theElements;
  MATRIX ()
    {
#ifdef __DONTCOPY__
      IsTemporary = 0;
#endif
      nRows = nCols = 0; theElements = NULL; }
  MATRIX (INT r, INT c)
    {
#ifdef __DONTCOPY__
      IsTemporary = 0;
#endif
      CheckMatrixRange (r, c);
      nRows = r; nCols = c;
      theElements = new REAL[r * c];
      CheckMemory (theElements);
    }
  ~MATRIX ()
    { if (theElements != NULL) delete theElements; }
  MATRIX (MATRIX &);
  REAL & operator () (INT i, INT j)
    { CheckMatrixIndex (i, j, *this); return theElements[(i-1) * nCols + (j-1)]; }
  MATRIX & operator =  (MATRIX &);
  MATRIX & operator += (MATRIX &);
  MATRIX & operator -= (MATRIX &);
  MATRIX & operator *= (REAL);
  MATRIX & operator /= (REAL);
  friend INT RowDimension (MATRIX & x) { return x.nRows; }
  friend INT ColDimension (MATRIX & x) { return x.nCols; }
  friend VOID Resize (MATRIX &, INT, INT);
#ifdef __DONTCOPY__
  friend VOID MakeTemporary (MATRIX & x) { x.IsTemporary = 1; }
  friend VOID MakePermanent (MATRIX & x) { x.IsTemporary = 0; }
#else
  friend VOID MakeTemporary (MATRIX & x) { }
  friend VOID MakePermanent (MATRIX & x) { }
#endif
  friend VOID Clear (MATRIX &);
  friend VOID Initialize (MATRIX &, REAL);
  friend VECTOR Row (MATRIX &, INT);
  friend VECTOR Col (MATRIX &, INT);
  friend VOID SetRow (MATRIX &, INT, VECTOR &);
  friend VOID SetCol (MATRIX &, INT, VECTOR &);
  friend MATRIX operator + (MATRIX & a) { return a; }
  friend MATRIX operator - (MATRIX &);
  friend MATRIX operator + (MATRIX &, MATRIX &);
  friend MATRIX operator - (MATRIX &, MATRIX &);
  friend MATRIX operator * (REAL    , MATRIX &);
  friend MATRIX operator / (MATRIX &, REAL    );
  friend VECTOR operator * (MATRIX &, VECTOR &);
  friend MATRIX operator * (MATRIX &, MATRIX &);
  friend INT    operator <  (MATRIX &, MATRIX &);
  friend INT    operator <= (MATRIX &, MATRIX &);
  friend INT    operator >  (MATRIX &, MATRIX &);
  friend INT    operator >= (MATRIX &, MATRIX &);
  friend MATRIX Abs (MATRIX &);
  friend ostream & operator << (ostream &, MATRIX &);
  friend istream & operator >> (istream &, MATRIX &);
};

#endif /* __MATRIX__ */
