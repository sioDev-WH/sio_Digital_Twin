// ShiftDlg.cpp : Implementation of CShift
#include "stdafx.h"
#include "ShiftDlg.h"
#include "OnPlot_i.c"

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

/////////////////////////////////////////////////////////////////////////////
// CShift


void CShiftDlg::init()
{
  int x = 500;
  int y = 100;
  int width = 200;
  int height = 200;
  RECT rect = { 500, 100, 200, 200 };
  DWORD dwStyle = WS_MAXIMIZEBOX | WS_MINIMIZEBOX | WS_SIZEBOX | WS_CAPTION | WS_VISIBLE;

  CComBSTR bstrId = CLSID_OnShiftLever;

  AtlAxWinInit();
  m_wnd.m_hWnd = m_wnd.Create(NULL, rect, bstrId, dwStyle, WS_EX_CLIENTEDGE);
  HRESULT hr = m_wnd.QueryControl( IID__OnShiftLever, reinterpret_cast<void**> (&m_pShift) );
  _ASSERTE(hr == S_OK);

  m_wnd.MoveWindow(x, y, width, height);
}

void CShiftDlg::Show()
{
  m_wnd.ShowWindow( SW_SHOWNORMAL );
  m_wnd.SetActiveWindow();
}

void CShiftDlg::SetCaption(LPCTSTR szCaption)
{
  m_wnd.SetWindowText(szCaption);
}

void CShiftDlg::Move(const int x, const int y, const int nWidth, const int nHeight)
{
  m_wnd.MoveWindow(x, y, nWidth, nHeight);
}

void CShiftDlg::clean()
{
 	m_pShift.Release();
  //ShowWindow(SW_HIDE);
  BOOL res = m_wnd.DestroyWindow( );
  if (!res)
  {
    DWORD err = GetLastError();
    ATLTRACE("%d", err);
  }
  AtlAxWinTerm();
}

HRESULT CShiftDlg::get_Position(long* val)
{
  return m_pShift->get_Position(val);
}

HRESULT CShiftDlg::put_Position(long val)
{
  return m_pShift->put_Position(&val);
}