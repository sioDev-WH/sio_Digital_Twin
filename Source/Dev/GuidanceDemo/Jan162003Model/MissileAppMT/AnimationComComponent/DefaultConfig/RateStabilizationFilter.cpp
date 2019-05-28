/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: RateStabilizationFilter
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\RateStabilizationFilter.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "RateStabilizationFilter.h"
#include <stdafx.h>

//## package SeekerSubsystemPkg 


//#[ ignore 
#define SeekerSubsystemPkg_RateStabilizationFilter_RateStabilizationFilter_SERIALIZE OM_NO_OP


#define SeekerSubsystemPkg_RateStabilizationFilter_clean_SERIALIZE OM_NO_OP


#define SeekerSubsystemPkg_RateStabilizationFilter_init_SERIALIZE OM_NO_OP


#define SeekerSubsystemPkg_RateStabilizationFilter_updateStabilizedRate_SERIALIZE \
    aomsmethod->addAttribute("gimbalAngleRateData", x2String(gimbalAngleRateData)); \
    aomsmethod->addAttribute("gyroData", x2String(gyroData));
//#]

//----------------------------------------------------------------------------
// RateStabilizationFilter.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(SeekerSubsystemPkg)
//## class RateStabilizationFilter 



RateStabilizationFilter::RateStabilizationFilter(OMThread*  p_thread) {
    NOTIFY_REACTIVE_CONSTRUCTOR(RateStabilizationFilter, RateStabilizationFilter(), 0, SeekerSubsystemPkg_RateStabilizationFilter_RateStabilizationFilter_SERIALIZE);
    setThread(p_thread, FALSE);
    //#[ operation RateStabilizationFilter() 
    init();
    //#]
}

RateStabilizationFilter::~RateStabilizationFilter() {
    NOTIFY_DESTRUCTOR(~RateStabilizationFilter, TRUE);
}

void RateStabilizationFilter::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, SeekerSubsystemPkg_RateStabilizationFilter_clean_SERIALIZE);
    //#[ operation clean() 
    //#]
}

void RateStabilizationFilter::init() {
    NOTIFY_OPERATION(init, init(), 0, SeekerSubsystemPkg_RateStabilizationFilter_init_SERIALIZE);
    //#[ operation init() 
    long i;
    int nx = Coeff.nx;
    int nu = Coeff.nu; 
    
    x = new double[nx]; // Destroy
    u = new double[nu];
    old_x = new double[nx];
    old_u = new double[nu];
      for (i = 0; i < nx; i++) old_x[i] = 0.0;
      for (i = 0; i < nu; i++) old_u[i] = 0.0;
    //#]
}

void RateStabilizationFilter::updateStabilizedRate(double  gimbalAngleRateData, double  gyroData) {
    NOTIFY_OPERATION(updateStabilizedRate, updateStabilizedRate(double,double), 2, SeekerSubsystemPkg_RateStabilizationFilter_updateStabilizedRate_SERIALIZE);
    //#[ operation updateStabilizedRate(double,double) 
    double y;
    int nx = Coeff.nx;
    int nu = Coeff.nu;
    
    int i,j; 
    
    // WAH
    // if(!ap_fs){ ap_fs = new ofstream; ap_fs->open("AutoPilotData.txt");}
    
    // Sensor processing
    // WAH [use fractions of H(s) since Numerator and Denumerator are of same order
    
    u[0] = gyroData + gimbalAngleRateData;
    
    
    
    // Filter Wgyro^2/(s^2 + 2*zeta*Wgyro*s + wgyro^2)
    
    for(i=0;i<nx;i++){
      x[i] = 0.0;
      for(j=0;j<nx;j++)
    	  x[i] += Coeff.A[i*nx+j]*old_x[j];
      for(j=0;j<nu;j++)
    	  x[i] += Coeff.B[i*nu+j]*u[j];
    }
    y = 0.0;
    for(i=0;i<nx;i++) y += Coeff.C[i]*x[i];
    for(j=0;j<nu;j++) y += Coeff.D[j]*u[j];
      
    
    // WAH update buffers
    old_u[0] = u[0];
    for(i=0;i<nx;i++) old_x[i] = x[i];
    
    // WAH
    // *rsf_fs << "\t"<< qs << "\t" <<  gyroData << "\t" <<  accelData << "\n";
    
    stabilizedRate = y; // stabilized rate qs
    //#]
}

double *  RateStabilizationFilter::getOld_u() const {
    return old_u;
}

void RateStabilizationFilter::setOld_u(double * p_old_u) {
    old_u = p_old_u;
}

double *  RateStabilizationFilter::getOld_x() const {
    return old_x;
}

void RateStabilizationFilter::setOld_x(double * p_old_x) {
    old_x = p_old_x;
}

double RateStabilizationFilter::getPeriod() const {
    return period;
}

void RateStabilizationFilter::setPeriod(double  p_period) {
    period = p_period;
}

double RateStabilizationFilter::getStabilizedRate() const {
    return stabilizedRate;
}

void RateStabilizationFilter::setStabilizedRate(double  p_stabilizedRate) {
    stabilizedRate = p_stabilizedRate;
}

double *  RateStabilizationFilter::getU() const {
    return u;
}

void RateStabilizationFilter::setU(double * p_u) {
    u = p_u;
}

double *  RateStabilizationFilter::getX() const {
    return x;
}

void RateStabilizationFilter::setX(double * p_x) {
    x = p_x;
}

RateStabilizationFilterCoeff* RateStabilizationFilter::getCoeff() const {
    return (RateStabilizationFilterCoeff*) &Coeff;
}

OMBoolean RateStabilizationFilter::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



#ifdef _OMINSTRUMENT


void OMAnimatedRateStabilizationFilter::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("x", x2String(myReal->x));
    aomsAttributes->addAttribute("old_x", x2String(myReal->old_x));
    aomsAttributes->addAttribute("u", x2String(myReal->u));
    aomsAttributes->addAttribute("old_u", x2String(myReal->old_u));
    aomsAttributes->addAttribute("stabilizedRate", x2String(myReal->stabilizedRate));
    aomsAttributes->addAttribute("period", x2String(myReal->period));
}

void OMAnimatedRateStabilizationFilter::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("Coeff", TRUE, TRUE);
    if((RateStabilizationFilterCoeff*) &myReal->Coeff)
        aomsRelations->ADD_ITEM((RateStabilizationFilterCoeff*) &myReal->Coeff);
}

IMPLEMENT_REACTIVE_META(RateStabilizationFilter, SeekerSubsystemPkg, FALSE, OMAnimatedRateStabilizationFilter)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\RateStabilizationFilter.cpp
*********************************************************************/

