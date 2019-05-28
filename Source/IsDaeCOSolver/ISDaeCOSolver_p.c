/* this ALWAYS GENERATED file contains the proxy stub code */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Jun 30 00:50:37 2003
 */
/* Compiler settings for C:\DistComponents\idl\ISDaeCOSolver.idl:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcproxy.h> version is high enough to compile this file*/
#ifndef __REDQ_RPCPROXY_H_VERSION__
#define __REQUIRED_RPCPROXY_H_VERSION__ 440
#endif


#include "rpcproxy.h"
#ifndef __RPCPROXY_H_VERSION__
#error this stub requires an updated version of <rpcproxy.h>
#endif // __RPCPROXY_H_VERSION__


#include "IsDaeCOSolver.h"

#define TYPE_FORMAT_STRING_SIZE   1187                              
#define PROC_FORMAT_STRING_SIZE   769                               

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


/* Standard interface: __MIDL_itf_ISDaeCOSolver_0000, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}} */


/* Object interface: IUnknown, ver. 0.0,
   GUID={0x00000000,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IDispatch, ver. 0.0,
   GUID={0x00020400,0x0000,0x0000,{0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46}} */


/* Object interface: IIsDaeEso, ver. 0.0,
   GUID={0xEFA96FD0,0xB83D,0x11d4,{0x83,0x9B,0x00,0x60,0x08,0x94,0xE8,0x02}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_SetRelTolerance_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *relTolValue)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      7);
        
        
        
        if(!relTolValue)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)relTolValue,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[960] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)relTolValue,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[960] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[0] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_SetRelTolerance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *relTolValue;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )relTolValue = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[0] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&relTolValue,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[960],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetRelTolerance((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,relTolValue);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)relTolValue,
                        &__MIDL_TypeFormatString.Format[2] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetRelTolerance_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *relTolValue)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      8);
        
        
        
        if(!relTolValue)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[6] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&relTolValue,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )relTolValue);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetRelTolerance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *relTolValue;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )relTolValue = 0;
    RpcTryFinally
        {
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetRelTolerance((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,relTolValue);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)relTolValue,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)relTolValue,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)relTolValue,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_SetAbsTolerance_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *absTolValues)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      9);
        
        
        
        if(!absTolValues)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)absTolValues,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)absTolValues,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[12] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_SetAbsTolerance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *absTolValues;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )absTolValues = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[12] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&absTolValues,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetAbsTolerance((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,absTolValues);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)absTolValues,
                        &__MIDL_TypeFormatString.Format[992] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetAbsTolerance_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *absTolValues)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      10);
        
        
        
        if(!absTolValues)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[6] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&absTolValues,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )absTolValues);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetAbsTolerance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *absTolValues;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )absTolValues = 0;
    RpcTryFinally
        {
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetAbsTolerance((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,absTolValues);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)absTolValues,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)absTolValues,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)absTolValues,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetAllResiduals_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *residuals,
    /* [out][in] */ VARIANT_BOOL __RPC_FAR *validVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      11);
        
        
        
        if(!residuals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!validVal)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U + 5U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)residuals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)residuals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 1) & ~ 0x1);
            *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++ = *validVal;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[18] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&residuals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 1) & ~ 0x1);
            *validVal = *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++;
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )residuals);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1006],
                         ( void __RPC_FAR * )validVal);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetAllResiduals_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *residuals;
    VARIANT_BOOL __RPC_FAR *validVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )residuals = 0;
    ( VARIANT_BOOL __RPC_FAR * )validVal = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[18] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&residuals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 1) & ~ 0x1);
        validVal = ( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( VARIANT_BOOL  );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetAllResiduals(
                   (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
                   residuals,
                   validVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 5U + 10U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)residuals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)residuals,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 1) & ~ 0x1);
        *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++ = *validVal;
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)residuals,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetResiduals_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *residuals,
    /* [out][in] */ VARIANT_BOOL __RPC_FAR *validVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      12);
        
        
        
        if(!Indices)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!residuals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!validVal)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U + 0U + 5U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Indices,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)residuals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Indices,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)residuals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 1) & ~ 0x1);
            *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++ = *validVal;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[28] );
            
            *validVal = *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++;
            
            _StubMsg.Buffer += 2;
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1006],
                         ( void __RPC_FAR * )validVal);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetResiduals_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *Indices;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *residuals;
    VARIANT_BOOL __RPC_FAR *validVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Indices = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )residuals = 0;
    ( VARIANT_BOOL __RPC_FAR * )validVal = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[28] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Indices,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&residuals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 1) & ~ 0x1);
        validVal = ( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( VARIANT_BOOL  );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetResiduals(
                (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
                Indices,
                residuals,
                validVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 2U + 6U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++ = *validVal;
        
        _StubMsg.Buffer += 2;
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Indices,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)residuals,
                        &__MIDL_TypeFormatString.Format[992] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetJacobianStruct_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nColIndices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      13);
        
        
        
        if(!nColIndices)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!ColIndices)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!cNZCols)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!CalcMethod)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 0U + 0U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)ColIndices,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)cNZCols,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)CalcMethod,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nColIndices;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)ColIndices,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)cNZCols,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)CalcMethod,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[42] );
            
            *nColIndices = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&ColIndices,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&cNZCols,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&CalcMethod,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1010],
                         ( void __RPC_FAR * )nColIndices);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )ColIndices);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )cNZCols);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )CalcMethod);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetJacobianStruct_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod;
    SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols;
    long __RPC_FAR *nColIndices;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( long __RPC_FAR * )nColIndices = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )ColIndices = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )cNZCols = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )CalcMethod = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[42] );
        
        nColIndices = ( long __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( long  );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ColIndices,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&cNZCols,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&CalcMethod,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetJacobianStruct(
                     (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
                     nColIndices,
                     ColIndices,
                     cNZCols,
                     CalcMethod);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 0U + 0U + 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)ColIndices,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)cNZCols,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)CalcMethod,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nColIndices;
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)ColIndices,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)cNZCols,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)CalcMethod,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ColIndices,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)cNZCols,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)CalcMethod,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetJacobianValues_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *JacVals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      14);
        
        
        
        if(!Indices)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!JacVals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Indices,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)JacVals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Indices,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)JacVals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[60] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&JacVals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )JacVals);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetJacobianValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *Indices;
    SAFEARRAY __RPC_FAR * __RPC_FAR *JacVals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Indices = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )JacVals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[60] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Indices,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&JacVals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetJacobianValues(
                     (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
                     Indices,
                     JacVals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)JacVals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)JacVals,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Indices,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)JacVals,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetAllJacobianValues_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out] */ IIsMatrix __RPC_FAR *__RPC_FAR *ppJacVals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(ppJacVals)
        {
        MIDL_memset(
               ppJacVals,
               0,
               sizeof( IIsMatrix __RPC_FAR *__RPC_FAR * ));
        }
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      15);
        
        
        
        if(!ppJacVals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[70] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ppJacVals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1014],
                                  (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1014],
                         ( void __RPC_FAR * )ppJacVals);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetAllJacobianValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    IIsMatrix __RPC_FAR *_M0;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    IIsMatrix __RPC_FAR *__RPC_FAR *ppJacVals;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( IIsMatrix __RPC_FAR *__RPC_FAR * )ppJacVals = 0;
    RpcTryFinally
        {
        ppJacVals = &_M0;
        _M0 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetAllJacobianValues((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,ppJacVals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 4U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)ppJacVals,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1014] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)ppJacVals,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1014] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ppJacVals,
                        &__MIDL_TypeFormatString.Format[1014] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetDiffJacobianStruct_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nColIndices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      16);
        
        
        
        if(!nColIndices)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!ColIndices)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!cNZCols)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!CalcMethod)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 0U + 0U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)ColIndices,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)cNZCols,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)CalcMethod,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nColIndices;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)ColIndices,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)cNZCols,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)CalcMethod,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[42] );
            
            *nColIndices = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&ColIndices,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&cNZCols,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&CalcMethod,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1010],
                         ( void __RPC_FAR * )nColIndices);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )ColIndices);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )cNZCols);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )CalcMethod);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetDiffJacobianStruct_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod;
    SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols;
    long __RPC_FAR *nColIndices;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( long __RPC_FAR * )nColIndices = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )ColIndices = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )cNZCols = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )CalcMethod = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[42] );
        
        nColIndices = ( long __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( long  );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ColIndices,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&cNZCols,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&CalcMethod,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetDiffJacobianStruct(
                         (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
                         nColIndices,
                         ColIndices,
                         cNZCols,
                         CalcMethod);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 0U + 0U + 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)ColIndices,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)cNZCols,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)CalcMethod,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nColIndices;
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)ColIndices,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)cNZCols,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)CalcMethod,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ColIndices,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)cNZCols,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)CalcMethod,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetDiffJacobianValues_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *MassVals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      17);
        
        
        
        if(!Indices)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!MassVals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Indices,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)MassVals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Indices,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)MassVals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[60] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&MassVals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )MassVals);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetDiffJacobianValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *Indices;
    SAFEARRAY __RPC_FAR * __RPC_FAR *MassVals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Indices = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )MassVals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[60] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Indices,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&MassVals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetDiffJacobianValues(
                         (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
                         Indices,
                         MassVals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)MassVals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)MassVals,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Indices,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)MassVals,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetAllDiffJacobianValues_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out] */ IIsMatrix __RPC_FAR *__RPC_FAR *ppMassVals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(ppMassVals)
        {
        MIDL_memset(
               ppMassVals,
               0,
               sizeof( IIsMatrix __RPC_FAR *__RPC_FAR * ));
        }
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      18);
        
        
        
        if(!ppMassVals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[70] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ppMassVals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1014],
                                  (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1014],
                         ( void __RPC_FAR * )ppMassVals);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetAllDiffJacobianValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    IIsMatrix __RPC_FAR *_M1;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    IIsMatrix __RPC_FAR *__RPC_FAR *ppMassVals;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( IIsMatrix __RPC_FAR *__RPC_FAR * )ppMassVals = 0;
    RpcTryFinally
        {
        ppMassVals = &_M1;
        _M1 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetAllDiffJacobianValues((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,ppMassVals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 4U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)ppMassVals,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1014] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)ppMassVals,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1014] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ppMassVals,
                        &__MIDL_TypeFormatString.Format[1014] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetVariables_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
    /* [in] */ double t,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      19);
        
        
        
        if(!Indices)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!Vals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U + 23U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Indices,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Vals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Indices,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 7) & ~ 0x7);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = t;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Vals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[76] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&Vals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )Vals);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetVariables_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *Indices;
    SAFEARRAY __RPC_FAR * __RPC_FAR *Vals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    double t;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Indices = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Vals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[76] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Indices,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 7) & ~ 0x7);
        t = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Vals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetVariables(
                (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
                Indices,
                t,
                Vals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)Vals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)Vals,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Indices,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Vals,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetVariable_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ double t,
    /* [out] */ double __RPC_FAR *val)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      20);
        
        
        
        if(!val)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 12U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = index;
            
            _StubMsg.Buffer += 4;
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = t;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[88] );
            
            *val = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1036],
                         ( void __RPC_FAR * )val);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetVariable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    double _M2;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long index;
    double t;
    double __RPC_FAR *val;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( double __RPC_FAR * )val = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[88] );
        
        index = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        _StubMsg.Buffer += 4;
        t = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        val = &_M2;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetVariable(
               (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
               index,
               t,
               val);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 8U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( double __RPC_FAR * )_StubMsg.Buffer)++ = *val;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetVariableId_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [out] */ long __RPC_FAR *idx)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      21);
        
        
        
        if(!idx)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&Name,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&Name,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[98] );
            
            *idx = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1054],
                         ( void __RPC_FAR * )idx);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetVariableId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR Name;
    long _M3;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_Name;
    long __RPC_FAR *idx;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_Name = &Name;
    MIDL_memset(
               _p_Name,
               0,
               sizeof( BSTR  ));
    ( long __RPC_FAR * )idx = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[98] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_Name,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044],
                                  (unsigned char)0 );
        
        idx = &_M3;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetVariableId(
                 (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
                 Name,
                 idx);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *idx;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&Name,
                            &__MIDL_TypeFormatString.Format[1044] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_SetVariables_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      22);
        
        
        
        if(!Indices)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!Vals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Indices,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Vals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Indices,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Vals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[108] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_SetVariables_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *Indices;
    SAFEARRAY __RPC_FAR * __RPC_FAR *Vals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Indices = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Vals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[108] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Indices,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Vals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetVariables(
                (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
                Indices,
                Vals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Indices,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Vals,
                        &__MIDL_TypeFormatString.Format[992] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetAllVariables_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ double t,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      23);
        
        
        
        if(!Vals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Vals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = t;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Vals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[118] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&Vals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )Vals);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetAllVariables_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *Vals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    double t;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Vals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[118] );
        
        t = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Vals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetAllVariables(
                   (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
                   t,
                   Vals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)Vals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)Vals,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Vals,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_SetAllVariables_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      24);
        
        
        
        if(!Vals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Vals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Vals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[12] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_SetAllVariables_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *Vals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Vals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[12] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Vals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetAllVariables((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,Vals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Vals,
                        &__MIDL_TypeFormatString.Format[992] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetDerivatives_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
    /* [in] */ double t,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      25);
        
        
        
        if(!Indices)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!Vals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U + 23U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Indices,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Vals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Indices,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 7) & ~ 0x7);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = t;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Vals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[76] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&Vals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )Vals);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetDerivatives_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *Indices;
    SAFEARRAY __RPC_FAR * __RPC_FAR *Vals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    double t;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Indices = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Vals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[76] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Indices,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 7) & ~ 0x7);
        t = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Vals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetDerivatives(
                  (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
                  Indices,
                  t,
                  Vals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)Vals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)Vals,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Indices,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Vals,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetDerivative_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ double t,
    /* [out] */ double __RPC_FAR *val)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      26);
        
        
        
        if(!val)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 12U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = index;
            
            _StubMsg.Buffer += 4;
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = t;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[88] );
            
            *val = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1036],
                         ( void __RPC_FAR * )val);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetDerivative_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    double _M4;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long index;
    double t;
    double __RPC_FAR *val;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( double __RPC_FAR * )val = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[88] );
        
        index = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        _StubMsg.Buffer += 4;
        t = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        val = &_M4;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetDerivative(
                 (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
                 index,
                 t,
                 val);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 8U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( double __RPC_FAR * )_StubMsg.Buffer)++ = *val;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_SetDerivatives_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      27);
        
        
        
        if(!Indices)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!Vals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Indices,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Vals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Indices,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Vals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[108] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_SetDerivatives_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *Indices;
    SAFEARRAY __RPC_FAR * __RPC_FAR *Vals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Indices = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Vals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[108] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Indices,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Vals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetDerivatives(
                  (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
                  Indices,
                  Vals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Indices,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Vals,
                        &__MIDL_TypeFormatString.Format[992] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetAllDerivatives_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ double t,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      28);
        
        
        
        if(!Vals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Vals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = t;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Vals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[118] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&Vals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )Vals);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetAllDerivatives_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *Vals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    double t;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Vals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[118] );
        
        t = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Vals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetAllDerivatives(
                     (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
                     t,
                     Vals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)Vals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)Vals,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Vals,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_SetAllDerivatives_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      29);
        
        
        
        if(!Vals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Vals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Vals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[12] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_SetAllDerivatives_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *Vals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Vals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[12] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Vals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetAllDerivatives((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,Vals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Vals,
                        &__MIDL_TypeFormatString.Format[992] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetNumVars_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *nVars)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      30);
        
        
        
        if(!nVars)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[126] );
            
            *nVars = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1054],
                         ( void __RPC_FAR * )nVars);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetNumVars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    long _M5;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long __RPC_FAR *nVars;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( long __RPC_FAR * )nVars = 0;
    RpcTryFinally
        {
        nVars = &_M5;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetNumVars((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,nVars);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nVars;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetNumEqns_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *nEqns)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      31);
        
        
        
        if(!nEqns)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[126] );
            
            *nEqns = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1054],
                         ( void __RPC_FAR * )nEqns);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetNumEqns_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    long _M6;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long __RPC_FAR *nEqns;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( long __RPC_FAR * )nEqns = 0;
    RpcTryFinally
        {
        nEqns = &_M6;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetNumEqns((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,nEqns);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nEqns;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetNumLocalVars_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *nVars)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      32);
        
        
        
        if(!nVars)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[126] );
            
            *nVars = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1054],
                         ( void __RPC_FAR * )nVars);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetNumLocalVars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    long _M7;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long __RPC_FAR *nVars;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( long __RPC_FAR * )nVars = 0;
    RpcTryFinally
        {
        nVars = &_M7;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetNumLocalVars((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,nVars);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nVars;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetNumLocalEqns_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *nEqns)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      33);
        
        
        
        if(!nEqns)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[126] );
            
            *nEqns = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1054],
                         ( void __RPC_FAR * )nEqns);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetNumLocalEqns_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    long _M8;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long __RPC_FAR *nEqns;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( long __RPC_FAR * )nEqns = 0;
    RpcTryFinally
        {
        nEqns = &_M8;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetNumLocalEqns((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,nEqns);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nEqns;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetLastTime_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    double __RPC_FAR *t)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      34);
        
        
        
        if(!t)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = *t;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[132] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetLastTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    double __RPC_FAR *t;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( double __RPC_FAR * )t = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[132] );
        
        t = ( double __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( double  );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetLastTime((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,t);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetTime_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    double __RPC_FAR *t)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      35);
        
        
        
        if(!t)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = *t;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[132] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    double __RPC_FAR *t;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( double __RPC_FAR * )t = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[132] );
        
        t = ( double __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( double  );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetTime((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,t);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_get_ContainerIndex_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Index)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      36);
        
        
        
        if(!Index)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[126] );
            
            *Index = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1054],
                         ( void __RPC_FAR * )Index);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_get_ContainerIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    long __RPC_FAR *Index;
    long _M9;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( long __RPC_FAR * )Index = 0;
    RpcTryFinally
        {
        Index = &_M9;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> get_ContainerIndex((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,Index);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *Index;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_put_ContainerIndex_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ long Index)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      37);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = Index;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[138] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_put_ContainerIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    long Index;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[138] );
        
        Index = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> put_ContainerIndex((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,Index);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_get_VariableMap_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      38);
        
        
        
        if(!pVal)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[6] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pVal,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )pVal);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_get_VariableMap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *pVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )pVal = 0;
    RpcTryFinally
        {
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> get_VariableMap((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,pVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)pVal,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)pVal,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)pVal,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_put_VariableMap_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *newVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      39);
        
        
        
        if(!newVal)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)newVal,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)newVal,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[12] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_put_VariableMap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *newVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )newVal = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[12] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&newVal,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> put_VariableMap((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,newVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)newVal,
                        &__MIDL_TypeFormatString.Format[992] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_InitTime_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ double StartTime,
    /* [in] */ VARIANT_BOOL bReverse)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      40);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U + 2U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = StartTime;
            
            *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++ = bReverse;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[142] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_InitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    double StartTime;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    VARIANT_BOOL bReverse;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[142] );
        
        StartTime = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        bReverse = *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> InitTime(
            (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
            StartTime,
            bReverse);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_SetTime_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ double time)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      41);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = time;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[148] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_SetTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    double time;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[148] );
        
        time = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetTime((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,time);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_SetLastTime_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ double last_time)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      42);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = last_time;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[148] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_SetLastTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    double last_time;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[148] );
        
        last_time = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetLastTime((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,last_time);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetVariablesIndex_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Index)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      43);
        
        
        
        if(!Index)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Index,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Index,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[152] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&Index,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )Index);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetVariablesIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *Index;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Index = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[152] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Index,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetVariablesIndex((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,Index);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)Index,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)Index,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Index,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_AddEso_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ IIsDaeEso __RPC_FAR *pEso)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      44);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrInterfacePointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                           (unsigned char __RPC_FAR *)pEso,
                                           (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1062] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrInterfacePointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                         (unsigned char __RPC_FAR *)pEso,
                                         (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1062] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[158] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_AddEso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    IIsDaeEso __RPC_FAR *pEso;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    pEso = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[158] );
        
        NdrInterfacePointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR * __RPC_FAR *)&pEso,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1062],
                                       (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> AddEso((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,pEso);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrInterfacePointerFree( &_StubMsg,
                                 (unsigned char __RPC_FAR *)pEso,
                                 &__MIDL_TypeFormatString.Format[1062] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetEso_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ long index,
    /* [out] */ IIsDaeEso __RPC_FAR *__RPC_FAR *pEso)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(pEso)
        {
        MIDL_memset(
               pEso,
               0,
               sizeof( IIsDaeEso __RPC_FAR *__RPC_FAR * ));
        }
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      45);
        
        
        
        if(!pEso)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = index;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[164] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&pEso,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1080],
                                  (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1080],
                         ( void __RPC_FAR * )pEso);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetEso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    IIsDaeEso __RPC_FAR *_M10;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long index;
    IIsDaeEso __RPC_FAR *__RPC_FAR *pEso;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( IIsDaeEso __RPC_FAR *__RPC_FAR * )pEso = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[164] );
        
        index = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        pEso = &_M10;
        _M10 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetEso(
          (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
          index,
          pEso);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 4U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)pEso,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1080] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)pEso,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1080] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)pEso,
                        &__MIDL_TypeFormatString.Format[1080] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_RemoveEso_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ long index)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      46);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = index;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[138] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_RemoveEso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long index;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[138] );
        
        index = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> RemoveEso((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,index);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetNumEso_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *count)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      47);
        
        
        
        if(!count)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[126] );
            
            *count = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1054],
                         ( void __RPC_FAR * )count);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetNumEso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    long _M11;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long __RPC_FAR *count;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( long __RPC_FAR * )count = 0;
    RpcTryFinally
        {
        count = &_M11;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetNumEso((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,count);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *count;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetReportInfo_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *StepperCalls,
    /* [out] */ long __RPC_FAR *functionCalls,
    /* [out] */ long __RPC_FAR *jacobiansCalls,
    /* [out] */ long __RPC_FAR *DecompCalls,
    /* [out] */ long __RPC_FAR *Substitutions,
    /* [out] */ long __RPC_FAR *TotalSteps,
    /* [out] */ long __RPC_FAR *errorRejectedSteps,
    /* [out] */ long __RPC_FAR *newtonRejectedSteps,
    /* [out] */ long __RPC_FAR *growthRejectedSteps,
    /* [out] */ long __RPC_FAR *funcRejectedSteps,
    /* [out] */ long __RPC_FAR *nStateEvents,
    /* [out] */ long __RPC_FAR *nParameterEvents,
    /* [out] */ long __RPC_FAR *nStepSizeChanges)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      48);
        
        
        
        if(!StepperCalls)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!functionCalls)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!jacobiansCalls)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!DecompCalls)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!Substitutions)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!TotalSteps)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!errorRejectedSteps)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!newtonRejectedSteps)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!growthRejectedSteps)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!funcRejectedSteps)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!nStateEvents)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!nParameterEvents)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!nStepSizeChanges)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[172] );
            
            *StepperCalls = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            *functionCalls = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            *jacobiansCalls = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            *DecompCalls = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            *Substitutions = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            *TotalSteps = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            *errorRejectedSteps = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            *newtonRejectedSteps = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            *growthRejectedSteps = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            *funcRejectedSteps = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            *nStateEvents = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            *nParameterEvents = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            *nStepSizeChanges = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1054],
                         ( void __RPC_FAR * )StepperCalls);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1054],
                         ( void __RPC_FAR * )functionCalls);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1054],
                         ( void __RPC_FAR * )jacobiansCalls);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1054],
                         ( void __RPC_FAR * )DecompCalls);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1054],
                         ( void __RPC_FAR * )Substitutions);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1054],
                         ( void __RPC_FAR * )TotalSteps);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1054],
                         ( void __RPC_FAR * )errorRejectedSteps);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1054],
                         ( void __RPC_FAR * )newtonRejectedSteps);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1054],
                         ( void __RPC_FAR * )growthRejectedSteps);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1054],
                         ( void __RPC_FAR * )funcRejectedSteps);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1054],
                         ( void __RPC_FAR * )nStateEvents);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1054],
                         ( void __RPC_FAR * )nParameterEvents);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1054],
                         ( void __RPC_FAR * )nStepSizeChanges);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetReportInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    long __RPC_FAR *DecompCalls;
    long __RPC_FAR *StepperCalls;
    long __RPC_FAR *Substitutions;
    long __RPC_FAR *TotalSteps;
    long _M12;
    long _M13;
    long _M14;
    long _M15;
    long _M16;
    long _M17;
    long _M18;
    long _M19;
    long _M20;
    long _M21;
    long _M22;
    long _M23;
    long _M24;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long __RPC_FAR *errorRejectedSteps;
    long __RPC_FAR *funcRejectedSteps;
    long __RPC_FAR *functionCalls;
    long __RPC_FAR *growthRejectedSteps;
    long __RPC_FAR *jacobiansCalls;
    long __RPC_FAR *nParameterEvents;
    long __RPC_FAR *nStateEvents;
    long __RPC_FAR *nStepSizeChanges;
    long __RPC_FAR *newtonRejectedSteps;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( long __RPC_FAR * )StepperCalls = 0;
    ( long __RPC_FAR * )functionCalls = 0;
    ( long __RPC_FAR * )jacobiansCalls = 0;
    ( long __RPC_FAR * )DecompCalls = 0;
    ( long __RPC_FAR * )Substitutions = 0;
    ( long __RPC_FAR * )TotalSteps = 0;
    ( long __RPC_FAR * )errorRejectedSteps = 0;
    ( long __RPC_FAR * )newtonRejectedSteps = 0;
    ( long __RPC_FAR * )growthRejectedSteps = 0;
    ( long __RPC_FAR * )funcRejectedSteps = 0;
    ( long __RPC_FAR * )nStateEvents = 0;
    ( long __RPC_FAR * )nParameterEvents = 0;
    ( long __RPC_FAR * )nStepSizeChanges = 0;
    RpcTryFinally
        {
        StepperCalls = &_M12;
        functionCalls = &_M13;
        jacobiansCalls = &_M14;
        DecompCalls = &_M15;
        Substitutions = &_M16;
        TotalSteps = &_M17;
        errorRejectedSteps = &_M18;
        newtonRejectedSteps = &_M19;
        growthRejectedSteps = &_M20;
        funcRejectedSteps = &_M21;
        nStateEvents = &_M22;
        nParameterEvents = &_M23;
        nStepSizeChanges = &_M24;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetReportInfo(
                 (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
                 StepperCalls,
                 functionCalls,
                 jacobiansCalls,
                 DecompCalls,
                 Substitutions,
                 TotalSteps,
                 errorRejectedSteps,
                 newtonRejectedSteps,
                 growthRejectedSteps,
                 funcRejectedSteps,
                 nStateEvents,
                 nParameterEvents,
                 nStepSizeChanges);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 4U + 4U + 4U + 4U + 4U + 4U + 4U + 4U + 4U + 4U + 4U + 4U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *StepperCalls;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *functionCalls;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *jacobiansCalls;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *DecompCalls;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *Substitutions;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *TotalSteps;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *errorRejectedSteps;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *newtonRejectedSteps;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *growthRejectedSteps;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *funcRejectedSteps;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nStateEvents;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nParameterEvents;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nStepSizeChanges;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_EvalStateCondition_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ double ZeroCrossingTime,
    /* [in] */ long iDisEqn,
    /* [in] */ long iTransition,
    /* [out] */ VARIANT_BOOL __RPC_FAR *bEvent)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      49);
        
        
        
        if(!bEvent)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U + 4U + 4U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = ZeroCrossingTime;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = iDisEqn;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = iTransition;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[226] );
            
            *bEvent = *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++;
            
            _StubMsg.Buffer += 2;
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1084],
                         ( void __RPC_FAR * )bEvent);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_EvalStateCondition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    double ZeroCrossingTime;
    VARIANT_BOOL _M25;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    VARIANT_BOOL __RPC_FAR *bEvent;
    long iDisEqn;
    long iTransition;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( VARIANT_BOOL __RPC_FAR * )bEvent = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[226] );
        
        ZeroCrossingTime = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        iDisEqn = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        iTransition = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        bEvent = &_M25;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> EvalStateCondition(
                      (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
                      ZeroCrossingTime,
                      iDisEqn,
                      iTransition,
                      bEvent);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 2U + 6U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++ = *bEvent;
        
        _StubMsg.Buffer += 2;
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][hidden][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetCPPPtr_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *pIsDaeEso)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      50);
        
        
        
        if(!pIsDaeEso)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[126] );
            
            *pIsDaeEso = *(( DWORD __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1054],
                         ( void __RPC_FAR * )pIsDaeEso);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetCPPPtr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    DWORD _M26;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    DWORD __RPC_FAR *pIsDaeEso;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( DWORD __RPC_FAR * )pIsDaeEso = 0;
    RpcTryFinally
        {
        pIsDaeEso = &_M26;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetCPPPtr((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,pIsDaeEso);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( DWORD __RPC_FAR * )_StubMsg.Buffer)++ = *pIsDaeEso;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetNumRealPars_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nRPars)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      51);
        
        
        
        if(!nRPars)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nRPars;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[238] );
            
            *nRPars = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1010],
                         ( void __RPC_FAR * )nRPars);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetNumRealPars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long __RPC_FAR *nRPars;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( long __RPC_FAR * )nRPars = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[238] );
        
        nRPars = ( long __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( long  );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetNumRealPars((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,nRPars);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nRPars;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetRealPar_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ long index,
    /* [out][in] */ double __RPC_FAR *Val)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      52);
        
        
        
        if(!Val)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 12U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = index;
            
            _StubMsg.Buffer += 4;
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = *Val;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[244] );
            
            *Val = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1058],
                         ( void __RPC_FAR * )Val);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetRealPar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    double __RPC_FAR *Val;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long index;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( double __RPC_FAR * )Val = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[244] );
        
        index = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        _StubMsg.Buffer += 4;
        Val = ( double __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( double  );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetRealPar(
              (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
              index,
              Val);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 8U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( double __RPC_FAR * )_StubMsg.Buffer)++ = *Val;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetRealParId_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [out][in] */ long __RPC_FAR *idx)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      53);
        
        
        
        if(!idx)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U + 11U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&Name,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&Name,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *idx;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[252] );
            
            *idx = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1010],
                         ( void __RPC_FAR * )idx);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetRealParId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR Name;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_Name;
    long __RPC_FAR *idx;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_Name = &Name;
    MIDL_memset(
               _p_Name,
               0,
               sizeof( BSTR  ));
    ( long __RPC_FAR * )idx = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[252] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_Name,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044],
                                  (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        idx = ( long __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( long  );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetRealParId(
                (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
                Name,
                idx);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *idx;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&Name,
                            &__MIDL_TypeFormatString.Format[1044] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_SetRealPar_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ double newVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      54);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 12U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = index;
            
            _StubMsg.Buffer += 4;
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = newVal;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[262] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_SetRealPar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long index;
    double newVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[262] );
        
        index = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        _StubMsg.Buffer += 4;
        newVal = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetRealPar(
              (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
              index,
              newVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetNumIntPars_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nIPars)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      55);
        
        
        
        if(!nIPars)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nIPars;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[238] );
            
            *nIPars = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1010],
                         ( void __RPC_FAR * )nIPars);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetNumIntPars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long __RPC_FAR *nIPars;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( long __RPC_FAR * )nIPars = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[238] );
        
        nIPars = ( long __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( long  );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetNumIntPars((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,nIPars);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nIPars;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetIntPar_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ long index,
    /* [out][in] */ long __RPC_FAR *Val)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      56);
        
        
        
        if(!Val)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 4U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = index;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *Val;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[268] );
            
            *Val = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1010],
                         ( void __RPC_FAR * )Val);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetIntPar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    long __RPC_FAR *Val;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long index;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( long __RPC_FAR * )Val = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[268] );
        
        index = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        Val = ( long __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( long  );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetIntPar(
             (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
             index,
             Val);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *Val;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetIntParId_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [out][in] */ long __RPC_FAR *idx)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      57);
        
        
        
        if(!idx)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U + 11U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&Name,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&Name,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *idx;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[252] );
            
            *idx = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1010],
                         ( void __RPC_FAR * )idx);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_GetIntParId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR Name;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_Name;
    long __RPC_FAR *idx;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_Name = &Name;
    MIDL_memset(
               _p_Name,
               0,
               sizeof( BSTR  ));
    ( long __RPC_FAR * )idx = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[252] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_Name,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044],
                                  (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        idx = ( long __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( long  );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetIntParId(
               (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
               Name,
               idx);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *idx;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&Name,
                            &__MIDL_TypeFormatString.Format[1044] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_SetIntPar_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ long newVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      58);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 4U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = index;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = newVal;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[276] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_SetIntPar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long index;
    long newVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[276] );
        
        index = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        newVal = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetIntPar(
             (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
             index,
             newVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_SetModelExec_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ IOnModelExec __RPC_FAR *pModelExec)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      59);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrInterfacePointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                           (unsigned char __RPC_FAR *)pModelExec,
                                           (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1088] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrInterfacePointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                         (unsigned char __RPC_FAR *)pModelExec,
                                         (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1088] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[282] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_SetModelExec_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    IOnModelExec __RPC_FAR *pModelExec;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    pModelExec = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[282] );
        
        NdrInterfacePointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR * __RPC_FAR *)&pModelExec,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1088],
                                       (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetModelExec((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,pModelExec);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrInterfacePointerFree( &_StubMsg,
                                 (unsigned char __RPC_FAR *)pModelExec,
                                 &__MIDL_TypeFormatString.Format[1088] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_PostStateEvent_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ double t,
    /* [in] */ BSTR EventId)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      60);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U + 8U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&EventId,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = t;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&EventId,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[288] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_PostStateEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR EventId;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_EventId;
    double t;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_EventId = &EventId;
    MIDL_memset(
               _p_EventId,
               0,
               sizeof( BSTR  ));
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[288] );
        
        t = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_EventId,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> PostStateEvent(
                  (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
                  t,
                  EventId);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&EventId,
                            &__MIDL_TypeFormatString.Format[1044] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_PostTransition_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ long iNewState)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      61);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = iNewState;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[138] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_PostTransition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long iNewState;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[138] );
        
        iNewState = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> PostTransition((IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,iNewState);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_PostRealParameter_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ double t,
    /* [in] */ long Id,
    /* [in] */ double newVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      62);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U + 4U + 12U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = t;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = Id;
            
            _StubMsg.Buffer += 4;
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = newVal;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[296] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_PostRealParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    long Id;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    double newVal;
    double t;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[296] );
        
        t = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        Id = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        _StubMsg.Buffer += 4;
        newVal = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> PostRealParameter(
                     (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
                     t,
                     Id,
                     newVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_PostIntegerParameter_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ double t,
    /* [in] */ long Id,
    /* [in] */ long newVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      63);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U + 4U + 4U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = t;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = Id;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = newVal;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[304] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEso_PostIntegerParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    long Id;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long newVal;
    double t;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[304] );
        
        t = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        Id = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        newVal = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> PostIntegerParameter(
                        (IIsDaeEso *) ((CStdStubBuffer *)This)->pvServerObject,
                        t,
                        Id,
                        newVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

CINTERFACE_PROXY_VTABLE(64) _IIsDaeEsoProxyVtbl = 
{
    &IID_IIsDaeEso,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch_GetTypeInfoCount_Proxy */ ,
    0 /* IDispatch_GetTypeInfo_Proxy */ ,
    0 /* IDispatch_GetIDsOfNames_Proxy */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    IIsDaeEso_SetRelTolerance_Proxy ,
    IIsDaeEso_GetRelTolerance_Proxy ,
    IIsDaeEso_SetAbsTolerance_Proxy ,
    IIsDaeEso_GetAbsTolerance_Proxy ,
    IIsDaeEso_GetAllResiduals_Proxy ,
    IIsDaeEso_GetResiduals_Proxy ,
    IIsDaeEso_GetJacobianStruct_Proxy ,
    IIsDaeEso_GetJacobianValues_Proxy ,
    IIsDaeEso_GetAllJacobianValues_Proxy ,
    IIsDaeEso_GetDiffJacobianStruct_Proxy ,
    IIsDaeEso_GetDiffJacobianValues_Proxy ,
    IIsDaeEso_GetAllDiffJacobianValues_Proxy ,
    IIsDaeEso_GetVariables_Proxy ,
    IIsDaeEso_GetVariable_Proxy ,
    IIsDaeEso_GetVariableId_Proxy ,
    IIsDaeEso_SetVariables_Proxy ,
    IIsDaeEso_GetAllVariables_Proxy ,
    IIsDaeEso_SetAllVariables_Proxy ,
    IIsDaeEso_GetDerivatives_Proxy ,
    IIsDaeEso_GetDerivative_Proxy ,
    IIsDaeEso_SetDerivatives_Proxy ,
    IIsDaeEso_GetAllDerivatives_Proxy ,
    IIsDaeEso_SetAllDerivatives_Proxy ,
    IIsDaeEso_GetNumVars_Proxy ,
    IIsDaeEso_GetNumEqns_Proxy ,
    IIsDaeEso_GetNumLocalVars_Proxy ,
    IIsDaeEso_GetNumLocalEqns_Proxy ,
    IIsDaeEso_GetLastTime_Proxy ,
    IIsDaeEso_GetTime_Proxy ,
    IIsDaeEso_get_ContainerIndex_Proxy ,
    IIsDaeEso_put_ContainerIndex_Proxy ,
    IIsDaeEso_get_VariableMap_Proxy ,
    IIsDaeEso_put_VariableMap_Proxy ,
    IIsDaeEso_InitTime_Proxy ,
    IIsDaeEso_SetTime_Proxy ,
    IIsDaeEso_SetLastTime_Proxy ,
    IIsDaeEso_GetVariablesIndex_Proxy ,
    IIsDaeEso_AddEso_Proxy ,
    IIsDaeEso_GetEso_Proxy ,
    IIsDaeEso_RemoveEso_Proxy ,
    IIsDaeEso_GetNumEso_Proxy ,
    IIsDaeEso_GetReportInfo_Proxy ,
    IIsDaeEso_EvalStateCondition_Proxy ,
    IIsDaeEso_GetCPPPtr_Proxy ,
    IIsDaeEso_GetNumRealPars_Proxy ,
    IIsDaeEso_GetRealPar_Proxy ,
    IIsDaeEso_GetRealParId_Proxy ,
    IIsDaeEso_SetRealPar_Proxy ,
    IIsDaeEso_GetNumIntPars_Proxy ,
    IIsDaeEso_GetIntPar_Proxy ,
    IIsDaeEso_GetIntParId_Proxy ,
    IIsDaeEso_SetIntPar_Proxy ,
    IIsDaeEso_SetModelExec_Proxy ,
    IIsDaeEso_PostStateEvent_Proxy ,
    IIsDaeEso_PostTransition_Proxy ,
    IIsDaeEso_PostRealParameter_Proxy ,
    IIsDaeEso_PostIntegerParameter_Proxy
};


static const PRPC_STUB_FUNCTION IIsDaeEso_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    IIsDaeEso_SetRelTolerance_Stub,
    IIsDaeEso_GetRelTolerance_Stub,
    IIsDaeEso_SetAbsTolerance_Stub,
    IIsDaeEso_GetAbsTolerance_Stub,
    IIsDaeEso_GetAllResiduals_Stub,
    IIsDaeEso_GetResiduals_Stub,
    IIsDaeEso_GetJacobianStruct_Stub,
    IIsDaeEso_GetJacobianValues_Stub,
    IIsDaeEso_GetAllJacobianValues_Stub,
    IIsDaeEso_GetDiffJacobianStruct_Stub,
    IIsDaeEso_GetDiffJacobianValues_Stub,
    IIsDaeEso_GetAllDiffJacobianValues_Stub,
    IIsDaeEso_GetVariables_Stub,
    IIsDaeEso_GetVariable_Stub,
    IIsDaeEso_GetVariableId_Stub,
    IIsDaeEso_SetVariables_Stub,
    IIsDaeEso_GetAllVariables_Stub,
    IIsDaeEso_SetAllVariables_Stub,
    IIsDaeEso_GetDerivatives_Stub,
    IIsDaeEso_GetDerivative_Stub,
    IIsDaeEso_SetDerivatives_Stub,
    IIsDaeEso_GetAllDerivatives_Stub,
    IIsDaeEso_SetAllDerivatives_Stub,
    IIsDaeEso_GetNumVars_Stub,
    IIsDaeEso_GetNumEqns_Stub,
    IIsDaeEso_GetNumLocalVars_Stub,
    IIsDaeEso_GetNumLocalEqns_Stub,
    IIsDaeEso_GetLastTime_Stub,
    IIsDaeEso_GetTime_Stub,
    IIsDaeEso_get_ContainerIndex_Stub,
    IIsDaeEso_put_ContainerIndex_Stub,
    IIsDaeEso_get_VariableMap_Stub,
    IIsDaeEso_put_VariableMap_Stub,
    IIsDaeEso_InitTime_Stub,
    IIsDaeEso_SetTime_Stub,
    IIsDaeEso_SetLastTime_Stub,
    IIsDaeEso_GetVariablesIndex_Stub,
    IIsDaeEso_AddEso_Stub,
    IIsDaeEso_GetEso_Stub,
    IIsDaeEso_RemoveEso_Stub,
    IIsDaeEso_GetNumEso_Stub,
    IIsDaeEso_GetReportInfo_Stub,
    IIsDaeEso_EvalStateCondition_Stub,
    IIsDaeEso_GetCPPPtr_Stub,
    IIsDaeEso_GetNumRealPars_Stub,
    IIsDaeEso_GetRealPar_Stub,
    IIsDaeEso_GetRealParId_Stub,
    IIsDaeEso_SetRealPar_Stub,
    IIsDaeEso_GetNumIntPars_Stub,
    IIsDaeEso_GetIntPar_Stub,
    IIsDaeEso_GetIntParId_Stub,
    IIsDaeEso_SetIntPar_Stub,
    IIsDaeEso_SetModelExec_Stub,
    IIsDaeEso_PostStateEvent_Stub,
    IIsDaeEso_PostTransition_Stub,
    IIsDaeEso_PostRealParameter_Stub,
    IIsDaeEso_PostIntegerParameter_Stub
};

CInterfaceStubVtbl _IIsDaeEsoStubVtbl =
{
    &IID_IIsDaeEso,
    0,
    64,
    &IIsDaeEso_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IIsMatrix, ver. 0.0,
   GUID={0x3F35CF66,0x839E,0x11D4,{0x83,0x8D,0x00,0x60,0x08,0x94,0xE8,0x02}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsMatrix_Init_Proxy( 
    IIsMatrix __RPC_FAR * This,
    /* [in] */ long nRows,
    /* [in] */ long nCols)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      7);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 4U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = nRows;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = nCols;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[276] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsMatrix_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long nCols;
    long nRows;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[276] );
        
        nRows = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        nCols = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsMatrix*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Init(
        (IIsMatrix *) ((CStdStubBuffer *)This)->pvServerObject,
        nRows,
        nCols);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsMatrix_GetData_Proxy( 
    IIsMatrix __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      8);
        
        
        
        if(!Vals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Vals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Vals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[152] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&Vals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )Vals);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsMatrix_GetData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *Vals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Vals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[152] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Vals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsMatrix*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetData((IIsMatrix *) ((CStdStubBuffer *)This)->pvServerObject,Vals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)Vals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)Vals,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Vals,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsMatrix_Attach_Proxy( 
    IIsMatrix __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      9);
        
        
        
        if(!Vals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Vals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Vals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[12] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsMatrix_Attach_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *Vals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Vals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[12] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Vals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsMatrix*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Attach((IIsMatrix *) ((CStdStubBuffer *)This)->pvServerObject,Vals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Vals,
                        &__MIDL_TypeFormatString.Format[992] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsMatrix_Detach_Proxy( 
    IIsMatrix __RPC_FAR * This,
    /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      10);
        
        
        
        if(!Vals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[6] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&Vals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )Vals);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsMatrix_Detach_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *Vals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Vals = 0;
    RpcTryFinally
        {
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsMatrix*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Detach((IIsMatrix *) ((CStdStubBuffer *)This)->pvServerObject,Vals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)Vals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)Vals,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Vals,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsMatrix_GetRow_Proxy( 
    IIsMatrix __RPC_FAR * This,
    /* [in] */ long Row,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      11);
        
        
        
        if(!Vals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Vals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = Row;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Vals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[312] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&Vals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )Vals);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsMatrix_GetRow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    long Row;
    SAFEARRAY __RPC_FAR * __RPC_FAR *Vals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Vals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[312] );
        
        Row = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Vals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsMatrix*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetRow(
          (IIsMatrix *) ((CStdStubBuffer *)This)->pvServerObject,
          Row,
          Vals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)Vals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)Vals,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Vals,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsMatrix_SetRow_Proxy( 
    IIsMatrix __RPC_FAR * This,
    /* [in] */ long Row,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      12);
        
        
        
        if(!Vals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Vals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = Row;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Vals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[320] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsMatrix_SetRow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    long Row;
    SAFEARRAY __RPC_FAR * __RPC_FAR *Vals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Vals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[320] );
        
        Row = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Vals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsMatrix*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetRow(
          (IIsMatrix *) ((CStdStubBuffer *)This)->pvServerObject,
          Row,
          Vals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Vals,
                        &__MIDL_TypeFormatString.Format[992] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsMatrix_GetCol_Proxy( 
    IIsMatrix __RPC_FAR * This,
    /* [in] */ long Col,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      13);
        
        
        
        if(!Vals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Vals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = Col;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Vals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[312] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&Vals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )Vals);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsMatrix_GetCol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    long Col;
    SAFEARRAY __RPC_FAR * __RPC_FAR *Vals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Vals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[312] );
        
        Col = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Vals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsMatrix*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetCol(
          (IIsMatrix *) ((CStdStubBuffer *)This)->pvServerObject,
          Col,
          Vals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)Vals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)Vals,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Vals,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsMatrix_SetCol_Proxy( 
    IIsMatrix __RPC_FAR * This,
    /* [in] */ long Col,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      14);
        
        
        
        if(!Vals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Vals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = Col;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Vals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[320] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsMatrix_SetCol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    long Col;
    SAFEARRAY __RPC_FAR * __RPC_FAR *Vals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Vals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[320] );
        
        Col = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Vals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsMatrix*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetCol(
          (IIsMatrix *) ((CStdStubBuffer *)This)->pvServerObject,
          Col,
          Vals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Vals,
                        &__MIDL_TypeFormatString.Format[992] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IIsMatrix_get_Value_Proxy( 
    IIsMatrix __RPC_FAR * This,
    /* [in] */ long Row,
    /* [in] */ long Col,
    /* [retval][out] */ double __RPC_FAR *pVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      15);
        
        
        
        if(!pVal)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 4U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = Row;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = Col;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[328] );
            
            *pVal = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1036],
                         ( void __RPC_FAR * )pVal);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsMatrix_get_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    long Col;
    long Row;
    double _M27;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    double __RPC_FAR *pVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( double __RPC_FAR * )pVal = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[328] );
        
        Row = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        Col = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        pVal = &_M27;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsMatrix*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> get_Value(
             (IIsMatrix *) ((CStdStubBuffer *)This)->pvServerObject,
             Row,
             Col,
             pVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 8U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( double __RPC_FAR * )_StubMsg.Buffer)++ = *pVal;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IIsMatrix_put_Value_Proxy( 
    IIsMatrix __RPC_FAR * This,
    /* [in] */ long Row,
    /* [in] */ long Col,
    /* [in] */ double Val)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      16);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 4U + 8U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = Row;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = Col;
            
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = Val;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[338] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsMatrix_put_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    long Col;
    long Row;
    double Val;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[338] );
        
        Row = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        Col = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        Val = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsMatrix*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> put_Value(
             (IIsMatrix *) ((CStdStubBuffer *)This)->pvServerObject,
             Row,
             Col,
             Val);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

CINTERFACE_PROXY_VTABLE(17) _IIsMatrixProxyVtbl = 
{
    &IID_IIsMatrix,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch_GetTypeInfoCount_Proxy */ ,
    0 /* IDispatch_GetTypeInfo_Proxy */ ,
    0 /* IDispatch_GetIDsOfNames_Proxy */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    IIsMatrix_Init_Proxy ,
    IIsMatrix_GetData_Proxy ,
    IIsMatrix_Attach_Proxy ,
    IIsMatrix_Detach_Proxy ,
    IIsMatrix_GetRow_Proxy ,
    IIsMatrix_SetRow_Proxy ,
    IIsMatrix_GetCol_Proxy ,
    IIsMatrix_SetCol_Proxy ,
    IIsMatrix_get_Value_Proxy ,
    IIsMatrix_put_Value_Proxy
};


static const PRPC_STUB_FUNCTION IIsMatrix_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    IIsMatrix_Init_Stub,
    IIsMatrix_GetData_Stub,
    IIsMatrix_Attach_Stub,
    IIsMatrix_Detach_Stub,
    IIsMatrix_GetRow_Stub,
    IIsMatrix_SetRow_Stub,
    IIsMatrix_GetCol_Stub,
    IIsMatrix_SetCol_Stub,
    IIsMatrix_get_Value_Stub,
    IIsMatrix_put_Value_Stub
};

CInterfaceStubVtbl _IIsMatrixStubVtbl =
{
    &IID_IIsMatrix,
    0,
    17,
    &IIsMatrix_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IIsNlaSolver, ver. 0.0,
   GUID={0x717E8183,0x92E1,0x11D4,{0x98,0xA8,0x00,0xC0,0x4F,0x68,0x01,0xA9}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsNlaSolver_SetEso_Proxy( 
    IIsNlaSolver __RPC_FAR * This,
    /* [in] */ IIsNlaEso __RPC_FAR *pEso)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      7);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrInterfacePointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                           (unsigned char __RPC_FAR *)pEso,
                                           (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1106] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrInterfacePointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                         (unsigned char __RPC_FAR *)pEso,
                                         (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1106] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[346] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsNlaSolver_SetEso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    IIsNlaEso __RPC_FAR *pEso;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    pEso = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[346] );
        
        NdrInterfacePointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR * __RPC_FAR *)&pEso,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1106],
                                       (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsNlaSolver*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetEso((IIsNlaSolver *) ((CStdStubBuffer *)This)->pvServerObject,pEso);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrInterfacePointerFree( &_StubMsg,
                                 (unsigned char __RPC_FAR *)pEso,
                                 &__MIDL_TypeFormatString.Format[1106] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsNlaSolver_Solve_Proxy( 
    IIsNlaSolver __RPC_FAR * This)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      8);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[352] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsNlaSolver_Solve_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsNlaSolver*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Solve((IIsNlaSolver *) ((CStdStubBuffer *)This)->pvServerObject);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

CINTERFACE_PROXY_VTABLE(9) _IIsNlaSolverProxyVtbl = 
{
    &IID_IIsNlaSolver,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch_GetTypeInfoCount_Proxy */ ,
    0 /* IDispatch_GetTypeInfo_Proxy */ ,
    0 /* IDispatch_GetIDsOfNames_Proxy */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    IIsNlaSolver_SetEso_Proxy ,
    IIsNlaSolver_Solve_Proxy
};


static const PRPC_STUB_FUNCTION IIsNlaSolver_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    IIsNlaSolver_SetEso_Stub,
    IIsNlaSolver_Solve_Stub
};

CInterfaceStubVtbl _IIsNlaSolverStubVtbl =
{
    &IID_IIsNlaSolver,
    0,
    9,
    &IIsNlaSolver_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IIsNlaEso, ver. 0.0,
   GUID={0xA6A32B44,0x92E2,0x11d4,{0x98,0xA8,0x00,0xC0,0x4F,0x68,0x01,0xA9}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsNlaEso_GetNumEqns_Proxy( 
    IIsNlaEso __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nEqns)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      7);
        
        
        
        if(!nEqns)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nEqns;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[238] );
            
            *nEqns = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1010],
                         ( void __RPC_FAR * )nEqns);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsNlaEso_GetNumEqns_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long __RPC_FAR *nEqns;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( long __RPC_FAR * )nEqns = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[238] );
        
        nEqns = ( long __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( long  );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsNlaEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetNumEqns((IIsNlaEso *) ((CStdStubBuffer *)This)->pvServerObject,nEqns);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nEqns;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsNlaEso_GetNumVars_Proxy( 
    IIsNlaEso __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nVars)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      8);
        
        
        
        if(!nVars)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nVars;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[238] );
            
            *nVars = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1010],
                         ( void __RPC_FAR * )nVars);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsNlaEso_GetNumVars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long __RPC_FAR *nVars;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( long __RPC_FAR * )nVars = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[238] );
        
        nVars = ( long __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( long  );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsNlaEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetNumVars((IIsNlaEso *) ((CStdStubBuffer *)This)->pvServerObject,nVars);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nVars;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsNlaEso_GetAllVariables_Proxy( 
    IIsNlaEso __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      9);
        
        
        
        if(!Vals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Vals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Vals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[152] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&Vals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )Vals);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsNlaEso_GetAllVariables_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *Vals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Vals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[152] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Vals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsNlaEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetAllVariables((IIsNlaEso *) ((CStdStubBuffer *)This)->pvServerObject,Vals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)Vals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)Vals,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Vals,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsNlaEso_SetAllVariables_Proxy( 
    IIsNlaEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      10);
        
        
        
        if(!Vals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Vals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Vals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[12] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsNlaEso_SetAllVariables_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *Vals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Vals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[12] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Vals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsNlaEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetAllVariables((IIsNlaEso *) ((CStdStubBuffer *)This)->pvServerObject,Vals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Vals,
                        &__MIDL_TypeFormatString.Format[992] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsNlaEso_GetResiduals_Proxy( 
    IIsNlaEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *x,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *residuals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      11);
        
        
        
        if(!x)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!residuals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)x,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)residuals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)x,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)residuals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[60] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&residuals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )residuals);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsNlaEso_GetResiduals_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *residuals;
    SAFEARRAY __RPC_FAR * __RPC_FAR *x;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )x = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )residuals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[60] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&x,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&residuals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsNlaEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetResiduals(
                (IIsNlaEso *) ((CStdStubBuffer *)This)->pvServerObject,
                x,
                residuals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)residuals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)residuals,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)x,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)residuals,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsNlaEso_GetResidual_Proxy( 
    IIsNlaEso __RPC_FAR * This,
    /* [in] */ long iEqn,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *x,
    /* [out][in] */ double __RPC_FAR *residual)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      12);
        
        
        
        if(!x)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!residual)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 0U + 23U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)x,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = iEqn;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)x,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 7) & ~ 0x7);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = *residual;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[354] );
            
            *residual = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1058],
                         ( void __RPC_FAR * )residual);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsNlaEso_GetResidual_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long iEqn;
    double __RPC_FAR *residual;
    SAFEARRAY __RPC_FAR * __RPC_FAR *x;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )x = 0;
    ( double __RPC_FAR * )residual = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[354] );
        
        iEqn = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&x,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 7) & ~ 0x7);
        residual = ( double __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( double  );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsNlaEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetResidual(
               (IIsNlaEso *) ((CStdStubBuffer *)This)->pvServerObject,
               iEqn,
               x,
               residual);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 8U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( double __RPC_FAR * )_StubMsg.Buffer)++ = *residual;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)x,
                        &__MIDL_TypeFormatString.Format[992] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsNlaEso_GetJacobianStruct_Proxy( 
    IIsNlaEso __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nColIndices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      13);
        
        
        
        if(!nColIndices)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!ColIndices)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!cNZCols)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!CalcMethod)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 0U + 0U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)ColIndices,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)cNZCols,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)CalcMethod,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nColIndices;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)ColIndices,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)cNZCols,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)CalcMethod,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[42] );
            
            *nColIndices = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&ColIndices,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&cNZCols,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&CalcMethod,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1010],
                         ( void __RPC_FAR * )nColIndices);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )ColIndices);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )cNZCols);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )CalcMethod);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsNlaEso_GetJacobianStruct_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod;
    SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols;
    long __RPC_FAR *nColIndices;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( long __RPC_FAR * )nColIndices = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )ColIndices = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )cNZCols = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )CalcMethod = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[42] );
        
        nColIndices = ( long __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( long  );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ColIndices,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&cNZCols,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&CalcMethod,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsNlaEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetJacobianStruct(
                     (IIsNlaEso *) ((CStdStubBuffer *)This)->pvServerObject,
                     nColIndices,
                     ColIndices,
                     cNZCols,
                     CalcMethod);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 0U + 0U + 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)ColIndices,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)cNZCols,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)CalcMethod,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nColIndices;
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)ColIndices,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)cNZCols,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)CalcMethod,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ColIndices,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)cNZCols,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)CalcMethod,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsNlaEso_GetJacobianValues_Proxy( 
    IIsNlaEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *JacVals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      14);
        
        
        
        if(!Indices)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!JacVals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Indices,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)JacVals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Indices,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)JacVals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[60] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&JacVals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )JacVals);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsNlaEso_GetJacobianValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *Indices;
    SAFEARRAY __RPC_FAR * __RPC_FAR *JacVals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Indices = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )JacVals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[60] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Indices,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&JacVals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsNlaEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetJacobianValues(
                     (IIsNlaEso *) ((CStdStubBuffer *)This)->pvServerObject,
                     Indices,
                     JacVals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)JacVals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)JacVals,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Indices,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)JacVals,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsNlaEso_GetAllJacobianValues_Proxy( 
    IIsNlaEso __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *JacVals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      15);
        
        
        
        if(!Indices)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!JacVals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Indices,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)JacVals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Indices,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)JacVals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[366] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&Indices,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&JacVals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )Indices);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )JacVals);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsNlaEso_GetAllJacobianValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *Indices;
    SAFEARRAY __RPC_FAR * __RPC_FAR *JacVals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Indices = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )JacVals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[366] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Indices,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&JacVals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsNlaEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetAllJacobianValues(
                        (IIsNlaEso *) ((CStdStubBuffer *)This)->pvServerObject,
                        Indices,
                        JacVals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)Indices,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)JacVals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)Indices,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)JacVals,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Indices,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)JacVals,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsNlaEso_Solve_Proxy( 
    IIsNlaEso __RPC_FAR * This)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      16);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[352] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsNlaEso_Solve_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsNlaEso*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Solve((IIsNlaEso *) ((CStdStubBuffer *)This)->pvServerObject);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

CINTERFACE_PROXY_VTABLE(17) _IIsNlaEsoProxyVtbl = 
{
    &IID_IIsNlaEso,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch_GetTypeInfoCount_Proxy */ ,
    0 /* IDispatch_GetTypeInfo_Proxy */ ,
    0 /* IDispatch_GetIDsOfNames_Proxy */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    IIsNlaEso_GetNumEqns_Proxy ,
    IIsNlaEso_GetNumVars_Proxy ,
    IIsNlaEso_GetAllVariables_Proxy ,
    IIsNlaEso_SetAllVariables_Proxy ,
    IIsNlaEso_GetResiduals_Proxy ,
    IIsNlaEso_GetResidual_Proxy ,
    IIsNlaEso_GetJacobianStruct_Proxy ,
    IIsNlaEso_GetJacobianValues_Proxy ,
    IIsNlaEso_GetAllJacobianValues_Proxy ,
    IIsNlaEso_Solve_Proxy
};


static const PRPC_STUB_FUNCTION IIsNlaEso_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    IIsNlaEso_GetNumEqns_Stub,
    IIsNlaEso_GetNumVars_Stub,
    IIsNlaEso_GetAllVariables_Stub,
    IIsNlaEso_SetAllVariables_Stub,
    IIsNlaEso_GetResiduals_Stub,
    IIsNlaEso_GetResidual_Stub,
    IIsNlaEso_GetJacobianStruct_Stub,
    IIsNlaEso_GetJacobianValues_Stub,
    IIsNlaEso_GetAllJacobianValues_Stub,
    IIsNlaEso_Solve_Stub
};

CInterfaceStubVtbl _IIsNlaEsoStubVtbl =
{
    &IID_IIsNlaEso,
    0,
    17,
    &IIsNlaEso_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IIsDaeEsoImpl, ver. 0.0,
   GUID={0xBFC328F0,0xCBF6,0x11d4,{0x83,0xA2,0x00,0x60,0x08,0x94,0xE8,0x02}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoImpl_Initialize_Proxy( 
    IIsDaeEsoImpl __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nEqns,
    /* [out][in] */ long __RPC_FAR *nVars,
    /* [out][in] */ long __RPC_FAR *nRPars,
    /* [out][in] */ long __RPC_FAR *nIPars,
    /* [out][in] */ double __RPC_FAR *t,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *atol,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *rtol,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *x,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *xdot,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *rpar,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ipar)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      7);
        
        
        
        if(!nEqns)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!nVars)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!nRPars)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!nIPars)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!t)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!atol)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!rtol)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!x)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!xdot)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!rpar)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!ipar)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 4U + 4U + 4U + 8U + 0U + 0U + 0U + 0U + 0U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)atol,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)rtol,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)x,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)xdot,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)rpar,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)ipar,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nEqns;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nVars;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nRPars;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nIPars;
            
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = *t;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)atol,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)rtol,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)x,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)xdot,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)rpar,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)ipar,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[376] );
            
            *nEqns = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            *nVars = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            *nRPars = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            *nIPars = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            *t = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&atol,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&rtol,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&x,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&xdot,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&rpar,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&ipar,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1010],
                         ( void __RPC_FAR * )nEqns);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1010],
                         ( void __RPC_FAR * )nVars);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1010],
                         ( void __RPC_FAR * )nRPars);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1010],
                         ( void __RPC_FAR * )nIPars);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1058],
                         ( void __RPC_FAR * )t);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )atol);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )rtol);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )x);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )xdot);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )rpar);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )ipar);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoImpl_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *atol;
    SAFEARRAY __RPC_FAR * __RPC_FAR *ipar;
    long __RPC_FAR *nEqns;
    long __RPC_FAR *nIPars;
    long __RPC_FAR *nRPars;
    long __RPC_FAR *nVars;
    SAFEARRAY __RPC_FAR * __RPC_FAR *rpar;
    SAFEARRAY __RPC_FAR * __RPC_FAR *rtol;
    double __RPC_FAR *t;
    SAFEARRAY __RPC_FAR * __RPC_FAR *x;
    SAFEARRAY __RPC_FAR * __RPC_FAR *xdot;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( long __RPC_FAR * )nEqns = 0;
    ( long __RPC_FAR * )nVars = 0;
    ( long __RPC_FAR * )nRPars = 0;
    ( long __RPC_FAR * )nIPars = 0;
    ( double __RPC_FAR * )t = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )atol = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )rtol = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )x = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )xdot = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )rpar = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )ipar = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[376] );
        
        nEqns = ( long __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( long  );
        
        nVars = ( long __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( long  );
        
        nRPars = ( long __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( long  );
        
        nIPars = ( long __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( long  );
        
        t = ( double __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( double  );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&atol,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&rtol,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&x,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&xdot,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&rpar,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ipar,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Initialize(
              (IIsDaeEsoImpl *) ((CStdStubBuffer *)This)->pvServerObject,
              nEqns,
              nVars,
              nRPars,
              nIPars,
              t,
              atol,
              rtol,
              x,
              xdot,
              rpar,
              ipar);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 4U + 4U + 4U + 8U + 0U + 0U + 0U + 0U + 0U + 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)atol,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)rtol,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)x,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)xdot,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)rpar,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)ipar,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nEqns;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nVars;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nRPars;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nIPars;
        
        *(( double __RPC_FAR * )_StubMsg.Buffer)++ = *t;
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)atol,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)rtol,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)x,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)xdot,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)rpar,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)ipar,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)atol,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)rtol,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)x,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)xdot,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)rpar,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ipar,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoImpl_GetJacobianStruct_Proxy( 
    IIsDaeEsoImpl __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nColIndices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      8);
        
        
        
        if(!nColIndices)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!ColIndices)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!cNZCols)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!CalcMethod)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 0U + 0U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)ColIndices,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)cNZCols,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)CalcMethod,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nColIndices;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)ColIndices,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)cNZCols,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)CalcMethod,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[42] );
            
            *nColIndices = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&ColIndices,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&cNZCols,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&CalcMethod,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1010],
                         ( void __RPC_FAR * )nColIndices);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )ColIndices);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )cNZCols);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )CalcMethod);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoImpl_GetJacobianStruct_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod;
    SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols;
    long __RPC_FAR *nColIndices;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( long __RPC_FAR * )nColIndices = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )ColIndices = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )cNZCols = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )CalcMethod = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[42] );
        
        nColIndices = ( long __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( long  );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ColIndices,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&cNZCols,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&CalcMethod,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetJacobianStruct(
                     (IIsDaeEsoImpl *) ((CStdStubBuffer *)This)->pvServerObject,
                     nColIndices,
                     ColIndices,
                     cNZCols,
                     CalcMethod);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 0U + 0U + 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)ColIndices,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)cNZCols,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)CalcMethod,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nColIndices;
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)ColIndices,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)cNZCols,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)CalcMethod,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ColIndices,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)cNZCols,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)CalcMethod,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoImpl_GetDiffJacobianStruct_Proxy( 
    IIsDaeEsoImpl __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nColIndices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      9);
        
        
        
        if(!nColIndices)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!ColIndices)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!cNZCols)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!CalcMethod)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 0U + 0U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)ColIndices,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)cNZCols,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)CalcMethod,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nColIndices;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)ColIndices,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)cNZCols,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)CalcMethod,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[42] );
            
            *nColIndices = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&ColIndices,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&cNZCols,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&CalcMethod,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1010],
                         ( void __RPC_FAR * )nColIndices);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )ColIndices);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )cNZCols);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )CalcMethod);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoImpl_GetDiffJacobianStruct_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod;
    SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols;
    long __RPC_FAR *nColIndices;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( long __RPC_FAR * )nColIndices = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )ColIndices = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )cNZCols = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )CalcMethod = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[42] );
        
        nColIndices = ( long __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( long  );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ColIndices,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&cNZCols,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&CalcMethod,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetDiffJacobianStruct(
                         (IIsDaeEsoImpl *) ((CStdStubBuffer *)This)->pvServerObject,
                         nColIndices,
                         ColIndices,
                         cNZCols,
                         CalcMethod);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 0U + 0U + 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)ColIndices,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)cNZCols,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)CalcMethod,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nColIndices;
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)ColIndices,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)cNZCols,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)CalcMethod,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ColIndices,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)cNZCols,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)CalcMethod,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoImpl_GetResiduals_Proxy( 
    IIsDaeEsoImpl __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *iEqn,
    /* [in] */ long nEqn,
    /* [in] */ double t,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *x,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *xdot,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *rPar,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *iPar,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *residuals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      10);
        
        
        
        if(!iEqn)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!x)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!xdot)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!rPar)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!iPar)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!residuals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U + 11U + 20U + 0U + 0U + 0U + 0U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)iEqn,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)x,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)xdot,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)rPar,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)iPar,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)residuals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)iEqn,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = nEqn;
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 7) & ~ 0x7);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = t;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)x,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)xdot,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)rPar,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)iPar,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)residuals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[422] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&residuals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )residuals);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoImpl_GetResiduals_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *iEqn;
    SAFEARRAY __RPC_FAR * __RPC_FAR *iPar;
    long nEqn;
    SAFEARRAY __RPC_FAR * __RPC_FAR *rPar;
    SAFEARRAY __RPC_FAR * __RPC_FAR *residuals;
    double t;
    SAFEARRAY __RPC_FAR * __RPC_FAR *x;
    SAFEARRAY __RPC_FAR * __RPC_FAR *xdot;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )iEqn = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )x = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )xdot = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )rPar = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )iPar = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )residuals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[422] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&iEqn,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        nEqn = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 7) & ~ 0x7);
        t = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&x,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&xdot,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&rPar,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&iPar,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&residuals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetResiduals(
                (IIsDaeEsoImpl *) ((CStdStubBuffer *)This)->pvServerObject,
                iEqn,
                nEqn,
                t,
                x,
                xdot,
                rPar,
                iPar,
                residuals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)residuals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)residuals,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)iEqn,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)x,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)xdot,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)rPar,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)iPar,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)residuals,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoImpl_GetJacobianValues_Proxy( 
    IIsDaeEsoImpl __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *iJac,
    /* [in] */ long nJac,
    /* [in] */ double t,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *x,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *xdot,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *rPar,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *iPar,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *jacobians)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      11);
        
        
        
        if(!iJac)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!x)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!xdot)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!rPar)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!iPar)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!jacobians)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U + 11U + 20U + 0U + 0U + 0U + 0U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)iJac,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)x,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)xdot,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)rPar,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)iPar,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)jacobians,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)iJac,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = nJac;
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 7) & ~ 0x7);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = t;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)x,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)xdot,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)rPar,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)iPar,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)jacobians,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[422] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&jacobians,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )jacobians);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoImpl_GetJacobianValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *iJac;
    SAFEARRAY __RPC_FAR * __RPC_FAR *iPar;
    SAFEARRAY __RPC_FAR * __RPC_FAR *jacobians;
    long nJac;
    SAFEARRAY __RPC_FAR * __RPC_FAR *rPar;
    double t;
    SAFEARRAY __RPC_FAR * __RPC_FAR *x;
    SAFEARRAY __RPC_FAR * __RPC_FAR *xdot;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )iJac = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )x = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )xdot = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )rPar = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )iPar = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )jacobians = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[422] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&iJac,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        nJac = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 7) & ~ 0x7);
        t = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&x,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&xdot,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&rPar,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&iPar,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&jacobians,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetJacobianValues(
                     (IIsDaeEsoImpl *) ((CStdStubBuffer *)This)->pvServerObject,
                     iJac,
                     nJac,
                     t,
                     x,
                     xdot,
                     rPar,
                     iPar,
                     jacobians);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)jacobians,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)jacobians,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)iJac,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)x,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)xdot,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)rPar,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)iPar,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)jacobians,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoImpl_GetDiffJacobianValues_Proxy( 
    IIsDaeEsoImpl __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *iJac,
    /* [in] */ long nJac,
    /* [in] */ double t,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *x,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *xdot,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *rPar,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *iPar,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *jacobians)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      12);
        
        
        
        if(!iJac)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!x)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!xdot)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!rPar)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!iPar)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!jacobians)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U + 11U + 20U + 0U + 0U + 0U + 0U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)iJac,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)x,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)xdot,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)rPar,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)iPar,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)jacobians,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)iJac,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = nJac;
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 7) & ~ 0x7);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = t;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)x,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)xdot,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)rPar,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)iPar,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)jacobians,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[422] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&jacobians,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )jacobians);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoImpl_GetDiffJacobianValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *iJac;
    SAFEARRAY __RPC_FAR * __RPC_FAR *iPar;
    SAFEARRAY __RPC_FAR * __RPC_FAR *jacobians;
    long nJac;
    SAFEARRAY __RPC_FAR * __RPC_FAR *rPar;
    double t;
    SAFEARRAY __RPC_FAR * __RPC_FAR *x;
    SAFEARRAY __RPC_FAR * __RPC_FAR *xdot;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )iJac = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )x = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )xdot = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )rPar = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )iPar = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )jacobians = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[422] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&iJac,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        nJac = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 7) & ~ 0x7);
        t = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&x,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&xdot,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&rPar,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&iPar,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&jacobians,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetDiffJacobianValues(
                         (IIsDaeEsoImpl *) ((CStdStubBuffer *)This)->pvServerObject,
                         iJac,
                         nJac,
                         t,
                         x,
                         xdot,
                         rPar,
                         iPar,
                         jacobians);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)jacobians,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)jacobians,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)iJac,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)x,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)xdot,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)rPar,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)iPar,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)jacobians,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoImpl_GetEqnForm_Proxy( 
    IIsDaeEsoImpl __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *form,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *diff_form)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      13);
        
        
        
        if(!form)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!diff_form)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)form,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)diff_form,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)form,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)diff_form,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[366] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&form,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&diff_form,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )form);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )diff_form);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoImpl_GetEqnForm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *diff_form;
    SAFEARRAY __RPC_FAR * __RPC_FAR *form;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )form = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )diff_form = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[366] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&form,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&diff_form,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetEqnForm(
              (IIsDaeEsoImpl *) ((CStdStubBuffer *)This)->pvServerObject,
              form,
              diff_form);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)form,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)diff_form,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)form,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)diff_form,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)form,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)diff_form,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoImpl_EvalStateCondition_Proxy( 
    IIsDaeEsoImpl __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *EqnState,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *x,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *xdot,
    /* [in] */ double EventTime,
    /* [in] */ long iDisEqn,
    /* [in] */ long iTransition,
    /* [out][in] */ VARIANT_BOOL __RPC_FAR *bEvent)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      14);
        
        
        
        if(!EqnState)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!x)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!xdot)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!bEvent)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U + 0U + 0U + 23U + 8U + 7U + 4U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)EqnState,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)x,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)xdot,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)EqnState,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)x,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)xdot,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 7) & ~ 0x7);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = EventTime;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = iDisEqn;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = iTransition;
            
            *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++ = *bEvent;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[452] );
            
            *bEvent = *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++;
            
            _StubMsg.Buffer += 2;
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1006],
                         ( void __RPC_FAR * )bEvent);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoImpl_EvalStateCondition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *EqnState;
    double EventTime;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    VARIANT_BOOL __RPC_FAR *bEvent;
    long iDisEqn;
    long iTransition;
    SAFEARRAY __RPC_FAR * __RPC_FAR *x;
    SAFEARRAY __RPC_FAR * __RPC_FAR *xdot;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )EqnState = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )x = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )xdot = 0;
    ( VARIANT_BOOL __RPC_FAR * )bEvent = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[452] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&EqnState,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&x,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&xdot,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[996],
                                  (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 7) & ~ 0x7);
        EventTime = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        iDisEqn = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        iTransition = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        bEvent = ( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( VARIANT_BOOL  );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> EvalStateCondition(
                      (IIsDaeEsoImpl *) ((CStdStubBuffer *)This)->pvServerObject,
                      EqnState,
                      x,
                      xdot,
                      EventTime,
                      iDisEqn,
                      iTransition,
                      bEvent);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 2U + 6U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++ = *bEvent;
        
        _StubMsg.Buffer += 2;
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)EqnState,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)x,
                        &__MIDL_TypeFormatString.Format[992] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)xdot,
                        &__MIDL_TypeFormatString.Format[992] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoImpl_GetMemberEsos_Proxy( 
    IIsDaeEsoImpl __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nEsos,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Esos)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      15);
        
        
        
        if(!nEsos)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!Esos)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Esos,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nEsos;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Esos,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[476] );
            
            *nEsos = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&Esos,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1010],
                         ( void __RPC_FAR * )nEsos);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )Esos);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoImpl_GetMemberEsos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *Esos;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long __RPC_FAR *nEsos;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( long __RPC_FAR * )nEsos = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Esos = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[476] );
        
        nEsos = ( long __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( long  );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Esos,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetMemberEsos(
                 (IIsDaeEsoImpl *) ((CStdStubBuffer *)This)->pvServerObject,
                 nEsos,
                 Esos);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)Esos,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nEsos;
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)Esos,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Esos,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoImpl_GetSTNStruct_Proxy( 
    IIsDaeEsoImpl __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nStates,
    /* [out][in] */ long __RPC_FAR *nTransitions,
    /* [out][in] */ long __RPC_FAR *iDefaultState,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TransEventIds,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *SrcStates,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *StateToEqnMap,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TransToEqnMap)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      16);
        
        
        
        if(!nStates)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!nTransitions)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!iDefaultState)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!TransEventIds)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!SrcStates)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!StateToEqnMap)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!TransToEqnMap)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 4U + 4U + 0U + 0U + 0U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)TransEventIds,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)SrcStates,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)StateToEqnMap,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)TransToEqnMap,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nStates;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nTransitions;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *iDefaultState;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)TransEventIds,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)SrcStates,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)StateToEqnMap,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)TransToEqnMap,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[486] );
            
            *nStates = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            *nTransitions = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            *iDefaultState = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&TransEventIds,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&SrcStates,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&StateToEqnMap,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&TransToEqnMap,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1010],
                         ( void __RPC_FAR * )nStates);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1010],
                         ( void __RPC_FAR * )nTransitions);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1010],
                         ( void __RPC_FAR * )iDefaultState);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )TransEventIds);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )SrcStates);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )StateToEqnMap);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )TransToEqnMap);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoImpl_GetSTNStruct_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *SrcStates;
    SAFEARRAY __RPC_FAR * __RPC_FAR *StateToEqnMap;
    SAFEARRAY __RPC_FAR * __RPC_FAR *TransEventIds;
    SAFEARRAY __RPC_FAR * __RPC_FAR *TransToEqnMap;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long __RPC_FAR *iDefaultState;
    long __RPC_FAR *nStates;
    long __RPC_FAR *nTransitions;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( long __RPC_FAR * )nStates = 0;
    ( long __RPC_FAR * )nTransitions = 0;
    ( long __RPC_FAR * )iDefaultState = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )TransEventIds = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )SrcStates = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )StateToEqnMap = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )TransToEqnMap = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[486] );
        
        nStates = ( long __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( long  );
        
        nTransitions = ( long __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( long  );
        
        iDefaultState = ( long __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( long  );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&TransEventIds,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&SrcStates,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&StateToEqnMap,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&TransToEqnMap,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetSTNStruct(
                (IIsDaeEsoImpl *) ((CStdStubBuffer *)This)->pvServerObject,
                nStates,
                nTransitions,
                iDefaultState,
                TransEventIds,
                SrcStates,
                StateToEqnMap,
                TransToEqnMap);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 4U + 4U + 0U + 0U + 0U + 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)TransEventIds,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)SrcStates,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)StateToEqnMap,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)TransToEqnMap,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nStates;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nTransitions;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *iDefaultState;
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)TransEventIds,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)SrcStates,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)StateToEqnMap,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)TransToEqnMap,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)TransEventIds,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)SrcStates,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)StateToEqnMap,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)TransToEqnMap,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoImpl_TriggerEvent_Proxy( 
    IIsDaeEsoImpl __RPC_FAR * This,
    /* [in] */ double EventTime,
    /* [in] */ BSTR EventId,
    /* [in] */ long iEventEqn)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      17);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U + 8U + 11U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&EventId,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = EventTime;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&EventId,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = iEventEqn;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[516] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoImpl_TriggerEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR EventId;
    double EventTime;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_EventId;
    long iEventEqn;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_EventId = &EventId;
    MIDL_memset(
               _p_EventId,
               0,
               sizeof( BSTR  ));
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[516] );
        
        EventTime = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_EventId,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044],
                                  (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        iEventEqn = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> TriggerEvent(
                (IIsDaeEsoImpl *) ((CStdStubBuffer *)This)->pvServerObject,
                EventTime,
                EventId,
                iEventEqn);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&EventId,
                            &__MIDL_TypeFormatString.Format[1044] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoImpl_GetMasterNodeStatus_Proxy( 
    IIsDaeEsoImpl __RPC_FAR * This,
    VARIANT_BOOL __RPC_FAR *bMasterNodeStatus)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      18);
        
        
        
        if(!bMasterNodeStatus)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 2U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++ = *bMasterNodeStatus;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[526] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoImpl_GetMasterNodeStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    VARIANT_BOOL __RPC_FAR *bMasterNodeStatus;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( VARIANT_BOOL __RPC_FAR * )bMasterNodeStatus = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[526] );
        
        bMasterNodeStatus = ( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( VARIANT_BOOL  );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetMasterNodeStatus((IIsDaeEsoImpl *) ((CStdStubBuffer *)This)->pvServerObject,bMasterNodeStatus);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

CINTERFACE_PROXY_VTABLE(19) _IIsDaeEsoImplProxyVtbl = 
{
    &IID_IIsDaeEsoImpl,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch_GetTypeInfoCount_Proxy */ ,
    0 /* IDispatch_GetTypeInfo_Proxy */ ,
    0 /* IDispatch_GetIDsOfNames_Proxy */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    IIsDaeEsoImpl_Initialize_Proxy ,
    IIsDaeEsoImpl_GetJacobianStruct_Proxy ,
    IIsDaeEsoImpl_GetDiffJacobianStruct_Proxy ,
    IIsDaeEsoImpl_GetResiduals_Proxy ,
    IIsDaeEsoImpl_GetJacobianValues_Proxy ,
    IIsDaeEsoImpl_GetDiffJacobianValues_Proxy ,
    IIsDaeEsoImpl_GetEqnForm_Proxy ,
    IIsDaeEsoImpl_EvalStateCondition_Proxy ,
    IIsDaeEsoImpl_GetMemberEsos_Proxy ,
    IIsDaeEsoImpl_GetSTNStruct_Proxy ,
    IIsDaeEsoImpl_TriggerEvent_Proxy ,
    IIsDaeEsoImpl_GetMasterNodeStatus_Proxy
};


static const PRPC_STUB_FUNCTION IIsDaeEsoImpl_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    IIsDaeEsoImpl_Initialize_Stub,
    IIsDaeEsoImpl_GetJacobianStruct_Stub,
    IIsDaeEsoImpl_GetDiffJacobianStruct_Stub,
    IIsDaeEsoImpl_GetResiduals_Stub,
    IIsDaeEsoImpl_GetJacobianValues_Stub,
    IIsDaeEsoImpl_GetDiffJacobianValues_Stub,
    IIsDaeEsoImpl_GetEqnForm_Stub,
    IIsDaeEsoImpl_EvalStateCondition_Stub,
    IIsDaeEsoImpl_GetMemberEsos_Stub,
    IIsDaeEsoImpl_GetSTNStruct_Stub,
    IIsDaeEsoImpl_TriggerEvent_Stub,
    IIsDaeEsoImpl_GetMasterNodeStatus_Stub
};

CInterfaceStubVtbl _IIsDaeEsoImplStubVtbl =
{
    &IID_IIsDaeEsoImpl,
    0,
    19,
    &IIsDaeEsoImpl_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IIsDaeEsoIImpl, ver. 0.0,
   GUID={0x732A30A3,0xCBE5,0x11D4,{0x83,0xA2,0x00,0x60,0x08,0x94,0xE8,0x02}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoIImpl_SetEso_Proxy( 
    IIsDaeEsoIImpl __RPC_FAR * This,
    /* [in] */ IIsDaeEsoImpl __RPC_FAR *pEso)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      64);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrInterfacePointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                           (unsigned char __RPC_FAR *)pEso,
                                           (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1124] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrInterfacePointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                         (unsigned char __RPC_FAR *)pEso,
                                         (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1124] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[532] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoIImpl_SetEso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    IIsDaeEsoImpl __RPC_FAR *pEso;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    pEso = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[532] );
        
        NdrInterfacePointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR * __RPC_FAR *)&pEso,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1124],
                                       (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoIImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetEso((IIsDaeEsoIImpl *) ((CStdStubBuffer *)This)->pvServerObject,pEso);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrInterfacePointerFree( &_StubMsg,
                                 (unsigned char __RPC_FAR *)pEso,
                                 &__MIDL_TypeFormatString.Format[1124] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

CINTERFACE_PROXY_VTABLE(65) _IIsDaeEsoIImplProxyVtbl = 
{
    &IID_IIsDaeEsoIImpl,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch_GetTypeInfoCount_Proxy */ ,
    0 /* IDispatch_GetTypeInfo_Proxy */ ,
    0 /* IDispatch_GetIDsOfNames_Proxy */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    IIsDaeEso_SetRelTolerance_Proxy ,
    IIsDaeEso_GetRelTolerance_Proxy ,
    IIsDaeEso_SetAbsTolerance_Proxy ,
    IIsDaeEso_GetAbsTolerance_Proxy ,
    IIsDaeEso_GetAllResiduals_Proxy ,
    IIsDaeEso_GetResiduals_Proxy ,
    IIsDaeEso_GetJacobianStruct_Proxy ,
    IIsDaeEso_GetJacobianValues_Proxy ,
    IIsDaeEso_GetAllJacobianValues_Proxy ,
    IIsDaeEso_GetDiffJacobianStruct_Proxy ,
    IIsDaeEso_GetDiffJacobianValues_Proxy ,
    IIsDaeEso_GetAllDiffJacobianValues_Proxy ,
    IIsDaeEso_GetVariables_Proxy ,
    IIsDaeEso_GetVariable_Proxy ,
    IIsDaeEso_GetVariableId_Proxy ,
    IIsDaeEso_SetVariables_Proxy ,
    IIsDaeEso_GetAllVariables_Proxy ,
    IIsDaeEso_SetAllVariables_Proxy ,
    IIsDaeEso_GetDerivatives_Proxy ,
    IIsDaeEso_GetDerivative_Proxy ,
    IIsDaeEso_SetDerivatives_Proxy ,
    IIsDaeEso_GetAllDerivatives_Proxy ,
    IIsDaeEso_SetAllDerivatives_Proxy ,
    IIsDaeEso_GetNumVars_Proxy ,
    IIsDaeEso_GetNumEqns_Proxy ,
    IIsDaeEso_GetNumLocalVars_Proxy ,
    IIsDaeEso_GetNumLocalEqns_Proxy ,
    IIsDaeEso_GetLastTime_Proxy ,
    IIsDaeEso_GetTime_Proxy ,
    IIsDaeEso_get_ContainerIndex_Proxy ,
    IIsDaeEso_put_ContainerIndex_Proxy ,
    IIsDaeEso_get_VariableMap_Proxy ,
    IIsDaeEso_put_VariableMap_Proxy ,
    IIsDaeEso_InitTime_Proxy ,
    IIsDaeEso_SetTime_Proxy ,
    IIsDaeEso_SetLastTime_Proxy ,
    IIsDaeEso_GetVariablesIndex_Proxy ,
    IIsDaeEso_AddEso_Proxy ,
    IIsDaeEso_GetEso_Proxy ,
    IIsDaeEso_RemoveEso_Proxy ,
    IIsDaeEso_GetNumEso_Proxy ,
    IIsDaeEso_GetReportInfo_Proxy ,
    IIsDaeEso_EvalStateCondition_Proxy ,
    IIsDaeEso_GetCPPPtr_Proxy ,
    IIsDaeEso_GetNumRealPars_Proxy ,
    IIsDaeEso_GetRealPar_Proxy ,
    IIsDaeEso_GetRealParId_Proxy ,
    IIsDaeEso_SetRealPar_Proxy ,
    IIsDaeEso_GetNumIntPars_Proxy ,
    IIsDaeEso_GetIntPar_Proxy ,
    IIsDaeEso_GetIntParId_Proxy ,
    IIsDaeEso_SetIntPar_Proxy ,
    IIsDaeEso_SetModelExec_Proxy ,
    IIsDaeEso_PostStateEvent_Proxy ,
    IIsDaeEso_PostTransition_Proxy ,
    IIsDaeEso_PostRealParameter_Proxy ,
    IIsDaeEso_PostIntegerParameter_Proxy ,
    IIsDaeEsoIImpl_SetEso_Proxy
};


static const PRPC_STUB_FUNCTION IIsDaeEsoIImpl_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    IIsDaeEso_SetRelTolerance_Stub,
    IIsDaeEso_GetRelTolerance_Stub,
    IIsDaeEso_SetAbsTolerance_Stub,
    IIsDaeEso_GetAbsTolerance_Stub,
    IIsDaeEso_GetAllResiduals_Stub,
    IIsDaeEso_GetResiduals_Stub,
    IIsDaeEso_GetJacobianStruct_Stub,
    IIsDaeEso_GetJacobianValues_Stub,
    IIsDaeEso_GetAllJacobianValues_Stub,
    IIsDaeEso_GetDiffJacobianStruct_Stub,
    IIsDaeEso_GetDiffJacobianValues_Stub,
    IIsDaeEso_GetAllDiffJacobianValues_Stub,
    IIsDaeEso_GetVariables_Stub,
    IIsDaeEso_GetVariable_Stub,
    IIsDaeEso_GetVariableId_Stub,
    IIsDaeEso_SetVariables_Stub,
    IIsDaeEso_GetAllVariables_Stub,
    IIsDaeEso_SetAllVariables_Stub,
    IIsDaeEso_GetDerivatives_Stub,
    IIsDaeEso_GetDerivative_Stub,
    IIsDaeEso_SetDerivatives_Stub,
    IIsDaeEso_GetAllDerivatives_Stub,
    IIsDaeEso_SetAllDerivatives_Stub,
    IIsDaeEso_GetNumVars_Stub,
    IIsDaeEso_GetNumEqns_Stub,
    IIsDaeEso_GetNumLocalVars_Stub,
    IIsDaeEso_GetNumLocalEqns_Stub,
    IIsDaeEso_GetLastTime_Stub,
    IIsDaeEso_GetTime_Stub,
    IIsDaeEso_get_ContainerIndex_Stub,
    IIsDaeEso_put_ContainerIndex_Stub,
    IIsDaeEso_get_VariableMap_Stub,
    IIsDaeEso_put_VariableMap_Stub,
    IIsDaeEso_InitTime_Stub,
    IIsDaeEso_SetTime_Stub,
    IIsDaeEso_SetLastTime_Stub,
    IIsDaeEso_GetVariablesIndex_Stub,
    IIsDaeEso_AddEso_Stub,
    IIsDaeEso_GetEso_Stub,
    IIsDaeEso_RemoveEso_Stub,
    IIsDaeEso_GetNumEso_Stub,
    IIsDaeEso_GetReportInfo_Stub,
    IIsDaeEso_EvalStateCondition_Stub,
    IIsDaeEso_GetCPPPtr_Stub,
    IIsDaeEso_GetNumRealPars_Stub,
    IIsDaeEso_GetRealPar_Stub,
    IIsDaeEso_GetRealParId_Stub,
    IIsDaeEso_SetRealPar_Stub,
    IIsDaeEso_GetNumIntPars_Stub,
    IIsDaeEso_GetIntPar_Stub,
    IIsDaeEso_GetIntParId_Stub,
    IIsDaeEso_SetIntPar_Stub,
    IIsDaeEso_SetModelExec_Stub,
    IIsDaeEso_PostStateEvent_Stub,
    IIsDaeEso_PostTransition_Stub,
    IIsDaeEso_PostRealParameter_Stub,
    IIsDaeEso_PostIntegerParameter_Stub,
    IIsDaeEsoIImpl_SetEso_Stub
};

CInterfaceStubVtbl _IIsDaeEsoIImplStubVtbl =
{
    &IID_IIsDaeEsoIImpl,
    0,
    65,
    &IIsDaeEsoIImpl_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IIsDaeEsoCImpl, ver. 0.0,
   GUID={0x43D71C20,0xE726,0x4786,{0x80,0x0E,0x15,0xC0,0x69,0x68,0xAD,0xF3}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_SetEso_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pEso)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      64);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrInterfacePointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                           (unsigned char __RPC_FAR *)pEso,
                                           (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1142] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrInterfacePointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                         (unsigned char __RPC_FAR *)pEso,
                                         (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1142] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[538] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoCImpl_SetEso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    IUnknown __RPC_FAR *pEso;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    pEso = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[538] );
        
        NdrInterfacePointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR * __RPC_FAR *)&pEso,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1142],
                                       (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoCImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetEso((IIsDaeEsoCImpl *) ((CStdStubBuffer *)This)->pvServerObject,pEso);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrInterfacePointerFree( &_StubMsg,
                                 (unsigned char __RPC_FAR *)pEso,
                                 &__MIDL_TypeFormatString.Format[1142] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_GetEsoNames_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pEsoNames)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      65);
        
        
        
        if(!pEsoNames)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)pEsoNames,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)pEsoNames,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[152] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pEsoNames,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )pEsoNames);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoCImpl_GetEsoNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *pEsoNames;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )pEsoNames = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[152] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&pEsoNames,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoCImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetEsoNames((IIsDaeEsoCImpl *) ((CStdStubBuffer *)This)->pvServerObject,pEsoNames);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)pEsoNames,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)pEsoNames,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)pEsoNames,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_get_Eso_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [retval][out] */ IIsDaeEsoCImpl __RPC_FAR *__RPC_FAR *pEso)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(pEso)
        {
        MIDL_memset(
               pEso,
               0,
               sizeof( IIsDaeEsoCImpl __RPC_FAR *__RPC_FAR * ));
        }
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      66);
        
        
        
        if(!pEso)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&Name,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&Name,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[544] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&pEso,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1160],
                                  (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1160],
                         ( void __RPC_FAR * )pEso);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoCImpl_get_Eso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR Name;
    IIsDaeEsoCImpl __RPC_FAR *_M28;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_Name;
    IIsDaeEsoCImpl __RPC_FAR *__RPC_FAR *pEso;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_Name = &Name;
    MIDL_memset(
               _p_Name,
               0,
               sizeof( BSTR  ));
    ( IIsDaeEsoCImpl __RPC_FAR *__RPC_FAR * )pEso = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[544] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_Name,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044],
                                  (unsigned char)0 );
        
        pEso = &_M28;
        _M28 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoCImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> get_Eso(
           (IIsDaeEsoCImpl *) ((CStdStubBuffer *)This)->pvServerObject,
           Name,
           pEso);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 4U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)pEso,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1160] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)pEso,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1160] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&Name,
                            &__MIDL_TypeFormatString.Format[1044] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)pEso,
                        &__MIDL_TypeFormatString.Format[1160] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_GetVarNames_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pVarNames)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      67);
        
        
        
        if(!pVarNames)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)pVarNames,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)pVarNames,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[152] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pVarNames,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )pVarNames);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoCImpl_GetVarNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *pVarNames;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )pVarNames = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[152] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&pVarNames,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoCImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetVarNames((IIsDaeEsoCImpl *) ((CStdStubBuffer *)This)->pvServerObject,pVarNames);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)pVarNames,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)pVarNames,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)pVarNames,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_get_Var_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [retval][out] */ double __RPC_FAR *pVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      68);
        
        
        
        if(!pVal)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&Name,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&Name,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[554] );
            
            *pVal = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1036],
                         ( void __RPC_FAR * )pVal);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoCImpl_get_Var_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR Name;
    double _M29;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_Name;
    double __RPC_FAR *pVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_Name = &Name;
    MIDL_memset(
               _p_Name,
               0,
               sizeof( BSTR  ));
    ( double __RPC_FAR * )pVal = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[554] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_Name,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044],
                                  (unsigned char)0 );
        
        pVal = &_M29;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoCImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> get_Var(
           (IIsDaeEsoCImpl *) ((CStdStubBuffer *)This)->pvServerObject,
           Name,
           pVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 8U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( double __RPC_FAR * )_StubMsg.Buffer)++ = *pVal;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&Name,
                            &__MIDL_TypeFormatString.Format[1044] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_put_Var_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [in] */ double Val)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      69);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U + 23U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&Name,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&Name,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 7) & ~ 0x7);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = Val;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[564] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoCImpl_put_Var_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR Name;
    double Val;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_Name;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_Name = &Name;
    MIDL_memset(
               _p_Name,
               0,
               sizeof( BSTR  ));
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[564] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_Name,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044],
                                  (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 7) & ~ 0x7);
        Val = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoCImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> put_Var(
           (IIsDaeEsoCImpl *) ((CStdStubBuffer *)This)->pvServerObject,
           Name,
           Val);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&Name,
                            &__MIDL_TypeFormatString.Format[1044] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_GetRParNames_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pRParNames)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      70);
        
        
        
        if(!pRParNames)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)pRParNames,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)pRParNames,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[152] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pRParNames,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )pRParNames);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoCImpl_GetRParNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *pRParNames;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )pRParNames = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[152] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&pRParNames,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoCImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetRParNames((IIsDaeEsoCImpl *) ((CStdStubBuffer *)This)->pvServerObject,pRParNames);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)pRParNames,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)pRParNames,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)pRParNames,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_get_RPar_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [retval][out] */ double __RPC_FAR *pVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      71);
        
        
        
        if(!pVal)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&Name,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&Name,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[554] );
            
            *pVal = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1036],
                         ( void __RPC_FAR * )pVal);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoCImpl_get_RPar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR Name;
    double _M30;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_Name;
    double __RPC_FAR *pVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_Name = &Name;
    MIDL_memset(
               _p_Name,
               0,
               sizeof( BSTR  ));
    ( double __RPC_FAR * )pVal = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[554] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_Name,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044],
                                  (unsigned char)0 );
        
        pVal = &_M30;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoCImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> get_RPar(
            (IIsDaeEsoCImpl *) ((CStdStubBuffer *)This)->pvServerObject,
            Name,
            pVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 8U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( double __RPC_FAR * )_StubMsg.Buffer)++ = *pVal;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&Name,
                            &__MIDL_TypeFormatString.Format[1044] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_put_RPar_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [in] */ double Val)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      72);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U + 23U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&Name,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&Name,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 7) & ~ 0x7);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = Val;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[564] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoCImpl_put_RPar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR Name;
    double Val;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_Name;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_Name = &Name;
    MIDL_memset(
               _p_Name,
               0,
               sizeof( BSTR  ));
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[564] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_Name,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044],
                                  (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 7) & ~ 0x7);
        Val = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoCImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> put_RPar(
            (IIsDaeEsoCImpl *) ((CStdStubBuffer *)This)->pvServerObject,
            Name,
            Val);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&Name,
                            &__MIDL_TypeFormatString.Format[1044] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_GetIParNames_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pIParNames)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      73);
        
        
        
        if(!pIParNames)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)pIParNames,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)pIParNames,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[152] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pIParNames,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )pIParNames);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoCImpl_GetIParNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *pIParNames;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )pIParNames = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[152] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&pIParNames,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoCImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetIParNames((IIsDaeEsoCImpl *) ((CStdStubBuffer *)This)->pvServerObject,pIParNames);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)pIParNames,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)pIParNames,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)pIParNames,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_get_IPar_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [retval][out] */ long __RPC_FAR *pVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      74);
        
        
        
        if(!pVal)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&Name,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&Name,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[98] );
            
            *pVal = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1054],
                         ( void __RPC_FAR * )pVal);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoCImpl_get_IPar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR Name;
    long _M31;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_Name;
    long __RPC_FAR *pVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_Name = &Name;
    MIDL_memset(
               _p_Name,
               0,
               sizeof( BSTR  ));
    ( long __RPC_FAR * )pVal = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[98] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_Name,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044],
                                  (unsigned char)0 );
        
        pVal = &_M31;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoCImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> get_IPar(
            (IIsDaeEsoCImpl *) ((CStdStubBuffer *)This)->pvServerObject,
            Name,
            pVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *pVal;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&Name,
                            &__MIDL_TypeFormatString.Format[1044] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_put_IPar_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [in] */ long Val)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      75);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U + 11U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&Name,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&Name,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = Val;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[572] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoCImpl_put_IPar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR Name;
    long Val;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_Name;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_Name = &Name;
    MIDL_memset(
               _p_Name,
               0,
               sizeof( BSTR  ));
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[572] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_Name,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044],
                                  (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        Val = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoCImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> put_IPar(
            (IIsDaeEsoCImpl *) ((CStdStubBuffer *)This)->pvServerObject,
            Name,
            Val);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&Name,
                            &__MIDL_TypeFormatString.Format[1044] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_GetEqnNames_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pEqnNames)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      76);
        
        
        
        if(!pEqnNames)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)pEqnNames,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)pEqnNames,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[152] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&pEqnNames,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )pEqnNames);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoCImpl_GetEqnNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *pEqnNames;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )pEqnNames = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[152] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&pEqnNames,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoCImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetEqnNames((IIsDaeEsoCImpl *) ((CStdStubBuffer *)This)->pvServerObject,pEqnNames);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)pEqnNames,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)pEqnNames,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)pEqnNames,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_Connect_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ConnA,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ConnB)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      77);
        
        
        
        if(!ConnA)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!ConnB)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)ConnA,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)ConnB,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)ConnA,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)ConnB,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[366] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&ConnA,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&ConnB,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )ConnA);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )ConnB);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoCImpl_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *ConnA;
    SAFEARRAY __RPC_FAR * __RPC_FAR *ConnB;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )ConnA = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )ConnB = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[366] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ConnA,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ConnB,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoCImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Connect(
           (IIsDaeEsoCImpl *) ((CStdStubBuffer *)This)->pvServerObject,
           ConnA,
           ConnB);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)ConnA,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)ConnB,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)ConnA,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)ConnB,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ConnA,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ConnB,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_AddModel_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [in] */ IIsDaeEsoCImpl __RPC_FAR *pEso,
    /* [in] */ BSTR modelName)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      78);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U + 8U;
            NdrInterfacePointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                           (unsigned char __RPC_FAR *)pEso,
                                           (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1164] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&modelName,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrInterfacePointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                         (unsigned char __RPC_FAR *)pEso,
                                         (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1164] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&modelName,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[580] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoCImpl_AddModel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_modelName;
    BSTR modelName;
    IIsDaeEsoCImpl __RPC_FAR *pEso;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    pEso = 0;
    _p_modelName = &modelName;
    MIDL_memset(
               _p_modelName,
               0,
               sizeof( BSTR  ));
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[580] );
        
        NdrInterfacePointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR * __RPC_FAR *)&pEso,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1164],
                                       (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_modelName,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoCImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> AddModel(
            (IIsDaeEsoCImpl *) ((CStdStubBuffer *)This)->pvServerObject,
            pEso,
            modelName);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrInterfacePointerFree( &_StubMsg,
                                 (unsigned char __RPC_FAR *)pEso,
                                 &__MIDL_TypeFormatString.Format[1164] );
        
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&modelName,
                            &__MIDL_TypeFormatString.Format[1044] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_get_EsoImpl_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pEsoImpl)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    if(pEsoImpl)
        {
        MIDL_memset(
               pEsoImpl,
               0,
               sizeof( IUnknown __RPC_FAR *__RPC_FAR * ));
        }
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      79);
        
        
        
        if(!pEsoImpl)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[590] );
            
            NdrPointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&pEsoImpl,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1182],
                                  (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1182],
                         ( void __RPC_FAR * )pEsoImpl);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoCImpl_get_EsoImpl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    IUnknown __RPC_FAR *_M32;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    IUnknown __RPC_FAR *__RPC_FAR *pEsoImpl;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( IUnknown __RPC_FAR *__RPC_FAR * )pEsoImpl = 0;
    RpcTryFinally
        {
        pEsoImpl = &_M32;
        _M32 = 0;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoCImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> get_EsoImpl((IIsDaeEsoCImpl *) ((CStdStubBuffer *)This)->pvServerObject,pEsoImpl);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 4U;
        NdrPointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                              (unsigned char __RPC_FAR *)pEsoImpl,
                              (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1182] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrPointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                            (unsigned char __RPC_FAR *)pEsoImpl,
                            (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1182] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)pEsoImpl,
                        &__MIDL_TypeFormatString.Format[1182] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_CompositeModelComplete_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      80);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[352] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IIsDaeEsoCImpl_CompositeModelComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IIsDaeEsoCImpl*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> CompositeModelComplete((IIsDaeEsoCImpl *) ((CStdStubBuffer *)This)->pvServerObject);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

CINTERFACE_PROXY_VTABLE(81) _IIsDaeEsoCImplProxyVtbl = 
{
    &IID_IIsDaeEsoCImpl,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch_GetTypeInfoCount_Proxy */ ,
    0 /* IDispatch_GetTypeInfo_Proxy */ ,
    0 /* IDispatch_GetIDsOfNames_Proxy */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    IIsDaeEso_SetRelTolerance_Proxy ,
    IIsDaeEso_GetRelTolerance_Proxy ,
    IIsDaeEso_SetAbsTolerance_Proxy ,
    IIsDaeEso_GetAbsTolerance_Proxy ,
    IIsDaeEso_GetAllResiduals_Proxy ,
    IIsDaeEso_GetResiduals_Proxy ,
    IIsDaeEso_GetJacobianStruct_Proxy ,
    IIsDaeEso_GetJacobianValues_Proxy ,
    IIsDaeEso_GetAllJacobianValues_Proxy ,
    IIsDaeEso_GetDiffJacobianStruct_Proxy ,
    IIsDaeEso_GetDiffJacobianValues_Proxy ,
    IIsDaeEso_GetAllDiffJacobianValues_Proxy ,
    IIsDaeEso_GetVariables_Proxy ,
    IIsDaeEso_GetVariable_Proxy ,
    IIsDaeEso_GetVariableId_Proxy ,
    IIsDaeEso_SetVariables_Proxy ,
    IIsDaeEso_GetAllVariables_Proxy ,
    IIsDaeEso_SetAllVariables_Proxy ,
    IIsDaeEso_GetDerivatives_Proxy ,
    IIsDaeEso_GetDerivative_Proxy ,
    IIsDaeEso_SetDerivatives_Proxy ,
    IIsDaeEso_GetAllDerivatives_Proxy ,
    IIsDaeEso_SetAllDerivatives_Proxy ,
    IIsDaeEso_GetNumVars_Proxy ,
    IIsDaeEso_GetNumEqns_Proxy ,
    IIsDaeEso_GetNumLocalVars_Proxy ,
    IIsDaeEso_GetNumLocalEqns_Proxy ,
    IIsDaeEso_GetLastTime_Proxy ,
    IIsDaeEso_GetTime_Proxy ,
    IIsDaeEso_get_ContainerIndex_Proxy ,
    IIsDaeEso_put_ContainerIndex_Proxy ,
    IIsDaeEso_get_VariableMap_Proxy ,
    IIsDaeEso_put_VariableMap_Proxy ,
    IIsDaeEso_InitTime_Proxy ,
    IIsDaeEso_SetTime_Proxy ,
    IIsDaeEso_SetLastTime_Proxy ,
    IIsDaeEso_GetVariablesIndex_Proxy ,
    IIsDaeEso_AddEso_Proxy ,
    IIsDaeEso_GetEso_Proxy ,
    IIsDaeEso_RemoveEso_Proxy ,
    IIsDaeEso_GetNumEso_Proxy ,
    IIsDaeEso_GetReportInfo_Proxy ,
    IIsDaeEso_EvalStateCondition_Proxy ,
    IIsDaeEso_GetCPPPtr_Proxy ,
    IIsDaeEso_GetNumRealPars_Proxy ,
    IIsDaeEso_GetRealPar_Proxy ,
    IIsDaeEso_GetRealParId_Proxy ,
    IIsDaeEso_SetRealPar_Proxy ,
    IIsDaeEso_GetNumIntPars_Proxy ,
    IIsDaeEso_GetIntPar_Proxy ,
    IIsDaeEso_GetIntParId_Proxy ,
    IIsDaeEso_SetIntPar_Proxy ,
    IIsDaeEso_SetModelExec_Proxy ,
    IIsDaeEso_PostStateEvent_Proxy ,
    IIsDaeEso_PostTransition_Proxy ,
    IIsDaeEso_PostRealParameter_Proxy ,
    IIsDaeEso_PostIntegerParameter_Proxy ,
    IIsDaeEsoCImpl_SetEso_Proxy ,
    IIsDaeEsoCImpl_GetEsoNames_Proxy ,
    IIsDaeEsoCImpl_get_Eso_Proxy ,
    IIsDaeEsoCImpl_GetVarNames_Proxy ,
    IIsDaeEsoCImpl_get_Var_Proxy ,
    IIsDaeEsoCImpl_put_Var_Proxy ,
    IIsDaeEsoCImpl_GetRParNames_Proxy ,
    IIsDaeEsoCImpl_get_RPar_Proxy ,
    IIsDaeEsoCImpl_put_RPar_Proxy ,
    IIsDaeEsoCImpl_GetIParNames_Proxy ,
    IIsDaeEsoCImpl_get_IPar_Proxy ,
    IIsDaeEsoCImpl_put_IPar_Proxy ,
    IIsDaeEsoCImpl_GetEqnNames_Proxy ,
    IIsDaeEsoCImpl_Connect_Proxy ,
    IIsDaeEsoCImpl_AddModel_Proxy ,
    IIsDaeEsoCImpl_get_EsoImpl_Proxy ,
    IIsDaeEsoCImpl_CompositeModelComplete_Proxy
};


static const PRPC_STUB_FUNCTION IIsDaeEsoCImpl_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    IIsDaeEso_SetRelTolerance_Stub,
    IIsDaeEso_GetRelTolerance_Stub,
    IIsDaeEso_SetAbsTolerance_Stub,
    IIsDaeEso_GetAbsTolerance_Stub,
    IIsDaeEso_GetAllResiduals_Stub,
    IIsDaeEso_GetResiduals_Stub,
    IIsDaeEso_GetJacobianStruct_Stub,
    IIsDaeEso_GetJacobianValues_Stub,
    IIsDaeEso_GetAllJacobianValues_Stub,
    IIsDaeEso_GetDiffJacobianStruct_Stub,
    IIsDaeEso_GetDiffJacobianValues_Stub,
    IIsDaeEso_GetAllDiffJacobianValues_Stub,
    IIsDaeEso_GetVariables_Stub,
    IIsDaeEso_GetVariable_Stub,
    IIsDaeEso_GetVariableId_Stub,
    IIsDaeEso_SetVariables_Stub,
    IIsDaeEso_GetAllVariables_Stub,
    IIsDaeEso_SetAllVariables_Stub,
    IIsDaeEso_GetDerivatives_Stub,
    IIsDaeEso_GetDerivative_Stub,
    IIsDaeEso_SetDerivatives_Stub,
    IIsDaeEso_GetAllDerivatives_Stub,
    IIsDaeEso_SetAllDerivatives_Stub,
    IIsDaeEso_GetNumVars_Stub,
    IIsDaeEso_GetNumEqns_Stub,
    IIsDaeEso_GetNumLocalVars_Stub,
    IIsDaeEso_GetNumLocalEqns_Stub,
    IIsDaeEso_GetLastTime_Stub,
    IIsDaeEso_GetTime_Stub,
    IIsDaeEso_get_ContainerIndex_Stub,
    IIsDaeEso_put_ContainerIndex_Stub,
    IIsDaeEso_get_VariableMap_Stub,
    IIsDaeEso_put_VariableMap_Stub,
    IIsDaeEso_InitTime_Stub,
    IIsDaeEso_SetTime_Stub,
    IIsDaeEso_SetLastTime_Stub,
    IIsDaeEso_GetVariablesIndex_Stub,
    IIsDaeEso_AddEso_Stub,
    IIsDaeEso_GetEso_Stub,
    IIsDaeEso_RemoveEso_Stub,
    IIsDaeEso_GetNumEso_Stub,
    IIsDaeEso_GetReportInfo_Stub,
    IIsDaeEso_EvalStateCondition_Stub,
    IIsDaeEso_GetCPPPtr_Stub,
    IIsDaeEso_GetNumRealPars_Stub,
    IIsDaeEso_GetRealPar_Stub,
    IIsDaeEso_GetRealParId_Stub,
    IIsDaeEso_SetRealPar_Stub,
    IIsDaeEso_GetNumIntPars_Stub,
    IIsDaeEso_GetIntPar_Stub,
    IIsDaeEso_GetIntParId_Stub,
    IIsDaeEso_SetIntPar_Stub,
    IIsDaeEso_SetModelExec_Stub,
    IIsDaeEso_PostStateEvent_Stub,
    IIsDaeEso_PostTransition_Stub,
    IIsDaeEso_PostRealParameter_Stub,
    IIsDaeEso_PostIntegerParameter_Stub,
    IIsDaeEsoCImpl_SetEso_Stub,
    IIsDaeEsoCImpl_GetEsoNames_Stub,
    IIsDaeEsoCImpl_get_Eso_Stub,
    IIsDaeEsoCImpl_GetVarNames_Stub,
    IIsDaeEsoCImpl_get_Var_Stub,
    IIsDaeEsoCImpl_put_Var_Stub,
    IIsDaeEsoCImpl_GetRParNames_Stub,
    IIsDaeEsoCImpl_get_RPar_Stub,
    IIsDaeEsoCImpl_put_RPar_Stub,
    IIsDaeEsoCImpl_GetIParNames_Stub,
    IIsDaeEsoCImpl_get_IPar_Stub,
    IIsDaeEsoCImpl_put_IPar_Stub,
    IIsDaeEsoCImpl_GetEqnNames_Stub,
    IIsDaeEsoCImpl_Connect_Stub,
    IIsDaeEsoCImpl_AddModel_Stub,
    IIsDaeEsoCImpl_get_EsoImpl_Stub,
    IIsDaeEsoCImpl_CompositeModelComplete_Stub
};

CInterfaceStubVtbl _IIsDaeEsoCImplStubVtbl =
{
    &IID_IIsDaeEsoCImpl,
    0,
    81,
    &IIsDaeEsoCImpl_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IOnModelExecEvents, ver. 0.0,
   GUID={0x60453BD6,0x4CD9,0x425c,{0x86,0x8B,0xE0,0x4F,0x7D,0x4E,0x16,0xC2}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExecEvents_BeforeRParEvent_Proxy( 
    IOnModelExecEvents __RPC_FAR * This,
    double Time,
    long iGlobalId,
    double Value)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      7);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U + 4U + 12U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = Time;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = iGlobalId;
            
            _StubMsg.Buffer += 4;
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = Value;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[296] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExecEvents_BeforeRParEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    double Time;
    double Value;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long iGlobalId;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[296] );
        
        Time = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        iGlobalId = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        _StubMsg.Buffer += 4;
        Value = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExecEvents*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> BeforeRParEvent(
                   (IOnModelExecEvents *) ((CStdStubBuffer *)This)->pvServerObject,
                   Time,
                   iGlobalId,
                   Value);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExecEvents_BeforeIParEvent_Proxy( 
    IOnModelExecEvents __RPC_FAR * This,
    double Time,
    long iGlobalId,
    long Value)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      8);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U + 4U + 4U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = Time;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = iGlobalId;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = Value;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[304] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExecEvents_BeforeIParEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    double Time;
    long Value;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long iGlobalId;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[304] );
        
        Time = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        iGlobalId = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        Value = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExecEvents*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> BeforeIParEvent(
                   (IOnModelExecEvents *) ((CStdStubBuffer *)This)->pvServerObject,
                   Time,
                   iGlobalId,
                   Value);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExecEvents_BeforeStateEvent_Proxy( 
    IOnModelExecEvents __RPC_FAR * This,
    double Time,
    BSTR EvId,
    long iEvEqn)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      9);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U + 8U + 11U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&EvId,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = Time;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&EvId,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = iEvEqn;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[516] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExecEvents_BeforeStateEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR EvId;
    double Time;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_EvId;
    long iEvEqn;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_EvId = &EvId;
    MIDL_memset(
               _p_EvId,
               0,
               sizeof( BSTR  ));
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[516] );
        
        Time = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_EvId,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044],
                                  (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        iEvEqn = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExecEvents*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> BeforeStateEvent(
                    (IOnModelExecEvents *) ((CStdStubBuffer *)This)->pvServerObject,
                    Time,
                    EvId,
                    iEvEqn);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&EvId,
                            &__MIDL_TypeFormatString.Format[1044] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExecEvents_AfterRParEvent_Proxy( 
    IOnModelExecEvents __RPC_FAR * This,
    double Time,
    long iGlobalId,
    double Value)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      10);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U + 4U + 12U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = Time;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = iGlobalId;
            
            _StubMsg.Buffer += 4;
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = Value;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[296] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExecEvents_AfterRParEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    double Time;
    double Value;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long iGlobalId;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[296] );
        
        Time = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        iGlobalId = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        _StubMsg.Buffer += 4;
        Value = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExecEvents*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> AfterRParEvent(
                  (IOnModelExecEvents *) ((CStdStubBuffer *)This)->pvServerObject,
                  Time,
                  iGlobalId,
                  Value);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExecEvents_AfterIParEvent_Proxy( 
    IOnModelExecEvents __RPC_FAR * This,
    double Time,
    long iGlobalId,
    long Value)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      11);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U + 4U + 4U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = Time;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = iGlobalId;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = Value;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[304] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExecEvents_AfterIParEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    double Time;
    long Value;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long iGlobalId;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[304] );
        
        Time = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        iGlobalId = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        Value = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExecEvents*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> AfterIParEvent(
                  (IOnModelExecEvents *) ((CStdStubBuffer *)This)->pvServerObject,
                  Time,
                  iGlobalId,
                  Value);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExecEvents_AfterStateEvent_Proxy( 
    IOnModelExecEvents __RPC_FAR * This,
    double Time,
    BSTR EvId,
    long iEvEqn)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      12);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U + 8U + 11U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&EvId,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = Time;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&EvId,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = iEvEqn;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[516] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExecEvents_AfterStateEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR EvId;
    double Time;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_EvId;
    long iEvEqn;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_EvId = &EvId;
    MIDL_memset(
               _p_EvId,
               0,
               sizeof( BSTR  ));
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[516] );
        
        Time = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_EvId,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044],
                                  (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        iEvEqn = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExecEvents*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> AfterStateEvent(
                   (IOnModelExecEvents *) ((CStdStubBuffer *)This)->pvServerObject,
                   Time,
                   EvId,
                   iEvEqn);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&EvId,
                            &__MIDL_TypeFormatString.Format[1044] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExecEvents_InitializationInfo_Proxy( 
    IOnModelExecEvents __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL fault,
    /* [in] */ long stage,
    /* [in] */ long nModelEqns,
    /* [in] */ long nModelVars,
    /* [in] */ long nActiveEqns,
    /* [in] */ long nActiveVars,
    /* [in] */ long nAugmentedEqns,
    /* [in] */ long nAugmentedVars,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *EqnNames,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarNames,
    /* [in] */ long nColIndices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *spRowPage,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *EqnOrder,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarOrder,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VAL,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *EAL,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *AssignedEqn,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarVals,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarDotVals,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ResVals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      13);
        
        
        
        if(!EqnNames)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!VarNames)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!cNZCols)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!spRowPage)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!ColIndices)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!EqnOrder)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!VarOrder)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!VAL)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!EAL)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!AssignedEqn)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!VarVals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!VarDotVals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!ResVals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 2U + 6U + 4U + 4U + 4U + 4U + 4U + 4U + 0U + 0U + 11U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)EqnNames,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)VarNames,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)cNZCols,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)spRowPage,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)ColIndices,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)EqnOrder,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)VarOrder,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)VAL,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)EAL,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)AssignedEqn,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)VarVals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)VarDotVals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)ResVals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++ = fault;
            
            _StubMsg.Buffer += 2;
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = stage;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = nModelEqns;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = nModelVars;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = nActiveEqns;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = nActiveVars;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = nAugmentedEqns;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = nAugmentedVars;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)EqnNames,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)VarNames,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = nColIndices;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)cNZCols,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)spRowPage,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)ColIndices,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)EqnOrder,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)VarOrder,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)VAL,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)EAL,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)AssignedEqn,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)VarVals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)VarDotVals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)ResVals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[596] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&EqnNames,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&VarNames,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&cNZCols,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&spRowPage,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&ColIndices,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&EqnOrder,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&VarOrder,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&VAL,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&EAL,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&AssignedEqn,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&VarVals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&VarDotVals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&ResVals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )EqnNames);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )VarNames);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )cNZCols);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )spRowPage);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )ColIndices);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )EqnOrder);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )VarOrder);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )VAL);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )EAL);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )AssignedEqn);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )VarVals);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )VarDotVals);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )ResVals);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExecEvents_InitializationInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *AssignedEqn;
    SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices;
    SAFEARRAY __RPC_FAR * __RPC_FAR *EAL;
    SAFEARRAY __RPC_FAR * __RPC_FAR *EqnNames;
    SAFEARRAY __RPC_FAR * __RPC_FAR *EqnOrder;
    SAFEARRAY __RPC_FAR * __RPC_FAR *ResVals;
    SAFEARRAY __RPC_FAR * __RPC_FAR *VAL;
    SAFEARRAY __RPC_FAR * __RPC_FAR *VarDotVals;
    SAFEARRAY __RPC_FAR * __RPC_FAR *VarNames;
    SAFEARRAY __RPC_FAR * __RPC_FAR *VarOrder;
    SAFEARRAY __RPC_FAR * __RPC_FAR *VarVals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols;
    VARIANT_BOOL fault;
    long nActiveEqns;
    long nActiveVars;
    long nAugmentedEqns;
    long nAugmentedVars;
    long nColIndices;
    long nModelEqns;
    long nModelVars;
    SAFEARRAY __RPC_FAR * __RPC_FAR *spRowPage;
    long stage;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )EqnNames = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )VarNames = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )cNZCols = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )spRowPage = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )ColIndices = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )EqnOrder = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )VarOrder = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )VAL = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )EAL = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )AssignedEqn = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )VarVals = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )VarDotVals = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )ResVals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[596] );
        
        fault = *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++;
        
        _StubMsg.Buffer += 2;
        stage = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        nModelEqns = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        nModelVars = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        nActiveEqns = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        nActiveVars = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        nAugmentedEqns = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        nAugmentedVars = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&EqnNames,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&VarNames,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        nColIndices = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&cNZCols,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&spRowPage,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ColIndices,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&EqnOrder,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&VarOrder,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&VAL,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&EAL,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&AssignedEqn,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&VarVals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&VarDotVals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ResVals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExecEvents*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> InitializationInfo(
                      (IOnModelExecEvents *) ((CStdStubBuffer *)This)->pvServerObject,
                      fault,
                      stage,
                      nModelEqns,
                      nModelVars,
                      nActiveEqns,
                      nActiveVars,
                      nAugmentedEqns,
                      nAugmentedVars,
                      EqnNames,
                      VarNames,
                      nColIndices,
                      cNZCols,
                      spRowPage,
                      ColIndices,
                      EqnOrder,
                      VarOrder,
                      VAL,
                      EAL,
                      AssignedEqn,
                      VarVals,
                      VarDotVals,
                      ResVals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)EqnNames,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)VarNames,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)cNZCols,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)spRowPage,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)ColIndices,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)EqnOrder,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)VarOrder,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)VAL,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)EAL,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)AssignedEqn,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)VarVals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)VarDotVals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)ResVals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)EqnNames,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)VarNames,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)cNZCols,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)spRowPage,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)ColIndices,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)EqnOrder,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)VarOrder,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)VAL,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)EAL,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)AssignedEqn,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)VarVals,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)VarDotVals,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)ResVals,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)EqnNames,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)VarNames,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)cNZCols,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)spRowPage,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ColIndices,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)EqnOrder,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)VarOrder,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)VAL,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)EAL,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)AssignedEqn,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)VarVals,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)VarDotVals,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ResVals,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExecEvents_GetTrimEqns_Proxy( 
    IOnModelExecEvents __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nEqns,
    /* [out][in] */ long __RPC_FAR *nColIndices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *spRowPage,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      14);
        
        
        
        if(!nEqns)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!nColIndices)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!cNZCols)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!spRowPage)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!ColIndices)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 4U + 0U + 0U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)cNZCols,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)spRowPage,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)ColIndices,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nEqns;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nColIndices;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)cNZCols,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)spRowPage,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)ColIndices,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[668] );
            
            *nEqns = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            *nColIndices = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&cNZCols,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&spRowPage,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&ColIndices,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1010],
                         ( void __RPC_FAR * )nEqns);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1010],
                         ( void __RPC_FAR * )nColIndices);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )cNZCols);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )spRowPage);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )ColIndices);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExecEvents_GetTrimEqns_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols;
    long __RPC_FAR *nColIndices;
    long __RPC_FAR *nEqns;
    SAFEARRAY __RPC_FAR * __RPC_FAR *spRowPage;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( long __RPC_FAR * )nEqns = 0;
    ( long __RPC_FAR * )nColIndices = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )cNZCols = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )spRowPage = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )ColIndices = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[668] );
        
        nEqns = ( long __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( long  );
        
        nColIndices = ( long __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( long  );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&cNZCols,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&spRowPage,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ColIndices,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExecEvents*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetTrimEqns(
               (IOnModelExecEvents *) ((CStdStubBuffer *)This)->pvServerObject,
               nEqns,
               nColIndices,
               cNZCols,
               spRowPage,
               ColIndices);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 4U + 0U + 0U + 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)cNZCols,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)spRowPage,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)ColIndices,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nEqns;
        
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nColIndices;
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)cNZCols,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)spRowPage,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)ColIndices,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)cNZCols,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)spRowPage,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ColIndices,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExecEvents_GetTrimVars_Proxy( 
    IOnModelExecEvents __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nVars,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarIds,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarVals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      15);
        
        
        
        if(!nVars)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!VarIds)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!VarVals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 0U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)VarIds,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)VarVals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nVars;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)VarIds,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)VarVals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[690] );
            
            *nVars = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&VarIds,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&VarVals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1010],
                         ( void __RPC_FAR * )nVars);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )VarIds);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )VarVals);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExecEvents_GetTrimVars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *VarIds;
    SAFEARRAY __RPC_FAR * __RPC_FAR *VarVals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long __RPC_FAR *nVars;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( long __RPC_FAR * )nVars = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )VarIds = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )VarVals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[690] );
        
        nVars = ( long __RPC_FAR * )_StubMsg.Buffer;
        _StubMsg.Buffer += sizeof( long  );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&VarIds,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&VarVals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExecEvents*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetTrimVars(
               (IOnModelExecEvents *) ((CStdStubBuffer *)This)->pvServerObject,
               nVars,
               VarIds,
               VarVals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U + 0U + 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)VarIds,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)VarVals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( long __RPC_FAR * )_StubMsg.Buffer)++ = *nVars;
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)VarIds,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)VarVals,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)VarIds,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)VarVals,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExecEvents_SetVariables_Proxy( 
    IOnModelExecEvents __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarVals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      16);
        
        
        
        if(!VarVals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)VarVals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)VarVals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[152] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&VarVals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )VarVals);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExecEvents_SetVariables_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *VarVals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )VarVals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[152] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&VarVals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExecEvents*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetVariables((IOnModelExecEvents *) ((CStdStubBuffer *)This)->pvServerObject,VarVals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)VarVals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)VarVals,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)VarVals,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExecEvents_GetResiduals_Proxy( 
    IOnModelExecEvents __RPC_FAR * This,
    /* [in] */ long nEqns,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *EqnIds,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Residuals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      17);
        
        
        
        if(!EqnIds)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!Residuals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 0U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)EqnIds,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Residuals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = nEqns;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)EqnIds,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Residuals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[704] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&EqnIds,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&Residuals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )EqnIds);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )Residuals);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExecEvents_GetResiduals_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *EqnIds;
    SAFEARRAY __RPC_FAR * __RPC_FAR *Residuals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long nEqns;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )EqnIds = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Residuals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[704] );
        
        nEqns = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&EqnIds,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Residuals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExecEvents*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetResiduals(
                (IOnModelExecEvents *) ((CStdStubBuffer *)This)->pvServerObject,
                nEqns,
                EqnIds,
                Residuals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)EqnIds,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)Residuals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)EqnIds,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)Residuals,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)EqnIds,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Residuals,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExecEvents_SetResiduals_Proxy( 
    IOnModelExecEvents __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ResVals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      18);
        
        
        
        if(!ResVals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)ResVals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)ResVals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[152] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&ResVals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )ResVals);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExecEvents_SetResiduals_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *ResVals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )ResVals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[152] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&ResVals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExecEvents*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetResiduals((IOnModelExecEvents *) ((CStdStubBuffer *)This)->pvServerObject,ResVals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)ResVals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)ResVals,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)ResVals,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExecEvents_ShowDialog_Proxy( 
    IOnModelExecEvents __RPC_FAR * This,
    /* [in] */ BSTR msg)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      19);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&msg,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&msg,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[716] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExecEvents_ShowDialog_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_msg;
    BSTR msg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_msg = &msg;
    MIDL_memset(
               _p_msg,
               0,
               sizeof( BSTR  ));
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[716] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_msg,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExecEvents*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> ShowDialog((IOnModelExecEvents *) ((CStdStubBuffer *)This)->pvServerObject,msg);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&msg,
                            &__MIDL_TypeFormatString.Format[1044] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

CINTERFACE_PROXY_VTABLE(20) _IOnModelExecEventsProxyVtbl = 
{
    &IID_IOnModelExecEvents,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch_GetTypeInfoCount_Proxy */ ,
    0 /* IDispatch_GetTypeInfo_Proxy */ ,
    0 /* IDispatch_GetIDsOfNames_Proxy */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    IOnModelExecEvents_BeforeRParEvent_Proxy ,
    IOnModelExecEvents_BeforeIParEvent_Proxy ,
    IOnModelExecEvents_BeforeStateEvent_Proxy ,
    IOnModelExecEvents_AfterRParEvent_Proxy ,
    IOnModelExecEvents_AfterIParEvent_Proxy ,
    IOnModelExecEvents_AfterStateEvent_Proxy ,
    IOnModelExecEvents_InitializationInfo_Proxy ,
    IOnModelExecEvents_GetTrimEqns_Proxy ,
    IOnModelExecEvents_GetTrimVars_Proxy ,
    IOnModelExecEvents_SetVariables_Proxy ,
    IOnModelExecEvents_GetResiduals_Proxy ,
    IOnModelExecEvents_SetResiduals_Proxy ,
    IOnModelExecEvents_ShowDialog_Proxy
};


static const PRPC_STUB_FUNCTION IOnModelExecEvents_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    IOnModelExecEvents_BeforeRParEvent_Stub,
    IOnModelExecEvents_BeforeIParEvent_Stub,
    IOnModelExecEvents_BeforeStateEvent_Stub,
    IOnModelExecEvents_AfterRParEvent_Stub,
    IOnModelExecEvents_AfterIParEvent_Stub,
    IOnModelExecEvents_AfterStateEvent_Stub,
    IOnModelExecEvents_InitializationInfo_Stub,
    IOnModelExecEvents_GetTrimEqns_Stub,
    IOnModelExecEvents_GetTrimVars_Stub,
    IOnModelExecEvents_SetVariables_Stub,
    IOnModelExecEvents_GetResiduals_Stub,
    IOnModelExecEvents_SetResiduals_Stub,
    IOnModelExecEvents_ShowDialog_Stub
};

CInterfaceStubVtbl _IOnModelExecEventsStubVtbl =
{
    &IID_IOnModelExecEvents,
    0,
    20,
    &IOnModelExecEvents_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IOnModelExec, ver. 0.0,
   GUID={0x58CF6F05,0xD4AC,0x481E,{0xB9,0x4D,0xFA,0x4F,0x4D,0xE0,0x91,0xC7}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExec_PostRPar_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [in] */ double event_time,
    /* [in] */ long iGlobalId,
    /* [in] */ double val)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      7);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U + 4U + 12U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = event_time;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = iGlobalId;
            
            _StubMsg.Buffer += 4;
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = val;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[296] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExec_PostRPar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    double event_time;
    long iGlobalId;
    double val;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[296] );
        
        event_time = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        iGlobalId = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        _StubMsg.Buffer += 4;
        val = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExec*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> PostRPar(
            (IOnModelExec *) ((CStdStubBuffer *)This)->pvServerObject,
            event_time,
            iGlobalId,
            val);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExec_PostIPar_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [in] */ double event_time,
    /* [in] */ long iGlobalId,
    /* [in] */ long val)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      8);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U + 4U + 4U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = event_time;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = iGlobalId;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = val;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[304] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExec_PostIPar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    double event_time;
    long iGlobalId;
    long val;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[304] );
        
        event_time = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        iGlobalId = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        val = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExec*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> PostIPar(
            (IOnModelExec *) ((CStdStubBuffer *)This)->pvServerObject,
            event_time,
            iGlobalId,
            val);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExec_SetModel_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [in] */ IIsDaeEso __RPC_FAR *pModel)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      9);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrInterfacePointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                           (unsigned char __RPC_FAR *)pModel,
                                           (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1062] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrInterfacePointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                         (unsigned char __RPC_FAR *)pModel,
                                         (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1062] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[158] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExec_SetModel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    IIsDaeEso __RPC_FAR *pModel;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    pModel = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[158] );
        
        NdrInterfacePointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR * __RPC_FAR *)&pModel,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1062],
                                       (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExec*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetModel((IOnModelExec *) ((CStdStubBuffer *)This)->pvServerObject,pModel);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrInterfacePointerFree( &_StubMsg,
                                 (unsigned char __RPC_FAR *)pModel,
                                 &__MIDL_TypeFormatString.Format[1062] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExec_PostStateEvent_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [in] */ double EventTime,
    /* [in] */ BSTR EventId,
    /* [in] */ long iEventEqn,
    /* [in] */ IIsDaeEso __RPC_FAR *pEventEso)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      10);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U + 8U + 11U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&EventId,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrInterfacePointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                           (unsigned char __RPC_FAR *)pEventEso,
                                           (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1062] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = EventTime;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&EventId,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = iEventEqn;
            
            NdrInterfacePointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                         (unsigned char __RPC_FAR *)pEventEso,
                                         (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1062] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[722] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExec_PostStateEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR EventId;
    double EventTime;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_EventId;
    long iEventEqn;
    IIsDaeEso __RPC_FAR *pEventEso;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_EventId = &EventId;
    MIDL_memset(
               _p_EventId,
               0,
               sizeof( BSTR  ));
    pEventEso = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[722] );
        
        EventTime = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_EventId,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044],
                                  (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        iEventEqn = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrInterfacePointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR * __RPC_FAR *)&pEventEso,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1062],
                                       (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExec*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> PostStateEvent(
                  (IOnModelExec *) ((CStdStubBuffer *)This)->pvServerObject,
                  EventTime,
                  EventId,
                  iEventEqn,
                  pEventEso);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&EventId,
                            &__MIDL_TypeFormatString.Format[1044] );
        
        NdrInterfacePointerFree( &_StubMsg,
                                 (unsigned char __RPC_FAR *)pEventEso,
                                 &__MIDL_TypeFormatString.Format[1062] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOnModelExec_get_MaxStepSize_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      11);
        
        
        
        if(!pVal)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[736] );
            
            *pVal = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1036],
                         ( void __RPC_FAR * )pVal);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExec_get_MaxStepSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    double _M33;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    double __RPC_FAR *pVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( double __RPC_FAR * )pVal = 0;
    RpcTryFinally
        {
        pVal = &_M33;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExec*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> get_MaxStepSize((IOnModelExec *) ((CStdStubBuffer *)This)->pvServerObject,pVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 8U + 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( double __RPC_FAR * )_StubMsg.Buffer)++ = *pVal;
        
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOnModelExec_put_MaxStepSize_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [in] */ double newVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      12);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = newVal;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[148] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExec_put_MaxStepSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    double newVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[148] );
        
        newVal = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExec*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> put_MaxStepSize((IOnModelExec *) ((CStdStubBuffer *)This)->pvServerObject,newVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExec_Step_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [in] */ double external_time)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      13);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = external_time;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[148] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExec_Step_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    double external_time;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[148] );
        
        external_time = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExec*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Step((IOnModelExec *) ((CStdStubBuffer *)This)->pvServerObject,external_time);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExec_OnTransition_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [in] */ double event_time,
    /* [in] */ long iEventEqn,
    /* [in] */ BSTR EventId,
    /* [in] */ long iNewState,
    /* [in] */ IIsDaeEso __RPC_FAR *pEventModel)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      14);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U + 4U + 4U + 11U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&EventId,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrInterfacePointerBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                           (unsigned char __RPC_FAR *)pEventModel,
                                           (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1062] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( double __RPC_FAR * )_StubMsg.Buffer)++ = event_time;
            
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = iEventEqn;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&EventId,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = iNewState;
            
            NdrInterfacePointerMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                         (unsigned char __RPC_FAR *)pEventModel,
                                         (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1062] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[742] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExec_OnTransition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    BSTR EventId;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_EventId;
    double event_time;
    long iEventEqn;
    long iNewState;
    IIsDaeEso __RPC_FAR *pEventModel;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_EventId = &EventId;
    MIDL_memset(
               _p_EventId,
               0,
               sizeof( BSTR  ));
    pEventModel = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[742] );
        
        event_time = *(( double __RPC_FAR * )_StubMsg.Buffer)++;
        
        iEventEqn = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_EventId,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044],
                                  (unsigned char)0 );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        iNewState = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrInterfacePointerUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                       (unsigned char __RPC_FAR * __RPC_FAR *)&pEventModel,
                                       (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1062],
                                       (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExec*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> OnTransition(
                (IOnModelExec *) ((CStdStubBuffer *)This)->pvServerObject,
                event_time,
                iEventEqn,
                EventId,
                iNewState,
                pEventModel);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&EventId,
                            &__MIDL_TypeFormatString.Format[1044] );
        
        NdrInterfacePointerFree( &_StubMsg,
                                 (unsigned char __RPC_FAR *)pEventModel,
                                 &__MIDL_TypeFormatString.Format[1062] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExec_Save_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [in] */ BSTR filename)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      15);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&filename,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&filename,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[716] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExec_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_filename;
    BSTR filename;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_filename = &filename;
    MIDL_memset(
               _p_filename,
               0,
               sizeof( BSTR  ));
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[716] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_filename,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExec*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Save((IOnModelExec *) ((CStdStubBuffer *)This)->pvServerObject,filename);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&filename,
                            &__MIDL_TypeFormatString.Format[1044] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExec_Load_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [in] */ BSTR filename)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      16);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 8U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)&filename,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)&filename,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[716] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExec_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    void __RPC_FAR *_p_filename;
    BSTR filename;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    _p_filename = &filename;
    MIDL_memset(
               _p_filename,
               0,
               sizeof( BSTR  ));
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[716] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&_p_filename,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[1044],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExec*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> Load((IOnModelExec *) ((CStdStubBuffer *)This)->pvServerObject,filename);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrUserMarshalFree( &_StubMsg,
                            (unsigned char __RPC_FAR *)&filename,
                            &__MIDL_TypeFormatString.Format[1044] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExec_ForceReset_Proxy( 
    IOnModelExec __RPC_FAR * This)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      17);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[352] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExec_ForceReset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExec*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> ForceReset((IOnModelExec *) ((CStdStubBuffer *)This)->pvServerObject);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOnModelExec_get_RetryInitialization_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      18);
        
        
        
        if(!bVal)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[758] );
            
            *bVal = *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++;
            
            _StubMsg.Buffer += 2;
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[1084],
                         ( void __RPC_FAR * )bVal);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExec_get_RetryInitialization_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    VARIANT_BOOL _M34;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    VARIANT_BOOL __RPC_FAR *bVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( VARIANT_BOOL __RPC_FAR * )bVal = 0;
    RpcTryFinally
        {
        bVal = &_M34;
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExec*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> get_RetryInitialization((IOnModelExec *) ((CStdStubBuffer *)This)->pvServerObject,bVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 2U + 6U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++ = *bVal;
        
        _StubMsg.Buffer += 2;
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOnModelExec_put_RetryInitialization_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL bVal)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      19);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 2U;
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++ = bVal;
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[764] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExec_put_RetryInitialization_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    VARIANT_BOOL bVal;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[764] );
        
        bVal = *(( VARIANT_BOOL __RPC_FAR * )_StubMsg.Buffer)++;
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExec*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> put_RetryInitialization((IOnModelExec *) ((CStdStubBuffer *)This)->pvServerObject,bVal);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExec_GetResiduals_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [in] */ long nEqns,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *EqnIds,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Residuals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      20);
        
        
        
        if(!EqnIds)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        if(!Residuals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 4U + 0U + 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)EqnIds,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)Residuals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            *(( long __RPC_FAR * )_StubMsg.Buffer)++ = nEqns;
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)EqnIds,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)Residuals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[704] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&EqnIds,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&Residuals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )EqnIds);
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )Residuals);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExec_GetResiduals_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *EqnIds;
    SAFEARRAY __RPC_FAR * __RPC_FAR *Residuals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    long nEqns;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )EqnIds = 0;
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )Residuals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[704] );
        
        nEqns = *(( long __RPC_FAR * )_StubMsg.Buffer)++;
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&EqnIds,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&Residuals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExec*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> GetResiduals(
                (IOnModelExec *) ((CStdStubBuffer *)This)->pvServerObject,
                nEqns,
                EqnIds,
                Residuals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)EqnIds,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)Residuals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)EqnIds,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)Residuals,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)EqnIds,
                        &__MIDL_TypeFormatString.Format[970] );
        
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)Residuals,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExec_SetVariables_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarVals)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      21);
        
        
        
        if(!VarVals)
            {
            RpcRaiseException(RPC_X_NULL_REF_POINTER);
            }
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR *)VarVals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                    (unsigned char __RPC_FAR *)VarVals,
                                    (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
            
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[152] );
            
            NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                      (unsigned char __RPC_FAR * __RPC_FAR *)&VarVals,
                                      (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                      (unsigned char)0 );
            
            _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        NdrClearOutParameters(
                         ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                         ( PFORMAT_STRING  )&__MIDL_TypeFormatString.Format[970],
                         ( void __RPC_FAR * )VarVals);
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExec_SetVariables_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    SAFEARRAY __RPC_FAR * __RPC_FAR *VarVals;
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    ( SAFEARRAY __RPC_FAR * __RPC_FAR * )VarVals = 0;
    RpcTryFinally
        {
        if ( (_pRpcMessage->DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
            NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[152] );
        
        NdrUserMarshalUnmarshall( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR * __RPC_FAR *)&VarVals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982],
                                  (unsigned char)0 );
        
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExec*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SetVariables((IOnModelExec *) ((CStdStubBuffer *)This)->pvServerObject,VarVals);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 0U + 11U;
        NdrUserMarshalBufferSize( (PMIDL_STUB_MESSAGE) &_StubMsg,
                                  (unsigned char __RPC_FAR *)VarVals,
                                  (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.BufferLength += 16;
        
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        NdrUserMarshalMarshall( (PMIDL_STUB_MESSAGE)& _StubMsg,
                                (unsigned char __RPC_FAR *)VarVals,
                                (PFORMAT_STRING) &__MIDL_TypeFormatString.Format[982] );
        
        _StubMsg.Buffer = (unsigned char __RPC_FAR *)(((long)_StubMsg.Buffer + 3) & ~ 0x3);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        NdrPointerFree( &_StubMsg,
                        (unsigned char __RPC_FAR *)VarVals,
                        &__MIDL_TypeFormatString.Format[970] );
        
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExec_HandleInitEvents_Proxy( 
    IOnModelExec __RPC_FAR * This)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      22);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[352] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnModelExec_HandleInitEvents_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnModelExec*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> HandleInitEvents((IOnModelExec *) ((CStdStubBuffer *)This)->pvServerObject);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

CINTERFACE_PROXY_VTABLE(23) _IOnModelExecProxyVtbl = 
{
    &IID_IOnModelExec,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch_GetTypeInfoCount_Proxy */ ,
    0 /* IDispatch_GetTypeInfo_Proxy */ ,
    0 /* IDispatch_GetIDsOfNames_Proxy */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    IOnModelExec_PostRPar_Proxy ,
    IOnModelExec_PostIPar_Proxy ,
    IOnModelExec_SetModel_Proxy ,
    IOnModelExec_PostStateEvent_Proxy ,
    IOnModelExec_get_MaxStepSize_Proxy ,
    IOnModelExec_put_MaxStepSize_Proxy ,
    IOnModelExec_Step_Proxy ,
    IOnModelExec_OnTransition_Proxy ,
    IOnModelExec_Save_Proxy ,
    IOnModelExec_Load_Proxy ,
    IOnModelExec_ForceReset_Proxy ,
    IOnModelExec_get_RetryInitialization_Proxy ,
    IOnModelExec_put_RetryInitialization_Proxy ,
    IOnModelExec_GetResiduals_Proxy ,
    IOnModelExec_SetVariables_Proxy ,
    IOnModelExec_HandleInitEvents_Proxy
};


static const PRPC_STUB_FUNCTION IOnModelExec_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    IOnModelExec_PostRPar_Stub,
    IOnModelExec_PostIPar_Stub,
    IOnModelExec_SetModel_Stub,
    IOnModelExec_PostStateEvent_Stub,
    IOnModelExec_get_MaxStepSize_Stub,
    IOnModelExec_put_MaxStepSize_Stub,
    IOnModelExec_Step_Stub,
    IOnModelExec_OnTransition_Stub,
    IOnModelExec_Save_Stub,
    IOnModelExec_Load_Stub,
    IOnModelExec_ForceReset_Stub,
    IOnModelExec_get_RetryInitialization_Stub,
    IOnModelExec_put_RetryInitialization_Stub,
    IOnModelExec_GetResiduals_Stub,
    IOnModelExec_SetVariables_Stub,
    IOnModelExec_HandleInitEvents_Stub
};

CInterfaceStubVtbl _IOnModelExecStubVtbl =
{
    &IID_IOnModelExec,
    0,
    23,
    &IOnModelExec_table[-3],
    CStdStubBuffer_DELEGATING_METHODS
};


/* Object interface: IOnTest, ver. 0.0,
   GUID={0x215F714B,0x4C21,0x476A,{0xA2,0x2E,0x72,0x5F,0x57,0x16,0x7B,0x83}} */


extern const MIDL_STUB_DESC Object_StubDesc;


#pragma code_seg(".orpc")

/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnTest_SparseTest_Proxy( 
    IOnTest __RPC_FAR * This)
{

    HRESULT _RetVal;
    
    RPC_MESSAGE _RpcMessage;
    
    MIDL_STUB_MESSAGE _StubMsg;
    
    RpcTryExcept
        {
        NdrProxyInitialize(
                      ( void __RPC_FAR *  )This,
                      ( PRPC_MESSAGE  )&_RpcMessage,
                      ( PMIDL_STUB_MESSAGE  )&_StubMsg,
                      ( PMIDL_STUB_DESC  )&Object_StubDesc,
                      7);
        
        
        
        RpcTryFinally
            {
            
            _StubMsg.BufferLength = 0U;
            NdrProxyGetBuffer(This, &_StubMsg);
            NdrProxySendReceive(This, &_StubMsg);
            
            if ( (_RpcMessage.DataRepresentation & 0X0000FFFFUL) != NDR_LOCAL_DATA_REPRESENTATION )
                NdrConvert( (PMIDL_STUB_MESSAGE) &_StubMsg, (PFORMAT_STRING) &__MIDL_ProcFormatString.Format[352] );
            
            _RetVal = *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++;
            
            }
        RpcFinally
            {
            NdrProxyFreeBuffer(This, &_StubMsg);
            
            }
        RpcEndFinally
        
        }
    RpcExcept(_StubMsg.dwStubPhase != PROXY_SENDRECEIVE)
        {
        _RetVal = NdrProxyErrorHandler(RpcExceptionCode());
        }
    RpcEndExcept
    return _RetVal;
}

void __RPC_STUB IOnTest_SparseTest_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase)
{
    HRESULT _RetVal;
    MIDL_STUB_MESSAGE _StubMsg;
    
NdrStubInitialize(
                     _pRpcMessage,
                     &_StubMsg,
                     &Object_StubDesc,
                     _pRpcChannelBuffer);
    RpcTryFinally
        {
        
        *_pdwStubPhase = STUB_CALL_SERVER;
        _RetVal = (((IOnTest*) ((CStdStubBuffer *)This)->pvServerObject)->lpVtbl) -> SparseTest((IOnTest *) ((CStdStubBuffer *)This)->pvServerObject);
        
        *_pdwStubPhase = STUB_MARSHAL;
        
        _StubMsg.BufferLength = 4U;
        NdrStubGetBuffer(This, _pRpcChannelBuffer, &_StubMsg);
        *(( HRESULT __RPC_FAR * )_StubMsg.Buffer)++ = _RetVal;
        
        }
    RpcFinally
        {
        }
    RpcEndFinally
    _pRpcMessage->BufferLength = 
        (unsigned int)((long)_StubMsg.Buffer - (long)_pRpcMessage->Buffer);
    
}

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

CINTERFACE_PROXY_VTABLE(8) _IOnTestProxyVtbl = 
{
    &IID_IOnTest,
    IUnknown_QueryInterface_Proxy,
    IUnknown_AddRef_Proxy,
    IUnknown_Release_Proxy ,
    0 /* IDispatch_GetTypeInfoCount_Proxy */ ,
    0 /* IDispatch_GetTypeInfo_Proxy */ ,
    0 /* IDispatch_GetIDsOfNames_Proxy */ ,
    0 /* IDispatch_Invoke_Proxy */ ,
    IOnTest_SparseTest_Proxy
};


static const PRPC_STUB_FUNCTION IOnTest_table[] =
{
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    STUB_FORWARDING_FUNCTION,
    IOnTest_SparseTest_Stub
};

CInterfaceStubVtbl _IOnTestStubVtbl =
{
    &IID_IOnTest,
    0,
    8,
    &IOnTest_table[-3],
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
#error   [wire_marshal] or [user_marshal] attribute.
#error However, your C/C++ compilation flags indicate you intend to run this app on earlier systems.
#error This app will die there with the RPC_X_WRONG_STUB_VERSION error.
#endif


static const MIDL_PROC_FORMAT_STRING __MIDL_ProcFormatString =
    {
        0,
        {
			
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/*  2 */	NdrFcShort( 0x2 ),	/* Type Offset=2 */
/*  4 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/*  6 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/*  8 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 10 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 12 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 14 */	NdrFcShort( 0x3e0 ),	/* Type Offset=992 */
/* 16 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 18 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 20 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 22 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 24 */	NdrFcShort( 0x3ee ),	/* Type Offset=1006 */
/* 26 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 28 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 30 */	NdrFcShort( 0x3e0 ),	/* Type Offset=992 */
/* 32 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 34 */	NdrFcShort( 0x3e0 ),	/* Type Offset=992 */
/* 36 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 38 */	NdrFcShort( 0x3ee ),	/* Type Offset=1006 */
/* 40 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 42 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 44 */	NdrFcShort( 0x3f2 ),	/* Type Offset=1010 */
/* 46 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 48 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 50 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 52 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 54 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 56 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 58 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 60 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 62 */	NdrFcShort( 0x3e0 ),	/* Type Offset=992 */
/* 64 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 66 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 68 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 70 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 72 */	NdrFcShort( 0x3f6 ),	/* Type Offset=1014 */
/* 74 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 76 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 78 */	NdrFcShort( 0x3e0 ),	/* Type Offset=992 */
/* 80 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0xc,		/* FC_DOUBLE */
/* 82 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 84 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 86 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 88 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 90 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0xc,		/* FC_DOUBLE */
/* 92 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 94 */	NdrFcShort( 0x40c ),	/* Type Offset=1036 */
/* 96 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 98 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 100 */	NdrFcShort( 0x414 ),	/* Type Offset=1044 */
/* 102 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 104 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */
/* 106 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 108 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 110 */	NdrFcShort( 0x3e0 ),	/* Type Offset=992 */
/* 112 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 114 */	NdrFcShort( 0x3e0 ),	/* Type Offset=992 */
/* 116 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 118 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0xc,		/* FC_DOUBLE */
/* 120 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 122 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 124 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 126 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 128 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */
/* 130 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 132 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 134 */	NdrFcShort( 0x422 ),	/* Type Offset=1058 */
/* 136 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 138 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 140 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 142 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0xc,		/* FC_DOUBLE */
/* 144 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x6,		/* FC_SHORT */
/* 146 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 148 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0xc,		/* FC_DOUBLE */
/* 150 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 152 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 154 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 156 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 158 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 160 */	NdrFcShort( 0x426 ),	/* Type Offset=1062 */
/* 162 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 164 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 166 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 168 */	NdrFcShort( 0x438 ),	/* Type Offset=1080 */
/* 170 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 172 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 174 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */
/* 176 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 178 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */
/* 180 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 182 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */
/* 184 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 186 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */
/* 188 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 190 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */
/* 192 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 194 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */
/* 196 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 198 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */
/* 200 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 202 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */
/* 204 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 206 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */
/* 208 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 210 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */
/* 212 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 214 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */
/* 216 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 218 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */
/* 220 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 222 */	NdrFcShort( 0x41e ),	/* Type Offset=1054 */
/* 224 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 226 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0xc,		/* FC_DOUBLE */
/* 228 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 230 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 232 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 234 */	NdrFcShort( 0x43c ),	/* Type Offset=1084 */
/* 236 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 238 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 240 */	NdrFcShort( 0x3f2 ),	/* Type Offset=1010 */
/* 242 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 244 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 246 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 248 */	NdrFcShort( 0x422 ),	/* Type Offset=1058 */
/* 250 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 252 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 254 */	NdrFcShort( 0x414 ),	/* Type Offset=1044 */
/* 256 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 258 */	NdrFcShort( 0x3f2 ),	/* Type Offset=1010 */
/* 260 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 262 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 264 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0xc,		/* FC_DOUBLE */
/* 266 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 268 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 270 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 272 */	NdrFcShort( 0x3f2 ),	/* Type Offset=1010 */
/* 274 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 276 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 278 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 280 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 282 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 284 */	NdrFcShort( 0x440 ),	/* Type Offset=1088 */
/* 286 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 288 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0xc,		/* FC_DOUBLE */
/* 290 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 292 */	NdrFcShort( 0x414 ),	/* Type Offset=1044 */
/* 294 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 296 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0xc,		/* FC_DOUBLE */
/* 298 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 300 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0xc,		/* FC_DOUBLE */
/* 302 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 304 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0xc,		/* FC_DOUBLE */
/* 306 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 308 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 310 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 312 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 314 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 316 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 318 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 320 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 322 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 324 */	NdrFcShort( 0x3e0 ),	/* Type Offset=992 */
/* 326 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 328 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 330 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 332 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 334 */	NdrFcShort( 0x40c ),	/* Type Offset=1036 */
/* 336 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 338 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 340 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 342 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0xc,		/* FC_DOUBLE */
/* 344 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 346 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 348 */	NdrFcShort( 0x452 ),	/* Type Offset=1106 */
/* 350 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 352 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 354 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 356 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 358 */	NdrFcShort( 0x3e0 ),	/* Type Offset=992 */
/* 360 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 362 */	NdrFcShort( 0x422 ),	/* Type Offset=1058 */
/* 364 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 366 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 368 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 370 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 372 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 374 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 376 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 378 */	NdrFcShort( 0x3f2 ),	/* Type Offset=1010 */
/* 380 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 382 */	NdrFcShort( 0x3f2 ),	/* Type Offset=1010 */
/* 384 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 386 */	NdrFcShort( 0x3f2 ),	/* Type Offset=1010 */
/* 388 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 390 */	NdrFcShort( 0x3f2 ),	/* Type Offset=1010 */
/* 392 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 394 */	NdrFcShort( 0x422 ),	/* Type Offset=1058 */
/* 396 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 398 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 400 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 402 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 404 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 406 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 408 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 410 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 412 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 414 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 416 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 418 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 420 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 422 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 424 */	NdrFcShort( 0x3e0 ),	/* Type Offset=992 */
/* 426 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 428 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0xc,		/* FC_DOUBLE */
/* 430 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 432 */	NdrFcShort( 0x3e0 ),	/* Type Offset=992 */
/* 434 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 436 */	NdrFcShort( 0x3e0 ),	/* Type Offset=992 */
/* 438 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 440 */	NdrFcShort( 0x3e0 ),	/* Type Offset=992 */
/* 442 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 444 */	NdrFcShort( 0x3e0 ),	/* Type Offset=992 */
/* 446 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 448 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 450 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 452 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 454 */	NdrFcShort( 0x3e0 ),	/* Type Offset=992 */
/* 456 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 458 */	NdrFcShort( 0x3e0 ),	/* Type Offset=992 */
/* 460 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 462 */	NdrFcShort( 0x3e0 ),	/* Type Offset=992 */
/* 464 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0xc,		/* FC_DOUBLE */
/* 466 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 468 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 470 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 472 */	NdrFcShort( 0x3ee ),	/* Type Offset=1006 */
/* 474 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 476 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 478 */	NdrFcShort( 0x3f2 ),	/* Type Offset=1010 */
/* 480 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 482 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 484 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 486 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 488 */	NdrFcShort( 0x3f2 ),	/* Type Offset=1010 */
/* 490 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 492 */	NdrFcShort( 0x3f2 ),	/* Type Offset=1010 */
/* 494 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 496 */	NdrFcShort( 0x3f2 ),	/* Type Offset=1010 */
/* 498 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 500 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 502 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 504 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 506 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 508 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 510 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 512 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 514 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 516 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0xc,		/* FC_DOUBLE */
/* 518 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 520 */	NdrFcShort( 0x414 ),	/* Type Offset=1044 */
/* 522 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 524 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 526 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 528 */	NdrFcShort( 0x3ee ),	/* Type Offset=1006 */
/* 530 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 532 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 534 */	NdrFcShort( 0x464 ),	/* Type Offset=1124 */
/* 536 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 538 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 540 */	NdrFcShort( 0x476 ),	/* Type Offset=1142 */
/* 542 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 544 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 546 */	NdrFcShort( 0x414 ),	/* Type Offset=1044 */
/* 548 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 550 */	NdrFcShort( 0x488 ),	/* Type Offset=1160 */
/* 552 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 554 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 556 */	NdrFcShort( 0x414 ),	/* Type Offset=1044 */
/* 558 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 560 */	NdrFcShort( 0x40c ),	/* Type Offset=1036 */
/* 562 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 564 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 566 */	NdrFcShort( 0x414 ),	/* Type Offset=1044 */
/* 568 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0xc,		/* FC_DOUBLE */
/* 570 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 572 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 574 */	NdrFcShort( 0x414 ),	/* Type Offset=1044 */
/* 576 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 578 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 580 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 582 */	NdrFcShort( 0x48c ),	/* Type Offset=1164 */
/* 584 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 586 */	NdrFcShort( 0x414 ),	/* Type Offset=1044 */
/* 588 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 590 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 592 */	NdrFcShort( 0x49e ),	/* Type Offset=1182 */
/* 594 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 596 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x6,		/* FC_SHORT */
/* 598 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 600 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 602 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 604 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 606 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 608 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 610 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 612 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 614 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 616 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 618 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 620 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 622 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 624 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 626 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 628 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 630 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 632 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 634 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 636 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 638 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 640 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 642 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 644 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 646 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 648 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 650 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 652 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 654 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 656 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 658 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 660 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 662 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 664 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 666 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 668 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 670 */	NdrFcShort( 0x3f2 ),	/* Type Offset=1010 */
/* 672 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 674 */	NdrFcShort( 0x3f2 ),	/* Type Offset=1010 */
/* 676 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 678 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 680 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 682 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 684 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 686 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 688 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 690 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 692 */	NdrFcShort( 0x3f2 ),	/* Type Offset=1010 */
/* 694 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 696 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 698 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 700 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 702 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 704 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 706 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 708 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 710 */	
			0x50,		/* FC_IN_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 712 */	NdrFcShort( 0x3ca ),	/* Type Offset=970 */
/* 714 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 716 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 718 */	NdrFcShort( 0x414 ),	/* Type Offset=1044 */
/* 720 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 722 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0xc,		/* FC_DOUBLE */
/* 724 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 726 */	NdrFcShort( 0x414 ),	/* Type Offset=1044 */
/* 728 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 730 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 732 */	NdrFcShort( 0x426 ),	/* Type Offset=1062 */
/* 734 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 736 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 738 */	NdrFcShort( 0x40c ),	/* Type Offset=1036 */
/* 740 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 742 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0xc,		/* FC_DOUBLE */
/* 744 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 746 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 748 */	NdrFcShort( 0x414 ),	/* Type Offset=1044 */
/* 750 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 752 */	
			0x4d,		/* FC_IN_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 754 */	NdrFcShort( 0x426 ),	/* Type Offset=1062 */
/* 756 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 758 */	
			0x51,		/* FC_OUT_PARAM */
#ifndef _ALPHA_
			0x1,		/* x86, MIPS & PPC Stack size = 1 */
#else
			0x2,		/* Alpha Stack size = 2 */
#endif
/* 760 */	NdrFcShort( 0x43c ),	/* Type Offset=1084 */
/* 762 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */
/* 764 */	0x4e,		/* FC_IN_PARAM_BASETYPE */
			0x6,		/* FC_SHORT */
/* 766 */	0x53,		/* FC_RETURN_PARAM_BASETYPE */
			0x8,		/* FC_LONG */

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
/* 972 */	NdrFcShort( 0xa ),	/* Offset= 10 (982) */
/* 974 */	
			0x13, 0x10,	/* FC_OP */
/* 976 */	NdrFcShort( 0x2 ),	/* Offset= 2 (978) */
/* 978 */	
			0x13, 0x0,	/* FC_OP */
/* 980 */	NdrFcShort( 0xffffffda ),	/* Offset= -38 (942) */
/* 982 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 984 */	NdrFcShort( 0x0 ),	/* 0 */
/* 986 */	NdrFcShort( 0x4 ),	/* 4 */
/* 988 */	NdrFcShort( 0x0 ),	/* 0 */
/* 990 */	NdrFcShort( 0xfffffff0 ),	/* Offset= -16 (974) */
/* 992 */	
			0x11, 0x0,	/* FC_RP */
/* 994 */	NdrFcShort( 0x2 ),	/* Offset= 2 (996) */
/* 996 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 998 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1000 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1002 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1004 */	NdrFcShort( 0xfffffe8a ),	/* Offset= -374 (630) */
/* 1006 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 1008 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 1010 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 1012 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1014 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] */
/* 1016 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1018) */
/* 1018 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1020 */	NdrFcLong( 0x3f35cf66 ),	/* 1060491110 */
/* 1024 */	NdrFcShort( 0x839e ),	/* -31842 */
/* 1026 */	NdrFcShort( 0x11d4 ),	/* 4564 */
/* 1028 */	0x83,		/* 131 */
			0x8d,		/* 141 */
/* 1030 */	0x0,		/* 0 */
			0x60,		/* 96 */
/* 1032 */	0x8,		/* 8 */
			0x94,		/* 148 */
/* 1034 */	0xe8,		/* 232 */
			0x2,		/* 2 */
/* 1036 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1038 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 1040 */	
			0x12, 0x0,	/* FC_UP */
/* 1042 */	NdrFcShort( 0xfffffc4a ),	/* Offset= -950 (92) */
/* 1044 */	0xb4,		/* FC_USER_MARSHAL */
			0x83,		/* 131 */
/* 1046 */	NdrFcShort( 0x1 ),	/* 1 */
/* 1048 */	NdrFcShort( 0x4 ),	/* 4 */
/* 1050 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1052 */	NdrFcShort( 0xfffffff4 ),	/* Offset= -12 (1040) */
/* 1054 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1056 */	0x8,		/* FC_LONG */
			0x5c,		/* FC_PAD */
/* 1058 */	
			0x11, 0x8,	/* FC_RP [simple_pointer] */
/* 1060 */	0xc,		/* FC_DOUBLE */
			0x5c,		/* FC_PAD */
/* 1062 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1064 */	NdrFcLong( 0xefa96fd0 ),	/* -274108464 */
/* 1068 */	NdrFcShort( 0xb83d ),	/* -18371 */
/* 1070 */	NdrFcShort( 0x11d4 ),	/* 4564 */
/* 1072 */	0x83,		/* 131 */
			0x9b,		/* 155 */
/* 1074 */	0x0,		/* 0 */
			0x60,		/* 96 */
/* 1076 */	0x8,		/* 8 */
			0x94,		/* 148 */
/* 1078 */	0xe8,		/* 232 */
			0x2,		/* 2 */
/* 1080 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] */
/* 1082 */	NdrFcShort( 0xffffffec ),	/* Offset= -20 (1062) */
/* 1084 */	
			0x11, 0xc,	/* FC_RP [alloced_on_stack] [simple_pointer] */
/* 1086 */	0x6,		/* FC_SHORT */
			0x5c,		/* FC_PAD */
/* 1088 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1090 */	NdrFcLong( 0x58cf6f05 ),	/* 1489989381 */
/* 1094 */	NdrFcShort( 0xd4ac ),	/* -11092 */
/* 1096 */	NdrFcShort( 0x481e ),	/* 18462 */
/* 1098 */	0xb9,		/* 185 */
			0x4d,		/* 77 */
/* 1100 */	0xfa,		/* 250 */
			0x4f,		/* 79 */
/* 1102 */	0x4d,		/* 77 */
			0xe0,		/* 224 */
/* 1104 */	0x91,		/* 145 */
			0xc7,		/* 199 */
/* 1106 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1108 */	NdrFcLong( 0xa6a32b44 ),	/* -1499255996 */
/* 1112 */	NdrFcShort( 0x92e2 ),	/* -27934 */
/* 1114 */	NdrFcShort( 0x11d4 ),	/* 4564 */
/* 1116 */	0x98,		/* 152 */
			0xa8,		/* 168 */
/* 1118 */	0x0,		/* 0 */
			0xc0,		/* 192 */
/* 1120 */	0x4f,		/* 79 */
			0x68,		/* 104 */
/* 1122 */	0x1,		/* 1 */
			0xa9,		/* 169 */
/* 1124 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1126 */	NdrFcLong( 0xbfc328f0 ),	/* -1077729040 */
/* 1130 */	NdrFcShort( 0xcbf6 ),	/* -13322 */
/* 1132 */	NdrFcShort( 0x11d4 ),	/* 4564 */
/* 1134 */	0x83,		/* 131 */
			0xa2,		/* 162 */
/* 1136 */	0x0,		/* 0 */
			0x60,		/* 96 */
/* 1138 */	0x8,		/* 8 */
			0x94,		/* 148 */
/* 1140 */	0xe8,		/* 232 */
			0x2,		/* 2 */
/* 1142 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1144 */	NdrFcLong( 0x0 ),	/* 0 */
/* 1148 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1150 */	NdrFcShort( 0x0 ),	/* 0 */
/* 1152 */	0xc0,		/* 192 */
			0x0,		/* 0 */
/* 1154 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1156 */	0x0,		/* 0 */
			0x0,		/* 0 */
/* 1158 */	0x0,		/* 0 */
			0x46,		/* 70 */
/* 1160 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] */
/* 1162 */	NdrFcShort( 0x2 ),	/* Offset= 2 (1164) */
/* 1164 */	
			0x2f,		/* FC_IP */
			0x5a,		/* FC_CONSTANT_IID */
/* 1166 */	NdrFcLong( 0x43d71c20 ),	/* 1138170912 */
/* 1170 */	NdrFcShort( 0xe726 ),	/* -6362 */
/* 1172 */	NdrFcShort( 0x4786 ),	/* 18310 */
/* 1174 */	0x80,		/* 128 */
			0xe,		/* 14 */
/* 1176 */	0x15,		/* 21 */
			0xc0,		/* 192 */
/* 1178 */	0x69,		/* 105 */
			0x68,		/* 104 */
/* 1180 */	0xad,		/* 173 */
			0xf3,		/* 243 */
/* 1182 */	
			0x11, 0x14,	/* FC_RP [alloced_on_stack] */
/* 1184 */	NdrFcShort( 0xfffffbf8 ),	/* Offset= -1032 (152) */

			0x0
        }
    };

const CInterfaceProxyVtbl * _ISDaeCOSolver_ProxyVtblList[] = 
{
    ( CInterfaceProxyVtbl *) &_IOnModelExecProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IIsDaeEsoCImplProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IIsNlaEsoProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOnTestProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IIsMatrixProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IIsNlaSolverProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IIsDaeEsoIImplProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IIsDaeEsoProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IOnModelExecEventsProxyVtbl,
    ( CInterfaceProxyVtbl *) &_IIsDaeEsoImplProxyVtbl,
    0
};

const CInterfaceStubVtbl * _ISDaeCOSolver_StubVtblList[] = 
{
    ( CInterfaceStubVtbl *) &_IOnModelExecStubVtbl,
    ( CInterfaceStubVtbl *) &_IIsDaeEsoCImplStubVtbl,
    ( CInterfaceStubVtbl *) &_IIsNlaEsoStubVtbl,
    ( CInterfaceStubVtbl *) &_IOnTestStubVtbl,
    ( CInterfaceStubVtbl *) &_IIsMatrixStubVtbl,
    ( CInterfaceStubVtbl *) &_IIsNlaSolverStubVtbl,
    ( CInterfaceStubVtbl *) &_IIsDaeEsoIImplStubVtbl,
    ( CInterfaceStubVtbl *) &_IIsDaeEsoStubVtbl,
    ( CInterfaceStubVtbl *) &_IOnModelExecEventsStubVtbl,
    ( CInterfaceStubVtbl *) &_IIsDaeEsoImplStubVtbl,
    0
};

PCInterfaceName const _ISDaeCOSolver_InterfaceNamesList[] = 
{
    "IOnModelExec",
    "IIsDaeEsoCImpl",
    "IIsNlaEso",
    "IOnTest",
    "IIsMatrix",
    "IIsNlaSolver",
    "IIsDaeEsoIImpl",
    "IIsDaeEso",
    "IOnModelExecEvents",
    "IIsDaeEsoImpl",
    0
};

const IID *  _ISDaeCOSolver_BaseIIDList[] = 
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
    0
};


#define _ISDaeCOSolver_CHECK_IID(n)	IID_GENERIC_CHECK_IID( _ISDaeCOSolver, pIID, n)

int __stdcall _ISDaeCOSolver_IID_Lookup( const IID * pIID, int * pIndex )
{
    IID_BS_LOOKUP_SETUP

    IID_BS_LOOKUP_INITIAL_TEST( _ISDaeCOSolver, 10, 8 )
    IID_BS_LOOKUP_NEXT_TEST( _ISDaeCOSolver, 4 )
    IID_BS_LOOKUP_NEXT_TEST( _ISDaeCOSolver, 2 )
    IID_BS_LOOKUP_NEXT_TEST( _ISDaeCOSolver, 1 )
    IID_BS_LOOKUP_RETURN_RESULT( _ISDaeCOSolver, 10, *pIndex )
    
}

const ExtendedProxyFileInfo ISDaeCOSolver_ProxyFileInfo = 
{
    (PCInterfaceProxyVtblList *) & _ISDaeCOSolver_ProxyVtblList,
    (PCInterfaceStubVtblList *) & _ISDaeCOSolver_StubVtblList,
    (const PCInterfaceName * ) & _ISDaeCOSolver_InterfaceNamesList,
    (const IID ** ) & _ISDaeCOSolver_BaseIIDList,
    & _ISDaeCOSolver_IID_Lookup, 
    10,
    1,
    0, /* table of [async_uuid] interfaces */
    0, /* Filler1 */
    0, /* Filler2 */
    0  /* Filler3 */
};
