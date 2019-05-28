// vbClutch.h : Declaration of the CvbClutch

#ifndef __VBCLUTCH_H_
#define __VBCLUTCH_H_

#include "resource.h"       // main symbols
#include "Clutch.h"
#include "vbBase.h"

/////////////////////////////////////////////////////////////////////////////
// CvbClutch
class ATL_NO_VTABLE CvbClutch : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CvbClutch, &CLSID_vbClutch>,
	public IDispatchImpl<IvbClutch, &IID_IvbClutch, &LIBID_RTSONTRANSMISSIONVBLib>,
  public vbBase<Clutch>
{
public:
	CvbClutch();
  ~CvbClutch();

DECLARE_REGISTRY_RESOURCEID(IDR_VBCLUTCH)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CvbClutch)
	COM_INTERFACE_ENTRY(IvbClutch)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IvbClutch
public:
  // from vbBase
  STDMETHOD(get_Eso)(/*[out, retval]*/ IDispatch* *pVal) { return vbBase<Clutch>::get_Eso(pVal); } 

  // specific to band brake
	STDMETHOD(get_actuator)(SAFEARRAY** val);
	STDMETHOD(get_n)(SAFEARRAY** val);
  STDMETHOD(get_p)(SAFEARRAY** val);

};

#endif //__VBCLUTCH_H_
