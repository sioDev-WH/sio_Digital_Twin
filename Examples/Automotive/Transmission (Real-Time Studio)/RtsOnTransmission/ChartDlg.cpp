// ChartDlg.cpp : Implementation of CChart
#include "stdafx.h"
#include "ChartDlg.h"
#include <math.h>

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

/////////////////////////////////////////////////////////////////////////////
// CChart


void CChartDlg::init()
{
  long i;
  int x = 500;
  int y = 300;
  int width = 400;
  int height = 400;

  m_SeriesCount = 0;

  RECT rect = { 500, 300, 400, 400 };
  DWORD dwStyle = WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SIZEBOX | WS_CAPTION | WS_VISIBLE;

  CComBSTR bstrId = CLSID_TChart;

  AtlAxWinInit();
  m_wnd.m_hWnd = m_wnd.Create(NULL, rect, bstrId, dwStyle, WS_EX_CLIENTEDGE);
  HRESULT hr = m_wnd.QueryControl( IID_ITChart, reinterpret_cast<void**> (&m_pChart) );
  _ASSERTE(hr == S_OK);

  plotColors[0] = 0xFF00FF;  // vbMagenta;
  plotColors[1] = 0xFF0000;  // vbBlue;
  plotColors[2] = 0xFFFF;    // vbYellow;
  plotColors[3] = 0xFF00;    // vbGreen;
  plotColors[4] = 0x0000000; // vbBlack;
  plotColors[5] = 0xFF;      // vbRed;


  m_wnd.MoveWindow(x, y, width, height);

  IZoom* pZoom = NULL;
  m_pChart->get_Zoom(&pZoom);
  pZoom->put_Enable(VARIANT_TRUE);
  pZoom->Release();

  IWalls* pWalls = NULL;
  m_pChart->get_Walls(&pWalls);
  pWalls->put_Visible(VARIANT_FALSE);
  pWalls->Release();

  IPanel* pPanel = NULL;
  IGradient* pGradient = NULL;
  m_pChart->get_Panel(&pPanel);
  pPanel->get_Gradient(&pGradient); 
  pGradient->put_Visible(VARIANT_TRUE);
  // 0xbbggrr

  //pGradient->put_StartColor( (OLE_COLOR) 0xFF0000); 
  //pGradient->put_EndColor(   (OLE_COLOR) 0x00FF00); 
  pGradient->put_StartColor( (OLE_COLOR) 0xFFFFFF); 
  pGradient->put_EndColor(   (OLE_COLOR) 0xFFFFFF); 
  pGradient->Release();
  pPanel->Release();

  ILegend* pLegend = NULL;
  m_pChart->get_Legend(&pLegend);
  pLegend->put_Visible(VARIANT_TRUE);
  ELegendStyle ls = lsSeries;
  ELegendAlignment la = laTop;
  pLegend->put_LegendStyle( ls );
  pLegend->put_Alignment( la );
  pLegend->Release();

  IAspect* pAspect = NULL;
  m_pChart->get_Aspect(&pAspect);     
  pAspect->put_View3D(VARIANT_FALSE);
  pAspect->Release();

  for (i = 0; i < 20; i++) ppSeries[i] = NULL;
}

void CChartDlg::Show()
{
  m_wnd.ShowWindow( SW_SHOWNORMAL );
  m_wnd.SetActiveWindow();
}

void CChartDlg::SetCaption(LPCTSTR szCaption)
{
  m_wnd.SetWindowText(szCaption);
}

void CChartDlg::GetPosition(int* x, int* y, int* nWidth, int* nHeight)
{
  RECT rect;
  m_wnd.GetWindowRect(&rect); 
  *x = rect.left;
  *y = rect.top;
  *nWidth = rect.right - rect.left;
  *nHeight = rect.bottom - rect.top;

}

void CChartDlg::Move(const int x, const int y, const int nWidth, const int nHeight)
{
  m_wnd.MoveWindow(x, y, nWidth, nHeight);
}

void CChartDlg::clean()
{
  long i;

  for (i = 0; i < 20; i++)
  {
    if (ppSeries[i]) 
    {
      ppSeries[i]->Release();
      ppSeries[i] = NULL;
    }
  }

 	m_pChart.Release();
  //ShowWindow(SW_HIDE);
  BOOL res = m_wnd.DestroyWindow( );
  if (!res)
  {
    DWORD err = GetLastError();
    ATLTRACE("%d", err);
  }
  AtlAxWinTerm();
}

void CChartDlg::initPlot(const long numberOfSeries, const bool bPoint, BSTR* pNames)
{
  long i;

  m_pChart->RemoveAllSeries();

  for (i = 0; i < numberOfSeries; i++)
  {
    if (pNames)
      addSeries(bPoint, pNames[i]);
    else
      addSeries(bPoint, NULL);
  }

}

void CChartDlg::addSeries(const bool bPoint, BSTR Name)
{
  long i;
  ESeriesClass series;
  CComPtr<IPointer> ptr;
  CComPtr<IPen> pen;
  CComPtr<ICustomSeries> pLine;
  CComPtr<IPointSeries> pPoint;
  OLE_COLOR color;

  if (!bPoint)
  {
    series = scLine;
    m_pChart->AddSeries( series );
    m_pChart->get_SeriesCount(&i);
    i--;
    m_pChart->get_Series(i, &(ppSeries[i]) );
    ppSeries[i]->put_Color( plotColors[i] );
    if (Name) ppSeries[i]->put_Title( Name );
    ppSeries[i]->put_ShowInLegend( VARIANT_TRUE );
    ppSeries[i]->get_asLine(&pLine);
    pLine->get_Pointer(&ptr);
    ptr->put_Style( psCircle );
    ptr->put_HorizontalSize( 1 );
    ptr->put_VerticalSize( 1 );
    ptr->get_Pen(&pen);
    color = 0xFF;      // vbRed;
    pen->put_Color( color );
    pLine.Release();
    ptr.Release();
    pen.Release();
  }
  else
  {
    series = scPoint;
    m_pChart->AddSeries( series );
    m_pChart->get_SeriesCount(&i);
    i--;
    m_pChart->get_Series(i, &ppSeries[i] );
    ppSeries[i]->put_Color( plotColors[i] );
    if (Name) ppSeries[i]->put_Title( Name );
    ppSeries[i]->put_ShowInLegend( VARIANT_TRUE );
    ppSeries[i]->get_asPoint(&pPoint);
    pPoint->get_Pointer(&ptr);
    ptr->put_Style( psCircle );
    ptr->put_HorizontalSize( 2 );
    ptr->put_VerticalSize( 2 );
    ptr->get_Pen(&pen);
    color = 0xFF;      // vbRed;
    pen->put_Color( color );
    pLine.Release();
    ptr.Release();
    pen.Release();

  }

  m_SeriesCount++;
}

void MessagePump();

void CChartDlg::plotSeriesData(const double time, double var)
{
  long i;
  long res;
  HRESULT hr = S_OK;
  ISeries* pSeries = NULL; 
  m_pChart->get_SeriesCount(&i);
  //i = m_SeriesCount;

  m_pChart->get_Series(i-1, &pSeries);
  pSeries->AddXY( time, var, L"", plotColors[i], &res);
  pSeries->Release();

  MessagePump();
}


void CChartDlg::plotData(const double time, const double* vars, const long count)
{
  long i;
  long res;
  HRESULT hr = S_OK;

  for (i = 0; i < count; i++)
  {
    hr = ppSeries[i]->AddXY( time, vars[i], L"", plotColors[i], &res);
    _ASSERTE(SUCCEEDED(hr));
    //ATLTRACE("\n%d\t%e\t%e", res, time, vars[i]);
  }

  MessagePump();
}

HRESULT CChartDlg::cleanPlot()
{
  long i;
  CComBSTR bstrId = CLSID_TChart;

  for (i = 0; i < 20; i++)
  {
    if (ppSeries[i]) 
    {
      ppSeries[i]->Release();
      ppSeries[i] = NULL;
    }
  }

  HRESULT hr = m_wnd.CreateControl( bstrId, NULL, NULL );
  if (SUCCEEDED(hr))
  {
    m_pChart = NULL;
    hr = m_wnd.QueryControl( IID_ITChart, reinterpret_cast<void**> (&m_pChart) );
  }


  return hr;
}
