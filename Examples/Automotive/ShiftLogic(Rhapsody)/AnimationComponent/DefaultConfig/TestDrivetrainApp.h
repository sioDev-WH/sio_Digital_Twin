/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: TestDrivetrainApp
//!	Generated Date	: Fri, 27, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\TestDrivetrainApp.h
*********************************************************************/


#ifndef TestDrivetrainApp_H 

#define TestDrivetrainApp_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "Application.h"
#include "OnUMLEso.h"
#include "fstream.h"

//## package Application 

//----------------------------------------------------------------------------
// TestDrivetrainApp.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedTestDrivetrainApp;
#endif // _OMINSTRUMENT
class TestDrivetrainApp_task_0100ms;


//## class TestDrivetrainApp 
class TestDrivetrainApp  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedTestDrivetrainApp;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation TestDrivetrainApp() 
    TestDrivetrainApp();
    
    //## operation ~TestDrivetrainApp() 
    ~TestDrivetrainApp();


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
    
    TestDrivetrainApp_task_0100ms* task_0100ms;		//## link task_0100ms 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedTestDrivetrainApp : virtual public AOMInstance {

    
    DECLARE_META(TestDrivetrainApp, OMAnimatedTestDrivetrainApp)


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\TestDrivetrainApp.h
*********************************************************************/

