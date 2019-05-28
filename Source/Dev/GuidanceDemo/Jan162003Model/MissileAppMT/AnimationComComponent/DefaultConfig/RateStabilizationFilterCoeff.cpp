/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: RateStabilizationFilterCoeff
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\RateStabilizationFilterCoeff.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "RateStabilizationFilterCoeff.h"
#include "ControlDesigner.h"
#include <stdafx.h>

//## package SeekerSubsystemPkg 


//#[ ignore 
#define SeekerSubsystemPkg_RateStabilizationFilterCoeff_RateStabilizationFilterCoeff_SERIALIZE OM_NO_OP


#define SeekerSubsystemPkg_RateStabilizationFilterCoeff_clean_SERIALIZE OM_NO_OP


#define SeekerSubsystemPkg_RateStabilizationFilterCoeff_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// RateStabilizationFilterCoeff.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(SeekerSubsystemPkg)
//## class RateStabilizationFilterCoeff 



RateStabilizationFilterCoeff::RateStabilizationFilterCoeff() {
    NOTIFY_CONSTRUCTOR(RateStabilizationFilterCoeff, RateStabilizationFilterCoeff(), 0, SeekerSubsystemPkg_RateStabilizationFilterCoeff_RateStabilizationFilterCoeff_SERIALIZE);
    pDesigner = NULL;
    //#[ operation RateStabilizationFilterCoeff() 
    init();
    //#]
}

RateStabilizationFilterCoeff::~RateStabilizationFilterCoeff() {
    NOTIFY_DESTRUCTOR(~RateStabilizationFilterCoeff, TRUE);
    cleanUpRelations();
}

void RateStabilizationFilterCoeff::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, SeekerSubsystemPkg_RateStabilizationFilterCoeff_clean_SERIALIZE);
    //#[ operation clean() 
    //#]
}

void RateStabilizationFilterCoeff::init() {
    NOTIFY_OPERATION(init, init(), 0, SeekerSubsystemPkg_RateStabilizationFilterCoeff_init_SERIALIZE);
    //#[ operation init() 
    
    int i;
    nx = 2;
    nu = 1;
    ny = 1;
    
    period = 10.0;
    
    double Ts  =    period/1000.0;
    gyroBandwidth		=   100.0*2*PI;		//  Wgyro
    gyroDamping		  =   0.7;		      //  zeta
    double Ac[] = 
    			{
    			  0,              1,
    			  -3.9478E+5,     -879.65
    			};
    
    double Bc[] =
    			{
    			  0, 3.9478E+5
    			};
    
    double Cc[] =
    			{
    
    			  1.0, 0.0
    			};
    
    double Dc[] =
    			{
    			  0
    			};
    A = new double[nx*nx];
    B = new double[nx*nu];
    C = new double[ny*nx];
    D = new double[ny*nu];
    
    ControlDesigner* pDesigner = new ControlDesigner;
    pDesigner->SS_discretize(Ts, nx,nu,Ac,Bc,A,B);
    delete pDesigner;
    for(i=0;i<ny*nx;i++)C[i] = Cc[i];
    for(i=0;i<ny*nu;i++)D[i] = Dc[i];
    //#]
}

double *  RateStabilizationFilterCoeff::getA() const {
    return A;
}

void RateStabilizationFilterCoeff::setA(double * p_A) {
    A = p_A;
}

double *  RateStabilizationFilterCoeff::getB() const {
    return B;
}

void RateStabilizationFilterCoeff::setB(double * p_B) {
    B = p_B;
}

double *  RateStabilizationFilterCoeff::getC() const {
    return C;
}

void RateStabilizationFilterCoeff::setC(double * p_C) {
    C = p_C;
}

double *  RateStabilizationFilterCoeff::getD() const {
    return D;
}

void RateStabilizationFilterCoeff::setD(double * p_D) {
    D = p_D;
}

double RateStabilizationFilterCoeff::getGyroBandwidth() const {
    return gyroBandwidth;
}

void RateStabilizationFilterCoeff::setGyroBandwidth(double  p_gyroBandwidth) {
    gyroBandwidth = p_gyroBandwidth;
}

double RateStabilizationFilterCoeff::getGyroDamping() const {
    return gyroDamping;
}

void RateStabilizationFilterCoeff::setGyroDamping(double  p_gyroDamping) {
    gyroDamping = p_gyroDamping;
}

int RateStabilizationFilterCoeff::getNu() const {
    return nu;
}

void RateStabilizationFilterCoeff::setNu(int  p_nu) {
    nu = p_nu;
}

int RateStabilizationFilterCoeff::getNx() const {
    return nx;
}

void RateStabilizationFilterCoeff::setNx(int  p_nx) {
    nx = p_nx;
}

int RateStabilizationFilterCoeff::getNy() const {
    return ny;
}

void RateStabilizationFilterCoeff::setNy(int  p_ny) {
    ny = p_ny;
}

double RateStabilizationFilterCoeff::getPeriod() const {
    return period;
}

void RateStabilizationFilterCoeff::setPeriod(double  p_period) {
    period = p_period;
}

ControlDesigner* RateStabilizationFilterCoeff::getPDesigner() const {
    return pDesigner;
}

void RateStabilizationFilterCoeff::setPDesigner(ControlDesigner*  p_ControlDesigner) {
    pDesigner = p_ControlDesigner;
}

void RateStabilizationFilterCoeff::cleanUpRelations() {
    if(pDesigner != NULL)
        {
            pDesigner = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedRateStabilizationFilterCoeff::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("period", x2String(myReal->period));
    aomsAttributes->addAttribute("gyroBandwidth", x2String(myReal->gyroBandwidth));
    aomsAttributes->addAttribute("gyroDamping", x2String(myReal->gyroDamping));
    aomsAttributes->addAttribute("nx", x2String(myReal->nx));
    aomsAttributes->addAttribute("nu", x2String(myReal->nu));
    aomsAttributes->addAttribute("ny", x2String(myReal->ny));
    aomsAttributes->addAttribute("A", x2String(myReal->A));
    aomsAttributes->addAttribute("B", x2String(myReal->B));
    aomsAttributes->addAttribute("C", x2String(myReal->C));
    aomsAttributes->addAttribute("D", x2String(myReal->D));
}

void OMAnimatedRateStabilizationFilterCoeff::serializeRelations(AOMSRelations*  aomsRelations) const {
}

IMPLEMENT_META(RateStabilizationFilterCoeff, SeekerSubsystemPkg, FALSE, OMAnimatedRateStabilizationFilterCoeff)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\RateStabilizationFilterCoeff.cpp
*********************************************************************/

