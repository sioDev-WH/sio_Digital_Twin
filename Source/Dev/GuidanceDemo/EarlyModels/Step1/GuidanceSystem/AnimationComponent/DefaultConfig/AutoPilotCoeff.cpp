/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: AutoPilotCoeff
//!	Generated Date	: Tue, 10, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\AutoPilotCoeff.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "stdafx.h"
#include "AutoPilotCoeff.h"

//## package GuidancePkg 

//----------------------------------------------------------------------------
// AutoPilotCoeff.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(GuidancePkg)
//## class AutoPilotCoeff 



AutoPilotCoeff::AutoPilotCoeff() {
    //#[ operation AutoPilotCoeff() 
    init();
    //#]
}

AutoPilotCoeff::~AutoPilotCoeff() {
}

void AutoPilotCoeff::init() {
    //#[ operation init() 
    // WAH samplingPeriod =    0.001;
    samplingPeriod =    0.001;
    gyroGain		=   0.80004035323733;		//  W1
    accelGain		=   0.10730904477327;		//  W2
    gyroFilterZero	= 10.0;					// -W3
    gyroFilterPole	= 1.0;					// -W4
    antiAliasGain	= 100.0;
    antiAliasPole	= 100.0;
    //#]
}

void AutoPilotCoeff::setAccelGain(double  p_accelGain) {
    accelGain = p_accelGain;
}

void AutoPilotCoeff::setAntiAliasGain(double  p_antiAliasGain) {
    antiAliasGain = p_antiAliasGain;
}

void AutoPilotCoeff::setAntiAliasPole(double  p_antiAliasPole) {
    antiAliasPole = p_antiAliasPole;
}

void AutoPilotCoeff::setGyroFilterPole(double  p_gyroFilterPole) {
    gyroFilterPole = p_gyroFilterPole;
}

void AutoPilotCoeff::setGyroFilterZero(double  p_gyroFilterZero) {
    gyroFilterZero = p_gyroFilterZero;
}

void AutoPilotCoeff::setGyroGain(double  p_gyroGain) {
    gyroGain = p_gyroGain;
}

void AutoPilotCoeff::setSamplingPeriod(double  p_samplingPeriod) {
    samplingPeriod = p_samplingPeriod;
}



#ifdef _OMINSTRUMENT


void OMAnimatedAutoPilotCoeff::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

IMPLEMENT_META(AutoPilotCoeff, GuidancePkg, FALSE, OMAnimatedAutoPilotCoeff)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\AutoPilotCoeff.cpp
*********************************************************************/

