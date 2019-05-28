/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: GimbalController
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\GimbalController.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "GimbalController.h"

//## package SeekerSubsystemPkg 


//#[ ignore 
#define SeekerSubsystemPkg_GimbalController_GimbalController_SERIALIZE OM_NO_OP


#define SeekerSubsystemPkg_GimbalController_adjustGimbalAngle_SERIALIZE \
    aomsmethod->addAttribute("dishError", x2String(dishError)); \
    aomsmethod->addAttribute("stabilizedRate", x2String(stabilizedRate));


#define SeekerSubsystemPkg_GimbalController_clean_SERIALIZE OM_NO_OP


#define SeekerSubsystemPkg_GimbalController_computeDishError_SERIALIZE \
    aomsmethod->addAttribute("lookAngle", x2String(lookAngle)); \
    aomsmethod->addAttribute("dishCommand", x2String(dishCommand)); \
    aomsmethod->addAttribute("guidanceMode", x2String(guidanceMode));


#define SeekerSubsystemPkg_GimbalController_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// GimbalController.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(SeekerSubsystemPkg)
//## class GimbalController 



GimbalController::GimbalController(OMThread*  p_thread) {
    NOTIFY_REACTIVE_CONSTRUCTOR(GimbalController, GimbalController(), 0, SeekerSubsystemPkg_GimbalController_GimbalController_SERIALIZE);
    setThread(p_thread, FALSE);
    //#[ operation GimbalController() 
    init();
    //#]
}

GimbalController::~GimbalController() {
    NOTIFY_DESTRUCTOR(~GimbalController, TRUE);
}

void GimbalController::adjustGimbalAngle(double  dishError, double  stabilizedRate) {
    NOTIFY_OPERATION(adjustGimbalAngle, adjustGimbalAngle(double,double), 2, SeekerSubsystemPkg_GimbalController_adjustGimbalAngle_SERIALIZE);
    //#[ operation adjustGimbalAngle(double,double) 
    double Ts = Coeff.period/1000.0 ; 
    double feedbackSignal;
    feedbackSignal = dishError/Coeff.TrackingTimeConstant - stabilizedRate;
    gimbalAngleRate = gimbalAngleRate + Ts * Coeff.rateLoopBandwidth * feedbackSignal;
    gimbalAngle = gimbalAngle + Ts*gimbalAngleRate;
    if(gimbalAngle > Coeff.GimbalAngle_max) gimbalAngle = Coeff.GimbalAngle_max;
    if(gimbalAngle < Coeff.GimbalAngle_min) gimbalAngle = Coeff.GimbalAngle_min;
    //#]
}

void GimbalController::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, SeekerSubsystemPkg_GimbalController_clean_SERIALIZE);
    //#[ operation clean() 
    //#]
}

double GimbalController::computeDishError(double  lookAngle, double  dishCommand, int  guidanceMode) {
    NOTIFY_OPERATION(computeDishError, computeDishError(double,double,int), 3, SeekerSubsystemPkg_GimbalController_computeDishError_SERIALIZE);
    //#[ operation computeDishError(double,double,int) 
    
      if(guidanceMode>1)
        dishError = lookAngle - gimbalAngle 
                   + Coeff.RadomeAberrtion*gimbalAngle  +  0.01* lookAngle * (0.5-rand()/RAND_MAX);
      else
        dishError = dishCommand*d2r - gimbalAngle; 
        
      return dishError;
    //#]
}

void GimbalController::init() {
    NOTIFY_OPERATION(init, init(), 0, SeekerSubsystemPkg_GimbalController_init_SERIALIZE);
    //#[ operation init() 
    gimbalAngle = 0.0;
    gimbalAngleRate = 0.0;
    //#]
}

double GimbalController::getDishError() const {
    return dishError;
}

void GimbalController::setDishError(double  p_dishError) {
    dishError = p_dishError;
}

double GimbalController::getGimbalAngle() const {
    return gimbalAngle;
}

void GimbalController::setGimbalAngle(double  p_gimbalAngle) {
    gimbalAngle = p_gimbalAngle;
}

double GimbalController::getGimbalAngleRate() const {
    return gimbalAngleRate;
}

void GimbalController::setGimbalAngleRate(double  p_gimbalAngleRate) {
    gimbalAngleRate = p_gimbalAngleRate;
}

GimbalControllerCoeff* GimbalController::getCoeff() const {
    return (GimbalControllerCoeff*) &Coeff;
}

OMBoolean GimbalController::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



#ifdef _OMINSTRUMENT


void OMAnimatedGimbalController::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("dishError", x2String(myReal->dishError));
    aomsAttributes->addAttribute("gimbalAngle", x2String(myReal->gimbalAngle));
    aomsAttributes->addAttribute("gimbalAngleRate", x2String(myReal->gimbalAngleRate));
}

void OMAnimatedGimbalController::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("Coeff", TRUE, TRUE);
    if((GimbalControllerCoeff*) &myReal->Coeff)
        aomsRelations->ADD_ITEM((GimbalControllerCoeff*) &myReal->Coeff);
}

IMPLEMENT_REACTIVE_META(GimbalController, SeekerSubsystemPkg, FALSE, OMAnimatedGimbalController)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\GimbalController.cpp
*********************************************************************/

