/*
*M
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
*      Fortran-style aligned supporting functions for FFT1 test 
*
*  Author  : Sivolgina O.
*M
*/

#include <windows.h>
#include <stdlib.h>
#include "fft_test.h"
      
void MKL_ALIGNING( double* A, int* bound, int* c_index, int* z_index )
{
/*
*  Purpose
*  =======
*
*  mkl_aligning returns indexes of complex*8  and complex*16 elements 
*                               which are aligned on defined boundary
*
*  Arguments
*  =========
*
*  A         (input)  COMPLEX*8 - input array
*  bound     (input)  INTEGER   - aligning in bytes from cache boundary
*  c_index   (output) INTEGER   - index of complex*8  element 
*                                 which is aligned on defined boundary
*  z_index   (output) INTEGER   - index of complex*16 element 
*                                 which is aligned on defined boundary
*/
    //  Local variables

    mkl_intp int_addr;
    mkl_intp tmp;
    mkl_intp diff;
 
    int index=0;
   
    int_addr = (mkl_intp)&A[index];
    
    tmp  = int_addr >> ALIGN_ORDER;
    
    diff = (1 << ALIGN_ORDER) - (int_addr - tmp * (1 << ALIGN_ORDER));

    if(diff != 0)
        index = diff >> 3;

    index += (*bound) >> 3;

    *c_index = index + 1;
    *z_index = (index >> 1) + 1;

    return;
}/* mkl_aligning */


void MKL_ITOA(double* c_array, unsigned int* len, char* Text, unsigned int lenText)
/*
*  Purpose
*  =======
*
*     mkl_itoa converts array address into string 
*              and returns pointer to this string
*  Arguments
*  =========
*
*  c_array   (input)  COMPLEX*8 - input array
*  text      (output) INTEGER   - pointer to string
*/
{
    mkl_intp int_addr;
    int i;

    int_addr = (mkl_intp)&c_array[0];
    itoa(int_addr, Text, 16);

    i=0;
    *len = strlen(Text);
    
	return;
}/* mkl_print */


