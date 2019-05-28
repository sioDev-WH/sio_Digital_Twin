/* this ALWAYS GENERATED file contains the proxy stub code */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Jan 09 10:46:40 2003
 */
/* Compiler settings for C:\DistComponents\RtsOnTransmissionVB\RtsOnTransmissionVB.idl:
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


#include "RtsOnTransmissionVB.h"

#define TYPE_FORMAT_STRING_SIZE   975                               
#define PROC_FORMAT_STRING_SIZE   243                               

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


/* Object interface: IvbActuator, ver. 0.0,
   GUID={0x151A17E2,0xEE49,0x48CB,{0x8F,0x80,0x37,0xE3,0xA8,0x4D,0x42,0x00}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IvbActuator_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IvbActuator_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    28,
    62
    };

static const MIDL_SERVER_INFO IvbActuator_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IvbActuator_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IvbActuator_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IvbActuator_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(10) _IvbActuatorProxyVtbl = 
{
    &IvbActuator_ProxyInfo,
    &IID_IvbActuator,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IvbActuator::get_Eso */ ,
    (void *)-1 /* IvbActuator::shiftEvent */ ,
    (void *)-1 /* IvbActuator::get_clutch */
};


static const PRPC_STUB_FUNCTION IvbActuator_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IvbActuatorStubVtbl =
{
    &IID_IvbActuator,
    &IvbActuator_ServerInfo,
    10,
    &IvbActuator_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IvbBand_Brake, ver. 0.0,
   GUID={0xC3FEA6B9,0x2A67,0x4730,{0x84,0xFF,0x33,0x9F,0x49,0xC6,0x3F,0xC7}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IvbBand_Brake_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IvbBand_Brake_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    90,
    62,
    118
    };

static const MIDL_SERVER_INFO IvbBand_Brake_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IvbBand_Brake_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IvbBand_Brake_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IvbBand_Brake_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(11) _IvbBand_BrakeProxyVtbl = 
{
    &IvbBand_Brake_ProxyInfo,
    &IID_IvbBand_Brake,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IvbBand_Brake::get_Eso */ ,
    (void *)-1 /* IvbBand_Brake::get_actuator */ ,
    (void *)-1 /* IvbBand_Brake::get_n */ ,
    (void *)-1 /* IvbBand_Brake::get_p */
};


static const PRPC_STUB_FUNCTION IvbBand_Brake_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IvbBand_BrakeStubVtbl =
{
    &IID_IvbBand_Brake,
    &IvbBand_Brake_ServerInfo,
    11,
    &IvbBand_Brake_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IvbBrakeActuator, ver. 0.0,
   GUID={0xC9F40039,0x5DD0,0x4731,{0xBB,0x00,0xFD,0xC8,0x70,0x37,0xA7,0xCB}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IvbBrakeActuator_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IvbBrakeActuator_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    90
    };

static const MIDL_SERVER_INFO IvbBrakeActuator_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IvbBrakeActuator_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IvbBrakeActuator_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IvbBrakeActuator_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(9) _IvbBrakeActuatorProxyVtbl = 
{
    &IvbBrakeActuator_ProxyInfo,
    &IID_IvbBrakeActuator,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IvbBrakeActuator::get_Eso */ ,
    (void *)-1 /* IvbBrakeActuator::get_p */
};


static const PRPC_STUB_FUNCTION IvbBrakeActuator_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IvbBrakeActuatorStubVtbl =
{
    &IID_IvbBrakeActuator,
    &IvbBrakeActuator_ServerInfo,
    9,
    &IvbBrakeActuator_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IvbDamper, ver. 0.0,
   GUID={0x5F57111A,0xD6E0,0x4682,{0x90,0xC1,0xD2,0xD8,0x59,0xC7,0x53,0xC2}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IvbDamper_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IvbDamper_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    90,
    62
    };

static const MIDL_SERVER_INFO IvbDamper_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IvbDamper_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IvbDamper_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IvbDamper_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(10) _IvbDamperProxyVtbl = 
{
    &IvbDamper_ProxyInfo,
    &IID_IvbDamper,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IvbDamper::get_Eso */ ,
    (void *)-1 /* IvbDamper::get_n */ ,
    (void *)-1 /* IvbDamper::get_p */
};


static const PRPC_STUB_FUNCTION IvbDamper_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IvbDamperStubVtbl =
{
    &IID_IvbDamper,
    &IvbDamper_ServerInfo,
    10,
    &IvbDamper_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IvbFrame, ver. 0.0,
   GUID={0xE33F7692,0xC1EC,0x4F20,{0x83,0x45,0xB2,0xE5,0xCC,0xD4,0xF4,0x35}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IvbFrame_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IvbFrame_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    90
    };

static const MIDL_SERVER_INFO IvbFrame_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IvbFrame_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IvbFrame_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IvbFrame_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(9) _IvbFrameProxyVtbl = 
{
    &IvbFrame_ProxyInfo,
    &IID_IvbFrame,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IvbFrame::get_Eso */ ,
    (void *)-1 /* IvbFrame::get_p */
};


static const PRPC_STUB_FUNCTION IvbFrame_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IvbFrameStubVtbl =
{
    &IID_IvbFrame,
    &IvbFrame_ServerInfo,
    9,
    &IvbFrame_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IvbClutch, ver. 0.0,
   GUID={0x1D54BCFB,0x53EF,0x4C9D,{0x9C,0xF4,0x94,0x26,0x41,0xC9,0xCD,0xB9}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IvbClutch_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IvbClutch_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    90,
    62,
    118
    };

static const MIDL_SERVER_INFO IvbClutch_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IvbClutch_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IvbClutch_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IvbClutch_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(11) _IvbClutchProxyVtbl = 
{
    &IvbClutch_ProxyInfo,
    &IID_IvbClutch,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IvbClutch::get_Eso */ ,
    (void *)-1 /* IvbClutch::get_actuator */ ,
    (void *)-1 /* IvbClutch::get_n */ ,
    (void *)-1 /* IvbClutch::get_p */
};


static const PRPC_STUB_FUNCTION IvbClutch_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IvbClutchStubVtbl =
{
    &IID_IvbClutch,
    &IvbClutch_ServerInfo,
    11,
    &IvbClutch_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IvbMass, ver. 0.0,
   GUID={0xE3830D21,0x7568,0x4546,{0x87,0x2A,0xF8,0xC8,0x4F,0xFD,0x7C,0x54}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IvbMass_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IvbMass_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    90,
    62
    };

static const MIDL_SERVER_INFO IvbMass_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IvbMass_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IvbMass_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IvbMass_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(10) _IvbMassProxyVtbl = 
{
    &IvbMass_ProxyInfo,
    &IID_IvbMass,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IvbMass::get_Eso */ ,
    (void *)-1 /* IvbMass::get_p */ ,
    (void *)-1 /* IvbMass::get_n */
};


static const PRPC_STUB_FUNCTION IvbMass_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IvbMassStubVtbl =
{
    &IID_IvbMass,
    &IvbMass_ServerInfo,
    10,
    &IvbMass_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IvbSpring, ver. 0.0,
   GUID={0x8F903BCD,0x9C46,0x4933,{0x98,0x77,0x4C,0x45,0x2E,0x8C,0xC0,0xD7}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IvbSpring_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IvbSpring_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    90,
    62
    };

static const MIDL_SERVER_INFO IvbSpring_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IvbSpring_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IvbSpring_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IvbSpring_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(10) _IvbSpringProxyVtbl = 
{
    &IvbSpring_ProxyInfo,
    &IID_IvbSpring,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IvbSpring::get_Eso */ ,
    (void *)-1 /* IvbSpring::get_p */ ,
    (void *)-1 /* IvbSpring::get_n */
};


static const PRPC_STUB_FUNCTION IvbSpring_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IvbSpringStubVtbl =
{
    &IID_IvbSpring,
    &IvbSpring_ServerInfo,
    10,
    &IvbSpring_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IvbEngine, ver. 0.0,
   GUID={0xAA69FC5D,0xA2CE,0x4CFF,{0xA9,0xF3,0xD3,0x93,0xC5,0x67,0x82,0x98}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IvbEngine_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IvbEngine_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    90,
    146,
    180
    };

static const MIDL_SERVER_INFO IvbEngine_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IvbEngine_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IvbEngine_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IvbEngine_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(11) _IvbEngineProxyVtbl = 
{
    &IvbEngine_ProxyInfo,
    &IID_IvbEngine,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IvbEngine::get_Eso */ ,
    (void *)-1 /* IvbEngine::get_n */ ,
    (void *)-1 /* IvbEngine::throttleEvent */ ,
    (void *)-1 /* IvbEngine::startEvent */
};


static const PRPC_STUB_FUNCTION IvbEngine_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IvbEngineStubVtbl =
{
    &IID_IvbEngine,
    &IvbEngine_ServerInfo,
    11,
    &IvbEngine_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IvbOneway_Clutch, ver. 0.0,
   GUID={0xC9AEA849,0x120B,0x4EA2,{0xBE,0xB2,0x11,0xEE,0x70,0xEB,0x0F,0x62}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IvbOneway_Clutch_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IvbOneway_Clutch_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    90,
    62,
    118
    };

static const MIDL_SERVER_INFO IvbOneway_Clutch_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IvbOneway_Clutch_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IvbOneway_Clutch_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IvbOneway_Clutch_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(11) _IvbOneway_ClutchProxyVtbl = 
{
    &IvbOneway_Clutch_ProxyInfo,
    &IID_IvbOneway_Clutch,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IvbOneway_Clutch::get_Eso */ ,
    (void *)-1 /* IvbOneway_Clutch::get_actuator */ ,
    (void *)-1 /* IvbOneway_Clutch::get_n */ ,
    (void *)-1 /* IvbOneway_Clutch::get_p */
};


static const PRPC_STUB_FUNCTION IvbOneway_Clutch_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IvbOneway_ClutchStubVtbl =
{
    &IID_IvbOneway_Clutch,
    &IvbOneway_Clutch_ServerInfo,
    11,
    &IvbOneway_Clutch_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IvbRavigneaux, ver. 0.0,
   GUID={0xF6220946,0xF942,0x4853,{0xA3,0x35,0x33,0xFD,0x40,0x5B,0x70,0x55}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IvbRavigneaux_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IvbRavigneaux_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    90,
    62,
    118,
    214
    };

static const MIDL_SERVER_INFO IvbRavigneaux_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IvbRavigneaux_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IvbRavigneaux_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IvbRavigneaux_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(12) _IvbRavigneauxProxyVtbl = 
{
    &IvbRavigneaux_ProxyInfo,
    &IID_IvbRavigneaux,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IvbRavigneaux::get_Eso */ ,
    (void *)-1 /* IvbRavigneaux::get_forwardSun */ ,
    (void *)-1 /* IvbRavigneaux::get_reverseSun */ ,
    (void *)-1 /* IvbRavigneaux::get_coupler */ ,
    (void *)-1 /* IvbRavigneaux::get_ring */
};


static const PRPC_STUB_FUNCTION IvbRavigneaux_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IvbRavigneauxStubVtbl =
{
    &IID_IvbRavigneaux,
    &IvbRavigneaux_ServerInfo,
    12,
    &IvbRavigneaux_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IvbTorque_Converter, ver. 0.0,
   GUID={0xC56FE92D,0xF08E,0x448C,{0x8F,0x20,0x05,0x66,0x74,0x14,0xF8,0x79}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IvbTorque_Converter_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IvbTorque_Converter_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    90,
    62
    };

static const MIDL_SERVER_INFO IvbTorque_Converter_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IvbTorque_Converter_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IvbTorque_Converter_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IvbTorque_Converter_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(10) _IvbTorque_ConverterProxyVtbl = 
{
    &IvbTorque_Converter_ProxyInfo,
    &IID_IvbTorque_Converter,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IvbTorque_Converter::get_Eso */ ,
    (void *)-1 /* IvbTorque_Converter::get_turbine */ ,
    (void *)-1 /* IvbTorque_Converter::get_impeller */
};


static const PRPC_STUB_FUNCTION IvbTorque_Converter_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IvbTorque_ConverterStubVtbl =
{
    &IID_IvbTorque_Converter,
    &IvbTorque_Converter_ServerInfo,
    10,
    &IvbTorque_Converter_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IvbVehicle, ver. 0.0,
   GUID={0xFAD2DA42,0x98D1,0x41B7,{0xB5,0x4B,0xA0,0xAB,0x35,0x9A,0xE3,0xC3}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IvbVehicle_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IvbVehicle_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    90
    };

static const MIDL_SERVER_INFO IvbVehicle_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IvbVehicle_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IvbVehicle_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IvbVehicle_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(9) _IvbVehicleProxyVtbl = 
{
    &IvbVehicle_ProxyInfo,
    &IID_IvbVehicle,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IvbVehicle::get_Eso */ ,
    (void *)-1 /* IvbVehicle::get_p */
};


static const PRPC_STUB_FUNCTION IvbVehicle_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IvbVehicleStubVtbl =
{
    &IID_IvbVehicle,
    &IvbVehicle_ServerInfo,
    9,
    &IvbVehicle_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IvbVehicle2, ver. 0.0,
   GUID={0x42DF008C,0x3E57,0x4C41,{0xB3,0xE5,0xFF,0xAA,0x1F,0x02,0x59,0x87}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IvbVehicle2_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IvbVehicle2_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    90
    };

static const MIDL_SERVER_INFO IvbVehicle2_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IvbVehicle2_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IvbVehicle2_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IvbVehicle2_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(9) _IvbVehicle2ProxyVtbl = 
{
    &IvbVehicle2_ProxyInfo,
    &IID_IvbVehicle2,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IvbVehicle2::get_Eso */ ,
    (void *)-1 /* IvbVehicle2::get_p */
};


static const PRPC_STUB_FUNCTION IvbVehicle2_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IvbVehicle2StubVtbl =
{
    &IID_IvbVehicle2,
    &IvbVehicle2_ServerInfo,
    9,
    &IvbVehicle2_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IvbVehicle5, ver. 0.0,
   GUID={0xB0C261A7,0x451A,0x42D5,{0x9D,0xB0,0xB7,0xAF,0x75,0xE7,0x49,0xBB}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IvbVehicle5_ServerInfo;

#pragma code_seg(".orpc")
static const unsigned short IvbVehicle5_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0,
    90,
    146
    };

static const MIDL_SERVER_INFO IvbVehicle5_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IvbVehicle5_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IvbVehicle5_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IvbVehicle5_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(10) _IvbVehicle5ProxyVtbl = 
{
    &IvbVehicle5_ProxyInfo,
    &IID_IvbVehicle5,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IvbVehicle5::get_Eso */ ,
    (void *)-1 /* IvbVehicle5::get_p */ ,
    (void *)-1 /* IvbVehicle5::brakeEvent */
};


static const PRPC_STUB_FUNCTION IvbVehicle5_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2,
    NdrStubCall2,
    NdrStubCall2
};

CInterfaceStubVtbl _IvbVehicle5StubVtbl =
{
    &IID_IvbVehicle5,
    &IvbVehicle5_ServerInfo,
    10,
    &IvbVehicle5_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IvbComposite, ver. 0.0,
   GUID={0xB43C1171,0x8D2A,0x4285,{0xAB,0xF0,0x01,0xA1,0x16,0x05,0xE4,0xB2}} */


extern const MIDL_STUB_DESC Object_StubDesc;


extern const MIDL_SERVER_INFO IvbComposite_ServerInfo;

#pragma code_seg(".orpc")
extern const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[1];

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

static const unsigned short IvbComposite_FormatStringOffsetTable[] = 
    {
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    (unsigned short) -1,
    0
    };

static const MIDL_SERVER_INFO IvbComposite_ServerInfo = 
    {
    &Object_StubDesc,
    0,
    __MIDL_ProcFormatString.Format,
    &IvbComposite_FormatStringOffsetTable[-3],
    0,
    0,
    0,
    0
    };

static const MIDL_STUBLESS_PROXY_INFO IvbComposite_ProxyInfo =
    {
    &Object_StubDesc,
    __MIDL_ProcFormatString.Format,
    &IvbComposite_FormatStringOffsetTable[-3],
    0,
    0,
    0
    };

CINTERFACE_PROXY_VTABLE(8) _IvbCompositeProxyVtbl = 
{
    &IvbComposite_ProxyInfo,
    &IID_IvbComposite,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfoCount */ ,
    0 /* (void *)-1 /* IDispatch::GetTypeInfo */ ,
    0 /* (void *)-1 /* IDispatch::GetIDsOfNames */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    (void *)-1 /* IvbComposite::get_Eso */
};


static const PRPC_STUB_FUNCTION IvbComposite_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    NdrStubCall2
};

CInterfaceStubVtbl _IvbCompositeStubVtbl =
{
    &IID_IvbComposite,
    &IvbComposite_ServerInfo,
    8,
    &IvbComposite_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};

#pragma data_seg(".rdata")

static const USER_MARSHAL_ROUTINE_QUADRUPLE UserMarshalRoutines[1] = 
        {
            
            {
            LPSAFEARRAY_UserSize
            ,LPSAFEARRAY_UserMarshal
            ,LPSAFEARRAY_UserUnmarshal
            ,LPSAFEARRAY_UserFree
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

	/* Procedure get_Eso */


	/* Procedure get_Eso */


	/* Procedure get_Eso */


	/* Procedure get_Eso */


	/* Procedure get_Eso */


	/* Procedure get_Eso */


	/* Procedure get_Eso */


	/* Procedure get_Eso */


	/* Procedure get_Eso */


	/* Procedure get_Eso */


	/* Procedure get_Eso */


	/* Procedure get_Eso */


	/* Procedure get_Eso */


	/* Procedure get_Eso */


	/* Procedure get_Eso */


	/* Procedure get_Eso */

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
/* 12 */	NdrFcShort( 0x8 ),	/* 8 */
/* 14 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */


	/* Parameter pVal */

/* 16 */	NdrFcShort( 0x13 ),	/* Flags:  must size, must free, out, */
#ifndef _ALPHA_
/* 18 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 20 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


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

	/* Procedure shiftEvent */

/* 28 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 30 */	NdrFcLong( 0x0 ),	/* 0 */
/* 34 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 36 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
#else
			NdrFcShort( 0x18 ),	/* MIPS & PPC Stack size/offset = 24 */
#endif
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 38 */	NdrFcShort( 0x18 ),	/* 24 */
/* 40 */	NdrFcShort( 0x8 ),	/* 8 */
/* 42 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter t */

/* 44 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 46 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* MIPS & PPC Stack size/offset = 8 */
#endif
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 48 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter val */

/* 50 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 52 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
#else
			NdrFcShort( 0x10 ),	/* MIPS & PPC Stack size/offset = 16 */
#endif
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 54 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 56 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 58 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
#else
			NdrFcShort( 0x14 ),	/* MIPS & PPC Stack size/offset = 20 */
#endif
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 60 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_impeller */


	/* Procedure get_reverseSun */


	/* Procedure get_n */


	/* Procedure get_n */


	/* Procedure get_n */


	/* Procedure get_n */


	/* Procedure get_p */


	/* Procedure get_n */


	/* Procedure get_clutch */

/* 62 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 64 */	NdrFcLong( 0x0 ),	/* 0 */
/* 68 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
/* 70 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 72 */	NdrFcShort( 0x0 ),	/* 0 */
/* 74 */	NdrFcShort( 0x8 ),	/* 8 */
/* 76 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter val */


	/* Parameter val */


	/* Parameter val */


	/* Parameter val */


	/* Parameter val */


	/* Parameter val */


	/* Parameter val */


	/* Parameter val */


	/* Parameter val */

/* 78 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
#ifndef _ALPHA_
/* 80 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 82 */	NdrFcShort( 0x3c4 ),	/* Type Offset=964 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 84 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 86 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 88 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_p */


	/* Procedure get_p */


	/* Procedure get_p */


	/* Procedure get_turbine */


	/* Procedure get_forwardSun */


	/* Procedure get_actuator */


	/* Procedure get_n */


	/* Procedure get_p */


	/* Procedure get_p */


	/* Procedure get_actuator */


	/* Procedure get_p */


	/* Procedure get_n */


	/* Procedure get_p */


	/* Procedure get_actuator */

/* 90 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 92 */	NdrFcLong( 0x0 ),	/* 0 */
/* 96 */	NdrFcShort( 0x8 ),	/* 8 */
#ifndef _ALPHA_
/* 98 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 100 */	NdrFcShort( 0x0 ),	/* 0 */
/* 102 */	NdrFcShort( 0x8 ),	/* 8 */
/* 104 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter val */


	/* Parameter val */


	/* Parameter val */


	/* Parameter val */


	/* Parameter val */


	/* Parameter val */


	/* Parameter val */


	/* Parameter val */


	/* Parameter val */


	/* Parameter val */


	/* Parameter val */


	/* Parameter val */


	/* Parameter val */


	/* Parameter val */

/* 106 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
#ifndef _ALPHA_
/* 108 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 110 */	NdrFcShort( 0x3c4 ),	/* Type Offset=964 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 112 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 114 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 116 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_coupler */


	/* Procedure get_p */


	/* Procedure get_p */


	/* Procedure get_p */

/* 118 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 120 */	NdrFcLong( 0x0 ),	/* 0 */
/* 124 */	NdrFcShort( 0xa ),	/* 10 */
#ifndef _ALPHA_
/* 126 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 128 */	NdrFcShort( 0x0 ),	/* 0 */
/* 130 */	NdrFcShort( 0x8 ),	/* 8 */
/* 132 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter val */


	/* Parameter val */


	/* Parameter val */


	/* Parameter val */

/* 134 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
#ifndef _ALPHA_
/* 136 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 138 */	NdrFcShort( 0x3c4 ),	/* Type Offset=964 */

	/* Return value */


	/* Return value */


	/* Return value */


	/* Return value */

/* 140 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 142 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 144 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure brakeEvent */


	/* Procedure throttleEvent */

/* 146 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 148 */	NdrFcLong( 0x0 ),	/* 0 */
/* 152 */	NdrFcShort( 0x9 ),	/* 9 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 154 */	NdrFcShort( 0x18 ),	/* x86 Stack size/offset = 24 */
#else
			NdrFcShort( 0x1c ),	/* MIPS & PPC Stack size/offset = 28 */
#endif
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 156 */	NdrFcShort( 0x20 ),	/* 32 */
/* 158 */	NdrFcShort( 0x8 ),	/* 8 */
/* 160 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter t */


	/* Parameter t */

/* 162 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 164 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* MIPS & PPC Stack size/offset = 8 */
#endif
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 166 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter val */


	/* Parameter val */

/* 168 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 170 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
#else
			NdrFcShort( 0x10 ),	/* MIPS & PPC Stack size/offset = 16 */
#endif
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 172 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Return value */


	/* Return value */

/* 174 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 176 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
#else
			NdrFcShort( 0x18 ),	/* MIPS & PPC Stack size/offset = 24 */
#endif
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 178 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure startEvent */

/* 180 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 182 */	NdrFcLong( 0x0 ),	/* 0 */
/* 186 */	NdrFcShort( 0xa ),	/* 10 */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 188 */	NdrFcShort( 0x14 ),	/* x86 Stack size/offset = 20 */
#else
			NdrFcShort( 0x18 ),	/* MIPS & PPC Stack size/offset = 24 */
#endif
#else
			NdrFcShort( 0x20 ),	/* Alpha Stack size/offset = 32 */
#endif
/* 190 */	NdrFcShort( 0x18 ),	/* 24 */
/* 192 */	NdrFcShort( 0x8 ),	/* 8 */
/* 194 */	0x4,		/* Oi2 Flags:  has return, */
			0x3,		/* 3 */

	/* Parameter t */

/* 196 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 198 */	NdrFcShort( 0x4 ),	/* x86 Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* MIPS & PPC Stack size/offset = 8 */
#endif
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 200 */	0xc,		/* FC_DOUBLE */
			0x0,		/* 0 */

	/* Parameter val */

/* 202 */	NdrFcShort( 0x48 ),	/* Flags:  in, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 204 */	NdrFcShort( 0xc ),	/* x86 Stack size/offset = 12 */
#else
			NdrFcShort( 0x10 ),	/* MIPS & PPC Stack size/offset = 16 */
#endif
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 206 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Return value */

/* 208 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
#if !defined(_MIPS_) && !defined(_PPC_)
/* 210 */	NdrFcShort( 0x10 ),	/* x86 Stack size/offset = 16 */
#else
			NdrFcShort( 0x14 ),	/* MIPS & PPC Stack size/offset = 20 */
#endif
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 212 */	0x8,		/* FC_LONG */
			0x0,		/* 0 */

	/* Procedure get_ring */

/* 214 */	0x33,		/* FC_AUTO_HANDLE */
			0x6c,		/* Old Flags:  object, Oi2 */
/* 216 */	NdrFcLong( 0x0 ),	/* 0 */
/* 220 */	NdrFcShort( 0xb ),	/* 11 */
#ifndef _ALPHA_
/* 222 */	NdrFcShort( 0xc ),	/* x86, MIPS, PPC Stack size/offset = 12 */
#else
			NdrFcShort( 0x18 ),	/* Alpha Stack size/offset = 24 */
#endif
/* 224 */	NdrFcShort( 0x0 ),	/* 0 */
/* 226 */	NdrFcShort( 0x8 ),	/* 8 */
/* 228 */	0x5,		/* Oi2 Flags:  srv must size, has return, */
			0x2,		/* 2 */

	/* Parameter val */

/* 230 */	NdrFcShort( 0x113 ),	/* Flags:  must size, must free, out, simple ref, */
#ifndef _ALPHA_
/* 232 */	NdrFcShort( 0x4 ),	/* x86, MIPS, PPC Stack size/offset = 4 */
#else
			NdrFcShort( 0x8 ),	/* Alpha Stack size/offset = 8 */
#endif
/* 234 */	NdrFcShort( 0x3c4 ),	/* Type Offset=964 */

	/* Return value */

/* 236 */	NdrFcShort( 0x70 ),	/* Flags:  out, return, base type, */
#ifndef _ALPHA_
/* 238 */	NdrFcShort( 0x8 ),	/* x86, MIPS, PPC Stack size/offset = 8 */
#else
			NdrFcShort( 0x10 ),	/* Alpha Stack size/offset = 16 */
#endif
/* 240 */	0x8,		/* FC_LONG */
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
			0x11, 0x10,	/* FC_RP */
/*  4 */	NdrFcShort( 0x2 ),	/* Offset= 2 (6) */
/*  6 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/*  8 */	NdrFcLong( 0x20400 ),	/* 132096 */
/* 12 */	NdrFcShort( 0x0 ),	/* 0 */
/* 14 */	NdrFcShort( 0x0 ),	/* 0 */
/* 16 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 18 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 20 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 22 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 24 */	
			0x11, 0x4,	/* FC_RP [alloced_on_stack] */
/* 26 */	NdrFcShort( 0x3aa ),	/* Offset= 938 (964) */
/* 28 */	
			0x13, 0x10,	/* FC_OP */
/* 30 */	NdrFcShort( 0x2 ),	/* Offset= 2 (32) */
/* 32 */	
			0x13, 0x0,	/* FC_OP */
/* 34 */	NdrFcShort( 0x390 ),	/* Offset= 912 (946) */
/* 36 */	
			0x2a,		/* FC_ENCAPSULATED_UNION */
			0x49,		/* 73 */
/* 38 */	NdrFcShort( 0x18 ),	/* 24 */
/* 40 */	NdrFcShort( 0xa ),	/* 10 */
/* 42 */	NdrFcLong( 0x8 ),	/* 8 */
/* 46 */	NdrFcShort( 0x6c ),	/* Offset= 108 (154) */
/* 48 */	NdrFcLong( 0xd ),	/* 13 */
/* 52 */	NdrFcShort( 0x9e ),	/* Offset= 158 (210) */
/* 54 */	NdrFcLong( 0x9 ),	/* 9 */
/* 58 */	NdrFcShort( 0xba ),	/* Offset= 186 (244) */
/* 60 */	NdrFcLong( 0xc ),	/* 12 */
/* 64 */	NdrFcShort( 0x280 ),	/* Offset= 640 (704) */
/* 66 */	NdrFcLong( 0x24 ),	/* 36 */
/* 70 */	NdrFcShort( 0x2a8 ),	/* Offset= 680 (750) */
/* 72 */	NdrFcLong( 0x800d ),	/* 32781 */
/* 76 */	NdrFcShort( 0x2c4 ),	/* Offset= 708 (784) */
/* 78 */	NdrFcLong( 0x10 ),	/* 16 */
/* 82 */	NdrFcShort( 0x2dc ),	/* Offset= 732 (814) */
/* 84 */	NdrFcLong( 0x2 ),	/* 2 */
/* 88 */	NdrFcShort( 0x2f4 ),	/* Offset= 756 (844) */
/* 90 */	NdrFcLong( 0x3 ),	/* 3 */
/* 94 */	NdrFcShort( 0x30c ),	/* Offset= 780 (874) */
/* 96 */	NdrFcLong( 0x14 ),	/* 20 */
/* 100 */	NdrFcShort( 0x324 ),	/* Offset= 804 (904) */
/* 102 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (101) */
/* 104 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 106 */	NdrFcShort( 0x2 ),	/* 2 */
/* 108 */	0x9,		/* Corr desc: FC_ULONG */
			0x0,		/*  */
/* 110 */	NdrFcShort( 0xfffc ),	/* -4 */
/* 112 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 114 */	
			0x17,		/* FC_CSTRUCT */
			0x3,		/* 3 */
/* 116 */	NdrFcShort( 0x8 ),	/* 8 */
/* 118 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (104) */
/* 120 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 122 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 124 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 126 */	NdrFcShort( 0x4 ),	/* 4 */
/* 128 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 130 */	NdrFcShort( 0x0 ),	/* 0 */
/* 132 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 134 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 136 */	NdrFcShort( 0x4 ),	/* 4 */
/* 138 */	NdrFcShort( 0x0 ),	/* 0 */
/* 140 */	NdrFcShort( 0x1 ),	/* 1 */
/* 142 */	NdrFcShort( 0x0 ),	/* 0 */
/* 144 */	NdrFcShort( 0x0 ),	/* 0 */
/* 146 */	0x13, 0x0,	/* FC_OP */
/* 148 */	NdrFcShort( 0xffffffde ),	/* Offset= -34 (114) */
/* 150 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 152 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 154 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 156 */	NdrFcShort( 0x8 ),	/* 8 */
/* 158 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 160 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 162 */	NdrFcShort( 0x4 ),	/* 4 */
/* 164 */	NdrFcShort( 0x4 ),	/* 4 */
/* 166 */	0x11, 0x0,	/* FC_RP */
/* 168 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (124) */
/* 170 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 172 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 174 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 176 */	NdrFcLong( 0x0 ),	/* 0 */
/* 180 */	NdrFcShort( 0x0 ),	/* 0 */
/* 182 */	NdrFcShort( 0x0 ),	/* 0 */
/* 184 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 186 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 188 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 190 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 192 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 194 */	NdrFcShort( 0x0 ),	/* 0 */
/* 196 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 198 */	NdrFcShort( 0x0 ),	/* 0 */
/* 200 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 204 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 206 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (174) */
/* 208 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 210 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 212 */	NdrFcShort( 0x8 ),	/* 8 */
/* 214 */	NdrFcShort( 0x0 ),	/* 0 */
/* 216 */	NdrFcShort( 0x6 ),	/* Offset= 6 (222) */
/* 218 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 220 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 222 */	
			0x11, 0x0,	/* FC_RP */
/* 224 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (192) */
/* 226 */	
			0x21,		/* FC_BOGUS_ARRAY */
			0x3,		/* 3 */
/* 228 */	NdrFcShort( 0x0 ),	/* 0 */
/* 230 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 232 */	NdrFcShort( 0x0 ),	/* 0 */
/* 234 */	NdrFcLong( 0xffffffff ),	/* -1 */
/* 238 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 240 */	NdrFcShort( 0xffffff16 ),	/* Offset= -234 (6) */
/* 242 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 244 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 246 */	NdrFcShort( 0x8 ),	/* 8 */
/* 248 */	NdrFcShort( 0x0 ),	/* 0 */
/* 250 */	NdrFcShort( 0x6 ),	/* Offset= 6 (256) */
/* 252 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 254 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 256 */	
			0x11, 0x0,	/* FC_RP */
/* 258 */	NdrFcShort( 0xffffffe0 ),	/* Offset= -32 (226) */
/* 260 */	
			0x2b,		/* FC_NON_ENCAPSULATED_UNION */
			0x9,		/* FC_ULONG */
/* 262 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 264 */	NdrFcShort( 0xfff8 ),	/* -8 */
/* 266 */	NdrFcShort( 0x2 ),	/* Offset= 2 (268) */
/* 268 */	NdrFcShort( 0x10 ),	/* 16 */
/* 270 */	NdrFcShort( 0x2b ),	/* 43 */
/* 272 */	NdrFcLong( 0x3 ),	/* 3 */
/* 276 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 278 */	NdrFcLong( 0x11 ),	/* 17 */
/* 282 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 284 */	NdrFcLong( 0x2 ),	/* 2 */
/* 288 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 290 */	NdrFcLong( 0x4 ),	/* 4 */
/* 294 */	NdrFcShort( 0x800a ),	/* Simple arm type: FC_FLOAT */
/* 296 */	NdrFcLong( 0x5 ),	/* 5 */
/* 300 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 302 */	NdrFcLong( 0xb ),	/* 11 */
/* 306 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 308 */	NdrFcLong( 0xa ),	/* 10 */
/* 312 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 314 */	NdrFcLong( 0x6 ),	/* 6 */
/* 318 */	NdrFcShort( 0xd6 ),	/* Offset= 214 (532) */
/* 320 */	NdrFcLong( 0x7 ),	/* 7 */
/* 324 */	NdrFcShort( 0x800c ),	/* Simple arm type: FC_DOUBLE */
/* 326 */	NdrFcLong( 0x8 ),	/* 8 */
/* 330 */	NdrFcShort( 0xd0 ),	/* Offset= 208 (538) */
/* 332 */	NdrFcLong( 0xd ),	/* 13 */
/* 336 */	NdrFcShort( 0xffffff5e ),	/* Offset= -162 (174) */
/* 338 */	NdrFcLong( 0x9 ),	/* 9 */
/* 342 */	NdrFcShort( 0xfffffeb0 ),	/* Offset= -336 (6) */
/* 344 */	NdrFcLong( 0x2000 ),	/* 8192 */
/* 348 */	NdrFcShort( 0xc2 ),	/* Offset= 194 (542) */
/* 350 */	NdrFcLong( 0x24 ),	/* 36 */
/* 354 */	NdrFcShort( 0xc0 ),	/* Offset= 192 (546) */
/* 356 */	NdrFcLong( 0x4024 ),	/* 16420 */
/* 360 */	NdrFcShort( 0xba ),	/* Offset= 186 (546) */
/* 362 */	NdrFcLong( 0x4011 ),	/* 16401 */
/* 366 */	NdrFcShort( 0xe8 ),	/* Offset= 232 (598) */
/* 368 */	NdrFcLong( 0x4002 ),	/* 16386 */
/* 372 */	NdrFcShort( 0xe6 ),	/* Offset= 230 (602) */
/* 374 */	NdrFcLong( 0x4003 ),	/* 16387 */
/* 378 */	NdrFcShort( 0xe4 ),	/* Offset= 228 (606) */
/* 380 */	NdrFcLong( 0x4004 ),	/* 16388 */
/* 384 */	NdrFcShort( 0xe2 ),	/* Offset= 226 (610) */
/* 386 */	NdrFcLong( 0x4005 ),	/* 16389 */
/* 390 */	NdrFcShort( 0xe0 ),	/* Offset= 224 (614) */
/* 392 */	NdrFcLong( 0x400b ),	/* 16395 */
/* 396 */	NdrFcShort( 0xce ),	/* Offset= 206 (602) */
/* 398 */	NdrFcLong( 0x400a ),	/* 16394 */
/* 402 */	NdrFcShort( 0xcc ),	/* Offset= 204 (606) */
/* 404 */	NdrFcLong( 0x4006 ),	/* 16390 */
/* 408 */	NdrFcShort( 0xd2 ),	/* Offset= 210 (618) */
/* 410 */	NdrFcLong( 0x4007 ),	/* 16391 */
/* 414 */	NdrFcShort( 0xc8 ),	/* Offset= 200 (614) */
/* 416 */	NdrFcLong( 0x4008 ),	/* 16392 */
/* 420 */	NdrFcShort( 0xca ),	/* Offset= 202 (622) */
/* 422 */	NdrFcLong( 0x400d ),	/* 16397 */
/* 426 */	NdrFcShort( 0xc8 ),	/* Offset= 200 (626) */
/* 428 */	NdrFcLong( 0x4009 ),	/* 16393 */
/* 432 */	NdrFcShort( 0xc6 ),	/* Offset= 198 (630) */
/* 434 */	NdrFcLong( 0x6000 ),	/* 24576 */
/* 438 */	NdrFcShort( 0xc4 ),	/* Offset= 196 (634) */
/* 440 */	NdrFcLong( 0x400c ),	/* 16396 */
/* 444 */	NdrFcShort( 0xbe ),	/* Offset= 190 (634) */
/* 446 */	NdrFcLong( 0x10 ),	/* 16 */
/* 450 */	NdrFcShort( 0x8002 ),	/* Simple arm type: FC_CHAR */
/* 452 */	NdrFcLong( 0x12 ),	/* 18 */
/* 456 */	NdrFcShort( 0x8006 ),	/* Simple arm type: FC_SHORT */
/* 458 */	NdrFcLong( 0x13 ),	/* 19 */
/* 462 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 464 */	NdrFcLong( 0x16 ),	/* 22 */
/* 468 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 470 */	NdrFcLong( 0x17 ),	/* 23 */
/* 474 */	NdrFcShort( 0x8008 ),	/* Simple arm type: FC_LONG */
/* 476 */	NdrFcLong( 0xe ),	/* 14 */
/* 480 */	NdrFcShort( 0x9e ),	/* Offset= 158 (638) */
/* 482 */	NdrFcLong( 0x400e ),	/* 16398 */
/* 486 */	NdrFcShort( 0xa4 ),	/* Offset= 164 (650) */
/* 488 */	NdrFcLong( 0x4010 ),	/* 16400 */
/* 492 */	NdrFcShort( 0x6a ),	/* Offset= 106 (598) */
/* 494 */	NdrFcLong( 0x4012 ),	/* 16402 */
/* 498 */	NdrFcShort( 0x68 ),	/* Offset= 104 (602) */
/* 500 */	NdrFcLong( 0x4013 ),	/* 16403 */
/* 504 */	NdrFcShort( 0x66 ),	/* Offset= 102 (606) */
/* 506 */	NdrFcLong( 0x4016 ),	/* 16406 */
/* 510 */	NdrFcShort( 0x60 ),	/* Offset= 96 (606) */
/* 512 */	NdrFcLong( 0x4017 ),	/* 16407 */
/* 516 */	NdrFcShort( 0x5a ),	/* Offset= 90 (606) */
/* 518 */	NdrFcLong( 0x0 ),	/* 0 */
/* 522 */	NdrFcShort( 0x0 ),	/* Offset= 0 (522) */
/* 524 */	NdrFcLong( 0x1 ),	/* 1 */
/* 528 */	NdrFcShort( 0x0 ),	/* Offset= 0 (528) */
/* 530 */	NdrFcShort( 0xffffffff ),	/* Offset= -1 (529) */
/* 532 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 534 */	NdrFcShort( 0x8 ),	/* 8 */
/* 536 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 538 */	
			0x13, 0x0,	/* FC_OP */
/* 540 */	NdrFcShort( 0xfffffe56 ),	/* Offset= -426 (114) */
/* 542 */	
			0x13, 0x0,	/* FC_OP */
/* 544 */	NdrFcShort( 0x192 ),	/* Offset= 402 (946) */
/* 546 */	
			0x13, 0x0,	/* FC_OP */
/* 548 */	NdrFcShort( 0x1e ),	/* Offset= 30 (578) */
/* 550 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 552 */	NdrFcLong( 0x2f ),	/* 47 */
/* 556 */	NdrFcShort( 0x0 ),	/* 0 */
/* 558 */	NdrFcShort( 0x0 ),	/* 0 */
/* 560 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 562 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 564 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 566 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 568 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 570 */	NdrFcShort( 0x1 ),	/* 1 */
/* 572 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 574 */	NdrFcShort( 0x4 ),	/* 4 */
/* 576 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 578 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 580 */	NdrFcShort( 0x10 ),	/* 16 */
/* 582 */	NdrFcShort( 0x0 ),	/* 0 */
/* 584 */	NdrFcShort( 0xa ),	/* Offset= 10 (594) */
/* 586 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 588 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 590 */	NdrFcShort( 0xffffffd8 ),	/* Offset= -40 (550) */
/* 592 */	0x36,		/* FC_POINTER */
			0x5b,		/* FC_END */
/* 594 */	
			0x13, 0x0,	/* FC_OP */
/* 596 */	NdrFcShort( 0xffffffe4 ),	/* Offset= -28 (568) */
/* 598 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 600 */	0x2,		/* FC_CHAR */
			0x5c,		/* FC_PAD */
/* 602 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 604 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 606 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 608 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 610 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 612 */	0xa,		/* FC_FLOAT */
			0x5c,		/* FC_PAD */
/* 614 */	
			0x13, 0x8,	/* FC_OP [simple_pointer] */
/* 616 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 618 */	
			0x13, 0x0,	/* FC_OP */
/* 620 */	NdrFcShort( 0xffffffa8 ),	/* Offset= -88 (532) */
/* 622 */	
			0x13, 0x10,	/* FC_OP */
/* 624 */	NdrFcShort( 0xffffffaa ),	/* Offset= -86 (538) */
/* 626 */	
			0x13, 0x10,	/* FC_OP */
/* 628 */	NdrFcShort( 0xfffffe3a ),	/* Offset= -454 (174) */
/* 630 */	
			0x13, 0x10,	/* FC_OP */
/* 632 */	NdrFcShort( 0xfffffd8e ),	/* Offset= -626 (6) */
/* 634 */	
			0x13, 0x10,	/* FC_OP */
/* 636 */	NdrFcShort( 0xffffffa2 ),	/* Offset= -94 (542) */
/* 638 */	
			0x15,		/* FC_STRUCT */
			0x7,		/* 7 */
/* 640 */	NdrFcShort( 0x10 ),	/* 16 */
/* 642 */	0x6,		/* FC_SHORT */
			0x2,		/* FC_CHAR */
/* 644 */	0x2,		/* FC_CHAR */
			0x38,		/* FC_ALIGNM4 */
/* 646 */	0x8,		/* FC_LONG */
			0x39,		/* FC_ALIGNM8 */
/* 648 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 650 */	
			0x13, 0x0,	/* FC_OP */
/* 652 */	NdrFcShort( 0xfffffff2 ),	/* Offset= -14 (638) */
/* 654 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x7,		/* 7 */
/* 656 */	NdrFcShort( 0x20 ),	/* 32 */
/* 658 */	NdrFcShort( 0x0 ),	/* 0 */
/* 660 */	NdrFcShort( 0x0 ),	/* Offset= 0 (660) */
/* 662 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 664 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 666 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 668 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 670 */	NdrFcShort( 0xfffffe66 ),	/* Offset= -410 (260) */
/* 672 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 674 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 676 */	NdrFcShort( 0x4 ),	/* 4 */
/* 678 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 680 */	NdrFcShort( 0x0 ),	/* 0 */
/* 682 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 684 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 686 */	NdrFcShort( 0x4 ),	/* 4 */
/* 688 */	NdrFcShort( 0x0 ),	/* 0 */
/* 690 */	NdrFcShort( 0x1 ),	/* 1 */
/* 692 */	NdrFcShort( 0x0 ),	/* 0 */
/* 694 */	NdrFcShort( 0x0 ),	/* 0 */
/* 696 */	0x13, 0x0,	/* FC_OP */
/* 698 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (654) */
/* 700 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 702 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 704 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 706 */	NdrFcShort( 0x8 ),	/* 8 */
/* 708 */	NdrFcShort( 0x0 ),	/* 0 */
/* 710 */	NdrFcShort( 0x6 ),	/* Offset= 6 (716) */
/* 712 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 714 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 716 */	
			0x11, 0x0,	/* FC_RP */
/* 718 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (674) */
/* 720 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 722 */	NdrFcShort( 0x4 ),	/* 4 */
/* 724 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 726 */	NdrFcShort( 0x0 ),	/* 0 */
/* 728 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 730 */	
			0x48,		/* FC_VARIABLE_REPEAT */
			0x49,		/* FC_FIXED_OFFSET */
/* 732 */	NdrFcShort( 0x4 ),	/* 4 */
/* 734 */	NdrFcShort( 0x0 ),	/* 0 */
/* 736 */	NdrFcShort( 0x1 ),	/* 1 */
/* 738 */	NdrFcShort( 0x0 ),	/* 0 */
/* 740 */	NdrFcShort( 0x0 ),	/* 0 */
/* 742 */	0x13, 0x0,	/* FC_OP */
/* 744 */	NdrFcShort( 0xffffff5a ),	/* Offset= -166 (578) */
/* 746 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 748 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 750 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 752 */	NdrFcShort( 0x8 ),	/* 8 */
/* 754 */	NdrFcShort( 0x0 ),	/* 0 */
/* 756 */	NdrFcShort( 0x6 ),	/* Offset= 6 (762) */
/* 758 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 760 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 762 */	
			0x11, 0x0,	/* FC_RP */
/* 764 */	NdrFcShort( 0xffffffd4 ),	/* Offset= -44 (720) */
/* 766 */	
			0x1d,		/* FC_SMFARRAY */
			0x0,		/* 0 */
/* 768 */	NdrFcShort( 0x8 ),	/* 8 */
/* 770 */	0x2,		/* FC_CHAR */
			0x5b,		/* FC_END */
/* 772 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 774 */	NdrFcShort( 0x10 ),	/* 16 */
/* 776 */	0x8,		/* FC_LONG */
			0x6,		/* FC_SHORT */
/* 778 */	0x6,		/* FC_SHORT */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 780 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffff1 ),	/* Offset= -15 (766) */
			0x5b,		/* FC_END */
/* 784 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 786 */	NdrFcShort( 0x18 ),	/* 24 */
/* 788 */	NdrFcShort( 0x0 ),	/* 0 */
/* 790 */	NdrFcShort( 0xa ),	/* Offset= 10 (800) */
/* 792 */	0x8,		/* FC_LONG */
			0x36,		/* FC_POINTER */
/* 794 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 796 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (772) */
/* 798 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 800 */	
			0x11, 0x0,	/* FC_RP */
/* 802 */	NdrFcShort( 0xfffffd9e ),	/* Offset= -610 (192) */
/* 804 */	
			0x1b,		/* FC_CARRAY */
			0x0,		/* 0 */
/* 806 */	NdrFcShort( 0x1 ),	/* 1 */
/* 808 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 810 */	NdrFcShort( 0x0 ),	/* 0 */
/* 812 */	0x1,		/* FC_BYTE */
			0x5b,		/* FC_END */
/* 814 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 816 */	NdrFcShort( 0x8 ),	/* 8 */
/* 818 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 820 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 822 */	NdrFcShort( 0x4 ),	/* 4 */
/* 824 */	NdrFcShort( 0x4 ),	/* 4 */
/* 826 */	0x13, 0x0,	/* FC_OP */
/* 828 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (804) */
/* 830 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 832 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 834 */	
			0x1b,		/* FC_CARRAY */
			0x1,		/* 1 */
/* 836 */	NdrFcShort( 0x2 ),	/* 2 */
/* 838 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 840 */	NdrFcShort( 0x0 ),	/* 0 */
/* 842 */	0x6,		/* FC_SHORT */
			0x5b,		/* FC_END */
/* 844 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 846 */	NdrFcShort( 0x8 ),	/* 8 */
/* 848 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 850 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 852 */	NdrFcShort( 0x4 ),	/* 4 */
/* 854 */	NdrFcShort( 0x4 ),	/* 4 */
/* 856 */	0x13, 0x0,	/* FC_OP */
/* 858 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (834) */
/* 860 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 862 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 864 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 866 */	NdrFcShort( 0x4 ),	/* 4 */
/* 868 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 870 */	NdrFcShort( 0x0 ),	/* 0 */
/* 872 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 874 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 876 */	NdrFcShort( 0x8 ),	/* 8 */
/* 878 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 880 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 882 */	NdrFcShort( 0x4 ),	/* 4 */
/* 884 */	NdrFcShort( 0x4 ),	/* 4 */
/* 886 */	0x13, 0x0,	/* FC_OP */
/* 888 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (864) */
/* 890 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 892 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 894 */	
			0x1b,		/* FC_CARRAY */
			0x7,		/* 7 */
/* 896 */	NdrFcShort( 0x8 ),	/* 8 */
/* 898 */	0x19,		/* Corr desc:  field pointer, FC_ULONG */
			0x0,		/*  */
/* 900 */	NdrFcShort( 0x0 ),	/* 0 */
/* 902 */	0xb,		/* FC_HYPER */
			0x5b,		/* FC_END */
/* 904 */	
			0x16,		/* FC_PSTRUCT */
			0x3,		/* 3 */
/* 906 */	NdrFcShort( 0x8 ),	/* 8 */
/* 908 */	
			0x4b,		/* FC_PP */
			0x5c,		/* FC_PAD */
/* 910 */	
			0x46,		/* FC_NO_REPEAT */
			0x5c,		/* FC_PAD */
/* 912 */	NdrFcShort( 0x4 ),	/* 4 */
/* 914 */	NdrFcShort( 0x4 ),	/* 4 */
/* 916 */	0x13, 0x0,	/* FC_OP */
/* 918 */	NdrFcShort( 0xffffffe8 ),	/* Offset= -24 (894) */
/* 920 */	
			0x5b,		/* FC_END */

			0x8,		/* FC_LONG */
/* 922 */	0x8,		/* FC_LONG */
			0x5b,		/* FC_END */
/* 924 */	
			0x15,		/* FC_STRUCT */
			0x3,		/* 3 */
/* 926 */	NdrFcShort( 0x8 ),	/* 8 */
/* 928 */	0x8,		/* FC_LONG */
			0x8,		/* FC_LONG */
/* 930 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 932 */	
			0x1b,		/* FC_CARRAY */
			0x3,		/* 3 */
/* 934 */	NdrFcShort( 0x8 ),	/* 8 */
/* 936 */	0x7,		/* Corr desc: FC_USHORT */
			0x0,		/*  */
/* 938 */	NdrFcShort( 0xffd8 ),	/* -40 */
/* 940 */	0x4c,		/* FC_EMBEDDED_COMPLEX */
			0x0,		/* 0 */
/* 942 */	NdrFcShort( 0xffffffee ),	/* Offset= -18 (924) */
/* 944 */	0x5c,		/* FC_PAD */
			0x5b,		/* FC_END */
/* 946 */	
			0x1a,		/* FC_BOGUS_STRUCT */
			0x3,		/* 3 */
/* 948 */	NdrFcShort( 0x28 ),	/* 40 */
/* 950 */	NdrFcShort( 0xffffffee ),	/* Offset= -18 (932) */
/* 952 */	NdrFcShort( 0x0 ),	/* Offset= 0 (952) */
/* 954 */	0x6,		/* FC_SHORT */
			0x6,		/* FC_SHORT */
/* 956 */	0x38,		/* FC_ALIGNM4 */
			0x8,		/* FC_LONG */
/* 958 */	0x8,		/* FC_LONG */
			0x4c,		/* FC_EMBEDDED_COMPLEX */
/* 960 */	0x0,		/* 0 */
			NdrFcShort( 0xfffffc63 ),	/* Offset= -925 (36) */
			0x5b,		/* FC_END */
/* 964 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 966 */	NdrFcShort( 0x0 ),	/* 0 */
/* 968 */	NdrFcShort( 0x4 ),	/* 4 */
/* 970 */	NdrFcShort( 0x0 ),	/* 0 */
/* 972 */	NdrFcShort( 0xfffffc50 ),	/* Offset= -944 (28) */

			0x0
        }
    };

const CInterfaceProxyVtbl * _RtsOnTransmissionVB_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IvbDamperProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IvbMassProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IvbTorque_ConverterProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IvbBrakeActuatorProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IvbVehicleProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IvbRavigneauxProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IvbOneway_ClutchProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IvbEngineProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IvbCompositeProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IvbVehicle2ProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IvbFrameProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IvbVehicle5ProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IvbBand_BrakeProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IvbSpringProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IvbActuatorProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IvbClutchProxyVtbl,
    0
};

const CInterfaceStubVtbl * _RtsOnTransmissionVB_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IvbDamperStubVtbl,
    ( CInterfaceStubVtbl *) &_IvbMassStubVtbl,
    ( CInterfaceStubVtbl *) &_IvbTorque_ConverterStubVtbl,
    ( CInterfaceStubVtbl *) &_IvbBrakeActuatorStubVtbl,
    ( CInterfaceStubVtbl *) &_IvbVehicleStubVtbl,
    ( CInterfaceStubVtbl *) &_IvbRavigneauxStubVtbl,
    ( CInterfaceStubVtbl *) &_IvbOneway_ClutchStubVtbl,
    ( CInterfaceStubVtbl *) &_IvbEngineStubVtbl,
    ( CInterfaceStubVtbl *) &_IvbCompositeStubVtbl,
    ( CInterfaceStubVtbl *) &_IvbVehicle2StubVtbl,
    ( CInterfaceStubVtbl *) &_IvbFrameStubVtbl,
    ( CInterfaceStubVtbl *) &_IvbVehicle5StubVtbl,
    ( CInterfaceStubVtbl *) &_IvbBand_BrakeStubVtbl,
    ( CInterfaceStubVtbl *) &_IvbSpringStubVtbl,
    ( CInterfaceStubVtbl *) &_IvbActuatorStubVtbl,
    ( CInterfaceStubVtbl *) &_IvbClutchStubVtbl,
    0
};

PCInterfaceName const _RtsOnTransmissionVB_InterfaceNamesList[] = 
{
    "IvbDamper",
    "IvbMass",
    "IvbTorque_Converter",
    "IvbBrakeActuator",
    "IvbVehicle",
    "IvbRavigneaux",
    "IvbOneway_Clutch",
    "IvbEngine",
    "IvbComposite",
    "IvbVehicle2",
    "IvbFrame",
    "IvbVehicle5",
    "IvbBand_Brake",
    "IvbSpring",
    "IvbActuator",
    "IvbClutch",
    0
};

const IID *  _RtsOnTransmissionVB_BaseIIDList[] = 
{
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    &IID_IDispatch,
    0
};


#define _RtsOnTransmissionVB_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _RtsOnTransmissionVB, pIID, n)

int __stdcall _RtsOnTransmissionVB_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _RtsOnTransmissionVB, 16, 8 )
    IID_BS_LOOKUP_NEXT_TEST( _RtsOnTransmissionVB, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _RtsOnTransmissionVB, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _RtsOnTransmissionVB, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _RtsOnTransmissionVB, 16, *pIndex )
    
}

const ExtendedProxyFileInfo RtsOnTransmissionVB_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _RtsOnTransmissionVB_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _RtsOnTransmissionVB_StubVtblList,
    (const PCInterfaceName * ) & _RtsOnTransmissionVB_InterfaceNamesList,
    (const IID ** ) & _RtsOnTransmissionVB_BaseIIDList,
    & _RtsOnTransmissionVB_IID_Lookup, 
    16,
    2,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
