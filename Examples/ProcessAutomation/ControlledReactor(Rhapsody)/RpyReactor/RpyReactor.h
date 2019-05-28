/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Jan 20 19:50:05 2003
 */
/* Compiler settings for C:\Rhapsody40\Reactor\RpyReactor\RpyReactor.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __RpyReactor_h__
#define __RpyReactor_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IRpyReactorTestHarness_FWD_DEFINED__
#define __IRpyReactorTestHarness_FWD_DEFINED__
typedef interface IRpyReactorTestHarness IRpyReactorTestHarness;
#endif 	/* __IRpyReactorTestHarness_FWD_DEFINED__ */


#ifndef __RpyReactorTestHarness_FWD_DEFINED__
#define __RpyReactorTestHarness_FWD_DEFINED__

#ifdef __cplusplus
typedef class RpyReactorTestHarness RpyReactorTestHarness;
#else
typedef struct RpyReactorTestHarness RpyReactorTestHarness;
#endif /* __cplusplus */

#endif 	/* __RpyReactorTestHarness_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IRpyReactorTestHarness_INTERFACE_DEFINED__
#define __IRpyReactorTestHarness_INTERFACE_DEFINED__

/* interface IRpyReactorTestHarness */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRpyReactorTestHarness;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E36160FD-AA21-4318-A452-15FF518B5A07")
    IRpyReactorTestHarness : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetModel( 
            IDispatch __RPC_FAR *__RPC_FAR *ppModel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetModelExec( 
            IDispatch __RPC_FAR *__RPC_FAR *ppModelExec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Step( 
            /* [in] */ double t) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetControllerOutput( 
            /* [in] */ double time,
            /* [out] */ double __RPC_FAR *pOut) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE setSetpoint( 
            /* [in] */ double val) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRpyReactorTestHarnessVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRpyReactorTestHarness __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRpyReactorTestHarness __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRpyReactorTestHarness __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRpyReactorTestHarness __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRpyReactorTestHarness __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRpyReactorTestHarness __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRpyReactorTestHarness __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetModel )( 
            IRpyReactorTestHarness __RPC_FAR * This,
            IDispatch __RPC_FAR *__RPC_FAR *ppModel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetModelExec )( 
            IRpyReactorTestHarness __RPC_FAR * This,
            IDispatch __RPC_FAR *__RPC_FAR *ppModelExec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Step )( 
            IRpyReactorTestHarness __RPC_FAR * This,
            /* [in] */ double t);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetControllerOutput )( 
            IRpyReactorTestHarness __RPC_FAR * This,
            /* [in] */ double time,
            /* [out] */ double __RPC_FAR *pOut);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *setSetpoint )( 
            IRpyReactorTestHarness __RPC_FAR * This,
            /* [in] */ double val);
        
        END_INTERFACE
    } IRpyReactorTestHarnessVtbl;

    interface IRpyReactorTestHarness
    {
        CONST_VTBL struct IRpyReactorTestHarnessVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRpyReactorTestHarness_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRpyReactorTestHarness_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRpyReactorTestHarness_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRpyReactorTestHarness_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRpyReactorTestHarness_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRpyReactorTestHarness_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRpyReactorTestHarness_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRpyReactorTestHarness_GetModel(This,ppModel)	\
    (This)->lpVtbl -> GetModel(This,ppModel)

#define IRpyReactorTestHarness_GetModelExec(This,ppModelExec)	\
    (This)->lpVtbl -> GetModelExec(This,ppModelExec)

#define IRpyReactorTestHarness_Step(This,t)	\
    (This)->lpVtbl -> Step(This,t)

#define IRpyReactorTestHarness_GetControllerOutput(This,time,pOut)	\
    (This)->lpVtbl -> GetControllerOutput(This,time,pOut)

#define IRpyReactorTestHarness_setSetpoint(This,val)	\
    (This)->lpVtbl -> setSetpoint(This,val)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRpyReactorTestHarness_GetModel_Proxy( 
    IRpyReactorTestHarness __RPC_FAR * This,
    IDispatch __RPC_FAR *__RPC_FAR *ppModel);


void __RPC_STUB IRpyReactorTestHarness_GetModel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRpyReactorTestHarness_GetModelExec_Proxy( 
    IRpyReactorTestHarness __RPC_FAR * This,
    IDispatch __RPC_FAR *__RPC_FAR *ppModelExec);


void __RPC_STUB IRpyReactorTestHarness_GetModelExec_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRpyReactorTestHarness_Step_Proxy( 
    IRpyReactorTestHarness __RPC_FAR * This,
    /* [in] */ double t);


void __RPC_STUB IRpyReactorTestHarness_Step_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRpyReactorTestHarness_GetControllerOutput_Proxy( 
    IRpyReactorTestHarness __RPC_FAR * This,
    /* [in] */ double time,
    /* [out] */ double __RPC_FAR *pOut);


void __RPC_STUB IRpyReactorTestHarness_GetControllerOutput_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRpyReactorTestHarness_setSetpoint_Proxy( 
    IRpyReactorTestHarness __RPC_FAR * This,
    /* [in] */ double val);


void __RPC_STUB IRpyReactorTestHarness_setSetpoint_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRpyReactorTestHarness_INTERFACE_DEFINED__ */



#ifndef __RPYREACTORLib_LIBRARY_DEFINED__
#define __RPYREACTORLib_LIBRARY_DEFINED__

/* library RPYREACTORLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_RPYREACTORLib;

EXTERN_C const CLSID CLSID_RpyReactorTestHarness;

#ifdef __cplusplus

class DECLSPEC_UUID("774DFAF5-DEA7-4BB8-B67D-BD14889EA494")
RpyReactorTestHarness;
#endif
#endif /* __RPYREACTORLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
