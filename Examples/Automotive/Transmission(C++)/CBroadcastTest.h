// CBroadcastTest.h : Declaration of the CCBroadcastTest

#ifndef __CBROADCASTTEST_H_
#define __CBROADCASTTEST_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CCBroadcastTest
class ATL_NO_VTABLE CCBroadcastTest : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CCBroadcastTest, &CLSID_CBroadcastTest>,
	public IDispatchImpl<ICBroadcastTest, &IID_ICBroadcastTest, &LIBID_ONTRANSMISSIONLib>
{
public:
	CCBroadcastTest()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CBROADCASTTEST)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CCBroadcastTest)
	COM_INTERFACE_ENTRY(ICBroadcastTest)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// ICBroadcastTest
public:
	STDMETHOD(RunTest)();

  void Listen1(long* pVal) { ATLTRACE("\nListen1 called: %d", *pVal); }
  void Listen2(long* pVal) { ATLTRACE("\nListen2 called: %d", *pVal); }
  void Listen3(long* pVal) { ATLTRACE("\nListen3 called: %d", *pVal); }
  void Listen4(long* pVal) { ATLTRACE("\nListen4 called: %d", *pVal); }

};

#endif //__CBROADCASTTEST_H_
