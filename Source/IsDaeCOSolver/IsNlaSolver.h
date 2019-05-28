// IsNlaSolver.h : Declaration of the CIsNlaSolver

#ifndef __ISNLASOLVER_H_
#define __ISNLASOLVER_H_

#include "resource.h"       // main symbols
class MatInfo;

/////////////////////////////////////////////////////////////////////////////
// CIsNlaSolver
class ATL_NO_VTABLE CIsNlaSolver : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<CIsNlaSolver, &CLSID_IsNlaSolver>,
	public ISupportErrorInfo,
	public IDispatchImpl<IIsNlaSolver, &IID_IIsNlaSolver, &LIBID_ISDAECOSOLVERLib>
{
public:
	CIsNlaSolver();
  virtual ~CIsNlaSolver();

DECLARE_REGISTRY_RESOURCEID(IDR_ISNLASOLVER)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(CIsNlaSolver)
	COM_INTERFACE_ENTRY(IIsNlaSolver)
	COM_INTERFACE_ENTRY(IDispatch)
	COM_INTERFACE_ENTRY(ISupportErrorInfo)
END_COM_MAP()


public:
// ISupportsErrorInfo
	STDMETHOD(InterfaceSupportsErrorInfo)(REFIID riid);

// IIsNlaSolver
  STDMETHOD(SetEso)(IIsNlaEso* pEso) { m_pEso = pEso; return S_OK; }
	STDMETHOD(Solve)();

protected:

  double fmin(double* x);
  void broydn(long *check);
  void lnsrch(long n, double* xold, double fold, double* g, double* p, double* x,
			  double* f, double stpmax, long *check);
  void qrdcmp(double** a, long n, double* c, double* d, long *sing);
  void qrupdt(double** r, double** qt, long n, double* u, double* v);
  void rsolv(double** a, long n, double* d, double* b);
  void rotate(double** r, double** qt, long n, long i, double a, double b);

  void UpdateJacobianValues();
  void UpdateNumericJacobians();
  HRESULT InitJacStruct();
  HRESULT InitJacValues();

protected:
  IIsNlaEso* m_pEso;          // pointer to ESO
  SAFEARRAY* m_psax;          // safe array of x values
  SAFEARRAY* m_psaf;          // safe array of residuals
  long m_nVars;
  double* m_xvec;             // C++ array of x values
  double* m_fvec;             // C++ array of residuals
  long ij;

  // jacobian structure support for efficiency of jacobian calculations
  long m_nNumJac;             // number of jacobian values that must be calculated numerically
  long m_nEsoJac;             // number of jacobian values that will be calculated by the ESO
  long* m_vNumJac;            // [Row, Col] indices for numeric jacobian calculations
  double* m_vNumJacVals;      // SafeArray of jacobian values calculated numerically
  SAFEARRAY* m_psaEsoJac;     // SafeArray of [Row, Col] indices for ESO jacobian calculations
  long* m_vEsoJac;            // C++ array of [Row, Col] indices for ESO jacobian calculations
  SAFEARRAY* m_psaEsoJacVals; // SafeArray of jacobian values calculated by ESO
  double* m_vEsoJacVals;      // C++ array of jacobian values calculated by ESO

  MatInfo* m_JacStruct;       // jacobian structure (in compact form)
  MatInfo* m_Jac;             // jacobian matrix
};

#endif //__ISNLASOLVER_H_
