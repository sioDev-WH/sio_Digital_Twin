/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: App1_task_0001ms
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\App1_task_0001ms.h
*********************************************************************/


#ifndef App1_task_0001ms_H 

#define App1_task_0001ms_H 


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
// App1_task_0001ms.h                                                                  
//----------------------------------------------------------------------------
class AirframeSubsystem;
class AutoPilot;

#ifdef _OMINSTRUMENT
class OMAnimatedApp1_task_0001ms;
#endif // _OMINSTRUMENT


//## class App1_task_0001ms 
class App1_task_0001ms : public OMThread {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedApp1_task_0001ms;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation App1_task_0001ms() 
    App1_task_0001ms();
    
    //## operation ~App1_task_0001ms() 
    ~App1_task_0001ms();


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
    
    AirframeSubsystem* itsAirframeSubsystem;		//## link itsAirframeSubsystem 
    
    
    AutoPilot* itsAutoPilot;		//## link itsAutoPilot 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedApp1_task_0001ms : virtual public AOMInstance {

    
    DECLARE_META(App1_task_0001ms, OMAnimatedApp1_task_0001ms)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\App1_task_0001ms.h
*********************************************************************/

