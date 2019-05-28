/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: App_task_0010ms
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\App_task_0010ms.h
*********************************************************************/


#ifndef App_task_0010ms_H 

#define App_task_0010ms_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "Default.h"
#include "OnUMLEso.h"
#include "fstream.h"

//## package Default 

//----------------------------------------------------------------------------
// App_task_0010ms.h                                                                  
//----------------------------------------------------------------------------
class EstimatorVc;
class GuidanceLogic;
class Target;
class TrackingSubsystem;


//## class App_task_0010ms 
class App_task_0010ms  {


////    Constructors and destructors    ////
public :
    
    //## operation App_task_0010ms() 
    App_task_0010ms();
    
    //## operation ~App_task_0010ms() 
    ~App_task_0010ms();


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
    
    EstimatorVc* EstimatorVcBlock;		//## link EstimatorVcBlock 
    
    
    GuidanceLogic* GuidanceLogicBlock;		//## link GuidanceLogicBlock 
    
    
    Target* TargetBlock;		//## link TargetBlock 
    
    
    TrackingSubsystem* TrackingSubsystemBlock;		//## link TrackingSubsystemBlock 
    


};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\App_task_0010ms.h
*********************************************************************/

