/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: GuidanceLogic
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\GuidanceLogic.cpp
*********************************************************************/

#include <oxf/omthread.h>
#include "GuidanceLogic.h"
#include "EstimatorVc.h"
#include <stdafx.h>
#include <math.h>

//## package GuidancePkg 

//----------------------------------------------------------------------------
// GuidanceLogic.cpp                                                                  
//----------------------------------------------------------------------------
//## class GuidanceLogic 



GuidanceLogic::GuidanceLogic(OMThread*  p_thread) {
    setThread(p_thread, FALSE);
    itsEstimatorVc = NULL;
    initStatechart();
    //#[ operation GuidanceLogic() 
    //#]
}

GuidanceLogic::~GuidanceLogic() {
    //#[ operation ~GuidanceLogic() 
    //#]
    cleanUpRelations();
}

void GuidanceLogic::handle_tick() {
    //#[ operation handle_tick() 
    receive();
    GEN(evGuidanceTick);
    broadcast();
    //#]
}

void GuidanceLogic::setPeriod(long  val) {
    //#[ operation setPeriod(long) 
    period = val;
    //#]
}

double GuidanceLogic::getAcquireTime() const {
    return AcquireTime;
}

void GuidanceLogic::setAcquireTime(double  p_AcquireTime) {
    AcquireTime = p_AcquireTime;
}

double GuidanceLogic::getAz_Demand() const {
    return Az_Demand;
}

void GuidanceLogic::setAz_Demand(double  p_Az_Demand) {
    Az_Demand = p_Az_Demand;
}

double GuidanceLogic::getAz_Fixed() const {
    return Az_Fixed;
}

void GuidanceLogic::setAz_Fixed(double  p_Az_Fixed) {
    Az_Fixed = p_Az_Fixed;
}

double GuidanceLogic::getAz_max() const {
    return Az_max;
}

void GuidanceLogic::setAz_max(double  p_Az_max) {
    Az_max = p_Az_max;
}

double GuidanceLogic::getAz_min() const {
    return Az_min;
}

void GuidanceLogic::setAz_min(double  p_Az_min) {
    Az_min = p_Az_min;
}

double GuidanceLogic::getHitTime() const {
    return HitTime;
}

void GuidanceLogic::setHitTime(double  p_HitTime) {
    HitTime = p_HitTime;
}

double GuidanceLogic::getLOSRate() const {
    return LOSRate;
}

void GuidanceLogic::setLOSRate(double  p_LOSRate) {
    LOSRate = p_LOSRate;
}

double GuidanceLogic::getMissDistance() const {
    return MissDistance;
}

void GuidanceLogic::setMissDistance(double  p_MissDistance) {
    MissDistance = p_MissDistance;
}

double GuidanceLogic::getMissionTime() const {
    return MissionTime;
}

void GuidanceLogic::setMissionTime(double  p_MissionTime) {
    MissionTime = p_MissionTime;
}

double GuidanceLogic::getPropNavGain() const {
    return PropNavGain;
}

void GuidanceLogic::setPropNavGain(double  p_PropNavGain) {
    PropNavGain = p_PropNavGain;
}

double GuidanceLogic::getRange() const {
    return Range;
}

void GuidanceLogic::setRange(double  p_Range) {
    Range = p_Range;
}

int GuidanceLogic::getScanningSteps() const {
    return ScanningSteps;
}

void GuidanceLogic::setScanningSteps(int  p_ScanningSteps) {
    ScanningSteps = p_ScanningSteps;
}

double GuidanceLogic::getClosingVelocity() const {
    return closingVelocity;
}

void GuidanceLogic::setClosingVelocity(double  p_closingVelocity) {
    closingVelocity = p_closingVelocity;
}

double GuidanceLogic::getDishAngleCommand() const {
    return dishAngleCommand;
}

void GuidanceLogic::setDishAngleCommand(double  p_dishAngleCommand) {
    dishAngleCommand = p_dishAngleCommand;
}

int GuidanceLogic::getGuidanceMode() const {
    return guidanceMode;
}

void GuidanceLogic::setGuidanceMode(int  p_guidanceMode) {
    guidanceMode = p_guidanceMode;
}

int GuidanceLogic::getNTicks() const {
    return nTicks;
}

void GuidanceLogic::setNTicks(int  p_nTicks) {
    nTicks = p_nTicks;
}

long GuidanceLogic::getPeriod() const {
    return period;
}

EstimatorVc* GuidanceLogic::getItsEstimatorVc() const {
    return itsEstimatorVc;
}

void GuidanceLogic::setItsEstimatorVc(EstimatorVc*  p_EstimatorVc) {
    itsEstimatorVc = p_EstimatorVc;
}

void GuidanceLogic::rootState_entDef() {
    {
        Running_entDef();
    }
}

int GuidanceLogic::rootState_dispatchEvent(short  id) {
    int res = eventNotConsumed;
    switch (rootState_active) {
        case Running:
        {
            res = Running_dispatchEvent(id);
            break;
        };
        default:
            break;
    };
    return res;
}

int GuidanceLogic::Running_dispatchEvent(short  id) {
    int res = eventNotConsumed;
    if(GuidanceMode_dispatchEvent(id) > 0)
        {
            res = eventConsumed;
            if(!IS_IN(Running))
                {
                    return res;
                }
        }
    if(FuzeMode_dispatchEvent(id) > 0)
        {
            res = eventConsumed;
            if(!IS_IN(Running))
                {
                    return res;
                }
        }
    
    return res;
}

int GuidanceLogic::GuidanceMode_dispatchEvent(short  id) {
    int res = eventNotConsumed;
    switch (GuidanceMode_active) {
        case init:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    popNullConfig();
                    pushNullConfig();
                    GuidanceMode_subState = targetSearch;
                    GuidanceMode_active = targetSearch;
                    //#[ state ROOT.Running.GuidanceMode.targetSearch.(Entry) 
                    #define min(x, y) (((x) < (y)) ? (x) : (y))
                    #define max(x, y) (((x) > (y)) ? (x) : (y))
                    
                    guidanceMode = 1;
                    dishAngleCommand -= ((double)period/1000.0)*ScanningSteps;
                    this->nTicks++;
                    if(dishAngleCommand >= 30.0 || dishAngleCommand <= -30.0) ScanningSteps *= -1;
                    Az_Demand = min(max((Az_Fixed),Az_min),Az_max);
                    MissionTime += period/1000.0;
                    broadcast();
                    //#]
                    res = eventConsumed;
                }
            
            
            break;
        };
        case targetSearch:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    //## transition 2 
                    if(MissionTime>5)
                        {
                            popNullConfig();
                            //#[ transition 2 
                            GEN(evTimeout());
                            //#]
                            GuidanceMode_subState = abort;
                            GuidanceMode_active = abort;
                            //#[ state ROOT.Running.GuidanceMode.abort.(Entry) 
                            GEN(evDetonate());
                            //#]
                            res = eventConsumed;
                        }
                }
            else if(IS_EVENT_TYPE_OF(evGuidanceTick_GuidancePkg_id))
                {
                    popNullConfig();
                    pushNullConfig();
                    GuidanceMode_subState = targetSearch;
                    GuidanceMode_active = targetSearch;
                    //#[ state ROOT.Running.GuidanceMode.targetSearch.(Entry) 
                    #define min(x, y) (((x) < (y)) ? (x) : (y))
                    #define max(x, y) (((x) > (y)) ? (x) : (y))
                    
                    guidanceMode = 1;
                    dishAngleCommand -= ((double)period/1000.0)*ScanningSteps;
                    this->nTicks++;
                    if(dishAngleCommand >= 30.0 || dishAngleCommand <= -30.0) ScanningSteps *= -1;
                    Az_Demand = min(max((Az_Fixed),Az_min),Az_max);
                    MissionTime += period/1000.0;
                    broadcast();
                    //#]
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(evTargetAcquired_GuidancePkg_id))
                {
                    popNullConfig();
                    //#[ transition 3 
                    nTicks=0;
                    AcquireTime = MissionTime;
                    //#]
                    pushNullConfig();
                    GuidanceMode_subState = targetLock;
                    GuidanceMode_active = targetLock;
                    //#[ state ROOT.Running.GuidanceMode.targetLock.(Entry) 
                    guidanceMode = 2;
                    nTicks++; 
                    MissionTime += period/1000.0;
                    Az_Demand = min(max(Az_Fixed,Az_min),Az_max); 
                    broadcast();
                    //#]
                    res = eventConsumed;
                }
            
            
            break;
        };
        case radarGuided:
        {
            if(IS_EVENT_TYPE_OF(evTargetLost_GuidancePkg_id))
                {
                    popNullConfig();
                    //#[ transition 5 
                    nTicks=0;
                    Az_Fixed = Az_Demand;
                    //#]
                    pushNullConfig();
                    GuidanceMode_subState = targetSearch;
                    GuidanceMode_active = targetSearch;
                    //#[ state ROOT.Running.GuidanceMode.targetSearch.(Entry) 
                    #define min(x, y) (((x) < (y)) ? (x) : (y))
                    #define max(x, y) (((x) > (y)) ? (x) : (y))
                    
                    guidanceMode = 1;
                    dishAngleCommand -= ((double)period/1000.0)*ScanningSteps;
                    this->nTicks++;
                    if(dishAngleCommand >= 30.0 || dishAngleCommand <= -30.0) ScanningSteps *= -1;
                    Az_Demand = min(max((Az_Fixed),Az_min),Az_max);
                    MissionTime += period/1000.0;
                    broadcast();
                    //#]
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    //## transition 6 
                    if(Range<200.0)
                        {
                            popNullConfig();
                            //#[ transition 6 
                            Az_Fixed = Az_Demand;
                            //#]
                            pushNullConfig();
                            GuidanceMode_subState = blindRange;
                            GuidanceMode_active = blindRange;
                            //#[ state ROOT.Running.GuidanceMode.blindRange.(Entry) 
                            guidanceMode = 4;
                            MissionTime += period/1000.0;
                            Az_Demand = min(max(Az_Fixed,Az_min),Az_max);
                            if(Range < fabs(MissDistance)){
                            	MissDistance = Range; 
                            }
                            broadcast();
                            //#]
                            res = eventConsumed;
                        }
                }
            else if(IS_EVENT_TYPE_OF(evGuidanceTick_GuidancePkg_id))
                {
                    popNullConfig();
                    pushNullConfig();
                    GuidanceMode_subState = radarGuided;
                    GuidanceMode_active = radarGuided;
                    //#[ state ROOT.Running.GuidanceMode.radarGuided.(Entry) 
                    double Ts;
                    guidanceMode = 3;
                    Ts = period/1000.0;
                    MissionTime += Ts;
                    Az_Demand = - PropNavGain * closingVelocity * LOSRate;
                    Az_Demand = min(max((Az_Demand),Az_min),Az_max);  
                    
                    broadcast();
                    //#]
                    res = eventConsumed;
                }
            
            
            break;
        };
        case blindRange:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    //## transition 7 
                    if(Range<10)
                        {
                            popNullConfig();
                            GuidanceMode_subState = Detonate;
                            GuidanceMode_active = Detonate;
                            //#[ state ROOT.Running.GuidanceMode.Detonate.(Entry) 
                            
                            guidanceMode = 5;
                            MissDistance = Range; 
                            HitTime = MissionTime;
                            broadcast();
                            
                            //#]
                            res = eventConsumed;
                        }
                }
            else if(IS_EVENT_TYPE_OF(evGuidanceTick_GuidancePkg_id))
                {
                    popNullConfig();
                    pushNullConfig();
                    GuidanceMode_subState = blindRange;
                    GuidanceMode_active = blindRange;
                    //#[ state ROOT.Running.GuidanceMode.blindRange.(Entry) 
                    guidanceMode = 4;
                    MissionTime += period/1000.0;
                    Az_Demand = min(max(Az_Fixed,Az_min),Az_max);
                    if(Range < fabs(MissDistance)){
                    	MissDistance = Range; 
                    }
                    broadcast();
                    //#]
                    res = eventConsumed;
                }
            
            
            break;
        };
        case targetLock:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    //## transition 4 
                    if(nTicks*period > 200)
                        {
                            popNullConfig();
                            pushNullConfig();
                            GuidanceMode_subState = radarGuided;
                            GuidanceMode_active = radarGuided;
                            //#[ state ROOT.Running.GuidanceMode.radarGuided.(Entry) 
                            double Ts;
                            guidanceMode = 3;
                            Ts = period/1000.0;
                            MissionTime += Ts;
                            Az_Demand = - PropNavGain * closingVelocity * LOSRate;
                            Az_Demand = min(max((Az_Demand),Az_min),Az_max);  
                            
                            broadcast();
                            //#]
                            res = eventConsumed;
                        }
                }
            else if(IS_EVENT_TYPE_OF(evGuidanceTick_GuidancePkg_id))
                {
                    popNullConfig();
                    pushNullConfig();
                    GuidanceMode_subState = targetLock;
                    GuidanceMode_active = targetLock;
                    //#[ state ROOT.Running.GuidanceMode.targetLock.(Entry) 
                    guidanceMode = 2;
                    nTicks++; 
                    MissionTime += period/1000.0;
                    Az_Demand = min(max(Az_Fixed,Az_min),Az_max); 
                    broadcast();
                    //#]
                    res = eventConsumed;
                }
            
            
            break;
        };
        default:
            break;
    };
    return res;
}

int GuidanceLogic::FuzeMode_dispatchEvent(short  id) {
    int res = eventNotConsumed;
    switch (FuzeMode_active) {
        case FuzeMode_init:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    popNullConfig();
                    pushNullConfig();
                    FuzeMode_subState = inert;
                    FuzeMode_active = inert;
                    res = eventConsumed;
                }
            
            
            break;
        };
        case inert:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    //## transition 14 
                    if(IS_IN(radarGuided))
                        {
                            popNullConfig();
                            pushNullConfig();
                            FuzeMode_subState = armed;
                            FuzeMode_active = armed;
                            res = eventConsumed;
                        }
                }
            
            
            break;
        };
        case armed:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    //## transition 15 
                    if(IS_IN(targetSearch))
                        {
                            popNullConfig();
                            pushNullConfig();
                            FuzeMode_subState = inert;
                            FuzeMode_active = inert;
                            res = eventConsumed;
                        }
                }
            
            
            break;
        };
        default:
            break;
    };
    return res;
}

void GuidanceLogic::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
    GuidanceMode_subState = OMNonState;
    GuidanceMode_active = OMNonState;
    FuzeMode_subState = OMNonState;
    FuzeMode_active = OMNonState;
}

void GuidanceLogic::cleanUpRelations() {
    if(itsEstimatorVc != NULL)
        {
            itsEstimatorVc = NULL;
        }
}

OMBoolean GuidanceLogic::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}

void GuidanceLogic::FuzeMode_entDef() {
    pushNullConfig();
    FuzeMode_subState = FuzeMode_init;
    FuzeMode_active = FuzeMode_init;
}

void GuidanceLogic::Running_entDef() {
    rootState_subState = Running;
    rootState_active = Running;
    GuidanceMode_entDef();
    FuzeMode_entDef();
}

void GuidanceLogic::GuidanceMode_entDef() {
    pushNullConfig();
    GuidanceMode_subState = init;
    GuidanceMode_active = init;
    //#[ state ROOT.Running.GuidanceMode.init.(Entry) 
    guidanceMode = 0;
    // period = 5;
    Az_Fixed = -9.81;
    ScanningSteps = 100;
    nTicks = 0;
    Az_Demand = Az_Fixed;
    AcquireTime = 0.0;
    Range = 1000.0;
    Az_min = -40.0*9.81;
    Az_max = 40.0*9.81;
    closingVelocity = 0.0;
    LOSRate = 0.0;
    PropNavGain = 3.5;
    dishAngleCommand = 0.0;
    MissionTime = 0.0;
    
    //#]
}

void GuidanceLogic::Running_exit() {
    GuidanceMode_exit();
    switch (FuzeMode_subState) {
        case FuzeMode_init:
        {
            popNullConfig();
            break;
        };
        case inert:
        {
            popNullConfig();
            break;
        };
        case armed:
        {
            popNullConfig();
            break;
        };
        default:
            break;
    };
    FuzeMode_subState = OMNonState;
}

void GuidanceLogic::GuidanceMode_exit() {
    switch (GuidanceMode_subState) {
        case init:
        {
            popNullConfig();
            break;
        };
        case targetSearch:
        {
            popNullConfig();
            break;
        };
        case radarGuided:
        {
            popNullConfig();
            break;
        };
        case blindRange:
        {
            popNullConfig();
            break;
        };
        case targetLock:
        {
            popNullConfig();
            break;
        };
        default:
            break;
    };
    GuidanceMode_subState = OMNonState;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\GuidanceLogic.cpp
*********************************************************************/

