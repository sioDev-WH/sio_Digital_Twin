/************************************************************************
*  HighPrec.h (Definition of operations with exact scalar product)
*
*  Version:                     1.3
*  Date:                        10/19/93
*  Author:                      O. Knueppel
*************************************************************************/

#ifndef __HIGHPREC__
#define __HIGHPREC__

#include "ivalmat.h"
#include "Li.h"

REAL   HighPrecMul (VECTOR &, VECTOR &);
VECTOR HighPrecMul (MATRIX &, VECTOR &);
MATRIX HighPrecMul (MATRIX &, MATRIX &);

INTERVAL HighPrecMulBounds (VECTOR &         , VECTOR &         );
INTERVAL HighPrecMul       (VECTOR &         , INTERVAL_VECTOR &);
INTERVAL HighPrecMul       (INTERVAL_VECTOR &, VECTOR &         );
INTERVAL HighPrecMul       (INTERVAL_VECTOR &, INTERVAL_VECTOR &);

INTERVAL_VECTOR HighPrecMulBounds (MATRIX &         , VECTOR &         );
INTERVAL_VECTOR HighPrecMul       (MATRIX &         , INTERVAL_VECTOR &);
INTERVAL_VECTOR HighPrecMul       (INTERVAL_MATRIX &, VECTOR &         );
INTERVAL_VECTOR HighPrecMul       (INTERVAL_MATRIX &, INTERVAL_VECTOR &);

INTERVAL_MATRIX HighPrecMulBounds (MATRIX &         , MATRIX &         );
INTERVAL_MATRIX HighPrecMul       (MATRIX &         , INTERVAL_MATRIX &);
INTERVAL_MATRIX HighPrecMul       (INTERVAL_MATRIX &, MATRIX &         );
INTERVAL_MATRIX HighPrecMul       (INTERVAL_MATRIX &, INTERVAL_MATRIX &);

INTERVAL_MATRIX IdMinusHighPrecMul (MATRIX &         , MATRIX &         );
INTERVAL_MATRIX IdMinusHighPrecMul (MATRIX &         , INTERVAL_MATRIX &);
INTERVAL_MATRIX IdMinusHighPrecMul (INTERVAL_MATRIX &, MATRIX &         );
INTERVAL_MATRIX IdMinusHighPrecMul (INTERVAL_MATRIX &, INTERVAL_MATRIX &);

// the following functions are for internal use only!
LREAL  HighPrecScalpLr (PREAL, PREAL, INT, INT);
LIREAL HighPrecScalpLi (PREAL, PREAL, INT, INT);
LIREAL HighPrecScalpLi (PREAL, PBIASINTERVAL, INT, INT);
LIREAL HighPrecScalpLi (PBIASINTERVAL, PREAL, INT, INT);
LIREAL HighPrecScalpLi (PBIASINTERVAL, PBIASINTERVAL, INT, INT);

#endif /* __HIGHPREC__ */
