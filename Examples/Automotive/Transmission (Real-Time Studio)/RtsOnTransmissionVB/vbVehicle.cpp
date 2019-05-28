// vbVehicle.cpp : Implementation of CvbVehicle
#include "stdafx.h"
#include "RtsOnTransmissionVB.h"
#include "vbVehicle.h"

/////////////////////////////////////////////////////////////////////////////
// CvbVehicle

CvbVehicle::CvbVehicle()
{
}

CvbVehicle::~CvbVehicle()
{
}

// specific to Vehicle
STDMETHODIMP CvbVehicle::get_p(SAFEARRAY** val)
{
  getPath(0, val);
  return S_OK;
}

