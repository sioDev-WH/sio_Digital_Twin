/* this ALWAYS GENERATED file contains the proxy stub code */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Oct 19 15:13:00 2001
 */
/* Compiler settings for C:\DistComponents\Geomov\geomove.idl:
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


#include "geomove.h"

#define TYPE_FORMAT_STRING_SIZE   1095                              
#define PROC_FORMAT_STRING_SIZE   883                               

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


/* Standard interface: __MIDL_itf_geomove_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IGeoObject, ver. 0.0,
   GUID={0x4942183F,0xC793,0x11D3,{0x83,0xDD,0x00,0xC0,0x93,0x02,0x2C,0xC1}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IGeoObject_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IGeoObject_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    28,
    56,
    84,
    112,
    140,
    168,
    196,
    224,
    252,
    280,
    308,
    336,
    364
    };

static const MIDL_SERVER_INFO IGeoObject_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IGeoObject_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IGeoObject_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IGeoObject_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(21) _IGeoObjectProxyVtbl = 
{
    &IGeoObject_ProxyInfo,
    &IID_IGeoObject,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IGeoObject::get_Dimension */ ,
    (void *)-1 /* IGeoObject::put_Dimension */ ,
    (void *)-1 /* IGeoObject::get_Span */ ,
    (void *)-1 /* IGeoObject::put_Span */ ,
    (void *)-1 /* IGeoObject::SetInitialGuess */ ,
    (void *)-1 /* IGeoObject::get_Resolution */ ,
    (void *)-1 /* IGeoObject::put_Resolution */ ,
    (void *)-1 /* IGeoObject::get_MaxIteration */ ,
    (void *)-1 /* IGeoObject::put_MaxIteration */ ,
    (void *)-1 /* IGeoObject::get_MaxTime */ ,
    (void *)-1 /* IGeoObject::put_MaxTime */ ,
    (void *)-1 /* IGeoObject::SetModel */ ,
    (void *)-1 /* IGeoObject::SetIModel */ ,
    (void *)-1 /* IGeoObject::Optimize */
};


static const PRPC_STUB_FUNCTION IGeoObject_table[] =
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
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IGeoObjectStubVtbl =
{
    &IID_IGeoObject,
    &IGeoObject_ServerInfo,
    21,
    &IGeoObject_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IModel, ver. 0.0,
   GUID={0xA49A1201,0xC930,0x11D3,{0x83,0xDF,0x00,0xC0,0x93,0x02,0x2C,0xC1}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IModel_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IModel_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    398,
    426,
    454,
    482,
    510,
    538,
    566,
    600,
    634
    };

static const MIDL_SERVER_INFO IModel_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IModel_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IModel_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IModel_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(16) _IModelProxyVtbl = 
{
    &IModel_ProxyInfo,
    &IID_IModel,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IModel::get_Dimension */ ,
    (void *)-1 /* IModel::put_Dimension */ ,
    (void *)-1 /* IModel::get_NIC */ ,
    (void *)-1 /* IModel::put_NIC */ ,
    (void *)-1 /* IModel::get_NEC */ ,
    (void *)-1 /* IModel::put_NEC */ ,
    (void *)-1 /* IModel::Objective */ ,
    (void *)-1 /* IModel::EqualityConstraints */ ,
    (void *)-1 /* IModel::InequalityConstraints */
};


static const PRPC_STUB_FUNCTION IModel_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _IModelStubVtbl =
{
    &IID_IModel,
    &IModel_ServerInfo,
    16,
    &IModel_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: DIModel, ver. 0.0,
   GUID={0x8E0C8539,0x576C,0x4060,{0xB5,0x36,0x6B,0x75,0x81,0xE1,0x4E,0x46}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO DIModel_ServerInfo;

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

static const unsigned short DIModel_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    28,
    668,
    696,
    724,
    752,
    780,
    814,
    848
    };

static const MIDL_SERVER_INFO DIModel_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &DIModel_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO DIModel_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &DIModel_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(16) _DIModelProxyVtbl = 
{
    &DIModel_ProxyInfo,
    &IID_DIModel,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* DIModel::get_Dimension */ ,
    (void *)-1 /* DIModel::put_Dimension */ ,
    (void *)-1 /* DIModel::get_NIC */ ,
    (void *)-1 /* DIModel::put_NIC */ ,
    (void *)-1 /* DIModel::get_NEC */ ,
    (void *)-1 /* DIModel::put_NEC */ ,
    (void *)-1 /* DIModel::Objective */ ,
    (void *)-1 /* DIModel::EqualityConstraints */ ,
    (void *)-1 /* DIModel::InequalityConstraints */
};


static const PRPC_STUB_FUNCTION DIModel_table[] =
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
    NdrStubCall2
};

CInterfaceStubVtbl _DIModelStubVtbl =
{
    &IID_DIModel,
    &DIModel_ServerInfo,
    16,
    &DIModel_table[-3],
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
            VARIANT_UserSize
            ,VARIANT_UserMarshal
            ,VARIANT_UserUnmarshal
            ,VARIANT_UserFree
            }

        };


#if !defined(__RPC_WIN32__)
#error  Invalid build platform for this stub.
#endif

#if !(TARGET_IS_NT40_OR_LATER)
#error You need a Windows NT 4.0 or later to run this stub because it uses these features:
#error   -Oif or -Oicf, [wire_marshal] or [user_marshal] attribute, float, double or hyper in -Oif or -Oicf, more than 32 methods in the interface.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {

	/* Procedure get_Dimension */


	/* Procedure get_Dimension */

			0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/*  2 */	NdrFcLong( 0x0 ),	/* 0 */
/*  6 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/*  8 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 10 */	NdrFcShort( 0x0 ),	/* 0 */
/* 12 */	NdrFcShort( 0x10 ),	/* 16 */
/* 14 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */


	/* Parameter pVal */

/* 16 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 18 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 20 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 22 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 24 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 26 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Dimension */


	/* Procedure put_Dimension */

/* 28 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 30 */	NdrFcLong( 0x0 ),	/* 0 */
/* 34 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
/* 36 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 38 */	NdrFcShort( 0x8 ),	/* 8 */
/* 40 */	NdrFcShort( 0x8 ),	/* 8 */
/* 42 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */


	/* Parameter newVal */

/* 44 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 46 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 48 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 50 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 52 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 54 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Span */

/* 56 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 58 */	NdrFcLong( 0x0 ),	/* 0 */
/* 62 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
/* 64 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 66 */	NdrFcShort( 0x0 ),	/* 0 */
/* 68 */	NdrFcShort( 0x18 ),	/* 24 */
/* 70 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 72 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 74 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 76 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 78 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 80 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 82 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Span */

/* 84 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 86 */	NdrFcLong( 0x0 ),	/* 0 */
/* 90 */	NdrFcShort( 0xa ),	/* 10 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 92 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
#else
			NdrFcShort( 0x14 ),	/* MIPS & PPC Stack size/offset = 20 */
#endif
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 94 */	NdrFcShort( 0x10 ),	/* 16 */
/* 96 */	NdrFcShort( 0x8 ),	/* 8 */
/* 98 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

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

	/* Return value */

/* 106 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 108 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
#else
			NdrFcShort( 0x10 ),	/* MIPS & PPC Stack size/offset = 16 */
#endif
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 110 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetInitialGuess */

/* 112 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 114 */	NdrFcLong( 0x0 ),	/* 0 */
/* 118 */	NdrFcShort( 0xb ),	/* 11 */
#ifndef _ALPHA_
/* 120 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 122 */	NdrFcShort( 0x0 ),	/* 0 */
/* 124 */	NdrFcShort( 0x8 ),	/* 8 */
/* 126 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter ppsaArray */

/* 128 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
#ifndef _ALPHA_
/* 130 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 132 */	NdrFcShort( 0x3c8 ),	/* Type Offset=968 */

	/* Return value */

/* 134 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 136 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 138 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Resolution */

/* 140 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 142 */	NdrFcLong( 0x0 ),	/* 0 */
/* 146 */	NdrFcShort( 0xc ),	/* 12 */
#ifndef _ALPHA_
/* 148 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 152 */	NdrFcShort( 0x18 ),	/* 24 */
/* 154 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 156 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 158 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 160 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 162 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 164 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 166 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Resolution */

/* 168 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 170 */	NdrFcLong( 0x0 ),	/* 0 */
/* 174 */	NdrFcShort( 0xd ),	/* 13 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 176 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
#else
			NdrFcShort( 0x14 ),	/* MIPS & PPC Stack size/offset = 20 */
#endif
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 178 */	NdrFcShort( 0x10 ),	/* 16 */
/* 180 */	NdrFcShort( 0x8 ),	/* 8 */
/* 182 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 184 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 186 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* MIPS & PPC Stack size/offset = 8 */
#endif
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 188 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 190 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 192 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
#else
			NdrFcShort( 0x10 ),	/* MIPS & PPC Stack size/offset = 16 */
#endif
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 194 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_MaxIteration */

/* 196 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 198 */	NdrFcLong( 0x0 ),	/* 0 */
/* 202 */	NdrFcShort( 0xe ),	/* 14 */
#ifndef _ALPHA_
/* 204 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 206 */	NdrFcShort( 0x0 ),	/* 0 */
/* 208 */	NdrFcShort( 0x10 ),	/* 16 */
/* 210 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 212 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 214 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 216 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 218 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 220 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 222 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_MaxIteration */

/* 224 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 226 */	NdrFcLong( 0x0 ),	/* 0 */
/* 230 */	NdrFcShort( 0xf ),	/* 15 */
#ifndef _ALPHA_
/* 232 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 234 */	NdrFcShort( 0x8 ),	/* 8 */
/* 236 */	NdrFcShort( 0x8 ),	/* 8 */
/* 238 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 240 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 242 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 244 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 246 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 248 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 250 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_MaxTime */

/* 252 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 254 */	NdrFcLong( 0x0 ),	/* 0 */
/* 258 */	NdrFcShort( 0x10 ),	/* 16 */
#ifndef _ALPHA_
/* 260 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 262 */	NdrFcShort( 0x0 ),	/* 0 */
/* 264 */	NdrFcShort( 0x18 ),	/* 24 */
/* 266 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 268 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 270 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 272 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 274 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 276 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 278 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_MaxTime */

/* 280 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 282 */	NdrFcLong( 0x0 ),	/* 0 */
/* 286 */	NdrFcShort( 0x11 ),	/* 17 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 288 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
#else
			NdrFcShort( 0x14 ),	/* MIPS & PPC Stack size/offset = 20 */
#endif
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 290 */	NdrFcShort( 0x10 ),	/* 16 */
/* 292 */	NdrFcShort( 0x8 ),	/* 8 */
/* 294 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 296 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 298 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* MIPS & PPC Stack size/offset = 8 */
#endif
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 300 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 302 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 304 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
#else
			NdrFcShort( 0x10 ),	/* MIPS & PPC Stack size/offset = 16 */
#endif
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 306 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetModel */

/* 308 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 310 */	NdrFcLong( 0x0 ),	/* 0 */
/* 314 */	NdrFcShort( 0x12 ),	/* 18 */
#ifndef _ALPHA_
/* 316 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 318 */	NdrFcShort( 0x0 ),	/* 0 */
/* 320 */	NdrFcShort( 0x8 ),	/* 8 */
/* 322 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter pModel */

/* 324 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 326 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 328 */	NdrFcShort( 0xd4 ),	/* Type Offset=212 */

	/* Return value */

/* 330 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 332 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 334 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure SetIModel */

/* 336 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 338 */	NdrFcLong( 0x0 ),	/* 0 */
/* 342 */	NdrFcShort( 0x13 ),	/* 19 */
#ifndef _ALPHA_
/* 344 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 346 */	NdrFcShort( 0x0 ),	/* 0 */
/* 348 */	NdrFcShort( 0x8 ),	/* 8 */
/* 350 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter pModel */

/* 352 */	NdrFcShort( 0xb ),	/* Flags:  must size, must free, in, */
#ifndef _ALPHA_
/* 354 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 356 */	NdrFcShort( 0x3d2 ),	/* Type Offset=978 */

	/* Return value */

/* 358 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 360 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 362 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Optimize */

/* 364 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 366 */	NdrFcLong( 0x0 ),	/* 0 */
/* 370 */	NdrFcShort( 0x14 ),	/* 20 */
#ifndef _ALPHA_
/* 372 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 374 */	NdrFcShort( 0x0 ),	/* 0 */
/* 376 */	NdrFcShort( 0x18 ),	/* 24 */
/* 378 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter ppsaArray */

/* 380 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
#ifndef _ALPHA_
/* 382 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 384 */	NdrFcShort( 0x3c8 ),	/* Type Offset=968 */

	/* Parameter pVal */

/* 386 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 388 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 390 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 392 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 394 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 396 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_Dimension */

/* 398 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 400 */	NdrFcLong( 0x0 ),	/* 0 */
/* 404 */	NdrFcShort( 0x7 ),	/* 7 */
#ifndef _ALPHA_
/* 406 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 408 */	NdrFcShort( 0x0 ),	/* 0 */
/* 410 */	NdrFcShort( 0x8 ),	/* 8 */
/* 412 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 414 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
#ifndef _ALPHA_
/* 416 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 418 */	NdrFcShort( 0x3ec ),	/* Type Offset=1004 */

	/* Return value */

/* 420 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 422 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 424 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_Dimension */

/* 426 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 428 */	NdrFcLong( 0x0 ),	/* 0 */
/* 432 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 434 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
#else
			NdrFcShort( 0x1c ),	/* MIPS & PPC Stack size/offset = 28 */
#endif
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 436 */	NdrFcShort( 0x0 ),	/* 0 */
/* 438 */	NdrFcShort( 0x8 ),	/* 8 */
/* 440 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 442 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 444 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* MIPS & PPC Stack size/offset = 8 */
#endif
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 446 */	NdrFcShort( 0x3fa ),	/* Type Offset=1018 */

	/* Return value */

/* 448 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 450 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
#else
			NdrFcShort( 0x18 ),	/* MIPS & PPC Stack size/offset = 24 */
#endif
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 452 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_NIC */

/* 454 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 456 */	NdrFcLong( 0x0 ),	/* 0 */
/* 460 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
/* 462 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 464 */	NdrFcShort( 0x0 ),	/* 0 */
/* 466 */	NdrFcShort( 0x8 ),	/* 8 */
/* 468 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 470 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
#ifndef _ALPHA_
/* 472 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 474 */	NdrFcShort( 0x40c ),	/* Type Offset=1036 */

	/* Return value */

/* 476 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 478 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 480 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_NIC */

/* 482 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 484 */	NdrFcLong( 0x0 ),	/* 0 */
/* 488 */	NdrFcShort( 0xa ),	/* 10 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 490 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
#else
			NdrFcShort( 0x1c ),	/* MIPS & PPC Stack size/offset = 28 */
#endif
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 492 */	NdrFcShort( 0x0 ),	/* 0 */
/* 494 */	NdrFcShort( 0x8 ),	/* 8 */
/* 496 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 498 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 500 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* MIPS & PPC Stack size/offset = 8 */
#endif
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 502 */	NdrFcShort( 0x3fa ),	/* Type Offset=1018 */

	/* Return value */

/* 504 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 506 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
#else
			NdrFcShort( 0x18 ),	/* MIPS & PPC Stack size/offset = 24 */
#endif
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 508 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_NEC */

/* 510 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 512 */	NdrFcLong( 0x0 ),	/* 0 */
/* 516 */	NdrFcShort( 0xb ),	/* 11 */
#ifndef _ALPHA_
/* 518 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 520 */	NdrFcShort( 0x0 ),	/* 0 */
/* 522 */	NdrFcShort( 0x8 ),	/* 8 */
/* 524 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 526 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
#ifndef _ALPHA_
/* 528 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 530 */	NdrFcShort( 0x40c ),	/* Type Offset=1036 */

	/* Return value */

/* 532 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 534 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 536 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_NEC */

/* 538 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 540 */	NdrFcLong( 0x0 ),	/* 0 */
/* 544 */	NdrFcShort( 0xc ),	/* 12 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 546 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
#else
			NdrFcShort( 0x1c ),	/* MIPS & PPC Stack size/offset = 28 */
#endif
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 548 */	NdrFcShort( 0x0 ),	/* 0 */
/* 550 */	NdrFcShort( 0x8 ),	/* 8 */
/* 552 */	0x6,		/* Oi2 Flags:  clt must size, has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 554 */	NdrFcShort( 0x8b ),	/* Flags:  must size, must free, in, by val, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 556 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* MIPS & PPC Stack size/offset = 8 */
#endif
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 558 */	NdrFcShort( 0x3fa ),	/* Type Offset=1018 */

	/* Return value */

/* 560 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 562 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
#else
			NdrFcShort( 0x18 ),	/* MIPS & PPC Stack size/offset = 24 */
#endif
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 564 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Objective */

/* 566 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 568 */	NdrFcLong( 0x0 ),	/* 0 */
/* 572 */	NdrFcShort( 0xd ),	/* 13 */
#ifndef _ALPHA_
/* 574 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 576 */	NdrFcShort( 0x0 ),	/* 0 */
/* 578 */	NdrFcShort( 0x8 ),	/* 8 */
/* 580 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter pArray */

/* 582 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
#ifndef _ALPHA_
/* 584 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 586 */	NdrFcShort( 0x40c ),	/* Type Offset=1036 */

	/* Parameter pVal */

/* 588 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
#ifndef _ALPHA_
/* 590 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 592 */	NdrFcShort( 0x40c ),	/* Type Offset=1036 */

	/* Return value */

/* 594 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 596 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 598 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EqualityConstraints */

/* 600 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 602 */	NdrFcLong( 0x0 ),	/* 0 */
/* 606 */	NdrFcShort( 0xe ),	/* 14 */
#ifndef _ALPHA_
/* 608 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 610 */	NdrFcShort( 0x0 ),	/* 0 */
/* 612 */	NdrFcShort( 0x8 ),	/* 8 */
/* 614 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter pArray */

/* 616 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
#ifndef _ALPHA_
/* 618 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 620 */	NdrFcShort( 0x3fa ),	/* Type Offset=1018 */

	/* Parameter pVal */

/* 622 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
#ifndef _ALPHA_
/* 624 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 626 */	NdrFcShort( 0x40c ),	/* Type Offset=1036 */

	/* Return value */

/* 628 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 630 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 632 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InequalityConstraints */

/* 634 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 636 */	NdrFcLong( 0x0 ),	/* 0 */
/* 640 */	NdrFcShort( 0xf ),	/* 15 */
#ifndef _ALPHA_
/* 642 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 644 */	NdrFcShort( 0x0 ),	/* 0 */
/* 646 */	NdrFcShort( 0x8 ),	/* 8 */
/* 648 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter pArray */

/* 650 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
#ifndef _ALPHA_
/* 652 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 654 */	NdrFcShort( 0x3fa ),	/* Type Offset=1018 */

	/* Parameter pVal */

/* 656 */	NdrFcShort( 0x4113 ),	/* Flags:  must size, must free, out, simple ref, srv alloc size=16 */
#ifndef _ALPHA_
/* 658 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 660 */	NdrFcShort( 0x40c ),	/* Type Offset=1036 */

	/* Return value */

/* 662 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 664 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 666 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_NIC */

/* 668 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 670 */	NdrFcLong( 0x0 ),	/* 0 */
/* 674 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
/* 676 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 678 */	NdrFcShort( 0x0 ),	/* 0 */
/* 680 */	NdrFcShort( 0x10 ),	/* 16 */
/* 682 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 684 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 686 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 688 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 690 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 692 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 694 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_NIC */

/* 696 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 698 */	NdrFcLong( 0x0 ),	/* 0 */
/* 702 */	NdrFcShort( 0xa ),	/* 10 */
#ifndef _ALPHA_
/* 704 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 706 */	NdrFcShort( 0x8 ),	/* 8 */
/* 708 */	NdrFcShort( 0x8 ),	/* 8 */
/* 710 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 712 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 714 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 716 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 718 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 720 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 722 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_NEC */

/* 724 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 726 */	NdrFcLong( 0x0 ),	/* 0 */
/* 730 */	NdrFcShort( 0xb ),	/* 11 */
#ifndef _ALPHA_
/* 732 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 736 */	NdrFcShort( 0x10 ),	/* 16 */
/* 738 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter pVal */

/* 740 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 742 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 744 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 746 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 748 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 750 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure put_NEC */

/* 752 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 754 */	NdrFcLong( 0x0 ),	/* 0 */
/* 758 */	NdrFcShort( 0xc ),	/* 12 */
#ifndef _ALPHA_
/* 760 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 762 */	NdrFcShort( 0x8 ),	/* 8 */
/* 764 */	NdrFcShort( 0x8 ),	/* 8 */
/* 766 */	0x4,		/* Oi2 Flags:  has return, */
			0x2,		/* 2 */

	/* Parameter newVal */

/* 768 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
/* 770 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 772 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 774 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 776 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 778 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure Objective */

/* 780 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 782 */	NdrFcLong( 0x0 ),	/* 0 */
/* 786 */	NdrFcShort( 0xd ),	/* 13 */
#ifndef _ALPHA_
/* 788 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 790 */	NdrFcShort( 0x0 ),	/* 0 */
/* 792 */	NdrFcShort( 0x18 ),	/* 24 */
/* 794 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter pArray */

/* 796 */	NdrFcShort( 0x11b ),	/* Flags:  must size, must free, in, out, simple ref, */
#ifndef _ALPHA_
/* 798 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 800 */	NdrFcShort( 0x422 ),	/* Type Offset=1058 */

	/* Parameter pVal */

/* 802 */	NdrFcShort( 0x2150 ),	/* Flags:  out, base type, simple ref, srv alloc size=8 */
#ifndef _ALPHA_
/* 804 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 806 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */

/* 808 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 810 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 812 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure EqualityConstraints */

/* 814 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 816 */	NdrFcLong( 0x0 ),	/* 0 */
/* 820 */	NdrFcShort( 0xe ),	/* 14 */
#ifndef _ALPHA_
/* 822 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 824 */	NdrFcShort( 0x0 ),	/* 0 */
/* 826 */	NdrFcShort( 0x8 ),	/* 8 */
/* 828 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter pArray */

/* 830 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
#ifndef _ALPHA_
/* 832 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 834 */	NdrFcShort( 0x438 ),	/* Type Offset=1080 */

	/* Parameter pVal */

/* 836 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
#ifndef _ALPHA_
/* 838 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 840 */	NdrFcShort( 0x422 ),	/* Type Offset=1058 */

	/* Return value */

/* 842 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 844 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 846 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure InequalityConstraints */

/* 848 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 850 */	NdrFcLong( 0x0 ),	/* 0 */
/* 854 */	NdrFcShort( 0xf ),	/* 15 */
#ifndef _ALPHA_
/* 856 */	NdrFcShort( 0x10 ),	/* x86, MIPS, PPC Stack size/offset = 16 */
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 858 */	NdrFcShort( 0x0 ),	/* 0 */
/* 860 */	NdrFcShort( 0x8 ),	/* 8 */
/* 862 */	0x7,		/* Oi2 Flags:  srv must size, clt must size, has return, */
			0x3,		/* 3 */

	/* Parameter pArray */

/* 864 */	NdrFcShort( 0x10b ),	/* Flags:  must size, must free, in, simple ref, */
#ifndef _ALPHA_
/* 866 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 868 */	NdrFcShort( 0x438 ),	/* Type Offset=1080 */

	/* Parameter pVal */

/* 870 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
#ifndef _ALPHA_
/* 872 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 874 */	NdrFcShort( 0x422 ),	/* Type Offset=1058 */

	/* Return value */

/* 876 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 878 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 880 */	0x8,		/* FC_LONG */
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
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  4 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/*  6 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/*  8 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 10 */	
			0x11, 0x0,	/* FC_RP */
/* 12 */	NdrFcShort( 0x3bc ),	/* Offset= 956 (968) */
/* 14 */	
			0x13, 0x10,	/* FC_OP */
/* 16 */	NdrFcShort( 0x2 ),	/* Offset= 2 (18) */
/* 18 */	
			0x13, 0x0,	/* FC_OP */
/* 20 */	NdrFcShort( 0x3a2 ),	/* Offset= 930 (950) */
/* 22 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 24 */	NdrFcShort( 0x18 ),	/* 24 */
/* 26 */	NdrFcShort( 0xa ),	/* 10 */
/* 28 */	NdrFcLong( 0x8 ),	/* 8 */
/* 32 */	NdrFcShort( 0x6c ),	/* Offset= 108 (140) */
/* 34 */	NdrFcLong( 0xd ),	/* 13 */
/* 38 */	NdrFcShort( 0x9e ),	/* Offset= 158 (196) */
/* 40 */	NdrFcLong( 0x9 ),	/* 9 */
/* 44 */	NdrFcShort( 0xcc ),	/* Offset= 204 (248) */
/* 46 */	NdrFcLong( 0xc ),	/* 12 */
/* 50 */	NdrFcShort( 0x292 ),	/* Offset= 658 (708) */
/* 52 */	NdrFcLong( 0x24 ),	/* 36 */
/* 56 */	NdrFcShort( 0x2ba ),	/* Offset= 698 (754) */
/* 58 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 62 */	NdrFcShort( 0x2d6 ),	/* Offset= 726 (788) */
/* 64 */	NdrFcLong( 0x10 ),	/* 16 */
/* 68 */	NdrFcShort( 0x2ee ),	/* Offset= 750 (818) */
/* 70 */	NdrFcLong( 0x2 ),	/* 2 */
/* 74 */	NdrFcShort( 0x306 ),	/* Offset= 774 (848) */
/* 76 */	NdrFcLong( 0x3 ),	/* 3 */
/* 80 */	NdrFcShort( 0x31e ),	/* Offset= 798 (878) */
/* 82 */	NdrFcLong( 0x14 ),	/* 20 */
/* 86 */	NdrFcShort( 0x336 ),	/* Offset= 822 (908) */
/* 88 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (87) */
/* 90 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 92 */	NdrFcShort( 0x2 ),	/* 2 */
/* 94 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 96 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 98 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 100 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 102 */	NdrFcShort( 0x8 ),	/* 8 */
/* 104 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (90) */
/* 106 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 108 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 110 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 112 */	NdrFcShort( 0x4 ),	/* 4 */
/* 114 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 116 */	NdrFcShort( 0x0 ),	/* 0 */
/* 118 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 120 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 122 */	NdrFcShort( 0x4 ),	/* 4 */
/* 124 */	NdrFcShort( 0x0 ),	/* 0 */
/* 126 */	NdrFcShort( 0x1 ),	/* 1 */
/* 128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 132 */	0x13, 0x0,	/* FC_OP */
/* 134 */	NdrFcShort( 0xffffffde ),	/* Offset= -34 (100) */
/* 136 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 138 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 140 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 142 */	NdrFcShort( 0x8 ),	/* 8 */
/* 144 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 146 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 148 */	NdrFcShort( 0x4 ),	/* 4 */
/* 150 */	NdrFcShort( 0x4 ),	/* 4 */
/* 152 */	0x11, 0x0,	/* FC_RP */
/* 154 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (110) */
/* 156 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 158 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 160 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 162 */	NdrFcLong( 0x0 ),	/* 0 */
/* 166 */	NdrFcShort( 0x0 ),	/* 0 */
/* 168 */	NdrFcShort( 0x0 ),	/* 0 */
/* 170 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 172 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 174 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 176 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 178 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 182 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 184 */	NdrFcShort( 0x0 ),	/* 0 */
/* 186 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 190 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 192 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (160) */
/* 194 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 196 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 198 */	NdrFcShort( 0x8 ),	/* 8 */
/* 200 */	NdrFcShort( 0x0 ),	/* 0 */
/* 202 */	NdrFcShort( 0x6 ),	/* Offset= 6 (208) */
/* 204 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 206 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 208 */	
			0x11, 0x0,	/* FC_RP */
/* 210 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (178) */
/* 212 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 214 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 218 */	NdrFcShort( 0x0 ),	/* 0 */
/* 220 */	NdrFcShort( 0x0 ),	/* 0 */
/* 222 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 224 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 226 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 228 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 230 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 234 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 236 */	NdrFcShort( 0x0 ),	/* 0 */
/* 238 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 242 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 244 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (212) */
/* 246 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 248 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 250 */	NdrFcShort( 0x8 ),	/* 8 */
/* 252 */	NdrFcShort( 0x0 ),	/* 0 */
/* 254 */	NdrFcShort( 0x6 ),	/* Offset= 6 (260) */
/* 256 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 258 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 260 */	
			0x11, 0x0,	/* FC_RP */
/* 262 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (230) */
/* 264 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 266 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 268 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 270 */	NdrFcShort( 0x2 ),	/* Offset= 2 (272) */
/* 272 */	NdrFcShort( 0x10 ),	/* 16 */
/* 274 */	NdrFcShort( 0x2b ),	/* 43 */
/* 276 */	NdrFcLong( 0x3 ),	/* 3 */
/* 280 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 282 */	NdrFcLong( 0x11 ),	/* 17 */
/* 286 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 288 */	NdrFcLong( 0x2 ),	/* 2 */
/* 292 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 294 */	NdrFcLong( 0x4 ),	/* 4 */
/* 298 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 300 */	NdrFcLong( 0x5 ),	/* 5 */
/* 304 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 306 */	NdrFcLong( 0xb ),	/* 11 */
/* 310 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 312 */	NdrFcLong( 0xa ),	/* 10 */
/* 316 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 318 */	NdrFcLong( 0x6 ),	/* 6 */
/* 322 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (536) */
/* 324 */	NdrFcLong( 0x7 ),	/* 7 */
/* 328 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 330 */	NdrFcLong( 0x8 ),	/* 8 */
/* 334 */	NdrFcShort( 0xd0 ),	/* Offset= 208 (542) */
/* 336 */	NdrFcLong( 0xd ),	/* 13 */
/* 340 */	NdrFcShort( 0xffffff4c ),	/* Offset= -180 (160) */
/* 342 */	NdrFcLong( 0x9 ),	/* 9 */
/* 346 */	NdrFcShort( 0xffffff7a ),	/* Offset= -134 (212) */
/* 348 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 352 */	NdrFcShort( 0xc2 ),	/* Offset= 194 (546) */
/* 354 */	NdrFcLong( 0x24 ),	/* 36 */
/* 358 */	NdrFcShort( 0xc0 ),	/* Offset= 192 (550) */
/* 360 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 364 */	NdrFcShort( 0xba ),	/* Offset= 186 (550) */
/* 366 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 370 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (602) */
/* 372 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 376 */	NdrFcShort( 0xe6 ),	/* Offset= 230 (606) */
/* 378 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 382 */	NdrFcShort( 0xe4 ),	/* Offset= 228 (610) */
/* 384 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 388 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (614) */
/* 390 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 394 */	NdrFcShort( 0xe0 ),	/* Offset= 224 (618) */
/* 396 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 400 */	NdrFcShort( 0xce ),	/* Offset= 206 (606) */
/* 402 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 406 */	NdrFcShort( 0xcc ),	/* Offset= 204 (610) */
/* 408 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 412 */	NdrFcShort( 0xd2 ),	/* Offset= 210 (622) */
/* 414 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 418 */	NdrFcShort( 0xc8 ),	/* Offset= 200 (618) */
/* 420 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 424 */	NdrFcShort( 0xca ),	/* Offset= 202 (626) */
/* 426 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 430 */	NdrFcShort( 0xc8 ),	/* Offset= 200 (630) */
/* 432 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 436 */	NdrFcShort( 0xc6 ),	/* Offset= 198 (634) */
/* 438 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 442 */	NdrFcShort( 0xc4 ),	/* Offset= 196 (638) */
/* 444 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 448 */	NdrFcShort( 0xbe ),	/* Offset= 190 (638) */
/* 450 */	NdrFcLong( 0x10 ),	/* 16 */
/* 454 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 456 */	NdrFcLong( 0x12 ),	/* 18 */
/* 460 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 462 */	NdrFcLong( 0x13 ),	/* 19 */
/* 466 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 468 */	NdrFcLong( 0x16 ),	/* 22 */
/* 472 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 474 */	NdrFcLong( 0x17 ),	/* 23 */
/* 478 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 480 */	NdrFcLong( 0xe ),	/* 14 */
/* 484 */	NdrFcShort( 0x9e ),	/* Offset= 158 (642) */
/* 486 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 490 */	NdrFcShort( 0xa4 ),	/* Offset= 164 (654) */
/* 492 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 496 */	NdrFcShort( 0x6a ),	/* Offset= 106 (602) */
/* 498 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 502 */	NdrFcShort( 0x68 ),	/* Offset= 104 (606) */
/* 504 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 508 */	NdrFcShort( 0x66 ),	/* Offset= 102 (610) */
/* 510 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 514 */	NdrFcShort( 0x60 ),	/* Offset= 96 (610) */
/* 516 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 520 */	NdrFcShort( 0x5a ),	/* Offset= 90 (610) */
/* 522 */	NdrFcLong( 0x0 ),	/* 0 */
/* 526 */	NdrFcShort( 0x0 ),	/* Offset= 0 (526) */
/* 528 */	NdrFcLong( 0x1 ),	/* 1 */
/* 532 */	NdrFcShort( 0x0 ),	/* Offset= 0 (532) */
/* 534 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (533) */
/* 536 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 538 */	NdrFcShort( 0x8 ),	/* 8 */
/* 540 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 542 */	
			0x13, 0x0,	/* FC_OP */
/* 544 */	NdrFcShort( 0xfffffe44 ),	/* Offset= -444 (100) */
/* 546 */	
			0x13, 0x0,	/* FC_OP */
/* 548 */	NdrFcShort( 0x192 ),	/* Offset= 402 (950) */
/* 550 */	
			0x13, 0x0,	/* FC_OP */
/* 552 */	NdrFcShort( 0x1e ),	/* Offset= 30 (582) */
/* 554 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 556 */	NdrFcLong( 0x2f ),	/* 47 */
/* 560 */	NdrFcShort( 0x0 ),	/* 0 */
/* 562 */	NdrFcShort( 0x0 ),	/* 0 */
/* 564 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 566 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 568 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 570 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 572 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 574 */	NdrFcShort( 0x1 ),	/* 1 */
/* 576 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 578 */	NdrFcShort( 0x4 ),	/* 4 */
/* 580 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 582 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 584 */	NdrFcShort( 0x10 ),	/* 16 */
/* 586 */	NdrFcShort( 0x0 ),	/* 0 */
/* 588 */	NdrFcShort( 0xa ),	/* Offset= 10 (598) */
/* 590 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 592 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 594 */	NdrFcShort( 0xffffffd8 ),	/* Offset= -40 (554) */
/* 596 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 598 */	
			0x13, 0x0,	/* FC_OP */
/* 600 */	NdrFcShort( 0xffffffe4 ),	/* Offset= -28 (572) */
/* 602 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 604 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 606 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 608 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 610 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 612 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 614 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 616 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 618 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 620 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 622 */	
			0x13, 0x0,	/* FC_OP */
/* 624 */	NdrFcShort( 0xffffffa8 ),	/* Offset= -88 (536) */
/* 626 */	
			0x13, 0x10,	/* FC_OP */
/* 628 */	NdrFcShort( 0xffffffaa ),	/* Offset= -86 (542) */
/* 630 */	
			0x13, 0x10,	/* FC_OP */
/* 632 */	NdrFcShort( 0xfffffe28 ),	/* Offset= -472 (160) */
/* 634 */	
			0x13, 0x10,	/* FC_OP */
/* 636 */	NdrFcShort( 0xfffffe58 ),	/* Offset= -424 (212) */
/* 638 */	
			0x13, 0x10,	/* FC_OP */
/* 640 */	NdrFcShort( 0xffffffa2 ),	/* Offset= -94 (546) */
/* 642 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 644 */	NdrFcShort( 0x10 ),	/* 16 */
/* 646 */	0x6,		/* FC_SHORT */
			0x2,		/* FC_CHAR */
/* 648 */	0x2,		/* FC_CHAR */
			0x38,		/* FC_ALIGNM4 */
/* 650 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 652 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 654 */	
			0x13, 0x0,	/* FC_OP */
/* 656 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (642) */
/* 658 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 660 */	NdrFcShort( 0x20 ),	/* 32 */
/* 662 */	NdrFcShort( 0x0 ),	/* 0 */
/* 664 */	NdrFcShort( 0x0 ),	/* Offset= 0 (664) */
/* 666 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 668 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 670 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 672 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 674 */	NdrFcShort( 0xfffffe66 ),	/* Offset= -410 (264) */
/* 676 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 678 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 680 */	NdrFcShort( 0x4 ),	/* 4 */
/* 682 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 684 */	NdrFcShort( 0x0 ),	/* 0 */
/* 686 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 688 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 690 */	NdrFcShort( 0x4 ),	/* 4 */
/* 692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 694 */	NdrFcShort( 0x1 ),	/* 1 */
/* 696 */	NdrFcShort( 0x0 ),	/* 0 */
/* 698 */	NdrFcShort( 0x0 ),	/* 0 */
/* 700 */	0x13, 0x0,	/* FC_OP */
/* 702 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (658) */
/* 704 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 706 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 708 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 710 */	NdrFcShort( 0x8 ),	/* 8 */
/* 712 */	NdrFcShort( 0x0 ),	/* 0 */
/* 714 */	NdrFcShort( 0x6 ),	/* Offset= 6 (720) */
/* 716 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 718 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 720 */	
			0x11, 0x0,	/* FC_RP */
/* 722 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (678) */
/* 724 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 726 */	NdrFcShort( 0x4 ),	/* 4 */
/* 728 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 730 */	NdrFcShort( 0x0 ),	/* 0 */
/* 732 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 734 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 736 */	NdrFcShort( 0x4 ),	/* 4 */
/* 738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 740 */	NdrFcShort( 0x1 ),	/* 1 */
/* 742 */	NdrFcShort( 0x0 ),	/* 0 */
/* 744 */	NdrFcShort( 0x0 ),	/* 0 */
/* 746 */	0x13, 0x0,	/* FC_OP */
/* 748 */	NdrFcShort( 0xffffff5a ),	/* Offset= -166 (582) */
/* 750 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 752 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 754 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 756 */	NdrFcShort( 0x8 ),	/* 8 */
/* 758 */	NdrFcShort( 0x0 ),	/* 0 */
/* 760 */	NdrFcShort( 0x6 ),	/* Offset= 6 (766) */
/* 762 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 764 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 766 */	
			0x11, 0x0,	/* FC_RP */
/* 768 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (724) */
/* 770 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 772 */	NdrFcShort( 0x8 ),	/* 8 */
/* 774 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 776 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 778 */	NdrFcShort( 0x10 ),	/* 16 */
/* 780 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 782 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 784 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffff1 ),	/* Offset= -15 (770) */
			0x5b,		/* FC_END */
/* 788 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 790 */	NdrFcShort( 0x18 ),	/* 24 */
/* 792 */	NdrFcShort( 0x0 ),	/* 0 */
/* 794 */	NdrFcShort( 0xa ),	/* Offset= 10 (804) */
/* 796 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 798 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 800 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (776) */
/* 802 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 804 */	
			0x11, 0x0,	/* FC_RP */
/* 806 */	NdrFcShort( 0xfffffd8c ),	/* Offset= -628 (178) */
/* 808 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 810 */	NdrFcShort( 0x1 ),	/* 1 */
/* 812 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 814 */	NdrFcShort( 0x0 ),	/* 0 */
/* 816 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 818 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 820 */	NdrFcShort( 0x8 ),	/* 8 */
/* 822 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 824 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 826 */	NdrFcShort( 0x4 ),	/* 4 */
/* 828 */	NdrFcShort( 0x4 ),	/* 4 */
/* 830 */	0x13, 0x0,	/* FC_OP */
/* 832 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (808) */
/* 834 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 836 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 838 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 840 */	NdrFcShort( 0x2 ),	/* 2 */
/* 842 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 844 */	NdrFcShort( 0x0 ),	/* 0 */
/* 846 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 848 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 850 */	NdrFcShort( 0x8 ),	/* 8 */
/* 852 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 854 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 856 */	NdrFcShort( 0x4 ),	/* 4 */
/* 858 */	NdrFcShort( 0x4 ),	/* 4 */
/* 860 */	0x13, 0x0,	/* FC_OP */
/* 862 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (838) */
/* 864 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 866 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 868 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 870 */	NdrFcShort( 0x4 ),	/* 4 */
/* 872 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 874 */	NdrFcShort( 0x0 ),	/* 0 */
/* 876 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 878 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 880 */	NdrFcShort( 0x8 ),	/* 8 */
/* 882 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 884 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 886 */	NdrFcShort( 0x4 ),	/* 4 */
/* 888 */	NdrFcShort( 0x4 ),	/* 4 */
/* 890 */	0x13, 0x0,	/* FC_OP */
/* 892 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (868) */
/* 894 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 896 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 898 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 900 */	NdrFcShort( 0x8 ),	/* 8 */
/* 902 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 904 */	NdrFcShort( 0x0 ),	/* 0 */
/* 906 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 908 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 910 */	NdrFcShort( 0x8 ),	/* 8 */
/* 912 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 914 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 916 */	NdrFcShort( 0x4 ),	/* 4 */
/* 918 */	NdrFcShort( 0x4 ),	/* 4 */
/* 920 */	0x13, 0x0,	/* FC_OP */
/* 922 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (898) */
/* 924 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 926 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 928 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 930 */	NdrFcShort( 0x8 ),	/* 8 */
/* 932 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 934 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 936 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 938 */	NdrFcShort( 0x8 ),	/* 8 */
/* 940 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 942 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 944 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 946 */	NdrFcShort( 0xffffffee ),	/* Offset= -18 (928) */
/* 948 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 950 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 952 */	NdrFcShort( 0x28 ),	/* 40 */
/* 954 */	NdrFcShort( 0xffffffee ),	/* Offset= -18 (936) */
/* 956 */	NdrFcShort( 0x0 ),	/* Offset= 0 (956) */
/* 958 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 960 */	0x38,		/* FC_ALIGNM4 */
			0x8,		/* FC_LONG */
/* 962 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 964 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffc51 ),	/* Offset= -943 (22) */
			0x5b,		/* FC_END */
/* 968 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 972 */	NdrFcShort( 0x4 ),	/* 4 */
/* 974 */	NdrFcShort( 0x0 ),	/* 0 */
/* 976 */	NdrFcShort( 0xfffffc3e ),	/* Offset= -962 (14) */
/* 978 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 980 */	NdrFcLong( 0x8e0c8539 ),	/* -1911782087 */
/* 984 */	NdrFcShort( 0x576c ),	/* 22380 */
/* 986 */	NdrFcShort( 0x4060 ),	/* 16480 */
/* 988 */	0xb5,		/* 181 */
			0x36,		/* 54 */
/* 990 */	0x6b,		/* 107 */
			0x75,		/* 117 */
/* 992 */	0x81,		/* 129 */
			0xe1,		/* 225 */
/* 994 */	0x4e,		/* 78 */
			0x46,		/* 70 */
/* 996 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 998 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1004) */
/* 1000 */	
			0x13, 0x0,	/* FC_OP */
/* 1002 */	NdrFcShort( 0xfffffea8 ),	/* Offset= -344 (658) */
/* 1004 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1006 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1008 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1010 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1012 */	NdrFcShort( 0xfffffff4 ),	/* Offset= -12 (1000) */
/* 1014 */	
			0x12, 0x0,	/* FC_UP */
/* 1016 */	NdrFcShort( 0xfffffe9a ),	/* Offset= -358 (658) */
/* 1018 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1020 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1022 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1024 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1026 */	NdrFcShort( 0xfffffff4 ),	/* Offset= -12 (1014) */
/* 1028 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1030 */	NdrFcShort( 0x6 ),	/* Offset= 6 (1036) */
/* 1032 */	
			0x13, 0x0,	/* FC_OP */
/* 1034 */	NdrFcShort( 0xfffffe88 ),	/* Offset= -376 (658) */
/* 1036 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1038 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1040 */	NdrFcShort( 0x10 ),	/* 16 */
/* 1042 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1044 */	NdrFcShort( 0xfffffff4 ),	/* Offset= -12 (1032) */
/* 1046 */	
			0x11, 0x0,	/* FC_RP */
/* 1048 */	NdrFcShort( 0xfffffff4 ),	/* Offset= -12 (1036) */
/* 1050 */	
			0x11, 0x0,	/* FC_RP */
/* 1052 */	NdrFcShort( 0xffffffde ),	/* Offset= -34 (1018) */
/* 1054 */	
			0x11, 0x0,	/* FC_RP */
/* 1056 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1058) */
/* 1058 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1060 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1062 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1064 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1066 */	NdrFcShort( 0xfffffe54 ),	/* Offset= -428 (638) */
/* 1068 */	
			0x11, 0x0,	/* FC_RP */
/* 1070 */	NdrFcShort( 0xa ),	/* Offset= 10 (1080) */
/* 1072 */	
			0x12, 0x10,	/* FC_UP */
/* 1074 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1076) */
/* 1076 */	
			0x12, 0x0,	/* FC_UP */
/* 1078 */	NdrFcShort( 0xffffff80 ),	/* Offset= -128 (950) */
/* 1080 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1082 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1084 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1086 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1088 */	NdrFcShort( 0xfffffff0 ),	/* Offset= -16 (1072) */
/* 1090 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 1092 */	NdrFcShort( 0xffffffde ),	/* Offset= -34 (1058) */

			0x0
        }
    };

const CInterfaceProxyVtbl * _geomove_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IModelProxyVtbl,
    ( CInterfaceProxyVtbl *) &_DIModelProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IGeoObjectProxyVtbl,
    0
};

const CInterfaceStubVtbl * _geomove_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IModelStubVtbl,
    ( CInterfaceStubVtbl *) &_DIModelStubVtbl,
    ( CInterfaceStubVtbl *) &_IGeoObjectStubVtbl,
    0
};

PCInterfaceName const _geomove_InterfaceNamesList[] = 
{
    "IModel",
    "DIModel",
    "IGeoObject",
    0
};

const IID *  _geomove_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _geomove_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _geomove, pIID, n)

int __stdcall _geomove_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _geomove, 3, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _geomove, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _geomove, 3, *pIndex )
    
}

const ExtendedProxyFileInfo geomove_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _geomove_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _geomove_StubVtblList,
    (const PCInterfaceName * ) & _geomove_InterfaceNamesList,
    (const IID ** ) & _geomove_BaseIIDList,
    & _geomove_IID_Lookup, 
    3,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
