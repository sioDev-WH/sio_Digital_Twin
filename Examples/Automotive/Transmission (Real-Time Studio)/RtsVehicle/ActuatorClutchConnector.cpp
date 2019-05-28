//{{SCG_IMPLEMENTATION(ActuatorClutchConnector.cpp) [0]

//{{SCG_INCLUDE  
#include "stdafx.h"
#include "ActuatorClutchConnector.h"
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif


// Include for Template Class should go here.
//}}SCG_INCLUDE
                      
//{{SCG_CLASS_ID
//}}SCG_CLASS_ID

//{{SCG_ICLASS_INFO(0)


//}}SCG_ICLASS_INFO
//{{SCG_ATTS(0)
//}}SCG_ATTS

//{{SCG_ROLES(0)
//}}SCG_ROLES

//{{SCG_OPS(0)

//{{SCG_OP(0.0)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void ActuatorClutchConnector::init()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
pressure = 0.0;
der_pressure = 0.0;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            
//}}SCG_OPS

//}}SCG_IMPLEMENTATION



// OnRotConnector.cpp: implementation of the ActuatorClutchConnector class.
//
//////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

ActuatorClutchConnector::ActuatorClutchConnector()
{
  init();
}

ActuatorClutchConnector::~ActuatorClutchConnector()
{

}


HRESULT ActuatorClutchConnector::InitLocalEqns()
{
  if (m_nEsos == 0 && m_bMasterNode)
    m_nLocalEqns = 1;
  else
    m_nLocalEqns = m_nEsos;

  return S_OK;
}

HRESULT ActuatorClutchConnector::InitLocalADEqns()
{
  if (m_nEsos == 0 && m_bMasterNode)
    m_nLocalADEqns = 1;
  else
    m_nLocalADEqns = m_nEsos;

  return S_OK;
}


HRESULT ActuatorClutchConnector::InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
{
  ADD_LOCAL_SVAR(pressure)
  for (long i = 0; i < m_nEsos; i++) 
    AddLocalVar(m_Esos[i], NULL, NULL, varC, true);

  return S_OK;
}


HRESULT ActuatorClutchConnector::GetResiduals(
  long* iEqns, 
  long nEqn, 
  double t, 
  double* residuals)
{
  long i;
  ActuatorClutchConnector* pEso;

  if (m_nEsos == 0 && nEqn == 1)
  {
    residuals[0] = pressure;
#if 0
if (_verbose_print)
  //ATLTRACE("\n ActuatorClutchConnector::GetResiduals:\t%e", pressure);
#endif

  }
  else
  {
    for (i = 0; i < nEqn; i++)
    {
      pEso = reinterpret_cast<ActuatorClutchConnector*> (m_Esos[iEqns[i]]);

#if 0
if (_verbose_print)
  //ATLTRACE("\n ActuatorClutchConnector::GetResiduals[%d]:\t%e\t%e", iEqns[i], pressure, pEso->pressure);
#endif

      residuals[i] = pressure - pEso->pressure;
    }
  }

  return S_OK;
}

HRESULT ActuatorClutchConnector::GetADResidual(
  long iEqn, 
  double t, 
  Fdouble* residual)
{
  ActuatorClutchConnector* pEso;

  if (m_nEsos == 0)
    *residual = ad_pressure;
  else
  {
    pEso = reinterpret_cast<ActuatorClutchConnector*> (m_Esos[iEqn]);
    *residual = ad_pressure - pEso->ad_pressure;
  }

  return S_OK;
}


HRESULT ActuatorClutchConnector::GetJacobianValues(
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

    for (j = 0; j < m_varC.nADVars; j++) 
    {
      m_varC.FVars[j]->diff(-1, 0);
      m_varC.derFVars[j]->diff(-1,0);
    }

    for (j = 0; j < nVar; j++)
    {
      iVar = iJac[2*(i+j)+1];
      m_varC.FVars[iVar]->diff(j, nVar);
    }
    
		hr = GetADResidual(iEqn, t, &res);
    
    for (j = 0; j < nVar; j++) jacobians[i+j] = res.d(j);
    
    i += nVar;
  }

  return hr;
}

HRESULT ActuatorClutchConnector::GetDiffJacobianValues(
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
    
    for (j = 0; j < m_varC.nADVars; j++) 
    {
      m_varC.FVars[j]->diff(-1, 0);
      m_varC.derFVars[j]->diff(-1, 0);
    }

    for (j = 0; j < nVar; j++)
    {
      iVar = iJac[2*(i+j)+1];
      m_varC.derFVars[iVar]->diff(j, nVar);
    }
    
		hr = GetADResidual(iEqn, t, &res);
    
    for (j = 0; j < nVar; j++) jacobians[i+j] = res.d(j);
    
    i += nVar;
  }

  return hr;
}

HRESULT ActuatorClutchConnector::InitEqnForm(OnEqnForm** form, OnEqnDiffForm** diff_form)
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






