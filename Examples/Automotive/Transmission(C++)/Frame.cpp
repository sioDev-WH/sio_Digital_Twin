// Frame.cpp: implementation of the CFrame class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Frame.h"
#include "RigidConnector.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CFrame::CFrame()
{
  n = new CRigidConnector();
  n->AddRef();
}

CFrame::~CFrame()
{
  n->Release();
}

HRESULT CFrame::InitLocalEqns()
{
  ADD_LOCAL_EQN(CFrame, res0)
  return S_OK;
}

HRESULT CFrame::InitLocalADEqns()
{
  ADD_LOCAL_AD_EQN(CFrame, ad_res0)
  return S_OK;
}

HRESULT CFrame::InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
{
  for (long i = 0; i < m_nEsos; i++) 
    AddLocalVar(m_Esos[i], NULL, NULL, varC, true);

  return S_OK;
}


HRESULT CFrame::InitEsos()
{
  ADD_LOCAL_ESO(n)
  return S_OK;
}

HRESULT CFrame::res0(double* res)
{
  *res = n->A;

#if 0
  if (_verbose_print)
    ATLTRACE("\n CFrame::res0:\t%e", n->A);
#endif

  return S_OK;
}

HRESULT CFrame::ad_res0(Fdouble* res)
{
  *res = n->ad_A;
  return S_OK;
}

HRESULT CFrame::InitEqnForm(OnEqnForm** form, OnEqnDiffForm** diff_form)
{
  long i;
  DESTROY_VECTOR(*form)
  *form = new OnEqnForm[m_nLocalEqns];

  for (i = 0; i < m_nLocalEqns; i++) (*form)[i] = continuous;

  DESTROY_VECTOR(*diff_form)
  *diff_form = new OnEqnDiffForm[m_nLocalEqns];

  for (i = 0; i < m_nLocalEqns; i++) (*diff_form)[i] = automatic;

  return S_OK;
}


