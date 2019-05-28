// IsCINlaEso.h : Declaration of the CIsCINlaEso

#ifndef __ISCINLAESO_H_
#define __ISCINLAESO_H_


class CIsDaeEsoBase;
class MatInfo;
class ModelEqnMap;
class ModelVarMap;

#include "resource.h"       // main symbols
#include "ConsistentInitialization.h"

/////////////////////////////////////////////////////////////////////////////
// CIsCINlaEso
class ATL_NO_VTABLE CIsCINlaEso : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CIsCINlaEso, &CLSID_IsCINlaEso>,
	public ISupportErrorInfo,
	public IDispatchImpl<IIsNlaEso, &IID_IIsNlaEso, &LIBID_ISDAECOSOLVERLib>
{
public:
	CIsCINlaEso();
  virtual ~CIsCINlaEso();

DECLARE_REGISTRY_RESOURCEID(IDR_ISCINLAESO)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CIsCINlaEso)
	COM_INTERFACE_ENTRY(IIsNlaEso)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

public:
// IIsNlaEso
  STDMETHOD(GetNumEqns)(long* nEqns);
  STDMETHOD(GetNumVars)(long* nVars);
  STDMETHOD(GetAllVariables)(SAFEARRAY** Vals);
  STDMETHOD(SetAllVariables)(SAFEARRAY** Vals);
  STDMETHOD(GetResiduals)(SAFEARRAY** x, SAFEARRAY** residuals);
  STDMETHOD(GetResidual)(long iEqn, SAFEARRAY** x, double* residual);
  STDMETHOD(SetVariable)(long index, double Val);

	STDMETHOD(GetJacobianStruct)(
    long* nColIndices, 
    SAFEARRAY** ColIndices, 
    SAFEARRAY** cNZCols, 
    SAFEARRAY** CalcMethod);
	STDMETHOD(GetJacobianValues)(SAFEARRAY** Indices, SAFEARRAY** JacVals);
	STDMETHOD(GetAllJacobianValues)(SAFEARRAY** ppsaIndices, SAFEARRAY** JacVals);
  STDMETHOD(Solve)();

#if 0
  STDMETHOD(UpdateJacobian)();
  STDMETHOD(PrintJacobian)();
#endif

public:
  void SetCIData( 
      long nVars, long nEqns,
      long nAugmentedVars, long nAugmentedEqns,
      long* VarOrder, long* EqnOrder, long* VAL, long* itVAL,
      CIsDaeEsoBase* pDaeEso, CIsDaeEsoBase* pTransitionEso, long iEventEqn);

  void SetTriangularizationData(
      long* tr_spRowPage, long* tr_cNZCols, long* tr_ColIndices,
      long* tr_assignedEqn, long* tr_columnOrder, long* tr_rowOrder, 
      long tr_cBlocks, long* tr_blockSizes, long* tr_orderMap);

  void SetNlaSolver(IIsNlaSolver* pNlaSolver) { m_pNlaSolver = pNlaSolver; }

protected:
  void ReadEsoVariables();
  void WriteEsoVariables();
  void WriteBlockVariables();
  void WriteBlockVariable(long iVar);

  bool evalEqn(long iEqn, double& residual, long iVar = -1, double varVal = 0.0);
  bool evalDiffEqn(long iEqn, double& residual);
  void compute_dg_dt(double t, double* y, double* ydot, double& dg_dt, long iEqn, long iDaeVar);
  void compute_deltaG(double t_event, double dg_dt, double t_event_tol, double& delta_g);
  bool compute_dfi_dj(long iSourceEqn, long iVar, double dj_dt, double& dfi_djVal);
  void initializeJacobian();
  void initialize_dg_dt();
  HRESULT OneVarSolver();

public:  

  // from consistent initialization module
  long m_nVars;
  long m_nEqns;
  long m_nAugmentedVars;
  long m_nAugmentedEqns;

  CIsDaeEsoBase* m_pDaeEso;
  CIsDaeEsoBase* m_pTransitionEso;

  FlatModel* m_fm;
  long* m_VarOrder;
  long* m_EqnOrder;
  long* m_VAL;
  long* m_itVAL;
  long* m_itEqnOrder;

  long m_iEventEqn;

  double m_delta_g_min;   // for calculating delta_g 
  double m_delta_g_max;   // for calculating delta_g 


  // block triangularization data
  long* m_tr_spRowPage;
  long* m_tr_cNZCols;
  long* m_tr_ColIndices;
  long* m_tr_assignedEqn;     // [iVar] = iEqn
  long* m_tr_columnOrder;
  long* m_tr_rowOrder;
  long m_tr_cBlocks;
  long* m_tr_blockSizes;
  long* m_tr_orderMap;

  long m_cBlockVars;      // count of variables in current block
  long m_spBlock;         // current block start page (index into order map)

  // NlaSolver
  CComPtr<IIsNlaSolver> m_pNlaSolver;

  // allocated locally
  double* m_Vars;
  long* m_tr_AssignedVar; // [iEqn] = iVar
  long* m_BlockVarMap;    // variables in current block
  long* m_BlockEqnMap;    // equations in current block


  // dg_dt used during the calculation of g*
  double m_dg_dt_for_g_star;

  MatInfo* m_JacStruct;
  MatInfo* m_Jac;
};

#endif //__ISCINLAESO_H_
