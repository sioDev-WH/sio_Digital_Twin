// vbOneway_Clutch.h : Declaration of the CvbOneway_Clutch

#ifndef __VBONEWAY_CLUTCH_H_
#define __VBONEWAY_CLUTCH_H_

#include "resource.h"       // main symbols
#include "vbBase.h"
#include "Oneway_Clutch.h"

/////////////////////////////////////////////////////////////////////////////
// CvbOneway_Clutch
class ATL_NO_VTABLE CvbOneway_Clutch : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CvbOneway_Clutch, &CLSID_vbOneway_Clutch>,
	public IDispatchImpl<IvbOneway_Clutch, &IID_IvbOneway_Clutch, &LIBID_RTSONTRANSMISSIONVBLib>,
  public vbBase<Oneway_Clutch>

{
public:
	CvbOneway_Clutch();
  ~CvbOneway_Clutch();

DECLARE_REGISTRY_RESOURCEID(IDR_VBONEWAY_CLUTCH)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CvbOneway_Clutch)
	COM_INTERFACE_ENTRY(IvbOneway_Clutch)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IvbOneway_Clutch
public:
  // from vbBase
  STDMETHOD(get_Eso)(/*[out, retval]*/ IDispatch* *pVal) { return vbBase<Oneway_Clutch>::get_Eso(pVal); } 

  // specific to band brake
	STDMETHOD(get_actuator)(SAFEARRAY** val);
	STDMETHOD(get_n)(SAFEARRAY** val);
  STDMETHOD(get_p)(SAFEARRAY** val);


};

#endif //__VBONEWAY_CLUTCH_H_
