// vbBrakeActuator.cpp : Implementation of CvbBrakeActuator
#include "stdafx.h"
#include "RtsOnTransmissionVB.h"
#include "vbBrakeActuator.h"

/////////////////////////////////////////////////////////////////////////////
// CvbBrakeActuator

CvbBrakeActuator::CvbBrakeActuator()
{
}

CvbBrakeActuator::~CvbBrakeActuator()
{
}


STDMETHODIMP CvbBrakeActuator::get_p(SAFEARRAY** val)
{
  getPath(0, val);
  return S_OK;
}

