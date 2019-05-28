/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Controller
//!	Generated Date	: Wed, 11, Jun 2003  
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


#define TransmissionControlModels_Controller_duringGear_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_enterGear_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_handle_ShiftLeverData_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_handle_SpeedData_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_handle_ThrottleData_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_handle_tick_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_init_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_runShiftLogic_SERIALIZE OM_NO_OP


#define TransmissionControlModels_Controller_updateThresholds_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// Controller.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(TransmissionControlModels)
//## class Controller 



Controller::Controller(OMThread*  p_thread) : Port_RC(NULL) ,Port_LRB(NULL) ,Port_FC(NULL) ,Port_POC(NULL) ,Port_IOC(NULL) ,Port_TCC(NULL) ,Port_DC(NULL) ,Port_OB(NULL) ,shiftTime(0.0) ,Port_EngineStart(NULL) ,bEngineStarted(false) {
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
    
    //#]
}

Controller::~Controller() {
    NOTIFY_DESTRUCTOR(~Controller, TRUE);
    //#[ operation ~Controller() 
    clean();
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
    long engageMsg = 0;
    for(i=0;i<shiftData.clutchSchedule->nClutches;i++)
    if(shiftData.clutchSchedule->disengageList[i])
    {
      pActuatorPorts[i]->gen(&engageMsg);
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
      pActuatorPorts[i]->gen(&engageMsg);
    }
    
    //#]
}

bool Controller::Load(FILE * fs) {
    NOTIFY_OPERATION(Load, Load(FILE * ), 0, TransmissionControlModels_Controller_Load_SERIALIZE);
    //#[ operation Load(FILE * ) 
    long count = 6;
    
    READ_SCALAR( bEngineStarted )     
    READ_SCALAR( currentGear )     
    READ_VECTOR( downshiftDelay, double, count );
    READ_SCALAR( downShiftThreshold )     
    
    READ_SCALAR( shiftLeverData )
    READ_SCALAR( shiftTime )
    READ_SCALAR( throttleData )
    READ_VECTOR( upshiftDelay, double, count );
    READ_SCALAR( upShiftThreshold )
    READ_SCALAR( vehicleSpeedData )  
    
    // restore state machine implementation state variables
    READ_SCALAR( rootState_subState )
    READ_SCALAR( rootState_active )
    
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
    long count = 5;
    
    WRITE_SCALAR( bEngineStarted )     
    WRITE_SCALAR( currentGear )     
    WRITE_VECTOR( downshiftDelay, double, count );
    WRITE_SCALAR( downShiftThreshold )     
    
    WRITE_SCALAR( shiftLeverData )
    WRITE_SCALAR( shiftTime )
    WRITE_SCALAR( throttleData )
    WRITE_VECTOR( upshiftDelay, double, count );
    WRITE_SCALAR( upShiftThreshold )
    WRITE_SCALAR( vehicleSpeedData )  
    
    // save state machine implementation state variables
    WRITE_SCALAR( rootState_subState )
    WRITE_SCALAR( rootState_active )
    
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
    	for (long i = 0; i < 8; i++)
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

void Controller::duringGear() {
    NOTIFY_OPERATION(duringGear, duringGear(), 0, TransmissionControlModels_Controller_duringGear_SERIALIZE);
    //#[ operation duringGear() 
    if (targetGear != currentGear)
    {
    	double shiftDelay;
    	if (targetGear > currentGear)
    		shiftDelay = upshiftDelay[targetGear+1];
    	else
    		shiftDelay = downshiftDelay[targetGear+1];
    
    	shiftTime += getPeriod() / 1000.0;	
    	if ( shiftTime >= shiftDelay )
    	{  
    		shiftData.clutchSchedule->updateEngage(currentGear,targetGear);
    		Fire_EngageEvents();  
    		currentGear = targetGear;
    	}
    }   
    runShiftLogic();
    //#]
}

void Controller::enterGear(int  iState) {
    NOTIFY_OPERATION(enterGear, enterGear(int), 0, TransmissionControlModels_Controller_enterGear_SERIALIZE);
    //#[ operation enterGear(int) 
    shiftTime = 0.0; 
    targetGear = iState;
    shiftData.clutchSchedule->updateDisengage( currentGear, targetGear );
    Fire_DisengageEvents();
    updateThresholds( targetGear );
    
    //#]
}

void Controller::handle_ShiftLeverData(long * val) {
    NOTIFY_OPERATION(handle_ShiftLeverData, handle_ShiftLeverData(long * ), 0, TransmissionControlModels_Controller_handle_ShiftLeverData_SERIALIZE);
    //#[ operation handle_ShiftLeverData(long * ) 
    if (shiftLeverData != *val)
    {
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
    if (throttleData != *val)
    {
    	throttleData = *val;
    	updateThresholds( targetGear );
    }
    //#]
}

void Controller::handle_tick() {
    NOTIFY_OPERATION(handle_tick, handle_tick(), 0, TransmissionControlModels_Controller_handle_tick_SERIALIZE);
    //#[ operation handle_tick() 
      // start the engine if it has not already been started
      if (!bEngineStarted)
      {
        long engineStart = 1;
        Port_EngineStart->gen(&engineStart);
        bEngineStarted = true;
      }
    
      receive(); 
      duringGear();
      broadcast();
    
    //#]
}

void Controller::init() {
    NOTIFY_OPERATION(init, init(), 0, TransmissionControlModels_Controller_init_SERIALIZE);
    //#[ operation init() 
    m_cRef = 0;
    
    // index = target gear + 1
    upshiftDelay[0] = 0.0; // N/A (to reverse)
    upshiftDelay[1] = 0.0; // reverse to neutral
    upshiftDelay[2] = 0.0; // neutral to first
    upshiftDelay[3] = 0.0; // first to second
    upshiftDelay[4] = 0.0; // second to third
    upshiftDelay[5] = 0.1; // third to fourth
    
    // index = target gear + 1
    downshiftDelay[0] = 0.0; // neutral to reverse
    downshiftDelay[1] = 0.2; // first to neutral
    downshiftDelay[2] = 0.2; // second to first
    downshiftDelay[3] = 0.2; // third to second
    downshiftDelay[4] = 0.2; // fourth to third
    downshiftDelay[5] = 0.0; // N/A (to fourth)
    
    currentGear=0;  
    targetGear=0;
    throttleData=0.0;
    vehicleSpeedData=0.0;
    shiftLeverData=0; // for N; +/-1 for D and R
    shiftData.init();
    
    for (long i = 0; i < 8; i++)
    {
      pActuatorPorts[i] = new Port_Int();
      pActuatorPorts[i]->AddRef();
    }
    
    Port_EngineStart = new Port_Int();
    Port_EngineStart->AddRef();
    
    Port_RC = pActuatorPorts[0];
    Port_LRB = pActuatorPorts[1];
    Port_FC = pActuatorPorts[2];
    Port_POC = pActuatorPorts[3];
    Port_IOC = pActuatorPorts[4];
    Port_TCC = pActuatorPorts[5];
    Port_DC = pActuatorPorts[6];
    Port_OB = pActuatorPorts[7];
    
    //#]
}

void Controller::runShiftLogic() {
    NOTIFY_OPERATION(runShiftLogic, runShiftLogic(), 0, TransmissionControlModels_Controller_runShiftLogic_SERIALIZE);
    //#[ operation runShiftLogic() 
    if (targetGear >= 1)
    {
    	if(vehicleSpeedData <= downShiftThreshold && targetGear > 1)
    	{
    	  currentGear = targetGear;
    	  downshift ev;
    	  takeTrigger(&ev);
    	}
    	else if(vehicleSpeedData > upShiftThreshold && targetGear < 4)
    	{
    	  currentGear = targetGear;
    	  upshift ev;
    	  takeTrigger(&ev);
    	}
    }
    //#]
}

void Controller::updateThresholds(int  iState) {
    NOTIFY_OPERATION(updateThresholds, updateThresholds(int), 0, TransmissionControlModels_Controller_updateThresholds_SERIALIZE);
    //#[ operation updateThresholds(int) 
    shiftData.getDownShiftThreshold (throttleData, iState, &downShiftThreshold);
    shiftData.getUpShiftThreshold(throttleData, iState, &upShiftThreshold);
    
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
        NOTIFY_TRANSITION_STARTED("3");
        NOTIFY_STATE_ENTERED("ROOT.Idle");
        rootState_subState = Idle;
        rootState_active = Idle;
        //#[ state ROOT.Idle.(Entry) 
        enterGear(0);
        //#]
        NOTIFY_TRANSITION_TERMINATED("3");
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
                    enterGear(-1);
                    
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
                    enterGear(1);
                    
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("0");
                    res = eventConsumed;
                }
            
            break;
        };
        case First:
        {
            if(IS_EVENT_TYPE_OF(manualNeutralShift_TransmissionControlModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("10");
                    NOTIFY_STATE_EXITED("ROOT.First");
                    NOTIFY_STATE_ENTERED("ROOT.Idle");
                    rootState_subState = Idle;
                    rootState_active = Idle;
                    //#[ state ROOT.Idle.(Entry) 
                    enterGear(0);
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("10");
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(upshift_TransmissionControlModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("4");
                    NOTIFY_STATE_EXITED("ROOT.First");
                    NOTIFY_STATE_ENTERED("ROOT.Second");
                    rootState_subState = Second;
                    rootState_active = Second;
                    //#[ state ROOT.Second.(Entry) 
                    enterGear(2);
                    
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("4");
                    res = eventConsumed;
                }
            
            break;
        };
        case Second:
        {
            if(IS_EVENT_TYPE_OF(downshift_TransmissionControlModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("9");
                    NOTIFY_STATE_EXITED("ROOT.Second");
                    NOTIFY_STATE_ENTERED("ROOT.First");
                    rootState_subState = First;
                    rootState_active = First;
                    //#[ state ROOT.First.(Entry) 
                    enterGear(1);
                    
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("9");
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(upshift_TransmissionControlModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("5");
                    NOTIFY_STATE_EXITED("ROOT.Second");
                    NOTIFY_STATE_ENTERED("ROOT.Third");
                    rootState_subState = Third;
                    rootState_active = Third;
                    //#[ state ROOT.Third.(Entry) 
                    enterGear(3);
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("5");
                    res = eventConsumed;
                }
            
            break;
        };
        case Third:
        {
            if(IS_EVENT_TYPE_OF(downshift_TransmissionControlModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("8");
                    NOTIFY_STATE_EXITED("ROOT.Third");
                    NOTIFY_STATE_ENTERED("ROOT.Second");
                    rootState_subState = Second;
                    rootState_active = Second;
                    //#[ state ROOT.Second.(Entry) 
                    enterGear(2);
                    
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("8");
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(upshift_TransmissionControlModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("6");
                    NOTIFY_STATE_EXITED("ROOT.Third");
                    NOTIFY_STATE_ENTERED("ROOT.Fourth");
                    rootState_subState = Fourth;
                    rootState_active = Fourth;
                    //#[ state ROOT.Fourth.(Entry) 
                    enterGear(4);
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("6");
                    res = eventConsumed;
                }
            
            break;
        };
        case Fourth:
        {
            if(IS_EVENT_TYPE_OF(downshift_TransmissionControlModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("7");
                    NOTIFY_STATE_EXITED("ROOT.Fourth");
                    NOTIFY_STATE_ENTERED("ROOT.Third");
                    rootState_subState = Third;
                    rootState_active = Third;
                    //#[ state ROOT.Third.(Entry) 
                    enterGear(3);
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("7");
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
                    enterGear(0);
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

