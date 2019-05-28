// COnTransModelFactory.h : Declaration of the COnTransModelFactory

#ifndef __CONTRANSMODELFACTORY_H_
#define __CONTRANSMODELFACTORY_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COnTransModelFactory
class ATL_NO_VTABLE COnTransModelFactory : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<COnTransModelFactory, &CLSID_OnTransModelFactory>,
	public ISupportErrorInfo,
	public IDispatchImpl<IOnTransModelFactory, &IID_IOnTransModelFactory, &LIBID_ONTRANSMISSIONLib>
{
public:
	COnTransModelFactory()
	{
	}

DECLARE_REGISTRY_RESOURCEID(IDR_CONTRANSMODELFACTORY)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(COnTransModelFactory)
	COM_INTERFACE_ENTRY(IOnTransModelFactory)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);
  STDMETHOD(CreateModel)(BSTR bstrName, IDispatch **pModel);

// ICOnTransModelFactory
public:
};

#endif //__CONTRANSMODELFACTORY_H_
