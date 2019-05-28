// vbSpring.cpp : Implementation of CvbSpring
#include "stdafx.h"
#include "RtsOnTransmissionVB.h"
#include "vbSpring.h"

/////////////////////////////////////////////////////////////////////////////
// CvbSpring

CvbSpring::CvbSpring()
{
}

CvbSpring::~CvbSpring()
{
}


STDMETHODIMP CvbSpring::get_p(SAFEARRAY** val)
{
  getPath(0, val);
  return S_OK;
}

STDMETHODIMP CvbSpring::get_n(SAFEARRAY** val)
{
  getPath(1, val);
  return S_OK;
}
