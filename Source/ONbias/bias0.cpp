/************************************************************************
*  Bias0IEEE.c (Basic Interval Arithmetic Subroutines Level 0)
*
*  Version:                     1.19
*  Date:                        1/25/94
*  Author:                      D. Husung, O. Knueppel
*  Interval Representation:     INFSUP
*  Interval Implementation:     IEEE
*************************************************************************/

static char sccs_id[] = "@(#)Bias0IEEE.c 1.19 94/01/25 DH/OK";

#include "Bias0.h"
#include "BiasInt.h"
#include <math.h>
#include <stdio.h>

/************************************************************************
*  Definition of Constants, Types, and Variables
*************************************************************************/

#if defined (__MSC__) || defined (__BORLANDC__) || defined (__ON_Machine__) \
  || (defined (__I386__) && defined (__GNUC__))
/* WAH added || defined (__ON_Machine__) */

INT _BiasCwRoundUp      = CW_ROUND_UP;
INT _BiasCwRoundDown    = CW_ROUND_DOWN;
INT _BiasCwRoundNear    = CW_ROUND_NEAR;

#elif defined(sparc) && defined(__GNUC__)

ULONG _BiasCwRoundUp    = 0x80000000L;
ULONG _BiasCwRoundDown  = 0xC0000000L;
ULONG _BiasCwRoundNear  = 0x00000000L;

#elif defined(__hppa) && defined(__GNUC__)

INT _BiasCwRoundUp      = 0x81C00L;
INT _BiasCwRoundDown    = 0x81E00L;
INT _BiasCwRoundNear    = 0x81800L;

#elif defined(mc68000) && defined(__GNUC__)

INT _BiasCwRoundUp      = 0x00000030L;
INT _BiasCwRoundDown    = 0x00000020L;
INT _BiasCwRoundNear    = 0x00000000L;

#endif


/* The macro SECURE has inserted in the cases where problems may
 * occur due to compiler depended code movements when using asm
 * statements.
 * Until now, all compilers using asm statements for changing
 * the rounding mode seem to cause problems.
 */
#if defined (__GNUC__) || defined (__MSC__) || defined (__BORLANDC__)
#define SECURE volatile
#else
#define SECURE
#endif

/*
ONBIAS_API REAL BiasEpsilon;
ONBIAS_API REAL BiasEta;
ONBIAS_API REAL BiasNaN;
ONBIAS_API REAL BiasPosInf;
ONBIAS_API REAL BiasNegInf;
*/

ONBIAS_API double BiasEpsilon;
ONBIAS_API double BiasEta;
ONBIAS_API double BiasNaN;
ONBIAS_API double BiasPosInf;
ONBIAS_API double BiasNegInf;


static PCHAR ErrorDivideByZero = "Division by Zero";

/************************************************************************
*  Implementation of local functions
*************************************************************************/

VOID _BiasError(PCHAR s)
  /**********************************************************************
   *  Report error message and abort
   */
{
  fprintf (stderr, "BIAS: %s\n", s);
  abort ();
}

/************************************************************************
*  Implementation of global functions
*************************************************************************/

#if defined (__MSC__) || defined (__BORLANDC__) || defined (__ON_Machine__) \
  || (defined (__I386__) && defined (__GNUC__))

VOID BiasRoundUp   (VOID) { _BiasRoundUp   (); }
VOID BiasRoundDown (VOID) { _BiasRoundDown (); }
VOID BiasRoundNear (VOID) { _BiasRoundNear (); }

#endif

VOID BiasInit (VOID)
  /**********************************************************************
   *  Initialization
   */
{
  VOLATILE REAL Last, Current, OnePlusCurrent;
  union UREAL { USHORT ushort[4]; DOUBLE real; };
  static union UREAL Infinity = {{ 0x0000, 0x0000, 0x0000, 0x0000 }};
  static union UREAL NaN      = {{ 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF }};

  /* Default routing mode */
  _BiasRoundNear ();

  /* Calculation of BiasEpsilon (min { x >= 0 : 1 + x > 1 }) */
  Current = 1.0;
  do
    {
      Last = Current;
      Current /= 2.0;
      OnePlusCurrent = 1.0 + Current;
    } while (OnePlusCurrent > 1.0);
  BiasEpsilon = Last;

  /* Calculation of BiasEta     (min { x > 0 }) */
  Current = Last;
  do
    {
      Last = Current;
      Current /= 2.0;
    } while (Current > 0.0);
  BiasEta = Last;

  /* Definition of special floating point numbers (+/-oo, NaN) */
  Infinity.ushort[D3OF4] = 0x7FF0; BiasPosInf = Infinity.real;
  Infinity.ushort[D3OF4] = 0xFFF0; BiasNegInf = Infinity.real;
  NaN.ushort     [D3OF4] = 0x7FFF; BiasNaN    = NaN.real;
} /* BiasInit */

REAL BiasPredR (const PREAL pa)
  /**********************************************************************
  *  Result: largest possible floating point number with r < a
  */
{
  VOLATILE REAL pr;

  _BiasRoundDown ();
  pr = *pa - BiasEta;
  _SetRoundToNearest();
  return pr;
} /* BiasPredR */

INT BiasPredI (const PBIASINTERVAL pR, const PBIASINTERVAL pA)
  /**********************************************************************
  *  R = largest possible interval with R.inf > A.inf and R.sup < A.sup
  *  Result: 1, if R is a true interval, 0 otherwise
  */
{
  _BiasRoundDown ();
  pR->sup = pA->sup - BiasEta;
  _BiasRoundUp ();
  pR->inf = pA->inf + BiasEta;
  _SetRoundToNearest();
  return (pR->inf <= pR->sup);
} /* BiasPredI */

REAL BiasSuccR (const PREAL pa)
  /**********************************************************************
  *  Result: smallest possible floating point number with r > a
  */
{
  VOLATILE REAL pr;

  _BiasRoundUp ();
  pr = *pa + BiasEta;
  _SetRoundToNearest();
  return pr;
} /* BiasSuccR */

VOID BiasSuccI (const PBIASINTERVAL pR, const PBIASINTERVAL pA)
  /**********************************************************************
  *  R = smallest possible interval with R.inf < A.inf and R.sup > A.sup
  */
{
  _BiasRoundDown ();
  pR->inf = pA->inf - BiasEta;
  _BiasRoundUp ();
  pR->sup = pA->sup + BiasEta;
  _SetRoundToNearest();
} /* BiasSuccI */

VOID BiasAddRR (const PBIASINTERVAL pR,
		const SECURE PREAL pa, const SECURE PREAL pb)
  /**********************************************************************
  *  R = a + b
  */
{
  _BiasRoundDown ();
  pR->inf = *pa + *pb;
  _BiasRoundUp ();
  pR->sup = *pa + *pb;
  _SetRoundToNearest();
} /* BiasAddRR */

VOID BiasAddRI (const PBIASINTERVAL pR,
		const PREAL pa, const PBIASINTERVAL pB)
  /**********************************************************************
  *  R = a + B
  */
{
  REAL a = *pa;

  _BiasRoundDown ();
  pR->inf = a + pB->inf;
  _BiasRoundUp ();
  pR->sup = a + pB->sup;
  _SetRoundToNearest();
} /* BiasAddRI */

VOID BiasAddII (const PBIASINTERVAL pR,
		const PBIASINTERVAL pA, const PBIASINTERVAL pB)
  /**********************************************************************
  *  R = A + B
  */
{
  _BiasRoundDown ();
  pR->inf = pA->inf + pB->inf;
  _BiasRoundUp ();
  pR->sup = pA->sup + pB->sup;
  _SetRoundToNearest();
} /* BiasAddII */

VOID BiasSubRR (const PBIASINTERVAL pR,
		const SECURE PREAL pa, const SECURE PREAL pb)
  /**********************************************************************
  *  R = a - b
  */
{
  _BiasRoundDown ();
  pR->inf = *pa - *pb;
  _BiasRoundUp ();
  pR->sup = *pa - *pb;
  _SetRoundToNearest();
} /* BiasSubRR */

VOID BiasSubRI (const PBIASINTERVAL pR,
		const PREAL pa, const PBIASINTERVAL pB)
  /**********************************************************************
  *  R = a - B
  *  Assertion: R != B
  */
{
  REAL a = *pa;

  _BiasRoundDown ();
  pR->inf = a - pB->sup;
  _BiasRoundUp ();
  pR->sup = a - pB->inf;
  _SetRoundToNearest();
} /* BiasSubRI */

VOID BiasSubIR (const PBIASINTERVAL pR,
		const PBIASINTERVAL pA, const PREAL pb)
  /**********************************************************************
  *  R = A - b
  */
{
  REAL b = *pb;

  _BiasRoundDown ();
  pR->inf = pA->inf - b;
  _BiasRoundUp ();
  pR->sup = pA->sup - b;
  _SetRoundToNearest();
} /* BiasSubRI */

VOID BiasSubII (const PBIASINTERVAL pR,
		const PBIASINTERVAL pA, const PBIASINTERVAL pB)
  /**********************************************************************
  *  R = A - B
  *  Assertion: R != B
  */
{
  _BiasRoundDown ();
  pR->inf = pA->inf - pB->sup;
  _BiasRoundUp ();
  pR->sup = pA->sup - pB->inf;
  _SetRoundToNearest();
} /* BiasSubII */

VOID BiasMulRR (const PBIASINTERVAL pR,
		const SECURE PREAL pa, const SECURE PREAL pb)
  /**********************************************************************
  *  R = a * b
  */
{
  _BiasRoundDown ();
  pR->inf = *pa * *pb;
  _BiasRoundUp ();
  pR->sup = *pa * *pb;
  _SetRoundToNearest();
} /* BiasMulRR */

VOID BiasMulRI (const PBIASINTERVAL pR,
		const SECURE PREAL pa, const PBIASINTERVAL pB)
  /**********************************************************************
  *  R = a * B
  *  Assertion: R != B
  */
{
  REAL a = *pa;

  _BiasRoundDown ();
  if (Sign (*pa) == 0) {                                /* a >= 0 */
    pR->inf = a * pB->inf;
    _BiasRoundUp();
    pR->sup = a * pB->sup;
  }
  else {                                                /* a < 0  */
    pR->inf = a * pB->sup;
    _BiasRoundUp ();
    pR->sup = a * pB->inf;
  }
  _SetRoundToNearest();
} /* BiasMulRI */

VOID BiasMulII (const PBIASINTERVAL pR,
		const SECURE PBIASINTERVAL pA,
		const SECURE PBIASINTERVAL pB)
  /**********************************************************************
  *  R = A * B
  *  Assertion: R != A and R != B
  */
{
  _BiasRoundDown ();
  if (Sign (pA->inf) == 0) {                            /* A >= 0 */
    if (Sign (pB->inf) == 0) {                          /* B >= 0 */
      pR->inf = pA->inf * pB->inf;
      _BiasRoundUp ();
      pR->sup = pA->sup * pB->sup;
    }
    else if (Sign (pB->sup)) {                          /* B <= 0 */
      pR->inf = pA->sup * pB->inf;
      _BiasRoundUp ();
      pR->sup = pA->inf * pB->sup;
    }
    else {                                              /* 0 in B */
      pR->inf = pA->sup * pB->inf;
      _BiasRoundUp ();
      pR->sup = pA->sup * pB->sup;
    }
  }
  else if (Sign (pA->sup)) {                            /* A <= 0 */
    if (Sign (pB->inf) == 0) {                          /* B >= 0 */
      pR->inf = pA->inf * pB->sup;
      _BiasRoundUp ();
      pR->sup = pA->sup * pB->inf;
    }
    else if (Sign (pB->sup)) {                          /* B <= 0 */
      pR->inf = pA->sup * pB->sup;
      _BiasRoundUp ();
      pR->sup = pA->inf * pB->inf;
    }
    else {                                              /* 0 in B */
      pR->inf = pA->inf * pB->sup;
      _BiasRoundUp ();
      pR->sup = pA->inf * pB->inf;
    }
  }
  else {                                                /* 0 in A */
    if (Sign (pB->inf) == 0) {                          /* B >= 0 */
      pR->inf = pA->inf * pB->sup;
      _BiasRoundUp ();
      pR->sup = pA->sup * pB->sup;
    }
    else if (Sign (pB->sup)) {                          /* B <= 0 */
      pR->inf = pA->sup * pB->inf;
      _BiasRoundUp ();
      pR->sup = pA->inf * pB->inf;
    }
    else {                                              /* 0 in B */
      SECURE REAL r1 = pA->inf * pB->sup;
      SECURE REAL r2 = pA->sup * pB->inf;

      pR->inf = r1 < r2 ? r1 : r2;

      _BiasRoundUp ();

      r1 = pA->inf * pB->inf;
      r2 = pA->sup * pB->sup;

      pR->sup = r1 > r2 ? r1 : r2;
    }
  }
  _SetRoundToNearest();
} /* BiasMulII */

VOID BiasDivRR (const PBIASINTERVAL pR,
		const SECURE PREAL pa, const SECURE PREAL pb)
  /**********************************************************************
  *  R = a / b
  */
{
#if defined (__BIASRAISEDIVIDEBYZERO__)
  if (Zero (*pb)) _BiasError (ErrorDivideByZero);
#endif
  _BiasRoundDown ();
  pR->inf = *pa / *pb;
  _BiasRoundUp ();
  pR->sup = *pa / *pb;
  _SetRoundToNearest();
} /* BiasDivRR */

VOID BiasDivRI (const PBIASINTERVAL pR,
		const SECURE PREAL pa, const PBIASINTERVAL pB)
  /**********************************************************************
  *  R = a / B
  *  Assertion: R != B
  */
{
  REAL a = *pa;

  if ((Sign(pB->sup) == 0) && (Sign(pB->inf) || Zero(pB->inf)))
    {
#if defined (__BIASRAISEDIVIDEBYZERO__)
      _BiasError (ErrorDivideByZero);
#else
      if (Zero (*pa)) pR->sup = pR->inf = BiasNaN;
      else { pR->inf = BiasNegInf; pR->sup = BiasPosInf; }
#endif
      return;
    }
  _BiasRoundDown ();
  if (Sign (*pa) == 0) {                                /* a >= 0 */
    pR->inf = a / pB->sup;
    _BiasRoundUp();
    pR->sup = a / pB->inf;
  }
  else {                                                /* a < 0  */
    pR->inf = a / pB->inf;
    _BiasRoundUp ();
    pR->sup = a / pB->sup;
  }
  _SetRoundToNearest();
} /* BiasDivRI */

VOID BiasDivIR (const PBIASINTERVAL pR,
		const PBIASINTERVAL pA, const SECURE PREAL pb)
  /**********************************************************************
  *  R = A / b
  *  Assertion: R != A
  */
{
  REAL b = *pb;

#if defined (__BIASRAISEDIVIDEBYZERO__)
  if (Zero (*pb)) _BiasError (ErrorDivideByZero);
#endif
  _BiasRoundDown ();
  if (Sign (*pb) == 0) {                                /* b > 0  */
    pR->inf = pA->inf / b;
    _BiasRoundUp();
    pR->sup = pA->sup / b;
  }
  else {                                                /* b < 0  */
    pR->inf = pA->sup / b;
    _BiasRoundUp ();
    pR->sup = pA->inf / b;
  }
  _SetRoundToNearest();
} /* BiasDivIR */

VOID BiasDivII (const PBIASINTERVAL pR,
		const SECURE PBIASINTERVAL pA,
		const SECURE PBIASINTERVAL pB)
  /**********************************************************************
  *  R = A / B
  *  Assertion: R != A and R != B
  */
{
  _BiasRoundDown ();
  if (Sign (pA->inf) == 0) {                            /* A >= 0 */
    if ((Sign (pB->inf) == 0) && !Zero (pB->inf)) {     /* B >  0 */
      pR->inf = pA->inf / pB->sup;
      _BiasRoundUp ();
      pR->sup = pA->sup / pB->inf;
    }
    else if (Sign (pB->sup) && !Zero (pB->inf)) {       /* B <  0 */
      pR->inf = pA->sup / pB->sup;
      _BiasRoundUp ();
      pR->sup = pA->inf / pB->inf;
    }
    else                                                /* 0 in B */
#if defined (__BIASRAISEDIVIDEBYZERO__)
      _BiasError (ErrorDivideByZero);
#else
      {
	_BiasRoundUp();
	if (Zero (pA->inf)) pR->sup = pR->inf = BiasNaN;
	else { pR->inf = BiasNegInf; pR->sup = BiasPosInf; }
      }
#endif
  }
  else if (Sign (pA->sup)) {                            /* A <= 0 */
    if ((Sign (pB->inf) == 0) && !Zero (pB->inf)) {     /* B >  0 */
      pR->inf = pA->inf / pB->inf;
      _BiasRoundUp ();
      pR->sup = pA->sup / pB->sup;
    }
    else if (Sign (pB->sup) && !Zero (pB->inf)) {       /* B <  0 */
      pR->inf = pA->sup / pB->inf;
      _BiasRoundUp ();
      pR->sup = pA->inf / pB->sup;
    }
    else                                                /* 0 in B */
#if defined (__BIASRAISEDIVIDEBYZERO__)
      _BiasError (ErrorDivideByZero);
#else
      {
	_BiasRoundUp();
	if (Zero (pA->sup)) pR->sup = pR->inf = BiasNaN;
	else { pR->inf = BiasNegInf; pR->sup = BiasPosInf; }
      }
#endif
  }
  else {                                                /* 0 in A */
    if ((Sign (pB->inf) == 0) && !Zero (pB->inf)) {     /* B >  0 */
      pR->inf = pA->inf / pB->inf;
      _BiasRoundUp ();
      pR->sup = pA->sup / pB->inf;
    }
    else if (Sign (pB->sup) && !Zero (pB->inf)) {       /* B <  0 */
      pR->inf = pA->sup / pB->sup;
      _BiasRoundUp ();
      pR->sup = pA->inf / pB->sup;
    }
    else                                                /* 0 in B */
#if defined (__BIASRAISEDIVIDEBYZERO__)
      _BiasError (ErrorDivideByZero);
#else
      {
	_BiasRoundUp();
	pR->sup = pR->inf = BiasNaN;
      }
#endif
  }
  _SetRoundToNearest();
}

VOID BiasMacRR (const PBIASINTERVAL pR,
		const SECURE PREAL pa, const SECURE PREAL pb)
  /**********************************************************************
  *  R += a * b
  */
{
  _BiasRoundDown ();
  pR->inf += *pa * *pb;
  _BiasRoundUp ();
  pR->sup += *pa * *pb;
  _SetRoundToNearest();
} /* BiasMacRR */

VOID BiasMacRI (const PBIASINTERVAL pR,
		const SECURE PREAL pa, const PBIASINTERVAL pB)
  /**********************************************************************
  *  R += a * B
  *  Assertion: R != B
  */
{
  REAL a = *pa;

  _BiasRoundDown ();
  if (Sign (*pa) == 0) {                                /* a >= 0 */
    pR->inf += a * pB->inf;
    _BiasRoundUp();
    pR->sup += a * pB->sup;
  }
  else {                                                /* a < 0  */
    pR->inf += a * pB->sup;
    _BiasRoundUp ();
    pR->sup += a * pB->inf;
  }
  _SetRoundToNearest();
} /* BiasMacRI */

VOID BiasMacII (const PBIASINTERVAL pR,
		const SECURE PBIASINTERVAL pA,
		const SECURE PBIASINTERVAL pB)
  /**********************************************************************
  *  R += A * B
  *  Assertion: R != A and R != B
  */
{
  _BiasRoundDown ();
  if (Sign (pA->inf) == 0) {                            /* A >= 0 */
    if (Sign (pB->inf) == 0) {                          /* B >= 0 */
      pR->inf += pA->inf * pB->inf;
      _BiasRoundUp ();
      pR->sup += pA->sup * pB->sup;
    }
    else if (Sign (pB->sup)) {                          /* B <= 0 */
      pR->inf += pA->sup * pB->inf;
      _BiasRoundUp ();
      pR->sup += pA->inf * pB->sup;
    }
    else {                                              /* 0 in B */
      pR->inf += pA->sup * pB->inf;
      _BiasRoundUp ();
      pR->sup += pA->sup * pB->sup;
    }
  }
  else if (Sign (pA->sup)) {                            /* A <= 0 */
    if (Sign (pB->inf) == 0) {                          /* B >= 0 */
      pR->inf += pA->inf * pB->sup;
      _BiasRoundUp ();
      pR->sup += pA->sup * pB->inf;
    }
    else if (Sign (pB->sup)) {                          /* B <= 0 */
      pR->inf += pA->sup * pB->sup;
      _BiasRoundUp ();
      pR->sup += pA->inf * pB->inf;
    }
    else {                                              /* 0 in B */
      pR->inf += pA->inf * pB->sup;
      _BiasRoundUp ();
      pR->sup += pA->inf * pB->inf;
    }
  }
  else {                                                /* 0 in A */
    if (Sign (pB->inf) == 0) {                          /* B >= 0 */
      pR->inf += pA->inf * pB->sup;
      _BiasRoundUp ();
      pR->sup += pA->sup * pB->sup;
    }
    else if (Sign (pB->sup)) {                          /* B <= 0 */
      pR->inf += pA->sup * pB->inf;
      _BiasRoundUp ();
      pR->sup += pA->inf * pB->inf;
    }
    else {                                              /* 0 in B */
      SECURE REAL r1 = pA->inf * pB->sup;
      SECURE REAL r2 = pA->sup * pB->inf;

      pR->inf += r1 < r2 ? r1 : r2;

      _BiasRoundUp ();

      r1 = pA->inf * pB->inf;
      r2 = pA->sup * pB->sup;

      pR->sup += r1 > r2 ? r1 : r2;
    }
  }
  _SetRoundToNearest();
} /* BiasMacII */

VOID BiasNeg (const PBIASINTERVAL pR, const PBIASINTERVAL pA)
  /**********************************************************************
  *  R = - A
  *  Assertion: R != A
  */
{
  pR->inf = -(pA->sup);
  pR->sup = -(pA->inf);
} /* BiasNeg */

REAL BiasMid (const PBIASINTERVAL pA)
  /**********************************************************************
  *  Result: Midpoint(A)
  */
{
  REAL pr;
  _BiasRoundUp();
  pr = pA->inf + (pA->sup - pA->inf) / 2.0;
  _SetRoundToNearest();
  return pr;
} /* BiasMid */

REAL BiasDiam (const PBIASINTERVAL pA)
  /**********************************************************************
  *  Result: Diameter(A)
  */
{
  REAL pr;

  _BiasRoundUp();
  pr = pA->sup - pA->inf;
  _SetRoundToNearest();
  return pr;
} /* BiasDiam */

VOID BiasMidRad (const PREAL pm, const PREAL pr,
		 const PBIASINTERVAL pA)
  /**********************************************************************
  *  pm = Midpoint(A), pr = Radius(A)
  */
{
  REAL r;

  _BiasRoundUp();
  r = (pA->sup - pA->inf) / 2.0;
  *pm = pA->inf + r;
  *pr = r;
  _SetRoundToNearest();
} /* BiasMidRad */

REAL BiasAbs (const PBIASINTERVAL pA)
  /**********************************************************************
  *  Result: Abs(A)
  */
{
  REAL infabs = fabs(pA->inf);
  REAL supabs = fabs(pA->sup);

  return (infabs < supabs) ? supabs : infabs;
} /* BiasAbs */

REAL BiasDistRI (const PREAL pa, const PBIASINTERVAL pB)
  /**********************************************************************
  *  Result: Distance between a and B
  */
{
  REAL a = *pa;

  if (a < pB->inf) return (pB->inf - a);
  if (a > pB->sup) return (a - pB->sup);
  return (0.0);
} /* BiasDistRI */

REAL BiasDistII (const PBIASINTERVAL pA, const PBIASINTERVAL pB)
  /**********************************************************************
  *  Result: Distance between A and B
  */
{
  REAL infabs = fabs(pA->inf - pB->inf);
  REAL supabs = fabs(pA->sup - pB->sup);

  return ((infabs < supabs) ? supabs : infabs);
} /* BiasDistII */

INT BiasIntersection (const PBIASINTERVAL pR,
		      const PBIASINTERVAL pA, const PBIASINTERVAL pB)
  /**********************************************************************
  *  R = Intersection (A, B). R is undefined, if A and B do not intersect
  *  Result: 1 if A and B intersect, 0 otherwise
  */
{
  pR->inf = (pA->inf > pB->inf) ? pA->inf : pB->inf;
  pR->sup = (pA->sup < pB->sup) ? pA->sup : pB->sup;
  return (pR->inf <= pR->sup);
} /* BiasIntersection */

VOID BiasHullR (const PBIASINTERVAL pR, const PREAL pa)
  /**********************************************************************
  *  R = Hull(a)
  */
{
  pR->inf = pR->sup = *pa;
} /* BiasHullR */

VOID BiasHullRR (const PBIASINTERVAL pR,
		 const PREAL pa, const PREAL pb)
  /**********************************************************************
  *  R = Hull(a, b)
  */
{
  REAL a = *pa;
  REAL b = *pb;

  if (a < b) { pR->inf = a; pR->sup = b; }
  else       { pR->inf = b; pR->sup = a; }
} /* BiasHullRR */

VOID BiasHullRI (const PBIASINTERVAL pR,
		 const PREAL pa, const PBIASINTERVAL pB)
  /**********************************************************************
  *  R = Hull(a, B)
  */
{
  REAL a = *pa;

  pR->inf = (a < pB->inf) ? a : pB->inf;
  pR->sup = (a > pB->sup) ? a : pB->sup;
} /* BiasHullRI */

VOID BiasHullII (const PBIASINTERVAL pR,
		 const PBIASINTERVAL pA, const PBIASINTERVAL pB)
  /**********************************************************************
  *  R = Hull(A, B)
  */
{
  pR->inf = (pA->inf < pB->inf) ? pA->inf : pB->inf;
  pR->sup = (pA->sup > pB->sup) ? pA->sup : pB->sup;
} /* BiasHullII */

INT BiasInR (const PREAL pa, const PBIASINTERVAL pB)
  /**********************************************************************
  *  Result: 1 if a is contained in B, 0 otherwise
  */
{
  REAL a = *pa;

  return ((a >= pB->inf) && (a <= pB->sup));
} /* BiasInR */

INT BiasInI (const PBIASINTERVAL pA, const PBIASINTERVAL pB)
  /**********************************************************************
  *  Result: 1 if A is contained in B, 0 otherwise
  */
{
  return ((pA->inf >= pB->inf) && (pA->sup <= pB->sup));
} /* BiasInI */

INT BiasInInteriorR (const PREAL pa, const PBIASINTERVAL pB)
  /**********************************************************************
  *  Result: 1 if a is contained in the interior of B, 0 otherwise
  */
{
  REAL a = *pa;

  return ((a > pB->inf) && (a < pB->sup));
} /* BiasInInteriorR */

INT BiasInInteriorI (const PBIASINTERVAL pA, const PBIASINTERVAL pB)
  /**********************************************************************
  *  Result: 1 if A is contained in the interior of B, 0 otherwise
  */
{
  return ((pA->inf > pB->inf) && (pA->sup < pB->sup));
} /* BiasInInteriorI */

INT BiasIsEqual (const PBIASINTERVAL pA, const PBIASINTERVAL pB)
  /**********************************************************************
  *  Result: 1, if A == B, 0 otherwise
  */
{
  return ((pA->inf == pB->inf) && (pA->sup == pB->sup));
} /* BiasIsEqual */
