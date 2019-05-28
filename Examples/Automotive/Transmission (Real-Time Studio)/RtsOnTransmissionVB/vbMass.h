// vbMass.h : Declaration of the CvbMass

#ifndef __VBMASS_H_
#define __VBMASS_H_

#include "resource.h"       // main symbols
#include "CMass.h"
#include "vbBase.h"

/////////////////////////////////////////////////////////////////////////////
// CvbMass
class ATL_NO_VTABLE CvbMass : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CvbMass, &CLSID_vbMass>,
	public IDispatchImpl<IvbMass, &IID_IvbMass, &LIBID_RTSONTRANSMISSIONVBLib>,
  public vbBase<CMass>
{
public:
	CvbMass();
  ~CvbMass();

DECLARE_REGISTRY_RESOURCEID(IDR_VBMASS)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CvbMass)
	COM_INTERFACE_ENTRY(IvbMass)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IvbMass
public:
  // from vbBase
  STDMETHOD(get_Eso)(/*[out, retval]*/ IDispatch* *pVal) { return vbBase<CMass>::get_Eso(pVal); } 

  // specific to CMass
  STDMETHOD(get_p)(SAFEARRAY** val);
	STDMETHOD(get_n)(SAFEARRAY** val);

};

#endif //__VBMASS_H_
