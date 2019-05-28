/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: AutopilotPkg
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\AutopilotPkg.cpp
*********************************************************************/

#include "AutopilotPkg.h"
#include "AutoPilot.h"
#include "AutoPilotCoeff.h"

//## package AutopilotPkg 

//----------------------------------------------------------------------------
// AutopilotPkg.cpp                                                                  
//----------------------------------------------------------------------------



evAutoPilotTick::evAutoPilotTick() {
    lId = evAutoPilotTick_AutopilotPkg_id;
}

OMBoolean evAutoPilotTick::isTypeOf(short  id) const {
    if(evAutoPilotTick_AutopilotPkg_id==id)
        return TRUE;
    else
        return FALSE;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\AutopilotPkg.cpp
*********************************************************************/

