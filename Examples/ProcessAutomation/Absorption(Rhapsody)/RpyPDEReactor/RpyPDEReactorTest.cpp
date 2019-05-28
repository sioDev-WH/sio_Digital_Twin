// RpyPDEReactorTest.cpp : Implementation of CRpyPDEReactorTest
#include "stdafx.h"
#include "RpyPDEReactor.h"
#include "RpyPDEReactorTest.h"
#include "Reactor_app.h"

/////////////////////////////////////////////////////////////////////////////
// CRpyPDEReactorTest


CRpyPDEReactorTest::CRpyPDEReactorTest() : m_pApp(NULL)
{
  init();
}

CRpyPDEReactorTest::~CRpyPDEReactorTest()
{
  clean();
}

void CRpyPDEReactorTest::init()
{
  if (!m_pApp)
  {
    m_pApp = new Reactor_app();
    m_pApp->initSimulation(); 
  }
}

void CRpyPDEReactorTest::clean()
{
  if (m_pApp)
  {
    m_pApp->termSimulation();
    delete m_pApp;
    m_pApp = NULL;
  }
}



STDMETHODIMP CRpyPDEReactorTest::Step(double time)
{
	return m_pApp->handle_tick(time); 
}

STDMETHODIMP CRpyPDEReactorTest::GetVariables(double t, SAFEARRAY **ppsaVars)
{
	return m_pApp->m_pModel->GetAllVariables(t, ppsaVars); 
}
