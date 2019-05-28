// Damper.cpp: implementation of the CDamper class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Damper.h"
#include "RigidConnector.h"

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CDamper::CDamper()
{
  Kd = 1.0;

  W = 0.0;
  der_W = 0.0;

  p = new CRigidConnector();
  n = new CRigidConnector();
  p->AddRef();
  n->AddRef();
}

CDamper::~CDamper()
{
  p->Release();
  n->Release();
}

HRESULT CDamper::InitLocalEqns()
{
  ADD_LOCAL_EQN(CDamper, res0)
  ADD_LOCAL_EQN(CDamper, res1)
  ADD_LOCAL_EQN(CDamper, res2)
  return S_OK;
}

HRESULT CDamper::InitLocalADEqns()
{
  ADD_LOCAL_AD_EQN(CDamper, ad_res0)
  ADD_LOCAL_AD_EQN(CDamper, ad_res1)
  ADD_LOCAL_AD_EQN(CDamper, ad_res2)
  return S_OK;
}

HRESULT CDamper::InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
{
  ADD_LOCAL_SVAR(W)
  for (long i = 0; i < m_nEsos; i++) 
    AddLocalVar(m_Esos[i], NULL, NULL, varC, true);

  return S_OK;
}

HRESULT CDamper::InitLocalRPars(const _TCHAR* prefix, double*** pars, _TCHAR*** Names, long* nPars, long* dPars)
{
  ADD_LOCAL_SRPAR(Kd)
  return S_OK;
}

HRESULT CDamper::InitEsos()
{
  ADD_LOCAL_ESO(p)
  ADD_LOCAL_ESO(n)

  return S_OK;
}

HRESULT CDamper::res0(double* res)
{
  *res = p->T - Kd * W;
  return S_OK;
}

HRESULT CDamper::res1(double* res)
{
  *res = p->T + n->T; 
  return S_OK;
}

HRESULT CDamper::res2(double* res)
{
  *res = der_W - (p->A - n->A);
  return S_OK;
}

// automatic differentiation
HRESULT CDamper::ad_res0(Fdouble* res)
{
  *res = p->ad_T - Kd * ad_W;
  return S_OK;
}

HRESULT CDamper::ad_res1(Fdouble* res)
{
  *res = p->ad_T + n->ad_T; 
  return S_OK;
}

HRESULT CDamper::ad_res2(Fdouble* res)
{
  *res = der_ad_W - (p->ad_A - n->ad_A);
  return S_OK;
}


HRESULT CDamper::InitEqnForm(OnEqnForm** form, OnEqnDiffForm** diff_form)
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

