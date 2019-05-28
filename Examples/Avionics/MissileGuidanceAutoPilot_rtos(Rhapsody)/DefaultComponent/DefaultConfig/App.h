/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: App
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\App.h
*********************************************************************/


#ifndef App_H 

#define App_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "Default.h"
#include "OnUMLEso.h"
#include "fstream.h"

//## package Default 

//----------------------------------------------------------------------------
// App.h                                                                  
//----------------------------------------------------------------------------
class App_task_0001ms;
class App_task_0010ms;
class App_task_0040ms;


//## class App 
class App  {


////    Constructors and destructors    ////
public :
    
    //## operation App() 
    App();
    
    //## operation ~App() 
    ~App();


////    Operations    ////
public :
    
    //## operation clean() 
    void clean();
    
    //## operation handle_tick() 
    void handle_tick();
    
    //## operation init() 
    void init();
    
    //## operation setTime(const double) 
    void setTime(const double  t);


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Relations and components    ////
public :
    
    App_task_0001ms* task_0001ms;		//## link task_0001ms 
    
    
    App_task_0010ms* task_0010ms;		//## link task_0010ms 
    
    
    App_task_0040ms* task_0040ms;		//## link task_0040ms 
    


};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\App.h
*********************************************************************/

