// vbVehicle.h : Declaration of the CvbVehicle

#ifndef __VBVEHICLE_H_
#define __VBVEHICLE_H_

#include "resource.h"       // main symbols
#include "Vehicle.h"
#include "vbBase.h"

/////////////////////////////////////////////////////////////////////////////
// CvbVehicle
class ATL_NO_VTABLE CvbVehicle : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CvbVehicle, &CLSID_vbVehicle>,
	public IDispatchImpl<IvbVehicle, &IID_IvbVehicle, &LIBID_RTSONTRANSMISSIONVBLib>,
  public vbBase<Vehicle>

{
public:
	CvbVehicle();
  ~CvbVehicle();

DECLARE_REGISTRY_RESOURCEID(IDR_VBVEHICLE)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CvbVehicle)
	COM_INTERFACE_ENTRY(IvbVehicle)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IvbVehicle
public:
  // from vbBase
  STDMETHOD(get_Eso)(/*[out, retval]*/ IDispatch* *pVal) { return vbBase<Vehicle>::get_Eso(pVal); } 

  // specific to Vehicle
  STDMETHOD(get_p)(SAFEARRAY** val);


};

#endif //__VBVEHICLE_H_
