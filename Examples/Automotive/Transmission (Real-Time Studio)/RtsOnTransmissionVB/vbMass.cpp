// vbMass.cpp : Implementation of CvbMass
#include "stdafx.h"
#include "RtsOnTransmissionVB.h"
#include "vbMass.h"

/////////////////////////////////////////////////////////////////////////////
// CvbMass

CvbMass::CvbMass()
{
}

CvbMass::~CvbMass()
{
}


STDMETHODIMP CvbMass::get_p(SAFEARRAY** val)
{
  getPath(0, val);
  return S_OK;
}

STDMETHODIMP CvbMass::get_n(SAFEARRAY** val)
{
  getPath(1, val);
  return S_OK;
}


