/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Chart
//!	Generated Date	: Mon, 9, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\Chart.cpp
*********************************************************************/

#include "Chart.h"
//#include "OnPlot_i.c"
//#include "OnPlot.h"
#include "ChartDialog.h"
//## package GUIModels 

//----------------------------------------------------------------------------
// Chart.cpp                                                                  
//----------------------------------------------------------------------------
//## class Chart 



Chart::Chart() : bInit(false) ,m_cRef(0) ,m_dialog(NULL) {
    //#[ operation Chart() 
    bInit= false;
    init();
    
    //#]
}

Chart::~Chart() {
    //#[ operation ~Chart() 
    clean();
    
    //#]
}

long Chart::AddRef() {
    //#[ operation AddRef() 
    return ++m_cRef;
    //#]
}

long Chart::Release() {
    //#[ operation Release() 
    m_cRef--;
    if (m_cRef <= 0)
      delete this;
    
    return m_cRef;
    //#]
}

void Chart::SetName(const _TCHAR * caption) {
    //#[ operation SetName(const _TCHAR * ) 
    m_dialog->SetCaption(caption);
    //#]
}

void Chart::clean() {
    //#[ operation clean() 
    if (m_dialog)
    {
      delete m_dialog;
      m_dialog = NULL;
    }  
    //#]
}

void Chart::handle_plotData(const double time, double * vals, long cVals) {
    //#[ operation handle_plotData(const double ,double * ,long ) 
    if(!bInit)
    {
      CComBSTR bstrSeries;
      for (long i = 0; i < cVals; i++)
      {
        bstrSeries = L"Series";
        m_dialog->addSeries(bstrSeries);
      }
      bInit = true;
    } 
    
    m_dialog->plotData(time, vals, cVals);
    //#]
}

void Chart::handle_plotData(const double time, long * vals, long cVals) {
    //#[ operation handle_plotData(const double ,long * ,long ) 
    if(!bInit)
    {
      CComBSTR bstrSeries;
      for (long i = 0; i < cVals; i++)
      {
        bstrSeries = L"Series";
        m_dialog->addSeries(bstrSeries);
      }
      bInit = true;
    } 
    
    m_dialog->plotData(time, vals, cVals);
    //#]
}

void Chart::handle_tick() {
    //#[ operation handle_tick() 
    receive();
    //#]
}

void Chart::init() {
    //#[ operation init() 
    //HRESULT hr = S_OK;  
    //hr = CoCreateInstance(CLSID_OnPlotDlgMgr, NULL, CLSCTX_INPROC_SERVER, IID__OnPlotDlgMgr, (void**) &m_dialog);
    //m_dialog->ShowChart();
    //_ASSERTE(hr == S_OK);
    //bInit=true;
    
    m_dialog = new CChartDialog();
    m_dialog->Show();
    bInit = true;
    //#]
}




/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Chart.cpp
*********************************************************************/

