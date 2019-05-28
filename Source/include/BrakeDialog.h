// BrakeDialog.h : Declaration of the CBrakeDialog

#ifndef __BRAKEDIALOG_H_
#define __BRAKEDIALOG_H_

#include <atlhost.h>
#include "OnShiftLogicDialogExport.h"
#import "OnPlot.ocx" raw_interfaces_only, raw_native_types, no_namespace, named_guids  

/////////////////////////////////////////////////////////////////////////////
// CBrakeDialog
class ONSHIFTLOGICDIALOG_API CBrakeDialog : public CAxDialogImpl<CBrakeDialog>
{
public:

  CBrakeDialog();
	~CBrakeDialog();

	enum { IDD = /*IDD_BRAKEDIALOG*/ 103 };

BEGIN_MSG_MAP(CBrakeDialog)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
END_MSG_MAP()

// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
  void SetCaption(LPCTSTR szCaption);
  void Show();
  HRESULT get_Position(double * val);
  HRESULT put_Position(double * val);

  _OnBrakes* m_dlg;
};

#endif //__BRAKEDIALOG_H_
