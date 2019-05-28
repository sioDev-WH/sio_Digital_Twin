/************************************************************************
*  Utilities.h (Some utility routines)
*
*  Version:                     1.6
*  Date:                        9/22/93
*  Author:                      O. Knueppel
*************************************************************************/

#ifndef __UTILITIES__
#define __UTILITIES__

#include "ivalmat.h"

MATRIX Inverse (MATRIX &);
MATRIX Transpose (MATRIX &);
INTERVAL_VECTOR Lower (INTERVAL_VECTOR &, INT);
INTERVAL_VECTOR Upper (INTERVAL_VECTOR &, INT);
MATRIX Id (INT);

REAL RelDiam (INTERVAL &);
VECTOR RelDiam (INTERVAL_VECTOR &);

#endif /* __UTILITIES__ */
