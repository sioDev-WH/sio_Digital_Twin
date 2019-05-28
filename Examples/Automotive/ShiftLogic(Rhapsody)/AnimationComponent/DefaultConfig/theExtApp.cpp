/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: theExtApp
//!	Generated Date	: Thu, 19, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\theExtApp.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 


#define _OMSTATECHART_ANIMATED 
//#]

#include "theExtApp.h"
#include "Application.h"
#include "ExtApp.h"
#include "initguid.h"

//## package AppSimple 


//#[ ignore 
#define AppSimple_theExtApp_theExtApp_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// theExtApp.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(AppSimple)
//## class theExtApp 



theExtApp::theExtApp(OMThread*  p_thread) : t(0.0) {
    NOTIFY_REACTIVE_CONSTRUCTOR(theExtApp, theExtApp(), 0, AppSimple_theExtApp_theExtApp_SERIALIZE);
    setThread(p_thread, FALSE);
    itsApp = NULL;
    initStatechart();
    //#[ operation theExtApp() 
    t = 0.0;
    startBehavior();     
     
    
    //#]
}

theExtApp::~theExtApp() {
    NOTIFY_DESTRUCTOR(~theExtApp, TRUE);
    //#[ operation ~theExtApp() 
        if(itsApp)
        { 
            delete  itsApp;
            itsApp = NULL; 
        }
    
    //#]
    cleanUpRelations();
}

double theExtApp::getT() const {
    return t;
}

void theExtApp::setT(double  p_t) {
    t = p_t;
}

ExtApp* theExtApp::getItsApp() const {
    return itsApp;
}

void theExtApp::setItsApp(ExtApp*  p_ExtApp) {
    itsApp = p_ExtApp;
    if(p_ExtApp != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsApp", p_ExtApp, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsApp");
        }
}

void theExtApp::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("1");
        NOTIFY_STATE_ENTERED("ROOT.init");
        pushNullConfig();
        rootState_subState = init;
        rootState_active = init;
        //#[ state ROOT.init.(Entry) 
        t = 0.0;
        itsApp = new ExtApp();
        //#]
        NOTIFY_TRANSITION_TERMINATED("1");
    }
}

int theExtApp::rootState_dispatchEvent(short  id) {
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

void theExtApp::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void theExtApp::cleanUpRelations() {
    if(itsApp != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsApp");
            itsApp = NULL;
        }
}

OMBoolean theExtApp::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



#ifdef _OMINSTRUMENT


void OMAnimatedtheExtApp::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedtheExtApp::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("itsApp", FALSE, TRUE);
    if(myReal->itsApp)
        aomsRelations->ADD_ITEM(myReal->itsApp);
}

void OMAnimatedtheExtApp::rootState_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case theExtApp::init:
        {
            init_serializeStates(aomsState);
            break;
        };
        case theExtApp::run:
        {
            run_serializeStates(aomsState);
            break;
        };
        case theExtApp::done:
        {
            done_serializeStates(aomsState);
            break;
        };
        default:
            break;
    };
}

void OMAnimatedtheExtApp::run_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.run");
}

void OMAnimatedtheExtApp::init_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.init");
}

void OMAnimatedtheExtApp::done_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.done");
}

IMPLEMENT_REACTIVE_META(theExtApp, AppSimple, FALSE, OMAnimatedtheExtApp)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\theExtApp.cpp
*********************************************************************/

