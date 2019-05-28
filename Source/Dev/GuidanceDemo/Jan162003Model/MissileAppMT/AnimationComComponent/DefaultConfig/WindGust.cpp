/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: WindGust
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\WindGust.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 


#define _OMSTATECHART_ANIMATED 
//#]

#include "WindGust.h"
#include <stdafx.h>

//## package LibraryPkg::AvionicsPkg 


//#[ ignore 
#define LibraryPkg_AvionicsPkg_WindGust_WindGust_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_WindGust_broadcast_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_WindGust_clean_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_WindGust_handle_tick_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_WindGust_init_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_WindGust_receive_SERIALIZE OM_NO_OP


#define LibraryPkg_AvionicsPkg_WindGust_update_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// WindGust.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(LibraryPkg::AvionicsPkg)
//## class WindGust 



WindGust::WindGust(OMThread*  p_thread) {
    NOTIFY_REACTIVE_CONSTRUCTOR(WindGust, WindGust(), 0, LibraryPkg_AvionicsPkg_WindGust_WindGust_SERIALIZE);
    setThread(p_thread, FALSE);
    initStatechart();
    //#[ operation WindGust() 
    init();
    startBehavior();
    //#]
}

WindGust::~WindGust() {
    NOTIFY_DESTRUCTOR(~WindGust, TRUE);
    //#[ operation ~WindGust() 
    clean();
    //#]
}

void WindGust::broadcast() {
    NOTIFY_OPERATION(broadcast, broadcast(), 0, LibraryPkg_AvionicsPkg_WindGust_broadcast_SERIALIZE);
    //#[ operation broadcast() 
    //#]
}

void WindGust::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, LibraryPkg_AvionicsPkg_WindGust_clean_SERIALIZE);
    //#[ operation clean() 
    
    if(aircraftVelocity) 	delete[] aircraftVelocity;
    if(amplitude) 	delete[] amplitude;
    if(length)delete[] length;
    if(velocity)delete[] velocity;
    if(x)delete[] x;
    
    //#]
}

void WindGust::handle_tick() {
    NOTIFY_OPERATION(handle_tick, handle_tick(), 0, LibraryPkg_AvionicsPkg_WindGust_handle_tick_SERIALIZE);
    //#[ operation handle_tick() 
    
    receive();
    GEN(evGustWindTick);
    broadcast();
    
    //#]
}

void WindGust::init() {
    NOTIFY_OPERATION(init, init(), 0, LibraryPkg_AvionicsPkg_WindGust_init_SERIALIZE);
    //#[ operation init() 
    int i;
    period =    1.0;
    double Ts = period/1000.0; 
    
    size = 3;
    
    aircraftVelocity = new double[size];
    amplitude = new double[size];
    length = new double[size]; 
    velocity = new double[size];
    x = new double[size]; // Relative position
    
    for(i=0;i<size;i++) aircraftVelocity[i] = 0.0;   
    for(i=0;i<size;i++) amplitude[i] = 0.0;
    for(i=0;i<size;i++) length[i] = 0.0; 
    for(i=0;i<size;i++) velocity[i] = 0.0;
    for(i=0;i<size;i++) x[i] = 0.0;
    
    //#]
}

void WindGust::receive() {
    NOTIFY_OPERATION(receive, receive(), 0, LibraryPkg_AvionicsPkg_WindGust_receive_SERIALIZE);
    //#[ operation receive() 
    //#]
}

void WindGust::update() {
    NOTIFY_OPERATION(update, update(), 0, LibraryPkg_AvionicsPkg_WindGust_update_SERIALIZE);
    //#[ operation update() 
    int i;
    double Ts = period/1000.0;
    int bExit = 1;
    for(i=0;i<size;i++){
       x[i] = x[i] + Ts* aircraftVelocity[i];
       velocity[i] = 0.5 * aircraftVelocity[i] *(1.0 -cos(PI*x[i]/length[i]));
       if(x[i]<length[i])bExit = 0;
    }
    if(bExit) GEN(evExit); 
    //#]
}

double* WindGust::getAircraftVelocity() const {
    return aircraftVelocity;
}

void WindGust::setAircraftVelocity(double*  p_aircraftVelocity) {
    aircraftVelocity = p_aircraftVelocity;
}

double* WindGust::getAmplitude() const {
    return amplitude;
}

void WindGust::setAmplitude(double*  p_amplitude) {
    amplitude = p_amplitude;
}

double* WindGust::getLength() const {
    return length;
}

void WindGust::setLength(double*  p_length) {
    length = p_length;
}

double WindGust::getPeriod() const {
    return period;
}

void WindGust::setPeriod(double  p_period) {
    period = p_period;
}

int WindGust::getSize() const {
    return size;
}

void WindGust::setSize(int  p_size) {
    size = p_size;
}

double* WindGust::getVelocity() const {
    return velocity;
}

void WindGust::setVelocity(double*  p_velocity) {
    velocity = p_velocity;
}

double* WindGust::getX() const {
    return x;
}

void WindGust::setX(double*  p_x) {
    x = p_x;
}

void WindGust::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("3");
        NOTIFY_STATE_ENTERED("ROOT.Wait");
        rootState_subState = Wait;
        rootState_active = Wait;
        //#[ state ROOT.Wait.(Entry) 
        int i;
        for(i=0;i<size;i++) x[i] = 0.0;
        //#]
        NOTIFY_TRANSITION_TERMINATED("3");
    }
}

int WindGust::rootState_dispatchEvent(short  id) {
    int res = eventNotConsumed;
    switch (rootState_active) {
        case Wait:
        {
            if(IS_EVENT_TYPE_OF(evEnter_AvionicsPkg_LibraryPkg_id))
                {
                    NOTIFY_TRANSITION_STARTED("0");
                    NOTIFY_STATE_EXITED("ROOT.Wait");
                    NOTIFY_STATE_ENTERED("ROOT.Run");
                    rootState_subState = Run;
                    rootState_active = Run;
                    //#[ state ROOT.Run.(Entry) 
                    update();
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("0");
                    res = eventConsumed;
                }
            
            break;
        };
        case Run:
        {
            if(IS_EVENT_TYPE_OF(evExit_AvionicsPkg_LibraryPkg_id))
                {
                    NOTIFY_TRANSITION_STARTED("1");
                    NOTIFY_STATE_EXITED("ROOT.Run");
                    NOTIFY_STATE_ENTERED("ROOT.Wait");
                    rootState_subState = Wait;
                    rootState_active = Wait;
                    //#[ state ROOT.Wait.(Entry) 
                    int i;
                    for(i=0;i<size;i++) x[i] = 0.0;
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("1");
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(evGustWindTick_AvionicsPkg_LibraryPkg_id))
                {
                    NOTIFY_TRANSITION_STARTED("2");
                    NOTIFY_STATE_EXITED("ROOT.Run");
                    NOTIFY_STATE_ENTERED("ROOT.Run");
                    rootState_subState = Run;
                    rootState_active = Run;
                    //#[ state ROOT.Run.(Entry) 
                    update();
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("2");
                    res = eventConsumed;
                }
            
            break;
        };
        default:
            break;
    };
    return res;
}

void WindGust::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

OMBoolean WindGust::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



#ifdef _OMINSTRUMENT


void OMAnimatedWindGust::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("amplitude", x2String(myReal->amplitude));
    aomsAttributes->addAttribute("aircraftVelocity", x2String(myReal->aircraftVelocity));
    aomsAttributes->addAttribute("velocity", x2String(myReal->velocity));
    aomsAttributes->addAttribute("size", x2String(myReal->size));
    aomsAttributes->addAttribute("length", x2String(myReal->length));
    aomsAttributes->addAttribute("x", x2String(myReal->x));
    aomsAttributes->addAttribute("period", x2String(myReal->period));
}

void OMAnimatedWindGust::rootState_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case WindGust::Wait:
        {
            Wait_serializeStates(aomsState);
            break;
        };
        case WindGust::Run:
        {
            Run_serializeStates(aomsState);
            break;
        };
        default:
            break;
    };
}

void OMAnimatedWindGust::Wait_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Wait");
}

void OMAnimatedWindGust::Run_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Run");
}

IMPLEMENT_REACTIVE_META(WindGust, LibraryPkg_AvionicsPkg, FALSE, OMAnimatedWindGust)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\WindGust.cpp
*********************************************************************/

