/************************************************************************
*  RealOp.h (Definition of commonly used real operations)
*
*  Version:                     1.1
*  Date:                        6/30/93
*  Author:                      O. Knueppel
*************************************************************************/

#ifndef __REALOP__
#define __REALOP__

#include "Portab.h"
#include "config.h"

#if defined (__cplusplus)
extern "C" {
#endif

VOID RealOpNeg (PREAL pr, PREAL pa, INT dim);

VOID RealOpAdd (PREAL pr, PREAL pa, PREAL pb, INT dim);
VOID RealOpSub (PREAL pr, PREAL pa, PREAL pb, INT dim);
VOID RealOpMul (PREAL pr, REAL  a,  PREAL pb, INT dim);
VOID RealOpDiv (PREAL pr, PREAL pa, REAL  b,  INT dim);

VOID RealOpAddTo   (PREAL pr, PREAL pa, INT dim);
VOID RealOpSubFrom (PREAL pr, PREAL pa, INT dim);
VOID RealOpMulWith (PREAL pr, REAL  a,  INT dim);
VOID RealOpDivBy   (PREAL pr, REAL  a,  INT dim);

REAL RealOpScalp (PREAL pa, PREAL pb, INT dim);

VOID RealOpVecMul (PREAL pr, PREAL pa, PREAL pb, INT rows, INT cols);
VOID RealOpMatMul (PREAL pr, PREAL pa, PREAL pb,
		   INT arows, INT acols, INT bcols);

INT RealOpLessThan     (PREAL pa, PREAL pb, INT dim);
INT RealOpLessEqual    (PREAL pa, PREAL pb, INT dim);
INT RealOpGreaterThan  (PREAL pa, PREAL pb, INT dim);
INT RealOpGreaterEqual (PREAL pa, PREAL pb, INT dim);

#if defined (__cplusplus)
}
#endif

#endif /* __REALOP__ */
