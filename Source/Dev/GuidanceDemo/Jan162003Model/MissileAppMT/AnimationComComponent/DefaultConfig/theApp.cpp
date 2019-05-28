/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: theApp
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\theApp.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 


#define _OMSTATECHART_ANIMATED 
//#]

#include "theApp.h"
#include "App1_app.h"
#include "math.h"
#include "stdafx.h"
#include "initguid.h"
#include "IsDaeCOSolver.h"
#include "IsDaeCOSolver_i.c"
#include "App1_task_0010ms.h"
#include "GuidanceLogic.h"

//## package Application 


//#[ ignore 
#define Application_theApp_theApp_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// theApp.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(Application)
//## class theApp 



theApp::theApp(OMThread*  p_thread) : t(0.0) {
    NOTIFY_REACTIVE_CONSTRUCTOR(theApp, theApp(), 0, Application_theApp_theApp_SERIALIZE);
    setThread(p_thread, FALSE);
    itsApp = NULL;
    initStatechart();
    //#[ operation theApp() 
    //#]
}

theApp::~theApp() {
    NOTIFY_DESTRUCTOR(~theApp, TRUE);
    //#[ operation ~theApp() 
    //#]
    cleanUpRelations();
}

long theApp::getGuidanceMode() const {
    return guidanceMode;
}

void theApp::setGuidanceMode(long  p_guidanceMode) {
    guidanceMode = p_guidanceMode;
}

double theApp::getT() const {
    return t;
}

void theApp::setT(double  p_t) {
    t = p_t;
}

App1_app* theApp::getItsApp() const {
    return itsApp;
}

void theApp::setItsApp(App1_app*  p_App1_app) {
    itsApp = p_App1_app;
    if(p_App1_app != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsApp", p_App1_app, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsApp");
        }
}

void theApp::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        NOTIFY_STATE_ENTERED("ROOT.Init");
        pushNullConfig();
        rootState_subState = Init;
        rootState_active = Init;
        //#[ state ROOT.Init.(Entry) 
        t = 0.0;
        itsApp = new App1_app();
        
        
        //#]
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

int theApp::rootState_dispatchEvent(short  id) {
    int res = eventNotConsumed;
    switch (rootState_active) {
        case Init:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    NOTIFY_TRANSITION_STARTED("2");
                    popNullConfig();
                    NOTIFY_STATE_EXITED("ROOT.Init");
                    NOTIFY_STATE_ENTERED("ROOT.Run");
                    rootState_subState = Run;
                    rootState_active = Run;
                    //#[ state ROOT.Run.(Entry) 
                    itsApp->handle_tick(t);
                    itsApp->task_0010ms->itsGuidanceLogic->get_guidanceMode(0.0, &guidanceMode);
                    t += 0.001;
                    GEN(evTick);
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("2");
                    res = eventConsumed;
                }
            
            break;
        };
        case Run:
        {
            if(IS_EVENT_TYPE_OF(evTick_Application_id))
                {
                    //## transition 3 
                    if((t>=5) || (guidanceMode==5))
                        {
                            NOTIFY_TRANSITION_STARTED("1");
                            NOTIFY_TRANSITION_STARTED("3");
                            NOTIFY_STATE_EXITED("ROOT.Run");
                            NOTIFY_STATE_ENTERED("ROOT.Done");
                            pushNullConfig();
                            rootState_subState = Done;
                            rootState_active = Done;
                            //#[ state ROOT.Done.(Entry) 
                            if(itsApp)
                            { 
                            	delete itsApp;
                            	itsApp = NULL;
                            }
                            
                            //#]
                            NOTIFY_TRANSITION_TERMINATED("3");
                            NOTIFY_TRANSITION_TERMINATED("1");
                            res = eventConsumed;
                        }
                    else
                        {
                            NOTIFY_TRANSITION_STARTED("1");
                            NOTIFY_TRANSITION_STARTED("4");
                            NOTIFY_STATE_EXITED("ROOT.Run");
                            NOTIFY_STATE_ENTERED("ROOT.Run");
                            rootState_subState = Run;
                            rootState_active = Run;
                            //#[ state ROOT.Run.(Entry) 
                            itsApp->handle_tick(t);
                            itsApp->task_0010ms->itsGuidanceLogic->get_guidanceMode(0.0, &guidanceMode);
                            t += 0.001;
                            GEN(evTick);
                            //#]
                            NOTIFY_TRANSITION_TERMINATED("4");
                            NOTIFY_TRANSITION_TERMINATED("1");
                            res = eventConsumed;
                        }
                }
            
            break;
        };
        case Done:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    NOTIFY_TRANSITION_STARTED("5");
                    popNullConfig();
                    NOTIFY_STATE_EXITED("ROOT.Done");
                    NOTIFY_STATE_ENTERED("ROOT.terminate");
                    rootState_subState = terminate;
                    rootState_active = terminate;
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

void theApp::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void theApp::cleanUpRelations() {
    if(itsApp != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsApp");
            itsApp = NULL;
        }
}

OMBoolean theApp::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}

void theApp::rootState_exit() {
    switch (rootState_subState) {
        case Init:
        {
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.Init");
            break;
        };
        case Run:
        {
            NOTIFY_STATE_EXITED("ROOT.Run");
            break;
        };
        case Done:
        {
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.Done");
            break;
        };
        case terminate:
        {
            NOTIFY_STATE_EXITED("ROOT.terminate");
            break;
        };
        default:
            break;
    };
    rootState_subState = OMNonState;
    NOTIFY_STATE_EXITED("ROOT");
}



#ifdef _OMINSTRUMENT


void OMAnimatedtheApp::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("t", x2String(myReal->t));
    aomsAttributes->addAttribute("guidanceMode", x2String(myReal->guidanceMode));
}

void OMAnimatedtheApp::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("itsApp", FALSE, TRUE);
    if(myReal->itsApp)
        aomsRelations->ADD_ITEM(myReal->itsApp);
}

void OMAnimatedtheApp::rootState_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case theApp::Init:
        {
            Init_serializeStates(aomsState);
            break;
        };
        case theApp::Run:
        {
            Run_serializeStates(aomsState);
            break;
        };
        case theApp::Done:
        {
            Done_serializeStates(aomsState);
            break;
        };
        case theApp::terminate:
        {
            terminate_serializeStates(aomsState);
            break;
        };
        default:
            break;
    };
}

void OMAnimatedtheApp::terminate_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.terminate");
}

void OMAnimatedtheApp::Run_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Run");
}

void OMAnimatedtheApp::Init_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Init");
}

void OMAnimatedtheApp::Done_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Done");
}

IMPLEMENT_REACTIVE_META(theApp, Application, FALSE, OMAnimatedtheApp)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\theApp.cpp
*********************************************************************/

