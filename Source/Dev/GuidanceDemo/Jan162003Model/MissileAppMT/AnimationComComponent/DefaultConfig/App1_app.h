/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: App1_app
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\App1_app.h
*********************************************************************/


#ifndef App1_app_H 

#define App1_app_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "Application.h"
#include "OnUMLEso.h"
#include "fstream.h"

//## package Application 

//----------------------------------------------------------------------------
// App1_app.h                                                                  
//----------------------------------------------------------------------------
class App1_task_0001ms;
class App1_task_0010ms;
class App1_task_0040ms;

#ifdef _OMINSTRUMENT
class OMAnimatedApp1_app;
#endif // _OMINSTRUMENT


//## class App1_app 
class App1_app  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedApp1_app;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation App1_app() 
    App1_app();
    
    //## operation ~App1_app() 
    ~App1_app();


////    Operations    ////
public :
    
    //## operation clean() 
    void clean();
    
    //## operation handle_tick(const double) 
    void handle_tick(const double  t);
    
    //## operation init() 
    void init();


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Relations and components    ////
public :
    
    App1_task_0001ms* task_0001ms;		//## link task_0001ms 
    
    
    App1_task_0010ms* task_0010ms;		//## link task_0010ms 
    
    
    App1_task_0040ms* task_0040ms;		//## link task_0040ms 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedApp1_app : virtual public AOMInstance {

    
    DECLARE_META(App1_app, OMAnimatedApp1_app)


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\App1_app.h
*********************************************************************/

