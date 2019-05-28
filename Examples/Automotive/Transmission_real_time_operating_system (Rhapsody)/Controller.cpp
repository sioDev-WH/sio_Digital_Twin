/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Controller
//!	Generated Date	: Sun, 19, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Controller.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 


#define _OMSTATECHART_ANIMATED 
//#]

#include "Controller.h"
#include "Clutch_Schedule.h"
#include "EventBroadcast.h"
#include "OnUMLEsoMacros.h"

//## package TransmissionControlModels 


//#[ ignore 
#define TransmissionControlModels_Controller_Controller_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_AddRef_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_Fire_DisengageEvents_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_Fire_EngageEvents_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_Load_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_Release_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_Save_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_SetName_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_SetShiftDelay_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_clean_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_downshiftEntry_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_downshiftExit_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_handle_ShiftLeverData_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_handle_SpeedData_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_handle_ThrottleData_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_handle_tick_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_init_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_runShiftLogic_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_updateShiftDelay_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_updateThresholds_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_upshiftEntry_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_upshiftExit_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// Controller.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(TransmissionControlModels)
//## class Controller 



Controller::Controller(OMThread*  p_thread) : Port_0(NULL) ,Port_1(NULL) ,Port_2(NULL) ,Port_3(NULL) ,Port_4(NULL) ,Port_5(NULL) ,Port_6(NULL) ,Port_7(NULL) ,Port_8(NULL) ,last_time(0.0) ,shiftDelay(0.0) ,Port_EngineStart(NULL) ,bEngineStarted(false) {
    NOTIFY_REACTIVE_CONSTRUCTOR(Controller, Controller(), 0, TransmissionControlModels_Controller_Controller_SERIALIZE);
    setThread(p_thread, FALSE);
    {
        {
            shiftData.setShouldDelete(FALSE);
        }
        shiftData.setThread(p_thread, FALSE);
    }
    initStatechart();
    //#[ operation Controller() 
        init();
        startBehavior();
        bReverse = false;
        last_time = 0.0;
        local_time = 0.0;
    
    //#]
}

Controller::~Controller() {
    NOTIFY_DESTRUCTOR(~Controller, TRUE);
    //#[ operation ~Controller() 
    //#]
}

long Controller::AddRef() {
    NOTIFY_OPERATION(AddRef, AddRef(), 0, TransmissionControlModels_Controller_AddRef_SERIALIZE);
    //#[ operation AddRef() 
      return ++m_cRef;
    
    //#]
}

void Controller::Fire_DisengageEvents() {
    NOTIFY_OPERATION(Fire_DisengageEvents, Fire_DisengageEvents(), 0, TransmissionControlModels_Controller_Fire_DisengageEvents_SERIALIZE);
    //#[ operation Fire_DisengageEvents() 
    int i;
    for(i=0;i<shiftData.clutchSchedule->nClutches;i++)
    if(shiftData.clutchSchedule->disengageList[i])
    {
      portData[i] = 0;
      pActuatorPorts[i]->gen(&portData[i]);
    }
    
    //#]
}

void Controller::Fire_EngageEvents() {
    NOTIFY_OPERATION(Fire_EngageEvents, Fire_EngageEvents(), 0, TransmissionControlModels_Controller_Fire_EngageEvents_SERIALIZE);
    //#[ operation Fire_EngageEvents() 
    long i;
    long engageMsg=1;
    for(i=0;i<shiftData.clutchSchedule->nClutches;i++)
    if(shiftData.clutchSchedule->engageList[i])
    {
      portData[i] = 1;
      pActuatorPorts[i]->gen(&portData[i]);
    }
    
    //#]
}

bool Controller::Load(FILE * fs) {
    NOTIFY_OPERATION(Load, Load(FILE * ), 0, TransmissionControlModels_Controller_Load_SERIALIZE);
    //#[ operation Load(FILE * ) 
      READ_SCALAR( currentGear )     
      READ_SCALAR( throttleData )     
      READ_SCALAR( vehicleSpeedData )     
      READ_SCALAR( upShiftThreshold )     
      READ_SCALAR( downShiftThreshold )     
      READ_SCALAR( shiftLeverData )     
      READ_SCALAR( rootState_active )     
      READ_SCALAR( local_time )
      READ_SCALAR( transition_time )
    
      long count = 4;
      READ_VECTOR( upshiftDelay, double, count);
      READ_VECTOR( downshiftDelay, double, count);
     
      return true;
    
    //#]
}

long Controller::Release() {
    NOTIFY_OPERATION(Release, Release(), 0, TransmissionControlModels_Controller_Release_SERIALIZE);
    //#[ operation Release() 
      m_cRef--;
      if (m_cRef <= 0)
        delete this;
    
      return m_cRef;
    
    //#]
}

void Controller::Save(FILE * fs) {
    NOTIFY_OPERATION(Save, Save(FILE * ), 0, TransmissionControlModels_Controller_Save_SERIALIZE);
    //#[ operation Save(FILE * ) 
      WRITE_SCALAR( currentGear )     
      WRITE_SCALAR( throttleData )     
      WRITE_SCALAR( vehicleSpeedData )     
      WRITE_SCALAR( upShiftThreshold )     
      WRITE_SCALAR( downShiftThreshold )     
      WRITE_SCALAR( shiftLeverData )     
      WRITE_SCALAR( rootState_active )     
      WRITE_SCALAR( local_time )
      WRITE_SCALAR( transition_time )
    
      long count = 4;
      WRITE_VECTOR( upshiftDelay, double, count);
      WRITE_VECTOR( downshiftDelay, double, count);
    
    //#]
}

void Controller::SetName(LPCTSTR cszName) {
    NOTIFY_OPERATION(SetName, SetName(LPCTSTR ), 0, TransmissionControlModels_Controller_SetName_SERIALIZE);
    //#[ operation SetName(LPCTSTR ) 
    //#]
}

void Controller::SetShiftDelay(const bool  bUp, const long  Gear, const double  delay) {
    NOTIFY_OPERATION(SetShiftDelay, SetShiftDelay(const bool,const long,const double), 0, TransmissionControlModels_Controller_SetShiftDelay_SERIALIZE);
    //#[ operation SetShiftDelay(const bool,const long,const double) 
    if (bUp)
    {
      if (Gear >= -1 && Gear <= 4)
        upshiftDelay[Gear+1] = delay;
    }
    else
    {
      if (Gear >= -1 && Gear <= 4)
        downshiftDelay[Gear+1] = delay;
    }
    //#]
}

void Controller::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, TransmissionControlModels_Controller_clean_SERIALIZE);
    //#[ operation clean() 
    	for (long i = 0; i < 10; i++)
    	{
    	  if (pActuatorPorts[i]) pActuatorPorts[i]->Release();
    	  pActuatorPorts[i] = NULL;
    	}
        
        if (Port_EngineStart)
        {
          Port_EngineStart->Release();
          Port_EngineStart = NULL;
        }  
    //#]
}

void Controller::downshiftEntry() {
    NOTIFY_OPERATION(downshiftEntry, downshiftEntry(), 0, TransmissionControlModels_Controller_downshiftEntry_SERIALIZE);
    //#[ operation downshiftEntry() 
    transition_time = 0.0;  
    shiftDelay = downshiftDelay[currentGear+1];
    if (bReverse)
    {
    	shiftData.clutchSchedule->updateEngage(currentGear,currentGear-1);
    	Fire_EngageEvents();
    }
    else
    {
        shiftData.clutchSchedule->updateDisengage(currentGear,currentGear-1);
        Fire_DisengageEvents();
    }
    //#]
}

void Controller::downshiftExit() {
    NOTIFY_OPERATION(downshiftExit, downshiftExit(), 0, TransmissionControlModels_Controller_downshiftExit_SERIALIZE);
    //#[ operation downshiftExit() 
    if (bReverse)
    {
    	shiftData.clutchSchedule->updateDisengage(currentGear,currentGear-1);
        Fire_DisengageEvents();
    }
    else
    {
    	shiftData.clutchSchedule->updateEngage(currentGear,currentGear-1);
    	Fire_EngageEvents();
    }
    //#]
}

void Controller::handle_ShiftLeverData(long * val) {
    NOTIFY_OPERATION(handle_ShiftLeverData, handle_ShiftLeverData(long * ), 0, TransmissionControlModels_Controller_handle_ShiftLeverData_SERIALIZE);
    //#[ operation handle_ShiftLeverData(long * ) 
    shiftLeverData = *val;
    if(shiftLeverData==0)
    { 
      manualNeutralShift ev;
      takeTrigger(&ev);
    }
    else if(shiftLeverData==1)
    {
      manualForwardShift ev;
      takeTrigger(&ev);
    }
    else if(shiftLeverData==-1)
    {
      manualReverseShift ev;
      takeTrigger(&ev);
    }
    
    //#]
}

void Controller::handle_SpeedData(double * val) {
    NOTIFY_OPERATION(handle_SpeedData, handle_SpeedData(double * ), 0, TransmissionControlModels_Controller_handle_SpeedData_SERIALIZE);
    //#[ operation handle_SpeedData(double * ) 
    vehicleSpeedData = *val;
    
    //#]
}

void Controller::handle_ThrottleData(double * val) {
    NOTIFY_OPERATION(handle_ThrottleData, handle_ThrottleData(double * ), 0, TransmissionControlModels_Controller_handle_ThrottleData_SERIALIZE);
    //#[ operation handle_ThrottleData(double * ) 
    throttleData = *val;
    
    //#]
}

void Controller::handle_tick() {
    NOTIFY_OPERATION(handle_tick, handle_tick(), 0, TransmissionControlModels_Controller_handle_tick_SERIALIZE);
    //#[ operation handle_tick() 
      // start the engine if it has not already been started
      if (!bEngineStarted)
      {
        engineData = 1;
        Port_EngineStart->gen(&engineData);
        bEngineStarted = true;
      }
    
      receive();
      runShiftLogic();
      broadcast();
    
    //#]
}

void Controller::init() {
    NOTIFY_OPERATION(init, init(), 0, TransmissionControlModels_Controller_init_SERIALIZE);
    //#[ operation init() 
    m_cRef = 0;
    
    transition_time = 0.0;
    
    upshiftDelay[0] = 0.0; // reverse to neutral
    upshiftDelay[1] = 0.0; // neutral to first
    upshiftDelay[2] = 0.0; // first to second
    upshiftDelay[3] = 0.0; // second to third
    upshiftDelay[4] = 0.1; // third to fourth
    upshiftDelay[5] = 0.0; // N/A
    
    downshiftDelay[0] = 0.0; // N/A
    downshiftDelay[1] = 0.2; // neutral to reverse
    downshiftDelay[2] = 0.2; // first to neutral
    downshiftDelay[3] = 0.2; // second to first
    downshiftDelay[4] = 0.2; // third to second
    downshiftDelay[5] = 0.2; // fourth to third
      
    currentGear=0;
    throttleData=0.0;
    vehicleSpeedData=0.0;
    shiftLeverData=0; // for N; +/-1 for D and R
    shiftData.init();
    
    for (long i = 0; i < 10; i++)
    {
      pActuatorPorts[i] = new Port_Int();
      pActuatorPorts[i]->AddRef();
    }
    
    Port_EngineStart = new Port_Int();
    Port_EngineStart->AddRef();
    
    Port_0 = pActuatorPorts[0];
    Port_1 = pActuatorPorts[1];
    Port_2 = pActuatorPorts[2];
    Port_3 = pActuatorPorts[3];
    Port_4 = pActuatorPorts[4];
    Port_5 = pActuatorPorts[5];
    Port_6 = pActuatorPorts[6];
    Port_7 = pActuatorPorts[7];
    Port_8 = pActuatorPorts[8];
    
    Port_Shift = pActuatorPorts[9];
    
    //#]
}

void Controller::runShiftLogic() {
    NOTIFY_OPERATION(runShiftLogic, runShiftLogic(), 0, TransmissionControlModels_Controller_runShiftLogic_SERIALIZE);
    //#[ operation runShiftLogic() 
    if(vehicleSpeedData<=downShiftThreshold && currentGear > 1)
    {
      downshift ev;
      takeTrigger(&ev);
    }
    else if(vehicleSpeedData>upShiftThreshold && currentGear < 4)
    {
      upshift ev;
      takeTrigger(&ev);
    }
    
    //#]
}

void Controller::updateShiftDelay() {
    NOTIFY_OPERATION(updateShiftDelay, updateShiftDelay(), 0, TransmissionControlModels_Controller_updateShiftDelay_SERIALIZE);
    //#[ operation updateShiftDelay() 
       transition_time += (local_time - last_time);     
       if (transition_time >= shiftDelay)
       { 
         shift ev;
         takeTrigger(&ev);
       }   
       
    //#]
}

void Controller::updateThresholds() {
    NOTIFY_OPERATION(updateThresholds, updateThresholds(), 0, TransmissionControlModels_Controller_updateThresholds_SERIALIZE);
    //#[ operation updateThresholds() 
    shiftData.getDownShiftThreshold (throttleData, currentGear, &downShiftThreshold);
    
    shiftData.getUpShiftThreshold(throttleData, currentGear, &upShiftThreshold);
    
    //#]
}

void Controller::upshiftEntry() {
    NOTIFY_OPERATION(upshiftEntry, upshiftEntry(), 0, TransmissionControlModels_Controller_upshiftEntry_SERIALIZE);
    //#[ operation upshiftEntry() 
    transition_time = 0.0; 
    shiftDelay = upshiftDelay[currentGear+1];
    if (bReverse)
    {
    	shiftData.clutchSchedule->updateEngage(currentGear,currentGear+1);
    	Fire_EngageEvents();
    }
    else
    {
        shiftData.clutchSchedule->updateDisengage(currentGear,currentGear+1);
        Fire_DisengageEvents();
    }
    //#]
}

void Controller::upshiftExit() {
    NOTIFY_OPERATION(upshiftExit, upshiftExit(), 0, TransmissionControlModels_Controller_upshiftExit_SERIALIZE);
    //#[ operation upshiftExit() 
    if (bReverse) 
    {
        shiftData.clutchSchedule->updateDisengage(currentGear,currentGear+1);
        Fire_DisengageEvents();
    }
    else
    {
    	shiftData.clutchSchedule->updateEngage(currentGear,currentGear+1);
    	Fire_EngageEvents();
    }
    
    //#]
}

Port_Int *  Controller::getPort_EngineStart() const {
    return Port_EngineStart;
}

void Controller::setPort_EngineStart(Port_Int * p_Port_EngineStart) {
    Port_EngineStart = p_Port_EngineStart;
}

bool Controller::getBEngineStarted() const {
    return bEngineStarted;
}

void Controller::setBEngineStarted(bool  p_bEngineStarted) {
    bEngineStarted = p_bEngineStarted;
}

ShiftData* Controller::getShiftData() const {
    return (ShiftData*) &shiftData;
}

void Controller::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("4");
        NOTIFY_STATE_ENTERED("ROOT.Idle");
        rootState_subState = Idle;
        rootState_active = Idle;
        //#[ state ROOT.Idle.(Entry) 
        currentGear = 0;
        
        //#]
        NOTIFY_TRANSITION_TERMINATED("4");
    }
}

int Controller::rootState_dispatchEvent(short  id) {
    int res = eventNotConsumed;
    switch (rootState_active) {
        case Idle:
        {
            if(IS_EVENT_TYPE_OF(manualReverseShift_TransmissionControlModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("2");
                    NOTIFY_STATE_EXITED("ROOT.Idle");
                    NOTIFY_STATE_ENTERED("ROOT.Reverse");
                    rootState_subState = Reverse;
                    rootState_active = Reverse;
                    //#[ state ROOT.Reverse.(Entry) 
                    currentGear = -1;
                    
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("2");
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(manualForwardShift_TransmissionControlModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("0");
                    NOTIFY_STATE_EXITED("ROOT.Idle");
                    NOTIFY_STATE_ENTERED("ROOT.First");
                    rootState_subState = First;
                    rootState_active = First;
                    //#[ state ROOT.First.(Entry) 
                    shiftData.clutchSchedule->updateDisengage(currentGear,1);
                    Fire_DisengageEvents();
                    shiftData.clutchSchedule->updateEngage(currentGear,1);
                    Fire_EngageEvents();
                    
                    currentGear = 1;
                    updateThresholds();
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("0");
                    res = eventConsumed;
                }
            
            break;
        };
        case First:
        {
            if(IS_EVENT_TYPE_OF(tic_TransmissionControlModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("3");
                    //#[ transition 3 
                    runShiftLogic();
                    updateThresholds();
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("3");
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(manualNeutralShift_TransmissionControlModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("11");
                    NOTIFY_STATE_EXITED("ROOT.First");
                    NOTIFY_STATE_ENTERED("ROOT.Idle");
                    rootState_subState = Idle;
                    rootState_active = Idle;
                    //#[ state ROOT.Idle.(Entry) 
                    currentGear = 0;
                    
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("11");
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(upshift_TransmissionControlModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("5");
                    NOTIFY_STATE_EXITED("ROOT.First");
                    NOTIFY_STATE_ENTERED("ROOT.Second");
                    rootState_subState = Second;
                    rootState_active = Second;
                    //#[ state ROOT.Second.(Entry) 
                    shiftData.clutchSchedule->updateDisengage(currentGear,2);
                    Fire_DisengageEvents();
                    shiftData.clutchSchedule->updateEngage(currentGear,2);
                    Fire_EngageEvents();
                    
                    currentGear = 2;
                    updateThresholds();
                    
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("5");
                    res = eventConsumed;
                }
            
            break;
        };
        case Second:
        {
            if(IS_EVENT_TYPE_OF(downshift_TransmissionControlModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("10");
                    NOTIFY_STATE_EXITED("ROOT.Second");
                    NOTIFY_STATE_ENTERED("ROOT.First");
                    rootState_subState = First;
                    rootState_active = First;
                    //#[ state ROOT.First.(Entry) 
                    shiftData.clutchSchedule->updateDisengage(currentGear,1);
                    Fire_DisengageEvents();
                    shiftData.clutchSchedule->updateEngage(currentGear,1);
                    Fire_EngageEvents();
                    
                    currentGear = 1;
                    updateThresholds();
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("10");
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(upshift_TransmissionControlModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("6");
                    NOTIFY_STATE_EXITED("ROOT.Second");
                    NOTIFY_STATE_ENTERED("ROOT.Third");
                    rootState_subState = Third;
                    rootState_active = Third;
                    //#[ state ROOT.Third.(Entry) 
                    shiftData.clutchSchedule->updateDisengage(currentGear,3);
                    Fire_DisengageEvents();
                    shiftData.clutchSchedule->updateEngage(currentGear,3);
                    Fire_EngageEvents();
                    
                    currentGear = 3;
                    updateThresholds();
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("6");
                    res = eventConsumed;
                }
            
            break;
        };
        case Third:
        {
            if(IS_EVENT_TYPE_OF(downshift_TransmissionControlModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("9");
                    NOTIFY_STATE_EXITED("ROOT.Third");
                    NOTIFY_STATE_ENTERED("ROOT.Second");
                    rootState_subState = Second;
                    rootState_active = Second;
                    //#[ state ROOT.Second.(Entry) 
                    shiftData.clutchSchedule->updateDisengage(currentGear,2);
                    Fire_DisengageEvents();
                    shiftData.clutchSchedule->updateEngage(currentGear,2);
                    Fire_EngageEvents();
                    
                    currentGear = 2;
                    updateThresholds();
                    
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("9");
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(upshift_TransmissionControlModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("7");
                    NOTIFY_STATE_EXITED("ROOT.Third");
                    NOTIFY_STATE_ENTERED("ROOT.Fourth");
                    rootState_subState = Fourth;
                    rootState_active = Fourth;
                    //#[ state ROOT.Fourth.(Entry) 
                    shiftData.clutchSchedule->updateDisengage(currentGear,4);
                    Fire_DisengageEvents();
                    shiftData.clutchSchedule->updateEngage(currentGear,4);
                    Fire_EngageEvents();
                    
                    currentGear = 4;
                    updateThresholds();
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("7");
                    res = eventConsumed;
                }
            
            break;
        };
        case Fourth:
        {
            if(IS_EVENT_TYPE_OF(downshift_TransmissionControlModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("8");
                    NOTIFY_STATE_EXITED("ROOT.Fourth");
                    NOTIFY_STATE_ENTERED("ROOT.Third");
                    rootState_subState = Third;
                    rootState_active = Third;
                    //#[ state ROOT.Third.(Entry) 
                    shiftData.clutchSchedule->updateDisengage(currentGear,3);
                    Fire_DisengageEvents();
                    shiftData.clutchSchedule->updateEngage(currentGear,3);
                    Fire_EngageEvents();
                    
                    currentGear = 3;
                    updateThresholds();
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("8");
                    res = eventConsumed;
                }
            
            break;
        };
        case Reverse:
        {
            if(IS_EVENT_TYPE_OF(manualNeutralShift_TransmissionControlModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("1");
                    NOTIFY_STATE_EXITED("ROOT.Reverse");
                    NOTIFY_STATE_ENTERED("ROOT.Idle");
                    rootState_subState = Idle;
                    rootState_active = Idle;
                    //#[ state ROOT.Idle.(Entry) 
                    currentGear = 0;
                    
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("1");
                    res = eventConsumed;
                }
            
            break;
        };
        default:
            break;
    };
    return res;
}

void Controller::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

OMBoolean Controller::startBehavior() {
    OMBoolean done = FALSE;
    shiftData.startBehavior();
    done = OMReactive::startBehavior();
    return done;
}

void Controller::rootState_exit() {
    switch (rootState_subState) {
        case Idle:
        {
            NOTIFY_STATE_EXITED("ROOT.Idle");
            break;
        };
        case First:
        {
            NOTIFY_STATE_EXITED("ROOT.First");
            break;
        };
        case Second:
        {
            NOTIFY_STATE_EXITED("ROOT.Second");
            break;
        };
        case Third:
        {
            NOTIFY_STATE_EXITED("ROOT.Third");
            break;
        };
        case Fourth:
        {
            NOTIFY_STATE_EXITED("ROOT.Fourth");
            break;
        };
        case Reverse:
        {
            NOTIFY_STATE_EXITED("ROOT.Reverse");
            break;
        };
        default:
            break;
    };
    rootState_subState = OMNonState;
    NOTIFY_STATE_EXITED("ROOT");
}



#ifdef _OMINSTRUMENT


void OMAnimatedController::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedController::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("shiftData", TRUE, TRUE);
    if((ShiftData*) &myReal->shiftData)
        aomsRelations->ADD_ITEM((ShiftData*) &myReal->shiftData);
}

void OMAnimatedController::rootState_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case Controller::Idle:
        {
            Idle_serializeStates(aomsState);
            break;
        };
        case Controller::First:
        {
            First_serializeStates(aomsState);
            break;
        };
        case Controller::Second:
        {
            Second_serializeStates(aomsState);
            break;
        };
        case Controller::Third:
        {
            Third_serializeStates(aomsState);
            break;
        };
        case Controller::Fourth:
        {
            Fourth_serializeStates(aomsState);
            break;
        };
        case Controller::Reverse:
        {
            Reverse_serializeStates(aomsState);
            break;
        };
        default:
            break;
    };
}

void OMAnimatedController::Third_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Third");
}

void OMAnimatedController::Second_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Second");
}

void OMAnimatedController::Reverse_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Reverse");
}

void OMAnimatedController::Idle_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Idle");
}

void OMAnimatedController::Fourth_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Fourth");
}

void OMAnimatedController::First_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.First");
}

IMPLEMENT_REACTIVE_META(Controller, TransmissionControlModels, FALSE, OMAnimatedController)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Controller.cpp
*********************************************************************/

