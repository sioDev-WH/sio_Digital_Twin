/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: GuidancePkg
//!	Generated Date	: Tue, 10, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\GuidancePkg.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "stdafx.h"
#include "GuidancePkg.h"
#include "AeroCoeff.h"
#include "AeroDynamics.h"
#include "AirFrame.h"
#include "AirFrameAutoPilotSystem.h"
#include "AtmoCoeff.h"
#include "Atmosphere.h"
#include "AutoPilot.h"
#include "AutoPilotCoeff.h"
#include "BodyDynamics.h"
#include "BodyDynamicsCoeff.h"
#include "FinActuator.h"
#include "FinActuatorCoeff.h"
#include "Guidance.h"
#include "myFactory.h"
#include "On1DConn.h"
#include "On3DConn.h"

//## package GuidancePkg 


//#[ ignore 
#define evRun_SERIALIZE OM_NO_OP


#define evRun_UNSERIALIZE OM_NO_OP


#define evRun_CONSTRUCTOR evRun()


#define evDetonate_SERIALIZE OM_NO_OP


#define evDetonate_UNSERIALIZE OM_NO_OP


#define evDetonate_CONSTRUCTOR evDetonate()


#define evTargetAcquired_SERIALIZE OM_NO_OP


#define evTargetAcquired_UNSERIALIZE OM_NO_OP


#define evTargetAcquired_CONSTRUCTOR evTargetAcquired()


#define evTimeout_SERIALIZE OM_NO_OP


#define evTimeout_UNSERIALIZE OM_NO_OP


#define evTimeout_CONSTRUCTOR evTimeout()
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



evRun::evRun() {
    NOTIFY_EVENT_CONSTRUCTOR(evRun)
    lId = evRun_GuidancePkg_id;
}

OMBoolean evRun::isTypeOf(short  id) const {
    if(evRun_GuidancePkg_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(evRun, GuidancePkg, evRun())
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


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\GuidancePkg.cpp
*********************************************************************/

