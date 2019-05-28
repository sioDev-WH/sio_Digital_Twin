// IOnUMLDaeEsoBase.h: interface for the IOnUMLDaeEsoBase class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_OnUMLDaeEsoBase_H__)
#define AFX_OnUMLDaeEsoBase_H__

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "CommonTools.h"
#include "IOnUMLDaeEsoBase.h"
#include "IOnVarInit.h"
#include "TransitionInfo.h"
#include "StateInfo.h"

// forward declarations
class IOnEventSink;
class COnUMLLink;
class COnUMLAssociation;
struct IOnEnv;
// end forward declarations

class ONUML_API COnUMLDaeEsoBase : public IOnUMLDaeEsoBase, public IOnVarInit
{
public:
  COnUMLDaeEsoBase();
  virtual ~COnUMLDaeEsoBase();

public:

// *********************************************************************
// IUnknown
// *******************************************

  ULONG STDMETHODCALLTYPE AddRef();
  ULONG STDMETHODCALLTYPE Release();
  HRESULT STDMETHODCALLTYPE QueryInterface(REFIID iid, void ** ppv);

// *********************************************************************
// IOnUMLDaeEsoBase
// *******************************************

  virtual HRESULT GetCppPtr(DWORD* ppModel);
  virtual HRESULT AddEso(IUnknown* pEsoImpl, BSTR modelName);
  virtual HRESULT GetOnModel(IIsDaeEso** ppModel); 
  virtual HRESULT SetOnModel(IIsDaeEso* pModel);

  virtual HRESULT iInitialize();
  virtual HRESULT iInitializeGlobalNode() { return S_OK; }

  virtual HRESULT GetNumEqns(long* nEqns);
  virtual HRESULT GetNumVars(long* nVars);
  virtual HRESULT GetNumRPars(long* nRPars);
  virtual HRESULT GetNumIPars(long* nIPars);

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
    long** nTransEqns);

  // member Esos
  HRESULT GetMemberEsos(long* nEsos, IOnUMLDaeEsoBase*** pEsos);
  HRESULT GetEsosByRefStatus(bool* ByRef) { *ByRef = m_bEsosByRef; return S_OK; }
  HRESULT GetMasterNodeStatus(bool* MasterNode) { *MasterNode = m_bMasterNode; return S_OK; }
  HRESULT SetMasterNodeStatus(bool bMasterNode);
  
  HRESULT GetNumByRefEsos(long& nEsos);
  HRESULT GetAllByRefEsos(long& nEsos, COnUMLDaeEsoBase**& pEsos);
  HRESULT GetAllAssociations(long& nLinks, long& dLinks, COnUMLLink**& Links);
  HRESULT GetAssociationBlocks(long& nBlocks, long*& spBlocks, long*& cNZBlocks, COnUMLDaeEsoBase**& pRetEsos);

  // equation form {continuous, discontinuous, reset}
  virtual HRESULT GetEquationForm(OnEqnForm** eqn_form, OnEqnDiffForm** eqn_diff_form);

  // model item naming (for user interaction)
  virtual HRESULT GetVarName(long index, BSTR* Name);
  virtual HRESULT GetEqnName(long index, BSTR* Name);
  virtual HRESULT GetEsoName(long index, BSTR* Name);
  virtual HRESULT GetRParName(long index, BSTR* Name);
  virtual HRESULT GetIParName(long index, BSTR* Name);
  virtual HRESULT GetStateName(long index, BSTR* Name);
  virtual HRESULT GetTransitionName(long index, BSTR* Name);

  // internal events
  virtual HRESULT EvalStateCondition(
    const bool* EqnState, 
    const double* x,
    const double* xdot,
    const double EventTime,
    const long iDisEqn,
    const long iTransition,
    bool* bEvent) { return E_NOTIMPL; }

  virtual HRESULT TriggerEvent(const double EventTime, const BSTR EventId) { return E_NOTIMPL; }

  // notify solver of changes in state, and model parameterization
  HRESULT PostStateEvent(double t, BSTR EventId);
  HRESULT PostTransition(long iNewState);
  HRESULT PostRealParameter(double t, long Id, double newVal);
  HRESULT PostIntegerParameter(double t, long Id, long newVal);

  // jacobians (by default, these function are not implemented)
  // typically, jacobians are only implemented on leaf Esos for performance / accuracy reasons
  virtual HRESULT GetJacobianStruct(
    long* nColIndices, 
    long** ColIndices, 
    long** cNZCols, 
    CalcMethod** calc_method) { return E_NOTIMPL; }
  virtual HRESULT GetDiffJacobianStruct(
    long* nColIndices, 
    long** ColIndices, 
    long** cNZCols, 
    CalcMethod** calc_method) { return E_NOTIMPL; }
  virtual HRESULT GetJacobianValues(
    long* iJac, 
    long nJac, 
    double t, 
    double* jacobians) { return E_NOTIMPL; }
  virtual HRESULT GetDiffJacobianValues(
    long* iJac, 
    long nJac, 
    double t, 
    double* jacobians) { return E_NOTIMPL; }


// *********************************************************************
// COnUMLDaeEsoBase methods
// *******************************************


  // Code generated initialization methods
  virtual HRESULT InitLocalEqns() { return S_OK; }
  virtual HRESULT InitLocalADEqns() { return S_OK; }
  virtual HRESULT InitEqnForm(OnEqnForm** form, OnEqnDiffForm** diff_form);
  virtual HRESULT InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly) { return S_OK; }

  virtual HRESULT InitLocalRPars(const _TCHAR* prefix, double*** pars, _TCHAR*** Names, long* nPars, long* dPars) { return S_OK; }
  virtual HRESULT InitLocalIPars(const _TCHAR* prefix, long*** pars, _TCHAR*** Names, long* nPars, long* dPars) { return S_OK; }
  virtual HRESULT InitEsos() { return S_OK; }
  virtual HRESULT InitStates() { return S_OK; }
  virtual HRESULT InitTransitions() { return S_OK; }
  virtual HRESULT InitAssociations() { return S_OK; }

  // variable and parameter accessor functions (with default implementation)
  HRESULT GetVariableInfo(double*** x, long* nVars) { *x = m_varC.vars; *nVars = m_varC.nVars; return S_OK; } 
  HRESULT GetDerivativeInfo(double*** xdot, long* nVars) { *xdot = m_varC.derVars; *nVars = m_varC.nVars; return S_OK; }
  HRESULT GetADVariableInfo(Fdouble*** ad_x, long* nVars) { *ad_x = m_varC.FVars; *nVars = m_varC.nADVars; return S_OK; }
  HRESULT GetADDerivativeInfo(Fdouble*** ad_xdot, long* nVars) { *ad_xdot = m_varC.derFVars; *nVars = m_varC.nADVars; return S_OK; } 
  HRESULT GetOldVariableInfo(double*** oldX, long* nVars) { *oldX = m_varC.oldVars; *nVars = m_varC.nVars; return S_OK; }
  HRESULT GetOldDerivativeInfo(double*** oldXDot, long* nVars) { *oldXDot = m_varC.derOldVars; *nVars = m_varC.nVars; return S_OK; }
  HRESULT GetRealParameterInfo(double*** rpar, long* nRPars) { *rpar = m_LocalRPars; *nRPars = m_nLocalRPars; return S_OK; }
  HRESULT GetIntegerParameterInfo(long*** ipar, long* nIPars) { *ipar = m_LocalIPars; *nIPars = m_nLocalIPars; return S_OK; }

  // addition and deletion of Esos
  //HRESULT InitMemberEsos();
  #define ADD_LOCAL_ESO(ESO) AddMemberEso(ESO, _T(#ESO));
  HRESULT AddMemberEso(COnUMLDaeEsoBase* pEso, _TCHAR* Name);
  HRESULT RemoveMemberEso(long index);
  HRESULT RemoveAllMemberEsos();

  // addition and deletion of associations
  HRESULT AddAssociation(COnUMLAssociation* pAssoc);
  HRESULT RemoveAssociation(long index);

  // addition and deletion of transitions
  HRESULT AddTransition(const _TCHAR* Name, const long SourceState, const _TCHAR* EventId, const long* Eqns, const long nEqns);
  HRESULT RemoveTransition(long index);

  // addition and deletion of states
  HRESULT AddState(const _TCHAR* Name, const bool bIsDefault, const long* Eqns, const long nEqns);
  HRESULT RemoveState(long index);

  // identification
  HRESULT GetType(BSTR* Type);
  HRESULT GetId(GUID* Id);
  HRESULT GetId(long* Path, long size, GUID* Id);

  // utility methods:
  void CopyGUID(const GUID& source, GUID& target);

  // helper methods for file location
  HRESULT GetDataPath(BSTR* path);

#if 0
  void SetVerbosePrint() { _verbose_print = true; }
#endif

protected:


  IOnEnv* m_pOnEnv;

  // reference counting
  IIsDaeEso* m_pOnModel;
  ULONG m_cRef;                           // reference count for IUnknown interface implementation

  double m_time;

  // variables, old variables, derivatives, and AD variables
  VarCont m_varC;
/*
  double** m_x;
  double** m_xdot;
  double** m_oldX;
  double** m_oldXDot;
  Fdouble** m_ad_x;
  Fdouble** m_ad_xdot;
  long m_nLocalVars;
  long m_nADVars;
  long m_dADVars;
  long m_dLocalVars;
  BSTR* m_VarNames;
*/
  long* m_ad_x_color;

  // real parameters
  double** m_LocalRPars;
  long m_nLocalRPars;
  long m_dLocalRPars;
  BSTR* m_RParNames;

  // integer parameters
  long** m_LocalIPars;
  long m_nLocalIPars;
  long m_dLocalIPars;
  BSTR* m_IParNames;

  // ******************************************************************************************
  // NOTE: All distributed equations must be added after normal equations
  //       Calls to distributed equations are at equation indices >= m_nLocalEqns
  //      
  // Example:  m_nLocalEqns = 3;
  //           m_nLocalDistEqns = 3; where each equation has 20 residuals
  //           
  //           eqn indices < 3 are calls to normal local equations
  //           eqn indices >= 3 are calls to distributed equations
  //           -->  These calls are adjusted to single calls returning many residuals
  // ******************************************************************************************

  // equation counts (equation vector defined in template class)
  long m_nLocalEqns;
  long m_dLocalEqns;
  long m_nLocalADEqns;
  long m_dLocalADEqns;
  BSTR* m_EqnNames;
  BSTR* m_DistEqnNames;
  BSTR* m_StlEqnNames;

  // distributed equation counts (equation vectors defined in template class)
  long m_nLocalDistEqns;
  long m_dLocalDistEqns;
  long m_nLocalDistADEqns;
  long m_dLocalDistADEqns;

  long m_nLocalStlEqns;
  long m_dLocalStlEqns;
  long m_nLocalStlADEqns;
  long m_dLocalStlADEqns;

  // distributed equation residual counts, and result variable pointers
  long* m_LocalDistEqnResCount;             // count of residuals per distributed equation
  bool* m_LocalDistEqnColor;                // for tracking which dist equations have been visited
  DistributedVar** m_LocalDistEqnVars;      // distributed vars holding residual results from residual fcn calls
  FDistributedVar** m_LocalDistADEqnVars;   // distributed vars holding AD residual results from AD residual fcn calls

  // stl equation residual counts, and result variable pointers
  long* m_LocalStlEqnResCount;              // count of residuals per stl equation
  bool* m_LocalStlEqnColor;                 // for tracking which dist equations have been visited
  valarray<double>** m_LocalStlEqnVars;     // stl vars holding residual results from residual fcn calls
  valarray<Fdouble>** m_LocalStlADEqnVars;  // stl vars holding AD residual results from AD residual fcn calls

  // equation format
  OnEqnForm* m_EqnForm;                     // format of local equations {continuous, discontinuous, reset}
  OnEqnDiffForm* m_EqnDiffForm;             // differentiation form { numeric, automatic, symbolic }

  // connection point / event interface 
  BSTR* m_EventCPs;                       // connection point GUIDs 
  IOnEventSink** m_EventSinks;            // event sink interface vector for firing events.
  long m_EventSinkSize;                   // size of event sink vector
  long m_EventSinkDim;                    // dimension of event sink vector (for resizing)

  // Composite Eso mapping
  COnUMLAssociation** m_Associations;     // association between Esos
  long m_nAssociations;                   // number of associations
  long m_dAssociations;                   // dimension of m_Associations vector

  //bool m_bEsosInitialized;                // member Eso references have been initialized
  COnUMLDaeEsoBase** m_Esos;              // member Esos
  long m_nEsos;                           // number of member Esos
  long m_dEsos;                           // dimension of m_Esos vector
  BSTR* m_EsoNames;                       // Eso names (optional)

  bool m_bEsosByRef;                      // if true; member Esos are referenced instead of contained
  bool m_bMasterNode;                     

  // state machine information
  StateInfo** m_States;                   // { equation map }
  long m_nStates;                         // number of states
  long m_dStates;                         // dimension of state vector
  long m_DefaultState;                    // index of default state in the machine

  TransitionInfo** m_Transitions;         // {SourceState, EventId, equation map}
  long m_nTransitions;                    // number of transitions
  long m_dTransitions;                    // dimension of transition vector

  // identification
  GUID m_TypeGUID;                        // Type Id (type identification for derived classes)
  GUID m_GUID;                            // unique identifier for relationships
  long m_GlobalIndex;                     // long index for connection analysis

#if 0
  long _verbose_print;
#endif
};



#endif // !defined(AFX_OnUMLDaeEsoBase_H__)
