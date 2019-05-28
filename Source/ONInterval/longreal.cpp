/************************************************************************
*  LongReal.C (Implementation of type LONGREAL)
*
*  Version:                     1.17
*  Date:                        11/10/94
*  Author:                      O. Knueppel
*************************************************************************/

static char sccs_id[] = "@(#)LongReal.C 1.17 94/11/10 OK";

//#include "stdafx.h"
#include "longreal.h"
#include "highprec.h"
#include <string.h>

class LONGREAL_INIT {
public:
  LONGREAL_INIT () { LrInit (); }
  ~LONGREAL_INIT () { };
};

static LONGREAL_INIT LongRealInit; // calls LrInit () automatically

USHORT LONGREAL::nCurrentDigits = 6;
USHORT LONGREAL::nOutFracDigits = 16;
USHORT LONGREAL::nOutIntDigits  = 3;
INT    LONGREAL::OutRndMode     = LR_RND_NEAR;

LONGREAL::LONGREAL (INT n)
{
#ifdef __DONTCOPY__
  isTemporary = 0;
#endif
  nDigits = nCurrentDigits;
  nGuards = n;
  value = LrNewTemp (nCurrentDigits, n);
}

LONGREAL::LONGREAL ()
{
#ifdef __DONTCOPY__
  isTemporary = 0;
#endif
  nDigits = nCurrentDigits;
  nGuards = 0;
  value = LrNewVar (nCurrentDigits);
}

LONGREAL::LONGREAL (REAL x)
{
#ifdef __DONTCOPY__
  isTemporary = 0;
#endif
  nDigits = nCurrentDigits;
  nGuards = 0;
  value = LrNewVar (nDigits);
  dtolr (value, & x);
}

LONGREAL::~LONGREAL ()
{
  if (value != NULL) LrDeleteTemp (value, nDigits, nGuards);
}

LONGREAL::LONGREAL (LONGREAL & x)
{
#ifdef __DONTCOPY__
  isTemporary = 1;
  nDigits = nCurrentDigits;
  nGuards = 0;
  if (x.isTemporary && (nDigits == x.nDigits)) {
    nGuards = x.nGuards;
    value = x.value;
    x.value = NULL;
  }
  else {
    value = LrNewVar (nDigits);
    LrAssign (value, x.value, 1);
  }
#else
  nDigits = nCurrentDigits;
  nGuards = 0;
  value = LrNewVar (nDigits);
  LrAssign (value, x.value, 1);
#endif
}

LONGREAL::LONGREAL (PCHAR sz, INT n)
{
#ifdef __DONTCOPY__
  isTemporary = 0;
#endif
  nDigits = (USHORT) (((13607L * (LONG) ((n == 0) ? strlen (sz) : n) + 65535L) >> 16) + 1);
  nGuards = 16;
  value = LrNewTemp (nDigits, nGuards);
  StringToLr (value, sz);
}

LONGREAL & LONGREAL::operator = (LONGREAL & x)
{
#ifdef __DONTCOPY__
  if ((nDigits == nCurrentDigits) && (nDigits == x.nDigits)) {
    if (value == x.value) return *this;
    if (x.isTemporary) {
      if (value != NULL) LrDeleteTemp (value, nDigits, nGuards);
      nGuards = x.nGuards;
      value = x.value;
      x.value = NULL;
    }
    else {
      LrSetPosDigits (value, nDigits);
      LrAssign (value, x.value, 1);
    }
  }
  else {
    if (value == x.value) {
      if (nDigits != nCurrentDigits) {
	USHORT nDigitsOld;
	USHORT nGuardsOld;
	LREAL valueOld;

	nDigitsOld = nDigits;
	nGuardsOld = nGuards;
	valueOld = x.value;
	nDigits = nCurrentDigits;
	nGuards = 0;
	value = LrNewVar (nDigits);
	LrAssign (valueOld, value, 1);
	LrDeleteTemp (valueOld, nDigitsOld, nGuardsOld);
      }
      return *this;
    }
    if (nDigits != nCurrentDigits) {
      if (value != NULL) LrDeleteTemp (value, nDigits, nGuards);
      nDigits = nCurrentDigits;
      nGuards = 0;
      value = LrNewVar (nDigits);
    }
    else LrSetPosDigits (value, nDigits);
    LrAssign (value, x.value, 1);
  }
#else
  if (value == x.value) {
    if (nDigits != nCurrentDigits) {
      USHORT nDigitsOld;
      USHORT nGuardsOld;
      LREAL valueOld;

      nDigitsOld = nDigits;
      nGuardsOld = nGuards;
      valueOld = x.value;
      nDigits = nCurrentDigits;
      nGuards = 0;
      value = LrNewVar (nDigits);
      LrAssign (valueOld, value, 1);
      LrDeleteTemp (valueOld, nDigitsOld, nGuardsOld);
    }
    return *this;
  }
  if (nDigits != nCurrentDigits) {
    if (value != NULL) LrDeleteTemp (value, nDigits, nGuards);
    nDigits = nCurrentDigits;
    nGuards = 0;
    value = LrNewVar (nDigits);
  }
  else LrSetPosDigits (value, nDigits);
  LrAssign (value, x.value, 1);
#endif
  return *this;
}

LONGREAL & LONGREAL::operator = (REAL x)
{
  if ((nDigits != nCurrentDigits) || (nGuards != 0)) {
    if (value != NULL) LrDeleteTemp (value, nDigits, nGuards);
    nDigits = nCurrentDigits;
    nGuards = 0;
    value = LrNewVar (nDigits);
  }
  dtolr (value, & x);
  return *this;
}

REAL RoundToReal (LONGREAL & x, INT RndMode)
{
  DOUBLE d;
  lrtod (& d, Value(x), RndMode);
  return (REAL) d;
}

LONGREAL & LONGREAL::operator += (LONGREAL & x)
{
  *this = *this + x;
  return *this;
}

LONGREAL & LONGREAL::operator += (REAL x)
{
  *this = *this + x;
  return *this;
}

LONGREAL & LONGREAL::operator -= (LONGREAL & x)
{
  *this = *this - x;
  return *this;
}

LONGREAL & LONGREAL::operator -= (REAL x)
{
  *this = *this - x;
  return *this;
}

LONGREAL & LONGREAL::operator *= (LONGREAL & x)
{
  *this = *this * x;
  return *this;
}

LONGREAL & LONGREAL::operator *= (REAL x)
{
  *this = *this * x;
  return *this;
}

LONGREAL & LONGREAL::operator /= (LONGREAL & x)
{
  *this = *this / x;
  return *this;
}

LONGREAL & LONGREAL::operator /= (REAL x)
{
  *this = *this / x;
  return *this;
}

LONGREAL & LONGREAL::operator ++ ()
{
  LrSucc (value, nDigits);
  return *this;
}

LONGREAL & LONGREAL::operator -- ()
{
  LrPred (value, nDigits);
  return *this;
}

LONGREAL operator - (LONGREAL & x)
{
  LONGREAL y;
  MakeTemporary (y);
  y = x;
  LrNegative (y.value);
  return y;
}

LONGREAL operator + (LONGREAL & a, REAL r)
{
  LONGREAL lr;
  lr = r;
  return a + lr;
}

LONGREAL operator + (REAL r, LONGREAL & a)
{
  LONGREAL lr;
  lr = r;
  return lr + a;
}

LONGREAL operator + (LONGREAL & a, LONGREAL & b)
{
  LONGREAL c(2);
  MakeTemporary (c);
  LrAdd (Value(a), Value(b), Value(c), 1);
  return c;
}

LONGREAL operator - (LONGREAL & a, REAL r)
{
  LONGREAL lr;
  lr = r;
  return a - lr;
}

LONGREAL operator - (REAL r, LONGREAL & a)
{
  LONGREAL lr;
  lr = r;
  return lr - a;
}

LONGREAL operator - (LONGREAL & a, LONGREAL & b)
{
  LONGREAL c(2);
  MakeTemporary (c);
  LrSub (Value(a), Value(b), Value(c), 1);
  return c;
}

LONGREAL operator * (LONGREAL & a, REAL r)
{
  LONGREAL lr;
  lr = r;
  return a * lr;
}

LONGREAL operator * (REAL r, LONGREAL & a)
{
  LONGREAL lr;
  lr = r;
  return lr * a;
}

LONGREAL operator * (LONGREAL & a, LONGREAL & b)
{
  LONGREAL c(4);
  MakeTemporary (c);
  LrMul (Value(a), Value(b), Value(c), 1);
  return c;
}

LONGREAL operator / (LONGREAL & a, REAL r)
{
  LONGREAL lr;
  lr = r;
  return a / lr;
}

LONGREAL operator / (REAL r, LONGREAL & a)
{
  LONGREAL lr;
  lr = r;
  return lr / a;
}

LONGREAL operator / (LONGREAL & a, LONGREAL & b)
{
  LONGREAL c(2), wrk(32);
  MakeTemporary (c);
  LrDiv (Value(a), Value(b), Value(c), Value(wrk), 1);
  return c;
}

VOID StringToLr (LREAL lr, PCHAR sz)
// Converts a string to a long real
// NOTE: lr must have at least 16 guard digits
{
  PCHAR szOut;
  PVOID wrk1, wrk2, wrk3, wrk4;

  USHORT  m     = ((ULONG) LrDigits (lr) * 78913L + 364804L) >> 16;
  USHORT Size1  = (m + 1) * sizeof (USHORT) + sizeof (LONG);
  USHORT Size2  = (LrDigits (lr) + 16) * sizeof (LDIGIT) + sizeof (LREALHDR);
  USHORT Size3  = (LrDigits (lr) + 32) * sizeof (LDIGIT) + sizeof (LREALHDR);

  wrk1 = MemNew (Size1);
  wrk2 = MemNew (Size2);
  wrk3 = MemNew (Size2);
  wrk4 = MemNew (Size3);

  lrsztolr (sz, &szOut, lr, wrk1, wrk2, wrk3, wrk4, 1);

  MemDelete (wrk4, Size3);
  MemDelete (wrk3, Size2);
  MemDelete (wrk2, Size2);
  MemDelete (wrk1, Size1);
}

LONGREAL StringToLongReal (PCHAR sz)
{
  LONGREAL x(16);

  MakeTemporary (x);
  StringToLr (Value (x), sz);
  return x;
}

istream & operator >> (istream & i, LONGREAL & x)
{
  static CHAR sz[1024];
  LONGREAL xtmp(16);

  MakeTemporary (xtmp);
  i >> sz;
  StringToLr (Value (xtmp), sz);
  x = xtmp;
  return i;
}

ostream & operator << (ostream & o, LONGREAL & x)
{
  LREAL lr = Value(x);
  USHORT FracDigits = LONGREAL::nOutFracDigits;
  INT    Rnd        = LONGREAL::OutRndMode;
  PCHAR   res;
  PVOID   wrk1,
	  wrk2,
	  wrk3;
  USHORT  Len;
  USHORT  Size1;
  USHORT  Size2;
  LONG	  Exp10;

  if (FracDigits < 1) FracDigits = 1;

  Len	= (USHORT) (( ((((LONG) FracDigits + 9) >> 2) << 16) + 83845L) / 78913L);
  Size1 = (Len + 14) * sizeof (LDIGIT) + sizeof (LREALHDR);
  Size2 = (Len + 33) * sizeof (LDIGIT);

  res  = (PCHAR) MemNew (FracDigits + 13);
  wrk1 = MemNew (Size1);
  wrk2 = MemNew (Size1);
  wrk3 = MemNew (Size2);

  o << lrtosze (lr, res, FracDigits, 1, Rnd, wrk1, wrk2, wrk3, &Exp10);

  MemDelete (wrk3, Size2);
  MemDelete (wrk2, Size1);
  MemDelete (wrk1, Size1);
  MemDelete ((PVOID) res, FracDigits + 13);

  return o;
}

VOID Accumulate (LONGREAL & x, VECTOR & a, VECTOR & b)
{
  INT dim = Dimension (a);
  INT g;
  LREAL laccu1, laccu2;

  CheckDimensions (a, b);
  laccu1 = HighPrecScalpLr (a.theElements, b.theElements, 1, dim);
  laccu2 = x.value;
  g = x.nGuards;
  x.nGuards = 2;
  x.value = LrNewTemp (x.nDigits, x.nGuards);
  LrAdd (laccu1, laccu2, x.value, 1);
  LrDeleteTemp (laccu2, x.nDigits, g);
}

INT GetDigits ()
{
  return (INT) ((((ULONG) LONGREAL::nCurrentDigits) << 16) / 13607L);
}

INT GetBaseDigits ()
{
  return (INT) LONGREAL::nCurrentDigits;
}

INT GetOutFracDigits ()
{
  return (INT) LONGREAL::nOutFracDigits;
}

INT GetOutIntDigits ()
{
  return (INT) LONGREAL::nOutIntDigits;
}

INT GetOutRndMode ()
{
  return LONGREAL::OutRndMode;
}

VOID SetDigits (INT n)
{
  LONGREAL::nCurrentDigits = (USHORT) (((13607L * (LONG) n + 65535L) >> 16) + 1);
}

VOID SetBaseDigits (INT n)
{
  LONGREAL::nCurrentDigits = (USHORT) n;
}

VOID SetOutFracDigits (INT n)
{
  LONGREAL::nOutFracDigits = (USHORT) n;
}

VOID SetOutIntDigits (INT n)
{
  LONGREAL::nOutIntDigits = (USHORT) n;
}

VOID SetOutRndMode (INT n)
{
  LONGREAL::OutRndMode =  n;
}

// The following routine is only used for reference in NiceIntervalOutput.C
// in order to force the loader to bind this file into the executable code.

VOID RegisterLongReal () { }
