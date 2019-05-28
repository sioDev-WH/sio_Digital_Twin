// vbRavigneaux.h : Declaration of the CvbRavigneaux

#ifndef __VBRAVIGNEAUX_H_
#define __VBRAVIGNEAUX_H_

#include "resource.h"       // main symbols
#include "Ravigneaux.h"
#include "vbBase.h"

/////////////////////////////////////////////////////////////////////////////
// CvbRavigneaux
class ATL_NO_VTABLE CvbRavigneaux : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CvbRavigneaux, &CLSID_vbRavigneaux>,
	public IDispatchImpl<IvbRavigneaux, &IID_IvbRavigneaux, &LIBID_RTSONTRANSMISSIONVBLib>,
  public vbBase<Ravigneaux>

{
public:
	CvbRavigneaux();
  ~CvbRavigneaux();

DECLARE_REGISTRY_RESOURCEID(IDR_VBRAVIGNEAUX)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CvbRavigneaux)
	COM_INTERFACE_ENTRY(IvbRavigneaux)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IvbRavigneaux
public:
  // from vbBase
  STDMETHOD(get_Eso)(/*[out, retval]*/ IDispatch* *pVal) { return vbBase<Ravigneaux>::get_Eso(pVal); } 

  STDMETHOD(get_forwardSun)(SAFEARRAY** val);
  STDMETHOD(get_reverseSun)(SAFEARRAY** val);
  STDMETHOD(get_coupler)(SAFEARRAY** val);
  STDMETHOD(get_ring)(SAFEARRAY** val);

};

#endif //__VBRAVIGNEAUX_H_
