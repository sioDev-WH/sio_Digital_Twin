/*
//               INTEL CORPORATION PROPRIETARY INFORMATION
//  This software is supplied under the terms of a license agreement or
//  nondisclosure agreement with Intel Corporation and may not be copied
//  or disclosed except in accordance with the terms of that agreement.
//    Copyright (C) 1996-2000 Intel Corporation. All Rights Reserved.
//
// File    : vml/functions.h
// Purpose : VML header. (Linux version)
// Author  : Gilev Andrey
*/

#ifndef __VML_FUNCTIONS_H__
#define __VML_FUNCTIONS_H__

#include "mkl_vml_types.h"


/*******************************************************************************
  Math functions
*******************************************************************************/

/* Inversion: r = 1.0 / a                                                 */
__VML_API(void,VSINV,(int * , const float  a[], float  r[]))
__VML_API(void,VDINV,(int * , const double a[], double r[]))
__vml_api(void, vsinv, ( int * , const float  a[], float  r[] ))
__vml_api(void, vdinv, ( int * , const double a[], double r[] ))
__Vml_Api(void, vsInv, ( int , const float  a[], float  r[] ))
__Vml_Api(void, vdInv, ( int , const double a[], double r[] ))

/* Square root: r = a**0.5                                                */
__VML_API(void, VSSQRT, ( int * , const float  a[], float  r[] ))
__VML_API(void, VDSQRT, ( int * , const double a[], double r[] ))
__vml_api(void, vssqrt, ( int * , const float  a[], float  r[] ))
__vml_api(void, vdsqrt, ( int * , const double a[], double r[] ))
__Vml_Api(void, vsSqrt, ( int , const float  a[], float  r[] ))
__Vml_Api(void, vdSqrt, ( int , const double a[], double r[] ))

/* Inversion Square root: r = 1/a**0.5                                                */
__VML_API(void, VSINVSQRT, ( int * , const float  a[], float  r[] ))
__VML_API(void, VDINVSQRT, ( int * , const double a[], double r[] ))
__vml_api(void, vsinvsqrt, ( int * , const float  a[], float  r[] ))
__vml_api(void, vdinvsqrt, ( int * , const double a[], double r[] ))
__Vml_Api(void, vsInvSqrt, ( int , const float  a[], float  r[] ))
__Vml_Api(void, vdInvSqrt, ( int , const double a[], double r[] ))

/* Cube root: r = a**0.3(3)                                                */
__VML_API(void, VSCBRT, ( int * , const float  a[], float  r[] ))
__VML_API(void, VDCBRT, ( int * , const double a[], double r[] ))
__vml_api(void, vscbrt, ( int * , const float  a[], float  r[] ))
__vml_api(void, vdcbrt, ( int * , const double a[], double r[] ))
__Vml_Api(void, vsCbrt, ( int , const float  a[], float  r[] ))
__Vml_Api(void, vdCbrt, ( int , const double a[], double r[] ))

/* Inversion Cube root: r = 1/a**0.3(3)                                                */
__VML_API(void, VSINVCBRT, ( int * , const float  a[], float  r[] ))
__VML_API(void, VDINVCBRT, ( int * , const double a[], double r[] ))
__vml_api(void, vsinvcbrt, ( int * , const float  a[], float  r[] ))
__vml_api(void, vdinvcbrt, ( int * , const double a[], double r[] ))
__Vml_Api(void, vsInvCbrt, ( int , const float  a[], float  r[] ))
__Vml_Api(void, vdInvCbrt, ( int , const double a[], double r[] ))

/* Exponent: r = e**a                                                     */
__VML_API(void, VSEXP, ( int * , const float  a[], float  r[] ))
__VML_API(void, VDEXP, ( int * , const double a[], double r[] ))
__vml_api(void, vsexp, ( int * , const float  a[], float  r[] ))
__vml_api(void, vdexp, ( int * , const double a[], double r[] ))
__Vml_Api(void, vsExp, ( int , const float  a[], float  r[] ))
__Vml_Api(void, vdExp, ( int , const double a[], double r[] ))

/* Logarithm: r = ln a                                                    */
__VML_API(void, VSLN, ( int * , const float  a[], float  r[] ))
__VML_API(void, VDLN, ( int * , const double a[], double r[] ))
__vml_api(void, vsln, ( int * , const float  a[], float  r[] ))
__vml_api(void, vdln, ( int * , const double a[], double r[] ))
__Vml_Api(void, vsLn, ( int , const float  a[], float  r[] ))
__Vml_Api(void, vdLn, ( int , const double a[], double r[] ))

/* Decimal logarithm: r = lg a                                            */
__VML_API(void, VSLOG10, ( int * , const float  a[], float  r[] ))
__VML_API(void, VDLOG10, ( int * , const double a[], double r[] ))
__vml_api(void, vslog10, ( int * , const float  a[], float  r[] ))
__vml_api(void, vdlog10, ( int * , const double a[], double r[] ))
__Vml_Api(void, vsLog10, ( int , const float  a[], float  r[] ))
__Vml_Api(void, vdLog10, ( int , const double a[], double r[] ))

/* Sin: r = SIN a                                                         */
__VML_API(void, VSSIN, ( int * , const float  a[], float  r[] ))
__VML_API(void, VDSIN, ( int * , const double a[], double r[] ))
__vml_api(void, vssin, ( int * , const float  a[], float  r[] ))
__vml_api(void, vdsin, ( int * , const double a[], double r[] ))
__Vml_Api(void, vsSin, ( int , const float  a[], float  r[] ))
__Vml_Api(void, vdSin, ( int , const double a[], double r[] ))

/* Cos: r = COS a                                                         */
__VML_API(void, VSCOS, ( int * , const float  a[], float  r[] ))
__VML_API(void, VDCOS, ( int * , const double a[], double r[] ))
__vml_api(void, vscos, ( int * , const float  a[], float  r[] ))
__vml_api(void, vdcos, ( int * , const double a[], double r[] ))
__Vml_Api(void, vsCos, ( int , const float  a[], float  r[] ))
__Vml_Api(void, vdCos, ( int , const double a[], double r[] ))

/* Tan: r = tan a                                                         */
__VML_API(void, VSTAN, ( int * , const float  a[], float  r[] ))
__VML_API(void, VDTAN, ( int * , const double a[], double r[] ))
__vml_api(void, vstan, ( int * , const float  a[], float  r[] ))
__vml_api(void, vdtan, ( int * , const double a[], double r[] ))
__Vml_Api(void, vsTan, ( int , const float  a[], float  r[] ))
__Vml_Api(void, vdTan, ( int , const double a[], double r[] ))

/* Sinh: r = sh a                                                         */
__VML_API(void, VSSINH, ( int * , const float  a[], float  r[] ))
__VML_API(void, VDSINH, ( int * , const double a[], double r[] ))
__vml_api(void, vssinh, ( int * , const float  a[], float  r[] ))
__vml_api(void, vdsinh, ( int * , const double a[], double r[] ))
__Vml_Api(void, vsSinh, ( int , const float  a[], float  r[] ))
__Vml_Api(void, vdSinh, ( int , const double a[], double r[] ))

/* Cosh: r = ch a                                                         */
__VML_API(void, VSCOSH, ( int * , const float  a[], float  r[] ))
__VML_API(void, VDCOSH, ( int * , const double a[], double r[] ))
__vml_api(void, vscosh, ( int * , const float  a[], float  r[] ))
__vml_api(void, vdcosh, ( int * , const double a[], double r[] ))
__Vml_Api(void, vsCosh, ( int , const float  a[], float  r[] ))
__Vml_Api(void, vdCosh, ( int , const double a[], double r[] ))

/* Tanh: r = th a                                                         */
__VML_API(void, VSTANH, ( int * , const float  a[], float  r[] ))
__VML_API(void, VDTANH, ( int * , const double a[], double r[] ))
__vml_api(void, vstanh, ( int * , const float  a[], float  r[] ))
__vml_api(void, vdtanh, ( int * , const double a[], double r[] ))
__Vml_Api(void, vsTanh, ( int , const float  a[], float  r[] ))
__Vml_Api(void, vdTanh, ( int , const double a[], double r[] ))

/* ACOS: r = arcCOS a                                                     */
__VML_API(void, VSACOS, ( int * , const float  a[], float  r[] ))
__VML_API(void, VDACOS, ( int * , const double a[], double r[] ))
__vml_api(void, vsacos, ( int * , const float  a[], float  r[] ))
__vml_api(void, vdacos, ( int * , const double a[], double r[] ))
__Vml_Api(void, vsAcos, ( int , const float  a[], float  r[] ))
__Vml_Api(void, vdAcos, ( int , const double a[], double r[] ))

/* ASIN: r = arcSIN a                                                     */
__VML_API(void, VSASIN, ( int * , const float  a[], float  r[] ))
__VML_API(void, VDASIN, ( int * , const double a[], double r[] ))
__vml_api(void, vsasin, ( int * , const float  a[], float  r[] ))
__vml_api(void, vdasin, ( int * , const double a[], double r[] ))
__Vml_Api(void, vsAsin, ( int , const float  a[], float  r[] ))
__Vml_Api(void, vdAsin, ( int , const double a[], double r[] ))

/* Atan: r = arctan a                                                     */
__VML_API(void, VSATAN, ( int * , const float  a[], float  r[] ))
__VML_API(void, VDATAN, ( int * , const double a[], double r[] ))
__vml_api(void, vsatan, ( int * , const float  a[], float  r[] ))
__vml_api(void, vdatan, ( int * , const double a[], double r[] ))
__Vml_Api(void, vsAtan, ( int , const float  a[], float  r[] ))
__Vml_Api(void, vdAtan, ( int , const double a[], double r[] ))

/* ACOSH: r = arcCH a                                                     */
__VML_API(void, VSACOSH, ( int * , const float  a[], float  r[] ))
__VML_API(void, VDACOSH, ( int * , const double a[], double r[] ))
__vml_api(void, vsacosh, ( int * , const float  a[], float  r[] ))
__vml_api(void, vdacosh, ( int * , const double a[], double r[] ))
__Vml_Api(void, vsAcosh, ( int , const float  a[], float  r[] ))
__Vml_Api(void, vdAcosh, ( int , const double a[], double r[] ))

/* ASINH: r = arcSH a                                                     */
__VML_API(void, VSASINH, ( int * , const float  a[], float  r[] ))
__VML_API(void, VDASINH, ( int * , const double a[], double r[] ))
__vml_api(void, vsasinh, ( int * , const float  a[], float  r[] ))
__vml_api(void, vdasinh, ( int * , const double a[], double r[] ))
__Vml_Api(void, vsAsinh, ( int , const float  a[], float  r[] ))
__Vml_Api(void, vdAsinh, ( int , const double a[], double r[] ))

/* AtanH: r = arcTH a                                                     */
__VML_API(void, VSATANH, ( int * , const float  a[], float  r[] ))
__VML_API(void, VDATANH, ( int * , const double a[], double r[] ))
__vml_api(void, vsatanh, ( int * , const float  a[], float  r[] ))
__vml_api(void, vdatanh, ( int * , const double a[], double r[] ))
__Vml_Api(void, vsAtanh, ( int , const float  a[], float  r[] ))
__Vml_Api(void, vdAtanh, ( int , const double a[], double r[] ))

/* Atan2: r = arctan a / b                                                */
__VML_API(void, VSATAN2, ( int * , const float  a[], const float  b[], float  r[] ))
__VML_API(void, VDATAN2, ( int * , const double a[], const double b[], double r[] ))
__vml_api(void, vsatan2, ( int * , const float  a[], const float  b[], float  r[] ))
__vml_api(void, vdatan2, ( int * , const double a[], const double b[], double r[] ))
__Vml_Api(void, vsAtan2, ( int , const float  a[], const float  b[], float  r[] ))
__Vml_Api(void, vdAtan2, ( int , const double a[], const double b[], double r[] ))

/* Division: r = a / b                                                    */
__VML_API(void, VSDIV, ( int * , const float  a[], const float  b[], float  r[] ))
__VML_API(void, VDDIV, ( int * , const double a[], const double b[], double r[] ))
__vml_api(void, vsdiv, ( int * , const float  a[], const float  b[], float  r[] ))
__vml_api(void, vddiv, ( int * , const double a[], const double b[], double r[] ))
__Vml_Api(void, vsDiv, ( int , const float  a[], const float  b[], float  r[] ))
__Vml_Api(void, vdDiv, ( int , const double a[], const double b[], double r[] ))

/* Power: r = a**b                                                        */
__VML_API(void, VSPOW, ( int * , const float  a[], const float  b[], float  r[] ))
__VML_API(void, VDPOW, ( int * , const double a[], const double b[], double r[] ))
__vml_api(void, vspow, ( int * , const float  a[], const float  b[], float  r[] ))
__vml_api(void, vdpow, ( int * , const double a[], const double b[], double r[] ))
__Vml_Api(void, vsPow, ( int , const float  a[], const float  b[], float  r[] ))
__Vml_Api(void, vdPow, ( int , const double a[], const double b[], double r[] ))

/* SinCos: r = SIN a r1=COS a                                             */
__VML_API(void, VSSINCOS, ( int * , const float  a[], float  r1[], float  r2[] ))
__VML_API(void, VDSINCOS, ( int * , const double a[], double r1[], double r2[] ))
__vml_api(void, vssincos, ( int * , const float  a[], float  r1[], float  r2[] ))
__vml_api(void, vdsincos, ( int * , const double a[], double r1[], double r2[] ))
__Vml_Api(void, vsSinCos, ( int , const float  a[], float  r1[], float  r2[] ))
__Vml_Api(void, vdSinCos, ( int , const double a[], double r1[], double r2[] ))

/*******************************************************************************
  Pack/Unpack functions
*******************************************************************************/

__VML_API(void, VSPACKI, ( int * , const float  a[], int * incra, float  y[]    ))
__VML_API(void, VDPACKI, ( int * , const double a[], int * incra, double y[]    ))
__VML_API(void, VSPACKV, ( int * , const float  a[], const int ia[], float  y[] ))
__VML_API(void, VDPACKV, ( int * , const double a[], const int ia[], double y[] ))
__VML_API(void, VSPACKM, ( int * , const float  a[], const int ma[], float  y[] ))
__VML_API(void, VDPACKM, ( int * , const double a[], const int ma[], double y[] ))
__vml_api(void, vspacki, ( int * , const float  a[], int * incra, float  y[]    ))
__vml_api(void, vdpacki, ( int * , const double a[], int * incra, double y[]    ))
__vml_api(void, vspackv, ( int * , const float  a[], const int ia[], float  y[] ))
__vml_api(void, vdpackv, ( int * , const double a[], const int ia[], double y[] ))
__vml_api(void, vspackm, ( int * , const float  a[], const int ma[], float  y[] ))
__vml_api(void, vdpackm, ( int * , const double a[], const int ma[], double y[] ))
__Vml_Api(void, vsPackI, ( int , const float  a[], int incra, float  y[]    ))
__Vml_Api(void, vdPackI, ( int , const double a[], int incra, double y[]    ))
__Vml_Api(void, vsPackV, ( int , const float  a[], const int ia[], float  y[] ))
__Vml_Api(void, vdPackV, ( int , const double a[], const int ia[], double y[] ))
__Vml_Api(void, vsPackM, ( int , const float  a[], const int ma[], float  y[] ))
__Vml_Api(void, vdPackM, ( int , const double a[], const int ma[], double y[] ))

__VML_API(void, VSUNPACKI, ( int * , const float  a[], float  y[], int * incry    ))
__VML_API(void, VDUNPACKI, ( int * , const double a[], double y[], int * incry    ))
__VML_API(void, VSUNPACKV, ( int * , const float  a[], float  y[], const int iy[] ))
__VML_API(void, VDUNPACKV, ( int * , const double a[], double y[], const int iy[] ))
__VML_API(void, VSUNPACKM, ( int * , const float  a[], float  y[], const int my[] ))
__VML_API(void, VDUNPACKM, ( int * , const double a[], double y[], const int my[] ))
__vml_api(void, vsunpacki, ( int * , const float  a[], float  y[], int * incry    ))
__vml_api(void, vdunpacki, ( int * , const double a[], double y[], int * incry    ))
__vml_api(void, vsunpackv, ( int * , const float  a[], float  y[], const int iy[] ))
__vml_api(void, vdunpackv, ( int * , const double a[], double y[], const int iy[] ))
__vml_api(void, vsunpackm, ( int * , const float  a[], float  y[], const int my[] ))
__vml_api(void, vdunpackm, ( int * , const double a[], double y[], const int my[] ))
__Vml_Api(void, vsUnpackI, ( int , const float  a[], float  y[], int incry    ))
__Vml_Api(void, vdUnpackI, ( int , const double a[], double y[], int incry    ))
__Vml_Api(void, vsUnpackV, ( int , const float  a[], float  y[], const int iy[] ))
__Vml_Api(void, vdUnpackV, ( int , const double a[], double y[], const int iy[] ))
__Vml_Api(void, vsUnpackM, ( int , const float  a[], float  y[], const int my[] ))
__Vml_Api(void, vdUnpackM, ( int , const double a[], double y[], const int my[] ))

/*******************************************************************************
  Errors functions
*******************************************************************************/

/* Declared in "errors.h" */

/*******************************************************************************
  Mode functions
*******************************************************************************/

/* Declared in "mode.h" */

/*******************************************************************************
  Version functions
*******************************************************************************/

/* Declared in "version.h" */


#endif /* __VML_FUNCTIONS_H__ */

/* End of file */
