/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: GuidanceLogic
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\GuidanceLogic.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 


#define _OMSTATECHART_ANIMATED 
//#]

#include "GuidanceLogic.h"
#include <stdafx.h>
#include <math.h>

//## package GuidancePkg 


//#[ ignore 
#define GuidancePkg_GuidanceLogic_GuidanceLogic_SERIALIZE OM_NO_OP


#define GuidancePkg_GuidanceLogic_get_Az_Demand_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define GuidancePkg_GuidanceLogic_get_dishAngleCommand_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define GuidancePkg_GuidanceLogic_get_guidanceMode_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define GuidancePkg_GuidanceLogic_handle_tick_SERIALIZE aomsmethod->addAttribute("t", x2String(t));


#define GuidancePkg_GuidanceLogic_set_LOSRate_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define GuidancePkg_GuidanceLogic_set_Range_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));


#define GuidancePkg_GuidanceLogic_set_closingVelocity_SERIALIZE \
    aomsmethod->addAttribute("t", x2String(t)); \
    aomsmethod->addAttribute("val", x2String(val));
//#]

//----------------------------------------------------------------------------
// GuidanceLogic.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(GuidancePkg)
//## class GuidanceLogic 



GuidanceLogic::GuidanceLogic(OMThread*  p_thread) {
    NOTIFY_REACTIVE_CONSTRUCTOR(GuidanceLogic, GuidanceLogic(), 0, GuidancePkg_GuidanceLogic_GuidanceLogic_SERIALIZE);
    setThread(p_thread, FALSE);
    initStatechart();
    //#[ operation GuidanceLogic() 
    //#]
}

GuidanceLogic::~GuidanceLogic() {
    NOTIFY_DESTRUCTOR(~GuidanceLogic, TRUE);
    //#[ operation ~GuidanceLogic() 
    //#]
}

void GuidanceLogic::get_Az_Demand(const double  t, double *val) {
    NOTIFY_OPERATION(get_Az_Demand, get_Az_Demand(const double,double *), 2, GuidancePkg_GuidanceLogic_get_Az_Demand_SERIALIZE);
    //#[ operation get_Az_Demand(const double,double *) 
    
    *val = Az_Demand; 
    //#]
}

void GuidanceLogic::get_dishAngleCommand(const double  t, double *val) {
    NOTIFY_OPERATION(get_dishAngleCommand, get_dishAngleCommand(const double,double *), 2, GuidancePkg_GuidanceLogic_get_dishAngleCommand_SERIALIZE);
    //#[ operation get_dishAngleCommand(const double,double *) 
    
    *val = dishAngleCommand; 
    //#]
}

void GuidanceLogic::get_guidanceMode(const double  t, long *val) {
    NOTIFY_OPERATION(get_guidanceMode, get_guidanceMode(const double,long *), 2, GuidancePkg_GuidanceLogic_get_guidanceMode_SERIALIZE);
    //#[ operation get_guidanceMode(const double,long *) 
    
    *val = guidanceMode; // *d2r if *val in degree for display
    //#]
}

void GuidanceLogic::handle_tick(const double  t) {
    NOTIFY_OPERATION(handle_tick, handle_tick(const double), 1, GuidancePkg_GuidanceLogic_handle_tick_SERIALIZE);
    //#[ operation handle_tick(const double) 
    receive();
    GEN(evGuidanceTick);
    broadcast(t);
    //#]
}

void GuidanceLogic::set_LOSRate(const double  t, double *val) {
    NOTIFY_OPERATION(set_LOSRate, set_LOSRate(const double,double *), 2, GuidancePkg_GuidanceLogic_set_LOSRate_SERIALIZE);
    //#[ operation set_LOSRate(const double,double *) 
    
    LOSRate  = *val; 
    //#]
}

void GuidanceLogic::set_Range(const double  t, double *val) {
    NOTIFY_OPERATION(set_Range, set_Range(const double,double *), 2, GuidancePkg_GuidanceLogic_set_Range_SERIALIZE);
    //#[ operation set_Range(const double,double *) 
    
    Range  = *val; 
    //#]
}

void GuidanceLogic::set_closingVelocity(const double  t, double *val) {
    NOTIFY_OPERATION(set_closingVelocity, set_closingVelocity(const double,double *), 2, GuidancePkg_GuidanceLogic_set_closingVelocity_SERIALIZE);
    //#[ operation set_closingVelocity(const double,double *) 
    
    closingVelocity  = *val; 
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

double GuidanceLogic::getPeriod() const {
    return period;
}

void GuidanceLogic::setPeriod(double  p_period) {
    period = p_period;
}

void GuidanceLogic::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        Running_entDef();
        NOTIFY_TRANSITION_TERMINATED("0");
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
                    NOTIFY_TRANSITION_STARTED("1");
                    popNullConfig();
                    NOTIFY_STATE_EXITED("ROOT.Running.GuidanceMode.init");
                    NOTIFY_STATE_ENTERED("ROOT.Running.GuidanceMode.targetSearch");
                    pushNullConfig();
                    GuidanceMode_subState = targetSearch;
                    GuidanceMode_active = targetSearch;
                    //#[ state ROOT.Running.GuidanceMode.targetSearch.(Entry) 
                    #define min(x, y) (((x) < (y)) ? (x) : (y))
                    #define max(x, y) (((x) > (y)) ? (x) : (y))
                    
                    guidanceMode = 1;
                    dishAngleCommand -= 0.01*ScanningSteps;
                    this->nTicks++;
                    if(dishAngleCommand >= 30.0 || dishAngleCommand <= -30.0) ScanningSteps *= -1;
                    Az_Demand = min(max((Az_Fixed),Az_min),Az_max);
                    MissionTime += period/1000.0;
                    broadcast(0.0);
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("1");
                    res = eventConsumed;
                }
            
            
            break;
        };
        case targetSearch:
        {
            res = targetSearch_takeEvent(id);
            break;
        };
        case radarGuided:
        {
            res = radarGuided_takeEvent(id);
            break;
        };
        case blindRange:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    //## transition 7 
                    if(Range<25)
                        {
                            NOTIFY_TRANSITION_STARTED("7");
                            popNullConfig();
                            NOTIFY_STATE_EXITED("ROOT.Running.GuidanceMode.blindRange");
                            NOTIFY_STATE_ENTERED("ROOT.Running.GuidanceMode.Detonate");
                            GuidanceMode_subState = Detonate;
                            GuidanceMode_active = Detonate;
                            //#[ state ROOT.Running.GuidanceMode.Detonate.(Entry) 
                            
                            guidanceMode = 5;
                            MissDistance = Range; 
                            HitTime = MissionTime;
                            broadcast(0.0);
                            
                            //#]
                            NOTIFY_TRANSITION_TERMINATED("7");
                            res = eventConsumed;
                        }
                }
            else if(IS_EVENT_TYPE_OF(evGuidanceTick_GuidancePkg_id))
                {
                    NOTIFY_TRANSITION_STARTED("12");
                    popNullConfig();
                    NOTIFY_STATE_EXITED("ROOT.Running.GuidanceMode.blindRange");
                    NOTIFY_STATE_ENTERED("ROOT.Running.GuidanceMode.blindRange");
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
                    broadcast(0.0);
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("12");
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
                            NOTIFY_TRANSITION_STARTED("4");
                            popNullConfig();
                            NOTIFY_STATE_EXITED("ROOT.Running.GuidanceMode.targetLock");
                            NOTIFY_STATE_ENTERED("ROOT.Running.GuidanceMode.radarGuided");
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
                            
                            broadcast(0.0);
                            //#]
                            NOTIFY_TRANSITION_TERMINATED("4");
                            res = eventConsumed;
                        }
                }
            else if(IS_EVENT_TYPE_OF(evGuidanceTick_GuidancePkg_id))
                {
                    NOTIFY_TRANSITION_STARTED("10");
                    popNullConfig();
                    NOTIFY_STATE_EXITED("ROOT.Running.GuidanceMode.targetLock");
                    NOTIFY_STATE_ENTERED("ROOT.Running.GuidanceMode.targetLock");
                    pushNullConfig();
                    GuidanceMode_subState = targetLock;
                    GuidanceMode_active = targetLock;
                    //#[ state ROOT.Running.GuidanceMode.targetLock.(Entry) 
                    guidanceMode = 2;
                    nTicks++; 
                    MissionTime += period/1000.0;
                    Az_Demand = min(max(Az_Fixed,Az_min),Az_max); 
                    broadcast(0.0);
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("10");
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
                    NOTIFY_TRANSITION_STARTED("13");
                    popNullConfig();
                    NOTIFY_STATE_EXITED("ROOT.Running.FuzeMode.init");
                    NOTIFY_STATE_ENTERED("ROOT.Running.FuzeMode.inert");
                    pushNullConfig();
                    FuzeMode_subState = inert;
                    FuzeMode_active = inert;
                    NOTIFY_TRANSITION_TERMINATED("13");
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
                            NOTIFY_TRANSITION_STARTED("14");
                            popNullConfig();
                            NOTIFY_STATE_EXITED("ROOT.Running.FuzeMode.inert");
                            NOTIFY_STATE_ENTERED("ROOT.Running.FuzeMode.armed");
                            pushNullConfig();
                            FuzeMode_subState = armed;
                            FuzeMode_active = armed;
                            NOTIFY_TRANSITION_TERMINATED("14");
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
                            NOTIFY_TRANSITION_STARTED("15");
                            popNullConfig();
                            NOTIFY_STATE_EXITED("ROOT.Running.FuzeMode.armed");
                            NOTIFY_STATE_ENTERED("ROOT.Running.FuzeMode.inert");
                            pushNullConfig();
                            FuzeMode_subState = inert;
                            FuzeMode_active = inert;
                            NOTIFY_TRANSITION_TERMINATED("15");
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

OMBoolean GuidanceLogic::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}

int GuidanceLogic::targetSearch_takeEvent(short  id) {
    int res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMEventNullId))
        {
            //## transition 2 
            if(MissionTime>5)
                {
                    NOTIFY_TRANSITION_STARTED("2");
                    popNullConfig();
                    NOTIFY_STATE_EXITED("ROOT.Running.GuidanceMode.targetSearch");
                    //#[ transition 2 
                    GEN(evTimeout());
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.Running.GuidanceMode.abort");
                    GuidanceMode_subState = abort;
                    GuidanceMode_active = abort;
                    //#[ state ROOT.Running.GuidanceMode.abort.(Entry) 
                    GEN(evDetonate());
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("2");
                    res = eventConsumed;
                }
        }
    else if(IS_EVENT_TYPE_OF(evGuidanceTick_GuidancePkg_id))
        {
            NOTIFY_TRANSITION_STARTED("11");
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.Running.GuidanceMode.targetSearch");
            NOTIFY_STATE_ENTERED("ROOT.Running.GuidanceMode.targetSearch");
            pushNullConfig();
            GuidanceMode_subState = targetSearch;
            GuidanceMode_active = targetSearch;
            //#[ state ROOT.Running.GuidanceMode.targetSearch.(Entry) 
            #define min(x, y) (((x) < (y)) ? (x) : (y))
            #define max(x, y) (((x) > (y)) ? (x) : (y))
            
            guidanceMode = 1;
            dishAngleCommand -= 0.01*ScanningSteps;
            this->nTicks++;
            if(dishAngleCommand >= 30.0 || dishAngleCommand <= -30.0) ScanningSteps *= -1;
            Az_Demand = min(max((Az_Fixed),Az_min),Az_max);
            MissionTime += period/1000.0;
            broadcast(0.0);
            //#]
            NOTIFY_TRANSITION_TERMINATED("11");
            res = eventConsumed;
        }
    else if(IS_EVENT_TYPE_OF(evTargetAcquired_GuidancePkg_id))
        {
            NOTIFY_TRANSITION_STARTED("3");
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.Running.GuidanceMode.targetSearch");
            //#[ transition 3 
            nTicks=0;
            AcquireTime = MissionTime;
            //#]
            NOTIFY_STATE_ENTERED("ROOT.Running.GuidanceMode.targetLock");
            pushNullConfig();
            GuidanceMode_subState = targetLock;
            GuidanceMode_active = targetLock;
            //#[ state ROOT.Running.GuidanceMode.targetLock.(Entry) 
            guidanceMode = 2;
            nTicks++; 
            MissionTime += period/1000.0;
            Az_Demand = min(max(Az_Fixed,Az_min),Az_max); 
            broadcast(0.0);
            //#]
            NOTIFY_TRANSITION_TERMINATED("3");
            res = eventConsumed;
        }
    
    
    return res;
}

void GuidanceLogic::FuzeMode_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.Running.FuzeMode");
    NOTIFY_TRANSITION_STARTED("16");
    NOTIFY_STATE_ENTERED("ROOT.Running.FuzeMode.init");
    pushNullConfig();
    FuzeMode_subState = FuzeMode_init;
    FuzeMode_active = FuzeMode_init;
    NOTIFY_TRANSITION_TERMINATED("16");
}

void GuidanceLogic::Running_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.Running");
    rootState_subState = Running;
    rootState_active = Running;
    GuidanceMode_entDef();
    FuzeMode_entDef();
}

int GuidanceLogic::radarGuided_takeEvent(short  id) {
    int res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(evTargetLost_GuidancePkg_id))
        {
            NOTIFY_TRANSITION_STARTED("5");
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.Running.GuidanceMode.radarGuided");
            //#[ transition 5 
            nTicks=0;
            Az_Fixed = Az_Demand;
            //#]
            NOTIFY_STATE_ENTERED("ROOT.Running.GuidanceMode.targetSearch");
            pushNullConfig();
            GuidanceMode_subState = targetSearch;
            GuidanceMode_active = targetSearch;
            //#[ state ROOT.Running.GuidanceMode.targetSearch.(Entry) 
            #define min(x, y) (((x) < (y)) ? (x) : (y))
            #define max(x, y) (((x) > (y)) ? (x) : (y))
            
            guidanceMode = 1;
            dishAngleCommand -= 0.01*ScanningSteps;
            this->nTicks++;
            if(dishAngleCommand >= 30.0 || dishAngleCommand <= -30.0) ScanningSteps *= -1;
            Az_Demand = min(max((Az_Fixed),Az_min),Az_max);
            MissionTime += period/1000.0;
            broadcast(0.0);
            //#]
            NOTIFY_TRANSITION_TERMINATED("5");
            res = eventConsumed;
        }
    else if(IS_EVENT_TYPE_OF(OMEventNullId))
        {
            //## transition 6 
            if(Range<200.0)
                {
                    NOTIFY_TRANSITION_STARTED("6");
                    popNullConfig();
                    NOTIFY_STATE_EXITED("ROOT.Running.GuidanceMode.radarGuided");
                    //#[ transition 6 
                    Az_Fixed = Az_Demand;
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.Running.GuidanceMode.blindRange");
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
                    broadcast(0.0);
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("6");
                    res = eventConsumed;
                }
        }
    else if(IS_EVENT_TYPE_OF(evGuidanceTick_GuidancePkg_id))
        {
            NOTIFY_TRANSITION_STARTED("9");
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.Running.GuidanceMode.radarGuided");
            NOTIFY_STATE_ENTERED("ROOT.Running.GuidanceMode.radarGuided");
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
            
            broadcast(0.0);
            //#]
            NOTIFY_TRANSITION_TERMINATED("9");
            res = eventConsumed;
        }
    
    
    return res;
}

void GuidanceLogic::GuidanceMode_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.Running.GuidanceMode");
    NOTIFY_TRANSITION_STARTED("8");
    NOTIFY_STATE_ENTERED("ROOT.Running.GuidanceMode.init");
    pushNullConfig();
    GuidanceMode_subState = init;
    GuidanceMode_active = init;
    //#[ state ROOT.Running.GuidanceMode.init.(Entry) 
    guidanceMode = 0;
    period = 10.0;
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
    NOTIFY_TRANSITION_TERMINATED("8");
}

void GuidanceLogic::Running_exit() {
    GuidanceMode_exit();
    switch (FuzeMode_subState) {
        case FuzeMode_init:
        {
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.Running.FuzeMode.init");
            break;
        };
        case inert:
        {
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.Running.FuzeMode.inert");
            break;
        };
        case armed:
        {
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.Running.FuzeMode.armed");
            break;
        };
        default:
            break;
    };
    FuzeMode_subState = OMNonState;
    NOTIFY_STATE_EXITED("ROOT.Running.FuzeMode");
    NOTIFY_STATE_EXITED("ROOT.Running");
}

void GuidanceLogic::GuidanceMode_exit() {
    switch (GuidanceMode_subState) {
        case init:
        {
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.Running.GuidanceMode.init");
            break;
        };
        case abort:
        {
            NOTIFY_STATE_EXITED("ROOT.Running.GuidanceMode.abort");
            break;
        };
        case targetSearch:
        {
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.Running.GuidanceMode.targetSearch");
            break;
        };
        case radarGuided:
        {
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.Running.GuidanceMode.radarGuided");
            break;
        };
        case Detonate:
        {
            NOTIFY_STATE_EXITED("ROOT.Running.GuidanceMode.Detonate");
            break;
        };
        case blindRange:
        {
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.Running.GuidanceMode.blindRange");
            break;
        };
        case targetLock:
        {
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.Running.GuidanceMode.targetLock");
            break;
        };
        default:
            break;
    };
    GuidanceMode_subState = OMNonState;
    NOTIFY_STATE_EXITED("ROOT.Running.GuidanceMode");
}



#ifdef _OMINSTRUMENT


void OMAnimatedGuidanceLogic::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("Az_Fixed", x2String(myReal->Az_Fixed));
    aomsAttributes->addAttribute("Az_Demand", x2String(myReal->Az_Demand));
    aomsAttributes->addAttribute("ScanningSteps", x2String(myReal->ScanningSteps));
    aomsAttributes->addAttribute("AcquireTime", x2String(myReal->AcquireTime));
    aomsAttributes->addAttribute("Range", x2String(myReal->Range));
    aomsAttributes->addAttribute("Az_min", x2String(myReal->Az_min));
    aomsAttributes->addAttribute("Az_max", x2String(myReal->Az_max));
    aomsAttributes->addAttribute("closingVelocity", x2String(myReal->closingVelocity));
    aomsAttributes->addAttribute("LOSRate", x2String(myReal->LOSRate));
    aomsAttributes->addAttribute("PropNavGain", x2String(myReal->PropNavGain));
    aomsAttributes->addAttribute("period", x2String(myReal->period));
    aomsAttributes->addAttribute("dishAngleCommand", x2String(myReal->dishAngleCommand));
    aomsAttributes->addAttribute("nTicks", x2String(myReal->nTicks));
    aomsAttributes->addAttribute("MissionTime", x2String(myReal->MissionTime));
    aomsAttributes->addAttribute("guidanceMode", x2String(myReal->guidanceMode));
    aomsAttributes->addAttribute("MissDistance", x2String(myReal->MissDistance));
    aomsAttributes->addAttribute("HitTime", x2String(myReal->HitTime));
}

void OMAnimatedGuidanceLogic::rootState_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case GuidanceLogic::Running:
        {
            Running_serializeStates(aomsState);
            break;
        };
        default:
            break;
    };
}

void OMAnimatedGuidanceLogic::Running_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running");
    GuidanceMode_serializeStates(aomsState);
    FuzeMode_serializeStates(aomsState);
}

void OMAnimatedGuidanceLogic::GuidanceMode_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.GuidanceMode");
    switch (myReal->GuidanceMode_subState) {
        case GuidanceLogic::init:
        {
            init_serializeStates(aomsState);
            break;
        };
        case GuidanceLogic::abort:
        {
            abort_serializeStates(aomsState);
            break;
        };
        case GuidanceLogic::targetSearch:
        {
            targetSearch_serializeStates(aomsState);
            break;
        };
        case GuidanceLogic::radarGuided:
        {
            radarGuided_serializeStates(aomsState);
            break;
        };
        case GuidanceLogic::Detonate:
        {
            Detonate_serializeStates(aomsState);
            break;
        };
        case GuidanceLogic::blindRange:
        {
            blindRange_serializeStates(aomsState);
            break;
        };
        case GuidanceLogic::targetLock:
        {
            targetLock_serializeStates(aomsState);
            break;
        };
        default:
            break;
    };
}

void OMAnimatedGuidanceLogic::targetSearch_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.GuidanceMode.targetSearch");
}

void OMAnimatedGuidanceLogic::targetLock_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.GuidanceMode.targetLock");
}

void OMAnimatedGuidanceLogic::radarGuided_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.GuidanceMode.radarGuided");
}

void OMAnimatedGuidanceLogic::init_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.GuidanceMode.init");
}

void OMAnimatedGuidanceLogic::Detonate_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.GuidanceMode.Detonate");
}

void OMAnimatedGuidanceLogic::blindRange_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.GuidanceMode.blindRange");
}

void OMAnimatedGuidanceLogic::abort_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.GuidanceMode.abort");
}

void OMAnimatedGuidanceLogic::FuzeMode_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.FuzeMode");
    switch (myReal->FuzeMode_subState) {
        case GuidanceLogic::FuzeMode_init:
        {
            FuzeMode_init_serializeStates(aomsState);
            break;
        };
        case GuidanceLogic::inert:
        {
            inert_serializeStates(aomsState);
            break;
        };
        case GuidanceLogic::armed:
        {
            armed_serializeStates(aomsState);
            break;
        };
        default:
            break;
    };
}

void OMAnimatedGuidanceLogic::FuzeMode_init_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.FuzeMode.init");
}

void OMAnimatedGuidanceLogic::inert_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.FuzeMode.inert");
}

void OMAnimatedGuidanceLogic::armed_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.FuzeMode.armed");
}

IMPLEMENT_REACTIVE_META(GuidanceLogic, GuidancePkg, FALSE, OMAnimatedGuidanceLogic)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\GuidanceLogic.cpp
*********************************************************************/

