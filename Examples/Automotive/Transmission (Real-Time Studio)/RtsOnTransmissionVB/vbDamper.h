// vbDamper.h : Declaration of the CvbDamper

#ifndef __VBDAMPER_H_
#define __VBDAMPER_H_

#include "resource.h"       // main symbols
#include "CDamper.h"
#include "vbBase.h"

/////////////////////////////////////////////////////////////////////////////
// CvbDamper
class ATL_NO_VTABLE CvbDamper : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CvbDamper, &CLSID_vbDamper>,
	public IDispatchImpl<IvbDamper, &IID_IvbDamper, &LIBID_RTSONTRANSMISSIONVBLib>,
  public vbBase<CDamper>
{
public:
	CvbDamper();
  ~CvbDamper();

DECLARE_REGISTRY_RESOURCEID(IDR_VBDAMPER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CvbDamper)
	COM_INTERFACE_ENTRY(IvbDamper)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IvbDamper
public:
  // from vbBase
  STDMETHOD(get_Eso)(/*[out, retval]*/ IDispatch* *pVal) { return vbBase<CDamper>::get_Eso(pVal); } 

  // specific to band brake
	STDMETHOD(get_n)(SAFEARRAY** val);
  STDMETHOD(get_p)(SAFEARRAY** val);

};

#endif //__VBDAMPER_H_
