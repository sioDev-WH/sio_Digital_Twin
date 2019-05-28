/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: SimpleGearbox
//!	Generated Date	: Wed, 11, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\SimpleGearbox.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 


#define _OMSTATECHART_ANIMATED 
//#]

#include "SimpleGearbox.h"
#include "Application.h"

//## package DiscreteTransmissionModels 


//#[ ignore 
#define DiscreteTransmissionModels_SimpleGearbox_SimpleGearbox_SERIALIZE OM_NO_OP


#define DiscreteTransmissionModels_SimpleGearbox_DC_Shift_SERIALIZE OM_NO_OP


#define DiscreteTransmissionModels_SimpleGearbox_FC_Shift_SERIALIZE OM_NO_OP


#define DiscreteTransmissionModels_SimpleGearbox_IOC_Shift_SERIALIZE OM_NO_OP


#define DiscreteTransmissionModels_SimpleGearbox_IsAny_SERIALIZE OM_NO_OP


#define DiscreteTransmissionModels_SimpleGearbox_IsFirst_SERIALIZE OM_NO_OP


#define DiscreteTransmissionModels_SimpleGearbox_IsFourth_SERIALIZE OM_NO_OP


#define DiscreteTransmissionModels_SimpleGearbox_IsInvalid_SERIALIZE OM_NO_OP


#define DiscreteTransmissionModels_SimpleGearbox_IsNone_SERIALIZE OM_NO_OP


#define DiscreteTransmissionModels_SimpleGearbox_IsReverse_SERIALIZE OM_NO_OP


#define DiscreteTransmissionModels_SimpleGearbox_IsSecond_SERIALIZE OM_NO_OP


#define DiscreteTransmissionModels_SimpleGearbox_IsThird_SERIALIZE OM_NO_OP


#define DiscreteTransmissionModels_SimpleGearbox_LRB_Shift_SERIALIZE OM_NO_OP


#define DiscreteTransmissionModels_SimpleGearbox_OB_Shift_SERIALIZE OM_NO_OP


#define DiscreteTransmissionModels_SimpleGearbox_POC_Shift_SERIALIZE OM_NO_OP


#define DiscreteTransmissionModels_SimpleGearbox_RC_Shift_SERIALIZE OM_NO_OP


#define DiscreteTransmissionModels_SimpleGearbox_TCC_Shift_SERIALIZE OM_NO_OP


#define DiscreteTransmissionModels_SimpleGearbox_handle_tick_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// SimpleGearbox.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(DiscreteTransmissionModels)
//## class SimpleGearbox 



SimpleGearbox::SimpleGearbox(OMThread*  p_thread) : DC(0) ,IOC(0) ,FC(0) ,LRB(0) ,OB(0) ,POC(0) ,RC(0) ,TCC(0) ,gear(0) ,T(0) {
    NOTIFY_REACTIVE_CONSTRUCTOR(SimpleGearbox, SimpleGearbox(), 0, DiscreteTransmissionModels_SimpleGearbox_SimpleGearbox_SERIALIZE);
    setThread(p_thread, FALSE);
    initStatechart();
}

SimpleGearbox::~SimpleGearbox() {
    NOTIFY_DESTRUCTOR(~SimpleGearbox, TRUE);
}

void SimpleGearbox::DC_Shift(const double t, long * val) {
    NOTIFY_OPERATION(DC_Shift, DC_Shift(const double ,long * ), 0, DiscreteTransmissionModels_SimpleGearbox_DC_Shift_SERIALIZE);
    //#[ operation DC_Shift(const double ,long * ) 
    DC = *val;
    //#]
}

void SimpleGearbox::FC_Shift(const double t, long * val) {
    NOTIFY_OPERATION(FC_Shift, FC_Shift(const double ,long * ), 0, DiscreteTransmissionModels_SimpleGearbox_FC_Shift_SERIALIZE);
    //#[ operation FC_Shift(const double ,long * ) 
    FC = *val;
    //#]
}

void SimpleGearbox::IOC_Shift(const double t, long * val) {
    NOTIFY_OPERATION(IOC_Shift, IOC_Shift(const double ,long * ), 0, DiscreteTransmissionModels_SimpleGearbox_IOC_Shift_SERIALIZE);
    //#[ operation IOC_Shift(const double ,long * ) 
    IOC = *val;
    //#]
}

int SimpleGearbox::IsAny() {
    NOTIFY_OPERATION(IsAny, IsAny(), 0, DiscreteTransmissionModels_SimpleGearbox_IsAny_SERIALIZE);
    //#[ operation IsAny() 
     return DC || FC || IOC || LRB || OB || POC || RC || TCC;
    //#]
}

int SimpleGearbox::IsFirst() {
    NOTIFY_OPERATION(IsFirst, IsFirst(), 0, DiscreteTransmissionModels_SimpleGearbox_IsFirst_SERIALIZE);
    //#[ operation IsFirst() 
     return !DC && FC && !IOC && !LRB && !OB && POC && !RC && !TCC;
    //#]
}

int SimpleGearbox::IsFourth() {
    NOTIFY_OPERATION(IsFourth, IsFourth(), 0, DiscreteTransmissionModels_SimpleGearbox_IsFourth_SERIALIZE);
    //#[ operation IsFourth() 
     return DC && !FC && !IOC && !LRB && OB && !POC && !RC && TCC;
    //#]
}

int SimpleGearbox::IsInvalid() {
    NOTIFY_OPERATION(IsInvalid, IsInvalid(), 0, DiscreteTransmissionModels_SimpleGearbox_IsInvalid_SERIALIZE);
    //#[ operation IsInvalid() 
      return (DC && FC) ||
             ((DC || FC) && RC) ||
             ((IOC || POC) && LRB);
    
    //#]
}

int SimpleGearbox::IsNone() {
    NOTIFY_OPERATION(IsNone, IsNone(), 0, DiscreteTransmissionModels_SimpleGearbox_IsNone_SERIALIZE);
    //#[ operation IsNone() 
     return !DC && !FC && !IOC && !LRB && !OB && !POC && !RC && !TCC;
    //#]
}

int SimpleGearbox::IsReverse() {
    NOTIFY_OPERATION(IsReverse, IsReverse(), 0, DiscreteTransmissionModels_SimpleGearbox_IsReverse_SERIALIZE);
    //#[ operation IsReverse() 
     return !DC && !FC && !IOC && LRB && !OB && !POC && RC && !TCC;
    //#]
}

int SimpleGearbox::IsSecond() {
    NOTIFY_OPERATION(IsSecond, IsSecond(), 0, DiscreteTransmissionModels_SimpleGearbox_IsSecond_SERIALIZE);
    //#[ operation IsSecond() 
      return !DC && FC && IOC && !LRB && !OB && !POC && !RC && !TCC;
    //#]
}

int SimpleGearbox::IsThird() {
    NOTIFY_OPERATION(IsThird, IsThird(), 0, DiscreteTransmissionModels_SimpleGearbox_IsThird_SERIALIZE);
    //#[ operation IsThird() 
     return DC && FC && !IOC && !LRB && !OB && !POC && !RC && TCC;
    //#]
}

void SimpleGearbox::LRB_Shift(const double t, long * val) {
    NOTIFY_OPERATION(LRB_Shift, LRB_Shift(const double ,long * ), 0, DiscreteTransmissionModels_SimpleGearbox_LRB_Shift_SERIALIZE);
    //#[ operation LRB_Shift(const double ,long * ) 
    LRB = *val;
    //#]
}

void SimpleGearbox::OB_Shift(const double t, long * val) {
    NOTIFY_OPERATION(OB_Shift, OB_Shift(const double ,long * ), 0, DiscreteTransmissionModels_SimpleGearbox_OB_Shift_SERIALIZE);
    //#[ operation OB_Shift(const double ,long * ) 
    OB = *val;
    //#]
}

void SimpleGearbox::POC_Shift(const double t, long * val) {
    NOTIFY_OPERATION(POC_Shift, POC_Shift(const double ,long * ), 0, DiscreteTransmissionModels_SimpleGearbox_POC_Shift_SERIALIZE);
    //#[ operation POC_Shift(const double ,long * ) 
    POC = *val;
    //#]
}

void SimpleGearbox::RC_Shift(const double t, long * val) {
    NOTIFY_OPERATION(RC_Shift, RC_Shift(const double ,long * ), 0, DiscreteTransmissionModels_SimpleGearbox_RC_Shift_SERIALIZE);
    //#[ operation RC_Shift(const double ,long * ) 
    RC = *val;
    //#]
}

void SimpleGearbox::TCC_Shift(const double t, long * val) {
    NOTIFY_OPERATION(TCC_Shift, TCC_Shift(const double ,long * ), 0, DiscreteTransmissionModels_SimpleGearbox_TCC_Shift_SERIALIZE);
    //#[ operation TCC_Shift(const double ,long * ) 
    TCC = *val;
    //#]
}

void SimpleGearbox::handle_tick() {
    NOTIFY_OPERATION(handle_tick, handle_tick(), 0, DiscreteTransmissionModels_SimpleGearbox_handle_tick_SERIALIZE);
    //#[ operation handle_tick() 
    receive();
    GEN(evTick);
    broadcast();
    //#]
}

long SimpleGearbox::getDC() const {
    return DC;
}

void SimpleGearbox::setDC(long  p_DC) {
    DC = p_DC;
}

long SimpleGearbox::getFC() const {
    return FC;
}

void SimpleGearbox::setFC(long  p_FC) {
    FC = p_FC;
}

long SimpleGearbox::getIOC() const {
    return IOC;
}

void SimpleGearbox::setIOC(long  p_IOC) {
    IOC = p_IOC;
}

long SimpleGearbox::getLRB() const {
    return LRB;
}

void SimpleGearbox::setLRB(long  p_LRB) {
    LRB = p_LRB;
}

long SimpleGearbox::getOB() const {
    return OB;
}

void SimpleGearbox::setOB(long  p_OB) {
    OB = p_OB;
}

long SimpleGearbox::getPOC() const {
    return POC;
}

void SimpleGearbox::setPOC(long  p_POC) {
    POC = p_POC;
}

long SimpleGearbox::getRC() const {
    return RC;
}

void SimpleGearbox::setRC(long  p_RC) {
    RC = p_RC;
}

long SimpleGearbox::getT() const {
    return T;
}

void SimpleGearbox::setT(long  p_T) {
    T = p_T;
}

long SimpleGearbox::getTCC() const {
    return TCC;
}

void SimpleGearbox::setTCC(long  p_TCC) {
    TCC = p_TCC;
}

long SimpleGearbox::getGear() const {
    return gear;
}

void SimpleGearbox::setGear(long  p_gear) {
    gear = p_gear;
}

void SimpleGearbox::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("13");
        NOTIFY_STATE_ENTERED("ROOT.Transition");
        pushNullConfig();
        rootState_subState = Transition;
        rootState_active = Transition;
        //#[ state ROOT.Transition.(Entry) 
        T = 1;
        //#]
        NOTIFY_TRANSITION_TERMINATED("13");
    }
}

int SimpleGearbox::rootState_dispatchEvent(short  id) {
    int res = eventNotConsumed;
    switch (rootState_active) {
        case Neutral:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    //## transition 0 
                    if(IsAny())
                        {
                            NOTIFY_TRANSITION_STARTED("0");
                            popNullConfig();
                            NOTIFY_STATE_EXITED("ROOT.Neutral");
                            NOTIFY_STATE_ENTERED("ROOT.Transition");
                            pushNullConfig();
                            rootState_subState = Transition;
                            rootState_active = Transition;
                            //#[ state ROOT.Transition.(Entry) 
                            T = 1;
                            //#]
                            NOTIFY_TRANSITION_TERMINATED("0");
                            res = eventConsumed;
                        }
                }
            
            break;
        };
        case First:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    //## transition 1 
                    if(!FC || !POC)
                        {
                            NOTIFY_TRANSITION_STARTED("1");
                            popNullConfig();
                            NOTIFY_STATE_EXITED("ROOT.First");
                            NOTIFY_STATE_ENTERED("ROOT.Transition");
                            pushNullConfig();
                            rootState_subState = Transition;
                            rootState_active = Transition;
                            //#[ state ROOT.Transition.(Entry) 
                            T = 1;
                            //#]
                            NOTIFY_TRANSITION_TERMINATED("1");
                            res = eventConsumed;
                        }
                }
            
            break;
        };
        case Second:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    //## transition 3 
                    if(!FC || !IOC)
                        {
                            NOTIFY_TRANSITION_STARTED("3");
                            popNullConfig();
                            NOTIFY_STATE_EXITED("ROOT.Second");
                            NOTIFY_STATE_ENTERED("ROOT.Transition");
                            pushNullConfig();
                            rootState_subState = Transition;
                            rootState_active = Transition;
                            //#[ state ROOT.Transition.(Entry) 
                            T = 1;
                            //#]
                            NOTIFY_TRANSITION_TERMINATED("3");
                            res = eventConsumed;
                        }
                }
            
            break;
        };
        case Third:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    //## transition 5 
                    if(!FC || !TCC || !DC)
                        {
                            NOTIFY_TRANSITION_STARTED("5");
                            popNullConfig();
                            NOTIFY_STATE_EXITED("ROOT.Third");
                            NOTIFY_STATE_ENTERED("ROOT.Transition");
                            pushNullConfig();
                            rootState_subState = Transition;
                            rootState_active = Transition;
                            //#[ state ROOT.Transition.(Entry) 
                            T = 1;
                            //#]
                            NOTIFY_TRANSITION_TERMINATED("5");
                            res = eventConsumed;
                        }
                }
            
            break;
        };
        case Fourth:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    //## transition 7 
                    if(!TCC || !DC || !OB )
                        {
                            NOTIFY_TRANSITION_STARTED("7");
                            popNullConfig();
                            NOTIFY_STATE_EXITED("ROOT.Fourth");
                            NOTIFY_STATE_ENTERED("ROOT.Transition");
                            pushNullConfig();
                            rootState_subState = Transition;
                            rootState_active = Transition;
                            //#[ state ROOT.Transition.(Entry) 
                            T = 1;
                            //#]
                            NOTIFY_TRANSITION_TERMINATED("7");
                            res = eventConsumed;
                        }
                }
            
            break;
        };
        case Reverse:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    //## transition 10 
                    if(!RC || !LRB)
                        {
                            NOTIFY_TRANSITION_STARTED("10");
                            popNullConfig();
                            NOTIFY_STATE_EXITED("ROOT.Reverse");
                            NOTIFY_STATE_ENTERED("ROOT.Transition");
                            pushNullConfig();
                            rootState_subState = Transition;
                            rootState_active = Transition;
                            //#[ state ROOT.Transition.(Entry) 
                            T = 1;
                            //#]
                            NOTIFY_TRANSITION_TERMINATED("10");
                            res = eventConsumed;
                        }
                }
            
            break;
        };
        case Transition:
        {
            res = Transition_takeEvent(id);
            break;
        };
        
        default:
            break;
    };
    return res;
}

void SimpleGearbox::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

OMBoolean SimpleGearbox::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}

int SimpleGearbox::Transition_takeEvent(short  id) {
    int res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(OMEventNullId))
        {
            res = TransitionTakeNull();
        }
    
    return res;
}

int SimpleGearbox::TransitionTakeNull() {
    int res = eventNotConsumed;
    //## transition 2 
    if(IsFirst())
        {
            NOTIFY_TRANSITION_STARTED("2");
            popNullConfig();
            //#[ state ROOT.Transition.(Exit) 
            T = 0;
            //#]
            NOTIFY_STATE_EXITED("ROOT.Transition");
            NOTIFY_STATE_ENTERED("ROOT.First");
            pushNullConfig();
            rootState_subState = First;
            rootState_active = First;
            //#[ state ROOT.First.(Entry) 
            gear = 1;
            //#]
            NOTIFY_TRANSITION_TERMINATED("2");
            res = eventConsumed;
        }
    else
        {
            //## transition 4 
            if(IsSecond())
                {
                    NOTIFY_TRANSITION_STARTED("4");
                    popNullConfig();
                    //#[ state ROOT.Transition.(Exit) 
                    T = 0;
                    //#]
                    NOTIFY_STATE_EXITED("ROOT.Transition");
                    NOTIFY_STATE_ENTERED("ROOT.Second");
                    pushNullConfig();
                    rootState_subState = Second;
                    rootState_active = Second;
                    //#[ state ROOT.Second.(Entry) 
                    gear = 2;
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("4");
                    res = eventConsumed;
                }
            else
                {
                    //## transition 6 
                    if(IsThird())
                        {
                            NOTIFY_TRANSITION_STARTED("6");
                            popNullConfig();
                            //#[ state ROOT.Transition.(Exit) 
                            T = 0;
                            //#]
                            NOTIFY_STATE_EXITED("ROOT.Transition");
                            NOTIFY_STATE_ENTERED("ROOT.Third");
                            pushNullConfig();
                            rootState_subState = Third;
                            rootState_active = Third;
                            //#[ state ROOT.Third.(Entry) 
                            gear = 3;
                            //#]
                            NOTIFY_TRANSITION_TERMINATED("6");
                            res = eventConsumed;
                        }
                    else
                        {
                            //## transition 8 
                            if(IsFourth())
                                {
                                    NOTIFY_TRANSITION_STARTED("8");
                                    popNullConfig();
                                    //#[ state ROOT.Transition.(Exit) 
                                    T = 0;
                                    //#]
                                    NOTIFY_STATE_EXITED("ROOT.Transition");
                                    NOTIFY_STATE_ENTERED("ROOT.Fourth");
                                    pushNullConfig();
                                    rootState_subState = Fourth;
                                    rootState_active = Fourth;
                                    //#[ state ROOT.Fourth.(Entry) 
                                    gear = 4;
                                    //#]
                                    NOTIFY_TRANSITION_TERMINATED("8");
                                    res = eventConsumed;
                                }
                            else
                                {
                                    //## transition 9 
                                    if(IsNone())
                                        {
                                            NOTIFY_TRANSITION_STARTED("9");
                                            popNullConfig();
                                            //#[ state ROOT.Transition.(Exit) 
                                            T = 0;
                                            //#]
                                            NOTIFY_STATE_EXITED("ROOT.Transition");
                                            NOTIFY_STATE_ENTERED("ROOT.Neutral");
                                            pushNullConfig();
                                            rootState_subState = Neutral;
                                            rootState_active = Neutral;
                                            //#[ state ROOT.Neutral.(Entry) 
                                            gear = 0;
                                            //#]
                                            NOTIFY_TRANSITION_TERMINATED("9");
                                            res = eventConsumed;
                                        }
                                    else
                                        {
                                            //## transition 11 
                                            if(IsReverse())
                                                {
                                                    NOTIFY_TRANSITION_STARTED("11");
                                                    popNullConfig();
                                                    //#[ state ROOT.Transition.(Exit) 
                                                    T = 0;
                                                    //#]
                                                    NOTIFY_STATE_EXITED("ROOT.Transition");
                                                    NOTIFY_STATE_ENTERED("ROOT.Reverse");
                                                    pushNullConfig();
                                                    rootState_subState = Reverse;
                                                    rootState_active = Reverse;
                                                    //#[ state ROOT.Reverse.(Entry) 
                                                    gear = -1;
                                                    //#]
                                                    NOTIFY_TRANSITION_TERMINATED("11");
                                                    res = eventConsumed;
                                                }
                                            else
                                                {
                                                    //## transition 12 
                                                    if(IsInvalid())
                                                        {
                                                            NOTIFY_TRANSITION_STARTED("12");
                                                            popNullConfig();
                                                            //#[ state ROOT.Transition.(Exit) 
                                                            T = 0;
                                                            //#]
                                                            NOTIFY_STATE_EXITED("ROOT.Transition");
                                                            NOTIFY_STATE_ENTERED("ROOT.Invalid");
                                                            rootState_subState = Invalid;
                                                            rootState_active = Invalid;
                                                            //#[ state ROOT.Invalid.(Entry) 
                                                            gear = -10;
                                                            //#]
                                                            NOTIFY_TRANSITION_TERMINATED("12");
                                                            res = eventConsumed;
                                                        }
                                                }
                                        }
                                }
                        }
                }
        }
    return res;
}

void SimpleGearbox::rootState_exit() {
    switch (rootState_subState) {
        case Neutral:
        {
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.Neutral");
            break;
        };
        case First:
        {
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.First");
            break;
        };
        case Second:
        {
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.Second");
            break;
        };
        case Third:
        {
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.Third");
            break;
        };
        case Fourth:
        {
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.Fourth");
            break;
        };
        case Reverse:
        {
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.Reverse");
            break;
        };
        case Transition:
        {
            popNullConfig();
            //#[ state ROOT.Transition.(Exit) 
            T = 0;
            //#]
            NOTIFY_STATE_EXITED("ROOT.Transition");
            break;
        };
        case Invalid:
        {
            NOTIFY_STATE_EXITED("ROOT.Invalid");
            break;
        };
        default:
            break;
    };
    rootState_subState = OMNonState;
    NOTIFY_STATE_EXITED("ROOT");
}



#ifdef _OMINSTRUMENT


void OMAnimatedSimpleGearbox::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedSimpleGearbox::rootState_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case SimpleGearbox::Neutral:
        {
            Neutral_serializeStates(aomsState);
            break;
        };
        case SimpleGearbox::First:
        {
            First_serializeStates(aomsState);
            break;
        };
        case SimpleGearbox::Second:
        {
            Second_serializeStates(aomsState);
            break;
        };
        case SimpleGearbox::Third:
        {
            Third_serializeStates(aomsState);
            break;
        };
        case SimpleGearbox::Fourth:
        {
            Fourth_serializeStates(aomsState);
            break;
        };
        case SimpleGearbox::Reverse:
        {
            Reverse_serializeStates(aomsState);
            break;
        };
        case SimpleGearbox::Transition:
        {
            Transition_serializeStates(aomsState);
            break;
        };
        case SimpleGearbox::Invalid:
        {
            Invalid_serializeStates(aomsState);
            break;
        };
        default:
            break;
    };
}

void OMAnimatedSimpleGearbox::Transition_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Transition");
}

void OMAnimatedSimpleGearbox::Third_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Third");
}

void OMAnimatedSimpleGearbox::Second_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Second");
}

void OMAnimatedSimpleGearbox::Reverse_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Reverse");
}

void OMAnimatedSimpleGearbox::Neutral_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Neutral");
}

void OMAnimatedSimpleGearbox::Invalid_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Invalid");
}

void OMAnimatedSimpleGearbox::Fourth_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Fourth");
}

void OMAnimatedSimpleGearbox::First_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.First");
}

IMPLEMENT_REACTIVE_META(SimpleGearbox, DiscreteTransmissionModels, FALSE, OMAnimatedSimpleGearbox)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\SimpleGearbox.cpp
*********************************************************************/

