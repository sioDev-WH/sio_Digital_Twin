/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: Application
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\Application.h
*********************************************************************/


#ifndef Application_H 

#define Application_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include <oxf/event.h>
#include "units.h"

//## package Application 


//#[ ignore 
#define evTick_Application_id 19801


#define evTerminate_Application_id 19802


#define evMissionComplete_Application_id 19803
//#]

//----------------------------------------------------------------------------
// Application.h                                                                  
//----------------------------------------------------------------------------
class AirFrame;
class AirframeSubsystem;
class App1_app;
class App1_task_0001ms;
class App1_task_0010ms;
class App1_task_0040ms;
class theApp;
class evMissionComplete;
class evTerminate;
class evTick;

#ifdef _OMINSTRUMENT
class OMAnimatedevMissionComplete;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedevTerminate;
#endif // _OMINSTRUMENT

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
//## event evTerminate() 
class evTerminate : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedevTerminate;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    evTerminate();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedevTerminate : virtual public AOMEvent {

    
    DECLARE_META_EVENT(evTerminate)


};

#endif // _OMINSTRUMENT
//## event evMissionComplete() 
class evMissionComplete : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedevMissionComplete;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    evMissionComplete();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedevMissionComplete : virtual public AOMEvent {

    
    DECLARE_META_EVENT(evMissionComplete)


};

#endif // _OMINSTRUMENT


#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\Application.h
*********************************************************************/

