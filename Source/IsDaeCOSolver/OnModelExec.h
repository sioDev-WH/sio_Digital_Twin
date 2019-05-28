// OnModelExec.h: Definition of the COnModelExec class
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_ONMODELEXEC_H__02E1CE5E_A5A9_4B29_A93E_F09558CCEE5B__INCLUDED_)
#define AFX_ONMODELEXEC_H__02E1CE5E_A5A9_4B29_A93E_F09558CCEE5B__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "resource.h"       // main symbols
#include "OnModelExecCP.h"
//struct _Collection;
//#include "OnInitialization.h"

class CIsDaeEsoCImpl;
class CIsCINlaEso;
class CIsDaeEsoBase;
class CIsStepper;
class FlatModel;
class ModelVarMap;
class COnInitDlg;

struct event_item;
struct _OnScriptParser;

/////////////////////////////////////////////////////////////////////////////
// COnModelExec

class COnModelExec : 
	public IDispatchImpl<IOnModelExec, &IID_IOnModelExec, &LIBID_ISDAECOSOLVERLib>, 
	public ISupportErrorInfo,
	public CComObjectRoot,
	public CComCoClass<COnModelExec,&CLSID_OnModelExec>,
	public IConnectionPointContainerImpl<COnModelExec>,
	public CProxy_IOnModelExecEvents< COnModelExec >,
	public CProxyIOnModelExecEvents< COnModelExec >
{
public:
	COnModelExec();
  virtual ~COnModelExec();

  void Destroy();

  typedef CProxy_IOnModelExecEvents< COnModelExec > DispatchProxy;
  typedef CProxyIOnModelExecEvents< COnModelExec > VTableProxy;

BEGIN_COM_MAP(COnModelExec)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(IOnModelExec)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
  COM_INTERFACE_ENTRY(IConnectionPointContainer)
END_COM_MAP()

BEGIN_CONNECTION_POINT_MAP(COnModelExec)
  CONNECTION_POINT_ENTRY(IID_IOnModelExecEvents)
  CONNECTION_POINT_ENTRY(DIID__IOnModelExecEvents)
END_CONNECTION_POINT_MAP()


//DECLARE_NOT_AGGREGATABLE(COnModelExec) 
// Remove the comment from the line above if you don't want your object to 
// support aggregation. 

DECLARE_REGISTRY_RESOURCEID(IDR_OnModelExec)
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IOnModelExec
public:
	STDMETHOD(HandleInitEvents)();
	STDMETHOD(Load)(/*[in]*/ BSTR filename);
	STDMETHOD(Save)(/*[in]*/ BSTR filename);
	STDMETHOD(Step)(/*[in]*/ double external_time);
	STDMETHOD(get_MaxStepSize)(/*[out, retval]*/ double *pVal);
	STDMETHOD(put_MaxStepSize)(/*[in]*/ double newVal);
  STDMETHOD(PostStateEvent)(double EventTime, BSTR EventId, long iEventEqn, IIsDaeEso* pEventModel);
	STDMETHOD(OnTransition)(double event_time, long iEventEqn, BSTR EventId, long iNewState, IIsDaeEso* pEventModel);
	STDMETHOD(SetModel)(/*[in]*/ IIsDaeEso* pModel);
	STDMETHOD(PostIPar)(/*[in]*/ double t, /*[in]*/ long iGlobalId, /*[in]*/ long val);
	STDMETHOD(PostRPar)(/*[in]*/ double t, /*[in]*/ long iGlobalId, /*[in]*/ double val);
  STDMETHOD(ForceReset)();
  STDMETHOD(get_RetryInitialization)(VARIANT_BOOL* bVal);
  STDMETHOD(put_RetryInitialization)(VARIANT_BOOL bVal);
  STDMETHOD(SetVariables)(SAFEARRAY** VarVals);
  STDMETHOD(GetResiduals)(long nEqns, SAFEARRAY** EqnIds, SAFEARRAY** Residuals);

protected:
  void init();
  void clean();
  void InternalEventDetection();
  HRESULT processEventQueue(double external_time);
  HRESULT iPostStateEvent(double EventTime, BSTR EventId, long iEventEqn, CIsDaeEsoBase* pEventEso, bool bExternal);
  void OrderEventQueue();
  void ValidateEventQueue();

  void performOutputAssignment(
    long nEqns,
    long nVars,
    long nAugmentedVars,
    long* cNZCols, 
    long* spRowPage, 
    long* ColIndices,
    long* VAL,
    long*& assignedEqn, 
    long*& itAssignedEqn,
    long*& itVAL);

  void printEqnStructure(
    CIsDaeEsoCImpl* pCImpl,
    long nEqns,
    long nVars,
    long nAugmentedVars,
    long* VAL,
    long* itVAL,
    long* EqnOrder,
    long* VarOrder,
    long* assignedEqn, 
    long* itAssignedEqn,
    bool bShowAssignment);

  void printEqnAndVarValues();

  void generateStepFailureReport();
// from ConsistentInitialization

  HRESULT ConsistentInitialization(
    long& nAugmentedEqns,
    long& nAugmentedVars,
    long*& assignedEqn,
    long*& VAL,
    CIsDaeEsoBase* pDaeEso,                    // pointer to differential algebraic model
    CComObject<CIsCINlaEso>*& pNlaEso,         // pointer to consistent initialization Nla Eso
    CIsDaeEsoBase* pTransitionEso = NULL,      // pointer to transition EsoX
    long iEventEqn = -1,                       // index of g*() (event initialization only)
    long* oldEqns = NULL,                      // indices of equations from source state
    long nOldEqns = 0,                         // number of equations in source state
    long* newEqns = NULL,                      // indices of equations in target state
    long nNewEqns = 0);                        // number of equations in target state

  void reportInitializationEqnInfo(
    bool bFault,
    InitStage stage,
    CIsDaeEsoBase* pDaeEso,
    long nEqns,
    long nVars,
    long* spRowPage,
    long* cNZCols,
    long nColIndices,
    long* ColIndices,
    long* EqnOrder, 
    long* VarOrder, 
    long* VAL,
    long* EAL,
    long* AssignedEqn);

  // remove old F(), G() and add new F() for MSS
  void replaceEquations(long* assignedEqn, FlatModel* fm, long* oldEqns, long nOldEqns, long* newEqns, long nNewEqns);
  // add old g* and R() equations for triangularization and initialization
  void addTransitionEquations(FlatModel* fm, long iEventEqn, long* oldEqns, long nOldEqns, addEquationInfo& addEqnInfo);
  // remove old g*() and R(), and add new state G() equations
  void replaceTransitionEquations(FlatModel* fm, long* oldEqns, long nOldEqns, long* newEqns, long nNewEqns);


  #if 0
  bool initEqns(long nDaeEsoEqns, long nDaeEsoVars, long nDaeEsoAugmentedVars, 
    long nAugmentedEqns, long nAugmentedVars, long* DaeEsoVarOrder,
    long* VAL, long* EAL, 
    long edgeList_nColIndices, long* edgeList_spRowPage, long* edgeList_cRowNZ, long* edgeList_columnIndices, 
    EqnStruct*& EqnStructs, long& nEqnStructs);
  #endif

  void ResizeCompactStructure(
    long nOldEqns, 
    long nOldColIndices, 
    long nNewEqns, 
    long nNewColIndices,
    long*& ColIndices, 
    long*& cNZCols, 
    long*& spRowPage);

  void DiffOrder(long* itAL, long size, long*& diffOrder);

// end from ConsistentInitialization


// from triangularization

  bool triangularizeMatrix(
    CIsDaeEsoBase* pDaeEso,
    long* VAL,
    long* EAL,
    long* eqnSource,
    bool bHighIndex,
    long &nEqns,                  // [in]       (scalar)
    long &nVars,                  // [in]       (scalar)
    long nColumnIndices,          // [in]       (scalar)
    long* in_columnIndices,       // [in]       [nColumnIndices]
    long* in_columnPageNumber,    // [in]       [nEqns]
    long* in_cRowNZ,              // [in]       [nEqns]
    long* out_columnIndices,      // [in, out]  [nColumnIndices]
    long* out_columnPageNumber,   // [in, out]  [nEqns]
    long* out_cRowNZ,             // [in, out]  [nEqns]
    long* assignedEqn,            // [in, out]  [nVars]
    long* columnOrder,            // [in, out]  [nVars] (initial order defined)
    long* rowOrder,               // [in, out]  [nVars] (initial order defined)
    long& cBlocks,                // [in, out]  (scalar)
    long* blockSizes,             // [in, out]  [nVars]
    long* out_orderMap,           // [in, out]  [nVars]
    ModelVarMap** VarMap,
    long* EqnOrder,
    long* VarOrder,
    addEquationInfo& addEqnInfo, 
    trimEquationInfo& trimEqnInfo, 
    trimConstraintInfo& trimConInfo);

  void FillSquareMatrix(bool bHighIndex, long nEqns, long nVars, long nColumnIndices,
                        long* in_columnPageNumber, long* in_cRowNZ, long* in_columnIndices, 
                        ModelVarMap** VarMap, long* VarOrder, long* assignedEqn,
                        long* s_columnPageNumber, long* s_cRowNZ, long* s_columnIndices, long& s_nColumnIndices);

  void GetUnassignedVars(long nEqns, long nVars, long* assignedEqn, 
                        long nColIndices, long* in_spRowPage, long* in_cRowNZ, long* in_colIndices, 
                        ModelVarMap** VarMap, long* VarOrder, 
                        long*& out_Vars, long& out_nVars);

// end from triangularization

protected:
  CIsDaeEsoBase* m_M;       // model
  IIsDaeEso* m_pIIsDaeEso;
  CIsStepper* m_pStepper;    // stepper
  
  // cached MSS results
  long m_nAugmentedEqns;
  long m_nAugmentedVars;
  long* m_assignedEqn;
  long* m_VAL;

  event_item** m_Events;
  long m_nEvents;
  long m_dEvents;
  bool m_bEventPostedWithoutReset;
  bool m_bEventProcessed;

  bool m_bRetryInitialization;

  CComObject<CIsCINlaEso>* m_pCINlaEso;
  _OnScriptParser* m_pScriptParser;

};

#endif // !defined(AFX_ONMODELEXEC_H__02E1CE5E_A5A9_4B29_A93E_F09558CCEE5B__INCLUDED_)
