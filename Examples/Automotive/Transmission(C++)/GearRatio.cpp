// OnRotGearRatio.cpp : Implementation of CGearRatio
#include "stdafx.h"
#include "OnTransmission.h"
#include "GearRatio.h"
#include "RigidConnector.h"

/////////////////////////////////////////////////////////////////////////////
// CGearRatio

CGearRatio::CGearRatio()
{
  R = 1.0;

  p = new CRigidConnector();
  n = new CRigidConnector();

  p->AddRef();
  n->AddRef();
}

CGearRatio::~CGearRatio()
{
  p->Release();
  n->Release();
}

HRESULT CGearRatio::InitEsos()
{
  ADD_LOCAL_ESO(p)
  ADD_LOCAL_ESO(n)

  return S_OK;
}

HRESULT CGearRatio::InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
{
  for (long i = 0; i < m_nEsos; i++) 
    AddLocalVar(m_Esos[i], NULL, NULL, varC, true);

  return S_OK;
}

HRESULT CGearRatio::InitLocalRPars(const _TCHAR* prefix, double*** pars, _TCHAR*** Names, long* nPars, long* dPars)
{
  ADD_LOCAL_SRPAR(R)
  return S_OK;
}

HRESULT CGearRatio::InitLocalEqns()
{
  ADD_LOCAL_EQN(CGearRatio, res0)
  ADD_LOCAL_EQN(CGearRatio, res1)

  return S_OK;
}

HRESULT CGearRatio::InitLocalADEqns()
{
  ADD_LOCAL_AD_EQN(CGearRatio, ad_res0)
  ADD_LOCAL_AD_EQN(CGearRatio, ad_res1)

  return S_OK;
}

HRESULT CGearRatio::res0(double* res)
{
  *res = p->T - 1/R * n->T;
  return S_OK;
}

HRESULT CGearRatio::res1(double* res)
{
  *res = p->A + R * n->A;
  return S_OK;
}

HRESULT CGearRatio::ad_res0(Fdouble* res)
{
  *res = p->ad_T - 1/R * n->ad_T;
  return S_OK;
}

HRESULT CGearRatio::ad_res1(Fdouble* res)
{
  *res = p->ad_A + R * n->ad_A;
  return S_OK;
}


HRESULT CGearRatio::InitEqnForm(OnEqnForm** form, OnEqnDiffForm** diff_form)
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


