// Mass.cpp : Implementation of CMass
#include "stdafx.h"
#include "OnTransmission.h"
#include "Mass.h"
#include "RigidConnector.h"


/////////////////////////////////////////////////////////////////////////////
// CMass

CMass::CMass()
{
  J = 100.0;

  W = 0.0;
  der_W = 0.0;

  p = new CRigidConnector();
  n = new CRigidConnector();

  p->AddRef();
  n->AddRef();
}

CMass::~CMass()
{
  p->Release();
  n->Release();
}

HRESULT CMass::InitEsos()
{
  ADD_LOCAL_ESO(p)
  ADD_LOCAL_ESO(n)

  return S_OK;
}

HRESULT CMass::InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
{
  ADD_LOCAL_SVAR(W)
  for (long i = 0; i < m_nEsos; i++) 
    AddLocalVar(m_Esos[i], NULL, NULL, varC, true);

  return S_OK;
}

HRESULT CMass::InitLocalRPars(const _TCHAR* prefix, double*** pars, _TCHAR*** Names, long* nPars, long* dPars)
{
  ADD_LOCAL_SRPAR(J)
  return S_OK;
}

HRESULT CMass::InitLocalEqns()
{
  ADD_LOCAL_EQN(CMass, res0)
  ADD_LOCAL_EQN(CMass, res1)
  ADD_LOCAL_EQN(CMass, res2)

  return S_OK;
}

HRESULT CMass::InitLocalADEqns()
{
  ADD_LOCAL_AD_EQN(CMass, ad_res0)
  ADD_LOCAL_AD_EQN(CMass, ad_res1)
  ADD_LOCAL_AD_EQN(CMass, ad_res2)

  return S_OK;
}

HRESULT CMass::res0(double* res)
{
  *res = p->T + n->T - J * p->A;

#if 0
  if (_verbose_print)
  ATLTRACE("\n CMass::res0:\t%e\t%e\t%e\t%e", 
    p->T, n->T, J, p->A );
#endif

  return S_OK;
}

HRESULT CMass::res1(double* res)
{
  *res = der_W - p->A;

#if 0
  if (_verbose_print)
  ATLTRACE("\n CMass::res1:\t%e\t%e", 
    der_W, p->A );
#endif

  return S_OK;
}

HRESULT CMass::res2(double* res)
{
  *res = p->A - n->A;

#if 0
  if (_verbose_print)
  ATLTRACE("\n CMass::res2:\t%e\t%e", 
    p->A, n->A );
#endif

  return S_OK;
}

HRESULT CMass::ad_res0(Fdouble* res)
{
  *res = p->ad_T + n->ad_T - J * p->ad_A;
  return S_OK;
}

HRESULT CMass::ad_res1(Fdouble* res)
{
  *res = der_ad_W - p->ad_A;
  return S_OK;
}

HRESULT CMass::ad_res2(Fdouble* res)
{
  *res = p->ad_A - n->ad_A;
  return S_OK;
}


HRESULT CMass::InitEqnForm(OnEqnForm** form, OnEqnDiffForm** diff_form)
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


