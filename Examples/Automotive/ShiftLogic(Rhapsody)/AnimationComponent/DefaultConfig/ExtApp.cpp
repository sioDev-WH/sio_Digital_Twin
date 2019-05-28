/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: ExtApp
//!	Generated Date	: Thu, 19, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\ExtApp.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "ExtApp.h"
#include "ExtApp_task_0100ms.h"
#include "EventBroadcast.h"
#include "OnDataCollector.h"
#include "Actuator.h"
#include "CFrame.h"
#include "Band_Brake.h"
#include "Clutch.h"
#include "Chart.h"
#include "ShiftLever.h"
#include "Brakes.h"
#include "Throttle.h"
#include "Controller.h"
#include "Engine.h"
#include "Torque_Converter.h"
#include "Vehicle5.h"
#include "Ravigneaux.h"
#include "Oneway_Clutch.h"
#include "ExtCar.h"
#include "ExtCarSS.h"

//## package AppSimple 

//----------------------------------------------------------------------------
// ExtApp.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(AppSimple)
//## class ExtApp 



ExtApp::ExtApp() {
    task_0100ms = NULL;
    //#[ operation ExtApp() 
    
    init();
    //#]
}

ExtApp::~ExtApp() {
    //#[ operation ~ExtApp() 
    
    clean();
    //#]
    cleanUpRelations();
}

void ExtApp::clean() {
    //#[ operation clean() 
    
    if (task_0100ms)
    {
      delete task_0100ms;
      task_0100ms = NULL;
    }
    
    //#]
}

void ExtApp::handle_tick() {
    //#[ operation handle_tick() 
    
      task_0100ms->handle_tick();
    //#]
}

void ExtApp::init() {
    //#[ operation init() 
    
    task_0100ms = new ExtApp_task_0100ms();
    
    
    // begin broadcaster / handler communication initialization
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_LRB)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsExtCarSS, 
      /* TargetClass: */ Actuator, 
      /* TargetObject: */ task_0100ms->itsExtCarSS->m_pSystemModel->aLRB, 
      /* TargetOperation: */ handle_shiftEvent)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_RC)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsExtCarSS, 
      /* TargetClass: */ Actuator, 
      /* TargetObject: */ task_0100ms->itsExtCarSS->m_pSystemModel->aRC, 
      /* TargetOperation: */ handle_shiftEvent)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_FCN_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0100ms->itsExtCarSS, 
        /* SourceClass: */ Vehicle5, 
        /* SourceObject: */ task_0100ms->itsExtCarSS->m_pSystemModel->itsVehicle, 
        /* SourceFunction: */ getSpeed)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsShiftController, 
      /* TargetClass: */ Controller, 
      /* TargetObject: */ task_0100ms->itsShiftController, 
      /* TargetOperation: */ handle_SpeedData)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsSpeedChart, 
      /* TargetClass: */ Chart, 
      /* TargetObject: */ task_0100ms->itsSpeedChart, 
      /* TargetOperation: */ handle_plotData)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_EngineStart)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsExtCarSS, 
      /* TargetClass: */ Engine, 
      /* TargetObject: */ task_0100ms->itsExtCarSS->m_pSystemModel->itsEngine, 
      /* TargetOperation: */ handle_Start)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_FCN_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0100ms->itsThrottle, 
        /* SourceClass: */ Throttle, 
        /* SourceObject: */ task_0100ms->itsThrottle, 
        /* SourceFunction: */ getPosition)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsExtCarSS, 
      /* TargetClass: */ Engine, 
      /* TargetObject: */ task_0100ms->itsExtCarSS->m_pSystemModel->itsEngine, 
      /* TargetOperation: */ handle_throttle)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsShiftController, 
      /* TargetClass: */ Controller, 
      /* TargetObject: */ task_0100ms->itsShiftController, 
      /* TargetOperation: */ handle_ThrottleData)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_FCN_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0100ms->itsExtCarSS, 
        /* SourceClass: */ Engine, 
        /* SourceObject: */ task_0100ms->itsExtCarSS->m_pSystemModel->itsEngine, 
        /* SourceFunction: */ getRPM)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsRPMChart, 
      /* TargetClass: */ Chart, 
      /* TargetObject: */ task_0100ms->itsRPMChart, 
      /* TargetOperation: */ handle_plotData)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_OB)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsExtCarSS, 
      /* TargetClass: */ Actuator, 
      /* TargetObject: */ task_0100ms->itsExtCarSS->m_pSystemModel->aOB, 
      /* TargetOperation: */ handle_shiftEvent)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_DC)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsExtCarSS, 
      /* TargetClass: */ Actuator, 
      /* TargetObject: */ task_0100ms->itsExtCarSS->m_pSystemModel->aDC, 
      /* TargetOperation: */ handle_shiftEvent)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_IOC)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsExtCarSS, 
      /* TargetClass: */ Actuator, 
      /* TargetObject: */ task_0100ms->itsExtCarSS->m_pSystemModel->aIOC, 
      /* TargetOperation: */ handle_shiftEvent)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_POC)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsExtCarSS, 
      /* TargetClass: */ Actuator, 
      /* TargetObject: */ task_0100ms->itsExtCarSS->m_pSystemModel->aPOC, 
      /* TargetOperation: */ handle_shiftEvent)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_FC)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsExtCarSS, 
      /* TargetClass: */ Actuator, 
      /* TargetObject: */ task_0100ms->itsExtCarSS->m_pSystemModel->aFC, 
      /* TargetOperation: */ handle_shiftEvent)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_FCN_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0100ms->itsBrake, 
        /* SourceClass: */ Brakes, 
        /* SourceObject: */ task_0100ms->itsBrake, 
        /* SourceFunction: */ getPosition)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsExtCarSS, 
      /* TargetClass: */ Vehicle5, 
      /* TargetObject: */ task_0100ms->itsExtCarSS->m_pSystemModel->itsVehicle, 
      /* TargetOperation: */ handle_brakePedal)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_FCN_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0100ms->itsShiftLever, 
        /* SourceClass: */ ShiftLever, 
        /* SourceObject: */ task_0100ms->itsShiftLever, 
        /* SourceFunction: */ get_Position)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsShiftController, 
      /* TargetClass: */ Controller, 
      /* TargetObject: */ task_0100ms->itsShiftController, 
      /* TargetOperation: */ handle_ShiftLeverData)
    ONI_END_BROADCAST_MAP()
    
    // end broadcaster / handler communication initialization
    
    task_0100ms->broadcast();
    //#]
}

void ExtApp::setTime(const double  t) {
    //#[ operation setTime(const double) 
    
    task_0100ms->setTime(t);
    //#]
}

void ExtApp::cleanUpRelations() {
    if(task_0100ms != NULL)
        {
            NOTIFY_RELATION_CLEARED("task_0100ms");
            task_0100ms = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedExtApp::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("task_0100ms", FALSE, TRUE);
    if(myReal->task_0100ms)
        aomsRelations->ADD_ITEM(myReal->task_0100ms);
}

IMPLEMENT_META(ExtApp, AppSimple, FALSE, OMAnimatedExtApp)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\ExtApp.cpp
*********************************************************************/

