/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: BodyDynamicsCoeff
//!	Generated Date	: Tue, 10, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\BodyDynamicsCoeff.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "stdafx.h"
#include "BodyDynamicsCoeff.h"

//## package GuidancePkg 

//----------------------------------------------------------------------------
// BodyDynamicsCoeff.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(GuidancePkg)
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

void BodyDynamicsCoeff::setIxx(double  p_Ixx) {
    Ixx = p_Ixx;
}

void BodyDynamicsCoeff::setIyy(double  p_Iyy) {
    Iyy = p_Iyy;
}

void BodyDynamicsCoeff::setIzz(double  p_Izz) {
    Izz = p_Izz;
}

void BodyDynamicsCoeff::setMass(double  p_Mass) {
    Mass = p_Mass;
}

void BodyDynamicsCoeff::setAccPos(double  p_accPos) {
    accPos = p_accPos;
}



#ifdef _OMINSTRUMENT


void OMAnimatedBodyDynamicsCoeff::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedBodyDynamicsCoeff::serializeRelations(AOMSRelations*  aomsRelations) const {
}

IMPLEMENT_META(BodyDynamicsCoeff, GuidancePkg, FALSE, OMAnimatedBodyDynamicsCoeff)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\BodyDynamicsCoeff.cpp
*********************************************************************/

