// vbTorque_Converter.h : Declaration of the CvbTorque_Converter

#ifndef __VBTORQUE_CONVERTER_H_
#define __VBTORQUE_CONVERTER_H_

#include "resource.h"       // main symbols
#include "Torque_Converter.h"
#include "vbBase.h"

/////////////////////////////////////////////////////////////////////////////
// CvbTorque_Converter
class ATL_NO_VTABLE CvbTorque_Converter : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CvbTorque_Converter, &CLSID_vbTorque_Converter>,
	public IDispatchImpl<IvbTorque_Converter, &IID_IvbTorque_Converter, &LIBID_RTSONTRANSMISSIONVBLib>,
  public vbBase<Torque_Converter>

{
public:
	CvbTorque_Converter();
  ~CvbTorque_Converter();


DECLARE_REGISTRY_RESOURCEID(IDR_VBTORQUE_CONVERTER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CvbTorque_Converter)
	COM_INTERFACE_ENTRY(IvbTorque_Converter)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IvbTorque_Converter
public:
  // from vbBase
  STDMETHOD(get_Eso)(/*[out, retval]*/ IDispatch* *pVal) { return vbBase<Torque_Converter>::get_Eso(pVal); } 

  STDMETHOD(get_turbine)(SAFEARRAY** val);
  STDMETHOD(get_impeller)(SAFEARRAY** val);


};

#endif //__VBTORQUE_CONVERTER_H_
