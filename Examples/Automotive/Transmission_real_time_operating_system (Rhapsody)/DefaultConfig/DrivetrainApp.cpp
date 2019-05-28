/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: DrivetrainApp
//!	Generated Date	: Mon, 20, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\DrivetrainApp.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "DrivetrainApp.h"
#include "DrivetrainApp_task_0100ms.h"
#include "OnDataCollector.h"
#include "EventBroadcast.h"
#include "Chart.h"
#include "Throttle.h"
#include "Controller.h"
#include "Actuator.h"
#include "Vehicle5.h"
#include "CFrame.h"
#include "Oneway_Clutch.h"
#include "Band_Brake.h"
#include "Ravigneaux.h"
#include "Engine.h"
#include "Torque_Converter.h"
#include "Drivetrain.h"
#include "DrivetrainSubsystem.h"

//## package Application 


//#[ ignore 
#define Application_DrivetrainApp_DrivetrainApp_SERIALIZE OM_NO_OP


#define Application_DrivetrainApp_clean_SERIALIZE OM_NO_OP


#define Application_DrivetrainApp_handle_tick_SERIALIZE OM_NO_OP


#define Application_DrivetrainApp_init_SERIALIZE OM_NO_OP


#define Application_DrivetrainApp_setTime_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// DrivetrainApp.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(Application)
//## class DrivetrainApp 



DrivetrainApp::DrivetrainApp() {
    NOTIFY_CONSTRUCTOR(DrivetrainApp, DrivetrainApp(), 0, Application_DrivetrainApp_DrivetrainApp_SERIALIZE);
    task_0100ms = NULL;
    //#[ operation DrivetrainApp() 
    
    init();
    //#]
}

DrivetrainApp::~DrivetrainApp() {
    NOTIFY_DESTRUCTOR(~DrivetrainApp, TRUE);
    //#[ operation ~DrivetrainApp() 
    
    clean();
    //#]
    cleanUpRelations();
}

void DrivetrainApp::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, Application_DrivetrainApp_clean_SERIALIZE);
    //#[ operation clean() 
    
    if (task_0100ms)
    {
      delete task_0100ms;
      task_0100ms = NULL;
    }
    
    //#]
}

void DrivetrainApp::handle_tick() {
    NOTIFY_OPERATION(handle_tick, handle_tick(), 0, Application_DrivetrainApp_handle_tick_SERIALIZE);
    //#[ operation handle_tick() 
    
      task_0100ms->handle_tick();
    //#]
}

void DrivetrainApp::init() {
    NOTIFY_OPERATION(init, init(), 0, Application_DrivetrainApp_init_SERIALIZE);
    //#[ operation init() 
    
    task_0100ms = new DrivetrainApp_task_0100ms();
    
    
    // begin broadcaster / handler communication initialization
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_DATACOLLECTOR_IMPL(task_0100ms->itsDrivetrainSubsystem->itsCar_speed, task_0100ms->itsDrivetrainSubsystem, task_0100ms->itsDrivetrainSubsystem->itsCar, speed)
      ONI_LISTENER_IMPL_DC(task_0100ms->SpeedChart, Chart, task_0100ms->SpeedChart, handle_plotData)
      ONI_LISTENER_IMPL_DC(task_0100ms->itsController, Controller, task_0100ms->itsController, handle_SpeedData)
    ONI_END_BROADCAST_MAP()
    
    ONI_DATACOLLECTOR_MAP(task_0100ms->itsDrivetrainSubsystem->itsEngine_RPM, task_0100ms->itsDrivetrainSubsystem, task_0100ms->itsDrivetrainSubsystem->itsEngine, RPM, task_0100ms->itsEngineChart, Chart, task_0100ms->itsEngineChart, handle_plotData)
    
    ONI_FCN_BROADCAST_MAP(double, task_0100ms->itsThrottle, Throttle, task_0100ms->itsThrottle, getPosition, task_0100ms->itsController, Controller, task_0100ms->itsController, handle_ThrottleData)
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsController->Port_6)
      ONI_LISTENER_IMPL(task_0100ms->itsDrivetrainSubsystem, Actuator, task_0100ms->itsDrivetrainSubsystem->m_pSystemModel->aDC, handle_shiftEvent)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsController->Port_7)
      ONI_LISTENER_IMPL(task_0100ms->itsDrivetrainSubsystem, Actuator, task_0100ms->itsDrivetrainSubsystem->m_pSystemModel->aOB, handle_shiftEvent)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsController->Port_4)
      ONI_LISTENER_IMPL(task_0100ms->itsDrivetrainSubsystem, Actuator, task_0100ms->itsDrivetrainSubsystem->m_pSystemModel->aIOC, handle_shiftEvent)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsController->Port_3)
      ONI_LISTENER_IMPL(task_0100ms->itsDrivetrainSubsystem, Actuator, task_0100ms->itsDrivetrainSubsystem->m_pSystemModel->aPOC, handle_shiftEvent)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsController->Port_2)
      ONI_LISTENER_IMPL(task_0100ms->itsDrivetrainSubsystem, Actuator, task_0100ms->itsDrivetrainSubsystem->m_pSystemModel->aFC, handle_shiftEvent)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsController->Port_EngineStart)
      ONI_LISTENER_IMPL(task_0100ms->itsDrivetrainSubsystem, Engine, task_0100ms->itsDrivetrainSubsystem->m_pSystemModel->itsEngine, handle_Start)
    ONI_END_BROADCAST_MAP()
    
    
    // end broadcaster / handler communication initialization
    
    task_0100ms->broadcast();
    //#]
}

void DrivetrainApp::setTime(const double  t) {
    NOTIFY_OPERATION(setTime, setTime(const double), 0, Application_DrivetrainApp_setTime_SERIALIZE);
    //#[ operation setTime(const double) 
    
    task_0100ms->setTime(t);
    //#]
}

void DrivetrainApp::cleanUpRelations() {
    if(task_0100ms != NULL)
        {
            NOTIFY_RELATION_CLEARED("task_0100ms");
            task_0100ms = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedDrivetrainApp::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("task_0100ms", FALSE, TRUE);
    if(myReal->task_0100ms)
        aomsRelations->ADD_ITEM(myReal->task_0100ms);
}

IMPLEMENT_META(DrivetrainApp, Application, FALSE, OMAnimatedDrivetrainApp)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\DrivetrainApp.cpp
*********************************************************************/

