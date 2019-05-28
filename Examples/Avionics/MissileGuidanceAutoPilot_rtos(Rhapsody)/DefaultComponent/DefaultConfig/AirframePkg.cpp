/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: AirframePkg
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\AirframePkg.cpp
*********************************************************************/

#include "AirframePkg.h"
#include "Units.h"
#include "aeroComposition.h"
#include "aeroDynamics.h"
#include "aeroFrame.h"
#include "aeroPort.h"
#include "AtmoHeightPort.h"
#include "AtmoPort.h"
#include "atmosphere.h"
#include "bodyDynamics.h"
#include "engineDynamics.h"
#include "finDynamics.h"
#include "FinPort.h"
#include "GustPort.h"
#include "gustWind.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// AirframePkg.cpp                                                                  
//----------------------------------------------------------------------------


//## operation fromMKS(double,Units & ) 
double fromMKS(double  data, Units & unit) {
    //#[ operation fromMKS(double,Units & ) 
    
    	double newData;
    
    	if(unit.bias==0.0)
    		newData = data/unit.slope;
    	else
    		newData = data/unit.slope - unit.bias;
    
    	return newData;
    //#]
}

//## operation toMKS(double,Units & ) 
double toMKS(double  data, Units & unit) {
    //#[ operation toMKS(double,Units & ) 
    
    	double newData;
    
    	if(unit.bias==0.0)
    		newData = data*unit.slope;
    	else
    		newData = (data + unit.bias)*unit.slope ;
    
    	return newData;
    //#]
}


evSL::evSL() {
    lId = evSL_AirframePkg_id;
}

OMBoolean evSL::isTypeOf(short  id) const {
    if(evSL_AirframePkg_id==id)
        return TRUE;
    else
        return FALSE;
}



evSH::evSH() {
    lId = evSH_AirframePkg_id;
}

OMBoolean evSH::isTypeOf(short  id) const {
    if(evSH_AirframePkg_id==id)
        return TRUE;
    else
        return FALSE;
}



evNorm::evNorm() {
    lId = evNorm_AirframePkg_id;
}

OMBoolean evNorm::isTypeOf(short  id) const {
    if(evNorm_AirframePkg_id==id)
        return TRUE;
    else
        return FALSE;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\AirframePkg.cpp
*********************************************************************/

