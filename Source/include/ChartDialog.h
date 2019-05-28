// ChartDialog.h : Declaration of the CChartDialog

#ifndef __CHARTDIALOG_H_
#define __CHARTDIALOG_H_

#include <atlhost.h>
#include "OnShiftLogicDialogExport.h"
#import "TeeChart5.ocx" raw_interfaces_only, raw_native_types, no_namespace, named_guids  

/////////////////////////////////////////////////////////////////////////////
// CChartDialog
class ONSHIFTLOGICDIALOG_API CChartDialog : public CAxDialogImpl<CChartDialog>
{
public:
	CChartDialog();
	~CChartDialog();

	enum { IDD = /*IDD_CHARTDIALOG*/ 104 };

BEGIN_MSG_MAP(CChartDialog)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
END_MSG_MAP()
// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
  void SetCaption(LPCTSTR szCaption);
  void Show();

  void addSeries(BSTR Name);
  void initPlot(const long count, BSTR * pNames);
  void plotData(const double time, const double * vars, const long count);
  void plotData(const double time, const long * vars, const long count);
  void plotSeriesData(const double time, double  var);

  OLE_COLOR plotColors[20];
  ITChart* m_dlg;

};

#endif //__CHARTDIALOG_H_
