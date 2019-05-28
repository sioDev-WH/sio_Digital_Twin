// vbActuator.cpp : Implementation of CvbActuator
#include "stdafx.h"
#include "RtsOnTransmissionVB.h"
#include "vbActuator.h"

/////////////////////////////////////////////////////////////////////////////
// CvbActuator

CvbActuator::CvbActuator()
{
}

CvbActuator::~CvbActuator()
{
}


STDMETHODIMP CvbActuator::shiftEvent(double t, long val)  
{
  m_pEso->handle_shiftEvent(t, &val);
  return S_OK;
}

STDMETHODIMP CvbActuator::get_clutch(SAFEARRAY** val)
{
	getPath(0, val);
	return S_OK;
}
