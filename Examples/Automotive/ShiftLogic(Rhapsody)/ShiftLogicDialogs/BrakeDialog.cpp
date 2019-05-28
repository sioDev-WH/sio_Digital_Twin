// BrakeDialog.cpp : Implementation of CBrakeDialog
#include "stdafx.h"
#include "BrakeDialog.h"
#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CBrakeDialog


CBrakeDialog::CBrakeDialog()
{
  m_dlg = NULL;
}

CBrakeDialog::~CBrakeDialog()
{
  if (m_dlg)
  {
    m_dlg->Release();
    m_dlg = NULL;
    BOOL bRet = DestroyWindow();
  }
}


LRESULT CBrakeDialog::OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
{
  HRESULT hr = S_OK;
  HWND _hwnd = GetDlgItem( IDC_ONBRAKES1 );
  IUnknown* pUnk = NULL;
  AtlAxGetControl( _hwnd, &pUnk );
  pUnk->QueryInterface( &m_dlg ); 
  pUnk->Release();
  
	return 1;  // Let the system set the focus
}


void CBrakeDialog::SetCaption(LPCTSTR szCaption) 
{
  SetWindowText(szCaption);
}

void CBrakeDialog::Show() 
{
  //DoModal();
  Create(NULL);
  ShowWindow( SW_SHOWNORMAL );
  SetActiveWindow();
}

HRESULT CBrakeDialog::get_Position(double * val) 
{
  return m_dlg->get_Brake(val);
}

HRESULT CBrakeDialog::put_Position(double * val) 
{
  return m_dlg->put_Brake(val);
}

