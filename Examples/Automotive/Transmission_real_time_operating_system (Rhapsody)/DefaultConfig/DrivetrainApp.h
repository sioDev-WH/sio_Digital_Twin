/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: DrivetrainApp
//!	Generated Date	: Sun, 19, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\DrivetrainApp.h
*********************************************************************/


#ifndef DrivetrainApp_H 

#define DrivetrainApp_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "Application.h"
#include "OnUMLEso.h"
#include "fstream.h"

//## package Application 

//----------------------------------------------------------------------------
// DrivetrainApp.h                                                                  
//----------------------------------------------------------------------------
class DrivetrainApp_task_0100ms;

#ifdef _OMINSTRUMENT
class OMAnimatedDrivetrainApp;
#endif // _OMINSTRUMENT


//## class DrivetrainApp 
class DrivetrainApp  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedDrivetrainApp;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation DrivetrainApp() 
    DrivetrainApp();
    
    //## operation ~DrivetrainApp() 
    ~DrivetrainApp();


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
    
    DrivetrainApp_task_0100ms* task_0100ms;		//## link task_0100ms 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedDrivetrainApp : virtual public AOMInstance {

    
    DECLARE_META(DrivetrainApp, OMAnimatedDrivetrainApp)


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\DrivetrainApp.h
*********************************************************************/

