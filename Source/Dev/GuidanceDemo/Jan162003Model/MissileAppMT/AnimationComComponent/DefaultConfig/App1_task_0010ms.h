/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: App1_task_0010ms
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\App1_task_0010ms.h
*********************************************************************/


#ifndef App1_task_0010ms_H 

#define App1_task_0010ms_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "Application.h"
#include <oxf/omthread.h>
#include "OnUMLEso.h"
#include "fstream.h"

//## package Application 

//----------------------------------------------------------------------------
// App1_task_0010ms.h                                                                  
//----------------------------------------------------------------------------
class Chart;
class GuidanceLogic;

#ifdef _OMINSTRUMENT
class OMAnimatedApp1_task_0010ms;
#endif // _OMINSTRUMENT
class SeekerSubsystem;
class Target;


//## class App1_task_0010ms 
class App1_task_0010ms : public OMThread {
public :
    //#[ ignore 
    #define d2r 0.017453292519943295769236907684886
    //#]
    
    


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedApp1_task_0010ms;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation App1_task_0010ms() 
    App1_task_0010ms();
    
    //## operation ~App1_task_0010ms() 
    ~App1_task_0010ms();


////    Operations    ////
public :
    
    //## operation broadcast(const double) 
    void broadcast(const double  t);
    
    //## operation clean() 
    void clean();
    
    //## operation handle_tick(const double) 
    void handle_tick(const double  t);
    
    //## operation init() 
    void init();


////    Additional operations    ////
public :
    
    //## auto_generated 
    Chart* getItsChart() const;
    
    //## auto_generated 
    void setItsChart(Chart*  p_Chart);

protected :
    
    //## auto_generated 
    void setNTicks(long  p_nTicks);
    
    //## auto_generated 
    void setPeriod(long  p_period);


////    Framework operations    ////
public :
    
    //## auto_generated 
    virtual OMBoolean startBehavior();

protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
protected :
    
    long nTicks;		//## attribute nTicks 
    
    long period;		//## attribute period 
    

////    Relations and components    ////
public :
    
    GuidanceLogic* itsGuidanceLogic;		//## link itsGuidanceLogic 
    
    
    SeekerSubsystem* itsSeeker;		//## link itsSeeker 
    
    
    Target* itsTarget;		//## link itsTarget 
    

protected :
    
    Chart* itsChart;		//## link itsChart 
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedApp1_task_0010ms : virtual public AOMInstance {

    
    DECLARE_META(App1_task_0010ms, OMAnimatedApp1_task_0010ms)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\App1_task_0010ms.h
*********************************************************************/

