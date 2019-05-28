// COnUMLDaeEsoBase.cpp: implementation of the COnUMLDaeEsoBase class.
//
//////////////////////////////////////////////////////////////////////


#include "stdafx.h"
#include "OnUMLEso.h"
#include "OnUMLEsoMacros.h"
#include "OnUMLDaeEsoBase.h"
#include "OnUMLAssociation.h"
#include "OnUMLConstants_i.c"
#include "OnUMLLink.h"
#include "OnUMLAssociation.h"
#include "OnAD.h"

#include "CommonTools.h"
#include "IOnUMLDaeEsoBase.h"
#include "StateInfo.h"
#include "TransitionInfo.h"
#include "OnMapBSTR.h"
#include "Triangularization.h"

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

COnUMLDaeEsoBase::COnUMLDaeEsoBase()
{

  m_pOnEnv = NULL;
  m_pOnModel = NULL;
  m_cRef = 0;

  m_time = 0.0;

  m_ad_x_color = NULL;
  m_LocalRPars = NULL;
  m_LocalIPars = NULL;

  m_nLocalEqns = 0;
  m_dLocalEqns = 0;
  m_nLocalADEqns = 0;
  m_dLocalADEqns = 0;

  m_nLocalDistEqns = 0;
  m_dLocalDistEqns = 0;
  m_nLocalDistADEqns = 0;
  m_dLocalDistADEqns = 0;

  m_LocalDistEqnResCount = NULL;
  m_LocalDistEqnColor = NULL;
  m_LocalDistEqnVars = NULL;
  m_LocalDistADEqnVars = NULL;

  m_nLocalStlEqns = 0;
  m_dLocalStlEqns = 0;
  m_nLocalStlADEqns = 0;
  m_dLocalStlADEqns = 0;

  m_LocalStlEqnResCount = NULL;
  m_LocalStlEqnColor = NULL;
  m_LocalStlEqnVars = NULL;
  m_LocalStlADEqnVars = NULL;

  m_nLocalRPars = 0;
  m_dLocalRPars = 0;
  m_nLocalIPars = 0;
  m_dLocalIPars = 0;

  // equation, variable, and parameter name maps (for humane user-interface)
  m_EqnNames = NULL;
  m_DistEqnNames = NULL;
  m_StlEqnNames = NULL;
  m_RParNames = NULL;
  m_IParNames = NULL;

  // equation format
  m_EqnForm = NULL;
  m_EqnDiffForm = NULL;

  // connection point / event interface 
  m_EventCPs = NULL;
  m_EventSinks = NULL;
  m_EventSinkSize = NULL;
  m_EventSinkDim = 0;

  // Composite Eso mapping
  m_Associations = NULL;
  m_nAssociations = 0;
  m_dAssociations = 0;

  //m_bEsosInitialized = false;
  m_EsoNames = NULL;
  m_Esos = NULL;
  m_nEsos = 0;
  m_dEsos = 0;

  m_bEsosByRef = false;
  m_bMasterNode = false;

  m_States = NULL;
  m_nStates = 0;
  m_dStates = 0;
  m_DefaultState = -1;

  m_Transitions = NULL;
  m_nTransitions = 0;
  m_dTransitions = 0;

  //m_TypeGUID;
  ::CoCreateGuid(&m_GUID);
  m_GlobalIndex = -1;

#if 0
  _verbose_print = false;
#endif

}



COnUMLDaeEsoBase::~COnUMLDaeEsoBase()
{
  long i;
  
  if (m_pOnEnv)
  {
    m_pOnEnv->Release();
    m_pOnEnv = NULL;
  }

  DESTROY_BSTR_ARRAY(m_EqnNames, m_nLocalEqns)
  DESTROY_BSTR_ARRAY(m_DistEqnNames, m_nLocalDistEqns)
  DESTROY_BSTR_ARRAY(m_StlEqnNames, m_nLocalStlEqns)
  DESTROY_BSTR_ARRAY(m_RParNames, m_nLocalRPars)
  DESTROY_BSTR_ARRAY(m_IParNames, m_nLocalIPars)
  DESTROY_BSTR_ARRAY(m_EsoNames, m_nEsos)

  DESTROY_VECTOR(m_ad_x_color)
  DESTROY_VECTOR(m_LocalRPars)
  DESTROY_VECTOR(m_LocalIPars)

  DESTROY_VECTOR(m_EqnForm)
  DESTROY_VECTOR(m_EqnDiffForm)

  DESTROY_VECTOR(m_LocalDistEqnResCount)
  DESTROY_VECTOR(m_LocalDistEqnColor)
  DESTROY_VECTOR(m_LocalDistEqnVars)
  DESTROY_VECTOR(m_LocalDistADEqnVars)

  DESTROY_VECTOR(m_LocalStlEqnResCount)
  DESTROY_VECTOR(m_LocalStlEqnColor)
  DESTROY_VECTOR(m_LocalStlEqnVars)
  DESTROY_VECTOR(m_LocalStlADEqnVars)

  if (m_Associations)
  {
    for (i = 0; i < m_nAssociations; i++) DESTROY_MEMBER(m_Associations[i])
    DESTROY_VECTOR(m_Associations)
  }

  if (m_Esos)
  {
    for (i = 0; i < m_nEsos; i++) 
    {
      if (m_Esos[i])
      {
        m_Esos[i]->Release();
        m_Esos[i] = NULL;
      }
    }
    DESTROY_VECTOR(m_Esos)
  }

  if (m_States)
  {
    for (i = 0; i < m_nStates; i++) DESTROY_MEMBER(m_States[i])
    DESTROY_VECTOR(m_States)
  }

  if (m_Transitions)
  {
    for (i = 0; i < m_nTransitions; i++) DESTROY_MEMBER(m_Transitions[i])
    DESTROY_VECTOR(m_Transitions)
  }

  DESTROY_BSTR_ARRAY(m_EventCPs, m_EventSinkDim)
  if (m_EventSinks)
  {
    // TODO: should the event sink interface support reference counting
    // for (i = 0; i < m_nEventSinks; i++) if (m_EventSinks[i]) m_EventSinks[i]->Release();
    DESTROY_VECTOR(m_EventSinks)
  }


}

ULONG COnUMLDaeEsoBase::AddRef()
{
#if 1
  if (m_cRef == 0)
    ATLTRACE("\nAddRef %d", m_cRef+1);
#endif

  return ++m_cRef;

}

ULONG COnUMLDaeEsoBase::Release()
{
#if 1
  if (m_cRef == 1)
    ATLTRACE("\nRelease %d", m_cRef-1);
#endif

  ULONG l = --m_cRef;
  if (m_cRef <= 0) 
    delete this;

  return l;
}

HRESULT COnUMLDaeEsoBase::QueryInterface(REFIID riid, void ** ppv)
{
  HRESULT hr = S_OK;

  if (IsEqualIID(riid, IID_IUnknown) || IsEqualIID (riid, IID_IOnUMLDaeEsoBase))
  {
    *ppv = static_cast<IOnUMLDaeEsoBase*> (this);
    AddRef();
  }
  else
  {
    *ppv = 0;
    hr = E_NOINTERFACE;
  }    
  return hr;
}

HRESULT COnUMLDaeEsoBase::GetCppPtr(DWORD* ppModel)
{
  *ppModel = reinterpret_cast<DWORD> (this);
  return S_OK;
}

HRESULT COnUMLDaeEsoBase::AddEso(IUnknown* pUnk, BSTR modelName)
{
  HRESULT hr;
  IOnUMLDaeEsoBase* pIEso = NULL;
  COnUMLDaeEsoBase* pEso = NULL;

  hr = pUnk->QueryInterface(IID_IOnUMLDaeEsoBase, reinterpret_cast<void**> (&pIEso) );
  if (SUCCEEDED(hr))
  {
    hr = pIEso->GetCppPtr(reinterpret_cast<DWORD*> (&pEso) );
    if (SUCCEEDED(hr))
    {
      hr = AddMemberEso(pEso, modelName);
    }
    pIEso->Release();
  }
  return hr;
}

HRESULT COnUMLDaeEsoBase::GetMemberEsos(long* nEsos, IOnUMLDaeEsoBase*** pEsos)
{
  long i;

  *nEsos = m_nEsos;
  if (m_nEsos > 0)
  {
    if (*pEsos == NULL) *pEsos = new IOnUMLDaeEsoBase*[m_nEsos];
    for (i = 0; i < m_nEsos; i++) 
    {
      (*pEsos)[i] = m_Esos[i];
      m_Esos[i]->AddRef();
    }
  }
  return S_OK;
}


HRESULT COnUMLDaeEsoBase::GetNumByRefEsos(long& nEsos)
{
  long i;

  if (m_bEsosByRef) nEsos++;
  for (i = 0; i < m_nEsos; i++) 
    m_Esos[i]->GetNumByRefEsos(nEsos);

  return S_OK;
}

HRESULT COnUMLDaeEsoBase::GetAllByRefEsos(long& nEsos, COnUMLDaeEsoBase**& pEsos)
{
  long i;

  if (m_bEsosByRef) 
    pEsos[nEsos++] = this;

  for (i = 0; i < m_nEsos; i++) 
    m_Esos[i]->GetAllByRefEsos(nEsos, pEsos);

  return S_OK;
}

HRESULT COnUMLDaeEsoBase::GetAllAssociations(long& nLinks, long& dLinks, COnUMLLink**& Links)
{
  long i;
  GUID Id;

  size_ptr_array(50, nLinks, dLinks, Links, m_nAssociations);

  for (i = 0; i < m_nAssociations; i++)
  {
    Links[nLinks] = new COnUMLLink();
    GetId(m_Associations[i]->FromIds, m_Associations[i]->nFromIds, &Id);
    Links[nLinks]->setFromId(Id);
    GetId(m_Associations[i]->ToIds, m_Associations[i]->nToIds, &Id);
    Links[nLinks]->setToId(Id);
    nLinks++;
  }

  for (i = 0; i < m_nEsos; i++) 
  {
    m_Esos[i]->GetAllAssociations(nLinks, dLinks, Links);
  }

  return S_OK;
}

HRESULT COnUMLDaeEsoBase::GetAssociationBlocks(long& cBlocks, long*& spBlocks, long*& cNZBlocks, COnUMLDaeEsoBase**& pRetEsos)
{
  long nEsos;
  long i, j, k, l;
  COnUMLDaeEsoBase** pEsos = NULL;
  long nLinks = 0;
  long dLinks = 0;
  COnUMLLink** Links = NULL;
  LPOLESTR szGUID = new TCHAR[39];
  long* ColIndices = NULL;
	long nColIndices = 0;
	long* spRowPage = NULL;
	long* cNZRow = NULL;
  long* tr_ColIndices = NULL;
	long tr_nColIndices = 0;
	long* tr_spRowPage = NULL;
	long* tr_cNZRow = NULL;
  long* blockSizes = NULL;
  long* orderMap = NULL;

  COnMapBSTR map;

  nEsos = 0;
  cBlocks = 0;
  GetNumByRefEsos(nEsos);
  if (nEsos > 0)
  {
    pEsos = new COnUMLDaeEsoBase*[nEsos];
    nEsos = 0;
    GetAllByRefEsos(nEsos, pEsos);
    map.InitHashTable(nEsos*2);
    for (i = 0; i < nEsos; i++)
    {
      ::StringFromGUID2(pEsos[i]->m_GUID, szGUID, 39);
      map.SetAt(::SysAllocString(szGUID), (DWORD) i);
    }

    nLinks = 0;
    dLinks = nEsos;
    Links = new COnUMLLink*[nEsos];
    for (i = 0; i < nEsos; i++) Links[i] = NULL;
    GetAllAssociations(nLinks, dLinks, Links);

    ColIndices = new long[nLinks*2];
    nColIndices = nLinks*2;
    spRowPage = new long[nLinks];
    cNZRow = new long[nLinks];

    for (i = 0; i < nLinks; i++)
    {
      ::StringFromGUID2(Links[i]->FromId, szGUID, 39);
      if ( map.Lookup(szGUID, (DWORD&) ColIndices[2*i]) )
      {
        ::StringFromGUID2(Links[i]->ToId, szGUID, 39);
        if ( map.Lookup(szGUID, (DWORD&) ColIndices[2*i+1]) )
        {
          spRowPage[i] = 2*i;
          cNZRow[i] = 2;
        }
        else
        {
          _ASSERTE(0);   
        }
      }
      else
      {
        _ASSERTE(0);
      }
    }

  #if 0
    printMat(nLinks, nEsos, cNZRow, ColIndices);
  #endif

    tr_nColIndices = 2*nLinks + nEsos;
    tr_ColIndices = new long[tr_nColIndices];
    tr_cNZRow = new long[nEsos];
    tr_spRowPage = new long[nEsos];

    l = 0;
    for (i = 0; i < nEsos; i++)
    {
      tr_cNZRow[i] = 1;
      tr_spRowPage[i] = l;
      tr_ColIndices[l++] = i;
      for (j = 0; j < nLinks; j++)
      {
        for (k = 0; k < cNZRow[j]; k++)
        {
          if (ColIndices[spRowPage[j]+k] == i)
          {
            // take the other indices
            if (k == 0)
            {
              tr_ColIndices[l++] = ColIndices[spRowPage[j]+1];
            }
            else // k == 1
            {
              tr_ColIndices[l++] = ColIndices[spRowPage[j]];
            }
            tr_cNZRow[i]++;
          }
        }
      }
    }

  #if 0
    printMat(nEsos, nEsos, tr_cNZRow, tr_ColIndices);
  #endif

    // nLinks is the number of equations
    // normMapSize is the number of variables (connected connectors)
    blockSizes = new long[nEsos];
    orderMap = new long[nEsos];

    for (i = 0; i < nEsos; i++)
    {
      blockSizes[i] = 0;
      orderMap[i] = -1;
    }

    tarjan(nEsos, tr_ColIndices, tr_nColIndices, tr_spRowPage, tr_cNZRow, orderMap, cBlocks, blockSizes);
  }

  if (cBlocks > 0 && nEsos > 0)
  {
    pRetEsos = new COnUMLDaeEsoBase*[nEsos];
    spBlocks = new long[cBlocks];
    cNZBlocks = new long[cBlocks];
    k = 0;

    for (i = 0; i < cBlocks; i++)
    {
      spBlocks[i] = k;
      cNZBlocks[i] = 0;
      for (j = 0; j < blockSizes[i]; j++)
      {
        pRetEsos[k] = pEsos[orderMap[k]];
        cNZBlocks[i]++;
        k++;
      }
    }
  }


  // cleanup
  DESTROY_VECTOR(pEsos)
  for (i = 0; i < nLinks; i++) DESTROY_MEMBER(Links[i])
  DESTROY_VECTOR(Links)
  DESTROY_VECTOR(szGUID);
  DESTROY_VECTOR(ColIndices)
	DESTROY_VECTOR(spRowPage)
	DESTROY_VECTOR(cNZRow)
  DESTROY_VECTOR(tr_ColIndices)
	DESTROY_VECTOR(tr_spRowPage)
	DESTROY_VECTOR(tr_cNZRow)
  DESTROY_VECTOR(blockSizes)
  DESTROY_VECTOR(orderMap)

  return S_OK;
}

HRESULT COnUMLDaeEsoBase::GetOnModel(IIsDaeEso** ppModel)
{
  HRESULT hr = E_FAIL;

  if (m_pOnModel)
  {
    *ppModel = m_pOnModel;
    m_pOnModel->AddRef();
    hr = S_OK;
  }

  return hr;
}

HRESULT COnUMLDaeEsoBase::SetOnModel(IIsDaeEso* pModel)
{
  m_pOnModel = pModel;
  return S_OK;
}

HRESULT COnUMLDaeEsoBase::GetEquationForm(OnEqnForm** eqn_form, OnEqnDiffForm** eqn_diff_form)
{
  long iRes, iEqn, iDistEqn, iStlEqn;
  long nLocalEqns = m_nLocalEqns + m_nLocalDistEqns + m_nLocalStlEqns;
  long nTotalEqns;

  GetNumEqns(&nTotalEqns);

  if (nLocalEqns > 0)
  {
    if (*eqn_form == NULL) *eqn_form = new OnEqnForm[nTotalEqns];
    if (m_EqnForm)
    {
      for (iEqn = 0; iEqn < m_nLocalEqns; iEqn++) (*eqn_form)[iEqn] = m_EqnForm[iEqn];
      iEqn = m_nLocalEqns;
      // Assumption: Will not be mixing distributed equations with stl equations
      if (m_nLocalDistEqns > 0)
      {
        for (iDistEqn = 0; iDistEqn < m_nLocalDistEqns; iDistEqn++) 
        {
          for (iRes = 0; iRes < m_LocalDistEqnResCount[iDistEqn]; iRes++)
          {
            (*eqn_form)[iEqn] = m_EqnForm[iDistEqn];
            iEqn++;
          }
        }
      }
      else if (m_nLocalStlEqns > 0)
      {
        for (iStlEqn = 0; iStlEqn < m_nLocalStlEqns; iStlEqn++) 
        {
          for (iRes = 0; iRes < m_LocalStlEqnResCount[iStlEqn]; iRes++)
          {
            (*eqn_form)[iEqn] = m_EqnForm[iStlEqn];
            iEqn++;
          }
        }
      }
    }
    else
    {
      for (iEqn = 0; iEqn < nTotalEqns; iEqn++) (*eqn_form)[iEqn] = continuous;
    }

    if (*eqn_diff_form == NULL) *eqn_diff_form = new OnEqnDiffForm[nTotalEqns];
    if (m_EqnDiffForm)
    {
      for (iEqn = 0; iEqn < m_nLocalEqns; iEqn++) (*eqn_diff_form)[iEqn] = m_EqnDiffForm[iEqn];
      iEqn = m_nLocalEqns;
      // Assumption: Won't be mixing distrubted and stl equations
      if (m_nLocalDistEqns > 0)
      {
        for (iStlEqn = 0; iStlEqn < m_nLocalStlEqns; iStlEqn++) 
        {
          for (iRes = 0; iRes < m_LocalStlEqnResCount[iStlEqn]; iRes++)
          {
            (*eqn_diff_form)[iEqn] = m_EqnDiffForm[iStlEqn];
            iEqn++;
          }
        }
      }
      else if (m_nLocalStlEqns > 0)
      {
        for (iStlEqn = 0; iStlEqn < m_nLocalStlEqns; iStlEqn++) 
        {
          for (iRes = 0; iRes < m_LocalStlEqnResCount[iStlEqn]; iRes++)
          {
            (*eqn_diff_form)[iEqn] = m_EqnDiffForm[iStlEqn];
            iEqn++;
          }
        }
      }

    }
    else
    {
      for (iEqn = 0; iEqn < nTotalEqns; iEqn++) (*eqn_diff_form)[iEqn] = numeric;
    }

  }
  return S_OK;
}

HRESULT COnUMLDaeEsoBase::GetNumEqns(long* nEqns)
{
  long i;

  // the number of equations as far as the DAE solver is concerned is the number of residuals
  *nEqns = m_nLocalEqns;
  if (m_nLocalDistEqns > 0)
  {
    for (i = 0; i < m_nLocalDistEqns; i++)
      *nEqns += m_LocalDistEqnResCount[i];
  }
  else if (m_nLocalStlEqns > 0)
  {
    for (i = 0; i < m_nLocalStlEqns; i++)
      *nEqns += m_LocalStlEqnResCount[i];
  }

  return S_OK;
}

HRESULT COnUMLDaeEsoBase::GetNumVars(long* nVars)
{
  *nVars = m_varC.nVars;
  return S_OK;
}

HRESULT COnUMLDaeEsoBase::GetNumRPars(long* nRPars)
{
  *nRPars = m_nLocalRPars;
  return S_OK;
}

HRESULT COnUMLDaeEsoBase::GetNumIPars(long* nIPars)
{
  *nIPars = m_nLocalIPars;
  return S_OK;
}

HRESULT COnUMLDaeEsoBase::GetSTNStruct(
    long* nStates, 
    long* nTransitions, 
    long* iDefaultState, 
    BSTR** TransEventIds, 
    long** SrcStates, 
    long*** StateToEqnMap, 
    long** nStateEqns,
    long*** TransToEqnMap,
    long** nTransEqns)
{
  long i, j, k, iFcn, iEqn;
  HRESULT hr = S_OK;
  long* indices = NULL;
  long count = 0;
  long eqnCount = 0;
  long* spEqns = NULL;
  
  // determine the start point equation index for each equation function
  if (m_nStates > 0)
  {
    if (m_nLocalDistEqns > 0)
    {
      spEqns = new long[m_nLocalEqns + m_nLocalDistEqns];
      for (iFcn = 0; iFcn < m_nLocalEqns; iFcn++) spEqns[iFcn] = iFcn;
      eqnCount = m_nLocalEqns;
      for (iFcn = 0; iFcn < m_nLocalDistEqns; iFcn++) 
      {
        spEqns[iEqn++] = eqnCount;
        eqnCount += m_LocalDistEqnResCount[iFcn]; 
      }
    }
    else if (m_nLocalStlEqns > 0)
    {
      spEqns = new long[m_nLocalEqns + m_nLocalStlEqns];
      for (iFcn = 0; iFcn < m_nLocalEqns; iFcn++) spEqns[iFcn] = iFcn;
      eqnCount = m_nLocalEqns;
      for (iFcn = 0; iFcn < m_nLocalStlEqns; iFcn++) 
      {
        spEqns[iFcn + m_nLocalEqns] = eqnCount;
        eqnCount += m_LocalStlEqnResCount[iFcn]; 
      }
    }
  }

  if (m_nStates > 0)
  {
    *nStates = m_nStates;
    *nTransitions = m_nTransitions;
    *iDefaultState = m_DefaultState;

    *StateToEqnMap = NULL;
    if (m_nStates > 0)
    {
      *StateToEqnMap = new long*[m_nStates];
      *nStateEqns = new long[m_nStates];
      for (i = 0; i < m_nStates; i++)
      {
        (*StateToEqnMap)[i] = NULL;
        if (m_nLocalDistEqns == 0 && m_nLocalStlEqns == 0)
        {
          m_States[i]->getEqns(&(*StateToEqnMap)[i], &(*nStateEqns)[i]);
        }
        else
        {
          m_States[i]->getEqns(&indices, &count);
          // calculate equation count
          eqnCount = 0;
          for (j = 0; j < count; j++)
          {
            iFcn = indices[j]; 
            if (iFcn < m_nLocalEqns)
              eqnCount++;
            else 
            {
              iFcn = indices[j] - m_nLocalEqns;
              if (m_nLocalDistEqns > 0)
                eqnCount += m_LocalDistEqnResCount[iFcn];
              else if (m_nLocalStlEqns > 0)
                eqnCount += m_LocalStlEqnResCount[iFcn];
            }
          }

          // copy to StateToEqn map
          (*StateToEqnMap)[i] = new long[eqnCount];
          (*nStateEqns)[i] = eqnCount;
          
          eqnCount = 0;
          for (j = 0; j < count; j++)
          {
            iFcn = indices[j]; 
            if (iFcn < m_nLocalEqns)
              (*StateToEqnMap)[i][eqnCount++] = iFcn;
            else 
            {
              iFcn = indices[j] - m_nLocalEqns;
              if (m_nLocalDistEqns > 0)
              {
                for (k = 0; k < m_LocalDistEqnResCount[iFcn]; k++)
                  (*StateToEqnMap)[i][eqnCount++] = spEqns[indices[j]] + k;
              }
              else if (m_nLocalStlEqns > 0)
              {
                for (k = 0; k < m_LocalStlEqnResCount[iFcn]; k++)
                  (*StateToEqnMap)[i][eqnCount++] = spEqns[indices[j]] + k;
              }
            }
          }

          // cleanup
          DESTROY_VECTOR(indices)
        }
      }
    }

    *TransEventIds = NULL;
    *SrcStates = NULL;
    *TransToEqnMap = NULL;

    if (m_nTransitions > 0)
    {
      *TransEventIds = new BSTR[m_nTransitions];
      *SrcStates = new long[m_nTransitions];
      *TransToEqnMap = new long*[m_nTransitions];
      *nTransEqns = new long[m_nTransitions];
      for (i = 0; i < m_nTransitions; i++)
      {
        (*TransEventIds)[i] = m_Transitions[i]->getEventId();
        (*SrcStates)[i] = m_Transitions[i]->SourceState;
        (*TransToEqnMap)[i] = NULL;
        // assumption: transition equations will always be scalar equations
        m_Transitions[i]->getEqns(&(*TransToEqnMap)[i], &(*nTransEqns)[i]);
      }
    }

  }

  // cleanup
  DESTROY_VECTOR(spEqns)

  return hr;
}

HRESULT COnUMLDaeEsoBase::GetVarName(long index, BSTR* Name)
{
  HRESULT hr = E_FAIL;
  if (m_varC.Names[index])
  {
    *Name = SysAllocString(m_varC.Names[index]);
    hr = S_OK;
  }

  return hr;
}

HRESULT COnUMLDaeEsoBase::GetEqnName(long index, BSTR* Name)
{
  HRESULT hr = E_FAIL;
  long iEqn, iDistEqn, iStlEqn;
  _TCHAR buffer[10];
  CComBSTR ret;

  if (index < m_nLocalEqns)
  {
    if (m_EqnNames)
    {
      if (m_EqnNames[index])
      {
        *Name = SysAllocString(m_EqnNames[index]);
        hr = S_OK;
      }
    }
  }
  else
  {
    iEqn = index - m_nLocalEqns;
    if (m_nLocalDistEqns > 0)
    {
      for (iDistEqn = 0; iDistEqn < m_nLocalDistEqns; iDistEqn++)
      {
        if (iEqn < m_LocalDistEqnResCount[iDistEqn])
        {
          if (m_DistEqnNames[iDistEqn])
          {
            ret = m_DistEqnNames[iDistEqn];
            ret.Append(L"[");
            _ltot( iEqn, buffer, 10 );
            ret.Append(buffer);
            ret.Append(L"]");
            *Name = ret.Detach();
            hr = S_OK;
          }
          break;
        }
        else
          iEqn -= m_LocalDistEqnResCount[iDistEqn];
      }
    }
    else if (m_nLocalStlEqns > 0)
    {
      for (iStlEqn = 0; iStlEqn < m_nLocalStlEqns; iStlEqn++)
      {
        if (iEqn < m_LocalStlEqnResCount[iStlEqn])
        {
          if (m_StlEqnNames[iStlEqn])
          {
            ret = m_StlEqnNames[iStlEqn];
            ret.Append(L"[");
            _ltot( iEqn, buffer, 10 );
            ret.Append(buffer);
            ret.Append(L"]");
            *Name = ret.Detach();
            hr = S_OK;
          }
          break;
        }
        else
          iEqn -= m_LocalStlEqnResCount[iStlEqn];
      }

    }
  }

  return hr;
}

HRESULT COnUMLDaeEsoBase::GetEsoName(long index, BSTR* Name)
{
  HRESULT hr = E_FAIL;
  if (m_EsoNames)
  {
    if (m_EsoNames[index])
    {
      *Name = SysAllocString(m_EsoNames[index]);
      hr = S_OK;
    }
  }

  return hr;
}

HRESULT COnUMLDaeEsoBase::GetRParName(long index, BSTR* Name)
{
  HRESULT hr = E_FAIL;
  if (m_RParNames)
  {
    if (m_RParNames[index])
    {
      *Name = SysAllocString(m_RParNames[index]);
      hr = S_OK;
    }
  }

  return hr;
}

HRESULT COnUMLDaeEsoBase::GetIParName(long index, BSTR* Name)
{
  HRESULT hr = E_FAIL;
  
  if (m_IParNames)
  {
    if (m_IParNames[index])
    {
      *Name = SysAllocString(m_IParNames[index]);
      hr = S_OK;
    }
  }

  return hr;
}

HRESULT COnUMLDaeEsoBase::GetStateName(long index, BSTR* Name)
{
  HRESULT hr = E_FAIL;
  if (m_States)
  {
    if (m_States[index])
    {
      *Name = m_States[index]->getName();
      hr = S_OK;
    }
  }

  return hr;
}


HRESULT COnUMLDaeEsoBase::GetTransitionName(long index, BSTR* Name)
{
  HRESULT hr = E_FAIL;
  
  if (m_Transitions)
  {
    if (m_Transitions[index])
    {
      *Name = m_Transitions[index]->getName();
      hr = S_OK;
    }
  }

  return hr;
}

/*
HRESULT COnUMLDaeEsoBase::InitMemberEsos()
{
  HRESULT hr = S_OK;
  if (!m_bEsosInitialized)
  {
    hr = InitEsos();
    if (SUCCEEDED(hr))
    {
      m_bEsosInitialized = true;
      for (long i = 0; i < m_nEsos && SUCCEEDED(hr); i++)
        hr = m_Esos[i]->InitMemberEsos();
    }
  }
  return hr;
}
*/

HRESULT COnUMLDaeEsoBase::iInitialize()
{
  HRESULT hr = S_OK;
  HRESULT hrRet = S_OK;

  //if (FAILED( hr = InitMemberEsos() )) hrRet = hr;
  if (FAILED( hr = InitEsos() )) hrRet = hr;
  if (FAILED( hr = InitLocalEqns() )) hrRet = hr;
  if (FAILED( hr = InitLocalADEqns() )) hrRet = hr;
  if (FAILED( hr = InitEqnForm(&m_EqnForm, &m_EqnDiffForm) )) hrRet = hr;
  if (FAILED( hr = InitLocalVars(NULL, &m_varC, false) )) hrRet = hr;
  m_ad_x_color = new long[m_varC.nADVars];
  if (FAILED( hr = InitLocalRPars(NULL, &m_LocalRPars, &m_RParNames, &m_nLocalRPars, &m_dLocalRPars) )) hrRet = hr;
  if (FAILED( hr = InitLocalIPars(NULL, &m_LocalIPars, &m_IParNames, &m_nLocalIPars, &m_dLocalIPars) )) hrRet = hr;
  if (FAILED( hr = InitStates() )) hrRet = hr;
  if (FAILED( hr = InitTransitions() )) hrRet = hr;

  return hrRet;
}

HRESULT COnUMLDaeEsoBase::SetMasterNodeStatus(bool bMasterNode)
{ 
  m_bMasterNode = bMasterNode; 

  m_nLocalEqns = 0;
  InitLocalEqns();

  m_nLocalADEqns = 0;
  InitLocalADEqns();

  // initialize equation form again, as nEqns was 0 on previous initialization
  DESTROY_VECTOR(m_EqnForm)
  DESTROY_VECTOR(m_EqnDiffForm);
  InitEqnForm(&m_EqnForm, &m_EqnDiffForm);

  m_varC.nVars = 0;
  m_varC.nADVars = 0;
  InitLocalVars(NULL, &m_varC, false);

  return S_OK;
}


HRESULT COnUMLDaeEsoBase::InitEqnForm(OnEqnForm** form, OnEqnDiffForm** diff_form)
{
  long i;
  long nLocalEqns = m_nLocalEqns + m_nLocalDistEqns + m_nLocalStlEqns;

  if (!form)
  {
    (*form) = new OnEqnForm[nLocalEqns];
    for (i = 0; i < nLocalEqns; i++) (*form)[i] = continuous;
  }

  if (!diff_form)
  {
    (*diff_form) = new OnEqnDiffForm[nLocalEqns];
    for (i = 0; i < nLocalEqns; i++) (*diff_form)[i] = numeric;
  }

  return S_OK;
}

HRESULT COnUMLDaeEsoBase::GetType(BSTR* Type)
{
  return E_NOTIMPL;
}

HRESULT COnUMLDaeEsoBase::GetId(GUID* Id)
{
  CopyGUID(m_GUID, *Id);
  return S_OK;
}

HRESULT COnUMLDaeEsoBase::GetId(long* Path, long size, GUID* Id)
{
  COnUMLDaeEsoBase* pEso;

  pEso = this;
  for (long i = 0; i < size; i++) pEso = pEso->m_Esos[Path[i]];
  pEso->GetId(Id);

  return S_OK;
}

HRESULT COnUMLDaeEsoBase::AddAssociation(COnUMLAssociation* pAssoc)
{
  size_ptr_array(10, m_nAssociations, m_dAssociations, m_Associations);
  m_Associations[m_nAssociations++] = pAssoc;

  return S_OK;
}

HRESULT COnUMLDaeEsoBase::RemoveAssociation(long index)
{
  HRESULT hr = E_INVALIDARG;

  if (index >= 0 && index < m_nAssociations)
  {
    hr = S_OK;
    if (m_Associations[index])
    {
      delete m_Associations[index];
      compress_ptr_array(index, m_nAssociations, m_Associations);
    }
  }
  
  return hr;
}

HRESULT COnUMLDaeEsoBase::AddTransition(
  const _TCHAR* Name, 
  const long SourceState,
  const _TCHAR* EventId, 
  const long* Eqns,
  const long nEqns)
{
  TransitionInfo* pT = new TransitionInfo();

  pT->setName(Name);
  pT->SourceState = SourceState;
  pT->setEventId(EventId);
  pT->setEqns(Eqns, nEqns);
  
  size_ptr_array(10, m_nTransitions, m_dTransitions, m_Transitions);
  m_Transitions[m_nTransitions++] = pT;

  return S_OK;
}

HRESULT COnUMLDaeEsoBase::RemoveTransition(long index)
{
  HRESULT hr = E_INVALIDARG;

  if (index >= 0 && index < m_nTransitions)
  {
    hr = S_OK;
    if (m_Transitions[index])
    {
      delete m_Transitions[index];
      compress_ptr_array(index, m_nTransitions, m_Transitions);
    }
  }
  
  return hr;
}


HRESULT COnUMLDaeEsoBase::AddState(
  const _TCHAR* Name, 
  const bool bIsDefault,
  const long* Eqns,
  const long nEqns)
{
  StateInfo* pS = new StateInfo();

  pS->setName(Name);
  pS->setEqns(Eqns, nEqns);
  
  if (bIsDefault) m_DefaultState = m_nStates;

  size_ptr_array(10, m_nStates, m_dStates, m_States);
  m_States[m_nStates++] = pS;

  return S_OK;
}

HRESULT COnUMLDaeEsoBase::RemoveState(long index)
{
  HRESULT hr = E_INVALIDARG;

  if (index >= 0 && index < m_nStates)
  {
    hr = S_OK;
    if (m_States[index])
    {
      delete m_States[index];
      compress_ptr_array(index, m_nStates, m_States);
    }
  }
  
  return hr;
}

HRESULT COnUMLDaeEsoBase::AddMemberEso(COnUMLDaeEsoBase* pEso, _TCHAR* Name)
{
  long Dim;

  Dim = m_dEsos;
  size_ptr_array(10, m_nEsos, Dim, m_Esos);
  size_ptr_array(10, m_nEsos, m_dEsos, m_EsoNames);
  m_Esos[m_nEsos] = pEso;
  pEso->AddRef();
  m_EsoNames[m_nEsos] = ::SysAllocString(Name);
  m_nEsos++;

  return S_OK;
}

HRESULT COnUMLDaeEsoBase::RemoveMemberEso(long index)
{
  HRESULT hr = E_INVALIDARG;

  if (index >= 0 && index < m_nEsos)
  {
    hr = S_OK;
    if (m_Esos[index])
    {
      m_Esos[index]->Release();
      m_Esos[index] = NULL;
      compress_ptr_array(index, m_nEsos, m_Esos);
    }
  }
  
  return hr;
}

HRESULT COnUMLDaeEsoBase::RemoveAllMemberEsos()
{
  long i;

  if (m_Esos)
  {
    for (i = 0; i < m_nEsos; i++) 
    {
      if (m_Esos[i]) 
      {
        m_Esos[i]->Release();
        m_Esos[i] = NULL;
      }
    }
    DESTROY_VECTOR(m_Esos)
    m_nEsos = 0;
    m_dEsos = 0;
  }
  
  return S_OK;
}

void COnUMLDaeEsoBase::CopyGUID(const GUID& source, GUID& target)
{ 
  long i;

  target.Data1 = source.Data1;
  target.Data2 = source.Data2;
  target.Data3 = source.Data3;
  for (i = 0; i < 8; i++) target.Data4[i] = source.Data4[i];
}

HRESULT COnUMLDaeEsoBase::PostStateEvent(double t, BSTR EventId)
{
  HRESULT hr = E_FAIL;
  if (m_pOnModel)
  {
    hr = m_pOnModel->PostStateEvent(t, EventId);
  }
  return hr;
}

HRESULT COnUMLDaeEsoBase::PostTransition(long iNewState)
{
  HRESULT hr = E_FAIL;
  if (m_pOnModel)
  {
    hr = m_pOnModel->PostTransition(iNewState);
  }
  return hr;
}

HRESULT COnUMLDaeEsoBase::PostRealParameter(double t, long Id, double newVal)
{
  HRESULT hr = E_FAIL;
  if (m_pOnModel)
  {
    hr = m_pOnModel->PostRealParameter(t, Id, newVal);
  }
  return hr;
}

HRESULT COnUMLDaeEsoBase::PostIntegerParameter(double t, long Id, long newVal)
{
  HRESULT hr = E_FAIL;
  if (m_pOnModel)
  {
    hr = m_pOnModel->PostIntegerParameter(t, Id, newVal);
  }
  return hr;
}

HRESULT COnUMLDaeEsoBase::GetDataPath(BSTR* path)
{
  HRESULT hr = S_OK;
  if (!m_pOnEnv)
    hr = CoCreateInstance(CLSID_OnEnv, NULL, CLSCTX_INPROC_SERVER, IID_IOnEnv, (void**) &m_pOnEnv);

  if (SUCCEEDED(hr))
    hr = m_pOnEnv->get_DataPath(path);

  return hr;
}
