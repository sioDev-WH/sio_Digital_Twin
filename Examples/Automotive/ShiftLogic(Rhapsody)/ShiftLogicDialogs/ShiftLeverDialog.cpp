// ShiftLeverDialog.cpp : Implementation of CShiftLeverDialog
#include "stdafx.h"
#include "ShiftLeverDialog.h"
#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CShiftLeverDialog

CShiftLeverDialog::CShiftLeverDialog()
{
  m_dlg = NULL;
}

CShiftLeverDialog::~CShiftLeverDialog()
{
  if (m_dlg)
  {
    m_dlg->Release();
    m_dlg = NULL;
    BOOL bRet = DestroyWindow();
  }
}


LRESULT CShiftLeverDialog::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
  HRESULT hr = S_OK;
  HWND _hwnd = GetDlgItem( IDC_ONSHIFTLEVER1 );
  IUnknown* pUnk = NULL;
  AtlAxGetControl( _hwnd, &pUnk );
  pUnk->QueryInterface( &m_dlg ); 
  pUnk->Release();
  
	return 1;  // Let the system set the focus
}


void CShiftLeverDialog::SetCaption(LPCTSTR szCaption) 
{
  SetWindowText(szCaption);
}

void CShiftLeverDialog::Show() 
{
  //DoModal();
  Create(NULL);
  ShowWindow( SW_SHOWNORMAL );
  SetActiveWindow();
}

HRESULT CShiftLeverDialog::get_Position(long * val) 
{
  return m_dlg->get_Position(val);
}

HRESULT CShiftLeverDialog::put_Position(long * val) 
{
  return m_dlg->put_Position(val);
}
