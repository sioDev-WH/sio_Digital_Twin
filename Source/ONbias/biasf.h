/************************************************************************
*  BiasF.h (Basic Interval Arithmetic Subroutines Standard Functions)
*
*  Version:                     1.4
*  Date:                        9/29/93
*  Author:                      O. Knueppel
*  Interval Representation:     any
*  Interval Implementation:     any
*************************************************************************/

#ifndef __BIASF__
#define __BIASF__

#include "ONbias.h"  // WAH
#include "Bias0.h"


/************************************************************************
*  Definition of Constants, Types, and Variables
*************************************************************************/

extern REAL ONBIAS_API     BiasPi;                 /* 3.141...                     */
extern REAL ONBIAS_API     BiasTwoPi;
extern REAL ONBIAS_API     BiasPiHalf;
extern REAL ONBIAS_API     BiasPiQuarter;
extern REAL ONBIAS_API     BiasE;
extern REAL ONBIAS_API     BiasSqrt2;
extern REAL ONBIAS_API     BiasInvSqrt2;           /* 1/ Sqrt(2)                   */
extern REAL ONBIAS_API     BiasLn10;

/************************************************************************
*  Function Prototypes
*************************************************************************/

#if defined (__cplusplus)
extern "C" {
#endif

ONBIAS_API VOID    BiasFuncInit    (VOID);

ONBIAS_API VOID    BiasSin    (const PBIASINTERVAL, const PBIASINTERVAL);
ONBIAS_API VOID    BiasCos    (const PBIASINTERVAL, const PBIASINTERVAL);
ONBIAS_API VOID    BiasTan    (const PBIASINTERVAL, const PBIASINTERVAL);
ONBIAS_API VOID    BiasCot    (const PBIASINTERVAL, const PBIASINTERVAL);

ONBIAS_API VOID    BiasArcSin (const PBIASINTERVAL, const PBIASINTERVAL);
ONBIAS_API VOID    BiasArcCos (const PBIASINTERVAL, const PBIASINTERVAL);
ONBIAS_API VOID    BiasArcTan (const PBIASINTERVAL, const PBIASINTERVAL);
ONBIAS_API VOID    BiasArcCot (const PBIASINTERVAL, const PBIASINTERVAL);

ONBIAS_API VOID    BiasSinh   (const PBIASINTERVAL, const PBIASINTERVAL);
ONBIAS_API VOID    BiasCosh   (const PBIASINTERVAL, const PBIASINTERVAL);
ONBIAS_API VOID    BiasTanh   (const PBIASINTERVAL, const PBIASINTERVAL);
ONBIAS_API VOID    BiasCoth   (const PBIASINTERVAL, const PBIASINTERVAL);

ONBIAS_API VOID    BiasArSinh (const PBIASINTERVAL, const PBIASINTERVAL);
ONBIAS_API VOID    BiasArCosh (const PBIASINTERVAL, const PBIASINTERVAL);
ONBIAS_API VOID    BiasArTanh (const PBIASINTERVAL, const PBIASINTERVAL);
ONBIAS_API VOID    BiasArCoth (const PBIASINTERVAL, const PBIASINTERVAL);

ONBIAS_API VOID    BiasExp    (const PBIASINTERVAL, const PBIASINTERVAL);
ONBIAS_API VOID    BiasLog    (const PBIASINTERVAL, const PBIASINTERVAL);
ONBIAS_API VOID    BiasLog10  (const PBIASINTERVAL, const PBIASINTERVAL);

ONBIAS_API VOID    BiasIAbs   (const PBIASINTERVAL, const PBIASINTERVAL);
ONBIAS_API VOID    BiasSqr    (const PBIASINTERVAL, const PBIASINTERVAL);

ONBIAS_API VOID    BiasSqrt   (const PBIASINTERVAL, const PBIASINTERVAL);
ONBIAS_API VOID    BiasRoot   (const PBIASINTERVAL, const PBIASINTERVAL, const INT);

ONBIAS_API VOID    BiasPowerN (const PBIASINTERVAL, const PBIASINTERVAL, const INT);
ONBIAS_API VOID    BiasPowerI (const PBIASINTERVAL, const PBIASINTERVAL, const PBIASINTERVAL);


#if defined (__cplusplus)
}
#endif

#endif /* __BIASF__ */
