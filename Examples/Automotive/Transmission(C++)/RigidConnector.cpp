// RigidConnector.cpp: implementation of the CRigidConnector class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "RigidConnector.h"


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRigidConnector::CRigidConnector()
{
  T = 0.0;
  der_T = 0.0;
  old_T = 0.0;
  der_old_T = 0.0;
  der_ad_T = 0.0;
  ad_T = 0.0;

  A = 0.0;
  der_A = 0.0;
  old_A = 0.0;
  der_old_A = 0.0;
  der_ad_A = 0.0;
  ad_A = 0.0;
}

CRigidConnector::~CRigidConnector()
{

}


HRESULT CRigidConnector::InitLocalEqns()
{
  if (m_bMasterNode)
    m_nLocalEqns = m_nEsos + 1;
  else
    m_nLocalEqns = 0;

  return S_OK;
}

HRESULT CRigidConnector::InitLocalADEqns()
{
  if (m_bMasterNode)
    m_nLocalADEqns = m_nEsos + 1;
  else
    m_nLocalADEqns = 0;

  return S_OK;
}


HRESULT CRigidConnector::InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
{
  ADD_LOCAL_SVAR(T)
  ADD_LOCAL_SVAR(A)
  for (long i = 0; i < m_nEsos; i++) 
    AddLocalVar(m_Esos[i], NULL, NULL, varC, true);

  return S_OK;
}


HRESULT CRigidConnector::GetResiduals(
  long* iEqns, 
  long nEqn, 
  double t, 
  double* residuals)
{
  long i, j, iEqn;
  CRigidConnector* pEso;

  for (i = 0; i < nEqn; i++)
  {
    iEqn = iEqns[i];
    if (iEqn == 0)
    { 

#if 0
  if (_verbose_print)
  ATLTRACE("\n CRigidConnector::GetResiduals[%d]:\t%e", iEqn, T);
#endif

      residuals[i] = T;
      for (j = 0; j < m_nEsos; j++)
      {
        pEso = reinterpret_cast<CRigidConnector*> (m_Esos[j]);
        residuals[i] += pEso->T;

#if 0
  if (_verbose_print)
        ATLTRACE("\t%e", pEso->T);
#endif

      }
    }
    else
    {
      pEso = reinterpret_cast<CRigidConnector*> (m_Esos[iEqn-1]);
      residuals[i] = A - pEso->A;

#if 0
  if (_verbose_print)
      ATLTRACE("\n CRigidConnector::GetResiduals[%d]:\t%e\t%e", iEqn, A, pEso->A);
#endif

    }
  }

  return S_OK;
}


HRESULT CRigidConnector::GetADResidual(
  long iEqn, 
  double t, 
  Fdouble* residual)
{
  long i;
  CRigidConnector* pEso;

#if 0
  ATLTRACE( _T("\nCRigidConnector::GetADResidual") );
#endif

  if (iEqn == 0)
  { 
    (*residual) = ad_T;
    for (i = 0; i < m_nEsos; i++)
    {
      pEso = reinterpret_cast<CRigidConnector*> (m_Esos[i]);
      (*residual) += pEso->ad_T;
    }
  }
  else
  {
    pEso = reinterpret_cast<CRigidConnector*> (m_Esos[iEqn-1]);
    (*residual) = ad_A - pEso->ad_A;
  }

  return S_OK;
}


HRESULT CRigidConnector::GetJacobianValues(
  long* iJac, 
  long nJac, 
  double t, 
  double* jacobians)
{
  HRESULT hr = S_OK;
	long i, j;
  long iEqn, iVar, nVar;

	Fdouble res;

  i = 0;
  while ( (i < nJac) && SUCCEEDED(hr) )
  {
    iEqn = iJac[2*i];
    for (j = i, nVar = 0; (iEqn == iJac[2*j]) && (j < nJac); j++) nVar++;

    for (j = 0; j < m_nADVars; j++) 
    {
      m_ad_x[j]->diff(-1, 0);
      m_ad_xdot[j]->diff(-1,0);
    }

    for (j = 0; j < nVar; j++)
    {
      iVar = iJac[2*(i+j)+1];
      m_ad_x[iVar]->diff(j, nVar);
    }
    
		hr = GetADResidual(iEqn, t, &res);
    
    for (j = 0; j < nVar; j++) jacobians[i+j] = res.d(j);
    
    i += nVar;
  }

  return hr;
}

HRESULT CRigidConnector::GetDiffJacobianValues(
  long* iJac, 
  long nJac, 
  double t, 
  double* jacobians)
{
  HRESULT hr = S_OK;
	long i, j;
  long iEqn, iVar, nVar;

	Fdouble res;
  i = 0;
  while ( (i < nJac) && SUCCEEDED(hr) )
  {
    iEqn = iJac[2*i];
    for (j = i, nVar = 0; (iEqn == iJac[2*j]) && (j < nJac); j++) nVar++;
    
    for (j = 0; j < m_nADVars; j++) 
    {
      m_ad_x[j]->diff(-1, 0);
      m_ad_xdot[j]->diff(-1, 0);
    }

    for (j = 0; j < nVar; j++)
    {
      iVar = iJac[2*(i+j)+1];
      m_ad_xdot[iVar]->diff(j, nVar);
    }
    
		hr = GetADResidual(iEqn, t, &res);
    
    for (j = 0; j < nVar; j++) jacobians[i+j] = res.d(j);
    
    i += nVar;
  }

  return hr;
}

HRESULT CRigidConnector::InitEqnForm(OnEqnForm** form, OnEqnDiffForm** diff_form)
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
