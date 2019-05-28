// RpyReactorTestHarness.cpp : Implementation of CRpyReactorTestHarness
#include "stdafx.h"
#include "RpyReactor.h"
#include "RpyReactorTestHarness.h"
#include "ControlledReactor_app.h"
#include "ControlledReactor.h"
#include "Controller.h"
#include "OnUMLEso.h"

/////////////////////////////////////////////////////////////////////////////
// CRpyReactorTestHarness

CRpyReactorTestHarness::CRpyReactorTestHarness()
{
  m_app = new ControlledReactor_app();
  m_app->initSimulation();
}

CRpyReactorTestHarness::~CRpyReactorTestHarness()
{
  if (m_app)
  {
    m_app->termSimulation();
    delete m_app;
    m_app = NULL;
  }
}

STDMETHODIMP CRpyReactorTestHarness::GetModel(IDispatch** ppModel)
{
  *ppModel = m_app->m_pModel;
  (*ppModel)->AddRef();
  return S_OK;
}

STDMETHODIMP CRpyReactorTestHarness::GetModelExec(IDispatch** ppModelExec)
{
  *ppModelExec = m_app->m_pModelExec;
  (*ppModelExec)->AddRef();
  return S_OK;
}

STDMETHODIMP CRpyReactorTestHarness::Step(double t)
{
	m_app->handle_tick(t);
	return S_OK;
}

STDMETHODIMP CRpyReactorTestHarness::GetControllerOutput(double time, double *pOut)
{
	*pOut = m_app->m_pUMLModel->getItsController()->get_Output(time); 
	return S_OK;
}

STDMETHODIMP CRpyReactorTestHarness::setSetpoint(double val)
{
	m_app->m_pUMLModel->getItsController()->Setpoint = val;  
	return S_OK;
}
