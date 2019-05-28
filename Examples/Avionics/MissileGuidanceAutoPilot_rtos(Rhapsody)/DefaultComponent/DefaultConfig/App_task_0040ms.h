/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: App_task_0040ms
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\App_task_0040ms.h
*********************************************************************/


#ifndef App_task_0040ms_H 

#define App_task_0040ms_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "Default.h"
#include "OnUMLEso.h"
#include "fstream.h"

//## package Default 

//----------------------------------------------------------------------------
// App_task_0040ms.h                                                                  
//----------------------------------------------------------------------------
class Animation;
class EstimatorLOS;


//## class App_task_0040ms 
class App_task_0040ms  {
 

////    Constructors and destructors    ////
public :
    
    //## operation App_task_0040ms() 
    App_task_0040ms();
    
    //## operation ~App_task_0040ms() 
    ~App_task_0040ms();


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
    
    Animation* AnimationBlock;		//## link AnimationBlock 
    
    
    EstimatorLOS* EstimatorLOSBlock;		//## link EstimatorLOSBlock 
    


};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\App_task_0040ms.h
*********************************************************************/

