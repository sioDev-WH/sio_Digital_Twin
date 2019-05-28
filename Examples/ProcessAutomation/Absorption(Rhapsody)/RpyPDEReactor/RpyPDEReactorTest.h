// RpyPDEReactorTest.h : Declaration of the CRpyPDEReactorTest

#ifndef __RPYPDEREACTORTEST_H_
#define __RPYPDEREACTORTEST_H_

#include "resource.h"       // main symbols

class Reactor_app;

/////////////////////////////////////////////////////////////////////////////
// CRpyPDEReactorTest
class ATL_NO_VTABLE CRpyPDEReactorTest : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CRpyPDEReactorTest, &CLSID_RpyPDEReactorTest>,
	public IDispatchImpl<IRpyPDEReactorTest, &IID_IRpyPDEReactorTest, &LIBID_RPYPDEREACTORLib>
{
public:
	CRpyPDEReactorTest();
	~CRpyPDEReactorTest();

public:
  void init();
  void clean();



DECLARE_REGISTRY_RESOURCEID(IDR_RPYPDEREACTORTEST)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CRpyPDEReactorTest)
	COM_INTERFACE_ENTRY(IRpyPDEReactorTest)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IRpyPDEReactorTest
public:
	STDMETHOD(GetVariables)(/*[in]*/ double time, /*[in, out]*/ SAFEARRAY** ppsaVars);
	STDMETHOD(Step)(/*[in]*/ double time);

protected:
  Reactor_app* m_pApp;

};

#endif //__RPYPDEREACTORTEST_H_
