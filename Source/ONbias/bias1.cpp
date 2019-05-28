/************************************************************************
*  Bias1IEEE.c (Basic Interval Arithmetic Subroutines Level 1)
*
*  Version:                     1.16
*  Date:                        10/1/93
*  Author:                      O. Knueppel
*  Interval Representation:     INFSUP
*  Interval Implementation:     IEEE
*************************************************************************/

static char sccs_id[] = "@(#)Bias1IEEE.c 1.16 93/10/01 OK";

#include "Bias1.h"
#include "BiasInt.h"
#include <memory.h>

#if !defined (__BIASINFSUP__) || !defined (__BIASIEEE__)
#error __BIASINFSUP__ and __BIASIEEE__ not set
#endif

static PCHAR ErrorVectorDivideByZero = "Vector Division by Zero";

/************************************************************************
*  Implementation of global functions
*************************************************************************/

VOID BiasPredVR (PREAL pr, PREAL pa, const INT dim)
  /**********************************************************************
  *  r_i = largest possible floating point number with r_i < a_i
  */
{
  INT i;
  REAL Eta = BiasEta;

  _BiasRoundDown ();
  for (i = 0; i < dim; i++) *(pr++) = *(pa++) - Eta;
  _SetRoundToNearest();
}

INT BiasPredVI (PBIASINTERVAL pR_start, PBIASINTERVAL pA_start,
		const INT dim)
  /**********************************************************************
  *  R_i = largest possible interval with R_i.inf > A_i.inf and R_i.sup < A_i.sup
  *  Result: 1, if R is a true interval vector, 0 otherwise
  */
{
  INT i;
  INT ok = 1;
  PBIASINTERVAL pR, pA;
  REAL Eta = BiasEta;

  _BiasRoundDown ();
  pR = pR_start; pA = pA_start;
  for (i = 0; i < dim; i++) (pR++)->sup = (pA++)->sup - Eta;
  _BiasRoundUp ();
  pR = pR_start; pA = pA_start;
  for (i = 0; i < dim; i++) (pR++)->inf = (pA++)->inf + Eta;
  pR = pR_start;
  for (i = 0; i < dim; i++) ok &= (pR->inf <= pR->sup);
  _SetRoundToNearest();
  return ok;
}

VOID BiasSuccVR (PREAL pr, PREAL pa, const INT dim)
  /**********************************************************************
  *  r_i = smallest possible floating point number with r_i > a_i
  */
{
  INT i;
  REAL Eta = BiasEta;

  _BiasRoundUp ();
  for (i = 0; i < dim; i++) *(pr++) = *(pa++) + Eta;
  _SetRoundToNearest();
}

VOID BiasSuccVI (PBIASINTERVAL pR_start, PBIASINTERVAL pA_start,
		 const INT dim)
  /**********************************************************************
  *  R_i = smallest possible interval with R_i.inf < A_i.inf
  *        and R_i.sup > A_i.sup
  */
{
  INT i;
  PBIASINTERVAL pR, pA;
  REAL Eta = BiasEta;

  _BiasRoundDown ();
  pR = pR_start; pA = pA_start;
  for (i = 0; i < dim; i++) (pR++)->inf = (pA++)->inf - Eta;
  _BiasRoundUp ();
  pR = pR_start; pA = pA_start;
  for (i = 0; i < dim; i++) (pR++)->sup = (pA++)->sup + Eta;
}

VOID BiasAddVRVR (const PBIASINTERVAL pR_start, const PREAL pa_start,
		  const PREAL pb_start, const INT dim)
  /**********************************************************************
   *  vR = va + vb
   */
{
  INT i;
  PREAL pa, pb;
  PBIASINTERVAL pR;

  _BiasRoundDown ();
  pa = pa_start; pb = pb_start; pR = pR_start;
  for (i = 0; i < dim; i++) (pR++)->inf = *(pa++) + *(pb++);
  _BiasRoundUp ();
  pa = pa_start; pb = pb_start; pR = pR_start;
  for (i = 0; i < dim; i++) (pR++)->sup = *(pa++) + *(pb++);
  _SetRoundToNearest();
}

VOID BiasAddVRVI (const PBIASINTERVAL pR_start, const PREAL pa_start,
		  const PBIASINTERVAL pB_start, const INT dim)
  /**********************************************************************
   *  vR = va + vB
   */
{
  INT i;
  PREAL pa;
  PBIASINTERVAL pB, pR;

  _BiasRoundDown ();
  pa = pa_start; pB = pB_start; pR = pR_start;
  for (i = 0; i < dim; i++) (pR++)->inf = *(pa++) + (pB++)->inf;
  _BiasRoundUp ();
  pa = pa_start; pB = pB_start; pR = pR_start;
  for (i = 0; i < dim; i++) (pR++)->sup = *(pa++) + (pB++)->sup;
  _SetRoundToNearest();
}

VOID BiasAddVIVI (const PBIASINTERVAL pR_start, const PBIASINTERVAL pA_start,
		  const PBIASINTERVAL pB_start, const INT dim)
  /**********************************************************************
   *  vR = vA + vB
   */
{
  INT i;
  PBIASINTERVAL pA, pB, pR;

  _BiasRoundDown ();
  pA = pA_start; pB = pB_start; pR = pR_start;
  for (i = 0; i < dim; i++) (pR++)->inf = (pA++)->inf + (pB++)->inf;
  _BiasRoundUp ();
  pA = pA_start; pB = pB_start; pR = pR_start;
  for (i = 0; i < dim; i++) (pR++)->sup = (pA++)->sup + (pB++)->sup;
  _SetRoundToNearest();
}

VOID BiasSubVRVR (const PBIASINTERVAL pR_start, const PREAL pa_start,
		  const PREAL pb_start, const INT dim)
  /**********************************************************************
   *  vR = va - vb
   */
{
  INT i;
  PREAL pa, pb;
  PBIASINTERVAL pR;

  _BiasRoundDown ();
  pa = pa_start; pb = pb_start; pR = pR_start;
  for (i = 0; i < dim; i++) (pR++)->inf = *(pa++) - *(pb++);
  _BiasRoundUp ();
  pa = pa_start; pb = pb_start; pR = pR_start;
  for (i = 0; i < dim; i++) (pR++)->sup = *(pa++) - *(pb++);
  _SetRoundToNearest();
}

VOID BiasSubVRVI (const PBIASINTERVAL pR_start, const PREAL pa_start,
		  const PBIASINTERVAL pB_start, const INT dim)
  /**********************************************************************
   *  vR = va - vB
   *  Assertion: vR != vB
   */
{
  INT i;
  PREAL pa;
  PBIASINTERVAL pB, pR;

  _BiasRoundDown ();
  pa = pa_start; pB = pB_start; pR = pR_start;
  for (i = 0; i < dim; i++) (pR++)->inf = *(pa++) - (pB++)->sup;
  _BiasRoundUp ();
  pa = pa_start; pB = pB_start; pR = pR_start;
  for (i = 0; i < dim; i++) (pR++)->sup = *(pa++) - (pB++)->inf;
  _SetRoundToNearest();
}

VOID BiasSubVIVR (const PBIASINTERVAL pR_start, const PBIASINTERVAL pA_start,
		  const PREAL pb_start, const INT dim)
  /**********************************************************************
   *  vR = vA - vb
   */
{
  INT i;
  PREAL pb;
  PBIASINTERVAL pA, pR;

  _BiasRoundDown ();
  pA = pA_start; pb = pb_start; pR = pR_start;
  for (i = 0; i < dim; i++) (pR++)->inf = (pA++)->inf - *(pb++);
  _BiasRoundUp ();
  pA = pA_start; pb = pb_start; pR = pR_start;
  for (i = 0; i < dim; i++) (pR++)->sup = (pA++)->sup - *(pb++);
  _SetRoundToNearest();
}

VOID BiasSubVIVI (const PBIASINTERVAL pR_start, const PBIASINTERVAL pA_start,
		  const PBIASINTERVAL pB_start, const INT dim)
  /**********************************************************************
   *  vR = vA - vB
   *  Assertion: vR != vB
   */
{
  INT i;
  PBIASINTERVAL pA, pB, pR;

  _BiasRoundDown ();
  pA = pA_start; pB = pB_start; pR = pR_start;
  for (i = 0; i < dim; i++) (pR++)->inf = (pA++)->inf - (pB++)->sup;
  _BiasRoundUp ();
  pA = pA_start; pB = pB_start; pR = pR_start;
  for (i = 0; i < dim; i++) (pR++)->sup = (pA++)->sup - (pB++)->inf;
  _SetRoundToNearest();
}

VOID BiasMulRVR (const PBIASINTERVAL pR_start, const PREAL pa,
		 const PREAL pb_start, const INT dim)
  /**********************************************************************
   *  vR = a * vb
   */
{
  INT i;
  REAL a = *pa;
  PREAL pb;
  PBIASINTERVAL pR;

  _BiasRoundDown ();
  pb = pb_start; pR = pR_start;
  for (i = 0; i < dim; i++) (pR++)->inf = a * *(pb++);
  _BiasRoundUp ();
  pb = pb_start; pR = pR_start;
  for (i = 0; i < dim; i++) (pR++)->sup = a * *(pb++);
  _SetRoundToNearest();
}

VOID BiasMulIVR (const PBIASINTERVAL pR_start, const PBIASINTERVAL pA,
		 const PREAL pb_start, const INT dim)
  /**********************************************************************
   *  vR = A * vb
   */
{
  INT i;
  REAL painf = pA->inf;
  REAL pasup = pA->sup;
  PREAL pb;
  PBIASINTERVAL pR;

  _BiasRoundDown ();
  pb = pb_start; pR = pR_start;
  for (i = 0; i < dim; i++) {
    (pR++)->inf = *pb * ((Sign (*pb) == 0) ? painf : pasup);
    pb++;
  }
  _BiasRoundUp (); 
  pb = pb_start; pR = pR_start;
  for (i = 0; i < dim; i++) {
    (pR++)->sup = *pb * ((Sign (*pb) == 0) ? pasup : painf);
    pb++;
  }
  _SetRoundToNearest();
}

VOID BiasMulRVI (const PBIASINTERVAL pR_start, const PREAL pa,
		 const PBIASINTERVAL pB_start, const INT dim)
  /**********************************************************************
   *  vR = a * vB
   *  Assertion: vR != vB
   */
{
  INT i;
  REAL a = *pa;
  PBIASINTERVAL pB, pR;

  _BiasRoundDown ();
  pB = pB_start; pR = pR_start;
  if (Sign (*pa) == 0) {                               /* a >= 0 */
    for (i = 0; i < dim; i++) (pR++)->inf = a * (pB++)->inf;
    _BiasRoundUp ();
    pB = pB_start; pR = pR_start;
    for (i = 0; i < dim; i++) (pR++)->sup = a * (pB++)->sup;
  }
  else {                                               /* a <  0 */
    for (i = 0; i < dim; i++) (pR++)->inf = a * (pB++)->sup;
    _BiasRoundUp ();
    pB = pB_start; pR = pR_start;
    for (i = 0; i < dim; i++) (pR++)->sup = a * (pB++)->inf;
  }
  _SetRoundToNearest();
}

VOID BiasMulIVI (PBIASINTERVAL pR, const PBIASINTERVAL pA,
		 PBIASINTERVAL pB, const INT dim)
  /**********************************************************************
   *  vR = A * vB
   *  Assertion: vR != vB
   */
{
  INT i;

  if (Sign (pA->inf) == 0) {                            /* A >= 0 */
    for (i = 0; i < dim; i++) {
      _BiasRoundDown ();
      if (Sign (pB->inf) == 0) {                        /* B_i >= 0 */
	pR->inf = pA->inf * pB->inf;
	_BiasRoundUp ();
	(pR++)->sup = pA->sup * (pB++)->sup;
      }
      else if (Sign (pB->sup)) {                        /* B_i <= 0 */
	pR->inf = pA->sup * pB->inf;
	_BiasRoundUp ();
	(pR++)->sup = pA->inf * (pB++)->sup;
      }
      else {                                            /* 0 in B_i */
	pR->inf = pA->sup * pB->inf;
	_BiasRoundUp ();
	(pR++)->sup = pA->sup * (pB++)->sup;
      }
    }
  }
  else if (Sign (pA->sup)) {                            /* A <= 0 */
    for (i = 0; i < dim; i++) {
      _BiasRoundDown ();
      if (Sign (pB->inf) == 0) {                        /* B_i >= 0 */
	pR->inf = pA->inf * pB->sup;
	_BiasRoundUp ();
	(pR++)->sup = pA->sup * (pB++)->inf;
      }
      else if (Sign (pB->sup)) {                        /* B_i <= 0 */
	pR->inf = pA->sup * pB->sup;
	_BiasRoundUp ();
	(pR++)->sup = pA->inf * (pB++)->inf;
      }
      else {                                            /* 0 in B_i */
	pR->inf = pA->inf * pB->sup;
	_BiasRoundUp ();
	(pR++)->sup = pA->inf * (pB++)->inf;
      }
    }
  }
  else {                                                /* 0 in A */
    for (i = 0; i < dim; i++) {
      _BiasRoundDown ();
      if (Sign (pB->inf) == 0) {                        /* B_i >= 0 */
	pR->inf = pA->inf * pB->sup;
	_BiasRoundUp ();
	(pR++)->sup = pA->sup * (pB++)->sup;
      }
      else if (Sign (pB->sup)) {                        /* B_i <= 0 */
	pR->inf = pA->sup * pB->inf;
	_BiasRoundUp ();
	(pR++)->sup = pA->inf * (pB++)->inf;
      }
      else {                                            /* 0 in B_i */
	REAL r1 = pA->inf * pB->sup;
	REAL r2 = pA->sup * pB->inf;

	pR->inf = r1 < r2 ? r1 : r2;

	_BiasRoundUp ();

	r1 = pA->inf * pB->inf;
	r2 = pA->sup * pB->sup;

	(pR++)->sup = r1 > r2 ? r1 : r2;
	pB++;
      }
    }
  }
  _SetRoundToNearest();
}

VOID BiasMacRVR (const PBIASINTERVAL pR_start, const PREAL pa,
		 const PREAL pb_start, const INT dim)
  /**********************************************************************
   *  vR += a * vb
   */
{
  INT i;
  REAL a = *pa;
  PREAL pb;
  PBIASINTERVAL pR;

  _BiasRoundDown ();
  pb = pb_start; pR = pR_start;
  for (i = 0; i < dim; i++) (pR++)->inf += a * *(pb++);
  _BiasRoundUp ();
  pb = pb_start; pR = pR_start;
  for (i = 0; i < dim; i++) (pR++)->sup += a * *(pb++);
  _SetRoundToNearest();
}

VOID BiasMacIVR (const PBIASINTERVAL pR_start, const PBIASINTERVAL pA,
		 const PREAL pb_start, const INT dim)
  /**********************************************************************
   *  vR += A * vb
   */
{
  INT i;
  REAL painf = pA->inf;
  REAL pasup = pA->sup;
  PREAL pb;
  PBIASINTERVAL pR;

  _BiasRoundDown ();
  pb = pb_start; pR = pR_start;
  for (i = 0; i < dim; i++) {
    (pR++)->inf += *pb * ((Sign (*pb) == 0) ? painf : pasup);
    pb++;
  }
  _BiasRoundUp (); 
  pb = pb_start; pR = pR_start;
  for (i = 0; i < dim; i++) {
    (pR++)->sup += *pb * ((Sign (*pb) == 0) ? pasup : painf);
    pb++;
  }
  _SetRoundToNearest();
}

VOID BiasMacRVI (const PBIASINTERVAL pR_start, const PREAL pa,
		 const PBIASINTERVAL pB_start, const INT dim)
  /**********************************************************************
   *  vR += a * vB
   *  Assertion: vR != vB
   */
{
  INT i;
  REAL a = *pa;
  PBIASINTERVAL pB, pR;

  _BiasRoundDown ();
  pB = pB_start; pR = pR_start;
  if (Sign (*pa) == 0) {                               /* a >= 0 */
    for (i = 0; i < dim; i++) (pR++)->inf += a * (pB++)->inf;
    _BiasRoundUp ();
    pB = pB_start; pR = pR_start;
    for (i = 0; i < dim; i++) (pR++)->sup += a * (pB++)->sup;
  }
  else {                                               /* a <  0 */
    for (i = 0; i < dim; i++) (pR++)->inf += a * (pB++)->sup;
    _BiasRoundUp ();
    pB = pB_start; pR = pR_start;
    for (i = 0; i < dim; i++) (pR++)->sup += a * (pB++)->inf;
  }
  _SetRoundToNearest();
}

VOID BiasMacIVI (PBIASINTERVAL pR, const PBIASINTERVAL pA,
		 PBIASINTERVAL pB, const INT dim)
  /**********************************************************************
   *  vR += A * vB
   *  Assertion: vR != vB
   */
{
  INT i;

  if (Sign (pA->inf) == 0) {                            /* A >= 0 */
    for (i = 0; i < dim; i++) {
      _BiasRoundDown ();
      if (Sign (pB->inf) == 0) {                        /* B_i >= 0 */
	pR->inf += pA->inf * pB->inf;
	_BiasRoundUp ();
	(pR++)->sup += pA->sup * (pB++)->sup;
      }
      else if (Sign (pB->sup)) {                        /* B_i <= 0 */
	pR->inf += pA->sup * pB->inf;
	_BiasRoundUp ();
	(pR++)->sup += pA->inf * (pB++)->sup;
      }
      else {                                            /* 0 in B_i */
	pR->inf += pA->sup * pB->inf;
	_BiasRoundUp ();
	(pR++)->sup += pA->sup * (pB++)->sup;
      }
    }
  }
  else if (Sign (pA->sup)) {                            /* A <= 0 */
    for (i = 0; i < dim; i++) {
      _BiasRoundDown ();
      if (Sign (pB->inf) == 0) {                        /* B_i >= 0 */
	pR->inf += pA->inf * pB->sup;
	_BiasRoundUp ();
	(pR++)->sup += pA->sup * (pB++)->inf;
      }
      else if (Sign (pB->sup)) {                        /* B_i <= 0 */
	pR->inf += pA->sup * pB->sup;
	_BiasRoundUp ();
	(pR++)->sup += pA->inf * (pB++)->inf;
      }
      else {                                            /* 0 in B_i */
	pR->inf += pA->inf * pB->sup;
	_BiasRoundUp ();
	(pR++)->sup += pA->inf * (pB++)->inf;
      }
    }
  }
  else {                                                /* 0 in A */
    for (i = 0; i < dim; i++) {
      _BiasRoundDown ();
      if (Sign (pB->inf) == 0) {                        /* B_i >= 0 */
	pR->inf += pA->inf * pB->sup;
	_BiasRoundUp ();
	(pR++)->sup += pA->sup * (pB++)->sup;
      }
      else if (Sign (pB->sup)) {                        /* B_i <= 0 */
	pR->inf += pA->sup * pB->inf;
	_BiasRoundUp ();
	(pR++)->sup += pA->inf * (pB++)->inf;
      }
      else {                                            /* 0 in B_i */
	REAL r1 = pA->inf * pB->sup;
	REAL r2 = pA->sup * pB->inf;

	pR->inf += r1 < r2 ? r1 : r2;

	_BiasRoundUp ();

	r1 = pA->inf * pB->inf;
	r2 = pA->sup * pB->sup;

	(pR++)->sup += r1 > r2 ? r1 : r2;
	pB++;
      }
    }
  }
  _SetRoundToNearest();
}

VOID BiasMacRVIs (const PBIASINTERVAL pR_start, const PREAL pa,
		  const PBIASINTERVAL pB_start, const INT dim,
		  const INT Bstep)
  /**********************************************************************
   *  vR += a * vB, Stepwidth in B = Bstep
   *  Assertion: vR != vB
   */
{
  INT i;
  REAL a = *pa;
  PBIASINTERVAL pB, pR;

  _BiasRoundDown ();
  pB = pB_start; pR = pR_start;
  if (Sign (*pa) == 0) {                               /* a >= 0 */
    for (i = 0; i < dim; i++, pB += Bstep)
      (pR++)->inf += a * pB->inf;
    _BiasRoundUp ();
    pB = pB_start; pR = pR_start;
    for (i = 0; i < dim; i++, pB += Bstep)
      (pR++)->sup += a * pB->sup;
  }
  else {                                               /* a <  0 */
    for (i = 0; i < dim; i++, pB += Bstep)
      (pR++)->inf += a * pB->sup;
    _BiasRoundUp ();
    pB = pB_start; pR = pR_start;
    for (i = 0; i < dim; i++, pB += Bstep)
      (pR++)->sup += a * pB->inf;
  }
  _SetRoundToNearest();
}

VOID BiasMacsRVIs (const PBIASINTERVAL pR_start, const PREAL pa,
		   const PBIASINTERVAL pB_start, const INT dim,
		   const INT Rstep, const INT Bstep)
  /**********************************************************************
   *  vR += a * vB, Stepwidth in B = Bstep, Stepwidth in R = Rstep
   *  Assertion: vR != vB
   */
{
  INT i;
  REAL a = *pa;
  PBIASINTERVAL pB, pR;

  _BiasRoundDown ();
  pB = pB_start; pR = pR_start;
  if (Sign (*pa) == 0) {                               /* a >= 0 */
    for (i = 0; i < dim; i++, pB += Bstep, pR += Rstep)
      pR->inf += a * pB->inf;
    _BiasRoundUp ();
    pB = pB_start; pR = pR_start;
    for (i = 0; i < dim; i++, pB += Bstep, pR += Rstep)
      pR->sup += a * pB->sup;
  }
  else {                                               /* a <  0 */
    for (i = 0; i < dim; i++, pB += Bstep, pR += Rstep)
      pR->inf += a * pB->sup;
    _BiasRoundUp ();
    pB = pB_start; pR = pR_start;
    for (i = 0; i < dim; i++, pB += Bstep, pR += Rstep)
      pR->sup += a * pB->inf;
  }
  _SetRoundToNearest();
}

VOID BiasDivVRR (const PBIASINTERVAL pR_start, const PREAL pa_start,
		 const PREAL pb, const INT dim)
  /**********************************************************************
   *  vR = va / b
   */
{
  INT i;
  REAL b = *pb;
  PREAL pa;
  PBIASINTERVAL pR;

#if defined (__BIASRAISEDIVIDEBYZERO__)
  if (Zero (*pb)) _BiasError (ErrorVectorDivideByZero);
#endif
  _BiasRoundDown ();
  pa = pa_start; pR = pR_start;
  for (i = 0; i < dim; i++) (pR++)->inf = *(pa++) / b;
  _BiasRoundUp ();
  pa = pa_start; pR = pR_start;
  for (i = 0; i < dim; i++) (pR++)->sup = *(pa++) / b;
  _SetRoundToNearest();
}

VOID BiasDivVIR (const PBIASINTERVAL pR_start, const PBIASINTERVAL pA_start,
		 const PREAL pb, const INT dim)
  /**********************************************************************
   *  vR = vA / b
   *  Assertion: vR != vA
   */
{
  INT i;
  REAL b = *pb;
  PBIASINTERVAL pA, pR;

#if defined (__BIASRAISEDIVIDEBYZERO__)
  if (Zero (*pb)) _BiasError (ErrorVectorDivideByZero);
#endif
  _BiasRoundDown ();
  pA = pA_start; pR = pR_start;
  if (Sign (*pb) == 0) {                               /* b >= 0 */
    for (i = 0; i < dim; i++) (pR++)->inf = (pA++)->inf / b;
    _BiasRoundUp ();
    pA = pA_start; pR = pR_start;
    for (i = 0; i < dim; i++) (pR++)->sup = (pA++)->sup / b;
  }
  else {                                               /* b <  0 */
    for (i = 0; i < dim; i++) (pR++)->inf = (pA++)->sup / b;
    _BiasRoundUp ();
    pA = pA_start; pR = pR_start;
    for (i = 0; i < dim; i++) (pR++)->sup = (pA++)->inf / b;
  }
  _SetRoundToNearest();
}

VOID BiasDivVRI (const PBIASINTERVAL pR_start, const PREAL pa_start,
		 const PBIASINTERVAL pB, const INT dim)
  /**********************************************************************
   *  vR = va / B
   *  Assertion: vR != B
   */
{
  INT i;
  REAL pbinf = pB->inf;
  REAL pbsup = pB->sup;
  PREAL pa;
  PBIASINTERVAL pR;

  pa = pa_start; pR = pR_start;
  if ((Sign(pB->sup) == 0) && (Sign(pB->inf) || Zero(pB->inf)))
    {
#if defined (__BIASRAISEDIVIDEBYZERO__)
      _BiasError (ErrorVectorDivideByZero);
#else
      for (i = 0; i < dim; i++, pa++, pR++)
	if (Zero (*pa)) pR->sup = pR->inf = BiasNaN;
	else { pR->inf = BiasNegInf; pR->sup = BiasPosInf; }
#endif
      return;
    }
  for (i = 0; i < dim; i++) {
    (pR++)->inf = *pa / ((Sign (*pa) == 0) ? pbsup : pbinf);
    pa++;
  }
  _BiasRoundUp (); 
  pa = pa_start; pR = pR_start;
  for (i = 0; i < dim; i++) {
    (pR++)->sup = *pa / ((Sign (*pa) == 0) ? pbinf : pbsup);
    pa++;
  }
  _SetRoundToNearest();
}

VOID BiasDivVII (PBIASINTERVAL pR, PBIASINTERVAL pA,
		 const PBIASINTERVAL pB, const INT dim)
  /**********************************************************************
   *  vR = vA / B
   *  Assertion: vR != vA and vR != B
   */
{
  INT i;

  for (i = 0; i < dim; i++) BiasDivII(pR++, pA++, pB);
}

VOID BiasMacVRVR(const PBIASINTERVAL pR, const PREAL pa_start,
		 const PREAL pb_start, const INT dim)
  /**********************************************************************
   *  R = va * vb
   */
{
  INT i;
  PREAL pa, pb;
  REAL sum;

  _BiasRoundDown ();
  pa = pa_start; pb = pb_start; sum = 0.0;
  for (i = 0; i < dim; i++) sum += *(pa++) * *(pb++);
  pR->inf = sum;
  _BiasRoundUp ();
  pa = pa_start; pb = pb_start; sum = 0.0;
  for (i = 0; i < dim; i++) sum += *(pa++) * *(pb++);
  pR->sup = sum;
  _SetRoundToNearest();
}

VOID BiasMacVRVI(const PBIASINTERVAL pR, const PREAL pa_start,
		 const PBIASINTERVAL pB_start, const INT dim)
  /**********************************************************************
   *  R = va * vB
   */
{
  INT i;
  PREAL pa;
  REAL sum;
  PBIASINTERVAL pB;

  _BiasRoundDown ();
  pa = pa_start; pB = pB_start; sum = 0.0;
  for (i = 0; i < dim; i++) {
    sum += *pa * ((Sign (*pa) == 0) ? pB->inf : pB->sup);
    pa++; pB++;
  }
  pR->inf = sum;
  _BiasRoundUp ();
  pa = pa_start; pB = pB_start; sum = 0.0;
  for (i = 0; i < dim; i++) {
    sum += *pa * ((Sign (*pa) == 0) ? pB->sup : pB->inf);
    pa++; pB++;
  }
  pR->sup = sum;
  _SetRoundToNearest();
}

VOID BiasMacVIVI(const PBIASINTERVAL pR, PBIASINTERVAL pA,
		 PBIASINTERVAL pB, const INT dim)
  /**********************************************************************
   *  R = vA * vB
   */
{
  INT i;

  pR->sup = pR->inf = 0.0;
  for (i = 0; i < dim; i++) BiasMacII(pR, pA++, pB++);
}

VOID BiasInfV (PREAL pr, PBIASINTERVAL pA, const INT dim)
  /**********************************************************************
  *  vr = Inf (vA)
  */
{
  INT i;

  for (i = 0; i < dim; i++) *(pr++) = (pA++)->inf;
}

VOID BiasSupV (PREAL pr, PBIASINTERVAL pA, const INT dim)
  /**********************************************************************
  *  vr = Sup (vA)
  */
{
  INT i;

  for (i = 0; i < dim; i++) *(pr++) = (pA++)->sup;
}

VOID BiasNegV (PBIASINTERVAL pR, PBIASINTERVAL pA, const INT dim)
  /**********************************************************************
  *  vR = - vA
  */
{
  INT i;

  for (i = 0; i < dim; i++, pR++, pA++) {
    pR->inf = -(pA->sup);
    pR->sup = -(pA->inf);
  }
}

VOID BiasMidV (PREAL pr, PBIASINTERVAL pA, const INT dim)
  /**********************************************************************
  *  vr = Midpoint (vA)
  */
{
  INT i;

  _BiasRoundUp ();
  for (i = 0; i < dim; i++, pA++)
    *(pr++) = pA->inf + (pA->sup - pA->inf) / 2.0;
  _SetRoundToNearest();
}

VOID BiasMidRadV (PREAL pm, PREAL pr, PBIASINTERVAL pA, const INT dim)
  /**********************************************************************
  *  vm = Midpoint (vA) and vr = Radius (vA)
  */
{
  INT i;
  REAL r;

  _BiasRoundUp ();
  for (i = 0; i < dim; i++, pA++) {
    r = (pA->sup - pA->inf) / 2.0;
    *(pm++) = pA->inf + r;
    *(pr++) = r;
  }
  _SetRoundToNearest();
}

VOID BiasDiamV (PREAL pr, PBIASINTERVAL pA, const INT dim)
  /**********************************************************************
  *  vr = Diameter (vA)
  */
{
  INT i;

  _BiasRoundUp();
  for (i = 0; i < dim; i++, pA++) *(pr++) = pA->sup - pA->inf;
  _SetRoundToNearest();
}

VOID BiasAbsV (PREAL pr, PBIASINTERVAL pA, const INT dim)
  /**********************************************************************
  *  vr = Abs (vA)
  */
{
  INT i;

  for (i = 0; i < dim; i++) *(pr++) = BiasAbs (pA++);
}

INT BiasIntersectionV (PBIASINTERVAL pR, PBIASINTERVAL pA,
		       PBIASINTERVAL pB, const INT dim)
  /**********************************************************************
  *  vR = Intersection (vA, vB). vR is undefined,
  *  if vA and vB do not intersect
  *  Result: 1 if vA and vB intersect, 0 otherwise
  */
{
  INT i;

  for (i = 0; i < dim; i++)
    if (!BiasIntersection (pR++, pA++, pB++)) return 0;
  return 1;
}

VOID BiasHullVR (PBIASINTERVAL pR, PREAL pa, const INT dim)
  /**********************************************************************
  *  vR = Hull (va)
  */
{
  INT i;

  for (i = 0; i < dim; i++, pR++, pa++)
    pR->sup = pR->inf = *pa;
}

VOID BiasHullVRVR (PBIASINTERVAL pR, PREAL pa, PREAL pb, const INT dim)
  /**********************************************************************
  *  vR = Hull (va, vb)
  */
{
  INT i;

  for (i = 0; i < dim; i++) BiasHullRR (pR++, pa++, pb++);
}

VOID BiasHullVRVI (PBIASINTERVAL pR, PREAL pa,
		   PBIASINTERVAL pB, const INT dim)
  /**********************************************************************
  *  vR = Hull (va, vB)
  */
{
  INT i;

  for (i = 0; i < dim; i++) BiasHullRI (pR++, pa++, pB++);
}

VOID BiasHullVIVI (PBIASINTERVAL pR, PBIASINTERVAL pA,
		   PBIASINTERVAL pB, const INT dim)
  /**********************************************************************
  *  vR = Hull (vA, vB)
  */
{
  INT i;

  for (i = 0; i < dim; i++) BiasHullII (pR++, pA++, pB++);
}

INT BiasInVR (PREAL pa, PBIASINTERVAL pB, const INT dim)
  /**********************************************************************
  *  Result: 1 if va is contained in vB, 0 otherwise
  */
{
  INT i;

  for (i = 0; i < dim; i++)
    if (!BiasInR (pa++, pB++)) return 0;
  return 1;
}

INT BiasInVI (PBIASINTERVAL pA, PBIASINTERVAL pB, const INT dim)
  /**********************************************************************
  *  Result: 1 if vA is contained in vB, 0 otherwise
  */
{
  INT i;

  for (i = 0; i < dim; i++)
    if (!BiasInI (pA++, pB++)) return 0;
  return 1;
}

INT BiasInInteriorVR (PREAL pa, PBIASINTERVAL pB, const INT dim)
  /**********************************************************************
  *  Result: 1 if va is contained in the interior of vB, 0 otherwise
  */
{
  INT i;

  for (i = 0; i < dim; i++)
    if (!BiasInInteriorR (pa++, pB++)) return 0;
  return 1;
}

INT BiasInInteriorVI (PBIASINTERVAL pA, PBIASINTERVAL pB, const INT dim)
  /**********************************************************************
  *  Result: 1 if vA is contained in the interior of vB, 0 otherwise
  */
{
  INT i;

  for (i = 0; i < dim; i++)
    if (!BiasInInteriorI (pA++, pB++)) return 0;
  return 1;
}

INT BiasIsEqualV (PBIASINTERVAL pA, PBIASINTERVAL pB, const INT dim)
  /**********************************************************************
  *  Result: 1, if vA == vB, 0 otherwise
  */
{
  INT i;

  for (i = 0; i < dim; i++)
    if (!BiasIsEqual (pA++, pB++)) return 0;
  return 1;
}

VOID BiasSetToZeroV (const PBIASINTERVAL pR, const INT dim)
  /**********************************************************************
  *  vR = 0
  */
{
  memset (pR, 0, dim * sizeof (BIASINTERVAL));
}

VOID BiasSetToZeroVs (PBIASINTERVAL pR, const INT dim,
		      const INT step)
  /**********************************************************************
  *  vR = 0, Stepwidth of R = step
  */
{
  INT j;

    for (j = 0; j < dim; j++, pR += step) pR->sup = pR->inf = 0.0;
}
