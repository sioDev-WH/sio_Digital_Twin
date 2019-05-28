/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: GimbalControllerCoeff
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\GimbalControllerCoeff.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "GimbalControllerCoeff.h"
#include <stdafx.h>

//## package SeekerSubsystemPkg 


//#[ ignore 
#define SeekerSubsystemPkg_GimbalControllerCoeff_GimbalControllerCoeff_SERIALIZE OM_NO_OP


#define SeekerSubsystemPkg_GimbalControllerCoeff_clean_SERIALIZE OM_NO_OP


#define SeekerSubsystemPkg_GimbalControllerCoeff_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// GimbalControllerCoeff.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(SeekerSubsystemPkg)
//## class GimbalControllerCoeff 



GimbalControllerCoeff::GimbalControllerCoeff() {
    NOTIFY_CONSTRUCTOR(GimbalControllerCoeff, GimbalControllerCoeff(), 0, SeekerSubsystemPkg_GimbalControllerCoeff_GimbalControllerCoeff_SERIALIZE);
    //#[ operation GimbalControllerCoeff() 
    init();
    //#]
}

GimbalControllerCoeff::~GimbalControllerCoeff() {
    NOTIFY_DESTRUCTOR(~GimbalControllerCoeff, TRUE);
}

void GimbalControllerCoeff::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, SeekerSubsystemPkg_GimbalControllerCoeff_clean_SERIALIZE);
    //#[ operation clean() 
    //#]
}

void GimbalControllerCoeff::init() {
    NOTIFY_OPERATION(init, init(), 0, SeekerSubsystemPkg_GimbalControllerCoeff_init_SERIALIZE);
    //#[ operation init() 
    period		=    10;
    rateLoopBandwidth	=   40.0 * PI ;		//  Ks
    GimbalAngle_max		=   35.0 * d2r;
    GimbalAngle_min		=   -35.0 * d2r;
    TrackingTimeConstant= 0.05; // tors
    RadomeAberrtion		= -0.02;
    //#]
}

double GimbalControllerCoeff::getGimbalAngle_max() const {
    return GimbalAngle_max;
}

void GimbalControllerCoeff::setGimbalAngle_max(double  p_GimbalAngle_max) {
    GimbalAngle_max = p_GimbalAngle_max;
}

double GimbalControllerCoeff::getGimbalAngle_min() const {
    return GimbalAngle_min;
}

void GimbalControllerCoeff::setGimbalAngle_min(double  p_GimbalAngle_min) {
    GimbalAngle_min = p_GimbalAngle_min;
}

double GimbalControllerCoeff::getRadomeAberrtion() const {
    return RadomeAberrtion;
}

void GimbalControllerCoeff::setRadomeAberrtion(double  p_RadomeAberrtion) {
    RadomeAberrtion = p_RadomeAberrtion;
}

double GimbalControllerCoeff::getTrackingTimeConstant() const {
    return TrackingTimeConstant;
}

void GimbalControllerCoeff::setTrackingTimeConstant(double  p_TrackingTimeConstant) {
    TrackingTimeConstant = p_TrackingTimeConstant;
}

double GimbalControllerCoeff::getPeriod() const {
    return period;
}

void GimbalControllerCoeff::setPeriod(double  p_period) {
    period = p_period;
}

double GimbalControllerCoeff::getRateLoopBandwidth() const {
    return rateLoopBandwidth;
}

void GimbalControllerCoeff::setRateLoopBandwidth(double  p_rateLoopBandwidth) {
    rateLoopBandwidth = p_rateLoopBandwidth;
}



#ifdef _OMINSTRUMENT


void OMAnimatedGimbalControllerCoeff::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("period", x2String(myReal->period));
    aomsAttributes->addAttribute("rateLoopBandwidth", x2String(myReal->rateLoopBandwidth));
    aomsAttributes->addAttribute("TrackingTimeConstant", x2String(myReal->TrackingTimeConstant));
    aomsAttributes->addAttribute("GimbalAngle_max", x2String(myReal->GimbalAngle_max));
    aomsAttributes->addAttribute("GimbalAngle_min", x2String(myReal->GimbalAngle_min));
    aomsAttributes->addAttribute("RadomeAberrtion", x2String(myReal->RadomeAberrtion));
}

IMPLEMENT_META(GimbalControllerCoeff, SeekerSubsystemPkg, FALSE, OMAnimatedGimbalControllerCoeff)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\GimbalControllerCoeff.cpp
*********************************************************************/

