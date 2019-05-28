/************************************************************************
*  Vector.h (Definition of type VECTOR)
*
*  Version:                     1.16
*  Date:                        1/26/94
*  Author:                      O. Knueppel
*************************************************************************/

#ifndef __VECTOR__
#define __VECTOR__

#include "Portab.h"
#include "config.h"
#include "error.h"
#include <iostream.h>

class VECTOR {
  INT nElements;
#ifdef __DONTCOPY__
  INT IsTemporary;
#endif
public:
  PREAL theElements;
  VECTOR ()
    {
#ifdef __DONTCOPY__
      IsTemporary = 0;
#endif
      nElements = 0; theElements = NULL; }
  VECTOR (INT n)
    {
#ifdef __DONTCOPY__
      IsTemporary = 0;
#endif
      CheckVectorRange (n);
      nElements = n;
      theElements = new REAL[n];
      CheckMemory (theElements);
    }
  ~VECTOR ()
    { if (theElements != NULL) delete theElements; }
  VECTOR (VECTOR &);
  REAL & operator () (INT i)
    { CheckVectorIndex (i, *this); return theElements[i-1]; }
  VECTOR & operator =  (VECTOR &);
  VECTOR & operator += (VECTOR &);
  VECTOR & operator -= (VECTOR &);
  VECTOR & operator *= (REAL);
  VECTOR & operator /= (REAL);
  friend INT Dimension (VECTOR & x) { return x.nElements; }
  friend VOID Resize (VECTOR &, INT);
#ifdef __DONTCOPY__
  friend VOID MakeTemporary (VECTOR & x) { x.IsTemporary = 1; }
  friend VOID MakePermanent (VECTOR & x) { x.IsTemporary = 0; }
#else
  friend VOID MakeTemporary (VECTOR & x) { }
  friend VOID MakePermanent (VECTOR & x) { }
#endif
  friend VOID Clear (VECTOR &);
  friend VOID Initialize (VECTOR &, REAL);
  friend VECTOR operator + (VECTOR & a) { return a; }
  friend VECTOR operator - (VECTOR &);
  friend VECTOR operator + (VECTOR &, VECTOR &);
  friend VECTOR operator - (VECTOR &, VECTOR &);
  friend VECTOR operator * (REAL    , VECTOR &);
  friend VECTOR operator / (VECTOR &, REAL    );
  friend REAL   operator * (VECTOR &, VECTOR &);
  friend INT    operator <  (VECTOR &, VECTOR &);
  friend INT    operator <= (VECTOR &, VECTOR &);
  friend INT    operator >  (VECTOR &, VECTOR &);
  friend INT    operator >= (VECTOR &, VECTOR &);
  friend VECTOR Abs  (VECTOR &);
  friend REAL   Sqr  (VECTOR &);
  friend REAL   Norm (VECTOR &);
  friend REAL   Max  (VECTOR &);
  friend REAL   Min  (VECTOR &);
  friend ostream & operator << (ostream &, VECTOR &);
  friend istream & operator >> (istream &, VECTOR &);
};

#endif /* __VECTOR__ */
