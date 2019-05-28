// IsMatrix.h : Declaration of the CIsMatrix

#ifndef __ISMATRIX_H_
#define __ISMATRIX_H_

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CIsMatrix
class ATL_NO_VTABLE CIsMatrix : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CIsMatrix, &CLSID_IsMatrix>,
	public ISupportErrorInfo,
	public IDispatchImpl<IIsMatrix, &IID_IIsMatrix, &LIBID_ISDAECOSOLVERLib>
{
public:
	CIsMatrix()
	{
    m_nRows = 0;
    m_nCols = 0;
    m_psaMatrix = NULL; // SA of SAs
    m_vMatrix = NULL;   // Array of SAs
    m_vRows = NULL;     // Array of arrays
	}

	virtual ~CIsMatrix()
	{
    Destroy();
	}

DECLARE_REGISTRY_RESOURCEID(IDR_ISMATRIX)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CIsMatrix)
	COM_INTERFACE_ENTRY(IIsMatrix)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()

// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IIsMatrix
public:

  STDMETHOD(Init)(long nRows, long nCols);
  STDMETHOD(GetData)(SAFEARRAY** Vals);
  STDMETHOD(Detach)(SAFEARRAY** Vals);
  STDMETHOD(Attach)(SAFEARRAY** Vals);
  STDMETHOD(GetRow)(long Row, SAFEARRAY** Vals);
  STDMETHOD(SetRow)(long Row, SAFEARRAY** Vals);
  STDMETHOD(GetCol)(long Col, SAFEARRAY** Vals);
  STDMETHOD(SetCol)(long Col, SAFEARRAY** Vals);
  STDMETHOD(get_Value)(long Row, long Col, double* pVal);
  STDMETHOD(put_Value)(long Row, long Col, double Val);
  void Destroy();

protected:
  long m_nRows;
  long m_nCols;
  SAFEARRAY* m_psaMatrix;      // SA of SAs
  VARIANT* m_vMatrix;          // Array of SAs
  double** m_vRows;     // Array of arrays

};

#endif //__ISMATRIX_H_
