// ChartDialog.cpp : Implementation of CChartDialog
#include "stdafx.h"
#include "ChartDialog.h"
#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CChartDialog

CChartDialog::CChartDialog()
{
  m_dlg = NULL;
}

CChartDialog::~CChartDialog()
{
  if (m_dlg)
  {
    m_dlg->Release();
    m_dlg = NULL;
    BOOL bRet = DestroyWindow();
  }
}


LRESULT CChartDialog::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
  HRESULT hr = S_OK;
  HWND _hwnd = GetDlgItem( IDC_TCHART1 );
  IUnknown* pUnk = NULL;
  AtlAxGetControl( _hwnd, &pUnk );
  pUnk->QueryInterface( &m_dlg ); 
  pUnk->Release();

  plotColors[0] = 0xFF00FF;  // vbMagenta;
  plotColors[1] = 0xFF0000;  // vbBlue;
  plotColors[2] = 0xFF;      // vbRed;
  plotColors[3] = 0x0000000; // vbBlack; 
  plotColors[4] = 0xFF00;    // vbGreen;
  plotColors[5] = 0xFFFF;    // vbYellow;
  
  IZoom* pZoom = NULL;
  m_dlg->get_Zoom(&pZoom);
  pZoom->put_Enable(VARIANT_TRUE);
  pZoom->Release();
  
  IWalls* pWalls = NULL;
  m_dlg->get_Walls(&pWalls);
  pWalls->put_Visible(VARIANT_FALSE);
  pWalls->Release();
  
  IPanel* pPanel = NULL;
  IGradient* pGradient = NULL;
  m_dlg->get_Panel(&pPanel);
  pPanel->get_Gradient(&pGradient); 
  pGradient->put_Visible(VARIANT_TRUE);
  // 0xbbggrr
  
  //pGradient->put_StartColor( (OLE_COLOR) 0xFF0000); 
  //pGradient->put_EndColor(   (OLE_COLOR) 0x00FF00); 
  pGradient->put_StartColor( (OLE_COLOR) 0xFFFFFF); 
  pGradient->put_EndColor(   (OLE_COLOR) 0xFFFFFF);
  pGradient->put_EndColor(   (OLE_COLOR) 0xFFFF00);
   
  pGradient->Release();
  pPanel->Release();
  
  ILegend* pLegend = NULL;
  m_dlg->get_Legend(&pLegend);
  pLegend->put_Visible(VARIANT_TRUE);
  ELegendStyle ls = lsSeries;
  ELegendAlignment la = laTop;
  pLegend->put_LegendStyle( ls );
  pLegend->put_Alignment( la );
  pLegend->Release();
  
  IAspect* pAspect = NULL;
  m_dlg->get_Aspect(&pAspect);     
  pAspect->put_View3D(VARIANT_FALSE);
  pAspect->Release();
  
  ITitles* pTitles = NULL;
  IStrings* pText = NULL;
  m_dlg->get_Header(&pTitles);
  pTitles->get_Text(&pText);
  pText->Clear();
  pText->Release();
  pTitles->Release();
 

	return 1;  // Let the system set the focus
}

void CChartDialog::SetCaption(LPCTSTR szCaption) 
{
  SetWindowText(szCaption);
}

void CChartDialog::Show() 
{
  //DoModal();
  Create(NULL);
  ShowWindow( SW_SHOWNORMAL );
  SetActiveWindow();
}


void CChartDialog::addSeries(BSTR Name) 
{
  long i;
  ESeriesClass series;
  CComPtr<IPointer> ptr;
  CComPtr<IPen> pen;
  CComPtr<ILineSeries> pLine;
  OLE_COLOR color;
  ISeries* pSeries = NULL;
  long value = 0;

  series = scLine;
  m_dlg->AddSeries( series , &value );
  m_dlg->get_SeriesCount(&i);
  i--;
  m_dlg->Series(i, &pSeries );
  pSeries->put_Color( plotColors[i] );
  if (Name) pSeries->put_Title( Name );
  pSeries->put_ShowInLegend( VARIANT_TRUE );
  pSeries->get_asLine(&pLine);
  pLine->get_Pointer(&ptr);
  ptr->put_Style( psCircle );
  ptr->put_HorizontalSize( 1 );
  ptr->put_VerticalSize( 1 );
  ptr->get_Pen(&pen);
  color = plotColors[i];
  pen->put_Color( color );
  pLine.Release();
  ptr.Release();
  pen.Release();
  pSeries->Release();
}

void CChartDialog::initPlot(const long count, BSTR * pNames) 
{
  long i;
  
  for (i = 0; i < count; i++)
  {
    if (pNames)
      addSeries(pNames[i]);
    else
      addSeries(NULL);
  }
}

void CChartDialog::plotData(const double time, const double * vars, const long count) 
{
  long i;
  long seriesCount = 0;
  HRESULT hr = S_OK;
  ISeries* pSeries = NULL; 
  CComBSTR label = L"";
  long AColor;

  m_dlg->get_SeriesCount(&seriesCount);

  if (count > seriesCount)
  {
    for (i = seriesCount; i < count; i++)
      addSeries(L"Series");
  }

  for (i = 0; i < count; i++)
  {
    m_dlg->Series(i, &pSeries);
    AColor = plotColors[i];
    pSeries->AddXY( time, vars[i], label, plotColors[i], &AColor);
    pSeries->Release();
  }
}

void CChartDialog::plotData(const double time, const long * vars, const long count) 
{
  long i;
  long seriesCount = 0;
  long AColor;
  HRESULT hr = S_OK;
  ISeries* pSeries = NULL; 
  CComBSTR label = L"";
  double val;

  m_dlg->get_SeriesCount(&seriesCount);

  if (count > seriesCount)
  {
    for (i = seriesCount; i < count; i++)
      addSeries(L"Series");
  }
  

  for (i = 0; i < count; i++)
  {
    m_dlg->Series(i, &pSeries);
    AColor = plotColors[i];
    val = (double) vars[i];
    pSeries->AddXY( time, val, label, plotColors[i], &AColor);
    pSeries->Release();
  }
}

void CChartDialog::plotSeriesData(const double time, double  var) 
{
  long i;
  long res;
  ISeries* pSeries = NULL; 

  m_dlg->get_SeriesCount(&i);
  m_dlg->Series(i-1, &pSeries);
  pSeries->AddXY( time, var, L"", plotColors[i], &res);
  pSeries->Release();
}
