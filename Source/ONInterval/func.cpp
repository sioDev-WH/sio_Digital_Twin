/************************************************************************
*  Functions.C (Implementation of standard functions (REAL and INTERVAL))
*
*  Version:                     1.8
*  Date:                        8/25/93
*  Author:                      O. Knueppel
*************************************************************************/

static char sccs_id[] = "@(#)Functions.C 1.8 93/08/25 OK";

//#include "stdafx.h"
#include "func.h"

REAL Constant::Pi         = 0.0;
REAL Constant::TwoPi      = 0.0;
REAL Constant::PiHalf     = 0.0;
REAL Constant::PiQuarter  = 0.0;
REAL Constant::e          = 0.0;
REAL Constant::Sqrt2      = 0.0;
REAL Constant::InvSqrt2   = 0.0;
REAL Constant::Ln10       = 0.0;

Constant UsefulConstants; // constructor is called automatically

Constant::Constant ()
{
  BiasFuncInit ();  

  Constant::Pi         = BiasPi;
  Constant::TwoPi      = BiasTwoPi;
  Constant::PiHalf     = BiasPiHalf;
  Constant::PiQuarter  = BiasPiQuarter;
  Constant::e          = BiasE;
  Constant::Sqrt2      = BiasSqrt2;
  Constant::InvSqrt2   = BiasInvSqrt2;
  Constant::Ln10       = BiasLn10;
}

REAL ArSinh (REAL x)
{
  return log (x + sqrt (x * x + 1.0));
}

REAL ArCosh (REAL x)
{
  return log (x + sqrt (x * x - 1.0));
}

REAL ArTanh (REAL x)
{
  return 0.5 * log ((1.0 + x) / (1.0 - x));
}

REAL ArCoth (REAL x)
{
  return 0.5 * log ((x + 1.0) / (x - 1.0));
}

REAL Power (REAL x, INT n)
// Calculates x^n, all cases are considered
{
  INT i, absn;
  REAL y = 1.0;

  absn = (n < 0) ? (-n) : n;
  for (i = 1; i <= absn; i++) y *= x;
  if (n < 0) return 1.0 / y;
  else return y;
}

INTERVAL Sin (INTERVAL & x)
{
  INTERVAL r;

  BiasSin (Bias(r), Bias(x));
  return r;
}

INTERVAL Cos (INTERVAL & x)
{
  INTERVAL r;

  BiasCos (Bias(r), Bias(x));
  return r;
}

INTERVAL Tan (INTERVAL & x)
{
  INTERVAL r;
  BiasTan (Bias(r), Bias(x));
  return r;
}

INTERVAL Cot (INTERVAL & x)
{
  INTERVAL r;

  BiasCot (Bias(r), Bias(x));
  return r;
}

INTERVAL ArcSin (INTERVAL & x)
{
  INTERVAL r;

  BiasArcSin (Bias(r), Bias(x));
  return r;
}

INTERVAL ArcCos (INTERVAL & x)
{
  INTERVAL r;

  BiasArcCos (Bias(r), Bias(x));
  return r;
}

INTERVAL ArcTan (INTERVAL & x)
{
  INTERVAL r;

  BiasArcTan (Bias(r), Bias(x));
  return r;
}

INTERVAL ArcCot (INTERVAL & x)
{
  INTERVAL r;

  BiasArcCot (Bias(r), Bias(x));
  return r;
}

INTERVAL Sinh (INTERVAL & x)
{
  INTERVAL r;

  BiasSinh (Bias(r), Bias(x));
  return r;
}

INTERVAL Cosh (INTERVAL & x)
{
  INTERVAL r;

  BiasCosh (Bias(r), Bias(x));
  return r;
}

INTERVAL Tanh (INTERVAL & x)
{
  INTERVAL r;

  BiasTanh (Bias(r), Bias(x));
  return r;
}

INTERVAL Coth (INTERVAL & x)
{
  INTERVAL r;

  BiasCoth (Bias(r), Bias(x));
  return r;
}

INTERVAL ArSinh (INTERVAL & x)
{
  INTERVAL r;

  BiasArSinh (Bias(r), Bias(x));
  return r;
}

INTERVAL ArCosh (INTERVAL & x)
{
  INTERVAL r;

  BiasArCosh (Bias(r), Bias(x));
  return r;
}

INTERVAL ArTanh (INTERVAL & x)
{
  INTERVAL r;

  BiasArTanh (Bias(r), Bias(x));
  return r;
}

INTERVAL ArCoth (INTERVAL & x)
{
  INTERVAL r;

  BiasArCoth (Bias(r), Bias(x));
  return r;
}

INTERVAL Exp (INTERVAL & x)
{
  INTERVAL r;

  BiasExp (Bias(r), Bias(x));
  return r;
}

INTERVAL Log (INTERVAL & x)
{
  INTERVAL r;

  BiasLog (Bias(r), Bias(x));
  return r;
}

INTERVAL Log10 (INTERVAL & x)
{
  INTERVAL r;

  BiasLog10 (Bias(r), Bias(x));
  return r;
}

INTERVAL IAbs (INTERVAL & x)
{
  INTERVAL r;

  BiasIAbs (Bias(r), Bias(x));
  return r;
}

INTERVAL Sqr (INTERVAL & x)
{
  INTERVAL r;

  BiasSqr (Bias(r), Bias(x));
  return r;
}

INTERVAL Sqrt (INTERVAL & x)
{
  INTERVAL r;

  BiasSqrt (Bias(r), Bias(x));
  return r;
}

INTERVAL Root (INTERVAL & x, INT n)
{
  INTERVAL r;

  BiasRoot (Bias(r), Bias(x), n);
  return r;
}

INTERVAL Power (INTERVAL & x, INT n)
{
  INTERVAL r;

  BiasPowerN (Bias(r), Bias(x), n);
  return r;
}

INTERVAL Power (INTERVAL & x, INTERVAL & y)
{
  INTERVAL r;

  BiasPowerI (Bias(r), Bias(x), Bias(y));
  return r;
}
