// vbRavigneaux.cpp : Implementation of CvbRavigneaux
#include "stdafx.h"
#include "RtsOnTransmissionVB.h"
#include "vbRavigneaux.h"

/////////////////////////////////////////////////////////////////////////////
// CvbRavigneaux

CvbRavigneaux::CvbRavigneaux()
{

}

CvbRavigneaux::~CvbRavigneaux()
{
  
}

STDMETHODIMP CvbRavigneaux::get_forwardSun(SAFEARRAY** val)
{
  getPath(0, val);
  return S_OK;
}

STDMETHODIMP CvbRavigneaux::get_reverseSun(SAFEARRAY** val)
{
  getPath(1, val);
  return S_OK;
}

STDMETHODIMP CvbRavigneaux::get_coupler(SAFEARRAY** val)
{
  getPath(2, val);
  return S_OK;
}

STDMETHODIMP CvbRavigneaux::get_ring(SAFEARRAY** val)
{
  getPath(3, val);
  return S_OK;
}
