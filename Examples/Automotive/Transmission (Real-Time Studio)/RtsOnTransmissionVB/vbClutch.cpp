// vbClutch.cpp : Implementation of CvbClutch
#include "stdafx.h"
#include "RtsOnTransmissionVB.h"
#include "vbClutch.h"

/////////////////////////////////////////////////////////////////////////////
// CvbClutch

CvbClutch::CvbClutch()
{
}

CvbClutch::~CvbClutch()
{
}


STDMETHODIMP CvbClutch::get_actuator(SAFEARRAY** val)
{
  getPath(0, val);
  return S_OK;
}

STDMETHODIMP CvbClutch::get_n(SAFEARRAY** val)
{
  getPath(1, val);
  return S_OK;
}

STDMETHODIMP CvbClutch::get_p(SAFEARRAY** val)
{
  getPath(2, val);
  return S_OK;
}
