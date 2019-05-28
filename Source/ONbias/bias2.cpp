/************************************************************************
*  Bias2IEEE.c (Basic Interval Arithmetic Subroutines Level 2)
*
*  Version:                     1.5
*  Date:                        3/13/96
*  Author:                      O. Knueppel
*  Interval Representation:     INFSUP
*  Interval Implementation:     IEEE
*************************************************************************/

static char sccs_id[] = "@(#)Bias2IEEE.c 1.5 96/03/13 OK";

#include "Bias2.h"
#include "BiasInt.h"

#if !defined (__BIASINFSUP__) || !defined (__BIASIEEE__)
#error __BIASINFSUP__ and __BIASIEEE__ not set
#endif

/************************************************************************
*  Implementation of global functions
*************************************************************************/

VOID BiasMulRMR (PBIASINTERVAL pR, PREAL pa, PREAL pb,
		 const INT rows, const INT cols)
  /**********************************************************************
   *  mR = a * mb
   */
{
  INT i;

  for (i = 0; i < rows; i++, pb += cols, pR += cols)
    BiasMulRVR (pR, pa, pb, cols);
}

VOID BiasMulRMI (PBIASINTERVAL pR, PREAL pa, PBIASINTERVAL pB,
		 const INT rows, const INT cols)
  /**********************************************************************
   *  mR = a * mB
   *  Assertion: mR != mB
   */
{
  INT i;

  for (i = 0; i < rows; i++, pB += cols, pR += cols)
    BiasMulRVI (pR, pa, pB, cols);
}

VOID BiasMulIMR (PBIASINTERVAL pR, PBIASINTERVAL pA, PREAL pb,
		 const INT rows, const INT cols)
  /**********************************************************************
   *  mR = A * mb
   */
{
  INT i;

  for (i = 0; i < rows; i++, pb += cols, pR += cols)
    BiasMulIVR (pR, pA, pb, cols);
}

VOID BiasMulIMI (PBIASINTERVAL pR, PBIASINTERVAL pA, PBIASINTERVAL pB,
		 const INT rows, const INT cols)
  /**********************************************************************
   *  mR = A * mB
   *  Assertion: mR != mB
   */
{
  INT i;

  for (i = 0; i < rows; i++, pB += cols, pR += cols)
    BiasMulIVI (pR, pA, pB, cols);
}

VOID BiasDivMRR (PBIASINTERVAL pR, PREAL pa, PREAL pb,
		 const INT rows, const INT cols)
  /**********************************************************************
   *  mR = ma / b
   */
{
  INT i;

  for (i = 0; i < rows; i++, pa += cols, pR += cols)
    BiasDivVRR (pR, pa, pb, cols);
}

VOID BiasDivMRI (PBIASINTERVAL pR, PREAL pa, PBIASINTERVAL pB,
		 const INT rows, const INT cols)
  /**********************************************************************
   *  mR = ma / B
   *  Assertion: mR != B
   */
{
  INT i;

  for (i = 0; i < rows; i++, pa += cols, pR += cols)
    BiasDivVRI (pR, pa, pB, cols);
}

VOID BiasDivMIR (PBIASINTERVAL pR, PBIASINTERVAL pA, PREAL pb,
		 const INT rows, const INT cols)
  /**********************************************************************
   *  mR = mA / b
   *  Assertion: mR != mA
   */
{
  INT i;

  for (i = 0; i < rows; i++, pA += cols, pR += cols)
    BiasDivVIR (pR, pA, pb, cols);
}

VOID BiasDivMII (PBIASINTERVAL pR, PBIASINTERVAL pA, PBIASINTERVAL pB,
		 const INT rows, const INT cols)
  /**********************************************************************
   *  mR = MA / B
   *  Assertion: mR != mA and mR != B
   */
{
  INT i;

  for (i = 0; i < rows; i++, pA += cols, pR += cols)
    BiasDivVII (pR, pA, pB, cols);
}

VOID BiasMulMRVR (PBIASINTERVAL pR, PREAL pa, PREAL pb,
		  const INT rows, const INT cols)
  /**********************************************************************
   *  vR = ma * vb
   */
{
  INT i;

  for (i = 0; i < rows; i++, pa += cols)
    BiasMacVRVR (pR++, pa, pb, cols);
}

VOID BiasMulMRVI (PBIASINTERVAL pR, PREAL pa, PBIASINTERVAL pB,
		  const INT rows, const INT cols)
  /**********************************************************************
   *  vR = ma * vB
   */
{
  INT i;

  for (i = 0; i < rows; i++, pa += cols)
    BiasMacVRVI (pR++, pa, pB, cols);
}

VOID BiasMulMIVR (PBIASINTERVAL pR, PBIASINTERVAL pA, PREAL pb,
		  const INT rows, const INT cols)
  /**********************************************************************
   *  vR = mA * vb
   */
{
  INT i;

  BiasSetToZeroV (pR, rows);
  for (i = 0; i < cols; i++, pb++)
    BiasMacRVIs (pR, pb, pA++, rows, cols);
}

VOID BiasMulMIVI (PBIASINTERVAL pR, PBIASINTERVAL pA, PBIASINTERVAL pB,
		  const INT rows, const INT cols)
  /**********************************************************************
   *  vR = mA * vB
   */
{
  INT i;

  for (i = 0; i < rows; i++, pA += cols)
    BiasMacVIVI (pR++, pA, pB, cols);
}

#if !defined (__BIAS2USEVECTOROPERATIONS__)

VOID BiasAddMRMR (PBIASINTERVAL pR, PREAL pa, PREAL pb,
		  const INT rows, const INT cols)
  /**********************************************************************
   *  mR = ma + mb
   */
{
  INT i;

  for (i = 0; i < rows; i++) {
    BiasAddVRVR (pR, pa, pb, cols);
    pR += cols; pa += cols; pb += cols;
  }
}

VOID BiasAddMRMI (PBIASINTERVAL pR, PREAL pa, PBIASINTERVAL pB,
		  const INT rows, const INT cols)
  /**********************************************************************
   *  mR = ma + mB
   */
{
  INT i;

  for (i = 0; i < rows; i++) {
    BiasAddVRVI (pR, pa, pB, cols);
    pR += cols; pa += cols; pB += cols;
  }
}

VOID BiasAddMIMI (PBIASINTERVAL pR, PBIASINTERVAL pA, PBIASINTERVAL pB,
		  const INT rows, const INT cols)
  /**********************************************************************
   *  mR = mA + mB
   */
{
  INT i;

  for (i = 0; i < rows; i++) {
    BiasAddVIVI (pR, pA, pB, cols);
    pR += cols; pA += cols; pB += cols;
  }
}

VOID BiasSubMRMR (PBIASINTERVAL pR, PREAL pa, PREAL pb,
		  const INT rows, const INT cols)
  /**********************************************************************
   *  mR = ma - ma
   */
{
  INT i;

  for (i = 0; i < rows; i++) {
    BiasSubVRVR (pR, pa, pb, cols);
    pR += cols; pa += cols; pb += cols;
  }
}

VOID BiasSubMRMI (PBIASINTERVAL pR, PREAL pa, PBIASINTERVAL pB,
		  const INT rows, const INT cols)
  /**********************************************************************
   *  mR = ma - mB
   *  Assertion: mR != mB
   */
{
  INT i;

  for (i = 0; i < rows; i++) {
    BiasSubVRVI (pR, pa, pB, cols);
    pR += cols; pa += cols; pB += cols;
  }
}

VOID BiasSubMIMR (PBIASINTERVAL pR, PBIASINTERVAL pA, PREAL pb,
		  const INT rows, const INT cols)
  /**********************************************************************
   *  mR = mA - mb
   */
{
  INT i;

  for (i = 0; i < rows; i++) {
    BiasSubVIVR (pR, pA, pb, cols);
    pR += cols; pA += cols; pb += cols;
  }
}

VOID BiasSubMIMI (PBIASINTERVAL pR, PBIASINTERVAL pA, PBIASINTERVAL pB,
		  const INT rows, const INT cols)
  /**********************************************************************
   *  mR = mA - mB
   *  Assertion: mR != mB
   */
{
  INT i;

  for (i = 0; i < rows; i++) {
    BiasSubVIVI (pR, pA, pB, cols);
    pR += cols; pA += cols; pB += cols;
  }
}
#endif /* __BIAS2USEVECTOROPERATIONS__ */

#if !defined (_AIX)

VOID BiasMulMRMR (PBIASINTERVAL pR_start, PREAL pa, PREAL pb,
		  const INT arows, const INT acols, const INT bcols)
  /**********************************************************************
   *  mR = ma * mb
   */
{
  INT i, j, k;
  REAL s;
  PBIASINTERVAL pR;

  _BiasRoundDown ();
  pR = pR_start;
  for (i = 0; i < arows; i++)
    for (j = 0; j < bcols; j++) {
      s = 0.0;
      for (k = 0; k < acols; k++)
	s += pa[i * acols + k] * pb[k * bcols + j];
      (pR++)->inf = s;
    }

  _BiasRoundUp ();
  pR = pR_start;
  for (i = 0; i < arows; i++)
    for (j = 0; j < bcols; j++) {
      s = 0.0;
      for (k = 0; k < acols; k++)
	s += pa[i * acols + k] * pb[k * bcols + j];
      (pR++)->sup = s;
    }
}

#else

VOID BiasMulMRMR (PBIASINTERVAL pR, PREAL pa, PREAL pb_start,
		  const INT arows, const INT acols, const INT bcols)
  /**********************************************************************
   *  mR = ma * mb
   */
{
  INT i, j;
  PREAL pb;

  for (i = 0; i < arows; i++) {
    BiasSetToZeroV (pR, bcols);
    pb = pb_start;
    for (j = 0; j < acols; j++) {
      BiasMacRVR (pR, pa++, pb, bcols);
      pb += bcols;
    }
    pR += bcols;
  }
}

#endif /* !_AIX */

VOID BiasMulMRMI (PBIASINTERVAL pR, PREAL pa, PBIASINTERVAL pB_start,
		  const INT arows, const INT acols, const INT Bcols)
  /**********************************************************************
   *  mR = ma * mB
   */
{
  INT i, j;
  PBIASINTERVAL pB;

  for (i = 0; i < arows; i++) {
    BiasSetToZeroV (pR, Bcols);
    pB = pB_start;
    for (j = 0; j < acols; j++) {
      BiasMacRVI (pR, pa++, pB, Bcols);
      pB += Bcols;
    }
    pR += Bcols;
  }
}

VOID BiasMulMIMR (PBIASINTERVAL pR, PBIASINTERVAL pA_start, PREAL pb_start,
		  const INT Arows, const INT Acols, const INT bcols)
  /**********************************************************************
   *  mR = mA * mb
   */
{
  INT i, j;
  PREAL pb;
  PBIASINTERVAL pA;

  for (i = 0; i < bcols; i++) {
    BiasSetToZeroVs (pR, Arows, bcols);
    pb = pb_start;
    pA = pA_start;
    for (j = 0; j < Acols; j++) {
      BiasMacsRVIs (pR, pb, pA++, Arows, bcols, Acols);
      pb += bcols;
    }
    pR++; pb_start++;
  }
}

VOID BiasMulMIMI (PBIASINTERVAL pR, PBIASINTERVAL pA, PBIASINTERVAL pB_start,
		  const INT Arows, const INT Acols, const INT Bcols)
  /**********************************************************************
   *  mR = mA * mB
   */
{
  INT i, j;
  PBIASINTERVAL pB;

  for (i = 0; i < Arows; i++) {
    BiasSetToZeroV (pR, Bcols);
    pB = pB_start;
    for (j = 0; j < Acols; j++) {
      BiasMacIVI (pR, pA++, pB, Bcols);
      pB += Bcols;
    }
    pR += Bcols;
  }
}
