/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: AirframePkg
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\AirframePkg.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "AirframePkg.h"
#include "AeroCoeff.h"
#include "AeroDynamics.h"
#include "AtmoCoeff.h"
#include "Atmosphere.h"
#include "BodyDynamics.h"
#include "BodyDynamicsCoeff.h"
#include "FinActuator.h"
#include "FinActuatorCoeff.h"
#include "On1DConn.h"
#include "On3DConn.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// AirframePkg.cpp                                                                  
//----------------------------------------------------------------------------



evRun::evRun() {
    lId = evRun_AirframePkg_id;
}

OMBoolean evRun::isTypeOf(short  id) const {
    if(evRun_AirframePkg_id==id)
        return TRUE;
    else
        return FALSE;
}



/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\AirframePkg.cpp
*********************************************************************/

