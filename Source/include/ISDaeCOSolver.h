/* this ALWAYS GENERATED file contains the definitions for the interfaces */


/* File created by MIDL compiler version 5.01.0164 */
/* at Mon Jun 30 00:50:37 2003
 */
/* Compiler settings for C:\DistComponents\idl\ISDaeCOSolver.idl:
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

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__

#ifndef COM_NO_WINDOWS_H
#include "windows.h"
#include "ole2.h"
#endif /*COM_NO_WINDOWS_H*/

#ifndef __IsDaeCOSolver_h__
#define __IsDaeCOSolver_h__

#ifdef __cplusplus
extern "C"{
#endif 

/* Forward Declarations */ 

#ifndef __IIsDaeEso_FWD_DEFINED__
#define __IIsDaeEso_FWD_DEFINED__
typedef interface IIsDaeEso IIsDaeEso;
#endif 	/* __IIsDaeEso_FWD_DEFINED__ */


#ifndef __IIsMatrix_FWD_DEFINED__
#define __IIsMatrix_FWD_DEFINED__
typedef interface IIsMatrix IIsMatrix;
#endif 	/* __IIsMatrix_FWD_DEFINED__ */


#ifndef __IIsNlaSolver_FWD_DEFINED__
#define __IIsNlaSolver_FWD_DEFINED__
typedef interface IIsNlaSolver IIsNlaSolver;
#endif 	/* __IIsNlaSolver_FWD_DEFINED__ */


#ifndef __IIsNlaEso_FWD_DEFINED__
#define __IIsNlaEso_FWD_DEFINED__
typedef interface IIsNlaEso IIsNlaEso;
#endif 	/* __IIsNlaEso_FWD_DEFINED__ */


#ifndef __IIsDaeEsoImpl_FWD_DEFINED__
#define __IIsDaeEsoImpl_FWD_DEFINED__
typedef interface IIsDaeEsoImpl IIsDaeEsoImpl;
#endif 	/* __IIsDaeEsoImpl_FWD_DEFINED__ */


#ifndef __IIsDaeEsoIImpl_FWD_DEFINED__
#define __IIsDaeEsoIImpl_FWD_DEFINED__
typedef interface IIsDaeEsoIImpl IIsDaeEsoIImpl;
#endif 	/* __IIsDaeEsoIImpl_FWD_DEFINED__ */


#ifndef __IIsDaeEsoCImpl_FWD_DEFINED__
#define __IIsDaeEsoCImpl_FWD_DEFINED__
typedef interface IIsDaeEsoCImpl IIsDaeEsoCImpl;
#endif 	/* __IIsDaeEsoCImpl_FWD_DEFINED__ */


#ifndef __IOnModelExecEvents_FWD_DEFINED__
#define __IOnModelExecEvents_FWD_DEFINED__
typedef interface IOnModelExecEvents IOnModelExecEvents;
#endif 	/* __IOnModelExecEvents_FWD_DEFINED__ */


#ifndef __IOnModelExec_FWD_DEFINED__
#define __IOnModelExec_FWD_DEFINED__
typedef interface IOnModelExec IOnModelExec;
#endif 	/* __IOnModelExec_FWD_DEFINED__ */


#ifndef __IOnTest_FWD_DEFINED__
#define __IOnTest_FWD_DEFINED__
typedef interface IOnTest IOnTest;
#endif 	/* __IOnTest_FWD_DEFINED__ */


#ifndef ___IOnModelExecEvents_FWD_DEFINED__
#define ___IOnModelExecEvents_FWD_DEFINED__
typedef interface _IOnModelExecEvents _IOnModelExecEvents;
#endif 	/* ___IOnModelExecEvents_FWD_DEFINED__ */


#ifndef __IOnEnv_FWD_DEFINED__
#define __IOnEnv_FWD_DEFINED__
typedef interface IOnEnv IOnEnv;
#endif 	/* __IOnEnv_FWD_DEFINED__ */


#ifndef __IsMatrix_FWD_DEFINED__
#define __IsMatrix_FWD_DEFINED__

#ifdef __cplusplus
typedef class IsMatrix IsMatrix;
#else
typedef struct IsMatrix IsMatrix;
#endif /* __cplusplus */

#endif 	/* __IsMatrix_FWD_DEFINED__ */


#ifndef __IsNlaSolver_FWD_DEFINED__
#define __IsNlaSolver_FWD_DEFINED__

#ifdef __cplusplus
typedef class IsNlaSolver IsNlaSolver;
#else
typedef struct IsNlaSolver IsNlaSolver;
#endif /* __cplusplus */

#endif 	/* __IsNlaSolver_FWD_DEFINED__ */


#ifndef __IsCINlaEso_FWD_DEFINED__
#define __IsCINlaEso_FWD_DEFINED__

#ifdef __cplusplus
typedef class IsCINlaEso IsCINlaEso;
#else
typedef struct IsCINlaEso IsCINlaEso;
#endif /* __cplusplus */

#endif 	/* __IsCINlaEso_FWD_DEFINED__ */


#ifndef __IsDaeEsoIImpl_FWD_DEFINED__
#define __IsDaeEsoIImpl_FWD_DEFINED__

#ifdef __cplusplus
typedef class IsDaeEsoIImpl IsDaeEsoIImpl;
#else
typedef struct IsDaeEsoIImpl IsDaeEsoIImpl;
#endif /* __cplusplus */

#endif 	/* __IsDaeEsoIImpl_FWD_DEFINED__ */


#ifndef __IsDaeEsoCImpl_FWD_DEFINED__
#define __IsDaeEsoCImpl_FWD_DEFINED__

#ifdef __cplusplus
typedef class IsDaeEsoCImpl IsDaeEsoCImpl;
#else
typedef struct IsDaeEsoCImpl IsDaeEsoCImpl;
#endif /* __cplusplus */

#endif 	/* __IsDaeEsoCImpl_FWD_DEFINED__ */


#ifndef __OnModelExec_FWD_DEFINED__
#define __OnModelExec_FWD_DEFINED__

#ifdef __cplusplus
typedef class OnModelExec OnModelExec;
#else
typedef struct OnModelExec OnModelExec;
#endif /* __cplusplus */

#endif 	/* __OnModelExec_FWD_DEFINED__ */


#ifndef __OnTest_FWD_DEFINED__
#define __OnTest_FWD_DEFINED__

#ifdef __cplusplus
typedef class OnTest OnTest;
#else
typedef struct OnTest OnTest;
#endif /* __cplusplus */

#endif 	/* __OnTest_FWD_DEFINED__ */


#ifndef __OnEnv_FWD_DEFINED__
#define __OnEnv_FWD_DEFINED__

#ifdef __cplusplus
typedef class OnEnv OnEnv;
#else
typedef struct OnEnv OnEnv;
#endif /* __cplusplus */

#endif 	/* __OnEnv_FWD_DEFINED__ */


/* header files for imported files */
#include "oaidl.h"
#include "ocidl.h"

void __RPC_FAR * __RPC_USER MIDL_user_allocate(size_t);
void __RPC_USER MIDL_user_free( void __RPC_FAR * ); 

/* interface __MIDL_itf_ISDaeCOSolver_0000 */
/* [local] */ 

typedef 
enum Jac_Calc_Method
    {	JCM_NC	= 0,
	JCM_AD	= JCM_NC + 1,
	JCM_NUM	= JCM_AD + 1,
	JCM_SYM	= JCM_NUM + 1,
	JCM_CONST	= JCM_SYM + 1
    }	Jac_Calc_Method;

typedef 
enum EqnForm
    {	EqnForm_Continuous	= 0,
	EqnForm_Discontinuous	= EqnForm_Continuous + 1,
	EqnForm_Reset	= EqnForm_Discontinuous + 1
    }	EqnForm;

typedef 
enum EqnDiffForm
    {	EqnDiffForm_Numeric	= 0,
	EqnDiffForm_Automatic	= EqnDiffForm_Numeric + 1,
	EqnDiffForm_Symbolic	= EqnDiffForm_Automatic + 1
    }	EqnDiffForm;

typedef 
enum SetType
    {	SetType_Balance	= 0,
	SetType_Equal	= SetType_Balance + 1
    }	SetType;

typedef 
enum InitStage
    {	InitStage_Init	= 0,
	InitStage_Reset	= InitStage_Init + 1,
	InitStage_Trim	= InitStage_Reset + 1,
	InitStage_Solve	= InitStage_Trim + 1
    }	InitStage;








extern RPC_IF_HANDLE __MIDL_itf_ISDaeCOSolver_0000_v0_0_c_ifspec;
extern RPC_IF_HANDLE __MIDL_itf_ISDaeCOSolver_0000_v0_0_s_ifspec;

#ifndef __IIsDaeEso_INTERFACE_DEFINED__
#define __IIsDaeEso_INTERFACE_DEFINED__

/* interface IIsDaeEso */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IIsDaeEso;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("EFA96FD0-B83D-11d4-839B-00600894E802")
    IIsDaeEso : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetRelTolerance( 
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *relTolValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRelTolerance( 
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *relTolValue) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAbsTolerance( 
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *absTolValues) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAbsTolerance( 
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *absTolValues) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAllResiduals( 
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *residuals,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *validVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetResiduals( 
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *residuals,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *validVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetJacobianStruct( 
            /* [out][in] */ long __RPC_FAR *nColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetJacobianValues( 
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *JacVals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAllJacobianValues( 
            /* [out] */ IIsMatrix __RPC_FAR *__RPC_FAR *ppJacVals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDiffJacobianStruct( 
            /* [out][in] */ long __RPC_FAR *nColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDiffJacobianValues( 
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *MassVals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAllDiffJacobianValues( 
            /* [out] */ IIsMatrix __RPC_FAR *__RPC_FAR *ppMassVals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVariables( 
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [in] */ double t,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVariable( 
            /* [in] */ long index,
            /* [in] */ double t,
            /* [out] */ double __RPC_FAR *val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVariableId( 
            /* [in] */ BSTR Name,
            /* [out] */ long __RPC_FAR *idx) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetVariables( 
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAllVariables( 
            /* [in] */ double t,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAllVariables( 
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDerivatives( 
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [in] */ double t,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDerivative( 
            /* [in] */ long index,
            /* [in] */ double t,
            /* [out] */ double __RPC_FAR *val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetDerivatives( 
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAllDerivatives( 
            /* [in] */ double t,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAllDerivatives( 
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNumVars( 
            /* [out] */ long __RPC_FAR *nVars) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNumEqns( 
            /* [out] */ long __RPC_FAR *nEqns) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNumLocalVars( 
            /* [out] */ long __RPC_FAR *nVars) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNumLocalEqns( 
            /* [out] */ long __RPC_FAR *nEqns) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetLastTime( 
            double __RPC_FAR *t) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTime( 
            double __RPC_FAR *t) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_ContainerIndex( 
            /* [retval][out] */ long __RPC_FAR *Index) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_ContainerIndex( 
            /* [in] */ long Index) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_VariableMap( 
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_VariableMap( 
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitTime( 
            /* [in] */ double StartTime,
            /* [in] */ VARIANT_BOOL bReverse) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetTime( 
            /* [in] */ double time) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetLastTime( 
            /* [in] */ double last_time) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVariablesIndex( 
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddEso( 
            /* [in] */ IIsDaeEso __RPC_FAR *pEso) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetEso( 
            /* [in] */ long index,
            /* [out] */ IIsDaeEso __RPC_FAR *__RPC_FAR *pEso) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE RemoveEso( 
            /* [in] */ long index) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNumEso( 
            /* [out] */ long __RPC_FAR *count) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetReportInfo( 
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
            /* [out] */ long __RPC_FAR *nStepSizeChanges) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EvalStateCondition( 
            /* [in] */ double ZeroCrossingTime,
            /* [in] */ long iDisEqn,
            /* [in] */ long iTransition,
            /* [out] */ VARIANT_BOOL __RPC_FAR *bEvent) = 0;
        
        virtual /* [helpstring][hidden][id] */ HRESULT STDMETHODCALLTYPE GetCPPPtr( 
            /* [out] */ DWORD __RPC_FAR *pIsDaeEso) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNumRealPars( 
            /* [out][in] */ long __RPC_FAR *nRPars) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRealPar( 
            /* [in] */ long index,
            /* [out][in] */ double __RPC_FAR *Val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRealParId( 
            /* [in] */ BSTR Name,
            /* [out][in] */ long __RPC_FAR *idx) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetRealPar( 
            /* [in] */ long index,
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNumIntPars( 
            /* [out][in] */ long __RPC_FAR *nIPars) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetIntPar( 
            /* [in] */ long index,
            /* [out][in] */ long __RPC_FAR *Val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetIntParId( 
            /* [in] */ BSTR Name,
            /* [out][in] */ long __RPC_FAR *idx) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetIntPar( 
            /* [in] */ long index,
            /* [in] */ long newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetModelExec( 
            /* [in] */ IOnModelExec __RPC_FAR *pModelExec) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PostStateEvent( 
            /* [in] */ double t,
            /* [in] */ BSTR EventId) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PostTransition( 
            /* [in] */ long iNewState) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PostRealParameter( 
            /* [in] */ double t,
            /* [in] */ long Id,
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PostIntegerParameter( 
            /* [in] */ double t,
            /* [in] */ long Id,
            /* [in] */ long newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIsDaeEsoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IIsDaeEso __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IIsDaeEso __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IIsDaeEso __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRelTolerance )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *relTolValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRelTolerance )( 
            IIsDaeEso __RPC_FAR * This,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *relTolValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAbsTolerance )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *absTolValues);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAbsTolerance )( 
            IIsDaeEso __RPC_FAR * This,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *absTolValues);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllResiduals )( 
            IIsDaeEso __RPC_FAR * This,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *residuals,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *validVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetResiduals )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *residuals,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *validVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetJacobianStruct )( 
            IIsDaeEso __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetJacobianValues )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *JacVals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllJacobianValues )( 
            IIsDaeEso __RPC_FAR * This,
            /* [out] */ IIsMatrix __RPC_FAR *__RPC_FAR *ppJacVals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDiffJacobianStruct )( 
            IIsDaeEso __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDiffJacobianValues )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *MassVals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllDiffJacobianValues )( 
            IIsDaeEso __RPC_FAR * This,
            /* [out] */ IIsMatrix __RPC_FAR *__RPC_FAR *ppMassVals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVariables )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [in] */ double t,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVariable )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ double t,
            /* [out] */ double __RPC_FAR *val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVariableId )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [out] */ long __RPC_FAR *idx);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVariables )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllVariables )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ double t,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAllVariables )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDerivatives )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [in] */ double t,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDerivative )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ double t,
            /* [out] */ double __RPC_FAR *val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDerivatives )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllDerivatives )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ double t,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAllDerivatives )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumVars )( 
            IIsDaeEso __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *nVars);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumEqns )( 
            IIsDaeEso __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *nEqns);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumLocalVars )( 
            IIsDaeEso __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *nVars);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumLocalEqns )( 
            IIsDaeEso __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *nEqns);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLastTime )( 
            IIsDaeEso __RPC_FAR * This,
            double __RPC_FAR *t);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTime )( 
            IIsDaeEso __RPC_FAR * This,
            double __RPC_FAR *t);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ContainerIndex )( 
            IIsDaeEso __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Index);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ContainerIndex )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ long Index);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_VariableMap )( 
            IIsDaeEso __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_VariableMap )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitTime )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ double StartTime,
            /* [in] */ VARIANT_BOOL bReverse);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTime )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ double time);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLastTime )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ double last_time);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVariablesIndex )( 
            IIsDaeEso __RPC_FAR * This,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddEso )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ IIsDaeEso __RPC_FAR *pEso);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEso )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ long index,
            /* [out] */ IIsDaeEso __RPC_FAR *__RPC_FAR *pEso);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveEso )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ long index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumEso )( 
            IIsDaeEso __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *count);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetReportInfo )( 
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
            /* [out] */ long __RPC_FAR *nStepSizeChanges);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EvalStateCondition )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ double ZeroCrossingTime,
            /* [in] */ long iDisEqn,
            /* [in] */ long iTransition,
            /* [out] */ VARIANT_BOOL __RPC_FAR *bEvent);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCPPPtr )( 
            IIsDaeEso __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pIsDaeEso);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumRealPars )( 
            IIsDaeEso __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nRPars);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRealPar )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ long index,
            /* [out][in] */ double __RPC_FAR *Val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRealParId )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [out][in] */ long __RPC_FAR *idx);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRealPar )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ double newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumIntPars )( 
            IIsDaeEso __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nIPars);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIntPar )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ long index,
            /* [out][in] */ long __RPC_FAR *Val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIntParId )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [out][in] */ long __RPC_FAR *idx);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetIntPar )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetModelExec )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ IOnModelExec __RPC_FAR *pModelExec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PostStateEvent )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ double t,
            /* [in] */ BSTR EventId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PostTransition )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ long iNewState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PostRealParameter )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ double t,
            /* [in] */ long Id,
            /* [in] */ double newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PostIntegerParameter )( 
            IIsDaeEso __RPC_FAR * This,
            /* [in] */ double t,
            /* [in] */ long Id,
            /* [in] */ long newVal);
        
        END_INTERFACE
    } IIsDaeEsoVtbl;

    interface IIsDaeEso
    {
        CONST_VTBL struct IIsDaeEsoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIsDaeEso_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IIsDaeEso_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IIsDaeEso_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IIsDaeEso_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IIsDaeEso_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IIsDaeEso_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IIsDaeEso_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IIsDaeEso_SetRelTolerance(This,relTolValue)	\
    (This)->lpVtbl -> SetRelTolerance(This,relTolValue)

#define IIsDaeEso_GetRelTolerance(This,relTolValue)	\
    (This)->lpVtbl -> GetRelTolerance(This,relTolValue)

#define IIsDaeEso_SetAbsTolerance(This,absTolValues)	\
    (This)->lpVtbl -> SetAbsTolerance(This,absTolValues)

#define IIsDaeEso_GetAbsTolerance(This,absTolValues)	\
    (This)->lpVtbl -> GetAbsTolerance(This,absTolValues)

#define IIsDaeEso_GetAllResiduals(This,residuals,validVal)	\
    (This)->lpVtbl -> GetAllResiduals(This,residuals,validVal)

#define IIsDaeEso_GetResiduals(This,Indices,residuals,validVal)	\
    (This)->lpVtbl -> GetResiduals(This,Indices,residuals,validVal)

#define IIsDaeEso_GetJacobianStruct(This,nColIndices,ColIndices,cNZCols,CalcMethod)	\
    (This)->lpVtbl -> GetJacobianStruct(This,nColIndices,ColIndices,cNZCols,CalcMethod)

#define IIsDaeEso_GetJacobianValues(This,Indices,JacVals)	\
    (This)->lpVtbl -> GetJacobianValues(This,Indices,JacVals)

#define IIsDaeEso_GetAllJacobianValues(This,ppJacVals)	\
    (This)->lpVtbl -> GetAllJacobianValues(This,ppJacVals)

#define IIsDaeEso_GetDiffJacobianStruct(This,nColIndices,ColIndices,cNZCols,CalcMethod)	\
    (This)->lpVtbl -> GetDiffJacobianStruct(This,nColIndices,ColIndices,cNZCols,CalcMethod)

#define IIsDaeEso_GetDiffJacobianValues(This,Indices,MassVals)	\
    (This)->lpVtbl -> GetDiffJacobianValues(This,Indices,MassVals)

#define IIsDaeEso_GetAllDiffJacobianValues(This,ppMassVals)	\
    (This)->lpVtbl -> GetAllDiffJacobianValues(This,ppMassVals)

#define IIsDaeEso_GetVariables(This,Indices,t,Vals)	\
    (This)->lpVtbl -> GetVariables(This,Indices,t,Vals)

#define IIsDaeEso_GetVariable(This,index,t,val)	\
    (This)->lpVtbl -> GetVariable(This,index,t,val)

#define IIsDaeEso_GetVariableId(This,Name,idx)	\
    (This)->lpVtbl -> GetVariableId(This,Name,idx)

#define IIsDaeEso_SetVariables(This,Indices,Vals)	\
    (This)->lpVtbl -> SetVariables(This,Indices,Vals)

#define IIsDaeEso_GetAllVariables(This,t,Vals)	\
    (This)->lpVtbl -> GetAllVariables(This,t,Vals)

#define IIsDaeEso_SetAllVariables(This,Vals)	\
    (This)->lpVtbl -> SetAllVariables(This,Vals)

#define IIsDaeEso_GetDerivatives(This,Indices,t,Vals)	\
    (This)->lpVtbl -> GetDerivatives(This,Indices,t,Vals)

#define IIsDaeEso_GetDerivative(This,index,t,val)	\
    (This)->lpVtbl -> GetDerivative(This,index,t,val)

#define IIsDaeEso_SetDerivatives(This,Indices,Vals)	\
    (This)->lpVtbl -> SetDerivatives(This,Indices,Vals)

#define IIsDaeEso_GetAllDerivatives(This,t,Vals)	\
    (This)->lpVtbl -> GetAllDerivatives(This,t,Vals)

#define IIsDaeEso_SetAllDerivatives(This,Vals)	\
    (This)->lpVtbl -> SetAllDerivatives(This,Vals)

#define IIsDaeEso_GetNumVars(This,nVars)	\
    (This)->lpVtbl -> GetNumVars(This,nVars)

#define IIsDaeEso_GetNumEqns(This,nEqns)	\
    (This)->lpVtbl -> GetNumEqns(This,nEqns)

#define IIsDaeEso_GetNumLocalVars(This,nVars)	\
    (This)->lpVtbl -> GetNumLocalVars(This,nVars)

#define IIsDaeEso_GetNumLocalEqns(This,nEqns)	\
    (This)->lpVtbl -> GetNumLocalEqns(This,nEqns)

#define IIsDaeEso_GetLastTime(This,t)	\
    (This)->lpVtbl -> GetLastTime(This,t)

#define IIsDaeEso_GetTime(This,t)	\
    (This)->lpVtbl -> GetTime(This,t)

#define IIsDaeEso_get_ContainerIndex(This,Index)	\
    (This)->lpVtbl -> get_ContainerIndex(This,Index)

#define IIsDaeEso_put_ContainerIndex(This,Index)	\
    (This)->lpVtbl -> put_ContainerIndex(This,Index)

#define IIsDaeEso_get_VariableMap(This,pVal)	\
    (This)->lpVtbl -> get_VariableMap(This,pVal)

#define IIsDaeEso_put_VariableMap(This,newVal)	\
    (This)->lpVtbl -> put_VariableMap(This,newVal)

#define IIsDaeEso_InitTime(This,StartTime,bReverse)	\
    (This)->lpVtbl -> InitTime(This,StartTime,bReverse)

#define IIsDaeEso_SetTime(This,time)	\
    (This)->lpVtbl -> SetTime(This,time)

#define IIsDaeEso_SetLastTime(This,last_time)	\
    (This)->lpVtbl -> SetLastTime(This,last_time)

#define IIsDaeEso_GetVariablesIndex(This,Index)	\
    (This)->lpVtbl -> GetVariablesIndex(This,Index)

#define IIsDaeEso_AddEso(This,pEso)	\
    (This)->lpVtbl -> AddEso(This,pEso)

#define IIsDaeEso_GetEso(This,index,pEso)	\
    (This)->lpVtbl -> GetEso(This,index,pEso)

#define IIsDaeEso_RemoveEso(This,index)	\
    (This)->lpVtbl -> RemoveEso(This,index)

#define IIsDaeEso_GetNumEso(This,count)	\
    (This)->lpVtbl -> GetNumEso(This,count)

#define IIsDaeEso_GetReportInfo(This,StepperCalls,functionCalls,jacobiansCalls,DecompCalls,Substitutions,TotalSteps,errorRejectedSteps,newtonRejectedSteps,growthRejectedSteps,funcRejectedSteps,nStateEvents,nParameterEvents,nStepSizeChanges)	\
    (This)->lpVtbl -> GetReportInfo(This,StepperCalls,functionCalls,jacobiansCalls,DecompCalls,Substitutions,TotalSteps,errorRejectedSteps,newtonRejectedSteps,growthRejectedSteps,funcRejectedSteps,nStateEvents,nParameterEvents,nStepSizeChanges)

#define IIsDaeEso_EvalStateCondition(This,ZeroCrossingTime,iDisEqn,iTransition,bEvent)	\
    (This)->lpVtbl -> EvalStateCondition(This,ZeroCrossingTime,iDisEqn,iTransition,bEvent)

#define IIsDaeEso_GetCPPPtr(This,pIsDaeEso)	\
    (This)->lpVtbl -> GetCPPPtr(This,pIsDaeEso)

#define IIsDaeEso_GetNumRealPars(This,nRPars)	\
    (This)->lpVtbl -> GetNumRealPars(This,nRPars)

#define IIsDaeEso_GetRealPar(This,index,Val)	\
    (This)->lpVtbl -> GetRealPar(This,index,Val)

#define IIsDaeEso_GetRealParId(This,Name,idx)	\
    (This)->lpVtbl -> GetRealParId(This,Name,idx)

#define IIsDaeEso_SetRealPar(This,index,newVal)	\
    (This)->lpVtbl -> SetRealPar(This,index,newVal)

#define IIsDaeEso_GetNumIntPars(This,nIPars)	\
    (This)->lpVtbl -> GetNumIntPars(This,nIPars)

#define IIsDaeEso_GetIntPar(This,index,Val)	\
    (This)->lpVtbl -> GetIntPar(This,index,Val)

#define IIsDaeEso_GetIntParId(This,Name,idx)	\
    (This)->lpVtbl -> GetIntParId(This,Name,idx)

#define IIsDaeEso_SetIntPar(This,index,newVal)	\
    (This)->lpVtbl -> SetIntPar(This,index,newVal)

#define IIsDaeEso_SetModelExec(This,pModelExec)	\
    (This)->lpVtbl -> SetModelExec(This,pModelExec)

#define IIsDaeEso_PostStateEvent(This,t,EventId)	\
    (This)->lpVtbl -> PostStateEvent(This,t,EventId)

#define IIsDaeEso_PostTransition(This,iNewState)	\
    (This)->lpVtbl -> PostTransition(This,iNewState)

#define IIsDaeEso_PostRealParameter(This,t,Id,newVal)	\
    (This)->lpVtbl -> PostRealParameter(This,t,Id,newVal)

#define IIsDaeEso_PostIntegerParameter(This,t,Id,newVal)	\
    (This)->lpVtbl -> PostIntegerParameter(This,t,Id,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_SetRelTolerance_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *relTolValue);


void __RPC_STUB IIsDaeEso_SetRelTolerance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetRelTolerance_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *relTolValue);


void __RPC_STUB IIsDaeEso_GetRelTolerance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_SetAbsTolerance_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *absTolValues);


void __RPC_STUB IIsDaeEso_SetAbsTolerance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetAbsTolerance_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *absTolValues);


void __RPC_STUB IIsDaeEso_GetAbsTolerance_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetAllResiduals_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *residuals,
    /* [out][in] */ VARIANT_BOOL __RPC_FAR *validVal);


void __RPC_STUB IIsDaeEso_GetAllResiduals_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetResiduals_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *residuals,
    /* [out][in] */ VARIANT_BOOL __RPC_FAR *validVal);


void __RPC_STUB IIsDaeEso_GetResiduals_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetJacobianStruct_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nColIndices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod);


void __RPC_STUB IIsDaeEso_GetJacobianStruct_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetJacobianValues_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *JacVals);


void __RPC_STUB IIsDaeEso_GetJacobianValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetAllJacobianValues_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out] */ IIsMatrix __RPC_FAR *__RPC_FAR *ppJacVals);


void __RPC_STUB IIsDaeEso_GetAllJacobianValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetDiffJacobianStruct_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nColIndices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod);


void __RPC_STUB IIsDaeEso_GetDiffJacobianStruct_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetDiffJacobianValues_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *MassVals);


void __RPC_STUB IIsDaeEso_GetDiffJacobianValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetAllDiffJacobianValues_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out] */ IIsMatrix __RPC_FAR *__RPC_FAR *ppMassVals);


void __RPC_STUB IIsDaeEso_GetAllDiffJacobianValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetVariables_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
    /* [in] */ double t,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);


void __RPC_STUB IIsDaeEso_GetVariables_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetVariable_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ double t,
    /* [out] */ double __RPC_FAR *val);


void __RPC_STUB IIsDaeEso_GetVariable_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetVariableId_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [out] */ long __RPC_FAR *idx);


void __RPC_STUB IIsDaeEso_GetVariableId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_SetVariables_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);


void __RPC_STUB IIsDaeEso_SetVariables_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetAllVariables_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ double t,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);


void __RPC_STUB IIsDaeEso_GetAllVariables_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_SetAllVariables_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);


void __RPC_STUB IIsDaeEso_SetAllVariables_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetDerivatives_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
    /* [in] */ double t,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);


void __RPC_STUB IIsDaeEso_GetDerivatives_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetDerivative_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ double t,
    /* [out] */ double __RPC_FAR *val);


void __RPC_STUB IIsDaeEso_GetDerivative_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_SetDerivatives_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);


void __RPC_STUB IIsDaeEso_SetDerivatives_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetAllDerivatives_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ double t,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);


void __RPC_STUB IIsDaeEso_GetAllDerivatives_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_SetAllDerivatives_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);


void __RPC_STUB IIsDaeEso_SetAllDerivatives_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetNumVars_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *nVars);


void __RPC_STUB IIsDaeEso_GetNumVars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetNumEqns_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *nEqns);


void __RPC_STUB IIsDaeEso_GetNumEqns_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetNumLocalVars_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *nVars);


void __RPC_STUB IIsDaeEso_GetNumLocalVars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetNumLocalEqns_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *nEqns);


void __RPC_STUB IIsDaeEso_GetNumLocalEqns_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetLastTime_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    double __RPC_FAR *t);


void __RPC_STUB IIsDaeEso_GetLastTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetTime_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    double __RPC_FAR *t);


void __RPC_STUB IIsDaeEso_GetTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_get_ContainerIndex_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [retval][out] */ long __RPC_FAR *Index);


void __RPC_STUB IIsDaeEso_get_ContainerIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_put_ContainerIndex_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ long Index);


void __RPC_STUB IIsDaeEso_put_ContainerIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_get_VariableMap_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pVal);


void __RPC_STUB IIsDaeEso_get_VariableMap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_put_VariableMap_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *newVal);


void __RPC_STUB IIsDaeEso_put_VariableMap_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_InitTime_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ double StartTime,
    /* [in] */ VARIANT_BOOL bReverse);


void __RPC_STUB IIsDaeEso_InitTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_SetTime_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ double time);


void __RPC_STUB IIsDaeEso_SetTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_SetLastTime_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ double last_time);


void __RPC_STUB IIsDaeEso_SetLastTime_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetVariablesIndex_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Index);


void __RPC_STUB IIsDaeEso_GetVariablesIndex_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_AddEso_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ IIsDaeEso __RPC_FAR *pEso);


void __RPC_STUB IIsDaeEso_AddEso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetEso_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ long index,
    /* [out] */ IIsDaeEso __RPC_FAR *__RPC_FAR *pEso);


void __RPC_STUB IIsDaeEso_GetEso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_RemoveEso_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ long index);


void __RPC_STUB IIsDaeEso_RemoveEso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetNumEso_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out] */ long __RPC_FAR *count);


void __RPC_STUB IIsDaeEso_GetNumEso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


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
    /* [out] */ long __RPC_FAR *nStepSizeChanges);


void __RPC_STUB IIsDaeEso_GetReportInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_EvalStateCondition_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ double ZeroCrossingTime,
    /* [in] */ long iDisEqn,
    /* [in] */ long iTransition,
    /* [out] */ VARIANT_BOOL __RPC_FAR *bEvent);


void __RPC_STUB IIsDaeEso_EvalStateCondition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][hidden][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetCPPPtr_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out] */ DWORD __RPC_FAR *pIsDaeEso);


void __RPC_STUB IIsDaeEso_GetCPPPtr_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetNumRealPars_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nRPars);


void __RPC_STUB IIsDaeEso_GetNumRealPars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetRealPar_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ long index,
    /* [out][in] */ double __RPC_FAR *Val);


void __RPC_STUB IIsDaeEso_GetRealPar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetRealParId_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [out][in] */ long __RPC_FAR *idx);


void __RPC_STUB IIsDaeEso_GetRealParId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_SetRealPar_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ double newVal);


void __RPC_STUB IIsDaeEso_SetRealPar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetNumIntPars_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nIPars);


void __RPC_STUB IIsDaeEso_GetNumIntPars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetIntPar_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ long index,
    /* [out][in] */ long __RPC_FAR *Val);


void __RPC_STUB IIsDaeEso_GetIntPar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_GetIntParId_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [out][in] */ long __RPC_FAR *idx);


void __RPC_STUB IIsDaeEso_GetIntParId_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_SetIntPar_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ long index,
    /* [in] */ long newVal);


void __RPC_STUB IIsDaeEso_SetIntPar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_SetModelExec_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ IOnModelExec __RPC_FAR *pModelExec);


void __RPC_STUB IIsDaeEso_SetModelExec_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_PostStateEvent_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ double t,
    /* [in] */ BSTR EventId);


void __RPC_STUB IIsDaeEso_PostStateEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_PostTransition_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ long iNewState);


void __RPC_STUB IIsDaeEso_PostTransition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_PostRealParameter_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ double t,
    /* [in] */ long Id,
    /* [in] */ double newVal);


void __RPC_STUB IIsDaeEso_PostRealParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEso_PostIntegerParameter_Proxy( 
    IIsDaeEso __RPC_FAR * This,
    /* [in] */ double t,
    /* [in] */ long Id,
    /* [in] */ long newVal);


void __RPC_STUB IIsDaeEso_PostIntegerParameter_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IIsDaeEso_INTERFACE_DEFINED__ */


#ifndef __IIsMatrix_INTERFACE_DEFINED__
#define __IIsMatrix_INTERFACE_DEFINED__

/* interface IIsMatrix */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IIsMatrix;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("3F35CF66-839E-11D4-838D-00600894E802")
    IIsMatrix : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Init( 
            /* [in] */ long nRows,
            /* [in] */ long nCols) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetData( 
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Attach( 
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Detach( 
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRow( 
            /* [in] */ long Row,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetRow( 
            /* [in] */ long Row,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetCol( 
            /* [in] */ long Col,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetCol( 
            /* [in] */ long Col,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Value( 
            /* [in] */ long Row,
            /* [in] */ long Col,
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Value( 
            /* [in] */ long Row,
            /* [in] */ long Col,
            /* [in] */ double Val) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIsMatrixVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IIsMatrix __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IIsMatrix __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IIsMatrix __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IIsMatrix __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IIsMatrix __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IIsMatrix __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IIsMatrix __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Init )( 
            IIsMatrix __RPC_FAR * This,
            /* [in] */ long nRows,
            /* [in] */ long nCols);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetData )( 
            IIsMatrix __RPC_FAR * This,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Attach )( 
            IIsMatrix __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Detach )( 
            IIsMatrix __RPC_FAR * This,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRow )( 
            IIsMatrix __RPC_FAR * This,
            /* [in] */ long Row,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRow )( 
            IIsMatrix __RPC_FAR * This,
            /* [in] */ long Row,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCol )( 
            IIsMatrix __RPC_FAR * This,
            /* [in] */ long Col,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetCol )( 
            IIsMatrix __RPC_FAR * This,
            /* [in] */ long Col,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Value )( 
            IIsMatrix __RPC_FAR * This,
            /* [in] */ long Row,
            /* [in] */ long Col,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Value )( 
            IIsMatrix __RPC_FAR * This,
            /* [in] */ long Row,
            /* [in] */ long Col,
            /* [in] */ double Val);
        
        END_INTERFACE
    } IIsMatrixVtbl;

    interface IIsMatrix
    {
        CONST_VTBL struct IIsMatrixVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIsMatrix_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IIsMatrix_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IIsMatrix_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IIsMatrix_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IIsMatrix_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IIsMatrix_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IIsMatrix_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IIsMatrix_Init(This,nRows,nCols)	\
    (This)->lpVtbl -> Init(This,nRows,nCols)

#define IIsMatrix_GetData(This,Vals)	\
    (This)->lpVtbl -> GetData(This,Vals)

#define IIsMatrix_Attach(This,Vals)	\
    (This)->lpVtbl -> Attach(This,Vals)

#define IIsMatrix_Detach(This,Vals)	\
    (This)->lpVtbl -> Detach(This,Vals)

#define IIsMatrix_GetRow(This,Row,Vals)	\
    (This)->lpVtbl -> GetRow(This,Row,Vals)

#define IIsMatrix_SetRow(This,Row,Vals)	\
    (This)->lpVtbl -> SetRow(This,Row,Vals)

#define IIsMatrix_GetCol(This,Col,Vals)	\
    (This)->lpVtbl -> GetCol(This,Col,Vals)

#define IIsMatrix_SetCol(This,Col,Vals)	\
    (This)->lpVtbl -> SetCol(This,Col,Vals)

#define IIsMatrix_get_Value(This,Row,Col,pVal)	\
    (This)->lpVtbl -> get_Value(This,Row,Col,pVal)

#define IIsMatrix_put_Value(This,Row,Col,Val)	\
    (This)->lpVtbl -> put_Value(This,Row,Col,Val)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsMatrix_Init_Proxy( 
    IIsMatrix __RPC_FAR * This,
    /* [in] */ long nRows,
    /* [in] */ long nCols);


void __RPC_STUB IIsMatrix_Init_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsMatrix_GetData_Proxy( 
    IIsMatrix __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);


void __RPC_STUB IIsMatrix_GetData_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsMatrix_Attach_Proxy( 
    IIsMatrix __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);


void __RPC_STUB IIsMatrix_Attach_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsMatrix_Detach_Proxy( 
    IIsMatrix __RPC_FAR * This,
    /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);


void __RPC_STUB IIsMatrix_Detach_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsMatrix_GetRow_Proxy( 
    IIsMatrix __RPC_FAR * This,
    /* [in] */ long Row,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);


void __RPC_STUB IIsMatrix_GetRow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsMatrix_SetRow_Proxy( 
    IIsMatrix __RPC_FAR * This,
    /* [in] */ long Row,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);


void __RPC_STUB IIsMatrix_SetRow_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsMatrix_GetCol_Proxy( 
    IIsMatrix __RPC_FAR * This,
    /* [in] */ long Col,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);


void __RPC_STUB IIsMatrix_GetCol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsMatrix_SetCol_Proxy( 
    IIsMatrix __RPC_FAR * This,
    /* [in] */ long Col,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);


void __RPC_STUB IIsMatrix_SetCol_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IIsMatrix_get_Value_Proxy( 
    IIsMatrix __RPC_FAR * This,
    /* [in] */ long Row,
    /* [in] */ long Col,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IIsMatrix_get_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IIsMatrix_put_Value_Proxy( 
    IIsMatrix __RPC_FAR * This,
    /* [in] */ long Row,
    /* [in] */ long Col,
    /* [in] */ double Val);


void __RPC_STUB IIsMatrix_put_Value_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IIsMatrix_INTERFACE_DEFINED__ */


#ifndef __IIsNlaSolver_INTERFACE_DEFINED__
#define __IIsNlaSolver_INTERFACE_DEFINED__

/* interface IIsNlaSolver */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IIsNlaSolver;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("717E8183-92E1-11D4-98A8-00C04F6801A9")
    IIsNlaSolver : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetEso( 
            /* [in] */ IIsNlaEso __RPC_FAR *pEso) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Solve( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIsNlaSolverVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IIsNlaSolver __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IIsNlaSolver __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IIsNlaSolver __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IIsNlaSolver __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IIsNlaSolver __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IIsNlaSolver __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IIsNlaSolver __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEso )( 
            IIsNlaSolver __RPC_FAR * This,
            /* [in] */ IIsNlaEso __RPC_FAR *pEso);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Solve )( 
            IIsNlaSolver __RPC_FAR * This);
        
        END_INTERFACE
    } IIsNlaSolverVtbl;

    interface IIsNlaSolver
    {
        CONST_VTBL struct IIsNlaSolverVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIsNlaSolver_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IIsNlaSolver_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IIsNlaSolver_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IIsNlaSolver_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IIsNlaSolver_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IIsNlaSolver_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IIsNlaSolver_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IIsNlaSolver_SetEso(This,pEso)	\
    (This)->lpVtbl -> SetEso(This,pEso)

#define IIsNlaSolver_Solve(This)	\
    (This)->lpVtbl -> Solve(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsNlaSolver_SetEso_Proxy( 
    IIsNlaSolver __RPC_FAR * This,
    /* [in] */ IIsNlaEso __RPC_FAR *pEso);


void __RPC_STUB IIsNlaSolver_SetEso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsNlaSolver_Solve_Proxy( 
    IIsNlaSolver __RPC_FAR * This);


void __RPC_STUB IIsNlaSolver_Solve_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IIsNlaSolver_INTERFACE_DEFINED__ */


#ifndef __IIsNlaEso_INTERFACE_DEFINED__
#define __IIsNlaEso_INTERFACE_DEFINED__

/* interface IIsNlaEso */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IIsNlaEso;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("A6A32B44-92E2-11d4-98A8-00C04F6801A9")
    IIsNlaEso : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNumEqns( 
            /* [out][in] */ long __RPC_FAR *nEqns) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetNumVars( 
            /* [out][in] */ long __RPC_FAR *nVars) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAllVariables( 
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetAllVariables( 
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetResiduals( 
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *x,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *residuals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetResidual( 
            /* [in] */ long iEqn,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *x,
            /* [out][in] */ double __RPC_FAR *residual) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetJacobianStruct( 
            /* [out][in] */ long __RPC_FAR *nColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetJacobianValues( 
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *JacVals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetAllJacobianValues( 
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *JacVals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Solve( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIsNlaEsoVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IIsNlaEso __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IIsNlaEso __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IIsNlaEso __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IIsNlaEso __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IIsNlaEso __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IIsNlaEso __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IIsNlaEso __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumEqns )( 
            IIsNlaEso __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nEqns);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumVars )( 
            IIsNlaEso __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nVars);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllVariables )( 
            IIsNlaEso __RPC_FAR * This,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAllVariables )( 
            IIsNlaEso __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetResiduals )( 
            IIsNlaEso __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *x,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *residuals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetResidual )( 
            IIsNlaEso __RPC_FAR * This,
            /* [in] */ long iEqn,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *x,
            /* [out][in] */ double __RPC_FAR *residual);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetJacobianStruct )( 
            IIsNlaEso __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetJacobianValues )( 
            IIsNlaEso __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *JacVals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllJacobianValues )( 
            IIsNlaEso __RPC_FAR * This,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *JacVals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Solve )( 
            IIsNlaEso __RPC_FAR * This);
        
        END_INTERFACE
    } IIsNlaEsoVtbl;

    interface IIsNlaEso
    {
        CONST_VTBL struct IIsNlaEsoVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIsNlaEso_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IIsNlaEso_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IIsNlaEso_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IIsNlaEso_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IIsNlaEso_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IIsNlaEso_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IIsNlaEso_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IIsNlaEso_GetNumEqns(This,nEqns)	\
    (This)->lpVtbl -> GetNumEqns(This,nEqns)

#define IIsNlaEso_GetNumVars(This,nVars)	\
    (This)->lpVtbl -> GetNumVars(This,nVars)

#define IIsNlaEso_GetAllVariables(This,Vals)	\
    (This)->lpVtbl -> GetAllVariables(This,Vals)

#define IIsNlaEso_SetAllVariables(This,Vals)	\
    (This)->lpVtbl -> SetAllVariables(This,Vals)

#define IIsNlaEso_GetResiduals(This,x,residuals)	\
    (This)->lpVtbl -> GetResiduals(This,x,residuals)

#define IIsNlaEso_GetResidual(This,iEqn,x,residual)	\
    (This)->lpVtbl -> GetResidual(This,iEqn,x,residual)

#define IIsNlaEso_GetJacobianStruct(This,nColIndices,ColIndices,cNZCols,CalcMethod)	\
    (This)->lpVtbl -> GetJacobianStruct(This,nColIndices,ColIndices,cNZCols,CalcMethod)

#define IIsNlaEso_GetJacobianValues(This,Indices,JacVals)	\
    (This)->lpVtbl -> GetJacobianValues(This,Indices,JacVals)

#define IIsNlaEso_GetAllJacobianValues(This,Indices,JacVals)	\
    (This)->lpVtbl -> GetAllJacobianValues(This,Indices,JacVals)

#define IIsNlaEso_Solve(This)	\
    (This)->lpVtbl -> Solve(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsNlaEso_GetNumEqns_Proxy( 
    IIsNlaEso __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nEqns);


void __RPC_STUB IIsNlaEso_GetNumEqns_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsNlaEso_GetNumVars_Proxy( 
    IIsNlaEso __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nVars);


void __RPC_STUB IIsNlaEso_GetNumVars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsNlaEso_GetAllVariables_Proxy( 
    IIsNlaEso __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);


void __RPC_STUB IIsNlaEso_GetAllVariables_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsNlaEso_SetAllVariables_Proxy( 
    IIsNlaEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);


void __RPC_STUB IIsNlaEso_SetAllVariables_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsNlaEso_GetResiduals_Proxy( 
    IIsNlaEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *x,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *residuals);


void __RPC_STUB IIsNlaEso_GetResiduals_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsNlaEso_GetResidual_Proxy( 
    IIsNlaEso __RPC_FAR * This,
    /* [in] */ long iEqn,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *x,
    /* [out][in] */ double __RPC_FAR *residual);


void __RPC_STUB IIsNlaEso_GetResidual_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsNlaEso_GetJacobianStruct_Proxy( 
    IIsNlaEso __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nColIndices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod);


void __RPC_STUB IIsNlaEso_GetJacobianStruct_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsNlaEso_GetJacobianValues_Proxy( 
    IIsNlaEso __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *JacVals);


void __RPC_STUB IIsNlaEso_GetJacobianValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsNlaEso_GetAllJacobianValues_Proxy( 
    IIsNlaEso __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *JacVals);


void __RPC_STUB IIsNlaEso_GetAllJacobianValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsNlaEso_Solve_Proxy( 
    IIsNlaEso __RPC_FAR * This);


void __RPC_STUB IIsNlaEso_Solve_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IIsNlaEso_INTERFACE_DEFINED__ */


#ifndef __IIsDaeEsoImpl_INTERFACE_DEFINED__
#define __IIsDaeEsoImpl_INTERFACE_DEFINED__

/* interface IIsDaeEsoImpl */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IIsDaeEsoImpl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BFC328F0-CBF6-11d4-83A2-00600894E802")
    IIsDaeEsoImpl : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Initialize( 
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
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ipar) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetJacobianStruct( 
            /* [out][in] */ long __RPC_FAR *nColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDiffJacobianStruct( 
            /* [out][in] */ long __RPC_FAR *nColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetResiduals( 
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *iEqn,
            /* [in] */ long nEqn,
            /* [in] */ double t,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *x,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *xdot,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *rPar,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *iPar,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *residuals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetJacobianValues( 
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *iJac,
            /* [in] */ long nJac,
            /* [in] */ double t,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *x,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *xdot,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *rPar,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *iPar,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *jacobians) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetDiffJacobianValues( 
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *iJac,
            /* [in] */ long nJac,
            /* [in] */ double t,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *x,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *xdot,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *rPar,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *iPar,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *jacobians) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetEqnForm( 
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *form,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *diff_form) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE EvalStateCondition( 
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *EqnState,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *x,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *xdot,
            /* [in] */ double EventTime,
            /* [in] */ long iDisEqn,
            /* [in] */ long iTransition,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *bEvent) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMemberEsos( 
            /* [out][in] */ long __RPC_FAR *nEsos,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Esos) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetSTNStruct( 
            /* [out][in] */ long __RPC_FAR *nStates,
            /* [out][in] */ long __RPC_FAR *nTransitions,
            /* [out][in] */ long __RPC_FAR *iDefaultState,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TransEventIds,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *SrcStates,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *StateToEqnMap,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TransToEqnMap) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE TriggerEvent( 
            /* [in] */ double EventTime,
            /* [in] */ BSTR EventId,
            /* [in] */ long iEventEqn) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetMasterNodeStatus( 
            VARIANT_BOOL __RPC_FAR *bMasterNodeStatus) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIsDaeEsoImplVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IIsDaeEsoImpl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IIsDaeEsoImpl __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IIsDaeEsoImpl __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IIsDaeEsoImpl __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IIsDaeEsoImpl __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IIsDaeEsoImpl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IIsDaeEsoImpl __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Initialize )( 
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
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ipar);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetJacobianStruct )( 
            IIsDaeEsoImpl __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDiffJacobianStruct )( 
            IIsDaeEsoImpl __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetResiduals )( 
            IIsDaeEsoImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *iEqn,
            /* [in] */ long nEqn,
            /* [in] */ double t,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *x,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *xdot,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *rPar,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *iPar,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *residuals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetJacobianValues )( 
            IIsDaeEsoImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *iJac,
            /* [in] */ long nJac,
            /* [in] */ double t,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *x,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *xdot,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *rPar,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *iPar,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *jacobians);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDiffJacobianValues )( 
            IIsDaeEsoImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *iJac,
            /* [in] */ long nJac,
            /* [in] */ double t,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *x,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *xdot,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *rPar,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *iPar,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *jacobians);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEqnForm )( 
            IIsDaeEsoImpl __RPC_FAR * This,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *form,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *diff_form);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EvalStateCondition )( 
            IIsDaeEsoImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *EqnState,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *x,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *xdot,
            /* [in] */ double EventTime,
            /* [in] */ long iDisEqn,
            /* [in] */ long iTransition,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *bEvent);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMemberEsos )( 
            IIsDaeEsoImpl __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nEsos,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Esos);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetSTNStruct )( 
            IIsDaeEsoImpl __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nStates,
            /* [out][in] */ long __RPC_FAR *nTransitions,
            /* [out][in] */ long __RPC_FAR *iDefaultState,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TransEventIds,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *SrcStates,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *StateToEqnMap,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TransToEqnMap);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *TriggerEvent )( 
            IIsDaeEsoImpl __RPC_FAR * This,
            /* [in] */ double EventTime,
            /* [in] */ BSTR EventId,
            /* [in] */ long iEventEqn);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetMasterNodeStatus )( 
            IIsDaeEsoImpl __RPC_FAR * This,
            VARIANT_BOOL __RPC_FAR *bMasterNodeStatus);
        
        END_INTERFACE
    } IIsDaeEsoImplVtbl;

    interface IIsDaeEsoImpl
    {
        CONST_VTBL struct IIsDaeEsoImplVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIsDaeEsoImpl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IIsDaeEsoImpl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IIsDaeEsoImpl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IIsDaeEsoImpl_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IIsDaeEsoImpl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IIsDaeEsoImpl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IIsDaeEsoImpl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IIsDaeEsoImpl_Initialize(This,nEqns,nVars,nRPars,nIPars,t,atol,rtol,x,xdot,rpar,ipar)	\
    (This)->lpVtbl -> Initialize(This,nEqns,nVars,nRPars,nIPars,t,atol,rtol,x,xdot,rpar,ipar)

#define IIsDaeEsoImpl_GetJacobianStruct(This,nColIndices,ColIndices,cNZCols,CalcMethod)	\
    (This)->lpVtbl -> GetJacobianStruct(This,nColIndices,ColIndices,cNZCols,CalcMethod)

#define IIsDaeEsoImpl_GetDiffJacobianStruct(This,nColIndices,ColIndices,cNZCols,CalcMethod)	\
    (This)->lpVtbl -> GetDiffJacobianStruct(This,nColIndices,ColIndices,cNZCols,CalcMethod)

#define IIsDaeEsoImpl_GetResiduals(This,iEqn,nEqn,t,x,xdot,rPar,iPar,residuals)	\
    (This)->lpVtbl -> GetResiduals(This,iEqn,nEqn,t,x,xdot,rPar,iPar,residuals)

#define IIsDaeEsoImpl_GetJacobianValues(This,iJac,nJac,t,x,xdot,rPar,iPar,jacobians)	\
    (This)->lpVtbl -> GetJacobianValues(This,iJac,nJac,t,x,xdot,rPar,iPar,jacobians)

#define IIsDaeEsoImpl_GetDiffJacobianValues(This,iJac,nJac,t,x,xdot,rPar,iPar,jacobians)	\
    (This)->lpVtbl -> GetDiffJacobianValues(This,iJac,nJac,t,x,xdot,rPar,iPar,jacobians)

#define IIsDaeEsoImpl_GetEqnForm(This,form,diff_form)	\
    (This)->lpVtbl -> GetEqnForm(This,form,diff_form)

#define IIsDaeEsoImpl_EvalStateCondition(This,EqnState,x,xdot,EventTime,iDisEqn,iTransition,bEvent)	\
    (This)->lpVtbl -> EvalStateCondition(This,EqnState,x,xdot,EventTime,iDisEqn,iTransition,bEvent)

#define IIsDaeEsoImpl_GetMemberEsos(This,nEsos,Esos)	\
    (This)->lpVtbl -> GetMemberEsos(This,nEsos,Esos)

#define IIsDaeEsoImpl_GetSTNStruct(This,nStates,nTransitions,iDefaultState,TransEventIds,SrcStates,StateToEqnMap,TransToEqnMap)	\
    (This)->lpVtbl -> GetSTNStruct(This,nStates,nTransitions,iDefaultState,TransEventIds,SrcStates,StateToEqnMap,TransToEqnMap)

#define IIsDaeEsoImpl_TriggerEvent(This,EventTime,EventId,iEventEqn)	\
    (This)->lpVtbl -> TriggerEvent(This,EventTime,EventId,iEventEqn)

#define IIsDaeEsoImpl_GetMasterNodeStatus(This,bMasterNodeStatus)	\
    (This)->lpVtbl -> GetMasterNodeStatus(This,bMasterNodeStatus)

#endif /* COBJMACROS */


#endif 	/* C style interface */



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
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ipar);


void __RPC_STUB IIsDaeEsoImpl_Initialize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoImpl_GetJacobianStruct_Proxy( 
    IIsDaeEsoImpl __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nColIndices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod);


void __RPC_STUB IIsDaeEsoImpl_GetJacobianStruct_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoImpl_GetDiffJacobianStruct_Proxy( 
    IIsDaeEsoImpl __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nColIndices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod);


void __RPC_STUB IIsDaeEsoImpl_GetDiffJacobianStruct_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoImpl_GetResiduals_Proxy( 
    IIsDaeEsoImpl __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *iEqn,
    /* [in] */ long nEqn,
    /* [in] */ double t,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *x,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *xdot,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *rPar,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *iPar,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *residuals);


void __RPC_STUB IIsDaeEsoImpl_GetResiduals_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoImpl_GetJacobianValues_Proxy( 
    IIsDaeEsoImpl __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *iJac,
    /* [in] */ long nJac,
    /* [in] */ double t,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *x,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *xdot,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *rPar,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *iPar,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *jacobians);


void __RPC_STUB IIsDaeEsoImpl_GetJacobianValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoImpl_GetDiffJacobianValues_Proxy( 
    IIsDaeEsoImpl __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *iJac,
    /* [in] */ long nJac,
    /* [in] */ double t,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *x,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *xdot,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *rPar,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *iPar,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *jacobians);


void __RPC_STUB IIsDaeEsoImpl_GetDiffJacobianValues_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoImpl_GetEqnForm_Proxy( 
    IIsDaeEsoImpl __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *form,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *diff_form);


void __RPC_STUB IIsDaeEsoImpl_GetEqnForm_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoImpl_EvalStateCondition_Proxy( 
    IIsDaeEsoImpl __RPC_FAR * This,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *EqnState,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *x,
    /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *xdot,
    /* [in] */ double EventTime,
    /* [in] */ long iDisEqn,
    /* [in] */ long iTransition,
    /* [out][in] */ VARIANT_BOOL __RPC_FAR *bEvent);


void __RPC_STUB IIsDaeEsoImpl_EvalStateCondition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoImpl_GetMemberEsos_Proxy( 
    IIsDaeEsoImpl __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nEsos,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Esos);


void __RPC_STUB IIsDaeEsoImpl_GetMemberEsos_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoImpl_GetSTNStruct_Proxy( 
    IIsDaeEsoImpl __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nStates,
    /* [out][in] */ long __RPC_FAR *nTransitions,
    /* [out][in] */ long __RPC_FAR *iDefaultState,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TransEventIds,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *SrcStates,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *StateToEqnMap,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *TransToEqnMap);


void __RPC_STUB IIsDaeEsoImpl_GetSTNStruct_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoImpl_TriggerEvent_Proxy( 
    IIsDaeEsoImpl __RPC_FAR * This,
    /* [in] */ double EventTime,
    /* [in] */ BSTR EventId,
    /* [in] */ long iEventEqn);


void __RPC_STUB IIsDaeEsoImpl_TriggerEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoImpl_GetMasterNodeStatus_Proxy( 
    IIsDaeEsoImpl __RPC_FAR * This,
    VARIANT_BOOL __RPC_FAR *bMasterNodeStatus);


void __RPC_STUB IIsDaeEsoImpl_GetMasterNodeStatus_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IIsDaeEsoImpl_INTERFACE_DEFINED__ */


#ifndef __IIsDaeEsoIImpl_INTERFACE_DEFINED__
#define __IIsDaeEsoIImpl_INTERFACE_DEFINED__

/* interface IIsDaeEsoIImpl */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IIsDaeEsoIImpl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("732A30A3-CBE5-11D4-83A2-00600894E802")
    IIsDaeEsoIImpl : public IIsDaeEso
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetEso( 
            /* [in] */ IIsDaeEsoImpl __RPC_FAR *pEso) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIsDaeEsoIImplVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IIsDaeEsoIImpl __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IIsDaeEsoIImpl __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRelTolerance )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *relTolValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRelTolerance )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *relTolValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAbsTolerance )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *absTolValues);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAbsTolerance )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *absTolValues);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllResiduals )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *residuals,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *validVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetResiduals )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *residuals,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *validVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetJacobianStruct )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetJacobianValues )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *JacVals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllJacobianValues )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [out] */ IIsMatrix __RPC_FAR *__RPC_FAR *ppJacVals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDiffJacobianStruct )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDiffJacobianValues )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *MassVals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllDiffJacobianValues )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [out] */ IIsMatrix __RPC_FAR *__RPC_FAR *ppMassVals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVariables )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [in] */ double t,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVariable )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ double t,
            /* [out] */ double __RPC_FAR *val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVariableId )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [out] */ long __RPC_FAR *idx);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVariables )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllVariables )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ double t,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAllVariables )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDerivatives )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [in] */ double t,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDerivative )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ double t,
            /* [out] */ double __RPC_FAR *val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDerivatives )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllDerivatives )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ double t,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAllDerivatives )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumVars )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *nVars);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumEqns )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *nEqns);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumLocalVars )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *nVars);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumLocalEqns )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *nEqns);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLastTime )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            double __RPC_FAR *t);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTime )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            double __RPC_FAR *t);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ContainerIndex )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Index);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ContainerIndex )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ long Index);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_VariableMap )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_VariableMap )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitTime )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ double StartTime,
            /* [in] */ VARIANT_BOOL bReverse);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTime )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ double time);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLastTime )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ double last_time);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVariablesIndex )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddEso )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ IIsDaeEso __RPC_FAR *pEso);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEso )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ long index,
            /* [out] */ IIsDaeEso __RPC_FAR *__RPC_FAR *pEso);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveEso )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ long index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumEso )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *count);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetReportInfo )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
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
            /* [out] */ long __RPC_FAR *nStepSizeChanges);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EvalStateCondition )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ double ZeroCrossingTime,
            /* [in] */ long iDisEqn,
            /* [in] */ long iTransition,
            /* [out] */ VARIANT_BOOL __RPC_FAR *bEvent);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCPPPtr )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pIsDaeEso);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumRealPars )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nRPars);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRealPar )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ long index,
            /* [out][in] */ double __RPC_FAR *Val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRealParId )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [out][in] */ long __RPC_FAR *idx);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRealPar )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ double newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumIntPars )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nIPars);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIntPar )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ long index,
            /* [out][in] */ long __RPC_FAR *Val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIntParId )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [out][in] */ long __RPC_FAR *idx);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetIntPar )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetModelExec )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ IOnModelExec __RPC_FAR *pModelExec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PostStateEvent )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ double t,
            /* [in] */ BSTR EventId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PostTransition )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ long iNewState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PostRealParameter )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ double t,
            /* [in] */ long Id,
            /* [in] */ double newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PostIntegerParameter )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ double t,
            /* [in] */ long Id,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEso )( 
            IIsDaeEsoIImpl __RPC_FAR * This,
            /* [in] */ IIsDaeEsoImpl __RPC_FAR *pEso);
        
        END_INTERFACE
    } IIsDaeEsoIImplVtbl;

    interface IIsDaeEsoIImpl
    {
        CONST_VTBL struct IIsDaeEsoIImplVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIsDaeEsoIImpl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IIsDaeEsoIImpl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IIsDaeEsoIImpl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IIsDaeEsoIImpl_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IIsDaeEsoIImpl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IIsDaeEsoIImpl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IIsDaeEsoIImpl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IIsDaeEsoIImpl_SetRelTolerance(This,relTolValue)	\
    (This)->lpVtbl -> SetRelTolerance(This,relTolValue)

#define IIsDaeEsoIImpl_GetRelTolerance(This,relTolValue)	\
    (This)->lpVtbl -> GetRelTolerance(This,relTolValue)

#define IIsDaeEsoIImpl_SetAbsTolerance(This,absTolValues)	\
    (This)->lpVtbl -> SetAbsTolerance(This,absTolValues)

#define IIsDaeEsoIImpl_GetAbsTolerance(This,absTolValues)	\
    (This)->lpVtbl -> GetAbsTolerance(This,absTolValues)

#define IIsDaeEsoIImpl_GetAllResiduals(This,residuals,validVal)	\
    (This)->lpVtbl -> GetAllResiduals(This,residuals,validVal)

#define IIsDaeEsoIImpl_GetResiduals(This,Indices,residuals,validVal)	\
    (This)->lpVtbl -> GetResiduals(This,Indices,residuals,validVal)

#define IIsDaeEsoIImpl_GetJacobianStruct(This,nColIndices,ColIndices,cNZCols,CalcMethod)	\
    (This)->lpVtbl -> GetJacobianStruct(This,nColIndices,ColIndices,cNZCols,CalcMethod)

#define IIsDaeEsoIImpl_GetJacobianValues(This,Indices,JacVals)	\
    (This)->lpVtbl -> GetJacobianValues(This,Indices,JacVals)

#define IIsDaeEsoIImpl_GetAllJacobianValues(This,ppJacVals)	\
    (This)->lpVtbl -> GetAllJacobianValues(This,ppJacVals)

#define IIsDaeEsoIImpl_GetDiffJacobianStruct(This,nColIndices,ColIndices,cNZCols,CalcMethod)	\
    (This)->lpVtbl -> GetDiffJacobianStruct(This,nColIndices,ColIndices,cNZCols,CalcMethod)

#define IIsDaeEsoIImpl_GetDiffJacobianValues(This,Indices,MassVals)	\
    (This)->lpVtbl -> GetDiffJacobianValues(This,Indices,MassVals)

#define IIsDaeEsoIImpl_GetAllDiffJacobianValues(This,ppMassVals)	\
    (This)->lpVtbl -> GetAllDiffJacobianValues(This,ppMassVals)

#define IIsDaeEsoIImpl_GetVariables(This,Indices,t,Vals)	\
    (This)->lpVtbl -> GetVariables(This,Indices,t,Vals)

#define IIsDaeEsoIImpl_GetVariable(This,index,t,val)	\
    (This)->lpVtbl -> GetVariable(This,index,t,val)

#define IIsDaeEsoIImpl_GetVariableId(This,Name,idx)	\
    (This)->lpVtbl -> GetVariableId(This,Name,idx)

#define IIsDaeEsoIImpl_SetVariables(This,Indices,Vals)	\
    (This)->lpVtbl -> SetVariables(This,Indices,Vals)

#define IIsDaeEsoIImpl_GetAllVariables(This,t,Vals)	\
    (This)->lpVtbl -> GetAllVariables(This,t,Vals)

#define IIsDaeEsoIImpl_SetAllVariables(This,Vals)	\
    (This)->lpVtbl -> SetAllVariables(This,Vals)

#define IIsDaeEsoIImpl_GetDerivatives(This,Indices,t,Vals)	\
    (This)->lpVtbl -> GetDerivatives(This,Indices,t,Vals)

#define IIsDaeEsoIImpl_GetDerivative(This,index,t,val)	\
    (This)->lpVtbl -> GetDerivative(This,index,t,val)

#define IIsDaeEsoIImpl_SetDerivatives(This,Indices,Vals)	\
    (This)->lpVtbl -> SetDerivatives(This,Indices,Vals)

#define IIsDaeEsoIImpl_GetAllDerivatives(This,t,Vals)	\
    (This)->lpVtbl -> GetAllDerivatives(This,t,Vals)

#define IIsDaeEsoIImpl_SetAllDerivatives(This,Vals)	\
    (This)->lpVtbl -> SetAllDerivatives(This,Vals)

#define IIsDaeEsoIImpl_GetNumVars(This,nVars)	\
    (This)->lpVtbl -> GetNumVars(This,nVars)

#define IIsDaeEsoIImpl_GetNumEqns(This,nEqns)	\
    (This)->lpVtbl -> GetNumEqns(This,nEqns)

#define IIsDaeEsoIImpl_GetNumLocalVars(This,nVars)	\
    (This)->lpVtbl -> GetNumLocalVars(This,nVars)

#define IIsDaeEsoIImpl_GetNumLocalEqns(This,nEqns)	\
    (This)->lpVtbl -> GetNumLocalEqns(This,nEqns)

#define IIsDaeEsoIImpl_GetLastTime(This,t)	\
    (This)->lpVtbl -> GetLastTime(This,t)

#define IIsDaeEsoIImpl_GetTime(This,t)	\
    (This)->lpVtbl -> GetTime(This,t)

#define IIsDaeEsoIImpl_get_ContainerIndex(This,Index)	\
    (This)->lpVtbl -> get_ContainerIndex(This,Index)

#define IIsDaeEsoIImpl_put_ContainerIndex(This,Index)	\
    (This)->lpVtbl -> put_ContainerIndex(This,Index)

#define IIsDaeEsoIImpl_get_VariableMap(This,pVal)	\
    (This)->lpVtbl -> get_VariableMap(This,pVal)

#define IIsDaeEsoIImpl_put_VariableMap(This,newVal)	\
    (This)->lpVtbl -> put_VariableMap(This,newVal)

#define IIsDaeEsoIImpl_InitTime(This,StartTime,bReverse)	\
    (This)->lpVtbl -> InitTime(This,StartTime,bReverse)

#define IIsDaeEsoIImpl_SetTime(This,time)	\
    (This)->lpVtbl -> SetTime(This,time)

#define IIsDaeEsoIImpl_SetLastTime(This,last_time)	\
    (This)->lpVtbl -> SetLastTime(This,last_time)

#define IIsDaeEsoIImpl_GetVariablesIndex(This,Index)	\
    (This)->lpVtbl -> GetVariablesIndex(This,Index)

#define IIsDaeEsoIImpl_AddEso(This,pEso)	\
    (This)->lpVtbl -> AddEso(This,pEso)

#define IIsDaeEsoIImpl_GetEso(This,index,pEso)	\
    (This)->lpVtbl -> GetEso(This,index,pEso)

#define IIsDaeEsoIImpl_RemoveEso(This,index)	\
    (This)->lpVtbl -> RemoveEso(This,index)

#define IIsDaeEsoIImpl_GetNumEso(This,count)	\
    (This)->lpVtbl -> GetNumEso(This,count)

#define IIsDaeEsoIImpl_GetReportInfo(This,StepperCalls,functionCalls,jacobiansCalls,DecompCalls,Substitutions,TotalSteps,errorRejectedSteps,newtonRejectedSteps,growthRejectedSteps,funcRejectedSteps,nStateEvents,nParameterEvents,nStepSizeChanges)	\
    (This)->lpVtbl -> GetReportInfo(This,StepperCalls,functionCalls,jacobiansCalls,DecompCalls,Substitutions,TotalSteps,errorRejectedSteps,newtonRejectedSteps,growthRejectedSteps,funcRejectedSteps,nStateEvents,nParameterEvents,nStepSizeChanges)

#define IIsDaeEsoIImpl_EvalStateCondition(This,ZeroCrossingTime,iDisEqn,iTransition,bEvent)	\
    (This)->lpVtbl -> EvalStateCondition(This,ZeroCrossingTime,iDisEqn,iTransition,bEvent)

#define IIsDaeEsoIImpl_GetCPPPtr(This,pIsDaeEso)	\
    (This)->lpVtbl -> GetCPPPtr(This,pIsDaeEso)

#define IIsDaeEsoIImpl_GetNumRealPars(This,nRPars)	\
    (This)->lpVtbl -> GetNumRealPars(This,nRPars)

#define IIsDaeEsoIImpl_GetRealPar(This,index,Val)	\
    (This)->lpVtbl -> GetRealPar(This,index,Val)

#define IIsDaeEsoIImpl_GetRealParId(This,Name,idx)	\
    (This)->lpVtbl -> GetRealParId(This,Name,idx)

#define IIsDaeEsoIImpl_SetRealPar(This,index,newVal)	\
    (This)->lpVtbl -> SetRealPar(This,index,newVal)

#define IIsDaeEsoIImpl_GetNumIntPars(This,nIPars)	\
    (This)->lpVtbl -> GetNumIntPars(This,nIPars)

#define IIsDaeEsoIImpl_GetIntPar(This,index,Val)	\
    (This)->lpVtbl -> GetIntPar(This,index,Val)

#define IIsDaeEsoIImpl_GetIntParId(This,Name,idx)	\
    (This)->lpVtbl -> GetIntParId(This,Name,idx)

#define IIsDaeEsoIImpl_SetIntPar(This,index,newVal)	\
    (This)->lpVtbl -> SetIntPar(This,index,newVal)

#define IIsDaeEsoIImpl_SetModelExec(This,pModelExec)	\
    (This)->lpVtbl -> SetModelExec(This,pModelExec)

#define IIsDaeEsoIImpl_PostStateEvent(This,t,EventId)	\
    (This)->lpVtbl -> PostStateEvent(This,t,EventId)

#define IIsDaeEsoIImpl_PostTransition(This,iNewState)	\
    (This)->lpVtbl -> PostTransition(This,iNewState)

#define IIsDaeEsoIImpl_PostRealParameter(This,t,Id,newVal)	\
    (This)->lpVtbl -> PostRealParameter(This,t,Id,newVal)

#define IIsDaeEsoIImpl_PostIntegerParameter(This,t,Id,newVal)	\
    (This)->lpVtbl -> PostIntegerParameter(This,t,Id,newVal)


#define IIsDaeEsoIImpl_SetEso(This,pEso)	\
    (This)->lpVtbl -> SetEso(This,pEso)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoIImpl_SetEso_Proxy( 
    IIsDaeEsoIImpl __RPC_FAR * This,
    /* [in] */ IIsDaeEsoImpl __RPC_FAR *pEso);


void __RPC_STUB IIsDaeEsoIImpl_SetEso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IIsDaeEsoIImpl_INTERFACE_DEFINED__ */


#ifndef __IIsDaeEsoCImpl_INTERFACE_DEFINED__
#define __IIsDaeEsoCImpl_INTERFACE_DEFINED__

/* interface IIsDaeEsoCImpl */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IIsDaeEsoCImpl;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("43D71C20-E726-4786-800E-15C06968ADF3")
    IIsDaeEsoCImpl : public IIsDaeEso
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetEso( 
            /* [in] */ IUnknown __RPC_FAR *pEso) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetEsoNames( 
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pEsoNames) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Eso( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ IIsDaeEsoCImpl __RPC_FAR *__RPC_FAR *pEso) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetVarNames( 
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pVarNames) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_Var( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_Var( 
            /* [in] */ BSTR Name,
            /* [in] */ double Val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetRParNames( 
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pRParNames) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RPar( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RPar( 
            /* [in] */ BSTR Name,
            /* [in] */ double Val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetIParNames( 
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pIParNames) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_IPar( 
            /* [in] */ BSTR Name,
            /* [retval][out] */ long __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_IPar( 
            /* [in] */ BSTR Name,
            /* [in] */ long Val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetEqnNames( 
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pEqnNames) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Connect( 
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ConnA,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ConnB) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AddModel( 
            /* [in] */ IIsDaeEsoCImpl __RPC_FAR *pEso,
            /* [in] */ BSTR modelName) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_EsoImpl( 
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pEsoImpl) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE CompositeModelComplete( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IIsDaeEsoCImplVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IIsDaeEsoCImpl __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IIsDaeEsoCImpl __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRelTolerance )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *relTolValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRelTolerance )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *relTolValue);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAbsTolerance )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *absTolValues);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAbsTolerance )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *absTolValues);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllResiduals )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *residuals,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *validVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetResiduals )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *residuals,
            /* [out][in] */ VARIANT_BOOL __RPC_FAR *validVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetJacobianStruct )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetJacobianValues )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *JacVals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllJacobianValues )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [out] */ IIsMatrix __RPC_FAR *__RPC_FAR *ppJacVals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDiffJacobianStruct )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *CalcMethod);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDiffJacobianValues )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *MassVals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllDiffJacobianValues )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [out] */ IIsMatrix __RPC_FAR *__RPC_FAR *ppMassVals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVariables )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [in] */ double t,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVariable )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ double t,
            /* [out] */ double __RPC_FAR *val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVariableId )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [out] */ long __RPC_FAR *idx);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVariables )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllVariables )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ double t,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAllVariables )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDerivatives )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [in] */ double t,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetDerivative )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ double t,
            /* [out] */ double __RPC_FAR *val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetDerivatives )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Indices,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetAllDerivatives )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ double t,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetAllDerivatives )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Vals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumVars )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *nVars);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumEqns )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *nEqns);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumLocalVars )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *nVars);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumLocalEqns )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *nEqns);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetLastTime )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            double __RPC_FAR *t);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTime )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            double __RPC_FAR *t);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_ContainerIndex )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [retval][out] */ long __RPC_FAR *Index);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_ContainerIndex )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ long Index);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_VariableMap )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [retval][out] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_VariableMap )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitTime )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ double StartTime,
            /* [in] */ VARIANT_BOOL bReverse);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetTime )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ double time);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetLastTime )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ double last_time);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVariablesIndex )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddEso )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ IIsDaeEso __RPC_FAR *pEso);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEso )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ long index,
            /* [out] */ IIsDaeEso __RPC_FAR *__RPC_FAR *pEso);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *RemoveEso )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ long index);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumEso )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [out] */ long __RPC_FAR *count);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetReportInfo )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
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
            /* [out] */ long __RPC_FAR *nStepSizeChanges);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *EvalStateCondition )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ double ZeroCrossingTime,
            /* [in] */ long iDisEqn,
            /* [in] */ long iTransition,
            /* [out] */ VARIANT_BOOL __RPC_FAR *bEvent);
        
        /* [helpstring][hidden][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetCPPPtr )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [out] */ DWORD __RPC_FAR *pIsDaeEso);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumRealPars )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nRPars);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRealPar )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ long index,
            /* [out][in] */ double __RPC_FAR *Val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRealParId )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [out][in] */ long __RPC_FAR *idx);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetRealPar )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ double newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetNumIntPars )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nIPars);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIntPar )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ long index,
            /* [out][in] */ long __RPC_FAR *Val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIntParId )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [out][in] */ long __RPC_FAR *idx);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetIntPar )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ long index,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetModelExec )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ IOnModelExec __RPC_FAR *pModelExec);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PostStateEvent )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ double t,
            /* [in] */ BSTR EventId);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PostTransition )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ long iNewState);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PostRealParameter )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ double t,
            /* [in] */ long Id,
            /* [in] */ double newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PostIntegerParameter )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ double t,
            /* [in] */ long Id,
            /* [in] */ long newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetEso )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ IUnknown __RPC_FAR *pEso);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEsoNames )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pEsoNames);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Eso )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ IIsDaeEsoCImpl __RPC_FAR *__RPC_FAR *pEso);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetVarNames )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pVarNames);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_Var )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_Var )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [in] */ double Val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetRParNames )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pRParNames);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RPar )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_RPar )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [in] */ double Val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIParNames )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pIParNames);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_IPar )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [retval][out] */ long __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_IPar )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ BSTR Name,
            /* [in] */ long Val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetEqnNames )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pEqnNames);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Connect )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ConnA,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ConnB);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AddModel )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [in] */ IIsDaeEsoCImpl __RPC_FAR *pEso,
            /* [in] */ BSTR modelName);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_EsoImpl )( 
            IIsDaeEsoCImpl __RPC_FAR * This,
            /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pEsoImpl);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *CompositeModelComplete )( 
            IIsDaeEsoCImpl __RPC_FAR * This);
        
        END_INTERFACE
    } IIsDaeEsoCImplVtbl;

    interface IIsDaeEsoCImpl
    {
        CONST_VTBL struct IIsDaeEsoCImplVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IIsDaeEsoCImpl_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IIsDaeEsoCImpl_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IIsDaeEsoCImpl_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IIsDaeEsoCImpl_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IIsDaeEsoCImpl_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IIsDaeEsoCImpl_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IIsDaeEsoCImpl_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IIsDaeEsoCImpl_SetRelTolerance(This,relTolValue)	\
    (This)->lpVtbl -> SetRelTolerance(This,relTolValue)

#define IIsDaeEsoCImpl_GetRelTolerance(This,relTolValue)	\
    (This)->lpVtbl -> GetRelTolerance(This,relTolValue)

#define IIsDaeEsoCImpl_SetAbsTolerance(This,absTolValues)	\
    (This)->lpVtbl -> SetAbsTolerance(This,absTolValues)

#define IIsDaeEsoCImpl_GetAbsTolerance(This,absTolValues)	\
    (This)->lpVtbl -> GetAbsTolerance(This,absTolValues)

#define IIsDaeEsoCImpl_GetAllResiduals(This,residuals,validVal)	\
    (This)->lpVtbl -> GetAllResiduals(This,residuals,validVal)

#define IIsDaeEsoCImpl_GetResiduals(This,Indices,residuals,validVal)	\
    (This)->lpVtbl -> GetResiduals(This,Indices,residuals,validVal)

#define IIsDaeEsoCImpl_GetJacobianStruct(This,nColIndices,ColIndices,cNZCols,CalcMethod)	\
    (This)->lpVtbl -> GetJacobianStruct(This,nColIndices,ColIndices,cNZCols,CalcMethod)

#define IIsDaeEsoCImpl_GetJacobianValues(This,Indices,JacVals)	\
    (This)->lpVtbl -> GetJacobianValues(This,Indices,JacVals)

#define IIsDaeEsoCImpl_GetAllJacobianValues(This,ppJacVals)	\
    (This)->lpVtbl -> GetAllJacobianValues(This,ppJacVals)

#define IIsDaeEsoCImpl_GetDiffJacobianStruct(This,nColIndices,ColIndices,cNZCols,CalcMethod)	\
    (This)->lpVtbl -> GetDiffJacobianStruct(This,nColIndices,ColIndices,cNZCols,CalcMethod)

#define IIsDaeEsoCImpl_GetDiffJacobianValues(This,Indices,MassVals)	\
    (This)->lpVtbl -> GetDiffJacobianValues(This,Indices,MassVals)

#define IIsDaeEsoCImpl_GetAllDiffJacobianValues(This,ppMassVals)	\
    (This)->lpVtbl -> GetAllDiffJacobianValues(This,ppMassVals)

#define IIsDaeEsoCImpl_GetVariables(This,Indices,t,Vals)	\
    (This)->lpVtbl -> GetVariables(This,Indices,t,Vals)

#define IIsDaeEsoCImpl_GetVariable(This,index,t,val)	\
    (This)->lpVtbl -> GetVariable(This,index,t,val)

#define IIsDaeEsoCImpl_GetVariableId(This,Name,idx)	\
    (This)->lpVtbl -> GetVariableId(This,Name,idx)

#define IIsDaeEsoCImpl_SetVariables(This,Indices,Vals)	\
    (This)->lpVtbl -> SetVariables(This,Indices,Vals)

#define IIsDaeEsoCImpl_GetAllVariables(This,t,Vals)	\
    (This)->lpVtbl -> GetAllVariables(This,t,Vals)

#define IIsDaeEsoCImpl_SetAllVariables(This,Vals)	\
    (This)->lpVtbl -> SetAllVariables(This,Vals)

#define IIsDaeEsoCImpl_GetDerivatives(This,Indices,t,Vals)	\
    (This)->lpVtbl -> GetDerivatives(This,Indices,t,Vals)

#define IIsDaeEsoCImpl_GetDerivative(This,index,t,val)	\
    (This)->lpVtbl -> GetDerivative(This,index,t,val)

#define IIsDaeEsoCImpl_SetDerivatives(This,Indices,Vals)	\
    (This)->lpVtbl -> SetDerivatives(This,Indices,Vals)

#define IIsDaeEsoCImpl_GetAllDerivatives(This,t,Vals)	\
    (This)->lpVtbl -> GetAllDerivatives(This,t,Vals)

#define IIsDaeEsoCImpl_SetAllDerivatives(This,Vals)	\
    (This)->lpVtbl -> SetAllDerivatives(This,Vals)

#define IIsDaeEsoCImpl_GetNumVars(This,nVars)	\
    (This)->lpVtbl -> GetNumVars(This,nVars)

#define IIsDaeEsoCImpl_GetNumEqns(This,nEqns)	\
    (This)->lpVtbl -> GetNumEqns(This,nEqns)

#define IIsDaeEsoCImpl_GetNumLocalVars(This,nVars)	\
    (This)->lpVtbl -> GetNumLocalVars(This,nVars)

#define IIsDaeEsoCImpl_GetNumLocalEqns(This,nEqns)	\
    (This)->lpVtbl -> GetNumLocalEqns(This,nEqns)

#define IIsDaeEsoCImpl_GetLastTime(This,t)	\
    (This)->lpVtbl -> GetLastTime(This,t)

#define IIsDaeEsoCImpl_GetTime(This,t)	\
    (This)->lpVtbl -> GetTime(This,t)

#define IIsDaeEsoCImpl_get_ContainerIndex(This,Index)	\
    (This)->lpVtbl -> get_ContainerIndex(This,Index)

#define IIsDaeEsoCImpl_put_ContainerIndex(This,Index)	\
    (This)->lpVtbl -> put_ContainerIndex(This,Index)

#define IIsDaeEsoCImpl_get_VariableMap(This,pVal)	\
    (This)->lpVtbl -> get_VariableMap(This,pVal)

#define IIsDaeEsoCImpl_put_VariableMap(This,newVal)	\
    (This)->lpVtbl -> put_VariableMap(This,newVal)

#define IIsDaeEsoCImpl_InitTime(This,StartTime,bReverse)	\
    (This)->lpVtbl -> InitTime(This,StartTime,bReverse)

#define IIsDaeEsoCImpl_SetTime(This,time)	\
    (This)->lpVtbl -> SetTime(This,time)

#define IIsDaeEsoCImpl_SetLastTime(This,last_time)	\
    (This)->lpVtbl -> SetLastTime(This,last_time)

#define IIsDaeEsoCImpl_GetVariablesIndex(This,Index)	\
    (This)->lpVtbl -> GetVariablesIndex(This,Index)

#define IIsDaeEsoCImpl_AddEso(This,pEso)	\
    (This)->lpVtbl -> AddEso(This,pEso)

#define IIsDaeEsoCImpl_GetEso(This,index,pEso)	\
    (This)->lpVtbl -> GetEso(This,index,pEso)

#define IIsDaeEsoCImpl_RemoveEso(This,index)	\
    (This)->lpVtbl -> RemoveEso(This,index)

#define IIsDaeEsoCImpl_GetNumEso(This,count)	\
    (This)->lpVtbl -> GetNumEso(This,count)

#define IIsDaeEsoCImpl_GetReportInfo(This,StepperCalls,functionCalls,jacobiansCalls,DecompCalls,Substitutions,TotalSteps,errorRejectedSteps,newtonRejectedSteps,growthRejectedSteps,funcRejectedSteps,nStateEvents,nParameterEvents,nStepSizeChanges)	\
    (This)->lpVtbl -> GetReportInfo(This,StepperCalls,functionCalls,jacobiansCalls,DecompCalls,Substitutions,TotalSteps,errorRejectedSteps,newtonRejectedSteps,growthRejectedSteps,funcRejectedSteps,nStateEvents,nParameterEvents,nStepSizeChanges)

#define IIsDaeEsoCImpl_EvalStateCondition(This,ZeroCrossingTime,iDisEqn,iTransition,bEvent)	\
    (This)->lpVtbl -> EvalStateCondition(This,ZeroCrossingTime,iDisEqn,iTransition,bEvent)

#define IIsDaeEsoCImpl_GetCPPPtr(This,pIsDaeEso)	\
    (This)->lpVtbl -> GetCPPPtr(This,pIsDaeEso)

#define IIsDaeEsoCImpl_GetNumRealPars(This,nRPars)	\
    (This)->lpVtbl -> GetNumRealPars(This,nRPars)

#define IIsDaeEsoCImpl_GetRealPar(This,index,Val)	\
    (This)->lpVtbl -> GetRealPar(This,index,Val)

#define IIsDaeEsoCImpl_GetRealParId(This,Name,idx)	\
    (This)->lpVtbl -> GetRealParId(This,Name,idx)

#define IIsDaeEsoCImpl_SetRealPar(This,index,newVal)	\
    (This)->lpVtbl -> SetRealPar(This,index,newVal)

#define IIsDaeEsoCImpl_GetNumIntPars(This,nIPars)	\
    (This)->lpVtbl -> GetNumIntPars(This,nIPars)

#define IIsDaeEsoCImpl_GetIntPar(This,index,Val)	\
    (This)->lpVtbl -> GetIntPar(This,index,Val)

#define IIsDaeEsoCImpl_GetIntParId(This,Name,idx)	\
    (This)->lpVtbl -> GetIntParId(This,Name,idx)

#define IIsDaeEsoCImpl_SetIntPar(This,index,newVal)	\
    (This)->lpVtbl -> SetIntPar(This,index,newVal)

#define IIsDaeEsoCImpl_SetModelExec(This,pModelExec)	\
    (This)->lpVtbl -> SetModelExec(This,pModelExec)

#define IIsDaeEsoCImpl_PostStateEvent(This,t,EventId)	\
    (This)->lpVtbl -> PostStateEvent(This,t,EventId)

#define IIsDaeEsoCImpl_PostTransition(This,iNewState)	\
    (This)->lpVtbl -> PostTransition(This,iNewState)

#define IIsDaeEsoCImpl_PostRealParameter(This,t,Id,newVal)	\
    (This)->lpVtbl -> PostRealParameter(This,t,Id,newVal)

#define IIsDaeEsoCImpl_PostIntegerParameter(This,t,Id,newVal)	\
    (This)->lpVtbl -> PostIntegerParameter(This,t,Id,newVal)


#define IIsDaeEsoCImpl_SetEso(This,pEso)	\
    (This)->lpVtbl -> SetEso(This,pEso)

#define IIsDaeEsoCImpl_GetEsoNames(This,pEsoNames)	\
    (This)->lpVtbl -> GetEsoNames(This,pEsoNames)

#define IIsDaeEsoCImpl_get_Eso(This,Name,pEso)	\
    (This)->lpVtbl -> get_Eso(This,Name,pEso)

#define IIsDaeEsoCImpl_GetVarNames(This,pVarNames)	\
    (This)->lpVtbl -> GetVarNames(This,pVarNames)

#define IIsDaeEsoCImpl_get_Var(This,Name,pVal)	\
    (This)->lpVtbl -> get_Var(This,Name,pVal)

#define IIsDaeEsoCImpl_put_Var(This,Name,Val)	\
    (This)->lpVtbl -> put_Var(This,Name,Val)

#define IIsDaeEsoCImpl_GetRParNames(This,pRParNames)	\
    (This)->lpVtbl -> GetRParNames(This,pRParNames)

#define IIsDaeEsoCImpl_get_RPar(This,Name,pVal)	\
    (This)->lpVtbl -> get_RPar(This,Name,pVal)

#define IIsDaeEsoCImpl_put_RPar(This,Name,Val)	\
    (This)->lpVtbl -> put_RPar(This,Name,Val)

#define IIsDaeEsoCImpl_GetIParNames(This,pIParNames)	\
    (This)->lpVtbl -> GetIParNames(This,pIParNames)

#define IIsDaeEsoCImpl_get_IPar(This,Name,pVal)	\
    (This)->lpVtbl -> get_IPar(This,Name,pVal)

#define IIsDaeEsoCImpl_put_IPar(This,Name,Val)	\
    (This)->lpVtbl -> put_IPar(This,Name,Val)

#define IIsDaeEsoCImpl_GetEqnNames(This,pEqnNames)	\
    (This)->lpVtbl -> GetEqnNames(This,pEqnNames)

#define IIsDaeEsoCImpl_Connect(This,ConnA,ConnB)	\
    (This)->lpVtbl -> Connect(This,ConnA,ConnB)

#define IIsDaeEsoCImpl_AddModel(This,pEso,modelName)	\
    (This)->lpVtbl -> AddModel(This,pEso,modelName)

#define IIsDaeEsoCImpl_get_EsoImpl(This,pEsoImpl)	\
    (This)->lpVtbl -> get_EsoImpl(This,pEsoImpl)

#define IIsDaeEsoCImpl_CompositeModelComplete(This)	\
    (This)->lpVtbl -> CompositeModelComplete(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_SetEso_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [in] */ IUnknown __RPC_FAR *pEso);


void __RPC_STUB IIsDaeEsoCImpl_SetEso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_GetEsoNames_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pEsoNames);


void __RPC_STUB IIsDaeEsoCImpl_GetEsoNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_get_Eso_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [retval][out] */ IIsDaeEsoCImpl __RPC_FAR *__RPC_FAR *pEso);


void __RPC_STUB IIsDaeEsoCImpl_get_Eso_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_GetVarNames_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pVarNames);


void __RPC_STUB IIsDaeEsoCImpl_GetVarNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_get_Var_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IIsDaeEsoCImpl_get_Var_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_put_Var_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [in] */ double Val);


void __RPC_STUB IIsDaeEsoCImpl_put_Var_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_GetRParNames_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pRParNames);


void __RPC_STUB IIsDaeEsoCImpl_GetRParNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_get_RPar_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IIsDaeEsoCImpl_get_RPar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_put_RPar_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [in] */ double Val);


void __RPC_STUB IIsDaeEsoCImpl_put_RPar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_GetIParNames_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pIParNames);


void __RPC_STUB IIsDaeEsoCImpl_GetIParNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_get_IPar_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [retval][out] */ long __RPC_FAR *pVal);


void __RPC_STUB IIsDaeEsoCImpl_get_IPar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_put_IPar_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [in] */ BSTR Name,
    /* [in] */ long Val);


void __RPC_STUB IIsDaeEsoCImpl_put_IPar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_GetEqnNames_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *pEqnNames);


void __RPC_STUB IIsDaeEsoCImpl_GetEqnNames_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_Connect_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ConnA,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ConnB);


void __RPC_STUB IIsDaeEsoCImpl_Connect_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_AddModel_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [in] */ IIsDaeEsoCImpl __RPC_FAR *pEso,
    /* [in] */ BSTR modelName);


void __RPC_STUB IIsDaeEsoCImpl_AddModel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_get_EsoImpl_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This,
    /* [retval][out] */ IUnknown __RPC_FAR *__RPC_FAR *pEsoImpl);


void __RPC_STUB IIsDaeEsoCImpl_get_EsoImpl_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IIsDaeEsoCImpl_CompositeModelComplete_Proxy( 
    IIsDaeEsoCImpl __RPC_FAR * This);


void __RPC_STUB IIsDaeEsoCImpl_CompositeModelComplete_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IIsDaeEsoCImpl_INTERFACE_DEFINED__ */


#ifndef __IOnModelExecEvents_INTERFACE_DEFINED__
#define __IOnModelExecEvents_INTERFACE_DEFINED__

/* interface IOnModelExecEvents */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IOnModelExecEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("60453BD6-4CD9-425c-868B-E04F7D4E16C2")
    IOnModelExecEvents : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BeforeRParEvent( 
            double Time,
            long iGlobalId,
            double Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BeforeIParEvent( 
            double Time,
            long iGlobalId,
            long Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE BeforeStateEvent( 
            double Time,
            BSTR EvId,
            long iEvEqn) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AfterRParEvent( 
            double Time,
            long iGlobalId,
            double Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AfterIParEvent( 
            double Time,
            long iGlobalId,
            long Value) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE AfterStateEvent( 
            double Time,
            BSTR EvId,
            long iEvEqn) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE InitializationInfo( 
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
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ResVals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTrimEqns( 
            /* [out][in] */ long __RPC_FAR *nEqns,
            /* [out][in] */ long __RPC_FAR *nColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *spRowPage,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetTrimVars( 
            /* [out][in] */ long __RPC_FAR *nVars,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarIds,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarVals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetVariables( 
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarVals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetResiduals( 
            /* [in] */ long nEqns,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *EqnIds,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Residuals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetResiduals( 
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ResVals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ShowDialog( 
            /* [in] */ BSTR msg) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOnModelExecEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IOnModelExecEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IOnModelExecEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IOnModelExecEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IOnModelExecEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IOnModelExecEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IOnModelExecEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IOnModelExecEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BeforeRParEvent )( 
            IOnModelExecEvents __RPC_FAR * This,
            double Time,
            long iGlobalId,
            double Value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BeforeIParEvent )( 
            IOnModelExecEvents __RPC_FAR * This,
            double Time,
            long iGlobalId,
            long Value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *BeforeStateEvent )( 
            IOnModelExecEvents __RPC_FAR * This,
            double Time,
            BSTR EvId,
            long iEvEqn);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AfterRParEvent )( 
            IOnModelExecEvents __RPC_FAR * This,
            double Time,
            long iGlobalId,
            double Value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AfterIParEvent )( 
            IOnModelExecEvents __RPC_FAR * This,
            double Time,
            long iGlobalId,
            long Value);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *AfterStateEvent )( 
            IOnModelExecEvents __RPC_FAR * This,
            double Time,
            BSTR EvId,
            long iEvEqn);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *InitializationInfo )( 
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
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ResVals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTrimEqns )( 
            IOnModelExecEvents __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nEqns,
            /* [out][in] */ long __RPC_FAR *nColIndices,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *spRowPage,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTrimVars )( 
            IOnModelExecEvents __RPC_FAR * This,
            /* [out][in] */ long __RPC_FAR *nVars,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarIds,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarVals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVariables )( 
            IOnModelExecEvents __RPC_FAR * This,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarVals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetResiduals )( 
            IOnModelExecEvents __RPC_FAR * This,
            /* [in] */ long nEqns,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *EqnIds,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Residuals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetResiduals )( 
            IOnModelExecEvents __RPC_FAR * This,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ResVals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ShowDialog )( 
            IOnModelExecEvents __RPC_FAR * This,
            /* [in] */ BSTR msg);
        
        END_INTERFACE
    } IOnModelExecEventsVtbl;

    interface IOnModelExecEvents
    {
        CONST_VTBL struct IOnModelExecEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOnModelExecEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOnModelExecEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOnModelExecEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOnModelExecEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOnModelExecEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOnModelExecEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOnModelExecEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IOnModelExecEvents_BeforeRParEvent(This,Time,iGlobalId,Value)	\
    (This)->lpVtbl -> BeforeRParEvent(This,Time,iGlobalId,Value)

#define IOnModelExecEvents_BeforeIParEvent(This,Time,iGlobalId,Value)	\
    (This)->lpVtbl -> BeforeIParEvent(This,Time,iGlobalId,Value)

#define IOnModelExecEvents_BeforeStateEvent(This,Time,EvId,iEvEqn)	\
    (This)->lpVtbl -> BeforeStateEvent(This,Time,EvId,iEvEqn)

#define IOnModelExecEvents_AfterRParEvent(This,Time,iGlobalId,Value)	\
    (This)->lpVtbl -> AfterRParEvent(This,Time,iGlobalId,Value)

#define IOnModelExecEvents_AfterIParEvent(This,Time,iGlobalId,Value)	\
    (This)->lpVtbl -> AfterIParEvent(This,Time,iGlobalId,Value)

#define IOnModelExecEvents_AfterStateEvent(This,Time,EvId,iEvEqn)	\
    (This)->lpVtbl -> AfterStateEvent(This,Time,EvId,iEvEqn)

#define IOnModelExecEvents_InitializationInfo(This,fault,stage,nModelEqns,nModelVars,nActiveEqns,nActiveVars,nAugmentedEqns,nAugmentedVars,EqnNames,VarNames,nColIndices,cNZCols,spRowPage,ColIndices,EqnOrder,VarOrder,VAL,EAL,AssignedEqn,VarVals,VarDotVals,ResVals)	\
    (This)->lpVtbl -> InitializationInfo(This,fault,stage,nModelEqns,nModelVars,nActiveEqns,nActiveVars,nAugmentedEqns,nAugmentedVars,EqnNames,VarNames,nColIndices,cNZCols,spRowPage,ColIndices,EqnOrder,VarOrder,VAL,EAL,AssignedEqn,VarVals,VarDotVals,ResVals)

#define IOnModelExecEvents_GetTrimEqns(This,nEqns,nColIndices,cNZCols,spRowPage,ColIndices)	\
    (This)->lpVtbl -> GetTrimEqns(This,nEqns,nColIndices,cNZCols,spRowPage,ColIndices)

#define IOnModelExecEvents_GetTrimVars(This,nVars,VarIds,VarVals)	\
    (This)->lpVtbl -> GetTrimVars(This,nVars,VarIds,VarVals)

#define IOnModelExecEvents_SetVariables(This,VarVals)	\
    (This)->lpVtbl -> SetVariables(This,VarVals)

#define IOnModelExecEvents_GetResiduals(This,nEqns,EqnIds,Residuals)	\
    (This)->lpVtbl -> GetResiduals(This,nEqns,EqnIds,Residuals)

#define IOnModelExecEvents_SetResiduals(This,ResVals)	\
    (This)->lpVtbl -> SetResiduals(This,ResVals)

#define IOnModelExecEvents_ShowDialog(This,msg)	\
    (This)->lpVtbl -> ShowDialog(This,msg)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExecEvents_BeforeRParEvent_Proxy( 
    IOnModelExecEvents __RPC_FAR * This,
    double Time,
    long iGlobalId,
    double Value);


void __RPC_STUB IOnModelExecEvents_BeforeRParEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExecEvents_BeforeIParEvent_Proxy( 
    IOnModelExecEvents __RPC_FAR * This,
    double Time,
    long iGlobalId,
    long Value);


void __RPC_STUB IOnModelExecEvents_BeforeIParEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExecEvents_BeforeStateEvent_Proxy( 
    IOnModelExecEvents __RPC_FAR * This,
    double Time,
    BSTR EvId,
    long iEvEqn);


void __RPC_STUB IOnModelExecEvents_BeforeStateEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExecEvents_AfterRParEvent_Proxy( 
    IOnModelExecEvents __RPC_FAR * This,
    double Time,
    long iGlobalId,
    double Value);


void __RPC_STUB IOnModelExecEvents_AfterRParEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExecEvents_AfterIParEvent_Proxy( 
    IOnModelExecEvents __RPC_FAR * This,
    double Time,
    long iGlobalId,
    long Value);


void __RPC_STUB IOnModelExecEvents_AfterIParEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExecEvents_AfterStateEvent_Proxy( 
    IOnModelExecEvents __RPC_FAR * This,
    double Time,
    BSTR EvId,
    long iEvEqn);


void __RPC_STUB IOnModelExecEvents_AfterStateEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


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
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ResVals);


void __RPC_STUB IOnModelExecEvents_InitializationInfo_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExecEvents_GetTrimEqns_Proxy( 
    IOnModelExecEvents __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nEqns,
    /* [out][in] */ long __RPC_FAR *nColIndices,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *cNZCols,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *spRowPage,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ColIndices);


void __RPC_STUB IOnModelExecEvents_GetTrimEqns_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExecEvents_GetTrimVars_Proxy( 
    IOnModelExecEvents __RPC_FAR * This,
    /* [out][in] */ long __RPC_FAR *nVars,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarIds,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarVals);


void __RPC_STUB IOnModelExecEvents_GetTrimVars_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExecEvents_SetVariables_Proxy( 
    IOnModelExecEvents __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarVals);


void __RPC_STUB IOnModelExecEvents_SetVariables_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExecEvents_GetResiduals_Proxy( 
    IOnModelExecEvents __RPC_FAR * This,
    /* [in] */ long nEqns,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *EqnIds,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Residuals);


void __RPC_STUB IOnModelExecEvents_GetResiduals_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExecEvents_SetResiduals_Proxy( 
    IOnModelExecEvents __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *ResVals);


void __RPC_STUB IOnModelExecEvents_SetResiduals_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExecEvents_ShowDialog_Proxy( 
    IOnModelExecEvents __RPC_FAR * This,
    /* [in] */ BSTR msg);


void __RPC_STUB IOnModelExecEvents_ShowDialog_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOnModelExecEvents_INTERFACE_DEFINED__ */


#ifndef __IOnModelExec_INTERFACE_DEFINED__
#define __IOnModelExec_INTERFACE_DEFINED__

/* interface IOnModelExec */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IOnModelExec;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("58CF6F05-D4AC-481E-B94D-FA4F4DE091C7")
    IOnModelExec : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PostRPar( 
            /* [in] */ double event_time,
            /* [in] */ long iGlobalId,
            /* [in] */ double val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PostIPar( 
            /* [in] */ double event_time,
            /* [in] */ long iGlobalId,
            /* [in] */ long val) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetModel( 
            /* [in] */ IIsDaeEso __RPC_FAR *pModel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE PostStateEvent( 
            /* [in] */ double EventTime,
            /* [in] */ BSTR EventId,
            /* [in] */ long iEventEqn,
            /* [in] */ IIsDaeEso __RPC_FAR *pEventEso) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_MaxStepSize( 
            /* [retval][out] */ double __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_MaxStepSize( 
            /* [in] */ double newVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Step( 
            /* [in] */ double external_time) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE OnTransition( 
            /* [in] */ double event_time,
            /* [in] */ long iEventEqn,
            /* [in] */ BSTR EventId,
            /* [in] */ long iNewState,
            /* [in] */ IIsDaeEso __RPC_FAR *pEventModel) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Save( 
            /* [in] */ BSTR filename) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE Load( 
            /* [in] */ BSTR filename) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE ForceReset( void) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_RetryInitialization( 
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_RetryInitialization( 
            /* [in] */ VARIANT_BOOL bVal) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE GetResiduals( 
            /* [in] */ long nEqns,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *EqnIds,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Residuals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SetVariables( 
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarVals) = 0;
        
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE HandleInitEvents( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOnModelExecVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IOnModelExec __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IOnModelExec __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IOnModelExec __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IOnModelExec __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IOnModelExec __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IOnModelExec __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IOnModelExec __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PostRPar )( 
            IOnModelExec __RPC_FAR * This,
            /* [in] */ double event_time,
            /* [in] */ long iGlobalId,
            /* [in] */ double val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PostIPar )( 
            IOnModelExec __RPC_FAR * This,
            /* [in] */ double event_time,
            /* [in] */ long iGlobalId,
            /* [in] */ long val);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetModel )( 
            IOnModelExec __RPC_FAR * This,
            /* [in] */ IIsDaeEso __RPC_FAR *pModel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *PostStateEvent )( 
            IOnModelExec __RPC_FAR * This,
            /* [in] */ double EventTime,
            /* [in] */ BSTR EventId,
            /* [in] */ long iEventEqn,
            /* [in] */ IIsDaeEso __RPC_FAR *pEventEso);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_MaxStepSize )( 
            IOnModelExec __RPC_FAR * This,
            /* [retval][out] */ double __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_MaxStepSize )( 
            IOnModelExec __RPC_FAR * This,
            /* [in] */ double newVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Step )( 
            IOnModelExec __RPC_FAR * This,
            /* [in] */ double external_time);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *OnTransition )( 
            IOnModelExec __RPC_FAR * This,
            /* [in] */ double event_time,
            /* [in] */ long iEventEqn,
            /* [in] */ BSTR EventId,
            /* [in] */ long iNewState,
            /* [in] */ IIsDaeEso __RPC_FAR *pEventModel);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Save )( 
            IOnModelExec __RPC_FAR * This,
            /* [in] */ BSTR filename);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Load )( 
            IOnModelExec __RPC_FAR * This,
            /* [in] */ BSTR filename);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *ForceReset )( 
            IOnModelExec __RPC_FAR * This);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_RetryInitialization )( 
            IOnModelExec __RPC_FAR * This,
            /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_RetryInitialization )( 
            IOnModelExec __RPC_FAR * This,
            /* [in] */ VARIANT_BOOL bVal);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetResiduals )( 
            IOnModelExec __RPC_FAR * This,
            /* [in] */ long nEqns,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *EqnIds,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Residuals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SetVariables )( 
            IOnModelExec __RPC_FAR * This,
            /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarVals);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *HandleInitEvents )( 
            IOnModelExec __RPC_FAR * This);
        
        END_INTERFACE
    } IOnModelExecVtbl;

    interface IOnModelExec
    {
        CONST_VTBL struct IOnModelExecVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOnModelExec_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOnModelExec_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOnModelExec_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOnModelExec_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOnModelExec_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOnModelExec_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOnModelExec_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IOnModelExec_PostRPar(This,event_time,iGlobalId,val)	\
    (This)->lpVtbl -> PostRPar(This,event_time,iGlobalId,val)

#define IOnModelExec_PostIPar(This,event_time,iGlobalId,val)	\
    (This)->lpVtbl -> PostIPar(This,event_time,iGlobalId,val)

#define IOnModelExec_SetModel(This,pModel)	\
    (This)->lpVtbl -> SetModel(This,pModel)

#define IOnModelExec_PostStateEvent(This,EventTime,EventId,iEventEqn,pEventEso)	\
    (This)->lpVtbl -> PostStateEvent(This,EventTime,EventId,iEventEqn,pEventEso)

#define IOnModelExec_get_MaxStepSize(This,pVal)	\
    (This)->lpVtbl -> get_MaxStepSize(This,pVal)

#define IOnModelExec_put_MaxStepSize(This,newVal)	\
    (This)->lpVtbl -> put_MaxStepSize(This,newVal)

#define IOnModelExec_Step(This,external_time)	\
    (This)->lpVtbl -> Step(This,external_time)

#define IOnModelExec_OnTransition(This,event_time,iEventEqn,EventId,iNewState,pEventModel)	\
    (This)->lpVtbl -> OnTransition(This,event_time,iEventEqn,EventId,iNewState,pEventModel)

#define IOnModelExec_Save(This,filename)	\
    (This)->lpVtbl -> Save(This,filename)

#define IOnModelExec_Load(This,filename)	\
    (This)->lpVtbl -> Load(This,filename)

#define IOnModelExec_ForceReset(This)	\
    (This)->lpVtbl -> ForceReset(This)

#define IOnModelExec_get_RetryInitialization(This,bVal)	\
    (This)->lpVtbl -> get_RetryInitialization(This,bVal)

#define IOnModelExec_put_RetryInitialization(This,bVal)	\
    (This)->lpVtbl -> put_RetryInitialization(This,bVal)

#define IOnModelExec_GetResiduals(This,nEqns,EqnIds,Residuals)	\
    (This)->lpVtbl -> GetResiduals(This,nEqns,EqnIds,Residuals)

#define IOnModelExec_SetVariables(This,VarVals)	\
    (This)->lpVtbl -> SetVariables(This,VarVals)

#define IOnModelExec_HandleInitEvents(This)	\
    (This)->lpVtbl -> HandleInitEvents(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExec_PostRPar_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [in] */ double event_time,
    /* [in] */ long iGlobalId,
    /* [in] */ double val);


void __RPC_STUB IOnModelExec_PostRPar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExec_PostIPar_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [in] */ double event_time,
    /* [in] */ long iGlobalId,
    /* [in] */ long val);


void __RPC_STUB IOnModelExec_PostIPar_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExec_SetModel_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [in] */ IIsDaeEso __RPC_FAR *pModel);


void __RPC_STUB IOnModelExec_SetModel_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExec_PostStateEvent_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [in] */ double EventTime,
    /* [in] */ BSTR EventId,
    /* [in] */ long iEventEqn,
    /* [in] */ IIsDaeEso __RPC_FAR *pEventEso);


void __RPC_STUB IOnModelExec_PostStateEvent_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOnModelExec_get_MaxStepSize_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [retval][out] */ double __RPC_FAR *pVal);


void __RPC_STUB IOnModelExec_get_MaxStepSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOnModelExec_put_MaxStepSize_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [in] */ double newVal);


void __RPC_STUB IOnModelExec_put_MaxStepSize_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExec_Step_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [in] */ double external_time);


void __RPC_STUB IOnModelExec_Step_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExec_OnTransition_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [in] */ double event_time,
    /* [in] */ long iEventEqn,
    /* [in] */ BSTR EventId,
    /* [in] */ long iNewState,
    /* [in] */ IIsDaeEso __RPC_FAR *pEventModel);


void __RPC_STUB IOnModelExec_OnTransition_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExec_Save_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [in] */ BSTR filename);


void __RPC_STUB IOnModelExec_Save_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExec_Load_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [in] */ BSTR filename);


void __RPC_STUB IOnModelExec_Load_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExec_ForceReset_Proxy( 
    IOnModelExec __RPC_FAR * This);


void __RPC_STUB IOnModelExec_ForceReset_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOnModelExec_get_RetryInitialization_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [retval][out] */ VARIANT_BOOL __RPC_FAR *bVal);


void __RPC_STUB IOnModelExec_get_RetryInitialization_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOnModelExec_put_RetryInitialization_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [in] */ VARIANT_BOOL bVal);


void __RPC_STUB IOnModelExec_put_RetryInitialization_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExec_GetResiduals_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [in] */ long nEqns,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *EqnIds,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *Residuals);


void __RPC_STUB IOnModelExec_GetResiduals_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExec_SetVariables_Proxy( 
    IOnModelExec __RPC_FAR * This,
    /* [out][in] */ SAFEARRAY __RPC_FAR * __RPC_FAR *VarVals);


void __RPC_STUB IOnModelExec_SetVariables_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnModelExec_HandleInitEvents_Proxy( 
    IOnModelExec __RPC_FAR * This);


void __RPC_STUB IOnModelExec_HandleInitEvents_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOnModelExec_INTERFACE_DEFINED__ */


#ifndef __IOnTest_INTERFACE_DEFINED__
#define __IOnTest_INTERFACE_DEFINED__

/* interface IOnTest */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IOnTest;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("215F714B-4C21-476A-A22E-725F57167B83")
    IOnTest : public IDispatch
    {
    public:
        virtual /* [helpstring][id] */ HRESULT STDMETHODCALLTYPE SparseTest( void) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOnTestVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IOnTest __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IOnTest __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IOnTest __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IOnTest __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IOnTest __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IOnTest __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IOnTest __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *SparseTest )( 
            IOnTest __RPC_FAR * This);
        
        END_INTERFACE
    } IOnTestVtbl;

    interface IOnTest
    {
        CONST_VTBL struct IOnTestVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOnTest_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOnTest_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOnTest_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOnTest_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOnTest_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOnTest_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOnTest_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IOnTest_SparseTest(This)	\
    (This)->lpVtbl -> SparseTest(This)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id] */ HRESULT STDMETHODCALLTYPE IOnTest_SparseTest_Proxy( 
    IOnTest __RPC_FAR * This);


void __RPC_STUB IOnTest_SparseTest_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOnTest_INTERFACE_DEFINED__ */



#ifndef __ISDAECOSOLVERLib_LIBRARY_DEFINED__
#define __ISDAECOSOLVERLib_LIBRARY_DEFINED__

/* library ISDAECOSOLVERLib */
/* [helpstring][version][uuid] */ 


EXTERN_C const IID LIBID_ISDAECOSOLVERLib;

#ifndef ___IOnModelExecEvents_DISPINTERFACE_DEFINED__
#define ___IOnModelExecEvents_DISPINTERFACE_DEFINED__

/* dispinterface _IOnModelExecEvents */
/* [helpstring][uuid] */ 


EXTERN_C const IID DIID__IOnModelExecEvents;

#if defined(__cplusplus) && !defined(CINTERFACE)

    MIDL_INTERFACE("77CBD767-8006-11D4-98A7-00C04F6801A9")
    _IOnModelExecEvents : public IDispatch
    {
    };
    
#else 	/* C style interface */

    typedef struct _IOnModelExecEventsVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            _IOnModelExecEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            _IOnModelExecEvents __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            _IOnModelExecEvents __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            _IOnModelExecEvents __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            _IOnModelExecEvents __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            _IOnModelExecEvents __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            _IOnModelExecEvents __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        END_INTERFACE
    } _IOnModelExecEventsVtbl;

    interface _IOnModelExecEvents
    {
        CONST_VTBL struct _IOnModelExecEventsVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define _IOnModelExecEvents_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define _IOnModelExecEvents_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define _IOnModelExecEvents_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define _IOnModelExecEvents_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define _IOnModelExecEvents_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define _IOnModelExecEvents_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define _IOnModelExecEvents_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)

#endif /* COBJMACROS */


#endif 	/* C style interface */


#endif 	/* ___IOnModelExecEvents_DISPINTERFACE_DEFINED__ */


#ifndef __IOnEnv_INTERFACE_DEFINED__
#define __IOnEnv_INTERFACE_DEFINED__

/* interface IOnEnv */
/* [unique][helpstring][dual][uuid][object] */ 


EXTERN_C const IID IID_IOnEnv;

#if defined(__cplusplus) && !defined(CINTERFACE)
    
    MIDL_INTERFACE("BD8956DB-B293-44AB-88FD-8E659094DD86")
    IOnEnv : public IDispatch
    {
    public:
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_DataPath( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_DataPath( 
            /* [in] */ BSTR newVal) = 0;
        
        virtual /* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE get_GraphicPath( 
            /* [retval][out] */ BSTR __RPC_FAR *pVal) = 0;
        
        virtual /* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE put_GraphicPath( 
            /* [in] */ BSTR newVal) = 0;
        
    };
    
#else 	/* C style interface */

    typedef struct IOnEnvVtbl
    {
        BEGIN_INTERFACE
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *QueryInterface )( 
            IOnEnv __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [iid_is][out] */ void __RPC_FAR *__RPC_FAR *ppvObject);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *AddRef )( 
            IOnEnv __RPC_FAR * This);
        
        ULONG ( STDMETHODCALLTYPE __RPC_FAR *Release )( 
            IOnEnv __RPC_FAR * This);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfoCount )( 
            IOnEnv __RPC_FAR * This,
            /* [out] */ UINT __RPC_FAR *pctinfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetTypeInfo )( 
            IOnEnv __RPC_FAR * This,
            /* [in] */ UINT iTInfo,
            /* [in] */ LCID lcid,
            /* [out] */ ITypeInfo __RPC_FAR *__RPC_FAR *ppTInfo);
        
        HRESULT ( STDMETHODCALLTYPE __RPC_FAR *GetIDsOfNames )( 
            IOnEnv __RPC_FAR * This,
            /* [in] */ REFIID riid,
            /* [size_is][in] */ LPOLESTR __RPC_FAR *rgszNames,
            /* [in] */ UINT cNames,
            /* [in] */ LCID lcid,
            /* [size_is][out] */ DISPID __RPC_FAR *rgDispId);
        
        /* [local] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *Invoke )( 
            IOnEnv __RPC_FAR * This,
            /* [in] */ DISPID dispIdMember,
            /* [in] */ REFIID riid,
            /* [in] */ LCID lcid,
            /* [in] */ WORD wFlags,
            /* [out][in] */ DISPPARAMS __RPC_FAR *pDispParams,
            /* [out] */ VARIANT __RPC_FAR *pVarResult,
            /* [out] */ EXCEPINFO __RPC_FAR *pExcepInfo,
            /* [out] */ UINT __RPC_FAR *puArgErr);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_DataPath )( 
            IOnEnv __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_DataPath )( 
            IOnEnv __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        /* [helpstring][id][propget] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *get_GraphicPath )( 
            IOnEnv __RPC_FAR * This,
            /* [retval][out] */ BSTR __RPC_FAR *pVal);
        
        /* [helpstring][id][propput] */ HRESULT ( STDMETHODCALLTYPE __RPC_FAR *put_GraphicPath )( 
            IOnEnv __RPC_FAR * This,
            /* [in] */ BSTR newVal);
        
        END_INTERFACE
    } IOnEnvVtbl;

    interface IOnEnv
    {
        CONST_VTBL struct IOnEnvVtbl __RPC_FAR *lpVtbl;
    };

    

#ifdef COBJMACROS


#define IOnEnv_QueryInterface(This,riid,ppvObject)	\
    (This)->lpVtbl -> QueryInterface(This,riid,ppvObject)

#define IOnEnv_AddRef(This)	\
    (This)->lpVtbl -> AddRef(This)

#define IOnEnv_Release(This)	\
    (This)->lpVtbl -> Release(This)


#define IOnEnv_GetTypeInfoCount(This,pctinfo)	\
    (This)->lpVtbl -> GetTypeInfoCount(This,pctinfo)

#define IOnEnv_GetTypeInfo(This,iTInfo,lcid,ppTInfo)	\
    (This)->lpVtbl -> GetTypeInfo(This,iTInfo,lcid,ppTInfo)

#define IOnEnv_GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)	\
    (This)->lpVtbl -> GetIDsOfNames(This,riid,rgszNames,cNames,lcid,rgDispId)

#define IOnEnv_Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)	\
    (This)->lpVtbl -> Invoke(This,dispIdMember,riid,lcid,wFlags,pDispParams,pVarResult,pExcepInfo,puArgErr)


#define IOnEnv_get_DataPath(This,pVal)	\
    (This)->lpVtbl -> get_DataPath(This,pVal)

#define IOnEnv_put_DataPath(This,newVal)	\
    (This)->lpVtbl -> put_DataPath(This,newVal)

#define IOnEnv_get_GraphicPath(This,pVal)	\
    (This)->lpVtbl -> get_GraphicPath(This,pVal)

#define IOnEnv_put_GraphicPath(This,newVal)	\
    (This)->lpVtbl -> put_GraphicPath(This,newVal)

#endif /* COBJMACROS */


#endif 	/* C style interface */



/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOnEnv_get_DataPath_Proxy( 
    IOnEnv __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IOnEnv_get_DataPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOnEnv_put_DataPath_Proxy( 
    IOnEnv __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOnEnv_put_DataPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propget] */ HRESULT STDMETHODCALLTYPE IOnEnv_get_GraphicPath_Proxy( 
    IOnEnv __RPC_FAR * This,
    /* [retval][out] */ BSTR __RPC_FAR *pVal);


void __RPC_STUB IOnEnv_get_GraphicPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);


/* [helpstring][id][propput] */ HRESULT STDMETHODCALLTYPE IOnEnv_put_GraphicPath_Proxy( 
    IOnEnv __RPC_FAR * This,
    /* [in] */ BSTR newVal);


void __RPC_STUB IOnEnv_put_GraphicPath_Stub(
    IRpcStubBuffer *This,
    IRpcChannelBuffer *_pRpcChannelBuffer,
    PRPC_MESSAGE _pRpcMessage,
    DWORD *_pdwStubPhase);



#endif 	/* __IOnEnv_INTERFACE_DEFINED__ */


EXTERN_C const CLSID CLSID_IsMatrix;

#ifdef __cplusplus

class DECLSPEC_UUID("3F35CF67-839E-11D4-838D-00600894E802")
IsMatrix;
#endif

EXTERN_C const CLSID CLSID_IsNlaSolver;

#ifdef __cplusplus

class DECLSPEC_UUID("717E8184-92E1-11D4-98A8-00C04F6801A9")
IsNlaSolver;
#endif

EXTERN_C const CLSID CLSID_IsCINlaEso;

#ifdef __cplusplus

class DECLSPEC_UUID("E3CA3C2A-9466-11D4-98A8-00C04F6801A9")
IsCINlaEso;
#endif

EXTERN_C const CLSID CLSID_IsDaeEsoIImpl;

#ifdef __cplusplus

class DECLSPEC_UUID("732A30A4-CBE5-11D4-83A2-00600894E802")
IsDaeEsoIImpl;
#endif

EXTERN_C const CLSID CLSID_IsDaeEsoCImpl;

#ifdef __cplusplus

class DECLSPEC_UUID("704B0744-BE48-4E89-84B6-6AC44BA12933")
IsDaeEsoCImpl;
#endif

EXTERN_C const CLSID CLSID_OnModelExec;

#ifdef __cplusplus

class DECLSPEC_UUID("0BF65E89-4B0C-40E8-8065-DA9E82EF0FAA")
OnModelExec;
#endif

EXTERN_C const CLSID CLSID_OnTest;

#ifdef __cplusplus

class DECLSPEC_UUID("24BE2738-C38D-430E-A966-2896238B1D0C")
OnTest;
#endif

EXTERN_C const CLSID CLSID_OnEnv;

#ifdef __cplusplus

class DECLSPEC_UUID("F1B06AA9-2721-4516-8BC4-12B56F2C5E31")
OnEnv;
#endif
#endif /* __ISDAECOSOLVERLib_LIBRARY_DEFINED__ */

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
