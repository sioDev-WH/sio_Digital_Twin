/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: StdApp_task_0100ms
//!	Generated Date	: Wed, 18, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\StdApp_task_0100ms.h
*********************************************************************/


#ifndef StdApp_task_0100ms_H 

#define StdApp_task_0100ms_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AppSimple.h"
#include "OnUMLEso.h"
#include "fstream.h"

//## package AppSimple 

//----------------------------------------------------------------------------
// StdApp_task_0100ms.h                                                                  
//----------------------------------------------------------------------------
class Brakes;
class Chart;
class Controller;

#ifdef _OMINSTRUMENT
class OMAnimatedStdApp_task_0100ms;
#endif // _OMINSTRUMENT
class ShiftLever;
class StdCarSS;
class Throttle;


//## class StdApp_task_0100ms 
class StdApp_task_0100ms  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedStdApp_task_0100ms;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation StdApp_task_0100ms() 
    StdApp_task_0100ms();
    
    //## operation ~StdApp_task_0100ms() 
    ~StdApp_task_0100ms();


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
    
    
    Chart* itsRPMChart;		//## link itsRPMChart 
    
    
    Controller* itsShiftController;		//## link itsShiftController 
    
    
    ShiftLever* itsShiftLever;		//## link itsShiftLever 
    
    
    Chart* itsSpeedChart;		//## link itsSpeedChart 
    
    
    StdCarSS* itsStdCarSS;		//## link itsStdCarSS 
    
    
    Throttle* itsThrottle;		//## link itsThrottle 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedStdApp_task_0100ms : virtual public AOMInstance {

    
    DECLARE_META(StdApp_task_0100ms, OMAnimatedStdApp_task_0100ms)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\StdApp_task_0100ms.h
*********************************************************************/

