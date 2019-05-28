/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: iDriveTrain_task_0100ms
//!	Generated Date	: Tue, 21, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\iDriveTrain_task_0100ms.h
*********************************************************************/


#ifndef iDriveTrain_task_0100ms_H 

#define iDriveTrain_task_0100ms_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "Application.h"
#include "OnUMLEso.h"
#include "fstream.h"

//## package Application 

//----------------------------------------------------------------------------
// iDriveTrain_task_0100ms.h                                                                  
//----------------------------------------------------------------------------
class Chart;
class Controller;
class Driver;
class iDriveTrainSubsystem;

#ifdef _OMINSTRUMENT
class OMAnimatediDriveTrain_task_0100ms;
#endif // _OMINSTRUMENT


//## class iDriveTrain_task_0100ms 
class iDriveTrain_task_0100ms  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatediDriveTrain_task_0100ms;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation iDriveTrain_task_0100ms() 
    iDriveTrain_task_0100ms();
    
    //## operation ~iDriveTrain_task_0100ms() 
    ~iDriveTrain_task_0100ms();


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
    
    Controller* ShiftLogicController;		//## link ShiftLogicController 
    
    
    Chart* SpeedChart;		//## link SpeedChart 
    
    
    Driver* itsDriver;		//## link itsDriver 
    
    
    Chart* itsEngineChart;		//## link itsEngineChart 
    
    
    iDriveTrainSubsystem* itsiDriveTrainSubsystem;		//## link itsiDriveTrainSubsystem 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatediDriveTrain_task_0100ms : virtual public AOMInstance {

    
    DECLARE_META(iDriveTrain_task_0100ms, OMAnimatediDriveTrain_task_0100ms)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\iDriveTrain_task_0100ms.h
*********************************************************************/

