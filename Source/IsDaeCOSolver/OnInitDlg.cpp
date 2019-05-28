
#include "OnInitDlg.h"
#include "ISDaeCOSolver.h"
#include "OnInitialization.h"



COnInitDlg::COnInitDlg() : m_pOnInit(NULL) 
{
    init();
}

COnInitDlg::~COnInitDlg() 
{
    if (m_pOnInit)
    {
      m_pOnInit->Release();
      m_pOnInit = NULL;
    }
    clean();
}

void COnInitDlg::GetPosition(int * x, int * y, int * nWidth, int * nHeight) 
{
    RECT rect;
    m_wnd.GetWindowRect(&rect); 
    *x = rect.left;
    *y = rect.top;
    *nWidth = rect.right - rect.left;
    *nHeight = rect.bottom - rect.top;
}

void COnInitDlg::Move(const int x, const int y, const int nWidth, const int nHeight) 
{
    m_wnd.MoveWindow(x, y, nWidth, nHeight);
}

void COnInitDlg::SetCaption(LPCTSTR szCaption) 
{
    m_wnd.SetWindowText(szCaption);
}

void COnInitDlg::Show() 
{
    m_wnd.ShowWindow( SW_SHOWNORMAL );
    m_wnd.SetActiveWindow();
}


void COnInitDlg::clean() {
    /*
    BOOL res = m_wnd.DestroyWindow( );
    if (!res)
    {
      DWORD err = GetLastError();
      ATLTRACE("%d", err);
    }
    AtlAxWinTerm();
    */
}

void COnInitDlg::init() {
    int x = 100;
    int y = 100;
    int width = 1500;
    int height = 1000;
    
    RECT rect = { 100, 100, 1500, 1000 };
    DWORD dwStyle = WS_POPUPWINDOW | WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SIZEBOX | WS_CAPTION | WS_VISIBLE;
    //DWORD dwStyle = WS_SIZEBOX | WS_CAPTION | WS_VISIBLE;

    //CComBSTR bstrId = CLSID_ctlInitialization;
    _ctlMessageWindow* pTest = NULL;
    CComBSTR bstrId = CLSID_ctlMessageWindow;
    
    AtlAxWinInit();
    m_wnd.m_hWnd = m_wnd.Create(NULL, rect, bstrId, dwStyle, WS_EX_CLIENTEDGE);
    //HRESULT hr = m_wnd.QueryControl( &m_pOnInit );
    HRESULT hr = m_wnd.QueryControl( &pTest );
    _ASSERTE(hr == S_OK);
   
    BSTR msg = L"Mod.Prop";
    hr = pTest->LogMessage(&msg);

    m_wnd.MoveWindow(x, y, width, height);
}

void COnInitDlg::SetModelExec(IOnModelExec* pModelExec)
{
  if (m_pOnInit)
  {
    IDispatch* pDispatch = pModelExec;
    //m_pOnInit->SetModelExec(&pDispatch);
  }
}