/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: RateStabilizationFilter
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\RateStabilizationFilter.cpp
*********************************************************************/

#include <oxf/omthread.h>
#include "RateStabilizationFilter.h"

//## package TrackingSubsystemPkg 

//----------------------------------------------------------------------------
// RateStabilizationFilter.cpp                                                                  
//----------------------------------------------------------------------------
//## class RateStabilizationFilter 



RateStabilizationFilter::RateStabilizationFilter(OMThread*  p_thread) {
    setThread(p_thread, FALSE);
    //#[ operation RateStabilizationFilter() 
    init();
    //#]
}

RateStabilizationFilter::~RateStabilizationFilter() {
}

void RateStabilizationFilter::clean() {
    //#[ operation clean() 
    if(x) delete x;
    if(u) delete u;
    //#]
}

void RateStabilizationFilter::init() {
    //#[ operation init() 
    long i;
    int nx = Coeff.nx;
    int nu = Coeff.nu; 
    
    stabilizedRate=0.0;
    x = new double[nx]; 
    u = new double[nu];
    for(i=0;i<nx;i++) x[i] = 0.0; 
    for(i=0;i<nu;i++) u[i] = 0.0;
    
    //#]
}

void RateStabilizationFilter::setPeriod(long  val) {
    //#[ operation setPeriod(long) 
    Coeff.setPeriod(val);
    Coeff.initData();
    //#]
}

void RateStabilizationFilter::updateStabilizedRate(double  gimbalAngleRateData, double  gyroData) {
    //#[ operation updateStabilizedRate(double,double) 
        double y,old_x[2];
        int nx = Coeff.nx;
        int nu = Coeff.nu;
        
        int i,j;
    
    
        u[0] = gyroData + gimbalAngleRateData;
        
    	old_x[0] = x[0];
    	old_x[1] = x[1];
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
        stabilizedRate = y; // stabilized rate qs
    //#]
}

long RateStabilizationFilter::getPeriod() const {
    return period;
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



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\RateStabilizationFilter.cpp
*********************************************************************/

