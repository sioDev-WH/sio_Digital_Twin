/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: PlanetaryCoupler
//!	Generated Date	: Wed, 8, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\PlanetaryCoupler.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "PlanetaryCoupler.h"

//## package TransmissionModels 


//#[ ignore 
#define TransmissionModels_PlanetaryCoupler_PlanetaryCoupler_SERIALIZE OM_NO_OP


#define TransmissionModels_PlanetaryCoupler_InitLocalIPars_SERIALIZE OM_NO_OP


#define TransmissionModels_PlanetaryCoupler_InitLocalRPars_SERIALIZE OM_NO_OP


#define TransmissionModels_PlanetaryCoupler_InitLocalVars_SERIALIZE OM_NO_OP


#define TransmissionModels_PlanetaryCoupler_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// PlanetaryCoupler.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(TransmissionModels)
//## class PlanetaryCoupler 



PlanetaryCoupler::PlanetaryCoupler() {
    NOTIFY_CONSTRUCTOR(PlanetaryCoupler, PlanetaryCoupler(), 0, TransmissionModels_PlanetaryCoupler_PlanetaryCoupler_SERIALIZE);
    //#[ operation PlanetaryCoupler() 
    init();
    //#]
}

PlanetaryCoupler::~PlanetaryCoupler() {
    NOTIFY_DESTRUCTOR(~PlanetaryCoupler, TRUE);
    //#[ operation ~PlanetaryCoupler() 
    //#]
}

HRESULT PlanetaryCoupler::InitLocalIPars(const _TCHAR * prefix, pplong * pars, ppchar * Names, long * nPars, long * dPars) {
    NOTIFY_OPERATION(InitLocalIPars, InitLocalIPars(const _TCHAR * ,pplong * ,ppchar * ,long * ,long * ), 0, TransmissionModels_PlanetaryCoupler_InitLocalIPars_SERIALIZE);
    //#[ operation InitLocalIPars(const _TCHAR * ,pplong * ,ppchar * ,long * ,long * ) 
    return S_OK;
    //#]
}

HRESULT PlanetaryCoupler::InitLocalRPars(const _TCHAR * prefix, ppdouble * pars, ppchar * Names, long * nPars, long * dPars) {
    NOTIFY_OPERATION(InitLocalRPars, InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ), 0, TransmissionModels_PlanetaryCoupler_InitLocalRPars_SERIALIZE);
    //#[ operation InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ) 
    /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
    //{{SCG_OP_BODY
    
    
      ADD_LOCAL_SRPAR(inertia)
    
      return S_OK;
    
    //}}SCG_OP_BODY
    /***** End of automatically generated code *****/
    //#]
}

HRESULT PlanetaryCoupler::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    NOTIFY_OPERATION(InitLocalVars, InitLocalVars(const _TCHAR * ,VarCont * ,const bool ), 0, TransmissionModels_PlanetaryCoupler_InitLocalVars_SERIALIZE);
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
    //{{SCG_OP_BODY
    
    
      ADD_LOCAL_SVAR(torque)
      ADD_LOCAL_SVAR(speed)
      ADD_LOCAL_SVAR(acceleration)
    
      return S_OK;
    
    //}}SCG_OP_BODY
    /***** End of automatically generated code *****/
    //#]
}

void PlanetaryCoupler::init() {
    NOTIFY_OPERATION(init, init(), 0, TransmissionModels_PlanetaryCoupler_init_SERIALIZE);
    //#[ operation init() 
    /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
    //{{SCG_OP_BODY
    torque = 0.0;
    speed = 0.0;
    acceleration = 0.0;
    
    DER(torque) = 0.0;
    DER(speed) = 0.0;
    DER(acceleration) = 0.0;
    
    inertia = 0.2;
    
    //}}SCG_OP_BODY
    /***** End of automatically generated code *****/
    //#]
}

VarEx PlanetaryCoupler::get_acceleration() const {
    return _acceleration;
}

void PlanetaryCoupler::set_acceleration(VarEx  p__acceleration) {
    _acceleration = p__acceleration;
}

VarEx PlanetaryCoupler::get_speed() const {
    return _speed;
}

void PlanetaryCoupler::set_speed(VarEx  p__speed) {
    _speed = p__speed;
}

VarEx PlanetaryCoupler::get_torque() const {
    return _torque;
}

void PlanetaryCoupler::set_torque(VarEx  p__torque) {
    _torque = p__torque;
}

double PlanetaryCoupler::getAcceleration() const {
    return acceleration;
}

void PlanetaryCoupler::setAcceleration(double  p_acceleration) {
    acceleration = p_acceleration;
}

double PlanetaryCoupler::getInertia() const {
    return inertia;
}

void PlanetaryCoupler::setInertia(double  p_inertia) {
    inertia = p_inertia;
}

double PlanetaryCoupler::getSpeed() const {
    return speed;
}

void PlanetaryCoupler::setSpeed(double  p_speed) {
    speed = p_speed;
}

double PlanetaryCoupler::getTorque() const {
    return torque;
}

void PlanetaryCoupler::setTorque(double  p_torque) {
    torque = p_torque;
}



#ifdef _OMINSTRUMENT


void OMAnimatedPlanetaryCoupler::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

IMPLEMENT_META(PlanetaryCoupler, TransmissionModels, FALSE, OMAnimatedPlanetaryCoupler)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\PlanetaryCoupler.cpp
*********************************************************************/

