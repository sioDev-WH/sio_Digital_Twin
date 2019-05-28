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



/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\AeroCoeff.cpp
*********************************************************************/

