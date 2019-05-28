/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: theApp
//!	Generated Date	: Tue, 4, Feb 2003  
	File Path	: AnimationComponent\DefaultConfig\theApp.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 


#define _OMSTATECHART_ANIMATED 
//#]

#include "theApp.h"
#include "DemoDrivetrainApp.h"
#include "initguid.h"
#include "IsDaeCOSolver.h"
#include "IsDaeCOSolver_i.c"

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
    t = 0.0;
    startBehavior();     
     
    
    //#]
}

theApp::~theApp() {
    NOTIFY_DESTRUCTOR(~theApp, TRUE);
    //#[ operation ~theApp() 
        if(itsApp)
        { 
            delete  itsApp;
            itsApp = NULL; 
        }
    
    //#]
    cleanUpRelations();
}

double theApp::getT() const {
    return t;
}

void theApp::setT(double  p_t) {
    t = p_t;
}

DemoDrivetrainApp* theApp::getItsApp() const {
    return itsApp;
}

void theApp::setItsApp(DemoDrivetrainApp*  p_DemoDrivetrainApp) {
    itsApp = p_DemoDrivetrainApp;
    if(p_DemoDrivetrainApp != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsApp", p_DemoDrivetrainApp, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsApp");
        }
}

void theApp::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("1");
        NOTIFY_STATE_ENTERED("ROOT.init");
        pushNullConfig();
        rootState_subState = init;
        rootState_active = init;
        //#[ state ROOT.init.(Entry) 
        t = 0.0;
        itsApp = new DemoDrivetrainApp();
        //#]
        NOTIFY_TRANSITION_TERMINATED("1");
    }
}

int theApp::rootState_dispatchEvent(short  id) {
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
                    if(t > 40.0)
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



#ifdef _OMINSTRUMENT


void OMAnimatedtheApp::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedtheApp::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("itsApp", FALSE, TRUE);
    if(myReal->itsApp)
        aomsRelations->ADD_ITEM(myReal->itsApp);
}

void OMAnimatedtheApp::rootState_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case theApp::init:
        {
            init_serializeStates(aomsState);
            break;
        };
        case theApp::run:
        {
            run_serializeStates(aomsState);
            break;
        };
        case theApp::done:
        {
            done_serializeStates(aomsState);
            break;
        };
        default:
            break;
    };
}

void OMAnimatedtheApp::run_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.run");
}

void OMAnimatedtheApp::init_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.init");
}

void OMAnimatedtheApp::done_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.done");
}

IMPLEMENT_REACTIVE_META(theApp, Application, FALSE, OMAnimatedtheApp)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\theApp.cpp
*********************************************************************/

