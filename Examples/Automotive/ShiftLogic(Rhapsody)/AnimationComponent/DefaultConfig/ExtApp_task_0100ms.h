/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: ExtApp_task_0100ms
//!	Generated Date	: Thu, 19, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\ExtApp_task_0100ms.h
*********************************************************************/


#ifndef ExtApp_task_0100ms_H 

#define ExtApp_task_0100ms_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AppSimple.h"
#include "OnUMLEso.h"
#include "fstream.h"

//## package AppSimple 

//----------------------------------------------------------------------------
// ExtApp_task_0100ms.h                                                                  
//----------------------------------------------------------------------------
class Brakes;
class Chart;
class Controller;
class ExtCarSS;

#ifdef _OMINSTRUMENT
class OMAnimatedExtApp_task_0100ms;
#endif // _OMINSTRUMENT
class ShiftLever;
class Throttle;


//## class ExtApp_task_0100ms 
class ExtApp_task_0100ms  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedExtApp_task_0100ms;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation ExtApp_task_0100ms() 
    ExtApp_task_0100ms();
    
    //## operation ~ExtApp_task_0100ms() 
    ~ExtApp_task_0100ms();


////    Operations    ////
public :
    
    //## operation broadcast() 
    void broadcast();
    
    //## operation clean() 
    void clean();
    
    //## operation handle_tick() 
    void handle_tick();
    
    //## operation init() 
    void init();
    
    //## operation setTime(const double) 
    void setTime(const double  t);


////    Additional operations    ////
protected :
    
    //## auto_generated 
    void setInterval(long  p_interval);
    
    //## auto_generated 
    void setNTicks(long  p_nTicks);


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
protected :
    
    long interval;		//## attribute interval 
    
    long nTicks;		//## attribute nTicks 
    

////    Relations and components    ////
public :
    
    Brakes* itsBrake;		//## link itsBrake 
    
    
    ExtCarSS* itsExtCarSS;		//## link itsExtCarSS 
    
    
    Chart* itsRPMChart;		//## link itsRPMChart 
    
    
    Controller* itsShiftController;		//## link itsShiftController 
    
    
    ShiftLever* itsShiftLever;		//## link itsShiftLever 
    
    
    Chart* itsSpeedChart;		//## link itsSpeedChart 
    
    
    Throttle* itsThrottle;		//## link itsThrottle 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedExtApp_task_0100ms : virtual public AOMInstance {

    
    DECLARE_META(ExtApp_task_0100ms, OMAnimatedExtApp_task_0100ms)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\ExtApp_task_0100ms.h
*********************************************************************/

