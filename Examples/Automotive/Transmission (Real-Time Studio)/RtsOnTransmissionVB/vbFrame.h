// vbFrame.h : Declaration of the CvbFrame

#ifndef __VBFRAME_H_
#define __VBFRAME_H_

#include "resource.h"       // main symbols
#include "CFrame.h"
#include "vbBase.h"

/////////////////////////////////////////////////////////////////////////////
// CvbFrame
class ATL_NO_VTABLE CvbFrame : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CvbFrame, &CLSID_vbFrame>,
	public IDispatchImpl<IvbFrame, &IID_IvbFrame, &LIBID_RTSONTRANSMISSIONVBLib>,
  vbBase<CFrame>

{
public:
	CvbFrame();
  ~CvbFrame();


DECLARE_REGISTRY_RESOURCEID(IDR_VBFRAME)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CvbFrame)
	COM_INTERFACE_ENTRY(IvbFrame)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IvbFrame
public:
  // from vbBase
  STDMETHOD(get_Eso)(/*[out, retval]*/ IDispatch* *pVal) { return vbBase<CFrame>::get_Eso(pVal); } 

  // specific to band brake
	STDMETHOD(get_p)(SAFEARRAY** val);


};

#endif //__VBFRAME_H_
