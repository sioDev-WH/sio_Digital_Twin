/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: GimbalControllerCoeff
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\GimbalControllerCoeff.cpp
*********************************************************************/

#include "GimbalControllerCoeff.h"

//## package TrackingSubsystemPkg 

//----------------------------------------------------------------------------
// GimbalControllerCoeff.cpp                                                                  
//----------------------------------------------------------------------------
//## class GimbalControllerCoeff 



GimbalControllerCoeff::GimbalControllerCoeff() {
    //#[ operation GimbalControllerCoeff() 
    init();
    //#]
}

GimbalControllerCoeff::~GimbalControllerCoeff() {
}

void GimbalControllerCoeff::clean() {
    //#[ operation clean() 
    //#]
}

void GimbalControllerCoeff::init() {
    //#[ operation init() 
    rateLoopBandwidth	=   40.0 * PI ;	
    GimbalAngle_max		=   35.0 * d2r;
    GimbalAngle_min		=   -35.0 * d2r;
    TrackingTimeConstant= 0.05;  
    RadomeAberrtion		= -0.02;
    //#]
}

void GimbalControllerCoeff::setPeriod(long  val) {
    //#[ operation setPeriod(long) 
    period = val;
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

long GimbalControllerCoeff::getPeriod() const {
    return period;
}

double GimbalControllerCoeff::getRateLoopBandwidth() const {
    return rateLoopBandwidth;
}

void GimbalControllerCoeff::setRateLoopBandwidth(double  p_rateLoopBandwidth) {
    rateLoopBandwidth = p_rateLoopBandwidth;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\GimbalControllerCoeff.cpp
*********************************************************************/

