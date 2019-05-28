/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: CChartDlg
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\CChartDlg.h
*********************************************************************/


#ifndef CChartDlg_H 

#define CChartDlg_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "DisplayPkg.h"
#include "atlhost.h"
#include "atlwin.h"

//## package DisplayPkg 

//----------------------------------------------------------------------------
// CChartDlg.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedCChartDlg;
#endif // _OMINSTRUMENT


//## class CChartDlg 
struct ITChart;
struct ISeries;

class CChartDlg  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedCChartDlg;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    // ## operation CChartDlg() 
    //## operation CChartDlg() 
    CChartDlg();
    
    // ## operation ~CChartDlg() 
    //## operation ~CChartDlg() 
    ~CChartDlg();


////    Operations    ////
public :
    
    // 
    // LRESULT OnInitDialog(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL& bHandled)
    // {
    // return 1;  // Let the system set the focus
    // }
    // ## operation GetChart() 
    //## operation GetChart() 
    ITChart *  GetChart();
    
    // ## operation GetPosition(int * ,int * ,int * ,int * ) 
    //## operation GetPosition(int * ,int * ,int * ,int * ) 
    void GetPosition(int * x, int * y, int * nWidth, int * nHeight);
    
    // ## operation Move(const int ,const int ,const int ,const int ) 
    //## operation Move(const int ,const int ,const int ,const int ) 
    void Move(const int x, const int y, const int nWidth, const int nHeight);
    
    // ## operation SetCaption(LPCTSTR ) 
    //## operation SetCaption(LPCTSTR ) 
    void SetCaption(LPCTSTR szCaption);
    
    //## operation SetLegends(const long ,BSTR *) 
    void SetLegends(const long  nSeries, BSTR *  pLegend);
    
    // ## operation Show() 
    //## operation Show() 
    void Show();
    
    // ## operation addSeries(const bool ,BSTR ) 
    //## operation addSeries(const bool ,BSTR ) 
    void addSeries(const bool bPoint, BSTR Name);
    
    // ## operation clean() 
    //## operation clean() 
    void clean();
    
    // ## operation cleanPlot() 
    //## operation cleanPlot() 
    HRESULT cleanPlot();
    
    // ## operation init() 
    //## operation init() 
    void init();
    
    // ## operation initPlot(const long ,const bool ,BSTR * ) 
    //## operation initPlot(const long ,const bool ,BSTR * ) 
    void initPlot(const long numberOfSeries, const bool bPoint, BSTR * pNames);
    
    // ## operation plotData(const double ,const double * ,const long ) 
    //## operation plotData(const double ,const double * ,const long ) 
    void plotData(const double time, const double * vars, const long count);
    
    // ## operation plotSeriesData(const double ,double) 
    //## operation plotSeriesData(const double ,double) 
    void plotSeriesData(const double time, double  var);


////    Additional operations    ////
public :
    
    //## auto_generated 
    long getM_SeriesCount() const;
    
    //## auto_generated 
    void setM_SeriesCount(long  p_m_SeriesCount);
    
    //## auto_generated 
    ITChart* getM_pChart() const;
    
    //## auto_generated 
    void setM_pChart(ITChart*  p_m_pChart);
    
    //## auto_generated 
    CAxWindow  getM_wnd() const;
    
    //## auto_generated 
    void setM_wnd(CAxWindow p_m_wnd);
    
    //## auto_generated 
    OLE_COLOR getPlotColors(int  i1) const;
    
    //## auto_generated 
    void setPlotColors(int  i1, OLE_COLOR  p_plotColors);
    
    //## auto_generated 
    ISeries* getPpSeries(int  i1) const;
    
    //## auto_generated 
    void setPpSeries(int  i1, ISeries*  p_ppSeries);


////    Attributes    ////
public :
    
    // ## attribute plotColors 
    OLE_COLOR plotColors[20];		//## attribute plotColors 
    
protected :
    
    ITChart* m_pChart;		//## attribute m_pChart 
    
    ISeries* ppSeries [20];		//## attribute ppSeries 
    
private :
    
    // ## attribute m_SeriesCount 
    long m_SeriesCount;		//## attribute m_SeriesCount 
    
    // ## attribute m_wnd 
    CAxWindow m_wnd;		//## attribute m_wnd 
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedCChartDlg : virtual public AOMInstance {

    
    DECLARE_META(CChartDlg, OMAnimatedCChartDlg)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\CChartDlg.h
*********************************************************************/

