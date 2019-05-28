// IsMatrix.cpp : Implementation of CIsMatrix
#include "stdafx.h"
#include "ISDaeCOSolver.h"
#include "IsMatrix.h"

#if 0
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#endif

/////////////////////////////////////////////////////////////////////////////
// CIsMatrix

STDMETHODIMP CIsMatrix::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IIsMatrix
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

void CIsMatrix::Destroy()
{
  long i;

  if (m_vRows)
  {
    delete[] m_vRows;
    m_vRows = NULL;
  }

  if (m_vMatrix)
  {
    for (i = 0; i < m_nRows; i++)
      SafeArrayUnaccessData(m_vMatrix[i].parray);

    m_vMatrix = NULL;
  }

  if (m_psaMatrix)
  {
    SafeArrayUnaccessData(m_psaMatrix);
    SafeArrayDestroy(m_psaMatrix);
    m_psaMatrix = NULL;
  }

}

STDMETHODIMP CIsMatrix::Init(long nRows, long nCols)
{
  long i;
  
  Destroy();
  m_nRows = nRows;
  m_nCols = nCols;
  m_psaMatrix = SafeArrayCreateVector(VT_VARIANT, 0, nRows);
  SafeArrayAccessData(m_psaMatrix, (void HUGEP* FAR*)& m_vMatrix);
  m_vRows = new double* [m_nRows];
  for (i = 0; i < m_nRows; i++)
  {
    VariantInit(&m_vMatrix[i]);
    m_vMatrix[i].vt = VT_ARRAY | VT_R8;
    m_vMatrix[i].parray = SafeArrayCreateVector(VT_R8, 0, m_nCols);
    SafeArrayAccessData(m_vMatrix[i].parray, (void HUGEP* FAR*)& m_vRows[i]);
  }

  return S_OK;
}

STDMETHODIMP CIsMatrix::Detach(SAFEARRAY** Vals)
{
  long i;

  *Vals = m_psaMatrix;

  // destroy, but don't destroy the m_psaMatrix safe array
  if (m_vRows)
  {
    delete[] m_vRows;
    m_vRows = NULL;
  }

  if (m_vMatrix)
  {
    for (i = 0; i < m_nRows; i++)
      SafeArrayUnaccessData(m_vMatrix[i].parray);

    m_vMatrix = NULL;
  }

  if (m_psaMatrix)
  {
    SafeArrayUnaccessData(m_psaMatrix);
    m_psaMatrix = NULL;
  }

  return S_OK;
}

STDMETHODIMP CIsMatrix::GetData(SAFEARRAY** Vals)
{
  *Vals = m_psaMatrix;
  return S_OK;
}

STDMETHODIMP CIsMatrix::Attach(SAFEARRAY** Vals)
{
  long ubound, lbound;
  long i;

  Destroy();
  m_psaMatrix = *Vals;
  SafeArrayGetLBound(m_psaMatrix, (unsigned int) 1, &lbound);
  SafeArrayGetUBound(m_psaMatrix, (unsigned int) 1, &ubound);
  m_nRows = ubound - lbound + 1;

  SafeArrayAccessData(m_psaMatrix, (void HUGEP* FAR*)& m_vMatrix);
  SafeArrayGetLBound(m_vMatrix[0].parray, (unsigned int) 1, &lbound);
  SafeArrayGetUBound(m_vMatrix[0].parray, (unsigned int) 1, &ubound);
  m_nCols = ubound - lbound + 1;

  m_vRows = new double* [m_nRows];
  for (i = 0; i < m_nRows; i++)
    SafeArrayAccessData(m_vMatrix[i].parray, (void HUGEP* FAR*)& m_vRows[i]);

  return S_OK;
}

STDMETHODIMP CIsMatrix::GetRow(long Row, SAFEARRAY** Vals)
{
  HRESULT hr = E_INVALIDARG;

  if (Row >= 0 && Row < m_nRows)
  {
    *Vals = m_vMatrix[Row].parray;
    hr = S_OK;
  }

  return hr;
}

STDMETHODIMP CIsMatrix::SetRow(long Row, SAFEARRAY** Vals)
{
  long i;
  double* pvData = NULL;
  SafeArrayAccessData(*Vals, (void HUGEP* FAR*)& pvData);
  for (i = 0; i < m_nCols; i++)
    m_vRows[Row][i] = pvData[i];

  SafeArrayUnaccessData(*Vals);
  return S_OK;
}

STDMETHODIMP CIsMatrix::GetCol(long Col, SAFEARRAY** Vals)
{
  long i;
  double* pvData = NULL;
  SafeArrayAccessData(*Vals, (void HUGEP* FAR*)& pvData);
  for (i = 0; i < m_nRows; i++)
    pvData[i] = m_vRows[i][Col];

  SafeArrayUnaccessData(*Vals);
  return S_OK;
}

STDMETHODIMP CIsMatrix::SetCol(long Col, SAFEARRAY** Vals)
{
  long i;
  double* pvData = NULL;
  SafeArrayAccessData(*Vals, (void HUGEP* FAR*)& pvData);
  for (i = 0; i < m_nRows; i++)
    m_vRows[i][Col] = pvData[i];

  SafeArrayUnaccessData(*Vals);
  return S_OK;
}

STDMETHODIMP CIsMatrix::get_Value(long Row, long Col, double* pVal)
{
  *pVal = m_vRows[Row][Col];
  return S_OK;
}

STDMETHODIMP CIsMatrix::put_Value(long Row, long Col, double Val)
{
  m_vRows[Row][Col] = Val;
  return S_OK;
}