/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: TestDrivetrainApp_task_0100ms
//!	Generated Date	: Fri, 27, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\TestDrivetrainApp_task_0100ms.h
*********************************************************************/


#ifndef TestDrivetrainApp_task_0100ms_H 

#define TestDrivetrainApp_task_0100ms_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "Application.h"
#include "OnUMLEso.h"
#include "fstream.h"

//## package Application 

//----------------------------------------------------------------------------
// TestDrivetrainApp_task_0100ms.h                                                                  
//----------------------------------------------------------------------------
class Brakes;
class Chart;
class Controller;

#ifdef _OMINSTRUMENT
class OMAnimatedTestDrivetrainApp_task_0100ms;
#endif // _OMINSTRUMENT
class ShiftLever;
class TestDrivetrainSS;
class Throttle;


//## class TestDrivetrainApp_task_0100ms 
class TestDrivetrainApp_task_0100ms  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedTestDrivetrainApp_task_0100ms;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation TestDrivetrainApp_task_0100ms() 
    TestDrivetrainApp_task_0100ms();
    
    //## operation ~TestDrivetrainApp_task_0100ms() 
    ~TestDrivetrainApp_task_0100ms();


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
    
    Chart* itsEngineChart;		//## link itsEngineChart 
    
    
    Controller* itsShiftController;		//## link itsShiftController 
    
    
    ShiftLever* itsShiftLever;		//## link itsShiftLever 
    
    
    Chart* itsSpeedChart;		//## link itsSpeedChart 
    
    
    TestDrivetrainSS* itsTestDrivetrainSS;		//## link itsTestDrivetrainSS 
    
    
    Throttle* itsThrottle;		//## link itsThrottle 
    
    
    Brakes* itsWheelBrake;		//## link itsWheelBrake 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedTestDrivetrainApp_task_0100ms : virtual public AOMInstance {

    
    DECLARE_META(TestDrivetrainApp_task_0100ms, OMAnimatedTestDrivetrainApp_task_0100ms)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\TestDrivetrainApp_task_0100ms.h
*********************************************************************/

