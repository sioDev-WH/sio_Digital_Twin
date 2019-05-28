// COnTestHarness.cpp : Implementation of CCOnTestHarness
#include "stdafx.h"
#include "RtsOnTransmission.h"
#include "COnTestHarness.h"
#include ".\..\RtsTransmission\TestHarness.h"
#include ".\..\RtsTransmission\Car_app.h"

// patch includes
#include ".\..\RtsTransmission\Controller.h"
#include ".\..\RtsTransmission\Car1.h"
#include ".\..\RtsTransmission\Actuator.h"
#include ".\..\RtsTransmission\Clutch.h"
#include ".\..\RtsTransmission\Oneway_clutch.h"
#include ".\..\RtsTransmission\Band_Break.h"
#include ".\..\RtsTransmission\Engine.h"
#include ".\..\RtsTransmission\Torque_Converter.h"

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

/////////////////////////////////////////////////////////////////////////////
// CCOnTestHarness


STDMETHODIMP CCOnTestHarness::runTest()
{
  TestHarness* th = new TestHarness();
  th->RtsrunSim();
  th->RtsexitSim();
  delete th;
	return S_OK;
}

STDMETHODIMP CCOnTestHarness::init()
{
  pApp = new TestHarness();
  pApp->m_app->initSimulation();
	return S_OK;
}

STDMETHODIMP CCOnTestHarness::tick(double t)
{
  HRESULT hr = E_FAIL;
  if (pApp)
  {
    hr = pApp->m_app->handle_tick(t);
  }
	return hr;
}

STDMETHODIMP CCOnTestHarness::term()
{
  if (pApp)
  {
    pApp->m_app->termSimulation();
    delete pApp;
    pApp = NULL;
  }

	return S_OK;
}


STDMETHODIMP CCOnTestHarness::get_model(IIsDaeEsoCImpl **pVal)
{
  *pVal = pApp->m_app->m_pModel;
  (*pVal)->AddRef();
	return S_OK;
}

STDMETHODIMP CCOnTestHarness::get_ModelExec(IOnModelExec **pVal)
{
	*pVal = pApp->m_app->m_pModelExec;
  (*pVal)->AddRef();
	return S_OK;
}


STDMETHODIMP CCOnTestHarness::SetShiftTiming(VARIANT_BOOL bUp, long iShift, double val)
{
  // bUp { 1, 2, 3 } ==> 1->2, 2->3, 3->4
#if APP_HARNESS_CAR_APP
  if (bUp == VARIANT_TRUE)
    pApp->m_app->AODController->upshiftDelay[iShift] = val;
  else
    pApp->m_app->AODController->downshiftDelay[iShift] = val; 
#endif
  return S_OK;
}

STDMETHODIMP CCOnTestHarness::SetShiftPeriod(long iClutch, double val)
{
#if APP_HARNESS_CAR_APP

  switch (iClutch)
  {
  case 0:
    pApp->m_app->m_pUMLModel->aDC->SetShiftPeriod(val);
    break;
  case 1:
    pApp->m_app->m_pUMLModel->aFC->SetShiftPeriod(val); 
    break;
  case 2:
    pApp->m_app->m_pUMLModel->aIOC->SetShiftPeriod(val); 
    break;
  case 3:
    pApp->m_app->m_pUMLModel->aLRB->SetShiftPeriod(val);
    break;
  case 4:
    pApp->m_app->m_pUMLModel->aOB->SetShiftPeriod(val); 
    break;
  case 5:
    pApp->m_app->m_pUMLModel->aPOC->SetShiftPeriod(val);
    break;
  case 6:
    pApp->m_app->m_pUMLModel->aRC->SetShiftPeriod(val);
    break;
  case 7:
    pApp->m_app->m_pUMLModel->aTCC->SetShiftPeriod(val); 
    break;
  }
#endif

  return S_OK;
}

STDMETHODIMP CCOnTestHarness::SetThrottle(double throttle)
{
#if APP_HARNESS_CAR_APP
  pApp->m_app->set_throttle(pApp->m_app->sim_time, &throttle); 
#endif
  return S_OK;
}

STDMETHODIMP CCOnTestHarness::Load(BSTR FileName)
{
  pApp->m_app->Load(FileName);
  return S_OK;
}

STDMETHODIMP CCOnTestHarness::Save(BSTR FileName)
{
  pApp->m_app->Save(FileName);
  return S_OK;
}

STDMETHODIMP CCOnTestHarness::GetStates(SAFEARRAY** psa_states)
{
#if APP_HARNESS_CAR_APP

  long* states = NULL;

  SafeArrayAccessData(*psa_states, (void HUGEP* FAR*)& states);

  states[0] = (long) pApp->m_app->m_pUMLModel->EngineWithSpeed->RtsCurrent_Engine;
  states[1] = (long) pApp->m_app->m_pUMLModel->aRC->RtsCurrent_Actuator;
  states[2] = (long) pApp->m_app->m_pUMLModel->RC->RtsCurrent_Clutch;
  states[3] = (long) pApp->m_app->m_pUMLModel->aLRB->RtsCurrent_Actuator;
  states[4] = (long) pApp->m_app->m_pUMLModel->LRB->RtsCurrent_Clutch;
  states[5] = (long) pApp->m_app->m_pUMLModel->aTCC->RtsCurrent_Actuator;
  states[6] = (long) pApp->m_app->m_pUMLModel->TCC->RtsCurrent_Clutch;
  states[7] = (long) pApp->m_app->m_pUMLModel->Converter->RtsCurrent_Torque_Converter;
  states[8] = (long) pApp->m_app->m_pUMLModel->aOB->RtsCurrent_Actuator;
  states[9] = (long) pApp->m_app->m_pUMLModel->OB->RtsCurrent_Clutch;
  states[10] = (long) pApp->m_app->m_pUMLModel->aDC->RtsCurrent_Actuator;
  states[11] = (long) pApp->m_app->m_pUMLModel->DC->RtsCurrent_Clutch;
  states[12] = (long) pApp->m_app->m_pUMLModel->aIOC->RtsCurrent_Actuator;
  states[13] = (long) pApp->m_app->m_pUMLModel->IOC->RtsCurrent_Clutch;
  states[14] = (long) pApp->m_app->m_pUMLModel->aPOC->RtsCurrent_Actuator;
  states[15] = (long) pApp->m_app->m_pUMLModel->POC->RtsCurrent_Clutch;
  states[16] = (long) pApp->m_app->m_pUMLModel->aFC->RtsCurrent_Actuator;
  states[17] = (long) pApp->m_app->m_pUMLModel->FC->RtsCurrent_Clutch;

  SafeArrayUnaccessData(*psa_states);

#endif
  return S_OK;
}