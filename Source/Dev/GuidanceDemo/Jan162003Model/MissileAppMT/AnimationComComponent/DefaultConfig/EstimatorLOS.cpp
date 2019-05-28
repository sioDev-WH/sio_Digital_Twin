/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: EstimatorLOS
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\EstimatorLOS.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "EstimatorLOS.h"
#include <stdafx.h>

//## package SeekerSubsystemPkg 


//#[ ignore 
#define SeekerSubsystemPkg_EstimatorLOS_EstimatorLOS_SERIALIZE \
    aomsmethod->addAttribute("damping", x2String(damping)); \
    aomsmethod->addAttribute("bandwidth", x2String(bandwidth));


#define OM_SeekerSubsystemPkg_EstimatorLOS_EstimatorLOS_1_SERIALIZE OM_NO_OP


#define SeekerSubsystemPkg_EstimatorLOS_clean_SERIALIZE OM_NO_OP


#define SeekerSubsystemPkg_EstimatorLOS_get_LOSRate_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define SeekerSubsystemPkg_EstimatorLOS_handle_tick_SERIALIZE aomsmethod->addAttribute("t", x2String(t));


#define SeekerSubsystemPkg_EstimatorLOS_init_SERIALIZE OM_NO_OP


#define SeekerSubsystemPkg_EstimatorLOS_set_LOS_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define SeekerSubsystemPkg_EstimatorLOS_set_dishError_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define SeekerSubsystemPkg_EstimatorLOS_set_guidanceMode_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define SeekerSubsystemPkg_EstimatorLOS_set_stabilizedRate_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define SeekerSubsystemPkg_EstimatorLOS_update_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// EstimatorLOS.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(SeekerSubsystemPkg)
//## class EstimatorLOS 



EstimatorLOS::EstimatorLOS(double  damping, double  bandwidth, OMThread*  p_thread) {
    NOTIFY_REACTIVE_CONSTRUCTOR(EstimatorLOS, EstimatorLOS(double,double), 2, SeekerSubsystemPkg_EstimatorLOS_EstimatorLOS_SERIALIZE);
    setThread(p_thread, FALSE);
    //#[ operation EstimatorLOS(double,double) 
    Coeff.design(damping,bandwidth);
    //#]
}

EstimatorLOS::EstimatorLOS(OMThread*  p_thread) {
    NOTIFY_REACTIVE_CONSTRUCTOR(EstimatorLOS, EstimatorLOS(), 0, OM_SeekerSubsystemPkg_EstimatorLOS_EstimatorLOS_1_SERIALIZE);
    setThread(p_thread, FALSE);
    //#[ operation EstimatorLOS() 
    init();
    //#]
}

EstimatorLOS::~EstimatorLOS() {
    NOTIFY_DESTRUCTOR(~EstimatorLOS, TRUE);
}

void EstimatorLOS::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, SeekerSubsystemPkg_EstimatorLOS_clean_SERIALIZE);
    //#[ operation clean() 
    //#]
}

void EstimatorLOS::get_LOSRate(const double  t, double *val) {
    NOTIFY_OPERATION(get_LOSRate, get_LOSRate(const double,double *), 2, SeekerSubsystemPkg_EstimatorLOS_get_LOSRate_SERIALIZE);
    //#[ operation get_LOSRate(const double,double *) 
    
    *val = LOSRate; 
    //#]
}

void EstimatorLOS::handle_tick(const double  t) {
    NOTIFY_OPERATION(handle_tick, handle_tick(const double), 1, SeekerSubsystemPkg_EstimatorLOS_handle_tick_SERIALIZE);
    //#[ operation handle_tick(const double) 
    
    receive();
    if(guidanceMode>1)  // radar guided
    			update();
    broadcast(t);
    
    //#]
}

void EstimatorLOS::init() {
    NOTIFY_OPERATION(init, init(), 0, SeekerSubsystemPkg_EstimatorLOS_init_SERIALIZE);
    //#[ operation init() 
    epsilon = 0.0; // 25 Hz
    LOSRate = 0.0;
    LOS = 0.0;
    //#]
}

void EstimatorLOS::set_LOS(const double  t, double *val) {
    NOTIFY_OPERATION(set_LOS, set_LOS(const double,double *), 2, SeekerSubsystemPkg_EstimatorLOS_set_LOS_SERIALIZE);
    //#[ operation set_LOS(const double,double *) 
    
    LOS  = *val; 
    //#]
}

void EstimatorLOS::set_dishError(const double  t, double *val) {
    NOTIFY_OPERATION(set_dishError, set_dishError(const double,double *), 2, SeekerSubsystemPkg_EstimatorLOS_set_dishError_SERIALIZE);
    //#[ operation set_dishError(const double,double *) 
    
    dishError   = *val; // *d2r if *val in degree for display
    //#]
}

void EstimatorLOS::set_guidanceMode(const double  t, long *val) {
    NOTIFY_OPERATION(set_guidanceMode, set_guidanceMode(const double,long *), 2, SeekerSubsystemPkg_EstimatorLOS_set_guidanceMode_SERIALIZE);
    //#[ operation set_guidanceMode(const double,long *) 
    
    guidanceMode  = *val; // *d2r if *val in degree for display
    //#]
}

void EstimatorLOS::set_stabilizedRate(const double  t, double *val) {
    NOTIFY_OPERATION(set_stabilizedRate, set_stabilizedRate(const double,double *), 2, SeekerSubsystemPkg_EstimatorLOS_set_stabilizedRate_SERIALIZE);
    //#[ operation set_stabilizedRate(const double,double *) 
    
    stabilizedRate  = *val; // *d2r if *val in degree for display
    //#]
}

void EstimatorLOS::update() {
    NOTIFY_OPERATION(update, update(), 0, SeekerSubsystemPkg_EstimatorLOS_update_SERIALIZE);
    //#[ operation update() 
        double Ts = Coeff.period/1000.0;
    
       /*
    	double eBar = epsilon + (Ts - Coeff.tau)*(LOSRate-stabilizedRate);	// Detection time Eqn  (16) B. Ekstrand, IEEE TAE July 2001
    	// epsilon = epsilon + Ts*LOSRate - Ts*qs + (Coeff.L1 + Coeff.tau*Coeff.L2)*(dishError-eBar);// Eqn. (14)
        // LOSRate   = LOSRate   + Coeff.L2*(e-eBar); // Eqn. (15)
        epsilon = epsilon + Ts*LOSRate - Ts*stabilizedRate + (Coeff.L1 + Coeff.tau*Coeff.L2)*(dishError-eBar);// Eqn. (14)
        LOSRate   = LOSRate   + Coeff.L2*(dishError-eBar); // Eqn. (15)
        // EstimatedError    = epsilon; 
    	// EstimatedLOSRate  = LOSRate;
    
       */
        // This is a test patch to check behavior of Estimator
        // double old_LOS;
        
    
    	LOSRate = (LOS-LOS_old)/Ts;   
    	LOS_old = LOS;
    
    //#]
}

double EstimatorLOS::getLOS() const {
    return LOS;
}

void EstimatorLOS::setLOS(double  p_LOS) {
    LOS = p_LOS;
}

double EstimatorLOS::getLOSRate() const {
    return LOSRate;
}

void EstimatorLOS::setLOSRate(double  p_LOSRate) {
    LOSRate = p_LOSRate;
}

double EstimatorLOS::getLOS_old() const {
    return LOS_old;
}

void EstimatorLOS::setLOS_old(double  p_LOS_old) {
    LOS_old = p_LOS_old;
}

double EstimatorLOS::getDishError() const {
    return dishError;
}

void EstimatorLOS::setDishError(double  p_dishError) {
    dishError = p_dishError;
}

double EstimatorLOS::getEpsilon() const {
    return epsilon;
}

void EstimatorLOS::setEpsilon(double  p_epsilon) {
    epsilon = p_epsilon;
}

int EstimatorLOS::getGuidanceMode() const {
    return guidanceMode;
}

void EstimatorLOS::setGuidanceMode(int  p_guidanceMode) {
    guidanceMode = p_guidanceMode;
}

double EstimatorLOS::getStabilizedRate() const {
    return stabilizedRate;
}

void EstimatorLOS::setStabilizedRate(double  p_stabilizedRate) {
    stabilizedRate = p_stabilizedRate;
}

EstimatorLOSCoeff* EstimatorLOS::getCoeff() const {
    return (EstimatorLOSCoeff*) &Coeff;
}

OMBoolean EstimatorLOS::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



#ifdef _OMINSTRUMENT


void OMAnimatedEstimatorLOS::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("epsilon", x2String(myReal->epsilon));
    aomsAttributes->addAttribute("LOSRate", x2String(myReal->LOSRate));
    aomsAttributes->addAttribute("stabilizedRate", x2String(myReal->stabilizedRate));
    aomsAttributes->addAttribute("dishError", x2String(myReal->dishError));
    aomsAttributes->addAttribute("guidanceMode", x2String(myReal->guidanceMode));
    aomsAttributes->addAttribute("LOS", x2String(myReal->LOS));
    aomsAttributes->addAttribute("LOS_old", x2String(myReal->LOS_old));
}

void OMAnimatedEstimatorLOS::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("Coeff", TRUE, TRUE);
    if((EstimatorLOSCoeff*) &myReal->Coeff)
        aomsRelations->ADD_ITEM((EstimatorLOSCoeff*) &myReal->Coeff);
}

IMPLEMENT_REACTIVE_META(EstimatorLOS, SeekerSubsystemPkg, FALSE, OMAnimatedEstimatorLOS)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\EstimatorLOS.cpp
*********************************************************************/

