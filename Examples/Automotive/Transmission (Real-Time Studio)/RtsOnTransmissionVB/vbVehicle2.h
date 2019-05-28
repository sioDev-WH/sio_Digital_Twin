// vbVehicle2.h : Declaration of the CvbVehicle2

#ifndef __VBVEHICLE2_H_
#define __VBVEHICLE2_H_

#include "resource.h"       // main symbols
#include "Vehicle2.h"
#include "vbBase.h"

/////////////////////////////////////////////////////////////////////////////
// CvbVehicle2
class ATL_NO_VTABLE CvbVehicle2 : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CvbVehicle2, &CLSID_vbVehicle2>,
	public IDispatchImpl<IvbVehicle2, &IID_IvbVehicle2, &LIBID_RTSONTRANSMISSIONVBLib>,
  public vbBase<Vehicle2>

{
public:
	CvbVehicle2();
  ~CvbVehicle2();

DECLARE_REGISTRY_RESOURCEID(IDR_VBVEHICLE2)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CvbVehicle2)
	COM_INTERFACE_ENTRY(IvbVehicle2)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IvbVehicle2
public:
  // from vbBase
  STDMETHOD(get_Eso)(/*[out, retval]*/ IDispatch* *pVal) { return vbBase<Vehicle2>::get_Eso(pVal); } 

  // specific to Vehicle2
  STDMETHOD(get_p)(SAFEARRAY** val);


};

#endif //__VBVEHICLE2_H_
