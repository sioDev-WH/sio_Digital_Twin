/*
//               INTEL CORPORATION PROPRIETARY INFORMATION
//  This software is supplied under the terms of a license agreement or
//  nondisclosure agreement with Intel Corporation and may not be copied
//  or disclosed except in accordance with the terms of that agreement.
//    Copyright (C) 1996-2000 Intel Corporation. All Rights Reserved.
//
// File   : errors.h
// Purpose: VML. Error-handling subsystem interface (Windows version)
// Author : Gilev Andrey, Kolesov Andrey, Lev Nezhdanov
*/

#ifndef __VML_ERRORS_H__
#define __VML_ERRORS_H__


/* Codes for vml?Error function call and errstatus */
#define VML_STATUS_OK                    0
#define VML_STATUS_BADSIZE              -1
#define VML_STATUS_BADMEM               -2
#define VML_STATUS_ERRDOM                1
#define VML_STATUS_SING                  2
#define VML_STATUS_OVERFLOW              3
#define VML_STATUS_UNDERFLOW             4

/* Mask for standard error handler modes separation*/
#define VML_ERRMODE_STDHANDLER_MASK       0x0f00
/* Mask for additional callback switch bit separation */
#define VML_ERRMODE_CALLBACK_MASK         0xf000

/* Type for error context structure (parameter for additional callback) */
typedef struct _DefVmlErrorContext
{ 
    int iCode; 
    int iIndex;
    double dbA1;
    double dbA2;
    double dbR1;
    double dbR2;
    char cFuncName[64];
    int  iFuncNameLen;
} DefVmlErrorContext;

/* Additional callback error handler function type */
typedef int (__stdcall *VMLErrorCallBack)  \
(DefVmlErrorContext* pdefVmlErrorContext);


/*F---------------------------------------------------------------------------*/
/*    Name:       vmlSetErrStatus                                             */
/*    Purpose:    Set the error status of VML library                         */
/*    Context:                                                                */
/*    Parameters:                                                             */
/*    Returns:                                                                */
/*    Notes:                                                                  */
/*F---------------------------------------------------------------------------*/
__VML_API(unsigned int,VMLSETERRSTATUS,(unsigned int * status));
__vml_api(unsigned int,vmlseterrstatus,(unsigned int * status));
__Vml_Api(unsigned int,vmlSetErrStatus,(unsigned int status));
/*F---------------------------------------------------------------------------*/
/*    Name:       vmlGetErrStatus                                             */
/*    Purpose:    Get the error status of VML library                         */
/*    Context:                                                                */
/*    Parameters:                                                             */
/*    Returns:                                                                */
/*    Notes:                                                                  */
/*F---------------------------------------------------------------------------*/
__VML_API(unsigned int, VMLGETERRSTATUS, ());
__vml_api(unsigned int, vmlgeterrstatus, ());
__Vml_Api(unsigned int, vmlGetErrStatus, ());
/*F---------------------------------------------------------------------------*/
/*    Name:       vmlClearErrStatus                                           */
/*    Purpose:    Clear the error status of VML library (set to OK)           */
/*    Context:                                                                */
/*    Parameters:                                                             */
/*    Returns:                                                                */
/*    Notes:                                                                  */
/*F---------------------------------------------------------------------------*/
__VML_API(unsigned int, VMLCLEARERRSTATUS, ());
__vml_api(unsigned int, vmlclearerrstatus, ());
__Vml_Api(unsigned int, vmlClearErrStatus, ());
/*F---------------------------------------------------------------------------*/
/*    Name:       vmlSetErrorCallBack                                         */
/*    Purpose:    Set additional error callback function                      */
/*    Context:                                                                */
/*    Parameters:                                                             */
/*    Returns:                                                                */
/*    Notes:                                                                  */
/*F---------------------------------------------------------------------------*/
__VML_API(VMLErrorCallBack, VMLSETERRORCALLBACK, (VMLErrorCallBack func));
__vml_api(VMLErrorCallBack, vmlseterrorcallback, (VMLErrorCallBack func));
__Vml_Api(VMLErrorCallBack, vmlSetErrorCallBack, (VMLErrorCallBack func));
/*F---------------------------------------------------------------------------*/
/*    Name:       vmlGetErrorCallBack                                         */
/*    Purpose:    Get additional error callback function                      */
/*    Context:                                                                */
/*    Parameters:                                                             */
/*    Returns:                                                                */
/*    Notes:                                                                  */
/*F---------------------------------------------------------------------------*/
__VML_API(VMLErrorCallBack, VMLGETERRORCALLBACK, ());
__vml_api(VMLErrorCallBack, vmlgeterrorcallback, ());
__Vml_Api(VMLErrorCallBack, vmlGetErrorCallBack, ());
/*F---------------------------------------------------------------------------*/
/*    Name:       vmlClearErrorCallBack                                       */
/*    Purpose:    Clear additional error callback function                    */
/*                                             (restore to default)           */
/*    Context:                                                                */
/*    Parameters:                                                             */
/*    Returns:                                                                */
/*    Notes:                                                                  */
/*F---------------------------------------------------------------------------*/
__VML_API(VMLErrorCallBack, VMLCLEARERRORCALLBACK, ());
__vml_api(VMLErrorCallBack, vmlclearerrorcallback, ());
__Vml_Api(VMLErrorCallBack, vmlClearErrorCallBack, ());


#endif /* __VML_ERRORS_H__ */

/* End of file. */
