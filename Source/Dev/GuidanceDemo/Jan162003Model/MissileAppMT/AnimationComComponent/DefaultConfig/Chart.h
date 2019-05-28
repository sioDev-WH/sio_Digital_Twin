/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: Chart
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\Chart.h
*********************************************************************/


#ifndef Chart_H 

#define Chart_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "DisplayPkg.h"
#include "stdafx.h"
#include "OnModelBase.h"

//## package DisplayPkg 

//----------------------------------------------------------------------------
// Chart.h                                                                  
//----------------------------------------------------------------------------
class CChartDlg;

#ifdef _OMINSTRUMENT
class OMAnimatedChart;
#endif // _OMINSTRUMENT


// ## class Chart 
//## class Chart 
class Chart : public COnModelBase {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedChart;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    // ## operation Chart() 
    //## operation Chart() 
    Chart();
    
    // ## operation ~Chart() 
    //## operation ~Chart() 
    ~Chart();


////    Operations    ////
public :
    
    // ## operation AddRef() 
    //## operation AddRef() 
    long AddRef();
    
    // ## operation Release() 
    //## operation Release() 
    long Release();
    
    // ## operation SetName(const _TCHAR * ) 
    //## operation SetName(const _TCHAR * ) 
    void SetName(const _TCHAR * caption);
    
    // ## operation clean() 
    //## operation clean() 
    void clean();
    
    // ## operation handle_plotData(const double ,double * ,long ) 
    //## operation handle_plotData(const double ,double * ,long) 
    void handle_plotData(const double time, double * vals, long  cVals);
    
    // ## operation handle_tick(const double ) 
    //## operation handle_tick(const double ) 
    void handle_tick(const double time);
    
    // ## operation init() 
    //## operation init() 
    void init();
    
    // ## operation initPlot(const long ,const bool ,BSTR * ) 
    //## operation initPlot(const long ,const bool ,BSTR * ) 
    void initPlot(const long numberOfSeries, const bool bPoint, BSTR * pNames);
    
    //## operation setLegends(const long ,BSTR * ) 
    void setLegends(const long  nSeries, BSTR *  pLegends);


////    Additional operations    ////
public :
    
    //## auto_generated 
    bool  getBInit() const;
    
    //## auto_generated 
    void setBInit(bool p_bInit);
    
    //## auto_generated 
    long getM_cRef() const;
    
    //## auto_generated 
    void setM_cRef(long  p_m_cRef);
    
    //## auto_generated 
    BSTR * getPLegands() const;
    
    //## auto_generated 
    void setPLegands(BSTR *  p_pLegands);
    
    //## auto_generated 
    CChartDlg* getM_dlg() const;
    
    //## auto_generated 
    void setM_dlg(CChartDlg*  p_CChartDlg);


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
public :
    
    // Cg_Add
    // ## attribute bInit 
    bool bInit;		//## attribute bInit 
    
    // ## attribute m_cRef 
    long m_cRef;		//## attribute m_cRef 
    
protected :
    
    BSTR * pLegands;		//## attribute pLegands 
    

////    Relations and components    ////
protected :
    
    // ## link m_dlg 
    CChartDlg* m_dlg;		//## link m_dlg 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedChart : virtual public AOMInstance {

    
    DECLARE_META(Chart, OMAnimatedChart)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\Chart.h
*********************************************************************/

