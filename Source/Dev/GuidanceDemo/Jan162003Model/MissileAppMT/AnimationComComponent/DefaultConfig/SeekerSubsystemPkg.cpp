/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: SeekerSubsystemPkg
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\SeekerSubsystemPkg.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "SeekerSubsystemPkg.h"
#include "EstimatorLOS.h"
#include "EstimatorLOSCoeff.h"
#include "GimbalController.h"
#include "GimbalControllerCoeff.h"
#include "RateStabilizationFilter.h"
#include "RateStabilizationFilterCoeff.h"
#include "SeekerSubsystem.h"
#include "SeekerSubsystemCoeff.h"

//## package SeekerSubsystemPkg 

//----------------------------------------------------------------------------
// SeekerSubsystemPkg.cpp                                                                  
//----------------------------------------------------------------------------


#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes*  aomsAttributes);
#endif // _OMINSTRUMENT
IMPLEMENT_META_PACKAGE(SeekerSubsystemPkg,SeekerSubsystemPkg)



#ifdef _OMINSTRUMENT
static void serializeGlobalVars(AOMSAttributes*  aomsAttributes) {
}

#endif // _OMINSTRUMENT

/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\SeekerSubsystemPkg.cpp
*********************************************************************/

