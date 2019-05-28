/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: UI
//!	Generated Date	: Tue, 21, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\UI.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "UI.h"
#include "Driver.h"

//## package UI 


//#[ ignore 
#define evDriverTick_SERIALIZE OM_NO_OP


#define evDriverTick_UNSERIALIZE OM_NO_OP


#define evDriverTick_CONSTRUCTOR evDriverTick()
//#]

//----------------------------------------------------------------------------
// UI.cpp                                                                  
//----------------------------------------------------------------------------


#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes*  aomsAttributes);
#endif // _OMINSTRUMENT
IMPLEMENT_META_PACKAGE(UI,UI)



#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes*  aomsAttributes) {
}

#endif // _OMINSTRUMENT

evDriverTick::evDriverTick() {
    NOTIFY_EVENT_CONSTRUCTOR(evDriverTick)
    lId = evDriverTick_UI_id;
}

OMBoolean evDriverTick::isTypeOf(short  id) const {
    if(evDriverTick_UI_id==id)
        return TRUE;
    else
        return FALSE;
}


#ifdef _OMINSTRUMENT


IMPLEMENT_META_EVENT(evDriverTick, UI, evDriverTick())
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\UI.cpp
*********************************************************************/

