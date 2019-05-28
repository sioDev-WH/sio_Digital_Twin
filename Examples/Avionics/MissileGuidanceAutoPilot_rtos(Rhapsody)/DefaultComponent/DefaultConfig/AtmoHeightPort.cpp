/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: AtmoHeightPort
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\AtmoHeightPort.cpp
*********************************************************************/

#include "AtmoHeightPort.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// AtmoHeightPort.cpp                                                                  
//----------------------------------------------------------------------------
//## class AtmoHeightPort 



AtmoHeightPort::AtmoHeightPort() {
}

AtmoHeightPort::~AtmoHeightPort() {
}

HRESULT AtmoHeightPort::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    ADD_LOCAL_STLVAR(height)
    
    for (long i = 0; i < m_nEsos; i++) 
      AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
    return S_OK;
    //#]
}

bool AtmoHeightPort::Load(FILE * fs) {
    //#[ operation Load(FILE * ) 
    return true;
    //#]
}

void AtmoHeightPort::Save(FILE * fs) {
    //#[ operation Save(FILE * ) 
    //#]
}

void AtmoHeightPort::enumVars(OnStlVec<double> * * & vec, long & size) {
    //#[ operation enumVars(OnStlVec<double> * * & ,long & ) 
    size = 1;
    vec = new OnStlVec<double>*[size];
    vec[0] = &height;
    //#]
}

aeroLength<double>  AtmoHeightPort::getHeight() const {
    return height;
}

void AtmoHeightPort::setHeight(aeroLength<double> p_height) {
    height = p_height;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\AtmoHeightPort.cpp
*********************************************************************/

