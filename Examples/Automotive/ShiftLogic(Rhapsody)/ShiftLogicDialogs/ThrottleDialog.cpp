// ThrottleDialog.cpp : Implementation of CThrottleDialog
#include "stdafx.h"
#include "ThrottleDialog.h"
#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CThrottleDialog

CThrottleDialog::CThrottleDialog()
{
  m_dlg = NULL;
}

CThrottleDialog::~CThrottleDialog()
{
  if (m_dlg)
  {
    m_dlg->Release();
    m_dlg = NULL;
    BOOL bRet = DestroyWindow();
  }
}


LRESULT CThrottleDialog::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
  HRESULT hr = S_OK;
  HWND _hwnd = GetDlgItem( IDC_ONTHROTTLE1 );
  IUnknown* pUnk = NULL;
  AtlAxGetControl( _hwnd, &pUnk );
  pUnk->QueryInterface( &m_dlg ); 
  pUnk->Release();
  
	return 1;  // Let the system set the focus
}


void CThrottleDialog::SetCaption(LPCTSTR szCaption) 
{
  SetWindowText(szCaption);
}

void CThrottleDialog::Show() 
{
  //DoModal();
  Create(NULL);
  ShowWindow( SW_SHOWNORMAL );
  SetActiveWindow();
}

HRESULT CThrottleDialog::get_Position(double * val) 
{
  return m_dlg->get_Throttle(val);
}

HRESULT CThrottleDialog::put_Position(double * val) 
{
  return m_dlg->put_Throttle(val);
}
