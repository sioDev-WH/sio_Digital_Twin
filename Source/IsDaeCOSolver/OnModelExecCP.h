#ifndef _ONMODELEXECCP_H_
#define _ONMODELEXECCP_H_

#include "trimInfo.h"

template <class T>
class CProxy_IOnModelExecEvents : public IConnectionPointImpl<T, &DIID__IOnModelExecEvents, CComDynamicUnkArray>
{
	//Warning this class may be recreated by the wizard.
public:

  void Fire_BeforeRParEvent(double Time, long iGlobalId, double Value)
  {
    if (m_vec.GetSize() == 0) return;

		T* pT = static_cast<T*>(this);
    int nConnections;
		int nConnectionIndex;
    CComPtr<IUnknown> sp;
    IDispatch* pDispatch;

		CComVariant pvars[3];
    pvars[2] = Time;
    pvars[1] = iGlobalId;
    pvars[0] = Value;
		
		pT->Lock();
    nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			sp = m_vec.GetAt(nConnectionIndex);
			pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x1, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		pT->Unlock();
  }

  void Fire_BeforeIParEvent(double Time, long iGlobalId, long Value)
  {
    if (m_vec.GetSize() == 0) return;

		T* pT = static_cast<T*>(this);
    int nConnections;
		int nConnectionIndex;
    CComPtr<IUnknown> sp;
    IDispatch* pDispatch;

		CComVariant pvars[3];
    pvars[2] = Time;
    pvars[1] = iGlobalId;
    pvars[0] = Value;
		
		pT->Lock();
    nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			sp = m_vec.GetAt(nConnectionIndex);
			pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x2, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		pT->Unlock();
  }


  void Fire_BeforeStateEvent(double Time, BSTR EvId, long iEvEqn)
  {
    if (m_vec.GetSize() == 0) return;

		T* pT = static_cast<T*>(this);
    int nConnections;
		int nConnectionIndex;
    CComPtr<IUnknown> sp;
    IDispatch* pDispatch;

		CComVariant pvars[3];
    pvars[2] = Time;
    pvars[1] = EvId;
    pvars[0] = iEvEqn;
		
		pT->Lock();
    nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			sp = m_vec.GetAt(nConnectionIndex);
			pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x3, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		pT->Unlock();
  }


  void Fire_AfterRParEvent(double Time, long iGlobalId, double Value)
  {
    if (m_vec.GetSize() == 0) return;

		T* pT = static_cast<T*>(this);
    int nConnections;
		int nConnectionIndex;
    CComPtr<IUnknown> sp;
    IDispatch* pDispatch;

		CComVariant pvars[3];
    pvars[2] = Time;
    pvars[1] = iGlobalId;
    pvars[0] = Value;
		
		pT->Lock();
    nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			sp = m_vec.GetAt(nConnectionIndex);
			pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x4, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		pT->Unlock();
  }

  void Fire_AfterIParEvent(double Time, long iGlobalId, long Value)
  {
    if (m_vec.GetSize() == 0) return;

		T* pT = static_cast<T*>(this);
    int nConnections;
		int nConnectionIndex;
    CComPtr<IUnknown> sp;
    IDispatch* pDispatch;

		CComVariant pvars[3];
    pvars[2] = Time;
    pvars[1] = iGlobalId;
    pvars[0] = Value;
		
		pT->Lock();
    nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			sp = m_vec.GetAt(nConnectionIndex);
			pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x5, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		pT->Unlock();
  }


  void Fire_AfterStateEvent(double Time, BSTR EvId, long iEvEqn)
  {
    if (m_vec.GetSize() == 0) return;

		T* pT = static_cast<T*>(this);
    int nConnections;
		int nConnectionIndex;
    CComPtr<IUnknown> sp;
    IDispatch* pDispatch;

		CComVariant pvars[3];
    pvars[2] = Time;
    pvars[1] = EvId;
    pvars[0] = iEvEqn;
		
		pT->Lock();
    nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			sp = m_vec.GetAt(nConnectionIndex);
			pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x6, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		pT->Unlock();
  }

#define INIT_BOOL_VARIANT(var, val) \
  VariantInit(&var); \
  var.vt = VT_BOOL; \
  var.boolVal = val ? VARIANT_TRUE : VARIANT_FALSE;

#define INIT_LONG_VARIANT(var, val) \
  VariantInit(&var); \
  var.vt = VT_I4; \
  var.lVal = val;

#define INIT_BSTR_VARIANT(var, val) \
  VariantInit(&var); \
  var.vt = VT_BSTR; \
  var.bstrVal = val;


#define INIT_BYREF_LONG_VARIANT(var, val) \
  VariantInit(&var); \
  var.vt = VT_I4 | VT_BYREF; \
  var.plVal = val;

#define INIT_BSTR_VARIANT_ARRAY(var, val) \
  VariantInit(&var); \
  var.vt = VT_ARRAY | VT_BSTR | VT_BYREF; \
  var.pparray = val;

#define INIT_DOUBLE_VARIANT_ARRAY(var, val) \
  VariantInit(&var); \
  var.vt = VT_ARRAY | VT_R8 | VT_BYREF; \
  var.pparray = val;

#define INIT_LONG_VARIANT_ARRAY(var, val) \
  VariantInit(&var); \
  var.vt = VT_ARRAY | VT_I4 | VT_BYREF; \
  var.pparray = val;

  void Fire_InitializationInfo(
		VARIANT_BOOL fault, 
		long stage,
		long nModelEqns,
		long nModelVars,
		long nActiveEqns,
		long nActiveVars,
		long nAugmentedEqns,
		long nAugmentedVars,
		SAFEARRAY* EqnNames, 
		SAFEARRAY* VarNames, 
		long nColIndices,
		SAFEARRAY* cNZCols, 
		SAFEARRAY* spRowPage, 
		SAFEARRAY* ColIndices,
		SAFEARRAY* EqnOrder, 
		SAFEARRAY* VarOrder, 
		SAFEARRAY* VAL,
    SAFEARRAY* EAL,
		SAFEARRAY* AssignedEqn,
		SAFEARRAY* VarVals,
	  SAFEARRAY* VarDotVals,
    SAFEARRAY* ResVals)
  {
    if (m_vec.GetSize() == 0) return;

		T* pT = static_cast<T*>(this);
    int nConnections;
		int nConnectionIndex;
    CComPtr<IUnknown> sp;
    IDispatch* pDispatch;
		VARIANT pvars[22];

    INIT_BOOL_VARIANT(pvars[21], fault)                    // [in] VARIANT_BOOL fault, 
    INIT_LONG_VARIANT(pvars[20], stage)                    // [in] long stage,
    INIT_LONG_VARIANT(pvars[19], nModelEqns)               // [in] long nModelEqns,
    INIT_LONG_VARIANT(pvars[18], nModelVars)               // [in] long nModelVars,
		INIT_LONG_VARIANT(pvars[17], nActiveEqns)              // [in] long nActiveEqns,
		INIT_LONG_VARIANT(pvars[16], nActiveVars)              // [in] long nActiveVars,
		INIT_LONG_VARIANT(pvars[15], nAugmentedEqns)           // [in] long nAugmentedEqns,
		INIT_LONG_VARIANT(pvars[14], nAugmentedVars)           // [in] long nAugmentedVars,
		INIT_BSTR_VARIANT_ARRAY(pvars[13], &EqnNames)          // [in, out] SAFEARRAY(BSTR)* EqnNames, 
		INIT_BSTR_VARIANT_ARRAY(pvars[12], &VarNames)          // [in, out] SAFEARRAY(BSTR)* VarNames,
		INIT_LONG_VARIANT(pvars[11], nColIndices)             // [in] long nColIndices,
		INIT_LONG_VARIANT_ARRAY(pvars[10], &cNZCols)          // [in, out] SAFEARRAY(long)* cNZCols, 
		INIT_LONG_VARIANT_ARRAY(pvars[9], &spRowPage)        // [in, out] SAFEARRAY(long)* spRowPage, 
		INIT_LONG_VARIANT_ARRAY(pvars[8], &ColIndices)       // [in, out] SAFEARRAY(long)* ColIndices,
		INIT_LONG_VARIANT_ARRAY(pvars[7], &EqnOrder)         // [in, out] SAFEARRAY(long)* EqnOrder, 
		INIT_LONG_VARIANT_ARRAY(pvars[6], &VarOrder)         // [in, out] SAFEARRAY(long)* VarOrder, 
		INIT_LONG_VARIANT_ARRAY(pvars[5], &VAL)              // [in, out] SAFEARRAY(long)* VAL,
		INIT_LONG_VARIANT_ARRAY(pvars[4], &EAL)              // [in, out] SAFEARRAY(long)* EAL,
		INIT_LONG_VARIANT_ARRAY(pvars[3], &AssignedEqn)      // [in, out] SAFEARRAY(long)* AssignedEqn,
		INIT_DOUBLE_VARIANT_ARRAY(pvars[2], &VarVals)        // [in, out] SAFEARRAY(double)* VarVals,
		INIT_DOUBLE_VARIANT_ARRAY(pvars[1], &VarDotVals)     // [in, out] SAFEARRAY(double)* VarDotVals,
		INIT_DOUBLE_VARIANT_ARRAY(pvars[0], &ResVals)        // [in, out] SAFEARRAY(double)* ResVals);

		pT->Lock();
    nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			sp = m_vec.GetAt(nConnectionIndex);
			pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				DISPPARAMS disp = { pvars, NULL, 22, 0 };
				HRESULT hr = S_OK;
        hr = pDispatch->Invoke(0x7, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
        DWORD err = GetLastError();
			}
		}
		pT->Unlock();
  }


  void Fire_GetTrimEqns(trimEquationInfo& trimEqnInfo)
  {
    if (m_vec.GetSize() == 0) return;

		T* pT = static_cast<T*>(this);
    int nConnections;
		int nConnectionIndex;
    CComPtr<IUnknown> sp;
    IDispatch* pDispatch;
    VARIANT pvars[5];

    INIT_BYREF_LONG_VARIANT(pvars[4], &trimEqnInfo.nEqns)
		INIT_BYREF_LONG_VARIANT(pvars[3], &trimEqnInfo.nColIndices)
		INIT_LONG_VARIANT_ARRAY(pvars[2], &trimEqnInfo.psa_cNZCols) 
		INIT_LONG_VARIANT_ARRAY(pvars[1], &trimEqnInfo.psa_spRowPage)
		INIT_LONG_VARIANT_ARRAY(pvars[0], &trimEqnInfo.psa_ColIndices)

		pT->Lock();
    nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			sp = m_vec.GetAt(nConnectionIndex);
			pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				DISPPARAMS disp = { pvars, NULL, 5, 0 };
				pDispatch->Invoke(0x8, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		pT->Unlock();
  }

  void Fire_GetTrimVars(trimConstraintInfo& trimConInfo)
  {
    if (m_vec.GetSize() == 0) return;

		T* pT = static_cast<T*>(this);
    int nConnections;
		int nConnectionIndex;
    CComPtr<IUnknown> sp;
    IDispatch* pDispatch;
		VARIANT pvars[3];

    INIT_BYREF_LONG_VARIANT(pvars[2], &trimConInfo.nVars)
		INIT_LONG_VARIANT_ARRAY(pvars[1], &trimConInfo.psa_VarIds) 
		INIT_LONG_VARIANT_ARRAY(pvars[0], &trimConInfo.psa_VarVals)
		
		pT->Lock();
    nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			sp = m_vec.GetAt(nConnectionIndex);
			pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0x9, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
			}
		}
		pT->Unlock();
  }

  void Fire_SetVariables(SAFEARRAY* pVarVals) 
  {
    if (m_vec.GetSize() == 0) return;

		T* pT = static_cast<T*>(this);
    int nConnections;
		int nConnectionIndex;
    CComPtr<IUnknown> sp;
    IDispatch* pDispatch;
		VARIANT pvars[1];

		INIT_DOUBLE_VARIANT_ARRAY(pvars[0], &pVarVals) 
		
		pT->Lock();
    nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			sp = m_vec.GetAt(nConnectionIndex);
			pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0xA, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
        DWORD err = GetLastError();
			}
		}
		pT->Unlock();
  }


  void Fire_GetResiduals(
			long nEqns, 
			SAFEARRAY* pEqnIds, 
			SAFEARRAY* pResiduals)
  {
    if (m_vec.GetSize() == 0) return;

		T* pT = static_cast<T*>(this);
    int nConnections;
		int nConnectionIndex;
    CComPtr<IUnknown> sp;
    IDispatch* pDispatch;
		VARIANT pvars[3];

    INIT_LONG_VARIANT(pvars[2], nEqns)
		INIT_LONG_VARIANT_ARRAY(pvars[1], &pEqnIds) 
		INIT_DOUBLE_VARIANT_ARRAY(pvars[0], &pResiduals)
		
		pT->Lock();
    nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			sp = m_vec.GetAt(nConnectionIndex);
			pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0xB, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
        DWORD err = GetLastError();
			}
		}
		pT->Unlock();
  }

  void Fire_SetResiduals(SAFEARRAY* pResVals) 
  {
    if (m_vec.GetSize() == 0) return;

		T* pT = static_cast<T*>(this);
    int nConnections;
		int nConnectionIndex;
    CComPtr<IUnknown> sp;
    IDispatch* pDispatch;
		VARIANT pvars[1];

		INIT_DOUBLE_VARIANT_ARRAY(pvars[0], &pResVals) 
		
		pT->Lock();
    nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			sp = m_vec.GetAt(nConnectionIndex);
			pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				DISPPARAMS disp = { pvars, NULL, 3, 0 };
				pDispatch->Invoke(0xC, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
        DWORD err = GetLastError();
			}
		}
		pT->Unlock();
  }

  void Fire_ShowDialog(BSTR msg) 
  {
    if (m_vec.GetSize() == 0) return;

		T* pT = static_cast<T*>(this);
    int nConnections;
		int nConnectionIndex;
    CComPtr<IUnknown> sp;
    IDispatch* pDispatch;
		VARIANT pvars[1];

		INIT_BSTR_VARIANT(pvars[0], msg) 
		
		pT->Lock();
    nConnections = m_vec.GetSize();
		
		for (nConnectionIndex = 0; nConnectionIndex < nConnections; nConnectionIndex++)
		{
			sp = m_vec.GetAt(nConnectionIndex);
			pDispatch = reinterpret_cast<IDispatch*>(sp.p);
			if (pDispatch != NULL)
			{
				DISPPARAMS disp = { pvars, NULL, 1, 0 };
				pDispatch->Invoke(0xD, IID_NULL, LOCALE_USER_DEFAULT, DISPATCH_METHOD, &disp, NULL, NULL, NULL);
        DWORD err = GetLastError();
			}
		}
		pT->Unlock();
  }

};





template <class T>
class CProxyIOnModelExecEvents : public IConnectionPointImpl<T, &IID_IOnModelExecEvents, CComDynamicUnkArray>
{
	//Warning this class may be recreated by the wizard.
public:

  HRESULT Fire_BeforeRParEvent(double Time, long iGlobalId, double Value)
	{
    HRESULT ret = S_OK;
    IOnModelExecEvents* pIF = NULL;
		T* pT = static_cast<T*>(this);
    pT->Lock();

    IUnknown** pp = m_vec.begin();
    while (pp < m_vec.end())
		{
			if (*pp != NULL)
      {
			  pIF = reinterpret_cast<IOnModelExecEvents*>(*pp);
				ret = pIF->BeforeRParEvent(Time, iGlobalId, Value);
			}
      pp++;
		}
    pT->Unlock();
    return ret;
  }

  HRESULT Fire_BeforeIParEvent(double Time, long iGlobalId, long Value)
	{
    HRESULT ret = S_OK;
    IOnModelExecEvents* pIF = NULL;
		T* pT = static_cast<T*>(this);
    pT->Lock();

    IUnknown** pp = m_vec.begin();
    while (pp < m_vec.end())
		{
			if (*pp != NULL)
      {
			  pIF = reinterpret_cast<IOnModelExecEvents*>(*pp);
				ret = pIF->BeforeIParEvent(Time, iGlobalId, Value);
			}
      pp++;
		}
    pT->Unlock();
    return ret;
  }

  HRESULT Fire_BeforeStateEvent(double Time, BSTR EvId, long iEvEqn)
	{
    HRESULT ret = S_OK;
    IOnModelExecEvents* pIF = NULL;
		T* pT = static_cast<T*>(this);
    pT->Lock();

    IUnknown** pp = m_vec.begin();
    while (pp < m_vec.end())
		{
			if (*pp != NULL)
      {
			  pIF = reinterpret_cast<IOnModelExecEvents*>(*pp);
				ret = pIF->BeforeStateEvent(Time, EvId, iEvEqn);
			}
      pp++;
		}
    pT->Unlock();
    return ret;
  }
  
  HRESULT Fire_AfterRParEvent(double Time, long iGlobalId, double Value)
	{
    HRESULT ret = S_OK;
    IOnModelExecEvents* pIF = NULL;
		T* pT = static_cast<T*>(this);
    pT->Lock();

    IUnknown** pp = m_vec.begin();
    while (pp < m_vec.end())
		{
			if (*pp != NULL)
      {
			  pIF = reinterpret_cast<IOnModelExecEvents*>(*pp);
				ret = pIF->AfterRParEvent(Time, iGlobalId, Value);
			}
      pp++;
		}
    pT->Unlock();
    return ret;
  }

  HRESULT Fire_AfterIParEvent(double Time, long iGlobalId, long Value)
	{
    HRESULT ret = S_OK;
    IOnModelExecEvents* pIF = NULL;
		T* pT = static_cast<T*>(this);
    pT->Lock();

    IUnknown** pp = m_vec.begin();
    while (pp < m_vec.end())
		{
			if (*pp != NULL)
      {
			  pIF = reinterpret_cast<IOnModelExecEvents*>(*pp);
				ret = pIF->AfterIParEvent(Time, iGlobalId, Value);
			}
      pp++;
		}
    pT->Unlock();
    return ret;
  }

  HRESULT Fire_AfterStateEvent(double Time, BSTR EvId, long iEvEqn)
	{
    HRESULT ret = S_OK;
    IOnModelExecEvents* pIF = NULL;
		T* pT = static_cast<T*>(this);
    pT->Lock();

    IUnknown** pp = m_vec.begin();
    while (pp < m_vec.end())
		{
			if (*pp != NULL)
      {
			  pIF = reinterpret_cast<IOnModelExecEvents*>(*pp);
				ret = pIF->AfterStateEvent(Time, EvId, iEvEqn);
			}
      pp++;
		}
    pT->Unlock();
    return ret;
  }

  HRESULT Fire_InitializationInfo(
		VARIANT_BOOL fault, 
		long stage,
		long nModelEqns,
		long nModelVars,
		long nActiveEqns,
		long nActiveVars,
		long nAugmentedEqns,
		long nAugmentedVars,
		SAFEARRAY* EqnNames, 
		SAFEARRAY* VarNames, 
		long nColIndices,
		SAFEARRAY* cNZCols, 
		SAFEARRAY* spRowPage, 
		SAFEARRAY* ColIndices,
		SAFEARRAY* EqnOrder, 
		SAFEARRAY* VarOrder, 
		SAFEARRAY* VAL,
    SAFEARRAY* EAL,
		SAFEARRAY* AssignedEqn,
		SAFEARRAY* VarVals,
	  SAFEARRAY* VarDotVals,
    SAFEARRAY* ResVals)
	{
    HRESULT ret = S_OK;
    IOnModelExecEvents* pIF = NULL;
		T* pT = static_cast<T*>(this);
    pT->Lock();
  
    VARIANT_BOOL bFault = fault ? VARIANT_TRUE : VARIANT_FALSE;
    IUnknown** pp = m_vec.begin();
    while (pp < m_vec.end())
		{
			if (*pp != NULL)
      {
			  pIF = reinterpret_cast<IOnModelExecEvents*>(*pp);
				ret = pIF->InitializationInfo(
          bFault,
          (InitStage) stage,
          nModelEqns,
          nModelVars,
          nActiveEqns,
          nActiveVars,
          nAugmentedEqns,
          nAugmentedVars,
          &EqnNames, 
          &VarNames, 
          nColIndices,
          &cNZCols, 
          &spRowPage, 
          &ColIndices,
          &EqnOrder, 
          &VarOrder, 
          &VAL,
          &EAL,
          &AssignedEqn,
          &VarVals,
          &VarDotVals,
          &ResVals);
			}
      pp++;
		}
    pT->Unlock();
    return ret;
  }

  HRESULT Fire_GetTrimEqns(trimEquationInfo& trimEqnInfo)
	{
    HRESULT ret = S_OK;
    IOnModelExecEvents* pIF = NULL;
		T* pT = static_cast<T*>(this);
    pT->Lock();

    IUnknown** pp = m_vec.begin();
    while (pp < m_vec.end())
		{
			if (*pp != NULL)
      {
			  pIF = reinterpret_cast<IOnModelExecEvents*>(*pp);
				ret = pIF->GetTrimEqns(
          &trimEqnInfo.nEqns, 
          &trimEqnInfo.nColIndices, 
          &trimEqnInfo.psa_cNZCols, 
          &trimEqnInfo.psa_spRowPage, 
          &trimEqnInfo.psa_ColIndices);
			}
      pp++;
		}
    pT->Unlock();
    return ret;
  }

  HRESULT Fire_GetTrimVars(trimConstraintInfo& trimConInfo)
	{
    HRESULT ret = S_OK;
    IOnModelExecEvents* pIF = NULL;
		T* pT = static_cast<T*>(this);
    pT->Lock();

    IUnknown** pp = m_vec.begin();
    while (pp < m_vec.end())
		{
			if (*pp != NULL)
      {
			  pIF = reinterpret_cast<IOnModelExecEvents*>(*pp);
				ret = pIF->GetTrimVars(
          &trimConInfo.nVars, 
          &trimConInfo.psa_VarIds, 
          &trimConInfo.psa_VarVals); 
			}
      pp++;
		}
    pT->Unlock();
    return ret;
  }

  HRESULT Fire_SetVariables(SAFEARRAY* VarVals)
	{
    HRESULT ret = S_OK;
    IOnModelExecEvents* pIF = NULL;
		T* pT = static_cast<T*>(this);
    pT->Lock();

    IUnknown** pp = m_vec.begin();
    while (pp < m_vec.end())
		{
			if (*pp != NULL)
      {
			  pIF = reinterpret_cast<IOnModelExecEvents*>(*pp);
				ret = pIF->SetVariables(&VarVals);
			}
      pp++;
		}
    pT->Unlock();
    return ret;
  }

  HRESULT Fire_GetResiduals(
			long nEqns, 
			SAFEARRAY* pEqnIds, 
			SAFEARRAY* pResiduals)
	{
    HRESULT ret = S_OK;
    IOnModelExecEvents* pIF = NULL;
		T* pT = static_cast<T*>(this);
    pT->Lock();

    IUnknown** pp = m_vec.begin();
    while (pp < m_vec.end())
		{
			if (*pp != NULL)
      {
			  pIF = reinterpret_cast<IOnModelExecEvents*>(*pp);
				ret = pIF->GetResiduals(
			    nEqns, 
			    &pEqnIds, 
			    &pResiduals);
			}
      pp++;
		}
    pT->Unlock();
    return ret;
  }

  HRESULT Fire_SetResiduals(SAFEARRAY* ResVals)
	{
    HRESULT ret = S_OK;
    IOnModelExecEvents* pIF = NULL;
		T* pT = static_cast<T*>(this);
    pT->Lock();

    IUnknown** pp = m_vec.begin();
    while (pp < m_vec.end())
		{
			if (*pp != NULL)
      {
			  pIF = reinterpret_cast<IOnModelExecEvents*>(*pp);
				ret = pIF->SetResiduals(&ResVals);
			}
      pp++;
		}
    pT->Unlock();
    return ret;
  }

  HRESULT Fire_ShowDialog(BSTR msg)
	{
    HRESULT ret = S_OK;
    IOnModelExecEvents* pIF = NULL;
		T* pT = static_cast<T*>(this);
    pT->Lock();

    IUnknown** pp = m_vec.begin();
    while (pp < m_vec.end())
		{
			if (*pp != NULL)
      {
			  pIF = reinterpret_cast<IOnModelExecEvents*>(*pp);
				ret = pIF->ShowDialog(msg);
			}
      pp++;
		}
    pT->Unlock();
    return ret;
  }

};

#endif // _ONMODELEXECCP_H_