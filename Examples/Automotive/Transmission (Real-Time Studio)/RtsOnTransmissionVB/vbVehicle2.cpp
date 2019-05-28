// vbVehicle2.cpp : Implementation of CvbVehicle2
#include "stdafx.h"
#include "RtsOnTransmissionVB.h"
#include "vbVehicle2.h"

/////////////////////////////////////////////////////////////////////////////
// CvbVehicle2

CvbVehicle2::CvbVehicle2()
{
}

CvbVehicle2::~CvbVehicle2()
{
}

// specific to Vehicle2
STDMETHODIMP CvbVehicle2::get_p(SAFEARRAY** val)
{
  getPath(0, val);
  return S_OK;
}

