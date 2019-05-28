/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: theStdApp
//!	Generated Date	: Wed, 18, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\theStdApp.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 


#define _OMSTATECHART_ANIMATED 
//#]

#include "theStdApp.h"
#include "Application.h"
#include "StdApp.h"
#include "initguid.h"

//## package AppSimple 


//#[ ignore 
#define AppSimple_theStdApp_theStdApp_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// theStdApp.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(AppSimple)
//## class theStdApp 



theStdApp::theStdApp(OMThread*  p_thread) : t(0.0) {
    NOTIFY_REACTIVE_CONSTRUCTOR(theStdApp, theStdApp(), 0, AppSimple_theStdApp_theStdApp_SERIALIZE);
    setThread(p_thread, FALSE);
    itsApp = NULL;
    initStatechart();
    //#[ operation theStdApp() 
    t = 0.0;
    startBehavior();     
     
    
    //#]
}

theStdApp::~theStdApp() {
    NOTIFY_DESTRUCTOR(~theStdApp, TRUE);
    //#[ operation ~theStdApp() 
        if(itsApp)
        { 
            delete  itsApp;
            itsApp = NULL; 
        }
    
    //#]
    cleanUpRelations();
}

double theStdApp::getT() const {
    return t;
}

void theStdApp::setT(double  p_t) {
    t = p_t;
}

StdApp* theStdApp::getItsApp() const {
    return itsApp;
}

void theStdApp::setItsApp(StdApp*  p_StdApp) {
    itsApp = p_StdApp;
    if(p_StdApp != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsApp", p_StdApp, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsApp");
        }
}

void theStdApp::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("1");
        NOTIFY_STATE_ENTERED("ROOT.init");
        pushNullConfig();
        rootState_subState = init;
        rootState_active = init;
        //#[ state ROOT.init.(Entry) 
        t = 0.0;
        itsApp = new StdApp();
        //#]
        NOTIFY_TRANSITION_TERMINATED("1");
    }
}

int theStdApp::rootState_dispatchEvent(short  id) {
    int res = eventNotConsumed;
    switch (rootState_active) {
        case init:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    NOTIFY_TRANSITION_STARTED("0");
                    popNullConfig();
                    NOTIFY_STATE_EXITED("ROOT.init");
                    NOTIFY_STATE_ENTERED("ROOT.run");
                    rootState_subState = run;
                    rootState_active = run;
                    //#[ state ROOT.run.(Entry) 
                    itsApp->setTime(t);
                    itsApp->handle_tick();  
                    t += 0.1;
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
                    if(t > 1000.0)
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
                              delete itsApp;
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
                            NOTIFY_STATE_ENTERED("ROOT.run");
                            rootState_subState = run;
                            rootState_active = run;
                            //#[ state ROOT.run.(Entry) 
                            itsApp->setTime(t);
                            itsApp->handle_tick();  
                            t += 0.1;
                            GEN(evTick);
                            //#]
                            NOTIFY_TRANSITION_TERMINATED("3");
                            NOTIFY_TRANSITION_TERMINATED("2");
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

void theStdApp::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void theStdApp::cleanUpRelations() {
    if(itsApp != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsApp");
            itsApp = NULL;
        }
}

OMBoolean theStdApp::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



#ifdef _OMINSTRUMENT


void OMAnimatedtheStdApp::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedtheStdApp::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("itsApp", FALSE, TRUE);
    if(myReal->itsApp)
        aomsRelations->ADD_ITEM(myReal->itsApp);
}

void OMAnimatedtheStdApp::rootState_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case theStdApp::init:
        {
            init_serializeStates(aomsState);
            break;
        };
        case theStdApp::run:
        {
            run_serializeStates(aomsState);
            break;
        };
        case theStdApp::done:
        {
            done_serializeStates(aomsState);
            break;
        };
        default:
            break;
    };
}

void OMAnimatedtheStdApp::run_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.run");
}

void OMAnimatedtheStdApp::init_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.init");
}

void OMAnimatedtheStdApp::done_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.done");
}

IMPLEMENT_REACTIVE_META(theStdApp, AppSimple, FALSE, OMAnimatedtheStdApp)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\theStdApp.cpp
*********************************************************************/

