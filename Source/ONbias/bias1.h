/************************************************************************
*  Bias1IEEE.h (Basic Interval Arithmetic Subroutines Level 1)
*
*  Version:                     1.6
*  Date:                        10/1/93
*  Author:                      O. Knueppel
*  Interval Representation:     INFSUP
*  Interval Implementation:     IEEE
*************************************************************************/

#ifndef __BIAS1__
#define __BIAS1__

#ifndef __BIAS0__
#include "Bias0.h"
#endif

#include "ONbias.h"  // WAH

/************************************************************************
*  Function Prototypes
*************************************************************************/

#if defined (__cplusplus)
extern "C" {
#endif

ONBIAS_API VOID    BiasPredVR      (      PREAL         pr,
			       PREAL         pa, const INT dim);
ONBIAS_API INT     BiasPredVI      (      PBIASINTERVAL pR,
			       PBIASINTERVAL pA, const INT dim);

ONBIAS_API VOID    BiasSuccVR      (      PREAL         pr,
			       PREAL         pa, const INT dim);
ONBIAS_API VOID    BiasSuccVI      (      PBIASINTERVAL pR,
			       PBIASINTERVAL pA, const INT dim);

ONBIAS_API VOID    BiasAddVRVR     (const PBIASINTERVAL pR, const PREAL         pa,
			 const PREAL         pb, const INT dim);
ONBIAS_API VOID    BiasAddVRVI     (const PBIASINTERVAL pR, const PREAL         pa,
			 const PBIASINTERVAL pB, const INT dim);
ONBIAS_API VOID    BiasAddVIVI     (const PBIASINTERVAL pR, const PBIASINTERVAL pa,
			 const PBIASINTERVAL pB, const INT dim);

ONBIAS_API VOID    BiasSubVRVR     (const PBIASINTERVAL pR, const PREAL         pa,
			 const PREAL         pb, const INT dim);
ONBIAS_API VOID    BiasSubVRVI     (const PBIASINTERVAL pR, const PREAL         pa,
			 const PBIASINTERVAL pB, const INT dim);
ONBIAS_API VOID    BiasSubVIVR     (const PBIASINTERVAL pR, const PBIASINTERVAL pA,
			 const PREAL         pb, const INT dim);
ONBIAS_API VOID    BiasSubVIVI     (const PBIASINTERVAL pR, const PBIASINTERVAL pa,
			 const PBIASINTERVAL pB, const INT dim);

ONBIAS_API VOID    BiasMulRVR      (const PBIASINTERVAL pR, const PREAL         pa,
			 const PREAL         pb, const INT dim);
ONBIAS_API VOID    BiasMulIVR      (      PBIASINTERVAL pR, const PBIASINTERVAL pA,
			       PREAL         pb, const INT dim);
ONBIAS_API VOID    BiasMulRVI      (const PBIASINTERVAL pR, const PREAL         pa,
			 const PBIASINTERVAL pB, const INT dim);
ONBIAS_API VOID    BiasMulIVI      (      PBIASINTERVAL pR, const PBIASINTERVAL pa,
			       PBIASINTERVAL pB, const INT dim);

ONBIAS_API VOID    BiasMacRVR      (const PBIASINTERVAL pR, const PREAL         pa,
			 const PREAL         pb, const INT dim);
ONBIAS_API VOID    BiasMacIVR      (      PBIASINTERVAL pR, const PBIASINTERVAL pA,
			       PREAL         pb, const INT dim);
ONBIAS_API VOID    BiasMacRVI      (const PBIASINTERVAL pR, const PREAL         pa,
			 const PBIASINTERVAL pB, const INT dim);
ONBIAS_API VOID    BiasMacIVI      (      PBIASINTERVAL pR, const PBIASINTERVAL pa,
			       PBIASINTERVAL pB, const INT dim);

ONBIAS_API VOID    BiasMacRVIs     (const PBIASINTERVAL pR, const PREAL         pa,
			 const PBIASINTERVAL pB, const INT dim, const INT Bstep);
ONBIAS_API VOID    BiasMacsRVIs    (const PBIASINTERVAL pR,
			 const PREAL         pa, const PBIASINTERVAL pB,
			 const INT dim, const INT Rstep, const INT Bstep);

ONBIAS_API VOID    BiasDivVRR      (const PBIASINTERVAL pR, const PREAL         pa,
			 const PREAL         pb, const INT dim);
ONBIAS_API VOID    BiasDivVIR      (const PBIASINTERVAL pR, const PBIASINTERVAL pA,
			 const PREAL         pb, const INT dim);
ONBIAS_API VOID    BiasDivVRI      (const PBIASINTERVAL pR, const PREAL         pa,
			 const PBIASINTERVAL pB, const INT dim);
ONBIAS_API VOID    BiasDivVII      (      PBIASINTERVAL pR,       PBIASINTERVAL pa,
			 const PBIASINTERVAL pB, const INT dim);

ONBIAS_API VOID    BiasMacVRVR     (const PBIASINTERVAL pR, const PREAL         pa,
			 const PREAL         pb, const INT dim);
ONBIAS_API VOID    BiasMacVRVI     (const PBIASINTERVAL pR, const PREAL         pa,
			 const PBIASINTERVAL pB, const INT dim);
ONBIAS_API VOID    BiasMacVIVI     (const PBIASINTERVAL pR,       PBIASINTERVAL pA,
			       PBIASINTERVAL pB, const INT dim);

ONBIAS_API VOID    BiasInfV        (      PREAL         pr,       PBIASINTERVAL pA, const INT dim);
ONBIAS_API VOID    BiasSupV        (      PREAL         pr,       PBIASINTERVAL pA, const INT dim);

ONBIAS_API VOID    BiasNegV        (      PBIASINTERVAL pR,       PBIASINTERVAL pA, const INT dim);

ONBIAS_API VOID    BiasMidV        (      PREAL         pr,       PBIASINTERVAL pA, const INT dim);
ONBIAS_API VOID    BiasMidRadV     (      PREAL         pm,       PREAL         pr,
			       PBIASINTERVAL pA, const INT dim);
ONBIAS_API VOID    BiasDiamV       (      PREAL         pr,
			       PBIASINTERVAL pA, const INT dim);

ONBIAS_API VOID    BiasAbsV        (      PREAL         pr,
			       PBIASINTERVAL pA, const INT dim);

ONBIAS_API INT     BiasIntersectionV (      PBIASINTERVAL pR,
			         PBIASINTERVAL pA,       PBIASINTERVAL pB, const INT dim);

ONBIAS_API VOID    BiasHullVR      (      PBIASINTERVAL pR,
			       PREAL         pa, const INT dim);
ONBIAS_API VOID    BiasHullVRVR    (      PBIASINTERVAL pR,
			       PREAL         pa,       PREAL         pb, const INT dim);
ONBIAS_API VOID    BiasHullVRVI    (      PBIASINTERVAL pR,
			       PREAL         pa,       PBIASINTERVAL pB, const INT dim);
ONBIAS_API VOID    BiasHullVIVI    (      PBIASINTERVAL pR,
			       PBIASINTERVAL pA,       PBIASINTERVAL pB, const INT dim);

ONBIAS_API INT     BiasInVR        (      PREAL         pa,       PBIASINTERVAL pB, const INT dim);
ONBIAS_API INT     BiasInVI        (      PBIASINTERVAL pA,       PBIASINTERVAL pB, const INT dim);

ONBIAS_API INT     BiasInInteriorVR(      PREAL         pa,       PBIASINTERVAL pB, const INT dim);
ONBIAS_API INT     BiasInInteriorVI(      PBIASINTERVAL pA,       PBIASINTERVAL pB, const INT dim);

ONBIAS_API INT     BiasIsEqualV    (      PBIASINTERVAL pA,       PBIASINTERVAL pB, const INT dim);

ONBIAS_API VOID    BiasSetToZeroV  (const PBIASINTERVAL pR, const INT dim);
ONBIAS_API VOID    BiasSetToZeroVs (      PBIASINTERVAL pR, const INT dim, const INT step);

#define BiasAddVIVR(pR, pA, pb, d)   BiasAddVRVI (pR, pb, pA, d)
#define BiasMacVIVR(pR, pA, pb, d)   BiasMacVRVI (pR, pb, pA, d)
#define BiasHullVIVR(pR, pA, pb, d)  BiasHullVRVI (pR, pb, pA, d)

#if defined (__cplusplus)
}
#endif

#endif /* __BIAS1__ */
