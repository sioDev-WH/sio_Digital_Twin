/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: GimbalController
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\GimbalController.cpp
*********************************************************************/

#include <oxf/omthread.h>
#include "GimbalController.h"

//## package TrackingSubsystemPkg 

//----------------------------------------------------------------------------
// GimbalController.cpp                                                                  
//----------------------------------------------------------------------------
//## class GimbalController 



GimbalController::GimbalController(OMThread*  p_thread) {
    setThread(p_thread, FALSE);
    //#[ operation GimbalController() 
    init();
    //#]
}

GimbalController::~GimbalController() {
}

void GimbalController::adjustGimbalAngle(double  dishError, double  stabilizedRate) {
    //#[ operation adjustGimbalAngle(double,double) 
    double Ts = Coeff.period/1000.0 ; 
    double feedbackSignal; 
    
    
        feedbackSignal = dishError/Coeff.TrackingTimeConstant - stabilizedRate;
        gimbalAngleRate = gimbalAngleRate + Ts * Coeff.rateLoopBandwidth * feedbackSignal;
        gimbalAngle = gimbalAngle + Ts*gimbalAngleRate;
    	if(gimbalAngle > Coeff.GimbalAngle_max) gimbalAngle = Coeff.GimbalAngle_max;
        if(gimbalAngle < Coeff.GimbalAngle_min) gimbalAngle = Coeff.GimbalAngle_min;
    
    //#]
}

void GimbalController::clean() {
    //#[ operation clean() 
    //#]
}

double GimbalController::computeDishError(double  lookAngle, double  dishCommand, int  guidanceMode) {
    //#[ operation computeDishError(double,double,int) 
    
      if(guidanceMode>1)
        dishError = lookAngle - gimbalAngle 
                   + Coeff.RadomeAberrtion*gimbalAngle  +  0.01* lookAngle * (0.5-rand()/RAND_MAX);
      else
        dishError = dishCommand*d2r - gimbalAngle; 
        
      return dishError;
    //#]
}

void GimbalController::init() {
    //#[ operation init() 
    gimbalAngle = 0.0;
    gimbalAngleRate = 0.0;
    //#]
}

void GimbalController::setPeriod(long  val) {
    //#[ operation setPeriod(long) 
    Coeff.setPeriod(val);
    //#]
}

double GimbalController::getDishError() const {
    return dishError;
}

void GimbalController::setDishError(double  p_dishError) {
    dishError = p_dishError;
}

double GimbalController::getGimbalAngle() const {
    return gimbalAngle;
}

void GimbalController::setGimbalAngle(double  p_gimbalAngle) {
    gimbalAngle = p_gimbalAngle;
}

double GimbalController::getGimbalAngleRate() const {
    return gimbalAngleRate;
}

void GimbalController::setGimbalAngleRate(double  p_gimbalAngleRate) {
    gimbalAngleRate = p_gimbalAngleRate;
}

GimbalControllerCoeff* GimbalController::getCoeff() const {
    return (GimbalControllerCoeff*) &Coeff;
}

OMBoolean GimbalController::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\GimbalController.cpp
*********************************************************************/

