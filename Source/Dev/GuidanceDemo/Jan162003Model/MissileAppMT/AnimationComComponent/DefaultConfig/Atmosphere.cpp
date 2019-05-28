/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: Atmosphere
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\Atmosphere.cpp
*********************************************************************/

#include "Atmosphere.h"
#include "AtmoCoeff.h"
#include "stdafx.h"
#include "math.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// Atmosphere.cpp                                                                  
//----------------------------------------------------------------------------
//## class Atmosphere 



Atmosphere::Atmosphere() {
    pCoeff = NULL;
    //#[ operation Atmosphere() 
    init();
    //#]
}

Atmosphere::~Atmosphere() {
    //#[ operation ~Atmosphere() 
    clean();
    //#]
    cleanUpRelations();
}

void Atmosphere::clean() {
    //#[ operation clean() 
    if (pCoeff)
    {
      delete pCoeff;
      pCoeff = NULL;
    }
    //#]
}

void Atmosphere::init() {
    //#[ operation init() 
    double initialHeight = 10000/m2ft;
    
    pCoeff = new AtmoCoeff;
    setHeight(initialHeight);
    setCoeff(pCoeff);
    updateData(initialHeight);
    //#]
}

void Atmosphere::setCoeff(AtmoCoeff * pC) {
    //#[ operation setCoeff(AtmoCoeff * ) 
    if(pC) pCoeff = pC; else pCoeff = 0;
    //#]
}

void Atmosphere::setHeight(double  h) {
    //#[ operation setHeight(double) 
    height=h;
    //#]
}

void Atmosphere::updateData(double  height) {
    //#[ operation updateData(double) 
    // Assumption:
    // This is called only from the AeroDynamics.init()
    // If the height was changing
    
    // Saturation block [0,troposphere]
    double h;
    AtmoCoeff& C = *pCoeff;
    h = height;
    if(h<0) h = 0;
    if(h > C.troposphere)h = C.troposphere;
    
    temperature = C.seaLevelTemperature - C.lapseRate * h;
    speedOfSound = sqrt(C.specificHeatRatio*C.R*temperature);
    
    double temperatureRatio = (temperature/C.seaLevelTemperature);
    double temp1 = pow(temperatureRatio,C.gravity/C.lapseRate/C.R);
    double temp2 = temp1/temperatureRatio;
    temp1 *= C.seaLevelPressure;
    temp2 *= C.seaLevelDensity;
    
    // Saturation block [troposphere - maxHeightRange,0]
    h = height-C.troposphere;
    if(h < 0) h = 0;
    if(h > C.maxHeightRange)h = C.maxHeightRange;
    
    
    double temp3 = exp(h*C.gravity/C.R/temperature);
    
    airPressure = temp1 * temp3;
    airDensity  = temp2 * temp3;
    
    //#]
}

double Atmosphere::getAirDensity() const {
    return airDensity;
}

void Atmosphere::setAirDensity(double  p_airDensity) {
    airDensity = p_airDensity;
}

double Atmosphere::getAirPressure() const {
    return airPressure;
}

void Atmosphere::setAirPressure(double  p_airPressure) {
    airPressure = p_airPressure;
}

double Atmosphere::getHeight() const {
    return height;
}

double Atmosphere::getSpeedOfSound() const {
    return speedOfSound;
}

void Atmosphere::setSpeedOfSound(double  p_speedOfSound) {
    speedOfSound = p_speedOfSound;
}

double Atmosphere::getTemperature() const {
    return temperature;
}

void Atmosphere::setTemperature(double  p_temperature) {
    temperature = p_temperature;
}

AtmoCoeff* Atmosphere::getPCoeff() const {
    return pCoeff;
}

void Atmosphere::setPCoeff(AtmoCoeff*  p_AtmoCoeff) {
    pCoeff = p_AtmoCoeff;
}

void Atmosphere::cleanUpRelations() {
    if(pCoeff != NULL)
        {
            pCoeff = NULL;
        }
}



/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\Atmosphere.cpp
*********************************************************************/

