/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Tue Jun 10 23:05:40 2003
 */
/* Compiler settings for C:\DistComponents\idl\OnPlot.IDL:
    Os (OptLev=s), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 440
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __OnPlot_h__
#define __OnPlot_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef ___OnThrottle_FWD_DEFINED__
#define ___OnThrottle_FWD_DEFINED__
typedef interface _OnThrottle _OnThrottle;
#endif 	/* ___OnThrottle_FWD_DEFINED__ */


#ifndef ___OnBrakes_FWD_DEFINED__
#define ___OnBrakes_FWD_DEFINED__
typedef interface _OnBrakes _OnBrakes;
#endif 	/* ___OnBrakes_FWD_DEFINED__ */


#ifndef ___OnShiftLever_FWD_DEFINED__
#define ___OnShiftLever_FWD_DEFINED__
typedef interface _OnShiftLever _OnShiftLever;
#endif 	/* ___OnShiftLever_FWD_DEFINED__ */


#ifndef ___OnPlotDlgMgr_FWD_DEFINED__
#define ___OnPlotDlgMgr_FWD_DEFINED__
typedef interface _OnPlotDlgMgr _OnPlotDlgMgr;
#endif 	/* ___OnPlotDlgMgr_FWD_DEFINED__ */


#ifndef ____OnThrottle_FWD_DEFINED__
#define ____OnThrottle_FWD_DEFINED__
typedef interface __OnThrottle __OnThrottle;
#endif 	/* ____OnThrottle_FWD_DEFINED__ */


#ifndef ____OnBrakes_FWD_DEFINED__
#define ____OnBrakes_FWD_DEFINED__
typedef interface __OnBrakes __OnBrakes;
#endif 	/* ____OnBrakes_FWD_DEFINED__ */


#ifndef ____OnShiftLever_FWD_DEFINED__
#define ____OnShiftLever_FWD_DEFINED__
typedef interface __OnShiftLever __OnShiftLever;
#endif 	/* ____OnShiftLever_FWD_DEFINED__ */


#ifndef __OnThrottle_FWD_DEFINED__
#define __OnThrottle_FWD_DEFINED__

#ifdef __cplusplus
typedef class OnThrottle OnThrottle;
#else
typedef struct OnThrottle OnThrottle;
#endif /* __cplusplus */

#endif 	/* __OnThrottle_FWD_DEFINED__ */


#ifndef __OnBrakes_FWD_DEFINED__
#define __OnBrakes_FWD_DEFINED__

#ifdef __cplusplus
typedef class OnBrakes OnBrakes;
#else
typedef struct OnBrakes OnBrakes;
#endif /* __cplusplus */

#endif 	/* __OnBrakes_FWD_DEFINED__ */


#ifndef __OnShiftLever_FWD_DEFINED__
#define __OnShiftLever_FWD_DEFINED__

#ifdef __cplusplus
typedef class OnShiftLever OnShiftLever;
#else
typedef struct OnShiftLever OnShiftLever;
#endif /* __cplusplus */

#endif 	/* __OnShiftLever_FWD_DEFINED__ */


#ifndef __OnPlotDlgMgr_FWD_DEFINED__
#define __OnPlotDlgMgr_FWD_DEFINED__

#ifdef __cplusplus
typedef class OnPlotDlgMgr OnPlotDlgMgr;
#else
typedef struct OnPlotDlgMgr OnPlotDlgMgr;
#endif /* __cplusplus */

#endif 	/* __OnPlotDlgMgr_FWD_DEFINED__ */


void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 


#ifndef __OnPlotLib_LIBRARY_DEFINED__
#define __OnPlotLib_LIBRARY_DEFINED__

/* library OnPlotLib */
/* [helpstring][version][uuid] */ 








typedef /* [public][version][uuid] */ _OnPlotDlgMgr OnPlotDlgMgr___v0;


EXTERN_C const IID LIBID_OnPlotLib;

#ifndef ___OnThrottle_INTERFACE_DEFINED__
#define ___OnThrottle_INTERFACE_DEFINED__

/* interface _OnThrottle */
/* [object][oleautomation][nonextensible][dual][hidden][version][uuid] */ 


EXTERN_C const IID IID__OnThrottle;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AC45BC84-79DD-418F-BA17-570FB32ADD78")
    _OnThrottle : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Throttle( 
            /* [retval][out] */ double __RPC_FAR *__MIDL_0014) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Throttle( 
            /* [out][in] */ double __RPC_FAR *__MIDL_0015) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _OnThrottleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _OnThrottle __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _OnThrottle __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _OnThrottle __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _OnThrottle __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _OnThrottle __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _OnThrottle __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _OnThrottle __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Throttle )( 
            _OnThrottle __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *__MIDL_0014);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Throttle )( 
            _OnThrottle __RPC_FAR * This,
            /* [out][in] */ double __RPC_FAR *__MIDL_0015);
        
        END_INTERFACE
    } _OnThrottleVtbl;

    interface _OnThrottle
    {
        CONST_VTBL struct _OnThrottleVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _OnThrottle_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _OnThrottle_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _OnThrottle_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _OnThrottle_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _OnThrottle_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _OnThrottle_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _OnThrottle_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define _OnThrottle_get_Throttle(This,__MIDL_0014)	\
    (This)->lpVtbl -> get_Throttle(This,__MIDL_0014)

#define _OnThrottle_put_Throttle(This,__MIDL_0015)	\
    (This)->lpVtbl -> put_Throttle(This,__MIDL_0015)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE _OnThrottle_get_Throttle_Proxy( 
    _OnThrottle __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *__MIDL_0014);


void __RPC_STUB _OnThrottle_get_Throttle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _OnThrottle_put_Throttle_Proxy( 
    _OnThrottle __RPC_FAR * This,
    /* [out][in] */ double __RPC_FAR *__MIDL_0015);


void __RPC_STUB _OnThrottle_put_Throttle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* ___OnThrottle_INTERFACE_DEFINED__ */


#ifndef ___OnBrakes_INTERFACE_DEFINED__
#define ___OnBrakes_INTERFACE_DEFINED__

/* interface _OnBrakes */
/* [object][oleautomation][nonextensible][dual][hidden][version][uuid] */ 


EXTERN_C const IID IID__OnBrakes;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1AECE0F1-5ABB-422D-9D59-AE73C2C65F92")
    _OnBrakes : public IDispatch
    {
    public:
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Brake( 
            /* [out][in] */ double __RPC_FAR *__MIDL_0016) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Brake( 
            /* [retval][out] */ double __RPC_FAR *__MIDL_0017) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _OnBrakesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _OnBrakes __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _OnBrakes __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _OnBrakes __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _OnBrakes __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _OnBrakes __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _OnBrakes __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _OnBrakes __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Brake )( 
            _OnBrakes __RPC_FAR * This,
            /* [out][in] */ double __RPC_FAR *__MIDL_0016);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Brake )( 
            _OnBrakes __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *__MIDL_0017);
        
        END_INTERFACE
    } _OnBrakesVtbl;

    interface _OnBrakes
    {
        CONST_VTBL struct _OnBrakesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _OnBrakes_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _OnBrakes_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _OnBrakes_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _OnBrakes_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _OnBrakes_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _OnBrakes_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _OnBrakes_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define _OnBrakes_put_Brake(This,__MIDL_0016)	\
    (This)->lpVtbl -> put_Brake(This,__MIDL_0016)

#define _OnBrakes_get_Brake(This,__MIDL_0017)	\
    (This)->lpVtbl -> get_Brake(This,__MIDL_0017)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propput][id] */ HRESULT STDMETHODCALLTYPE _OnBrakes_put_Brake_Proxy( 
    _OnBrakes __RPC_FAR * This,
    /* [out][in] */ double __RPC_FAR *__MIDL_0016);


void __RPC_STUB _OnBrakes_put_Brake_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _OnBrakes_get_Brake_Proxy( 
    _OnBrakes __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *__MIDL_0017);


void __RPC_STUB _OnBrakes_get_Brake_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* ___OnBrakes_INTERFACE_DEFINED__ */


#ifndef ___OnShiftLever_INTERFACE_DEFINED__
#define ___OnShiftLever_INTERFACE_DEFINED__

/* interface _OnShiftLever */
/* [object][oleautomation][nonextensible][dual][hidden][version][uuid] */ 


EXTERN_C const IID IID__OnShiftLever;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8BC66FF1-5D82-497A-AB3C-2676EE198106")
    _OnShiftLever : public IDispatch
    {
    public:
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Position( 
            /* [out][in] */ long __RPC_FAR *__MIDL_0018) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Position( 
            /* [retval][out] */ long __RPC_FAR *__MIDL_0019) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _OnShiftLeverVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _OnShiftLever __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _OnShiftLever __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _OnShiftLever __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _OnShiftLever __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _OnShiftLever __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _OnShiftLever __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _OnShiftLever __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Position )( 
            _OnShiftLever __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *__MIDL_0018);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Position )( 
            _OnShiftLever __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *__MIDL_0019);
        
        END_INTERFACE
    } _OnShiftLeverVtbl;

    interface _OnShiftLever
    {
        CONST_VTBL struct _OnShiftLeverVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _OnShiftLever_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _OnShiftLever_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _OnShiftLever_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _OnShiftLever_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _OnShiftLever_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _OnShiftLever_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _OnShiftLever_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define _OnShiftLever_put_Position(This,__MIDL_0018)	\
    (This)->lpVtbl -> put_Position(This,__MIDL_0018)

#define _OnShiftLever_get_Position(This,__MIDL_0019)	\
    (This)->lpVtbl -> get_Position(This,__MIDL_0019)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propput][id] */ HRESULT STDMETHODCALLTYPE _OnShiftLever_put_Position_Proxy( 
    _OnShiftLever __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *__MIDL_0018);


void __RPC_STUB _OnShiftLever_put_Position_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _OnShiftLever_get_Position_Proxy( 
    _OnShiftLever __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *__MIDL_0019);


void __RPC_STUB _OnShiftLever_get_Position_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* ___OnShiftLever_INTERFACE_DEFINED__ */


#ifndef ___OnPlotDlgMgr_INTERFACE_DEFINED__
#define ___OnPlotDlgMgr_INTERFACE_DEFINED__

/* interface _OnPlotDlgMgr */
/* [object][oleautomation][nonextensible][dual][hidden][version][uuid] */ 


EXTERN_C const IID IID__OnPlotDlgMgr;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("CF740FA9-357B-4F77-B81C-30D02E5E9B24")
    _OnPlotDlgMgr : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ShowBrakes( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ShowThrottle( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ShowShiftLever( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ShowChart( void) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_BrakeCaption( 
            /* [out][in] */ BSTR __RPC_FAR *rhs) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_ThrottleCaption( 
            /* [out][in] */ BSTR __RPC_FAR *rhs) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_ShiftLeverCaption( 
            /* [out][in] */ BSTR __RPC_FAR *rhs) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_ChartCaption( 
            /* [out][in] */ BSTR __RPC_FAR *rhs) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_BrakeVal( 
            /* [out][in] */ double __RPC_FAR *__MIDL_0020) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_BrakeVal( 
            /* [retval][out] */ double __RPC_FAR *__MIDL_0021) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_ShiftLeverVal( 
            /* [out][in] */ long __RPC_FAR *__MIDL_0022) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ShiftLeverVal( 
            /* [retval][out] */ long __RPC_FAR *__MIDL_0023) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_ThrottleVal( 
            /* [out][in] */ double __RPC_FAR *__MIDL_0024) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ThrottleVal( 
            /* [retval][out] */ double __RPC_FAR *__MIDL_0025) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ChartAddSeries( 
            /* [out][in] */ BSTR __RPC_FAR *Name) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ChartPlotData( 
            /* [out][in] */ double __RPC_FAR *time,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *vars,
            /* [out][in] */ long __RPC_FAR *count) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _OnPlotDlgMgrVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _OnPlotDlgMgr __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _OnPlotDlgMgr __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _OnPlotDlgMgr __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _OnPlotDlgMgr __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _OnPlotDlgMgr __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _OnPlotDlgMgr __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _OnPlotDlgMgr __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowBrakes )( 
            _OnPlotDlgMgr __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowThrottle )( 
            _OnPlotDlgMgr __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowShiftLever )( 
            _OnPlotDlgMgr __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowChart )( 
            _OnPlotDlgMgr __RPC_FAR * This);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BrakeCaption )( 
            _OnPlotDlgMgr __RPC_FAR * This,
            /* [out][in] */ BSTR __RPC_FAR *rhs);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ThrottleCaption )( 
            _OnPlotDlgMgr __RPC_FAR * This,
            /* [out][in] */ BSTR __RPC_FAR *rhs);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ShiftLeverCaption )( 
            _OnPlotDlgMgr __RPC_FAR * This,
            /* [out][in] */ BSTR __RPC_FAR *rhs);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ChartCaption )( 
            _OnPlotDlgMgr __RPC_FAR * This,
            /* [out][in] */ BSTR __RPC_FAR *rhs);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_BrakeVal )( 
            _OnPlotDlgMgr __RPC_FAR * This,
            /* [out][in] */ double __RPC_FAR *__MIDL_0020);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_BrakeVal )( 
            _OnPlotDlgMgr __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *__MIDL_0021);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ShiftLeverVal )( 
            _OnPlotDlgMgr __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *__MIDL_0022);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ShiftLeverVal )( 
            _OnPlotDlgMgr __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *__MIDL_0023);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ThrottleVal )( 
            _OnPlotDlgMgr __RPC_FAR * This,
            /* [out][in] */ double __RPC_FAR *__MIDL_0024);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ThrottleVal )( 
            _OnPlotDlgMgr __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *__MIDL_0025);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ChartAddSeries )( 
            _OnPlotDlgMgr __RPC_FAR * This,
            /* [out][in] */ BSTR __RPC_FAR *Name);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ChartPlotData )( 
            _OnPlotDlgMgr __RPC_FAR * This,
            /* [out][in] */ double __RPC_FAR *time,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *vars,
            /* [out][in] */ long __RPC_FAR *count);
        
        END_INTERFACE
    } _OnPlotDlgMgrVtbl;

    interface _OnPlotDlgMgr
    {
        CONST_VTBL struct _OnPlotDlgMgrVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _OnPlotDlgMgr_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _OnPlotDlgMgr_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _OnPlotDlgMgr_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _OnPlotDlgMgr_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _OnPlotDlgMgr_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _OnPlotDlgMgr_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _OnPlotDlgMgr_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define _OnPlotDlgMgr_ShowBrakes(This)	\
    (This)->lpVtbl -> ShowBrakes(This)

#define _OnPlotDlgMgr_ShowThrottle(This)	\
    (This)->lpVtbl -> ShowThrottle(This)

#define _OnPlotDlgMgr_ShowShiftLever(This)	\
    (This)->lpVtbl -> ShowShiftLever(This)

#define _OnPlotDlgMgr_ShowChart(This)	\
    (This)->lpVtbl -> ShowChart(This)

#define _OnPlotDlgMgr_put_BrakeCaption(This,rhs)	\
    (This)->lpVtbl -> put_BrakeCaption(This,rhs)

#define _OnPlotDlgMgr_put_ThrottleCaption(This,rhs)	\
    (This)->lpVtbl -> put_ThrottleCaption(This,rhs)

#define _OnPlotDlgMgr_put_ShiftLeverCaption(This,rhs)	\
    (This)->lpVtbl -> put_ShiftLeverCaption(This,rhs)

#define _OnPlotDlgMgr_put_ChartCaption(This,rhs)	\
    (This)->lpVtbl -> put_ChartCaption(This,rhs)

#define _OnPlotDlgMgr_put_BrakeVal(This,__MIDL_0020)	\
    (This)->lpVtbl -> put_BrakeVal(This,__MIDL_0020)

#define _OnPlotDlgMgr_get_BrakeVal(This,__MIDL_0021)	\
    (This)->lpVtbl -> get_BrakeVal(This,__MIDL_0021)

#define _OnPlotDlgMgr_put_ShiftLeverVal(This,__MIDL_0022)	\
    (This)->lpVtbl -> put_ShiftLeverVal(This,__MIDL_0022)

#define _OnPlotDlgMgr_get_ShiftLeverVal(This,__MIDL_0023)	\
    (This)->lpVtbl -> get_ShiftLeverVal(This,__MIDL_0023)

#define _OnPlotDlgMgr_put_ThrottleVal(This,__MIDL_0024)	\
    (This)->lpVtbl -> put_ThrottleVal(This,__MIDL_0024)

#define _OnPlotDlgMgr_get_ThrottleVal(This,__MIDL_0025)	\
    (This)->lpVtbl -> get_ThrottleVal(This,__MIDL_0025)

#define _OnPlotDlgMgr_ChartAddSeries(This,Name)	\
    (This)->lpVtbl -> ChartAddSeries(This,Name)

#define _OnPlotDlgMgr_ChartPlotData(This,time,vars,count)	\
    (This)->lpVtbl -> ChartPlotData(This,time,vars,count)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE _OnPlotDlgMgr_ShowBrakes_Proxy( 
    _OnPlotDlgMgr __RPC_FAR * This);


void __RPC_STUB _OnPlotDlgMgr_ShowBrakes_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _OnPlotDlgMgr_ShowThrottle_Proxy( 
    _OnPlotDlgMgr __RPC_FAR * This);


void __RPC_STUB _OnPlotDlgMgr_ShowThrottle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _OnPlotDlgMgr_ShowShiftLever_Proxy( 
    _OnPlotDlgMgr __RPC_FAR * This);


void __RPC_STUB _OnPlotDlgMgr_ShowShiftLever_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _OnPlotDlgMgr_ShowChart_Proxy( 
    _OnPlotDlgMgr __RPC_FAR * This);


void __RPC_STUB _OnPlotDlgMgr_ShowChart_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _OnPlotDlgMgr_put_BrakeCaption_Proxy( 
    _OnPlotDlgMgr __RPC_FAR * This,
    /* [out][in] */ BSTR __RPC_FAR *rhs);


void __RPC_STUB _OnPlotDlgMgr_put_BrakeCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _OnPlotDlgMgr_put_ThrottleCaption_Proxy( 
    _OnPlotDlgMgr __RPC_FAR * This,
    /* [out][in] */ BSTR __RPC_FAR *rhs);


void __RPC_STUB _OnPlotDlgMgr_put_ThrottleCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _OnPlotDlgMgr_put_ShiftLeverCaption_Proxy( 
    _OnPlotDlgMgr __RPC_FAR * This,
    /* [out][in] */ BSTR __RPC_FAR *rhs);


void __RPC_STUB _OnPlotDlgMgr_put_ShiftLeverCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _OnPlotDlgMgr_put_ChartCaption_Proxy( 
    _OnPlotDlgMgr __RPC_FAR * This,
    /* [out][in] */ BSTR __RPC_FAR *rhs);


void __RPC_STUB _OnPlotDlgMgr_put_ChartCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _OnPlotDlgMgr_put_BrakeVal_Proxy( 
    _OnPlotDlgMgr __RPC_FAR * This,
    /* [out][in] */ double __RPC_FAR *__MIDL_0020);


void __RPC_STUB _OnPlotDlgMgr_put_BrakeVal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _OnPlotDlgMgr_get_BrakeVal_Proxy( 
    _OnPlotDlgMgr __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *__MIDL_0021);


void __RPC_STUB _OnPlotDlgMgr_get_BrakeVal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _OnPlotDlgMgr_put_ShiftLeverVal_Proxy( 
    _OnPlotDlgMgr __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *__MIDL_0022);


void __RPC_STUB _OnPlotDlgMgr_put_ShiftLeverVal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _OnPlotDlgMgr_get_ShiftLeverVal_Proxy( 
    _OnPlotDlgMgr __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *__MIDL_0023);


void __RPC_STUB _OnPlotDlgMgr_get_ShiftLeverVal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _OnPlotDlgMgr_put_ThrottleVal_Proxy( 
    _OnPlotDlgMgr __RPC_FAR * This,
    /* [out][in] */ double __RPC_FAR *__MIDL_0024);


void __RPC_STUB _OnPlotDlgMgr_put_ThrottleVal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _OnPlotDlgMgr_get_ThrottleVal_Proxy( 
    _OnPlotDlgMgr __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *__MIDL_0025);


void __RPC_STUB _OnPlotDlgMgr_get_ThrottleVal_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _OnPlotDlgMgr_ChartAddSeries_Proxy( 
    _OnPlotDlgMgr __RPC_FAR * This,
    /* [out][in] */ BSTR __RPC_FAR *Name);


void __RPC_STUB _OnPlotDlgMgr_ChartAddSeries_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _OnPlotDlgMgr_ChartPlotData_Proxy( 
    _OnPlotDlgMgr __RPC_FAR * This,
    /* [out][in] */ double __RPC_FAR *time,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *vars,
    /* [out][in] */ long __RPC_FAR *count);


void __RPC_STUB _OnPlotDlgMgr_ChartPlotData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* ___OnPlotDlgMgr_INTERFACE_DEFINED__ */


#ifndef ____OnThrottle_DISPINTERFACE_DEFINED__
#define ____OnThrottle_DISPINTERFACE_DEFINED__

/* dispinterface __OnThrottle */
/* [nonextensible][hidden][version][uuid] */ 


EXTERN_C const IID DIID___OnThrottle;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("98B50489-5B70-44B5-8EA8-2C37DCBB5133")
    __OnThrottle : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct __OnThrottleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            __OnThrottle __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            __OnThrottle __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            __OnThrottle __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            __OnThrottle __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            __OnThrottle __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            __OnThrottle __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            __OnThrottle __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } __OnThrottleVtbl;

    interface __OnThrottle
    {
        CONST_VTBL struct __OnThrottleVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __OnThrottle_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define __OnThrottle_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define __OnThrottle_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define __OnThrottle_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define __OnThrottle_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define __OnThrottle_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define __OnThrottle_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ____OnThrottle_DISPINTERFACE_DEFINED__ */


#ifndef ____OnBrakes_DISPINTERFACE_DEFINED__
#define ____OnBrakes_DISPINTERFACE_DEFINED__

/* dispinterface __OnBrakes */
/* [nonextensible][hidden][version][uuid] */ 


EXTERN_C const IID DIID___OnBrakes;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("DC857E9B-C80F-4EAE-9C4F-66E75F23294E")
    __OnBrakes : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct __OnBrakesVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            __OnBrakes __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            __OnBrakes __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            __OnBrakes __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            __OnBrakes __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            __OnBrakes __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            __OnBrakes __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            __OnBrakes __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } __OnBrakesVtbl;

    interface __OnBrakes
    {
        CONST_VTBL struct __OnBrakesVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __OnBrakes_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define __OnBrakes_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define __OnBrakes_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define __OnBrakes_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define __OnBrakes_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define __OnBrakes_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define __OnBrakes_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ____OnBrakes_DISPINTERFACE_DEFINED__ */


#ifndef ____OnShiftLever_DISPINTERFACE_DEFINED__
#define ____OnShiftLever_DISPINTERFACE_DEFINED__

/* dispinterface __OnShiftLever */
/* [nonextensible][hidden][version][uuid] */ 


EXTERN_C const IID DIID___OnShiftLever;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("CCB5353D-19DA-4BD5-A750-C8B24087D18D")
    __OnShiftLever : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct __OnShiftLeverVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            __OnShiftLever __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            __OnShiftLever __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            __OnShiftLever __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            __OnShiftLever __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            __OnShiftLever __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            __OnShiftLever __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            __OnShiftLever __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } __OnShiftLeverVtbl;

    interface __OnShiftLever
    {
        CONST_VTBL struct __OnShiftLeverVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __OnShiftLever_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define __OnShiftLever_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define __OnShiftLever_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define __OnShiftLever_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define __OnShiftLever_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define __OnShiftLever_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define __OnShiftLever_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ____OnShiftLever_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_OnThrottle;

#ifdef __cplusplus

class DECLSPEC_UUID("71E96FA0-749E-4CAF-A453-71A278C3CB53")
OnThrottle;
#endif

EXTERN_C const CLSID CLSID_OnBrakes;

#ifdef __cplusplus

class DECLSPEC_UUID("A880BF82-2F9A-4575-82DB-7A2193C42189")
OnBrakes;
#endif

EXTERN_C const CLSID CLSID_OnShiftLever;

#ifdef __cplusplus

class DECLSPEC_UUID("DBAD0A7B-08AA-4431-B67E-86DD110B03EE")
OnShiftLever;
#endif

EXTERN_C const CLSID CLSID_OnPlotDlgMgr;

#ifdef __cplusplus

class DECLSPEC_UUID("FAC71F1E-0EB0-4F4C-AD54-1D7F6E8B90C2")
OnPlotDlgMgr;
#endif
#endif /* __OnPlotLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
