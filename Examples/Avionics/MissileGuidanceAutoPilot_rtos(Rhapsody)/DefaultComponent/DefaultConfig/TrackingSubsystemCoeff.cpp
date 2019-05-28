/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: TrackingSubsystemCoeff
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\TrackingSubsystemCoeff.cpp
*********************************************************************/

#include "TrackingSubsystemCoeff.h"

//## package TrackingSubsystemPkg 

//----------------------------------------------------------------------------
// TrackingSubsystemCoeff.cpp                                                                  
//----------------------------------------------------------------------------
//## class TrackingSubsystemCoeff 



TrackingSubsystemCoeff::TrackingSubsystemCoeff() {
    //#[ operation TrackingSubsystemCoeff() 
    init();
    //#]
}

TrackingSubsystemCoeff::~TrackingSubsystemCoeff() {
}

void TrackingSubsystemCoeff::clean() {
    //#[ operation clean() 
    //#]
}

void TrackingSubsystemCoeff::init() {
    //#[ operation init() 
    period = 10;
    radarBeamWidth  = 10*d2r;
    radarFrameRate = 100; // Hz
    //#]
}

void TrackingSubsystemCoeff::setPeriod(long  val) {
    //#[ operation setPeriod(long) 
    //#]
}

long TrackingSubsystemCoeff::getPeriod() const {
    return period;
}

double TrackingSubsystemCoeff::getRadarBeamWidth() const {
    return radarBeamWidth;
}

void TrackingSubsystemCoeff::setRadarBeamWidth(double  p_radarBeamWidth) {
    radarBeamWidth = p_radarBeamWidth;
}

double TrackingSubsystemCoeff::getRadarFrameRate() const {
    return radarFrameRate;
}

void TrackingSubsystemCoeff::setRadarFrameRate(double  p_radarFrameRate) {
    radarFrameRate = p_radarFrameRate;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\TrackingSubsystemCoeff.cpp
*********************************************************************/

