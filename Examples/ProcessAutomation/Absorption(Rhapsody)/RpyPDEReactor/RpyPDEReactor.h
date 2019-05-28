/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Sun Nov 17 11:06:46 2002
 */
/* Compiler settings for C:\Rhapsody40\PDEReactor\RpyPDEReactor\RpyPDEReactor.idl:
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

#ifndef __RpyPDEReactor_h__
#define __RpyPDEReactor_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IRpyPDEReactorTest_FWD_DEFINED__
#define __IRpyPDEReactorTest_FWD_DEFINED__
typedef interface IRpyPDEReactorTest IRpyPDEReactorTest;
#endif 	/* __IRpyPDEReactorTest_FWD_DEFINED__ */


#ifndef __RpyPDEReactorTest_FWD_DEFINED__
#define __RpyPDEReactorTest_FWD_DEFINED__

#ifdef __cplusplus
typedef class RpyPDEReactorTest RpyPDEReactorTest;
#else
typedef struct RpyPDEReactorTest RpyPDEReactorTest;
#endif /* __cplusplus */

#endif 	/* __RpyPDEReactorTest_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "OnUMLEso.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IRpyPDEReactorTest_INTERFACE_DEFINED__
#define __IRpyPDEReactorTest_INTERFACE_DEFINED__

/* interface IRpyPDEReactorTest */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IRpyPDEReactorTest;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("225F917C-E26F-4E35-B5DB-C6EA501C551C")
    IRpyPDEReactorTest : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Step( 
            /* [in] */ double time) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVariables( 
            /* [in] */ double time,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ppsaVars) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IRpyPDEReactorTestVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IRpyPDEReactorTest __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IRpyPDEReactorTest __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IRpyPDEReactorTest __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IRpyPDEReactorTest __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IRpyPDEReactorTest __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IRpyPDEReactorTest __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IRpyPDEReactorTest __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Step )( 
            IRpyPDEReactorTest __RPC_FAR * This,
            /* [in] */ double time);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVariables )( 
            IRpyPDEReactorTest __RPC_FAR * This,
            /* [in] */ double time,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ppsaVars);
        
        END_INTERFACE
    } IRpyPDEReactorTestVtbl;

    interface IRpyPDEReactorTest
    {
        CONST_VTBL struct IRpyPDEReactorTestVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IRpyPDEReactorTest_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IRpyPDEReactorTest_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IRpyPDEReactorTest_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IRpyPDEReactorTest_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IRpyPDEReactorTest_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IRpyPDEReactorTest_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IRpyPDEReactorTest_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IRpyPDEReactorTest_Step(This,time)	\
    (This)->lpVtbl -> Step(This,time)

#define IRpyPDEReactorTest_GetVariables(This,time,ppsaVars)	\
    (This)->lpVtbl -> GetVariables(This,time,ppsaVars)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRpyPDEReactorTest_Step_Proxy( 
    IRpyPDEReactorTest __RPC_FAR * This,
    /* [in] */ double time);


void __RPC_STUB IRpyPDEReactorTest_Step_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IRpyPDEReactorTest_GetVariables_Proxy( 
    IRpyPDEReactorTest __RPC_FAR * This,
    /* [in] */ double time,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ppsaVars);


void __RPC_STUB IRpyPDEReactorTest_GetVariables_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IRpyPDEReactorTest_INTERFACE_DEFINED__ */



#ifndef __RPYPDEREACTORLib_LIBRARY_DEFINED__
#define __RPYPDEREACTORLib_LIBRARY_DEFINED__

/* library RPYPDEREACTORLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_RPYPDEREACTORLib;

EXTERN_C const CLSID CLSID_RpyPDEReactorTest;

#ifdef __cplusplus

class DECLSPEC_UUID("162A3AE1-0CAE-4DA1-9675-74C98AC7940D")
RpyPDEReactorTest;
#endif
#endif /* __RPYPDEREACTORLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long __RPC_FAR *, unsigned long            , LPSAFEARRAY __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, LPSAFEARRAY __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, LPSAFEARRAY __RPC_FAR * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long __RPC_FAR *, LPSAFEARRAY __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
