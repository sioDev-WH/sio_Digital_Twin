/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Thu Jan 09 10:46:40 2003
 */
/* Compiler settings for C:\DistComponents\RtsOnTransmissionVB\RtsOnTransmissionVB.idl:
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

#ifndef __RtsOnTransmissionVB_h__
#define __RtsOnTransmissionVB_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IvbActuator_FWD_DEFINED__
#define __IvbActuator_FWD_DEFINED__
typedef interface IvbActuator IvbActuator;
#endif 	/* __IvbActuator_FWD_DEFINED__ */


#ifndef __IvbBand_Brake_FWD_DEFINED__
#define __IvbBand_Brake_FWD_DEFINED__
typedef interface IvbBand_Brake IvbBand_Brake;
#endif 	/* __IvbBand_Brake_FWD_DEFINED__ */


#ifndef __IvbBrakeActuator_FWD_DEFINED__
#define __IvbBrakeActuator_FWD_DEFINED__
typedef interface IvbBrakeActuator IvbBrakeActuator;
#endif 	/* __IvbBrakeActuator_FWD_DEFINED__ */


#ifndef __IvbDamper_FWD_DEFINED__
#define __IvbDamper_FWD_DEFINED__
typedef interface IvbDamper IvbDamper;
#endif 	/* __IvbDamper_FWD_DEFINED__ */


#ifndef __IvbFrame_FWD_DEFINED__
#define __IvbFrame_FWD_DEFINED__
typedef interface IvbFrame IvbFrame;
#endif 	/* __IvbFrame_FWD_DEFINED__ */


#ifndef __IvbClutch_FWD_DEFINED__
#define __IvbClutch_FWD_DEFINED__
typedef interface IvbClutch IvbClutch;
#endif 	/* __IvbClutch_FWD_DEFINED__ */


#ifndef __IvbMass_FWD_DEFINED__
#define __IvbMass_FWD_DEFINED__
typedef interface IvbMass IvbMass;
#endif 	/* __IvbMass_FWD_DEFINED__ */


#ifndef __IvbSpring_FWD_DEFINED__
#define __IvbSpring_FWD_DEFINED__
typedef interface IvbSpring IvbSpring;
#endif 	/* __IvbSpring_FWD_DEFINED__ */


#ifndef __IvbEngine_FWD_DEFINED__
#define __IvbEngine_FWD_DEFINED__
typedef interface IvbEngine IvbEngine;
#endif 	/* __IvbEngine_FWD_DEFINED__ */


#ifndef __IvbOneway_Clutch_FWD_DEFINED__
#define __IvbOneway_Clutch_FWD_DEFINED__
typedef interface IvbOneway_Clutch IvbOneway_Clutch;
#endif 	/* __IvbOneway_Clutch_FWD_DEFINED__ */


#ifndef __IvbRavigneaux_FWD_DEFINED__
#define __IvbRavigneaux_FWD_DEFINED__
typedef interface IvbRavigneaux IvbRavigneaux;
#endif 	/* __IvbRavigneaux_FWD_DEFINED__ */


#ifndef __IvbTorque_Converter_FWD_DEFINED__
#define __IvbTorque_Converter_FWD_DEFINED__
typedef interface IvbTorque_Converter IvbTorque_Converter;
#endif 	/* __IvbTorque_Converter_FWD_DEFINED__ */


#ifndef __IvbVehicle_FWD_DEFINED__
#define __IvbVehicle_FWD_DEFINED__
typedef interface IvbVehicle IvbVehicle;
#endif 	/* __IvbVehicle_FWD_DEFINED__ */


#ifndef __IvbVehicle2_FWD_DEFINED__
#define __IvbVehicle2_FWD_DEFINED__
typedef interface IvbVehicle2 IvbVehicle2;
#endif 	/* __IvbVehicle2_FWD_DEFINED__ */


#ifndef __IvbVehicle5_FWD_DEFINED__
#define __IvbVehicle5_FWD_DEFINED__
typedef interface IvbVehicle5 IvbVehicle5;
#endif 	/* __IvbVehicle5_FWD_DEFINED__ */


#ifndef __IvbComposite_FWD_DEFINED__
#define __IvbComposite_FWD_DEFINED__
typedef interface IvbComposite IvbComposite;
#endif 	/* __IvbComposite_FWD_DEFINED__ */


#ifndef __vbActuator_FWD_DEFINED__
#define __vbActuator_FWD_DEFINED__

#ifdef __cplusplus
typedef class vbActuator vbActuator;
#else
typedef struct vbActuator vbActuator;
#endif /* __cplusplus */

#endif 	/* __vbActuator_FWD_DEFINED__ */


#ifndef __vbBand_Brake_FWD_DEFINED__
#define __vbBand_Brake_FWD_DEFINED__

#ifdef __cplusplus
typedef class vbBand_Brake vbBand_Brake;
#else
typedef struct vbBand_Brake vbBand_Brake;
#endif /* __cplusplus */

#endif 	/* __vbBand_Brake_FWD_DEFINED__ */


#ifndef __vbBrakeActuator_FWD_DEFINED__
#define __vbBrakeActuator_FWD_DEFINED__

#ifdef __cplusplus
typedef class vbBrakeActuator vbBrakeActuator;
#else
typedef struct vbBrakeActuator vbBrakeActuator;
#endif /* __cplusplus */

#endif 	/* __vbBrakeActuator_FWD_DEFINED__ */


#ifndef __vbDamper_FWD_DEFINED__
#define __vbDamper_FWD_DEFINED__

#ifdef __cplusplus
typedef class vbDamper vbDamper;
#else
typedef struct vbDamper vbDamper;
#endif /* __cplusplus */

#endif 	/* __vbDamper_FWD_DEFINED__ */


#ifndef __vbFrame_FWD_DEFINED__
#define __vbFrame_FWD_DEFINED__

#ifdef __cplusplus
typedef class vbFrame vbFrame;
#else
typedef struct vbFrame vbFrame;
#endif /* __cplusplus */

#endif 	/* __vbFrame_FWD_DEFINED__ */


#ifndef __vbClutch_FWD_DEFINED__
#define __vbClutch_FWD_DEFINED__

#ifdef __cplusplus
typedef class vbClutch vbClutch;
#else
typedef struct vbClutch vbClutch;
#endif /* __cplusplus */

#endif 	/* __vbClutch_FWD_DEFINED__ */


#ifndef __vbMass_FWD_DEFINED__
#define __vbMass_FWD_DEFINED__

#ifdef __cplusplus
typedef class vbMass vbMass;
#else
typedef struct vbMass vbMass;
#endif /* __cplusplus */

#endif 	/* __vbMass_FWD_DEFINED__ */


#ifndef __vbSpring_FWD_DEFINED__
#define __vbSpring_FWD_DEFINED__

#ifdef __cplusplus
typedef class vbSpring vbSpring;
#else
typedef struct vbSpring vbSpring;
#endif /* __cplusplus */

#endif 	/* __vbSpring_FWD_DEFINED__ */


#ifndef __vbEngine_FWD_DEFINED__
#define __vbEngine_FWD_DEFINED__

#ifdef __cplusplus
typedef class vbEngine vbEngine;
#else
typedef struct vbEngine vbEngine;
#endif /* __cplusplus */

#endif 	/* __vbEngine_FWD_DEFINED__ */


#ifndef __vbOneway_Clutch_FWD_DEFINED__
#define __vbOneway_Clutch_FWD_DEFINED__

#ifdef __cplusplus
typedef class vbOneway_Clutch vbOneway_Clutch;
#else
typedef struct vbOneway_Clutch vbOneway_Clutch;
#endif /* __cplusplus */

#endif 	/* __vbOneway_Clutch_FWD_DEFINED__ */


#ifndef __vbRavigneaux_FWD_DEFINED__
#define __vbRavigneaux_FWD_DEFINED__

#ifdef __cplusplus
typedef class vbRavigneaux vbRavigneaux;
#else
typedef struct vbRavigneaux vbRavigneaux;
#endif /* __cplusplus */

#endif 	/* __vbRavigneaux_FWD_DEFINED__ */


#ifndef __vbTorque_Converter_FWD_DEFINED__
#define __vbTorque_Converter_FWD_DEFINED__

#ifdef __cplusplus
typedef class vbTorque_Converter vbTorque_Converter;
#else
typedef struct vbTorque_Converter vbTorque_Converter;
#endif /* __cplusplus */

#endif 	/* __vbTorque_Converter_FWD_DEFINED__ */


#ifndef __vbVehicle_FWD_DEFINED__
#define __vbVehicle_FWD_DEFINED__

#ifdef __cplusplus
typedef class vbVehicle vbVehicle;
#else
typedef struct vbVehicle vbVehicle;
#endif /* __cplusplus */

#endif 	/* __vbVehicle_FWD_DEFINED__ */


#ifndef __vbVehicle2_FWD_DEFINED__
#define __vbVehicle2_FWD_DEFINED__

#ifdef __cplusplus
typedef class vbVehicle2 vbVehicle2;
#else
typedef struct vbVehicle2 vbVehicle2;
#endif /* __cplusplus */

#endif 	/* __vbVehicle2_FWD_DEFINED__ */


#ifndef __vbVehicle5_FWD_DEFINED__
#define __vbVehicle5_FWD_DEFINED__

#ifdef __cplusplus
typedef class vbVehicle5 vbVehicle5;
#else
typedef struct vbVehicle5 vbVehicle5;
#endif /* __cplusplus */

#endif 	/* __vbVehicle5_FWD_DEFINED__ */


#ifndef __vbComposite_FWD_DEFINED__
#define __vbComposite_FWD_DEFINED__

#ifdef __cplusplus
typedef class vbComposite vbComposite;
#else
typedef struct vbComposite vbComposite;
#endif /* __cplusplus */

#endif 	/* __vbComposite_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"
#include "IsDaeCOSolver.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

#ifndef __IvbActuator_INTERFACE_DEFINED__
#define __IvbActuator_INTERFACE_DEFINED__

/* interface IvbActuator */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IvbActuator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("151A17E2-EE49-48CB-8F80-37E3A84D4200")
    IvbActuator : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Eso( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE shiftEvent( 
            /* [in] */ double t,
            /* [in] */ long val) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_clutch( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IvbActuatorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IvbActuator __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IvbActuator __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IvbActuator __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IvbActuator __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IvbActuator __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IvbActuator __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IvbActuator __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Eso )( 
            IvbActuator __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *shiftEvent )( 
            IvbActuator __RPC_FAR * This,
            /* [in] */ double t,
            /* [in] */ long val);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_clutch )( 
            IvbActuator __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        END_INTERFACE
    } IvbActuatorVtbl;

    interface IvbActuator
    {
        CONST_VTBL struct IvbActuatorVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IvbActuator_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IvbActuator_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IvbActuator_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IvbActuator_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IvbActuator_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IvbActuator_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IvbActuator_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IvbActuator_get_Eso(This,pVal)	\
    (This)->lpVtbl -> get_Eso(This,pVal)

#define IvbActuator_shiftEvent(This,t,val)	\
    (This)->lpVtbl -> shiftEvent(This,t,val)

#define IvbActuator_get_clutch(This,val)	\
    (This)->lpVtbl -> get_clutch(This,val)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbActuator_get_Eso_Proxy( 
    IvbActuator __RPC_FAR * This,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IvbActuator_get_Eso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbActuator_shiftEvent_Proxy( 
    IvbActuator __RPC_FAR * This,
    /* [in] */ double t,
    /* [in] */ long val);


void __RPC_STUB IvbActuator_shiftEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbActuator_get_clutch_Proxy( 
    IvbActuator __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbActuator_get_clutch_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IvbActuator_INTERFACE_DEFINED__ */


#ifndef __IvbBand_Brake_INTERFACE_DEFINED__
#define __IvbBand_Brake_INTERFACE_DEFINED__

/* interface IvbBand_Brake */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IvbBand_Brake;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C3FEA6B9-2A67-4730-84FF-339F49C63FC7")
    IvbBand_Brake : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Eso( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_actuator( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_n( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_p( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IvbBand_BrakeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IvbBand_Brake __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IvbBand_Brake __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IvbBand_Brake __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IvbBand_Brake __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IvbBand_Brake __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IvbBand_Brake __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IvbBand_Brake __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Eso )( 
            IvbBand_Brake __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_actuator )( 
            IvbBand_Brake __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_n )( 
            IvbBand_Brake __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_p )( 
            IvbBand_Brake __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        END_INTERFACE
    } IvbBand_BrakeVtbl;

    interface IvbBand_Brake
    {
        CONST_VTBL struct IvbBand_BrakeVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IvbBand_Brake_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IvbBand_Brake_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IvbBand_Brake_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IvbBand_Brake_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IvbBand_Brake_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IvbBand_Brake_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IvbBand_Brake_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IvbBand_Brake_get_Eso(This,pVal)	\
    (This)->lpVtbl -> get_Eso(This,pVal)

#define IvbBand_Brake_get_actuator(This,val)	\
    (This)->lpVtbl -> get_actuator(This,val)

#define IvbBand_Brake_get_n(This,val)	\
    (This)->lpVtbl -> get_n(This,val)

#define IvbBand_Brake_get_p(This,val)	\
    (This)->lpVtbl -> get_p(This,val)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbBand_Brake_get_Eso_Proxy( 
    IvbBand_Brake __RPC_FAR * This,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IvbBand_Brake_get_Eso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbBand_Brake_get_actuator_Proxy( 
    IvbBand_Brake __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbBand_Brake_get_actuator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbBand_Brake_get_n_Proxy( 
    IvbBand_Brake __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbBand_Brake_get_n_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbBand_Brake_get_p_Proxy( 
    IvbBand_Brake __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbBand_Brake_get_p_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IvbBand_Brake_INTERFACE_DEFINED__ */


#ifndef __IvbBrakeActuator_INTERFACE_DEFINED__
#define __IvbBrakeActuator_INTERFACE_DEFINED__

/* interface IvbBrakeActuator */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IvbBrakeActuator;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C9F40039-5DD0-4731-BB00-FDC87037A7CB")
    IvbBrakeActuator : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Eso( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_p( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IvbBrakeActuatorVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IvbBrakeActuator __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IvbBrakeActuator __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IvbBrakeActuator __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IvbBrakeActuator __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IvbBrakeActuator __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IvbBrakeActuator __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IvbBrakeActuator __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Eso )( 
            IvbBrakeActuator __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_p )( 
            IvbBrakeActuator __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        END_INTERFACE
    } IvbBrakeActuatorVtbl;

    interface IvbBrakeActuator
    {
        CONST_VTBL struct IvbBrakeActuatorVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IvbBrakeActuator_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IvbBrakeActuator_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IvbBrakeActuator_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IvbBrakeActuator_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IvbBrakeActuator_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IvbBrakeActuator_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IvbBrakeActuator_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IvbBrakeActuator_get_Eso(This,pVal)	\
    (This)->lpVtbl -> get_Eso(This,pVal)

#define IvbBrakeActuator_get_p(This,val)	\
    (This)->lpVtbl -> get_p(This,val)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbBrakeActuator_get_Eso_Proxy( 
    IvbBrakeActuator __RPC_FAR * This,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IvbBrakeActuator_get_Eso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbBrakeActuator_get_p_Proxy( 
    IvbBrakeActuator __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbBrakeActuator_get_p_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IvbBrakeActuator_INTERFACE_DEFINED__ */


#ifndef __IvbDamper_INTERFACE_DEFINED__
#define __IvbDamper_INTERFACE_DEFINED__

/* interface IvbDamper */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IvbDamper;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("5F57111A-D6E0-4682-90C1-D2D859C753C2")
    IvbDamper : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Eso( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_n( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_p( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IvbDamperVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IvbDamper __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IvbDamper __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IvbDamper __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IvbDamper __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IvbDamper __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IvbDamper __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IvbDamper __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Eso )( 
            IvbDamper __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_n )( 
            IvbDamper __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_p )( 
            IvbDamper __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        END_INTERFACE
    } IvbDamperVtbl;

    interface IvbDamper
    {
        CONST_VTBL struct IvbDamperVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IvbDamper_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IvbDamper_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IvbDamper_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IvbDamper_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IvbDamper_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IvbDamper_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IvbDamper_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IvbDamper_get_Eso(This,pVal)	\
    (This)->lpVtbl -> get_Eso(This,pVal)

#define IvbDamper_get_n(This,val)	\
    (This)->lpVtbl -> get_n(This,val)

#define IvbDamper_get_p(This,val)	\
    (This)->lpVtbl -> get_p(This,val)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbDamper_get_Eso_Proxy( 
    IvbDamper __RPC_FAR * This,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IvbDamper_get_Eso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbDamper_get_n_Proxy( 
    IvbDamper __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbDamper_get_n_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbDamper_get_p_Proxy( 
    IvbDamper __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbDamper_get_p_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IvbDamper_INTERFACE_DEFINED__ */


#ifndef __IvbFrame_INTERFACE_DEFINED__
#define __IvbFrame_INTERFACE_DEFINED__

/* interface IvbFrame */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IvbFrame;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E33F7692-C1EC-4F20-8345-B2E5CCD4F435")
    IvbFrame : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Eso( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_p( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IvbFrameVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IvbFrame __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IvbFrame __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IvbFrame __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IvbFrame __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IvbFrame __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IvbFrame __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IvbFrame __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Eso )( 
            IvbFrame __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_p )( 
            IvbFrame __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        END_INTERFACE
    } IvbFrameVtbl;

    interface IvbFrame
    {
        CONST_VTBL struct IvbFrameVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IvbFrame_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IvbFrame_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IvbFrame_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IvbFrame_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IvbFrame_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IvbFrame_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IvbFrame_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IvbFrame_get_Eso(This,pVal)	\
    (This)->lpVtbl -> get_Eso(This,pVal)

#define IvbFrame_get_p(This,val)	\
    (This)->lpVtbl -> get_p(This,val)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbFrame_get_Eso_Proxy( 
    IvbFrame __RPC_FAR * This,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IvbFrame_get_Eso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbFrame_get_p_Proxy( 
    IvbFrame __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbFrame_get_p_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IvbFrame_INTERFACE_DEFINED__ */


#ifndef __IvbClutch_INTERFACE_DEFINED__
#define __IvbClutch_INTERFACE_DEFINED__

/* interface IvbClutch */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IvbClutch;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("1D54BCFB-53EF-4C9D-9CF4-942641C9CDB9")
    IvbClutch : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Eso( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_actuator( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_n( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_p( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IvbClutchVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IvbClutch __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IvbClutch __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IvbClutch __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IvbClutch __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IvbClutch __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IvbClutch __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IvbClutch __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Eso )( 
            IvbClutch __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_actuator )( 
            IvbClutch __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_n )( 
            IvbClutch __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_p )( 
            IvbClutch __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        END_INTERFACE
    } IvbClutchVtbl;

    interface IvbClutch
    {
        CONST_VTBL struct IvbClutchVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IvbClutch_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IvbClutch_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IvbClutch_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IvbClutch_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IvbClutch_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IvbClutch_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IvbClutch_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IvbClutch_get_Eso(This,pVal)	\
    (This)->lpVtbl -> get_Eso(This,pVal)

#define IvbClutch_get_actuator(This,val)	\
    (This)->lpVtbl -> get_actuator(This,val)

#define IvbClutch_get_n(This,val)	\
    (This)->lpVtbl -> get_n(This,val)

#define IvbClutch_get_p(This,val)	\
    (This)->lpVtbl -> get_p(This,val)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbClutch_get_Eso_Proxy( 
    IvbClutch __RPC_FAR * This,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IvbClutch_get_Eso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbClutch_get_actuator_Proxy( 
    IvbClutch __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbClutch_get_actuator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbClutch_get_n_Proxy( 
    IvbClutch __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbClutch_get_n_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbClutch_get_p_Proxy( 
    IvbClutch __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbClutch_get_p_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IvbClutch_INTERFACE_DEFINED__ */


#ifndef __IvbMass_INTERFACE_DEFINED__
#define __IvbMass_INTERFACE_DEFINED__

/* interface IvbMass */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IvbMass;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("E3830D21-7568-4546-872A-F8C84FFD7C54")
    IvbMass : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Eso( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_p( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_n( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IvbMassVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IvbMass __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IvbMass __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IvbMass __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IvbMass __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IvbMass __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IvbMass __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IvbMass __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Eso )( 
            IvbMass __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_p )( 
            IvbMass __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_n )( 
            IvbMass __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        END_INTERFACE
    } IvbMassVtbl;

    interface IvbMass
    {
        CONST_VTBL struct IvbMassVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IvbMass_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IvbMass_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IvbMass_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IvbMass_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IvbMass_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IvbMass_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IvbMass_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IvbMass_get_Eso(This,pVal)	\
    (This)->lpVtbl -> get_Eso(This,pVal)

#define IvbMass_get_p(This,val)	\
    (This)->lpVtbl -> get_p(This,val)

#define IvbMass_get_n(This,val)	\
    (This)->lpVtbl -> get_n(This,val)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbMass_get_Eso_Proxy( 
    IvbMass __RPC_FAR * This,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IvbMass_get_Eso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbMass_get_p_Proxy( 
    IvbMass __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbMass_get_p_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbMass_get_n_Proxy( 
    IvbMass __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbMass_get_n_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IvbMass_INTERFACE_DEFINED__ */


#ifndef __IvbSpring_INTERFACE_DEFINED__
#define __IvbSpring_INTERFACE_DEFINED__

/* interface IvbSpring */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IvbSpring;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("8F903BCD-9C46-4933-9877-4C452E8CC0D7")
    IvbSpring : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Eso( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_p( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_n( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IvbSpringVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IvbSpring __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IvbSpring __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IvbSpring __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IvbSpring __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IvbSpring __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IvbSpring __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IvbSpring __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Eso )( 
            IvbSpring __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_p )( 
            IvbSpring __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_n )( 
            IvbSpring __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        END_INTERFACE
    } IvbSpringVtbl;

    interface IvbSpring
    {
        CONST_VTBL struct IvbSpringVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IvbSpring_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IvbSpring_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IvbSpring_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IvbSpring_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IvbSpring_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IvbSpring_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IvbSpring_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IvbSpring_get_Eso(This,pVal)	\
    (This)->lpVtbl -> get_Eso(This,pVal)

#define IvbSpring_get_p(This,val)	\
    (This)->lpVtbl -> get_p(This,val)

#define IvbSpring_get_n(This,val)	\
    (This)->lpVtbl -> get_n(This,val)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbSpring_get_Eso_Proxy( 
    IvbSpring __RPC_FAR * This,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IvbSpring_get_Eso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbSpring_get_p_Proxy( 
    IvbSpring __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbSpring_get_p_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbSpring_get_n_Proxy( 
    IvbSpring __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbSpring_get_n_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IvbSpring_INTERFACE_DEFINED__ */


#ifndef __IvbEngine_INTERFACE_DEFINED__
#define __IvbEngine_INTERFACE_DEFINED__

/* interface IvbEngine */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IvbEngine;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("AA69FC5D-A2CE-4CFF-A9F3-D393C5678298")
    IvbEngine : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Eso( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_n( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE throttleEvent( 
            /* [in] */ double t,
            /* [in] */ double val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE startEvent( 
            /* [in] */ double t,
            /* [in] */ long val) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IvbEngineVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IvbEngine __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IvbEngine __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IvbEngine __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IvbEngine __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IvbEngine __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IvbEngine __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IvbEngine __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Eso )( 
            IvbEngine __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_n )( 
            IvbEngine __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *throttleEvent )( 
            IvbEngine __RPC_FAR * This,
            /* [in] */ double t,
            /* [in] */ double val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *startEvent )( 
            IvbEngine __RPC_FAR * This,
            /* [in] */ double t,
            /* [in] */ long val);
        
        END_INTERFACE
    } IvbEngineVtbl;

    interface IvbEngine
    {
        CONST_VTBL struct IvbEngineVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IvbEngine_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IvbEngine_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IvbEngine_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IvbEngine_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IvbEngine_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IvbEngine_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IvbEngine_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IvbEngine_get_Eso(This,pVal)	\
    (This)->lpVtbl -> get_Eso(This,pVal)

#define IvbEngine_get_n(This,val)	\
    (This)->lpVtbl -> get_n(This,val)

#define IvbEngine_throttleEvent(This,t,val)	\
    (This)->lpVtbl -> throttleEvent(This,t,val)

#define IvbEngine_startEvent(This,t,val)	\
    (This)->lpVtbl -> startEvent(This,t,val)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbEngine_get_Eso_Proxy( 
    IvbEngine __RPC_FAR * This,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IvbEngine_get_Eso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbEngine_get_n_Proxy( 
    IvbEngine __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbEngine_get_n_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbEngine_throttleEvent_Proxy( 
    IvbEngine __RPC_FAR * This,
    /* [in] */ double t,
    /* [in] */ double val);


void __RPC_STUB IvbEngine_throttleEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbEngine_startEvent_Proxy( 
    IvbEngine __RPC_FAR * This,
    /* [in] */ double t,
    /* [in] */ long val);


void __RPC_STUB IvbEngine_startEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IvbEngine_INTERFACE_DEFINED__ */


#ifndef __IvbOneway_Clutch_INTERFACE_DEFINED__
#define __IvbOneway_Clutch_INTERFACE_DEFINED__

/* interface IvbOneway_Clutch */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IvbOneway_Clutch;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C9AEA849-120B-4EA2-BEB2-11EE70EB0F62")
    IvbOneway_Clutch : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Eso( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_actuator( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_n( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_p( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IvbOneway_ClutchVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IvbOneway_Clutch __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IvbOneway_Clutch __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IvbOneway_Clutch __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IvbOneway_Clutch __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IvbOneway_Clutch __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IvbOneway_Clutch __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IvbOneway_Clutch __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Eso )( 
            IvbOneway_Clutch __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_actuator )( 
            IvbOneway_Clutch __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_n )( 
            IvbOneway_Clutch __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_p )( 
            IvbOneway_Clutch __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        END_INTERFACE
    } IvbOneway_ClutchVtbl;

    interface IvbOneway_Clutch
    {
        CONST_VTBL struct IvbOneway_ClutchVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IvbOneway_Clutch_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IvbOneway_Clutch_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IvbOneway_Clutch_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IvbOneway_Clutch_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IvbOneway_Clutch_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IvbOneway_Clutch_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IvbOneway_Clutch_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IvbOneway_Clutch_get_Eso(This,pVal)	\
    (This)->lpVtbl -> get_Eso(This,pVal)

#define IvbOneway_Clutch_get_actuator(This,val)	\
    (This)->lpVtbl -> get_actuator(This,val)

#define IvbOneway_Clutch_get_n(This,val)	\
    (This)->lpVtbl -> get_n(This,val)

#define IvbOneway_Clutch_get_p(This,val)	\
    (This)->lpVtbl -> get_p(This,val)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbOneway_Clutch_get_Eso_Proxy( 
    IvbOneway_Clutch __RPC_FAR * This,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IvbOneway_Clutch_get_Eso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbOneway_Clutch_get_actuator_Proxy( 
    IvbOneway_Clutch __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbOneway_Clutch_get_actuator_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbOneway_Clutch_get_n_Proxy( 
    IvbOneway_Clutch __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbOneway_Clutch_get_n_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbOneway_Clutch_get_p_Proxy( 
    IvbOneway_Clutch __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbOneway_Clutch_get_p_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IvbOneway_Clutch_INTERFACE_DEFINED__ */


#ifndef __IvbRavigneaux_INTERFACE_DEFINED__
#define __IvbRavigneaux_INTERFACE_DEFINED__

/* interface IvbRavigneaux */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IvbRavigneaux;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("F6220946-F942-4853-A335-33FD405B7055")
    IvbRavigneaux : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Eso( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_forwardSun( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_reverseSun( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_coupler( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ring( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IvbRavigneauxVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IvbRavigneaux __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IvbRavigneaux __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IvbRavigneaux __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IvbRavigneaux __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IvbRavigneaux __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IvbRavigneaux __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IvbRavigneaux __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Eso )( 
            IvbRavigneaux __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_forwardSun )( 
            IvbRavigneaux __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_reverseSun )( 
            IvbRavigneaux __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_coupler )( 
            IvbRavigneaux __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ring )( 
            IvbRavigneaux __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        END_INTERFACE
    } IvbRavigneauxVtbl;

    interface IvbRavigneaux
    {
        CONST_VTBL struct IvbRavigneauxVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IvbRavigneaux_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IvbRavigneaux_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IvbRavigneaux_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IvbRavigneaux_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IvbRavigneaux_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IvbRavigneaux_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IvbRavigneaux_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IvbRavigneaux_get_Eso(This,pVal)	\
    (This)->lpVtbl -> get_Eso(This,pVal)

#define IvbRavigneaux_get_forwardSun(This,val)	\
    (This)->lpVtbl -> get_forwardSun(This,val)

#define IvbRavigneaux_get_reverseSun(This,val)	\
    (This)->lpVtbl -> get_reverseSun(This,val)

#define IvbRavigneaux_get_coupler(This,val)	\
    (This)->lpVtbl -> get_coupler(This,val)

#define IvbRavigneaux_get_ring(This,val)	\
    (This)->lpVtbl -> get_ring(This,val)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbRavigneaux_get_Eso_Proxy( 
    IvbRavigneaux __RPC_FAR * This,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IvbRavigneaux_get_Eso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbRavigneaux_get_forwardSun_Proxy( 
    IvbRavigneaux __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbRavigneaux_get_forwardSun_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbRavigneaux_get_reverseSun_Proxy( 
    IvbRavigneaux __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbRavigneaux_get_reverseSun_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbRavigneaux_get_coupler_Proxy( 
    IvbRavigneaux __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbRavigneaux_get_coupler_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbRavigneaux_get_ring_Proxy( 
    IvbRavigneaux __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbRavigneaux_get_ring_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IvbRavigneaux_INTERFACE_DEFINED__ */


#ifndef __IvbTorque_Converter_INTERFACE_DEFINED__
#define __IvbTorque_Converter_INTERFACE_DEFINED__

/* interface IvbTorque_Converter */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IvbTorque_Converter;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("C56FE92D-F08E-448C-8F20-05667414F879")
    IvbTorque_Converter : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Eso( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_turbine( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_impeller( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IvbTorque_ConverterVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IvbTorque_Converter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IvbTorque_Converter __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IvbTorque_Converter __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IvbTorque_Converter __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IvbTorque_Converter __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IvbTorque_Converter __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IvbTorque_Converter __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Eso )( 
            IvbTorque_Converter __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_turbine )( 
            IvbTorque_Converter __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_impeller )( 
            IvbTorque_Converter __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        END_INTERFACE
    } IvbTorque_ConverterVtbl;

    interface IvbTorque_Converter
    {
        CONST_VTBL struct IvbTorque_ConverterVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IvbTorque_Converter_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IvbTorque_Converter_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IvbTorque_Converter_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IvbTorque_Converter_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IvbTorque_Converter_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IvbTorque_Converter_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IvbTorque_Converter_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IvbTorque_Converter_get_Eso(This,pVal)	\
    (This)->lpVtbl -> get_Eso(This,pVal)

#define IvbTorque_Converter_get_turbine(This,val)	\
    (This)->lpVtbl -> get_turbine(This,val)

#define IvbTorque_Converter_get_impeller(This,val)	\
    (This)->lpVtbl -> get_impeller(This,val)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbTorque_Converter_get_Eso_Proxy( 
    IvbTorque_Converter __RPC_FAR * This,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IvbTorque_Converter_get_Eso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbTorque_Converter_get_turbine_Proxy( 
    IvbTorque_Converter __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbTorque_Converter_get_turbine_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbTorque_Converter_get_impeller_Proxy( 
    IvbTorque_Converter __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbTorque_Converter_get_impeller_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IvbTorque_Converter_INTERFACE_DEFINED__ */


#ifndef __IvbVehicle_INTERFACE_DEFINED__
#define __IvbVehicle_INTERFACE_DEFINED__

/* interface IvbVehicle */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IvbVehicle;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("FAD2DA42-98D1-41B7-B54B-A0AB359AE3C3")
    IvbVehicle : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Eso( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_p( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IvbVehicleVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IvbVehicle __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IvbVehicle __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IvbVehicle __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IvbVehicle __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IvbVehicle __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IvbVehicle __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IvbVehicle __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Eso )( 
            IvbVehicle __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_p )( 
            IvbVehicle __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        END_INTERFACE
    } IvbVehicleVtbl;

    interface IvbVehicle
    {
        CONST_VTBL struct IvbVehicleVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IvbVehicle_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IvbVehicle_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IvbVehicle_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IvbVehicle_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IvbVehicle_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IvbVehicle_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IvbVehicle_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IvbVehicle_get_Eso(This,pVal)	\
    (This)->lpVtbl -> get_Eso(This,pVal)

#define IvbVehicle_get_p(This,val)	\
    (This)->lpVtbl -> get_p(This,val)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbVehicle_get_Eso_Proxy( 
    IvbVehicle __RPC_FAR * This,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IvbVehicle_get_Eso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbVehicle_get_p_Proxy( 
    IvbVehicle __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbVehicle_get_p_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IvbVehicle_INTERFACE_DEFINED__ */


#ifndef __IvbVehicle2_INTERFACE_DEFINED__
#define __IvbVehicle2_INTERFACE_DEFINED__

/* interface IvbVehicle2 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IvbVehicle2;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("42DF008C-3E57-4C41-B3E5-FFAA1F025987")
    IvbVehicle2 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Eso( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_p( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IvbVehicle2Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IvbVehicle2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IvbVehicle2 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IvbVehicle2 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IvbVehicle2 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IvbVehicle2 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IvbVehicle2 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IvbVehicle2 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Eso )( 
            IvbVehicle2 __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_p )( 
            IvbVehicle2 __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        END_INTERFACE
    } IvbVehicle2Vtbl;

    interface IvbVehicle2
    {
        CONST_VTBL struct IvbVehicle2Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IvbVehicle2_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IvbVehicle2_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IvbVehicle2_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IvbVehicle2_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IvbVehicle2_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IvbVehicle2_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IvbVehicle2_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IvbVehicle2_get_Eso(This,pVal)	\
    (This)->lpVtbl -> get_Eso(This,pVal)

#define IvbVehicle2_get_p(This,val)	\
    (This)->lpVtbl -> get_p(This,val)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbVehicle2_get_Eso_Proxy( 
    IvbVehicle2 __RPC_FAR * This,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IvbVehicle2_get_Eso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbVehicle2_get_p_Proxy( 
    IvbVehicle2 __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbVehicle2_get_p_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IvbVehicle2_INTERFACE_DEFINED__ */


#ifndef __IvbVehicle5_INTERFACE_DEFINED__
#define __IvbVehicle5_INTERFACE_DEFINED__

/* interface IvbVehicle5 */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IvbVehicle5;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B0C261A7-451A-42D5-9DB0-B7AF75E749BB")
    IvbVehicle5 : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Eso( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_p( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE brakeEvent( 
            /* [in] */ double t,
            /* [in] */ double val) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IvbVehicle5Vtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IvbVehicle5 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IvbVehicle5 __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IvbVehicle5 __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IvbVehicle5 __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IvbVehicle5 __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IvbVehicle5 __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IvbVehicle5 __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Eso )( 
            IvbVehicle5 __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_p )( 
            IvbVehicle5 __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *brakeEvent )( 
            IvbVehicle5 __RPC_FAR * This,
            /* [in] */ double t,
            /* [in] */ double val);
        
        END_INTERFACE
    } IvbVehicle5Vtbl;

    interface IvbVehicle5
    {
        CONST_VTBL struct IvbVehicle5Vtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IvbVehicle5_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IvbVehicle5_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IvbVehicle5_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IvbVehicle5_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IvbVehicle5_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IvbVehicle5_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IvbVehicle5_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IvbVehicle5_get_Eso(This,pVal)	\
    (This)->lpVtbl -> get_Eso(This,pVal)

#define IvbVehicle5_get_p(This,val)	\
    (This)->lpVtbl -> get_p(This,val)

#define IvbVehicle5_brakeEvent(This,t,val)	\
    (This)->lpVtbl -> brakeEvent(This,t,val)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbVehicle5_get_Eso_Proxy( 
    IvbVehicle5 __RPC_FAR * This,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IvbVehicle5_get_Eso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbVehicle5_get_p_Proxy( 
    IvbVehicle5 __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *val);


void __RPC_STUB IvbVehicle5_get_p_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IvbVehicle5_brakeEvent_Proxy( 
    IvbVehicle5 __RPC_FAR * This,
    /* [in] */ double t,
    /* [in] */ double val);


void __RPC_STUB IvbVehicle5_brakeEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IvbVehicle5_INTERFACE_DEFINED__ */


#ifndef __IvbComposite_INTERFACE_DEFINED__
#define __IvbComposite_INTERFACE_DEFINED__

/* interface IvbComposite */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IvbComposite;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("B43C1171-8D2A-4285-ABF0-01A11605E4B2")
    IvbComposite : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Eso( 
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IvbCompositeVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IvbComposite __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IvbComposite __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IvbComposite __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IvbComposite __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IvbComposite __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IvbComposite __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IvbComposite __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Eso )( 
            IvbComposite __RPC_FAR * This,
            /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);
        
        END_INTERFACE
    } IvbCompositeVtbl;

    interface IvbComposite
    {
        CONST_VTBL struct IvbCompositeVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IvbComposite_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IvbComposite_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IvbComposite_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IvbComposite_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IvbComposite_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IvbComposite_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IvbComposite_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IvbComposite_get_Eso(This,pVal)	\
    (This)->lpVtbl -> get_Eso(This,pVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IvbComposite_get_Eso_Proxy( 
    IvbComposite __RPC_FAR * This,
    /* [retval][out] */ IDispatch __RPC_FAR *__RPC_FAR *pVal);


void __RPC_STUB IvbComposite_get_Eso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IvbComposite_INTERFACE_DEFINED__ */



#ifndef __RTSONTRANSMISSIONVBLib_LIBRARY_DEFINED__
#define __RTSONTRANSMISSIONVBLib_LIBRARY_DEFINED__

/* library RTSONTRANSMISSIONVBLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_RTSONTRANSMISSIONVBLib;

EXTERN_C const CLSID CLSID_vbActuator;

#ifdef __cplusplus

class DECLSPEC_UUID("A69B361D-1B99-4C58-8E39-AE74998408FF")
vbActuator;
#endif

EXTERN_C const CLSID CLSID_vbBand_Brake;

#ifdef __cplusplus

class DECLSPEC_UUID("68106DC2-0D2E-43EE-9C27-9631CD9A76FA")
vbBand_Brake;
#endif

EXTERN_C const CLSID CLSID_vbBrakeActuator;

#ifdef __cplusplus

class DECLSPEC_UUID("4ED98690-219A-45D5-9E93-428D81E82B35")
vbBrakeActuator;
#endif

EXTERN_C const CLSID CLSID_vbDamper;

#ifdef __cplusplus

class DECLSPEC_UUID("BC7E3159-6811-4BC8-B5ED-BAC856AB15F3")
vbDamper;
#endif

EXTERN_C const CLSID CLSID_vbFrame;

#ifdef __cplusplus

class DECLSPEC_UUID("5097F3C6-277B-4F3A-9ADF-EC976FE35897")
vbFrame;
#endif

EXTERN_C const CLSID CLSID_vbClutch;

#ifdef __cplusplus

class DECLSPEC_UUID("32066F91-763F-42D5-8BE6-FFE063A21F00")
vbClutch;
#endif

EXTERN_C const CLSID CLSID_vbMass;

#ifdef __cplusplus

class DECLSPEC_UUID("42C9605E-F2CA-46BA-9172-E6B0E5A601CA")
vbMass;
#endif

EXTERN_C const CLSID CLSID_vbSpring;

#ifdef __cplusplus

class DECLSPEC_UUID("DE8ED079-5EFD-4C95-A250-8B2D59CB6D95")
vbSpring;
#endif

EXTERN_C const CLSID CLSID_vbEngine;

#ifdef __cplusplus

class DECLSPEC_UUID("B8E27D05-7F2A-4879-BCD7-D99D167EF626")
vbEngine;
#endif

EXTERN_C const CLSID CLSID_vbOneway_Clutch;

#ifdef __cplusplus

class DECLSPEC_UUID("0CA0A218-5C05-4FB5-81EB-5B21174F833D")
vbOneway_Clutch;
#endif

EXTERN_C const CLSID CLSID_vbRavigneaux;

#ifdef __cplusplus

class DECLSPEC_UUID("4EB24F1A-7F7B-4AFD-8171-C49BC53EC8BF")
vbRavigneaux;
#endif

EXTERN_C const CLSID CLSID_vbTorque_Converter;

#ifdef __cplusplus

class DECLSPEC_UUID("33F21A86-FAAC-4D64-885C-70DE23EE4AFE")
vbTorque_Converter;
#endif

EXTERN_C const CLSID CLSID_vbVehicle;

#ifdef __cplusplus

class DECLSPEC_UUID("851E4885-7325-454B-B66C-705BCCCBF30E")
vbVehicle;
#endif

EXTERN_C const CLSID CLSID_vbVehicle2;

#ifdef __cplusplus

class DECLSPEC_UUID("FFF1C150-F7EC-4B84-8218-3319FCF9F5FF")
vbVehicle2;
#endif

EXTERN_C const CLSID CLSID_vbVehicle5;

#ifdef __cplusplus

class DECLSPEC_UUID("E3752EB2-F95C-4749-B185-18E62877F73E")
vbVehicle5;
#endif

EXTERN_C const CLSID CLSID_vbComposite;

#ifdef __cplusplus

class DECLSPEC_UUID("5FA80366-8AEB-4A36-9772-2B58F2B78EBA")
vbComposite;
#endif
#endif /* __RTSONTRANSMISSIONVBLib_LIBRARY_DEFINED__ */

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
