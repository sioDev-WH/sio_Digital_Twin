/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: BodyDynamicsCoeff
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\BodyDynamicsCoeff.cpp
*********************************************************************/

#include "BodyDynamicsCoeff.h"
#include "stdafx.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// BodyDynamicsCoeff.cpp                                                                  
//----------------------------------------------------------------------------
//## class BodyDynamicsCoeff 



BodyDynamicsCoeff::BodyDynamicsCoeff() {
    //#[ operation BodyDynamicsCoeff() 
    init();
    //#]
}

BodyDynamicsCoeff::~BodyDynamicsCoeff() {
}

HRESULT BodyDynamicsCoeff::InitLocalIPars(const _TCHAR * prefix, pplong * pars, ppchar * Names, long * nPars, long * dPars) {
    //#[ operation InitLocalIPars(const _TCHAR * ,pplong * ,ppchar * ,long * ,long * ) 
    return S_OK;
    //#]
}

HRESULT BodyDynamicsCoeff::InitLocalRPars(const _TCHAR * prefix, ppdouble * pars, ppchar * Names, long * nPars, long * dPars) {
    //#[ operation InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ) 
    
       ADD_LOCAL_SRPAR(Mass)
       ADD_LOCAL_SRPAR(Ixx)
       ADD_LOCAL_SRPAR(Iyy)
       ADD_LOCAL_SRPAR(Izz)
       ADD_LOCAL_SRPAR(accPos)
    
       return S_OK;
    //#]
}

HRESULT BodyDynamicsCoeff::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    
       return S_OK; 
    //#]
}

void BodyDynamicsCoeff::init() {
    //#[ operation init() 
    Ixx   = 1.0;    //  not being used in this example
    // WAH Iyy   = 182.5;
    Iyy   = 182.5/(Kg2slug*m2ft*m2ft);
    Izz   = 1.0;    //  not being used in this example
    // WAH Mass  = 13.98;
    Mass = 13.98/Kg2slug;
    accPos = 0.5;   // Distance in front of CG
    //#]
}

double BodyDynamicsCoeff::getIxx() const {
    return Ixx;
}

void BodyDynamicsCoeff::setIxx(double  p_Ixx) {
    Ixx = p_Ixx;
}

double BodyDynamicsCoeff::getIyy() const {
    return Iyy;
}

void BodyDynamicsCoeff::setIyy(double  p_Iyy) {
    Iyy = p_Iyy;
}

double BodyDynamicsCoeff::getIzz() const {
    return Izz;
}

void BodyDynamicsCoeff::setIzz(double  p_Izz) {
    Izz = p_Izz;
}

double BodyDynamicsCoeff::getMass() const {
    return Mass;
}

void BodyDynamicsCoeff::setMass(double  p_Mass) {
    Mass = p_Mass;
}

double BodyDynamicsCoeff::getAccPos() const {
    return accPos;
}

void BodyDynamicsCoeff::setAccPos(double  p_accPos) {
    accPos = p_accPos;
}



/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\BodyDynamicsCoeff.cpp
*********************************************************************/

