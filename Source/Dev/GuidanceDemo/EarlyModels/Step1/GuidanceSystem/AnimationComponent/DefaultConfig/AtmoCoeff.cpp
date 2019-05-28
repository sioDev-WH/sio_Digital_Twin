/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: AtmoCoeff
//!	Generated Date	: Tue, 10, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\AtmoCoeff.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "stdafx.h"
#include "AtmoCoeff.h"

//## package GuidancePkg 

//----------------------------------------------------------------------------
// AtmoCoeff.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(GuidancePkg)
//## class AtmoCoeff 



AtmoCoeff::AtmoCoeff() {
    //#[ operation AtmoCoeff() 
    init();
    //#]
}

AtmoCoeff::~AtmoCoeff() {
}

void AtmoCoeff::init() {
    //#[ operation init() 
    seaLevelTemperature=288.16;
    seaLevelPressure=101325.0;	
    seaLevelDensity=1.225;
    lapseRate=0.0065;
    R=287.26;
    specificHeatRatio=1.403;
    troposphere=11000.0/m2ft;
    maxHeightRange = 20000/m2ft;
    gravity = 9.81;
    //#]
}

void AtmoCoeff::setR(double  p_R) {
    R = p_R;
}

void AtmoCoeff::setGravity(double  p_gravity) {
    gravity = p_gravity;
}

void AtmoCoeff::setLapseRate(double  p_lapseRate) {
    lapseRate = p_lapseRate;
}

void AtmoCoeff::setMaxHeightRange(double  p_maxHeightRange) {
    maxHeightRange = p_maxHeightRange;
}

void AtmoCoeff::setSeaLevelDensity(double  p_seaLevelDensity) {
    seaLevelDensity = p_seaLevelDensity;
}

void AtmoCoeff::setSeaLevelPressure(double  p_seaLevelPressure) {
    seaLevelPressure = p_seaLevelPressure;
}

void AtmoCoeff::setSeaLevelTemperature(double  p_seaLevelTemperature) {
    seaLevelTemperature = p_seaLevelTemperature;
}

void AtmoCoeff::setSpecificHeatRatio(double  p_specificHeatRatio) {
    specificHeatRatio = p_specificHeatRatio;
}

void AtmoCoeff::setTroposphere(double  p_troposphere) {
    troposphere = p_troposphere;
}



#ifdef _OMINSTRUMENT


void OMAnimatedAtmoCoeff::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

IMPLEMENT_META(AtmoCoeff, GuidancePkg, FALSE, OMAnimatedAtmoCoeff)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\AtmoCoeff.cpp
*********************************************************************/

