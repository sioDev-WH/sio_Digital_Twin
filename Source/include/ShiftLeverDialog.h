// ShiftLeverDialog.h : Declaration of the CShiftLeverDialog

#ifndef __SHIFTLEVERDIALOG_H_
#define __SHIFTLEVERDIALOG_H_


#include <atlhost.h>
#include "OnShiftLogicDialogExport.h"
#import "OnPlot.ocx" raw_interfaces_only, raw_native_types, no_namespace, named_guids  

/////////////////////////////////////////////////////////////////////////////
// CShiftLeverDialog
class ONSHIFTLOGICDIALOG_API CShiftLeverDialog : public CAxDialogImpl<CShiftLeverDialog>
{
public:
	CShiftLeverDialog();
	~CShiftLeverDialog();

	enum { IDD = /*IDD_SHIFTLEVERDIALOG*/ 101 };

BEGIN_MSG_MAP(CShiftLeverDialog)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
  void SetCaption(LPCTSTR szCaption);
  void Show();
  HRESULT get_Position(long * val);
  HRESULT put_Position(long * val);

  _OnShiftLever* m_dlg;  
};

#endif //__SHIFTLEVERDIALOG_H_
