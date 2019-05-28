// vbBand_Brake.cpp : Implementation of CvbBand_Brake
#include "stdafx.h"
#include "RtsOnTransmissionVB.h"
#include "vbBand_Brake.h"

/////////////////////////////////////////////////////////////////////////////
// CvbBand_Brake

CvbBand_Brake::CvbBand_Brake()
{
}

CvbBand_Brake::~CvbBand_Brake()
{
}


STDMETHODIMP CvbBand_Brake::get_actuator(SAFEARRAY** val)
{
  getPath(0, val);
  return S_OK;
}

STDMETHODIMP CvbBand_Brake::get_n(SAFEARRAY** val)
{
  getPath(1, val);
  return S_OK;
}

STDMETHODIMP CvbBand_Brake::get_p(SAFEARRAY** val)
{
  getPath(2, val);
  return S_OK;
}

