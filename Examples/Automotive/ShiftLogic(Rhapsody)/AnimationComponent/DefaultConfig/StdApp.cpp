/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: StdApp
//!	Generated Date	: Wed, 18, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\StdApp.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "StdApp.h"
#include "StdApp_task_0100ms.h"
#include "EventBroadcast.h"
#include "OnDataCollector.h"
#include "Chart.h"
#include "ShiftLever.h"
#include "Brakes.h"
#include "Throttle.h"
#include "Controller.h"
#include "Engine.h"
#include "CFrame.h"
#include "Torque_Converter.h"
#include "Vehicle5.h"
#include "Ravigneaux.h"
#include "Actuator.h"
#include "Oneway_Clutch.h"
#include "Band_Brake.h"
#include "StdCar.h"
#include "StdCarSS.h"

//## package AppSimple 

//----------------------------------------------------------------------------
// StdApp.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(AppSimple)
//## class StdApp 



StdApp::StdApp() {
    task_0100ms = NULL;
    //#[ operation StdApp() 
    
    init();
    //#]
}

StdApp::~StdApp() {
    //#[ operation ~StdApp() 
    
    clean();
    //#]
    cleanUpRelations();
}

void StdApp::clean() {
    //#[ operation clean() 
    
    if (task_0100ms)
    {
      delete task_0100ms;
      task_0100ms = NULL;
    }
    
    //#]
}

void StdApp::handle_tick() {
    //#[ operation handle_tick() 
    
      task_0100ms->handle_tick();
    //#]
}

 StdApp::init() {
    //#[ operation init() 
    
    task_0100ms = new StdApp_task_0100ms();
    
    
    // begin broadcaster / handler communication initialization
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_FCN_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0100ms->itsStdCarSS, 
        /* SourceClass: */ Vehicle5, 
        /* SourceObject: */ task_0100ms->itsStdCarSS->m_pSystemModel->itsVehicle, 
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
      /* TargetCompositeObject: */ task_0100ms->itsStdCarSS, 
      /* TargetClass: */ Engine, 
      /* TargetObject: */ task_0100ms->itsStdCarSS->m_pSystemModel->itsEngine, 
      /* TargetOperation: */ handle_Start)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_FCN_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0100ms->itsThrottle, 
        /* SourceClass: */ Throttle, 
        /* SourceObject: */ task_0100ms->itsThrottle, 
        /* SourceFunction: */ getPosition)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsStdCarSS, 
      /* TargetClass: */ Engine, 
      /* TargetObject: */ task_0100ms->itsStdCarSS->m_pSystemModel->itsEngine, 
      /* TargetOperation: */ handle_throttle)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsShiftController, 
      /* TargetClass: */ Controller, 
      /* TargetObject: */ task_0100ms->itsShiftController, 
      /* TargetOperation: */ handle_ThrottleData)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_FCN_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0100ms->itsStdCarSS, 
        /* SourceClass: */ Engine, 
        /* SourceObject: */ task_0100ms->itsStdCarSS->m_pSystemModel->itsEngine, 
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
      /* TargetCompositeObject: */ task_0100ms->itsStdCarSS, 
      /* TargetClass: */ Actuator, 
      /* TargetObject: */ task_0100ms->itsStdCarSS->m_pSystemModel->aOB, 
      /* TargetOperation: */ handle_shiftEvent)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_DC)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsStdCarSS, 
      /* TargetClass: */ Actuator, 
      /* TargetObject: */ task_0100ms->itsStdCarSS->m_pSystemModel->aDC, 
      /* TargetOperation: */ handle_shiftEvent)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_IOC)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsStdCarSS, 
      /* TargetClass: */ Actuator, 
      /* TargetObject: */ task_0100ms->itsStdCarSS->m_pSystemModel->aIOC, 
      /* TargetOperation: */ handle_shiftEvent)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_POC)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsStdCarSS, 
      /* TargetClass: */ Actuator, 
      /* TargetObject: */ task_0100ms->itsStdCarSS->m_pSystemModel->aPOC, 
      /* TargetOperation: */ handle_shiftEvent)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_FC)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsStdCarSS, 
      /* TargetClass: */ Actuator, 
      /* TargetObject: */ task_0100ms->itsStdCarSS->m_pSystemModel->aFC, 
      /* TargetOperation: */ handle_shiftEvent)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_FCN_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0100ms->itsBrake, 
        /* SourceClass: */ Brakes, 
        /* SourceObject: */ task_0100ms->itsBrake, 
        /* SourceFunction: */ getPosition)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsStdCarSS, 
      /* TargetClass: */ Vehicle5, 
      /* TargetObject: */ task_0100ms->itsStdCarSS->m_pSystemModel->itsVehicle, 
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

void StdApp::setTime(const double  t) {
    //#[ operation setTime(const double) 
    
    task_0100ms->setTime(t);
    //#]
}

void StdApp::cleanUpRelations() {
    if(task_0100ms != NULL)
        {
            NOTIFY_RELATION_CLEARED("task_0100ms");
            task_0100ms = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedStdApp::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("task_0100ms", FALSE, TRUE);
    if(myReal->task_0100ms)
        aomsRelations->ADD_ITEM(myReal->task_0100ms);
}

IMPLEMENT_META(StdApp, AppSimple, FALSE, OMAnimatedStdApp)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\StdApp.cpp
*********************************************************************/

