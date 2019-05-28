/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Feb 10 17:14:38 2003
 */
/* Compiler settings for C:\DistComponents\RtsOnTransmission\RtsOnTransmission.idl:
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

#ifndef __RtsOnTransmission_h__
#define __RtsOnTransmission_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IOnChart_FWD_DEFINED__
#define __IOnChart_FWD_DEFINED__
typedef interface IOnChart IOnChart;
#endif 	/* __IOnChart_FWD_DEFINED__ */


#ifndef __ICOnTestHarness_FWD_DEFINED__
#define __ICOnTestHarness_FWD_DEFINED__
typedef interface ICOnTestHarness ICOnTestHarness;
#endif 	/* __ICOnTestHarness_FWD_DEFINED__ */


#ifndef __OnChart_FWD_DEFINED__
#define __OnChart_FWD_DEFINED__

#ifdef __cplusplus
typedef class OnChart OnChart;
#else
typedef struct OnChart OnChart;
#endif /* __cplusplus */

#endif 	/* __OnChart_FWD_DEFINED__ */


#ifndef __COnTestHarness_FWD_DEFINED__
#define __COnTestHarness_FWD_DEFINED__

#ifdef __cplusplus
typedef class COnTestHarness COnTestHarness;
#else
typedef struct COnTestHarness COnTestHarness;
#endif /* __cplusplus */

#endif 	/* __COnTestHarness_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "OnUMLEso.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IOnChart_INTERFACE_DEFINED__
#define __IOnChart_INTERFACE_DEFINED__

/* interface IOnChart */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IOnChart;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E4814F69-68C9-49AE-8292-B6A5AC3A3B43")
    IOnChart : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Show( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Hide( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE initPlot( 
            /* [in] */ long numberOfSeries,
            /* [in] */ VARIANT_BOOL vbPoint,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *SeriesNames) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE plotData( 
            /* [in] */ double time,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *psaVals,
            /* [in] */ long count) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCaption( 
            /* [in] */ BSTR caption) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Move( 
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int nWidth,
            /* [in] */ int nHeight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE cleanPlot( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetPosition( 
            /* [out][in] */ int __RPC_FAR *x,
            /* [out][in] */ int __RPC_FAR *y,
            /* [out][in] */ int __RPC_FAR *nWidth,
            /* [out][in] */ int __RPC_FAR *nHeight) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddSeries( 
            /* [in] */ BSTR SeriesName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE plotSeriesData( 
            /* [in] */ double t,
            /* [in] */ double val) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOnChartVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IOnChart __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IOnChart __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IOnChart __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IOnChart __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IOnChart __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IOnChart __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IOnChart __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Show )( 
            IOnChart __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Hide )( 
            IOnChart __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *initPlot )( 
            IOnChart __RPC_FAR * This,
            /* [in] */ long numberOfSeries,
            /* [in] */ VARIANT_BOOL vbPoint,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *SeriesNames);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *plotData )( 
            IOnChart __RPC_FAR * This,
            /* [in] */ double time,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *psaVals,
            /* [in] */ long count);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCaption )( 
            IOnChart __RPC_FAR * This,
            /* [in] */ BSTR caption);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Move )( 
            IOnChart __RPC_FAR * This,
            /* [in] */ int x,
            /* [in] */ int y,
            /* [in] */ int nWidth,
            /* [in] */ int nHeight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *cleanPlot )( 
            IOnChart __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetPosition )( 
            IOnChart __RPC_FAR * This,
            /* [out][in] */ int __RPC_FAR *x,
            /* [out][in] */ int __RPC_FAR *y,
            /* [out][in] */ int __RPC_FAR *nWidth,
            /* [out][in] */ int __RPC_FAR *nHeight);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddSeries )( 
            IOnChart __RPC_FAR * This,
            /* [in] */ BSTR SeriesName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *plotSeriesData )( 
            IOnChart __RPC_FAR * This,
            /* [in] */ double t,
            /* [in] */ double val);
        
        END_INTERFACE
    } IOnChartVtbl;

    interface IOnChart
    {
        CONST_VTBL struct IOnChartVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOnChart_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOnChart_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOnChart_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOnChart_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOnChart_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOnChart_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOnChart_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IOnChart_Show(This)	\
    (This)->lpVtbl -> Show(This)

#define IOnChart_Hide(This)	\
    (This)->lpVtbl -> Hide(This)

#define IOnChart_initPlot(This,numberOfSeries,vbPoint,SeriesNames)	\
    (This)->lpVtbl -> initPlot(This,numberOfSeries,vbPoint,SeriesNames)

#define IOnChart_plotData(This,time,psaVals,count)	\
    (This)->lpVtbl -> plotData(This,time,psaVals,count)

#define IOnChart_SetCaption(This,caption)	\
    (This)->lpVtbl -> SetCaption(This,caption)

#define IOnChart_Move(This,x,y,nWidth,nHeight)	\
    (This)->lpVtbl -> Move(This,x,y,nWidth,nHeight)

#define IOnChart_cleanPlot(This)	\
    (This)->lpVtbl -> cleanPlot(This)

#define IOnChart_GetPosition(This,x,y,nWidth,nHeight)	\
    (This)->lpVtbl -> GetPosition(This,x,y,nWidth,nHeight)

#define IOnChart_AddSeries(This,SeriesName)	\
    (This)->lpVtbl -> AddSeries(This,SeriesName)

#define IOnChart_plotSeriesData(This,t,val)	\
    (This)->lpVtbl -> plotSeriesData(This,t,val)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnChart_Show_Proxy( 
    IOnChart __RPC_FAR * This);


void __RPC_STUB IOnChart_Show_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnChart_Hide_Proxy( 
    IOnChart __RPC_FAR * This);


void __RPC_STUB IOnChart_Hide_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnChart_initPlot_Proxy( 
    IOnChart __RPC_FAR * This,
    /* [in] */ long numberOfSeries,
    /* [in] */ VARIANT_BOOL vbPoint,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *SeriesNames);


void __RPC_STUB IOnChart_initPlot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnChart_plotData_Proxy( 
    IOnChart __RPC_FAR * This,
    /* [in] */ double time,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *psaVals,
    /* [in] */ long count);


void __RPC_STUB IOnChart_plotData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnChart_SetCaption_Proxy( 
    IOnChart __RPC_FAR * This,
    /* [in] */ BSTR caption);


void __RPC_STUB IOnChart_SetCaption_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnChart_Move_Proxy( 
    IOnChart __RPC_FAR * This,
    /* [in] */ int x,
    /* [in] */ int y,
    /* [in] */ int nWidth,
    /* [in] */ int nHeight);


void __RPC_STUB IOnChart_Move_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnChart_cleanPlot_Proxy( 
    IOnChart __RPC_FAR * This);


void __RPC_STUB IOnChart_cleanPlot_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnChart_GetPosition_Proxy( 
    IOnChart __RPC_FAR * This,
    /* [out][in] */ int __RPC_FAR *x,
    /* [out][in] */ int __RPC_FAR *y,
    /* [out][in] */ int __RPC_FAR *nWidth,
    /* [out][in] */ int __RPC_FAR *nHeight);


void __RPC_STUB IOnChart_GetPosition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnChart_AddSeries_Proxy( 
    IOnChart __RPC_FAR * This,
    /* [in] */ BSTR SeriesName);


void __RPC_STUB IOnChart_AddSeries_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnChart_plotSeriesData_Proxy( 
    IOnChart __RPC_FAR * This,
    /* [in] */ double t,
    /* [in] */ double val);


void __RPC_STUB IOnChart_plotSeriesData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOnChart_INTERFACE_DEFINED__ */


#ifndef __ICOnTestHarness_INTERFACE_DEFINED__
#define __ICOnTestHarness_INTERFACE_DEFINED__

/* interface ICOnTestHarness */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_ICOnTestHarness;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3669889E-81B0-4D6C-9230-10FD265189A5")
    ICOnTestHarness : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE runTest( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE init( void) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE tick( 
            double t) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE term( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_model( 
            /* [retval][out] */ IIsDaeEsoCImpl __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ModelExec( 
            /* [retval][out] */ IOnModelExec __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetShiftTiming( 
            /* [in] */ VARIANT_BOOL bUp,
            /* [in] */ long iShift,
            /* [in] */ double val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetShiftPeriod( 
            /* [in] */ long iClutch,
            /* [in] */ double val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetThrottle( 
            /* [in] */ double throttle) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ BSTR FileName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ BSTR FileName) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetStates( 
            SAFEARRAY __RPC_FAR * __RPC_FAR *states) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct ICOnTestHarnessVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            ICOnTestHarness __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            ICOnTestHarness __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            ICOnTestHarness __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            ICOnTestHarness __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            ICOnTestHarness __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            ICOnTestHarness __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            ICOnTestHarness __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *runTest )( 
            ICOnTestHarness __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *init )( 
            ICOnTestHarness __RPC_FAR * This);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *tick )( 
            ICOnTestHarness __RPC_FAR * This,
            double t);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *term )( 
            ICOnTestHarness __RPC_FAR * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_model )( 
            ICOnTestHarness __RPC_FAR * This,
            /* [retval][out] */ IIsDaeEsoCImpl __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ModelExec )( 
            ICOnTestHarness __RPC_FAR * This,
            /* [retval][out] */ IOnModelExec __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetShiftTiming )( 
            ICOnTestHarness __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL bUp,
            /* [in] */ long iShift,
            /* [in] */ double val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetShiftPeriod )( 
            ICOnTestHarness __RPC_FAR * This,
            /* [in] */ long iClutch,
            /* [in] */ double val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetThrottle )( 
            ICOnTestHarness __RPC_FAR * This,
            /* [in] */ double throttle);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            ICOnTestHarness __RPC_FAR * This,
            /* [in] */ BSTR FileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Save )( 
            ICOnTestHarness __RPC_FAR * This,
            /* [in] */ BSTR FileName);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetStates )( 
            ICOnTestHarness __RPC_FAR * This,
            SAFEARRAY __RPC_FAR * __RPC_FAR *states);
        
        END_INTERFACE
    } ICOnTestHarnessVtbl;

    interface ICOnTestHarness
    {
        CONST_VTBL struct ICOnTestHarnessVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define ICOnTestHarness_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define ICOnTestHarness_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define ICOnTestHarness_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define ICOnTestHarness_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define ICOnTestHarness_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define ICOnTestHarness_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define ICOnTestHarness_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define ICOnTestHarness_runTest(This)	\
    (This)->lpVtbl -> runTest(This)

#define ICOnTestHarness_init(This)	\
    (This)->lpVtbl -> init(This)

#define ICOnTestHarness_tick(This,t)	\
    (This)->lpVtbl -> tick(This,t)

#define ICOnTestHarness_term(This)	\
    (This)->lpVtbl -> term(This)

#define ICOnTestHarness_get_model(This,pVal)	\
    (This)->lpVtbl -> get_model(This,pVal)

#define ICOnTestHarness_get_ModelExec(This,pVal)	\
    (This)->lpVtbl -> get_ModelExec(This,pVal)

#define ICOnTestHarness_SetShiftTiming(This,bUp,iShift,val)	\
    (This)->lpVtbl -> SetShiftTiming(This,bUp,iShift,val)

#define ICOnTestHarness_SetShiftPeriod(This,iClutch,val)	\
    (This)->lpVtbl -> SetShiftPeriod(This,iClutch,val)

#define ICOnTestHarness_SetThrottle(This,throttle)	\
    (This)->lpVtbl -> SetThrottle(This,throttle)

#define ICOnTestHarness_Load(This,FileName)	\
    (This)->lpVtbl -> Load(This,FileName)

#define ICOnTestHarness_Save(This,FileName)	\
    (This)->lpVtbl -> Save(This,FileName)

#define ICOnTestHarness_GetStates(This,states)	\
    (This)->lpVtbl -> GetStates(This,states)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICOnTestHarness_runTest_Proxy( 
    ICOnTestHarness __RPC_FAR * This);


void __RPC_STUB ICOnTestHarness_runTest_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICOnTestHarness_init_Proxy( 
    ICOnTestHarness __RPC_FAR * This);


void __RPC_STUB ICOnTestHarness_init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICOnTestHarness_tick_Proxy( 
    ICOnTestHarness __RPC_FAR * This,
    double t);


void __RPC_STUB ICOnTestHarness_tick_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICOnTestHarness_term_Proxy( 
    ICOnTestHarness __RPC_FAR * This);


void __RPC_STUB ICOnTestHarness_term_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICOnTestHarness_get_model_Proxy( 
    ICOnTestHarness __RPC_FAR * This,
    /* [retval][out] */ IIsDaeEsoCImpl __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB ICOnTestHarness_get_model_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE ICOnTestHarness_get_ModelExec_Proxy( 
    ICOnTestHarness __RPC_FAR * This,
    /* [retval][out] */ IOnModelExec __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB ICOnTestHarness_get_ModelExec_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICOnTestHarness_SetShiftTiming_Proxy( 
    ICOnTestHarness __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL bUp,
    /* [in] */ long iShift,
    /* [in] */ double val);


void __RPC_STUB ICOnTestHarness_SetShiftTiming_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICOnTestHarness_SetShiftPeriod_Proxy( 
    ICOnTestHarness __RPC_FAR * This,
    /* [in] */ long iClutch,
    /* [in] */ double val);


void __RPC_STUB ICOnTestHarness_SetShiftPeriod_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICOnTestHarness_SetThrottle_Proxy( 
    ICOnTestHarness __RPC_FAR * This,
    /* [in] */ double throttle);


void __RPC_STUB ICOnTestHarness_SetThrottle_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICOnTestHarness_Load_Proxy( 
    ICOnTestHarness __RPC_FAR * This,
    /* [in] */ BSTR FileName);


void __RPC_STUB ICOnTestHarness_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICOnTestHarness_Save_Proxy( 
    ICOnTestHarness __RPC_FAR * This,
    /* [in] */ BSTR FileName);


void __RPC_STUB ICOnTestHarness_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ICOnTestHarness_GetStates_Proxy( 
    ICOnTestHarness __RPC_FAR * This,
    SAFEARRAY __RPC_FAR * __RPC_FAR *states);


void __RPC_STUB ICOnTestHarness_GetStates_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __ICOnTestHarness_INTERFACE_DEFINED__ */



#ifndef __RTSONTRANSMISSIONLib_LIBRARY_DEFINED__
#define __RTSONTRANSMISSIONLib_LIBRARY_DEFINED__

/* library RTSONTRANSMISSIONLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_RTSONTRANSMISSIONLib;

EXTERN_C const CLSID CLSID_OnChart;

#ifdef __cplusplus

class DECLSPEC_UUID("A0B5F84A-7758-4EF9-8BE8-16D1C0ABFB3E")
OnChart;
#endif

EXTERN_C const CLSID CLSID_COnTestHarness;

#ifdef __cplusplus

class DECLSPEC_UUID("612AC51E-6CB5-46C3-B603-6268202D48DC")
COnTestHarness;
#endif
#endif /* __RTSONTRANSMISSIONLib_LIBRARY_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

unsigned long             __RPC_USER  BSTR_UserSize(     unsigned long __RPC_FAR *, unsigned long            , BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  BSTR_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, BSTR __RPC_FAR * ); 
void                      __RPC_USER  BSTR_UserFree(     unsigned long __RPC_FAR *, BSTR __RPC_FAR * ); 

unsigned long             __RPC_USER  LPSAFEARRAY_UserSize(     unsigned long __RPC_FAR *, unsigned long            , LPSAFEARRAY __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  LPSAFEARRAY_UserMarshal(  unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, LPSAFEARRAY __RPC_FAR * ); 
unsigned char __RPC_FAR * __RPC_USER  LPSAFEARRAY_UserUnmarshal(unsigned long __RPC_FAR *, unsigned char __RPC_FAR *, LPSAFEARRAY __RPC_FAR * ); 
void                      __RPC_USER  LPSAFEARRAY_UserFree(     unsigned long __RPC_FAR *, LPSAFEARRAY __RPC_FAR * ); 

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif
