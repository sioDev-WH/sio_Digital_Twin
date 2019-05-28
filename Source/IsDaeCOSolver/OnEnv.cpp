// OnEnv.cpp : Implementation of COnEnv
#include "stdafx.h"
#include "ISDaeCOSolver.h"
#include "OnEnv.h"

/////////////////////////////////////////////////////////////////////////////
// COnEnv


COnEnv::COnEnv()
{
  // TODO: remove temporary hard coded initialization
  m_DataPath = L"c:\\DemoData\\Data\\";
  m_GraphicPath = L"c:\\DemoData\\graphics\\";
}

STDMETHODIMP COnEnv::get_DataPath(BSTR *pVal)
{
  *pVal = m_DataPath.Copy();
	return S_OK;
}

STDMETHODIMP COnEnv::put_DataPath(BSTR newVal)
{
	m_DataPath = newVal;
	return S_OK;
}


STDMETHODIMP COnEnv::get_GraphicPath(BSTR *pVal)
{
  *pVal = m_GraphicPath.Copy();
	return S_OK;
}

STDMETHODIMP COnEnv::put_GraphicPath(BSTR newVal)
{
	m_GraphicPath = newVal;
	return S_OK;
}
