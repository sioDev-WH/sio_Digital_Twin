/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Driver
//!	Generated Date	: Sun, 16, Feb 2003  
	File Path	: AnimationComponent\DefaultConfig\Driver.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 


#define _OMSTATECHART_ANIMATED 
//#]

#include "Driver.h"
#include <math.h>
#include "EventBroadcast.h"

//## package UI 


//#[ ignore 
#define UI_Driver_Driver_SERIALIZE OM_NO_OP


#define UI_Driver_clean_SERIALIZE OM_NO_OP


#define UI_Driver_fast_SERIALIZE OM_NO_OP


#define UI_Driver_handle_tick_SERIALIZE OM_NO_OP


#define UI_Driver_init_SERIALIZE OM_NO_OP


#define UI_Driver_shiftForward_SERIALIZE OM_NO_OP


#define UI_Driver_slow_SERIALIZE OM_NO_OP


#define UI_Driver_updateActionTime_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// Driver.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(UI)
//## class Driver 



Driver::Driver(OMThread*  p_thread) : shiftLever(NULL) ,accelerator(NULL) ,brakes(NULL) ,actionTime(0.0) ,currentTime(0.0) {
    NOTIFY_REACTIVE_CONSTRUCTOR(Driver, Driver(), 0, UI_Driver_Driver_SERIALIZE);
    setThread(p_thread, FALSE);
    initStatechart();
    //#[ operation Driver() 
    //#]
}

Driver::~Driver() {
    NOTIFY_DESTRUCTOR(~Driver, TRUE);
    //#[ operation ~Driver() 
    clean();
    //#]
}

void Driver::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, UI_Driver_clean_SERIALIZE);
    //#[ operation clean() 
    if (accelerator)
    {
    	accelerator->Release();
    	accelerator = NULL;
    }
    
    if (brakes)
    {
    	brakes->Release();
    	brakes = NULL;
    }
    
    if (shiftLever)
    {
    	shiftLever->Release();
    	shiftLever = NULL;
    }
    //#]
}

void Driver::fast() {
    NOTIFY_OPERATION(fast, fast(), 0, UI_Driver_fast_SERIALIZE);
    //#[ operation fast() 
     // release brakes
    ATLTRACE("\nDriver::fast()");
    
    brakeVal = 0.0;
    brakes->gen(&brakeVal);
    
    // apply acceleration
    acceleratorVal = 50 + 30 * (0.5 - ((double)rand())/RAND_MAX);
    accelerator->gen(&acceleratorVal); 
    
    updateActionTime();
    //#]
}

void Driver::handle_tick() {
    NOTIFY_OPERATION(handle_tick, handle_tick(), 0, UI_Driver_handle_tick_SERIALIZE);
    //#[ operation handle_tick() 
    
    evDriverTick ev;
    takeTrigger(&ev);
    //GEN(evDriverTick);
    //#]
}

void Driver::init() {
    NOTIFY_OPERATION(init, init(), 0, UI_Driver_init_SERIALIZE);
    //#[ operation init() 
    
    accelerator = new Port_Double();
    shiftLever = new Port_Int();
    brakes = new Port_Double();
    
    currentTime = getTime();
    actionTime = currentTime + 4.0 * ((double)rand())/RAND_MAX;
    //#]
}

void Driver::shiftForward() {
    NOTIFY_OPERATION(shiftForward, shiftForward(), 0, UI_Driver_shiftForward_SERIALIZE);
    //#[ operation shiftForward() 
    ATLTRACE("\nDriver::shiftForward()");
    
    brakeVal = 20.0;
    brakes->gen(&brakeVal);
    
    shiftVal = 1;
    shiftLever->gen(&shiftVal);
    
    updateActionTime();
    //#]
}

void Driver::slow() {
    NOTIFY_OPERATION(slow, slow(), 0, UI_Driver_slow_SERIALIZE);
    //#[ operation slow() 
    // release accelerator
    ATLTRACE("\nDriver::slow()");
    
    acceleratorVal  = 0.0; 
    accelerator->gen(&acceleratorVal);  
    
    // apply brakes
    brakeVal = 60 + 10 * (0.5 - ((double)rand())/RAND_MAX); 
    brakes->gen(&brakeVal);
    
    updateActionTime();
    //#]
}

void Driver::updateActionTime() {
    NOTIFY_OPERATION(updateActionTime, updateActionTime(), 0, UI_Driver_updateActionTime_SERIALIZE);
    //#[ operation updateActionTime() 
    actionTime = currentTime + 5.0 + 5.0 * ((double)rand())/RAND_MAX;
    
    //#]
}

double Driver::getAcceleratorVal() const {
    return acceleratorVal;
}

void Driver::setAcceleratorVal(double  p_acceleratorVal) {
    acceleratorVal = p_acceleratorVal;
}

double Driver::getBrakeVal() const {
    return brakeVal;
}

void Driver::setBrakeVal(double  p_brakeVal) {
    brakeVal = p_brakeVal;
}

long Driver::getShiftVal() const {
    return shiftVal;
}

void Driver::setShiftVal(long  p_shiftVal) {
    shiftVal = p_shiftVal;
}

void Driver::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        NOTIFY_STATE_ENTERED("ROOT.Init");
        pushNullConfig();
        rootState_subState = Init;
        rootState_active = Init;
        //#[ state ROOT.Init.(Entry) 
        init();
        //#]
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

int Driver::rootState_dispatchEvent(short  id) {
    int res = eventNotConsumed;
    switch (rootState_active) {
        case Init:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    NOTIFY_TRANSITION_STARTED("1");
                    popNullConfig();
                    NOTIFY_STATE_EXITED("ROOT.Init");
                    //#[ transition 1 
                    shiftForward();
                    //#]
                    NOTIFY_STATE_ENTERED("ROOT.ShiftForward");
                    pushNullConfig();
                    rootState_subState = ShiftForward;
                    rootState_active = ShiftForward;
                    //#[ state ROOT.ShiftForward.(Entry) 
                    currentTime = getTime();
                    
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("1");
                    res = eventConsumed;
                }
            
            break;
        };
        case ShiftForward:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    //## transition 3 
                    if(currentTime > actionTime)
                        {
                            NOTIFY_TRANSITION_STARTED("3");
                            popNullConfig();
                            NOTIFY_STATE_EXITED("ROOT.ShiftForward");
                            //#[ transition 3 
                            fast();
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.Accelerate");
                            pushNullConfig();
                            rootState_subState = Accelerate;
                            rootState_active = Accelerate;
                            //#[ state ROOT.Accelerate.(Entry) 
                            currentTime = getTime();
                            
                            //#]
                            NOTIFY_TRANSITION_TERMINATED("3");
                            res = eventConsumed;
                        }
                }
            else if(IS_EVENT_TYPE_OF(evDriverTick_UI_id))
                {
                    NOTIFY_TRANSITION_STARTED("7");
                    popNullConfig();
                    NOTIFY_STATE_EXITED("ROOT.ShiftForward");
                    NOTIFY_STATE_ENTERED("ROOT.ShiftForward");
                    pushNullConfig();
                    rootState_subState = ShiftForward;
                    rootState_active = ShiftForward;
                    //#[ state ROOT.ShiftForward.(Entry) 
                    currentTime = getTime();
                    
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("7");
                    res = eventConsumed;
                }
            
            break;
        };
        case Accelerate:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    //## transition 4 
                    if(currentTime > actionTime)
                        {
                            NOTIFY_TRANSITION_STARTED("4");
                            popNullConfig();
                            NOTIFY_STATE_EXITED("ROOT.Accelerate");
                            //#[ transition 4 
                            slow();
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.Brake");
                            pushNullConfig();
                            rootState_subState = Brake;
                            rootState_active = Brake;
                            //#[ state ROOT.Brake.(Entry) 
                            currentTime = getTime();
                            //#]
                            NOTIFY_TRANSITION_TERMINATED("4");
                            res = eventConsumed;
                        }
                }
            else if(IS_EVENT_TYPE_OF(evDriverTick_UI_id))
                {
                    NOTIFY_TRANSITION_STARTED("2");
                    popNullConfig();
                    NOTIFY_STATE_EXITED("ROOT.Accelerate");
                    NOTIFY_STATE_ENTERED("ROOT.Accelerate");
                    pushNullConfig();
                    rootState_subState = Accelerate;
                    rootState_active = Accelerate;
                    //#[ state ROOT.Accelerate.(Entry) 
                    currentTime = getTime();
                    
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("2");
                    res = eventConsumed;
                }
            
            break;
        };
        case Brake:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    //## transition 6 
                    if(currentTime > actionTime)
                        {
                            NOTIFY_TRANSITION_STARTED("6");
                            popNullConfig();
                            NOTIFY_STATE_EXITED("ROOT.Brake");
                            //#[ transition 6 
                            fast();
                            //#]
                            NOTIFY_STATE_ENTERED("ROOT.Accelerate");
                            pushNullConfig();
                            rootState_subState = Accelerate;
                            rootState_active = Accelerate;
                            //#[ state ROOT.Accelerate.(Entry) 
                            currentTime = getTime();
                            
                            //#]
                            NOTIFY_TRANSITION_TERMINATED("6");
                            res = eventConsumed;
                        }
                }
            else if(IS_EVENT_TYPE_OF(evDriverTick_UI_id))
                {
                    NOTIFY_TRANSITION_STARTED("5");
                    popNullConfig();
                    NOTIFY_STATE_EXITED("ROOT.Brake");
                    NOTIFY_STATE_ENTERED("ROOT.Brake");
                    pushNullConfig();
                    rootState_subState = Brake;
                    rootState_active = Brake;
                    //#[ state ROOT.Brake.(Entry) 
                    currentTime = getTime();
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("5");
                    res = eventConsumed;
                }
            
            break;
        };
        default:
            break;
    };
    return res;
}

void Driver::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

OMBoolean Driver::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}

void Driver::rootState_exit() {
    switch (rootState_subState) {
        case Init:
        {
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.Init");
            break;
        };
        case ShiftForward:
        {
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.ShiftForward");
            break;
        };
        case Accelerate:
        {
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.Accelerate");
            break;
        };
        case Brake:
        {
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.Brake");
            break;
        };
        default:
            break;
    };
    rootState_subState = OMNonState;
    NOTIFY_STATE_EXITED("ROOT");
}



#ifdef _OMINSTRUMENT


void OMAnimatedDriver::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedDriver::rootState_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case Driver::Init:
        {
            Init_serializeStates(aomsState);
            break;
        };
        case Driver::ShiftForward:
        {
            ShiftForward_serializeStates(aomsState);
            break;
        };
        case Driver::Accelerate:
        {
            Accelerate_serializeStates(aomsState);
            break;
        };
        case Driver::Brake:
        {
            Brake_serializeStates(aomsState);
            break;
        };
        default:
            break;
    };
}

void OMAnimatedDriver::ShiftForward_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.ShiftForward");
}

void OMAnimatedDriver::Init_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Init");
}

void OMAnimatedDriver::Brake_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Brake");
}

void OMAnimatedDriver::Accelerate_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Accelerate");
}

IMPLEMENT_REACTIVE_META(Driver, UI, FALSE, OMAnimatedDriver)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Driver.cpp
*********************************************************************/

