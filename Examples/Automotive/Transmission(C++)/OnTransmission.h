/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Aug 31 13:37:45 2001
 */
/* Compiler settings for C:\DistComponents\OnTransmission\OnTransmission.idl:
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

#ifndef __OnTransmission_h__
#define __OnTransmission_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IOnTransModelFactory_FWD_DEFINED__
#define __IOnTransModelFactory_FWD_DEFINED__
typedef interface IOnTransModelFactory IOnTransModelFactory;
#endif 	/* __IOnTransModelFactory_FWD_DEFINED__ */


#ifndef __ICBroadcastTest_FWD_DEFINED__
#define __ICBroadcastTest_FWD_DEFINED__
typedef interface ICBroadcastTest ICBroadcastTest;
#endif 	/* __ICBroadcastTest_FWD_DEFINED__ */


#ifndef __OnTransModelFactory_FWD_DEFINED__
#define __OnTransModelFactory_FWD_DEFINED__

#ifdef __cplusplus
typedef class OnTransModelFactory OnTransModelFactory;
#else
typedef struct OnTransModelFactory OnTransModelFactory;
#endif /* __cplusplus */

#endif 	/* __OnTransModelFactory_FWD_DEFINED__ */


#ifndef __CBroadcastTest_FWD_DEFINED__
#define __CBroadcastTest_FWD_DEFINED__

#ifdef __cplusplus
typedef class CBroadcastTest CBroadcastTest;
#else
typedef struct CBroadcastTest CBroadcastTest;
#endif /* __cplusplus */

#endif 	/* __CBroadcastTest_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IsDaeCOSolver.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IOnTransModelFactory_INTERFACE_DEFINED__
#define __IOnTransModelFactory_INTERFACE_DEFINED__

/* interface IOnTransModelFactory */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IOnTransModelFactory;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C632D18B-80C1-49A2-A8E4-86762B654A13")
    IOnTransModelFactory : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CreateModel( 
            /* [in] */ BSTR Name,
            /* [out][in] */ IDispatch __RPC_FAR *__RPC_FAR *pModel) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOnTransModelFactoryVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IOnTransModelFactory __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IOnTransModelFactory __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IOnTransModelFactory __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IOnTransModelFactory __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IOnTransModelFactory __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IOnTransModelFactory __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IOnTransModelFactory __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CreateModel )( 
            IOnTransModelFactory __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [out][in] */ IDispatch __RPC_FAR *__RPC_FAR *pModel);
        
        END_INTERFACE
    } IOnTransModelFactoryVtbl;

    interface IOnTransModelFactory
    {
        CONST_VTBL struct IOnTransModelFactoryVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOnTransModelFactory_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOnTransModelFactory_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOnTransModelFactory_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOnTransModelFactory_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOnTransModelFactory_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOnTransModelFactory_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOnTransModelFactory_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IOnTransModelFactory_CreateModel(This,Name,pModel)	\
    (This)->lpVtbl -> CreateModel(This,Name,pModel)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnTransModelFactory_CreateModel_Proxy( 
    IOnTransModelFactory __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [out][in] */ IDispatch __RPC_FAR *__RPC_FAR *pModel);


void __RPC_STUB IOnTransModelFactory_CreateModel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOnTransModelFactory_INTERFACE_DEFINED__ */


#ifndef __ICBroadcastTest_INTERFACE_DEFINED__
#define __ICBroadcastTest_INTERFACE_DEFINED__

/* interface ICBroadcastTest */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICBroadcastTest;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("0B55BCFE-DD2D-46E0-A624-3CAA4F1D40BC")
    ICBroadcastTest : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RunTest( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICBroadcastTestVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ICBroadcastTest __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ICBroadcastTest __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ICBroadcastTest __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ICBroadcastTest __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ICBroadcastTest __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ICBroadcastTest __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ICBroadcastTest __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RunTest )( 
            ICBroadcastTest __RPC_FAR * This);
        
        END_INTERFACE
    } ICBroadcastTestVtbl;

    interface ICBroadcastTest
    {
        CONST_VTBL struct ICBroadcastTestVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICBroadcastTest_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICBroadcastTest_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICBroadcastTest_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICBroadcastTest_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICBroadcastTest_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICBroadcastTest_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICBroadcastTest_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICBroadcastTest_RunTest(This)	\
    (This)->lpVtbl -> RunTest(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICBroadcastTest_RunTest_Proxy( 
    ICBroadcastTest __RPC_FAR * This);


void __RPC_STUB ICBroadcastTest_RunTest_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICBroadcastTest_INTERFACE_DEFINED__ */



#ifndef __ONTRANSMISSIONLib_LIBRARY_DEFINED__
#define __ONTRANSMISSIONLib_LIBRARY_DEFINED__

/* library ONTRANSMISSIONLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ONTRANSMISSIONLib;

EXTERN_C const CLSID CLSID_OnTransModelFactory;

#ifdef __cplusplus

class DECLSPEC_UUID("881EE912-657D-4CFA-B927-C64581CDE66F")
OnTransModelFactory;
#endif

EXTERN_C const CLSID CLSID_CBroadcastTest;

#ifdef __cplusplus

class DECLSPEC_UUID("67532C3D-F849-4AC7-A1A1-067F3E90CB67")
CBroadcastTest;
#endif
#endif /* __ONTRANSMISSIONLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
