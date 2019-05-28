/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: CShiftDlg
//!	Generated Date	: Mon, 20, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\CShiftDlg.cpp
*********************************************************************/

#include "CShiftDlg.h"
#include "OnPlot_i.c"
#include "OnPlot.h"

//## package GUIModels 

//----------------------------------------------------------------------------
// CShiftDlg.cpp                                                                  
//----------------------------------------------------------------------------
//## class CShiftDlg 



CShiftDlg::CShiftDlg() {
    //#[ operation CShiftDlg() 
    init();
    //#]
}

CShiftDlg::~CShiftDlg() {
    //#[ operation ~CShiftDlg() 
    clean();
    //#]
}

void CShiftDlg::Move(const int x, const int y, const int nWidth, const int nHeight) {
    //#[ operation Move(const int ,const int ,const int ,const int ) 
    m_wnd.MoveWindow(x, y, nWidth, nHeight);
    //#]
}

void CShiftDlg::SetCaption(LPCTSTR szCaption) {
    //#[ operation SetCaption(LPCTSTR ) 
    m_wnd.SetWindowText(szCaption);
    //#]
}

void CShiftDlg::Show() {
    //#[ operation Show() 
    m_wnd.ShowWindow( SW_SHOWNORMAL );
    m_wnd.SetActiveWindow();
    //#]
}

void CShiftDlg::clean() {
    //#[ operation clean() 
    m_pShift.Release();
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

HRESULT CShiftDlg::get_Position(long * val) {
    //#[ operation get_Position(long * ) 
    return m_pShift->get_Position(val);
    //#]
}

void CShiftDlg::init() {
    //#[ operation init() 
    int x = 500;
    int y = 100;
    int width = 200;
    int height = 200;
    RECT rect = { 500, 100, 200, 200 };
    DWORD dwStyle = WS_POPUPWINDOW | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SIZEBOX | WS_CAPTION | WS_VISIBLE;
    
    CComBSTR bstrId = CLSID_OnShiftLever;
    
    AtlAxWinInit();
    m_wnd.m_hWnd = m_wnd.Create(NULL, rect, bstrId, dwStyle, WS_EX_CLIENTEDGE);
    HRESULT hr = m_wnd.QueryControl( IID__OnShiftLever, reinterpret_cast<void**> (&m_pShift) );
    _ASSERTE(hr == S_OK);
    
    m_wnd.MoveWindow(x, y, width, height);
    //#]
}

HRESULT CShiftDlg::put_Position(long*  val) {
    //#[ operation put_Position(long*) 
    return m_pShift->put_Position(val);
    //#]
}

CComPtr<_OnShiftLever>  CShiftDlg::getM_pShift() const {
    return m_pShift;
}

void CShiftDlg::setM_pShift(CComPtr<_OnShiftLever> p_m_pShift) {
    m_pShift = p_m_pShift;
}

CAxWindow  CShiftDlg::getM_wnd() const {
    return m_wnd;
}

void CShiftDlg::setM_wnd(CAxWindow p_m_wnd) {
    m_wnd = p_m_wnd;
}



/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\CShiftDlg.cpp
*********************************************************************/

