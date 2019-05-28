// vbTorque_Converter.cpp : Implementation of CvbTorque_Converter
#include "stdafx.h"
#include "RtsOnTransmissionVB.h"
#include "vbTorque_Converter.h"

/////////////////////////////////////////////////////////////////////////////
// CvbTorque_Converter

CvbTorque_Converter::CvbTorque_Converter()
{
}

CvbTorque_Converter::~CvbTorque_Converter()
{
}


STDMETHODIMP CvbTorque_Converter::get_turbine(SAFEARRAY** val)
{
  getPath(0, val);
  return S_OK;
}

STDMETHODIMP CvbTorque_Converter::get_impeller(SAFEARRAY** val)
{
  getPath(1, val);
  return S_OK;
}

