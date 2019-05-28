// COnTransModelFactory.cpp : Implementation of CCOnTransModelFactory
#include "stdafx.h"
#include "OnTransmission.h"
#include "COnTransModelFactory.h"
#include "OnTransMSF.h"
#include "OnewayMSF.h"
#include "OnRavMSF.h"
#include "COneClutch.h"

/////////////////////////////////////////////////////////////////////////////
// CCOnTransModelFactory

STDMETHODIMP COnTransModelFactory::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IOnTransModelFactory
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP COnTransModelFactory::CreateModel(BSTR bstrName, IDispatch **pModel)
{
  HRESULT hr = E_INVALIDARG;
  IIsDaeEsoCImpl* pEsoImpl = NULL;
  IOnUMLDaeEsoBase* pEso = NULL;

  CComBSTR Name = bstrName;
  if (Name == L"OnTransMSF")
  {
    pEso = new COnTransMSF();
    hr = S_OK;
  }
  if (Name == L"OneWayMSF")
  {
    pEso = new COneWayMSF();
    hr = S_OK;
  }
  if (Name == L"OnRavMSF")
  {
    pEso = new COneClutch();
    hr = S_OK;
  }

  if (SUCCEEDED(hr))
  {
    hr = CoCreateInstance(CLSID_IsDaeEsoCImpl, NULL, CLSCTX_INPROC_SERVER, IID_IIsDaeEsoCImpl, reinterpret_cast<void**> (&pEsoImpl) );
    if (SUCCEEDED(hr))
    {
      hr = pEsoImpl->SetEso(pEso);
      if (SUCCEEDED(hr))
        *pModel = pEsoImpl;
    }
  }

  if (FAILED(hr))
  {
    if (pEso) pEso->Release();
    if (pEsoImpl) pEsoImpl->Release();
  }

	return hr;
}
