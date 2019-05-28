/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: DrivetrainApp_task_0100ms
//!	Generated Date	: Sun, 19, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\DrivetrainApp_task_0100ms.h
*********************************************************************/


#ifndef DrivetrainApp_task_0100ms_H 

#define DrivetrainApp_task_0100ms_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "Application.h"
#include "OnUMLEso.h"
#include "fstream.h"

//## package Application 

//----------------------------------------------------------------------------
// DrivetrainApp_task_0100ms.h                                                                  
//----------------------------------------------------------------------------
class Chart;
class Controller;
class DrivetrainSubsystem;

#ifdef _OMINSTRUMENT
class OMAnimatedDrivetrainApp_task_0100ms;
#endif // _OMINSTRUMENT
class Throttle;


//## class DrivetrainApp_task_0100ms 
class DrivetrainApp_task_0100ms  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedDrivetrainApp_task_0100ms;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation DrivetrainApp_task_0100ms() 
    DrivetrainApp_task_0100ms();
    
    //## operation ~DrivetrainApp_task_0100ms() 
    ~DrivetrainApp_task_0100ms();


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
    
    Chart* SpeedChart;		//## link SpeedChart 
    
    
    Controller* itsController;		//## link itsController 
    
    
    DrivetrainSubsystem* itsDrivetrainSubsystem;		//## link itsDrivetrainSubsystem 
    
    
    Chart* itsEngineChart;		//## link itsEngineChart 
    
    
    Throttle* itsThrottle;		//## link itsThrottle 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedDrivetrainApp_task_0100ms : virtual public AOMInstance {

    
    DECLARE_META(DrivetrainApp_task_0100ms, OMAnimatedDrivetrainApp_task_0100ms)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\DrivetrainApp_task_0100ms.h
*********************************************************************/

