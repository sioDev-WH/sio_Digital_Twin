// ThrottleDialog.h : Declaration of the CThrottleDialog

#ifndef __THROTTLEDIALOG_H_
#define __THROTTLEDIALOG_H_

#include <atlhost.h>
#include "OnShiftLogicDialogExport.h"
#import "OnPlot.ocx" raw_interfaces_only, raw_native_types, no_namespace, named_guids  

/////////////////////////////////////////////////////////////////////////////
// CThrottleDialog
class ONSHIFTLOGICDIALOG_API CThrottleDialog : public CAxDialogImpl<CThrottleDialog>
{
public:
	CThrottleDialog();
	~CThrottleDialog();

	enum { IDD = /*IDD_THROTTLEDIALOG*/ 102 };

BEGIN_MSG_MAP(CThrottleDialog)
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

  _OnThrottle* m_dlg;
};

#endif //__THROTTLEDIALOG_H_
