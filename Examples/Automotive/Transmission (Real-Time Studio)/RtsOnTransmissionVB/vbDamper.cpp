// vbDamper.cpp : Implementation of CvbDamper
#include "stdafx.h"
#include "RtsOnTransmissionVB.h"
#include "vbDamper.h"

/////////////////////////////////////////////////////////////////////////////
// CvbDamper

CvbDamper::CvbDamper()
{
}

CvbDamper::~CvbDamper()
{
}


STDMETHODIMP CvbDamper::get_n(SAFEARRAY** val)
{
  getPath(0, val);
  return S_OK;
}

STDMETHODIMP CvbDamper::get_p(SAFEARRAY** val)
{
  getPath(1, val);
  return S_OK;
}

