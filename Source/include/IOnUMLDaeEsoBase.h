// IOnUMLDaeEsoBase.h
//
// --- Do not edit this header file.  It is a duplicate of the same header file defined in 
// --- the IsDaeCOSolver project.
//
// exported definition of IUnknown (to suppress compiler warning messages)

#ifndef _IONUMLDAEESOBASE_H_
#define _IONUMLDAEESOBASE_H_


#include "OnUMLEsoExports.h"
#include "OnDaeCOSolverTypeDefs.h"

// forward declarations
class IOnEventSink;
struct IIsDaeEso;
class Fdouble;

// suppress warning regarding the export of IOnUMLDaeEsoBase without exporting IUnknown
#pragma warning( disable : 4275 )

class ONUML_API IOnUMLDaeEsoBase : public IUnknown
{

public:
  // wrapper interface methods
  virtual HRESULT GetCppPtr(DWORD* ppModel) = 0;
  virtual HRESULT AddEso(IUnknown* pEsoImpl, BSTR modelName) = 0;
  virtual HRESULT GetOnModel(IIsDaeEso** ppModel) = 0;
  virtual HRESULT SetOnModel(IIsDaeEso* pModel) = 0;

  // initialization
  virtual HRESULT iInitialize() = 0;
  virtual HRESULT iInitializeGlobalNode() = 0;

  // dimensions
  virtual HRESULT GetNumEqns(long* nEqns) = 0;
  virtual HRESULT GetNumVars(long* nVars) = 0;
  virtual HRESULT GetNumRPars(long* nRPars) = 0;
  virtual HRESULT GetNumIPars(long* nIPars) = 0;

  // STN information (if any)
  virtual HRESULT GetSTNStruct(
    long* nStates, 
    long* nTransitions, 
    long* iDefaultState, 
    BSTR** TransEventIds, 
    long** SrcStates, 
    long*** StateToEqnMap, 
    long** nStateEqns,
    long*** TransToEqnMap,
    long** nTransEqns) = 0;

  // member Esos
  virtual HRESULT GetMemberEsos(long* nEsos, IOnUMLDaeEsoBase*** pEsos) = 0;
  virtual HRESULT GetEsosByRefStatus(bool* ByRef) = 0;
  virtual HRESULT GetMasterNodeStatus(bool* MasterNode) = 0;
  virtual HRESULT SetMasterNodeStatus(bool bMasterNode) = 0;

  // connections
  virtual HRESULT Connect(SAFEARRAY** ConnA, SAFEARRAY** ConnB) = 0;

  // equation form {continuous, discontinuous, reset}
  virtual HRESULT GetEquationForm(OnEqnForm** eqn_form, OnEqnDiffForm** eqn_diff_form) = 0;

  // model item naming (for user interaction)
  virtual HRESULT GetVarName(long index, BSTR* Name) = 0;
  virtual HRESULT GetEqnName(long index, BSTR* Name) = 0;
  virtual HRESULT GetEsoName(long index, BSTR* Name) = 0;
  virtual HRESULT GetRParName(long index, BSTR* Name) = 0;
  virtual HRESULT GetIParName(long index, BSTR* Name) = 0;
  virtual HRESULT GetStateName(long index, BSTR* Name) = 0;
  virtual HRESULT GetTransitionName(long index, BSTR* Name) = 0;

  // internal events
  virtual HRESULT EvalStateCondition(
    const bool* EqnState, 
    const double* x,
    const double* xdot,
    const double EventTime,
    const long iDisEqn,
    const long iTransition,
    bool* bEvent) = 0;

  virtual HRESULT TriggerEvent(const double EventTime, const BSTR EventId) = 0;

  // variables / parameters
  virtual HRESULT GetVariableInfo(double*** x, long* nVars) = 0;
  virtual HRESULT GetDerivativeInfo(double*** xdot, long* nVars) = 0;
  virtual HRESULT GetADVariableInfo(Fdouble*** ad_x, long* nVars) = 0;
  virtual HRESULT GetADDerivativeInfo(Fdouble*** ad_xdot, long* nVars) = 0;
  virtual HRESULT GetOldVariableInfo(double*** oldX, long* nVars) = 0;
  virtual HRESULT GetOldDerivativeInfo(double*** oldXDot, long* nVars) = 0;
  virtual HRESULT GetRealParameterInfo(double*** rpar, long* nRPars) = 0;
  virtual HRESULT GetIntegerParameterInfo(long*** ipar, long* nIPars) = 0;

  // residuals
  virtual HRESULT GetResiduals(
    long* iEqn, 
    long nEqn, 
    double t, 
    double* residuals) = 0;

  // jacobians
  virtual HRESULT GetJacobianStruct(
    long* nColIndices, 
    long** ColIndices, 
    long** cNZCols, 
    CalcMethod** calc_method) = 0;

  virtual HRESULT GetDiffJacobianStruct(
    long* nColIndices, 
    long** ColIndices, 
    long** cNZCols, 
    CalcMethod** calc_method) = 0;

  virtual HRESULT GetJacobianValues(
    long* iJac, 
    long nJac, 
    double t, 
    double* jacobians) = 0;
  
  virtual HRESULT GetDiffJacobianValues(
    long* iJac, 
    long nJac, 
    double t, 
    double* jacobians) = 0;

  virtual void Save(FILE* fs) = 0;
  virtual bool Load(FILE* fs) = 0;

};

#endif _IONUMLDAEESOBASE_H_