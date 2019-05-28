/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: FinActuatorCoeff
//!	Generated Date	: Tue, 10, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\FinActuatorCoeff.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "stdafx.h"
#include "FinActuatorCoeff.h"

//## package GuidancePkg 

//----------------------------------------------------------------------------
// FinActuatorCoeff.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(GuidancePkg)
//## class FinActuatorCoeff 



FinActuatorCoeff::FinActuatorCoeff() {
    //#[ operation FinActuatorCoeff() 
    init();
    //#]
}

FinActuatorCoeff::~FinActuatorCoeff() {
}

HRESULT FinActuatorCoeff::InitLocalIPars(const _TCHAR * prefix, pplong * pars, ppchar * Names, long * nPars, long * dPars) {
    //#[ operation InitLocalIPars(const _TCHAR * ,pplong * ,ppchar * ,long * ,long * ) 
    return S_OK;
    //#]
}

HRESULT FinActuatorCoeff::InitLocalRPars(const _TCHAR * prefix, ppdouble * pars, ppchar * Names, long * nPars, long * dPars) {
    //#[ operation InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ) 
    
       ADD_LOCAL_SRPAR(gain)
       ADD_LOCAL_SRPAR(damping)
       ADD_LOCAL_SRPAR(bandwidth)
       ADD_LOCAL_SRPAR(max_angle)
       ADD_LOCAL_SRPAR(min_angle)
       ADD_LOCAL_SRPAR(max_rate)
    
       return S_OK;
    //#]
}

HRESULT FinActuatorCoeff::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    
       return S_OK; 
    //#]
}

void FinActuatorCoeff::init() {
    //#[ operation init() 
    gain = 1.0;	
    damping = 0.7;
    bandwidth = 150.0;
    max_angle = 30.0 * d2r;	
    min_angle = -30.0 * d2r;
    max_rate = 500 * d2r;
    //#]
}

void FinActuatorCoeff::setBandwidth(double  p_bandwidth) {
    bandwidth = p_bandwidth;
}

void FinActuatorCoeff::setDamping(double  p_damping) {
    damping = p_damping;
}

void FinActuatorCoeff::setGain(double  p_gain) {
    gain = p_gain;
}

void FinActuatorCoeff::setMax_angle(double  p_max_angle) {
    max_angle = p_max_angle;
}

void FinActuatorCoeff::setMax_rate(double  p_max_rate) {
    max_rate = p_max_rate;
}

void FinActuatorCoeff::setMin_angle(double  p_min_angle) {
    min_angle = p_min_angle;
}



#ifdef _OMINSTRUMENT


void OMAnimatedFinActuatorCoeff::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedFinActuatorCoeff::serializeRelations(AOMSRelations*  aomsRelations) const {
}

IMPLEMENT_META(FinActuatorCoeff, GuidancePkg, FALSE, OMAnimatedFinActuatorCoeff)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\FinActuatorCoeff.cpp
*********************************************************************/

