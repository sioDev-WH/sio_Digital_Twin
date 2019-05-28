// ChartDlg.h : Declaration of the CChart

#ifndef __CHARTDLG_H_
#define __CHARTDLG_H_

#include "resource.h"       // main symbols
#include <atlhost.h>
#include <atlwin.h>
#include "RtsOnTransmissionExport.h"

#import ".\..\..\TeeChart\TeeChart.ocx" no_namespace raw_interfaces_only named_guids

/////////////////////////////////////////////////////////////////////////////
// CChart
class RTSONTRANSMISSION_API CChartDlg
{
public:
	CChartDlg()
	{
    m_SeriesCount = 0;
    init();
	}

	~CChartDlg()
	{
    clean();
	}

  void init();
  void clean();
  void Show();
  void SetCaption(LPCTSTR szCaption);
  void GetPosition(int* x, int* y, int* nWidth, int* nHeight);
  void Move(const int x, const int y, const int nWidth, const int nHeight);
  void addSeries(const bool bPoint, BSTR Name);
  void initPlot(const long numberOfSeries, const bool bPoint, BSTR* pNames);
  void plotSeriesData(const double time, double var);
  void plotData(const double time, const double* vars, const long count);
  HRESULT cleanPlot();


  OLE_COLOR plotColors[20];

/*
BEGIN_MSG_MAP(CChart)
	MESSAGE_HANDLER(WM_INITDIALOG, OnInitDialog)
END_MSG_MAP()
*/

// Handler prototypes:
//  LRESULT MessageHandler(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled);
//  LRESULT CommandHandler(WORD wNotifyCode, WORD wID, HWND hWndCtl, BOOL& bHandled);
//  LRESULT NotifyHandler(int idCtrl, LPNMHDR pnmh, BOOL& bHandled);

/*
	LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
	{
		return 1;  // Let the system set the focus
	}
*/

  ITChart* GetChart() { return m_pChart; }

private:
	CComPtr<ITChart>		m_pChart;
  CAxWindow m_wnd;
  ISeries* ppSeries[20];
  long m_SeriesCount;
};

#endif //__CHARTDLG_H_
