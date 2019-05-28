/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: GustPort
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\GustPort.cpp
*********************************************************************/

#include "GustPort.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// GustPort.cpp                                                                  
//----------------------------------------------------------------------------
//## class GustPort 



GustPort::GustPort() {
}

GustPort::~GustPort() {
}

HRESULT GustPort::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    ADD_LOCAL_STLVAR(velocity)
    ADD_LOCAL_STLVAR(rate)
    
    for (long i = 0; i < m_nEsos; i++) 
      AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
    return S_OK;
    //#]
}

bool GustPort::Load(FILE * fs) {
    //#[ operation Load(FILE * ) 
    return true;
    //#]
}

void GustPort::Save(FILE * fs) {
    //#[ operation Save(FILE * ) 
    //#]
}

void GustPort::enumVars(OnStlVec<double> * * & vec, long & size) {
    //#[ operation enumVars(OnStlVec<double> * * & ,long & ) 
    size = 2;
    vec = new OnStlVec<double>*[size];
    vec[0] = &velocity;
    vec[1] = &rate;
    //#]
}

RotVel GustPort::getRate() const {
    return rate;
}

void GustPort::setRate(RotVel  p_rate) {
    rate = p_rate;
}

Vel GustPort::getVelocity() const {
    return velocity;
}

void GustPort::setVelocity(Vel  p_velocity) {
    velocity = p_velocity;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\GustPort.cpp
*********************************************************************/

