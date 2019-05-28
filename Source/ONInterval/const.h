/************************************************************************
*  Constants.h (Machine dependent constants)
*
*  Version:                     1.3
*  Date:                        4/5/93
*  Author:                      O. Knueppel
*************************************************************************/

#ifndef __CONSTANTS__
#define __CONSTANTS__

#include "Bias0.h"

class Machine {
public:
  static REAL Epsilon;            // smallest positive number with 1.0 + Eps > 1.0
  static REAL MinPositive;        // smallest positive number
  static REAL PosInfinity;        // should be +oo
  static REAL NegInfinity;        // should be -oo
  static REAL NaN;                // should be NaN
  Machine();
  ~Machine() { }
};

#endif /* __CONSTANTS__ */
