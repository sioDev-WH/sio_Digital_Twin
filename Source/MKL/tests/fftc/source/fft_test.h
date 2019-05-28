/*
//               INTEL CORPORATION PROPRIETARY INFORMATION
//  This software is supplied under the terms of a license agreement or
//  nondisclosure agreement with Intel Corporation and may not be copied
//  or disclosed except in accordance with the terms of that agreement.
//    Copyright (c) 1999, 2000 Intel Corporation. All Rights Reserved.
//
// File    : fft_test.h
// Purpose : MKL FFT constants
// Author  : Sivolgina Olga, Mustaeva Nadya
*/

#ifndef __fft_test_h__
#define __fft_test_h__

#ifdef ia64
#include "fft_test_ia64.h"
#else
#include "fft_test_ia32.h"
#endif

#endif /* __fft_test_h__ */
