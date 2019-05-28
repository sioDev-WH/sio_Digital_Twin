/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Target
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\Target.cpp
*********************************************************************/

#include "Target.h"
#include "math.h"

//## package TargetPkg 

//----------------------------------------------------------------------------
// Target.cpp                                                                  
//----------------------------------------------------------------------------
//## class Target 



Target::Target() {
    //#[ operation Target() 
    init();
    //#]
}

Target::~Target() {
    //#[ operation ~Target() 
    //#]
}

void Target::clean() {
    //#[ operation clean() 
      
    //#]
}

void Target::get_x(double *val) {
    //#[ operation get_x(double *) 
    
    *val = x; 
    //#]
}

void Target::get_z(double *val) {
    //#[ operation get_z(double *) 
    
    *val = z; 
    //#]
}

void Target::handle_tick() {
    //#[ operation handle_tick() 
    double distance = (period/1000.0)*V;
    receive();
    x += distance*cos(attitude);
    z -= distance*sin(attitude);
    broadcast();
    //#]
}

void Target::init() {
    //#[ operation init() 
    double x_m=0.0; // Missile initial position in meter
    double z_m = 10000.0/m2ft; //Missile initial altitude in meter
    double theta_m = 0.0; // Mssile initial attitude 
    
    x = (x_m + 4500.0);
    z = -(z_m + 500);
    V = 328; // 1 Mach
    attitude = (theta_m + 180.0*d2r); // target 
    
    //#]
}

void Target::setPeriod(long  val) {
    //#[ operation setPeriod(long) 
    period = val;
    //#]
}

double Target::getV() const {
    return V;
}

void Target::setV(double  p_V) {
    V = p_V;
}

double Target::getAttitude() const {
    return attitude;
}

void Target::setAttitude(double  p_attitude) {
    attitude = p_attitude;
}

long Target::getPeriod() const {
    return period;
}

double Target::getX() const {
    return x;
}

void Target::setX(double  p_x) {
    x = p_x;
}

double Target::getZ() const {
    return z;
}

void Target::setZ(double  p_z) {
    z = p_z;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Target.cpp
*********************************************************************/

