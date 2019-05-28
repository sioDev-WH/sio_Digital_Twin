// vbComposite.h : Declaration of the CvbComposite

#ifndef __VBCOMPOSITE_H_
#define __VBCOMPOSITE_H_

#include "resource.h"       // main symbols
#include "vbBase.h"
#include "OnDefaultCImpl.h"

/////////////////////////////////////////////////////////////////////////////
// CvbComposite
class ATL_NO_VTABLE CvbComposite : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CvbComposite, &CLSID_vbComposite>,
	public IDispatchImpl<IvbComposite, &IID_IvbComposite, &LIBID_RTSONTRANSMISSIONVBLib>,
  public vbBase<COnDefaultCImpl>

{
public:
	CvbComposite();
  ~CvbComposite();

DECLARE_REGISTRY_RESOURCEID(IDR_VBCOMPOSITE)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CvbComposite)
	COM_INTERFACE_ENTRY(IvbComposite)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IvbComposite
public:
  STDMETHOD(get_Eso)(/*[out, retval]*/ IDispatch* *pVal) { return vbBase<COnDefaultCImpl>::get_Eso(pVal); } 
  
  

};

#endif //__VBCOMPOSITE_H_
