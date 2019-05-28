/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: AtmoCoeff
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\AtmoCoeff.cpp
*********************************************************************/

#include "AtmoCoeff.h"
#include "stdafx.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// AtmoCoeff.cpp                                                                  
//----------------------------------------------------------------------------
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



/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\AtmoCoeff.cpp
*********************************************************************/

