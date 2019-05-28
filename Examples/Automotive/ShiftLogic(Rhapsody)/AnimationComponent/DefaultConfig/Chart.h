/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Chart
//!	Generated Date	: Mon, 9, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\Chart.h
*********************************************************************/


#ifndef Chart_H 

#define Chart_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "GUIModels.h"
#include "TransmissionControlModels.h"
#include "OnModelBase.h"

//## package GUIModels 

//----------------------------------------------------------------------------
// Chart.h                                                                  
//----------------------------------------------------------------------------

//## class Chart 
//struct _OnPlotDlgMgr;
class CChartDialog;

class Chart : public COnModelBase {


////    Constructors and destructors    ////
public :
    
    //## operation Chart() 
    Chart();
    
    //## operation ~Chart() 
    ~Chart();


////    Operations    ////
public :
    
    //## operation AddRef() 
    long AddRef();
    
    //## operation Release() 
    long Release();
    
    //## operation SetName(const _TCHAR * ) 
    void SetName(const _TCHAR * caption);
    
    //## operation clean() 
    void clean();
    
    //## operation handle_plotData(const double ,double * ,long ) 
    void handle_plotData(const double time, double * vals, long cVals);
    
    //## operation handle_plotData(const double ,long * ,long ) 
    void handle_plotData(const double time, long * vals, long cVals);
    
    //## operation handle_tick() 
    void handle_tick();
    
    //## operation init() 
    void init();


////    Additional operations    ////
public :
    

////    Attributes    ////
public :
    
    // Cg_Add
    bool bInit;		//## attribute bInit 
    
    long m_cRef;		//## attribute m_cRef 
    
protected :
    
    //_OnPlotDlgMgr* m_dlg;		//## attribute m_dlg 
    CChartDialog* m_dialog;
    

};


#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Chart.h
*********************************************************************/

