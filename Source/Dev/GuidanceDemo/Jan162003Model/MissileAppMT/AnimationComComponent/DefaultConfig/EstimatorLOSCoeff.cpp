/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: EstimatorLOSCoeff
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\EstimatorLOSCoeff.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "EstimatorLOSCoeff.h"
#include "math.h"

//## package SeekerSubsystemPkg 


//#[ ignore 
#define SeekerSubsystemPkg_EstimatorLOSCoeff_EstimatorLOSCoeff_SERIALIZE OM_NO_OP


#define SeekerSubsystemPkg_EstimatorLOSCoeff_clean_SERIALIZE OM_NO_OP


#define SeekerSubsystemPkg_EstimatorLOSCoeff_design_SERIALIZE \
    aomsmethod->addAttribute("damping", x2String(damping)); \
    aomsmethod->addAttribute("bandwidth", x2String(bandwidth));


#define SeekerSubsystemPkg_EstimatorLOSCoeff_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// EstimatorLOSCoeff.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(SeekerSubsystemPkg)
//## class EstimatorLOSCoeff 



EstimatorLOSCoeff::EstimatorLOSCoeff() {
    NOTIFY_CONSTRUCTOR(EstimatorLOSCoeff, EstimatorLOSCoeff(), 0, SeekerSubsystemPkg_EstimatorLOSCoeff_EstimatorLOSCoeff_SERIALIZE);
    //#[ operation EstimatorLOSCoeff() 
    init();
    //#]
}

EstimatorLOSCoeff::~EstimatorLOSCoeff() {
    NOTIFY_DESTRUCTOR(~EstimatorLOSCoeff, TRUE);
}

void EstimatorLOSCoeff::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, SeekerSubsystemPkg_EstimatorLOSCoeff_clean_SERIALIZE);
    //#[ operation clean() 
    //#]
}

void EstimatorLOSCoeff::design(double  damping, double  bandwidth) {
    NOTIFY_OPERATION(design, design(double,double), 2, SeekerSubsystemPkg_EstimatorLOSCoeff_design_SERIALIZE);
    //#[ operation design(double,double) 
    
    double Ts;
    double product;
    double sum;
    double Wn = bandwidth;
    
    Ts = period/1000.0;
    product = exp(-2.0*damping*Wn*Ts);  // product of exp(pole_1*Ts)*exp(pole_2*Ts)
    if(damping<1)
       sum     = 2.0*exp(-damping*Wn*Ts)* cos(sqrt(1-damping*damping)*Wn*Ts);
    else
       sum     = 2.0*exp(-damping*Wn*Ts);
    L1 = 1 - product;
    L2 = (1.0 + product - sum)/Ts;
    //#]
}

void EstimatorLOSCoeff::init() {
    NOTIFY_OPERATION(init, init(), 0, SeekerSubsystemPkg_EstimatorLOSCoeff_init_SERIALIZE);
    //#[ operation init() 
    period = 40.0; // 40 mSec or 25 Hz 
    double Ts = period/1000.0;
    // tau = Ts/2.0; // delay due to image processing
    tau = 0.0;
    design(0.7,7);
    //#]
}

double EstimatorLOSCoeff::getL1() const {
    return L1;
}

void EstimatorLOSCoeff::setL1(double  p_L1) {
    L1 = p_L1;
}

double EstimatorLOSCoeff::getL2() const {
    return L2;
}

void EstimatorLOSCoeff::setL2(double  p_L2) {
    L2 = p_L2;
}

double EstimatorLOSCoeff::getPeriod() const {
    return period;
}

void EstimatorLOSCoeff::setPeriod(double  p_period) {
    period = p_period;
}

double EstimatorLOSCoeff::getTau() const {
    return tau;
}

void EstimatorLOSCoeff::setTau(double  p_tau) {
    tau = p_tau;
}



#ifdef _OMINSTRUMENT


void OMAnimatedEstimatorLOSCoeff::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("period", x2String(myReal->period));
    aomsAttributes->addAttribute("tau", x2String(myReal->tau));
    aomsAttributes->addAttribute("L1", x2String(myReal->L1));
    aomsAttributes->addAttribute("L2", x2String(myReal->L2));
}

IMPLEMENT_META(EstimatorLOSCoeff, SeekerSubsystemPkg, FALSE, OMAnimatedEstimatorLOSCoeff)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\EstimatorLOSCoeff.cpp
*********************************************************************/

