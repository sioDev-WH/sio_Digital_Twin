/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: CChartDlg
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\CChartDlg.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "CChartDlg.h"
#include <stdafx.h>
#include "TeeChart5.h"
#include "TeeChart5_i.c"

//## package DisplayPkg 


//#[ ignore 
#define DisplayPkg_CChartDlg_CChartDlg_SERIALIZE OM_NO_OP


#define DisplayPkg_CChartDlg_GetChart_SERIALIZE OM_NO_OP


#define DisplayPkg_CChartDlg_GetPosition_SERIALIZE \
    aomsmethod->addAttribute("x", x2String(x)); \
    aomsmethod->addAttribute("y", x2String(y)); \
    aomsmethod->addAttribute("nWidth", x2String(nWidth)); \
    aomsmethod->addAttribute("nHeight", x2String(nHeight));


#define DisplayPkg_CChartDlg_Move_SERIALIZE \
    aomsmethod->addAttribute("x", x2String(x)); \
    aomsmethod->addAttribute("y", x2String(y)); \
    aomsmethod->addAttribute("nWidth", x2String(nWidth)); \
    aomsmethod->addAttribute("nHeight", x2String(nHeight));


#define DisplayPkg_CChartDlg_SetCaption_SERIALIZE aomsmethod->addAttribute("szCaption", x2String(szCaption));


#define DisplayPkg_CChartDlg_SetLegends_SERIALIZE \
    aomsmethod->addAttribute("nSeries", x2String(nSeries)); \
    aomsmethod->addAttribute("pLegend", x2String(pLegend));


#define DisplayPkg_CChartDlg_Show_SERIALIZE OM_NO_OP


#define DisplayPkg_CChartDlg_addSeries_SERIALIZE \
    aomsmethod->addAttribute("bPoint", x2String(bPoint)); \
    aomsmethod->addAttribute("Name", x2String(Name));


#define DisplayPkg_CChartDlg_clean_SERIALIZE OM_NO_OP


#define DisplayPkg_CChartDlg_cleanPlot_SERIALIZE OM_NO_OP


#define DisplayPkg_CChartDlg_init_SERIALIZE OM_NO_OP


#define DisplayPkg_CChartDlg_initPlot_SERIALIZE \
    aomsmethod->addAttribute("numberOfSeries", x2String(numberOfSeries)); \
    aomsmethod->addAttribute("bPoint", x2String(bPoint)); \
    aomsmethod->addAttribute("pNames", x2String(pNames));


#define DisplayPkg_CChartDlg_plotData_SERIALIZE \
    aomsmethod->addAttribute("time", x2String(time)); \
    aomsmethod->addAttribute("vars", x2String(vars)); \
    aomsmethod->addAttribute("count", x2String(count));


#define DisplayPkg_CChartDlg_plotSeriesData_SERIALIZE \
    aomsmethod->addAttribute("time", x2String(time)); \
    aomsmethod->addAttribute("var", x2String(var));
//#]

//----------------------------------------------------------------------------
// CChartDlg.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(DisplayPkg)
//## class CChartDlg 



CChartDlg::CChartDlg() : m_pChart(NULL) {
    NOTIFY_CONSTRUCTOR(CChartDlg, CChartDlg(), 0, DisplayPkg_CChartDlg_CChartDlg_SERIALIZE);
    //#[ operation CChartDlg() 
    init();
    //#]
}

CChartDlg::~CChartDlg() {
    NOTIFY_DESTRUCTOR(~CChartDlg, TRUE);
    //#[ operation ~CChartDlg() 
    if (m_pChart)
    {
      m_pChart->Release();
      m_pChart = NULL;
    }
    clean();
    
    //#]
}

ITChart *  CChartDlg::GetChart() {
    NOTIFY_OPERATION(GetChart, GetChart(), 0, DisplayPkg_CChartDlg_GetChart_SERIALIZE);
    //#[ operation GetChart() 
    return m_pChart;
    
    //#]
}

void CChartDlg::GetPosition(int * x, int * y, int * nWidth, int * nHeight) {
    NOTIFY_OPERATION(GetPosition, GetPosition(int * ,int * ,int * ,int * ), 4, DisplayPkg_CChartDlg_GetPosition_SERIALIZE);
    //#[ operation GetPosition(int * ,int * ,int * ,int * ) 
    RECT rect;
    m_wnd.GetWindowRect(&rect); 
    *x = rect.left;
    *y = rect.top;
    *nWidth = rect.right - rect.left;
    *nHeight = rect.bottom - rect.top;
    
    //#]
}

void CChartDlg::Move(const int x, const int y, const int nWidth, const int nHeight) {
    NOTIFY_OPERATION(Move, Move(const int ,const int ,const int ,const int ), 4, DisplayPkg_CChartDlg_Move_SERIALIZE);
    //#[ operation Move(const int ,const int ,const int ,const int ) 
    m_wnd.MoveWindow(x, y, nWidth, nHeight);
    
    //#]
}

void CChartDlg::SetCaption(LPCTSTR szCaption) {
    NOTIFY_OPERATION(SetCaption, SetCaption(LPCTSTR ), 1, DisplayPkg_CChartDlg_SetCaption_SERIALIZE);
    //#[ operation SetCaption(LPCTSTR ) 
    m_wnd.SetWindowText(szCaption);
    
    //#]
}

void CChartDlg::SetLegends(const long  nSeries, BSTR *  pLegend) {
    NOTIFY_OPERATION(SetLegends, SetLegends(const long ,BSTR *), 2, DisplayPkg_CChartDlg_SetLegends_SERIALIZE);
    //#[ operation SetLegends(const long ,BSTR *) 
    
    // LegendString(LegendIndex: Integer; LegendTextStyle: ELegendTextStyle): WideString;
    int i;
    
    
        for(i=0;i<nSeries;i++)   
        	m_pChart->SeriesTitleLegend(i,&pLegend[i]);    
    
    //#]
}

void CChartDlg::Show() {
    NOTIFY_OPERATION(Show, Show(), 0, DisplayPkg_CChartDlg_Show_SERIALIZE);
    //#[ operation Show() 
    m_wnd.ShowWindow( SW_SHOWNORMAL );
    m_wnd.SetActiveWindow();
    
    //#]
}

void CChartDlg::addSeries(const bool bPoint, BSTR Name) {
    NOTIFY_OPERATION(addSeries, addSeries(const bool ,BSTR ), 2, DisplayPkg_CChartDlg_addSeries_SERIALIZE);
    //#[ operation addSeries(const bool ,BSTR ) 
    long i;
    ESeriesClass series;
    CComPtr<IPointer> ptr;
    CComPtr<IPen> pen;
    CComPtr<ILineSeries> pLine;
    CComPtr<IPointSeries> pPoint;
    OLE_COLOR color;
    
    if (!bPoint)
    {
      series = scLine;
      
      m_pChart->AddSeries( series, NULL );
      m_pChart->get_SeriesCount(&i);
      i--;
      m_pChart->Series(i, &(ppSeries[i]) );
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
      m_pChart->AddSeries( series , NULL );
      m_pChart->get_SeriesCount(&i);
      i--;
      m_pChart->Series(i, &ppSeries[i] );
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
    
    //#]
}

void CChartDlg::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, DisplayPkg_CChartDlg_clean_SERIALIZE);
    //#[ operation clean() 
    long i;
    
    for (i = 0; i < 20; i++)
    {
      if (ppSeries[i]) 
      {
        ppSeries[i]->Release();
        ppSeries[i] = NULL;
      }
    }
    
    //ShowWindow(SW_HIDE);
    /*
    BOOL res = m_wnd.DestroyWindow( );
    if (!res)
    {
      DWORD err = GetLastError();
      ATLTRACE("%d", err);
    }
    AtlAxWinTerm();
    */
    
    //#]
}

HRESULT CChartDlg::cleanPlot() {
    NOTIFY_OPERATION(cleanPlot, cleanPlot(), 0, DisplayPkg_CChartDlg_cleanPlot_SERIALIZE);
    //#[ operation cleanPlot() 
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
    
    //#]
}

void CChartDlg::init() {
    NOTIFY_OPERATION(init, init(), 0, DisplayPkg_CChartDlg_init_SERIALIZE);
    //#[ operation init() 
    long i;
    int x = 500;
    int y = 300;
    int width = 400;
    int height = 400;
    
    m_SeriesCount = 0;
    
    RECT rect = { 500, 300, 400, 400 };
    DWORD dwStyle = WS_POPUPWINDOW | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SIZEBOX | WS_CAPTION | WS_VISIBLE;
    
    CComBSTR bstrId = CLSID_TChart;
    
    AtlAxWinInit();
    m_wnd.m_hWnd = m_wnd.Create(NULL, rect, bstrId, dwStyle, WS_EX_CLIENTEDGE);
    HRESULT hr = m_wnd.QueryControl( IID_ITChart, reinterpret_cast<void**> (&m_pChart) );
    _ASSERTE(hr == S_OK);
    
    plotColors[0] = 0xFF00FF;  // vbMagenta;
    plotColors[1] = 0xFF0000;  // vbBlue;
    plotColors[2] = 0xFF;      // vbRed;
    plotColors[3] = 0x0000000; // vbBlack; 
    plotColors[4] = 0xFF00;    // vbGreen;
    plotColors[5] = 0xFFFF;    // vbYellow;
    
    
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
    pGradient->put_EndColor(   (OLE_COLOR) 0xFFFF00);
     
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
    
    ITitles* pTitles = NULL;
    IStrings* pText = NULL;
    m_pChart->get_Header(&pTitles);
    pTitles->get_Text(&pText);
    pText->Clear();
    pText->Release();
    pTitles->Release();
    
    for (i = 0; i < 20; i++) ppSeries[i] = NULL;
    
    //#]
}

void CChartDlg::initPlot(const long numberOfSeries, const bool bPoint, BSTR * pNames) {
    NOTIFY_OPERATION(initPlot, initPlot(const long ,const bool ,BSTR * ), 3, DisplayPkg_CChartDlg_initPlot_SERIALIZE);
    //#[ operation initPlot(const long ,const bool ,BSTR * ) 
    long i;
    
    m_pChart->RemoveAllSeries();
    
    for (i = 0; i < numberOfSeries; i++)
    {
      if (pNames)
        addSeries(bPoint, pNames[i]);
      else
        addSeries(bPoint, NULL);
    }
    
    //#]
}

void CChartDlg::plotData(const double time, const double * vars, const long count) {
    NOTIFY_OPERATION(plotData, plotData(const double ,const double * ,const long ), 3, DisplayPkg_CChartDlg_plotData_SERIALIZE);
    //#[ operation plotData(const double ,const double * ,const long ) 
    long i;
    long res;
    HRESULT hr = S_OK;
    
    for (i = 0; i < count; i++)
    {
      hr = ppSeries[i]->AddXY( time, vars[i], L"", plotColors[i], &res);
      _ASSERTE(SUCCEEDED(hr));
    }
    
    //#]
}

void CChartDlg::plotSeriesData(const double time, double  var) {
    NOTIFY_OPERATION(plotSeriesData, plotSeriesData(const double ,double), 2, DisplayPkg_CChartDlg_plotSeriesData_SERIALIZE);
    //#[ operation plotSeriesData(const double ,double) 
    long i;
    long res;
    HRESULT hr = S_OK;
    ISeries* pSeries = NULL; 
    m_pChart->get_SeriesCount(&i);
    
    m_pChart->Series(i-1, &pSeries);
    pSeries->AddXY( time, var, L"", plotColors[i], &res);
    pSeries->Release();
    
    //#]
}

long CChartDlg::getM_SeriesCount() const {
    return m_SeriesCount;
}

void CChartDlg::setM_SeriesCount(long  p_m_SeriesCount) {
    m_SeriesCount = p_m_SeriesCount;
}

ITChart* CChartDlg::getM_pChart() const {
    return m_pChart;
}

void CChartDlg::setM_pChart(ITChart*  p_m_pChart) {
    m_pChart = p_m_pChart;
}

CAxWindow  CChartDlg::getM_wnd() const {
    return m_wnd;
}

void CChartDlg::setM_wnd(CAxWindow p_m_wnd) {
    m_wnd = p_m_wnd;
}

OLE_COLOR CChartDlg::getPlotColors(int  i1) const {
    return plotColors[i1];
}

void CChartDlg::setPlotColors(int  i1, OLE_COLOR  p_plotColors) {
    plotColors[i1] = p_plotColors;
}

ISeries* CChartDlg::getPpSeries(int  i1) const {
    return ppSeries[i1];
}

void CChartDlg::setPpSeries(int  i1, ISeries*  p_ppSeries) {
    ppSeries[i1] = p_ppSeries;
}



#ifdef _OMINSTRUMENT


void OMAnimatedCChartDlg::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("plotColors", array2String(20, (OLE_COLOR*)myReal->plotColors, sizeof(OLE_COLOR), &x2String));
    aomsAttributes->addAttribute("m_SeriesCount", x2String(myReal->m_SeriesCount));
    aomsAttributes->addAttribute("m_wnd", x2String(myReal->m_wnd));
    aomsAttributes->addAttribute("m_pChart", x2String(myReal->m_pChart));
    aomsAttributes->addAttribute("ppSeries", array2String(20, (ISeries**)myReal->ppSeries, sizeof(ISeries*), &x2String));
}

IMPLEMENT_META(CChartDlg, DisplayPkg, FALSE, OMAnimatedCChartDlg)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\CChartDlg.cpp
*********************************************************************/

