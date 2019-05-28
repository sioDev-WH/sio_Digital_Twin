/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: theSimpleApp
//!	Generated Date	: Wed, 11, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\theSimpleApp.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 


#define _OMSTATECHART_ANIMATED 
//#]

#include "theSimpleApp.h"
#include "Application.h"
#include "SimpleApp.h"
#include "initguid.h"

//## package AppSimple 


//#[ ignore 
#define AppSimple_theSimpleApp_theSimpleApp_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// theSimpleApp.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(AppSimple)
//## class theSimpleApp 



theSimpleApp::theSimpleApp(OMThread*  p_thread) : t(0.0) {
    NOTIFY_REACTIVE_CONSTRUCTOR(theSimpleApp, theSimpleApp(), 0, AppSimple_theSimpleApp_theSimpleApp_SERIALIZE);
    setThread(p_thread, FALSE);
    itsApp = NULL;
    initStatechart();
    //#[ operation theSimpleApp() 
    t = 0.0;
    startBehavior();     
     
    
    //#]
}

theSimpleApp::~theSimpleApp() {
    NOTIFY_DESTRUCTOR(~theSimpleApp, TRUE);
    //#[ operation ~theSimpleApp() 
        if(itsApp)
        { 
            delete  itsApp;
            itsApp = NULL; 
        }
    
    //#]
    cleanUpRelations();
}

double theSimpleApp::getT() const {
    return t;
}

void theSimpleApp::setT(double  p_t) {
    t = p_t;
}

SimpleApp* theSimpleApp::getItsApp() const {
    return itsApp;
}

void theSimpleApp::setItsApp(SimpleApp*  p_SimpleApp) {
    itsApp = p_SimpleApp;
    if(p_SimpleApp != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsApp", p_SimpleApp, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsApp");
        }
}

void theSimpleApp::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("1");
        NOTIFY_STATE_ENTERED("ROOT.init");
        rootState_subState = init;
        rootState_active = init;
        //#[ state ROOT.init.(Entry) 
        t = 0.0;
        itsApp = new SimpleApp();   
        GEN(evTick);
        //#]
        NOTIFY_TRANSITION_TERMINATED("1");
    }
}

int theSimpleApp::rootState_dispatchEvent(short  id) {
    int res = eventNotConsumed;
    switch (rootState_active) {
        case init:
        {
            if(IS_EVENT_TYPE_OF(evTick_Application_id))
                {
                    NOTIFY_TRANSITION_STARTED("0");
                    NOTIFY_STATE_EXITED("ROOT.init");
                    NOTIFY_STATE_ENTERED("ROOT.run");
                    rootState_subState = run;
                    rootState_active = run;
                    //#[ state ROOT.run.(Entry) 
                    itsApp->setTime(t);
                    itsApp->handle_tick();  
                    t += 0.001;
                    GEN(evTick);
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("0");
                    res = eventConsumed;
                }
            
            break;
        };
        case run:
        {
            if(IS_EVENT_TYPE_OF(evTick_Application_id))
                {
                    //## transition 4 
                    if(t > 600.0)
                        {
                            NOTIFY_TRANSITION_STARTED("2");
                            NOTIFY_TRANSITION_STARTED("4");
                            NOTIFY_STATE_EXITED("ROOT.run");
                            NOTIFY_STATE_ENTERED("ROOT.done");
                            rootState_subState = done;
                            rootState_active = done;
                            //#[ state ROOT.done.(Entry) 
                            if (itsApp)
                            {
                              //delete itsApp;
                              itsApp = NULL;
                            }
                            //#]
                            NOTIFY_TRANSITION_TERMINATED("4");
                            NOTIFY_TRANSITION_TERMINATED("2");
                            res = eventConsumed;
                        }
                    else
                        {
                            NOTIFY_TRANSITION_STARTED("2");
                            NOTIFY_TRANSITION_STARTED("3");
                            NOTIFY_STATE_EXITED("ROOT.run");
                            NOTIFY_STATE_ENTERED("ROOT.wait");
                            rootState_subState = wait;
                            rootState_active = wait;
                            //#[ state ROOT.wait.(Entry) 
                            GEN(evTick);
                            //#]
                            NOTIFY_TRANSITION_TERMINATED("3");
                            NOTIFY_TRANSITION_TERMINATED("2");
                            res = eventConsumed;
                        }
                }
            
            break;
        };
        case wait:
        {
            if(IS_EVENT_TYPE_OF(evTick_Application_id))
                {
                    NOTIFY_TRANSITION_STARTED("5");
                    NOTIFY_STATE_EXITED("ROOT.wait");
                    NOTIFY_STATE_ENTERED("ROOT.run");
                    rootState_subState = run;
                    rootState_active = run;
                    //#[ state ROOT.run.(Entry) 
                    itsApp->setTime(t);
                    itsApp->handle_tick();  
                    t += 0.001;
                    GEN(evTick);
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

void theSimpleApp::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void theSimpleApp::cleanUpRelations() {
    if(itsApp != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsApp");
            itsApp = NULL;
        }
}

OMBoolean theSimpleApp::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}

void theSimpleApp::rootState_exit() {
    switch (rootState_subState) {
        case init:
        {
            NOTIFY_STATE_EXITED("ROOT.init");
            break;
        };
        case run:
        {
            NOTIFY_STATE_EXITED("ROOT.run");
            break;
        };
        case done:
        {
            NOTIFY_STATE_EXITED("ROOT.done");
            break;
        };
        case wait:
        {
            NOTIFY_STATE_EXITED("ROOT.wait");
            break;
        };
        default:
            break;
    };
    rootState_subState = OMNonState;
    NOTIFY_STATE_EXITED("ROOT");
}



#ifdef _OMINSTRUMENT


void OMAnimatedtheSimpleApp::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedtheSimpleApp::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("itsApp", FALSE, TRUE);
    if(myReal->itsApp)
        aomsRelations->ADD_ITEM(myReal->itsApp);
}

void OMAnimatedtheSimpleApp::rootState_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case theSimpleApp::init:
        {
            init_serializeStates(aomsState);
            break;
        };
        case theSimpleApp::run:
        {
            run_serializeStates(aomsState);
            break;
        };
        case theSimpleApp::done:
        {
            done_serializeStates(aomsState);
            break;
        };
        case theSimpleApp::wait:
        {
            wait_serializeStates(aomsState);
            break;
        };
        default:
            break;
    };
}

void OMAnimatedtheSimpleApp::wait_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.wait");
}

void OMAnimatedtheSimpleApp::run_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.run");
}

void OMAnimatedtheSimpleApp::init_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.init");
}

void OMAnimatedtheSimpleApp::done_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.done");
}

IMPLEMENT_REACTIVE_META(theSimpleApp, AppSimple, FALSE, OMAnimatedtheSimpleApp)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\theSimpleApp.cpp
*********************************************************************/

