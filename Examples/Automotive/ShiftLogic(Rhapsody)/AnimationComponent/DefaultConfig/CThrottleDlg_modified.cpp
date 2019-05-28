/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: CThrottleDlg
//!	Generated Date	: Sun, 19, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\CThrottleDlg.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "CThrottleDlg.h"
#include "OnPlot_i.c"
//#include "OnPlot.h"

#import "OnPlot.ocx" no_namespace raw_interfaces_only

//## package GUIModels 


//#[ ignore 
#define GUIModels_CThrottleDlg_CThrottleDlg_SERIALIZE OM_NO_OP


#define GUIModels_CThrottleDlg_Move_SERIALIZE OM_NO_OP


#define GUIModels_CThrottleDlg_SetCaption_SERIALIZE OM_NO_OP


#define GUIModels_CThrottleDlg_Show_SERIALIZE OM_NO_OP


#define GUIModels_CThrottleDlg_clean_SERIALIZE OM_NO_OP


#define GUIModels_CThrottleDlg_getThrottle_SERIALIZE OM_NO_OP


#define GUIModels_CThrottleDlg_init_SERIALIZE OM_NO_OP


#define GUIModels_CThrottleDlg_setThrottle_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// CThrottleDlg.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(GUIModels)
//## class CThrottleDlg 



CThrottleDlg::CThrottleDlg() {
    NOTIFY_CONSTRUCTOR(CThrottleDlg, CThrottleDlg(), 0, GUIModels_CThrottleDlg_CThrottleDlg_SERIALIZE);
    //#[ operation CThrottleDlg() 
    init();
    //#]
}

CThrottleDlg::~CThrottleDlg() {
    NOTIFY_DESTRUCTOR(~CThrottleDlg, TRUE);
    //#[ operation ~CThrottleDlg() 
    clean();
    //#]
}

void CThrottleDlg::Move(int  x, int  y, int  nWidth, int  nHeight) {
    NOTIFY_OPERATION(Move, Move(int,int,int,int), 0, GUIModels_CThrottleDlg_Move_SERIALIZE);
    //#[ operation Move(int,int,int,int) 
    m_wnd.MoveWindow(x, y, nWidth, nHeight);
    //#]
}

void CThrottleDlg::SetCaption(LPCTSTR szCaption) {
    NOTIFY_OPERATION(SetCaption, SetCaption(LPCTSTR ), 0, GUIModels_CThrottleDlg_SetCaption_SERIALIZE);
    //#[ operation SetCaption(LPCTSTR ) 
    m_wnd.SetWindowText(szCaption);
    //#]
}

void CThrottleDlg::Show() {
    NOTIFY_OPERATION(Show, Show(), 0, GUIModels_CThrottleDlg_Show_SERIALIZE);
    //#[ operation Show() 
    m_wnd.ShowWindow( SW_SHOWNORMAL );
    m_wnd.SetActiveWindow();
    //#]
}

void CThrottleDlg::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, GUIModels_CThrottleDlg_clean_SERIALIZE);
    //#[ operation clean() 
    if (m_pThrottle)
    {
      m_pThrottle->Release();
      m_pThrottle = NULL;
    }

    //ShowWindow(SW_HIDE); 
    
    /*
    m_wnd.DestroyWindow( );
    AtlAxWinTerm();
    */
    //#]
}

void CThrottleDlg::getThrottle(double * val) {
    NOTIFY_OPERATION(getThrottle, getThrottle(double * ), 0, GUIModels_CThrottleDlg_getThrottle_SERIALIZE);
    //#[ operation getThrottle(double * ) 
    m_pThrottle->get_Throttle(val);
    //#]
}

void CThrottleDlg::init() {
    NOTIFY_OPERATION(init, init(), 0, GUIModels_CThrottleDlg_init_SERIALIZE);
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
    m_pThrottle->get_Throttle(&val);
    m_pThrottle->get_Throttle(&val);
    m_pThrottle->get_Throttle(&val);
    m_pThrottle->get_Throttle(&val);
    m_pThrottle->get_Throttle(&val);
    m_pThrottle->get_Throttle(&val);
    m_pThrottle->get_Throttle(&val);

    //#]
}


void CThrottleDlg::setThrottle(double *  val) {
    NOTIFY_OPERATION(setThrottle, setThrottle(double *), 0, GUIModels_CThrottleDlg_setThrottle_SERIALIZE);
    //#[ operation setThrottle(double *) 
    m_pThrottle->put_Throttle(val);
    //#]
}


#ifdef _OMINSTRUMENT


void OMAnimatedCThrottleDlg::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

IMPLEMENT_META(CThrottleDlg, GUIModels, FALSE, OMAnimatedCThrottleDlg)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\CThrottleDlg.cpp
*********************************************************************/

