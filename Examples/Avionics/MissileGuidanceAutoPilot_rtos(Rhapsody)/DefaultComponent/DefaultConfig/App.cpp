/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: App
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\App.cpp
*********************************************************************/

#include "App.h"
#include "App_task_0001ms.h"
#include "App_task_0010ms.h"
#include "App_task_0040ms.h"
#include "EventBroadcast.h"
#include "OnDataCollector.h"
#include "Animation.h"
#include "TrackingSubsystem.h"
#include "Target.h"
#include "GuidanceLogic.h"
#include "EstimatorVc.h"
#include "EstimatorLOS.h"
#include "AutoPilot.h"
#include "aeroComposition.h"
#include "AppAirFrame.h"

//## package Default 

//----------------------------------------------------------------------------
// App.cpp                                                                  
//----------------------------------------------------------------------------
//## class App 



App::App() {
    task_0001ms = NULL;
    task_0010ms = NULL;
    task_0040ms = NULL;
    //#[ operation App() 
    
    init();
    //#]
}

App::~App() {
    //#[ operation ~App() 
    
    clean();
    //#]
    cleanUpRelations();
}

void App::clean() {
    //#[ operation clean() 
    
    if (task_0040ms)
    {
      delete task_0040ms;
      task_0040ms = NULL;
    }
    
    if (task_0010ms)
    {
      delete task_0010ms;
      task_0010ms = NULL;
    }
    
    if (task_0001ms)
    {
      delete task_0001ms;
      task_0001ms = NULL;
    }
    
    //#]
}

void App::handle_tick() {
    //#[ operation handle_tick() 
    
      task_0040ms->handle_tick();
      task_0010ms->handle_tick();
      task_0001ms->handle_tick();
    //#]
}

void App::init() {
    //#[ operation init() 
    
    task_0040ms = new App_task_0040ms();
    
    task_0010ms = new App_task_0010ms();
    
    task_0001ms = new App_task_0001ms();
    
    // KAB

    // begin broadcaster / handler communication initialization
    ONI_BEGIN_EVENT_BROADCAST_MAP()
      ONI_EVENT_BROADCASTER_ENTRY(task_0010ms->TrackingSubsystemBlock->evToGuidance)
      ONI_EVENT_LISTENER_IMPL(
        /* TargetCompositeObject: */ task_0010ms->GuidanceLogicBlock, 
        /* TargetClass: */ GuidanceLogic, 
        /* TargetObject: */ task_0010ms->GuidanceLogicBlock)
    ONI_END_EVENT_BROADCAST_MAP()

    // KAB
    

    // begin broadcaster / handler communication initialization
    ONI_BEGIN_BROADCAST_MAP(int)
      ONI_SCALAR_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* SourceObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* SourceAttribute: */ bTargetAcquired)
      ONI_ATTR_LISTENER_IMPL(
        /* TargetCompositeObject: */ task_0010ms->EstimatorVcBlock, 
        /* TargetClass: */ EstimatorVc, 
        /* TargetObject: */ task_0010ms->EstimatorVcBlock, 
        /* TargetAttribute: */ bTargetAcquired)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_SCALAR_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* SourceObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* SourceAttribute: */ dishError)
      ONI_ATTR_LISTENER_IMPL(
        /* TargetCompositeObject: */ task_0040ms->EstimatorLOSBlock, 
        /* TargetClass: */ EstimatorLOS, 
        /* TargetObject: */ task_0040ms->EstimatorLOSBlock, 
        /* TargetAttribute: */ epsilon)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_FCN_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* SourceClass: */ TrackingSubsystem, 
        /* SourceObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* SourceFunction: */ getQS)
      ONI_ATTR_LISTENER_IMPL(
        /* TargetCompositeObject: */ task_0040ms->EstimatorLOSBlock, 
        /* TargetClass: */ EstimatorLOS, 
        /* TargetObject: */ task_0040ms->EstimatorLOSBlock, 
        /* TargetAttribute: */ qs)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(int)
      ONI_SCALAR_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0010ms->GuidanceLogicBlock, 
        /* SourceObject: */ task_0010ms->GuidanceLogicBlock, 
        /* SourceAttribute: */ guidanceMode)
      ONI_ATTR_LISTENER_IMPL(
        /* TargetCompositeObject: */ task_0040ms->EstimatorLOSBlock, 
        /* TargetClass: */ EstimatorLOS, 
        /* TargetObject: */ task_0040ms->EstimatorLOSBlock, 
        /* TargetAttribute: */ guidanceMode)
      ONI_ATTR_LISTENER_IMPL(
        /* TargetCompositeObject: */ task_0040ms->AnimationBlock, 
        /* TargetClass: */ Animation, 
        /* TargetObject: */ task_0040ms->AnimationBlock, 
        /* TargetAttribute: */ guidanceMode)
      ONI_ATTR_LISTENER_IMPL(
        /* TargetCompositeObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* TargetClass: */ TrackingSubsystem, 
        /* TargetObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* TargetAttribute: */ guidanceMode)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_FCN_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0001ms->itsAppAirFrame, 
        /* SourceClass: */ aeroComposition, 
        /* SourceObject: */ task_0001ms->itsAppAirFrame->m_pSystemModel, 
        /* SourceFunction: */ bodyDynamicsBlock_getAttitude)
      ONI_ATTR_LISTENER_IMPL(
        /* TargetCompositeObject: */ task_0040ms->AnimationBlock, 
        /* TargetClass: */ Animation, 
        /* TargetObject: */ task_0040ms->AnimationBlock, 
        /* TargetAttribute: */ missile_attitude)
      ONI_ATTR_LISTENER_IMPL(
        /* TargetCompositeObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* TargetClass: */ TrackingSubsystem, 
        /* TargetObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* TargetAttribute: */ missile_Attitude_Data)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_SCALAR_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* SourceObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* SourceAttribute: */ gimbalAngle)
      ONI_ATTR_LISTENER_IMPL(
        /* TargetCompositeObject: */ task_0040ms->AnimationBlock, 
        /* TargetClass: */ Animation, 
        /* TargetObject: */ task_0040ms->AnimationBlock, 
        /* TargetAttribute: */ dishAngle)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_SCALAR_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0010ms->GuidanceLogicBlock, 
        /* SourceObject: */ task_0010ms->GuidanceLogicBlock, 
        /* SourceAttribute: */ dishAngleCommand)
      ONI_ATTR_LISTENER_IMPL(
        /* TargetCompositeObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* TargetClass: */ TrackingSubsystem, 
        /* TargetObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* TargetAttribute: */ dishCommand)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_SCALAR_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0010ms->TargetBlock, 
        /* SourceObject: */ task_0010ms->TargetBlock, 
        /* SourceAttribute: */ z)
      ONI_ATTR_LISTENER_IMPL(
        /* TargetCompositeObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* TargetClass: */ TrackingSubsystem, 
        /* TargetObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* TargetAttribute: */ target_Z_Data)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_SCALAR_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0010ms->TargetBlock, 
        /* SourceObject: */ task_0010ms->TargetBlock, 
        /* SourceAttribute: */ x)
      ONI_ATTR_LISTENER_IMPL(
        /* TargetCompositeObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* TargetClass: */ TrackingSubsystem, 
        /* TargetObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* TargetAttribute: */ target_X_Data)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_FCN_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0001ms->itsAppAirFrame, 
        /* SourceClass: */ aeroComposition, 
        /* SourceObject: */ task_0001ms->itsAppAirFrame->m_pSystemModel, 
        /* SourceFunction: */ bodyDynamicsBlock_getX)
      ONI_ATTR_LISTENER_IMPL(
        /* TargetCompositeObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* TargetClass: */ TrackingSubsystem, 
        /* TargetObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* TargetAttribute: */ missile_X_Data)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_FCN_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0001ms->itsAppAirFrame, 
        /* SourceClass: */ aeroComposition, 
        /* SourceObject: */ task_0001ms->itsAppAirFrame->m_pSystemModel, 
        /* SourceFunction: */ bodyDynamicsBlock_getZ)
      ONI_ATTR_LISTENER_IMPL(
        /* TargetCompositeObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* TargetClass: */ TrackingSubsystem, 
        /* TargetObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* TargetAttribute: */ missile_Z_Data)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_FCN_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0001ms->itsAppAirFrame, 
        /* SourceClass: */ aeroComposition, 
        /* SourceObject: */ task_0001ms->itsAppAirFrame->m_pSystemModel, 
        /* SourceFunction: */ bodyDynamicsBlock_getGyro)
      ONI_ATTR_LISTENER_IMPL(
        /* TargetCompositeObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* TargetClass: */ TrackingSubsystem, 
        /* TargetObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* TargetAttribute: */ missile_Gyro_Data)
      ONI_ATTR_LISTENER_IMPL(
        /* TargetCompositeObject: */ task_0001ms->AutoPilotBlock, 
        /* TargetClass: */ AutoPilot, 
        /* TargetObject: */ task_0001ms->AutoPilotBlock, 
        /* TargetAttribute: */ gyroData)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_SCALAR_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* SourceObject: */ task_0010ms->TrackingSubsystemBlock, 
        /* SourceAttribute: */ range)
      ONI_ATTR_LISTENER_IMPL(
        /* TargetCompositeObject: */ task_0010ms->GuidanceLogicBlock, 
        /* TargetClass: */ GuidanceLogic, 
        /* TargetObject: */ task_0010ms->GuidanceLogicBlock, 
        /* TargetAttribute: */ Range)
      ONI_ATTR_LISTENER_IMPL(
        /* TargetCompositeObject: */ task_0010ms->EstimatorVcBlock, 
        /* TargetClass: */ EstimatorVc, 
        /* TargetObject: */ task_0010ms->EstimatorVcBlock, 
        /* TargetAttribute: */ Range)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_SCALAR_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0040ms->EstimatorLOSBlock, 
        /* SourceObject: */ task_0040ms->EstimatorLOSBlock, 
        /* SourceAttribute: */ LOSRate)
      ONI_ATTR_LISTENER_IMPL(
        /* TargetCompositeObject: */ task_0010ms->GuidanceLogicBlock, 
        /* TargetClass: */ GuidanceLogic, 
        /* TargetObject: */ task_0010ms->GuidanceLogicBlock, 
        /* TargetAttribute: */ LOSRate)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_SCALAR_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0010ms->EstimatorVcBlock, 
        /* SourceObject: */ task_0010ms->EstimatorVcBlock, 
        /* SourceAttribute: */ Vc)
      ONI_ATTR_LISTENER_IMPL(
        /* TargetCompositeObject: */ task_0010ms->GuidanceLogicBlock, 
        /* TargetClass: */ GuidanceLogic, 
        /* TargetObject: */ task_0010ms->GuidanceLogicBlock, 
        /* TargetAttribute: */ closingVelocity)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_SCALAR_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0010ms->GuidanceLogicBlock, 
        /* SourceObject: */ task_0010ms->GuidanceLogicBlock, 
        /* SourceAttribute: */ Az_Demand)
      ONI_ATTR_LISTENER_IMPL(
        /* TargetCompositeObject: */ task_0001ms->AutoPilotBlock, 
        /* TargetClass: */ AutoPilot, 
        /* TargetObject: */ task_0001ms->AutoPilotBlock, 
        /* TargetAttribute: */ command)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_FCN_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0001ms->itsAppAirFrame, 
        /* SourceClass: */ aeroComposition, 
        /* SourceObject: */ task_0001ms->itsAppAirFrame->m_pSystemModel, 
        /* SourceFunction: */ bodyDynamicsBlock_getAccel)
      ONI_ATTR_LISTENER_IMPL(
        /* TargetCompositeObject: */ task_0001ms->AutoPilotBlock, 
        /* TargetClass: */ AutoPilot, 
        /* TargetObject: */ task_0001ms->AutoPilotBlock, 
        /* TargetAttribute: */ accelData)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_FCN_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0001ms->itsAppAirFrame, 
        /* SourceClass: */ aeroComposition, 
        /* SourceObject: */ task_0001ms->itsAppAirFrame->m_pSystemModel, 
        /* SourceFunction: */ aeroDynamicsBlock_getAlpha)
      ONI_ATTR_LISTENER_IMPL(
        /* TargetCompositeObject: */ task_0001ms->AutoPilotBlock, 
        /* TargetClass: */ AutoPilot, 
        /* TargetObject: */ task_0001ms->AutoPilotBlock, 
        /* TargetAttribute: */ Alpha)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_FCN_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0001ms->itsAppAirFrame, 
        /* SourceClass: */ aeroComposition, 
        /* SourceObject: */ task_0001ms->itsAppAirFrame->m_pSystemModel, 
        /* SourceFunction: */ aeroDynamicsBlock_getMach)
      ONI_ATTR_LISTENER_IMPL(
        /* TargetCompositeObject: */ task_0001ms->AutoPilotBlock, 
        /* TargetClass: */ AutoPilot, 
        /* TargetObject: */ task_0001ms->AutoPilotBlock, 
        /* TargetAttribute: */ Mach)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_SCALAR_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0001ms->AutoPilotBlock, 
        /* SourceObject: */ task_0001ms->AutoPilotBlock, 
        /* SourceAttribute: */ Fin)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0001ms->itsAppAirFrame, 
      /* TargetClass: */ aeroComposition, 
      /* TargetObject: */ task_0001ms->itsAppAirFrame->m_pSystemModel, 
      /* TargetOperation: */ finDynamics_handle_AngleSetpoint)
    ONI_END_BROADCAST_MAP()
    
    // end broadcaster / handler communication initialization
    
    task_0040ms->broadcast();
    task_0010ms->broadcast();
    task_0001ms->broadcast();
    //#]
}

void App::setTime(const double  t) {
    //#[ operation setTime(const double) 
    
    task_0040ms->setTime(t);
    task_0010ms->setTime(t);
    task_0001ms->setTime(t);
    //#]
}

void App::cleanUpRelations() {
    if(task_0001ms != NULL)
        {
            task_0001ms = NULL;
        }
    if(task_0010ms != NULL)
        {
            task_0010ms = NULL;
        }
    if(task_0040ms != NULL)
        {
            task_0040ms = NULL;
        }
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\App.cpp
*********************************************************************/

