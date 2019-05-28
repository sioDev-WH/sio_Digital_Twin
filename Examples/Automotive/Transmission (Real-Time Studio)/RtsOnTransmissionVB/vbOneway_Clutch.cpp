// vbOneway_Clutch.cpp : Implementation of CvbOneway_Clutch
#include "stdafx.h"
#include "RtsOnTransmissionVB.h"
#include "vbOneway_Clutch.h"

/////////////////////////////////////////////////////////////////////////////
// CvbOneway_Clutch

CvbOneway_Clutch::CvbOneway_Clutch()
{
}

CvbOneway_Clutch::~CvbOneway_Clutch()
{
}


STDMETHODIMP CvbOneway_Clutch::get_actuator(SAFEARRAY** val)
{
  getPath(0, val);
  return S_OK;
}

STDMETHODIMP CvbOneway_Clutch::get_n(SAFEARRAY** val)
{
  getPath(1, val);
  return S_OK;
}

STDMETHODIMP CvbOneway_Clutch::get_p(SAFEARRAY** val)
{
  getPath(2, val);
  return S_OK;
}

