/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: TransmissionControlModels
//!	Generated Date	: Sun, 19, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\TransmissionControlModels.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "TransmissionControlModels.h"
#include "Clutch_Schedule.h"
#include "Controller.h"
#include "GearInfo.h"
#include "ShiftData.h"

//## package TransmissionControlModels 


//#[ ignore 
#define manualNeutralShift_SERIALIZE OM_NO_OP


#define manualNeutralShift_UNSERIALIZE OM_NO_OP


#define manualNeutralShift_CONSTRUCTOR manualNeutralShift()


#define manualReverseShift_SERIALIZE OM_NO_OP


#define manualReverseShift_UNSERIALIZE OM_NO_OP


#define manualReverseShift_CONSTRUCTOR manualReverseShift()


#define manualForwardShift_SERIALIZE OM_NO_OP


#define manualForwardShift_UNSERIALIZE OM_NO_OP


#define manualForwardShift_CONSTRUCTOR manualForwardShift()


#define upshift_SERIALIZE OM_NO_OP


#define upshift_UNSERIALIZE OM_NO_OP


#define upshift_CONSTRUCTOR upshift()


#define downshift_SERIALIZE OM_NO_OP


#define downshift_UNSERIALIZE OM_NO_OP


#define downshift_CONSTRUCTOR downshift()


#define tic_SERIALIZE OM_NO_OP


#define tic_UNSERIALIZE OM_NO_OP


#define tic_CONSTRUCTOR tic()


#define shift_SERIALIZE OM_NO_OP


#define shift_UNSERIALIZE OM_NO_OP


#define shift_CONSTRUCTOR shift()
//#]

//----------------------------------------------------------------------------
// TransmissionControlModels.cpp                                                                  
//----------------------------------------------------------------------------


#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes*  aomsAttributes);
#endif // _OMINSTRUMENT
IMPLEMENT_META_PACKAGE(TransmissionControlModels,TransmissionControlModels)



#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes*  aomsAttributes) {
}

#endif // _OMINSTRUMENT

manualNeutralShift::manualNeutralShift() {
    NOTIFY_EVENT_CONSTRUCTOR(manualNeutralShift)
    lId = manualNeutralShift_TransmissionControlModels_id;
}

OMBoolean manualNeutralShift::isTypeOf(short  id) const {
    if(manualNeutralShift_TransmissionControlModels_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(manualNeutralShift, TransmissionControlModels, manualNeutralShift())
#endif // _OMINSTRUMENT


manualReverseShift::manualReverseShift() {
    NOTIFY_EVENT_CONSTRUCTOR(manualReverseShift)
    lId = manualReverseShift_TransmissionControlModels_id;
}

OMBoolean manualReverseShift::isTypeOf(short  id) const {
    if(manualReverseShift_TransmissionControlModels_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(manualReverseShift, TransmissionControlModels, manualReverseShift())
#endif // _OMINSTRUMENT


manualForwardShift::manualForwardShift() {
    NOTIFY_EVENT_CONSTRUCTOR(manualForwardShift)
    lId = manualForwardShift_TransmissionControlModels_id;
}

OMBoolean manualForwardShift::isTypeOf(short  id) const {
    if(manualForwardShift_TransmissionControlModels_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(manualForwardShift, TransmissionControlModels, manualForwardShift())
#endif // _OMINSTRUMENT


upshift::upshift() {
    NOTIFY_EVENT_CONSTRUCTOR(upshift)
    lId = upshift_TransmissionControlModels_id;
}

OMBoolean upshift::isTypeOf(short  id) const {
    if(upshift_TransmissionControlModels_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(upshift, TransmissionControlModels, upshift())
#endif // _OMINSTRUMENT


downshift::downshift() {
    NOTIFY_EVENT_CONSTRUCTOR(downshift)
    lId = downshift_TransmissionControlModels_id;
}

OMBoolean downshift::isTypeOf(short  id) const {
    if(downshift_TransmissionControlModels_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(downshift, TransmissionControlModels, downshift())
#endif // _OMINSTRUMENT


tic::tic() {
    NOTIFY_EVENT_CONSTRUCTOR(tic)
    lId = tic_TransmissionControlModels_id;
}

OMBoolean tic::isTypeOf(short  id) const {
    if(tic_TransmissionControlModels_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(tic, TransmissionControlModels, tic())
#endif // _OMINSTRUMENT


shift::shift() {
    NOTIFY_EVENT_CONSTRUCTOR(shift)
    lId = shift_TransmissionControlModels_id;
}

OMBoolean shift::isTypeOf(short  id) const {
    if(shift_TransmissionControlModels_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(shift, TransmissionControlModels, shift())
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\TransmissionControlModels.cpp
*********************************************************************/

