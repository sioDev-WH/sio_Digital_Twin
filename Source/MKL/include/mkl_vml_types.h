/*
//               INTEL CORPORATION PROPRIETARY INFORMATION
//  This software is supplied under the terms of a license agreement or
//  nondisclosure agreement with Intel Corporation and may not be copied
//  or disclosed except in accordance with the terms of that agreement.
//    Copyright (C) 1996-2000 Intel Corporation. All Rights Reserved.
//
// File    : vml_types.h
// Purpose : VML. Data types (Windows version)
// Author  : Gilev Andrey, Nezhdanov Lev
*/

#ifndef __VML_TYPES_H__
#define __VML_TYPES_H__


/* Complex type (single precision). */
typedef
struct _vml_sComplex_t {
    float    re;
    float    im;
} vml_sComplex_t;


/* Complex type (double precision). */
typedef
struct _vml_dComplex_t {
    double    re;
    double    im;
} vml_dComplex_t;


#endif /* __VML_TYPES_H__ */

/* End of file */
