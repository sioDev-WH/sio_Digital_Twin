// vbActuator.h : Declaration of the CvbActuator

#ifndef __VBACTUATOR_H_
#define __VBACTUATOR_H_

#include "resource.h"       // main symbols
#include "Actuator.h"
#include "vbBase.h"

/////////////////////////////////////////////////////////////////////////////
// CvbActuator
class ATL_NO_VTABLE CvbActuator : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CvbActuator, &CLSID_vbActuator>,
	public IDispatchImpl<IvbActuator, &IID_IvbActuator, &LIBID_RTSONTRANSMISSIONVBLib>,
  public vbBase<Actuator>
{
public:
	CvbActuator();
  ~CvbActuator();

DECLARE_REGISTRY_RESOURCEID(IDR_VBACTUATOR)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CvbActuator)
	COM_INTERFACE_ENTRY(IvbActuator)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IvbActuator
public:
  // from vbBase
  STDMETHOD(get_Eso)(/*[out, retval]*/ IDispatch* *pVal) { return vbBase<Actuator>::get_Eso(pVal); } 

  // specific to actuator
  STDMETHOD(get_clutch)(SAFEARRAY** val);
	STDMETHOD(shiftEvent)(/*[in]*/ double t, /*[in]*/ long val);

};

#endif //__VBACTUATOR_H_
