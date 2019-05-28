// COnTestHarness.h : Declaration of the CCOnTestHarness

#ifndef __CONTESTHARNESS_H_
#define __CONTESTHARNESS_H_

#include "resource.h"       // main symbols

class Car_app;
class TestHarness;

/////////////////////////////////////////////////////////////////////////////
// CCOnTestHarness
class ATL_NO_VTABLE CCOnTestHarness : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCOnTestHarness, &CLSID_COnTestHarness>,
	public IDispatchImpl<ICOnTestHarness, &IID_ICOnTestHarness, &LIBID_RTSONTRANSMISSIONLib>
{
public:
	CCOnTestHarness()
	{
    pApp = NULL;
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CONTESTHARNESS)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CCOnTestHarness)
	COM_INTERFACE_ENTRY(ICOnTestHarness)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// ICOnTestHarness
public:
	STDMETHOD(get_ModelExec)(/*[out, retval]*/ IOnModelExec* *pVal);
	STDMETHOD(get_model)(/*[out, retval]*/ IIsDaeEsoCImpl* *pVal);
	STDMETHOD(term)();
	STDMETHOD(tick)(double t);
	STDMETHOD(init)();
	STDMETHOD(runTest)();

  // interface methods for doing Monte Carlo simulation from VB
	STDMETHOD(SetShiftTiming)(VARIANT_BOOL bUp, long iShift, double val);
	STDMETHOD(SetShiftPeriod)(long iClutch, double val);
	STDMETHOD(SetThrottle)(double throttle);
  STDMETHOD(Load)(BSTR FileName);
  STDMETHOD(Save)(BSTR FileName);
  STDMETHOD(GetStates)(SAFEARRAY** states);

  TestHarness* pApp;
};

#endif //__CONTESTHARNESS_H_
