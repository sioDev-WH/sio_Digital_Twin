/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: DemoDrivetrainApp
//!	Generated Date	: Tue, 21, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\DemoDrivetrainApp.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "DemoDrivetrainApp.h"
#include "DemoDrivetrain_task_0100ms.h"
#include "EventBroadcast.h"
#include "OnDataCollector.h"
#include "Vehicle5.h"
#include "Driver.h"
#include "Controller.h"
#include "Chart.h"
#include "Actuator.h"
#include "CFrame.h"
#include "Oneway_Clutch.h"
#include "Band_Brake.h"
#include "Ravigneaux.h"
#include "Engine.h"
#include "Torque_Converter.h"
#include "DemoDrivetrain.h"
#include "DemoDrivetrainSubsystem.h"

//## package Application 


//#[ ignore 
#define Application_DemoDrivetrainApp_DemoDrivetrainApp_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrainApp_clean_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrainApp_handle_tick_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrainApp_init_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrainApp_setTime_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// DemoDrivetrainApp.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(Application)
//## class DemoDrivetrainApp 



DemoDrivetrainApp::DemoDrivetrainApp() {
    NOTIFY_CONSTRUCTOR(DemoDrivetrainApp, DemoDrivetrainApp(), 0, Application_DemoDrivetrainApp_DemoDrivetrainApp_SERIALIZE);
    task_0100ms = NULL;
    //#[ operation DemoDrivetrainApp() 
    
    init();
    //#]
}

DemoDrivetrainApp::~DemoDrivetrainApp() {
    NOTIFY_DESTRUCTOR(~DemoDrivetrainApp, TRUE);
    //#[ operation ~DemoDrivetrainApp() 
    
    clean();
    //#]
    cleanUpRelations();
}

void DemoDrivetrainApp::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, Application_DemoDrivetrainApp_clean_SERIALIZE);
    //#[ operation clean() 
    
    if (task_0100ms)
    {
      delete task_0100ms;
      task_0100ms = NULL;
    }
    
    //#]
}

void DemoDrivetrainApp::handle_tick() {
    NOTIFY_OPERATION(handle_tick, handle_tick(), 0, Application_DemoDrivetrainApp_handle_tick_SERIALIZE);
    //#[ operation handle_tick() 
    
      task_0100ms->handle_tick();
    //#]
}

void DemoDrivetrainApp::init() {
    NOTIFY_OPERATION(init, init(), 0, Application_DemoDrivetrainApp_init_SERIALIZE);
    //#[ operation init() 
    
    task_0100ms = new DemoDrivetrain_task_0100ms();
    
    
    // begin broadcaster / handler communication initialization
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsDriver->accelerator)
      ONI_LISTENER_IMPL(task_0100ms->itsDemoDrivetrainSubsystem, Engine, task_0100ms->itsDemoDrivetrainSubsystem->m_pSystemModel->itsEngine, handle_throttle)
      ONI_LISTENER_IMPL(task_0100ms->ShiftLogicController, Controller, task_0100ms->ShiftLogicController, handle_ThrottleData)
    ONI_END_BROADCAST_MAP()
    
    ONI_DATACOLLECTOR_MAP(task_0100ms->itsDemoDrivetrainSubsystem->itsEngine_RPM, task_0100ms->itsDemoDrivetrainSubsystem, task_0100ms->itsDemoDrivetrainSubsystem->itsEngine, RPM, task_0100ms->itsEngineChart, Chart, task_0100ms->itsEngineChart, handle_plotData)
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_DATACOLLECTOR_IMPL(task_0100ms->itsDemoDrivetrainSubsystem->Car_speed, task_0100ms->itsDemoDrivetrainSubsystem, task_0100ms->itsDemoDrivetrainSubsystem->Car, speed)
      ONI_LISTENER_IMPL_DC(task_0100ms->ShiftLogicController, Controller, task_0100ms->ShiftLogicController, handle_SpeedData)
      ONI_LISTENER_IMPL_DC(task_0100ms->SpeedChart, Chart, task_0100ms->SpeedChart, handle_plotData)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsDriver->brakes)
      ONI_LISTENER_IMPL(task_0100ms->itsDemoDrivetrainSubsystem, Vehicle5, task_0100ms->itsDemoDrivetrainSubsystem->m_pSystemModel->Car, handle_brakePedal)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsDriver->shiftLever)
      ONI_LISTENER_IMPL(task_0100ms->ShiftLogicController, Controller, task_0100ms->ShiftLogicController, handle_ShiftLeverData)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->ShiftLogicController->Port_6)
      ONI_LISTENER_IMPL(task_0100ms->itsDemoDrivetrainSubsystem, Actuator, task_0100ms->itsDemoDrivetrainSubsystem->m_pSystemModel->aDC, handle_shiftEvent)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->ShiftLogicController->Port_7)
      ONI_LISTENER_IMPL(task_0100ms->itsDemoDrivetrainSubsystem, Actuator, task_0100ms->itsDemoDrivetrainSubsystem->m_pSystemModel->aOB, handle_shiftEvent)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->ShiftLogicController->Port_4)
      ONI_LISTENER_IMPL(task_0100ms->itsDemoDrivetrainSubsystem, Actuator, task_0100ms->itsDemoDrivetrainSubsystem->m_pSystemModel->aIOC, handle_shiftEvent)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->ShiftLogicController->Port_3)
      ONI_LISTENER_IMPL(task_0100ms->itsDemoDrivetrainSubsystem, Actuator, task_0100ms->itsDemoDrivetrainSubsystem->m_pSystemModel->aPOC, handle_shiftEvent)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->ShiftLogicController->Port_2)
      ONI_LISTENER_IMPL(task_0100ms->itsDemoDrivetrainSubsystem, Actuator, task_0100ms->itsDemoDrivetrainSubsystem->m_pSystemModel->aFC, handle_shiftEvent)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->ShiftLogicController->Port_EngineStart)
      ONI_LISTENER_IMPL(task_0100ms->itsDemoDrivetrainSubsystem, Engine, task_0100ms->itsDemoDrivetrainSubsystem->m_pSystemModel->itsEngine, handle_Start)
    ONI_END_BROADCAST_MAP()
    
    // end broadcaster / handler communication initialization
    
    task_0100ms->broadcast();
    //#]
}

void DemoDrivetrainApp::setTime(const double  t) {
    NOTIFY_OPERATION(setTime, setTime(const double), 0, Application_DemoDrivetrainApp_setTime_SERIALIZE);
    //#[ operation setTime(const double) 
    
    task_0100ms->setTime(t);
    //#]
}

void DemoDrivetrainApp::cleanUpRelations() {
    if(task_0100ms != NULL)
        {
            NOTIFY_RELATION_CLEARED("task_0100ms");
            task_0100ms = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedDemoDrivetrainApp::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("task_0100ms", FALSE, TRUE);
    if(myReal->task_0100ms)
        aomsRelations->ADD_ITEM(myReal->task_0100ms);
}

IMPLEMENT_META(DemoDrivetrainApp, Application, FALSE, OMAnimatedDemoDrivetrainApp)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\DemoDrivetrainApp.cpp
*********************************************************************/

