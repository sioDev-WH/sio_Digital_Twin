/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: SimpleApp
//!	Generated Date	: Wed, 11, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\SimpleApp.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "SimpleApp.h"
#include "SimpleApp_task_0100ms.h"
#include "EventBroadcast.h"
#include "OnDataCollector.h"
#include "SimpleGearbox.h"
#include "Chart.h"
#include "ShiftLever.h"
#include "Throttle.h"
#include "Controller.h"

//## package AppSimple 

//----------------------------------------------------------------------------
// SimpleApp.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(AppSimple)
//## class SimpleApp 



SimpleApp::SimpleApp() {
    task_0100ms = NULL;
    //#[ operation SimpleApp() 
    
    init();
    //#]
}

SimpleApp::~SimpleApp() {
    //#[ operation ~SimpleApp() 
    
    clean();
    //#]
    cleanUpRelations();
}

void SimpleApp::clean() {
    //#[ operation clean() 
    
    if (task_0100ms)
    {
      delete task_0100ms;
      task_0100ms = NULL;
    }
    
    //#]
}

void SimpleApp::handle_tick() {
    //#[ operation handle_tick() 
    
      task_0100ms->handle_tick();
    //#]
}

 SimpleApp::init() {
    //#[ operation init() 
    
    task_0100ms = new SimpleApp_task_0100ms();
    
    
    // begin broadcaster / handler communication initialization
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_SCALAR_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0100ms->itsSimpleGearbox, 
        /* SourceObject: */ task_0100ms->itsSimpleGearbox, 
        /* SourceAttribute: */ gear)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsGearChart, 
      /* TargetClass: */ Chart, 
      /* TargetObject: */ task_0100ms->itsGearChart, 
      /* TargetOperation: */ handle_plotData)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_OB)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsSimpleGearbox, 
      /* TargetClass: */ SimpleGearbox, 
      /* TargetObject: */ task_0100ms->itsSimpleGearbox, 
      /* TargetOperation: */ OB_Shift)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_DC)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsSimpleGearbox, 
      /* TargetClass: */ SimpleGearbox, 
      /* TargetObject: */ task_0100ms->itsSimpleGearbox, 
      /* TargetOperation: */ DC_Shift)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_TCC)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsSimpleGearbox, 
      /* TargetClass: */ SimpleGearbox, 
      /* TargetObject: */ task_0100ms->itsSimpleGearbox, 
      /* TargetOperation: */ TCC_Shift)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_IOC)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsSimpleGearbox, 
      /* TargetClass: */ SimpleGearbox, 
      /* TargetObject: */ task_0100ms->itsSimpleGearbox, 
      /* TargetOperation: */ IOC_Shift)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_POC)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsSimpleGearbox, 
      /* TargetClass: */ SimpleGearbox, 
      /* TargetObject: */ task_0100ms->itsSimpleGearbox, 
      /* TargetOperation: */ POC_Shift)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_FC)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsSimpleGearbox, 
      /* TargetClass: */ SimpleGearbox, 
      /* TargetObject: */ task_0100ms->itsSimpleGearbox, 
      /* TargetOperation: */ FC_Shift)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_LRB)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsSimpleGearbox, 
      /* TargetClass: */ SimpleGearbox, 
      /* TargetObject: */ task_0100ms->itsSimpleGearbox, 
      /* TargetOperation: */ LRB_Shift)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(long)
      ONI_BROADCASTER_ENTRY(task_0100ms->itsShiftController->Port_RC)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsSimpleGearbox, 
      /* TargetClass: */ SimpleGearbox, 
      /* TargetObject: */ task_0100ms->itsSimpleGearbox, 
      /* TargetOperation: */ RC_Shift)
    ONI_END_BROADCAST_MAP()
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_FCN_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0100ms->itsSpeed, 
        /* SourceClass: */ Throttle, 
        /* SourceObject: */ task_0100ms->itsSpeed, 
        /* SourceFunction: */ getPosition)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsSpeedChart, 
      /* TargetClass: */ Chart, 
      /* TargetObject: */ task_0100ms->itsSpeedChart, 
      /* TargetOperation: */ handle_plotData)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsShiftController, 
      /* TargetClass: */ Controller, 
      /* TargetObject: */ task_0100ms->itsShiftController, 
      /* TargetOperation: */ handle_SpeedData)
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
    
    ONI_BEGIN_BROADCAST_MAP(double)
      ONI_FCN_BROADCASTER_IMPL(
        /* SourceCompositeObject: */ task_0100ms->itsThrottle, 
        /* SourceClass: */ Throttle, 
        /* SourceObject: */ task_0100ms->itsThrottle, 
        /* SourceFunction: */ getPosition)
      ONI_OPER_LISTENER_IMPL(
      /* TargetCompositeObject: */ task_0100ms->itsShiftController, 
      /* TargetClass: */ Controller, 
      /* TargetObject: */ task_0100ms->itsShiftController, 
      /* TargetOperation: */ handle_ThrottleData)
    ONI_END_BROADCAST_MAP()
    
    // end broadcaster / handler communication initialization
    
    task_0100ms->broadcast();
    //#]
}

void SimpleApp::setTime(const double  t) {
    //#[ operation setTime(const double) 
    
    task_0100ms->setTime(t);
    //#]
}

void SimpleApp::cleanUpRelations() {
    if(task_0100ms != NULL)
        {
            NOTIFY_RELATION_CLEARED("task_0100ms");
            task_0100ms = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedSimpleApp::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("task_0100ms", FALSE, TRUE);
    if(myReal->task_0100ms)
        aomsRelations->ADD_ITEM(myReal->task_0100ms);
}

IMPLEMENT_META(SimpleApp, AppSimple, FALSE, OMAnimatedSimpleApp)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\SimpleApp.cpp
*********************************************************************/

