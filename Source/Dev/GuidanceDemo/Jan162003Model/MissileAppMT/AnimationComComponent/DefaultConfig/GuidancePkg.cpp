/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: GuidancePkg
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\GuidancePkg.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "GuidancePkg.h"
#include "GuidanceLogic.h"

//## package GuidancePkg 


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


#define evTargetLost_SERIALIZE OM_NO_OP


#define evTargetLost_UNSERIALIZE OM_NO_OP


#define evTargetLost_CONSTRUCTOR evTargetLost()


#define evGuidanceTick_SERIALIZE OM_NO_OP


#define evGuidanceTick_UNSERIALIZE OM_NO_OP


#define evGuidanceTick_CONSTRUCTOR evGuidanceTick()
//#]

//----------------------------------------------------------------------------
// GuidancePkg.cpp                                                                  
//----------------------------------------------------------------------------


#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes*  aomsAttributes);
#endif // _OMINSTRUMENT
IMPLEMENT_META_PACKAGE(GuidancePkg,GuidancePkg)



#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes*  aomsAttributes) {
}

#endif // _OMINSTRUMENT

evTargetAcquired::evTargetAcquired() {
    NOTIFY_EVENT_CONSTRUCTOR(evTargetAcquired)
    lId = evTargetAcquired_GuidancePkg_id;
}

OMBoolean evTargetAcquired::isTypeOf(short  id) const {
    if(evTargetAcquired_GuidancePkg_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(evTargetAcquired, GuidancePkg, evTargetAcquired())
#endif // _OMINSTRUMENT


evDetonate::evDetonate() {
    NOTIFY_EVENT_CONSTRUCTOR(evDetonate)
    lId = evDetonate_GuidancePkg_id;
}

OMBoolean evDetonate::isTypeOf(short  id) const {
    if(evDetonate_GuidancePkg_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(evDetonate, GuidancePkg, evDetonate())
#endif // _OMINSTRUMENT


evTimeout::evTimeout() {
    NOTIFY_EVENT_CONSTRUCTOR(evTimeout)
    lId = evTimeout_GuidancePkg_id;
}

OMBoolean evTimeout::isTypeOf(short  id) const {
    if(evTimeout_GuidancePkg_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(evTimeout, GuidancePkg, evTimeout())
#endif // _OMINSTRUMENT


evTargetLost::evTargetLost() {
    NOTIFY_EVENT_CONSTRUCTOR(evTargetLost)
    lId = evTargetLost_GuidancePkg_id;
}

OMBoolean evTargetLost::isTypeOf(short  id) const {
    if(evTargetLost_GuidancePkg_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(evTargetLost, GuidancePkg, evTargetLost())
#endif // _OMINSTRUMENT


evGuidanceTick::evGuidanceTick() {
    NOTIFY_EVENT_CONSTRUCTOR(evGuidanceTick)
    lId = evGuidanceTick_GuidancePkg_id;
}

OMBoolean evGuidanceTick::isTypeOf(short  id) const {
    if(evGuidanceTick_GuidancePkg_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(evGuidanceTick, GuidancePkg, evGuidanceTick())
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\GuidancePkg.cpp
*********************************************************************/

