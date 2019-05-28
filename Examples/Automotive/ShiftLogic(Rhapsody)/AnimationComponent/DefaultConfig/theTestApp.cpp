/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: theTestApp
//!	Generated Date	: Fri, 27, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\theTestApp.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 


#define _OMSTATECHART_ANIMATED 
//#]

#include "theTestApp.h"
#include "TestDrivetrainApp.h"
#include "initguid.h"

//## package Application 


//#[ ignore 
#define Application_theTestApp_theTestApp_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// theTestApp.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(Application)
//## class theTestApp 



theTestApp::theTestApp(OMThread*  p_thread) : t(0.0) {
    NOTIFY_REACTIVE_CONSTRUCTOR(theTestApp, theTestApp(), 0, Application_theTestApp_theTestApp_SERIALIZE);
    setThread(p_thread, FALSE);
    itsApp = NULL;
    initStatechart();
    //#[ operation theTestApp() 
    t = 0.0;
    startBehavior();     
     
    
    //#]
}

theTestApp::~theTestApp() {
    NOTIFY_DESTRUCTOR(~theTestApp, TRUE);
    //#[ operation ~theTestApp() 
        if(itsApp)
        { 
            delete  itsApp;
            itsApp = NULL; 
        }
    
    //#]
    cleanUpRelations();
}

double theTestApp::getT() const {
    return t;
}

void theTestApp::setT(double  p_t) {
    t = p_t;
}

TestDrivetrainApp* theTestApp::getItsApp() const {
    return itsApp;
}

void theTestApp::setItsApp(TestDrivetrainApp*  p_TestDrivetrainApp) {
    itsApp = p_TestDrivetrainApp;
    if(p_TestDrivetrainApp != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsApp", p_TestDrivetrainApp, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsApp");
        }
}

void theTestApp::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("1");
        NOTIFY_STATE_ENTERED("ROOT.init");
        pushNullConfig();
        rootState_subState = init;
        rootState_active = init;
        //#[ state ROOT.init.(Entry) 
        t = 0.0;
        itsApp = new TestDrivetrainApp();
        //#]
        NOTIFY_TRANSITION_TERMINATED("1");
    }
}

int theTestApp::rootState_dispatchEvent(short  id) {
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

void theTestApp::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void theTestApp::cleanUpRelations() {
    if(itsApp != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsApp");
            itsApp = NULL;
        }
}

OMBoolean theTestApp::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



#ifdef _OMINSTRUMENT


void OMAnimatedtheTestApp::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedtheTestApp::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("itsApp", FALSE, TRUE);
    if(myReal->itsApp)
        aomsRelations->ADD_ITEM(myReal->itsApp);
}

void OMAnimatedtheTestApp::rootState_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case theTestApp::init:
        {
            init_serializeStates(aomsState);
            break;
        };
        case theTestApp::run:
        {
            run_serializeStates(aomsState);
            break;
        };
        case theTestApp::done:
        {
            done_serializeStates(aomsState);
            break;
        };
        default:
            break;
    };
}

void OMAnimatedtheTestApp::run_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.run");
}

void OMAnimatedtheTestApp::init_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.init");
}

void OMAnimatedtheTestApp::done_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.done");
}

IMPLEMENT_REACTIVE_META(theTestApp, Application, FALSE, OMAnimatedtheTestApp)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\theTestApp.cpp
*********************************************************************/

