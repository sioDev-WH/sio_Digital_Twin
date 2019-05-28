/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: CThrottleDlg
//!	Generated Date	: Mon, 20, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\CThrottleDlg.cpp
*********************************************************************/

#include "CThrottleDlg.h"
#include "OnPlot_i.c"
//#include "OnPlot.h"
#import "OnPlot.ocx" no_namespace raw_interfaces_only


//## package GUIModels 

//----------------------------------------------------------------------------
// CThrottleDlg.cpp                                                                  
//----------------------------------------------------------------------------
//## class CThrottleDlg 



CThrottleDlg::CThrottleDlg() {
    //#[ operation CThrottleDlg() 
    init();
    //#]
}

CThrottleDlg::~CThrottleDlg() {
    //#[ operation ~CThrottleDlg() 
    clean();
    //#]
}

void CThrottleDlg::Move(int  x, int  y, int  nWidth, int  nHeight) {
    //#[ operation Move(int,int,int,int) 
    m_wnd.MoveWindow(x, y, nWidth, nHeight);
    //#]
}

void CThrottleDlg::SetCaption(LPCTSTR szCaption) {
    //#[ operation SetCaption(LPCTSTR ) 
    m_wnd.SetWindowText(szCaption);
    //#]
}

void CThrottleDlg::Show() {
    //#[ operation Show() 
    m_wnd.ShowWindow( SW_SHOWNORMAL );
    m_wnd.SetActiveWindow();
    //#]
}

void CThrottleDlg::clean() {
    //#[ operation clean() 
    m_pThrottle.Release();
    //ShowWindow(SW_HIDE); 
    
    /*
    m_wnd.DestroyWindow( );
    AtlAxWinTerm();
    */
    //#]
}

void CThrottleDlg::getThrottle(double * val) {
    //#[ operation getThrottle(double * ) 
    //m_pThrottle->get_Throttle(val);
    *val = 40.0;
    //#]
}

void CThrottleDlg::init() {
    //#[ operation init() 
    int x = 0;
    int y = 0;
    int width = 200;
    int height = 300;
    RECT rect = { 100, 100, 200, 300 };
    DWORD dwStyle = WS_POPUPWINDOW | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SIZEBOX | WS_CAPTION | WS_VISIBLE;
    
    CComBSTR bstrId = CLSID_OnThrottle;
    
    AtlAxWinInit();
    m_wnd.m_hWnd = m_wnd.Create(NULL, rect, bstrId, dwStyle, WS_EX_CLIENTEDGE);
    HRESULT hr = m_wnd.QueryControl( IID__OnThrottle, reinterpret_cast<void**> (&m_pThrottle) );
    _ASSERTE(hr == S_OK);
    m_wnd.SetWindowText(L"Throttle");
    Move(x, y, width, height);

    double val = 0.0;
    m_pThrottle->get_Throttle(&val);
    //#]
}

void CThrottleDlg::setThrottle(double *  val) {
    //#[ operation setThrottle(double *) 
    m_pThrottle->put_Throttle(val);
    //#]
}

CComPtr<_OnThrottle>  CThrottleDlg::getM_pThrottle() const {
    return m_pThrottle;
}

void CThrottleDlg::setM_pThrottle(CComPtr<_OnThrottle> p_m_pThrottle) {
    m_pThrottle = p_m_pThrottle;
}

CAxWindow  CThrottleDlg::getM_wnd() const {
    return m_wnd;
}

void CThrottleDlg::setM_wnd(CAxWindow p_m_wnd) {
    m_wnd = p_m_wnd;
}



/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\CThrottleDlg.cpp
*********************************************************************/

