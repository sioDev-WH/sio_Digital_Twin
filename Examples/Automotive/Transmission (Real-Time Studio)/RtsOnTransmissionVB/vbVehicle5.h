// vbVehicle5.h : Declaration of the CvbVehicle5

#ifndef __VBVEHICLE5_H_
#define __VBVEHICLE5_H_

#include "resource.h"       // main symbols
#include "Vehicle5.h"
#include "vbBase.h"

/////////////////////////////////////////////////////////////////////////////
// CvbVehicle5
class ATL_NO_VTABLE CvbVehicle5 : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CvbVehicle5, &CLSID_vbVehicle5>,
	public IDispatchImpl<IvbVehicle5, &IID_IvbVehicle5, &LIBID_RTSONTRANSMISSIONVBLib>,
  public vbBase<Vehicle5>

{
public:
	CvbVehicle5();
  ~CvbVehicle5();

DECLARE_REGISTRY_RESOURCEID(IDR_VBVEHICLE5)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CvbVehicle5)
	COM_INTERFACE_ENTRY(IvbVehicle5)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IvbVehicle5
public:
  // from vbBase
  STDMETHOD(get_Eso)(/*[out, retval]*/ IDispatch* *pVal) { return vbBase<Vehicle5>::get_Eso(pVal); } 

  // specific to Vehicle5
  STDMETHOD(get_p)(SAFEARRAY** val);
  STDMETHOD(brakeEvent)(double t, double val);

};

#endif //__VBVEHICLE5_H_
