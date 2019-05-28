/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: CBrakeDlg
//!	Generated Date	: Mon, 20, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\CBrakeDlg.cpp
*********************************************************************/

#include "CBrakeDlg.h"
#include "OnPlot_i.c"
#include "OnPlot.h"

//## package GUIModels 

//----------------------------------------------------------------------------
// CBrakeDlg.cpp                                                                  
//----------------------------------------------------------------------------
//## class CBrakeDlg 



CBrakeDlg::CBrakeDlg() {
    //#[ operation CBrakeDlg() 
    init();
    //#]
}

CBrakeDlg::~CBrakeDlg() {
    //#[ operation ~CBrakeDlg() 
    clean();
    //#]
}

void CBrakeDlg::Move(const int x, const int y, const int nWidth, const int nHeight) {
    //#[ operation Move(const int ,const int ,const int ,const int ) 
    m_wnd.MoveWindow(x, y, nWidth, nHeight);
    //#]
}

void CBrakeDlg::SetCaption(LPCTSTR szCaption) {
    //#[ operation SetCaption(LPCTSTR ) 
    m_wnd.SetWindowText(szCaption);
    //#]
}

void CBrakeDlg::Show() {
    //#[ operation Show() 
    m_wnd.ShowWindow( SW_SHOWNORMAL );
    m_wnd.SetActiveWindow();
    //#]
}

void CBrakeDlg::clean() {
    //#[ operation clean() 
    m_pBrake.Release();
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

HRESULT CBrakeDlg::get_Position(double * val) {
    //#[ operation get_Position(double * ) 
    return m_pBrake->get_Brake(val);
    //#]
}

void CBrakeDlg::init() {
    //#[ operation init() 
    int x = 300;
    int y = 100;
    int width = 200;
    int height = 150;
    RECT rect = { 300, 100, 200, 300 };
    DWORD dwStyle = WS_POPUPWINDOW | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SIZEBOX | WS_CAPTION | WS_VISIBLE;
    
    CComBSTR bstrId = CLSID_OnBrakes;
    
    AtlAxWinInit();
    m_wnd.m_hWnd = m_wnd.Create(NULL, rect, bstrId, dwStyle, WS_EX_CLIENTEDGE);
    HRESULT hr = m_wnd.QueryControl( IID__OnBrakes, reinterpret_cast<void**> (&m_pBrake) );
    _ASSERTE(hr == S_OK);
    
    m_wnd.MoveWindow(x, y, width, height);
    //#]
}

HRESULT CBrakeDlg::put_Position(double  val) {
    //#[ operation put_Position(double) 
    return m_pBrake->put_Brake(&val);
    //#]
}

CComPtr<_OnBrakes>  CBrakeDlg::getM_pBrake() const {
    return m_pBrake;
}

void CBrakeDlg::setM_pBrake(CComPtr<_OnBrakes> p_m_pBrake) {
    m_pBrake = p_m_pBrake;
}

CAxWindow  CBrakeDlg::getM_wnd() const {
    return m_wnd;
}

void CBrakeDlg::setM_wnd(CAxWindow p_m_wnd) {
    m_wnd = p_m_wnd;
}



/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\CBrakeDlg.cpp
*********************************************************************/

