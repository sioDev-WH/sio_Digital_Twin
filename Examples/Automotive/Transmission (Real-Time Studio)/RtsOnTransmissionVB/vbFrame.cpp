// vbFrame.cpp : Implementation of CvbFrame
#include "stdafx.h"
#include "RtsOnTransmissionVB.h"
#include "vbFrame.h"

/////////////////////////////////////////////////////////////////////////////
// CvbFrame

CvbFrame::CvbFrame()
{
}

CvbFrame::~CvbFrame()
{
}


STDMETHODIMP CvbFrame::get_p(SAFEARRAY** val)
{
  getPath(0, val);
  return S_OK;
}
