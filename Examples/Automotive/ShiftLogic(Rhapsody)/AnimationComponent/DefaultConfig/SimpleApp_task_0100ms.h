/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: SimpleApp_task_0100ms
//!	Generated Date	: Wed, 11, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\SimpleApp_task_0100ms.h
*********************************************************************/


#ifndef SimpleApp_task_0100ms_H 

#define SimpleApp_task_0100ms_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AppSimple.h"
#include "OnUMLEso.h"
#include "fstream.h"

//## package AppSimple 

//----------------------------------------------------------------------------
// SimpleApp_task_0100ms.h                                                                  
//----------------------------------------------------------------------------
class Chart;
class Controller;

#ifdef _OMINSTRUMENT
class OMAnimatedSimpleApp_task_0100ms;
#endif // _OMINSTRUMENT
class ShiftLever;
class SimpleGearbox;
class Throttle;


//## class SimpleApp_task_0100ms 
class SimpleApp_task_0100ms  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedSimpleApp_task_0100ms;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation SimpleApp_task_0100ms() 
    SimpleApp_task_0100ms();
    
    //## operation ~SimpleApp_task_0100ms() 
    ~SimpleApp_task_0100ms();


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
    
    Chart* itsGearChart;		//## link itsGearChart 
    
    
    Controller* itsShiftController;		//## link itsShiftController 
    
    
    ShiftLever* itsShiftLever;		//## link itsShiftLever 
    
    
    SimpleGearbox* itsSimpleGearbox;		//## link itsSimpleGearbox 
    
    
    Throttle* itsSpeed;		//## link itsSpeed 
    
    
    Chart* itsSpeedChart;		//## link itsSpeedChart 
    
    
    Throttle* itsThrottle;		//## link itsThrottle 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedSimpleApp_task_0100ms : virtual public AOMInstance {

    
    DECLARE_META(SimpleApp_task_0100ms, OMAnimatedSimpleApp_task_0100ms)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\SimpleApp_task_0100ms.h
*********************************************************************/

