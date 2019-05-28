/*
//               INTEL CORPORATION PROPRIETARY INFORMATION
//  This software is supplied under the terms of a license agreement or
//  nondisclosure agreement with Intel Corporation and may not be copied
//  or disclosed except in accordance with the terms of that agreement.
//    Copyright (C) 1996-2000 Intel Corporation. All Rights Reserved.
//
// File   : vml.h
// Purpose: VML header (Windows version)
// Author : Gilev Andrey, Nezhdanov Lev
*/

#ifndef __VML_H__
#define __VML_H__

#if defined(MKL_VML_CDECL)
#  define __VML_API(_VML_RET_TYPE,_VML_FUNC_NAME,_VML_FUNC_ARG) extern _VML_RET_TYPE __cdecl _VML_FUNC_NAME _VML_FUNC_ARG;
#  define __vml_api(_vml_ret_type,_vml_func_name,_vml_func_arg) extern _vml_ret_type __cdecl _vml_func_name _vml_func_arg;
#  define __Vml_Api(_Vml_Ret_Type,_Vml_Func_Name,_Vml_Func_Arg) extern _Vml_Ret_Type __cdecl _Vml_Func_Name _Vml_Func_Arg;
#elif defined(MKL_VML_STDCALL)
#  define __VML_API(_VML_RET_TYPE,_VML_FUNC_NAME,_VML_FUNC_ARG) extern _VML_RET_TYPE __stdcall _VML_FUNC_NAME _VML_FUNC_ARG;
#  define __vml_api(_vml_ret_type,_vml_func_name,_vml_func_arg) extern _vml_ret_type __stdcall _vml_func_name _vml_func_arg;
#  define __Vml_Api(_Vml_Ret_Type,_Vml_Func_Name,_Vml_Func_Arg) extern _Vml_Ret_Type __stdcall _Vml_Func_Name _Vml_Func_Arg;
#else
#  define __VML_API(_VML_RET_TYPE,_VML_FUNC_NAME,_VML_FUNC_ARG) extern _VML_RET_TYPE __cdecl _VML_FUNC_NAME _VML_FUNC_ARG;
#  define __vml_api(_vml_ret_type,_vml_func_name,_vml_func_arg) extern _vml_ret_type __cdecl _vml_func_name _vml_func_arg;
#  define __Vml_Api(_Vml_Ret_Type,_Vml_Func_Name,_Vml_Func_Arg) extern _Vml_Ret_Type __cdecl _Vml_Func_Name _Vml_Func_Arg;
#endif

#include "mkl_vml_types.h"
#include "mkl_vml_functions.h"
#include "mkl_vml_errors.h"
#include "mkl_vml_mode.h"


#endif /* __VML_H__ */

/* End of file */
