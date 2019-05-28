// OnChart.cpp : Implementation of COnChart
#include "stdafx.h"
#include "RtsOnTransmission.h"
#include "OnChart.h"
#include "ChartDlg.h"

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

/////////////////////////////////////////////////////////////////////////////
// COnChart


COnChart::COnChart()
{
  m_bInit = false;
  m_dlg = new CChartDlg();
}


COnChart::~COnChart()
{
  if (m_dlg) delete m_dlg;
}


STDMETHODIMP COnChart::Show()
{
  m_dlg->Show();
	return S_OK;
}

STDMETHODIMP COnChart::SetCaption(BSTR szCaption)
{
  CComBSTR caption = szCaption;
  m_dlg->SetCaption(caption);
  return S_OK;
}


STDMETHODIMP COnChart::Hide()
{
	return S_OK;
}

STDMETHODIMP COnChart::Move( int x, int y, int nWidth, int nHeight)
{
  m_dlg->Move(x, y, nWidth, nHeight);
  return S_OK;
}

STDMETHODIMP COnChart::initPlot(long numberOfSeries, VARIANT_BOOL vbPoint, SAFEARRAY** ppsaNames)
{
  bool bPoint = vbPoint == VARIANT_TRUE ? true : false;
  BSTR* pNames = NULL;

  if (ppsaNames) SafeArrayAccessData(*ppsaNames, (void HUGEP* FAR*)& pNames);
  m_dlg->initPlot(numberOfSeries, bPoint, pNames);
  if (ppsaNames) SafeArrayUnaccessData(*ppsaNames);

  m_bInit = true;
	return S_OK;
}

STDMETHODIMP COnChart::plotData(double t, SAFEARRAY** psaVals, long count)
{
  double* pVals = NULL;

  if (!m_bInit) initPlot(count, VARIANT_FALSE, NULL);
  SafeArrayAccessData(*psaVals, (void HUGEP* FAR*)& pVals);
  m_dlg->plotData(t, pVals, count);
  SafeArrayUnaccessData(*psaVals);
  return S_OK;
}

STDMETHODIMP COnChart::cleanPlot()
{
  return m_dlg->cleanPlot();
}

STDMETHODIMP COnChart::GetPosition(int *x, int *y, int *nWidth, int *nHeight)
{
  m_dlg->GetPosition(x, y, nWidth, nHeight); 
	return S_OK;
}

STDMETHODIMP COnChart::AddSeries(BSTR SeriesName)
{
	m_dlg->addSeries(false, SeriesName);
	return S_OK;
}

STDMETHODIMP COnChart::plotSeriesData(double t, double val)
{
	m_dlg->plotSeriesData(t, val); 
	return S_OK;
}
