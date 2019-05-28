/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Application
//!	Generated Date	: Tue, 21, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Application.h
*********************************************************************/


#ifndef Application_H 

#define Application_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <oxf/event.h>
#include "stdafx.h"

//## package Application 


//#[ ignore 
#define evTick_Application_id 19801
//#]

//----------------------------------------------------------------------------
// Application.h                                                                  
//----------------------------------------------------------------------------
class DemoDrivetrain;
class DemoDrivetrain_task_0100ms;
class DemoDrivetrainApp;
class DemoDrivetrainSubsystem;
class theApp;
class evTick;

#ifdef _OMINSTRUMENT
class OMAnimatedevTick;
#endif // _OMINSTRUMENT



//## event evTick() 
class evTick : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedevTick;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    evTick();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedevTick : virtual public AOMEvent {

    
    DECLARE_META_EVENT(evTick)


};

#endif // _OMINSTRUMENT


#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Application.h
*********************************************************************/

