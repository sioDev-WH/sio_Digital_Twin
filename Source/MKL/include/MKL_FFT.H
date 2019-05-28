/*
//               INTEL CORPORATION PROPRIETARY INFORMATION
//  This software is supplied under the terms of a license agreement or
//  nondisclosure agreement with Intel Corporation and may not be copied
//  or disclosed except in accordance with the terms of that agreement.
//    Copyright (c) 1999, 2000 Intel Corporation. All Rights Reserved.
//
// File    : mkl_fft.h
// Purpose : MKL FFT interface
// Author  : 
*/

#ifndef __mkl_fft_h__
#define __mkl_fft_h__


#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */



void   CFFT1D(float* ar,  int* m, int* isign, float* ws);
void   ZFFT1D(double* ar, int* m, int* isign, double* ws);
void   CSFFT1D(float* r,  int* m, int* isign, float* ws);
void   SCFFT1D(float* r,  int* m, int* isign, float* ws);
void   ZDFFT1D(double* r, int* m, int* isign, double* ws);
void   DZFFT1D(double* r, int* m, int* isign, double* ws);
void   CFFT1DC(float* ar, float* ai, int m, int isign, float* ws);
void   ZFFT1DC(double* ar, double* ai, int m, int isign, double* ws);
void   CSFFT1DC(float* r,  int m, int isign, float* ws);
void   SCFFT1DC(float* r,  int m, int isign, float* ws);
void   ZDFFT1DC(double* r, int m, int isign, double* ws);
void   DZFFT1DC(double* r, int m, int isign, double* ws);
void   CFFT2D(float* ar,  int* m, int* n, int* isign);
void   ZFFT2D(double* ar, int* m, int* n, int* isign);
void   CSFFT2D(float* r,  int* m, int* n);
void   SCFFT2D(float* r,  int* m, int* n);
void   ZDFFT2D(double* r, int* m, int* n);
void   DZFFT2D(double* r, int* m, int* n);
void   CFFT2DC(float* ar, float* ai, int m, int n, int isign);
void   ZFFT2DC(double* ar, double* ai, int m, int n, int isign);
void   CSFFT2DC(float* r, int m, int n);
void   SCFFT2DC(float* r, int m, int n);
void   ZDFFT2DC(double* r, int m, int n);
void   DZFFT2DC(double* r, int m, int n);

#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif /* __mkl_fft_h__ */
