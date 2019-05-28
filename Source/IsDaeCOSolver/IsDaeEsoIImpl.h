// CIsDaeEsoIImpl.h : Declaration of the CIsDaeEsoIImpl

#ifndef __CIsDaeEsoIImpl_H_
#define __CIsDaeEsoIImpl_H_

#include "resource.h"       // main symbols
#include "IsDaeEso.h"
#include "IIsDaeModelImpl.h"

/////////////////////////////////////////////////////////////////////////////
// CIsDaeEsoIImpl
class ATL_NO_VTABLE CIsDaeEsoIImpl : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CIsDaeEsoIImpl, &CLSID_IsDaeEsoIImpl>,
	public ISupportErrorInfo,
	public IDispatchImpl<IIsDaeEsoIImpl, &IID_IIsDaeEsoIImpl, &LIBID_ISDAECOSOLVERLib>,
  public CIsDaeEsoBase
{
public:
  CIsDaeEsoIImpl();
  virtual ~CIsDaeEsoIImpl();

DECLARE_REGISTRY_RESOURCEID(IDR_ISDAEESOIIMPL)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CIsDaeEsoIImpl)
	COM_INTERFACE_ENTRY(IIsDaeEso)
	COM_INTERFACE_ENTRY(IIsDaeEsoIImpl)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

public:
  // IIsDaeEso
  IIS_DAE_MODEL_IMPL

public:
  virtual HRESULT iGetEquationForm(EqnForm*& eqn_form, EqnDiffForm*& eqn_diff_form);
  STDMETHOD(SetEso)(/*[in]*/ IIsDaeEsoImpl* pEso);

  STDMETHOD(SetSize)(long nEqns, long nVars, long nRPars, long IPars);
  virtual HRESULT iEvalStateCondition(
    bool* EqnState, 
    double EventTime, 
    long iDisEqn, 
    long iTransition,
    VARIANT_BOOL* bEvent);

  virtual HRESULT iGetVariableId(BSTR Name, long* idx) { return E_NOTIMPL; }
  virtual HRESULT iGetRealParId(BSTR Name, long* idx) { return E_NOTIMPL; }
  virtual HRESULT iGetIntParId(BSTR Name, long* idx) { return E_NOTIMPL; }


  virtual HRESULT iGetLocalJacobianStruct(MatInfo& JacStruct);
  virtual HRESULT iGetLocalMassStruct(MatInfo& MassStruct);
	virtual HRESULT iGetLocalResiduals(
		long* Indices,
    long cIndices,
		double t,
		double* y,
		double* ydot,
    double* residuals,
		bool& validVal,
		double* realParameters,
		long* integerParameters);

  virtual HRESULT iGetLocalJacobianValues(
    long* indices,
    long cIndices,
    MatInfo& JacStruct,
    double t, 
    double* y, 
    double* ydot,
		double* JacVals,
    double* rPar, 
    long* iPar,
    bool bIncludeConst);

  virtual HRESULT iGetLocalMassValues(
    long* Indices,
    long cIndices,
    MatInfo& MassStruct,
    double t, 
    double* y, 
    double* ydot,
		double* MassVals, 
    double* rPar, 
    long* iPar,
    bool bIncludeConst);

  virtual HRESULT TriggerEvent(double EventTime, BSTR EventId, long iEventEqn);
  STDMETHOD(PostTransition)(long iNewState);
  STDMETHOD(PostStateEvent)(double t, BSTR EventId);

protected:
  void initSafeArrays();
  void DestroySafeArrays();
  
  inline void SetArrays(
    double* y,
    double* ydot,
    double* rPar, 
    long* iPar,
    SAFEARRAY*& psa_x,
    SAFEARRAY*& psa_xdot,
    SAFEARRAY*& psa_rpar,
    SAFEARRAY*& psa_ipar);

protected:
  IIsDaeEsoImpl* m_pEsoImpl;
  SAFEARRAY* m_psa_x;
  SAFEARRAY* m_psa_xdot;
  SAFEARRAY* m_psa_rpar;
  SAFEARRAY* m_psa_ipar;
  SAFEARRAY* m_psa_iEqn;
  SAFEARRAY* m_psa_vEqn;
  SAFEARRAY* m_psa_iJac;
  SAFEARRAY* m_psa_iActiveJac;
  SAFEARRAY* m_psa_vJac;

  double* m_x;
  double* m_xdot;
  double* m_rpar;
  long* m_ipar;
  long* m_iEqn;
  double* m_vEqn;
  long* m_iJac;
  long* m_iActiveJac;
  double* m_vJac;

};

#endif //__CIsDaeEsoIImpl_H_
