// SignalActuator.cpp: implementation of the CSignalActuator class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "SignalActuator.h"
#include "RigidConnector.h"
#include <math.h>


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CSignalActuator::CSignalActuator()
{
  n = new CRigidConnector();
  n->AddRef();
  LocalTime = 0.0;
  der_LocalTime = 1.0;      // <der_SimVar>
  direction = 1.0;
}

CSignalActuator::~CSignalActuator()
{
  n->Release();
}

HRESULT CSignalActuator::InitLocalEqns()
{
  ADD_LOCAL_EQN(CSignalActuator, res0)
  ADD_LOCAL_EQN(CSignalActuator, res1)
  return S_OK;
}

HRESULT CSignalActuator::InitLocalADEqns()
{
  ADD_LOCAL_AD_EQN(CSignalActuator, ad_res0)
  ADD_LOCAL_AD_EQN(CSignalActuator, ad_res1)
  return S_OK;
}

HRESULT CSignalActuator::InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
{
  ADD_LOCAL_SVAR(LocalTime)  
  for (long i = 0; i < m_nEsos; i++) 
    AddLocalVar(m_Esos[i], NULL, NULL, varC, true);

  return S_OK;
}

HRESULT CSignalActuator::InitEsos()
{
  ADD_LOCAL_ESO(n)
  return S_OK;
}

// residuals
HRESULT CSignalActuator::res0(double* res)
{
  *res = n->T + direction * 200.0; // * sin(10.0*LocalTime);

#if 0
  if (_verbose_print)
      ATLTRACE("\n CSignalActuator::res0:\t%e", n->T);
#endif

  return S_OK;
}

HRESULT CSignalActuator::res1(double* res)
{
  *res = der_LocalTime - 1.0;

#if 0
  if (_verbose_print)
      ATLTRACE("\n CSignalActuator::res1:\t%e", der_LocalTime);
#endif

  return S_OK;
}


HRESULT CSignalActuator::ad_res0(Fdouble* res)
{
  *res = n->ad_T + direction * 200.0;// * sin(10.0 * ad_LocalTime);
  return S_OK;
}

HRESULT CSignalActuator::ad_res1(Fdouble* res)
{
  *res = der_ad_LocalTime - 1.0;
  return S_OK;
}

HRESULT CSignalActuator::InitEqnForm(OnEqnForm** form, OnEqnDiffForm** diff_form)
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
