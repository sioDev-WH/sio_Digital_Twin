// OnEnv.h : Declaration of the COnEnv

#ifndef __ONENV_H_
#define __ONENV_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// COnEnv
class ATL_NO_VTABLE COnEnv : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<COnEnv, &CLSID_OnEnv>,
	public IDispatchImpl<IOnEnv, &IID_IOnEnv, &LIBID_ISDAECOSOLVERLib>
{
public:
	COnEnv();

DECLARE_CLASSFACTORY_SINGLETON(COnEnv)
DECLARE_REGISTRY_RESOURCEID(IDR_ONENV)
DECLARE_NOT_AGGREGATABLE(COnEnv)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(COnEnv)
	COM_INTERFACE_ENTRY(IOnEnv)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IOnEnv
public:
	STDMETHOD(get_GraphicPath)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_GraphicPath)(/*[in]*/ BSTR newVal);
	STDMETHOD(get_DataPath)(/*[out, retval]*/ BSTR *pVal);
	STDMETHOD(put_DataPath)(/*[in]*/ BSTR newVal);

private:
  CComBSTR m_DataPath;
  CComBSTR m_GraphicPath;

};

#endif //__ONENV_H_
