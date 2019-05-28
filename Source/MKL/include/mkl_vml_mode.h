/*
//               INTEL CORPORATION PROPRIETARY INFORMATION
//  This software is supplied under the terms of a license agreement or
//  nondisclosure agreement with Intel Corporation and may not be copied
//  or disclosed except in accordance with the terms of that agreement.
//    Copyright (C) 1996-2000 Intel Corporation. All Rights Reserved.
//
// File   : vml/mode.h
// Purpose: VML header (Windows version)
// Author : Gilev Andrey, Kolesov Andrey
*/

#ifndef __VML_MODE_H__
#define __VML_MODE_H__

#include "mkl_vml_errors.h"


/* Defines for accuracy setting LA or HA */
#define VML_LA                          0x001
#define VML_HA                          0x002

/* Defines for precision setting mode (to set or not to set :0)) */
#define VML_DEFAULT_PRECISION           0x000
#define VML_FLOAT_CONSISTENT            0x010
#define VML_DOUBLE_CONSISTENT           0x020
#define VML_RESTORE                     0x030

/* Defines for error modes  */
#define VML_ERRMODE_IGNORE              0x0100
#define VML_ERRMODE_ERRNO               0x0200
#define VML_ERRMODE_STDERR              0x0400
#define VML_ERRMODE_EXCEPT              0x0800
#define VML_ERRMODE_CALLBACK            0x1000
#define VML_ERRMODE_DEFAULT             VML_ERRMODE_ERRNO | VML_ERRMODE_CALLBACK | VML_ERRMODE_EXCEPT

/* Mask for accuracy setting separation */
#define VML_ACCURACY_MASK               0x000f
/* Mask for precision setting separation */
#define VML_FPUMODE_MASK                0x00f0
/* Mask for error mode separation */
#define VML_ERRMODE_MASK                0xff00

/*F---------------------------------------------------------------------------*/
/*    Name:       vmlSetMode                                                  */
/*    Purpose:    Set VML library mode                                        */
/*    Context:                                                                */
/*    Parameters:                                                             */
/*    Returns:                                                                */
/*    Notes:                                                                  */
/*F---------------------------------------------------------------------------*/
__VML_API(unsigned int, VMLSETMODE, (unsigned int * newmode));
__vml_api(unsigned int, vmlsetmode, (unsigned int * newmode));
__Vml_Api(unsigned int, vmlSetMode, (unsigned int newmode));
/*F---------------------------------------------------------------------------*/
/*    Name:       vmlGetMode                                                  */
/*    Purpose:    Get VML library mode                                        */
/*    Context:                                                                */
/*    Parameters:                                                             */
/*    Returns:                                                                */
/*    Notes:                                                                  */
/*F---------------------------------------------------------------------------*/
__VML_API(unsigned int, VMLGETMODE, ());
__vml_api(unsigned int, vmlgetmode, ());
__Vml_Api(unsigned int, vmlGetMode, ());


#endif /* __VML_MODE_H__ */

/* End of file */
