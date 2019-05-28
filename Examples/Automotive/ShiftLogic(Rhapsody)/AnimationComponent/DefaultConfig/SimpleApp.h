/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: SimpleApp
//!	Generated Date	: Wed, 11, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\SimpleApp.h
*********************************************************************/


#ifndef SimpleApp_H 

#define SimpleApp_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AppSimple.h"
#include "OnUMLEso.h"
#include "fstream.h"

//## package AppSimple 

//----------------------------------------------------------------------------
// SimpleApp.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedSimpleApp;
#endif // _OMINSTRUMENT
class SimpleApp_task_0100ms;


//## class SimpleApp 
class SimpleApp  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedSimpleApp;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation SimpleApp() 
    SimpleApp();
    
    //## operation ~SimpleApp() 
    ~SimpleApp();


////    Operations    ////
public :
    
    //## operation clean() 
    void clean();
    
    //## operation handle_tick() 
    void handle_tick();
    
    //## operation init() 
     init();
    
    //## operation setTime(const double) 
    void setTime(const double  t);


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Relations and components    ////
public :
    
    SimpleApp_task_0100ms* task_0100ms;		//## link task_0100ms 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedSimpleApp : virtual public AOMInstance {

    
    DECLARE_META(SimpleApp, OMAnimatedSimpleApp)


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\SimpleApp.h
*********************************************************************/

