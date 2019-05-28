/************************************************************************
*  LSS.h (Solvers for Linear Systems)
*
*  Version:                     1.1
*  Date:                        4/6/93
*  Author:                      O. Knueppel
*************************************************************************/

#ifndef __LSS__
#define __LSS__

#include "ivalmat.h"

INTERVAL_VECTOR LSS  (MATRIX &, VECTOR &, INT &);
INTERVAL_VECTOR ILSS (INTERVAL_MATRIX &, INTERVAL_VECTOR &, INT &);

#endif /* __LSS__ */
