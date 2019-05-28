/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: GuidancePkg
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\GuidancePkg.cpp
*********************************************************************/

#include "GuidancePkg.h"
#include "EstimatorLOS.h"
#include "EstimatorLOSCoeff.h"
#include "EstimatorVc.h"
#include "EstimatorVcCoeff.h"
#include "GuidanceLogic.h"

//## package GuidancePkg 

//----------------------------------------------------------------------------
// GuidancePkg.cpp                                                                  
//----------------------------------------------------------------------------



evTargetAcquired::evTargetAcquired() {
    lId = evTargetAcquired_GuidancePkg_id;
}

OMBoolean evTargetAcquired::isTypeOf(short  id) const {
    if(evTargetAcquired_GuidancePkg_id==id)
        return TRUE;
    else
        return FALSE;
}



evDetonate::evDetonate() {
    lId = evDetonate_GuidancePkg_id;
}

OMBoolean evDetonate::isTypeOf(short  id) const {
    if(evDetonate_GuidancePkg_id==id)
        return TRUE;
    else
        return FALSE;
}



evTimeout::evTimeout() {
    lId = evTimeout_GuidancePkg_id;
}

OMBoolean evTimeout::isTypeOf(short  id) const {
    if(evTimeout_GuidancePkg_id==id)
        return TRUE;
    else
        return FALSE;
}



evTargetLost::evTargetLost() {
    lId = evTargetLost_GuidancePkg_id;
}

OMBoolean evTargetLost::isTypeOf(short  id) const {
    if(evTargetLost_GuidancePkg_id==id)
        return TRUE;
    else
        return FALSE;
}



evGuidanceTick::evGuidanceTick() {
    lId = evGuidanceTick_GuidancePkg_id;
}

OMBoolean evGuidanceTick::isTypeOf(short  id) const {
    if(evGuidanceTick_GuidancePkg_id==id)
        return TRUE;
    else
        return FALSE;
}



evRadarTick::evRadarTick() {
    lId = evRadarTick_GuidancePkg_id;
}

OMBoolean evRadarTick::isTypeOf(short  id) const {
    if(evRadarTick_GuidancePkg_id==id)
        return TRUE;
    else
        return FALSE;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\GuidancePkg.cpp
*********************************************************************/

