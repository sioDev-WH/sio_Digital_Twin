/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: App_task_0001ms
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\App_task_0001ms.h
*********************************************************************/


#ifndef App_task_0001ms_H 

#define App_task_0001ms_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "Default.h"
#include "OnUMLEso.h"
#include "fstream.h"
#include "chart.h"

//## package Default 

//----------------------------------------------------------------------------
// App_task_0001ms.h                                                                  
//----------------------------------------------------------------------------
class AppAirFrame;
class AutoPilot;


//## class App_task_0001ms 
class App_task_0001ms  {


////    Constructors and destructors    ////
public :
    
    //## operation App_task_0001ms() 
    App_task_0001ms();
    
    //## operation ~App_task_0001ms() 
    ~App_task_0001ms();


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
    
    AutoPilot* AutoPilotBlock;		//## link AutoPilotBlock 
    
    
    AppAirFrame* itsAppAirFrame;		//## link itsAppAirFrame 
    
    Chart* itsChart;
    Chart* itsChart1;

};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\App_task_0001ms.h
*********************************************************************/

