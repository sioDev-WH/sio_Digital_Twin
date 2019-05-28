// OnTest.h : Declaration of the COnTest

#ifndef __ONTEST_H_
#define __ONTEST_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COnTest
class MatInfo;

class ATL_NO_VTABLE COnTest : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<COnTest, &CLSID_OnTest>,
	public ISupportErrorInfo,
	public IDispatchImpl<IOnTest, &IID_IOnTest, &LIBID_ISDAECOSOLVERLib>
{
public:
	COnTest();
  virtual ~COnTest();

DECLARE_REGISTRY_RESOURCEID(IDR_ONTEST)
DECLARE_NOT_AGGREGATABLE(COnTest)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(COnTest)
	COM_INTERFACE_ENTRY(IOnTest)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IOnTest
public:
	STDMETHOD(SparseTest)();
  void fillTestData(MatInfo& m, long nSize, long nColIndices, double* RHS);
  void getData(const double t, double* val) { *val = 10.0; }
};

#endif //__ONTEST_H_
