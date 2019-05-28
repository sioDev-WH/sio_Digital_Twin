// vbEngine.h : Declaration of the CvbEngine

#ifndef __VBENGINE_H_
#define __VBENGINE_H_

#include "resource.h"       // main symbols
#include "Engine.h"
#include "vbBase.h"

/////////////////////////////////////////////////////////////////////////////
// CvbEngine
class ATL_NO_VTABLE CvbEngine : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CvbEngine, &CLSID_vbEngine>,
	public IDispatchImpl<IvbEngine, &IID_IvbEngine, &LIBID_RTSONTRANSMISSIONVBLib>,
  public vbBase<Engine>
{
public:
	CvbEngine();
  ~CvbEngine();

DECLARE_REGISTRY_RESOURCEID(IDR_VBENGINE)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CvbEngine)
	COM_INTERFACE_ENTRY(IvbEngine)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IvbEngine
public:
  // from vbBase
  STDMETHOD(get_Eso)(/*[out, retval]*/ IDispatch* *pVal) { return vbBase<Engine>::get_Eso(pVal); } 

  // specific to Engine
	STDMETHOD(get_n)(SAFEARRAY** val);
  STDMETHOD(throttleEvent)(double t, double val);
  STDMETHOD(startEvent)(double t, long val);

};

#endif //__VBENGINE_H_
