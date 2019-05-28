/*M*
*
*  INTEL CORPORATION PROPRIETARY INFORMATION
*  This software is supplied under the terms of a license agreement or
*  nondisclosure agreement with Intel Corporation and may not be copied
*  or disclosed except in accordance with the terms of that agreement.
*  Copyright (c) 1999 Intel Corporation. All Rights Reserved.
*
*      $Workfile$
*      $Revision$
*      $Modtime$
*
*  Contents:
*      simple FFT code
*
*  Author  : Sivolgina O.,  Mustaeva N.
*
*M*/

#include <windows.h>
#include <math.h>
#include <stdarg.h>
#include <float.h>
#include "fft_test.h"

void  cradix4s(float*, int*, int*, float*);
void  CFFT1D_S(float*, int*, int*, float*);
void  CBITREVSS(float*, int*, int*, float*);
void  cr4irevs(float*, int*, float*, int*, float*);
void  COEF4R22S(int*, float*);
void  bittabs(int*, int);
void  ccopy(int*, float*, int*, float*, int*);
void  zcopy(int*, double*, int*, double*, int*);

void  ZFFT1D_S(double*, int*, int*, double*);
void  ZRADIX4S(double*, int*, int*, double*);
void  ZBITREVSS(double*, int*, int*, double*);
void  zr4irevs(double*, int*, double*, int*, double*);
void  COEF4R22_ZS(int*, double*);
void  bittazs(int*, int);

//#define ZCOPY zcopy
//#define CCOPY ccopy

/* ------------------------------------------------
*     Sample FFT functions for testing compariable
*  ------------------------------------------------
*/

void CFFT2D_S(float* r, int* m, int* n, int* isign, float* twidle, float* t01) {

/* --- Function:
* ---          Sample FFT
* ---          Computes forward/inverse 2-dimensional FFT of
* ---             a single presicion complex vector
*/
      

/* --- Local variables */
      int i, j;
      int p0 = 0;
      int p1 = 1;

/***************************
*     column direction
***************************/
      CFFT1D_S(r, m, &p0, twidle);
      for (j = 0; j<*n; j++) {
         CFFT1D_S(&r[j*2*(*m)], m, isign, twidle);
      }

/***************************
*     row direction
***************************/

      CFFT1D_S(r, n, &p0, twidle);
      for ( i=0; i<*m; i++) {
         CCOPY(n, &r[i*2], m, t01, &p1);
         CFFT1D_S(t01, n, isign, twidle);
         CCOPY(n, t01, &p1, &r[i*2], m);
      }
      return;
 }   


 void ZFFT2D_S(double* r, int* m, int* n, int* isign, double* twidle, double* t01) {

/* --- Function:
* ---          Sample FFT
* ---          Computes forward/inverse 2-dimensional FFT of
* ---             a double presicion complex vector
*/

/* --- Local variables */
      int i, j;
      int p0 = 0;
      int p1 = 1;

/***************************
*     column direction
***************************/

      ZFFT1D_S(r, m, &p0, twidle);
      for (j = 0; j<*n; j++) {
         ZFFT1D_S(&r[j*2*(*m)], m, isign, twidle);
      }

/***************************
*     row direction
***************************/

      ZFFT1D_S(r, n, &p0, twidle);
      for (i = 0; i<*m; i++) {
         ZCOPY(n, &r[i*2], m, t01, &p1);
         ZFFT1D_S(t01, n, isign, twidle);
         ZCOPY(n, t01, &p1, &r[i*2], m);
      }
      return;
  }

void  CFFT1D_S(float* r, int* n, int* isign, float* wsave) {
/*
* --- Version:
* ---         RFNC (VNIIEF), Department 8, Sivolgina O.
* ---         for INTEL
* ---         .11.98
* ---         RFNC (VNIIEF), Department 8, Mustaeva N.
* ---         for INTEL

* --- Fortran-style function:   
* ---          Computes forward/inverse 1-dimensional FFT of
* ---             a float presicion complex vector

* --- Implementation:
* ---        An in-place, radix4, decimation-in-frequency,
* ---        complex FFT
* ---        (with table look-up)
* ---        On entry:
* ---           n - integer, transform length, must be power of 2,
* ---           r - float complex input vector,
* ---               array of dimension at least (n)
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
* ---        A call to cfft1d with isign=0 must be prior to using the
* ---        function to compute the forward/inverse fft for a given length
* ---        in order to inicialize coeeficients. Thereafter, any number
* ---        transforms of the same length can be computed using
* ---        these coefficients.
*/

float  Scale, E1 = 1.0;
int    ldrr;
int    pwr = 0;

/*     Test the input parameters */
    if (*n == 0 || *n == 1) return;

    if (*n >= 0) while (*n >> pwr) pwr++;
    pwr--;

    if (*isign == 0) {
        COEF4R22S(&pwr, wsave);
        return;
    }

    ldrr = -(*isign);

    if (*isign > 0 ) {

        if (pwr == 1) {
            Scale = (r[0]+r[2]) / 2;
            r[2] = (r[0] - r[2]) / 2;
            r[0]= Scale;
            Scale = (r[1]+r[3]) / 2;
            r[3] = (r[1] - r[3]) / 2;
            r[1]= Scale;
            return;
        }
        Scale = E1 / (float)(*n);
        if (*isign != 2) {
           CBITREVSS(r, n, isign, wsave);
        }
        cr4irevs(r, n, wsave, &pwr, &Scale);

    } else {

        cradix4s(r, &pwr, &ldrr, wsave);

        if (*isign != -2) {
            CBITREVSS(r, n, isign, wsave);
        }
    }

    return;
}

void cradix4s(float* d, int* k, int* isign, float* w) {

    float tr, ti, tr1, ti1, tr2, ti2, tr3, ti3;
    int   nstep, nl, n2, n4, nn, i, i0, iwt, j, stepi;
    int   w1, w2;

    if (*k == 1) {
       tr = d[0] - d[2];
       ti = d[1] - d[3];
       d[0] = d[0] + d[2];
       d[1] = d[1] + d[3];
       d[2] = tr;
       d[3] = ti;
       return;
    }

    n4 = 1 << *k;
    n2 = n4 >> 1;
    w1 = n2;
    w2 = n4;

    nl = 1;
    stepi = 2;
    for (nstep = 4; nstep <= *k; nstep = nstep+2) {
        i0 = 0;
        nn = n2+n4;
        for (j = nl; j > 0; j--) {
            iwt = stepi;
            tr = d[i0] + d[i0+n4];
            ti = d[i0+1] + d[i0+n4+1];
            tr2 = d[i0] - d[i0+n4];
            ti2 = d[i0+1] - d[i0+n4+1];
            tr1 = d[i0+n2] + d[i0+nn];
            ti1 = d[i0+n2+1] + d[i0+nn+1];
            tr3 = d[i0+n2] - d[i0+nn];
            ti3 = d[i0+n2+1] - d[i0+nn+1];
            d[i0] = tr + tr1;
            d[i0+1] = ti + ti1;
            d[i0+n2] = tr - tr1;
            d[i0+n2+1] = ti - ti1;
            d[i0+n4] = tr2 + ti3;
            d[i0+n4+1] = ti2 - tr3;
            d[i0+nn] = tr2 - ti3;
            d[i0+nn+1] = ti2 + tr3;

            for (i=i0+2; i < i0+n2; i = i+2) {

                tr = d[i] + d[i+n4];
                ti = d[i+1] + d[i+n4+1];
                tr1 = d[i] - d[i+n4];
                ti1 = d[i+1] - d[i+n4+1];
                tr2 = d[i+n2] + d[i+nn];
                ti2 = d[i+n2+1] + d[i+nn+1];
                tr3 = d[i+n2] - d[i+nn];
                ti3 = d[i+n2+1] - d[i+nn+1];
                d[i] = tr+tr2;
                tr = tr - tr2;
                d[i+1] = ti+ti2;
                ti = ti - ti2;
                d[i+n2] = tr * w[iwt+w1] - ti * w[iwt+w1+1];
                d[i+n2+1] = ti * w[iwt+w1] + tr * w[iwt+w1+1];
                tr = tr1+ti3;
                tr1 = tr1-ti3;
                ti = ti1-tr3;
                ti1 = ti1+tr3;
                d[i+n4] = tr * w[iwt] - ti * w[iwt+1];
                d[i+n4+1] = ti * w[iwt] + tr * w[iwt+1];
                d[i+nn] = tr1 * w[iwt+w2] - ti1 * w[iwt+w2+1];
                d[i+nn+1] = ti1 * w[iwt+w2] + tr1 *w[iwt+w2+1];

                iwt = iwt +stepi;
            }
            i0 = i0 + 2*n4;
        }
        nl = nl << 2;
        n2 = n2 >> 2;
        n4 = n4 >> 2;
        stepi = stepi << 2;
    }

    j = 1 << (*k+1);

    if ((*k & 1) == 1) {

        nl = j >> 3;
        for (i=0; i < j; i = i+16) {
            tr = d[i] + d[i+8];
            ti = d[i+1] + d[i+9];
            tr2 = d[i] - d[i+8];
            ti2 = d[i+1] - d[i+9];
            tr1 = d[i+4] + d[i+12];
            ti1 = d[i+5] + d[i+13];
            tr3 = d[i+4] - d[i+12];
            ti3 = d[i+5] - d[i+13];
            d[i] = tr + tr1;
            d[i+1] = ti + ti1;
            d[i+4] = tr - tr1;
            d[i+5] = ti - ti1;
            d[i+8] = tr2 + ti3;
            d[i+9] = ti2 - tr3;
            d[i+12] = tr2 - ti3;
            d[i+13] = ti2 + tr3;

            tr = d[i+2] + d[i+10];
            ti = d[i+3] + d[i+11];
            tr1 = d[i+2] - d[i+10];
            ti1 = d[i+3] - d[i+11];
            tr2 = d[i+6] + d[i+14];
            ti2 = d[i+7] + d[i+15];
            tr3 = d[i+6] - d[i+14];
            ti3 = d[i+7] - d[i+15];
            d[i+2] = tr + tr2;
            d[i+3] = ti + ti2;
            d[i+6] = ti - ti2;
            d[i+7] = tr2 - tr;

            tr = tr1 + ti3;
            ti = ti1 - tr3;
            d[i+10] = w[nl] * (tr + ti);
            d[i+11] = w[nl] * (ti - tr);
            tr = tr1 - ti3;
            ti = ti1 + tr3;
            d[i+14] = w[nl] * (ti - tr);
            d[i+15] = - w[nl] * (ti + tr);
        }
        for (i=0; i < j; i= i+4) {
            tr = d[i] + d[i+2];
            ti = d[i+1] + d[i+3];
            d[i+2] = d[i] - d[i+2];
            d[i+3] = d[i+1] - d[i+3];
            d[i] = tr;
            d[i+1] = ti;
        }

    } else {
        for (i=0; i<j; i= i+8) {
            tr = d[i] + d[i+4];
            ti = d[i+1] + d[i+5];
            tr2 = d[i] - d[i+4];
            ti2 = d[i+1] - d[i+5];
            tr1 = d[i+2] + d[i+6];
            ti1 = d[i+3] + d[i+7];
            tr3 = d[i+2] - d[i+6];
            ti3 = d[i+3] - d[i+7];
            d[i] = tr + tr1;
            d[i+1] = ti + ti1;
            d[i+2] = tr - tr1;
            d[i+3] = ti - ti1;
            d[i+4] = tr2 + ti3;
            d[i+5] = ti2 - tr3;
            d[i+6] = tr2 - ti3;
            d[i+7] = ti2 + tr3;
        }
    }
    return;
}

void cr4irevs(float* d, int* n, float* w, int* kj, float* scale) {
   float tr, ti, t1r, t1i, t2r, t2i, t3r, t3i, twr, twi;
   int nstep, lstep, lstep2, lstep4, nn, i, stepi;
   float fnorm;
   int k, i0, i1, iw, ldd, step1w, step2w;

   fnorm = *scale;
   ldd = *n << 1;
   step1w = ldd >> 2;
   step2w = step1w + step1w;
   if ((*kj & 1) == 1) {

      for (i=0; i < ldd; i = i+4) {
          tr = d[i] + d[i+2];
          ti = d[i+1] + d[i+3];
          d[i+2] = (d[i] - d[i+2]) * fnorm;
          d[i+3] = (d[i+1] - d[i+3]) * fnorm;
          d[i] = tr * fnorm;
          d[i+1] = ti * fnorm;
      }

      stepi = ldd >> 3;
      for (i=0; i<ldd; i=i+16) {
          tr = d[i] + d[i+4];
          ti = d[i+1] + d[i+5];
          t2r = d[i] - d[i+4];
          t2i = d[i+1] - d[i+5];
          t1r = d[i+8] + d[i+12];
          t1i = d[i+9] + d[i+13];
          t3r = d[i+8] - d[i+12];
          t3i = d[i+9] - d[i+13];
          d[i] = tr + t1r;
          d[i+1] = ti + t1i;
          d[i+8] = tr - t1r;
          d[i+9] = ti - t1i;
          d[i+4] = t2r - t3i;
          d[i+5] = t2i + t3r;
          d[i+12] = t2r + t3i;
          d[i+13] = t2i - t3r;

          tr = d[i+2] - d[i+7];
          ti = d[i+3] + d[i+6];
          t1r = d[i+2] + d[i+7];
          t1i = d[i+3] - d[i+6];

          t2r = d[i+10] - d[i+15];
          t2i = d[i+11] + d[i+14];
          t3r = w[stepi] * (t2r - t2i);
          t3i = w[stepi] * (t2r + t2i);
          d[i+2] = tr + t3r;
          d[i+3] = ti + t3i;
          tr = tr - t3r;
          ti = ti - t3i;

          t2r = d[i+14] - d[i+11];
          t2i = d[i+10] + d[i+15];
          t3r = w[stepi] * (t2r - t2i);
          t3i = w[stepi] * (t2r + t2i);
          d[i+6] = t1r + t3r;
          d[i+7] = t1i + t3i;
          d[i+14] = t1r - t3r;
          d[i+15] = t1i - t3i;
          d[i+10] = tr;
          d[i+11] = ti;
      }

      lstep = 32;
      stepi = stepi >> 2;

   } else {

       for (i = 0; i < ldd; i = i+8) {

           tr = d[i] + d[i+2];
           ti = d[i+1] + d[i+3];
           t2r = d[i] - d[i+2];
           t2i = d[i+1] - d[i+3];
           t1r = d[i+4] + d[i+6];
           t1i = d[i+5] + d[i+7];
           t3r = d[i+4] - d[i+6];
           t3i = d[i+5] - d[i+7];
           d[i] = (tr + t1r) * fnorm;
           d[i+1] = (ti + t1i) * fnorm;
           d[i+4] = (tr - t1r) * fnorm;
           d[i+5] = (ti - t1i) * fnorm;
           d[i+2] = (t2r - t3i) * fnorm;
           d[i+3] = (t2i + t3r) * fnorm;
           d[i+6] = (t2r + t3i) * fnorm;
           d[i+7] = (t2i - t3r) * fnorm;
       }
       lstep = 16;
       stepi = ldd >> 4;
   }

   lstep2 = lstep >> 1;
   nn = (ldd/lstep) >> 1;

   for (nstep=4; nstep <= *kj; nstep = nstep+2) {
       i1 = lstep + lstep2;
       i = 0;
       iw = 0;
       for (k=nn; k > 0; k--) {
           tr = d[i] + d[i+lstep2];
           ti = d[i+1] + d[i+lstep2+1];
           t2r = d[i] - d[i+lstep2];
           t2i = d[i+1] - d[i+lstep2+1];
           t1r = d[i+lstep] + d[i+i1];
           t1i = d[i+lstep+1] + d[i+i1+1];
           t3r = d[i+lstep] - d[i+i1];
           t3i = d[i+lstep+1] - d[i+i1+1];
           d[i] = tr + t1r;
           d[i+1] = ti + t1i;
           d[i+lstep] = tr - t1r;
           d[i+lstep+1] = ti - t1i;
           d[i+lstep2] = t2r - t3i;
           d[i+lstep2+1] = t2i + t3r;
           d[i+i1] = t2r + t3i;
           d[i+i1+1] = t2i - t3r;

           i = i + (lstep<<1);
       }

       iw = iw + stepi;
       for (i0 = 2; i0 < lstep2; i0 = i0 + 2) {
           i = i0;
           for (k = nn; k > 0; k--) {
               t1r = d[i+lstep2] * w[iw+step1w] + d[i+lstep2+1] * w[iw+step1w+1];
               t1i = -d[i+lstep2] * w[iw+step1w+1] + d[i+lstep2+1] * w[iw+step1w];
               tr = d[i] + t1r;
               ti = d[i+1] + t1i;
               t1r = d[i] - t1r;
               t1i = d[i+1] - t1i;
               t3r = d[i+i1] * w[iw+step2w] + d[i+i1+1] * w[iw+step2w+1];
               t3i = -d[i+i1] * w[iw+step2w+1] + d[i+i1+1] * w[iw+step2w];
               t2r = d[i+lstep] * w[iw] + d[i+lstep+1] * w[iw+1];
               t2i = -d[i+lstep] * w[iw+1] + d[i+lstep+1] * w[iw];
               twr = t2r + t3r;
               twi = t2i + t3i;
               d[i] = tr + twr;
               d[i+1] = ti + twi;
               d[i+lstep] = tr - twr;
               d[i+lstep+1] = ti - twi;
               tr = t2r - t3r;
               ti = t2i - t3i;
               d[i+lstep2] = t1r - ti;
               d[i+lstep2+1] = t1i + tr;
               d[i+i1] = t1r + ti;
               d[i+i1+1] = t1i - tr;

               i = i + (lstep<<1);
           }
           iw = iw+stepi;
       }
       nn = nn >> 2;
       lstep = lstep << 2;
       lstep2 = lstep2 << 2;
       lstep4 = lstep4 << 2;
       stepi = stepi >> 2;
   }
   return;
}

void COEF4R22S(int* k, float* w) {
/*
* --- Function: coef4r22
* ---        Compute the table of twiddle factors for
* ---        the forward/inverse radix2 FFT (single precision)
* --- Function: bittac
* ---        Compute the integer table for bit-reverse
*/
      int n, i, j, t, s, kj;
      double fi, tfi;
      double E1=(double)1.0;

      int cache_L1 = 9;
      int cache_L1_x = 9;
      int cache_L2 = 14;
      int*   wint;
      mkl_intp intadr;

      n = 1 << (*k);

      w[0] = (float)n;
      w[1] = 0.0;
      if (*k <= 1) return;

      fi = (double)8.0 * (double)atan(E1)/(double)n;
      s = n >> 2;
         tfi = fi;
         for( i = 1; i < s; i++){
             w[i*2]   =  (float)cos(tfi);
             w[i*2+1] = -(float)sin(tfi);
             tfi += fi;
         }
         j = 2;
         for( i = s+1; i < s+s; i++){
             w[i*2]   =  w[j]*w[j] - w[j+1]*w[j+1];
             w[i*2+1] = w[j]*w[j+1]*2;
             j = j+2;
         }
         j = 2;
         t = s+s+2;
         for( i = s+s+1; i < s+s+s; i++){
             w[i*2]   =  w[j]*w[t] - w[j+1]*w[t+1];
             w[i*2+1] = w[j]*w[t+1] + w[t]*w[j+1];
             j = j+2;
             t = t+2;
         }
       s = n;

     intadr =(mkl_intp)&w[s*2];
     wint =(int*) intadr;
     bittabs(wint, n);
}

      void bittabs(int* x, int n){
      int  j,i,k,kk;
/*     -- Bit-reverse shuffle */
      j = 1;
      kk = 0;
      for(i=1; i <= (n-1); i++){
         if (i < j){
            kk += 2;
            x[kk] = (i-1) * 2;
            x[kk+1] = (j-1) * 2;
         }
         k =  n >> 1;
M1:      if (j > k){
            j = j-k;
            k = k >> 1;
            goto M1;
		 }
         j = j+k;
      }
      x[0]=0;
/*      x[1]=kk/2; */
      x[1] = kk;
      return;
}   /*   end  */

void CBITREVSS(float* d, int* n, int * isign, float* wint) {

    int    i, j1, j2, k;
    float  t;
    int*   w;
    mkl_intp intadr;

    if (*n <= 2) return;
    k = *n << 1;
    intadr =(mkl_intp)wint;
    w =(int*) intadr;


    for (i=k+2; i < k+2+w[k+1]; i = i+2) {
        j1 = w[i];
        j2=  w[i+1];
        t = d[j1];
        d[j1] = d[j2];
        d[j2] = t;
        t = d[j1+1];
        d[j1+1] = d[j2+1];
        d[j2+1] = t;
    }
    return;
}

void  ZFFT1D_S(double* r, int* n, int* isign, double* wsave)
/*
// --- Version:
// ---         .10.98
// ---         RFNC (VNIIEF), Department 8, Sivolgina O.
// ---         for INTEL
// ---         .05.99
// ---         RFNC (VNIIEF), Department 8, Mustaeva N.
// ---         for INTEL
//
// --- Fortran-style function:   
// ---          Computes forward/inverse 1-dimensional FFT of
// ---             a double presicion complex vector
//
// --- Implementation:
// ---        An in-place, radix4, decimation-in-frequency,
// ---        complex FFT
// ---        (with table look-up)
// ---        On entry:
// ---           n - integer, transform length, must be power of 2,
// ---           r - double complex input vector,
// ---               array of dimension at least (n)
// ---           isign - integer =  0  initialize the coefficents wsave
// ---                           = -1 perform forward fft
// ---                           =  1 perform inverse fft
// ---                           = -2 perform forward fft with out bitreverse
// ---                           =  2 perform inverse fft with out bitrevers
// ---           wsave - double,
// ---                   array of dimension at least ((n*2)/4-2)
// ---        On return:
// ---           r - result of the transform (if isign = -1 or 1).
// ---               If isign=0, it is not changed.
// ---           wsave - if isign=0, it contains the initialized fft
// ---               coefficients. It is unaltered otherwise.
//
// --- Notice:
// ---        A call to cfft1d with isign=0 must be prior to using the
// ---        function to compute the forward/inverse fft for a given length
// ---        in order to inicialize coeeficients. Thereafter, any number
// ---        transforms of the same length can be computed using
// ---        these coefficients.
*/
{
    double  Scale, E1 = 1.0;
    int    ldrr;
    int    i;
    int    p1 = 1;
    int    pwr = 0;

    if (*n == 0 || *n == 1) return;

    if (*n >= 0) while (*n >> pwr) pwr++;
    pwr--;

    if (*isign == 0) {
        COEF4R22_ZS(&pwr, wsave);
        return;
    }/* if */

    ldrr = -(*isign);

    if (*isign > 0 ) {
        if (pwr == 1) {
            Scale = (r[0]+r[2]) / 2;
            r[2] = (r[0] - r[2]) / 2;
            r[0]= Scale;
            Scale = (r[1]+r[3]) / 2;
            r[3] = (r[1] - r[3]) / 2;
            r[1]= Scale;
            return;
        }/* if */

        Scale = E1 / (double)(*n);
        if (*isign != 2) {
            ZBITREVSS(r, n, isign, wsave);
        }/* if */
          
        zr4irevs(r, n, wsave, &pwr, &Scale);

    } else {

        ZRADIX4S(r, &pwr, &ldrr, wsave);

        if (*isign != -2) {
            ZBITREVSS(r, n, isign, wsave);
        }/* if */
    }/* if */
    return;
}

void ZRADIX4S(double* d, int* k, int* isign, double* w) {

    double tr, ti, tr1, ti1, tr2, ti2, tr3, ti3;
    int   nstep, nl, n2, n4, nn, i, i0, iwt, j, stepi;
    int   w1, w2;

    if (*k == 1) {
       tr = d[0] - d[2];
       ti = d[1] - d[3];
       d[0] = d[0] + d[2];
       d[1] = d[1] + d[3];
       d[2] = tr;
       d[3] = ti;
       return;
    }

    n4 = 1 << *k;
    n2 = n4 >> 1;
    w1 = n2;
    w2 = n4;

    nl = 1;
    stepi = 2;
    for (nstep = 4; nstep <= *k; nstep = nstep+2) {
        i0 = 0;
        nn = n2+n4;
        for (j = nl; j > 0; j--) {
            iwt = stepi;
            tr = d[i0] + d[i0+n4];
            ti = d[i0+1] + d[i0+n4+1];
            tr2 = d[i0] - d[i0+n4];
            ti2 = d[i0+1] - d[i0+n4+1];
            tr1 = d[i0+n2] + d[i0+nn];
            ti1 = d[i0+n2+1] + d[i0+nn+1];
            tr3 = d[i0+n2] - d[i0+nn];
            ti3 = d[i0+n2+1] - d[i0+nn+1];
            d[i0] = tr + tr1;
            d[i0+1] = ti + ti1;
            d[i0+n2] = tr - tr1;
            d[i0+n2+1] = ti - ti1;
            d[i0+n4] = tr2 + ti3;
            d[i0+n4+1] = ti2 - tr3;
            d[i0+nn] = tr2 - ti3;
            d[i0+nn+1] = ti2 + tr3;

            for (i=i0+2; i < i0+n2; i = i+2) {

                tr = d[i] + d[i+n4];
                ti = d[i+1] + d[i+n4+1];
                tr1 = d[i] - d[i+n4];
                ti1 = d[i+1] - d[i+n4+1];
                tr2 = d[i+n2] + d[i+nn];
                ti2 = d[i+n2+1] + d[i+nn+1];
                tr3 = d[i+n2] - d[i+nn];
                ti3 = d[i+n2+1] - d[i+nn+1];
                d[i] = tr+tr2;
                tr = tr - tr2;
                d[i+1] = ti+ti2;
                ti = ti - ti2;
                d[i+n2] = tr * w[iwt+w1] - ti * w[iwt+w1+1];
                d[i+n2+1] = ti * w[iwt+w1] + tr * w[iwt+w1+1];
                tr = tr1+ti3;
                tr1 = tr1-ti3;
                ti = ti1-tr3;
                ti1 = ti1+tr3;
                d[i+n4] = tr * w[iwt] - ti * w[iwt+1];
                d[i+n4+1] = ti * w[iwt] + tr * w[iwt+1];
                d[i+nn] = tr1 * w[iwt+w2] - ti1 * w[iwt+w2+1];
                d[i+nn+1] = ti1 * w[iwt+w2] + tr1 *w[iwt+w2+1];

                iwt = iwt +stepi;
            }
            i0 = i0 + 2*n4;
        }
        nl = nl << 2;
        n2 = n2 >> 2;
        n4 = n4 >> 2;
        stepi = stepi << 2;
    }

    j = 1 << (*k+1);

    if ((*k & 1) == 1) {

       nl = j >> 3;
       for (i=0; i < j; i = i+16) {
         tr = d[i] + d[i+8];
         ti = d[i+1] + d[i+9];
         tr2 = d[i] - d[i+8];
         ti2 = d[i+1] - d[i+9];
         tr1 = d[i+4] + d[i+12];
         ti1 = d[i+5] + d[i+13];
         tr3 = d[i+4] - d[i+12];
         ti3 = d[i+5] - d[i+13];
         d[i] = tr + tr1;
         d[i+1] = ti + ti1;
         d[i+4] = tr - tr1;
         d[i+5] = ti - ti1;
         d[i+8] = tr2 + ti3;
         d[i+9] = ti2 - tr3;
         d[i+12] = tr2 - ti3;
         d[i+13] = ti2 + tr3;

         tr = d[i+2] + d[i+10];
         ti = d[i+3] + d[i+11];
         tr1 = d[i+2] - d[i+10];
         ti1 = d[i+3] - d[i+11];
         tr2 = d[i+6] + d[i+14];
         ti2 = d[i+7] + d[i+15];
         tr3 = d[i+6] - d[i+14];
         ti3 = d[i+7] - d[i+15];
         d[i+2] = tr + tr2;
         d[i+3] = ti + ti2;
         d[i+6] = ti - ti2;
         d[i+7] = tr2 - tr;

         tr = tr1 + ti3;
         ti = ti1 - tr3;
		 d[i+10] = w[nl] * (tr + ti);
         d[i+11] = w[nl] * (ti - tr);
         tr = tr1 - ti3;
         ti = ti1 + tr3;
         d[i+14] = w[nl] * (ti - tr);
         d[i+15] = - w[nl] * (ti + tr);
     }
     for (i=0; i < j; i= i+4) {
        tr = d[i] + d[i+2];
        ti = d[i+1] + d[i+3];
        d[i+2] = d[i] - d[i+2];
        d[i+3] = d[i+1] - d[i+3];
        d[i] = tr;
        d[i+1] = ti;
     }

    } else {
       for (i=0; i<j; i= i+8) {
         tr = d[i] + d[i+4];
         ti = d[i+1] + d[i+5];
         tr2 = d[i] - d[i+4];
         ti2 = d[i+1] - d[i+5];
         tr1 = d[i+2] + d[i+6];
         ti1 = d[i+3] + d[i+7];
         tr3 = d[i+2] - d[i+6];
         ti3 = d[i+3] - d[i+7];
         d[i] = tr + tr1;
         d[i+1] = ti + ti1;
         d[i+2] = tr - tr1;
         d[i+3] = ti - ti1;
         d[i+4] = tr2 + ti3;
         d[i+5] = ti2 - tr3;
         d[i+6] = tr2 - ti3;
         d[i+7] = ti2 + tr3;
      }
   }
   return;
}

void zr4irevs(double* d, int* n, double* w, int* kj, double* scale) {
   double tr, ti, t1r, t1i, t2r, t2i, t3r, t3i, twr, twi;
   int nstep, lstep, lstep2, lstep4, nn, i, stepi;
   double fnorm;
   int k, i0, i1, iw, ldd, step1w, step2w;

   fnorm = *scale;
   ldd = *n << 1;
   step1w = ldd >> 2;
   step2w = step1w + step1w;
   if ((*kj & 1) == 1) {

      for (i=0; i < ldd; i = i+4) {
          tr = d[i] + d[i+2];
          ti = d[i+1] + d[i+3];
          d[i+2] = (d[i] - d[i+2]) * fnorm;
          d[i+3] = (d[i+1] - d[i+3]) * fnorm;
          d[i] = tr * fnorm;
          d[i+1] = ti * fnorm;
      }

      stepi = ldd >> 3;
      for (i=0; i<ldd; i=i+16) {
          tr = d[i] + d[i+4];
          ti = d[i+1] + d[i+5];
          t2r = d[i] - d[i+4];
          t2i = d[i+1] - d[i+5];
          t1r = d[i+8] + d[i+12];
          t1i = d[i+9] + d[i+13];
          t3r = d[i+8] - d[i+12];
          t3i = d[i+9] - d[i+13];
          d[i] = tr + t1r;
          d[i+1] = ti + t1i;
          d[i+8] = tr - t1r;
          d[i+9] = ti - t1i;
          d[i+4] = t2r - t3i;
          d[i+5] = t2i + t3r;
          d[i+12] = t2r + t3i;
          d[i+13] = t2i - t3r;

          tr = d[i+2] - d[i+7];
          ti = d[i+3] + d[i+6];
          t1r = d[i+2] + d[i+7];
          t1i = d[i+3] - d[i+6];

          t2r = d[i+10] - d[i+15];
          t2i = d[i+11] + d[i+14];
          t3r = w[stepi] * (t2r - t2i);
          t3i = w[stepi] * (t2r + t2i);
          d[i+2] = tr + t3r;
          d[i+3] = ti + t3i;
          tr = tr - t3r;
          ti = ti - t3i;

          t2r = d[i+14] - d[i+11];
          t2i = d[i+10] + d[i+15];
          t3r = w[stepi] * (t2r - t2i);
          t3i = w[stepi] * (t2r + t2i);
          d[i+6] = t1r + t3r;
          d[i+7] = t1i + t3i;
          d[i+14] = t1r - t3r;
          d[i+15] = t1i - t3i;
          d[i+10] = tr;
          d[i+11] = ti;


      }

      lstep = 32;
      stepi = stepi >> 2;

   } else {

       for (i = 0; i < ldd; i = i+8) {

           tr = d[i] + d[i+2];
           ti = d[i+1] + d[i+3];
           t2r = d[i] - d[i+2];
           t2i = d[i+1] - d[i+3];
           t1r = d[i+4] + d[i+6];
           t1i = d[i+5] + d[i+7];
           t3r = d[i+4] - d[i+6];
           t3i = d[i+5] - d[i+7];
           d[i] = (tr + t1r) * fnorm;
           d[i+1] = (ti + t1i) * fnorm;
           d[i+4] = (tr - t1r) * fnorm;
           d[i+5] = (ti - t1i) * fnorm;
           d[i+2] = (t2r - t3i) * fnorm;
           d[i+3] = (t2i + t3r) * fnorm;
           d[i+6] = (t2r + t3i) * fnorm;
           d[i+7] = (t2i - t3r) * fnorm;
       }
       lstep = 16;
       stepi = ldd >> 4;
   }

   lstep2 = lstep >> 1;
   nn = (ldd/lstep) >> 1;

   for (nstep=4; nstep <= *kj; nstep = nstep+2) {
       i1 = lstep + lstep2;
       i = 0;
       iw = 0;
       for (k=nn; k > 0; k--) {
           tr = d[i] + d[i+lstep2];
           ti = d[i+1] + d[i+lstep2+1];
           t2r = d[i] - d[i+lstep2];
           t2i = d[i+1] - d[i+lstep2+1];
           t1r = d[i+lstep] + d[i+i1];
           t1i = d[i+lstep+1] + d[i+i1+1];
           t3r = d[i+lstep] - d[i+i1];
           t3i = d[i+lstep+1] - d[i+i1+1];
           d[i] = tr + t1r;
           d[i+1] = ti + t1i;
           d[i+lstep] = tr - t1r;
           d[i+lstep+1] = ti - t1i;
           d[i+lstep2] = t2r - t3i;
           d[i+lstep2+1] = t2i + t3r;
           d[i+i1] = t2r + t3i;
           d[i+i1+1] = t2i - t3r;

           i = i + (lstep<<1);
       }

       iw = iw + stepi;
       for (i0 = 2; i0 < lstep2; i0 = i0 + 2) {
           i = i0;
           for (k = nn; k > 0; k--) {
               t1r = d[i+lstep2] * w[iw+step1w] + d[i+lstep2+1] * w[iw+step1w+1];
               t1i = -d[i+lstep2] * w[iw+step1w+1] + d[i+lstep2+1] * w[iw+step1w];
               tr = d[i] + t1r;
               ti = d[i+1] + t1i;
               t1r = d[i] - t1r;
               t1i = d[i+1] - t1i;
               t3r = d[i+i1] * w[iw+step2w] + d[i+i1+1] * w[iw+step2w+1];
               t3i = -d[i+i1] * w[iw+step2w+1] + d[i+i1+1] * w[iw+step2w];
               t2r = d[i+lstep] * w[iw] + d[i+lstep+1] * w[iw+1];
               t2i = -d[i+lstep] * w[iw+1] + d[i+lstep+1] * w[iw];
               twr = t2r + t3r;
               twi = t2i + t3i;
               d[i] = tr + twr;
               d[i+1] = ti + twi;
               d[i+lstep] = tr - twr;
               d[i+lstep+1] = ti - twi;
               tr = t2r - t3r;
               ti = t2i - t3i;
               d[i+lstep2] = t1r - ti;
               d[i+lstep2+1] = t1i + tr;
               d[i+i1] = t1r + ti;
               d[i+i1+1] = t1i - tr;

               i = i + (lstep<<1);
           }
           iw = iw+stepi;
       }
       nn = nn >> 2;
       lstep = lstep << 2;
       lstep2 = lstep2 << 2;
       lstep4 = lstep4 << 2;
       stepi = stepi >> 2;
   }
   return;
}

void COEF4R22_ZS(int* k, double* w) {
/*
* --- Function: coefhz
* ---        Compute the table of twiddle factors for
* ---        the forward/inverse radix2 FFT (double precision)
* ---        for seguential case
* --- Function: bittaz
* ---        Compute the integer table for bit-reverse
*/
   int n, i, j, t, s, kj;
   double fi, tfi;
   double E1=1.0, E8=8.0;
   int cache_L1 = 9;
   int cache_L2 = 13;
   int*   wint;
   mkl_intp intadr;

   n = 1 << (*k);

   w[0] = (double)n;
   w[1] = 0.0;
   if (*k <= 1) return;

   fi = E8 * atan(E1)/(double)n;
   tfi = fi;
   s = n >> 2;

         for( i = 1; i < s; i++){
             w[i*2]   =  cos(tfi);
             w[i*2+1] = -sin(tfi);
			 tfi += fi;
         }
         j = 2;
         for( i = s+1; i < s+s; i++){
             w[i*2]   =  w[j]*w[j] - w[j+1]*w[j+1];
             w[i*2+1] = w[j]*w[j+1]*2;
             j = j+2;
         }
         j = 2;
         t = s+s+2;
         for( i = s+s+1; i < s+s+s; i++){
             w[i*2]   =  w[j]*w[t] - w[j+1]*w[t+1];
             w[i*2+1] = w[j]*w[t+1] + w[t]*w[j+1];
             j = j+2;
             t = t+2;
         }
          s = n;

    intadr =(mkl_intp)&w[s*2];
    wint =(int*) intadr;
    bittazs(wint, n);
}

      void bittazs(int* x, int n){
      int  j,i,k,kk;
/*     -- Bit-reverse shuffle */
      j = 1;
      kk = 0;
      for(i=1; i <= (n-1); i++){
         if (i < j){
            kk += 2;
            x[kk] = (i-1)*2;
            x[kk+1] = (j-1)*2;
         }
         k =  n >> 1;
M1:      if (j > k){
            j = j-k;
            k = k >> 1;
            goto M1;
		 }
         j = j+k;
      }
      x[0]=0;
/*      x[1]=kk/2; */
      x[1]=kk;
      return;
}   /*   end  */

void ZBITREVSS(double* d, int* n, int * isign, double* wint) {

    int    i, j1, j2, k;
    double  t;
    int*   w;
    mkl_intp intadr;

    if (*n <= 2) return;
    k = *n << 2;
    intadr =(mkl_intp)wint;
    w =(int*) intadr;
 
    for (i=k+2; i < k+2+w[k+1]; i = i+2) {
	    j1 = w[i];
        j2=  w[i+1];
        t = d[j1];
        d[j1] = d[j2];
        d[j2] = t;
        t = d[j1+1];
        d[j1+1] = d[j2+1];
        d[j2+1] = t;
	}
    return;
}

