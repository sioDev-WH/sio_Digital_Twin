// implementation for class ControlledReactor_app
#include "StdAfx.h"
#include "RpyReactor.h"
#include <math.h>
#include "ControlledReactor_app.h"
#include "ControlledReactor.h"
#include "Controller.h"
#include "Heater.h"
#include "OnUMLEso.h"

ControlledReactor_app::ControlledReactor_app()
{
  init();
}

ControlledReactor_app::~ControlledReactor_app()
{
  clean();
}

void ControlledReactor_app::Fire_Tick(const double t)
{
  
  double sim_time = t;
  
  // non-system objects
  
  // data consumers
  
  // get the control output from the controller, and update the control setting on the heater
  double CO = m_pUMLModel->getItsController()->get_Output(t);
  m_pUMLModel->getItsHeater()->handle_Sh(t, &CO); 
}


void ControlledReactor_app::initSimulation()
{
  
  HRESULT hr = S_OK;
  SAFEARRAY* psaVarNames = NULL;
  BSTR* varNames = NULL;
  long i;
  
  psaVarVals = NULL;
  varVals = NULL;
  
  USES_CONVERSION;
  m_pModel->GetTime(&sim_time);
  // record data to file
  fs.open("ControlledReactor.txt");
  m_pModel->GetNumVars(&nVars);
  psaVarVals = SafeArrayCreateVector(VT_R8, 0, nVars);
  SafeArrayAccessData(psaVarVals, (void HUGEP* FAR*)& varVals);
  
  m_pModel->GetVarNames(&psaVarNames);
  SafeArrayAccessData(psaVarNames, (void HUGEP* FAR*)& varNames);
  fs << "time" << "\t";
  for (i = 0; i < nVars; i++)
  {
    if (varNames[i])
      fs << W2CA(varNames[i]) << "\t";
    else
      fs << "\t";
  }
  fs << "\n";
  SafeArrayUnaccessData(psaVarNames);
  SafeArrayDestroy(psaVarNames);
  psaVarNames = NULL;
  varNames = NULL;
}


void ControlledReactor_app::runSimulation()
{
  
  HRESULT hr = S_OK;
  
  initSimulation();
  
  while (sim_time < m_endTime && SUCCEEDED(hr))
  {
    hr = handle_tick(sim_time);
    sim_time += m_stepSize;
  }
  
  termSimulation();
}


HRESULT ControlledReactor_app::handle_tick(const double t)
{
  
  long i;
  static double last_sim_time = 0.0;
  sim_time = t;
  HRESULT hr = m_pModelExec->Step(sim_time);
  if (SUCCEEDED(hr))
  {
    m_pModel->GetAllVariables(sim_time, &psaVarVals);
    fs << sim_time << "\t";
    for (i = 0; i < nVars; i++)
      fs << varVals[i] << "\t";
  
    fs << "\n";
  
    Fire_Tick(sim_time);
  }
  
  return hr;
}


void ControlledReactor_app::termSimulation()
{
  
  // cleanup
  if (psaVarVals)
  {
    SafeArrayUnaccessData(psaVarVals);
    SafeArrayDestroy(psaVarVals);
    psaVarVals = NULL;
    varVals = NULL;
  }
  fs.close();
}


void ControlledReactor_app::init()
{
  
  psaVarVals = NULL;
  sim_time = 0.0;
  varVals = NULL;
  nVars = 0;
  
  
  IIsDaeEsoCImpl* pEso = NULL;
  long nVars = 0;
  long i;
  HRESULT hr = S_OK;
  
  m_startTime = 0;
  m_endTime = 5;
  m_stepSize = 0.1;
  
  CoInitialize(NULL);
  hr = CoCreateInstance(CLSID_OnModelExec, NULL, CLSCTX_INPROC_SERVER, IID_IOnModelExec, (void**) &m_pModelExec);
  _ASSERTE(hr == S_OK);
  hr = CoCreateInstance(CLSID_IsDaeEsoCImpl, NULL, CLSCTX_INPROC_SERVER, IID_IIsDaeEsoCImpl, (void**) &m_pModel);
  _ASSERTE(hr == S_OK);
  m_pUMLModel = new ControlledReactor();
  m_pModel->SetEso(m_pUMLModel);
  m_pModelExec->SetModel(m_pModel);
  
  // tolerance initialization
  m_pModel->GetNumVars(&nVars);
  SAFEARRAY* psa_atol = SafeArrayCreateVector(VT_R8, 0, nVars);
  SAFEARRAY* psa_rtol = SafeArrayCreateVector(VT_R8, 0, nVars);
  double* v_atol = NULL;
  double* v_rtol = NULL;
  SafeArrayAccessData(psa_atol, (void HUGEP* FAR*)& v_atol);
  SafeArrayAccessData(psa_rtol, (void HUGEP* FAR*)& v_rtol);
  
  // TODO: modify tolerances as necessary
  for (i = 0; i < nVars; i++)
  {
    v_atol[i] = 1.0e-6;
    v_rtol[i] = 1.0e-6;
  }
  
  SafeArrayUnaccessData(psa_atol);
  SafeArrayUnaccessData(psa_atol);
  m_pModel->SetAbsTolerance(&psa_atol);
  m_pModel->SetRelTolerance(&psa_rtol);
  SafeArrayDestroy(psa_atol);
  SafeArrayDestroy(psa_rtol);
  // end tolerance initialization
  
  
  // time initialization
  double t;
  m_pModel->InitTime(m_startTime, VARIANT_FALSE);
  m_pModel->GetTime(&t);
  m_t_last = t;
  // end time initialization
  
  // sub model initialization
  // end sub model initialization
  
  // broadcaster / handler communication initialization
  // end broadcaster / handler communication initialization
  
  // data consumer communication initialization
  // end data consumer communication initialization
  
}


void ControlledReactor_app::clean()
{
  if (m_pModelExec)
  {
    m_pModelExec->SetModel(NULL);
    m_pModelExec->Release();
    m_pModelExec = NULL;
  }
  
  if (m_pModel)
  {
    m_pModel->Release();
    m_pModel = NULL;
  }
  
  CoUninitialize();
}

void ControlledReactor_app::SetTime(double t)
{
  SAFEARRAY* psa = NULL;

  m_pModel->GetAllVariables(t, &psa);
  m_pModel->SetAllVariables(&psa);
  
  SafeArrayDestroy(psa);
  psa = NULL;

  m_pModel->GetAllDerivatives(t, &psa);
  m_pModel->SetAllDerivatives(&psa);
  
  SafeArrayDestroy(psa);
  psa = NULL;

}

