/************************************************************************
*  LongInterval.h (Definition of type LONGINTERVAL)
*
*  Version:                     1.6
*  Date:                        1/31/94
*  Author:                      O. Knueppel
*************************************************************************/

#ifndef __LONGINTERVAL__
#define __LONGINTERVAL__

#include "config.h"
#include "longreal.h"
#include "ivalvec.h"
#include "Li.h"
#include "DynMem.h"

class LONGINTERVAL {
  static USHORT OutOptions;           // output options (long intervals only)
  USHORT nDigits;                     // total number of digits (long real base)
  USHORT nGuards;                     // number of guard digits (long real base)
#ifdef __DONTCOPY__
  INT    isTemporary;                 // set, if variable is only temporary
#endif
  LIREAL  value;                      // pointer to long real number
  LONGINTERVAL (INT);                 // private to avoid typecast INT -> LONGINTERVAL
public:
  LONGINTERVAL ();
  LONGINTERVAL (REAL);
  LONGINTERVAL (INTERVAL &);
  LONGINTERVAL (LONGREAL &);
  LONGINTERVAL (LONGINTERVAL &);
  LONGINTERVAL (PCHAR, INT n = 0);
  ~LONGINTERVAL ();
  LONGINTERVAL & operator = (REAL);
  LONGINTERVAL & operator = (INTERVAL &);
  LONGINTERVAL & operator = (LONGINTERVAL &);
  LONGINTERVAL & operator += (REAL);
  LONGINTERVAL & operator += (INTERVAL &);
  LONGINTERVAL & operator += (LONGINTERVAL &);
  LONGINTERVAL & operator -= (REAL);
  LONGINTERVAL & operator -= (INTERVAL &);
  LONGINTERVAL & operator -= (LONGINTERVAL &);
  LONGINTERVAL & operator *= (REAL);
  LONGINTERVAL & operator *= (INTERVAL &);
  LONGINTERVAL & operator *= (LONGINTERVAL &);
  LONGINTERVAL & operator /= (REAL);
  LONGINTERVAL & operator /= (INTERVAL &);
  LONGINTERVAL & operator /= (LONGINTERVAL &);
  friend LONGINTERVAL Hull (LONGREAL &);
  friend LONGINTERVAL Hull (LONGREAL &, LONGREAL &);
  friend LONGREAL Inf (LONGINTERVAL &);
  friend LONGREAL Sup (LONGINTERVAL &);
  friend LONGREAL Diam (LONGINTERVAL &);
  friend LONGREAL Mid (LONGINTERVAL &);
#ifdef __DONTCOPY__
  friend VOID MakeTemporary (LONGINTERVAL & x) { x.isTemporary = 1; }
  friend VOID MakePermanent (LONGINTERVAL & x) { x.isTemporary = 0; }
#else
  friend VOID MakeTemporary (LONGINTERVAL & x) { }
  friend VOID MakePermanent (LONGINTERVAL & x) { }
#endif
  friend LIREAL Value (LONGINTERVAL & x) { return x.value; }
  friend INTERVAL RoundToInterval (LONGINTERVAL &);
  friend LONGINTERVAL LongIntervalEnclosure (PCHAR);
  friend VOID Accumulate (LONGINTERVAL &, VECTOR &         , VECTOR &);
  friend VOID Accumulate (LONGINTERVAL &, VECTOR &         , INTERVAL_VECTOR &);
  friend VOID Accumulate (LONGINTERVAL &, INTERVAL_VECTOR &, VECTOR &);
  friend VOID Accumulate (LONGINTERVAL &, INTERVAL_VECTOR &, INTERVAL_VECTOR &);
  friend LONGINTERVAL operator - (LONGINTERVAL &);
  friend LONGINTERVAL operator + (LONGINTERVAL &, REAL);
  friend LONGINTERVAL operator + (LONGINTERVAL &, INTERVAL &);
  friend LONGINTERVAL operator + (REAL,           LONGINTERVAL &);
  friend LONGINTERVAL operator + (INTERVAL &,     LONGINTERVAL &);
  friend LONGINTERVAL operator + (LONGINTERVAL &, LONGINTERVAL &);
  friend LONGINTERVAL operator - (LONGINTERVAL &, REAL);
  friend LONGINTERVAL operator - (LONGINTERVAL &, INTERVAL &);
  friend LONGINTERVAL operator - (REAL,           LONGINTERVAL &);
  friend LONGINTERVAL operator - (INTERVAL &,     LONGINTERVAL &);
  friend LONGINTERVAL operator - (LONGINTERVAL &, LONGINTERVAL &);
  friend LONGINTERVAL operator * (LONGINTERVAL &, REAL);
  friend LONGINTERVAL operator * (LONGINTERVAL &, INTERVAL &);
  friend LONGINTERVAL operator * (REAL,           LONGINTERVAL &);
  friend LONGINTERVAL operator * (INTERVAL &,     LONGINTERVAL &);
  friend LONGINTERVAL operator * (LONGINTERVAL &, LONGINTERVAL &);
  friend LONGINTERVAL operator / (LONGINTERVAL &, REAL);
  friend LONGINTERVAL operator / (LONGINTERVAL &, INTERVAL &);
  friend LONGINTERVAL operator / (REAL,           LONGINTERVAL &);
  friend LONGINTERVAL operator / (INTERVAL &,     LONGINTERVAL &);
  friend LONGINTERVAL operator / (LONGINTERVAL &, LONGINTERVAL &);
  friend ostream & operator << (ostream &, LONGINTERVAL &);
  friend istream & operator >> (istream &, LONGINTERVAL &);
  friend INT GetOutOptions ();
  friend VOID SetOutOptions (INT);
};

VOID LiToOutput (ostream &, LIREAL);
VOID StringToLi (LIREAL, PCHAR);
INTERVAL Enclosure (PCHAR);

#endif /* __LONGINTERVAL__ */
