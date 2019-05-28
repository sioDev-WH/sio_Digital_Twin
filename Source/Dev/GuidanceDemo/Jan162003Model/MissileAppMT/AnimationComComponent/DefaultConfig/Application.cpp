/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: Application
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\Application.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "Application.h"
#include "AirFrame.h"
#include "AirframeSubsystem.h"
#include "App1_app.h"
#include "App1_task_0001ms.h"
#include "App1_task_0010ms.h"
#include "App1_task_0040ms.h"
#include "theApp.h"

//## package Application 


//#[ ignore 
#define evTick_SERIALIZE OM_NO_OP


#define evTick_UNSERIALIZE OM_NO_OP


#define evTick_CONSTRUCTOR evTick()


#define evTerminate_SERIALIZE OM_NO_OP


#define evTerminate_UNSERIALIZE OM_NO_OP


#define evTerminate_CONSTRUCTOR evTerminate()


#define evMissionComplete_SERIALIZE OM_NO_OP


#define evMissionComplete_UNSERIALIZE OM_NO_OP


#define evMissionComplete_CONSTRUCTOR evMissionComplete()
//#]

//----------------------------------------------------------------------------
// Application.cpp                                                                  
//----------------------------------------------------------------------------


#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes*  aomsAttributes);
#endif // _OMINSTRUMENT
IMPLEMENT_META_PACKAGE(Application,Application)



#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes*  aomsAttributes) {
}

#endif // _OMINSTRUMENT

evTick::evTick() {
    NOTIFY_EVENT_CONSTRUCTOR(evTick)
    lId = evTick_Application_id;
}

OMBoolean evTick::isTypeOf(short  id) const {
    if(evTick_Application_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(evTick, Application, evTick())
#endif // _OMINSTRUMENT


evTerminate::evTerminate() {
    NOTIFY_EVENT_CONSTRUCTOR(evTerminate)
    lId = evTerminate_Application_id;
}

OMBoolean evTerminate::isTypeOf(short  id) const {
    if(evTerminate_Application_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(evTerminate, Application, evTerminate())
#endif // _OMINSTRUMENT


evMissionComplete::evMissionComplete() {
    NOTIFY_EVENT_CONSTRUCTOR(evMissionComplete)
    lId = evMissionComplete_Application_id;
}

OMBoolean evMissionComplete::isTypeOf(short  id) const {
    if(evMissionComplete_Application_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(evMissionComplete, Application, evMissionComplete())
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\Application.cpp
*********************************************************************/

