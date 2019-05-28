/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: AvionicsPkg
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\AvionicsPkg.cpp
*********************************************************************/

#include "AvionicsPkg.h"
#include "ControlDesigner.h"

//## package LibraryPkg::AvionicsPkg 

//----------------------------------------------------------------------------
// AvionicsPkg.cpp                                                                  
//----------------------------------------------------------------------------



evGustWindTick::evGustWindTick() {
    lId = evGustWindTick_AvionicsPkg_LibraryPkg_id;
}

OMBoolean evGustWindTick::isTypeOf(short  id) const {
    if(evGustWindTick_AvionicsPkg_LibraryPkg_id==id)
        return TRUE;
    else
        return FALSE;
}



evEnter::evEnter() {
    lId = evEnter_AvionicsPkg_LibraryPkg_id;
}

OMBoolean evEnter::isTypeOf(short  id) const {
    if(evEnter_AvionicsPkg_LibraryPkg_id==id)
        return TRUE;
    else
        return FALSE;
}



evExit::evExit() {
    lId = evExit_AvionicsPkg_LibraryPkg_id;
}

OMBoolean evExit::isTypeOf(short  id) const {
    if(evExit_AvionicsPkg_LibraryPkg_id==id)
        return TRUE;
    else
        return FALSE;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\AvionicsPkg.cpp
*********************************************************************/

