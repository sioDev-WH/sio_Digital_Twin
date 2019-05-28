// IIsDaeModelImpl.h

#ifndef _IIS_DAE_MODEL_IMPL_H_
#define _IIS_DAE_MODEL_IMPL_H_

/////////////////////////////////////////////////////////////////////
// DAE Model IIsDaeEso interface implementation macro
//
// Provides the pass through calls to CIsDaeEsoTImpl for all IIsDaeEso 
// interface functions for models derived from CIsDaeEsoImpl
//
#define IIS_DAE_MODEL_IMPL \
STDMETHODIMP PostRealParameter(double t, long Id, double newVal) \
{ return CIsDaeEsoBase::PostRealParameter(t, Id, newVal); } \
STDMETHODIMP PostIntegerParameter(double t, long Id, long newVal) \
{ return CIsDaeEsoBase::PostIntegerParameter(t, Id, newVal); } \
STDMETHODIMP SetModelExec(IOnModelExec* pModelExec) \
{ return CIsDaeEsoBase::SetModelExec(pModelExec); } \
STDMETHODIMP GetReportInfo(long* StepperCalls, long* functionCalls, long* jacobiansCalls, long* DecompCalls, long* Substitutions, long* TotalSteps, long* errorRejectedSteps, long* newtonRejectedSteps, long* growthRejectedSteps, long* funcRejectedSteps, long* nStateEvents, long* nParameterEvents, long* nStepSizeChanges) \
{ return CIsDaeEsoBase::GetReportInfo(StepperCalls, functionCalls, jacobiansCalls, DecompCalls, Substitutions, TotalSteps, errorRejectedSteps, newtonRejectedSteps, growthRejectedSteps, funcRejectedSteps, nStateEvents, nParameterEvents, nStepSizeChanges); } \
STDMETHODIMP InitTime(double StartTime, VARIANT_BOOL Reverse) \
{ return CIsDaeEsoBase::InitTime(StartTime, Reverse); } \
STDMETHODIMP SetTime(double time) \
{ return CIsDaeEsoBase::SetTime(time); } \
STDMETHODIMP SetLastTime(double time) \
{ return CIsDaeEsoBase::SetLastTime(time); } \
STDMETHODIMP SetRelTolerance(SAFEARRAY** relTolValue) \
{ return CIsDaeEsoBase::SetRelTolerance(relTolValue); } \
STDMETHODIMP GetRelTolerance(SAFEARRAY** relTolValue) \
{ return CIsDaeEsoBase::GetRelTolerance(relTolValue); } \
STDMETHODIMP SetAbsTolerance(SAFEARRAY** absTolValues) \
{ return CIsDaeEsoBase::SetAbsTolerance(absTolValues); } \
STDMETHODIMP GetAbsTolerance(SAFEARRAY** absTolValues) \
{ return CIsDaeEsoBase::GetAbsTolerance(absTolValues); } \
STDMETHODIMP GetAllResiduals(SAFEARRAY** residuals,	VARIANT_BOOL* validVal) \
{ return CIsDaeEsoBase::GetAllResiduals(residuals, validVal); } \
STDMETHODIMP GetResiduals(SAFEARRAY** Indices, SAFEARRAY** residuals,	VARIANT_BOOL* validVal) \
{ return CIsDaeEsoBase::GetResiduals(Indices, residuals, validVal); } \
STDMETHODIMP GetJacobianStruct(long* nColIndices, SAFEARRAY** ColIndices, SAFEARRAY** cNZCols, SAFEARRAY** CalcMethod) \
{ return CIsDaeEsoBase::GetJacobianStruct(nColIndices, ColIndices, cNZCols, CalcMethod); } \
STDMETHODIMP GetJacobianValues(SAFEARRAY** Indices, SAFEARRAY** JacVals) \
{ return CIsDaeEsoBase::GetJacobianValues(Indices, JacVals); } \
STDMETHODIMP GetAllJacobianValues(IIsMatrix** ppJacVals) \
{ return CIsDaeEsoBase::GetAllJacobianValues(ppJacVals); } \
STDMETHODIMP GetDiffJacobianStruct(long* nColIndices, SAFEARRAY** ColIndices, SAFEARRAY** cNZCols, SAFEARRAY** CalcMethod) \
{ return CIsDaeEsoBase::GetDiffJacobianStruct(nColIndices, ColIndices, cNZCols, CalcMethod); } \
STDMETHODIMP GetDiffJacobianValues(SAFEARRAY** Indices, SAFEARRAY** MassVals) \
{ return CIsDaeEsoBase::GetDiffJacobianValues(Indices, MassVals); } \
STDMETHODIMP GetAllDiffJacobianValues(IIsMatrix** ppMassVals) \
{ return CIsDaeEsoBase::GetAllDiffJacobianValues(ppMassVals); } \
STDMETHODIMP GetNumRealPars(long* nRPars) \
{ return CIsDaeEsoBase::GetNumRealPars(nRPars); } \
STDMETHODIMP GetRealPar(long index, double* Val) \
{ return CIsDaeEsoBase::GetRealPar(index, Val); } \
STDMETHODIMP GetRealParId(BSTR Name, long* idx) \
{ return CIsDaeEsoBase::GetRealParId(Name, idx); } \
STDMETHODIMP SetRealPar(long index, double newVal) \
{ return CIsDaeEsoBase::SetRealPar(index, newVal); } \
STDMETHODIMP GetNumIntPars(long* nIPars) \
{ return CIsDaeEsoBase::GetNumIntPars(nIPars); } \
STDMETHODIMP GetIntPar(long index, long* Val) \
{ return CIsDaeEsoBase::GetIntPar(index, Val); } \
STDMETHODIMP GetIntParId(BSTR Name, long* idx) \
{ return CIsDaeEsoBase::GetIntParId(Name, idx); } \
STDMETHODIMP SetIntPar(long index, long newVal) \
{ return CIsDaeEsoBase::SetIntPar(index, newVal); } \
STDMETHODIMP GetVariables(SAFEARRAY** Indices, double t, SAFEARRAY** Vals) \
{ return CIsDaeEsoBase::GetVariables(Indices, t, Vals); } \
STDMETHODIMP GetVariable(long index, double t, double* val) \
{ return CIsDaeEsoBase::GetVariable(index, t, val); } \
STDMETHODIMP GetVariableId(BSTR Name, long* idx) \
{ return CIsDaeEsoBase::GetVariableId(Name, idx); } \
STDMETHODIMP SetVariables(SAFEARRAY** Indices, SAFEARRAY** Vals) \
{ return CIsDaeEsoBase::SetVariables(Indices, Vals); } \
STDMETHODIMP SetVariable(long index, double val) \
{ return CIsDaeEsoBase::SetVariable(index, val); } \
STDMETHODIMP SetLastVariable(long index, double val) \
{ return CIsDaeEsoBase::SetLastVariable(index, val); } \
STDMETHODIMP GetAllVariables(double t, SAFEARRAY** Vals) \
{ return CIsDaeEsoBase::GetAllVariables(t, Vals); } \
STDMETHODIMP SetAllVariables(SAFEARRAY** Vals) \
{ return CIsDaeEsoBase::SetAllVariables(Vals); } \
STDMETHODIMP GetDerivatives(SAFEARRAY** Indices, double t, SAFEARRAY** Vals) \
{ return CIsDaeEsoBase::GetDerivatives(Indices, t, Vals); } \
STDMETHODIMP GetDerivative(long index, double t, double* val) \
{ return CIsDaeEsoBase::GetDerivative(index, t, val); } \
STDMETHODIMP SetDerivatives(SAFEARRAY** Indices, SAFEARRAY** Vals) \
{ return CIsDaeEsoBase::SetDerivatives(Indices, Vals); } \
STDMETHODIMP SetDerivative(long index, double val) \
{ return CIsDaeEsoBase::SetDerivative(index, val); } \
STDMETHODIMP SetLastDerivative(long index, double val) \
{ return CIsDaeEsoBase::SetLastDerivative(index, val); } \
STDMETHODIMP GetAllDerivatives(double t, SAFEARRAY** Vals) \
{ return CIsDaeEsoBase::GetAllDerivatives(t, Vals); } \
STDMETHODIMP SetAllDerivatives(SAFEARRAY** Vals) \
{ return CIsDaeEsoBase::SetAllDerivatives(Vals); } \
STDMETHODIMP GetNumVars(long* nVars) \
{ return CIsDaeEsoBase::GetNumVars(nVars); } \
STDMETHODIMP GetNumEqns(long* nEqns) \
{ return CIsDaeEsoBase::GetNumEqns(nEqns); } \
STDMETHODIMP GetNumLocalVars(long* nVars) \
{ return CIsDaeEsoBase::GetNumLocalVars(nVars); } \
STDMETHODIMP GetNumLocalEqns(long* nEqns) \
{ return CIsDaeEsoBase::GetNumLocalEqns(nEqns); } \
STDMETHODIMP GetVariablesIndex(SAFEARRAY** Index) \
{ return CIsDaeEsoBase::GetVariablesIndex(Index); } \
STDMETHODIMP GetLastTime(double* t) \
{ return CIsDaeEsoBase::GetLastTime(t); } \
STDMETHODIMP GetTime(double* t) \
{ return CIsDaeEsoBase::GetTime(t); } \
STDMETHODIMP GetCPPPtr(DWORD* pIsDaeEso) \
{ return CIsDaeEsoBase::GetCPPPtr(pIsDaeEso); } \
STDMETHODIMP get_ContainerIndex(long* Index) \
{ return CIsDaeEsoBase::get_ContainerIndex(Index); } \
STDMETHODIMP put_ContainerIndex(long Index) \
{ return CIsDaeEsoBase::put_ContainerIndex(Index); } \
STDMETHODIMP get_VariableMap(SAFEARRAY** Map) \
{ return CIsDaeEsoBase::get_VariableMap(Map); } \
STDMETHODIMP put_VariableMap(SAFEARRAY** Map) \
{ return CIsDaeEsoBase::put_VariableMap(Map); } \
STDMETHODIMP EvalStateCondition(double ZeroCrossingTime, long iDisEqn, long iTransition, VARIANT_BOOL* bEvent) \
{ return CIsDaeEsoBase::EvalStateCondition(ZeroCrossingTime, iDisEqn, iTransition, bEvent); } \
STDMETHODIMP AddEso(IIsDaeEso* pEso) \
{ return CIsDaeEsoBase::AddEso(pEso); } \
STDMETHODIMP GetEso(long index, IIsDaeEso** pEso) \
{ return CIsDaeEsoBase::GetEso(index, pEso); } \
STDMETHODIMP RemoveEso(long index) \
{ return CIsDaeEsoBase::RemoveEso(index); } \
STDMETHODIMP GetNumEso(long* count) \
{ return CIsDaeEsoBase::GetNumEso(count); }

#endif // _IIS_DAE_MODEL_IMPL_H_