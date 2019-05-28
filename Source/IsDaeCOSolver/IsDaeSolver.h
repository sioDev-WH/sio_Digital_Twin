// IsDaeSolver.h : Declaration of the CIsDaeSolver

#ifndef __ISDAESOLVER_H_
#define __ISDAESOLVER_H_

#include "resource.h"       // main symbols
class CIsStepper;

/////////////////////////////////////////////////////////////////////////////
// CIsDaeSolver
class ATL_NO_VTABLE CIsDaeSolver : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CIsDaeSolver, &CLSID_IsDaeSolver>,
	public ISupportErrorInfo,
	public IDispatchImpl<IIsDaeSolver, &IID_IIsDaeSolver, &LIBID_ISDAECOSOLVERLib>
{
public:
	CIsDaeSolver();
  virtual ~CIsDaeSolver();

DECLARE_REGISTRY_RESOURCEID(IDR_ISDAESOLVER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CIsDaeSolver)
	COM_INTERFACE_ENTRY(IIsDaeSolver)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()


// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IIsDaeSolver
public:
  STDMETHOD(Step)();
  STDMETHOD(SetEso)(IIsDaeEso* pEso);

protected:
  CIsStepper* m_pStepper;
  IIsDaeEso* m_pModel;

  // cached MSS results
  long m_nAugmentedEqns;
  long m_nAugmentedVars; 
  long* m_VAL;
  long* m_assignedEqn;

};

#endif //__ISDAESOLVER_H_
