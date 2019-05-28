/************************************************************************
*  IntegerVector.h (Definition of type INTEGER_VECTOR)
*
*  Version:                     1.9
*  Date:                        1/26/94
*  Author:                      O. Knueppel
*************************************************************************/

#ifndef __INTEGER_VECTOR__
#define __INTEGER_VECTOR__

#include "Portab.h"
#include "error.h"
#include <iostream.h>

class INTEGER_VECTOR {
  INT nElements;
#ifdef __DONTCOPY__
  INT IsTemporary;
#endif
public:
  PINT theElements;
  INTEGER_VECTOR ()
    {
#ifdef __DONTCOPY__
      IsTemporary = 0;
#endif
      nElements = 0; theElements = NULL; }
  INTEGER_VECTOR (INT n)
    {
#ifdef __DONTCOPY__
      IsTemporary = 0;
#endif
      CheckVectorRange (n);
      nElements = n;
      theElements = new INT[n];
      CheckMemory (theElements);
    }
  ~INTEGER_VECTOR ()
    { if (theElements != NULL) delete theElements; }
  INTEGER_VECTOR (INTEGER_VECTOR &);
  INT & operator () (INT i)
    { CheckVectorIndex (i, *this); return theElements[i-1]; }
  INTEGER_VECTOR & operator =  (INTEGER_VECTOR &);
  INTEGER_VECTOR & operator += (INTEGER_VECTOR &);
  INTEGER_VECTOR & operator -= (INTEGER_VECTOR &);
  INTEGER_VECTOR & operator *= (INT);
  INTEGER_VECTOR & operator /= (INT);
  friend INT Dimension (INTEGER_VECTOR & x) { return x.nElements; }
  friend VOID Resize (INTEGER_VECTOR &, INT);
#ifdef __DONTCOPY__
  friend VOID MakeTemporary (INTEGER_VECTOR & x) { x.IsTemporary = 1; }
  friend VOID MakePermanent (INTEGER_VECTOR & x) { x.IsTemporary = 0; }
#else
  friend VOID MakeTemporary (INTEGER_VECTOR & x) { }
  friend VOID MakePermanent (INTEGER_VECTOR & x) { }
#endif
  friend VOID Clear (INTEGER_VECTOR &);
  friend VOID Initialize (INTEGER_VECTOR &, INT);
  friend INTEGER_VECTOR operator + (INTEGER_VECTOR &, INTEGER_VECTOR &);
  friend INTEGER_VECTOR operator - (INTEGER_VECTOR &, INTEGER_VECTOR &);
  friend INTEGER_VECTOR operator * (INT             , INTEGER_VECTOR &);
  friend INTEGER_VECTOR operator / (INTEGER_VECTOR &, INT             );
  friend INT            operator * (INTEGER_VECTOR &, INTEGER_VECTOR &);
  friend ostream & operator << (ostream &, INTEGER_VECTOR &);
  friend istream & operator >> (istream &, INTEGER_VECTOR &);
};

#endif /* __INTEGER_VECTOR__ */
