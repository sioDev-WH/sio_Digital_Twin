/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: EstimatorVcCoeff
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\EstimatorVcCoeff.cpp
*********************************************************************/

#include "EstimatorVcCoeff.h"
#include "math.h"

//## package GuidancePkg 

//----------------------------------------------------------------------------
// EstimatorVcCoeff.cpp                                                                  
//----------------------------------------------------------------------------
//## class EstimatorVcCoeff 



EstimatorVcCoeff::EstimatorVcCoeff() {
    //#[ operation EstimatorVcCoeff() 
    init();
    //#]
}

EstimatorVcCoeff::~EstimatorVcCoeff() {
}

void EstimatorVcCoeff::clean() {
    //#[ operation clean() 
    //#]
}

void EstimatorVcCoeff::design(double  bandwidth) {
    //#[ operation design(double) 
    
    double Ts;
    double Wn = bandwidth;
    
    Ts = period/1000.0;
    A = exp(-Wn*Ts);   // Discrete eigenvalue
    B = (1.0 -A)*Wn;
    //#]
}

void EstimatorVcCoeff::init() {
    //#[ operation init() 
    double Ts = period/1000.0; 
    Bandwidth = 7;
    design(Bandwidth);
    //#]
}

void EstimatorVcCoeff::setBandwidth(double  omega) {
    //#[ operation setBandwidth(double) 
    Bandwidth = omega;
    //#]
}

void EstimatorVcCoeff::setPeriod(long  val) {
    //#[ operation setPeriod(long) 
    period = val;
    //#]
}

double EstimatorVcCoeff::getA() const {
    return A;
}

void EstimatorVcCoeff::setA(double  p_A) {
    A = p_A;
}

double EstimatorVcCoeff::getB() const {
    return B;
}

void EstimatorVcCoeff::setB(double  p_B) {
    B = p_B;
}

double EstimatorVcCoeff::getBandwidth() const {
    return Bandwidth;
}

long EstimatorVcCoeff::getPeriod() const {
    return period;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\EstimatorVcCoeff.cpp
*********************************************************************/

