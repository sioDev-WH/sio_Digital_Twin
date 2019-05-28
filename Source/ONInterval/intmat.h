/************************************************************************
*  IntegerMatrix.h (Definition of type INTEGER_MATRIX)
*
*  Version:                     1.8
*  Date:                        1/26/94
*  Author:                      O. Knueppel
*************************************************************************/

#ifndef __INTEGER_MATRIX__
#define __INTEGER_MATRIX__

#include "Portab.h"
#include "error.h"
#include "intvec.h"

class INTEGER_MATRIX {
  INT nRows;
  INT nCols;
#ifdef __DONTCOPY__
  INT IsTemporary;
#endif
public:
  PINT theElements;
  INTEGER_MATRIX ()
    {
#ifdef __DONTCOPY__
      IsTemporary = 0;
#endif
      nRows = nCols = 0; theElements = NULL; }
  INTEGER_MATRIX (INT r, INT c)
    {
#ifdef __DONTCOPY__
      IsTemporary = 0;
#endif
      CheckMatrixRange (r, c);
      nRows = r; nCols = c;
      theElements = new INT[r * c];
      CheckMemory (theElements);
    }
  ~INTEGER_MATRIX ()
    { if (theElements != NULL) delete theElements; }
  INTEGER_MATRIX (INTEGER_MATRIX &);
  INT & operator () (INT i, INT j)
    { CheckMatrixIndex (i, j, *this); return theElements[(i-1) * nCols + (j-1)]; }
  INTEGER_MATRIX & operator =  (INTEGER_MATRIX &);
  INTEGER_MATRIX & operator += (INTEGER_MATRIX &);
  INTEGER_MATRIX & operator -= (INTEGER_MATRIX &);
  INTEGER_MATRIX & operator *= (INT);
  INTEGER_MATRIX & operator /= (INT);
  friend INT RowDimension (const INTEGER_MATRIX & x) { return x.nRows; }
  friend INT ColDimension (const INTEGER_MATRIX & x) { return x.nCols; }
  friend VOID Resize (INTEGER_MATRIX &, INT, INT);
#ifdef __DONTCOPY__
  friend VOID MakeTemporary (INTEGER_MATRIX & x) { x.IsTemporary = 1; }
  friend VOID MakePermanent (INTEGER_MATRIX & x) { x.IsTemporary = 0; }
#else
  friend VOID MakeTemporary (INTEGER_MATRIX & x) { }
  friend VOID MakePermanent (INTEGER_MATRIX & x) { }
#endif
  friend VOID Clear (INTEGER_MATRIX &);
  friend VOID Initialize (INTEGER_MATRIX &, INT);
  friend INTEGER_MATRIX operator + (INTEGER_MATRIX &, INTEGER_MATRIX &);
  friend INTEGER_MATRIX operator - (INTEGER_MATRIX &, INTEGER_MATRIX &);
  friend INTEGER_MATRIX operator * (INT, INTEGER_MATRIX &);
  friend INTEGER_MATRIX operator / (INTEGER_MATRIX &, INT);
  friend INTEGER_VECTOR operator * (INTEGER_MATRIX &, INTEGER_VECTOR &);
  friend ostream & operator << (ostream &, INTEGER_MATRIX &);
  friend istream & operator >> (istream &, INTEGER_MATRIX &);
};

#endif /* __INTEGER_MATRIX__ */
