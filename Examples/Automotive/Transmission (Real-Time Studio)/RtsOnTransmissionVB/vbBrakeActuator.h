// vbBrakeActuator.h : Declaration of the CvbBrakeActuator

#ifndef __VBBRAKEACTUATOR_H_
#define __VBBRAKEACTUATOR_H_

#include "resource.h"       // main symbols
#include "BrakeActuator.h"
#include "vbBase.h"

/////////////////////////////////////////////////////////////////////////////
// CvbBrakeActuator
class ATL_NO_VTABLE CvbBrakeActuator : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CvbBrakeActuator, &CLSID_vbBrakeActuator>,
	public IDispatchImpl<IvbBrakeActuator, &IID_IvbBrakeActuator, &LIBID_RTSONTRANSMISSIONVBLib>,
  public vbBase<BrakeActuator>
{
public:
	CvbBrakeActuator();
  ~CvbBrakeActuator();

DECLARE_REGISTRY_RESOURCEID(IDR_VBBRAKEACTUATOR)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CvbBrakeActuator)
	COM_INTERFACE_ENTRY(IvbBrakeActuator)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IvbBrakeActuator
public:
  // from vbBase
  STDMETHOD(get_Eso)(/*[out, retval]*/ IDispatch* *pVal) { return vbBase<BrakeActuator>::get_Eso(pVal); } 

  // specific to band brake
  STDMETHOD(get_p)(SAFEARRAY** val);

};

#endif //__VBBRAKEACTUATOR_H_
