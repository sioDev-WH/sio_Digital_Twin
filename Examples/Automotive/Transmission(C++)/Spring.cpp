// Spring.cpp: implementation of the CSpring class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Spring.h"
#include "RigidConnector.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSpring::CSpring()
{
  Ks = 160;

  dTs = 0.0;
  der_dTs = 0.0;

  ddTs = 0.0;
  der_ddTs = 0.0;

  p = new CRigidConnector();
  n = new CRigidConnector();

  p->AddRef();
  n->AddRef();
}

CSpring::~CSpring()
{
  p->Release();
  n->Release();
}

HRESULT CSpring::InitLocalEqns()
{
  ADD_LOCAL_EQN(CSpring, res0)
  ADD_LOCAL_EQN(CSpring, res1)
  ADD_LOCAL_EQN(CSpring, res2)
  ADD_LOCAL_EQN(CSpring, res3)
  return S_OK;
}

HRESULT CSpring::InitLocalADEqns()
{
  ADD_LOCAL_AD_EQN(CSpring, ad_res0)
  ADD_LOCAL_AD_EQN(CSpring, ad_res1)
  ADD_LOCAL_AD_EQN(CSpring, ad_res2)
  ADD_LOCAL_AD_EQN(CSpring, ad_res3)
  return S_OK;
}

HRESULT CSpring::InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
{
  ADD_LOCAL_SVAR(dTs)
  ADD_LOCAL_SVAR(ddTs)
  for (long i = 0; i < m_nEsos; i++) 
    AddLocalVar(m_Esos[i], NULL, NULL, varC, true);

  return S_OK;
}

HRESULT CSpring::InitLocalRPars(const _TCHAR* prefix, double*** pars, _TCHAR*** Names, long* nPars, long* dPars)
{
  ADD_LOCAL_SRPAR(Ks)
  return S_OK;
}

HRESULT CSpring::InitEsos()
{
  ADD_LOCAL_ESO(p)
  ADD_LOCAL_ESO(n)

  return S_OK;
}


HRESULT CSpring::res0(double* res)
{
  *res = p->der_T - dTs;
  return S_OK;
}

HRESULT CSpring::res1(double* res)
{
  *res = der_dTs - ddTs;
  return S_OK;
}

HRESULT CSpring::res2(double* res)
{
  *res = ddTs - Ks * (p->A - n->A);
  return S_OK;
}

HRESULT CSpring::res3(double* res)
{
  *res = p->T + n->T;
  return S_OK;
}




// automatic differentiation
HRESULT CSpring::ad_res0(Fdouble* res)
{
  *res = p->der_ad_T - ad_dTs;
  return S_OK;
}

HRESULT CSpring::ad_res1(Fdouble* res)
{
  *res = der_ad_dTs - ad_ddTs;
  return S_OK;
}

HRESULT CSpring::ad_res2(Fdouble* res)
{
  *res = ad_ddTs - Ks * (p->ad_A - n->ad_A);
  return S_OK;
}

HRESULT CSpring::ad_res3(Fdouble* res)
{
  *res = p->ad_T + n->ad_T;
  return S_OK;
}



HRESULT CSpring::InitEqnForm(OnEqnForm** form, OnEqnDiffForm** diff_form)
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




