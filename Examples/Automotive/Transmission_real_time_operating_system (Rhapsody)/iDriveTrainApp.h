/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: iDriveTrainApp
//!	Generated Date	: Tue, 21, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\iDriveTrainApp.h
*********************************************************************/


#ifndef iDriveTrainApp_H 

#define iDriveTrainApp_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "Application.h"
#include "OnUMLEso.h"
#include "fstream.h"

//## package Application 

//----------------------------------------------------------------------------
// iDriveTrainApp.h                                                                  
//----------------------------------------------------------------------------
class iDriveTrain_task_0100ms;

#ifdef _OMINSTRUMENT
class OMAnimatediDriveTrainApp;
#endif // _OMINSTRUMENT


//## class iDriveTrainApp 
class iDriveTrainApp  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatediDriveTrainApp;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation iDriveTrainApp() 
    iDriveTrainApp();
    
    //## operation ~iDriveTrainApp() 
    ~iDriveTrainApp();


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
    
    iDriveTrain_task_0100ms* task_0100ms;		//## link task_0100ms 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatediDriveTrainApp : virtual public AOMInstance {

    
    DECLARE_META(iDriveTrainApp, OMAnimatediDriveTrainApp)


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\iDriveTrainApp.h
*********************************************************************/

