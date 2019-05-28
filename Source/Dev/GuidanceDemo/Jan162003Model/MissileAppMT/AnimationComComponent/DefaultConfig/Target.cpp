/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: Target
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\Target.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "Target.h"
#include "math.h"

//## package TargetPkg 


//#[ ignore 
#define TargetPkg_Target_Target_SERIALIZE OM_NO_OP


#define TargetPkg_Target_clean_SERIALIZE OM_NO_OP


#define TargetPkg_Target_get_x_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define TargetPkg_Target_get_z_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define TargetPkg_Target_handle_tick_SERIALIZE aomsmethod->addAttribute("t", x2String(t));


#define TargetPkg_Target_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// Target.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(TargetPkg)
//## class Target 



Target::Target() {
    NOTIFY_CONSTRUCTOR(Target, Target(), 0, TargetPkg_Target_Target_SERIALIZE);
    //#[ operation Target() 
    init();
    //#]
}

Target::~Target() {
    NOTIFY_DESTRUCTOR(~Target, TRUE);
    //#[ operation ~Target() 
    //#]
}

void Target::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, TargetPkg_Target_clean_SERIALIZE);
    //#[ operation clean() 
      
    //#]
}

void Target::get_x(const double  t, double *val) {
    NOTIFY_OPERATION(get_x, get_x(const double,double *), 2, TargetPkg_Target_get_x_SERIALIZE);
    //#[ operation get_x(const double,double *) 
    
    *val = x; 
    //#]
}

void Target::get_z(const double  t, double *val) {
    NOTIFY_OPERATION(get_z, get_z(const double,double *), 2, TargetPkg_Target_get_z_SERIALIZE);
    //#[ operation get_z(const double,double *) 
    
    *val = z; 
    //#]
}

void Target::handle_tick(const double  t) {
    NOTIFY_OPERATION(handle_tick, handle_tick(const double), 1, TargetPkg_Target_handle_tick_SERIALIZE);
    //#[ operation handle_tick(const double) 
    double distance = (period/1000.0)*V;
    receive();
    x += distance*cos(attitude);
    z -= distance*sin(attitude);
    broadcast(t);
    //#]
}

void Target::init() {
    NOTIFY_OPERATION(init, init(), 0, TargetPkg_Target_init_SERIALIZE);
    //#[ operation init() 
    double x_m=0.0; // Missile initial position in meter
    double z_m = 10000.0/m2ft; //Missile initial altitude in meter
    double theta_m = 0.0; // Mssile initial attitude 
    
    period = 10.0;
    
    x = (x_m + 4500.0);
    z = -(z_m + 500);
    V = 328; // 1 Mach
    attitude = (theta_m + 180.0*d2r); // target 
    
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

double Target::getPeriod() const {
    return period;
}

void Target::setPeriod(double  p_period) {
    period = p_period;
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



#ifdef _OMINSTRUMENT


void OMAnimatedTarget::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("x", x2String(myReal->x));
    aomsAttributes->addAttribute("z", x2String(myReal->z));
    aomsAttributes->addAttribute("attitude", x2String(myReal->attitude));
    aomsAttributes->addAttribute("V", x2String(myReal->V));
    aomsAttributes->addAttribute("period", x2String(myReal->period));
}

IMPLEMENT_META(Target, TargetPkg, FALSE, OMAnimatedTarget)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\Target.cpp
*********************************************************************/

