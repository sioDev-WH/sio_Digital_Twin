/************************************************************************
*  Functions.h (Definition of standard functions (REAL and INTERVAL))
*
*  Version:                     1.9
*  Date:                        9/27/93
*  Author:                      O. Knueppel
*************************************************************************/

#ifndef __FUNCTIONS__
#define __FUNCTIONS__

#include "ival.h"
#include "BiasF.h"
#include <math.h>

class Constant {
public:
  static REAL Pi;
  static REAL TwoPi;
  static REAL PiHalf;
  static REAL PiQuarter;
  static REAL e;
  static REAL Sqrt2;
  static REAL InvSqrt2;
  static REAL Ln10;
  Constant ();
  ~Constant () { }
};

inline REAL Sin    (REAL x) { return sin(x); }
inline REAL Cos    (REAL x) { return cos(x); }
inline REAL Tan    (REAL x) { return tan(x); }
inline REAL Cot    (REAL x) { return -tan(x + Constant::PiHalf); }
inline REAL ArcSin (REAL x) { return asin(x); }
inline REAL ArcCos (REAL x) { return acos(x); }
inline REAL ArcTan (REAL x) { return atan(x); }
inline REAL ArcCot (REAL x) { return atan(-x) + Constant::PiHalf; }

inline REAL Sinh   (REAL x) { return sinh(x); }
inline REAL Cosh   (REAL x) { return cosh(x); }
inline REAL Tanh   (REAL x) { return tanh(x); }
inline REAL Coth   (REAL x) { return 1.0 / tanh(x); }
       REAL ArSinh (REAL x);
       REAL ArCosh (REAL x);
       REAL ArTanh (REAL x);
       REAL ArCoth (REAL x);

inline REAL Exp    (REAL x) { return exp(x); }
inline REAL Log    (REAL x) { return log(x); }
inline REAL Log10  (REAL x) { return log10(x); }

inline REAL Abs    (REAL x) { return fabs(x); }
inline REAL Sqr    (REAL x) { return x*x; }
inline REAL Sqrt   (REAL x) { return sqrt(x); }
inline REAL Root   (REAL x, INT n) { return pow(x, 1.0 / (REAL) n); }

       REAL Power  (REAL x, INT n);
inline REAL Power  (REAL x, REAL y) { return pow(x, y); }

inline REAL Min    (REAL x, REAL y) { return (x < y) ? x : y; }
inline REAL Max    (REAL x, REAL y) { return (x > y) ? x : y; }

       INTERVAL ONINTERVAL_API Sin    (INTERVAL & x);
       INTERVAL ONINTERVAL_API Cos    (INTERVAL & x);
       INTERVAL ONINTERVAL_API Tan    (INTERVAL & x);
       INTERVAL ONINTERVAL_API Cot    (INTERVAL & x);
       INTERVAL ONINTERVAL_API ArcSin (INTERVAL & x);
       INTERVAL ONINTERVAL_API ArcCos (INTERVAL & x);
       INTERVAL ONINTERVAL_API ArcTan (INTERVAL & x);
       INTERVAL ONINTERVAL_API ArcCot (INTERVAL & x);

       INTERVAL ONINTERVAL_API Sinh   (INTERVAL & x);
       INTERVAL ONINTERVAL_API Cosh   (INTERVAL & x);
       INTERVAL ONINTERVAL_API Tanh   (INTERVAL & x);
       INTERVAL ONINTERVAL_API Coth   (INTERVAL & x);
       INTERVAL ONINTERVAL_API ArSinh (INTERVAL & x);
       INTERVAL ONINTERVAL_API ArCosh (INTERVAL & x);
       INTERVAL ONINTERVAL_API ArTanh (INTERVAL & x);
       INTERVAL ONINTERVAL_API ArCoth (INTERVAL & x);

       INTERVAL ONINTERVAL_API Exp    (INTERVAL & x);
       INTERVAL ONINTERVAL_API Log    (INTERVAL & x);
       INTERVAL ONINTERVAL_API Log10  (INTERVAL & x);

       INTERVAL ONINTERVAL_API IAbs   (INTERVAL & x);
       INTERVAL ONINTERVAL_API Sqr    (INTERVAL & x);
       INTERVAL ONINTERVAL_API Sqrt   (INTERVAL & x);
       INTERVAL ONINTERVAL_API Root   (INTERVAL & x, INT n);

       INTERVAL ONINTERVAL_API Power  (INTERVAL & x, INT n);
       INTERVAL ONINTERVAL_API Power  (INTERVAL & x, INTERVAL & y);

#endif /* __FUNCTIONS__ */
