/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Guidance
//!	Generated Date	: Fri, 20, Dec 2002  
	File Path	: DefaultComponent\DefaultConfig\Guidance.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 


#define _OMSTATECHART_ANIMATED 
//#]

#include "Guidance.h"
#include "myFactory.h"

//## package Default 


//#[ ignore 
#define Default_Guidance_Guidance_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// Guidance.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(Default)
//## class Guidance 



Guidance::Guidance(OMThread*  p_thread) {
    NOTIFY_REACTIVE_CONSTRUCTOR(Guidance, Guidance(), 0, Default_Guidance_Guidance_SERIALIZE);
    setThread(p_thread, FALSE);
    itsMyFactory = NULL;
    initStatechart();
    //#[ operation Guidance() 
    //#]
}

Guidance::~Guidance() {
    NOTIFY_DESTRUCTOR(~Guidance, TRUE);
    //#[ operation ~Guidance() 
    //#]
    cleanUpRelations();
}

double Guidance::getAcquireTime() const {
    return AcquireTime;
}

void Guidance::setAcquireTime(double  p_AcquireTime) {
    AcquireTime = p_AcquireTime;
}

double Guidance::getAz_Demand() const {
    return Az_Demand;
}

void Guidance::setAz_Demand(double  p_Az_Demand) {
    Az_Demand = p_Az_Demand;
}

double Guidance::getAz_Fixed() const {
    return Az_Fixed;
}

void Guidance::setAz_Fixed(double  p_Az_Fixed) {
    Az_Fixed = p_Az_Fixed;
}

double Guidance::getAz_max() const {
    return Az_max;
}

void Guidance::setAz_max(double  p_Az_max) {
    Az_max = p_Az_max;
}

double Guidance::getAz_min() const {
    return Az_min;
}

void Guidance::setAz_min(double  p_Az_min) {
    Az_min = p_Az_min;
}

double Guidance::getDishAngle() const {
    return DishAngle;
}

void Guidance::setDishAngle(double  p_DishAngle) {
    DishAngle = p_DishAngle;
}

double Guidance::getLOSRate() const {
    return LOSRate;
}

void Guidance::setLOSRate(double  p_LOSRate) {
    LOSRate = p_LOSRate;
}

double Guidance::getMissionTime() const {
    return MissionTime;
}

void Guidance::setMissionTime(double  p_MissionTime) {
    MissionTime = p_MissionTime;
}

double Guidance::getPropNavGain() const {
    return PropNavGain;
}

void Guidance::setPropNavGain(double  p_PropNavGain) {
    PropNavGain = p_PropNavGain;
}

double Guidance::getRange() const {
    return Range;
}

void Guidance::setRange(double  p_Range) {
    Range = p_Range;
}

int Guidance::getScanningSteps() const {
    return ScanningSteps;
}

void Guidance::setScanningSteps(int  p_ScanningSteps) {
    ScanningSteps = p_ScanningSteps;
}

int Guidance::getBAcquired() const {
    return bAcquired;
}

void Guidance::setBAcquired(int  p_bAcquired) {
    bAcquired = p_bAcquired;
}

int Guidance::getBMissed() const {
    return bMissed;
}

void Guidance::setBMissed(int  p_bMissed) {
    bMissed = p_bMissed;
}

double Guidance::getClosingVelocity() const {
    return closingVelocity;
}

void Guidance::setClosingVelocity(double  p_closingVelocity) {
    closingVelocity = p_closingVelocity;
}

double Guidance::getDishAngleCommand() const {
    return dishAngleCommand;
}

void Guidance::setDishAngleCommand(double  p_dishAngleCommand) {
    dishAngleCommand = p_dishAngleCommand;
}

int Guidance::getNTicks() const {
    return nTicks;
}

void Guidance::setNTicks(int  p_nTicks) {
    nTicks = p_nTicks;
}

double Guidance::getSamplingInterval() const {
    return samplingInterval;
}

void Guidance::setSamplingInterval(double  p_samplingInterval) {
    samplingInterval = p_samplingInterval;
}

myFactory* Guidance::getItsMyFactory() const {
    return itsMyFactory;
}

void Guidance::__setItsMyFactory(myFactory*  p_myFactory) {
    itsMyFactory = p_myFactory;
    if(p_myFactory != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsMyFactory", p_myFactory, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsMyFactory");
        }
}

void Guidance::_setItsMyFactory(myFactory*  p_myFactory) {
    if(itsMyFactory != NULL)
        itsMyFactory->__setItsGuidance(NULL);
    __setItsMyFactory(p_myFactory);
}

void Guidance::setItsMyFactory(myFactory*  p_myFactory) {
    if(p_myFactory != NULL)
        p_myFactory->_setItsGuidance(this);
    _setItsMyFactory(p_myFactory);
}

void Guidance::_clearItsMyFactory() {
    NOTIFY_RELATION_CLEARED("itsMyFactory");
    itsMyFactory = NULL;
}

void Guidance::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        Running_entDef();
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

int Guidance::rootState_dispatchEvent(short  id) {
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

int Guidance::Running_dispatchEvent(short  id) {
    int res = eventNotConsumed;
    if(state_12_dispatchEvent(id) > 0)
        {
            res = eventConsumed;
            if(!IS_IN(Running))
                {
                    return res;
                }
        }
    if(state_13_dispatchEvent(id) > 0)
        {
            res = eventConsumed;
            if(!IS_IN(Running))
                {
                    return res;
                }
        }
    
    return res;
}

int Guidance::state_13_dispatchEvent(short  id) {
    int res = eventNotConsumed;
    switch (state_13_active) {
        case FuzeMode_init:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    NOTIFY_TRANSITION_STARTED("ROOT.Running.state_13.FuzeMode.1");
                    popNullConfig();
                    NOTIFY_STATE_EXITED("ROOT.Running.state_13.FuzeMode.ROOT.FuzeMode.init");
                    NOTIFY_STATE_ENTERED("ROOT.Running.state_13.FuzeMode.ROOT.FuzeMode.inert");
                    pushNullConfig();
                    FuzeMode_subState = inert;
                    state_13_active = inert;
                    NOTIFY_TRANSITION_TERMINATED("ROOT.Running.state_13.FuzeMode.1");
                    res = eventConsumed;
                }
            
            
            break;
        };
        case inert:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    //## transition ROOT.Running.state_13.FuzeMode.2 
                    if(IS_IN(radarGuided))
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.Running.state_13.FuzeMode.2");
                            popNullConfig();
                            NOTIFY_STATE_EXITED("ROOT.Running.state_13.FuzeMode.ROOT.FuzeMode.inert");
                            NOTIFY_STATE_ENTERED("ROOT.Running.state_13.FuzeMode.ROOT.FuzeMode.armed");
                            pushNullConfig();
                            FuzeMode_subState = armed;
                            state_13_active = armed;
                            NOTIFY_TRANSITION_TERMINATED("ROOT.Running.state_13.FuzeMode.2");
                            res = eventConsumed;
                        }
                }
            
            
            break;
        };
        case armed:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    //## transition ROOT.Running.state_13.FuzeMode.3 
                    if(IS_IN(targetSearch))
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.Running.state_13.FuzeMode.3");
                            popNullConfig();
                            NOTIFY_STATE_EXITED("ROOT.Running.state_13.FuzeMode.ROOT.FuzeMode.armed");
                            NOTIFY_STATE_ENTERED("ROOT.Running.state_13.FuzeMode.ROOT.FuzeMode.inert");
                            pushNullConfig();
                            FuzeMode_subState = inert;
                            state_13_active = inert;
                            NOTIFY_TRANSITION_TERMINATED("ROOT.Running.state_13.FuzeMode.3");
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

int Guidance::state_12_dispatchEvent(short  id) {
    int res = eventNotConsumed;
    switch (state_12_active) {
        case init:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    NOTIFY_TRANSITION_STARTED("ROOT.Running.state_12.GuidanceMode.1");
                    popNullConfig();
                    //#[ state ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.init.(Exit) 
                    
                    //#]
                    NOTIFY_STATE_EXITED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.init");
                    NOTIFY_STATE_ENTERED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.targetSearch");
                    pushNullConfig();
                    GuidanceMode_subState = targetSearch;
                    state_12_active = targetSearch;
                    //#[ state ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.targetSearch.(Entry) 
                    #define min(x, y) (((x) < (y)) ? (x) : (y))
                    #define max(x, y) (((x) > (y)) ? (x) : (y))
                    DishAngle += 0.01*ScanningSteps;
                    this->nTicks++;
                    if(DishAngle >= 30.0 || DishAngle <= -30.0) ScanningSteps *= -1;
                    Az_Demand = min(max((Az_Fixed),Az_min),Az_max);
                    MissionTime += samplingInterval;
                    //#]
                    myThread->schedTm(10, Guidance_Timeout_targetSearch_id, this, "ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.targetSearch");
                    NOTIFY_TRANSITION_TERMINATED("ROOT.Running.state_12.GuidanceMode.1");
                    res = eventConsumed;
                }
            
            
            break;
        };
        case targetSearch:
        {
            res = targetSearch_takeEvent(id);
            break;
        };
        case targetLock:
        {
            if(IS_EVENT_TYPE_OF(OMEventTimeoutId))
                {
                    if(((OMTimeout*)event)->getTimeoutId() == Guidance_Timeout_targetLock_id)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.Running.state_12.GuidanceMode.8");
                            popNullConfig();
                            myThread->unschedTm(Guidance_Timeout_targetLock_id, this);
                            NOTIFY_STATE_EXITED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.targetLock");
                            NOTIFY_STATE_ENTERED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.targetLock");
                            pushNullConfig();
                            GuidanceMode_subState = targetLock;
                            state_12_active = targetLock;
                            //#[ state ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.targetLock.(Entry) 
                            nTicks++;
                            Az_Demand = min(max(Az_Fixed,Az_min),Az_max);
                            //#]
                            myThread->schedTm(10, Guidance_Timeout_targetLock_id, this, "ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.targetLock");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.Running.state_12.GuidanceMode.8");
                            res = eventConsumed;
                        }
                }
            else if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    //## transition ROOT.Running.state_12.GuidanceMode.4 
                    if(nTicks*samplingInterval > 0.2)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.Running.state_12.GuidanceMode.4");
                            popNullConfig();
                            myThread->unschedTm(Guidance_Timeout_targetLock_id, this);
                            NOTIFY_STATE_EXITED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.targetLock");
                            NOTIFY_STATE_ENTERED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.radarGuided");
                            pushNullConfig();
                            GuidanceMode_subState = radarGuided;
                            state_12_active = radarGuided;
                            //#[ state ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.radarGuided.(Entry) 
                            Az_Demand = - PropNavGain * closingVelocity * LOSRate;
                            Az_Demand = min(max((Az_Demand),Az_min),Az_max);  
                            
                            Range -= 15.0;
                            //#]
                            myThread->schedTm(10, Guidance_Timeout_radarGuided_id, this, "ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.radarGuided");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.Running.state_12.GuidanceMode.4");
                            res = eventConsumed;
                        }
                }
            
            
            break;
        };
        case radarGuided:
        {
            res = radarGuided_takeEvent(id);
            break;
        };
        case blindRange:
        {
            if(IS_EVENT_TYPE_OF(OMEventTimeoutId))
                {
                    if(((OMTimeout*)event)->getTimeoutId() == Guidance_Timeout_blindRange_id)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.Running.state_12.GuidanceMode.10");
                            popNullConfig();
                            myThread->unschedTm(Guidance_Timeout_blindRange_id, this);
                            NOTIFY_STATE_EXITED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.blindRange");
                            NOTIFY_STATE_ENTERED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.blindRange");
                            pushNullConfig();
                            GuidanceMode_subState = blindRange;
                            state_12_active = blindRange;
                            //#[ state ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.blindRange.(Entry) 
                            Az_Demand = min(max(Az_Fixed,Az_min),Az_max);
                            Range -= 15;
                            //#]
                            myThread->schedTm(10, Guidance_Timeout_blindRange_id, this, "ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.blindRange");
                            NOTIFY_TRANSITION_TERMINATED("ROOT.Running.state_12.GuidanceMode.10");
                            res = eventConsumed;
                        }
                }
            else if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    //## transition ROOT.Running.state_12.GuidanceMode.11 
                    if(Range < 10)
                        {
                            NOTIFY_TRANSITION_STARTED("ROOT.Running.state_12.GuidanceMode.11");
                            popNullConfig();
                            myThread->unschedTm(Guidance_Timeout_blindRange_id, this);
                            NOTIFY_STATE_EXITED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.blindRange");
                            NOTIFY_STATE_ENTERED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.Done");
                            GuidanceMode_subState = Done;
                            state_12_active = Done;
                            NOTIFY_TRANSITION_TERMINATED("ROOT.Running.state_12.GuidanceMode.11");
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

void Guidance::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
    state_13_subState = OMNonState;
    state_13_active = OMNonState;
    FuzeMode_subState = OMNonState;
    state_12_subState = OMNonState;
    state_12_active = OMNonState;
    GuidanceMode_subState = OMNonState;
}

void Guidance::cleanUpRelations() {
    if(itsMyFactory != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsMyFactory");
            
            Guidance* p_Guidance = itsMyFactory->getItsGuidance();
            if(p_Guidance != NULL)
                itsMyFactory->__setItsGuidance(NULL);
            itsMyFactory = NULL;
        }
}

OMBoolean Guidance::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}

int Guidance::targetSearch_takeEvent(short  id) {
    int res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMEventTimeoutId))
        {
            if(((OMTimeout*)event)->getTimeoutId() == Guidance_Timeout_targetSearch_id)
                {
                    NOTIFY_TRANSITION_STARTED("ROOT.Running.state_12.GuidanceMode.7");
                    popNullConfig();
                    myThread->unschedTm(Guidance_Timeout_targetSearch_id, this);
                    NOTIFY_STATE_EXITED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.targetSearch");
                    NOTIFY_STATE_ENTERED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.targetSearch");
                    pushNullConfig();
                    GuidanceMode_subState = targetSearch;
                    state_12_active = targetSearch;
                    //#[ state ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.targetSearch.(Entry) 
                    #define min(x, y) (((x) < (y)) ? (x) : (y))
                    #define max(x, y) (((x) > (y)) ? (x) : (y))
                    DishAngle += 0.01*ScanningSteps;
                    this->nTicks++;
                    if(DishAngle >= 30.0 || DishAngle <= -30.0) ScanningSteps *= -1;
                    Az_Demand = min(max((Az_Fixed),Az_min),Az_max);
                    MissionTime += samplingInterval;
                    //#]
                    myThread->schedTm(10, Guidance_Timeout_targetSearch_id, this, "ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.targetSearch");
                    NOTIFY_TRANSITION_TERMINATED("ROOT.Running.state_12.GuidanceMode.7");
                    res = eventConsumed;
                }
        }
    else if(IS_EVENT_TYPE_OF(OMEventNullId))
        {
            //## transition ROOT.Running.state_12.GuidanceMode.2 
            if(MissionTime>7)
                {
                    NOTIFY_TRANSITION_STARTED("ROOT.Running.state_12.GuidanceMode.2");
                    popNullConfig();
                    myThread->unschedTm(Guidance_Timeout_targetSearch_id, this);
                    NOTIFY_STATE_EXITED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.targetSearch");
                    //#[ transition ROOT.Running.state_12.GuidanceMode.2 
                    GEN(evTimeout());
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.abort");
                    GuidanceMode_subState = abort;
                    state_12_active = abort;
                    //#[ state ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.abort.(Entry) 
                    GEN(evDetonate());
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("ROOT.Running.state_12.GuidanceMode.2");
                    res = eventConsumed;
                }
        }
    else if(IS_EVENT_TYPE_OF(evTargetAcquired_Default_id))
        {
            NOTIFY_TRANSITION_STARTED("ROOT.Running.state_12.GuidanceMode.3");
            popNullConfig();
            myThread->unschedTm(Guidance_Timeout_targetSearch_id, this);
            NOTIFY_STATE_EXITED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.targetSearch");
            //#[ transition ROOT.Running.state_12.GuidanceMode.3 
            nTicks = 0;
            //#]
            NOTIFY_STATE_ENTERED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.targetLock");
            pushNullConfig();
            GuidanceMode_subState = targetLock;
            state_12_active = targetLock;
            //#[ state ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.targetLock.(Entry) 
            nTicks++;
            Az_Demand = min(max(Az_Fixed,Az_min),Az_max);
            //#]
            myThread->schedTm(10, Guidance_Timeout_targetLock_id, this, "ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.targetLock");
            NOTIFY_TRANSITION_TERMINATED("ROOT.Running.state_12.GuidanceMode.3");
            res = eventConsumed;
        }
    
    
    return res;
}

void Guidance::state_13_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.Running.state_13");
    NOTIFY_TRANSITION_STARTED("2");
    FuzeMode_entDef();
    NOTIFY_TRANSITION_TERMINATED("2");
}

void Guidance::FuzeMode_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.Running.state_13.FuzeMode");
    state_13_subState = FuzeMode;
    NOTIFY_TRANSITION_STARTED("ROOT.Running.state_13.FuzeMode.0");
    NOTIFY_STATE_ENTERED("ROOT.Running.state_13.FuzeMode.ROOT.FuzeMode.init");
    pushNullConfig();
    FuzeMode_subState = FuzeMode_init;
    state_13_active = FuzeMode_init;
    NOTIFY_TRANSITION_TERMINATED("ROOT.Running.state_13.FuzeMode.0");
}

void Guidance::Running_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.Running");
    rootState_subState = Running;
    rootState_active = Running;
    state_12_entDef();
    state_13_entDef();
}

int Guidance::radarGuided_takeEvent(short  id) {
    int res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(evTargetLost_Default_id))
        {
            NOTIFY_TRANSITION_STARTED("ROOT.Running.state_12.GuidanceMode.5");
            popNullConfig();
            myThread->unschedTm(Guidance_Timeout_radarGuided_id, this);
            NOTIFY_STATE_EXITED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.radarGuided");
            //#[ transition ROOT.Running.state_12.GuidanceMode.5 
            nTicks=0;
            //#]
            NOTIFY_STATE_ENTERED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.targetSearch");
            pushNullConfig();
            GuidanceMode_subState = targetSearch;
            state_12_active = targetSearch;
            //#[ state ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.targetSearch.(Entry) 
            #define min(x, y) (((x) < (y)) ? (x) : (y))
            #define max(x, y) (((x) > (y)) ? (x) : (y))
            DishAngle += 0.01*ScanningSteps;
            this->nTicks++;
            if(DishAngle >= 30.0 || DishAngle <= -30.0) ScanningSteps *= -1;
            Az_Demand = min(max((Az_Fixed),Az_min),Az_max);
            MissionTime += samplingInterval;
            //#]
            myThread->schedTm(10, Guidance_Timeout_targetSearch_id, this, "ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.targetSearch");
            NOTIFY_TRANSITION_TERMINATED("ROOT.Running.state_12.GuidanceMode.5");
            res = eventConsumed;
        }
    else if(IS_EVENT_TYPE_OF(OMEventTimeoutId))
        {
            if(((OMTimeout*)event)->getTimeoutId() == Guidance_Timeout_radarGuided_id)
                {
                    NOTIFY_TRANSITION_STARTED("ROOT.Running.state_12.GuidanceMode.9");
                    popNullConfig();
                    myThread->unschedTm(Guidance_Timeout_radarGuided_id, this);
                    NOTIFY_STATE_EXITED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.radarGuided");
                    NOTIFY_STATE_ENTERED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.radarGuided");
                    pushNullConfig();
                    GuidanceMode_subState = radarGuided;
                    state_12_active = radarGuided;
                    //#[ state ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.radarGuided.(Entry) 
                    Az_Demand = - PropNavGain * closingVelocity * LOSRate;
                    Az_Demand = min(max((Az_Demand),Az_min),Az_max);  
                    
                    Range -= 15.0;
                    //#]
                    myThread->schedTm(10, Guidance_Timeout_radarGuided_id, this, "ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.radarGuided");
                    NOTIFY_TRANSITION_TERMINATED("ROOT.Running.state_12.GuidanceMode.9");
                    res = eventConsumed;
                }
        }
    else if(IS_EVENT_TYPE_OF(OMEventNullId))
        {
            //## transition ROOT.Running.state_12.GuidanceMode.6 
            if(Range < 200)
                {
                    NOTIFY_TRANSITION_STARTED("ROOT.Running.state_12.GuidanceMode.6");
                    popNullConfig();
                    myThread->unschedTm(Guidance_Timeout_radarGuided_id, this);
                    NOTIFY_STATE_EXITED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.radarGuided");
                    //#[ transition ROOT.Running.state_12.GuidanceMode.6 
                    Az_Fixed = Az_Demand;
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.blindRange");
                    pushNullConfig();
                    GuidanceMode_subState = blindRange;
                    state_12_active = blindRange;
                    //#[ state ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.blindRange.(Entry) 
                    Az_Demand = min(max(Az_Fixed,Az_min),Az_max);
                    Range -= 15;
                    //#]
                    myThread->schedTm(10, Guidance_Timeout_blindRange_id, this, "ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.blindRange");
                    NOTIFY_TRANSITION_TERMINATED("ROOT.Running.state_12.GuidanceMode.6");
                    res = eventConsumed;
                }
        }
    
    
    return res;
}

void Guidance::GuidanceMode_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.Running.state_12.GuidanceMode");
    state_12_subState = GuidanceMode;
    NOTIFY_TRANSITION_STARTED("ROOT.Running.state_12.GuidanceMode.0");
    NOTIFY_STATE_ENTERED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.init");
    pushNullConfig();
    GuidanceMode_subState = init;
    state_12_active = init;
    //#[ state ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.init.(Entry) 
    this->Az_Fixed = -9.81;
    DishAngle = 0.0;
    ScanningSteps = 100;
    nTicks = 0;
    this->Az_Demand = Az_Fixed;
    this->samplingInterval = 0.01; 
    AcquireTime = 0.0;
    this->Range = 1000.0;
    Az_min = 0.0;
    Az_max = 0.0;
    closingVelocity = 0.0;
    LOSRate = 0.0;
    this->PropNavGain = 1.0;
    dishAngleCommand = 0.0;
    bMissed = 0;
    bAcquired = 0;
    MissionTime = 0.0;
    
    //#]
    NOTIFY_TRANSITION_TERMINATED("ROOT.Running.state_12.GuidanceMode.0");
}

void Guidance::Running_exit() {
    switch (state_12_subState) {
        case GuidanceMode:
        {
            GuidanceMode_exit();
            break;
        };
        default:
            break;
    };
    state_12_subState = OMNonState;
    NOTIFY_STATE_EXITED("ROOT.Running.state_12");
    switch (state_13_subState) {
        case FuzeMode:
        {
            switch (FuzeMode_subState) {
                case FuzeMode_init:
                {
                    popNullConfig();
                    NOTIFY_STATE_EXITED("ROOT.Running.state_13.FuzeMode.ROOT.FuzeMode.init");
                    break;
                };
                case inert:
                {
                    popNullConfig();
                    NOTIFY_STATE_EXITED("ROOT.Running.state_13.FuzeMode.ROOT.FuzeMode.inert");
                    break;
                };
                case armed:
                {
                    popNullConfig();
                    NOTIFY_STATE_EXITED("ROOT.Running.state_13.FuzeMode.ROOT.FuzeMode.armed");
                    break;
                };
                default:
                    break;
            };
            FuzeMode_subState = OMNonState;
            NOTIFY_STATE_EXITED("ROOT.Running.state_13.FuzeMode");
            break;
        };
        default:
            break;
    };
    state_13_subState = OMNonState;
    NOTIFY_STATE_EXITED("ROOT.Running.state_13");
    NOTIFY_STATE_EXITED("ROOT.Running");
}

void Guidance::GuidanceMode_exit() {
    switch (GuidanceMode_subState) {
        case init:
        {
            popNullConfig();
            //#[ state ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.init.(Exit) 
            
            //#]
            NOTIFY_STATE_EXITED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.init");
            break;
        };
        case targetSearch:
        {
            popNullConfig();
            myThread->unschedTm(Guidance_Timeout_targetSearch_id, this);
            NOTIFY_STATE_EXITED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.targetSearch");
            break;
        };
        case targetLock:
        {
            popNullConfig();
            myThread->unschedTm(Guidance_Timeout_targetLock_id, this);
            NOTIFY_STATE_EXITED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.targetLock");
            break;
        };
        case radarGuided:
        {
            popNullConfig();
            myThread->unschedTm(Guidance_Timeout_radarGuided_id, this);
            NOTIFY_STATE_EXITED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.radarGuided");
            break;
        };
        case blindRange:
        {
            popNullConfig();
            myThread->unschedTm(Guidance_Timeout_blindRange_id, this);
            NOTIFY_STATE_EXITED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.blindRange");
            break;
        };
        case abort:
        {
            NOTIFY_STATE_EXITED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.abort");
            break;
        };
        case Done:
        {
            NOTIFY_STATE_EXITED("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.Done");
            break;
        };
        default:
            break;
    };
    GuidanceMode_subState = OMNonState;
    NOTIFY_STATE_EXITED("ROOT.Running.state_12.GuidanceMode");
}

void Guidance::state_12_entDef() {
    NOTIFY_STATE_ENTERED("ROOT.Running.state_12");
    NOTIFY_TRANSITION_STARTED("1");
    GuidanceMode_entDef();
    NOTIFY_TRANSITION_TERMINATED("1");
}



#ifdef _OMINSTRUMENT


void OMAnimatedGuidance::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("Az_Fixed", x2String(myReal->Az_Fixed));
    aomsAttributes->addAttribute("Az_Demand", x2String(myReal->Az_Demand));
    aomsAttributes->addAttribute("DishAngle", x2String(myReal->DishAngle));
    aomsAttributes->addAttribute("ScanningSteps", x2String(myReal->ScanningSteps));
    aomsAttributes->addAttribute("AcquireTime", x2String(myReal->AcquireTime));
    aomsAttributes->addAttribute("Range", x2String(myReal->Range));
    aomsAttributes->addAttribute("Az_min", x2String(myReal->Az_min));
    aomsAttributes->addAttribute("Az_max", x2String(myReal->Az_max));
    aomsAttributes->addAttribute("closingVelocity", x2String(myReal->closingVelocity));
    aomsAttributes->addAttribute("LOSRate", x2String(myReal->LOSRate));
    aomsAttributes->addAttribute("PropNavGain", x2String(myReal->PropNavGain));
    aomsAttributes->addAttribute("samplingInterval", x2String(myReal->samplingInterval));
    aomsAttributes->addAttribute("dishAngleCommand", x2String(myReal->dishAngleCommand));
    aomsAttributes->addAttribute("bMissed", x2String(myReal->bMissed));
    aomsAttributes->addAttribute("bAcquired", x2String(myReal->bAcquired));
    aomsAttributes->addAttribute("nTicks", x2String(myReal->nTicks));
    aomsAttributes->addAttribute("MissionTime", x2String(myReal->MissionTime));
}

void OMAnimatedGuidance::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("itsMyFactory", FALSE, TRUE);
    if(myReal->itsMyFactory)
        aomsRelations->ADD_ITEM(myReal->itsMyFactory);
}

void OMAnimatedGuidance::rootState_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case Guidance::Running:
        {
            Running_serializeStates(aomsState);
            break;
        };
        default:
            break;
    };
}

void OMAnimatedGuidance::Running_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running");
    state_12_serializeStates(aomsState);
    state_13_serializeStates(aomsState);
}

void OMAnimatedGuidance::state_13_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.state_13");
    switch (myReal->state_13_subState) {
        case Guidance::FuzeMode:
        {
            FuzeMode_serializeStates(aomsState);
            break;
        };
        default:
            break;
    };
}

void OMAnimatedGuidance::FuzeMode_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.state_13.FuzeMode");
    switch (myReal->FuzeMode_subState) {
        case Guidance::FuzeMode_init:
        {
            FuzeMode_init_serializeStates(aomsState);
            break;
        };
        case Guidance::inert:
        {
            inert_serializeStates(aomsState);
            break;
        };
        case Guidance::armed:
        {
            armed_serializeStates(aomsState);
            break;
        };
        default:
            break;
    };
}

void OMAnimatedGuidance::FuzeMode_init_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.state_13.FuzeMode.ROOT.FuzeMode.init");
}

void OMAnimatedGuidance::inert_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.state_13.FuzeMode.ROOT.FuzeMode.inert");
}

void OMAnimatedGuidance::armed_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.state_13.FuzeMode.ROOT.FuzeMode.armed");
}

void OMAnimatedGuidance::state_12_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.state_12");
    switch (myReal->state_12_subState) {
        case Guidance::GuidanceMode:
        {
            GuidanceMode_serializeStates(aomsState);
            break;
        };
        default:
            break;
    };
}

void OMAnimatedGuidance::GuidanceMode_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.state_12.GuidanceMode");
    switch (myReal->GuidanceMode_subState) {
        case Guidance::init:
        {
            init_serializeStates(aomsState);
            break;
        };
        case Guidance::targetSearch:
        {
            targetSearch_serializeStates(aomsState);
            break;
        };
        case Guidance::targetLock:
        {
            targetLock_serializeStates(aomsState);
            break;
        };
        case Guidance::radarGuided:
        {
            radarGuided_serializeStates(aomsState);
            break;
        };
        case Guidance::blindRange:
        {
            blindRange_serializeStates(aomsState);
            break;
        };
        case Guidance::abort:
        {
            abort_serializeStates(aomsState);
            break;
        };
        case Guidance::Done:
        {
            Done_serializeStates(aomsState);
            break;
        };
        default:
            break;
    };
}

void OMAnimatedGuidance::targetSearch_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.targetSearch");
}

void OMAnimatedGuidance::targetLock_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.targetLock");
}

void OMAnimatedGuidance::radarGuided_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.radarGuided");
}

void OMAnimatedGuidance::init_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.init");
}

void OMAnimatedGuidance::Done_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.Done");
}

void OMAnimatedGuidance::blindRange_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.blindRange");
}

void OMAnimatedGuidance::abort_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Running.state_12.GuidanceMode.ROOT.GuidanceMode.abort");
}

IMPLEMENT_REACTIVE_META(Guidance, Default, FALSE, OMAnimatedGuidance)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Guidance.cpp
*********************************************************************/

