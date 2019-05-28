// vbEngine.cpp : Implementation of CvbEngine
#include "stdafx.h"
#include "RtsOnTransmissionVB.h"
#include "vbEngine.h"

/////////////////////////////////////////////////////////////////////////////
// CvbEngine

CvbEngine::CvbEngine()
{
}

CvbEngine::~CvbEngine()
{
}


STDMETHODIMP CvbEngine::get_n(SAFEARRAY** val)
{
  getPath(0, val);
  return S_OK;
}

STDMETHODIMP CvbEngine::throttleEvent(double t, double val)  
{
  m_pEso->handle_throttle(t, &val);
  return S_OK;
}

STDMETHODIMP CvbEngine::startEvent(double t, long val)
{
  m_pEso->handle_Start(t, &val);
  return S_OK;
}

