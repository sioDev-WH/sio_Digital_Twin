/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: AeroDynamics
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\AeroDynamics.cpp
*********************************************************************/
#include <stdlib.h>
#include "AeroDynamics.h"
#include "AeroCoeff.h"
#include "Atmosphere.h"
#include "BodyDynamics.h"
#include "math.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// AeroDynamics.cpp                                                                  
//----------------------------------------------------------------------------
//## class AeroDynamics 

AeroDynamics::AeroDynamics() {
    pAtmosphere = NULL;
    pBody = NULL;
    pCoeff = NULL;
    FinPosition = 0;
    //#[ operation AeroDynamics() 
    init();
    //#]
}

AeroDynamics::~AeroDynamics() {
    //#[ operation ~AeroDynamics() 
    clean();
}

void AeroDynamics::clean() {
    //#[ operation clean() 
    if (pAtmosphere)
    {
      delete pAtmosphere;
      pAtmosphere = NULL;
    }
    if (pCoeff)
    {
      delete pCoeff;
      pAtmosphere = NULL;
    }

    //#]
}

void AeroDynamics::init() {
    //#[ operation init() 
    double initialHeight = 10000/m2ft;
    
    pAtmosphere = new Atmosphere();
    // Assumption: atmosphere data is only calculated on initialization
    pAtmosphere->updateData(initialHeight); 
    pCoeff = new AeroCoeff();
    pBody = new BodyDynamics();
    
    // WAH initializing u to mach 3 - REPLACED by STATE MACHINE Reset equations
    // pBody->u = 3.0 * 328;
    // pBody->w = 0.0;
    
    Thrust = 10000.0;
    
    // state machine implementation
    //initStateMachine();
    //#]
}

void AeroDynamics::r_Cm_alpha(double * res) {
    //#[ operation r_Cm_alpha(double * ) 
    *res = 	-pCoeff->Cm_alpha + pCoeff->alpha*
    					(  - pCoeff->cm*(7.0-8.0*pCoeff->Mach/3.0) 
    					   + pCoeff->bm*fabs(pCoeff->alpha)
    					   + pCoeff->am*pCoeff->alpha*pCoeff->alpha);
    
    //#]
}

void AeroDynamics::r_Cx_alpha(double * res) {
    //#[ operation r_Cx_alpha(double * ) 
    *res = -pCoeff->Cx_alpha - 0.3;
    
    //#]
}

void AeroDynamics::r_Cz_alpha(double * res) {
    //#[ operation r_Cz_alpha(double * ) 
    *res = -pCoeff->Cz_alpha + pCoeff->alpha*
    					(	 pCoeff->cn*(2.0-pCoeff->Mach/3.0) 
    					   + pCoeff->bn*fabs(pCoeff->alpha)
    					   + pCoeff->an*pCoeff->alpha*pCoeff->alpha);
    
    //#]
}

void AeroDynamics::r_Fx(double * res) {
    //#[ operation r_Fx(double * ) 
    double dynamicPressure;
    double& Fx = pBody->Fx;
    
    dynamicPressure = 0.5 * pCoeff->V * pCoeff->V * pAtmosphere->airDensity;
    *res = -Fx + pCoeff->S_ref*dynamicPressure*(pCoeff->Cx_alpha+pCoeff->Cx_el * FinPosition )+ Thrust ;
    
    
    //#]
}

void AeroDynamics::r_Fz(double * res) {
    //#[ operation r_Fz(double * ) 
    double dynamicPressure;
    double& Fz = pBody->Fz;
    
    dynamicPressure = 0.5 * pCoeff->V * pCoeff->V * pAtmosphere->airDensity;
    *res = -Fz + pCoeff->S_ref*dynamicPressure*(pCoeff->Cz_alpha+pCoeff->Cz_el * FinPosition);
    
    
    //#]
}

void AeroDynamics::r_Mach(double * res) {
    //#[ operation r_Mach(double * ) 
    *res = -pCoeff->Mach + pCoeff->V/pAtmosphere->speedOfSound;
    
    //#]
}

void AeroDynamics::r_My(double * res) {
    //#[ operation r_My(double * ) 
    double dynamicPressure;
    double& My = pBody->My;
    double& q = pBody->q;
    
    dynamicPressure = 0.5 * pCoeff->V * pCoeff->V * pAtmosphere->airDensity;
    *res = -My + pCoeff->d_ref*pCoeff->S_ref*dynamicPressure *
         (pCoeff->Cm_alpha+pCoeff->Cm_el * FinPosition + pCoeff->Cm_q*q);
    
    
    //#]
}

void AeroDynamics::r_V(double * res) {
    //#[ operation r_V(double * ) 
    double& u = pBody->u;
    double& w = pBody->w;
    
    *res = -pCoeff->V + sqrt(u*u+w*w);
    
    //#]
}

void AeroDynamics::r_alpha(double * res) {
    //#[ operation r_alpha(double * ) 
    double& u = pBody->u;
    double& w = pBody->w;
    
    // TODO: put this back
    //*res = -pCoeff->alpha + atan2(w, u);
    
    // WAH See note below on atan2(y,x)
    if (u == 0.0) u = 1.0e-15;
    *res = -pCoeff->alpha + atan(w/u);
    
    //KB *res = -pCoeff->alpha; 
    
    //#]
}



/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\AeroDynamics.cpp
*********************************************************************/

