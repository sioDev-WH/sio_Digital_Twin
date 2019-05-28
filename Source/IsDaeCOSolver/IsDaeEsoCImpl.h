// IsDaeEsoCImpl.h : Declaration of the CIsDaeEsoCImpl

#ifndef __ISDAEESOCIMPL_H_
#define __ISDAEESOCIMPL_H_

#include "resource.h"       // main symbols
#include "IsDaeEso.h"
#include "IIsDaeModelImpl.h"

class IOnUMLDaeEsoBase;
class Fdouble;

/////////////////////////////////////////////////////////////////////////////
// CIsDaeEsoCImpl
class ATL_NO_VTABLE CIsDaeEsoCImpl : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CIsDaeEsoCImpl, &CLSID_IsDaeEsoCImpl>,
	public ISupportErrorInfo,
	public IDispatchImpl<IIsDaeEsoCImpl, &IID_IIsDaeEsoCImpl, &LIBID_ISDAECOSOLVERLib>,
  public CIsDaeEsoBase

{
public:
	CIsDaeEsoCImpl();
  virtual ~CIsDaeEsoCImpl();

DECLARE_REGISTRY_RESOURCEID(IDR_ISDAEESOCIMPL)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CIsDaeEsoCImpl)
	COM_INTERFACE_ENTRY(IIsDaeEso)
	COM_INTERFACE_ENTRY(IIsDaeEsoCImpl)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

public:
  
  // IIsDaeEsoCImpl
  STDMETHOD(GetEsoNames)(SAFEARRAY** pEsoNames);
  STDMETHOD(get_Eso)( BSTR Name,  IIsDaeEsoCImpl** pEso);
  STDMETHOD(GetVarNames)( SAFEARRAY** pVarNames);
  STDMETHOD(get_Var)( BSTR Name,  double* pVal);
  STDMETHOD(put_Var)( BSTR Name,  double Val);
  STDMETHOD(GetRParNames)( SAFEARRAY** pRParNames);
  STDMETHOD(get_RPar)( BSTR Name,  double* pVal);
  STDMETHOD(put_RPar)( BSTR Name,  double Val);
  STDMETHOD(GetIParNames)( SAFEARRAY** pIParNames);
  STDMETHOD(get_IPar)( BSTR Name, long* pVal);
  STDMETHOD(put_IPar)( BSTR Name, long Val);
  STDMETHOD(GetEqnNames)( SAFEARRAY** pEqnNames);

  HRESULT iGetEsoNames();
  HRESULT iGetVarNames( BSTR*& pVarNames, CComBSTR& prefix, long& count);
  HRESULT iGetRParNames( BSTR*& pRParNames, CComBSTR& prefix, long& count);
  HRESULT iGetIParNames( BSTR*& pIParNames, CComBSTR& prefix, long& count);
  HRESULT iGetEqnNames( BSTR*& pEqnNames, CComBSTR& prefix, long& count);


  // IIsDaeEso
  IIS_DAE_MODEL_IMPL

  STDMETHOD(SetEso)(IUnknown* pEso);

  virtual HRESULT iGetVariableId(BSTR Name, long* idx);
  virtual HRESULT iGetRealParId(BSTR Name, long* idx);
  virtual HRESULT iGetIntParId(BSTR Name, long* idx);

  virtual HRESULT iInitialize();
  virtual HRESULT iFindMasterNodes();
  virtual HRESULT iGetEquationForm(EqnForm*& eqn_form, EqnDiffForm*& eqn_diff_form);

  virtual HRESULT iEvalStateCondition(
    bool* EqnState, 
    double EventTime, 
    long iDisEqn, 
    long iTransition, 
    VARIANT_BOOL* bEvent);

  virtual HRESULT iCIEvalStateCondition(
    bool* EqnState, 
    double EventTime, 
    long iActiveDisEqn, 
    long iTransition, 
    VARIANT_BOOL* bEvent,
    double* global_x,
    double* global_xdot);

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
  STDMETHOD(PostStateEvent)(double t, BSTR EventId);
  STDMETHOD(PostTransition)(long iNewState);


  // serialization
  virtual bool Load(FILE* fs);
  virtual void Save(FILE* fs);

public: // protected: // TODO: put this back
	STDMETHOD(Connect)(/*[in, out]*/ SAFEARRAY**ConnA, /*[in, out]*/ SAFEARRAY** ConnB);
  STDMETHOD(AddModel)(IIsDaeEsoCImpl* pEso, BSTR modelName);
  STDMETHOD(get_EsoImpl)(IUnknown** pEsoImpl);
	STDMETHOD(CompositeModelComplete)();

  IOnUMLDaeEsoBase* m_pEsoImpl;

  // cached info from model
  long m_nx;
  long m_nad_x;
  long m_nrpar;
  long m_nipar;

  double** m_x;
  double** m_xdot;
  Fdouble** m_ad_x;
  Fdouble** m_ad_xdot;
  double** m_oldx;
  double** m_oldxdot;
  double** m_rpar;
  long** m_ipar;

protected:
  BSTR* m_pEsoNames;
  BSTR* m_pVarNames;
  BSTR* m_pRParNames;
  BSTR* m_pIParNames;
  BSTR* m_pEqnNames;

};

#endif //__ISDAEESOCIMPL_H_
