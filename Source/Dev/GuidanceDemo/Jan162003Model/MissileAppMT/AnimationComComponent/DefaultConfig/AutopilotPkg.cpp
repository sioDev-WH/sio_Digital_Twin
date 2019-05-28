/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: AutopilotPkg
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\AutopilotPkg.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "AutopilotPkg.h"
#include "AutoPilot.h"
#include "AutoPilotCoeff.h"

//## package AutopilotPkg 


//#[ ignore 
#define evAutoPilotTick_SERIALIZE OM_NO_OP


#define evAutoPilotTick_UNSERIALIZE OM_NO_OP


#define evAutoPilotTick_CONSTRUCTOR evAutoPilotTick()
//#]

//----------------------------------------------------------------------------
// AutopilotPkg.cpp                                                                  
//----------------------------------------------------------------------------


#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes*  aomsAttributes);
#endif // _OMINSTRUMENT
IMPLEMENT_META_PACKAGE(AutopilotPkg,AutopilotPkg)



#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes*  aomsAttributes) {
}

#endif // _OMINSTRUMENT

evAutoPilotTick::evAutoPilotTick() {
    NOTIFY_EVENT_CONSTRUCTOR(evAutoPilotTick)
    lId = evAutoPilotTick_AutopilotPkg_id;
}

OMBoolean evAutoPilotTick::isTypeOf(short  id) const {
    if(evAutoPilotTick_AutopilotPkg_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(evAutoPilotTick, AutopilotPkg, evAutoPilotTick())
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\AutopilotPkg.cpp
*********************************************************************/

