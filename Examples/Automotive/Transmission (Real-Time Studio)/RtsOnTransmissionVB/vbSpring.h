// vbSpring.h : Declaration of the CvbSpring

#ifndef __VBSPRING_H_
#define __VBSPRING_H_

#include "resource.h"       // main symbols
#include "CSpring.h"
#include "vbBase.h"

/////////////////////////////////////////////////////////////////////////////
// CvbSpring
class ATL_NO_VTABLE CvbSpring : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CvbSpring, &CLSID_vbSpring>,
	public IDispatchImpl<IvbSpring, &IID_IvbSpring, &LIBID_RTSONTRANSMISSIONVBLib>,
  public vbBase<CSpring>

{
public:
	CvbSpring();
  ~CvbSpring();

DECLARE_REGISTRY_RESOURCEID(IDR_VBSPRING)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CvbSpring)
	COM_INTERFACE_ENTRY(IvbSpring)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IvbSpring
public:
  // from vbBase
  STDMETHOD(get_Eso)(/*[out, retval]*/ IDispatch* *pVal) { return vbBase<CSpring>::get_Eso(pVal); } 

  // specific to CSpring
  STDMETHOD(get_p)(SAFEARRAY** val);
	STDMETHOD(get_n)(SAFEARRAY** val);

};

#endif //__VBSPRING_H_
