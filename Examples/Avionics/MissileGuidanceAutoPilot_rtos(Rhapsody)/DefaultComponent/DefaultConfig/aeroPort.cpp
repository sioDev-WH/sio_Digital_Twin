/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: aeroPort
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\aeroPort.cpp
*********************************************************************/

#include "aeroPort.h"
#include "stdafx.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// aeroPort.cpp                                                                  
//----------------------------------------------------------------------------
//## class aeroPort 



aeroPort::aeroPort() {
}

aeroPort::~aeroPort() {
}

HRESULT aeroPort::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    ADD_LOCAL_STLVAR(force)
    ADD_LOCAL_STLVAR(moment)
    ADD_LOCAL_STLVAR(velocity)
    ADD_LOCAL_STLVAR(rate)
    ADD_LOCAL_STLVAR(position)
    ADD_LOCAL_STLVAR(angle)
    
    for (long i = 0; i < m_nEsos; i++) 
      AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
    return S_OK;
    //#]
}

bool aeroPort::Load(FILE * fs) {
    //#[ operation Load(FILE * ) 
    return true;
    //#]
}

void aeroPort::Save(FILE * fs) {
    //#[ operation Save(FILE * ) 
    //#]
}

void aeroPort::enumVars(OnStlVec<double> * * & vec, long & size) {
    //#[ operation enumVars(OnStlVec<double> * * & ,long & ) 
    size = 6;
    vec = new OnStlVec<double>*[size];
    vec[0] = &force;
    vec[1] = &moment;
    vec[2] = &velocity;
    vec[3] = &rate;
    vec[4] = &position;
    vec[5] = &angle;  
    
    //#]
}

Angle aeroPort::getAngle() const {
    return angle;
}

void aeroPort::setAngle(Angle  p_angle) {
    angle = p_angle;
}

Force aeroPort::getForce() const {
    return force;
}

void aeroPort::setForce(Force  p_force) {
    force = p_force;
}

Moment aeroPort::getMoment() const {
    return moment;
}

void aeroPort::setMoment(Moment  p_moment) {
    moment = p_moment;
}

Pos aeroPort::getPosition() const {
    return position;
}

void aeroPort::setPosition(Pos  p_position) {
    position = p_position;
}

RotVel aeroPort::getRate() const {
    return rate;
}

void aeroPort::setRate(RotVel  p_rate) {
    rate = p_rate;
}

Vel aeroPort::getVelocity() const {
    return velocity;
}

void aeroPort::setVelocity(Vel  p_velocity) {
    velocity = p_velocity;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\aeroPort.cpp
*********************************************************************/

