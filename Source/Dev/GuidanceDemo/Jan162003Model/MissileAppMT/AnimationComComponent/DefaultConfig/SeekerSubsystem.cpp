/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: SeekerSubsystem
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\SeekerSubsystem.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "SeekerSubsystem.h"
#include "GuidanceLogic.h"
#include "math.h"

//## package SeekerSubsystemPkg 


//#[ ignore 
#define SeekerSubsystemPkg_SeekerSubsystem_SeekerSubsystem_SERIALIZE OM_NO_OP


#define SeekerSubsystemPkg_SeekerSubsystem_checkAcquisition_SERIALIZE OM_NO_OP


#define SeekerSubsystemPkg_SeekerSubsystem_clean_SERIALIZE OM_NO_OP


#define SeekerSubsystemPkg_SeekerSubsystem_computeSeparationData_SERIALIZE OM_NO_OP


#define SeekerSubsystemPkg_SeekerSubsystem_estimateLOSRate_SERIALIZE OM_NO_OP


#define SeekerSubsystemPkg_SeekerSubsystem_get_LOS_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define SeekerSubsystemPkg_SeekerSubsystem_get_closingVelocity_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define SeekerSubsystemPkg_SeekerSubsystem_get_dishError_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define SeekerSubsystemPkg_SeekerSubsystem_get_gimbalAngle_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define SeekerSubsystemPkg_SeekerSubsystem_get_range_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define SeekerSubsystemPkg_SeekerSubsystem_get_stabilizedRate_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define SeekerSubsystemPkg_SeekerSubsystem_handle_tick_SERIALIZE aomsmethod->addAttribute("t", x2String(t));


#define SeekerSubsystemPkg_SeekerSubsystem_init_SERIALIZE OM_NO_OP


#define SeekerSubsystemPkg_SeekerSubsystem_set_dishCommand_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define SeekerSubsystemPkg_SeekerSubsystem_set_guidanceMode_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define SeekerSubsystemPkg_SeekerSubsystem_set_missile_Attitude_Data_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define SeekerSubsystemPkg_SeekerSubsystem_set_missile_Gyro_Data_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define SeekerSubsystemPkg_SeekerSubsystem_set_missile_X_Data_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define SeekerSubsystemPkg_SeekerSubsystem_set_missile_Z_Data_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define SeekerSubsystemPkg_SeekerSubsystem_set_target_X_Data_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define SeekerSubsystemPkg_SeekerSubsystem_set_target_Z_Data_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));
//#]

//----------------------------------------------------------------------------
// SeekerSubsystem.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(SeekerSubsystemPkg)
//## class SeekerSubsystem 



SeekerSubsystem::SeekerSubsystem(OMThread*  p_thread) {
    NOTIFY_REACTIVE_CONSTRUCTOR(SeekerSubsystem, SeekerSubsystem(), 0, SeekerSubsystemPkg_SeekerSubsystem_SeekerSubsystem_SERIALIZE);
    setThread(p_thread, FALSE);
    {
        {
            itsGimbalController.setShouldDelete(FALSE);
        }
        itsGimbalController.setThread(p_thread, FALSE);
        {
            itsRateStabilizationFilter.setShouldDelete(FALSE);
        }
        itsRateStabilizationFilter.setThread(p_thread, FALSE);
    }
    itsGuidanceLogic = NULL;
    //#[ operation SeekerSubsystem() 
    init();
    //#]
}

SeekerSubsystem::~SeekerSubsystem() {
    NOTIFY_DESTRUCTOR(~SeekerSubsystem, TRUE);
    cleanUpRelations();
}

void SeekerSubsystem::checkAcquisition() {
    NOTIFY_OPERATION(checkAcquisition, checkAcquisition(), 0, SeekerSubsystemPkg_SeekerSubsystem_checkAcquisition_SERIALIZE);
    //#[ operation checkAcquisition() 
    if(fabs(lookAngle - gimbalAngle/**d2r*/)< Coeff.radarBeamWidth/2) bTargetAcquired = true; else bTargetAcquired=false;
    //#]
}

void SeekerSubsystem::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, SeekerSubsystemPkg_SeekerSubsystem_clean_SERIALIZE);
    //#[ operation clean() 
    //delete get_evTargetAquired;
    //delete get_evTargetLost;
    //#]
}

void SeekerSubsystem::computeSeparationData() {
    NOTIFY_OPERATION(computeSeparationData, computeSeparationData(), 0, SeekerSubsystemPkg_SeekerSubsystem_computeSeparationData_SERIALIZE);
    //#[ operation computeSeparationData() 
    
    
        double delta_x,delta_z;
        double target_Speed_Estimate,missile_Speed_Estimate;
        double Ts = Coeff.getPeriod()/1000.0;
        // double old_LOS;
    	// Data from Missile and target are updated 
    	delta_x = (target_X_Data - missile_X_Data); // x and z are w.r.t. global coordinates
    	delta_z = -(target_Z_Data - missile_Z_Data);
    	range = sqrt(delta_x*delta_x+delta_z*delta_z);
        
       //  old_LOS = LOS;
    	LOS = atan(delta_z/delta_x); 
    	lookAngle = LOS - missile_Attitude_Data;  
    	// LOSRate_Data = (LOS-old_LOS)/Ts;
    	
    	delta_x = (target_X_Data-target_X);
    	delta_z = (target_Z_Data-target_Z);
    	target_Speed_Estimate = sqrt(delta_x*delta_x+delta_z*delta_z)/Ts;
    	
    	delta_x = (missile_X_Data-missile_X);
    	delta_z = (missile_Z_Data-missile_Z);
    	missile_Speed_Estimate = sqrt(delta_x*delta_x+delta_z*delta_z)/Ts;
    	
    	// opposite directions 
    	closingVelocity = missile_Speed_Estimate + target_Speed_Estimate;
    	
    
    //#]
}

void SeekerSubsystem::estimateLOSRate() {
    NOTIFY_OPERATION(estimateLOSRate, estimateLOSRate(), 0, SeekerSubsystemPkg_SeekerSubsystem_estimateLOSRate_SERIALIZE);
    //#[ operation estimateLOSRate() 
    //double qs = itsRateStabilizationFilter.stabilizedRate;
    //double estimatedPointingError;
    //itsEstimator.update(dishError,qs,estimatedPointingError,LOSRate);
    //#]
}

void SeekerSubsystem::get_LOS(const double  t, double *val) {
    NOTIFY_OPERATION(get_LOS, get_LOS(const double,double *), 2, SeekerSubsystemPkg_SeekerSubsystem_get_LOS_SERIALIZE);
    //#[ operation get_LOS(const double,double *) 
    
    *val = LOS; 
    //#]
}

void SeekerSubsystem::get_closingVelocity(const double  t, double *val) {
    NOTIFY_OPERATION(get_closingVelocity, get_closingVelocity(const double,double *), 2, SeekerSubsystemPkg_SeekerSubsystem_get_closingVelocity_SERIALIZE);
    //#[ operation get_closingVelocity(const double,double *) 
    
    *val = closingVelocity; 
    //#]
}

void SeekerSubsystem::get_dishError(const double  t, double *val) {
    NOTIFY_OPERATION(get_dishError, get_dishError(const double,double *), 2, SeekerSubsystemPkg_SeekerSubsystem_get_dishError_SERIALIZE);
    //#[ operation get_dishError(const double,double *) 
    
    *val = dishError; 
    //#]
}

void SeekerSubsystem::get_gimbalAngle(const double  t, double *val) {
    NOTIFY_OPERATION(get_gimbalAngle, get_gimbalAngle(const double,double *), 2, SeekerSubsystemPkg_SeekerSubsystem_get_gimbalAngle_SERIALIZE);
    //#[ operation get_gimbalAngle(const double,double *) 
    
    *val = gimbalAngle; 
    //#]
}

void SeekerSubsystem::get_range(const double  t, double *val) {
    NOTIFY_OPERATION(get_range, get_range(const double,double *), 2, SeekerSubsystemPkg_SeekerSubsystem_get_range_SERIALIZE);
    //#[ operation get_range(const double,double *) 
    
    *val = range; 
    //#]
}

void SeekerSubsystem::get_stabilizedRate(const double  t, double *val) {
    NOTIFY_OPERATION(get_stabilizedRate, get_stabilizedRate(const double,double *), 2, SeekerSubsystemPkg_SeekerSubsystem_get_stabilizedRate_SERIALIZE);
    //#[ operation get_stabilizedRate(const double,double *) 
    
    *val = itsRateStabilizationFilter.stabilizedRate; 
    //#]
}

void SeekerSubsystem::handle_tick(const double  t) {
    NOTIFY_OPERATION(handle_tick, handle_tick(const double), 1, SeekerSubsystemPkg_SeekerSubsystem_handle_tick_SERIALIZE);
    //#[ operation handle_tick(const double) 
    #define ON_GEN(x) 
    // double LOSRateEstimate; 
    // double LOSErr; 
    double radarCounter = int(1/(Coeff.getRadarFrameRate()*Coeff.getPeriod()/1000));
    // update local data from theApp global vars
    
    receive();
    
    computeSeparationData();
    
    checkAcquisition();
    itsRateStabilizationFilter.updateStabilizedRate(itsGimbalController.gimbalAngleRate,missile_Gyro_Data);
    double qs = itsRateStabilizationFilter.stabilizedRate;
    dishError = itsGimbalController.computeDishError(lookAngle,dishCommand,guidanceMode);
    itsGimbalController.adjustGimbalAngle(dishError,qs);
    gimbalAngle = itsGimbalController.gimbalAngle; // /d2r;
    if(bTargetAcquired && guidanceMode==1) // End target-search mode
           itsGuidanceLogic->GEN(evTargetAcquired);     
           // ON_GEN(evTargetAcquired);
    if(!bTargetAcquired && guidanceMode==3) // Return to target-search from radar-guided
           itsGuidanceLogic->GEN(evTargetLost);
           //ON_GEN(evTargetLost);
    
    	// update locals 
    missile_X = missile_X_Data;
    missile_Z = missile_Z_Data;
    target_X = target_X_Data; 
    target_Z = target_Z_Data;
    
    // broadcast local data
    broadcast(t);             
    
    
      
    
    //#]
}

void SeekerSubsystem::init() {
    NOTIFY_OPERATION(init, init(), 0, SeekerSubsystemPkg_SeekerSubsystem_init_SERIALIZE);
    //#[ operation init() 
    range = 0.0;
    gimbalAngle = 0.0;
    LOS = 0.0; 
    LOSRate_Data = 0.0;
    lookAngle = 0.0;
    closingVelocity = 0.0;
    bTargetAcquired = 0; // False 
    
    dishCommand = 0.0; // from Guidance
    missile_Gyro_Data = 0.0;
    missile_Attitude_Data = 0.0;
    missile_X =  0.0;
    missile_Z =  0.0;
    target_X =  0.0;
    target_Z =  0.0;
        
    //get_evTargetAquired = new COnEventBroadcaster<evTargetAquired>();
    //get_evTargetLost = new COnEventBroadcaster<evTargetLost>();    
    //#]
}

void SeekerSubsystem::set_dishCommand(const double  t, double *val) {
    NOTIFY_OPERATION(set_dishCommand, set_dishCommand(const double,double *), 2, SeekerSubsystemPkg_SeekerSubsystem_set_dishCommand_SERIALIZE);
    //#[ operation set_dishCommand(const double,double *) 
    
    dishCommand = *val; // *d2r if *val in degree for display
    //#]
}

void SeekerSubsystem::set_guidanceMode(const double  t, long *val) {
    NOTIFY_OPERATION(set_guidanceMode, set_guidanceMode(const double,long *), 2, SeekerSubsystemPkg_SeekerSubsystem_set_guidanceMode_SERIALIZE);
    //#[ operation set_guidanceMode(const double,long *) 
    
    guidanceMode  = *val; // *d2r if *val in degree for display
    //#]
}

void SeekerSubsystem::set_missile_Attitude_Data(const double  t, double *val) {
    NOTIFY_OPERATION(set_missile_Attitude_Data, set_missile_Attitude_Data(const double,double *), 2, SeekerSubsystemPkg_SeekerSubsystem_set_missile_Attitude_Data_SERIALIZE);
    //#[ operation set_missile_Attitude_Data(const double,double *) 
    
    missile_Attitude_Data  = *val; // *d2r if *val in degree for display
    //#]
}

void SeekerSubsystem::set_missile_Gyro_Data(const double  t, double *val) {
    NOTIFY_OPERATION(set_missile_Gyro_Data, set_missile_Gyro_Data(const double,double *), 2, SeekerSubsystemPkg_SeekerSubsystem_set_missile_Gyro_Data_SERIALIZE);
    //#[ operation set_missile_Gyro_Data(const double,double *) 
    
    missile_Gyro_Data  = *val; // *d2r if *val in degree for display
    //#]
}

void SeekerSubsystem::set_missile_X_Data(const double  t, double *val) {
    NOTIFY_OPERATION(set_missile_X_Data, set_missile_X_Data(const double,double *), 2, SeekerSubsystemPkg_SeekerSubsystem_set_missile_X_Data_SERIALIZE);
    //#[ operation set_missile_X_Data(const double,double *) 
    
    missile_X_Data   = *val; // *d2r if *val in degree for display
    //#]
}

void SeekerSubsystem::set_missile_Z_Data(const double  t, double *val) {
    NOTIFY_OPERATION(set_missile_Z_Data, set_missile_Z_Data(const double,double *), 2, SeekerSubsystemPkg_SeekerSubsystem_set_missile_Z_Data_SERIALIZE);
    //#[ operation set_missile_Z_Data(const double,double *) 
    
    missile_Z_Data    = *val; // *d2r if *val in degree for display
    //#]
}

void SeekerSubsystem::set_target_X_Data(const double  t, double *val) {
    NOTIFY_OPERATION(set_target_X_Data, set_target_X_Data(const double,double *), 2, SeekerSubsystemPkg_SeekerSubsystem_set_target_X_Data_SERIALIZE);
    //#[ operation set_target_X_Data(const double,double *) 
    
    target_X_Data     = *val; // *d2r if *val in degree for display
    //#]
}

void SeekerSubsystem::set_target_Z_Data(const double  t, double *val) {
    NOTIFY_OPERATION(set_target_Z_Data, set_target_Z_Data(const double,double *), 2, SeekerSubsystemPkg_SeekerSubsystem_set_target_Z_Data_SERIALIZE);
    //#[ operation set_target_Z_Data(const double,double *) 
    
    target_Z_Data  = *val; // *d2r if *val in degree for display
    //#]
}

double SeekerSubsystem::getLOS() const {
    return LOS;
}

void SeekerSubsystem::setLOS(double  p_LOS) {
    LOS = p_LOS;
}

double SeekerSubsystem::getLOSRate_Data() const {
    return LOSRate_Data;
}

void SeekerSubsystem::setLOSRate_Data(double  p_LOSRate_Data) {
    LOSRate_Data = p_LOSRate_Data;
}

int SeekerSubsystem::getBTargetAcquired() const {
    return bTargetAcquired;
}

void SeekerSubsystem::setBTargetAcquired(int  p_bTargetAcquired) {
    bTargetAcquired = p_bTargetAcquired;
}

double SeekerSubsystem::getClosingVelocity() const {
    return closingVelocity;
}

void SeekerSubsystem::setClosingVelocity(double  p_closingVelocity) {
    closingVelocity = p_closingVelocity;
}

double SeekerSubsystem::getDishCommand() const {
    return dishCommand;
}

void SeekerSubsystem::setDishCommand(double  p_dishCommand) {
    dishCommand = p_dishCommand;
}

double SeekerSubsystem::getDishError() const {
    return dishError;
}

void SeekerSubsystem::setDishError(double  p_dishError) {
    dishError = p_dishError;
}

double SeekerSubsystem::getGimbalAngle() const {
    return gimbalAngle;
}

void SeekerSubsystem::setGimbalAngle(double  p_gimbalAngle) {
    gimbalAngle = p_gimbalAngle;
}

int SeekerSubsystem::getGuidanceMode() const {
    return guidanceMode;
}

void SeekerSubsystem::setGuidanceMode(int  p_guidanceMode) {
    guidanceMode = p_guidanceMode;
}

double SeekerSubsystem::getLookAngle() const {
    return lookAngle;
}

void SeekerSubsystem::setLookAngle(double  p_lookAngle) {
    lookAngle = p_lookAngle;
}

double SeekerSubsystem::getMissile_Attitude_Data() const {
    return missile_Attitude_Data;
}

void SeekerSubsystem::setMissile_Attitude_Data(double  p_missile_Attitude_Data) {
    missile_Attitude_Data = p_missile_Attitude_Data;
}

double SeekerSubsystem::getMissile_Gyro_Data() const {
    return missile_Gyro_Data;
}

void SeekerSubsystem::setMissile_Gyro_Data(double  p_missile_Gyro_Data) {
    missile_Gyro_Data = p_missile_Gyro_Data;
}

double SeekerSubsystem::getMissile_X() const {
    return missile_X;
}

void SeekerSubsystem::setMissile_X(double  p_missile_X) {
    missile_X = p_missile_X;
}

double SeekerSubsystem::getMissile_X_Data() const {
    return missile_X_Data;
}

void SeekerSubsystem::setMissile_X_Data(double  p_missile_X_Data) {
    missile_X_Data = p_missile_X_Data;
}

double SeekerSubsystem::getMissile_Z() const {
    return missile_Z;
}

void SeekerSubsystem::setMissile_Z(double  p_missile_Z) {
    missile_Z = p_missile_Z;
}

double SeekerSubsystem::getMissile_Z_Data() const {
    return missile_Z_Data;
}

void SeekerSubsystem::setMissile_Z_Data(double  p_missile_Z_Data) {
    missile_Z_Data = p_missile_Z_Data;
}

double SeekerSubsystem::getRange() const {
    return range;
}

void SeekerSubsystem::setRange(double  p_range) {
    range = p_range;
}

double SeekerSubsystem::getTarget_X() const {
    return target_X;
}

void SeekerSubsystem::setTarget_X(double  p_target_X) {
    target_X = p_target_X;
}

double SeekerSubsystem::getTarget_X_Data() const {
    return target_X_Data;
}

void SeekerSubsystem::setTarget_X_Data(double  p_target_X_Data) {
    target_X_Data = p_target_X_Data;
}

double SeekerSubsystem::getTarget_Z() const {
    return target_Z;
}

void SeekerSubsystem::setTarget_Z(double  p_target_Z) {
    target_Z = p_target_Z;
}

double SeekerSubsystem::getTarget_Z_Data() const {
    return target_Z_Data;
}

void SeekerSubsystem::setTarget_Z_Data(double  p_target_Z_Data) {
    target_Z_Data = p_target_Z_Data;
}

SeekerSubsystemCoeff* SeekerSubsystem::getCoeff() const {
    return (SeekerSubsystemCoeff*) &Coeff;
}

GimbalController* SeekerSubsystem::getItsGimbalController() const {
    return (GimbalController*) &itsGimbalController;
}

GuidanceLogic* SeekerSubsystem::getItsGuidanceLogic() const {
    return itsGuidanceLogic;
}

void SeekerSubsystem::setItsGuidanceLogic(GuidanceLogic*  p_GuidanceLogic) {
    itsGuidanceLogic = p_GuidanceLogic;
    if(p_GuidanceLogic != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsGuidanceLogic", p_GuidanceLogic, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsGuidanceLogic");
        }
}

RateStabilizationFilter* SeekerSubsystem::getItsRateStabilizationFilter() const {
    return (RateStabilizationFilter*) &itsRateStabilizationFilter;
}

void SeekerSubsystem::cleanUpRelations() {
    if(itsGuidanceLogic != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsGuidanceLogic");
            itsGuidanceLogic = NULL;
        }
}

OMBoolean SeekerSubsystem::startBehavior() {
    OMBoolean done = FALSE;
    itsGimbalController.startBehavior();
    itsRateStabilizationFilter.startBehavior();
    done = OMReactive::startBehavior();
    return done;
}



#ifdef _OMINSTRUMENT


void OMAnimatedSeekerSubsystem::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("range", x2String(myReal->range));
    aomsAttributes->addAttribute("missile_X", x2String(myReal->missile_X));
    aomsAttributes->addAttribute("missile_Z", x2String(myReal->missile_Z));
    aomsAttributes->addAttribute("gimbalAngle", x2String(myReal->gimbalAngle));
    aomsAttributes->addAttribute("dishError", x2String(myReal->dishError));
    aomsAttributes->addAttribute("LOS", x2String(myReal->LOS));
    aomsAttributes->addAttribute("lookAngle", x2String(myReal->lookAngle));
    aomsAttributes->addAttribute("LOSRate_Data", x2String(myReal->LOSRate_Data));
    aomsAttributes->addAttribute("closingVelocity", x2String(myReal->closingVelocity));
    aomsAttributes->addAttribute("bTargetAcquired", x2String(myReal->bTargetAcquired));
    aomsAttributes->addAttribute("missile_Gyro_Data", x2String(myReal->missile_Gyro_Data));
    aomsAttributes->addAttribute("target_X_Data", x2String(myReal->target_X_Data));
    aomsAttributes->addAttribute("target_Z_Data", x2String(myReal->target_Z_Data));
    aomsAttributes->addAttribute("missile_Attitude_Data", x2String(myReal->missile_Attitude_Data));
    aomsAttributes->addAttribute("missile_X_Data", x2String(myReal->missile_X_Data));
    aomsAttributes->addAttribute("missile_Z_Data", x2String(myReal->missile_Z_Data));
    aomsAttributes->addAttribute("dishCommand", x2String(myReal->dishCommand));
    aomsAttributes->addAttribute("target_X", x2String(myReal->target_X));
    aomsAttributes->addAttribute("target_Z", x2String(myReal->target_Z));
    aomsAttributes->addAttribute("guidanceMode", x2String(myReal->guidanceMode));
}

void OMAnimatedSeekerSubsystem::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("Coeff", TRUE, TRUE);
    if((SeekerSubsystemCoeff*) &myReal->Coeff)
        aomsRelations->ADD_ITEM((SeekerSubsystemCoeff*) &myReal->Coeff);
    aomsRelations->addRelation("itsGimbalController", TRUE, TRUE);
    if((GimbalController*) &myReal->itsGimbalController)
        aomsRelations->ADD_ITEM((GimbalController*) &myReal->itsGimbalController);
    aomsRelations->addRelation("itsRateStabilizationFilter", TRUE, TRUE);
    if((RateStabilizationFilter*) &myReal->itsRateStabilizationFilter)
        aomsRelations->ADD_ITEM((RateStabilizationFilter*) &myReal->itsRateStabilizationFilter);
    aomsRelations->addRelation("itsGuidanceLogic", FALSE, TRUE);
    if(myReal->itsGuidanceLogic)
        aomsRelations->ADD_ITEM(myReal->itsGuidanceLogic);
}

IMPLEMENT_REACTIVE_META(SeekerSubsystem, SeekerSubsystemPkg, FALSE, OMAnimatedSeekerSubsystem)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\SeekerSubsystem.cpp
*********************************************************************/

