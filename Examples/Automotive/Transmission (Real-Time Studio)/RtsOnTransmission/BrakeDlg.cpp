// BrakeDlg.cpp : Implementation of CBrake
#include "stdafx.h"
#include "BrakeDlg.h"
#include "OnPlot_i.c"
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

/////////////////////////////////////////////////////////////////////////////
// CBrake


void CBrakeDlg::init()
{
  int x = 300;
  int y = 100;
  int width = 200;
  int height = 150;
  RECT rect = { 300, 100, 200, 300 };
  DWORD dwStyle = WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SIZEBOX | WS_CAPTION | WS_VISIBLE;

  CComBSTR bstrId = CLSID_OnBrakes;

  AtlAxWinInit();
  m_wnd.m_hWnd = m_wnd.Create(NULL, rect, bstrId, dwStyle, WS_EX_CLIENTEDGE);
  HRESULT hr = m_wnd.QueryControl( IID__OnBrakes, reinterpret_cast<void**> (&m_pBrake) );
  _ASSERTE(hr == S_OK);

  m_wnd.MoveWindow(x, y, width, height);
}

void CBrakeDlg::Show()
{
  m_wnd.ShowWindow( SW_SHOWNORMAL );
  m_wnd.SetActiveWindow();
}

void CBrakeDlg::SetCaption(LPCTSTR szCaption)
{
  m_wnd.SetWindowText(szCaption);
}

void CBrakeDlg::Move(const int x, const int y, const int nWidth, const int nHeight)
{
  m_wnd.MoveWindow(x, y, nWidth, nHeight);
}

void CBrakeDlg::clean()
{
 	m_pBrake.Release();
  //ShowWindow(SW_HIDE);
  BOOL res = m_wnd.DestroyWindow( );
  if (!res)
  {
    DWORD err = GetLastError();
    ATLTRACE("%d", err);
  }
  AtlAxWinTerm();
}

HRESULT CBrakeDlg::get_Position(double* val)
{
  return m_pBrake->get_Brake(val);
}

HRESULT CBrakeDlg::put_Position(double val)
{
  return m_pBrake->put_Brake(&val);
}
