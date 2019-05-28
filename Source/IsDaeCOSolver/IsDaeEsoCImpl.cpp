// IsDaeEsoCImpl.cpp : Implementation of CIsDaeEsoCImpl
#include "stdafx.h"
#include "ISDaeCOSolver.h"
#include "IsDaeEsoCImpl.h"
#include "IOnUMLDaeEsoBase.h"
#include "OnDaeCOSolverMacros.h"
#include "TransitionInfo.h"
#include "StateInfo.h"
#include "VarInfo.h"
#include "ModelNavMaps.h"
#include "MatInfo.h"
#include "VirtualTimeInfo.h"
#include "triangularization.h"
#include "OnAD.h"

// from ONUMLEso library
#include "OnUMLConstants_i.c"
#include "stdio.h"

#if 0
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#endif

/////////////////////////////////////////////////////////////////////////////
// CIsDaeEsoCImpl

CIsDaeEsoCImpl::CIsDaeEsoCImpl() : CIsDaeEsoBase(0, 0, 0, 0)
{
  m_pEsoImpl = NULL;
  m_pEsoNames = NULL;
  m_pVarNames = NULL;
  m_pRParNames = NULL;
  m_pIParNames = NULL;
  m_pEqnNames = NULL;

  m_nx = 0;
  m_nad_x = 0;
  m_nrpar = 0;
  m_nipar = 0;

  m_x = NULL;
  m_xdot = NULL;
  m_ad_x = NULL;
  m_ad_xdot = NULL;
  m_oldx = NULL;
  m_oldxdot = NULL;
  m_rpar = NULL;
  m_ipar = NULL;
}

CIsDaeEsoCImpl::~CIsDaeEsoCImpl()
{
  long i;

  if (m_pEsoImpl) 
  {
    m_pEsoImpl->Release();
    //delete m_pEsoImpl;
    m_pEsoImpl = NULL;
  }

  if (m_pEsoNames)
  {
    for (i = 0; i < m_nEsos; i++) 
    {
      if (m_pEsoNames[i]) 
        ::SysFreeString(m_pEsoNames[i]);
    }
    DESTROY_VECTOR(m_pEsoNames)
  }

  if (m_pVarNames)
  {
    for (i = 0; i < m_nVars; i++) if (m_pVarNames[i]) ::SysFreeString(m_pVarNames[i]);
    DESTROY_VECTOR(m_pVarNames)
  }
  
  if (m_pRParNames)
  {
    for (i = 0; i < m_nRealParameters; i++) if (m_pRParNames[i]) ::SysFreeString(m_pRParNames[i]);
    DESTROY_VECTOR(m_pRParNames)
  }

  if (m_pIParNames)
  {
    for (i = 0; i < m_nIntegerParameters; i++) if (m_pIParNames[i]) ::SysFreeString(m_pIParNames[i]);
    DESTROY_VECTOR(m_pIParNames)
  }

  if (m_pEqnNames)
  {
    for (i = 0; i < m_nEqns; i++) if (m_pEqnNames[i]) ::SysFreeString(m_pEqnNames[i]);
    DESTROY_VECTOR(m_pEqnNames)
  }

  DESTROY_VECTOR(m_StateInfo)
  DESTROY_VECTOR(m_TransitionInfo)
}

HRESULT CIsDaeEsoCImpl::GetEsoNames(SAFEARRAY** pEsoNames)
{
  BSTR* pvData = NULL;
  long i;

  if (*pEsoNames) SafeArrayDestroy(*pEsoNames);

	*pEsoNames = SafeArrayCreateVector(VT_BSTR, 0, m_nEsos-1);
  SafeArrayAccessData(*pEsoNames, (void HUGEP* FAR*)& pvData);
  if (!m_pEsoNames) iGetEsoNames();
  for (i = 1; i < m_nEsos; i++)
  {
    if (m_pEsoNames[i])
      pvData[i-1] = SysAllocString(m_pEsoNames[i]);
    else
      pvData[i-1] = NULL;
  }
  SafeArrayUnaccessData(*pEsoNames);
	return S_OK;
}

HRESULT CIsDaeEsoCImpl::iGetEsoNames()
{
  BSTR Name = NULL;
  long i;
  long cEsos = 0;

  if (!m_pEsoNames)
  {
    m_pEsoNames = new BSTR[m_nEsos];
    m_pEsoNames[0] = NULL;
    for (i = 1; i < m_nEsos; i++) 
    {
      m_pEsoNames[i] = NULL;
      if (!m_Esos[i]->m_bMasterNode)
      {
        if (SUCCEEDED( m_pEsoImpl->GetEsoName(cEsos++, &Name) ))
          m_pEsoNames[i] = Name;
      }
    }
  }

  return S_OK;
}

HRESULT CIsDaeEsoCImpl::get_EsoImpl(IUnknown** pEsoImpl)
{
  HRESULT hr;

  if (m_pEsoImpl)
  {
    *pEsoImpl = m_pEsoImpl;
    m_pEsoImpl->AddRef();
    hr = S_OK;
  }
  else
  {
    *pEsoImpl = NULL;
    hr = E_FAIL;
  }

  return hr;
}

STDMETHODIMP CIsDaeEsoCImpl::AddModel(IIsDaeEsoCImpl* pEso, BSTR modelName)
{
  HRESULT hr;
  IUnknown* pEsoImpl;

  hr = pEso->get_EsoImpl(&pEsoImpl);
  if (SUCCEEDED(hr))
  {
    m_pEsoImpl->AddEso(pEsoImpl, modelName);
    AddEso(pEso);
  }

  return hr;
}

HRESULT CIsDaeEsoCImpl::get_Eso(BSTR Name, IIsDaeEsoCImpl** pEso)
{
  CComBSTR cmpName;
  CComBSTR srcName = Name;
  HRESULT hr = E_INVALIDARG;
  long i;

  if (!m_pEsoNames) iGetEsoNames();

  for (i = 1; i < m_nEsos; i++) 
  {
    if (!m_Esos[i]->m_bMasterNode)
    {
      cmpName = m_pEsoNames[i];
      if (cmpName == srcName)
      {
        hr = m_IIsEsos[i]->QueryInterface(IID_IIsDaeEsoCImpl, reinterpret_cast<void**> (pEso) );
        break;
      }
    }
  }

  return hr;
}

HRESULT CIsDaeEsoCImpl::GetVarNames( SAFEARRAY** pVarNames)
{
  BSTR* pvData = NULL;
  CComBSTR prefix;
  long count = 0;
  long i;

  if (*pVarNames) SafeArrayDestroy(*pVarNames);
	*pVarNames = SafeArrayCreateVector(VT_BSTR, 0, m_nVars);
  SafeArrayAccessData(*pVarNames, (void HUGEP* FAR*)& pvData);
  if (!m_pVarNames) 
  {
    iGetVarNames(m_pVarNames, prefix, count);
    _ASSERTE(count == m_nVars);
  }

  for (i = 0; i < m_nVars; i++)
  {
    if (m_pVarNames[i])
      pvData[i] = ::SysAllocString(m_pVarNames[i]);
    else
      pvData[i] = NULL;
  }
  SafeArrayUnaccessData(*pVarNames);
	
  return S_OK;
}

HRESULT CIsDaeEsoCImpl::iGetVarNames( BSTR*& pVarNames, CComBSTR& prefix, long& count)
{
  long i;
  BSTR Name = NULL;
  CComBSTR local_prefix;
  long cEso;
  CIsDaeEsoBase* pEso;

  if (!pVarNames) pVarNames = new BSTR[m_nVars];

  for (i = 0; i < m_nLocalVars; i++) 
  {
    if (SUCCEEDED( m_pEsoImpl->GetVarName(i, &Name) ))
    {
      local_prefix = prefix;
      if (local_prefix.Length() > 0) local_prefix.Append(L".");
      local_prefix.Append(Name);
      pVarNames[count++] = local_prefix.Detach();
      ::SysFreeString(Name);
    }
    else
      pVarNames[count++] = NULL;
  }
 
  cEso = 0;
  for (i = 0; i < m_nEsos-1; i++)
  {
    pEso = m_Esos[i+1];
    if (m_bGlobalNode)
    {
      if (!pEso->m_bMasterNode)
      {
        Name = NULL;
        m_pEsoImpl->GetEsoName(cEso++, &Name);
        local_prefix = prefix;
        if (local_prefix.Length() > 0) local_prefix.Append(L".");
        local_prefix.Append(Name);
        ::SysFreeString(Name);
        static_cast<CIsDaeEsoCImpl*> (pEso)->iGetVarNames(pVarNames, local_prefix, count);
      }
    }
    else if (!m_bMasterNode)
    {
      Name = NULL;
      m_pEsoImpl->GetEsoName(cEso++, &Name);
      local_prefix = prefix;
      if (local_prefix.Length() > 0) local_prefix.Append(L".");
      local_prefix.Append(Name);
      ::SysFreeString(Name);
      static_cast<CIsDaeEsoCImpl*> (pEso)->iGetVarNames(pVarNames, local_prefix, count);
    }
  }
  
  return S_OK;
}


HRESULT CIsDaeEsoCImpl::get_Var( BSTR Name,  double* pVal)
{
  CComBSTR cmpName;
  CComBSTR srcName = Name;
  HRESULT hr = E_INVALIDARG;
  CComBSTR prefix;
  long count = 0;
  long i;

  if (!m_pVarNames) 
  {
    iGetVarNames(m_pVarNames, prefix, count);
    _ASSERTE(count == m_nVars);
  }

  for (i = 0; i < m_nVars; i++) 
  {
    cmpName = m_pVarNames[i];
    if (cmpName == srcName)
    {
      *pVal = m_y->m_varVal[i];
      hr = S_OK;
      break;
    }
  }
  return hr;
}

HRESULT CIsDaeEsoCImpl::put_Var( BSTR Name,  double Val)
{
  CComBSTR cmpName;
  CComBSTR srcName = Name;
  HRESULT hr = E_INVALIDARG;
  CComBSTR prefix;
  long count = 0;
  long i;

  if (!m_pVarNames) 
  {
    iGetVarNames(m_pVarNames, prefix, count);
    _ASSERTE(count == m_nVars);
  }

  for (i = 0; i < m_nVars; i++) 
  {
    cmpName = m_pVarNames[i];
    if (cmpName == srcName)
    {
      m_y->m_varVal[i] = Val;
      hr = S_OK;
      break;
    }
  }
  return hr;
}

HRESULT CIsDaeEsoCImpl::GetRParNames( SAFEARRAY** pRParNames)
{
  BSTR* pvData = NULL;
  CComBSTR prefix;
  long count = 0;
  long i;

  if (*pRParNames) SafeArrayDestroy(*pRParNames);
	*pRParNames = SafeArrayCreateVector(VT_BSTR, 0, m_nRealParameters);
  SafeArrayAccessData(*pRParNames, (void HUGEP* FAR*)& pvData);
  if (!m_pRParNames) 
  {
    iGetRParNames(m_pRParNames, prefix, count);
    _ASSERTE(count == m_nRealParameters);
  }

  for (i = 0; i < m_nRealParameters; i++)
  {
    if (m_pRParNames[i])
      pvData[i] = ::SysAllocString(m_pRParNames[i]);
    else
      pvData[i] = NULL;
  }
  SafeArrayUnaccessData(*pRParNames);
	
  return S_OK;
}

HRESULT CIsDaeEsoCImpl::iGetRParNames( BSTR*& pRParNames, CComBSTR& prefix, long& count)
{
  long i;
  BSTR Name = NULL;
  CComBSTR local_prefix;
  long cEso;
  CIsDaeEsoBase* pEso;

  if (!pRParNames) pRParNames = new BSTR[m_nRealParameters];

  for (i = 0; i < m_nLocalRPars; i++) 
  {
    if (SUCCEEDED( m_pEsoImpl->GetRParName(i, &Name) ))
    {
      local_prefix = prefix;
      if (local_prefix.Length() > 0) local_prefix.Append(L".");
      local_prefix.Append(Name);
      pRParNames[count++] = local_prefix.Detach();
      ::SysFreeString(Name);
    }
    else
      pRParNames[count++] = NULL;
  }
 
  cEso = 0;
  for (i = 0; i < m_nEsos-1; i++)
  {
    pEso = m_Esos[i+1];
    if (m_bGlobalNode)
    {
      if (!pEso->m_bMasterNode)
      {
        Name = NULL;
        m_pEsoImpl->GetEsoName(cEso++, &Name);
        local_prefix = prefix;
        if (local_prefix.Length() > 0) local_prefix.Append(L".");
        local_prefix.Append(Name);
        ::SysFreeString(Name);
        static_cast<CIsDaeEsoCImpl*> (pEso)->iGetRParNames(pRParNames, local_prefix, count);
      }
    }
    else if (!m_bMasterNode)
    {
      Name = NULL;
      m_pEsoImpl->GetEsoName(cEso++, &Name);
      local_prefix = prefix;
      if (local_prefix.Length() > 0) local_prefix.Append(L".");
      local_prefix.Append(Name);
      ::SysFreeString(Name);
      static_cast<CIsDaeEsoCImpl*> (pEso)->iGetRParNames(pRParNames, local_prefix, count);
    }
  }
  
  return S_OK;
}


HRESULT CIsDaeEsoCImpl::get_RPar( BSTR Name,  double* pVal)
{
  CComBSTR cmpName;
  CComBSTR srcName = Name;
  HRESULT hr = E_INVALIDARG;
  CComBSTR prefix;
  long count = 0;
  long i;

  if (!m_pRParNames) 
  {
    iGetRParNames(m_pRParNames, prefix, count);
    _ASSERTE(count != m_nRealParameters);
  }

  for (i = 0; i < m_nRealParameters; i++) 
  {
    cmpName = m_pRParNames[i];
    if (cmpName == srcName)
    {
      *pVal = m_realParameters[i];
      hr = S_OK;
      break;
    }
  }
  return hr;
}

HRESULT CIsDaeEsoCImpl::put_RPar( BSTR Name,  double Val)
{
  CComBSTR cmpName;
  CComBSTR srcName = Name;
  HRESULT hr = E_INVALIDARG;
  CComBSTR prefix;
  long count = 0;
  long i;

  if (!m_pRParNames) 
  {
    iGetRParNames(m_pRParNames, prefix, count);
    _ASSERTE(count != m_nRealParameters);
  }

  for (i = 0; i < m_nRealParameters; i++) 
  {
    cmpName = m_pRParNames[i];
    if (cmpName == srcName)
    {
      m_realParameters[i] = Val;
      hr = S_OK;
      break;
    }
  }
  return hr;
}


HRESULT CIsDaeEsoCImpl::GetIParNames( SAFEARRAY** pIParNames)
{
  BSTR* pvData = NULL;
  CComBSTR prefix;
  long count = 0;
  long i;

  if (*pIParNames) SafeArrayDestroy(*pIParNames);
	*pIParNames = SafeArrayCreateVector(VT_BSTR, 0, m_nIntegerParameters);
  SafeArrayAccessData(*pIParNames, (void HUGEP* FAR*)& pvData);
  if (!m_pIParNames) 
  {
    iGetIParNames(m_pIParNames, prefix, count);
    _ASSERTE(count == m_nIntegerParameters);
  }

  for (i = 0; i < m_nIntegerParameters; i++)
  {
    if (m_pIParNames[i])
      pvData[i] = ::SysAllocString(m_pIParNames[i]);
    else
      pvData[i] = NULL;
  }
  SafeArrayUnaccessData(*pIParNames);
	
  return S_OK;
}

HRESULT CIsDaeEsoCImpl::iGetIParNames( BSTR*& pIParNames, CComBSTR& prefix, long& count)
{
  long i;
  BSTR Name = NULL;
  CComBSTR local_prefix;
  long cEso;
  CIsDaeEsoBase* pEso;

  if (!pIParNames) pIParNames = new BSTR[m_nIntegerParameters];

  for (i = 0; i < m_nLocalIPars; i++) 
  {
    if (SUCCEEDED( m_pEsoImpl->GetIParName(i, &Name) ))
    {
      local_prefix = prefix;
      if (local_prefix.Length() > 0) local_prefix.Append(L".");
      local_prefix.Append(Name);
      pIParNames[count++] = local_prefix.Detach();
      ::SysFreeString(Name);
    }
    else
      pIParNames[count++] = NULL;
  }
 
  cEso = 0;
  for (i = 0; i < m_nEsos-1; i++)
  {
    pEso = m_Esos[i+1];
    if (m_bGlobalNode)
    {
      if (!pEso->m_bMasterNode)
      {
        Name = NULL;
        m_pEsoImpl->GetEsoName(cEso++, &Name);
        local_prefix = prefix;
        if (local_prefix.Length() > 0) local_prefix.Append(L".");
        local_prefix.Append(Name);
        ::SysFreeString(Name);
        static_cast<CIsDaeEsoCImpl*> (pEso)->iGetIParNames(pIParNames, local_prefix, count);
      }
    }
    else if (!m_bMasterNode)
    {
      Name = NULL;
      m_pEsoImpl->GetEsoName(cEso++, &Name);
      local_prefix = prefix;
      if (local_prefix.Length() > 0) local_prefix.Append(L".");
      local_prefix.Append(Name);
      ::SysFreeString(Name);
      static_cast<CIsDaeEsoCImpl*> (pEso)->iGetIParNames(pIParNames, local_prefix, count);
    }
  }
  
  return S_OK;
}


HRESULT CIsDaeEsoCImpl::get_IPar( BSTR Name,  long* pVal)
{
  CComBSTR cmpName;
  CComBSTR srcName = Name;
  HRESULT hr = E_INVALIDARG;
  CComBSTR prefix;
  long count = 0;
  long i;

  if (!m_pIParNames) 
  {
    iGetIParNames(m_pIParNames, prefix, count);
    _ASSERTE(count != m_nIntegerParameters);
  }

  for (i = 0; i < m_nIntegerParameters; i++) 
  {
    cmpName = m_pIParNames[i];
    if (cmpName == srcName)
    {
      *pVal = m_integerParameters[i];
      hr = S_OK;
      break;
    }
  }
  return hr;
}

HRESULT CIsDaeEsoCImpl::put_IPar( BSTR Name,  long Val)
{
  CComBSTR cmpName;
  CComBSTR srcName = Name;
  HRESULT hr = E_INVALIDARG;
  CComBSTR prefix;
  long count = 0;
  long i;

  if (!m_pIParNames) 
  {
    iGetIParNames(m_pIParNames, prefix, count);
    _ASSERTE(count != m_nIntegerParameters);
  }

  for (i = 0; i < m_nIntegerParameters; i++) 
  {
    cmpName = m_pIParNames[i];
    if (cmpName == srcName)
    {
      m_integerParameters[i] = Val;
      hr = S_OK;
      break;
    }
  }
  return hr;
}

HRESULT CIsDaeEsoCImpl::iGetVariableId(BSTR Name, long* idx)
{
  CComBSTR cmpName;
  CComBSTR srcName = Name;
  HRESULT hr = E_INVALIDARG;
  CComBSTR prefix;
  long count = 0;
  long i;

  if (!m_pVarNames) 
  {
    iGetVarNames(m_pVarNames, prefix, count);
    _ASSERTE(count == m_nVars);
  }

  for (i = 0; i < m_nVars; i++) 
  {
    cmpName = m_pVarNames[i];
    if (cmpName == srcName)
    {
      *idx = i;
      hr = S_OK;
      break;
    }
  }
  return hr;
}

HRESULT CIsDaeEsoCImpl::iGetRealParId(BSTR Name, long* idx)
{
  CComBSTR cmpName;
  CComBSTR srcName = Name;
  HRESULT hr = E_INVALIDARG;
  CComBSTR prefix;
  long count = 0;
  long i;

  if (!m_pRParNames) 
  {
    iGetRParNames(m_pRParNames, prefix, count);
    _ASSERTE(count != m_nRealParameters);
  }

  for (i = 0; i < m_nRealParameters; i++) 
  {
    cmpName = m_pRParNames[i];
    if (cmpName == srcName)
    {
      *idx = i;
      hr = S_OK;
      break;
    }
  }
  return hr;
}

HRESULT CIsDaeEsoCImpl::iGetIntParId(BSTR Name, long* idx)
{
  CComBSTR cmpName;
  CComBSTR srcName = Name;
  HRESULT hr = E_INVALIDARG;
  CComBSTR prefix;
  long count = 0;
  long i;

  if (!m_pIParNames) 
  {
    iGetIParNames(m_pIParNames, prefix, count);
    _ASSERTE(count != m_nIntegerParameters);
  }

  for (i = 0; i < m_nIntegerParameters; i++) 
  {
    cmpName = m_pIParNames[i];
    if (cmpName == srcName)
    {
      *idx = i;
      hr = S_OK;
      break;
    }
  }
  return hr;
}

HRESULT CIsDaeEsoCImpl::GetEqnNames( SAFEARRAY** pEqnNames)
{
  BSTR* pvData = NULL;
  CComBSTR prefix;
  long count = 0;
  long i;

  if (*pEqnNames) SafeArrayDestroy(*pEqnNames);
	*pEqnNames = SafeArrayCreateVector(VT_BSTR, 0, m_nEqns);
  SafeArrayAccessData(*pEqnNames, (void HUGEP* FAR*)& pvData);
  if (!m_pEqnNames) 
  {
    iGetEqnNames(m_pEqnNames, prefix, count);
    _ASSERTE(count == m_nEqns);
  }

  for (i = 0; i < m_nEqns; i++)
  {
    if (m_pEqnNames[i])
      pvData[i] = ::SysAllocString(m_pEqnNames[i]);
    else
      pvData[i] = NULL;
  }
  SafeArrayUnaccessData(*pEqnNames);
	
  return S_OK;
}

HRESULT CIsDaeEsoCImpl::iGetEqnNames( BSTR*& pEqnNames, CComBSTR& prefix, long& count)
{
  long i, j;
  BSTR Name = NULL;
  CComBSTR local_prefix;
  long cEso;
  CIsDaeEsoBase* pEso;
  HRESULT hr = S_OK;

  if (!pEqnNames) pEqnNames = new BSTR[m_nEqns];

  for (i = 0; i < m_nLocalEqns; i++) 
  {
    if (m_EqnMap[i].bUndefined)
    {
      Name = ::SysAllocString(L"Undefined");
      hr = S_OK;
    }
    else
    {
      hr =  m_pEsoImpl->GetEqnName(m_EqnMap[i].iEqn, &Name);
    }
    
    if (SUCCEEDED(hr))
    {
      local_prefix = prefix;
      if (local_prefix.Length() > 0) local_prefix.Append(L".");
      local_prefix.Append(Name);
      pEqnNames[count++] = local_prefix.Detach();
      ::SysFreeString(Name);
    }
    else
      pEqnNames[count++] = NULL;
  }
 
  cEso = 0;
  for (i = 0; i < m_nEsos-1; i++)
  {
    pEso = m_Esos[i+1];
    Name = NULL;
    if (m_bGlobalNode)
    {
      if (pEso->m_bMasterNode)
        for (j = 0; j < pEso->m_nEqns; j++) pEqnNames[count++] = NULL;
      else
      {
        m_pEsoImpl->GetEsoName(cEso++, &Name);
        local_prefix = prefix;
        if (local_prefix.Length() > 0) local_prefix.Append(L".");
        local_prefix.Append(Name);
        ::SysFreeString(Name);
        static_cast<CIsDaeEsoCImpl*> (pEso)->iGetEqnNames(pEqnNames, local_prefix, count);
      }
    }
    else
    {
      if (!pEso->m_bMasterNode)
      {
        m_pEsoImpl->GetEsoName(cEso++, &Name);
        local_prefix = prefix;
        if (local_prefix.Length() > 0) local_prefix.Append(L".");
        local_prefix.Append(Name);
        ::SysFreeString(Name);
        static_cast<CIsDaeEsoCImpl*> (pEso)->iGetEqnNames(pEqnNames, local_prefix, count);
      }
    }
  }
  
  return S_OK;
}






HRESULT CIsDaeEsoCImpl::iInitialize()
{
  HRESULT hr = S_OK;

  if (!m_pEsoImpl) 
    return E_FAIL;

  if (m_bGlobalNode) 
  {
    hr = m_pEsoImpl->iInitializeGlobalNode();
    if (SUCCEEDED(hr))
      hr = iFindMasterNodes(); 
  }

  if (SUCCEEDED(hr))
    hr = CIsDaeEsoBase::iInitialize();

  return hr;
}

HRESULT CIsDaeEsoCImpl::iFindMasterNodes()
{
  long nEsos = 0;
  IOnUMLDaeEsoBase** pUMLEsos = NULL;
  IIsDaeEso* pIIsDaeEso = NULL;
  HRESULT hr = S_OK;
  long i;
  long nEqns;

  for (i = 1; i < m_nEsos; i++) 
    static_cast<CIsDaeEsoCImpl*> (m_Esos[i])->iFindMasterNodes();

  m_pEsoImpl->GetMasterNodeStatus(&m_bMasterNode);

  if (m_bMasterNode)
  {
    m_pEsoImpl->GetMemberEsos(&nEsos, &pUMLEsos);
    for (i = 0; i < nEsos; i++)
    {
      pUMLEsos[i]->GetOnModel(&pIIsDaeEso);
      AddEso(pIIsDaeEso);
      pIIsDaeEso->Release();  // counter the query interface call
      pUMLEsos[i]->Release(); // counter the GetMemberEsos call
    }
    m_pEsoImpl->GetNumEqns(&nEqns); // number of equations will have changed
    SetLocalSize(nEqns, m_nLocalVars, m_nLocalRPars, m_nLocalIPars);
    // iInitialize();
  }

  DESTROY_VECTOR(pUMLEsos)

  return S_OK;
}

STDMETHODIMP CIsDaeEsoCImpl::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IIsDaeEsoCImpl
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CIsDaeEsoCImpl::SetEso(IUnknown* pEso)
{
  HRESULT hr;
  long i;
  long nEsos = 0;
  IOnUMLDaeEsoBase** pEsos = NULL;
  CComObject<CIsDaeEsoCImpl>* pEsoCont;
  long nStates = 0; 
  long nTransitions = 0; 
  long iDefaultState = 0; 
  BSTR* TransEventIds = NULL; 
  long* SrcStates = NULL; 
  long** StateToEqnMap = NULL; 
  long* nStateEqns = NULL;
  long** TransToEqnMap = NULL;
  long* nTransEqns = NULL;
  IIsDaeEso* pIIsDaeEso;
  
  long nEqns;

  if (m_pEsoImpl) 
  {
    m_pEsoImpl->Release();
    m_pEsoImpl = NULL;
  }
  hr = pEso->QueryInterface(IID_IOnUMLDaeEsoBase, reinterpret_cast<void**> (&m_pEsoImpl) );

  if (SUCCEEDED(hr))
  {
	  hr = m_pEsoImpl->iInitialize();
    if (SUCCEEDED(hr))
    {
      // store this pointer on the Eso so it can be retrieved later if this is a member of a master node
      m_pEsoImpl->SetOnModel(static_cast<IIsDaeEso*> (this));
      m_pEsoImpl->GetNumEqns(&nEqns);
      m_pEsoImpl->GetVariableInfo(&m_x, &m_nx);
      m_pEsoImpl->GetDerivativeInfo(&m_xdot, &m_nx);
      m_pEsoImpl->GetADVariableInfo(&m_ad_x, &m_nad_x);
      m_pEsoImpl->GetADDerivativeInfo(&m_ad_xdot, &m_nad_x);
      m_pEsoImpl->GetOldVariableInfo(&m_oldx, &m_nx);
      m_pEsoImpl->GetOldVariableInfo(&m_oldxdot, &m_nx);
      m_pEsoImpl->GetRealParameterInfo(&m_rpar, &m_nrpar);
      m_pEsoImpl->GetIntegerParameterInfo(&m_ipar, &m_nipar);
      SetLocalSize(nEqns, m_nx, m_nrpar, m_nipar);

      if (SUCCEEDED( m_pEsoImpl->GetMemberEsos(&nEsos, &pEsos) ))
      {
        if (pEsos && nEsos > 0)
        {
          for (i = 0; i < nEsos; i++)
          {
            CComObject<CIsDaeEsoCImpl>::CreateInstance(&pEsoCont);
            pEsoCont->SetEso(pEsos[i]);
            pEsos[i]->Release();
            pEsoCont->QueryInterface(IID_IIsDaeEso, reinterpret_cast<void**> (&pIIsDaeEso) );
            AddEso(pIIsDaeEso);
            pEsoCont->Release();
          }
        }
      }

            // add STN information if defined
  		if (SUCCEEDED( m_pEsoImpl->GetSTNStruct(
        &nStates, 
        &nTransitions, 
        &iDefaultState, 
        &TransEventIds, 
        &SrcStates, 
        &StateToEqnMap, 
        &nStateEqns, 
        &TransToEqnMap, 
        &nTransEqns) ))
      {
        if (nStates > 0 && nTransitions > 0 && iDefaultState >= 0)
        {
          m_nStates = nStates;
          m_nTransitions = nTransitions;
          m_DefaultState = iDefaultState;
          m_CurrentState = iDefaultState;

          m_TransitionInfo = new TransitionInfo[nTransitions];
          for (i = 0; i < nTransitions; i++)
          {
            m_TransitionInfo[i].SourceState = SrcStates[i];
            m_TransitionInfo[i].setEventId(TransEventIds[i]);
            m_TransitionInfo[i].setEqns(TransToEqnMap[i], nTransEqns[i]);
          }
          m_StateInfo = new StateInfo[nStates];
          for (i = 0; i < nStates; i++) 
          {
            m_StateInfo[i].setEqns(StateToEqnMap[i], nStateEqns[i]);
          }
        }
      }

      for (i = 0; i < m_nx; i++)
      {
        m_y->m_var_init[i] = *(m_x[i]);
        m_y->m_varDot_init[i] = *(m_xdot[i]);
      }
      for (i = 0; i < m_nrpar; i++) m_realParameters[i] = *(m_rpar[i]);
      for (i = 0; i < m_nipar; i++) m_integerParameters[i] = *(m_ipar[i]);
    }
  }


  // cleanup

  DESTROY_VECTOR(pEsos)
  for (i = 0; i < nTransitions; i++) 
    if (TransEventIds[i]) ::SysFreeString(TransEventIds[i]);

  DESTROY_VECTOR(TransEventIds)
  DESTROY_VECTOR(SrcStates)
  for (i = 0; i < nStates; i++)
    DESTROY_VECTOR(StateToEqnMap[i])

  DESTROY_VECTOR(StateToEqnMap)
  DESTROY_VECTOR(nStateEqns)

  for (i = 0; i < nTransitions; i++)
    DESTROY_VECTOR(TransToEqnMap[i])

  DESTROY_VECTOR(TransToEqnMap)
  DESTROY_VECTOR(nTransEqns)

  return hr;
}

STDMETHODIMP CIsDaeEsoCImpl::CompositeModelComplete()
{
  HRESULT hr;
  long i;
  long nEsos = 0;
  long nEqns = 0;

	hr = m_pEsoImpl->iInitialize();
  if (SUCCEEDED(hr))
  {
    // store this pointer on the Eso so it can be retrieved later if this is a member of a master node
    m_pEsoImpl->SetOnModel(static_cast<IIsDaeEso*> (this));
    m_pEsoImpl->GetNumEqns(&nEqns);
    m_pEsoImpl->GetVariableInfo(&m_x, &m_nx);
    m_pEsoImpl->GetDerivativeInfo(&m_xdot, &m_nx);
    m_pEsoImpl->GetADVariableInfo(&m_ad_x, &m_nad_x);
    m_pEsoImpl->GetADDerivativeInfo(&m_ad_xdot, &m_nad_x);
    m_pEsoImpl->GetOldVariableInfo(&m_oldx, &m_nx);
    m_pEsoImpl->GetOldVariableInfo(&m_oldxdot, &m_nx);
    m_pEsoImpl->GetRealParameterInfo(&m_rpar, &m_nrpar);
    m_pEsoImpl->GetIntegerParameterInfo(&m_ipar, &m_nipar);
    SetLocalSize(nEqns, m_nx, m_nrpar, m_nipar);

    for (i = 0; i < m_nx; i++)
    {
      m_y->m_var_init[i] = *(m_x[i]);
      m_y->m_varDot_init[i] = *(m_xdot[i]);
    }
    for (i = 0; i < m_nrpar; i++) m_realParameters[i] = *(m_rpar[i]);
    for (i = 0; i < m_nipar; i++) m_integerParameters[i] = *(m_ipar[i]);
  }

  return hr;
}

HRESULT CIsDaeEsoCImpl::iEvalStateCondition(bool* EqnState, double EventTime, long iActiveDisEqn, long iTransition, VARIANT_BOOL* bEvent)
{
  if (!m_pEsoImpl) return E_FAIL;

  long iDisEqn;
  double* x = new double[m_nVars];
  double* xdot = new double[m_nVars];

  iDerivInterpolateAll(EventTime, x, xdot);
  if (iActiveDisEqn >= 0)
    iDisEqn = m_EqnMap[m_ActiveEqns[iActiveDisEqn]].iEqn;
  else
    iDisEqn = -1;
  
  bool Event = false;
  HRESULT hr = m_pEsoImpl->EvalStateCondition(
    (const bool*) EqnState, 
    (const double*) x, 
    (const double*) xdot, 
    (const double) EventTime, 
    (const long) iDisEqn, 
    (const long) iTransition,
    &Event);

  *bEvent = Event ? VARIANT_TRUE : VARIANT_FALSE;

  DESTROY_VECTOR(x)
  DESTROY_VECTOR(xdot)

  return hr;
}

HRESULT CIsDaeEsoCImpl::iCIEvalStateCondition(
  bool* EqnState, 
  double EventTime, 
  long iActiveDisEqn, 
  long iTransition, 
  VARIANT_BOOL* bEvent,
  double* global_x,
  double* global_xdot)
{
  if (!m_pEsoImpl) return E_FAIL;

  long iDisEqn;
  double* x = new double[m_nVars];
  double* xdot = new double[m_nVars];
  long i;

  for (i = 0; i < m_nVars; i++)
  {
    x[i] = global_x[m_VarMap[i].iGlobalVar];
    xdot[i] = global_xdot[m_VarMap[i].iGlobalVar];
  }

  iDisEqn = m_EqnMap[m_ActiveEqns[iActiveDisEqn]].iEqn;
  
  bool Event = false;
  HRESULT hr = m_pEsoImpl->EvalStateCondition(
    (const bool*) EqnState, 
    (const double*) x, 
    (const double*) xdot, 
    (const double) EventTime, 
    (const long) iDisEqn, 
    (const long) iTransition,
    &Event);

  *bEvent = Event ? VARIANT_TRUE : VARIANT_FALSE;

  DESTROY_VECTOR(x)
  DESTROY_VECTOR(xdot)

  return hr;
}


HRESULT CIsDaeEsoCImpl::iGetLocalJacobianStruct(MatInfo& JacStruct)
{
  long i, j, k, l;
  if (!m_pEsoImpl) return E_FAIL;

  long nColIndices = 0;
  long* ColIndices = NULL; 
  long* cNZCols = NULL;
  CalcMethod* CalcMethod = NULL;

  HRESULT hr = m_pEsoImpl->GetJacobianStruct(&nColIndices, &ColIndices, &cNZCols, &CalcMethod);

  if (SUCCEEDED(hr))
  {
    if (nColIndices > 0)
    {
      // allow room for z entries for discontinuous functions
      JacStruct.SetCompactSize(m_nEqns, nColIndices + m_nEqns);
      JacStruct.m_nColIndices = 0;

      if (ColIndices && CalcMethod && cNZCols)
      {
        k = 0;
        l = 0;
        for (i = 0; i < m_nLocalEqns; i++)
        {
          JacStruct.m_spRowPage[i] = k;
          JacStruct.m_cNZCols[i] = 0;
          if (m_EqnMap[i].bDiscontinuous)
          {
            // add z entries
            JacStruct.m_cNZCols[i]++;
            JacStruct.m_ColIndices[k] = m_EqnMap[i].iDiscVar; 
            JacStruct.m_compact_data[k] = JCM_CONST;
            JacStruct.m_compact_value[k] = 1.0;
            JacStruct.m_bValueSet[i] = true;
            JacStruct.m_nColIndices++;
            k++;
          }
          for (j = 0; j < cNZCols[i]; j++)
          {
            JacStruct.m_ColIndices[k] = ColIndices[l];
            JacStruct.m_compact_data[k] = CalcMethod[l];
            JacStruct.m_compact_value[k] = 0.0;
            JacStruct.m_bValueSet[i] = false;
            JacStruct.m_cNZCols[i]++;
            JacStruct.m_nColIndices++;
            k++;
            l++;
          }
        }
      }

    }
  }
  return hr;
}

HRESULT CIsDaeEsoCImpl::iGetLocalMassStruct(MatInfo& MassStruct)
{
  long i, j, k;
  if (!m_pEsoImpl) return E_FAIL;

  long nColIndices = 0;
  long* ColIndices = NULL; 
  long* cNZCols = NULL;
  CalcMethod* CalcMethod = NULL;

  HRESULT hr = m_pEsoImpl->GetDiffJacobianStruct(&nColIndices, &ColIndices, &cNZCols, &CalcMethod);

  if (SUCCEEDED(hr))
  {
    if (nColIndices > 0)
    {
      MassStruct.SetCompactSize(m_nEqns, nColIndices);
      MassStruct.m_nColIndices = 0;

      if (ColIndices && CalcMethod && cNZCols)
      {
        k = 0;
        for (i = 0; i < m_nLocalEqns; i++)
        {
          MassStruct.m_spRowPage[i] = k;
          MassStruct.m_cNZCols[i] = 0;
          for (j = 0; j < cNZCols[i]; j++)
          {
            MassStruct.m_ColIndices[k] = ColIndices[k];
            MassStruct.m_compact_data[k] = CalcMethod[k];
            MassStruct.m_compact_value[k] = 0.0;
            MassStruct.m_bValueSet[k] = false;
            MassStruct.m_cNZCols[i]++;
            MassStruct.m_nColIndices++;
            k++;
          }
        }
      }

    }
  }
  return hr;
}

HRESULT CIsDaeEsoCImpl::iGetLocalResiduals(
	long* Indices,                // equation indices
  long cIndices,                // count of equation indices
	double t,                     // time
	double* y,                    // y variable values
	double* ydot,                 // dy/dt values
  double* residuals,            // equation residuals
	bool& validVal,               // result validation
	double* realParameters,       // real parameters
	long* integerParameters)      // integer parameters
{
  HRESULT hr = S_OK;

  long i, iMapEqn;
  long* iEqns = new long[cIndices];
  long* loc_indices = new long[cIndices];
  double* loc_res = new double[cIndices];
  long count = 0;

  for (i = 0; i < cIndices; i++)
  {
    residuals[i] = 0.0;
    loc_res[i] = 0.0;
    iMapEqn = m_ActiveEqns[Indices[i]];
    if (!m_EqnMap[iMapEqn].bUndefined)
    {
      iEqns[count] = m_EqnMap[iMapEqn].iEqn;
      loc_indices[count] = i;
      count++;
    }
  }

  for (i = 0; i < m_nx; i++)
  {
    *(m_x[i]) = y[i];
    *(m_xdot[i]) = ydot[i];
  }
  for (i = 0; i < m_nrpar; i++) *(m_rpar[i]) = realParameters[i];
  for (i = 0; i < m_nipar; i++) *(m_ipar[i]) = integerParameters[i];

  hr = m_pEsoImpl->GetResiduals(iEqns, count, t, loc_res);
  for (i = 0; i < count; i++) residuals[loc_indices[i]] = loc_res[i];

  if (SUCCEEDED(hr))
  {
    // correct the residuals for the discontinuous functions
    // rp = g(), but r = z - g() ==> r = z - rp
    for (i = 0; i < cIndices; i++)
    {
      iMapEqn = m_ActiveEqns[Indices[i]];
      if (m_EqnMap[iMapEqn].bDiscontinuous)
        residuals[i] = y[m_itActiveVars[m_EqnMap[iMapEqn].iDiscVar]] - residuals[i];
    }
  } 

  DESTROY_VECTOR(iEqns)
  DESTROY_VECTOR(loc_indices)
  DESTROY_VECTOR(loc_res)

  return hr;
}

HRESULT CIsDaeEsoCImpl::iGetLocalJacobianValues(
  long* ActiveIndices,
  long cIndices,
  MatInfo& JacStruct,
  double t, 
  double* y, 
  double* ydot,
  double* JacVals, 
  double* rPar, 
  long* iPar,
  bool bIncludeConst)
{
  HRESULT hr = S_OK;

  long i, j, k;
  long iActiveEqn, iMapEqn, iDaeEqn, iActiveVar, iVar, iDaeVar; 
  long cmap;
  Jac_Calc_Method cm;
  long count = 0;
  bool bFound;

  long* indices = new long[cIndices*2];
  long* dae_indices = new long[cIndices*2];
  long* iActive = new long[cIndices*2];
  double* localJacVals = new double[cIndices];
  long* map = NULL;
  long* itmap = NULL;
  double* local_y = NULL;
  double* local_ydot = NULL;


  long nVars = 0;
  long nRPars = 0;
  long nIPars = 0;
  Fdouble** ad_x = NULL;
  Fdouble** ad_xdot = NULL;
  double** rpar = NULL;
  long** ipar = NULL;

  cmap = 0;
  if (m_nDiscontinuousEqns > 0)
  {
    map = new long[m_nVars];
    itmap = new long[m_nVars];
    for (i = 0; i < m_nVars; i++) if (!m_VarMap[i].bDiscontinuous) map[cmap++] = i;
    TransposeVector(map, cmap, itmap, m_nVars);
    local_y = new double[cmap];
    local_ydot = new double[cmap];
    for (i = 0; i < cmap; i++)
    {
      local_y[i] = y[map[i]];
      local_ydot[i] = ydot[map[i]];
    }
  }

  if (JacStruct.m_cNZCols)
  {
    for (i = 0; i < cIndices && SUCCEEDED(hr); i++) 
    {
      iActiveEqn = ActiveIndices[2*i];
      iMapEqn = m_ActiveEqns[iActiveEqn];
      iDaeEqn = m_EqnMap[iMapEqn].iEqn;
      iActiveVar = ActiveIndices[2*i+1];
      iVar = m_ActiveVars[iActiveVar];

      if (m_EqnMap[iMapEqn].iDiscVar == iVar)
      {
        JacVals[i] = 1.0;
      }
      else
      {
        bFound = false;
        for (j = 0; j < JacStruct.m_cNZCols[iMapEqn]; j++)
        {
          k = JacStruct.m_spRowPage[iMapEqn]+j;
          if (JacStruct.m_ColIndices[k] == iVar)
          {
            cm = (Jac_Calc_Method) JacStruct.m_compact_data[k];
            if (cm == JCM_CONST)
            {
              JacVals[i] = JacStruct.m_compact_value[k];
              //if (m_EqnMap[iEqn].bDiscontinuous) JacVals[i] *= -1.0;
            }
            else
              bFound = true;

            break;
          }
        }

        if (bFound)
        {
          if (cm == JCM_NUM)
          {
            hr = numericJacobian(iActiveEqn, iVar, t, y, ydot, rPar, iPar, JacVals[i]);
            if (m_EqnMap[iMapEqn].bDiscontinuous) JacVals[i] *= -1.0;
          }
          else if (cm == JCM_SYM || cm == JCM_AD)
          {
            if (m_nDiscontinuousEqns > 0)
            {
              iDaeVar = itmap[iVar]; 
              if (iDaeVar >= 0)
              {
                indices[2*count] = iMapEqn;
                indices[2*count+1] = iVar;
                dae_indices[2*count] = iDaeEqn;
                dae_indices[2*count+1] = iDaeVar;
                iActive[count] = i;
                count++;
              }
              else
              {
                JacVals[i] = 0.0;
              }
            }
            else
            {
              iDaeVar = iVar;
              indices[2*count] = iMapEqn;
              indices[2*count+1] = iVar;
              dae_indices[2*count] = iDaeEqn;
              dae_indices[2*count+1] = iDaeVar;
              iActive[count] = i;
              count++;
            }
          }
        }
        else if (cm != JCM_CONST)
        {
          _ASSERTE(0);
        }
      }
    }

    if (count > 0)
    {
      if (m_nDiscontinuousEqns > 0)
      {
        // TODO: make this more efficient
        m_pEsoImpl->GetADVariableInfo(&ad_x, &nVars);
        m_pEsoImpl->GetADDerivativeInfo(&ad_xdot, &nVars);
        m_pEsoImpl->GetRealParameterInfo(&rpar, &nRPars);
        m_pEsoImpl->GetIntegerParameterInfo(&ipar, &nIPars);
        for (k = 0; k < nVars; k++) 
        {
          ad_x[k]->v = local_y[k];
          ad_xdot[k]->v = local_ydot[k];
        }
        for (k = 0; k < nRPars; k++) *(rpar[k]) = rPar[k];
        for (k = 0; k < nIPars; k++) *(ipar[k]) = iPar[k];
        hr = m_pEsoImpl->GetJacobianValues(dae_indices, count, t, localJacVals);
      }
      else
      {
        // TODO: make this more efficient
        m_pEsoImpl->GetADVariableInfo(&ad_x, &nVars);
        m_pEsoImpl->GetADDerivativeInfo(&ad_xdot, &nVars);
        m_pEsoImpl->GetRealParameterInfo(&rpar, &nRPars);
        m_pEsoImpl->GetIntegerParameterInfo(&ipar, &nIPars);
        for (k = 0; k < nVars; k++) 
        {
          ad_x[k]->v = y[k];
          ad_xdot[k]->v = ydot[k];
        }
        for (k = 0; k < nRPars; k++) *(rpar[k]) = rPar[k];
        for (k = 0; k < nIPars; k++) *(ipar[k]) = iPar[k];
        hr = m_pEsoImpl->GetJacobianValues(dae_indices, count, t, localJacVals);
      }

      for (i = 0; i < count; i++) JacVals[iActive[i]] = localJacVals[i];
    }
  }
  else
  {
    // jacobian structure is has not yet been evaluated.
    count = 0;
    for (i = 0; i < cIndices; i++)
    {
      iActiveEqn = ActiveIndices[2*i];
      iMapEqn = m_ActiveEqns[iActiveEqn];
      iDaeEqn = m_EqnMap[iMapEqn].iEqn;
      iActiveVar = ActiveIndices[2*i+1];
      iVar = m_ActiveVars[iActiveVar];
      if (m_nDiscontinuousEqns > 0)
      {
        iDaeVar = itmap[iVar];
        if (iDaeVar >= 0)
        {
          indices[2*count] = iMapEqn;
          indices[2*count+1] = iVar;
          dae_indices[2*count] = iDaeEqn;
          dae_indices[2*count+1] = iDaeVar;
          iActive[count] = i;
          count++;
        }
        else
        {
          JacVals[i] = 0.0;
        }
      }
      else
      {
        iDaeVar = iVar;
        indices[2*count] = iMapEqn;
        indices[2*count+1] = iVar;
        dae_indices[2*count] = iDaeEqn;
        dae_indices[2*count+1] = iDaeVar;
        iActive[count] = i;
        count++;
      }
    }

    if (m_nDiscontinuousEqns > 0)
    {
      // TODO: make this more efficient
      m_pEsoImpl->GetADVariableInfo(&ad_x, &nVars);
      m_pEsoImpl->GetADDerivativeInfo(&ad_xdot, &nVars);
      m_pEsoImpl->GetRealParameterInfo(&rpar, &nRPars);
      m_pEsoImpl->GetIntegerParameterInfo(&ipar, &nIPars);
      for (k = 0; k < nVars; k++) 
      {
        ad_x[k]->v = local_y[k];
        ad_xdot[k]->v = local_ydot[k];
      }
      for (k = 0; k < nRPars; k++) *(rpar[k]) = rPar[k];
      for (k = 0; k < nIPars; k++) *(ipar[k]) = iPar[k];
      hr = m_pEsoImpl->GetJacobianValues(dae_indices, count, t, localJacVals);
    }
    else
    {
      // TODO: make this more efficient
      m_pEsoImpl->GetADVariableInfo(&ad_x, &nVars);
      m_pEsoImpl->GetADDerivativeInfo(&ad_xdot, &nVars);
      m_pEsoImpl->GetRealParameterInfo(&rpar, &nRPars);
      m_pEsoImpl->GetIntegerParameterInfo(&ipar, &nIPars);
      for (k = 0; k < nVars; k++) 
      {
        ad_x[k]->v = y[k];
        ad_xdot[k]->v = ydot[k];
      }
      for (k = 0; k < nRPars; k++) *(rpar[k]) = rPar[k];
      for (k = 0; k < nIPars; k++) *(ipar[k]) = iPar[k];
      hr = m_pEsoImpl->GetJacobianValues(dae_indices, count, t, localJacVals);
    }

    for (i = 0; i < count; i++) JacVals[iActive[i]] = localJacVals[i];

    for (i = 0; i < cIndices; i++)
    {
      iActiveEqn = ActiveIndices[2*i];
      iMapEqn = m_ActiveEqns[iActiveEqn];
      iActiveVar = ActiveIndices[2*i+1];
      iVar = m_ActiveVars[iActiveVar];

      if (m_EqnMap[iMapEqn].iDiscVar == iVar)
      {
        JacVals[i] = 1.0;
      }
    }
  }

  if (SUCCEEDED(hr))
  {
    for (i = 0; i < count; i++)
    {
      iMapEqn = indices[2*i];
      if (m_EqnMap[iMapEqn].bDiscontinuous) JacVals[iActive[i]] *= -1.0;
    }
  }

  DESTROY_VECTOR(indices)
  DESTROY_VECTOR(dae_indices)
  DESTROY_VECTOR(iActive)
  DESTROY_VECTOR(localJacVals)
  DESTROY_VECTOR(map)
  DESTROY_VECTOR(itmap)
  DESTROY_VECTOR(local_y)
  DESTROY_VECTOR(local_ydot)

  return hr;
}

HRESULT CIsDaeEsoCImpl::iGetLocalMassValues(
  long* ActiveIndices,
  long cIndices,
  MatInfo& JacStruct,
  double t, 
  double* y, 
  double* ydot,
  double* JacVals, 
  double* rPar, 
  long* iPar,
  bool bIncludeConst)
{
  HRESULT hr = S_OK;

  long i, j, k;
  long iActiveEqn, iMapEqn, iDaeEqn, iActiveVar, iVar, iDaeVar; 
  long cmap;
  Jac_Calc_Method cm;
  long count = 0;
  bool bFound;

  long* indices = new long[cIndices*2];
  long* dae_indices = new long[cIndices*2];
  long* iActive = new long[cIndices*2];
  double* localJacVals = new double[cIndices];
  long* map = NULL;
  long* itmap = NULL;
  double* local_y = NULL;
  double* local_ydot = NULL;

  Fdouble** ad_x = NULL;
  Fdouble** ad_xdot = NULL;
  double** rpar = NULL;
  long** ipar = NULL;
  long nVars;
  long nRPars;
  long nIPars;

  cmap = 0;
  if (m_nDiscontinuousEqns > 0)
  {
    map = new long[m_nVars];
    itmap = new long[m_nVars];
    for (i = 0; i < m_nVars; i++) if (!m_VarMap[i].bDiscontinuous) map[cmap++] = i;
    TransposeVector(map, cmap, itmap, m_nVars);
    local_y = new double[cmap];
    local_ydot = new double[cmap];
    for (i = 0; i < cmap; i++)
    {
      local_y[i] = y[map[i]];
      local_ydot[i] = ydot[map[i]];
    }
  }

  if (JacStruct.m_cNZCols)
  {
    for (i = 0; i < cIndices && SUCCEEDED(hr); i++) 
    {
      iActiveEqn = ActiveIndices[2*i];
      iMapEqn = m_ActiveEqns[iActiveEqn];
      iDaeEqn = m_EqnMap[iMapEqn].iEqn;
      iActiveVar = ActiveIndices[2*i+1];
      iVar = m_ActiveVars[iActiveVar];

      bFound = false;
      for (j = 0; j < JacStruct.m_cNZCols[iMapEqn]; j++)
      {
        k = JacStruct.m_spRowPage[iMapEqn]+j;
        if (JacStruct.m_ColIndices[k] == iVar)
        {
          cm = (Jac_Calc_Method) JacStruct.m_compact_data[k];
          if (cm == JCM_CONST)
          {
            JacVals[i] = JacStruct.m_compact_value[k];
          }
          else
            bFound = true;

          break;
        }
      }

      if (bFound)
      {
        if (cm == JCM_NUM)
        {
          hr = numericDiffJacobian(iActiveEqn, iVar, t, y, ydot, rPar, iPar, JacVals[i]);
        }
        else if (cm == JCM_SYM || cm == JCM_AD)
        {
          if (m_nDiscontinuousEqns > 0)
          {
            iDaeVar = itmap[iVar]; 
            if (iDaeVar >= 0)
            {
              indices[2*count] = iMapEqn;
              indices[2*count+1] = iVar;
              dae_indices[2*count] = iDaeEqn;
              dae_indices[2*count+1] = iDaeVar;
              iActive[count] = i;
              count++;
            }
            else
            {
              JacVals[i] = 0.0;
            }
          }
          else
          {
            iDaeVar = iVar;
            indices[2*count] = iMapEqn;
            indices[2*count+1] = iVar;
            dae_indices[2*count] = iDaeEqn;
            dae_indices[2*count+1] = iDaeVar;
            iActive[count] = i;
            count++;
          }
        }
      }
      else if (cm != JCM_CONST)
      {
        //_ASSERTE(0);
      }
    }

    if (count > 0)
    {
      if (m_nDiscontinuousEqns > 0)
      {
        // TODO: make this more efficient
        m_pEsoImpl->GetADVariableInfo(&ad_x, &nVars);
        m_pEsoImpl->GetADDerivativeInfo(&ad_xdot, &nVars);
        m_pEsoImpl->GetRealParameterInfo(&rpar, &nRPars);
        m_pEsoImpl->GetIntegerParameterInfo(&ipar, &nIPars);
        for (k = 0; k < nVars; k++) 
        {
          ad_x[k]->v = local_y[k];
          ad_xdot[k]->v = local_ydot[k];
        }
        for (k = 0; k < nRPars; k++) *(rpar[k]) = rPar[k];
        for (k = 0; k < nIPars; k++) *(ipar[k]) = iPar[k];
        hr = m_pEsoImpl->GetDiffJacobianValues(dae_indices, count, t, localJacVals);
      }
      else
      {
        // TODO: make this more efficient
        m_pEsoImpl->GetADVariableInfo(&ad_x, &nVars);
        m_pEsoImpl->GetADDerivativeInfo(&ad_xdot, &nVars);
        m_pEsoImpl->GetRealParameterInfo(&rpar, &nRPars);
        m_pEsoImpl->GetIntegerParameterInfo(&ipar, &nIPars);
        for (k = 0; k < nVars; k++) 
        {
          ad_x[k]->v = y[k];
          ad_xdot[k]->v = ydot[k];
        }
        for (k = 0; k < nRPars; k++) *(rpar[k]) = rPar[k];
        for (k = 0; k < nIPars; k++) *(ipar[k]) = iPar[k];
        hr = m_pEsoImpl->GetDiffJacobianValues(dae_indices, count, t, localJacVals);
      }

      for (i = 0; i < count; i++) JacVals[iActive[i]] = localJacVals[i];
    }
  }
  else
  {
    // Mass structure is has not yet been evaluated.
    count = 0;
    for (i = 0; i < cIndices; i++)
    {
      iActiveEqn = ActiveIndices[2*i];
      iMapEqn = m_ActiveEqns[iActiveEqn];
      iDaeEqn = m_EqnMap[iMapEqn].iEqn;
      iActiveVar = ActiveIndices[2*i+1];
      iVar = m_ActiveVars[iActiveVar];
      if (m_nDiscontinuousEqns > 0)
      {
        iDaeVar = itmap[iVar];
        if (iDaeVar >= 0)
        {
          indices[2*count] = iMapEqn;
          indices[2*count+1] = iVar;
          dae_indices[2*count] = iDaeEqn;
          dae_indices[2*count+1] = iDaeVar;
          iActive[count] = i;
          count++;
        }
        else
        {
          JacVals[i] = 0.0;
        }
      }
      else
      {
        iDaeVar = iVar;
        indices[2*count] = iMapEqn;
        indices[2*count+1] = iVar;
        dae_indices[2*count] = iDaeEqn;
        dae_indices[2*count+1] = iDaeVar;
        iActive[count] = i;
        count++;
      }
    }

    if (m_nDiscontinuousEqns > 0)
    {
      // TODO: make this more efficient
      m_pEsoImpl->GetADVariableInfo(&ad_x, &nVars);
      m_pEsoImpl->GetADDerivativeInfo(&ad_xdot, &nVars);
      m_pEsoImpl->GetRealParameterInfo(&rpar, &nRPars);
      m_pEsoImpl->GetIntegerParameterInfo(&ipar, &nIPars);
      for (k = 0; k < nVars; k++) 
      {
        ad_x[k]->v = local_y[k];
        ad_xdot[k]->v = local_ydot[k];
      }
      for (k = 0; k < nRPars; k++) *(rpar[k]) = rPar[k];
      for (k = 0; k < nIPars; k++) *(ipar[k]) = iPar[k];
      hr = m_pEsoImpl->GetDiffJacobianValues(dae_indices, count, t, localJacVals);
    }
    else
    {
      // TODO: make this more efficient
      m_pEsoImpl->GetADVariableInfo(&ad_x, &nVars);
      m_pEsoImpl->GetADDerivativeInfo(&ad_xdot, &nVars);
      m_pEsoImpl->GetRealParameterInfo(&rpar, &nRPars);
      m_pEsoImpl->GetIntegerParameterInfo(&ipar, &nIPars);
      for (k = 0; k < nVars; k++) 
      {
        ad_x[k]->v = y[k];
        ad_xdot[k]->v = ydot[k];
      }
      for (k = 0; k < nRPars; k++) *(rpar[k]) = rPar[k];
      for (k = 0; k < nIPars; k++) *(ipar[k]) = iPar[k];
      hr = m_pEsoImpl->GetDiffJacobianValues(dae_indices, count, t, localJacVals);
    }

    for (i = 0; i < count; i++) JacVals[iActive[i]] = localJacVals[i];
  }

  DESTROY_VECTOR(indices)
  DESTROY_VECTOR(dae_indices)
  DESTROY_VECTOR(iActive)
  DESTROY_VECTOR(localJacVals)
  DESTROY_VECTOR(map)
  DESTROY_VECTOR(itmap)
  DESTROY_VECTOR(local_y)
  DESTROY_VECTOR(local_ydot)

  return hr;
}

HRESULT CIsDaeEsoCImpl::iGetEquationForm(EqnForm*& iEqnForm, EqnDiffForm*& iEqnDiffForm)
{
  long i;

  if (!m_pEsoImpl) return E_FAIL;

  iEqnForm = new EqnForm[m_nEqns];
  iEqnDiffForm = new EqnDiffForm[m_nEqns];

  for (i = 0; i < m_nEqns; i++) 
  {
    iEqnForm[i] = EqnForm_Continuous;
    iEqnDiffForm[i] = EqnDiffForm_Numeric;
  }

  HRESULT hr = m_pEsoImpl->GetEquationForm( (OnEqnForm**) &iEqnForm, (OnEqnDiffForm**) &iEqnDiffForm);

  return hr;
}

HRESULT CIsDaeEsoCImpl::TriggerEvent(double EventTime, BSTR EventId, long iEventEqn)
{
  if (!m_pEsoImpl) return E_FAIL;

  m_EventTime = EventTime;
  m_EventId = EventId;
  m_EventEqn = iEventEqn;

  double** x = NULL;
  double** xdot = NULL;
  long nVars;
  long i;

  m_pEsoImpl->GetOldVariableInfo(&x, &nVars); 
  m_pEsoImpl->GetOldDerivativeInfo(&xdot, &nVars); 
  for (i = 0; i < nVars; i++)
  {
    *(x[i]) = m_y->m_varVal[i];
    *(xdot[i]) = m_y->m_varDotVal[i];
  }
  HRESULT hr = m_pEsoImpl->TriggerEvent(EventTime, EventId);

  m_EventTime = 0.0;
  m_EventId = NULL;
  m_EventEqn = -1;

  return hr;
}


STDMETHODIMP CIsDaeEsoCImpl::PostTransition(long iNewState)
{
  HRESULT hr = E_FAIL;

  if (m_pModelExec)
  {
    hr = m_pModelExec->OnTransition(m_EventTime, m_EventEqn, m_EventId, iNewState, static_cast<IIsDaeEso*> (this));
  }

  return hr;
}

STDMETHODIMP CIsDaeEsoCImpl::PostStateEvent(double t, BSTR EventId)
{
  HRESULT hr = E_FAIL;

  if (m_pModelExec)
  {
    hr = m_pModelExec->PostStateEvent(t, EventId, -1, static_cast<IIsDaeEso*> (this));
  }

  return hr;
}


bool CIsDaeEsoCImpl::Load(FILE* fs)
{
  const long m_schema = 1;
  const long m_classId = 1007;

  long classId;
  long schema;
  bool bRet = false;

  READ_SCALAR( classId )
  if (classId != m_classId) { _ASSERTE(0); return false; }

  READ_SCALAR( schema )

  switch (schema)
  {
  case 1:
    if (! CIsDaeEsoBase::Load(fs) ) { _ASSERTE(0); return false; }
    if (!m_pEsoImpl) { _ASSERTE(0); return false; }
    bRet = m_pEsoImpl->Load(fs);
    break;
  }

  return bRet;
}

void CIsDaeEsoCImpl::Save(FILE* fs)
{
  const long m_schema = 1;
  const long m_classId = 1007;

  WRITE_SCALAR( m_classId )
  WRITE_SCALAR( m_schema )

  CIsDaeEsoBase::Save(fs);
  if (m_pEsoImpl)
    m_pEsoImpl->Save(fs);
}

STDMETHODIMP CIsDaeEsoCImpl::Connect(SAFEARRAY** ConnA, SAFEARRAY** ConnB)
{
  if (m_pEsoImpl)
    return m_pEsoImpl->Connect(ConnA, ConnB);
  else
    return E_FAIL;
}
