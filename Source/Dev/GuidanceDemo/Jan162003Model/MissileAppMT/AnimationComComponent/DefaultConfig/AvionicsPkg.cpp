/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: AvionicsPkg
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\AvionicsPkg.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "AvionicsPkg.h"
#include "ControlDesigner.h"
#include "crossProduct.h"
#include "dotProduct.h"
#include "ScheduledController_1D.h"
#include "ScheduledController_1D_Coeff.h"
#include "transformAngle_DMC2Euler.h"
#include "transformAngle_Euler2Quaternion.h"
#include "transformAngleRate.h"
#include "transformPosition_B2I.h"
#include "transformPosition_I2B.h"
#include "WindGust.h"

//## package LibraryPkg::AvionicsPkg 


//#[ ignore 
#define evGustWindTick_SERIALIZE OM_NO_OP


#define evGustWindTick_UNSERIALIZE OM_NO_OP


#define evGustWindTick_CONSTRUCTOR evGustWindTick()


#define evEnter_SERIALIZE OM_NO_OP


#define evEnter_UNSERIALIZE OM_NO_OP


#define evEnter_CONSTRUCTOR evEnter()


#define evExit_SERIALIZE OM_NO_OP


#define evExit_UNSERIALIZE OM_NO_OP


#define evExit_CONSTRUCTOR evExit()
//#]

//----------------------------------------------------------------------------
// AvionicsPkg.cpp                                                                  
//----------------------------------------------------------------------------


#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes*  aomsAttributes);
#endif // _OMINSTRUMENT
IMPLEMENT_META_PACKAGE(LibraryPkg_AvionicsPkg,LibraryPkg::AvionicsPkg)



#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes*  aomsAttributes) {
}

#endif // _OMINSTRUMENT

evGustWindTick::evGustWindTick() {
    NOTIFY_EVENT_CONSTRUCTOR(evGustWindTick)
    lId = evGustWindTick_AvionicsPkg_LibraryPkg_id;
}

OMBoolean evGustWindTick::isTypeOf(short  id) const {
    if(evGustWindTick_AvionicsPkg_LibraryPkg_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(evGustWindTick, LibraryPkg_AvionicsPkg, evGustWindTick())
#endif // _OMINSTRUMENT


evEnter::evEnter() {
    NOTIFY_EVENT_CONSTRUCTOR(evEnter)
    lId = evEnter_AvionicsPkg_LibraryPkg_id;
}

OMBoolean evEnter::isTypeOf(short  id) const {
    if(evEnter_AvionicsPkg_LibraryPkg_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(evEnter, LibraryPkg_AvionicsPkg, evEnter())
#endif // _OMINSTRUMENT


evExit::evExit() {
    NOTIFY_EVENT_CONSTRUCTOR(evExit)
    lId = evExit_AvionicsPkg_LibraryPkg_id;
}

OMBoolean evExit::isTypeOf(short  id) const {
    if(evExit_AvionicsPkg_LibraryPkg_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(evExit, LibraryPkg_AvionicsPkg, evExit())
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\AvionicsPkg.cpp
*********************************************************************/

