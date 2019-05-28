/************************************************************************
*  Bias2IEEE.h (Basic Interval Arithmetic Subroutines Level 2)
*
*  Version:                     1.3
*  Date:                        10/1/93
*  Author:                      O. Knueppel
*  Interval Representation:     INFSUP
*  Interval Implementation:     IEEE
*************************************************************************/

#ifndef __BIAS2__
#define __BIAS2__

#ifndef __BIAS0__
#include "Bias0.h"
#endif

#ifndef __BIAS1__
#include "Bias1.h"
#endif

#include "ONbias.h"  // WAH

/* #define __BIAS2USEVECTOROPERATIONS__ */

/************************************************************************
*  Function Prototypes
*************************************************************************/

#if defined (__cplusplus)
extern "C" {
#endif

ONBIAS_API VOID    BiasMulRMR      (PBIASINTERVAL pR, PREAL         pa, PREAL         pb,
			 const INT rows, const INT cols);
ONBIAS_API VOID    BiasMulRMI      (PBIASINTERVAL pR, PREAL         pa, PBIASINTERVAL pB,
			 const INT rows, const INT cols);
ONBIAS_API VOID    BiasMulIMR      (PBIASINTERVAL pR, PBIASINTERVAL pA, PREAL         pb,
			 const INT rows, const INT cols);
ONBIAS_API VOID    BiasMulIMI      (PBIASINTERVAL pR, PBIASINTERVAL pA, PBIASINTERVAL pB,
			 const INT rows, const INT cols);

ONBIAS_API VOID    BiasDivMRR      (PBIASINTERVAL pR, PREAL         pa, PREAL         pb,
			 const INT rows, const INT cols);
ONBIAS_API VOID    BiasDivMRI      (PBIASINTERVAL pR, PREAL         pa, PBIASINTERVAL pB,
			 const INT rows, const INT cols);
ONBIAS_API VOID    BiasDivMIR      (PBIASINTERVAL pR, PBIASINTERVAL pA, PREAL         pb,
			 const INT rows, const INT cols);
ONBIAS_API VOID    BiasDivMII      (PBIASINTERVAL pR, PBIASINTERVAL pA, PBIASINTERVAL pB,
			 const INT rows, const INT cols);

ONBIAS_API VOID    BiasMulMRVR     (PBIASINTERVAL pR, PREAL         pa, PREAL         pb,
			 const INT rows, const INT cols);
ONBIAS_API VOID    BiasMulMRVI     (PBIASINTERVAL pR, PREAL         pa, PBIASINTERVAL pB,
			 const INT rows, const INT cols);
ONBIAS_API VOID    BiasMulMIVR     (PBIASINTERVAL pR, PBIASINTERVAL pA, PREAL         pb,
			 const INT rows, const INT cols);
ONBIAS_API VOID    BiasMulMIVI     (PBIASINTERVAL pR, PBIASINTERVAL pA, PBIASINTERVAL pB,
			 const INT rows, const INT cols);

#if defined (__BIAS2USEVECTOROPERATIONS__)
#define BiasAddMRMR(pR, pa, pb, r, c)      BiasAddVRVR (pR, pa, pb, (r)*(c))
#define BiasAddMRMI(pR, pa, pB, r, c)      BiasAddVRVI (pR, pa, pB, (r)*(c))
#define BiasAddMIMR(pR, pA, pb, r, c)      BiasAddVIVR (pR, pA, pb, (r)*(c))
#define BiasAddMIMI(pR, pA, pB, r, c)      BiasAddVIVI (pR, pA, pB, (r)*(c))
#define BiasSubMRMR(pR, pa, pb, r, c)      BiasSubVRVR (pR, pa, pb, (r)*(c))
#define BiasSubMRMI(pR, pa, pB, r, c)      BiasSubVRVI (pR, pa, pB, (r)*(c))
#define BiasSubMIMR(pR, pA, pb, r, c)      BiasSubVIVR (pR, pA, pb, (r)*(c))
#define BiasSubMIMI(pR, pA, pB, r, c)      BiasSubVIVI (pR, pA, pB, (r)*(c))
#else

ONBIAS_API VOID    BiasAddMRMR     (PBIASINTERVAL pR, PREAL         pa, PREAL         pb,
			 const INT rows, const INT cols);
ONBIAS_API VOID    BiasAddMRMI     (PBIASINTERVAL pR, PREAL         pa, PBIASINTERVAL pB,
			 const INT rows, const INT cols);
#define BiasAddMIMR(pR, pA, pb, r, c)      BiasAddMRMI (pR, pb, pA, r, c)
ONBIAS_API VOID    BiasAddMIMI     (PBIASINTERVAL pR, PBIASINTERVAL pA, PBIASINTERVAL pB,
			 const INT rows, const INT cols);

ONBIAS_API VOID    BiasSubMRMR     (PBIASINTERVAL pR, PREAL         pa, PREAL         pb,
			 const INT rows, const INT cols);
ONBIAS_API VOID    BiasSubMRMI     (PBIASINTERVAL pR, PREAL         pa, PBIASINTERVAL pB,
			 const INT rows, const INT cols);
ONBIAS_API VOID    BiasSubMIMR     (PBIASINTERVAL pR, PBIASINTERVAL pA, PREAL         pb,
			 const INT rows, const INT cols);
ONBIAS_API VOID    BiasSubMIMI     (PBIASINTERVAL pR, PBIASINTERVAL pA, PBIASINTERVAL pB,
			 const INT rows, const INT cols);
#endif

ONBIAS_API VOID    BiasMulMRMR     (PBIASINTERVAL pR, PREAL         pa, PREAL         pb,
			 const INT arows, const INT acols, const INT bcols);
ONBIAS_API VOID    BiasMulMRMI     (PBIASINTERVAL pR, PREAL         pa, PBIASINTERVAL pB,
			 const INT arows, const INT acols, const INT Bcols);
ONBIAS_API VOID    BiasMulMIMR     (PBIASINTERVAL pR, PBIASINTERVAL pA, PREAL         pb,
			 const INT Arows, const INT Acols, const INT bcols);
ONBIAS_API VOID    BiasMulMIMI     (PBIASINTERVAL pR, PBIASINTERVAL pA, PBIASINTERVAL pB,
			 const INT Arows, const INT Acols, const INT Bcols);

#define BiasPredMR(pr, pa, r, c)           BiasPredVR (pr, pa, (r)*(c))
#define BiasPredMI(pR, pA, r, c)           BiasPredVI (pR, pA, (r)*(c))
#define BiasSuccMR(pr, pa, r, c)           BiasSuccVR (pr, pa, (r)*(c))
#define BiasSuccMI(pR, pA, r, c)           BiasSuccVI (pR, pA, (r)*(c))

#define BiasInfM(pr, pA, r, c)             BiasInfV (pr, pA, (r)*(c))
#define BiasSupM(pr, pA, r, c)             BiasSupV (pr, pA, (r)*(c))

#define BiasNegM(pR, pA, r, c)             BiasNegV (pR, pA, (r)*(c))

#define BiasMidM(pr, pA, r, c)             BiasMidV (pr, pA, (r)*(c))
#define BiasMidRadM(pm, pr, pA, r, c)      BiasMidRadV (pm, pr, pA, (r)*(c))

#define BiasDiamM(pr, pA, r, c)            BiasDiamV (pr, pA, (r)*(c))

#define BiasAbsM(pr, pA, r, c)             BiasAbsV (pr, pA, (r)*(c))

#define BiasIntersectionM(pR, pA, pB, r, c)   BiasIntersectionV (pR, pA, pB, (r)*(c))

#define BiasHullMR(pR, pa, r, c)           BiasHullVR (pR, pa, (r)*(c))
#define BiasHullMRMR(pR, pa, pb, r, c)     BiasHullVRVR (pR, pa, pb, (r)*(c))
#define BiasHullMRMI(pR, pa, pB, r, c)     BiasHullVRVI (pR, pa, pB, (r)*(c))
#define BiasHullMIMR(pR, pA, pb, r, c)     BiasHullVIVR (pR, pA, pb, (r)*(c))
#define BiasHullMIMI(pR, pA, pB, r, c)     BiasHullVIVI (pR, pA, pB, (r)*(c))

#define BiasInMR(pa, pB, r, c)             BiasInVR (pa, pB, (r)*(c))
#define BiasInMI(pA, pB, r, c)             BiasInVI (pA, pB, (r)*(c))

#define BiasInInteriorMR(pa, pB, r, c)     BiasInInteriorVR (pa, pB, (r)*(c))
#define BiasInInteriorMI(pA, pB, r, c)     BiasInInteriorVI (pA, pB, (r)*(c))

#define BiasIsEqualM(pA, pB, r, c)         BiasIsEqualV (pA, pB, (r)*(c))

#define BiasSetToZeroM(pR, r, c)           BiasSetToZeroV (pR, (r)*(c))

#if defined (__cplusplus)
}
#endif

#endif /* __BIAS2__ */
