// ThrottleDlg.cpp : Implementation of CThrottle
#include "stdafx.h"
#include "ThrottleDlg.h"
#include "OnPlot_i.c"                  

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

/////////////////////////////////////////////////////////////////////////////
// CThrottle


void CThrottleDlg::init()
{
  int x = 0;
  int y = 0;
  int width = 200;
  int height = 300;
  RECT rect = { 100, 100, 200, 300 };
  DWORD dwStyle = WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SIZEBOX | WS_CAPTION | WS_VISIBLE;

  CComBSTR bstrId = CLSID_OnThrottle;

  AtlAxWinInit();
  m_wnd.m_hWnd = m_wnd.Create(NULL, rect, bstrId, dwStyle, WS_EX_CLIENTEDGE);
  HRESULT hr = m_wnd.QueryControl( IID__OnThrottle, reinterpret_cast<void**> (&m_pThrottle) );
  _ASSERTE(hr == S_OK);
  m_wnd.SetWindowText(L"Throttle");
  Move(x, y, width, height);
}

void CThrottleDlg::Show()
{
  m_wnd.ShowWindow( SW_SHOWNORMAL );
  m_wnd.SetActiveWindow();
}

void CThrottleDlg::SetCaption(LPCTSTR szCaption)
{
  m_wnd.SetWindowText(szCaption);
}

void CThrottleDlg::Move( int x, int y, int nWidth, int nHeight)
{
  m_wnd.MoveWindow(x, y, nWidth, nHeight);
}

void CThrottleDlg::clean()
{
 	m_pThrottle.Release();
  //ShowWindow(SW_HIDE);
  m_wnd.DestroyWindow( );
  AtlAxWinTerm();
}


void CThrottleDlg::getThrottle(double* val)
{
  m_pThrottle->get_Throttle(val);
}

void CThrottleDlg::setThrottle(double val)
{
  m_pThrottle->put_Throttle(&val);
}

