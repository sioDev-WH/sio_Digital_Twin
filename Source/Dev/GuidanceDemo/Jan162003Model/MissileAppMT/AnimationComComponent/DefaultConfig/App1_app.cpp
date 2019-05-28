/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: App1_app
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\App1_app.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "App1_app.h"
#include "App1_task_0001ms.h"
#include "App1_task_0010ms.h"
#include "App1_task_0040ms.h"
#include "EventBroadcast.h"
#include "AutoPilot.h"
#include "FinActuator.h"
#include "Animation.h"
#include "Target.h"
#include "EstimatorLOS.h"
#include "SeekerSubsystem.h"
#include "GuidanceLogic.h"
#include "BodyDynamics.h"
#include "AeroDynamics.h"
#include "AirFrame.h"
#include "AirframeSubsystem.h"

//## package Application 


//#[ ignore 
#define Application_App1_app_App1_app_SERIALIZE OM_NO_OP


#define Application_App1_app_clean_SERIALIZE OM_NO_OP


#define Application_App1_app_handle_tick_SERIALIZE aomsmethod->addAttribute("t", x2String(t));


#define Application_App1_app_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// App1_app.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(Application)
//## class App1_app 



App1_app::App1_app() {
    NOTIFY_CONSTRUCTOR(App1_app, App1_app(), 0, Application_App1_app_App1_app_SERIALIZE);
    task_0001ms = NULL;
    task_0010ms = NULL;
    task_0040ms = NULL;
    //#[ operation App1_app() 
    
    init();
    //#]
}

App1_app::~App1_app() {
    NOTIFY_DESTRUCTOR(~App1_app, TRUE);
    //#[ operation ~App1_app() 
    
    clean();
    //#]
    cleanUpRelations();
}

void App1_app::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, Application_App1_app_clean_SERIALIZE);
    //#[ operation clean() 
    
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
    
    if (task_0040ms)
    {
      delete task_0040ms;
      task_0040ms = NULL;
    }
    
    //#]
}

void App1_app::handle_tick(const double  t) {
    NOTIFY_OPERATION(handle_tick, handle_tick(const double), 1, Application_App1_app_handle_tick_SERIALIZE);
    //#[ operation handle_tick(const double) 
    
      task_0010ms->handle_tick(t);
      task_0001ms->handle_tick(t);
      task_0040ms->handle_tick(t);
    //#]
}

void App1_app::init() {
    NOTIFY_OPERATION(init, init(), 0, Application_App1_app_init_SERIALIZE);
    //#[ operation init() 
    
    task_0010ms = new App1_task_0010ms();
    
    task_0001ms = new App1_task_0001ms();
    
    task_0040ms = new App1_task_0040ms();
    
    
    
    // begin broadcaster / handler communication initialization
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_BROADCASTER_IMPL(task_0001ms->itsAirframeSubsystem, BodyDynamics, task_0001ms->itsAirframeSubsystem->m_pSystemModel->itsBodyDynamics, get_theta)
      ONI_LISTENER_IMPL(task_0040ms->itsAvionicsAnimation, Animation, task_0040ms->itsAvionicsAnimation, set_missile_attitude)
      ONI_LISTENER_IMPL(task_0010ms->itsSeeker, SeekerSubsystem, task_0010ms->itsSeeker, set_missile_Attitude_Data)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_IMPL(task_0010ms->itsGuidanceLogic, GuidanceLogic, task_0010ms->itsGuidanceLogic, get_guidanceMode)
      ONI_LISTENER_IMPL(task_0040ms->itsAvionicsAnimation, Animation, task_0040ms->itsAvionicsAnimation, set_guidanceMode)
      ONI_LISTENER_IMPL(task_0040ms->itsLOSEstimator, EstimatorLOS, task_0040ms->itsLOSEstimator, set_guidanceMode)
      ONI_LISTENER_IMPL(task_0010ms->itsSeeker, SeekerSubsystem, task_0010ms->itsSeeker, set_guidanceMode)
    ONI_END_BROADCAST_MAP()
    
    ONI_BROADCAST_MAP(double, task_0040ms->itsLOSEstimator, EstimatorLOS, task_0040ms->itsLOSEstimator, get_LOSRate, task_0010ms->itsGuidanceLogic, GuidanceLogic, task_0010ms->itsGuidanceLogic, set_LOSRate)
    
    ONI_BROADCAST_MAP(double, task_0010ms->itsSeeker, SeekerSubsystem, task_0010ms->itsSeeker, get_closingVelocity, task_0010ms->itsGuidanceLogic, GuidanceLogic, task_0010ms->itsGuidanceLogic, set_closingVelocity)
    
    ONI_BROADCAST_MAP(double, task_0010ms->itsSeeker, SeekerSubsystem, task_0010ms->itsSeeker, get_range, task_0010ms->itsGuidanceLogic, GuidanceLogic, task_0010ms->itsGuidanceLogic, set_Range)
    
    ONI_BROADCAST_MAP(double, task_0010ms->itsSeeker, SeekerSubsystem, task_0010ms->itsSeeker, get_gimbalAngle, task_0040ms->itsAvionicsAnimation, Animation, task_0040ms->itsAvionicsAnimation, set_dishAngle)
    
    ONI_BROADCAST_MAP(double, task_0001ms->itsAirframeSubsystem, BodyDynamics, task_0001ms->itsAirframeSubsystem->m_pSystemModel->itsBodyDynamics, get_x, task_0010ms->itsSeeker, SeekerSubsystem, task_0010ms->itsSeeker, set_missile_X_Data)
    
    ONI_BROADCAST_MAP(double, task_0001ms->itsAirframeSubsystem, BodyDynamics, task_0001ms->itsAirframeSubsystem->m_pSystemModel->itsBodyDynamics, get_z, task_0010ms->itsSeeker, SeekerSubsystem, task_0010ms->itsSeeker, set_missile_Z_Data)
    
    ONI_BROADCAST_MAP(double, task_0010ms->itsSeeker, SeekerSubsystem, task_0010ms->itsSeeker, get_LOS, task_0040ms->itsLOSEstimator, EstimatorLOS, task_0040ms->itsLOSEstimator, set_LOS)
    
    ONI_BROADCAST_MAP(double, task_0010ms->itsSeeker, SeekerSubsystem, task_0010ms->itsSeeker, get_stabilizedRate, task_0040ms->itsLOSEstimator, EstimatorLOS, task_0040ms->itsLOSEstimator, set_stabilizedRate)
    
    ONI_BROADCAST_MAP(double, task_0010ms->itsSeeker, SeekerSubsystem, task_0010ms->itsSeeker, get_dishError, task_0040ms->itsLOSEstimator, EstimatorLOS, task_0040ms->itsLOSEstimator, set_dishError)
    
    ONI_BROADCAST_MAP(double, task_0010ms->itsTarget, Target, task_0010ms->itsTarget, get_z, task_0010ms->itsSeeker, SeekerSubsystem, task_0010ms->itsSeeker, set_target_Z_Data)
    
    ONI_BROADCAST_MAP(double, task_0010ms->itsTarget, Target, task_0010ms->itsTarget, get_x, task_0010ms->itsSeeker, SeekerSubsystem, task_0010ms->itsSeeker, set_target_X_Data)
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_BROADCASTER_IMPL(task_0001ms->itsAirframeSubsystem, BodyDynamics, task_0001ms->itsAirframeSubsystem->m_pSystemModel->itsBodyDynamics, getGyroData)
      ONI_LISTENER_IMPL(task_0010ms->itsSeeker, SeekerSubsystem, task_0010ms->itsSeeker, set_missile_Gyro_Data)
      ONI_LISTENER_IMPL(task_0001ms->itsAutoPilot, AutoPilot, task_0001ms->itsAutoPilot, set_gyroData)
    ONI_END_BROADCAST_MAP()
    
    ONI_BROADCAST_MAP(double, task_0010ms->itsGuidanceLogic, GuidanceLogic, task_0010ms->itsGuidanceLogic, get_dishAngleCommand, task_0010ms->itsSeeker, SeekerSubsystem, task_0010ms->itsSeeker, set_dishCommand)
    
    ONI_BROADCAST_MAP(double, task_0010ms->itsGuidanceLogic, GuidanceLogic, task_0010ms->itsGuidanceLogic, get_Az_Demand, task_0001ms->itsAutoPilot, AutoPilot, task_0001ms->itsAutoPilot, set_command)
    
    ONI_BROADCAST_MAP(double, task_0001ms->itsAirframeSubsystem, BodyDynamics, task_0001ms->itsAirframeSubsystem->m_pSystemModel->itsBodyDynamics, getAccData, task_0001ms->itsAutoPilot, AutoPilot, task_0001ms->itsAutoPilot, set_accelData)
    
    ONI_BROADCAST_MAP(double, task_0001ms->itsAutoPilot, AutoPilot, task_0001ms->itsAutoPilot, get_Fin, task_0001ms->itsAirframeSubsystem, FinActuator, task_0001ms->itsAirframeSubsystem->m_pSystemModel->itsFinDynamics, setAngleSetpoint)
    
    // end broadcaster / handler communication initialization
    
    task_0010ms->broadcast(0.0);
    task_0001ms->broadcast(0.0);
    task_0040ms->broadcast(0.0);
    //#]
}

void App1_app::cleanUpRelations() {
    if(task_0001ms != NULL)
        {
            NOTIFY_RELATION_CLEARED("task_0001ms");
            task_0001ms = NULL;
        }
    if(task_0010ms != NULL)
        {
            NOTIFY_RELATION_CLEARED("task_0010ms");
            task_0010ms = NULL;
        }
    if(task_0040ms != NULL)
        {
            NOTIFY_RELATION_CLEARED("task_0040ms");
            task_0040ms = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedApp1_app::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("task_0010ms", FALSE, TRUE);
    if(myReal->task_0010ms)
        aomsRelations->ADD_ITEM(myReal->task_0010ms);
    aomsRelations->addRelation("task_0001ms", FALSE, TRUE);
    if(myReal->task_0001ms)
        aomsRelations->ADD_ITEM(myReal->task_0001ms);
    aomsRelations->addRelation("task_0040ms", FALSE, TRUE);
    if(myReal->task_0040ms)
        aomsRelations->ADD_ITEM(myReal->task_0040ms);
}

IMPLEMENT_META(App1_app, Application, FALSE, OMAnimatedApp1_app)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\App1_app.cpp
*********************************************************************/

