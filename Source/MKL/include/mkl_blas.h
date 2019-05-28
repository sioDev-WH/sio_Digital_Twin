/*
//               INTEL CORPORATION PROPRIETARY INFORMATION
//  This software is supplied under the terms of a license agreement or
//  nondisclosure agreement with Intel Corporation and may not be copied
//  or disclosed except in accordance with the terms of that agreement.
//    Copyright (c) 1999, 2000 Intel Corporation. All Rights Reserved.
//
// File    : mkl_blas.h
// Purpose : MKL BLAS interface
// Author  : Shemyakin Andrey
*/

#ifndef _MKL_BLAS_H_
#define _MKL_BLAS_H_

#include "mkl_types.h"

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */


/* BLAS Level1 */

float SASUM(int *n,float *x,int *incx);
void  SAXPY(int *n,float *alpha,float *x,int *incx,float *y,int *incy);
void  SAXPYI(int *nz,float *a,float *x,int *indx,float *y);
float SCASUM(int *n,MKL_Complex8 *x,int *incx); 
float SCNRM2(int *n,MKL_Complex8 *x,int *incx); 
void  SCOPY(int *n,float *x,int *incx,float *y,int *incy);
float SDOT(int *n,float *x,int *incx,float *y,int *incy);
float SDOTI(int *nz,float *x,int *indx,float *y);
void  SGTHR(int *nz,float *y,float *x,int *indx);
void  SGTHRZ(int *nz,float *y,float *x,int *indx);
float SNRM2(int *n,float *x,int *incx);
void  SROT(int *n,float *x,int *incx,float *y,int *incy,float *c,float *s);
void  SROTG(float *a,float *b,float *c,float *s);
void  SROTI(int *nz,float *x,int *indx,float *y,float *c,float *s);
void  SROTM(int *n,float *x,int *incx,float *y,int *incy,float *param);
void  SROTMG(float *d1,float *d2,float *x1,float *y1,float *param);
void  SSCAL(int *n,float *a,float *x,int *incx);
void  SSCTR(int *nz,float *x,int *indx,float *y);
void  SSWAP(int *n,float *x,int *incx,float *y,int *incy);
int   ISAMAX(int *n,float *x,int *incx);
int   ISAMIN(int *n,float *x,int *incx);

void CAXPY(int *n,MKL_Complex8 *alpha,MKL_Complex8 *x,int *incx,MKL_Complex8 *y,int *incy); 
void CAXPYI(int *nz,MKL_Complex8 *a,MKL_Complex8 *x,int *indx,MKL_Complex8 *y); 
void CCOPY(int *n,MKL_Complex8 *x,int *incx,MKL_Complex8 *y,int *incy); 
void CDOTC(MKL_Complex8 *pres,int *n,MKL_Complex8 *x,int *incx,MKL_Complex8 *y,int *incy); 
void CDOTCI(MKL_Complex8 *pres,int *nz,MKL_Complex8 *x,int *indx,MKL_Complex8 *y); 
void CDOTU(MKL_Complex8 *pres,int *n,MKL_Complex8 *x,int *incx,MKL_Complex8 *y,int *incy); 
void CDOTUI(MKL_Complex8 *pres,int *nz,MKL_Complex8 *x,int *indx,MKL_Complex8 *y); 
void CGTHR(int *nz,MKL_Complex8 *y,MKL_Complex8 *x,int *indx); 
void CGTHRZ(int *nz,MKL_Complex8 *y,MKL_Complex8 *x,int *indx); 
void CROTG(MKL_Complex8 *a,MKL_Complex8 *b,float *c,MKL_Complex8 *s); 
void CSCAL(int *n,MKL_Complex8 *a,MKL_Complex8 *x,int *incx); 
void CSCTR(int *nz,MKL_Complex8 *x,int *indx,MKL_Complex8 *y); 
void CSROT(int *n,MKL_Complex8 *x,int *incx,MKL_Complex8 *y,int *incy,float *c,float *s); 
void CSSCAL(int *n,float *a,MKL_Complex8 *x,int *incx); 
void CSWAP(int *n,MKL_Complex8 *x,int *incx,MKL_Complex8 *y,int *incy); 
int  ICAMAX(int *n,MKL_Complex8 *x,int *incx); 
int  ICAMIN(int *n,MKL_Complex8 *x,int *incx); 

double DASUM(int *n,double *x,int *incx);
void   DAXPY(int *n,double *alpha,double *x,int *incx,double *y,int *incy);
void   DAXPYI(int *nz,double *a,double *x,int *indx,double *y);
void   DCOPY(int *n,double *x,int *incx,double *y,int *incy);
double DDOT(int *n,double *x,int *incx,double *y,int *incy);
double DDOTI(int *nz,double *x,int *indx,double *y);
void   DGTHR(int *nz,double *y,double *x,int *indx);
void   DGTHRZ(int *nz,double *y,double *x,int *indx);
double DNRM2(int *n,double *x,int *incx);
void   DROT(int *n,double *x,int *incx,double *y,int *incy,double *c,double *s);
void   DROTG(double *a,double *b,double *c,double *s);
void   DROTI(int *nz,double *x,int *indx,double *y,double *c,double *s);
void   DROTM(int *n,double *x,int *incx,double *y,int *incy,double *param);
void   DROTMG(double *d1,double *d2,double *x1,double *y1,double *param);
void   DSCAL(int *n,double *a,double *x,int *incx);
void   DSCTR(int *nz,double *x,int *indx,double *y);
void   DSWAP(int *n,double *x,int *incx,double *y,int *incy);
double DZASUM(int *n,MKL_Complex16 *x,int *incx); 
double DZNRM2(int *n,MKL_Complex16 *x,int *incx); 
int    IDAMAX(int *n,double *x,int *incx);
int    IDAMIN(int *n,double *x,int *incx);

void ZAXPY(int *n,MKL_Complex16 *alpha,MKL_Complex16 *x,int *incx,MKL_Complex16 *y,int *incy); 
void ZAXPYI(int *nz,MKL_Complex16 *a,MKL_Complex16 *x,int *indx,MKL_Complex16 *y); 
void ZCOPY(int *n,MKL_Complex16 *x,int *incx,MKL_Complex16 *y,int *incy); 
void ZDOTC(MKL_Complex16 *pres,int *n,MKL_Complex16 *x,int *incx,MKL_Complex16 *y,int *incy); 
void ZDOTCI(MKL_Complex16 *pres,int *nz,MKL_Complex16 *x,int *indx,MKL_Complex16 *y); 
void ZDOTU(MKL_Complex16 *pres,int *n,MKL_Complex16 *x,int *incx,MKL_Complex16 *y,int *incy); 
void ZDOTUI(MKL_Complex16 *pres,int *nz,MKL_Complex16 *x,int *indx,MKL_Complex16 *y); 
void ZDROT(int *n,MKL_Complex16 *x,int *incx,MKL_Complex16 *y,int *incy,double *c,double *s); 
void ZDSCAL(int *n,double *a,MKL_Complex16 *x,int *incx); 
void ZGTHR(int *nz,MKL_Complex16 *y,MKL_Complex16 *x,int *indx); 
void ZGTHRZ(int *nz,MKL_Complex16 *y,MKL_Complex16 *x,int *indx); 
void ZROTG(MKL_Complex16 *a,MKL_Complex16 *b,double *c,MKL_Complex16 *s); 
void ZSCAL(int *n,MKL_Complex16 *a,MKL_Complex16 *x,int *incx); 
void ZSCTR(int *nz,MKL_Complex16 *x,int *indx,MKL_Complex16 *y); 
void ZSWAP(int *n,MKL_Complex16 *x,int *incx,MKL_Complex16 *y,int *incy); 
int  IZAMAX(int *n,MKL_Complex16 *x,int *incx); 
int  IZAMIN(int *n,MKL_Complex16 *x,int *incx); 

/* BLAS Level2 */

void SGBMV(char *trans,int *m,int *n,int *kl,int *ku,float *alpha,float *a,int *lda,float *x,int *incx,float *beta,float *y,int *incy);
void SGEMV(char *trans,int *m,int *n,float *alpha,float *a,int *lda,float *x,int *incx,float *beta,float *y,int *incy);
void SGER(int *m,int *n,float *alpha,float *x,int *incx,float *y,int *incy,float *a,int *lda);
void SSBMV(char *uplo,int *n,int *k,float *alpha,float *a,int *lda,float *x,int *incx,float *beta,float *y,int *incy);
void SSPMV(char *uplo,int *n,float *alpha,float *ap,float *x,int *incx,float *beta,float *y,int *incy);
void SSPR(char *uplo,int *n,float *alpha,float *x,int *incx,float *ap);
void SSPR2(char *uplo,int *n,float *alpha,float *x,int *incx,float *y,int *incy,float *ap);
void SSYMV(char *uplo,int *n,float *alpha,float *a,int *lda,float *x,int *incx,float *beta,float *y,int *incy);
void SSYR(char *uplo,int *n,float *alpha,float *x,int *incx,float *a,int *lda);
void SSYR2(char *uplo,int *n,float *alpha,float *x,int *incx,float *y,int *incy,float *a,int *lda);
void STBMV(char *uplo,char *trans,char *diag,int *n,int *k,float *a,int *lda,float *x,int *incx);
void STBSV(char *uplo,char *trans,char *diag,int *n,int *k,float *a,int *lda,float *x,int *incx);
void STPMV(char *uplo,char *trans,char *diag,int *n,float *ap,float *x,int *incx);
void STPSV(char *uplo,char *trans,char *diag,int *n,float *ap,float *x,int *incx);
void STRMV(char *uplo,char *transa,char *diag,int *n,float *a,int *lda,float *b,int *incx);
void STRSV(char *uplo,char *trans,char *diag,int *n,float *a,int *lda,float *x,int *incx);

void CGBMV(char *trans,int *m,int *n,int *kl,int *ku,MKL_Complex8 *alpha,MKL_Complex8 *a,int *lda,MKL_Complex8 *x,int *incx,MKL_Complex8 *beta,MKL_Complex8 *y,int *incy); 
void CGEMV(char *trans,int *m,int *n,MKL_Complex8 *alpha,MKL_Complex8 *a,int *lda,MKL_Complex8 *x,int *incx,MKL_Complex8 *beta,MKL_Complex8 *y,int *incy); 
void CGERC(int *m,int *n,MKL_Complex8 *alpha,MKL_Complex8 *x,int *incx,MKL_Complex8 *y,int *incy,MKL_Complex8 *a,int *lda); 
void CGERU(int *m,int *n,MKL_Complex8 *alpha,MKL_Complex8 *x,int *incx,MKL_Complex8 *y,int *incy,MKL_Complex8 *a,int *lda); 
void CHBMV(char *uplo,int *n,int *k,MKL_Complex8 *alpha,MKL_Complex8 *a,int *lda,MKL_Complex8 *x,int *incx,MKL_Complex8 *beta,MKL_Complex8 *y,int *incy); 
void CHEMV(char *uplo,int *n,MKL_Complex8 *alpha,MKL_Complex8 *a,int *lda,MKL_Complex8 *x,int *incx,MKL_Complex8 *beta,MKL_Complex8 *y,int *incy); 
void CHER(char *uplo,int *n,float *alpha,MKL_Complex8 *x,int *incx,MKL_Complex8 *a,int *lda); 
void CHER2(char *uplo,int *n,MKL_Complex8 *alpha,MKL_Complex8 *x,int *incx,MKL_Complex8 *y,int *incy,MKL_Complex8 *a,int *lda); 
void CHPMV(char *uplo,int *n,MKL_Complex8 *alpha,MKL_Complex8 *ap,MKL_Complex8 *x,int *incx,MKL_Complex8 *beta,MKL_Complex8 *y,int *incy); 
void CHPR(char *uplo,int *n,float *alpha,MKL_Complex8 *x,int *incx,MKL_Complex8 *ap); 
void CHPR2(char *uplo,int *n,MKL_Complex8 *alpha,MKL_Complex8 *x,int *incx,MKL_Complex8 *y,int *incy,MKL_Complex8 *ap); 
void CTBMV(char *uplo,char *trans,char *diag,int *n,int *k,MKL_Complex8 *a,int *lda,MKL_Complex8 *x,int *incx); 
void CTBSV(char *uplo,char *trans,char *diag,int *n,int *k,MKL_Complex8 *a,int *lda,MKL_Complex8 *x,int *incx); 
void CTPMV(char *uplo,char *trans,char *diag,int *n,MKL_Complex8 *ap,MKL_Complex8 *x,int *incx); 
void CTPSV(char *uplo,char *trans,char *diag,int *n,MKL_Complex8 *ap,MKL_Complex8 *x,int *incx); 
void CTRMV(char *uplo,char *transa,char *diag,int *n,MKL_Complex8 *a,int *lda,MKL_Complex8 *b,int *incx); 
void CTRSV(char *uplo,char *trans,char *diag,int *n,MKL_Complex8 *a,int *lda,MKL_Complex8 *x,int *incx); 

void DGBMV(char *trans,int *m,int *n,int *kl,int *ku,double *alpha,double *a,int *lda,double *x,int *incx,double *beta,double *y,int *incy);
void DGEMV(char *trans,int *m,int *n,double *alpha,double *a,int *lda,double *x,int *incx,double *beta,double *y,int *incy);
void DGER(int *m,int *n,double *alpha,double *x,int *incx,double *y,int *incy,double *a,int *lda);
void DSBMV(char *uplo,int *n,int *k,double *alpha,double *a,int *lda,double *x,int *incx,double *beta,double *y,int *incy);
void DSPMV(char *uplo,int *n,double *alpha,double *ap,double *x,int *incx,double *beta,double *y,int *incy);
void DSPR(char *uplo,int *n,double *alpha,double *x,int *incx,double *ap);
void DSPR2(char *uplo,int *n,double *alpha,double *x,int *incx,double *y,int *incy,double *ap);
void DSYMV(char *uplo,int *n,double *alpha,double *a,int *lda,double *x,int *incx,double *beta,double *y,int *incy);
void DSYR(char *uplo,int *n,double *alpha,double *x,int *incx,double *a,int *lda);
void DSYR2(char *uplo,int *n,double *alpha,double *x,int *incx,double *y,int *incy,double *a,int *lda);
void DTBMV(char *uplo,char *trans,char *diag,int *n,int *k,double *a,int *lda,double *x,int *incx);
void DTBSV(char *uplo,char *trans,char *diag,int *n,int *k,double *a,int *lda,double *x,int *incx);
void DTPMV(char *uplo,char *trans,char *diag,int *n,double *ap,double *x,int *incx);
void DTPSV(char *uplo,char *trans,char *diag,int *n,double *ap,double *x,int *incx);
void DTRMV(char *uplo,char *transa,char *diag,int *n,double *a,int *lda,double *b,int *incx);
void DTRSV(char *uplo,char *trans,char *diag,int *n,double *a,int *lda,double *x,int *incx);

void ZGBMV(char *trans,int *m,int *n,int *kl,int *ku,MKL_Complex16 *alpha,MKL_Complex16 *a,int *lda,MKL_Complex16 *x,int *incx,MKL_Complex16 *beta,MKL_Complex16 *y,int *incy); 
void ZGEMV(char *trans,int *m,int *n,MKL_Complex16 *alpha,MKL_Complex16 *a,int *lda,MKL_Complex16 *x,int *incx,MKL_Complex16 *beta,MKL_Complex16 *y,int *incy); 
void ZGERC(int *m,int *n,MKL_Complex16 *alpha,MKL_Complex16 *x,int *incx,MKL_Complex16 *y,int *incy,MKL_Complex16 *a,int *lda); 
void ZGERU(int *m,int *n,MKL_Complex16 *alpha,MKL_Complex16 *x,int *incx,MKL_Complex16 *y,int *incy,MKL_Complex16 *a,int *lda); 
void ZHBMV(char *uplo,int *n,int *k,MKL_Complex16 *alpha,MKL_Complex16 *a,int *lda,MKL_Complex16 *x,int *incx,MKL_Complex16 *beta,MKL_Complex16 *y,int *incy); 
void ZHEMV(char *uplo,int *n,MKL_Complex16 *alpha,MKL_Complex16 *a,int *lda,MKL_Complex16 *x,int *incx,MKL_Complex16 *beta,MKL_Complex16 *y,int *incy); 
void ZHER(char *uplo,int *n,double *alpha,MKL_Complex16 *x,int *incx,MKL_Complex16 *a,int *lda); 
void ZHER2(char *uplo,int *n,MKL_Complex16 *alpha,MKL_Complex16 *x,int *incx,MKL_Complex16 *y,int *incy,MKL_Complex16 *a,int *lda); 
void ZHPMV(char *uplo,int *n,MKL_Complex16 *alpha,MKL_Complex16 *ap,MKL_Complex16 *x,int *incx,MKL_Complex16 *beta,MKL_Complex16 *y,int *incy); 
void ZHPR(char *uplo,int *n,double *alpha,MKL_Complex16 *x,int *incx,MKL_Complex16 *ap); 
void ZHPR2(char *uplo,int *n,MKL_Complex16 *alpha,MKL_Complex16 *x,int *incx,MKL_Complex16 *y,int *incy,MKL_Complex16 *ap); 
void ZTBMV(char *uplo,char *trans,char *diag,int *n,int *k,MKL_Complex16 *a,int *lda,MKL_Complex16 *x,int *incx); 
void ZTBSV(char *uplo,char *trans,char *diag,int *n,int *k,MKL_Complex16 *a,int *lda,MKL_Complex16 *x,int *incx); 
void ZTPMV(char *uplo,char *trans,char *diag,int *n,MKL_Complex16 *ap,MKL_Complex16 *x,int *incx); 
void ZTPSV(char *uplo,char *trans,char *diag,int *n,MKL_Complex16 *ap,MKL_Complex16 *x,int *incx); 
void ZTRMV(char *uplo,char *transa,char *diag,int *n,MKL_Complex16 *a,int *lda,MKL_Complex16 *b,int *incx); 
void ZTRSV(char *uplo,char *trans,char *diag,int *n,MKL_Complex16 *a,int *lda,MKL_Complex16 *x,int *incx); 

/* BLAS Level3 */

void SGEMM(char *transa,char *transb,int *m,int *n,int *k,float *alpha,float *a,int *lda,float *b,int *ldb,float *beta,float *c,int *ldc);
void SSYMM(char *side,char *uplo,int *m,int *n,float *alpha,float *a,int *lda,float *b,int *ldb,float *beta,float *c,int *ldc);
void SSYR2K(char *uplo,char *trans,int *n,int *k,float *alpha,float *a,int *lda,float *b,int *ldb,float *beta,float *c,int *ldc);
void SSYRK(char *uplo,char *trans,int *n,int *k,float *alpha,float *a,int *lda,float *beta,float *c,int *ldc);
void STRMM(char *side,char *uplo,char *transa,char *diag,int *m,int *n,float *alpha,float *a,int *lda,float *b,int *ldb);
void STRSM(char *side,char *uplo,char *transa,char *diag,int *m,int *n,float *alpha,float *a,int *lda,float *b,int *ldb);

void CGEMM(char *transa,char *transb,int *m,int *n,int *k,MKL_Complex8 *alpha,MKL_Complex8 *a,int *lda,MKL_Complex8 *b,int *ldb,MKL_Complex8 *beta,MKL_Complex8 *c,int *ldc); 
void CHEMM(char *side,char *uplo,int *m,int *n,MKL_Complex8 *alpha,MKL_Complex8 *a,int *lda,MKL_Complex8 *b,int *ldb,MKL_Complex8 *beta,MKL_Complex8 *c,int *ldc); 
void CHER2K(char *uplo,char *trans,int *n,int *k,MKL_Complex8 *alpha,MKL_Complex8 *a,int *lda,MKL_Complex8 *b,int *ldb,float *beta,MKL_Complex8 *c,int *ldc); 
void CHERK(char *uplo,char *trans,int *n,int *k,float *alpha,MKL_Complex8 *a,int *lda,float *beta,MKL_Complex8 *c,int *ldc); 
void CSYMM(char *side,char *uplo,int *m,int *n,MKL_Complex8 *alpha,MKL_Complex8 *a,int *lda,MKL_Complex8 *b,int *ldb,MKL_Complex8 *beta,MKL_Complex8 *c,int *ldc); 
void CSYR2K(char *uplo,char *trans,int *n,int *k,MKL_Complex8 *alpha,MKL_Complex8 *a,int *lda,MKL_Complex8 *b,int *ldb,MKL_Complex8 *beta,MKL_Complex8 *c,int *ldc); 
void CSYRK(char *uplo,char *trans,int *n,int *k,MKL_Complex8 *alpha,MKL_Complex8 *a,int *lda,MKL_Complex8 *beta,MKL_Complex8 *c,int *ldc); 
void CTRMM(char *side,char *uplo,char *transa,char *diag,int *m,int *n,MKL_Complex8 *alpha,MKL_Complex8 *a,int *lda,MKL_Complex8 *b,int *ldb); 
void CTRSM(char *side,char *uplo,char *transa,char *diag,int *m,int *n,MKL_Complex8 *alpha,MKL_Complex8 *a,int *lda,MKL_Complex8 *b,int *ldb); 

void DGEMM(char *transa,char *transb,int *m,int *n,int *k,double *alpha,double *a,int *lda,double *b,int *ldb,double *beta,double *c,int *ldc);
void DSYMM(char *side,char *uplo,int *m,int *n,double *alpha,double *a,int *lda,double *b,int *ldb,double *beta,double *c,int *ldc);
void DSYR2K(char *uplo,char *trans,int *n,int *k,double *alpha,double *a,int *lda,double *b,int *ldb,double *beta,double *c,int *ldc);
void DSYRK(char *uplo,char *trans,int *n,int *k,double *alpha,double *a,int *lda,double *beta,double *c,int *ldc);
void DTRMM(char *side,char *uplo,char *transa,char *diag,int *m,int *n,double *alpha,double *a,int *lda,double *b,int *ldb);
void DTRSM(char *side,char *uplo,char *transa,char *diag,int *m,int *n,double *alpha,double *a,int *lda,double *b,int *ldb);

void ZGEMM(char *transa,char *transb,int *m,int *n,int *k,MKL_Complex16 *alpha,MKL_Complex16 *a,int *lda,MKL_Complex16 *b,int *ldb,MKL_Complex16 *beta,MKL_Complex16 *c,int *ldc); 
void ZGEMM(char *transa,char *transb,int *m,int *n,int *k,MKL_Complex16 *alpha,MKL_Complex16 *a,int *lda,MKL_Complex16 *b,int *ldb,MKL_Complex16 *beta,MKL_Complex16 *c,int *ldc); 
void ZHEMM(char *side,char *uplo,int *m,int *n,MKL_Complex16 *alpha,MKL_Complex16 *a,int *lda,MKL_Complex16 *b,int *ldb,MKL_Complex16 *beta,MKL_Complex16 *c,int *ldc); 
void ZHER2K(char *uplo,char *trans,int *n,int *k,MKL_Complex16 *alpha,MKL_Complex16 *a,int *lda,MKL_Complex16 *b,int *ldb,double *beta,MKL_Complex16 *c,int *ldc); 
void ZHERK(char *uplo,char *trans,int *n,int *k,double *alpha,MKL_Complex16 *a,int *lda,double *beta,MKL_Complex16 *c,int *ldc); 
void ZSYMM(char *side,char *uplo,int *m,int *n,MKL_Complex16 *alpha,MKL_Complex16 *a,int *lda,MKL_Complex16 *b,int *ldb,MKL_Complex16 *beta,MKL_Complex16 *c,int *ldc); 
void ZSYR2K(char *uplo,char *trans,int *n,int *k,MKL_Complex16 *alpha,MKL_Complex16 *a,int *lda,MKL_Complex16 *b,int *ldb,MKL_Complex16 *beta,MKL_Complex16 *c,int *ldc); 
void ZSYRK(char *uplo,char *trans,int *n,int *k,MKL_Complex16 *alpha,MKL_Complex16 *a,int *lda,MKL_Complex16 *beta,MKL_Complex16 *c,int *ldc); 
void ZTRMM(char *side,char *uplo,char *transa,char *diag,int *m,int *n,MKL_Complex16 *alpha,MKL_Complex16 *a,int *lda,MKL_Complex16 *b,int *ldb); 
void ZTRSM(char *side,char *uplo,char *transa,char *diag,int *m,int *n,MKL_Complex16 *alpha,MKL_Complex16 *a,int *lda,MKL_Complex16 *b,int *ldb); 

/* MKL support */

void MKLGetVersion(MKLVersion *ver);
void MKLGetVersionString(char * buffer, int len);
void MKLStart(void);
void MKLEnd(void);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* _MKL_BLAS_H_ */
