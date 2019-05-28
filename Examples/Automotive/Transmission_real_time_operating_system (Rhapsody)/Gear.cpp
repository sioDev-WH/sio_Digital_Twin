/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Gear
//!	Generated Date	: Wed, 8, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Gear.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "Gear.h"

//## package TransmissionModels 


//#[ ignore 
#define TransmissionModels_Gear_Gear_SERIALIZE OM_NO_OP


#define TransmissionModels_Gear_InitLocalIPars_SERIALIZE OM_NO_OP


#define TransmissionModels_Gear_InitLocalRPars_SERIALIZE OM_NO_OP


#define TransmissionModels_Gear_InitLocalVars_SERIALIZE OM_NO_OP


#define TransmissionModels_Gear_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// Gear.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(TransmissionModels)
//## class Gear 



Gear::Gear() {
    NOTIFY_CONSTRUCTOR(Gear, Gear(), 0, TransmissionModels_Gear_Gear_SERIALIZE);
    //#[ operation Gear() 
    init();
    //#]
}

Gear::~Gear() {
    NOTIFY_DESTRUCTOR(~Gear, TRUE);
    //#[ operation ~Gear() 
    //#]
}

HRESULT Gear::InitLocalIPars(const _TCHAR * prefix, pplong * pars, ppchar * Names, long * nPars, long * dPars) {
    NOTIFY_OPERATION(InitLocalIPars, InitLocalIPars(const _TCHAR * ,pplong * ,ppchar * ,long * ,long * ), 0, TransmissionModels_Gear_InitLocalIPars_SERIALIZE);
    //#[ operation InitLocalIPars(const _TCHAR * ,pplong * ,ppchar * ,long * ,long * ) 
    /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
    //{{SCG_OP_BODY
    
    
      ADD_LOCAL_SIPAR(nTeeth)
    
      return S_OK;
    
    //}}SCG_OP_BODY
    /***** End of automatically generated code *****/
    //#]
}

HRESULT Gear::InitLocalRPars(const _TCHAR * prefix, ppdouble * pars, ppchar * Names, long * nPars, long * dPars) {
    NOTIFY_OPERATION(InitLocalRPars, InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ), 0, TransmissionModels_Gear_InitLocalRPars_SERIALIZE);
    //#[ operation InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ) 
    /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
    //{{SCG_OP_BODY
    
    
      ADD_LOCAL_SRPAR(radius)
      ADD_LOCAL_SRPAR(inertia)
    
      return S_OK;
    
    //}}SCG_OP_BODY
    /***** End of automatically generated code *****/
    //#]
}

HRESULT Gear::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    NOTIFY_OPERATION(InitLocalVars, InitLocalVars(const _TCHAR * ,VarCont * ,const bool ), 0, TransmissionModels_Gear_InitLocalVars_SERIALIZE);
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
    //{{SCG_OP_BODY
    
    
      ADD_LOCAL_SVAR(acceleration)
      ADD_LOCAL_SVAR(torque)
      ADD_LOCAL_SVAR(speed)
    
      return S_OK;
    
    //}}SCG_OP_BODY
    /***** End of automatically generated code *****/
    //#]
}

void Gear::init() {
    NOTIFY_OPERATION(init, init(), 0, TransmissionModels_Gear_init_SERIALIZE);
    //#[ operation init() 
    /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
    //{{SCG_OP_BODY
    torque = 0.0;
    speed = 0.0;
    acceleration = 0.0;
    
    DER(torque) = 0.0;
    DER(speed) = 0.0;
    DER(acceleration) = 0.0;
    
    inertia = 0.1;
    nTeeth = 20;
    radius = 0.1;
    
    //}}SCG_OP_BODY
    /***** End of automatically generated code *****/
    //#]
}

VarEx Gear::get_acceleration() const {
    return _acceleration;
}

void Gear::set_acceleration(VarEx  p__acceleration) {
    _acceleration = p__acceleration;
}

VarEx Gear::get_speed() const {
    return _speed;
}

void Gear::set_speed(VarEx  p__speed) {
    _speed = p__speed;
}

VarEx Gear::get_torque() const {
    return _torque;
}

void Gear::set_torque(VarEx  p__torque) {
    _torque = p__torque;
}

double Gear::getAcceleration() const {
    return acceleration;
}

void Gear::setAcceleration(double  p_acceleration) {
    acceleration = p_acceleration;
}

double Gear::getInertia() const {
    return inertia;
}

void Gear::setInertia(double  p_inertia) {
    inertia = p_inertia;
}

long Gear::getNTeeth() const {
    return nTeeth;
}

void Gear::setNTeeth(long  p_nTeeth) {
    nTeeth = p_nTeeth;
}

double Gear::getRadius() const {
    return radius;
}

void Gear::setRadius(double  p_radius) {
    radius = p_radius;
}

double Gear::getSpeed() const {
    return speed;
}

void Gear::setSpeed(double  p_speed) {
    speed = p_speed;
}

double Gear::getTorque() const {
    return torque;
}

void Gear::setTorque(double  p_torque) {
    torque = p_torque;
}



#ifdef _OMINSTRUMENT


void OMAnimatedGear::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

IMPLEMENT_META(Gear, TransmissionModels, FALSE, OMAnimatedGear)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Gear.cpp
*********************************************************************/

