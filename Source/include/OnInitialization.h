/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Jun 30 00:50:36 2003
 */
/* Compiler settings for C:\DistComponents\idl\OnInitialization.IDL:
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

#ifndef __OnInitialization_h__
#define __OnInitialization_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef ___ctlInitialization_FWD_DEFINED__
#define ___ctlInitialization_FWD_DEFINED__
typedef interface _ctlInitialization _ctlInitialization;
#endif 	/* ___ctlInitialization_FWD_DEFINED__ */


#ifndef ___clsVar_FWD_DEFINED__
#define ___clsVar_FWD_DEFINED__
typedef interface _clsVar _clsVar;
#endif 	/* ___clsVar_FWD_DEFINED__ */


#ifndef ___clsCVar_FWD_DEFINED__
#define ___clsCVar_FWD_DEFINED__
typedef interface _clsCVar _clsCVar;
#endif 	/* ___clsCVar_FWD_DEFINED__ */


#ifndef ___clsVarManager_FWD_DEFINED__
#define ___clsVarManager_FWD_DEFINED__
typedef interface _clsVarManager _clsVarManager;
#endif 	/* ___clsVarManager_FWD_DEFINED__ */


#ifndef ___ctlEquationEditor_FWD_DEFINED__
#define ___ctlEquationEditor_FWD_DEFINED__
typedef interface _ctlEquationEditor _ctlEquationEditor;
#endif 	/* ___ctlEquationEditor_FWD_DEFINED__ */


#ifndef ___ctlMessageWindow_FWD_DEFINED__
#define ___ctlMessageWindow_FWD_DEFINED__
typedef interface _ctlMessageWindow _ctlMessageWindow;
#endif 	/* ___ctlMessageWindow_FWD_DEFINED__ */


#ifndef ___OnScriptParser_FWD_DEFINED__
#define ___OnScriptParser_FWD_DEFINED__
typedef interface _OnScriptParser _OnScriptParser;
#endif 	/* ___OnScriptParser_FWD_DEFINED__ */


#ifndef ____ctlInitialization_FWD_DEFINED__
#define ____ctlInitialization_FWD_DEFINED__
typedef interface __ctlInitialization __ctlInitialization;
#endif 	/* ____ctlInitialization_FWD_DEFINED__ */


#ifndef ____ctlEquationEditor_FWD_DEFINED__
#define ____ctlEquationEditor_FWD_DEFINED__
typedef interface __ctlEquationEditor __ctlEquationEditor;
#endif 	/* ____ctlEquationEditor_FWD_DEFINED__ */


#ifndef ____ctlMessageWindow_FWD_DEFINED__
#define ____ctlMessageWindow_FWD_DEFINED__
typedef interface __ctlMessageWindow __ctlMessageWindow;
#endif 	/* ____ctlMessageWindow_FWD_DEFINED__ */


#ifndef ____OnScriptParser_FWD_DEFINED__
#define ____OnScriptParser_FWD_DEFINED__
typedef interface __OnScriptParser __OnScriptParser;
#endif 	/* ____OnScriptParser_FWD_DEFINED__ */


#ifndef __ctlInitialization_FWD_DEFINED__
#define __ctlInitialization_FWD_DEFINED__

#ifdef __cplusplus
typedef class ctlInitialization ctlInitialization;
#else
typedef struct ctlInitialization ctlInitialization;
#endif /* __cplusplus */

#endif 	/* __ctlInitialization_FWD_DEFINED__ */


#ifndef __clsVar_FWD_DEFINED__
#define __clsVar_FWD_DEFINED__

#ifdef __cplusplus
typedef class clsVar clsVar;
#else
typedef struct clsVar clsVar;
#endif /* __cplusplus */

#endif 	/* __clsVar_FWD_DEFINED__ */


#ifndef __clsCVar_FWD_DEFINED__
#define __clsCVar_FWD_DEFINED__

#ifdef __cplusplus
typedef class clsCVar clsCVar;
#else
typedef struct clsCVar clsCVar;
#endif /* __cplusplus */

#endif 	/* __clsCVar_FWD_DEFINED__ */


#ifndef __clsVarManager_FWD_DEFINED__
#define __clsVarManager_FWD_DEFINED__

#ifdef __cplusplus
typedef class clsVarManager clsVarManager;
#else
typedef struct clsVarManager clsVarManager;
#endif /* __cplusplus */

#endif 	/* __clsVarManager_FWD_DEFINED__ */


#ifndef __ctlEquationEditor_FWD_DEFINED__
#define __ctlEquationEditor_FWD_DEFINED__

#ifdef __cplusplus
typedef class ctlEquationEditor ctlEquationEditor;
#else
typedef struct ctlEquationEditor ctlEquationEditor;
#endif /* __cplusplus */

#endif 	/* __ctlEquationEditor_FWD_DEFINED__ */


#ifndef __ctlMessageWindow_FWD_DEFINED__
#define __ctlMessageWindow_FWD_DEFINED__

#ifdef __cplusplus
typedef class ctlMessageWindow ctlMessageWindow;
#else
typedef struct ctlMessageWindow ctlMessageWindow;
#endif /* __cplusplus */

#endif 	/* __ctlMessageWindow_FWD_DEFINED__ */


#ifndef __OnScriptParser_FWD_DEFINED__
#define __OnScriptParser_FWD_DEFINED__

#ifdef __cplusplus
typedef class OnScriptParser OnScriptParser;
#else
typedef struct OnScriptParser OnScriptParser;
#endif /* __cplusplus */

#endif 	/* __OnScriptParser_FWD_DEFINED__ */


void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 


#ifndef __OnInitialization_LIBRARY_DEFINED__
#define __OnInitialization_LIBRARY_DEFINED__

/* library OnInitialization */
/* [helpstring][version][uuid] */ 













EXTERN_C const IID LIBID_OnInitialization;

#ifndef ___ctlInitialization_INTERFACE_DEFINED__
#define ___ctlInitialization_INTERFACE_DEFINED__

/* interface _ctlInitialization */
/* [object][oleautomation][nonextensible][dual][hidden][version][uuid] */ 


EXTERN_C const IID IID__ctlInitialization;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("ED7DF5FA-20BE-45C3-B101-6A4B53C2B2FE")
    _ctlInitialization : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE init( 
            /* [out][in] */ _OnScriptParser __RPC_FAR *__RPC_FAR *sp,
            /* [out][in] */ _clsVarManager __RPC_FAR *__RPC_FAR *vm) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Destroy( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE OnApply( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE IsMsgWindowVisible( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *__MIDL_0014) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ShowMessageWindow( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SizeStatusBar( 
            /* [out][in] */ long __RPC_FAR *Y) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _ctlInitializationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _ctlInitialization __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _ctlInitialization __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _ctlInitialization __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _ctlInitialization __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _ctlInitialization __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _ctlInitialization __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _ctlInitialization __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *init )( 
            _ctlInitialization __RPC_FAR * This,
            /* [out][in] */ _OnScriptParser __RPC_FAR *__RPC_FAR *sp,
            /* [out][in] */ _clsVarManager __RPC_FAR *__RPC_FAR *vm);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Destroy )( 
            _ctlInitialization __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnApply )( 
            _ctlInitialization __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *IsMsgWindowVisible )( 
            _ctlInitialization __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *__MIDL_0014);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowMessageWindow )( 
            _ctlInitialization __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SizeStatusBar )( 
            _ctlInitialization __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *Y);
        
        END_INTERFACE
    } _ctlInitializationVtbl;

    interface _ctlInitialization
    {
        CONST_VTBL struct _ctlInitializationVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ctlInitialization_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _ctlInitialization_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _ctlInitialization_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _ctlInitialization_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _ctlInitialization_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _ctlInitialization_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _ctlInitialization_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define _ctlInitialization_init(This,sp,vm)	\
    (This)->lpVtbl -> init(This,sp,vm)

#define _ctlInitialization_Destroy(This)	\
    (This)->lpVtbl -> Destroy(This)

#define _ctlInitialization_OnApply(This)	\
    (This)->lpVtbl -> OnApply(This)

#define _ctlInitialization_IsMsgWindowVisible(This,__MIDL_0014)	\
    (This)->lpVtbl -> IsMsgWindowVisible(This,__MIDL_0014)

#define _ctlInitialization_ShowMessageWindow(This)	\
    (This)->lpVtbl -> ShowMessageWindow(This)

#define _ctlInitialization_SizeStatusBar(This,Y)	\
    (This)->lpVtbl -> SizeStatusBar(This,Y)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE _ctlInitialization_init_Proxy( 
    _ctlInitialization __RPC_FAR * This,
    /* [out][in] */ _OnScriptParser __RPC_FAR *__RPC_FAR *sp,
    /* [out][in] */ _clsVarManager __RPC_FAR *__RPC_FAR *vm);


void __RPC_STUB _ctlInitialization_init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _ctlInitialization_Destroy_Proxy( 
    _ctlInitialization __RPC_FAR * This);


void __RPC_STUB _ctlInitialization_Destroy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _ctlInitialization_OnApply_Proxy( 
    _ctlInitialization __RPC_FAR * This);


void __RPC_STUB _ctlInitialization_OnApply_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _ctlInitialization_IsMsgWindowVisible_Proxy( 
    _ctlInitialization __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *__MIDL_0014);


void __RPC_STUB _ctlInitialization_IsMsgWindowVisible_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _ctlInitialization_ShowMessageWindow_Proxy( 
    _ctlInitialization __RPC_FAR * This);


void __RPC_STUB _ctlInitialization_ShowMessageWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _ctlInitialization_SizeStatusBar_Proxy( 
    _ctlInitialization __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *Y);


void __RPC_STUB _ctlInitialization_SizeStatusBar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* ___ctlInitialization_INTERFACE_DEFINED__ */


#ifndef ___clsVar_INTERFACE_DEFINED__
#define ___clsVar_INTERFACE_DEFINED__

/* interface _clsVar */
/* [object][oleautomation][nonextensible][dual][hidden][version][uuid] */ 


EXTERN_C const IID IID__clsVar;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4C9143EA-7080-4BC1-84F6-50935435E0A7")
    _clsVar : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_longName( 
            /* [retval][out] */ BSTR __RPC_FAR *longName) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_longName( 
            /* [in] */ BSTR longName) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR __RPC_FAR *Name) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR Name) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Force( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Force) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Force( 
            /* [in] */ VARIANT_BOOL Force) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_DerForce( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *DerForce) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_DerForce( 
            /* [in] */ VARIANT_BOOL DerForce) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_ActiveIdx( 
            /* [retval][out] */ long __RPC_FAR *ActiveIdx) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_ActiveIdx( 
            /* [in] */ long ActiveIdx) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_GlobalIdx( 
            /* [retval][out] */ long __RPC_FAR *GlobalIdx) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_GlobalIdx( 
            /* [in] */ long GlobalIdx) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_GenEv( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *GenEv) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_GenEv( 
            /* [in] */ VARIANT_BOOL GenEv) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Root( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Root) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Root( 
            /* [in] */ VARIANT_BOOL Root) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_m_vm( 
            /* [retval][out] */ _clsVarManager __RPC_FAR *__RPC_FAR *m_vm) = 0;
        
        virtual /* [propputref][id] */ HRESULT STDMETHODCALLTYPE putref_m_vm( 
            /* [in] */ _clsVarManager __RPC_FAR *m_vm) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE init( 
            /* [out][in] */ BSTR __RPC_FAR *itsName,
            /* [out][in] */ BSTR __RPC_FAR *itsLongName,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *IsRoot,
            /* [out][in] */ long __RPC_FAR *ActiveId,
            /* [out][in] */ long __RPC_FAR *GlobalId,
            /* [out][in] */ double __RPC_FAR *v,
            /* [out][in] */ double __RPC_FAR *dv,
            /* [out][in] */ _clsVarManager __RPC_FAR *__RPC_FAR *vm) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [retval][out] */ double __RPC_FAR *__MIDL_0015) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [out][in] */ double __RPC_FAR *__MIDL_0016) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_der( 
            /* [defaultvalue][optional][out][in] */ long __RPC_FAR *derIdx,
            /* [retval][out] */ double __RPC_FAR *__MIDL_0017) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_der( 
            /* [defaultvalue][optional][out][in] */ long __RPC_FAR *derIdx,
            /* [out][in] */ double __RPC_FAR *__MIDL_0018) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Destroy( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _clsVarVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _clsVar __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _clsVar __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _clsVar __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _clsVar __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _clsVar __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _clsVar __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _clsVar __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_longName )( 
            _clsVar __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *longName);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_longName )( 
            _clsVar __RPC_FAR * This,
            /* [in] */ BSTR longName);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            _clsVar __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Name);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Name )( 
            _clsVar __RPC_FAR * This,
            /* [in] */ BSTR Name);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Force )( 
            _clsVar __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Force);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Force )( 
            _clsVar __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Force);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DerForce )( 
            _clsVar __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *DerForce);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DerForce )( 
            _clsVar __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL DerForce);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ActiveIdx )( 
            _clsVar __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *ActiveIdx);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ActiveIdx )( 
            _clsVar __RPC_FAR * This,
            /* [in] */ long ActiveIdx);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_GlobalIdx )( 
            _clsVar __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *GlobalIdx);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_GlobalIdx )( 
            _clsVar __RPC_FAR * This,
            /* [in] */ long GlobalIdx);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_GenEv )( 
            _clsVar __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *GenEv);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_GenEv )( 
            _clsVar __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL GenEv);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Root )( 
            _clsVar __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Root);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Root )( 
            _clsVar __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Root);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_m_vm )( 
            _clsVar __RPC_FAR * This,
            /* [retval][out] */ _clsVarManager __RPC_FAR *__RPC_FAR *m_vm);
        
        /* [propputref][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_m_vm )( 
            _clsVar __RPC_FAR * This,
            /* [in] */ _clsVarManager __RPC_FAR *m_vm);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *init )( 
            _clsVar __RPC_FAR * This,
            /* [out][in] */ BSTR __RPC_FAR *itsName,
            /* [out][in] */ BSTR __RPC_FAR *itsLongName,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *IsRoot,
            /* [out][in] */ long __RPC_FAR *ActiveId,
            /* [out][in] */ long __RPC_FAR *GlobalId,
            /* [out][in] */ double __RPC_FAR *v,
            /* [out][in] */ double __RPC_FAR *dv,
            /* [out][in] */ _clsVarManager __RPC_FAR *__RPC_FAR *vm);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Value )( 
            _clsVar __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *__MIDL_0015);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Value )( 
            _clsVar __RPC_FAR * This,
            /* [out][in] */ double __RPC_FAR *__MIDL_0016);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_der )( 
            _clsVar __RPC_FAR * This,
            /* [defaultvalue][optional][out][in] */ long __RPC_FAR *derIdx,
            /* [retval][out] */ double __RPC_FAR *__MIDL_0017);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_der )( 
            _clsVar __RPC_FAR * This,
            /* [defaultvalue][optional][out][in] */ long __RPC_FAR *derIdx,
            /* [out][in] */ double __RPC_FAR *__MIDL_0018);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Destroy )( 
            _clsVar __RPC_FAR * This);
        
        END_INTERFACE
    } _clsVarVtbl;

    interface _clsVar
    {
        CONST_VTBL struct _clsVarVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _clsVar_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _clsVar_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _clsVar_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _clsVar_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _clsVar_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _clsVar_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _clsVar_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define _clsVar_get_longName(This,longName)	\
    (This)->lpVtbl -> get_longName(This,longName)

#define _clsVar_put_longName(This,longName)	\
    (This)->lpVtbl -> put_longName(This,longName)

#define _clsVar_get_Name(This,Name)	\
    (This)->lpVtbl -> get_Name(This,Name)

#define _clsVar_put_Name(This,Name)	\
    (This)->lpVtbl -> put_Name(This,Name)

#define _clsVar_get_Force(This,Force)	\
    (This)->lpVtbl -> get_Force(This,Force)

#define _clsVar_put_Force(This,Force)	\
    (This)->lpVtbl -> put_Force(This,Force)

#define _clsVar_get_DerForce(This,DerForce)	\
    (This)->lpVtbl -> get_DerForce(This,DerForce)

#define _clsVar_put_DerForce(This,DerForce)	\
    (This)->lpVtbl -> put_DerForce(This,DerForce)

#define _clsVar_get_ActiveIdx(This,ActiveIdx)	\
    (This)->lpVtbl -> get_ActiveIdx(This,ActiveIdx)

#define _clsVar_put_ActiveIdx(This,ActiveIdx)	\
    (This)->lpVtbl -> put_ActiveIdx(This,ActiveIdx)

#define _clsVar_get_GlobalIdx(This,GlobalIdx)	\
    (This)->lpVtbl -> get_GlobalIdx(This,GlobalIdx)

#define _clsVar_put_GlobalIdx(This,GlobalIdx)	\
    (This)->lpVtbl -> put_GlobalIdx(This,GlobalIdx)

#define _clsVar_get_GenEv(This,GenEv)	\
    (This)->lpVtbl -> get_GenEv(This,GenEv)

#define _clsVar_put_GenEv(This,GenEv)	\
    (This)->lpVtbl -> put_GenEv(This,GenEv)

#define _clsVar_get_Root(This,Root)	\
    (This)->lpVtbl -> get_Root(This,Root)

#define _clsVar_put_Root(This,Root)	\
    (This)->lpVtbl -> put_Root(This,Root)

#define _clsVar_get_m_vm(This,m_vm)	\
    (This)->lpVtbl -> get_m_vm(This,m_vm)

#define _clsVar_putref_m_vm(This,m_vm)	\
    (This)->lpVtbl -> putref_m_vm(This,m_vm)

#define _clsVar_init(This,itsName,itsLongName,IsRoot,ActiveId,GlobalId,v,dv,vm)	\
    (This)->lpVtbl -> init(This,itsName,itsLongName,IsRoot,ActiveId,GlobalId,v,dv,vm)

#define _clsVar_get_Value(This,__MIDL_0015)	\
    (This)->lpVtbl -> get_Value(This,__MIDL_0015)

#define _clsVar_put_Value(This,__MIDL_0016)	\
    (This)->lpVtbl -> put_Value(This,__MIDL_0016)

#define _clsVar_get_der(This,derIdx,__MIDL_0017)	\
    (This)->lpVtbl -> get_der(This,derIdx,__MIDL_0017)

#define _clsVar_put_der(This,derIdx,__MIDL_0018)	\
    (This)->lpVtbl -> put_der(This,derIdx,__MIDL_0018)

#define _clsVar_Destroy(This)	\
    (This)->lpVtbl -> Destroy(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsVar_get_longName_Proxy( 
    _clsVar __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *longName);


void __RPC_STUB _clsVar_get_longName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsVar_put_longName_Proxy( 
    _clsVar __RPC_FAR * This,
    /* [in] */ BSTR longName);


void __RPC_STUB _clsVar_put_longName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsVar_get_Name_Proxy( 
    _clsVar __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Name);


void __RPC_STUB _clsVar_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsVar_put_Name_Proxy( 
    _clsVar __RPC_FAR * This,
    /* [in] */ BSTR Name);


void __RPC_STUB _clsVar_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsVar_get_Force_Proxy( 
    _clsVar __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Force);


void __RPC_STUB _clsVar_get_Force_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsVar_put_Force_Proxy( 
    _clsVar __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL Force);


void __RPC_STUB _clsVar_put_Force_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsVar_get_DerForce_Proxy( 
    _clsVar __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *DerForce);


void __RPC_STUB _clsVar_get_DerForce_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsVar_put_DerForce_Proxy( 
    _clsVar __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL DerForce);


void __RPC_STUB _clsVar_put_DerForce_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsVar_get_ActiveIdx_Proxy( 
    _clsVar __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *ActiveIdx);


void __RPC_STUB _clsVar_get_ActiveIdx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsVar_put_ActiveIdx_Proxy( 
    _clsVar __RPC_FAR * This,
    /* [in] */ long ActiveIdx);


void __RPC_STUB _clsVar_put_ActiveIdx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsVar_get_GlobalIdx_Proxy( 
    _clsVar __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *GlobalIdx);


void __RPC_STUB _clsVar_get_GlobalIdx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsVar_put_GlobalIdx_Proxy( 
    _clsVar __RPC_FAR * This,
    /* [in] */ long GlobalIdx);


void __RPC_STUB _clsVar_put_GlobalIdx_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsVar_get_GenEv_Proxy( 
    _clsVar __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *GenEv);


void __RPC_STUB _clsVar_get_GenEv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsVar_put_GenEv_Proxy( 
    _clsVar __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL GenEv);


void __RPC_STUB _clsVar_put_GenEv_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsVar_get_Root_Proxy( 
    _clsVar __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Root);


void __RPC_STUB _clsVar_get_Root_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsVar_put_Root_Proxy( 
    _clsVar __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL Root);


void __RPC_STUB _clsVar_put_Root_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsVar_get_m_vm_Proxy( 
    _clsVar __RPC_FAR * This,
    /* [retval][out] */ _clsVarManager __RPC_FAR *__RPC_FAR *m_vm);


void __RPC_STUB _clsVar_get_m_vm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propputref][id] */ HRESULT STDMETHODCALLTYPE _clsVar_putref_m_vm_Proxy( 
    _clsVar __RPC_FAR * This,
    /* [in] */ _clsVarManager __RPC_FAR *m_vm);


void __RPC_STUB _clsVar_putref_m_vm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsVar_init_Proxy( 
    _clsVar __RPC_FAR * This,
    /* [out][in] */ BSTR __RPC_FAR *itsName,
    /* [out][in] */ BSTR __RPC_FAR *itsLongName,
    /* [out][in] */ VARIANT_BOOL __RPC_FAR *IsRoot,
    /* [out][in] */ long __RPC_FAR *ActiveId,
    /* [out][in] */ long __RPC_FAR *GlobalId,
    /* [out][in] */ double __RPC_FAR *v,
    /* [out][in] */ double __RPC_FAR *dv,
    /* [out][in] */ _clsVarManager __RPC_FAR *__RPC_FAR *vm);


void __RPC_STUB _clsVar_init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsVar_get_Value_Proxy( 
    _clsVar __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *__MIDL_0015);


void __RPC_STUB _clsVar_get_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsVar_put_Value_Proxy( 
    _clsVar __RPC_FAR * This,
    /* [out][in] */ double __RPC_FAR *__MIDL_0016);


void __RPC_STUB _clsVar_put_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsVar_get_der_Proxy( 
    _clsVar __RPC_FAR * This,
    /* [defaultvalue][optional][out][in] */ long __RPC_FAR *derIdx,
    /* [retval][out] */ double __RPC_FAR *__MIDL_0017);


void __RPC_STUB _clsVar_get_der_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsVar_put_der_Proxy( 
    _clsVar __RPC_FAR * This,
    /* [defaultvalue][optional][out][in] */ long __RPC_FAR *derIdx,
    /* [out][in] */ double __RPC_FAR *__MIDL_0018);


void __RPC_STUB _clsVar_put_der_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsVar_Destroy_Proxy( 
    _clsVar __RPC_FAR * This);


void __RPC_STUB _clsVar_Destroy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* ___clsVar_INTERFACE_DEFINED__ */


#ifndef ___clsCVar_INTERFACE_DEFINED__
#define ___clsCVar_INTERFACE_DEFINED__

/* interface _clsCVar */
/* [object][oleautomation][nonextensible][dual][hidden][version][uuid] */ 


EXTERN_C const IID IID__clsCVar;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("53163479-35EC-4972-B481-FAA0F53BCC89")
    _clsCVar : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Name( 
            /* [retval][out] */ BSTR __RPC_FAR *Name) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Name( 
            /* [in] */ BSTR Name) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_longName( 
            /* [retval][out] */ BSTR __RPC_FAR *longName) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_longName( 
            /* [in] */ BSTR longName) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Root( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Root) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_Root( 
            /* [in] */ VARIANT_BOOL Root) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_m_vm( 
            /* [retval][out] */ _clsVarManager __RPC_FAR *__RPC_FAR *m_vm) = 0;
        
        virtual /* [propputref][id] */ HRESULT STDMETHODCALLTYPE putref_m_vm( 
            /* [in] */ _clsVarManager __RPC_FAR *m_vm) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE init( 
            /* [out][in] */ BSTR __RPC_FAR *itsName,
            /* [out][in] */ BSTR __RPC_FAR *itsLongName,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *IsRoot,
            /* [out][in] */ _clsVarManager __RPC_FAR *__RPC_FAR *vm) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Add( 
            /* [out][in] */ BSTR __RPC_FAR *itemKey,
            /* [out][in] */ IDispatch __RPC_FAR *__RPC_FAR *newItem) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE removeAll( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE remove( 
            /* [out][in] */ VARIANT __RPC_FAR *itemKey) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Item( 
            /* [out][in] */ VARIANT __RPC_FAR *itemKey,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *__MIDL_0019) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_Count( 
            /* [retval][out] */ long __RPC_FAR *__MIDL_0020) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Destroy( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _clsCVarVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _clsCVar __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _clsCVar __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _clsCVar __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _clsCVar __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _clsCVar __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _clsCVar __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _clsCVar __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Name )( 
            _clsCVar __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *Name);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Name )( 
            _clsCVar __RPC_FAR * This,
            /* [in] */ BSTR Name);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_longName )( 
            _clsCVar __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *longName);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_longName )( 
            _clsCVar __RPC_FAR * This,
            /* [in] */ BSTR longName);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Root )( 
            _clsCVar __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Root);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Root )( 
            _clsCVar __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL Root);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_m_vm )( 
            _clsCVar __RPC_FAR * This,
            /* [retval][out] */ _clsVarManager __RPC_FAR *__RPC_FAR *m_vm);
        
        /* [propputref][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_m_vm )( 
            _clsCVar __RPC_FAR * This,
            /* [in] */ _clsVarManager __RPC_FAR *m_vm);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *init )( 
            _clsCVar __RPC_FAR * This,
            /* [out][in] */ BSTR __RPC_FAR *itsName,
            /* [out][in] */ BSTR __RPC_FAR *itsLongName,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *IsRoot,
            /* [out][in] */ _clsVarManager __RPC_FAR *__RPC_FAR *vm);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Add )( 
            _clsCVar __RPC_FAR * This,
            /* [out][in] */ BSTR __RPC_FAR *itemKey,
            /* [out][in] */ IDispatch __RPC_FAR *__RPC_FAR *newItem);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *removeAll )( 
            _clsCVar __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *remove )( 
            _clsCVar __RPC_FAR * This,
            /* [out][in] */ VARIANT __RPC_FAR *itemKey);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Item )( 
            _clsCVar __RPC_FAR * This,
            /* [out][in] */ VARIANT __RPC_FAR *itemKey,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *__MIDL_0019);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Count )( 
            _clsCVar __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *__MIDL_0020);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Destroy )( 
            _clsCVar __RPC_FAR * This);
        
        END_INTERFACE
    } _clsCVarVtbl;

    interface _clsCVar
    {
        CONST_VTBL struct _clsCVarVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _clsCVar_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _clsCVar_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _clsCVar_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _clsCVar_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _clsCVar_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _clsCVar_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _clsCVar_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define _clsCVar_get_Name(This,Name)	\
    (This)->lpVtbl -> get_Name(This,Name)

#define _clsCVar_put_Name(This,Name)	\
    (This)->lpVtbl -> put_Name(This,Name)

#define _clsCVar_get_longName(This,longName)	\
    (This)->lpVtbl -> get_longName(This,longName)

#define _clsCVar_put_longName(This,longName)	\
    (This)->lpVtbl -> put_longName(This,longName)

#define _clsCVar_get_Root(This,Root)	\
    (This)->lpVtbl -> get_Root(This,Root)

#define _clsCVar_put_Root(This,Root)	\
    (This)->lpVtbl -> put_Root(This,Root)

#define _clsCVar_get_m_vm(This,m_vm)	\
    (This)->lpVtbl -> get_m_vm(This,m_vm)

#define _clsCVar_putref_m_vm(This,m_vm)	\
    (This)->lpVtbl -> putref_m_vm(This,m_vm)

#define _clsCVar_init(This,itsName,itsLongName,IsRoot,vm)	\
    (This)->lpVtbl -> init(This,itsName,itsLongName,IsRoot,vm)

#define _clsCVar_Add(This,itemKey,newItem)	\
    (This)->lpVtbl -> Add(This,itemKey,newItem)

#define _clsCVar_removeAll(This)	\
    (This)->lpVtbl -> removeAll(This)

#define _clsCVar_remove(This,itemKey)	\
    (This)->lpVtbl -> remove(This,itemKey)

#define _clsCVar_get_Item(This,itemKey,__MIDL_0019)	\
    (This)->lpVtbl -> get_Item(This,itemKey,__MIDL_0019)

#define _clsCVar_get_Count(This,__MIDL_0020)	\
    (This)->lpVtbl -> get_Count(This,__MIDL_0020)

#define _clsCVar_Destroy(This)	\
    (This)->lpVtbl -> Destroy(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsCVar_get_Name_Proxy( 
    _clsCVar __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *Name);


void __RPC_STUB _clsCVar_get_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsCVar_put_Name_Proxy( 
    _clsCVar __RPC_FAR * This,
    /* [in] */ BSTR Name);


void __RPC_STUB _clsCVar_put_Name_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsCVar_get_longName_Proxy( 
    _clsCVar __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *longName);


void __RPC_STUB _clsCVar_get_longName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsCVar_put_longName_Proxy( 
    _clsCVar __RPC_FAR * This,
    /* [in] */ BSTR longName);


void __RPC_STUB _clsCVar_put_longName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsCVar_get_Root_Proxy( 
    _clsCVar __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *Root);


void __RPC_STUB _clsCVar_get_Root_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _clsCVar_put_Root_Proxy( 
    _clsCVar __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL Root);


void __RPC_STUB _clsCVar_put_Root_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsCVar_get_m_vm_Proxy( 
    _clsCVar __RPC_FAR * This,
    /* [retval][out] */ _clsVarManager __RPC_FAR *__RPC_FAR *m_vm);


void __RPC_STUB _clsCVar_get_m_vm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propputref][id] */ HRESULT STDMETHODCALLTYPE _clsCVar_putref_m_vm_Proxy( 
    _clsCVar __RPC_FAR * This,
    /* [in] */ _clsVarManager __RPC_FAR *m_vm);


void __RPC_STUB _clsCVar_putref_m_vm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsCVar_init_Proxy( 
    _clsCVar __RPC_FAR * This,
    /* [out][in] */ BSTR __RPC_FAR *itsName,
    /* [out][in] */ BSTR __RPC_FAR *itsLongName,
    /* [out][in] */ VARIANT_BOOL __RPC_FAR *IsRoot,
    /* [out][in] */ _clsVarManager __RPC_FAR *__RPC_FAR *vm);


void __RPC_STUB _clsCVar_init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsCVar_Add_Proxy( 
    _clsCVar __RPC_FAR * This,
    /* [out][in] */ BSTR __RPC_FAR *itemKey,
    /* [out][in] */ IDispatch __RPC_FAR *__RPC_FAR *newItem);


void __RPC_STUB _clsCVar_Add_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsCVar_removeAll_Proxy( 
    _clsCVar __RPC_FAR * This);


void __RPC_STUB _clsCVar_removeAll_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsCVar_remove_Proxy( 
    _clsCVar __RPC_FAR * This,
    /* [out][in] */ VARIANT __RPC_FAR *itemKey);


void __RPC_STUB _clsCVar_remove_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsCVar_get_Item_Proxy( 
    _clsCVar __RPC_FAR * This,
    /* [out][in] */ VARIANT __RPC_FAR *itemKey,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *__MIDL_0019);


void __RPC_STUB _clsCVar_get_Item_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsCVar_get_Count_Proxy( 
    _clsCVar __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *__MIDL_0020);


void __RPC_STUB _clsCVar_get_Count_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsCVar_Destroy_Proxy( 
    _clsCVar __RPC_FAR * This);


void __RPC_STUB _clsCVar_Destroy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* ___clsCVar_INTERFACE_DEFINED__ */


#ifndef ___clsVarManager_INTERFACE_DEFINED__
#define ___clsVarManager_INTERFACE_DEFINED__

/* interface _clsVarManager */
/* [object][oleautomation][nonextensible][dual][hidden][version][uuid] */ 


EXTERN_C const IID IID__clsVarManager;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("DECA34C4-1F6B-4DF0-8F19-3533DC83B0DB")
    _clsVarManager : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_vars( 
            /* [retval][out] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *vars) = 0;
        
        virtual /* [propputref][id] */ HRESULT STDMETHODCALLTYPE putref_vars( 
            /* [in] */ /* external definition not present */ _Collection __RPC_FAR *vars) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_CVars( 
            /* [retval][out] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *CVars) = 0;
        
        virtual /* [propputref][id] */ HRESULT STDMETHODCALLTYPE putref_CVars( 
            /* [in] */ /* external definition not present */ _Collection __RPC_FAR *CVars) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_EqnV( 
            /* [retval][out] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *EqnV) = 0;
        
        virtual /* [propputref][id] */ HRESULT STDMETHODCALLTYPE putref_EqnV( 
            /* [in] */ /* external definition not present */ _Collection __RPC_FAR *EqnV) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_EqnDV1( 
            /* [retval][out] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *EqnDV1) = 0;
        
        virtual /* [propputref][id] */ HRESULT STDMETHODCALLTYPE putref_EqnDV1( 
            /* [in] */ /* external definition not present */ _Collection __RPC_FAR *EqnDV1) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_EqnDV2( 
            /* [retval][out] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *EqnDV2) = 0;
        
        virtual /* [propputref][id] */ HRESULT STDMETHODCALLTYPE putref_EqnDV2( 
            /* [in] */ /* external definition not present */ _Collection __RPC_FAR *EqnDV2) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_EqnDV3( 
            /* [retval][out] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *EqnDV3) = 0;
        
        virtual /* [propputref][id] */ HRESULT STDMETHODCALLTYPE putref_EqnDV3( 
            /* [in] */ /* external definition not present */ _Collection __RPC_FAR *EqnDV3) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Destroy( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE EnableEvents( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE DisableEvents( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE init( 
            /* [out][in] */ long __RPC_FAR *nVars,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarOrder,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarNames,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *DerVals) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE InitStruct( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ReportStruct( 
            /* [out][in] */ long __RPC_FAR *der,
            /* [out][in] */ _clsVar __RPC_FAR *__RPC_FAR *var) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _clsVarManagerVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _clsVarManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _clsVarManager __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _clsVarManager __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _clsVarManager __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _clsVarManager __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _clsVarManager __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _clsVarManager __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_vars )( 
            _clsVarManager __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *vars);
        
        /* [propputref][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_vars )( 
            _clsVarManager __RPC_FAR * This,
            /* [in] */ /* external definition not present */ _Collection __RPC_FAR *vars);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_CVars )( 
            _clsVarManager __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *CVars);
        
        /* [propputref][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_CVars )( 
            _clsVarManager __RPC_FAR * This,
            /* [in] */ /* external definition not present */ _Collection __RPC_FAR *CVars);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_EqnV )( 
            _clsVarManager __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *EqnV);
        
        /* [propputref][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_EqnV )( 
            _clsVarManager __RPC_FAR * This,
            /* [in] */ /* external definition not present */ _Collection __RPC_FAR *EqnV);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_EqnDV1 )( 
            _clsVarManager __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *EqnDV1);
        
        /* [propputref][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_EqnDV1 )( 
            _clsVarManager __RPC_FAR * This,
            /* [in] */ /* external definition not present */ _Collection __RPC_FAR *EqnDV1);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_EqnDV2 )( 
            _clsVarManager __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *EqnDV2);
        
        /* [propputref][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_EqnDV2 )( 
            _clsVarManager __RPC_FAR * This,
            /* [in] */ /* external definition not present */ _Collection __RPC_FAR *EqnDV2);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_EqnDV3 )( 
            _clsVarManager __RPC_FAR * This,
            /* [retval][out] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *EqnDV3);
        
        /* [propputref][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_EqnDV3 )( 
            _clsVarManager __RPC_FAR * This,
            /* [in] */ /* external definition not present */ _Collection __RPC_FAR *EqnDV3);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Destroy )( 
            _clsVarManager __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EnableEvents )( 
            _clsVarManager __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *DisableEvents )( 
            _clsVarManager __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *init )( 
            _clsVarManager __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nVars,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarOrder,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarNames,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *DerVals);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitStruct )( 
            _clsVarManager __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ReportStruct )( 
            _clsVarManager __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *der,
            /* [out][in] */ _clsVar __RPC_FAR *__RPC_FAR *var);
        
        END_INTERFACE
    } _clsVarManagerVtbl;

    interface _clsVarManager
    {
        CONST_VTBL struct _clsVarManagerVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _clsVarManager_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _clsVarManager_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _clsVarManager_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _clsVarManager_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _clsVarManager_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _clsVarManager_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _clsVarManager_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define _clsVarManager_get_vars(This,vars)	\
    (This)->lpVtbl -> get_vars(This,vars)

#define _clsVarManager_putref_vars(This,vars)	\
    (This)->lpVtbl -> putref_vars(This,vars)

#define _clsVarManager_get_CVars(This,CVars)	\
    (This)->lpVtbl -> get_CVars(This,CVars)

#define _clsVarManager_putref_CVars(This,CVars)	\
    (This)->lpVtbl -> putref_CVars(This,CVars)

#define _clsVarManager_get_EqnV(This,EqnV)	\
    (This)->lpVtbl -> get_EqnV(This,EqnV)

#define _clsVarManager_putref_EqnV(This,EqnV)	\
    (This)->lpVtbl -> putref_EqnV(This,EqnV)

#define _clsVarManager_get_EqnDV1(This,EqnDV1)	\
    (This)->lpVtbl -> get_EqnDV1(This,EqnDV1)

#define _clsVarManager_putref_EqnDV1(This,EqnDV1)	\
    (This)->lpVtbl -> putref_EqnDV1(This,EqnDV1)

#define _clsVarManager_get_EqnDV2(This,EqnDV2)	\
    (This)->lpVtbl -> get_EqnDV2(This,EqnDV2)

#define _clsVarManager_putref_EqnDV2(This,EqnDV2)	\
    (This)->lpVtbl -> putref_EqnDV2(This,EqnDV2)

#define _clsVarManager_get_EqnDV3(This,EqnDV3)	\
    (This)->lpVtbl -> get_EqnDV3(This,EqnDV3)

#define _clsVarManager_putref_EqnDV3(This,EqnDV3)	\
    (This)->lpVtbl -> putref_EqnDV3(This,EqnDV3)

#define _clsVarManager_Destroy(This)	\
    (This)->lpVtbl -> Destroy(This)

#define _clsVarManager_EnableEvents(This)	\
    (This)->lpVtbl -> EnableEvents(This)

#define _clsVarManager_DisableEvents(This)	\
    (This)->lpVtbl -> DisableEvents(This)

#define _clsVarManager_init(This,nVars,VarOrder,VarNames,Vals,DerVals)	\
    (This)->lpVtbl -> init(This,nVars,VarOrder,VarNames,Vals,DerVals)

#define _clsVarManager_InitStruct(This)	\
    (This)->lpVtbl -> InitStruct(This)

#define _clsVarManager_ReportStruct(This,der,var)	\
    (This)->lpVtbl -> ReportStruct(This,der,var)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsVarManager_get_vars_Proxy( 
    _clsVarManager __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *vars);


void __RPC_STUB _clsVarManager_get_vars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propputref][id] */ HRESULT STDMETHODCALLTYPE _clsVarManager_putref_vars_Proxy( 
    _clsVarManager __RPC_FAR * This,
    /* [in] */ /* external definition not present */ _Collection __RPC_FAR *vars);


void __RPC_STUB _clsVarManager_putref_vars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsVarManager_get_CVars_Proxy( 
    _clsVarManager __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *CVars);


void __RPC_STUB _clsVarManager_get_CVars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propputref][id] */ HRESULT STDMETHODCALLTYPE _clsVarManager_putref_CVars_Proxy( 
    _clsVarManager __RPC_FAR * This,
    /* [in] */ /* external definition not present */ _Collection __RPC_FAR *CVars);


void __RPC_STUB _clsVarManager_putref_CVars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsVarManager_get_EqnV_Proxy( 
    _clsVarManager __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *EqnV);


void __RPC_STUB _clsVarManager_get_EqnV_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propputref][id] */ HRESULT STDMETHODCALLTYPE _clsVarManager_putref_EqnV_Proxy( 
    _clsVarManager __RPC_FAR * This,
    /* [in] */ /* external definition not present */ _Collection __RPC_FAR *EqnV);


void __RPC_STUB _clsVarManager_putref_EqnV_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsVarManager_get_EqnDV1_Proxy( 
    _clsVarManager __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *EqnDV1);


void __RPC_STUB _clsVarManager_get_EqnDV1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propputref][id] */ HRESULT STDMETHODCALLTYPE _clsVarManager_putref_EqnDV1_Proxy( 
    _clsVarManager __RPC_FAR * This,
    /* [in] */ /* external definition not present */ _Collection __RPC_FAR *EqnDV1);


void __RPC_STUB _clsVarManager_putref_EqnDV1_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsVarManager_get_EqnDV2_Proxy( 
    _clsVarManager __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *EqnDV2);


void __RPC_STUB _clsVarManager_get_EqnDV2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propputref][id] */ HRESULT STDMETHODCALLTYPE _clsVarManager_putref_EqnDV2_Proxy( 
    _clsVarManager __RPC_FAR * This,
    /* [in] */ /* external definition not present */ _Collection __RPC_FAR *EqnDV2);


void __RPC_STUB _clsVarManager_putref_EqnDV2_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _clsVarManager_get_EqnDV3_Proxy( 
    _clsVarManager __RPC_FAR * This,
    /* [retval][out] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *EqnDV3);


void __RPC_STUB _clsVarManager_get_EqnDV3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propputref][id] */ HRESULT STDMETHODCALLTYPE _clsVarManager_putref_EqnDV3_Proxy( 
    _clsVarManager __RPC_FAR * This,
    /* [in] */ /* external definition not present */ _Collection __RPC_FAR *EqnDV3);


void __RPC_STUB _clsVarManager_putref_EqnDV3_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsVarManager_Destroy_Proxy( 
    _clsVarManager __RPC_FAR * This);


void __RPC_STUB _clsVarManager_Destroy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsVarManager_EnableEvents_Proxy( 
    _clsVarManager __RPC_FAR * This);


void __RPC_STUB _clsVarManager_EnableEvents_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsVarManager_DisableEvents_Proxy( 
    _clsVarManager __RPC_FAR * This);


void __RPC_STUB _clsVarManager_DisableEvents_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsVarManager_init_Proxy( 
    _clsVarManager __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nVars,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarOrder,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarNames,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *DerVals);


void __RPC_STUB _clsVarManager_init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsVarManager_InitStruct_Proxy( 
    _clsVarManager __RPC_FAR * This);


void __RPC_STUB _clsVarManager_InitStruct_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _clsVarManager_ReportStruct_Proxy( 
    _clsVarManager __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *der,
    /* [out][in] */ _clsVar __RPC_FAR *__RPC_FAR *var);


void __RPC_STUB _clsVarManager_ReportStruct_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* ___clsVarManager_INTERFACE_DEFINED__ */


#ifndef ___ctlEquationEditor_INTERFACE_DEFINED__
#define ___ctlEquationEditor_INTERFACE_DEFINED__

/* interface _ctlEquationEditor */
/* [object][oleautomation][nonextensible][dual][hidden][version][uuid] */ 


EXTERN_C const IID IID__ctlEquationEditor;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("4ACDF901-8C5E-4F8B-8FFD-AFDF5509C45D")
    _ctlEquationEditor : public IDispatch
    {
    public:
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_GridIndex( 
            /* [retval][out] */ long __RPC_FAR *GridIndex) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_GridIndex( 
            /* [in] */ long GridIndex) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_EqnIndex( 
            /* [retval][out] */ long __RPC_FAR *EqnIndex) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_EqnIndex( 
            /* [in] */ long EqnIndex) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_eqnName( 
            /* [retval][out] */ BSTR __RPC_FAR *eqnName) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_eqnName( 
            /* [in] */ BSTR eqnName) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE init( 
            /* [out][in] */ _OnScriptParser __RPC_FAR *__RPC_FAR *sp,
            /* [out][in] */ _clsVarManager __RPC_FAR *__RPC_FAR *vm,
            /* [out][in] */ _ctlMessageWindow __RPC_FAR *__RPC_FAR *st) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Destroy( void) = 0;
        
        virtual /* [propput][id] */ HRESULT STDMETHODCALLTYPE put_EqnBody( 
            /* [out][in] */ BSTR __RPC_FAR *__MIDL_0021) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_EqnBody( 
            /* [retval][out] */ BSTR __RPC_FAR *__MIDL_0022) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Fmt( 
            /* [out][in] */ BSTR __RPC_FAR *VIn,
            /* [retval][out] */ BSTR __RPC_FAR *__MIDL_0023) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _ctlEquationEditorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _ctlEquationEditor __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _ctlEquationEditor __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _ctlEquationEditor __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _ctlEquationEditor __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _ctlEquationEditor __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _ctlEquationEditor __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _ctlEquationEditor __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_GridIndex )( 
            _ctlEquationEditor __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *GridIndex);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_GridIndex )( 
            _ctlEquationEditor __RPC_FAR * This,
            /* [in] */ long GridIndex);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_EqnIndex )( 
            _ctlEquationEditor __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *EqnIndex);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_EqnIndex )( 
            _ctlEquationEditor __RPC_FAR * This,
            /* [in] */ long EqnIndex);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_eqnName )( 
            _ctlEquationEditor __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *eqnName);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_eqnName )( 
            _ctlEquationEditor __RPC_FAR * This,
            /* [in] */ BSTR eqnName);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *init )( 
            _ctlEquationEditor __RPC_FAR * This,
            /* [out][in] */ _OnScriptParser __RPC_FAR *__RPC_FAR *sp,
            /* [out][in] */ _clsVarManager __RPC_FAR *__RPC_FAR *vm,
            /* [out][in] */ _ctlMessageWindow __RPC_FAR *__RPC_FAR *st);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Destroy )( 
            _ctlEquationEditor __RPC_FAR * This);
        
        /* [propput][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_EqnBody )( 
            _ctlEquationEditor __RPC_FAR * This,
            /* [out][in] */ BSTR __RPC_FAR *__MIDL_0021);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_EqnBody )( 
            _ctlEquationEditor __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *__MIDL_0022);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Fmt )( 
            _ctlEquationEditor __RPC_FAR * This,
            /* [out][in] */ BSTR __RPC_FAR *VIn,
            /* [retval][out] */ BSTR __RPC_FAR *__MIDL_0023);
        
        END_INTERFACE
    } _ctlEquationEditorVtbl;

    interface _ctlEquationEditor
    {
        CONST_VTBL struct _ctlEquationEditorVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ctlEquationEditor_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _ctlEquationEditor_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _ctlEquationEditor_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _ctlEquationEditor_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _ctlEquationEditor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _ctlEquationEditor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _ctlEquationEditor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define _ctlEquationEditor_get_GridIndex(This,GridIndex)	\
    (This)->lpVtbl -> get_GridIndex(This,GridIndex)

#define _ctlEquationEditor_put_GridIndex(This,GridIndex)	\
    (This)->lpVtbl -> put_GridIndex(This,GridIndex)

#define _ctlEquationEditor_get_EqnIndex(This,EqnIndex)	\
    (This)->lpVtbl -> get_EqnIndex(This,EqnIndex)

#define _ctlEquationEditor_put_EqnIndex(This,EqnIndex)	\
    (This)->lpVtbl -> put_EqnIndex(This,EqnIndex)

#define _ctlEquationEditor_get_eqnName(This,eqnName)	\
    (This)->lpVtbl -> get_eqnName(This,eqnName)

#define _ctlEquationEditor_put_eqnName(This,eqnName)	\
    (This)->lpVtbl -> put_eqnName(This,eqnName)

#define _ctlEquationEditor_init(This,sp,vm,st)	\
    (This)->lpVtbl -> init(This,sp,vm,st)

#define _ctlEquationEditor_Destroy(This)	\
    (This)->lpVtbl -> Destroy(This)

#define _ctlEquationEditor_put_EqnBody(This,__MIDL_0021)	\
    (This)->lpVtbl -> put_EqnBody(This,__MIDL_0021)

#define _ctlEquationEditor_get_EqnBody(This,__MIDL_0022)	\
    (This)->lpVtbl -> get_EqnBody(This,__MIDL_0022)

#define _ctlEquationEditor_Fmt(This,VIn,__MIDL_0023)	\
    (This)->lpVtbl -> Fmt(This,VIn,__MIDL_0023)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [propget][id] */ HRESULT STDMETHODCALLTYPE _ctlEquationEditor_get_GridIndex_Proxy( 
    _ctlEquationEditor __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *GridIndex);


void __RPC_STUB _ctlEquationEditor_get_GridIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _ctlEquationEditor_put_GridIndex_Proxy( 
    _ctlEquationEditor __RPC_FAR * This,
    /* [in] */ long GridIndex);


void __RPC_STUB _ctlEquationEditor_put_GridIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _ctlEquationEditor_get_EqnIndex_Proxy( 
    _ctlEquationEditor __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *EqnIndex);


void __RPC_STUB _ctlEquationEditor_get_EqnIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _ctlEquationEditor_put_EqnIndex_Proxy( 
    _ctlEquationEditor __RPC_FAR * This,
    /* [in] */ long EqnIndex);


void __RPC_STUB _ctlEquationEditor_put_EqnIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _ctlEquationEditor_get_eqnName_Proxy( 
    _ctlEquationEditor __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *eqnName);


void __RPC_STUB _ctlEquationEditor_get_eqnName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _ctlEquationEditor_put_eqnName_Proxy( 
    _ctlEquationEditor __RPC_FAR * This,
    /* [in] */ BSTR eqnName);


void __RPC_STUB _ctlEquationEditor_put_eqnName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _ctlEquationEditor_init_Proxy( 
    _ctlEquationEditor __RPC_FAR * This,
    /* [out][in] */ _OnScriptParser __RPC_FAR *__RPC_FAR *sp,
    /* [out][in] */ _clsVarManager __RPC_FAR *__RPC_FAR *vm,
    /* [out][in] */ _ctlMessageWindow __RPC_FAR *__RPC_FAR *st);


void __RPC_STUB _ctlEquationEditor_init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _ctlEquationEditor_Destroy_Proxy( 
    _ctlEquationEditor __RPC_FAR * This);


void __RPC_STUB _ctlEquationEditor_Destroy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propput][id] */ HRESULT STDMETHODCALLTYPE _ctlEquationEditor_put_EqnBody_Proxy( 
    _ctlEquationEditor __RPC_FAR * This,
    /* [out][in] */ BSTR __RPC_FAR *__MIDL_0021);


void __RPC_STUB _ctlEquationEditor_put_EqnBody_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _ctlEquationEditor_get_EqnBody_Proxy( 
    _ctlEquationEditor __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *__MIDL_0022);


void __RPC_STUB _ctlEquationEditor_get_EqnBody_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _ctlEquationEditor_Fmt_Proxy( 
    _ctlEquationEditor __RPC_FAR * This,
    /* [out][in] */ BSTR __RPC_FAR *VIn,
    /* [retval][out] */ BSTR __RPC_FAR *__MIDL_0023);


void __RPC_STUB _ctlEquationEditor_Fmt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* ___ctlEquationEditor_INTERFACE_DEFINED__ */


#ifndef ___ctlMessageWindow_INTERFACE_DEFINED__
#define ___ctlMessageWindow_INTERFACE_DEFINED__

/* interface _ctlMessageWindow */
/* [object][oleautomation][nonextensible][dual][hidden][version][uuid] */ 


EXTERN_C const IID IID__ctlMessageWindow;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C9A0A35F-4543-433B-9FD2-EE99D985AEA3")
    _ctlMessageWindow : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Destroy( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE LogMessage( 
            /* [out][in] */ BSTR __RPC_FAR *strMsg) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ClearMessageWindow( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE MaximizeMessageWindow( 
            /* [out][in] */ short __RPC_FAR *ucHeight,
            /* [out][in] */ short __RPC_FAR *ucWidth) = 0;
        
        virtual /* [propputref][id] */ HRESULT STDMETHODCALLTYPE putref_ActiveForm( 
            /* [out][in] */ IDispatch __RPC_FAR *__RPC_FAR *rhs) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _ctlMessageWindowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _ctlMessageWindow __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _ctlMessageWindow __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _ctlMessageWindow __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _ctlMessageWindow __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _ctlMessageWindow __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _ctlMessageWindow __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _ctlMessageWindow __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Destroy )( 
            _ctlMessageWindow __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *LogMessage )( 
            _ctlMessageWindow __RPC_FAR * This,
            /* [out][in] */ BSTR __RPC_FAR *strMsg);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ClearMessageWindow )( 
            _ctlMessageWindow __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *MaximizeMessageWindow )( 
            _ctlMessageWindow __RPC_FAR * This,
            /* [out][in] */ short __RPC_FAR *ucHeight,
            /* [out][in] */ short __RPC_FAR *ucWidth);
        
        /* [propputref][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *putref_ActiveForm )( 
            _ctlMessageWindow __RPC_FAR * This,
            /* [out][in] */ IDispatch __RPC_FAR *__RPC_FAR *rhs);
        
        END_INTERFACE
    } _ctlMessageWindowVtbl;

    interface _ctlMessageWindow
    {
        CONST_VTBL struct _ctlMessageWindowVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _ctlMessageWindow_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _ctlMessageWindow_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _ctlMessageWindow_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _ctlMessageWindow_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _ctlMessageWindow_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _ctlMessageWindow_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _ctlMessageWindow_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define _ctlMessageWindow_Destroy(This)	\
    (This)->lpVtbl -> Destroy(This)

#define _ctlMessageWindow_LogMessage(This,strMsg)	\
    (This)->lpVtbl -> LogMessage(This,strMsg)

#define _ctlMessageWindow_ClearMessageWindow(This)	\
    (This)->lpVtbl -> ClearMessageWindow(This)

#define _ctlMessageWindow_MaximizeMessageWindow(This,ucHeight,ucWidth)	\
    (This)->lpVtbl -> MaximizeMessageWindow(This,ucHeight,ucWidth)

#define _ctlMessageWindow_putref_ActiveForm(This,rhs)	\
    (This)->lpVtbl -> putref_ActiveForm(This,rhs)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE _ctlMessageWindow_Destroy_Proxy( 
    _ctlMessageWindow __RPC_FAR * This);


void __RPC_STUB _ctlMessageWindow_Destroy_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _ctlMessageWindow_LogMessage_Proxy( 
    _ctlMessageWindow __RPC_FAR * This,
    /* [out][in] */ BSTR __RPC_FAR *strMsg);


void __RPC_STUB _ctlMessageWindow_LogMessage_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _ctlMessageWindow_ClearMessageWindow_Proxy( 
    _ctlMessageWindow __RPC_FAR * This);


void __RPC_STUB _ctlMessageWindow_ClearMessageWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _ctlMessageWindow_MaximizeMessageWindow_Proxy( 
    _ctlMessageWindow __RPC_FAR * This,
    /* [out][in] */ short __RPC_FAR *ucHeight,
    /* [out][in] */ short __RPC_FAR *ucWidth);


void __RPC_STUB _ctlMessageWindow_MaximizeMessageWindow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propputref][id] */ HRESULT STDMETHODCALLTYPE _ctlMessageWindow_putref_ActiveForm_Proxy( 
    _ctlMessageWindow __RPC_FAR * This,
    /* [out][in] */ IDispatch __RPC_FAR *__RPC_FAR *rhs);


void __RPC_STUB _ctlMessageWindow_putref_ActiveForm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* ___ctlMessageWindow_INTERFACE_DEFINED__ */


#ifndef ___OnScriptParser_INTERFACE_DEFINED__
#define ___OnScriptParser_INTERFACE_DEFINED__

/* interface _OnScriptParser */
/* [object][oleautomation][nonextensible][dual][hidden][version][uuid] */ 


EXTERN_C const IID IID__OnScriptParser;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("388305A9-A31C-4D2E-BAC8-52D6AF9F9D26")
    _OnScriptParser : public IDispatch
    {
    public:
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetModelExec( 
            /* [out][in] */ /* external definition not present */ IOnModelExec __RPC_FAR *__RPC_FAR *pModelExec) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_nVars( 
            /* [retval][out] */ long __RPC_FAR *__MIDL_0024) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_nEqns( 
            /* [retval][out] */ long __RPC_FAR *__MIDL_0025) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_nModelVars( 
            /* [retval][out] */ long __RPC_FAR *__MIDL_0026) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_nModelEqns( 
            /* [retval][out] */ long __RPC_FAR *__MIDL_0027) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_nActiveEqns( 
            /* [retval][out] */ long __RPC_FAR *__MIDL_0028) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_nActiveVars( 
            /* [retval][out] */ long __RPC_FAR *__MIDL_0029) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_VarOrder( 
            /* [out][in] */ long __RPC_FAR *iActiveVar,
            /* [retval][out] */ long __RPC_FAR *__MIDL_0030) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_EqnOrder( 
            /* [out][in] */ long __RPC_FAR *iActiveEqn,
            /* [retval][out] */ long __RPC_FAR *__MIDL_0031) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_itVarOrder( 
            /* [out][in] */ long __RPC_FAR *iVar,
            /* [retval][out] */ long __RPC_FAR *__MIDL_0032) = 0;
        
        virtual /* [propget][id] */ HRESULT STDMETHODCALLTYPE get_itEqnOrder( 
            /* [out][in] */ long __RPC_FAR *iEqn,
            /* [retval][out] */ long __RPC_FAR *__MIDL_0033) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE ShowDialog( void) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetScripts( 
            /* [out][in] */ long __RPC_FAR *nScripts,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *AssignedVars,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptNames,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptVars,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptResiduals,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptBodies,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptVarCount) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE SetTrimVars( 
            /* [out][in] */ long __RPC_FAR *nTrimVars,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TrimVars,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TrimVarVals) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetScripts( 
            /* [out][in] */ long __RPC_FAR *nScripts,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *AssignedVars,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptNames,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptVars,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptResiduals,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptBodies,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptVarCount) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetTrimVars( 
            /* [out][in] */ long __RPC_FAR *nTrimVars,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TrimVars,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TrimVarVals) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE eqnName( 
            /* [out][in] */ long __RPC_FAR *iEqn,
            /* [retval][out] */ BSTR __RPC_FAR *__MIDL_0034) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE VarName( 
            /* [out][in] */ long __RPC_FAR *iVar,
            /* [retval][out] */ BSTR __RPC_FAR *__MIDL_0035) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE initModelVar( 
            /* [out][in] */ long __RPC_FAR *iActiveVar,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *bActive,
            /* [out][in] */ long __RPC_FAR *aIndex,
            /* [out][in] */ BSTR __RPC_FAR *aAssignedEqn,
            /* [out][in] */ BSTR __RPC_FAR *aName,
            /* [out][in] */ long __RPC_FAR *aDER,
            /* [out][in] */ double __RPC_FAR *aValue) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE initModelEqn( 
            /* [out][in] */ long __RPC_FAR *iActiveEqn,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *bActive,
            /* [out][in] */ long __RPC_FAR *aIndex,
            /* [out][in] */ BSTR __RPC_FAR *aAssignedVar,
            /* [out][in] */ BSTR __RPC_FAR *aName,
            /* [out][in] */ BSTR __RPC_FAR *aVars,
            /* [out][in] */ double __RPC_FAR *aResidual) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Test( 
            /* [out][in] */ BSTR __RPC_FAR *sName,
            /* [out][in] */ BSTR __RPC_FAR *sScript,
            /* [out][in] */ BSTR __RPC_FAR *sFinalScript,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *bErr,
            /* [out][in] */ double __RPC_FAR *retVal,
            /* [out][in] */ long __RPC_FAR *errLine,
            /* [out][in] */ long __RPC_FAR *errCol,
            /* [out][in] */ BSTR __RPC_FAR *errDesc,
            /* [out][in] */ BSTR __RPC_FAR *errText) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Eval( 
            /* [out][in] */ BSTR __RPC_FAR *eqnName,
            /* [out][in] */ BSTR __RPC_FAR *script,
            /* [out][in] */ BSTR __RPC_FAR *finalScript,
            /* [retval][out] */ double __RPC_FAR *__MIDL_0036) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE GetEqnStruct( 
            /* [out][in] */ BSTR __RPC_FAR *script,
            /* [out][in] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *v,
            /* [out][in] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *dv1,
            /* [out][in] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *dv2,
            /* [out][in] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *dv3,
            /* [out][in] */ double __RPC_FAR *result) = 0;
        
        virtual /* [id] */ HRESULT STDMETHODCALLTYPE Fmt( 
            /* [out][in] */ BSTR __RPC_FAR *VIn,
            /* [retval][out] */ BSTR __RPC_FAR *__MIDL_0037) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct _OnScriptParserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _OnScriptParser __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _OnScriptParser __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _OnScriptParser __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _OnScriptParser __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _OnScriptParser __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _OnScriptParser __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _OnScriptParser __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetModelExec )( 
            _OnScriptParser __RPC_FAR * This,
            /* [out][in] */ /* external definition not present */ IOnModelExec __RPC_FAR *__RPC_FAR *pModelExec);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_nVars )( 
            _OnScriptParser __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *__MIDL_0024);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_nEqns )( 
            _OnScriptParser __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *__MIDL_0025);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_nModelVars )( 
            _OnScriptParser __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *__MIDL_0026);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_nModelEqns )( 
            _OnScriptParser __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *__MIDL_0027);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_nActiveEqns )( 
            _OnScriptParser __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *__MIDL_0028);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_nActiveVars )( 
            _OnScriptParser __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *__MIDL_0029);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_VarOrder )( 
            _OnScriptParser __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *iActiveVar,
            /* [retval][out] */ long __RPC_FAR *__MIDL_0030);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_EqnOrder )( 
            _OnScriptParser __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *iActiveEqn,
            /* [retval][out] */ long __RPC_FAR *__MIDL_0031);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_itVarOrder )( 
            _OnScriptParser __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *iVar,
            /* [retval][out] */ long __RPC_FAR *__MIDL_0032);
        
        /* [propget][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_itEqnOrder )( 
            _OnScriptParser __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *iEqn,
            /* [retval][out] */ long __RPC_FAR *__MIDL_0033);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowDialog )( 
            _OnScriptParser __RPC_FAR * This);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetScripts )( 
            _OnScriptParser __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nScripts,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *AssignedVars,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptNames,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptVars,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptResiduals,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptBodies,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptVarCount);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTrimVars )( 
            _OnScriptParser __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nTrimVars,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TrimVars,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TrimVarVals);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetScripts )( 
            _OnScriptParser __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nScripts,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *AssignedVars,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptNames,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptVars,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptResiduals,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptBodies,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptVarCount);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTrimVars )( 
            _OnScriptParser __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nTrimVars,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TrimVars,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TrimVarVals);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *eqnName )( 
            _OnScriptParser __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *iEqn,
            /* [retval][out] */ BSTR __RPC_FAR *__MIDL_0034);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *VarName )( 
            _OnScriptParser __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *iVar,
            /* [retval][out] */ BSTR __RPC_FAR *__MIDL_0035);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *initModelVar )( 
            _OnScriptParser __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *iActiveVar,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *bActive,
            /* [out][in] */ long __RPC_FAR *aIndex,
            /* [out][in] */ BSTR __RPC_FAR *aAssignedEqn,
            /* [out][in] */ BSTR __RPC_FAR *aName,
            /* [out][in] */ long __RPC_FAR *aDER,
            /* [out][in] */ double __RPC_FAR *aValue);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *initModelEqn )( 
            _OnScriptParser __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *iActiveEqn,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *bActive,
            /* [out][in] */ long __RPC_FAR *aIndex,
            /* [out][in] */ BSTR __RPC_FAR *aAssignedVar,
            /* [out][in] */ BSTR __RPC_FAR *aName,
            /* [out][in] */ BSTR __RPC_FAR *aVars,
            /* [out][in] */ double __RPC_FAR *aResidual);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Test )( 
            _OnScriptParser __RPC_FAR * This,
            /* [out][in] */ BSTR __RPC_FAR *sName,
            /* [out][in] */ BSTR __RPC_FAR *sScript,
            /* [out][in] */ BSTR __RPC_FAR *sFinalScript,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *bErr,
            /* [out][in] */ double __RPC_FAR *retVal,
            /* [out][in] */ long __RPC_FAR *errLine,
            /* [out][in] */ long __RPC_FAR *errCol,
            /* [out][in] */ BSTR __RPC_FAR *errDesc,
            /* [out][in] */ BSTR __RPC_FAR *errText);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Eval )( 
            _OnScriptParser __RPC_FAR * This,
            /* [out][in] */ BSTR __RPC_FAR *eqnName,
            /* [out][in] */ BSTR __RPC_FAR *script,
            /* [out][in] */ BSTR __RPC_FAR *finalScript,
            /* [retval][out] */ double __RPC_FAR *__MIDL_0036);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEqnStruct )( 
            _OnScriptParser __RPC_FAR * This,
            /* [out][in] */ BSTR __RPC_FAR *script,
            /* [out][in] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *v,
            /* [out][in] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *dv1,
            /* [out][in] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *dv2,
            /* [out][in] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *dv3,
            /* [out][in] */ double __RPC_FAR *result);
        
        /* [id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Fmt )( 
            _OnScriptParser __RPC_FAR * This,
            /* [out][in] */ BSTR __RPC_FAR *VIn,
            /* [retval][out] */ BSTR __RPC_FAR *__MIDL_0037);
        
        END_INTERFACE
    } _OnScriptParserVtbl;

    interface _OnScriptParser
    {
        CONST_VTBL struct _OnScriptParserVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _OnScriptParser_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _OnScriptParser_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _OnScriptParser_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _OnScriptParser_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _OnScriptParser_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _OnScriptParser_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _OnScriptParser_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define _OnScriptParser_SetModelExec(This,pModelExec)	\
    (This)->lpVtbl -> SetModelExec(This,pModelExec)

#define _OnScriptParser_get_nVars(This,__MIDL_0024)	\
    (This)->lpVtbl -> get_nVars(This,__MIDL_0024)

#define _OnScriptParser_get_nEqns(This,__MIDL_0025)	\
    (This)->lpVtbl -> get_nEqns(This,__MIDL_0025)

#define _OnScriptParser_get_nModelVars(This,__MIDL_0026)	\
    (This)->lpVtbl -> get_nModelVars(This,__MIDL_0026)

#define _OnScriptParser_get_nModelEqns(This,__MIDL_0027)	\
    (This)->lpVtbl -> get_nModelEqns(This,__MIDL_0027)

#define _OnScriptParser_get_nActiveEqns(This,__MIDL_0028)	\
    (This)->lpVtbl -> get_nActiveEqns(This,__MIDL_0028)

#define _OnScriptParser_get_nActiveVars(This,__MIDL_0029)	\
    (This)->lpVtbl -> get_nActiveVars(This,__MIDL_0029)

#define _OnScriptParser_get_VarOrder(This,iActiveVar,__MIDL_0030)	\
    (This)->lpVtbl -> get_VarOrder(This,iActiveVar,__MIDL_0030)

#define _OnScriptParser_get_EqnOrder(This,iActiveEqn,__MIDL_0031)	\
    (This)->lpVtbl -> get_EqnOrder(This,iActiveEqn,__MIDL_0031)

#define _OnScriptParser_get_itVarOrder(This,iVar,__MIDL_0032)	\
    (This)->lpVtbl -> get_itVarOrder(This,iVar,__MIDL_0032)

#define _OnScriptParser_get_itEqnOrder(This,iEqn,__MIDL_0033)	\
    (This)->lpVtbl -> get_itEqnOrder(This,iEqn,__MIDL_0033)

#define _OnScriptParser_ShowDialog(This)	\
    (This)->lpVtbl -> ShowDialog(This)

#define _OnScriptParser_SetScripts(This,nScripts,AssignedVars,ScriptNames,ScriptVars,ScriptResiduals,ScriptBodies,ScriptVarCount)	\
    (This)->lpVtbl -> SetScripts(This,nScripts,AssignedVars,ScriptNames,ScriptVars,ScriptResiduals,ScriptBodies,ScriptVarCount)

#define _OnScriptParser_SetTrimVars(This,nTrimVars,TrimVars,TrimVarVals)	\
    (This)->lpVtbl -> SetTrimVars(This,nTrimVars,TrimVars,TrimVarVals)

#define _OnScriptParser_GetScripts(This,nScripts,AssignedVars,ScriptNames,ScriptVars,ScriptResiduals,ScriptBodies,ScriptVarCount)	\
    (This)->lpVtbl -> GetScripts(This,nScripts,AssignedVars,ScriptNames,ScriptVars,ScriptResiduals,ScriptBodies,ScriptVarCount)

#define _OnScriptParser_GetTrimVars(This,nTrimVars,TrimVars,TrimVarVals)	\
    (This)->lpVtbl -> GetTrimVars(This,nTrimVars,TrimVars,TrimVarVals)

#define _OnScriptParser_eqnName(This,iEqn,__MIDL_0034)	\
    (This)->lpVtbl -> eqnName(This,iEqn,__MIDL_0034)

#define _OnScriptParser_VarName(This,iVar,__MIDL_0035)	\
    (This)->lpVtbl -> VarName(This,iVar,__MIDL_0035)

#define _OnScriptParser_initModelVar(This,iActiveVar,bActive,aIndex,aAssignedEqn,aName,aDER,aValue)	\
    (This)->lpVtbl -> initModelVar(This,iActiveVar,bActive,aIndex,aAssignedEqn,aName,aDER,aValue)

#define _OnScriptParser_initModelEqn(This,iActiveEqn,bActive,aIndex,aAssignedVar,aName,aVars,aResidual)	\
    (This)->lpVtbl -> initModelEqn(This,iActiveEqn,bActive,aIndex,aAssignedVar,aName,aVars,aResidual)

#define _OnScriptParser_Test(This,sName,sScript,sFinalScript,bErr,retVal,errLine,errCol,errDesc,errText)	\
    (This)->lpVtbl -> Test(This,sName,sScript,sFinalScript,bErr,retVal,errLine,errCol,errDesc,errText)

#define _OnScriptParser_Eval(This,eqnName,script,finalScript,__MIDL_0036)	\
    (This)->lpVtbl -> Eval(This,eqnName,script,finalScript,__MIDL_0036)

#define _OnScriptParser_GetEqnStruct(This,script,v,dv1,dv2,dv3,result)	\
    (This)->lpVtbl -> GetEqnStruct(This,script,v,dv1,dv2,dv3,result)

#define _OnScriptParser_Fmt(This,VIn,__MIDL_0037)	\
    (This)->lpVtbl -> Fmt(This,VIn,__MIDL_0037)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [id] */ HRESULT STDMETHODCALLTYPE _OnScriptParser_SetModelExec_Proxy( 
    _OnScriptParser __RPC_FAR * This,
    /* [out][in] */ /* external definition not present */ IOnModelExec __RPC_FAR *__RPC_FAR *pModelExec);


void __RPC_STUB _OnScriptParser_SetModelExec_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _OnScriptParser_get_nVars_Proxy( 
    _OnScriptParser __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *__MIDL_0024);


void __RPC_STUB _OnScriptParser_get_nVars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _OnScriptParser_get_nEqns_Proxy( 
    _OnScriptParser __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *__MIDL_0025);


void __RPC_STUB _OnScriptParser_get_nEqns_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _OnScriptParser_get_nModelVars_Proxy( 
    _OnScriptParser __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *__MIDL_0026);


void __RPC_STUB _OnScriptParser_get_nModelVars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _OnScriptParser_get_nModelEqns_Proxy( 
    _OnScriptParser __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *__MIDL_0027);


void __RPC_STUB _OnScriptParser_get_nModelEqns_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _OnScriptParser_get_nActiveEqns_Proxy( 
    _OnScriptParser __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *__MIDL_0028);


void __RPC_STUB _OnScriptParser_get_nActiveEqns_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _OnScriptParser_get_nActiveVars_Proxy( 
    _OnScriptParser __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *__MIDL_0029);


void __RPC_STUB _OnScriptParser_get_nActiveVars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _OnScriptParser_get_VarOrder_Proxy( 
    _OnScriptParser __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *iActiveVar,
    /* [retval][out] */ long __RPC_FAR *__MIDL_0030);


void __RPC_STUB _OnScriptParser_get_VarOrder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _OnScriptParser_get_EqnOrder_Proxy( 
    _OnScriptParser __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *iActiveEqn,
    /* [retval][out] */ long __RPC_FAR *__MIDL_0031);


void __RPC_STUB _OnScriptParser_get_EqnOrder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _OnScriptParser_get_itVarOrder_Proxy( 
    _OnScriptParser __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *iVar,
    /* [retval][out] */ long __RPC_FAR *__MIDL_0032);


void __RPC_STUB _OnScriptParser_get_itVarOrder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [propget][id] */ HRESULT STDMETHODCALLTYPE _OnScriptParser_get_itEqnOrder_Proxy( 
    _OnScriptParser __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *iEqn,
    /* [retval][out] */ long __RPC_FAR *__MIDL_0033);


void __RPC_STUB _OnScriptParser_get_itEqnOrder_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _OnScriptParser_ShowDialog_Proxy( 
    _OnScriptParser __RPC_FAR * This);


void __RPC_STUB _OnScriptParser_ShowDialog_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _OnScriptParser_SetScripts_Proxy( 
    _OnScriptParser __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nScripts,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *AssignedVars,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptNames,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptVars,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptResiduals,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptBodies,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptVarCount);


void __RPC_STUB _OnScriptParser_SetScripts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _OnScriptParser_SetTrimVars_Proxy( 
    _OnScriptParser __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nTrimVars,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TrimVars,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TrimVarVals);


void __RPC_STUB _OnScriptParser_SetTrimVars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _OnScriptParser_GetScripts_Proxy( 
    _OnScriptParser __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nScripts,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *AssignedVars,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptNames,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptVars,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptResiduals,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptBodies,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ScriptVarCount);


void __RPC_STUB _OnScriptParser_GetScripts_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _OnScriptParser_GetTrimVars_Proxy( 
    _OnScriptParser __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nTrimVars,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TrimVars,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TrimVarVals);


void __RPC_STUB _OnScriptParser_GetTrimVars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _OnScriptParser_eqnName_Proxy( 
    _OnScriptParser __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *iEqn,
    /* [retval][out] */ BSTR __RPC_FAR *__MIDL_0034);


void __RPC_STUB _OnScriptParser_eqnName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _OnScriptParser_VarName_Proxy( 
    _OnScriptParser __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *iVar,
    /* [retval][out] */ BSTR __RPC_FAR *__MIDL_0035);


void __RPC_STUB _OnScriptParser_VarName_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _OnScriptParser_initModelVar_Proxy( 
    _OnScriptParser __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *iActiveVar,
    /* [out][in] */ VARIANT_BOOL __RPC_FAR *bActive,
    /* [out][in] */ long __RPC_FAR *aIndex,
    /* [out][in] */ BSTR __RPC_FAR *aAssignedEqn,
    /* [out][in] */ BSTR __RPC_FAR *aName,
    /* [out][in] */ long __RPC_FAR *aDER,
    /* [out][in] */ double __RPC_FAR *aValue);


void __RPC_STUB _OnScriptParser_initModelVar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _OnScriptParser_initModelEqn_Proxy( 
    _OnScriptParser __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *iActiveEqn,
    /* [out][in] */ VARIANT_BOOL __RPC_FAR *bActive,
    /* [out][in] */ long __RPC_FAR *aIndex,
    /* [out][in] */ BSTR __RPC_FAR *aAssignedVar,
    /* [out][in] */ BSTR __RPC_FAR *aName,
    /* [out][in] */ BSTR __RPC_FAR *aVars,
    /* [out][in] */ double __RPC_FAR *aResidual);


void __RPC_STUB _OnScriptParser_initModelEqn_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _OnScriptParser_Test_Proxy( 
    _OnScriptParser __RPC_FAR * This,
    /* [out][in] */ BSTR __RPC_FAR *sName,
    /* [out][in] */ BSTR __RPC_FAR *sScript,
    /* [out][in] */ BSTR __RPC_FAR *sFinalScript,
    /* [out][in] */ VARIANT_BOOL __RPC_FAR *bErr,
    /* [out][in] */ double __RPC_FAR *retVal,
    /* [out][in] */ long __RPC_FAR *errLine,
    /* [out][in] */ long __RPC_FAR *errCol,
    /* [out][in] */ BSTR __RPC_FAR *errDesc,
    /* [out][in] */ BSTR __RPC_FAR *errText);


void __RPC_STUB _OnScriptParser_Test_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _OnScriptParser_Eval_Proxy( 
    _OnScriptParser __RPC_FAR * This,
    /* [out][in] */ BSTR __RPC_FAR *eqnName,
    /* [out][in] */ BSTR __RPC_FAR *script,
    /* [out][in] */ BSTR __RPC_FAR *finalScript,
    /* [retval][out] */ double __RPC_FAR *__MIDL_0036);


void __RPC_STUB _OnScriptParser_Eval_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _OnScriptParser_GetEqnStruct_Proxy( 
    _OnScriptParser __RPC_FAR * This,
    /* [out][in] */ BSTR __RPC_FAR *script,
    /* [out][in] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *v,
    /* [out][in] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *dv1,
    /* [out][in] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *dv2,
    /* [out][in] */ /* external definition not present */ _Collection __RPC_FAR *__RPC_FAR *dv3,
    /* [out][in] */ double __RPC_FAR *result);


void __RPC_STUB _OnScriptParser_GetEqnStruct_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [id] */ HRESULT STDMETHODCALLTYPE _OnScriptParser_Fmt_Proxy( 
    _OnScriptParser __RPC_FAR * This,
    /* [out][in] */ BSTR __RPC_FAR *VIn,
    /* [retval][out] */ BSTR __RPC_FAR *__MIDL_0037);


void __RPC_STUB _OnScriptParser_Fmt_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* ___OnScriptParser_INTERFACE_DEFINED__ */


#ifndef ____ctlInitialization_DISPINTERFACE_DEFINED__
#define ____ctlInitialization_DISPINTERFACE_DEFINED__

/* dispinterface __ctlInitialization */
/* [nonextensible][hidden][version][uuid] */ 


EXTERN_C const IID DIID___ctlInitialization;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("64970E55-6C10-4F33-90E9-62EFC31E3C07")
    __ctlInitialization : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct __ctlInitializationVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            __ctlInitialization __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            __ctlInitialization __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            __ctlInitialization __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            __ctlInitialization __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            __ctlInitialization __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            __ctlInitialization __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            __ctlInitialization __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } __ctlInitializationVtbl;

    interface __ctlInitialization
    {
        CONST_VTBL struct __ctlInitializationVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __ctlInitialization_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define __ctlInitialization_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define __ctlInitialization_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define __ctlInitialization_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define __ctlInitialization_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define __ctlInitialization_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define __ctlInitialization_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ____ctlInitialization_DISPINTERFACE_DEFINED__ */


#ifndef ____ctlEquationEditor_DISPINTERFACE_DEFINED__
#define ____ctlEquationEditor_DISPINTERFACE_DEFINED__

/* dispinterface __ctlEquationEditor */
/* [nonextensible][hidden][version][uuid] */ 


EXTERN_C const IID DIID___ctlEquationEditor;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("0ECAEA74-52A4-4A81-9557-601ED4112FFB")
    __ctlEquationEditor : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct __ctlEquationEditorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            __ctlEquationEditor __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            __ctlEquationEditor __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            __ctlEquationEditor __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            __ctlEquationEditor __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            __ctlEquationEditor __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            __ctlEquationEditor __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            __ctlEquationEditor __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } __ctlEquationEditorVtbl;

    interface __ctlEquationEditor
    {
        CONST_VTBL struct __ctlEquationEditorVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __ctlEquationEditor_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define __ctlEquationEditor_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define __ctlEquationEditor_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define __ctlEquationEditor_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define __ctlEquationEditor_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define __ctlEquationEditor_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define __ctlEquationEditor_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ____ctlEquationEditor_DISPINTERFACE_DEFINED__ */


#ifndef ____ctlMessageWindow_DISPINTERFACE_DEFINED__
#define ____ctlMessageWindow_DISPINTERFACE_DEFINED__

/* dispinterface __ctlMessageWindow */
/* [nonextensible][hidden][version][uuid] */ 


EXTERN_C const IID DIID___ctlMessageWindow;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("7785B142-E38D-4A67-9EDD-5B25439F09DE")
    __ctlMessageWindow : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct __ctlMessageWindowVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            __ctlMessageWindow __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            __ctlMessageWindow __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            __ctlMessageWindow __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            __ctlMessageWindow __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            __ctlMessageWindow __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            __ctlMessageWindow __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            __ctlMessageWindow __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } __ctlMessageWindowVtbl;

    interface __ctlMessageWindow
    {
        CONST_VTBL struct __ctlMessageWindowVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __ctlMessageWindow_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define __ctlMessageWindow_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define __ctlMessageWindow_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define __ctlMessageWindow_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define __ctlMessageWindow_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define __ctlMessageWindow_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define __ctlMessageWindow_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ____ctlMessageWindow_DISPINTERFACE_DEFINED__ */


#ifndef ____OnScriptParser_DISPINTERFACE_DEFINED__
#define ____OnScriptParser_DISPINTERFACE_DEFINED__

/* dispinterface __OnScriptParser */
/* [nonextensible][hidden][version][uuid] */ 


EXTERN_C const IID DIID___OnScriptParser;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("F2D89834-D2C8-47AA-893F-C19C01AFD00B")
    __OnScriptParser : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct __OnScriptParserVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            __OnScriptParser __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            __OnScriptParser __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            __OnScriptParser __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            __OnScriptParser __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            __OnScriptParser __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            __OnScriptParser __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            __OnScriptParser __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } __OnScriptParserVtbl;

    interface __OnScriptParser
    {
        CONST_VTBL struct __OnScriptParserVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define __OnScriptParser_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define __OnScriptParser_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define __OnScriptParser_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define __OnScriptParser_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define __OnScriptParser_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define __OnScriptParser_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define __OnScriptParser_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ____OnScriptParser_DISPINTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_ctlInitialization;

#ifdef __cplusplus

class DECLSPEC_UUID("D16FD96C-E4D6-46B6-AC9E-BD2CE0BE9F2E")
ctlInitialization;
#endif

EXTERN_C const CLSID CLSID_clsVar;

#ifdef __cplusplus

class DECLSPEC_UUID("0897D1F1-6FC5-4649-9854-AF148ED60049")
clsVar;
#endif

EXTERN_C const CLSID CLSID_clsCVar;

#ifdef __cplusplus

class DECLSPEC_UUID("47A4423A-34A8-4DE5-AB74-3948B3F7AA2A")
clsCVar;
#endif

EXTERN_C const CLSID CLSID_clsVarManager;

#ifdef __cplusplus

class DECLSPEC_UUID("F469F156-6AC1-4063-A534-E054BF7B8A86")
clsVarManager;
#endif

EXTERN_C const CLSID CLSID_ctlEquationEditor;

#ifdef __cplusplus

class DECLSPEC_UUID("F16D8DA2-A244-4F7A-9E2C-ABF5C1AB126A")
ctlEquationEditor;
#endif

EXTERN_C const CLSID CLSID_ctlMessageWindow;

#ifdef __cplusplus

class DECLSPEC_UUID("FDC0FDCE-FD09-42D9-A667-0BE7A75591D0")
ctlMessageWindow;
#endif

EXTERN_C const CLSID CLSID_OnScriptParser;

#ifdef __cplusplus

class DECLSPEC_UUID("FBE4C91A-6686-4133-BB27-9956857B6C99")
OnScriptParser;
#endif
#endif /* __OnInitialization_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
