// vbBand_Brake.h : Declaration of the CvbBand_Brake

#ifndef __VBBAND_BRAKE_H_
#define __VBBAND_BRAKE_H_

#include "resource.h"       // main symbols
#include "Band_Break.h"
#include "vbBase.h"

/////////////////////////////////////////////////////////////////////////////
// CvbBand_Brake
class ATL_NO_VTABLE CvbBand_Brake : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CvbBand_Brake, &CLSID_vbBand_Brake>,
	public IDispatchImpl<IvbBand_Brake, &IID_IvbBand_Brake, &LIBID_RTSONTRANSMISSIONVBLib>,
  public vbBase<Band_Break>
{
public:
	CvbBand_Brake();
  ~CvbBand_Brake();

DECLARE_REGISTRY_RESOURCEID(IDR_VBBAND_BRAKE)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CvbBand_Brake)
	COM_INTERFACE_ENTRY(IvbBand_Brake)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IvbBand_Brake
public:
  // from vbBase
  STDMETHOD(get_Eso)(/*[out, retval]*/ IDispatch* *pVal) { return vbBase<Band_Break>::get_Eso(pVal); } 

  // specific to band brake
	STDMETHOD(get_actuator)(SAFEARRAY** val);
	STDMETHOD(get_n)(SAFEARRAY** val);
  STDMETHOD(get_p)(SAFEARRAY** val);


};

#endif //__VBBAND_BRAKE_H_
