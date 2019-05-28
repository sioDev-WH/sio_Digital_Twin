/************************************************************************
*  IntervalVector.h (Definition of type INTERVAL_VECTOR)
*
*  Version:                     1.17
*  Date:                        1/30/95
*  Author:                      O. Knueppel
*************************************************************************/

#ifndef __INTERVAL_VECTOR__
#define __INTERVAL_VECTOR__

#include "Bias1.h"
#include "error.h"
#include "vector.h"
#include "ival.h"
#include <memory.h>

class INTERVAL_VECTOR {
  INT nElements;
#ifdef __DONTCOPY__
  INT IsTemporary;
#endif
public:
  PBIASINTERVAL theElements;
  INTERVAL_VECTOR ()
    {
#ifdef __DONTCOPY__
      IsTemporary = 0;
#endif
      nElements = 0; theElements = NULL; }
  INTERVAL_VECTOR (INT n)
    {
#ifdef __DONTCOPY__
      IsTemporary = 0;
#endif
      CheckVectorRange (n);
      nElements = n;
      theElements = new BIASINTERVAL[n];
      CheckMemory (theElements);
    }
  ~INTERVAL_VECTOR ()
    { if (theElements != NULL) delete theElements; }
  INTERVAL_VECTOR (INTERVAL_VECTOR &);
  INTERVAL & operator () (INT i)
    { CheckVectorIndex (i, *this); return * ((INTERVAL *)(theElements + i-1)); }
  INTERVAL_VECTOR & operator =  (INTERVAL_VECTOR &);
  INTERVAL_VECTOR & operator =  (VECTOR &);
  INTERVAL_VECTOR & operator += (INTERVAL_VECTOR &);
  INTERVAL_VECTOR & operator -= (INTERVAL_VECTOR &);
  INTERVAL_VECTOR & operator *= (INTERVAL &);
  INTERVAL_VECTOR & operator /= (INTERVAL &);
  INTERVAL_VECTOR & operator += (VECTOR &);
  INTERVAL_VECTOR & operator -= (VECTOR &);
  INTERVAL_VECTOR & operator *= (REAL);
  INTERVAL_VECTOR & operator /= (REAL);
  friend INT Dimension (INTERVAL_VECTOR & x) { return x.nElements; }
  friend VOID Resize (INTERVAL_VECTOR &, INT);
#ifdef __DONTCOPY__
  friend VOID MakeTemporary (INTERVAL_VECTOR & x) { x.IsTemporary = 1; }
  friend VOID MakePermanent (INTERVAL_VECTOR & x) { x.IsTemporary = 0; }
#else
  friend VOID MakeTemporary (INTERVAL_VECTOR & x) { }
  friend VOID MakePermanent (INTERVAL_VECTOR & x) { }
#endif
  friend VOID Clear (INTERVAL_VECTOR &);
  friend VOID Initialize (INTERVAL_VECTOR &, INTERVAL &);
  friend VECTOR Inf (INTERVAL_VECTOR &);
  friend VECTOR Sup (INTERVAL_VECTOR &);
  friend VECTOR Mid (INTERVAL_VECTOR &);
  friend VECTOR Diam (INTERVAL_VECTOR &);
  friend VECTOR Abs (INTERVAL_VECTOR &);
  friend INT Intersection (INTERVAL_VECTOR &, INTERVAL_VECTOR &, INTERVAL_VECTOR &);
  friend INT operator <= (VECTOR &, INTERVAL_VECTOR &);
  friend INT operator <= (INTERVAL_VECTOR &, INTERVAL_VECTOR &);
  friend INT operator <  (VECTOR &, INTERVAL_VECTOR &);
  friend INT operator <  (INTERVAL_VECTOR &, INTERVAL_VECTOR &);
  friend INT operator == (INTERVAL_VECTOR &, INTERVAL_VECTOR &);
  friend INT operator != (INTERVAL_VECTOR &, INTERVAL_VECTOR &);
  friend INTERVAL_VECTOR Hull (VECTOR &);
  friend INTERVAL_VECTOR Hull (VECTOR &, VECTOR &);
  friend INTERVAL_VECTOR Hull (VECTOR &, INTERVAL_VECTOR &);
  friend INTERVAL_VECTOR Hull (INTERVAL_VECTOR &, VECTOR &);
  friend INTERVAL_VECTOR Hull (INTERVAL_VECTOR &, INTERVAL_VECTOR &);
  friend INTERVAL_VECTOR SymHull (VECTOR & x) { return Hull (-x, x); }
  friend INTERVAL_VECTOR operator + (INTERVAL_VECTOR & a) { return a; }
  friend INTERVAL_VECTOR operator - (INTERVAL_VECTOR &);
  friend INTERVAL_VECTOR operator + (VECTOR &, INTERVAL_VECTOR &);
  friend INTERVAL_VECTOR operator + (INTERVAL_VECTOR &, VECTOR &);
  friend INTERVAL_VECTOR operator + (INTERVAL_VECTOR &, INTERVAL_VECTOR &);
  friend INTERVAL_VECTOR AddBounds  (VECTOR &, VECTOR &);
  friend INTERVAL_VECTOR operator - (VECTOR &, INTERVAL_VECTOR &);
  friend INTERVAL_VECTOR operator - (INTERVAL_VECTOR &, VECTOR &);
  friend INTERVAL_VECTOR operator - (INTERVAL_VECTOR &, INTERVAL_VECTOR &);
  friend INTERVAL_VECTOR SubBounds  (VECTOR &, VECTOR &);
  friend INTERVAL_VECTOR operator * (REAL, INTERVAL_VECTOR &);
  friend INTERVAL_VECTOR operator * (INTERVAL &, VECTOR &);
  friend INTERVAL_VECTOR operator * (INTERVAL &, INTERVAL_VECTOR &);
  friend INTERVAL_VECTOR MulBounds  (REAL, VECTOR &);
  friend INTERVAL_VECTOR operator / (INTERVAL_VECTOR &, REAL);
  friend INTERVAL_VECTOR operator / (VECTOR &, INTERVAL &);
  friend INTERVAL_VECTOR operator / (INTERVAL_VECTOR &, INTERVAL &);
  friend INTERVAL_VECTOR DivBounds  (VECTOR &, REAL);
  friend INTERVAL operator * (VECTOR &, INTERVAL_VECTOR &);
  friend INTERVAL operator * (INTERVAL_VECTOR &, VECTOR &);
  friend INTERVAL operator * (INTERVAL_VECTOR &, INTERVAL_VECTOR &);
  friend INTERVAL MulBounds  (VECTOR &, VECTOR &);
  friend INTERVAL Sqr  (INTERVAL_VECTOR &);
  friend INTERVAL Norm (INTERVAL_VECTOR &);
  friend ostream & operator << (ostream &, INTERVAL_VECTOR &);
  friend istream & operator >> (istream &, INTERVAL_VECTOR &);
};

#endif /* __INTERVAL_VECTOR__ */
