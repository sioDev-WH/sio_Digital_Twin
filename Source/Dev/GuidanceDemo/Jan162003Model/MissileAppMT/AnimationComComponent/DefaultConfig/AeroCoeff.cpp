/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: AeroCoeff
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\AeroCoeff.cpp
*********************************************************************/

#include "AeroCoeff.h"
#include "math.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// AeroCoeff.cpp                                                                  
//----------------------------------------------------------------------------
//## class AeroCoeff 



AeroCoeff::AeroCoeff() {
    //#[ operation AeroCoeff() 
    init();
    //#]
}

AeroCoeff::~AeroCoeff() {
}

HRESULT AeroCoeff::FinalConstruct() {
    //#[ operation FinalConstruct() 
    return S_OK;
    //#]
}

 AeroCoeff::FinalRelease() {
    //#[ operation FinalRelease() 
    //#]
}

HRESULT AeroCoeff::InitLocalIPars(const _TCHAR * prefix, pplong * pars, ppchar * Names, long * nPars, long * dPars) {
    //#[ operation InitLocalIPars(const _TCHAR * ,pplong * ,ppchar * ,long * ,long * ) 
    return S_OK;
    //#]
}

HRESULT AeroCoeff::InitLocalRPars(const _TCHAR * prefix, ppdouble * pars, ppchar * Names, long * nPars, long * dPars) {
    //#[ operation InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ) 
    
     ADD_LOCAL_SRPAR(S_ref)
    ADD_LOCAL_SRPAR(d_ref)
    ADD_LOCAL_SRPAR(an)
    ADD_LOCAL_SRPAR(bn)
    ADD_LOCAL_SRPAR(cn)
    ADD_LOCAL_SRPAR(Cx_el)
    ADD_LOCAL_SRPAR(Cz_el)
     ADD_LOCAL_SRPAR(am)
     ADD_LOCAL_SRPAR(bm)
    ADD_LOCAL_SRPAR(cm)
    ADD_LOCAL_SRPAR(Cm_el)
    ADD_LOCAL_SRPAR(Cm_q)
     return S_OK;
    //#]
}

HRESULT AeroCoeff::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    
     ADD_LOCAL_SVAR(alpha)
     ADD_LOCAL_SVAR(V)
     ADD_LOCAL_SVAR(Mach)
     ADD_LOCAL_SVAR(Cx_alpha)
    ADD_LOCAL_SVAR(Cz_alpha)
    ADD_LOCAL_SVAR(Cm_alpha)
    
     return S_OK; 
    //#]
}

void AeroCoeff::init() {
    //#[ operation init() 
    an =  0.000103/pow(d2r,3);
    bn = -0.009450/pow(d2r,2);
    cn = -0.169600/d2r;
    am =  0.000215/pow(d2r,3);
    bm = -0.019500/pow(d2r,2);
    cm =  0.051000/d2r;
    
    // WAH S_ref = 0.44;
    S_ref = 0.44/m2ft/m2ft;
    // WAH d_ref = 0.75;
    d_ref = 0.75/m2ft;
    
    Cx_el = 0.00000;
    Cz_el = -0.0340/d2r;
    Cm_el = -0.2060/d2r;
    
    Cm_q = -1.7190;
    
    Cx_alpha = -0.3;
    Cz_alpha = 0.0;
    Cm_alpha = 0.0;
    
    alpha = 0.0;
    V = 0.0;
    Mach = 0.0;
    
    DER(alpha) = 0.0;
    DER(V) = 0.0;
    DER(Mach) = 0.0;
    
    DER(Cx_alpha) = 0.0;
    DER(Cz_alpha) = 0.0;
    DER(Cm_alpha) = 0.0;
    
    //#]
}

void AeroCoeff::setCm_alpha(double  p_Cm_alpha) {
    Cm_alpha = p_Cm_alpha;
}

void AeroCoeff::setCm_el(double  p_Cm_el) {
    Cm_el = p_Cm_el;
}

void AeroCoeff::setCm_q(double  p_Cm_q) {
    Cm_q = p_Cm_q;
}

void AeroCoeff::setCx_alpha(double  p_Cx_alpha) {
    Cx_alpha = p_Cx_alpha;
}

void AeroCoeff::setCx_el(double  p_Cx_el) {
    Cx_el = p_Cx_el;
}

void AeroCoeff::setCz_alpha(double  p_Cz_alpha) {
    Cz_alpha = p_Cz_alpha;
}

void AeroCoeff::setCz_el(double  p_Cz_el) {
    Cz_el = p_Cz_el;
}

void AeroCoeff::setMach(double  p_Mach) {
    Mach = p_Mach;
}

void AeroCoeff::setS_ref(double  p_S_ref) {
    S_ref = p_S_ref;
}

void AeroCoeff::setV(double  p_V) {
    V = p_V;
}

void AeroCoeff::set_Cm_alpha(VarEx p__Cm_alpha) {
    _Cm_alpha = p__Cm_alpha;
}

void AeroCoeff::set_Cx_alpha(VarEx p__Cx_alpha) {
    _Cx_alpha = p__Cx_alpha;
}

void AeroCoeff::set_Cz_alpha(VarEx p__Cz_alpha) {
    _Cz_alpha = p__Cz_alpha;
}

void AeroCoeff::set_Mach(VarEx p__Mach) {
    _Mach = p__Mach;
}

void AeroCoeff::set_V(VarEx p__V) {
    _V = p__V;
}

void AeroCoeff::set_alpha(VarEx p__alpha) {
    _alpha = p__alpha;
}

void AeroCoeff::setAlpha(double  p_alpha) {
    alpha = p_alpha;
}

void AeroCoeff::setAm(double  p_am) {
    am = p_am;
}

void AeroCoeff::setAn(double  p_an) {
    an = p_an;
}

void AeroCoeff::setBm(double  p_bm) {
    bm = p_bm;
}

void AeroCoeff::setBn(double  p_bn) {
    bn = p_bn;
}

void AeroCoeff::setCm(double  p_cm) {
    cm = p_cm;
}

void AeroCoeff::setCn(double  p_cn) {
    cn = p_cn;
}

void AeroCoeff::setD_ref(double  p_d_ref) {
    d_ref = p_d_ref;
}



/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\AeroCoeff.cpp
*********************************************************************/

