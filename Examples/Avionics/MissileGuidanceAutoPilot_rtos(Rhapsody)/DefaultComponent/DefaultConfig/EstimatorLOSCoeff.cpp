/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: EstimatorLOSCoeff
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\EstimatorLOSCoeff.cpp
*********************************************************************/

#include "EstimatorLOSCoeff.h"
#include "math.h"

//## package GuidancePkg 

//----------------------------------------------------------------------------
// EstimatorLOSCoeff.cpp                                                                  
//----------------------------------------------------------------------------
//## class EstimatorLOSCoeff 



EstimatorLOSCoeff::EstimatorLOSCoeff() {
    //#[ operation EstimatorLOSCoeff() 
    init();
    //#]
}

EstimatorLOSCoeff::~EstimatorLOSCoeff() {
}

void EstimatorLOSCoeff::clean() {
    //#[ operation clean() 
    //#]
}

void EstimatorLOSCoeff::design(double  bandwidth) {
    //#[ operation design(double) 
    
    double Ts;
    double Wn = bandwidth;
    
    Ts = period/1000.0;
    A = exp(-Wn*Ts);   // Discrete eigenvalue
    B = (1.0 -A)*Wn;
    //#]
}

void EstimatorLOSCoeff::init() {
    //#[ operation init() 
    double Ts = period/1000.0;
    Bandwidth=7.0;
    design(Bandwidth);
    //#]
}

void EstimatorLOSCoeff::setBandwidth(double  omega) {
    //#[ operation setBandwidth(double) 
    Bandwidth = omega;
    //#]
}

void EstimatorLOSCoeff::setPeriod(long  val) {
    //#[ operation setPeriod(long) 
    period = val;
    //#]
}

double EstimatorLOSCoeff::getA() const {
    return A;
}

void EstimatorLOSCoeff::setA(double  p_A) {
    A = p_A;
}

double EstimatorLOSCoeff::getB() const {
    return B;
}

void EstimatorLOSCoeff::setB(double  p_B) {
    B = p_B;
}

double EstimatorLOSCoeff::getBandwidth() const {
    return Bandwidth;
}

long EstimatorLOSCoeff::getPeriod() const {
    return period;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\EstimatorLOSCoeff.cpp
*********************************************************************/

