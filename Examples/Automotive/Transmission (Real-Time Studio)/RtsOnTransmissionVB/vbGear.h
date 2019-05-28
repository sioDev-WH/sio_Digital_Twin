// vbGear.h : Declaration of the CvbGear

#ifndef __VBGEAR_H_
#define __VBGEAR_H_

#include "resource.h"       // main symbols
#include "Gear.h"
#include "vbBase.h"

/////////////////////////////////////////////////////////////////////////////
// CvbGear
class ATL_NO_VTABLE CvbGear : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CvbGear, &CLSID_vbGear>,
	public IDispatchImpl<IvbGear, &IID_IvbGear, &LIBID_RTSONTRANSMISSIONVBLib>,
  vbBase<Gear>

{
public:
	CvbGear();
  ~CvbGear();

DECLARE_REGISTRY_RESOURCEID(IDR_VBGEAR)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CvbGear)
	COM_INTERFACE_ENTRY(IvbGear)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IvbGear
public:
  // from vbBase
  STDMETHOD(get_Eso)(/*[out, retval]*/ IDispatch* *pVal) { return vbBase<Gear>::get_Eso(pVal); } 
  STDMETHOD(get_Index)(/*[out, retval]*/ long *pVal) { return vbBase<Gear>::get_Index(pVal); } 



};

#endif //__VBGEAR_H_
