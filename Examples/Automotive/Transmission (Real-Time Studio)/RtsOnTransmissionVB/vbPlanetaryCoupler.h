// vbPlanetaryCoupler.h : Declaration of the CvbPlanetaryCoupler

#ifndef __VBPLANETARYCOUPLER_H_
#define __VBPLANETARYCOUPLER_H_

#include "resource.h"       // main symbols
#include "vbBase.h"
#include "PlanetaryCoupler.h"

/////////////////////////////////////////////////////////////////////////////
// CvbPlanetaryCoupler
class ATL_NO_VTABLE CvbPlanetaryCoupler : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CvbPlanetaryCoupler, &CLSID_vbPlanetaryCoupler>,
	public IDispatchImpl<IvbPlanetaryCoupler, &IID_IvbPlanetaryCoupler, &LIBID_RTSONTRANSMISSIONVBLib>,
  vbBase<PlanetaryCoupler>

{
public:
	CvbPlanetaryCoupler();
  ~CvbPlanetaryCoupler();


DECLARE_REGISTRY_RESOURCEID(IDR_VBPLANETARYCOUPLER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CvbPlanetaryCoupler)
	COM_INTERFACE_ENTRY(IvbPlanetaryCoupler)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IvbPlanetaryCoupler
public:
  // from vbBase
  STDMETHOD(get_Eso)(/*[out, retval]*/ IDispatch* *pVal) { return vbBase<PlanetaryCoupler>::get_Eso(pVal); } 
  STDMETHOD(get_Index)(/*[out, retval]*/ long *pVal) { return vbBase<PlanetaryCoupler>::get_Index(pVal); } 


};

#endif //__VBPLANETARYCOUPLER_H_
