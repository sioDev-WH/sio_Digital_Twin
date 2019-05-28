/************************************************************************
*  LongReal.h (Definition of type LONGREAL)
*
*  Version:                     1.12
*  Date:                        1/31/94
*  Author:                      O. Knueppel
*************************************************************************/

#ifndef __LONGREAL__
#define __LONGREAL__

#include "config.h"
#include "vector.h"
#include "Lr.h"
#include "DynMem.h"

class LONGREAL {
  static USHORT nCurrentDigits;       // current total number of digits
  static USHORT nOutFracDigits;       // total number of fraction digits for output
  static USHORT nOutIntDigits;        // total number of integer digits for output
                                      // (long intervals only)
  static INT    OutRndMode;           // rounding mode for output

  USHORT nDigits;                     // total number of digits (long real base)
  USHORT nGuards;                     // number of guard digits (long real base)
#ifdef __DONTCOPY__
  INT    isTemporary;                 // set, if variable is only temporary
#endif
  LREAL  value;                       // pointer to long real number
  LONGREAL (INT);                     // private to avoid typecast INT -> LONGREAL
public:
  LONGREAL ();
  LONGREAL (REAL);
  LONGREAL (LONGREAL &);
  LONGREAL (PCHAR, INT n = 0);
  ~LONGREAL ();
  LONGREAL & operator = (LONGREAL &);
  LONGREAL & operator = (REAL);
  LONGREAL & operator += (LONGREAL &);
  LONGREAL & operator += (REAL);
  LONGREAL & operator -= (LONGREAL &);
  LONGREAL & operator -= (REAL);
  LONGREAL & operator *= (LONGREAL &);
  LONGREAL & operator *= (REAL);
  LONGREAL & operator /= (LONGREAL &);
  LONGREAL & operator /= (REAL);
  LONGREAL & operator ++ ();
  LONGREAL & operator -- ();
#ifdef __DONTCOPY__
  friend VOID MakeTemporary (LONGREAL & x) { x.isTemporary = 1; }
  friend VOID MakePermanent (LONGREAL & x) { x.isTemporary = 0; }
#else
  friend VOID MakeTemporary (LONGREAL & x) { }
  friend VOID MakePermanent (LONGREAL & x) { }
#endif
  friend LREAL Value (LONGREAL & x) { return x.value; }
  friend REAL RoundToReal (LONGREAL & x, INT RndMode = LR_RND_NEAR);
  friend VOID Accumulate (LONGREAL &, VECTOR &, VECTOR &);
  friend LONGREAL StringToLongReal (PCHAR);
  friend LONGREAL operator - (LONGREAL &);
  friend LONGREAL operator + (LONGREAL &, REAL);
  friend LONGREAL operator + (REAL,       LONGREAL &);
  friend LONGREAL operator + (LONGREAL &, LONGREAL &);
  friend LONGREAL operator - (LONGREAL &, REAL);
  friend LONGREAL operator - (REAL,       LONGREAL &);
  friend LONGREAL operator - (LONGREAL &, LONGREAL &);
  friend LONGREAL operator * (LONGREAL &, REAL);
  friend LONGREAL operator * (REAL,       LONGREAL &);
  friend LONGREAL operator * (LONGREAL &, LONGREAL &);
  friend LONGREAL operator / (LONGREAL &, REAL);
  friend LONGREAL operator / (REAL,       LONGREAL &);
  friend LONGREAL operator / (LONGREAL &, LONGREAL &);
  friend INT operator == (LONGREAL & a, LONGREAL & b)
    { return (LrCmp (Value(a), Value(b)) == LR_EQ); }
  friend INT operator != (LONGREAL & a, LONGREAL & b)
    { return (LrCmp (Value(a), Value(b)) != LR_EQ); }
  friend INT operator <  (LONGREAL & a, LONGREAL & b)
    { return (LrCmp (Value(a), Value(b)) == LR_LT); }
  friend INT operator <= (LONGREAL & a, LONGREAL & b)
    {
      INT c;
      c =  LrCmp (Value(a), Value(b));
      return (c == LR_LT) || (c == LR_EQ);
    }
  friend INT operator >  (LONGREAL & a, LONGREAL & b)
    { return (LrCmp (Value(a), Value(b)) == LR_GT); }
  friend INT operator >= (LONGREAL & a, LONGREAL & b)
    {
      INT c;
      c =  LrCmp (Value(a), Value(b));
      return (c == LR_GT) || (c == LR_EQ);
    }
  friend INT GetDigits ();
  friend INT GetBaseDigits ();
  friend INT GetOutFracDigits ();
  friend INT GetOutIntDigits ();
  friend INT GetOutRndMode ();
  friend VOID SetDigits (INT);
  friend VOID SetBaseDigits (INT);
  friend VOID SetOutFracDigits (INT);
  friend VOID SetOutIntDigits (INT);
  friend VOID SetOutRndMode (INT);
  friend istream & operator >> (istream &, LONGREAL &);
  friend ostream & operator << (ostream &, LONGREAL &);
};

VOID StringToLr (LREAL, PCHAR);

#endif /* __LONGREAL__ */
