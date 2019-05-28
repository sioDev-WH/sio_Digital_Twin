#ifndef __VBBASE_H
#define __VBBASE_H

template <class T>
class vbBase
{
public:
  vbBase()
  {
    m_pEso = NULL;
    m_pEsoImpl = NULL;
  }

  ~vbBase()
  {
    if (m_pEso)
    {
      m_pEso->Release();
      m_pEso = NULL;
    }

    if (m_pEsoImpl)
    {
      m_pEsoImpl->Release();
      m_pEsoImpl = NULL;
    }
  }

public:
  STDMETHODIMP get_Eso(IDispatch **pModel)
  {
    HRESULT hr = E_INVALIDARG;

    if (!m_pEso)
    {
      m_pEso = new T();
      m_pEso->AddRef();
    }

    if (m_pEsoImpl)
    {
      *pModel = m_pEsoImpl;
      m_pEsoImpl->AddRef();
    }
    else
    {
      hr = CoCreateInstance(CLSID_IsDaeEsoCImpl, NULL, CLSCTX_INPROC_SERVER, IID_IIsDaeEsoCImpl, reinterpret_cast<void**> (&m_pEsoImpl) );
      if (SUCCEEDED(hr))
      {
        hr = m_pEsoImpl->SetEso(m_pEso);
        if (SUCCEEDED(hr))
        {
          *pModel = m_pEsoImpl;
          m_pEsoImpl->AddRef();
        }
      }
    }

	  return hr;
  }

  HRESULT getPath(/*[in]*/ long iConn, /*[in, out]*/ SAFEARRAY** ppsaPath)
  {
    HRESULT hr;
    long* vec = NULL;
    long val;
    bool bAlloc = true;
    long ubound, lbound;

    if (*ppsaPath)
    {
      SafeArrayGetUBound(*ppsaPath, (UINT) 1, &ubound);
      SafeArrayGetLBound(*ppsaPath, (UINT) 1, &lbound);
      if ((ubound - lbound + 1) == 2)
        bAlloc = false;
      else
        SafeArrayDestroy(*ppsaPath);
    }

    if (bAlloc) 
      *ppsaPath = SafeArrayCreateVector(VT_I4, 0, 2);

    SafeArrayAccessData(*ppsaPath, (void HUGEP* FAR*)& vec);

    if (m_pEsoImpl)
    {
      m_pEsoImpl->get_ContainerIndex(&val);
      vec[0] = val - 1;  // container index in CImpl model is offset by one (the base Eso)
      vec[1] = iConn;
      hr = S_OK;
    }
    else
    {
      vec[0] = 0;
      vec[1] = 0;
      hr = E_FAIL;
    }
    
    SafeArrayUnaccessData(*ppsaPath);

    return hr;
  }

protected:
  T* m_pEso;
  IIsDaeEsoCImpl* m_pEsoImpl;

};

#endif // __VBBASE_H