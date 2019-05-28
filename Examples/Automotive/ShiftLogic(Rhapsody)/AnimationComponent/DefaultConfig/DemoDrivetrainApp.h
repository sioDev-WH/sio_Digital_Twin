/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: DemoDrivetrainApp
//!	Generated Date	: Tue, 21, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\DemoDrivetrainApp.h
*********************************************************************/


#ifndef DemoDrivetrainApp_H 

#define DemoDrivetrainApp_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "Application.h"
#include "OnUMLEso.h"
#include "fstream.h"

//## package Application 

//----------------------------------------------------------------------------
// DemoDrivetrainApp.h                                                                  
//----------------------------------------------------------------------------
class DemoDrivetrain_task_0100ms;

#ifdef _OMINSTRUMENT
class OMAnimatedDemoDrivetrainApp;
#endif // _OMINSTRUMENT


//## class DemoDrivetrainApp 
class DemoDrivetrainApp  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedDemoDrivetrainApp;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation DemoDrivetrainApp() 
    DemoDrivetrainApp();
    
    //## operation ~DemoDrivetrainApp() 
    ~DemoDrivetrainApp();


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
    
    DemoDrivetrain_task_0100ms* task_0100ms;		//## link task_0100ms 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedDemoDrivetrainApp : virtual public AOMInstance {

    
    DECLARE_META(DemoDrivetrainApp, OMAnimatedDemoDrivetrainApp)


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\DemoDrivetrainApp.h
*********************************************************************/

