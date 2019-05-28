/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: TrackingSubsystem
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\TrackingSubsystem.cpp
*********************************************************************/

#include <oxf/omthread.h>
#include "TrackingSubsystem.h"
#include "GuidanceLogic.h"
#include "math.h"

//## package TrackingSubsystemPkg 

//----------------------------------------------------------------------------
// TrackingSubsystem.cpp                                                                  
//----------------------------------------------------------------------------
//## class TrackingSubsystem 



TrackingSubsystem::TrackingSubsystem(OMThread*  p_thread) {
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
    //#[ operation TrackingSubsystem() 
    init();
    //#]
}

TrackingSubsystem::~TrackingSubsystem() {
    cleanUpRelations();
}

void TrackingSubsystem::checkAcquisition() {
    //#[ operation checkAcquisition() 
    if(fabs(lookAngle - gimbalAngle/**d2r*/)< Coeff.radarBeamWidth/2) bTargetAcquired = true; else bTargetAcquired=false;
    //#]
}

void TrackingSubsystem::clean() {
    //#[ operation clean() 
    if (evToGuidance)
    {
      evToGuidance->Release();
      evToGuidance = NULL;
    }  
    
    //#]
}

void TrackingSubsystem::computeSeparationData() {
    //#[ operation computeSeparationData() 
    
    
        double delta_x,delta_z;
        double Ts = Coeff.getPeriod()/1000.0;
    
    	// Data from Missile and target are updated 
    	delta_x = (target_X_Data - missile_X_Data); // x and z are w.r.t. global coordinates
    	delta_z = -(target_Z_Data - missile_Z_Data);
    	range = sqrt(delta_x*delta_x+delta_z*delta_z);
        
    
    	LOS = atan(delta_z/delta_x); 
    	lookAngle = LOS - missile_Attitude_Data;  
    
    //#]
}

void TrackingSubsystem::getQS(double*  val) {
    //#[ operation getQS(double*) 
    *val = itsRateStabilizationFilter.stabilizedRate;
    //#]
}

void TrackingSubsystem::handle_tick() {
    //#[ operation handle_tick() 
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
    {
        evTargetAcquired* ev = new evTargetAcquired(); 
    	evToGuidance->gen(ev);	
           //itsGuidanceLogic->GEN(evTargetAcquired);     
           // ON_GEN(evTargetAcquired);
    }
    if(!bTargetAcquired && guidanceMode==3) // Return to target-search from radar-guided
    {      
        evTargetLost* ev = new evTargetLost(); 
    	evToGuidance->gen(ev);	
           //itsGuidanceLogic->GEN(evTargetLost);
           //ON_GEN(evTargetLost);
    }
    	// update locals 
    missile_X = missile_X_Data;
    missile_Z = missile_Z_Data;
    target_X = target_X_Data; 
    target_Z = target_Z_Data;
    
    // broadcast local data
    broadcast();             
    
    
      
    
    //#]
}

void TrackingSubsystem::init() {
    //#[ operation init() 
    range = 0.0;
    rangeRate=range;
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
    
    evToGuidance = new COnEventBroadcaster();
    evToGuidance->AddRef();
    //#]
}

void TrackingSubsystem::setPeriod(long  val) {
    //#[ operation setPeriod(long) 
     Coeff.setPeriod(val); 
     itsGimbalController.setPeriod(val);
     itsRateStabilizationFilter.setPeriod(val);
    //#]
}

double TrackingSubsystem::getLOS() const {
    return LOS;
}

void TrackingSubsystem::setLOS(double  p_LOS) {
    LOS = p_LOS;
}

double TrackingSubsystem::getLOSRate_Data() const {
    return LOSRate_Data;
}

void TrackingSubsystem::setLOSRate_Data(double  p_LOSRate_Data) {
    LOSRate_Data = p_LOSRate_Data;
}

int TrackingSubsystem::getBTargetAcquired() const {
    return bTargetAcquired;
}

void TrackingSubsystem::setBTargetAcquired(int  p_bTargetAcquired) {
    bTargetAcquired = p_bTargetAcquired;
}

double TrackingSubsystem::getClosingVelocity() const {
    return closingVelocity;
}

void TrackingSubsystem::setClosingVelocity(double  p_closingVelocity) {
    closingVelocity = p_closingVelocity;
}

double TrackingSubsystem::getDishCommand() const {
    return dishCommand;
}

void TrackingSubsystem::setDishCommand(double  p_dishCommand) {
    dishCommand = p_dishCommand;
}

double TrackingSubsystem::getDishError() const {
    return dishError;
}

void TrackingSubsystem::setDishError(double  p_dishError) {
    dishError = p_dishError;
}

COnEventBroadcaster* TrackingSubsystem::getEvToGuidance() const {
    return evToGuidance;
}

void TrackingSubsystem::setEvToGuidance(COnEventBroadcaster*  p_evToGuidance) {
    evToGuidance = p_evToGuidance;
}

double TrackingSubsystem::getGimbalAngle() const {
    return gimbalAngle;
}

void TrackingSubsystem::setGimbalAngle(double  p_gimbalAngle) {
    gimbalAngle = p_gimbalAngle;
}

int TrackingSubsystem::getGuidanceMode() const {
    return guidanceMode;
}

void TrackingSubsystem::setGuidanceMode(int  p_guidanceMode) {
    guidanceMode = p_guidanceMode;
}

double TrackingSubsystem::getLookAngle() const {
    return lookAngle;
}

void TrackingSubsystem::setLookAngle(double  p_lookAngle) {
    lookAngle = p_lookAngle;
}

double TrackingSubsystem::getMissile_Attitude_Data() const {
    return missile_Attitude_Data;
}

void TrackingSubsystem::setMissile_Attitude_Data(double  p_missile_Attitude_Data) {
    missile_Attitude_Data = p_missile_Attitude_Data;
}

double TrackingSubsystem::getMissile_Gyro_Data() const {
    return missile_Gyro_Data;
}

void TrackingSubsystem::setMissile_Gyro_Data(double  p_missile_Gyro_Data) {
    missile_Gyro_Data = p_missile_Gyro_Data;
}

double TrackingSubsystem::getMissile_X() const {
    return missile_X;
}

void TrackingSubsystem::setMissile_X(double  p_missile_X) {
    missile_X = p_missile_X;
}

double TrackingSubsystem::getMissile_X_Data() const {
    return missile_X_Data;
}

void TrackingSubsystem::setMissile_X_Data(double  p_missile_X_Data) {
    missile_X_Data = p_missile_X_Data;
}

double TrackingSubsystem::getMissile_Z() const {
    return missile_Z;
}

void TrackingSubsystem::setMissile_Z(double  p_missile_Z) {
    missile_Z = p_missile_Z;
}

double TrackingSubsystem::getMissile_Z_Data() const {
    return missile_Z_Data;
}

void TrackingSubsystem::setMissile_Z_Data(double  p_missile_Z_Data) {
    missile_Z_Data = p_missile_Z_Data;
}

double TrackingSubsystem::getRange() const {
    return range;
}

void TrackingSubsystem::setRange(double  p_range) {
    range = p_range;
}

double TrackingSubsystem::getRangeRate() const {
    return rangeRate;
}

void TrackingSubsystem::setRangeRate(double  p_rangeRate) {
    rangeRate = p_rangeRate;
}

double TrackingSubsystem::getTarget_X() const {
    return target_X;
}

void TrackingSubsystem::setTarget_X(double  p_target_X) {
    target_X = p_target_X;
}

double TrackingSubsystem::getTarget_X_Data() const {
    return target_X_Data;
}

void TrackingSubsystem::setTarget_X_Data(double  p_target_X_Data) {
    target_X_Data = p_target_X_Data;
}

double TrackingSubsystem::getTarget_Z() const {
    return target_Z;
}

void TrackingSubsystem::setTarget_Z(double  p_target_Z) {
    target_Z = p_target_Z;
}

double TrackingSubsystem::getTarget_Z_Data() const {
    return target_Z_Data;
}

void TrackingSubsystem::setTarget_Z_Data(double  p_target_Z_Data) {
    target_Z_Data = p_target_Z_Data;
}

TrackingSubsystemCoeff* TrackingSubsystem::getCoeff() const {
    return (TrackingSubsystemCoeff*) &Coeff;
}

GimbalController* TrackingSubsystem::getItsGimbalController() const {
    return (GimbalController*) &itsGimbalController;
}

GuidanceLogic* TrackingSubsystem::getItsGuidanceLogic() const {
    return itsGuidanceLogic;
}

void TrackingSubsystem::setItsGuidanceLogic(GuidanceLogic*  p_GuidanceLogic) {
    itsGuidanceLogic = p_GuidanceLogic;
}

RateStabilizationFilter* TrackingSubsystem::getItsRateStabilizationFilter() const {
    return (RateStabilizationFilter*) &itsRateStabilizationFilter;
}

void TrackingSubsystem::cleanUpRelations() {
    if(itsGuidanceLogic != NULL)
        {
            itsGuidanceLogic = NULL;
        }
}

OMBoolean TrackingSubsystem::startBehavior() {
    OMBoolean done = FALSE;
    itsGimbalController.startBehavior();
    itsRateStabilizationFilter.startBehavior();
    done = OMReactive::startBehavior();
    return done;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\TrackingSubsystem.cpp
*********************************************************************/

