/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: TransmissionModels
//!	Generated Date	: Fri, 3, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\TransmissionModels.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "TransmissionModels.h"
#include "Actuator.h"
#include "ActuatorClutchConnector.h"
#include "Band_Brake.h"
#include "BrakeActuator.h"
#include "Clutch.h"
#include "ClutchBase.h"
#include "CRigidConnector.h"
#include "Engine.h"
#include "Gear.h"
#include "Oneway_Clutch.h"
#include "PlanetaryCoupler.h"
#include "Ravigneaux.h"
#include "Torque_Converter.h"

//## package TransmissionModels 


//#[ ignore 
#define es_SlipToLock_SERIALIZE OM_NO_OP


#define es_SlipToLock_UNSERIALIZE OM_NO_OP


#define es_SlipToLock_CONSTRUCTOR es_SlipToLock()


#define es_LockTocSlip_SERIALIZE OM_NO_OP


#define es_LockTocSlip_UNSERIALIZE OM_NO_OP


#define es_LockTocSlip_CONSTRUCTOR es_LockTocSlip()


#define es_LockToccSlip_SERIALIZE OM_NO_OP


#define es_LockToccSlip_UNSERIALIZE OM_NO_OP


#define es_LockToccSlip_CONSTRUCTOR es_LockToccSlip()


#define ec_Engage_SERIALIZE OM_NO_OP


#define ec_Engage_UNSERIALIZE OM_NO_OP


#define ec_Engage_CONSTRUCTOR ec_Engage()


#define ec_Disengage_SERIALIZE OM_NO_OP


#define ec_Disengage_UNSERIALIZE OM_NO_OP


#define ec_Disengage_CONSTRUCTOR ec_Disengage()


#define es_Start_SERIALIZE OM_NO_OP


#define es_Start_UNSERIALIZE OM_NO_OP


#define es_Start_CONSTRUCTOR es_Start()


#define es_On_SERIALIZE OM_NO_OP


#define es_On_UNSERIALIZE OM_NO_OP


#define es_On_CONSTRUCTOR es_On()


#define es_Stop_SERIALIZE OM_NO_OP


#define es_Stop_UNSERIALIZE OM_NO_OP


#define es_Stop_CONSTRUCTOR es_Stop()


#define es_TMM_SERIALIZE OM_NO_OP


#define es_TMM_UNSERIALIZE OM_NO_OP


#define es_TMM_CONSTRUCTOR es_TMM()


#define es_FCM_SERIALIZE OM_NO_OP


#define es_FCM_UNSERIALIZE OM_NO_OP


#define es_FCM_CONSTRUCTOR es_FCM()


#define es_Lock_SERIALIZE OM_NO_OP


#define es_Lock_UNSERIALIZE OM_NO_OP


#define es_Lock_CONSTRUCTOR es_Lock()
//#]

//----------------------------------------------------------------------------
// TransmissionModels.cpp                                                                  
//----------------------------------------------------------------------------


#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes*  aomsAttributes);
#endif // _OMINSTRUMENT
IMPLEMENT_META_PACKAGE(TransmissionModels,TransmissionModels)



#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes*  aomsAttributes) {
}

#endif // _OMINSTRUMENT

es_SlipToLock::es_SlipToLock() {
    NOTIFY_EVENT_CONSTRUCTOR(es_SlipToLock)
    lId = es_SlipToLock_TransmissionModels_id;
}

OMBoolean es_SlipToLock::isTypeOf(short  id) const {
    if(es_SlipToLock_TransmissionModels_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(es_SlipToLock, TransmissionModels, es_SlipToLock())
#endif // _OMINSTRUMENT


es_LockTocSlip::es_LockTocSlip() {
    NOTIFY_EVENT_CONSTRUCTOR(es_LockTocSlip)
    lId = es_LockTocSlip_TransmissionModels_id;
}

OMBoolean es_LockTocSlip::isTypeOf(short  id) const {
    if(es_LockTocSlip_TransmissionModels_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(es_LockTocSlip, TransmissionModels, es_LockTocSlip())
#endif // _OMINSTRUMENT


es_LockToccSlip::es_LockToccSlip() {
    NOTIFY_EVENT_CONSTRUCTOR(es_LockToccSlip)
    lId = es_LockToccSlip_TransmissionModels_id;
}

OMBoolean es_LockToccSlip::isTypeOf(short  id) const {
    if(es_LockToccSlip_TransmissionModels_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(es_LockToccSlip, TransmissionModels, es_LockToccSlip())
#endif // _OMINSTRUMENT


ec_Engage::ec_Engage() {
    NOTIFY_EVENT_CONSTRUCTOR(ec_Engage)
    lId = ec_Engage_TransmissionModels_id;
}

OMBoolean ec_Engage::isTypeOf(short  id) const {
    if(ec_Engage_TransmissionModels_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(ec_Engage, TransmissionModels, ec_Engage())
#endif // _OMINSTRUMENT


ec_Disengage::ec_Disengage() {
    NOTIFY_EVENT_CONSTRUCTOR(ec_Disengage)
    lId = ec_Disengage_TransmissionModels_id;
}

OMBoolean ec_Disengage::isTypeOf(short  id) const {
    if(ec_Disengage_TransmissionModels_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(ec_Disengage, TransmissionModels, ec_Disengage())
#endif // _OMINSTRUMENT


es_Start::es_Start() {
    NOTIFY_EVENT_CONSTRUCTOR(es_Start)
    lId = es_Start_TransmissionModels_id;
}

OMBoolean es_Start::isTypeOf(short  id) const {
    if(es_Start_TransmissionModels_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(es_Start, TransmissionModels, es_Start())
#endif // _OMINSTRUMENT


es_On::es_On() {
    NOTIFY_EVENT_CONSTRUCTOR(es_On)
    lId = es_On_TransmissionModels_id;
}

OMBoolean es_On::isTypeOf(short  id) const {
    if(es_On_TransmissionModels_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(es_On, TransmissionModels, es_On())
#endif // _OMINSTRUMENT


es_Stop::es_Stop() {
    NOTIFY_EVENT_CONSTRUCTOR(es_Stop)
    lId = es_Stop_TransmissionModels_id;
}

OMBoolean es_Stop::isTypeOf(short  id) const {
    if(es_Stop_TransmissionModels_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(es_Stop, TransmissionModels, es_Stop())
#endif // _OMINSTRUMENT


es_TMM::es_TMM() {
    NOTIFY_EVENT_CONSTRUCTOR(es_TMM)
    lId = es_TMM_TransmissionModels_id;
}

OMBoolean es_TMM::isTypeOf(short  id) const {
    if(es_TMM_TransmissionModels_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(es_TMM, TransmissionModels, es_TMM())
#endif // _OMINSTRUMENT


es_FCM::es_FCM() {
    NOTIFY_EVENT_CONSTRUCTOR(es_FCM)
    lId = es_FCM_TransmissionModels_id;
}

OMBoolean es_FCM::isTypeOf(short  id) const {
    if(es_FCM_TransmissionModels_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(es_FCM, TransmissionModels, es_FCM())
#endif // _OMINSTRUMENT


es_Lock::es_Lock() {
    NOTIFY_EVENT_CONSTRUCTOR(es_Lock)
    lId = es_Lock_TransmissionModels_id;
}

OMBoolean es_Lock::isTypeOf(short  id) const {
    if(es_Lock_TransmissionModels_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(es_Lock, TransmissionModels, es_Lock())
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\TransmissionModels.cpp
*********************************************************************/

