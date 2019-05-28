/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Default
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\Default.cpp
*********************************************************************/

#include "Default.h"
#include "App.h"
#include "App_task_0001ms.h"
#include "App_task_0010ms.h"
#include "App_task_0040ms.h"
#include "AppAirFrame.h"

//## package Default 

//----------------------------------------------------------------------------
// Default.cpp                                                                  
//----------------------------------------------------------------------------

evTick::evTick() {
    lId = evTick_Default_id;
}

OMBoolean evTick::isTypeOf(short  id) const {
    if(evTick_Default_id==id)
        return TRUE;
    else
        return FALSE;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Default.cpp
*********************************************************************/

