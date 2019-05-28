/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: theExtApp2
//!	Generated Date	: Sun, 22, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\theExtApp2.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 


#define _OMSTATECHART_ANIMATED 
//#]

#include "theExtApp2.h"
#include "Application.h"
#include "ExtApp.h"
#include "ExtApp_task_0100ms.h"
#include "Controller.h"
#include "ExtCarSS.h"

//## package AppSimple 


//#[ ignore 
#define AppSimple_theExtApp2_theExtApp2_SERIALIZE OM_NO_OP


#define AppSimple_theExtApp2_Load_SERIALIZE OM_NO_OP


#define AppSimple_theExtApp2_Save_SERIALIZE OM_NO_OP


#define AppSimple_theExtApp2_UpdateParameters_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// theExtApp2.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(AppSimple)
//## class theExtApp2 



theExtApp2::theExtApp2(OMThread*  p_thread) : t(0.0) ,shiftTime(0.0) ,bDataSaved(0) ,cycles(0) {
    NOTIFY_REACTIVE_CONSTRUCTOR(theExtApp2, theExtApp2(), 0, AppSimple_theExtApp2_theExtApp2_SERIALIZE);
    setThread(p_thread, FALSE);
    itsApp = NULL;
    initStatechart();
    //#[ operation theExtApp2() 
    t = 0.0;
    startBehavior();     
     
    
    //#]
}

theExtApp2::~theExtApp2() {
    NOTIFY_DESTRUCTOR(~theExtApp2, TRUE);
    //#[ operation ~theExtApp2() 
        if(itsApp)
        { 
            delete  itsApp;
            itsApp = NULL; 
        }
    
    //#]
    cleanUpRelations();
}

void theExtApp2::Load() {
    NOTIFY_OPERATION(Load, Load(), 0, AppSimple_theExtApp2_Load_SERIALIZE);
    //#[ operation Load() 
    
    FILE* fs = fopen("snapshotData.bin", "rb");
    itsApp->task_0100ms->itsShiftController->Load(fs);
    
    CComBSTR bstrModelDataFileName = L"snapshotModelData.bin";
    itsApp->task_0100ms->itsExtCarSS->Load(bstrModelDataFileName);
    fclose(fs);
    
    //#]
}

void theExtApp2::Save() {
    NOTIFY_OPERATION(Save, Save(), 0, AppSimple_theExtApp2_Save_SERIALIZE);
    //#[ operation Save() 
    FILE* fs = fopen("snapshotData.bin","wb");
    itsApp->task_0100ms->itsShiftController->Save(fs);
    
    CComBSTR bstrModelDataFileName = L"snapshotModelData.bin";
    itsApp->task_0100ms->itsExtCarSS->Save(bstrModelDataFileName);
    
    fclose(fs);
    bDataSaved = 1;
    //#]
}

void theExtApp2::UpdateParameters() {
    NOTIFY_OPERATION(UpdateParameters, UpdateParameters(), 0, AppSimple_theExtApp2_UpdateParameters_SERIALIZE);
    //#[ operation UpdateParameters() 
    bool bUp = true;
    long iGear = 1;
    shiftTime = shiftTime + 0.1;
    itsApp->task_0100ms->itsShiftController->SetShiftDelay(bUp, iGear, shiftTime);
    //#]
}

int theExtApp2::getBDataSaved() const {
    return bDataSaved;
}

void theExtApp2::setBDataSaved(int  p_bDataSaved) {
    bDataSaved = p_bDataSaved;
}

int theExtApp2::getCycles() const {
    return cycles;
}

void theExtApp2::setCycles(int  p_cycles) {
    cycles = p_cycles;
}

ofstream theExtApp2::getFs() const {
    return fs;
}

void theExtApp2::setFs(ofstream  p_fs) {
    fs = p_fs;
}

double theExtApp2::getShiftTime() const {
    return shiftTime;
}

void theExtApp2::setShiftTime(double  p_shiftTime) {
    shiftTime = p_shiftTime;
}

double theExtApp2::getT() const {
    return t;
}

void theExtApp2::setT(double  p_t) {
    t = p_t;
}

ExtApp* theExtApp2::getItsApp() const {
    return itsApp;
}

void theExtApp2::setItsApp(ExtApp*  p_ExtApp) {
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

void theExtApp2::rootState_entDef() {
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

int theExtApp2::rootState_dispatchEvent(short  id) {
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
            res = run_takeEvent(id);
            break;
        };
        case SaveData:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    NOTIFY_TRANSITION_STARTED("7");
                    popNullConfig();
                    NOTIFY_STATE_EXITED("ROOT.SaveData");
                    NOTIFY_STATE_ENTERED("ROOT.run");
                    rootState_subState = run;
                    rootState_active = run;
                    //#[ state ROOT.run.(Entry) 
                    itsApp->setTime(t);
                    itsApp->handle_tick();  
                    t += 0.1;
                    GEN(evTick);
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("7");
                    res = eventConsumed;
                }
            
            break;
        };
        case LoadData:
        {
            if(IS_EVENT_TYPE_OF(OMEventNullId))
                {
                    NOTIFY_TRANSITION_STARTED("8");
                    popNullConfig();
                    NOTIFY_STATE_EXITED("ROOT.LoadData");
                    NOTIFY_STATE_ENTERED("ROOT.run");
                    rootState_subState = run;
                    rootState_active = run;
                    //#[ state ROOT.run.(Entry) 
                    itsApp->setTime(t);
                    itsApp->handle_tick();  
                    t += 0.1;
                    GEN(evTick);
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("8");
                    res = eventConsumed;
                }
            
            break;
        };
        default:
            break;
    };
    return res;
}

void theExtApp2::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void theExtApp2::cleanUpRelations() {
    if(itsApp != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsApp");
            itsApp = NULL;
        }
}

OMBoolean theExtApp2::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}

int theExtApp2::run_takeEvent(short  id) {
    int res = eventNotConsumed;
    if(IS_EVENT_TYPE_OF(evTick_Application_id))
        {
            res = runTakeevTick();
        }
    
    return res;
}

int theExtApp2::runTakeevTick() {
    int res = eventNotConsumed;
    //## transition 4 
    if(t > 5.0 && cycles < 10)
        {
            NOTIFY_TRANSITION_STARTED("2");
            NOTIFY_TRANSITION_STARTED("4");
            NOTIFY_STATE_EXITED("ROOT.run");
            NOTIFY_STATE_ENTERED("ROOT.LoadData");
            pushNullConfig();
            rootState_subState = LoadData;
            rootState_active = LoadData;
            //#[ state ROOT.LoadData.(Entry) 
            t = 0.5;
            Load();
            UpdateParameters();
            cycles = cycles + 1;
            //#]
            NOTIFY_TRANSITION_TERMINATED("4");
            NOTIFY_TRANSITION_TERMINATED("2");
            res = eventConsumed;
        }
    else
        {
            //## transition 5 
            if(t >= 0.5 && !bDataSaved)
                {
                    NOTIFY_TRANSITION_STARTED("2");
                    NOTIFY_TRANSITION_STARTED("5");
                    NOTIFY_STATE_EXITED("ROOT.run");
                    NOTIFY_STATE_ENTERED("ROOT.SaveData");
                    pushNullConfig();
                    rootState_subState = SaveData;
                    rootState_active = SaveData;
                    //#[ state ROOT.SaveData.(Entry) 
                    Save();
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("5");
                    NOTIFY_TRANSITION_TERMINATED("2");
                    res = eventConsumed;
                }
            else
                {
                    //## transition 6 
                    if(cycles >= 10)
                        {
                            NOTIFY_TRANSITION_STARTED("2");
                            NOTIFY_TRANSITION_STARTED("6");
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
                            NOTIFY_TRANSITION_TERMINATED("6");
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
        }
    return res;
}

void theExtApp2::rootState_exit() {
    switch (rootState_subState) {
        case init:
        {
            popNullConfig();
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
        case SaveData:
        {
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.SaveData");
            break;
        };
        case LoadData:
        {
            popNullConfig();
            NOTIFY_STATE_EXITED("ROOT.LoadData");
            break;
        };
        default:
            break;
    };
    rootState_subState = OMNonState;
    NOTIFY_STATE_EXITED("ROOT");
}



#ifdef _OMINSTRUMENT


void OMAnimatedtheExtApp2::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedtheExtApp2::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("itsApp", FALSE, TRUE);
    if(myReal->itsApp)
        aomsRelations->ADD_ITEM(myReal->itsApp);
}

void OMAnimatedtheExtApp2::rootState_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case theExtApp2::init:
        {
            init_serializeStates(aomsState);
            break;
        };
        case theExtApp2::run:
        {
            run_serializeStates(aomsState);
            break;
        };
        case theExtApp2::done:
        {
            done_serializeStates(aomsState);
            break;
        };
        case theExtApp2::SaveData:
        {
            SaveData_serializeStates(aomsState);
            break;
        };
        case theExtApp2::LoadData:
        {
            LoadData_serializeStates(aomsState);
            break;
        };
        default:
            break;
    };
}

void OMAnimatedtheExtApp2::SaveData_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.SaveData");
}

void OMAnimatedtheExtApp2::run_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.run");
}

void OMAnimatedtheExtApp2::LoadData_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.LoadData");
}

void OMAnimatedtheExtApp2::init_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.init");
}

void OMAnimatedtheExtApp2::done_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.done");
}

IMPLEMENT_REACTIVE_META(theExtApp2, AppSimple, FALSE, OMAnimatedtheExtApp2)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\theExtApp2.cpp
*********************************************************************/

