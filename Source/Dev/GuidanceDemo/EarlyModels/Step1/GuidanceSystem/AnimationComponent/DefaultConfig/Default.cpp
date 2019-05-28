/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Default
//!	Generated Date	: Mon, 9, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\Default.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "stdafx.h"
#include "Default.h"
#include <OnUMLConnectorImpl.h>
#include <OnUMLDaeEsoImpl.h>

//## package Default 


//#[ ignore 
#define evTargetAcquired_SERIALIZE OM_NO_OP


#define evTargetAcquired_UNSERIALIZE OM_NO_OP


#define evTargetAcquired_CONSTRUCTOR evTargetAcquired()


#define evDetonate_SERIALIZE OM_NO_OP


#define evDetonate_UNSERIALIZE OM_NO_OP


#define evDetonate_CONSTRUCTOR evDetonate()


#define evTimeout_SERIALIZE OM_NO_OP


#define evTimeout_UNSERIALIZE OM_NO_OP


#define evTimeout_CONSTRUCTOR evTimeout()
//#]

//----------------------------------------------------------------------------
// Default.cpp                                                                  
//----------------------------------------------------------------------------


#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes*  aomsAttributes);
#endif // _OMINSTRUMENT
IMPLEMENT_META_PACKAGE(Default,Default)



#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes*  aomsAttributes) {
}

#endif // _OMINSTRUMENT

evTargetAcquired::evTargetAcquired() {
    NOTIFY_EVENT_CONSTRUCTOR(evTargetAcquired)
    lId = evTargetAcquired_Default_id;
}

OMBoolean evTargetAcquired::isTypeOf(short  id) const {
    if(evTargetAcquired_Default_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(evTargetAcquired, Default, evTargetAcquired())
#endif // _OMINSTRUMENT


evDetonate::evDetonate() {
    NOTIFY_EVENT_CONSTRUCTOR(evDetonate)
    lId = evDetonate_Default_id;
}

OMBoolean evDetonate::isTypeOf(short  id) const {
    if(evDetonate_Default_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(evDetonate, Default, evDetonate())
#endif // _OMINSTRUMENT


evTimeout::evTimeout() {
    NOTIFY_EVENT_CONSTRUCTOR(evTimeout)
    lId = evTimeout_Default_id;
}

OMBoolean evTimeout::isTypeOf(short  id) const {
    if(evTimeout_Default_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(evTimeout, Default, evTimeout())
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Default.cpp
*********************************************************************/

