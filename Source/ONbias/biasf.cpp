/************************************************************************
*  BiasF.c (Basic Interval Arithmetic Subroutines Standard Functions)
*
*  Version:                     1.16
*  Date:                        10/6/95
*  Author:                      O. Knueppel
*  Interval Representation:     any
*  Interval Implementation:     any
*************************************************************************/

static char sccs_id[] = "@(#)BiasF.c 1.16 95/10/06 DH/OK";

#include "BiasF.h"
#include "BiasInt.h"
#include <math.h>

ONBIAS_API REAL BiasPi;
ONBIAS_API REAL BiasTwoPi;
ONBIAS_API REAL BiasPiHalf;
ONBIAS_API REAL BiasPiQuarter;
ONBIAS_API REAL BiasE;
ONBIAS_API REAL BiasSqrt2;
ONBIAS_API REAL BiasInvSqrt2;
ONBIAS_API REAL BiasLn10;

static BIASINTERVAL BiasPiHalfIncl; /* enclosure of Pi/2  */
static BIASINTERVAL BiasLn10Incl;   /* enclosure of Ln 10 */

static BIASINTERVAL PlusMinusOne;   /* [-1,1] */

static REAL BiasStdFuncOnePlusEps;  /* (1.0 + n * Epsilon)          */
static REAL BiasStdFuncOneMinusEps; /* (1.0 - n * Epsilon)          */

static REAL Zero     =  0.0;
static REAL MinusOne = -1.0;
static REAL PlusOne  =  1.0;
static REAL PlusTwo  =  2.0;

#define RoundUp(x) \
  (((x < 0.0) ? BiasStdFuncOneMinusEps : BiasStdFuncOnePlusEps) * (x) \
   + BiasEta)
#define RoundDown(x) \
  (((x < 0.0) ? BiasStdFuncOnePlusEps : BiasStdFuncOneMinusEps) * (x) \
   - BiasEta)
#define DEBUGGING

/************************************************************************
*  Implementation of local functions
*************************************************************************/

static INT Quadrant (REAL x)
  /**********************************************************************
   *  Calculation of the quadrant x is lying in (x in [0, 2Pi])
   */
{
  if (x <= BiasPiHalf) return 0;
  if (x <= BiasPi) return 1;
  if (x <= BiasPi + BiasPiHalf) return 2;
  return 3;
}

static VOID ScaleTo2Pi (PREAL py_inf, PREAL py_sup, const PBIASINTERVAL pX)
  /**********************************************************************
   *  The interval x is scaled to the range [0, 2Pi].
   *  Result: Interval [y_inf, y_sup]
   */
{
  REAL q;
  REAL x_inf, x_sup;

  if (((*py_inf = BiasInf (pX)) >= 0.0)
      && ((*py_sup = BiasSup (pX)) < BiasPiHalf)) return;

  q = BiasInf (pX) / BiasTwoPi;
  q = floor(BiasPredR (& q));
  q *= BiasTwoPi;
  q = BiasSuccR (& q);
  if (q > 0.0) {
    q *= (1.0 + BiasEpsilon); /* error estimation: 1 unit in LSB */
    q = BiasSuccR (& q);
  }
  x_inf = BiasInf (pX) - q;
  x_inf = BiasPredR (& x_inf);
  if (x_inf < 0.0) {
    x_inf += BiasTwoPi;
    x_inf = BiasPredR (& x_inf);
  }
  q = BiasSup (pX) / BiasTwoPi;
  q = floor(BiasPredR (& q));
  q *= BiasTwoPi;
  q = BiasPredR (& q);
  if (q < 0.0) {
    q *= (1.0 + BiasEpsilon); /* error estimation: 1 unit in LSB */
    q = BiasPredR (& q);
  }
  x_sup = BiasSup (pX) - q;
  x_sup = BiasSuccR (& x_sup);
  if (x_sup > BiasTwoPi) {
    x_sup -= BiasTwoPi;
    x_sup = BiasSuccR (& x_sup);
  }
#ifdef DEBUGGING
  if (x_inf < 0.0)
    _BiasError ("ScaleTo2Pi (): inf < 0");
  if (x_sup > BiasTwoPi)
    _BiasError ("ScaleTo2Pi (): sup > 2Pi");
#endif
  *py_inf = x_inf; *py_sup = x_sup;
}

/************************************************************************
*  Implementation of global functions
*************************************************************************/

VOID BiasFuncInit (VOID)
  /**********************************************************************
   *  Initialization
   */
{
  INT InvalidBits = 0; /* # of invalid digits in calculation of std. func. */
  BIASINTERVAL tmp;

  BiasInit ();

  BiasPi         = 3.14159265358979323846;
  BiasTwoPi      = 6.28318530717958647693;
  BiasPiHalf     = 1.57079632679489661923;
  BiasPiQuarter  = 0.78539816339744830962;
  BiasE          = 2.7182818284590452354;
  BiasSqrt2      = 1.41421356237309504880;
  BiasInvSqrt2   = 0.70710678118654752440;
  BiasLn10       = 2.30258509299404568402;

  BiasHullR (& tmp, & BiasPiHalf);
  BiasSuccI (& BiasPiHalfIncl, & tmp);

  BiasHullR (& tmp, & BiasLn10);
  BiasSuccI (& BiasLn10Incl, & tmp);

  BiasHullRR (& PlusMinusOne, & MinusOne, & PlusOne);

  BiasRoundNear ();

  BiasStdFuncOnePlusEps  = 1.0 + (1 << (InvalidBits + 1)) * BiasEpsilon;
  BiasStdFuncOneMinusEps = 1.0 - (1 << (InvalidBits + 1)) * BiasEpsilon;
}

VOID BiasSin (const PBIASINTERVAL pR, const PBIASINTERVAL pX)
  /**********************************************************************
   *  R = Sin (X)
   */
{
  REAL x_inf, x_sup;
  REAL y_inf, y_sup;
  int q_inf, q_sup;

  if (BiasDiam (pX) >= BiasTwoPi) {
    BiasHullRR (pR, & MinusOne, & PlusOne);
    return;
  }
  /* Reduction of x to [0, 2Pi] */
  ScaleTo2Pi (& x_inf, & x_sup, pX);
  if (x_sup >= x_inf + BiasTwoPi) { /* security */
    BiasHullRR (pR, & MinusOne, & PlusOne);
    return;
  }
  /* x_inf, x_sup are now in the range [0, 2Pi]
   * Quadrants:
   *  0 = [0,Pi/2]
   *  1 = [Pi/2,Pi]
   *  2 = [Pi,3Pi/2]
   *  3 = [3Pi/2,2Pi]
   */
  q_inf = Quadrant (x_inf);
  q_sup = Quadrant (x_sup);

  if ((q_inf == q_sup) && (BiasSup (pX) > BiasInf (pX) + BiasPi)) {
    BiasHullRR (pR, & MinusOne, & PlusOne);
    return;
  }
  switch ((q_sup << 2) + q_inf)
    {
    case 0:
    case 3:
    case 15:
      x_inf = sin (x_inf);
      x_sup = sin (x_sup);
      y_inf = RoundDown (x_inf);
      y_sup = RoundUp (x_sup);
      break;
    case 1:
    case 14:
      y_inf = -1.0;
      x_inf = sin (x_inf);
      x_sup = sin (x_sup);
      x_inf = RoundUp (x_inf);
      x_sup = RoundUp (x_sup);
      y_sup = max(x_inf, x_sup);
      break;
    case 2:
      y_inf = -1.0;
      x_sup = sin (x_sup);
      y_sup = RoundUp (x_sup);
      break;
    case 4:
    case 11:
      y_sup = 1.0;
      x_inf = sin (x_inf);
      x_sup = sin (x_sup);
      x_inf = RoundDown (x_inf);
      x_sup = RoundDown (x_sup);
      y_inf = min(x_inf, x_sup);
      break;
    case 5:
    case 9:
    case 10:
      x_inf = sin (x_inf);
      x_sup = sin (x_sup);
      y_inf = RoundDown (x_sup);
      y_sup = RoundUp (x_inf);
      break;
    case 6:
    case 12:
      y_inf = -1.0; y_sup = 1.0; break;
    case 7:
      y_sup = 1.0;
      x_inf = sin (x_inf);
      y_inf = RoundDown (x_inf);
      break;
    case 8:
      y_sup = 1.0;
      x_sup = sin (x_sup);
      y_inf = RoundDown (x_sup);
      break;
    case 13:
      y_inf = -1.0;
      x_inf = sin (x_inf);
      y_sup = RoundUp (x_inf);
      break;
    }
  if (y_inf < -1.0) y_inf = -1.0;	/* don't overestimate */
  if (y_sup > 1.0) y_sup = 1.0;	        /* dto.               */
  BiasHullRR (pR, & y_inf, & y_sup);
}

VOID BiasCos (const PBIASINTERVAL pR, const PBIASINTERVAL pX)
  /**********************************************************************
   *  R = Cos (X)
   */
{
  BIASINTERVAL tmp;

  BiasAddII (& tmp, pX, & BiasPiHalfIncl);
  BiasSin (pR, & tmp);
}

VOID BiasTan (const PBIASINTERVAL pR, const PBIASINTERVAL pX)
  /**********************************************************************
   *  R = Tan (X)
   */
{
  REAL x_inf, x_sup;
  REAL y_inf, y_sup;
  INT q_inf, q_sup;

  if (BiasDiam (pX) >= BiasTwoPi) {
    BiasHullRR (pR, & BiasNegInf, & BiasPosInf);
    return;
  }
  /* Reduction of x to [0, 2Pi] */
  ScaleTo2Pi(& x_inf, & x_sup, pX);
  if (x_sup >= x_inf + BiasTwoPi) { /* security */
    BiasHullRR (pR, & BiasNegInf, & BiasPosInf);
    return;
  }
  /* x_inf, x_sup are now in the range [0, 2Pi]
   * Quadrants:
   *  0 = [0,Pi/2]
   *  1 = [Pi/2,Pi]
   *  2 = [Pi,3Pi/2]
   *  3 = [3Pi/2,2Pi]
   */
  q_inf = Quadrant (x_inf);
  q_sup = Quadrant (x_sup);

  if ((q_inf == q_sup) && (x_sup > x_inf + BiasPi)) {
    BiasHullRR (pR, & BiasNegInf, & BiasPosInf);
    return;
  }
  switch ((q_sup << 2) + q_inf)
    {
    case 0:
    case 3:
    case 5:
    case 9:
    case 10:
    case 15:
      x_inf = tan (x_inf);
      x_sup = tan (x_sup);
      y_inf = RoundDown (x_inf);
      y_sup = RoundUp   (x_sup);
      break;
    default:
      y_inf = BiasNegInf;
      y_sup = BiasPosInf;
      break;
    }
  BiasHullRR (pR, & y_inf, & y_sup);
}

VOID BiasCot (const PBIASINTERVAL pR, const PBIASINTERVAL pX)
  /**********************************************************************
   *  R = Tan (X)
   */
{
  BIASINTERVAL t1, t2;

  BiasAddII (& t1, pX, & BiasPiHalfIncl);
  BiasTan (& t2, & t1);
  BiasNeg (pR, & t2);
}

VOID BiasArcSin (const PBIASINTERVAL pR, const PBIASINTERVAL pX)
  /**********************************************************************
   *  R = ArcSin (X)
   */
{
  REAL x_inf, x_sup;

  x_inf = BiasInf (pX); x_sup = BiasSup (pX);
  if ((x_inf < -1.0) || (x_sup > 1.0))
    _BiasError ("ArcSin argument out of range");
  x_inf = asin (x_inf);
  x_sup = asin (x_sup);
  x_inf = RoundDown (x_inf);
  x_sup = RoundUp   (x_sup);
  BiasHullRR (pR, & x_inf, & x_sup);
}

VOID BiasArcCos (const PBIASINTERVAL pR, const PBIASINTERVAL pX)
  /**********************************************************************
   *  R = ArcCos (X)
   */
{
  REAL x_inf, x_sup;

  x_inf = BiasInf (pX); x_sup = BiasSup (pX);
  if ((x_inf < -1.0) || (x_sup > 1.0))
    _BiasError ("ArcCos argument out of range");
  x_inf = asin (x_inf);
  x_sup = asin (x_sup);
  x_inf = RoundDown (x_inf);
  x_sup = RoundUp   (x_sup);
  BiasHullRR (pR, & x_inf, & x_sup);
}

VOID BiasArcTan (const PBIASINTERVAL pR, const PBIASINTERVAL pX)
  /**********************************************************************
   *  R = ArcTan (X)
   */
{
  REAL x_inf, x_sup;

  x_inf = atan (BiasInf (pX));
  x_sup = atan (BiasSup (pX));
  x_inf = RoundDown (x_inf);
  x_sup = RoundUp   (x_sup);
  BiasHullRR (pR, & x_inf, & x_sup);
}

VOID BiasArcCot (const PBIASINTERVAL pR, const PBIASINTERVAL pX)
  /**********************************************************************
   *  R = ArcCot (X)
   */
{
  BIASINTERVAL t1, t2;

  BiasNeg (& t1, pX);
  BiasArcTan (& t2, & t1);
  BiasAddII (pR, & t2, & BiasPiHalfIncl);
}

VOID BiasSinh (const PBIASINTERVAL pR, const PBIASINTERVAL pX)
  /**********************************************************************
   *  R = Sinh (X)
   */
{
  BIASINTERVAL t1, t2, t3;

  BiasExp (& t1, pX);
  BiasDivRI (& t2, & PlusOne, & t1);
  BiasSubII (& t3, & t1, & t2);
  BiasDivIR (pR, & t3, & PlusTwo);
}

VOID BiasCosh (const PBIASINTERVAL pR, const PBIASINTERVAL pX)
  /**********************************************************************
   *  R = Cosh (X)
   */
{
  BIASINTERVAL t1, t2, t3;

  BiasExp (& t1, pX);
  BiasDivRI (& t2, & PlusOne, & t1);
  BiasAddII (& t3, & t1, & t2);
  BiasDivIR (pR, & t3, & PlusTwo);
}

VOID BiasTanh (const PBIASINTERVAL pR, const PBIASINTERVAL pX)
  /**********************************************************************
   *  R = Tanh (X)
   */
{
  BIASINTERVAL t1, t2, t3, t4;

  BiasExp (& t1, pX);
  BiasDivRI (& t2, & PlusOne, & t1);
  BiasAddII (& t3, & t1, & t2);
  BiasSubII (& t4, & t1, & t2);
  BiasDivII (pR, & t4, & t3);
}

VOID BiasCoth (const PBIASINTERVAL pR, const PBIASINTERVAL pX)
  /**********************************************************************
   *  R = Coth (X)
   */
{
  BIASINTERVAL t1, t2, t3, t4;

  BiasExp (& t1, pX);
  BiasDivRI (& t2, & PlusOne, & t1);
  BiasAddII (& t3, & t1, & t2);
  BiasSubII (& t4, & t1, & t2);
  BiasDivII (pR, & t3, & t4);
}

VOID BiasArSinh (const PBIASINTERVAL pR, const PBIASINTERVAL pX)
  /**********************************************************************
   *  R = ArSinh (X)
   */
{
  BIASINTERVAL t1, t2, tx;
  REAL inf, sup;

  inf = BiasInf (pX);
  sup = BiasSup (pX);

  BiasHullR (& tx, & inf);
  BiasSqr (& t1, & tx);
  BiasAddRI (& t2, & PlusOne, & t1);
  BiasSqrt (& t1, & t2);
  BiasAddII (& t2, & tx, & t1);
  inf = BiasInf (& t2);

  BiasHullR (& tx, & sup);
  BiasSqr (& t1, & tx);
  BiasAddRI (& t2, & PlusOne, & t1);
  BiasSqrt (& t1, & t2);
  BiasAddII (& t2, & tx, & t1);
  sup = BiasSup (& t2);

  BiasHullRR (& t1, & inf, & sup);
  BiasLog (pR, & t1);
}

VOID BiasArCosh (const PBIASINTERVAL pR, const PBIASINTERVAL pX)
  /**********************************************************************
   *  R = ArCosh (X)
   */
{
  BIASINTERVAL t1, t2;

  if (BiasInf (pX) < 1.0)
    _BiasError ("ArCosh argument out of range");
  BiasSqr (& t1, pX);
  BiasSubIR (& t2, & t1, & PlusOne);
  BiasSqrt (& t1, & t2);
  BiasAddII (& t2, pX, & t1);
  BiasLog (pR, & t2);
}

VOID BiasArTanh (const PBIASINTERVAL pR, const PBIASINTERVAL pX)
  /**********************************************************************
   *  R = ArTanh (X)
   */
{
  BIASINTERVAL t1, t2, t3;

  if ((BiasInf (pX) <= -1.0) || (BiasSup (pX) >= 1.0))
    _BiasError ("ArTanh argument out of range");
  BiasAddIR (& t1, pX, & PlusOne);
  BiasSubRI (& t2, & PlusOne, pX);
  BiasDivII (& t3, & t1, & t2);
  BiasLog (& t1, & t3);
  BiasDivIR (pR, & t1, & PlusTwo);
}

VOID BiasArCoth (const PBIASINTERVAL pR, const PBIASINTERVAL pX)
  /**********************************************************************
   *  R = ArCoth (X)
   */
{
  BIASINTERVAL t1, t2, t3;

  if (BiasIntersection (& t1, & PlusMinusOne, pX))
    _BiasError ("ArCoth argument out of range");
  BiasAddIR (& t1, pX, & PlusOne);
  BiasSubIR (& t2, pX, & PlusOne);
  BiasDivII (& t3, & t1, & t2);
  BiasLog (& t1, & t3);
  BiasDivIR (pR, & t1, & PlusTwo);
}

VOID BiasExp (const PBIASINTERVAL pR, const PBIASINTERVAL pX)
  /**********************************************************************
   *  R = e^X
   */
{
  REAL y_inf, y_sup;

  y_inf = exp (BiasInf (pX));
  y_sup = exp (BiasSup (pX));
  y_inf = RoundDown (y_inf);
  y_sup = RoundUp   (y_sup);
  if (y_inf < 0.0) y_inf = 0.0;
  BiasHullRR (pR, & y_inf, & y_sup);
}

VOID BiasLog (const PBIASINTERVAL pR, const PBIASINTERVAL pX)
  /**********************************************************************
   *  R = Ln (X)
   */
{
  REAL y_inf, y_sup;

  if (BiasInf (pX) <= 0.0)
    _BiasError ("Log argument out of range"); /* BiasHullR (pR, & BiasNaN); */
  else {
    y_inf = log (BiasInf (pX));
    y_sup = log (BiasSup (pX));
    y_inf = RoundDown (y_inf);
    y_sup = RoundUp   (y_sup);
    BiasHullRR (pR, & y_inf, & y_sup);
  }
}

VOID BiasLog10 (const PBIASINTERVAL pR, const PBIASINTERVAL pX)
  /**********************************************************************
   *  R = Log10 (X)
   */
{
  BIASINTERVAL t1;

  if (BiasInf (pX) <= 0.0)
    _BiasError ("Log10 argument out of range"); /* BiasHullR (pR, & BiasNaN); */
  else {
    BiasLog (& t1, pX);
    BiasDivII (pR, & t1, & BiasLn10Incl);
  }
}

VOID BiasIAbs (const PBIASINTERVAL pR, const PBIASINTERVAL pX)
  /**********************************************************************
   *  R = { |x| : x in X }
   */
{
  REAL t;

  if (BiasInf (pX) > 0.0) *pR = *pX;
  else if (BiasSup (pX) < 0.0) BiasNeg (pR, pX);
  else {
    t = BiasAbs (pX);
    BiasHullRR (pR, & Zero, & t);
  }
}

VOID BiasSqr (const PBIASINTERVAL pR, const PBIASINTERVAL pX)
  /**********************************************************************
   *  R = X^2
   */
{
  BIASINTERVAL t1;

  BiasIAbs (& t1, pX);
  BiasMulII (pR, & t1, & t1);
}

VOID BiasSqrt (const PBIASINTERVAL pR, const PBIASINTERVAL pX)
  /**********************************************************************
   *  R = Sqrt (X)
   */
{
  REAL y_inf, y_sup;

  if (BiasInf (pX) < 0.0)
    _BiasError ("Sqrt argument out of range"); /* BiasHullR (pR, & BiasNaN); */
  else {
    y_inf = sqrt (BiasInf (pX));
    y_sup = sqrt (BiasSup (pX));
    y_inf = RoundDown (y_inf);
    y_sup = RoundUp   (y_sup);
    if (y_inf < 0.0) y_inf = 0.0;
    BiasHullRR (pR, & y_inf, & y_sup);
  }
}

VOID BiasRoot (const PBIASINTERVAL pR, const PBIASINTERVAL pX,
	       const INT n)
  /**********************************************************************
   *  R = n-th root (X)
   */
{
  REAL tn, sup;
  INT inf_is_zero;
  BIASINTERVAL t1, t2, t3;

  if (n < 2) _BiasError ("Root: n must be >= 2");
  if (BiasInf (pX) < 0.0) _BiasError ("Root: Argument must be >= 0");
  tn = (REAL) n;
  BiasDivRR (& t1, & PlusOne, & tn);
  if ((inf_is_zero = (BiasInf (pX) == 0.0)) != 0) {
    sup = BiasSup (pX);
    BiasHullR (& t3, & sup);
    BiasLog (& t2, & t3);
  }
  else BiasLog (& t2, pX);
  BiasMulII (& t3, & t1, & t2);
  if (inf_is_zero) {
    BiasExp (& t2, & t3);
    BiasHullRI (pR, & Zero, & t2);
  }
  else BiasExp (pR, & t3);
}

VOID BiasPowerN (const PBIASINTERVAL pR, const PBIASINTERVAL pX,
		 const INT n)
  /**********************************************************************
   *  R = X^n
   */
{
  INT i, absn;
  BIASINTERVAL y, z, xsqr;

  absn = (n < 0) ? (-n) : n;
  if (absn >= 2) {
    BiasSqr (& xsqr, pX);
    if (absn & 1) BiasMulII (& y, & xsqr, pX);
    else y = xsqr;
    for (i = 3; i < absn; i += 2) {
      z = y;
      BiasMulII (& y, & z, & xsqr);
      }
  }
  else if (absn & 1) y = *pX;
  else BiasHullR (& y, & PlusOne);
  if (n < 0) BiasDivRI (pR, & PlusOne, & y);
  else *pR = y;
}

VOID BiasPowerI (const PBIASINTERVAL pR,
		 const PBIASINTERVAL pX, const PBIASINTERVAL pY)
  /**********************************************************************
   *  R = X^Y
   */
{
  REAL x_inf = BiasInf (pX);
  REAL sup;
  INT inf_is_zero;
  BIASINTERVAL t1, t2;

  if (x_inf < 0.0) _BiasError ("Power: Base is negative");
  if ((x_inf == 0.0) && (BiasInf (pY) <= 0.0))
    _BiasError ("Power: Negative or zero exponent with zero base");
  else {
    if ((inf_is_zero = (BiasInf (pX) == 0.0)) != 0) {
      sup = BiasSup (pX);
      BiasHullR (& t2, & sup);
      BiasLog (& t1, & t2);
    }
    else BiasLog (& t1, pX);
    BiasMulII (& t2, & t1, pY);
    if (inf_is_zero) {
      BiasExp (& t1, & t2);
      BiasHullRI (pR, & Zero, & t1);
    }
    else BiasExp (pR, & t2);
  }
}
