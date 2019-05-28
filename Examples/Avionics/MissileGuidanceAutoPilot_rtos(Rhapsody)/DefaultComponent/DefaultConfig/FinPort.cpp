/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: FinPort
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\FinPort.cpp
*********************************************************************/

#include "FinPort.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// FinPort.cpp                                                                  
//----------------------------------------------------------------------------
//## class FinPort 



FinPort::FinPort() {
}

FinPort::~FinPort() {
}

HRESULT FinPort::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    ADD_LOCAL_STLVAR(angle)
    
    for (long i = 0; i < m_nEsos; i++) 
      AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
    return S_OK;
    //#]
}

bool FinPort::Load(FILE * fs) {
    //#[ operation Load(FILE * ) 
    return true;
    //#]
}

void FinPort::Save(FILE * fs) {
    //#[ operation Save(FILE * ) 
    //#]
}

void FinPort::enumVars(OnStlVec<double> * * & vec, long & size) {
    //#[ operation enumVars(OnStlVec<double> * * & ,long & ) 
    size = 1;
    vec = new OnStlVec<double>*[size];
    vec[0] = &angle;
    //#]
}

Angle FinPort::getAngle() const {
    return angle;
}

void FinPort::setAngle(Angle  p_angle) {
    angle = p_angle;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\FinPort.cpp
*********************************************************************/

