/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: SeekerSubsystemCoeff
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\SeekerSubsystemCoeff.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "SeekerSubsystemCoeff.h"
#include <stdafx.h>

//## package SeekerSubsystemPkg 


//#[ ignore 
#define SeekerSubsystemPkg_SeekerSubsystemCoeff_SeekerSubsystemCoeff_SERIALIZE OM_NO_OP


#define SeekerSubsystemPkg_SeekerSubsystemCoeff_clean_SERIALIZE OM_NO_OP


#define SeekerSubsystemPkg_SeekerSubsystemCoeff_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// SeekerSubsystemCoeff.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(SeekerSubsystemPkg)
//## class SeekerSubsystemCoeff 



SeekerSubsystemCoeff::SeekerSubsystemCoeff() {
    NOTIFY_CONSTRUCTOR(SeekerSubsystemCoeff, SeekerSubsystemCoeff(), 0, SeekerSubsystemPkg_SeekerSubsystemCoeff_SeekerSubsystemCoeff_SERIALIZE);
    //#[ operation SeekerSubsystemCoeff() 
    init();
    //#]
}

SeekerSubsystemCoeff::~SeekerSubsystemCoeff() {
    NOTIFY_DESTRUCTOR(~SeekerSubsystemCoeff, TRUE);
}

void SeekerSubsystemCoeff::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, SeekerSubsystemPkg_SeekerSubsystemCoeff_clean_SERIALIZE);
    //#[ operation clean() 
    //#]
}

void SeekerSubsystemCoeff::init() {
    NOTIFY_OPERATION(init, init(), 0, SeekerSubsystemPkg_SeekerSubsystemCoeff_init_SERIALIZE);
    //#[ operation init() 
    period = 10.0;
    radarBeamWidth  = 10*d2r;
    radarFrameRate = 100; // Hz
    //#]
}

double SeekerSubsystemCoeff::getPeriod() const {
    return period;
}

void SeekerSubsystemCoeff::setPeriod(double  p_period) {
    period = p_period;
}

double SeekerSubsystemCoeff::getRadarBeamWidth() const {
    return radarBeamWidth;
}

void SeekerSubsystemCoeff::setRadarBeamWidth(double  p_radarBeamWidth) {
    radarBeamWidth = p_radarBeamWidth;
}

double SeekerSubsystemCoeff::getRadarFrameRate() const {
    return radarFrameRate;
}

void SeekerSubsystemCoeff::setRadarFrameRate(double  p_radarFrameRate) {
    radarFrameRate = p_radarFrameRate;
}



#ifdef _OMINSTRUMENT


void OMAnimatedSeekerSubsystemCoeff::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("radarBeamWidth", x2String(myReal->radarBeamWidth));
    aomsAttributes->addAttribute("period", x2String(myReal->period));
    aomsAttributes->addAttribute("radarFrameRate", x2String(myReal->radarFrameRate));
}

IMPLEMENT_META(SeekerSubsystemCoeff, SeekerSubsystemPkg, FALSE, OMAnimatedSeekerSubsystemCoeff)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\SeekerSubsystemCoeff.cpp
*********************************************************************/

