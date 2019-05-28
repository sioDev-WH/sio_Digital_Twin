// vbVehicle5.cpp : Implementation of CvbVehicle5
#include "stdafx.h"
#include "RtsOnTransmissionVB.h"
#include "vbVehicle5.h"
#include "BrakeActuator.h"

/////////////////////////////////////////////////////////////////////////////
// CvbVehicle5

CvbVehicle5::CvbVehicle5()
{
}

CvbVehicle5::~CvbVehicle5()
{
}

// specific to Vehicle5
STDMETHODIMP CvbVehicle5::get_p(SAFEARRAY** val)
{
  getPath(0, val);
  return S_OK;
}

STDMETHODIMP CvbVehicle5::brakeEvent(double t, double val)
{
  m_pEso->aBrakeActuator->handle_brakePedal(t, &val); 
  return S_OK;
}