/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: ExtApp
//!	Generated Date	: Thu, 19, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\ExtApp.h
*********************************************************************/


#ifndef ExtApp_H 

#define ExtApp_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AppSimple.h"
#include "OnUMLEso.h"
#include "fstream.h"

//## package AppSimple 

//----------------------------------------------------------------------------
// ExtApp.h                                                                  
//----------------------------------------------------------------------------
class ExtApp_task_0100ms;

#ifdef _OMINSTRUMENT
class OMAnimatedExtApp;
#endif // _OMINSTRUMENT


//## class ExtApp 
class ExtApp  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedExtApp;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation ExtApp() 
    ExtApp();
    
    //## operation ~ExtApp() 
    ~ExtApp();


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
    
    ExtApp_task_0100ms* task_0100ms;		//## link task_0100ms 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedExtApp : virtual public AOMInstance {

    
    DECLARE_META(ExtApp, OMAnimatedExtApp)


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\ExtApp.h
*********************************************************************/

