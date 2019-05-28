/* this ALWAYS GENERATED file contains the proxy stub code */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Feb 10 17:14:38 2003
 */
/* Compiler settings for C:\DistComponents\RtsOnTransmission\RtsOnTransmission.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )

#define USE_STUBLESS_PROXY


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 440
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "RtsOnTransmission.h"

#define TYPE_FORMAT_STRING_SIZE   1047                              
#define PROC_FORMAT_STRING_SIZE   621                               

typedef struct _MIDL_TYPE_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ TYPE_FORMAT_STRING_SIZE ];
    } MIDL_TYPE_FORMAT_STRING;

typedef struct _MIDL_PROC_FORMAT_STRING
    {
    short          Pad;
    unsigned char  Format[ PROC_FORMAT_STRING_SIZE ];
    } MIDL_PROC_FORMAT_STRING;


extern const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString;
extern const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString;


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IOnChart, ver. 0.0,
   GUID={0xE4814F69,0x68C9,0x49AE,{0x82,0x92,0xB6,0xA5,0xAC,0x3A,0x3B,0x43}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IOnChart_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IOnChart_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    22,
    44,
    84,
    124,
    152,
    198,
    220,
    266,
    294
    };

static const MIDL_SERVER_INFO IOnChart_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IOnChart_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IOnChart_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IOnChart_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(17) _IOnChartProxyVtbl = 
{
    &IOnChart_ProxyInfo,
    &IID_IOnChart,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IOnChart::Show */ ,
    (void *)-1 /* IOnChart::Hide */ ,
    (void *)-1 /* IOnChart::initPlot */ ,
    (void *)-1 /* IOnChart::plotData */ ,
    (void *)-1 /* IOnChart::SetCaption */ ,
    (void *)-1 /* IOnChart::Move */ ,
    (void *)-1 /* IOnChart::cleanPlot */ ,
    (void *)-1 /* IOnChart::GetPosition */ ,
    (void *)-1 /* IOnChart::AddSeries */ ,
    (void *)-1 /* IOnChart::plotSeriesData */
};


static const PRPC_STUB_FUNCTION IOnChart_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IOnChartStubVtbl =
{
    &IID_IOnChart,
    &IOnChart_ServerInfo,
    17,
    &IOnChart_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: ICOnTestHarness, ver. 0.0,
   GUID={0x3669889E,0x81B0,0x4D6C,{0x92,0x30,0x10,0xFD,0x26,0x51,0x89,0xA5}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO ICOnTestHarness_ServerInfo;

#pragma code_seg(".orpc")
extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[2];

static const MIDL_STUB_DESC Object_StubDesc = 
    {
    0,
    NdrOleAllocate,
    NdrOleFree,
    0,
    0,
    0,
    0,
    0,
    __MIDL_TypeFormatString.Format,
    1, /* -error bounds_check flag */
    0x20000, /* Ndr library version */
    0,
    0x50100a4, /* MIDL Version 5.1.164 */
    0,
    UserMarshalRoutines,
    0,  /* notify & notify_flag routine table */
    1,  /* Flags */
    0,  /* Reserved3 */
    0,  /* Reserved4 */
    0   /* Reserved5 */
    };

static const unsigned short ICOnTestHarness_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    22,
    328,
    356,
    378,
    406,
    434,
    474,
    508,
    536,
    564,
    592
    };

static const MIDL_SERVER_INFO ICOnTestHarness_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &ICOnTestHarness_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO ICOnTestHarness_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &ICOnTestHarness_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(19) _ICOnTestHarnessProxyVtbl = 
{
    &ICOnTestHarness_ProxyInfo,
    &IID_ICOnTestHarness,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* ICOnTestHarness::runTest */ ,
    (void *)-1 /* ICOnTestHarness::init */ ,
    (void *)-1 /* ICOnTestHarness::tick */ ,
    (void *)-1 /* ICOnTestHarness::term */ ,
    (void *)-1 /* ICOnTestHarness::get_model */ ,
    (void *)-1 /* ICOnTestHarness::get_ModelExec */ ,
    (void *)-1 /* ICOnTestHarness::SetShiftTiming */ ,
    (void *)-1 /* ICOnTestHarness::SetShiftPeriod */ ,
    (void *)-1 /* ICOnTestHarness::SetThrottle */ ,
    (void *)-1 /* ICOnTestHarness::Load */ ,
    (void *)-1 /* ICOnTestHarness::Save */ ,
    (void *)-1 /* ICOnTestHarness::GetStates */
};


static const PRPC_STUB_FUNCTION ICOnTestHarness_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _ICOnTestHarnessStubVtbl =
{
    &IID_ICOnTestHarness,
    &ICOnTestHarness_ServerInfo,
    19,
    &ICOnTestHarness_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

#pragma data_seg(".rdata")

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[2] = 
        {
            
            {
            LPSAFEARRAY_UserSize
            ,LPSAFEARRAY_UserMarshal
            ,LPSAFEARRAY_UserUnmarshal
            ,LPSAFEARRAY_UserFree
            },
            {
            BSTR_UserSize
            ,BSTR_UserMarshal
            ,BSTR_UserUnmarshal
            ,BSTR_UserFree
            }

        };


#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT40_OR_LATER)
#error You need a Windows NT 4.0 or later to run this stub because it uses these features:
#error   -Oif or -Oicf, [wire_marshal] or [user_marshal] attribute, more than 64 delegated procs, float, double or hyper in -Oif or -Oicf, more than 32 methods in the interface.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure runTest */


	/* Procedure Show */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/*  8 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */


	/* Return value */

/* 16 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 18 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 20 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure init */


	/* Procedure Hide */

/* 22 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 24 */	NdrFcLong( 0x0 ),	/* 0 */
/* 28 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
/* 30 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 32 */	NdrFcShort( 0x0 ),	/* 0 */
/* 34 */	NdrFcShort( 0x8 ),	/* 8 */
/* 36 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */


	/* Return value */

/* 38 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 40 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 42 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure initPlot */

/* 44 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 46 */	NdrFcLong( 0x0 ),	/* 0 */
/* 50 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
/* 52 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 54 */	NdrFcShort( 0xe ),	/* 14 */
/* 56 */	NdrFcShort( 0x8 ),	/* 8 */
/* 58 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter numberOfSeries */

/* 60 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 62 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 64 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter vbPoint */

/* 66 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 68 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 70 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter SeriesNames */

/* 72 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
#ifndef _ALPHA_
/* 74 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 76 */	NdrFcShort( 0x3c0 ),	/* Type Offset=960 */

	/* Return value */

/* 78 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 80 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 82 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure plotData */

/* 84 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 86 */	NdrFcLong( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0xa ),	/* 10 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 92 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
#else
			NdrFcShort( 0x1c ),	/* MIPS & PPC Stack size/offset = 28 */
#endif
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 94 */	NdrFcShort( 0x18 ),	/* 24 */
/* 96 */	NdrFcShort( 0x8 ),	/* 8 */
/* 98 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x4,		/* 4 */

	/* Parameter time */

/* 100 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 102 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* MIPS & PPC Stack size/offset = 8 */
#endif
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 104 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter psaVals */

/* 106 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 108 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
#else
			NdrFcShort( 0x10 ),	/* MIPS & PPC Stack size/offset = 16 */
#endif
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 110 */	NdrFcShort( 0x3ce ),	/* Type Offset=974 */

	/* Parameter count */

/* 112 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 114 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
#else
			NdrFcShort( 0x14 ),	/* MIPS & PPC Stack size/offset = 20 */
#endif
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 118 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 120 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
#else
			NdrFcShort( 0x18 ),	/* MIPS & PPC Stack size/offset = 24 */
#endif
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 122 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetCaption */

/* 124 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 126 */	NdrFcLong( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0xb ),	/* 11 */
#ifndef _ALPHA_
/* 132 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 134 */	NdrFcShort( 0x0 ),	/* 0 */
/* 136 */	NdrFcShort( 0x8 ),	/* 8 */
/* 138 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter caption */

/* 140 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 142 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 144 */	NdrFcShort( 0x3dc ),	/* Type Offset=988 */

	/* Return value */

/* 146 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 148 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 150 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Move */

/* 152 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 154 */	NdrFcLong( 0x0 ),	/* 0 */
/* 158 */	NdrFcShort( 0xc ),	/* 12 */
#ifndef _ALPHA_
/* 160 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 162 */	NdrFcShort( 0x20 ),	/* 32 */
/* 164 */	NdrFcShort( 0x8 ),	/* 8 */
/* 166 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter x */

/* 168 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 170 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 172 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter y */

/* 174 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 176 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 178 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nWidth */

/* 180 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 182 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 184 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nHeight */

/* 186 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 188 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 190 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 192 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 194 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 196 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure cleanPlot */

/* 198 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 200 */	NdrFcLong( 0x0 ),	/* 0 */
/* 204 */	NdrFcShort( 0xd ),	/* 13 */
#ifndef _ALPHA_
/* 206 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 208 */	NdrFcShort( 0x0 ),	/* 0 */
/* 210 */	NdrFcShort( 0x8 ),	/* 8 */
/* 212 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 214 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 216 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 218 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetPosition */

/* 220 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 222 */	NdrFcLong( 0x0 ),	/* 0 */
/* 226 */	NdrFcShort( 0xe ),	/* 14 */
#ifndef _ALPHA_
/* 228 */	NdrFcShort( 0x18 ),	/* x86, MIPS, PPC Stack size/offset = 24 */
#else
			NdrFcShort( 0x30 ),	/* Alpha Stack size/offset = 48 */
#endif
/* 230 */	NdrFcShort( 0x20 ),	/* 32 */
/* 232 */	NdrFcShort( 0x28 ),	/* 40 */
/* 234 */	0x4,		/* Oi2 Flags:  has return, */
			0x5,		/* 5 */

	/* Parameter x */

/* 236 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
#ifndef _ALPHA_
/* 238 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 240 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter y */

/* 242 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
#ifndef _ALPHA_
/* 244 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 246 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nWidth */

/* 248 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
#ifndef _ALPHA_
/* 250 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 252 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter nHeight */

/* 254 */	NdrFcShort( 0x158 ),	/* Flags:  in, out, base type, simple ref, */
#ifndef _ALPHA_
/* 256 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 258 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 260 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 262 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 264 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure AddSeries */

/* 266 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 268 */	NdrFcLong( 0x0 ),	/* 0 */
/* 272 */	NdrFcShort( 0xf ),	/* 15 */
#ifndef _ALPHA_
/* 274 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 276 */	NdrFcShort( 0x0 ),	/* 0 */
/* 278 */	NdrFcShort( 0x8 ),	/* 8 */
/* 280 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter SeriesName */

/* 282 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 284 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 286 */	NdrFcShort( 0x3dc ),	/* Type Offset=988 */

	/* Return value */

/* 288 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 290 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 292 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure plotSeriesData */

/* 294 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 296 */	NdrFcLong( 0x0 ),	/* 0 */
/* 300 */	NdrFcShort( 0x10 ),	/* 16 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 302 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
#else
			NdrFcShort( 0x1c ),	/* MIPS & PPC Stack size/offset = 28 */
#endif
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 304 */	NdrFcShort( 0x20 ),	/* 32 */
/* 306 */	NdrFcShort( 0x8 ),	/* 8 */
/* 308 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter t */

/* 310 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 312 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* MIPS & PPC Stack size/offset = 8 */
#endif
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 314 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter val */

/* 316 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 318 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
#else
			NdrFcShort( 0x10 ),	/* MIPS & PPC Stack size/offset = 16 */
#endif
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 320 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 322 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 324 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
#else
			NdrFcShort( 0x18 ),	/* MIPS & PPC Stack size/offset = 24 */
#endif
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 326 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure tick */

/* 328 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 330 */	NdrFcLong( 0x0 ),	/* 0 */
/* 334 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 336 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
#else
			NdrFcShort( 0x14 ),	/* MIPS & PPC Stack size/offset = 20 */
#endif
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 338 */	NdrFcShort( 0x10 ),	/* 16 */
/* 340 */	NdrFcShort( 0x8 ),	/* 8 */
/* 342 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter t */

/* 344 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 346 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* MIPS & PPC Stack size/offset = 8 */
#endif
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 348 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 350 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 352 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
#else
			NdrFcShort( 0x10 ),	/* MIPS & PPC Stack size/offset = 16 */
#endif
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 354 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure term */

/* 356 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 358 */	NdrFcLong( 0x0 ),	/* 0 */
/* 362 */	NdrFcShort( 0xa ),	/* 10 */
#ifndef _ALPHA_
/* 364 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 366 */	NdrFcShort( 0x0 ),	/* 0 */
/* 368 */	NdrFcShort( 0x8 ),	/* 8 */
/* 370 */	0x4,		/* Oi2 Flags:  has return, */
			0x1,		/* 1 */

	/* Return value */

/* 372 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 374 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 376 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_model */

/* 378 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 380 */	NdrFcLong( 0x0 ),	/* 0 */
/* 384 */	NdrFcShort( 0xb ),	/* 11 */
#ifndef _ALPHA_
/* 386 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 388 */	NdrFcShort( 0x0 ),	/* 0 */
/* 390 */	NdrFcShort( 0x8 ),	/* 8 */
/* 392 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 394 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
#ifndef _ALPHA_
/* 396 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 398 */	NdrFcShort( 0x3ea ),	/* Type Offset=1002 */

	/* Return value */

/* 400 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 402 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 404 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ModelExec */

/* 406 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 408 */	NdrFcLong( 0x0 ),	/* 0 */
/* 412 */	NdrFcShort( 0xc ),	/* 12 */
#ifndef _ALPHA_
/* 414 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 416 */	NdrFcShort( 0x0 ),	/* 0 */
/* 418 */	NdrFcShort( 0x8 ),	/* 8 */
/* 420 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 422 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
#ifndef _ALPHA_
/* 424 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 426 */	NdrFcShort( 0x400 ),	/* Type Offset=1024 */

	/* Return value */

/* 428 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 430 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 432 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetShiftTiming */

/* 434 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 436 */	NdrFcLong( 0x0 ),	/* 0 */
/* 440 */	NdrFcShort( 0xd ),	/* 13 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 442 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
#else
			NdrFcShort( 0x1c ),	/* MIPS & PPC Stack size/offset = 28 */
#endif
#else
			NdrFcShort( 0x28 ),	/* Alpha Stack size/offset = 40 */
#endif
/* 444 */	NdrFcShort( 0x1e ),	/* 30 */
/* 446 */	NdrFcShort( 0x8 ),	/* 8 */
/* 448 */	0x4,		/* Oi2 Flags:  has return, */
			0x4,		/* 4 */

	/* Parameter bUp */

/* 450 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 452 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 454 */	0x6,		/* FC_SHORT */
			0x0,		/* 0 */

	/* Parameter iShift */

/* 456 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 458 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 460 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter val */

/* 462 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 464 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
#else
			NdrFcShort( 0x10 ),	/* MIPS & PPC Stack size/offset = 16 */
#endif
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 466 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 468 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 470 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
#else
			NdrFcShort( 0x18 ),	/* MIPS & PPC Stack size/offset = 24 */
#endif
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 472 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetShiftPeriod */

/* 474 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 476 */	NdrFcLong( 0x0 ),	/* 0 */
/* 480 */	NdrFcShort( 0xe ),	/* 14 */
#ifndef _ALPHA_
/* 482 */	NdrFcShort( 0x14 ),	/* x86, MIPS, PPC Stack size/offset = 20 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 484 */	NdrFcShort( 0x18 ),	/* 24 */
/* 486 */	NdrFcShort( 0x8 ),	/* 8 */
/* 488 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter iClutch */

/* 490 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 492 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 494 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Parameter val */

/* 496 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 498 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 500 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 502 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 504 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 506 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetThrottle */

/* 508 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 510 */	NdrFcLong( 0x0 ),	/* 0 */
/* 514 */	NdrFcShort( 0xf ),	/* 15 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 516 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
#else
			NdrFcShort( 0x14 ),	/* MIPS & PPC Stack size/offset = 20 */
#endif
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 518 */	NdrFcShort( 0x10 ),	/* 16 */
/* 520 */	NdrFcShort( 0x8 ),	/* 8 */
/* 522 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter throttle */

/* 524 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 526 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* MIPS & PPC Stack size/offset = 8 */
#endif
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 528 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 530 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 532 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
#else
			NdrFcShort( 0x10 ),	/* MIPS & PPC Stack size/offset = 16 */
#endif
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 534 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Load */

/* 536 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 538 */	NdrFcLong( 0x0 ),	/* 0 */
/* 542 */	NdrFcShort( 0x10 ),	/* 16 */
#ifndef _ALPHA_
/* 544 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 546 */	NdrFcShort( 0x0 ),	/* 0 */
/* 548 */	NdrFcShort( 0x8 ),	/* 8 */
/* 550 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter FileName */

/* 552 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 554 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 556 */	NdrFcShort( 0x3dc ),	/* Type Offset=988 */

	/* Return value */

/* 558 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 560 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 562 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Save */

/* 564 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 566 */	NdrFcLong( 0x0 ),	/* 0 */
/* 570 */	NdrFcShort( 0x11 ),	/* 17 */
#ifndef _ALPHA_
/* 572 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 574 */	NdrFcShort( 0x0 ),	/* 0 */
/* 576 */	NdrFcShort( 0x8 ),	/* 8 */
/* 578 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter FileName */

/* 580 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
/* 582 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 584 */	NdrFcShort( 0x3dc ),	/* Type Offset=988 */

	/* Return value */

/* 586 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 588 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 590 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure GetStates */

/* 592 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 594 */	NdrFcLong( 0x0 ),	/* 0 */
/* 598 */	NdrFcShort( 0x12 ),	/* 18 */
#ifndef _ALPHA_
/* 600 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 602 */	NdrFcShort( 0x0 ),	/* 0 */
/* 604 */	NdrFcShort( 0x8 ),	/* 8 */
/* 606 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter states */

/* 608 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
#ifndef _ALPHA_
/* 610 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 612 */	NdrFcShort( 0x3ce ),	/* Type Offset=974 */

	/* Return value */

/* 614 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 616 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 618 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

			0x0
        }
    };

static const MIDL_TYPE_FORMAT_STRING __MIDL_TypeFormatString =
    {
        0,
        {
			NdrFcShort( 0x0 ),	/* 0 */
/*  2 */	
			0x11, 0x0,	/* FC_RP */
/*  4 */	NdrFcShort( 0x3bc ),	/* Offset= 956 (960) */
/*  6 */	
			0x12, 0x10,	/* FC_UP */
/*  8 */	NdrFcShort( 0x2 ),	/* Offset= 2 (10) */
/* 10 */	
			0x12, 0x0,	/* FC_UP */
/* 12 */	NdrFcShort( 0x3a2 ),	/* Offset= 930 (942) */
/* 14 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 16 */	NdrFcShort( 0x18 ),	/* 24 */
/* 18 */	NdrFcShort( 0xa ),	/* 10 */
/* 20 */	NdrFcLong( 0x8 ),	/* 8 */
/* 24 */	NdrFcShort( 0x6c ),	/* Offset= 108 (132) */
/* 26 */	NdrFcLong( 0xd ),	/* 13 */
/* 30 */	NdrFcShort( 0x9e ),	/* Offset= 158 (188) */
/* 32 */	NdrFcLong( 0x9 ),	/* 9 */
/* 36 */	NdrFcShort( 0xcc ),	/* Offset= 204 (240) */
/* 38 */	NdrFcLong( 0xc ),	/* 12 */
/* 42 */	NdrFcShort( 0x292 ),	/* Offset= 658 (700) */
/* 44 */	NdrFcLong( 0x24 ),	/* 36 */
/* 48 */	NdrFcShort( 0x2ba ),	/* Offset= 698 (746) */
/* 50 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 54 */	NdrFcShort( 0x2d6 ),	/* Offset= 726 (780) */
/* 56 */	NdrFcLong( 0x10 ),	/* 16 */
/* 60 */	NdrFcShort( 0x2ee ),	/* Offset= 750 (810) */
/* 62 */	NdrFcLong( 0x2 ),	/* 2 */
/* 66 */	NdrFcShort( 0x306 ),	/* Offset= 774 (840) */
/* 68 */	NdrFcLong( 0x3 ),	/* 3 */
/* 72 */	NdrFcShort( 0x31e ),	/* Offset= 798 (870) */
/* 74 */	NdrFcLong( 0x14 ),	/* 20 */
/* 78 */	NdrFcShort( 0x336 ),	/* Offset= 822 (900) */
/* 80 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (79) */
/* 82 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 84 */	NdrFcShort( 0x2 ),	/* 2 */
/* 86 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 88 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 90 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 92 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 94 */	NdrFcShort( 0x8 ),	/* 8 */
/* 96 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (82) */
/* 98 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 100 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 102 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 104 */	NdrFcShort( 0x4 ),	/* 4 */
/* 106 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 108 */	NdrFcShort( 0x0 ),	/* 0 */
/* 110 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 112 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 114 */	NdrFcShort( 0x4 ),	/* 4 */
/* 116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 118 */	NdrFcShort( 0x1 ),	/* 1 */
/* 120 */	NdrFcShort( 0x0 ),	/* 0 */
/* 122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 124 */	0x12, 0x0,	/* FC_UP */
/* 126 */	NdrFcShort( 0xffffffde ),	/* Offset= -34 (92) */
/* 128 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 130 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 132 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 134 */	NdrFcShort( 0x8 ),	/* 8 */
/* 136 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 138 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 140 */	NdrFcShort( 0x4 ),	/* 4 */
/* 142 */	NdrFcShort( 0x4 ),	/* 4 */
/* 144 */	0x11, 0x0,	/* FC_RP */
/* 146 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (102) */
/* 148 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 150 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 152 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 154 */	NdrFcLong( 0x0 ),	/* 0 */
/* 158 */	NdrFcShort( 0x0 ),	/* 0 */
/* 160 */	NdrFcShort( 0x0 ),	/* 0 */
/* 162 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 164 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 166 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 168 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 170 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 172 */	NdrFcShort( 0x0 ),	/* 0 */
/* 174 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 176 */	NdrFcShort( 0x0 ),	/* 0 */
/* 178 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 182 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 184 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (152) */
/* 186 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 188 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 190 */	NdrFcShort( 0x8 ),	/* 8 */
/* 192 */	NdrFcShort( 0x0 ),	/* 0 */
/* 194 */	NdrFcShort( 0x6 ),	/* Offset= 6 (200) */
/* 196 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 198 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 200 */	
			0x11, 0x0,	/* FC_RP */
/* 202 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (170) */
/* 204 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 206 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 210 */	NdrFcShort( 0x0 ),	/* 0 */
/* 212 */	NdrFcShort( 0x0 ),	/* 0 */
/* 214 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 216 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 218 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 220 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 222 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 226 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 230 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 234 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 236 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (204) */
/* 238 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 240 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 242 */	NdrFcShort( 0x8 ),	/* 8 */
/* 244 */	NdrFcShort( 0x0 ),	/* 0 */
/* 246 */	NdrFcShort( 0x6 ),	/* Offset= 6 (252) */
/* 248 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 250 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 252 */	
			0x11, 0x0,	/* FC_RP */
/* 254 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (222) */
/* 256 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 258 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 260 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 262 */	NdrFcShort( 0x2 ),	/* Offset= 2 (264) */
/* 264 */	NdrFcShort( 0x10 ),	/* 16 */
/* 266 */	NdrFcShort( 0x2b ),	/* 43 */
/* 268 */	NdrFcLong( 0x3 ),	/* 3 */
/* 272 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 274 */	NdrFcLong( 0x11 ),	/* 17 */
/* 278 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 280 */	NdrFcLong( 0x2 ),	/* 2 */
/* 284 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 286 */	NdrFcLong( 0x4 ),	/* 4 */
/* 290 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 292 */	NdrFcLong( 0x5 ),	/* 5 */
/* 296 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 298 */	NdrFcLong( 0xb ),	/* 11 */
/* 302 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 304 */	NdrFcLong( 0xa ),	/* 10 */
/* 308 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 310 */	NdrFcLong( 0x6 ),	/* 6 */
/* 314 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (528) */
/* 316 */	NdrFcLong( 0x7 ),	/* 7 */
/* 320 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 322 */	NdrFcLong( 0x8 ),	/* 8 */
/* 326 */	NdrFcShort( 0xd0 ),	/* Offset= 208 (534) */
/* 328 */	NdrFcLong( 0xd ),	/* 13 */
/* 332 */	NdrFcShort( 0xffffff4c ),	/* Offset= -180 (152) */
/* 334 */	NdrFcLong( 0x9 ),	/* 9 */
/* 338 */	NdrFcShort( 0xffffff7a ),	/* Offset= -134 (204) */
/* 340 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 344 */	NdrFcShort( 0xc2 ),	/* Offset= 194 (538) */
/* 346 */	NdrFcLong( 0x24 ),	/* 36 */
/* 350 */	NdrFcShort( 0xc0 ),	/* Offset= 192 (542) */
/* 352 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 356 */	NdrFcShort( 0xba ),	/* Offset= 186 (542) */
/* 358 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 362 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (594) */
/* 364 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 368 */	NdrFcShort( 0xe6 ),	/* Offset= 230 (598) */
/* 370 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 374 */	NdrFcShort( 0xe4 ),	/* Offset= 228 (602) */
/* 376 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 380 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (606) */
/* 382 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 386 */	NdrFcShort( 0xe0 ),	/* Offset= 224 (610) */
/* 388 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 392 */	NdrFcShort( 0xce ),	/* Offset= 206 (598) */
/* 394 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 398 */	NdrFcShort( 0xcc ),	/* Offset= 204 (602) */
/* 400 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 404 */	NdrFcShort( 0xd2 ),	/* Offset= 210 (614) */
/* 406 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 410 */	NdrFcShort( 0xc8 ),	/* Offset= 200 (610) */
/* 412 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 416 */	NdrFcShort( 0xca ),	/* Offset= 202 (618) */
/* 418 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 422 */	NdrFcShort( 0xc8 ),	/* Offset= 200 (622) */
/* 424 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 428 */	NdrFcShort( 0xc6 ),	/* Offset= 198 (626) */
/* 430 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 434 */	NdrFcShort( 0xc4 ),	/* Offset= 196 (630) */
/* 436 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 440 */	NdrFcShort( 0xbe ),	/* Offset= 190 (630) */
/* 442 */	NdrFcLong( 0x10 ),	/* 16 */
/* 446 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 448 */	NdrFcLong( 0x12 ),	/* 18 */
/* 452 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 454 */	NdrFcLong( 0x13 ),	/* 19 */
/* 458 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 460 */	NdrFcLong( 0x16 ),	/* 22 */
/* 464 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 466 */	NdrFcLong( 0x17 ),	/* 23 */
/* 470 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 472 */	NdrFcLong( 0xe ),	/* 14 */
/* 476 */	NdrFcShort( 0x9e ),	/* Offset= 158 (634) */
/* 478 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 482 */	NdrFcShort( 0xa4 ),	/* Offset= 164 (646) */
/* 484 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 488 */	NdrFcShort( 0x6a ),	/* Offset= 106 (594) */
/* 490 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 494 */	NdrFcShort( 0x68 ),	/* Offset= 104 (598) */
/* 496 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 500 */	NdrFcShort( 0x66 ),	/* Offset= 102 (602) */
/* 502 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 506 */	NdrFcShort( 0x60 ),	/* Offset= 96 (602) */
/* 508 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 512 */	NdrFcShort( 0x5a ),	/* Offset= 90 (602) */
/* 514 */	NdrFcLong( 0x0 ),	/* 0 */
/* 518 */	NdrFcShort( 0x0 ),	/* Offset= 0 (518) */
/* 520 */	NdrFcLong( 0x1 ),	/* 1 */
/* 524 */	NdrFcShort( 0x0 ),	/* Offset= 0 (524) */
/* 526 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (525) */
/* 528 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 530 */	NdrFcShort( 0x8 ),	/* 8 */
/* 532 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 534 */	
			0x12, 0x0,	/* FC_UP */
/* 536 */	NdrFcShort( 0xfffffe44 ),	/* Offset= -444 (92) */
/* 538 */	
			0x12, 0x0,	/* FC_UP */
/* 540 */	NdrFcShort( 0x192 ),	/* Offset= 402 (942) */
/* 542 */	
			0x12, 0x0,	/* FC_UP */
/* 544 */	NdrFcShort( 0x1e ),	/* Offset= 30 (574) */
/* 546 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 548 */	NdrFcLong( 0x2f ),	/* 47 */
/* 552 */	NdrFcShort( 0x0 ),	/* 0 */
/* 554 */	NdrFcShort( 0x0 ),	/* 0 */
/* 556 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 558 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 560 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 562 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 564 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 566 */	NdrFcShort( 0x1 ),	/* 1 */
/* 568 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 570 */	NdrFcShort( 0x4 ),	/* 4 */
/* 572 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 574 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 576 */	NdrFcShort( 0x10 ),	/* 16 */
/* 578 */	NdrFcShort( 0x0 ),	/* 0 */
/* 580 */	NdrFcShort( 0xa ),	/* Offset= 10 (590) */
/* 582 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 584 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 586 */	NdrFcShort( 0xffffffd8 ),	/* Offset= -40 (546) */
/* 588 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 590 */	
			0x12, 0x0,	/* FC_UP */
/* 592 */	NdrFcShort( 0xffffffe4 ),	/* Offset= -28 (564) */
/* 594 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 596 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 598 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 600 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 602 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 604 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 606 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 608 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 610 */	
			0x12, 0x8,	/* FC_UP [simple_pointer] */
/* 612 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 614 */	
			0x12, 0x0,	/* FC_UP */
/* 616 */	NdrFcShort( 0xffffffa8 ),	/* Offset= -88 (528) */
/* 618 */	
			0x12, 0x10,	/* FC_UP */
/* 620 */	NdrFcShort( 0xffffffaa ),	/* Offset= -86 (534) */
/* 622 */	
			0x12, 0x10,	/* FC_UP */
/* 624 */	NdrFcShort( 0xfffffe28 ),	/* Offset= -472 (152) */
/* 626 */	
			0x12, 0x10,	/* FC_UP */
/* 628 */	NdrFcShort( 0xfffffe58 ),	/* Offset= -424 (204) */
/* 630 */	
			0x12, 0x10,	/* FC_UP */
/* 632 */	NdrFcShort( 0xffffffa2 ),	/* Offset= -94 (538) */
/* 634 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 636 */	NdrFcShort( 0x10 ),	/* 16 */
/* 638 */	0x6,		/* FC_SHORT */
			0x2,		/* FC_CHAR */
/* 640 */	0x2,		/* FC_CHAR */
			0x38,		/* FC_ALIGNM4 */
/* 642 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 644 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 646 */	
			0x12, 0x0,	/* FC_UP */
/* 648 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (634) */
/* 650 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 652 */	NdrFcShort( 0x20 ),	/* 32 */
/* 654 */	NdrFcShort( 0x0 ),	/* 0 */
/* 656 */	NdrFcShort( 0x0 ),	/* Offset= 0 (656) */
/* 658 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 660 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 662 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 664 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 666 */	NdrFcShort( 0xfffffe66 ),	/* Offset= -410 (256) */
/* 668 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 670 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 672 */	NdrFcShort( 0x4 ),	/* 4 */
/* 674 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 676 */	NdrFcShort( 0x0 ),	/* 0 */
/* 678 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 680 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 682 */	NdrFcShort( 0x4 ),	/* 4 */
/* 684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 686 */	NdrFcShort( 0x1 ),	/* 1 */
/* 688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 690 */	NdrFcShort( 0x0 ),	/* 0 */
/* 692 */	0x12, 0x0,	/* FC_UP */
/* 694 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (650) */
/* 696 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 698 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 700 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 702 */	NdrFcShort( 0x8 ),	/* 8 */
/* 704 */	NdrFcShort( 0x0 ),	/* 0 */
/* 706 */	NdrFcShort( 0x6 ),	/* Offset= 6 (712) */
/* 708 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 710 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 712 */	
			0x11, 0x0,	/* FC_RP */
/* 714 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (670) */
/* 716 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 718 */	NdrFcShort( 0x4 ),	/* 4 */
/* 720 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 722 */	NdrFcShort( 0x0 ),	/* 0 */
/* 724 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 726 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 728 */	NdrFcShort( 0x4 ),	/* 4 */
/* 730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 732 */	NdrFcShort( 0x1 ),	/* 1 */
/* 734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 736 */	NdrFcShort( 0x0 ),	/* 0 */
/* 738 */	0x12, 0x0,	/* FC_UP */
/* 740 */	NdrFcShort( 0xffffff5a ),	/* Offset= -166 (574) */
/* 742 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 744 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 746 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 748 */	NdrFcShort( 0x8 ),	/* 8 */
/* 750 */	NdrFcShort( 0x0 ),	/* 0 */
/* 752 */	NdrFcShort( 0x6 ),	/* Offset= 6 (758) */
/* 754 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 756 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 758 */	
			0x11, 0x0,	/* FC_RP */
/* 760 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (716) */
/* 762 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 764 */	NdrFcShort( 0x8 ),	/* 8 */
/* 766 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 768 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 770 */	NdrFcShort( 0x10 ),	/* 16 */
/* 772 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 774 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 776 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffff1 ),	/* Offset= -15 (762) */
			0x5b,		/* FC_END */
/* 780 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 782 */	NdrFcShort( 0x18 ),	/* 24 */
/* 784 */	NdrFcShort( 0x0 ),	/* 0 */
/* 786 */	NdrFcShort( 0xa ),	/* Offset= 10 (796) */
/* 788 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 790 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 792 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (768) */
/* 794 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 796 */	
			0x11, 0x0,	/* FC_RP */
/* 798 */	NdrFcShort( 0xfffffd8c ),	/* Offset= -628 (170) */
/* 800 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 802 */	NdrFcShort( 0x1 ),	/* 1 */
/* 804 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 806 */	NdrFcShort( 0x0 ),	/* 0 */
/* 808 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 810 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 812 */	NdrFcShort( 0x8 ),	/* 8 */
/* 814 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 816 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 818 */	NdrFcShort( 0x4 ),	/* 4 */
/* 820 */	NdrFcShort( 0x4 ),	/* 4 */
/* 822 */	0x12, 0x0,	/* FC_UP */
/* 824 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (800) */
/* 826 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 828 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 830 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 832 */	NdrFcShort( 0x2 ),	/* 2 */
/* 834 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 836 */	NdrFcShort( 0x0 ),	/* 0 */
/* 838 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 840 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 842 */	NdrFcShort( 0x8 ),	/* 8 */
/* 844 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 846 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 848 */	NdrFcShort( 0x4 ),	/* 4 */
/* 850 */	NdrFcShort( 0x4 ),	/* 4 */
/* 852 */	0x12, 0x0,	/* FC_UP */
/* 854 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (830) */
/* 856 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 858 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 860 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 862 */	NdrFcShort( 0x4 ),	/* 4 */
/* 864 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 866 */	NdrFcShort( 0x0 ),	/* 0 */
/* 868 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 870 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 872 */	NdrFcShort( 0x8 ),	/* 8 */
/* 874 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 876 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 878 */	NdrFcShort( 0x4 ),	/* 4 */
/* 880 */	NdrFcShort( 0x4 ),	/* 4 */
/* 882 */	0x12, 0x0,	/* FC_UP */
/* 884 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (860) */
/* 886 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 888 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 890 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 892 */	NdrFcShort( 0x8 ),	/* 8 */
/* 894 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 896 */	NdrFcShort( 0x0 ),	/* 0 */
/* 898 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 900 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 902 */	NdrFcShort( 0x8 ),	/* 8 */
/* 904 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 906 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 908 */	NdrFcShort( 0x4 ),	/* 4 */
/* 910 */	NdrFcShort( 0x4 ),	/* 4 */
/* 912 */	0x12, 0x0,	/* FC_UP */
/* 914 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (890) */
/* 916 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 918 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 920 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 922 */	NdrFcShort( 0x8 ),	/* 8 */
/* 924 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 926 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 928 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 930 */	NdrFcShort( 0x8 ),	/* 8 */
/* 932 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 934 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 936 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 938 */	NdrFcShort( 0xffffffee ),	/* Offset= -18 (920) */
/* 940 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 942 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 944 */	NdrFcShort( 0x28 ),	/* 40 */
/* 946 */	NdrFcShort( 0xffffffee ),	/* Offset= -18 (928) */
/* 948 */	NdrFcShort( 0x0 ),	/* Offset= 0 (948) */
/* 950 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 952 */	0x38,		/* FC_ALIGNM4 */
			0x8,		/* FC_LONG */
/* 954 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 956 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffc51 ),	/* Offset= -943 (14) */
			0x5b,		/* FC_END */
/* 960 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 962 */	NdrFcShort( 0x0 ),	/* 0 */
/* 964 */	NdrFcShort( 0x4 ),	/* 4 */
/* 966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 968 */	NdrFcShort( 0xfffffc3e ),	/* Offset= -962 (6) */
/* 970 */	
			0x11, 0x0,	/* FC_RP */
/* 972 */	NdrFcShort( 0x2 ),	/* Offset= 2 (974) */
/* 974 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 976 */	NdrFcShort( 0x0 ),	/* 0 */
/* 978 */	NdrFcShort( 0x4 ),	/* 4 */
/* 980 */	NdrFcShort( 0x0 ),	/* 0 */
/* 982 */	NdrFcShort( 0xfffffea0 ),	/* Offset= -352 (630) */
/* 984 */	
			0x12, 0x0,	/* FC_UP */
/* 986 */	NdrFcShort( 0xfffffc82 ),	/* Offset= -894 (92) */
/* 988 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 990 */	NdrFcShort( 0x1 ),	/* 1 */
/* 992 */	NdrFcShort( 0x4 ),	/* 4 */
/* 994 */	NdrFcShort( 0x0 ),	/* 0 */
/* 996 */	NdrFcShort( 0xfffffff4 ),	/* Offset= -12 (984) */
/* 998 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 1000 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1002 */	
			0x11, 0x10,	/* FC_RP */
/* 1004 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1006) */
/* 1006 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1008 */	NdrFcLong( 0x43d71c20 ),	/* 1138170912 */
/* 1012 */	NdrFcShort( 0xe726 ),	/* -6362 */
/* 1014 */	NdrFcShort( 0x4786 ),	/* 18310 */
/* 1016 */	0x80,		/* 128 */
			0xe,		/* 14 */
/* 1018 */	0x15,		/* 21 */
			0xc0,		/* 192 */
/* 1020 */	0x69,		/* 105 */
			0x68,		/* 104 */
/* 1022 */	0xad,		/* 173 */
			0xf3,		/* 243 */
/* 1024 */	
			0x11, 0x10,	/* FC_RP */
/* 1026 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1028) */
/* 1028 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1030 */	NdrFcLong( 0x58cf6f05 ),	/* 1489989381 */
/* 1034 */	NdrFcShort( 0xd4ac ),	/* -11092 */
/* 1036 */	NdrFcShort( 0x481e ),	/* 18462 */
/* 1038 */	0xb9,		/* 185 */
			0x4d,		/* 77 */
/* 1040 */	0xfa,		/* 250 */
			0x4f,		/* 79 */
/* 1042 */	0x4d,		/* 77 */
			0xe0,		/* 224 */
/* 1044 */	0x91,		/* 145 */
			0xc7,		/* 199 */

			0x0
        }
    };

const CInterfaceProxyVtbl * _RtsOnTransmission_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IOnChartProxyVtbl,
    ( CInterfaceProxyVtbl *) &_ICOnTestHarnessProxyVtbl,
    0
};

const CInterfaceStubVtbl * _RtsOnTransmission_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IOnChartStubVtbl,
    ( CInterfaceStubVtbl *) &_ICOnTestHarnessStubVtbl,
    0
};

PCInterfaceName const _RtsOnTransmission_InterfaceNamesList[] = 
{
    "IOnChart",
    "ICOnTestHarness",
    0
};

const IID *  _RtsOnTransmission_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _RtsOnTransmission_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _RtsOnTransmission, pIID, n)

int __stdcall _RtsOnTransmission_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _RtsOnTransmission, 2, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _RtsOnTransmission, 2, *pIndex )
    
}

const ExtendedProxyFileInfo RtsOnTransmission_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _RtsOnTransmission_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _RtsOnTransmission_StubVtblList,
    (const PCInterfaceName * ) & _RtsOnTransmission_InterfaceNamesList,
    (const IID ** ) & _RtsOnTransmission_BaseIIDList,
    & _RtsOnTransmission_IID_Lookup, 
    2,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
