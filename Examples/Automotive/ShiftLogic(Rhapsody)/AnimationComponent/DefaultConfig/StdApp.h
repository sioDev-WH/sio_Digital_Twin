/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: StdApp
//!	Generated Date	: Thu, 12, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\StdApp.h
*********************************************************************/


#ifndef StdApp_H 

#define StdApp_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AppSimple.h"
#include "OnUMLEso.h"
#include "fstream.h"

//## package AppSimple 

//----------------------------------------------------------------------------
// StdApp.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedStdApp;
#endif // _OMINSTRUMENT
class StdApp_task_0100ms;


//## class StdApp 
class StdApp  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedStdApp;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation StdApp() 
    StdApp();
    
    //## operation ~StdApp() 
    ~StdApp();


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
    
    StdApp_task_0100ms* task_0100ms;		//## link task_0100ms 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedStdApp : virtual public AOMInstance {

    
    DECLARE_META(StdApp, OMAnimatedStdApp)


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\StdApp.h
*********************************************************************/

