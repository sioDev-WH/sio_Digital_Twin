/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Application
//!	Generated Date	: Tue, 21, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Application.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "Application.h"
#include "DemoDrivetrain.h"
#include "DemoDrivetrain_task_0100ms.h"
#include "DemoDrivetrainApp.h"
#include "DemoDrivetrainSubsystem.h"
#include "theApp.h"

//## package Application 


//#[ ignore 
#define evTick_SERIALIZE OM_NO_OP


#define evTick_UNSERIALIZE OM_NO_OP


#define evTick_CONSTRUCTOR evTick()
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


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Application.cpp
*********************************************************************/

