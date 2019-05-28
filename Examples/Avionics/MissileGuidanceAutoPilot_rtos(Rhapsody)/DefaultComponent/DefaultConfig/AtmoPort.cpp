/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: AtmoPort
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\AtmoPort.cpp
*********************************************************************/

#include "AtmoPort.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// AtmoPort.cpp                                                                  
//----------------------------------------------------------------------------
//## class AtmoPort 



AtmoPort::AtmoPort() {
}

AtmoPort::~AtmoPort() {
}

HRESULT AtmoPort::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    ADD_LOCAL_STLVAR(airDensity)
    ADD_LOCAL_STLVAR(speedOfSound)
    
    for (long i = 0; i < m_nEsos; i++) 
      AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
    return S_OK;
    //#]
}

bool AtmoPort::Load(FILE * fs) {
    //#[ operation Load(FILE * ) 
    return true;
    //#]
}

void AtmoPort::Save(FILE * fs) {
    //#[ operation Save(FILE * ) 
    //#]
}

void AtmoPort::enumVars(OnStlVec<double> * * & vec, long & size) {
    //#[ operation enumVars(OnStlVec<double> * * & ,long & ) 
    size = 2;
    vec = new OnStlVec<double>*[size];
    vec[0] = &airDensity;
    vec[1] = &speedOfSound;
    //#]
}

aeroDensity<double>  AtmoPort::getAirDensity() const {
    return airDensity;
}

void AtmoPort::setAirDensity(aeroDensity<double> p_airDensity) {
    airDensity = p_airDensity;
}

aeroSpeedOfSound<double>  AtmoPort::getSpeedOfSound() const {
    return speedOfSound;
}

void AtmoPort::setSpeedOfSound(aeroSpeedOfSound<double> p_speedOfSound) {
    speedOfSound = p_speedOfSound;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\AtmoPort.cpp
*********************************************************************/

