/*M*
//
//  INTEL CORPORATION PROPRIETARY INFORMATION
//  This software is supplied under the terms of a license agreement or
//  nondisclosure agreement with Intel Corporation and may not be copied
//  or disclosed except in accordance with the terms of that agreement.
//  Copyright (c) 1999 Intel Corporation. All Rights Reserved.
//
//      $Workfile$
//      $Revision$
//      $Modtime$
//
//  Contents:
//       C-style sample FFT for one-dimension TEST
//
//  Author  : Mustaeva N., Sivolgina O.
//
*M*/

#include <windows.h>
#include <math.h>
#include <errno.h>
#include <assert.h>
#include "fft_test.h"

#define  D_ELM_SIZE  8
#define  S_ELM_SIZE  4

static const int xCode = 0,
                 xLName = 9;
static const int * pxCode = &xCode;

void CFFT1DC_S(float*, float*, int, int, float*);
void ZFFT1DC_S(double*, double*, int, int, double*);

void COEF4R22_S(int, float*);
void COEF4R22_ZC_S(int, double*);

void SCOPY(int*, float*, int*, float*, int*);
void DCOPY(int*, double*, int*, double*, int*);

void cbitrevc_s(float*, float*, int, float*);
void zbitrevc_s(double*, double*, int, double*);
int  LOG2(int*);

void ZFFT2DC_S(double* ar, double* ai, int m, int n, int isign)
/*
// --- Version:
// ---         .06.97
// ---         RFNC (VNIIEF), Department 8, Gvozdev E.
// ---         for INTEL
// ---         .10.98
// ---         RFNC (VNIIEF), Sivolgina O.
// ---         for INTEL
// --- Function:
// ---          Sample forward/inverse 2-dimensional FFT of
// ---          a double presicion complex vector
// --- Implementation:
// ---        An in-place, split-radix, decimation-in-frequency,
// ---        complex FFT
// ---        (with table look-up)
// ---        On entry:
// ---           n - integer, transform length, must be power of 2,
// ---           ar - double, real part of complex input matrix, 
// ---                array of dimension at least (n)
// ---           ai - double, imagine part of complex input matrix, 
// ---                array of dimension at least (n)
// ---           isign - integer =  0  initialize the coefficents wsave
// ---                           = -1 perform forward fft
// ---                           =  1 perform inverse fft
// ---                           = -2 perform forward fft with out bitreverse
// ---                           =  2 perform inverse fft with out bitreverse
// ---        On return:
// ---           ar - real part of result of the transform (if isign = -1 or 1).
// ---                If isign=0, it is not changed.
// ---           ai - imagine part of result of the transform (if isign = -1 or 1).
// ---                If isign=0, it is not changed.
*/
{
    double*  twiddle;
    double*  t01;
    double*  t02;

	int      pwrn;
	int      pwrm;
    int      i,j;
    int      twsize;
    int      ldr;

    int      err;
    int      one = 1;
    int      *pone = &one;
    const char xName[] = "ZFFT2DC_S";

    assert(ar != NULL);
    assert(ai != NULL);
    assert(abs(isign) == 1 || abs(isign) == 2);
  
    twsize = (n < m) ? m : n;
    twiddle = (double *)LocalAlloc(LMEM_FIXED, 3*twsize*D_ELM_SIZE);
  
    if (twiddle == NULL) {
        XERBLA(xName, pxCode, xLName);
        return;
    }/* if */
  
    t01 = (double *)LocalAlloc(LMEM_FIXED, m*D_ELM_SIZE);
  
    if (t01 == NULL) {
        LocalFree(twiddle);
        XERBLA(xName, pxCode, xLName);
        return;
    }/* if */
  
    t02 = (double *)LocalAlloc(LMEM_FIXED, m*D_ELM_SIZE);
  
    if (t02 == NULL) {
        XERBLA(xName, pxCode, xLName);
        LocalFree(twiddle);
        LocalFree(t01);
        t01 = NULL;
        return;
    }/* if */

    ldr = n;
    pwrn = LOG2(&n);
    COEF4R22_ZC_S(pwrn, twiddle);

    for (i = 0; i < m; i++) {
        ZFFT1DC_S(&(ar[ldr*i]), &(ai[ldr*i]), n, isign, twiddle);
    }/* for */

    pwrm = LOG2(&m);
    COEF4R22_ZC_S(pwrm, twiddle);

    for (j = 0; j < n; j++) {
        DCOPY(&m, &(ar[j]), &ldr, t01, pone);
        DCOPY(&m, &(ai[j]), &ldr, t02, pone);
        ZFFT1DC_S(t01, t02, m, isign, twiddle);
        DCOPY(&m, t01, pone, &(ar[j]), &ldr);
        DCOPY(&m, t02, pone, &(ai[j]), &ldr);
    }/* for */
  
    LocalFree(t02);
    LocalFree(t01);
    LocalFree(twiddle);
    twiddle = NULL;
    t01 = NULL;
    t02 = NULL;
    return;

} /* ZFFT2DC_S */


void CFFT2DC_S(float* ar, float* ai, int m, int n, int isign)
/*
// --- Version:
// ---         .06.97
// ---         RFNC (VNIIEF), Department 8, Gvozdev E.
// ---         for INTEL
// ---         .10.98
// ---         RFNC (VNIIEF), Department 8, Sivolgina O.
// ---         for INTEL
// --- Function:
// ---          Simple forward/inverse 2-dimensional FFT of
// ---             a single presicion complex vector
// --- Implementation:
// ---        An in-place, split-radix, decimation-in-frequency,
// ---        complex FFT
// ---        (with table look-up)
// ---        On entry:
// ---           n - integer, transform length, must be power of 2,
// ---           ar - real, real part of complex input matrix, 
// ---                array of dimension at least (n)
// ---           ai - real, imagine part of complex input matrix, 
// ---                array of dimension at least (n)
// ---           isign - integer =  0  initialize the coefficents wsave
// ---                           = -1 perform forward fft
// ---                           =  1 perform inverse fft
// ---                           = -2 perform forward fft with out bitreverse
// ---                           =  2 perform inverse fft with out bitreverse
// ---        On return:
// ---           ar - real part of result of the transform (if isign = -1 or 1).
// ---                If isign=0, it is not changed.
// ---           ai - imagine part of result of the transform (if isign = -1 or 1).
// ---                If isign=0, it is not changed.
*/
{
    float*   twiddle;
    float*   t01;
    float*   t02;
    
	int      pwrn;
	int      pwrm;
    int      i,j;
    int      twsize;
    int      ldr;
    int      err;
    int      one = 1;
    int      *pone = &one;
    const char xName[] = "CFFT2DC_S";
  
    assert(ar != NULL);
    assert(ai != NULL);
    assert(abs(isign) == 1 || abs(isign) == 2);

    twsize = (n < m) ? m : n;
    twiddle = (float *)LocalAlloc(LMEM_FIXED, (3*twsize)*S_ELM_SIZE);
    if (twiddle == NULL) {
        XERBLA(xName, pxCode, xLName);
        return;
    }/* if */
  
    t01 = (float *)LocalAlloc(LMEM_FIXED, m*S_ELM_SIZE);
    if (t01 == NULL) {
        XERBLA(xName, pxCode, xLName);
        LocalFree(twiddle);
        twiddle = NULL;
        return;
    }/* if */
  
    t02 = (float *)LocalAlloc(LMEM_FIXED, m*S_ELM_SIZE);
    if (t02 == NULL) {
        XERBLA(xName, pxCode, xLName);
        LocalFree(t01);
        LocalFree(twiddle);
        twiddle = NULL;
        t01 = NULL;
        return;
    }/* if */

    ldr = n;
    pwrn = LOG2(&n);
    COEF4R22_S(pwrn, twiddle);
 
    for (i = 0; i < m; i++) 
        CFFT1DC_S(&(ar[ldr*i]), &(ai[ldr*i]), n, isign, twiddle);
  
    pwrm = LOG2(&m);
    COEF4R22_S(pwrm, twiddle);

    for (j = 0; j < n; j++) {
        SCOPY(&m, &(ar[j]), &ldr, t01, pone);
        SCOPY(&m, &(ai[j]), &ldr, t02, pone);
        CFFT1DC_S(t01, t02, m, isign, twiddle);
        SCOPY(&m, t01, pone, &(ar[j]), &ldr);
        SCOPY(&m, t02, pone, &(ai[j]), &ldr);
    }/* for */

    LocalFree(t02);
    LocalFree(t01);
    LocalFree(twiddle);
    twiddle = NULL;
    t01 = NULL;
    t02 = NULL;
    return;

}/* CFFT2DC_S */


void  CFFT1DC_S(float* rr, float* ri, int n, int isign, float* wsave) {
/*
* --- Version:
* ---         .03.98
* ---         RFNC (VNIIEF), Department 8, Mustaeva N.
* ---         for INTEL

* --- Function:
* ---          Computes forward/inverse 1-dimensional FFT of
* ---             a float presicion complex vector

* --- Implementation:
* ---        An in-place, split-radix, decimation-in-frequency,
* ---        complex FFT
* ---        (with table look-up)
* ---        On entry:
* ---           n - integer, transform length, must be power of 2,
* ---           rr - float, real part of complex input vector,
* ---                array of dimension at least (n)
* ---           rr - float, imagine part of complex input vector,
* ---                array of dimension at least (n)
* ---           isign - integer =  0  initialize the coefficents wsave
* ---                           = -1 perform forward fft
* ---                           =  1 perform inverse fft
* ---           wsave - float,
* ---                   array of dimension at least ((n*2)/4-2)
* ---        On return:
* ---           r - result of the transform (if isign = -1 or 1).
* ---               If isign=0, it is not changed.
* ---           wsave - if isign=0, it contains the initialized fft
* ---               coefficients. It is unaltered otherwise.

* --- Notice:
* ---        A call to zfft1dc with isign=0 must be prior to using the
* ---        function to compute the forward/inverse fft for a given length
* ---        in order to inicialize coeeficients. Thereafter, any number
* ---        transforms of the same length can be computed using
* ---        these coefficients.
*/

static const char xName[] = "CFFT1DC_S";
float* r;
float* prr;
float* pri;
int    ldrr, ldrc, k, j, nstep, lstep, stepi, nblk;
int    p0 = 0;
int    p1 = 1;
float  Scale, t, t1, E1 = 1.0;
static int last_tw = 0;
int    pwr = 0;
int    err;
int    l, i, i0, iw, nn;


  if (wsave == NULL) {
    err = 5;
    XERBLA(xName, &err, xLName);
    return;
  }
  k = LOG2(&n);

  if (isign == 0) {
    last_tw = n;
    COEF4R22_S(k, wsave);
    return;
  }

//  if (isign != 0 && wsave[1] != n) {
//    err = 5;
//    XERBLA(xName, &err, xLName);
//    return;
//  }

  if (n >= 0) while (n >> pwr) pwr++;
  if (n <= 0 || n != (1 << (pwr-1))) {
    err = 3;
    XERBLA(xName, &err, xLName);
    return;
  }

  if (rr == NULL) {
    err = 1;
    XERBLA(xName, &err, xLName);
    return;
  }

  if (ri == NULL) {
    err = 2;
    XERBLA(xName, &err, xLName);
    return;
  }

  if (n == 1) return;

  if (isign > 0) {
     // Backward FFT sample //

    Scale = E1/(float)n;
    if (k == 1) {
        t = (rr[0] + rr[1])*Scale;
        rr[1] = (rr[0] - rr[1])*Scale;
        rr[0] = t;
        t = (ri[0] + ri[1])*Scale;
        ri[1] = (ri[0] - ri[1])*Scale;
        ri[0] = t;
        return;
    }

    Scale = E1;
 
    if(abs(isign) < 2) cbitrevc_s(rr, ri, n, wsave);
    for (i= 0; i<n-1; i+=2)  {
              t = (rr[i] + rr[i+1])*Scale;
              rr[i+1] = (rr[i] - rr[i+1])*Scale;
              rr[i] = t;
              t = (ri[i] + ri[i+1])*Scale;
              ri[i+1] = (ri[i] - ri[i+1])*Scale;
              ri[i] = t;
     }

     lstep = 2;
     nn = n/4;
     nblk = lstep/2;
     stepi = n/2;

     for (nstep = 2; nstep <=k; nstep++) {
         i0 = 0;
         for (l = nn-1; l>=0; l--) {
             iw = 0;
             for (i = i0; i <= i0 + nblk-1; i++) {

                t = rr[i+lstep]*wsave[iw] + ri[i+lstep]*wsave[iw+1];
                t1 = -rr[i+lstep]*wsave[iw+1] + ri[i+lstep]*wsave[iw];

                rr[i+lstep] = rr[i] - t;
                rr[i] = rr[i] + t;
                ri[i+lstep] = ri[i] - t1;
                ri[i] = ri[i] + t1;
                iw = iw + stepi;
            }

             i0 = i0 + (lstep >>1);
             iw = 0;
             for (i = i0; i <= i0 + nblk-1; i++) {

                 t = rr[i+lstep]*wsave[iw+1] - ri[i+lstep]*wsave[iw];
                 t1 = rr[i+lstep]*wsave[iw] + ri[i+lstep]*wsave[iw+1];

                 rr[i+lstep] = rr[i] - t;
                 rr[i] = rr[i] + t;
                 ri[i+lstep] = ri[i] - t1;
                 ri[i] = ri[i] + t1;

                 iw = iw + stepi;
             }

             i0 = i0 + lstep + (lstep >> 1);
     }
     nn = nn >>1;
     lstep = lstep << 1;
     nblk = nblk << 1;
     stepi = stepi >>1;
   }
   // Scaling //
    Scale = E1/(float)n;
    for (i= 0; i<n-1; i+=2)  {
          rr[i] *= Scale;
          rr[i+1] *= Scale;
          ri[i] *= Scale;
          ri[i+1] *= Scale;
     }
  } else {
     // Forward FFT sample //
     if (k == 1) {
        t = rr[0] + rr[1];
        rr[1] = rr[0] - rr[1];
        rr[0] = t;
        t = ri[0] + ri[1];
        ri[1] = ri[0] - ri[1];
        ri[0] = t;
        return;
     }
     cbitrevc_s(rr, ri, n, wsave);

     for (i= 0; i<n-1; i+=2)  {
              t = rr[i] + rr[i+1];
              rr[i+1] = rr[i] - rr[i+1];
              rr[i] = t;
              t = ri[i] + ri[i+1];
              ri[i+1] = ri[i] - ri[i+1];
              ri[i] = t;
     }

     lstep = 2;
     nn = n/4;
     nblk = lstep/2;
     stepi = n/2;

     for (nstep = 2; nstep <=k; nstep++) {
         i0 = 0;
         for (l = nn-1; l>=0; l--) {
             iw = 0;
             for (i = i0; i <= i0 + nblk-1; i++) {

                     t = rr[i+lstep]*wsave[iw] - ri[i+lstep]*wsave[iw+1];
                     t1 = rr[i+lstep]*wsave[iw+1] + ri[i+lstep]*wsave[iw];

                     rr[i+lstep] = rr[i] - t;
                     rr[i] = rr[i] + t;
                     ri[i+lstep] = ri[i] - t1;
                     ri[i] = ri[i] + t1;
                     iw = iw + stepi;
            }

             i0 = i0 + (lstep >>1);
             iw = 0;
             for (i = i0; i <= i0 + nblk-1; i++) {

                  t = rr[i+lstep]*wsave[iw+1] + ri[i+lstep]*wsave[iw];
                     t1 = -rr[i+lstep]*wsave[iw] + ri[i+lstep]*wsave[iw+1];

                     rr[i+lstep] = rr[i] - t;
                     rr[i] = rr[i] + t;
                     ri[i+lstep] = ri[i] - t1;
                     ri[i] = ri[i] + t1;

                     iw = iw + stepi;
             }

             i0 = i0 + lstep + (lstep >> 1);
         }
         nn = nn >>1;
         lstep = lstep << 1;
         nblk = nblk << 1;
         stepi = stepi >>1;
     }
     if(abs(isign) == 2) cbitrevc_s(rr, ri, n, wsave);
  }
  return;
}


void  ZFFT1DC_S(double* rr, double* ri, int n, int isign, double* wsave) {
/*
* --- Version:
* ---         .03.98
* ---         RFNC (VNIIEF), Department 8, Mustaeva N.
* ---         for INTEL

* --- Function:
* ---          Computes forward/inverse 1-dimensional FFT of
* ---             a double presicion complex vector

* --- Implementation:
* ---        An in-place, split-radix, decimation-in-frequency,
* ---        complex FFT
* ---        (with table look-up)
* ---        On entry:
* ---           n - integer, transform length, must be power of 2,
* ---           rr - double, real part of complex input vector, 
* ---                array of dimension at least (n)
* ---           rr - double, imagine part of complex input vector, 
* ---                array of dimension at least (n)
* ---           isign - integer =  0  initialize the coefficents wsave
* ---                           = -1 perform forward fft
* ---                           =  1 perform inverse fft
* ---           wsave - double,
* ---                   array of dimension at least ((n*2)/4-2)
* ---        On return:
* ---           r - result of the transform (if isign = -1 or 1).
* ---               If isign=0, it is not changed.
* ---           wsave - if isign=0, it contains the initialized fft
* ---               coefficients. It is unaltered otherwise.

* --- Notice:
* ---        A call to zfft1dc with isign=0 must be prior to using the
* ---        function to compute the forward/inverse fft for a given length
* ---        in order to inicialize coeeficients. Thereafter, any number
* ---        transforms of the same length can be computed using
* ---        these coefficients.
*/

static const char xName[] = "ZFFT1DC_S";
double* r;
double* prr;
double* pri;
int    ldrr, ldrc, k, j, nstep, lstep, stepi, nblk;
int    p0 = 0;
int    p1 = 1;
double  Scale, t, t1, E1 = 1.0;
static int last_tw = 0;
int    pwr = 0;
int    err;
int    l, i, i0, iw, nn;


  if (n >= 0) while (n >> pwr) pwr++;
  if (n <= 0 || n != (1 << (pwr-1))) {
    err = 3;
    XERBLA(xName, &err, xLName);
    return;
  }

  if (rr == NULL) {
    err = 1;
    XERBLA(xName, &err, xLName);
    return;
  }

  if (ri == NULL) {
    err = 2;
    XERBLA(xName, &err, xLName);
    return;
  }

  if (wsave == NULL) {
    err = 5;
    XERBLA(xName, &err, xLName);
    return;
  }
  k = LOG2(&n);

  if (isign == 0) {
    last_tw = n;
    COEF4R22_ZC_S(k, wsave);
    return;
  }

  if (n == 1) return;

  if (isign > 0) {

      if(abs(isign) < 2) zbitrevc_s(rr, ri, n, wsave);
      Scale = E1/(double)n;
      for (i= 0; i<n-1; i+=2)  {
              t = (rr[i] + rr[i+1])*Scale;
              rr[i+1] = (rr[i] - rr[i+1])*Scale;
              rr[i] = t;
              t = (ri[i] + ri[i+1])*Scale;
              ri[i+1] = (ri[i] - ri[i+1])*Scale;
              ri[i] = t;
	  }
	  if (k == 1) return;

     lstep = 2;
     nn = n/4;
     nblk = lstep/2;
     stepi = n/2;

     for (nstep = 2; nstep <=k; nstep++) {
         i0 = 0;
         for (l = nn-1; l>=0; l--) {
             iw = 0;
             for (i = i0; i <= i0 + nblk-1; i++) {

                     t = rr[i+lstep]*wsave[iw] + ri[i+lstep]*wsave[iw+1];
                     t1 = -rr[i+lstep]*wsave[iw+1] + ri[i+lstep]*wsave[iw];

                     rr[i+lstep] = rr[i] - t;
                     rr[i] = rr[i] + t;
                     ri[i+lstep] = ri[i] - t1;
                     ri[i] = ri[i] + t1;
                     iw = iw + stepi;
            }

             i0 = i0 + (lstep >>1);
             iw = 0;
             for (i = i0; i <= i0 + nblk-1; i++) {

                 t = rr[i+lstep]*wsave[iw+1] - ri[i+lstep]*wsave[iw];
                 t1 = rr[i+lstep]*wsave[iw] + ri[i+lstep]*wsave[iw+1];

                 rr[i+lstep] = rr[i] - t;
                 rr[i] = rr[i] + t;
                 ri[i+lstep] = ri[i] - t1;
                 ri[i] = ri[i] + t1;

                 iw = iw + stepi;
             }

             i0 = i0 + lstep + (lstep >> 1);
     }
     nn = nn >>1;
     lstep = lstep << 1;
     nblk = nblk << 1;
     stepi = stepi >>1;
   }
  } else {
     zbitrevc_s(rr, ri, n, wsave);

     for (i= 0; i<n-1; i+=2)  {
              t = rr[i] + rr[i+1];
              rr[i+1] = rr[i] - rr[i+1];
              rr[i] = t;
              t = ri[i] + ri[i+1];
              ri[i+1] = ri[i] - ri[i+1];
              ri[i] = t;
     }
     if (k == 1) return;

     lstep = 2;
     nn = n/4;
     nblk = lstep/2;
     stepi = n/2;

     for (nstep = 2; nstep <=k; nstep++) {
         i0 = 0;

         for (l = nn-1; l>=0; l--) {
             iw = 0;
             for (i = i0; i <= i0 + nblk-1; i++) {

                     t = rr[i+lstep]*wsave[iw] - ri[i+lstep]*wsave[iw+1];
                     t1 = rr[i+lstep]*wsave[iw+1] + ri[i+lstep]*wsave[iw];

                     rr[i+lstep] = rr[i] - t;
                     rr[i] = rr[i] + t;
                     ri[i+lstep] = ri[i] - t1;
                     ri[i] = ri[i] + t1;
                     iw = iw + stepi;
            }

             i0 = i0 + (lstep >>1);
             iw = 0;
             for (i = i0; i <= i0 + nblk-1; i++) {

                  t = rr[i+lstep]*wsave[iw+1] + ri[i+lstep]*wsave[iw];
                     t1 = -rr[i+lstep]*wsave[iw] + ri[i+lstep]*wsave[iw+1];

                     rr[i+lstep] = rr[i] - t;
                     rr[i] = rr[i] + t;
                     ri[i+lstep] = ri[i] - t1;
                     ri[i] = ri[i] + t1;

                     iw = iw + stepi;
             }

             i0 = i0 + lstep + (lstep >> 1);
         }
         nn = nn >>1;
         lstep = lstep << 1;
         nblk = nblk << 1;
         stepi = stepi >>1;
     }
     if(abs(isign) == 2) zbitrevc_s(rr, ri, n, wsave);
  }
  return;
}

/* ; --------------------------- cfft1dc  routine --------
;  Purpose
;  =======
;
;-------------------------------------------------------------
;
;   Designed for C-interface by Mustaeva N., RFNC, 25.98
;------------------------------------------------------------- */

void cbitrevc_s(float* datar, float* datai, int n, float* con) {

     float   t;
     int     i, j, icon;
     int*    pcon = (int*)(mkl_intp)con;
     int     dfirst;
     int     dsecond;
     int*    pt;

     if (n > 2) {

         pcon = pcon + (n>>1);
         icon = *pcon;           /*  count of cycle */
         pcon++;                 /* begin of table */

         if (n <= 1024) {

             for (i=0;i<icon;i++) {
                 dfirst = *pcon;
                 pcon++;
                 dsecond = *pcon;
                 pcon++;
                 t = datar[dfirst];
                 datar[dfirst] = datar[dsecond];
                 datar[dsecond] = t;
                 t = datai[dfirst];
                 datai[dfirst] = datai[dsecond];
                 datai[dsecond] = t;
             }
         } else {
             pt = pcon;

             for (i=0;i<icon;i++) {

                 dfirst = *pcon;
                 pcon++;
                 dsecond = *pcon;
                 pcon++;
                 t = datar[dfirst];
                 datar[dfirst] = datar[dsecond];
                 datar[dsecond] = t;
             }

             pcon = pt;
             for (i=0;i<icon;i++) {

                 dfirst = *pcon;
                 pcon++;
                 dsecond = *pcon;
                 pcon++;
                 t = datai[dfirst];
                 datai[dfirst] = datai[dsecond];
                 datai[dsecond] = t;
             }
         }   /* n>10 */
     }   /* n>2 */
     return;
}  /* end */



/* ; --------------------------- zfft1dc  routine --------
;  Purpose
;  =======
;
;-------------------------------------------------------------
;
;   Designed for C-interface by Mustaeva N., RFNC, 25.98
;------------------------------------------------------------- */

void zbitrevc_s(double* datar, double* datai, int n, double* con) {

     double   t;
     int     i, j, icon;
     int*    pcon = (int*)(mkl_intp)con;
     int     dfirst;
     int     dsecond;
     int*    pt;

     if (n > 2) {

         pcon = pcon + n;
         icon = *pcon;           /*  count of cycle */
         pcon++;                 /* begin of table */

         if (n <= 512) {

             for (i=0;i<icon;i++) {
                 dfirst = *pcon;
                 pcon++;
                 dsecond = *pcon;
                 pcon++;
                 t = datar[dfirst];
                 datar[dfirst] = datar[dsecond];
                 datar[dsecond] = t;
                 t = datai[dfirst];
                 datai[dfirst] = datai[dsecond];
                 datai[dsecond] = t;
             }
         } else {
             pt = pcon;

             for (i=0;i<icon;i++) {

                 dfirst = *pcon;
                 pcon++;
                 dsecond = *pcon;
                 pcon++;
                 t = datar[dfirst];
                 datar[dfirst] = datar[dsecond];
                 datar[dsecond] = t;
             }

             pcon = pt;
             for (i=0;i<icon;i++) {

                 dfirst = *pcon;
                 pcon++;
                 dsecond = *pcon;
                 pcon++;
                 t = datai[dfirst];
                 datai[dfirst] = datai[dsecond];
                 datai[dsecond] = t;
             }
         }   /* n>10 */
     }   /* n>2 */
     return;
}  /* end */


/*
*     Twiddle factors calculation
*     for 'simple' fft of C-test
*
*/


  void bittab_s(int* x, int n);

  void COEF4R22_S(int k, float* w)
  {
      double fi, one=1.0, eight=8.0;
      double temp_fi;
      int   n, i, s;
      int   cashe_L2 = 14;

      int*   wint;
      mkl_intp    intadr;

      if (k <= 1) return;

      n = 1 << k;
      fi = eight * atan(one)/(double)n;

      s = n >> 2;

      w[0] = 1.0;
      w[1] = 0.0;
      temp_fi =  fi;
      for( i = 1; i < s; i++){
         w[2*i] = (float)cos(temp_fi);
         w[2*i+1] = -(float)sin(temp_fi);
         temp_fi +=fi;
      }

      intadr = (mkl_intp) w;
      wint = (int*) intadr;

      bittab_s(&wint[s*2], n);
  }

      void bittab_s(int* x, int n){
      int  j,i,k,kk;
/*     -- Bit-reverse shuffle */
      j = 1;
      kk = 0;
      for(i=1; i <= (n-1); i++){
         if (i < j){
            kk += 2;
            x[kk-1] = i-1;
            x[kk] = j-1;
         }
         k =  n >> 1;
M1:      if (j > k){
            j = j-k;
            k = k >> 1;
            goto M1;
		 }
         j = j+k;
      }
      x[0]=kk/2;
      return;
}   /*   end  */


  void bittaz_s(int* x, int n);

  void COEF4R22_ZC_S(int k, double* w)
  {
      double fi, one=1.0, eight=8.0;
      double temp_fi;
      int    n, i, s;
      int    cashe_L2 = 14;

      int*   wint;
      mkl_intp    intadr;

      if (k <= 1) return;

      n = 1 << k;
      fi = eight * atan(one)/(double)n;
      s = n >> 2;

      w[0] = 1.0;
      w[1] = 0.0;
      temp_fi = fi;
      for( i = 1; i < s; i++){
         w[2*i] = cos(temp_fi);
         w[2*i+1] = -sin(temp_fi);
      temp_fi += fi;
      }

      intadr =(mkl_intp)&w[s*2];
      wint =(int*) intadr;
      bittaz_s(wint, n);
  
      for( i = 0; i < (2*wint[0]+1); i++){
	  }
}

      void bittaz_s(int* x, int n){
      int  j,i,k,kk;
/*     -- Bit-reverse shuffle */
      j = 1;
      kk = 0;
      for(i=1; i <= (n-1); i++){
         if (i < j){
            kk += 2;
            x[kk-1] = i-1;
            x[kk] = j-1;
         }
         k =  n >> 1;
M1:      if (j > k){
            j = j-k;
            k = k >> 1;
            goto M1;
		 }
         j = j+k;
      }
      x[0]=kk/2;
      return;
}   /*   end  */


/* ---------------------------------------------------------
* --                                                     --
* --     L O G 2 ()                                      --
* --                                                     --
* ---------------------------------------------------------
*/

      int LOG2(int* n) {

/*
* --- Function:
* ---        Integer log2(n)

* --- Implementation:
* ---        On entry:  integer n, must be power of 2
* ---        On return: +integer, - if n is power of  2
* ---                    -1       - if n is not power of 2

* --- Notice:
* ---        n - must be integer*4
*/


/* --- Local Variables    */
      int    pwr = 0;
      int   reslog2;

/* --- Executable Statements */


      if (*n <= 0) {
         reslog2 = -1;
         return(reslog2);
      }

      while (*n >> pwr) pwr++;

      if (*n == (1 << (pwr-1))) return(pwr-1);

      reslog2 = -1;
      return(reslog2);
  }

