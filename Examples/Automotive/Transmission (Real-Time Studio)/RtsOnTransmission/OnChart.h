// OnChart.h : Declaration of the COnChart

#ifndef __ONCHART_H_
#define __ONCHART_H_

#include "resource.h"       // main symbols
class CChartDlg;

/////////////////////////////////////////////////////////////////////////////
// COnChart
class ATL_NO_VTABLE COnChart : 
	public CComObjectRootEx<CComSingleThreadModel>,
	public CComCoClass<COnChart, &CLSID_OnChart>,
	public IDispatchImpl<IOnChart, &IID_IOnChart, &LIBID_RTSONTRANSMISSIONLib>
{
public:
	COnChart();
  ~COnChart();

DECLARE_REGISTRY_RESOURCEID(IDR_ONCHART)

DECLARE_PROTECT_FINAL_CONSTRUCT()

BEGIN_COM_MAP(COnChart)
	COM_INTERFACE_ENTRY(IOnChart)
	COM_INTERFACE_ENTRY(IDispatch)
END_COM_MAP()

// IOnChart
public:
	STDMETHOD(plotSeriesData)(/*[in]*/ double t, /*[in]*/ double val);
	STDMETHOD(AddSeries)(BSTR SeriesName);
	STDMETHOD(GetPosition)(/*[in, out]*/ int* x, /*[in, out]*/ int* y, /*[in, out]*/ int* nWidth, /*[in, out]*/ int* nHeight);
  STDMETHOD(initPlot)(long numberOfSeries, VARIANT_BOOL vbPoint, SAFEARRAY** ppsaNames);
  STDMETHOD(plotData)(double time, SAFEARRAY** psaVals, long count);
	STDMETHOD(Hide)();
	STDMETHOD(Show)();
  STDMETHOD(SetCaption)(BSTR caption);
  STDMETHOD(Move)( int x, int y, int nWidth, int nHeight);
  STDMETHOD(cleanPlot)();


	CChartDlg* m_dlg;
  bool m_bInit;

};

#endif //__ONCHART_H_
