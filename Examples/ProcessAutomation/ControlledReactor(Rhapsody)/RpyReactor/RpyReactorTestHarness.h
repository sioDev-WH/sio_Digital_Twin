// RpyReactorTestHarness.h : Declaration of the CRpyReactorTestHarness

#ifndef __RPYREACTORTESTHARNESS_H_
#define __RPYREACTORTESTHARNESS_H_

#include "resource.h"       // main symbols
class ControlledReactor_app;

/////////////////////////////////////////////////////////////////////////////
// CRpyReactorTestHarness
class ATL_NO_VTABLE CRpyReactorTestHarness : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRpyReactorTestHarness, &CLSID_RpyReactorTestHarness>,
	public IDispatchImpl<IRpyReactorTestHarness, &IID_IRpyReactorTestHarness, &LIBID_RPYREACTORLib>
{
public:
	CRpyReactorTestHarness();
  ~CRpyReactorTestHarness();


DECLARE_REGISTRY_RESOURCEID(IDR_RPYREACTORTESTHARNESS)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CRpyReactorTestHarness)
	COM_INTERFACE_ENTRY(IRpyReactorTestHarness)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IRpyReactorTestHarness
public:
	STDMETHOD(setSetpoint)(/*[in]*/ double val);
	STDMETHOD(GetControllerOutput)(double time, double *pOut);
	STDMETHOD(Step)(/*[in]*/ double t);
  STDMETHOD(GetModel)(IDispatch** ppModel);
  STDMETHOD(GetModelExec)(IDispatch** ppModelExec);

protected:
  ControlledReactor_app* m_app;

};

#endif //__RPYREACTORTESTHARNESS_H_
