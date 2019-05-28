/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: theTest
//!	Generated Date	: Sat, 7, Jun 2003  
	File Path	: AnimationComComponent\DefaultConfig\theTest.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 


#define _OMSTATECHART_ANIMATED 
//#]

#include "theTest.h"
#include "App.h"
#include "App_task_0010ms.h"
#include "math.h"
#include "stdafx.h"
#include "initguid.h"
#include "IsDaeCOSolver.h"
#include "IsDaeCOSolver_i.c"
#include "GuidanceLogic.h"

//## package Application3 


//#[ ignore 
#define Application3_theTest_theTest_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// theTest.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(Application3)
//## class theTest 

#define TICK_INTERVAL 0.001

theTest::theTest(OMThread*  p_thread) : t(0.0) {
    setThread(p_thread, FALSE);
    itsApp = NULL;
    itstask_0010ms = NULL;
    initStatechart();
    //#[ operation theTest() 
    //#]
}

theTest::~theTest() {
    //#[ operation ~theTest() 
    //#]
    cleanUpRelations();
}

long theTest::getGuidanceMode() const {
    return guidanceMode;
}

void theTest::setGuidanceMode(long  p_guidanceMode) {
    guidanceMode = p_guidanceMode;
}

int theTest::getInterval() const {
    return interval;
}

void theTest::setInterval(int  p_interval) {
    interval = p_interval;
}

double theTest::getT() const {
    return t;
}

void theTest::setT(double  p_t) {
    t = p_t;
}

App* theTest::getItsApp() const {
    return itsApp;
}

void theTest::setItsApp(App*  p_App) {
    itsApp = p_App;
    if(p_App != NULL)
        {
        }
    else
        {
        }
}

App_task_0010ms* theTest::getItstask_0010ms() const {
    return itstask_0010ms;
}

void theTest::setItstask_0010ms(App_task_0010ms*  p_App_task_0010ms) {
    itstask_0010ms = p_App_task_0010ms;
    if(p_App_task_0010ms != NULL)
        {
        }
    else
        {
        }
}

void theTest::rootState_entDef() {
    {
        pushNullConfig();
        rootState_subState = Init;
        rootState_active = Init;
        //#[ state ROOT.Init.(Entry) 
        t = 0.0;
        //itsApp = new MissileGuidance();
        itsApp = new App();
        
        
        //#]
    }
}

int theTest::rootState_dispatchEvent(short  id) {
    int res = eventNotConsumed;
    switch (rootState_active) {
        case Init:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    popNullConfig();
                    rootState_subState = Run;
                    rootState_active = Run;
                    //#[ state ROOT.Run.(Entry) 
                    itsApp->setTime(t);
                    itsApp->handle_tick();
                    guidanceMode = itsApp->task_0010ms->GuidanceLogicBlock->getGuidanceMode();
                    t += TICK_INTERVAL; // WAH  0.001;
                    GEN(evTick);
                    //#]
                    res = eventConsumed;
                }
            
            break;
        };
        case Run:
        {
            if(IS_EVENT_TYPE_OF(evTick_Default_id))
                {
                    //## transition 3 
                    if((t>=5) || (guidanceMode==5))
                        {
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
                            res = eventConsumed;
                        }
                    else
                        {
                            rootState_subState = Run;
                            rootState_active = Run;
                            //#[ state ROOT.Run.(Entry) 
                            itsApp->setTime(t);
                            itsApp->handle_tick();
                            guidanceMode = itsApp->task_0010ms->GuidanceLogicBlock->getGuidanceMode();
                            t += TICK_INTERVAL; // WAH  0.001;
                            GEN(evTick);
                            //#]
                            res = eventConsumed;
                        }
                }
            
            break;
        };
        case Done:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    popNullConfig();
                    rootState_subState = terminate;
                    rootState_active = terminate;
                    res = eventConsumed;
                }
            
            break;
        };
        
        default:
            break;
    };
    return res;
}

void theTest::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void theTest::cleanUpRelations() {
    if(itsApp != NULL)
        {
            itsApp = NULL;
        }
    if(itstask_0010ms != NULL)
        {
            itstask_0010ms = NULL;
        }
}

OMBoolean theTest::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}

void theTest::rootState_exit() {
    switch (rootState_subState) {
        case Init:
        {
            popNullConfig();
            break;
        };
        case Run:
        {
            break;
        };
        case Done:
        {
            popNullConfig();
            break;
        };
        case terminate:
        {
            break;
        };
        default:
            break;
    };
    rootState_subState = OMNonState;
}






/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\theTest.cpp
*********************************************************************/

