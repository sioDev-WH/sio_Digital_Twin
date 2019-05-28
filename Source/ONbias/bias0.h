/************************************************************************
*  Bias0IEEE.h (Basic Interval Arithmetic Subroutines Level 0)
*
*  Version:                     1.8
*  Date:                        10/1/93
*  Author:                      D. Husung, O. Knueppel
*  Interval Representation:     INFSUP
*  Interval Implementation:     IEEE
*************************************************************************/

#ifndef __BIAS0__
#define __BIAS0__

#define __BIASINFSUP__                  /* __BIASMIDRAD__               */
#define __BIASIEEE__                    /* __BIASEPS__, __BIASFAST__    */

#ifndef __PORTAB__
#include "Portab.h"
#endif

#include "ONbias.h"  // WAH

/************************************************************************
*  Definition of Constants, Types, and Variables
*************************************************************************/

#define REAL    DOUBLE
#define PREAL   PDOUBLE

typedef struct {
  REAL          inf;
  REAL          sup;
} BIASINTERVAL;

typedef BIASINTERVAL FAR * PBIASINTERVAL;

// WAH
//extern ONBIAS_API REAL     BiasEpsilon;            /* min {x >= 0 : 1 + x > 1}     */
//extern ONBIAS_API REAL     BiasEta;                /* min {x > 0}                  */
//extern ONBIAS_API REAL     BiasNaN;                /* NaN                          */
//extern ONBIAS_API REAL     BiasPosInf;             /* +oo                          */
//extern ONBIAS_API REAL     BiasNegInf;             /* -oo                          */

extern ONBIAS_API double   BiasEpsilon;            /* min {x >= 0 : 1 + x > 1}     */
extern ONBIAS_API double   BiasEta;                /* min {x > 0}                  */
extern ONBIAS_API double   BiasNaN;                /* NaN                          */
extern ONBIAS_API double   BiasPosInf;             /* +oo                          */
extern ONBIAS_API double   BiasNegInf;             /* -oo                          */

/************************************************************************
*  Function Prototypes
*************************************************************************/
#if defined (__cplusplus)
extern "C" {
#endif

ONBIAS_API VOID    BiasRoundUp     (VOID);
ONBIAS_API VOID    BiasRoundDown   (VOID);
ONBIAS_API VOID    BiasRoundNear   (VOID);

ONBIAS_API VOID    BiasInit        (VOID);

ONBIAS_API REAL    BiasPredR       (const PREAL         pa);
ONBIAS_API INT     BiasPredI       (const PBIASINTERVAL pR, const PBIASINTERVAL pA);

ONBIAS_API REAL    BiasSuccR       (const PREAL         pa);
ONBIAS_API VOID    BiasSuccI       (const PBIASINTERVAL pR, const PBIASINTERVAL pA);

ONBIAS_API VOID    BiasAddRR       (const PBIASINTERVAL pR,
			 const PREAL         pa, const PREAL         pb);
ONBIAS_API VOID    BiasAddRI       (const PBIASINTERVAL pR,
			 const PREAL         pa, const PBIASINTERVAL pB);
ONBIAS_API VOID    BiasAddII       (const PBIASINTERVAL pR,
			 const PBIASINTERVAL pA, const PBIASINTERVAL pB);

ONBIAS_API VOID    BiasSubRR       (const PBIASINTERVAL pR,
			 const PREAL         pa, PREAL         pb);
ONBIAS_API VOID    BiasSubRI       (const PBIASINTERVAL pR,
			 const PREAL         pa, const PBIASINTERVAL pB);
ONBIAS_API VOID    BiasSubIR       (const PBIASINTERVAL pR,
			 const PBIASINTERVAL pA, const PREAL         pb);
ONBIAS_API VOID    BiasSubII       (const PBIASINTERVAL pR,
			 const PBIASINTERVAL pA, const PBIASINTERVAL pB);

ONBIAS_API VOID    BiasMulRR       (const PBIASINTERVAL pR,
			 const PREAL         pa, const PREAL         pb);
ONBIAS_API VOID    BiasMulRI       (const PBIASINTERVAL pR,
			 const PREAL         pa, const PBIASINTERVAL pB);
ONBIAS_API VOID    BiasMulII       (const PBIASINTERVAL pR,
			 const PBIASINTERVAL pA, const PBIASINTERVAL pB);

ONBIAS_API VOID    BiasDivRR       (const PBIASINTERVAL pR,
			 const PREAL         pa, const PREAL         pb);
ONBIAS_API VOID    BiasDivRI       (const PBIASINTERVAL pR,
			 const PREAL         pa, const PBIASINTERVAL pB);
ONBIAS_API VOID    BiasDivIR       (const PBIASINTERVAL pR,
			 const PBIASINTERVAL pA, const PREAL         pb);
ONBIAS_API VOID    BiasDivII       (const PBIASINTERVAL pR,
			 const PBIASINTERVAL pA, const PBIASINTERVAL pB);

ONBIAS_API VOID    BiasMacRR       (const PBIASINTERVAL pR,
			 const PREAL         pa, const PREAL         pb);
ONBIAS_API VOID    BiasMacRI       (const PBIASINTERVAL pR,
			 const PREAL         pa, const PBIASINTERVAL pB);
ONBIAS_API VOID    BiasMacII       (const PBIASINTERVAL pR,
			 const PBIASINTERVAL pA, const PBIASINTERVAL pB);

/*
  REAL    BiasInf         (const PBIASINTERVAL pA);
  REAL    BiasSub         (const PBIASINTERVAL pA);
*/

ONBIAS_API VOID    BiasNeg         (const PBIASINTERVAL pR, const PBIASINTERVAL pA);

ONBIAS_API REAL    BiasMid         (const PBIASINTERVAL pA);
ONBIAS_API VOID    BiasMidRad      (const PREAL         pm, const PREAL         pr,
			 const PBIASINTERVAL pA);
ONBIAS_API REAL    BiasDiam        (const PBIASINTERVAL pA);

ONBIAS_API REAL    BiasAbs         (const PBIASINTERVAL pA);

ONBIAS_API REAL    BiasDistRI      (const PREAL         pa, const PBIASINTERVAL pB);
ONBIAS_API REAL    BiasDistII      (const PBIASINTERVAL pA, const PBIASINTERVAL pB);

ONBIAS_API INT     BiasIntersection(const PBIASINTERVAL pR,
			 const PBIASINTERVAL pA, const PBIASINTERVAL pB);

ONBIAS_API VOID    BiasHullR       (const PBIASINTERVAL pR, const PREAL         pa);
ONBIAS_API VOID    BiasHullRR      (const PBIASINTERVAL pR,
			 const PREAL         pa, const PREAL         pb);
ONBIAS_API VOID    BiasHullRI      (const PBIASINTERVAL pR,
			 const PREAL         pa, const PBIASINTERVAL pB);
ONBIAS_API VOID    BiasHullII      (const PBIASINTERVAL pR,
			 const PBIASINTERVAL pA, const PBIASINTERVAL pB);

ONBIAS_API INT     BiasInR         (const PREAL         pa, const PBIASINTERVAL pB);
ONBIAS_API INT     BiasInI         (const PBIASINTERVAL pA, const PBIASINTERVAL pB);

ONBIAS_API INT     BiasInInteriorR (const PREAL         pa, const PBIASINTERVAL pB);
ONBIAS_API INT     BiasInInteriorI (const PBIASINTERVAL pA, const PBIASINTERVAL pB);

ONBIAS_API INT     BiasIsEqual     (const PBIASINTERVAL pA, const PBIASINTERVAL pB);

#define BiasInf(pA)     ((pA)->inf)
#define BiasSup(pA)     ((pA)->sup)

#define BiasAddIR(pR, pA, pb)    BiasAddRI (pR, pb, pA)
#define BiasMulIR(pR, pA, pb)    BiasMulRI (pR, pb, pA)
#define BiasMacIR(pR, pA, pb)    BiasMacRI (pR, pb, pA)
#define BiasDistIR(pA, pb)       BiasDistRI (pb, pA)
#define BiasHullIR(pR, pA, pb)   BiasHullRI (pR, pb, pA)

#if defined (__cplusplus)
}
#endif

#endif /* __BIAS0__ */
