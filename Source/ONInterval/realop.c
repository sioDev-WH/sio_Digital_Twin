/************************************************************************
*  RealOp.c (Implementation of commonly used real operations)
*
*  Version:                     1.11
*  Date:                        3/13/96
*  Author:                      O. Knueppel
*************************************************************************/

static char sccs_id[] = "@(#)RealOp.c 1.11 96/03/13 OK";

//#include "stdafx.h"
#include "realop.h"
#include <memory.h>

VOID RealOpNeg (PREAL pr, PREAL pa, INT dim)
  /**********************************************************************
   *  r_i = -a_i
   */
{
  INT i;

  for (i = 0; i < dim; i++) *(pr++) = - *(pa++);
}

VOID RealOpAdd (PREAL pr, PREAL pa, PREAL pb, INT dim)
  /**********************************************************************
   *  r_i = a_i + b_i
   */
{
  INT i;

  for (i = 0; i < dim; i++) *(pr++) = *(pa++) + *(pb++);
}

VOID RealOpSub (PREAL pr, PREAL pa, PREAL pb, INT dim)
  /**********************************************************************
   *  r_i = a_i - b_i
   */
{
  INT i;

  for (i = 0; i < dim; i++) *(pr++) = *(pa++) - *(pb++);
}

VOID RealOpMul (PREAL pr, REAL  a,  PREAL pb, INT dim)
  /**********************************************************************
   *  r_i = a * b_i
   */
{
  INT i;

  for (i = 0; i < dim; i++) *(pr++) = a * *(pb++);
}

VOID RealOpDiv (PREAL pr, PREAL pa, REAL  b,  INT dim)
  /**********************************************************************
   *  r_i = a_i / b
   */
{
  INT i;

  for (i = 0; i < dim; i++) *(pr++) = *(pa++) / b;
}

VOID RealOpAddTo (PREAL pr, PREAL pa, INT dim)
  /**********************************************************************
   *  r_i += a_i
   */
{
  INT i;

  for (i = 0; i < dim; i++) *(pr++) += *(pa++);
}

VOID RealOpSubFrom (PREAL pr, PREAL pa, INT dim)
  /**********************************************************************
   *  r_i -= a_i
   */
{
  INT i;

  for (i = 0; i < dim; i++) *(pr++) -= *(pa++);
}

VOID RealOpMulWith (PREAL pr, REAL a, INT dim)
  /**********************************************************************
   *  r_i *= a
   */
{
  INT i;

  for (i = 0; i < dim; i++) *(pr++) *= a;
}

VOID RealOpDivBy (PREAL pr, REAL a, INT dim)
  /**********************************************************************
   *  r_i /= a
   */
{
  INT i;

  for (i = 0; i < dim; i++) *(pr++) /= a;
}

REAL RealOpScalp (PREAL pa, PREAL pb, INT dim)
  /**********************************************************************
   *  Result = sum (a_i * b_i)
   */
{
  INT i;
  REAL sum = 0.0;

  for (i = 0; i < dim; i++) sum += *(pa++) * *(pb++);
  return sum;
}

#if defined (_AIX) || defined (sparc) || defined (__I386__)

#define UNROLLDEPTH 4

VOID RealOpVecMul (PREAL pr, PREAL pa, PREAL pb_start, INT rows, INT cols)
  /**********************************************************************
   *  vr = ma * vb
   */
{
  INT i, j;
  REAL t1, t2, t3, t4;
  PREAL pb;

  for (i = 0; i < rows - (UNROLLDEPTH - 1); i+= UNROLLDEPTH) {
    t1 = 0.0; t2 = 0.0; t3 = 0.0; t4 = 0.0;
    pb = pb_start;
    for (j = 0; j < cols; j++, pa++, pb++) {
      t1 += pa[       0] * (*pb);
      t2 += pa[    cols] * (*pb);
      t3 += pa[2 * cols] * (*pb);
      t4 += pa[3 * cols] * (*pb);
    }
    pr[0] = t1;
    pr[1] = t2;
    pr[2] = t3;
    pr[3] = t4;
    pr += UNROLLDEPTH;
    pa += (UNROLLDEPTH - 1) * cols;
  }

  for (i = UNROLLDEPTH * (rows / UNROLLDEPTH); i < rows; i++) {
    t1 = 0.0; pb = pb_start;
    for (j = 0; j < cols; j++)
      t1 += *(pa++) * *(pb++);
    *(pr++) = t1;
    }
}

#undef UNROLLDEPTH

#else /* _AIX || sparc */

VOID RealOpVecMul (PREAL pr, PREAL pa, PREAL pb_start, INT rows, INT cols)
  /**********************************************************************
   *  vr = ma * vb
   */
{
  INT i, j;
  REAL s;
  PREAL pb;

  for (i = 0; i < rows; i++) {
    s = 0.0; pb = pb_start;
    for (j = 0; j < cols; j++)
      s += *(pa++) * *(pb++);
    *(pr++) = s;
    }
}

#endif

#if defined (_AIX) || defined (sparc) || defined (__I386__)

#define BLOCKSIZE_A_COLS 64
#define BLOCKSIZE_A_ROWS 64
#define BLOCKSIZE_B_COLS 64
#define I_DEPTH 2
#define J_DEPTH 2

VOID RealOpMatMul (PREAL pr, PREAL pa, PREAL pb,
		   INT arows, INT acols, INT bcols)
  /**********************************************************************
   *  mr = ma * mb
   */
{
  static REAL rh[BLOCKSIZE_A_COLS * BLOCKSIZE_B_COLS];
  REAL t11, t12, t21, t22;
  INT i, ii, ilen, ispan;
  INT j, jj, jlen, jspan;
  INT l, ll, lspan;

  memset (pr, 0, arows * bcols * sizeof (REAL));

  for (l = 0; l < acols; l += BLOCKSIZE_A_COLS) {
    lspan = min(BLOCKSIZE_A_COLS, acols - l);
    for (i = 0; i < bcols; i += BLOCKSIZE_B_COLS) {
      ispan = min(BLOCKSIZE_B_COLS, bcols - i);
      ilen = I_DEPTH * (ispan / I_DEPTH);
      for (ii = i; ii < i + ispan; ii++)
	for (ll = l; ll < l + lspan; ll++)
	  rh[(ii - i) * BLOCKSIZE_A_COLS + (ll - l)] = pb[ll * bcols + ii];
      for (j = 0; j < arows; j += BLOCKSIZE_A_ROWS) {
	jspan = min(BLOCKSIZE_A_ROWS, arows - j);
	jlen = J_DEPTH * (jspan / J_DEPTH);
	for (jj = j; jj < j + jlen; jj += J_DEPTH) {
	  for (ii = i; ii < i + ilen; ii += I_DEPTH) {
	    t11 = 0.0; t12 = 0.0; t21 = 0.0; t22 = 0.0;
	    for (ll = l; ll < l + lspan; ll++) {
	      t11 += rh[(ii - i)     * BLOCKSIZE_A_COLS + (ll - l)] * pa[jj * acols + ll];
	      t21 += rh[(ii - i + 1) * BLOCKSIZE_A_COLS + (ll - l)] * pa[jj * acols + ll];
	      t12 += rh[(ii - i)     * BLOCKSIZE_A_COLS + (ll - l)] * pa[(jj + 1) * acols + ll];
	      t22 += rh[(ii - i + 1) * BLOCKSIZE_A_COLS + (ll - l)] * pa[(jj + 1) * acols + ll];
	    }
	    pr[jj        * bcols + ii]     += t11;
	    pr[jj        * bcols + ii + 1] += t21;
	    pr[(jj  + 1) * bcols + ii]     += t12;
	    pr[(jj  + 1) * bcols + ii + 1] += t22;
	  }
	  if (ilen < ispan) {
	    for (ii = i + ilen; ii < i + ispan; ii++) {
	      t11 = 0.0; t12 = 0.0;
	      for (ll = l; ll < l + lspan; ll++) {
		t11 += rh[(ii - i) * BLOCKSIZE_A_COLS + (ll - l)] * pa[jj       * acols + ll];
		t12 += rh[(ii - i) * BLOCKSIZE_A_COLS + (ll - l)] * pa[(jj + 1) * acols + ll];
	      }
	      pr[jj       * bcols + ii] += t11;
	      pr[(jj + 1) * bcols + ii] += t12;
	    }
	  }
	}
	if (jlen < jspan) {
	  for (jj = j + jlen; jj < j + jspan; jj++) {
	    for (ii = i; ii < i + ilen; ii += I_DEPTH) {
	      t11 = 0.0; t21 = 0.0;
	      for (ll = l; ll < l + lspan; ll++) {
		t11 += rh[(ii - i)     * BLOCKSIZE_A_COLS + (ll - l)] * pa[jj * acols + ll];
		t21 += rh[(ii - i + 1) * BLOCKSIZE_A_COLS + (ll - l)] * pa[jj * acols + ll];
	      }
	      pr[jj * bcols + ii]     += t11;
	      pr[jj * bcols + ii + 1] += t21;
	    }
	    if (ilen < ispan) {
	      for (ii = i + ilen; ii < i + ispan; ii++) {
		t11 = 0.0;
		for (ll = l; ll < l + lspan; ll++)
		  t11 += rh[(ii - i) * BLOCKSIZE_A_COLS + (ll - l)] * pa[jj * acols + ll];
		pr[jj * bcols + ii] += t11;
	      }
	    }
	  }
	}
      }
    }
  }
}

#undef BLOCKSIZE_A_COLS
#undef BLOCKSIZE_A_ROWS
#undef BLOCKSIZE_B_COLS
#undef I_DEPTH
#undef J_DEPTH

#else /* _AIX || sparc || __I386__ */

VOID RealOpMatMul (PREAL pr, PREAL pa, PREAL pb,
		   INT arows, INT acols, INT bcols)
  /**********************************************************************
   *  mr = ma * mb
   */
{
  INT i, j, k;
  REAL s;

  for (i = 0; i < arows; i++)
    for (j = 0; j < bcols; j++) {
      s = 0.0;
      for (k = 0; k < acols; k++)
	s += pa[i * acols + k] * pb[k * bcols + j];
      *(pr++) = s;
    }
}

#endif /* _AIX || sparc || __I386__ */

INT RealOpLessThan (PREAL pa, PREAL pb, INT dim)
  /**********************************************************************
   *  Result: TRUE, if for all i: a_i < b_i
   */
{
  INT i;

  for (i = 0; i < dim; i++)
    if (*(pa++) >= *(pb++)) return FALSE;
  return TRUE;
}

INT RealOpLessEqual (PREAL pa, PREAL pb, INT dim)
  /**********************************************************************
   *  Result: TRUE, if for all i: a_i <= b_i
   */
{
  INT i;

  for (i = 0; i < dim; i++)
    if (*(pa++) > *(pb++)) return FALSE;
  return TRUE;
}

INT RealOpGreaterThan (PREAL pa, PREAL pb, INT dim)
  /**********************************************************************
   *  Result: TRUE, if for all i: a_i > b_i
   */
{
  INT i;

  for (i = 0; i < dim; i++)
    if (*(pa++) <= *(pb++)) return FALSE;
  return TRUE;
}

INT RealOpGreaterEqual (PREAL pa, PREAL pb, INT dim)
  /**********************************************************************
   *  Result: TRUE, if for all i: a_i >= b_i
   */
{
  INT i;

  for (i = 0; i < dim; i++)
    if (*(pa++) < *(pb++)) return FALSE;
  return TRUE;
}
