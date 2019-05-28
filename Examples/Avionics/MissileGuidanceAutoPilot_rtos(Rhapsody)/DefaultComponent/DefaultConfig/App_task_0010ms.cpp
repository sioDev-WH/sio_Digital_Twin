/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: App_task_0010ms
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\App_task_0010ms.cpp
*********************************************************************/

#include "App_task_0010ms.h"
#include "EstimatorVc.h"
#include "GuidanceLogic.h"
#include "Target.h"
#include "TrackingSubsystem.h"

//## package Default 

//----------------------------------------------------------------------------
// App_task_0010ms.cpp                                                                  
//----------------------------------------------------------------------------
//## class App_task_0010ms 



App_task_0010ms::App_task_0010ms() : nTicks(0) ,interval(0) {
    EstimatorVcBlock = NULL;
    GuidanceLogicBlock = NULL;
    TargetBlock = NULL;
    TrackingSubsystemBlock = NULL;
    //#[ operation App_task_0010ms() 
    
    init();
    //#]
}

App_task_0010ms::~App_task_0010ms() {
    //#[ operation ~App_task_0010ms() 
    
    clean();
    //#]
    cleanUpRelations();
}

void App_task_0010ms::broadcast() {
    //#[ operation broadcast() 
    
    TrackingSubsystemBlock->broadcast();
    TargetBlock->broadcast();
    GuidanceLogicBlock->broadcast();
    EstimatorVcBlock->broadcast();
    //#]
}

void App_task_0010ms::clean() { 
    //#[ operation clean() 
    
    if (TrackingSubsystemBlock)
    {
      delete TrackingSubsystemBlock;
      TrackingSubsystemBlock = NULL;
    }
    
    if (TargetBlock)
    {
      delete TargetBlock;
      TargetBlock = NULL;
    }
    
    if (GuidanceLogicBlock)
    {
      delete GuidanceLogicBlock;
      GuidanceLogicBlock = NULL;
    }
    
    if (EstimatorVcBlock)
    {
      delete EstimatorVcBlock;
      EstimatorVcBlock = NULL;
    }
    
    //#]
}

void App_task_0010ms::handle_tick() {
    //#[ operation handle_tick() 
    
    if (nTicks == 0)
    {
      TrackingSubsystemBlock->handle_tick();
      TargetBlock->handle_tick();
      GuidanceLogicBlock->handle_tick();
      EstimatorVcBlock->handle_tick();
    }
    if (++nTicks == interval) nTicks = 0;
    //#]
}

void App_task_0010ms::init() {
    //#[ operation init() 
    
    // calculate the number of ticks (period) before broadcasting tick()
    long task_TS = 10;
    long fastest_task_TS = 1;
    interval = task_TS / fastest_task_TS;
    nTicks = 0;
    TrackingSubsystemBlock = new TrackingSubsystem();
    TrackingSubsystemBlock->setPeriod(task_TS);
    
    TargetBlock = new Target();
    TargetBlock->setPeriod(task_TS);
    
    GuidanceLogicBlock = new GuidanceLogic();
    GuidanceLogicBlock->setPeriod(task_TS);
    GuidanceLogicBlock->startBehavior();
    
    EstimatorVcBlock = new EstimatorVc();
    EstimatorVcBlock->setPeriod(task_TS);
    EstimatorVcBlock->startBehavior();
    
    //#]
}

void App_task_0010ms::setTime(const double  t) {
    //#[ operation setTime(const double) 
    
    TrackingSubsystemBlock->setTime(t);
    TargetBlock->setTime(t);
    GuidanceLogicBlock->setTime(t);
    EstimatorVcBlock->setTime(t);
    //#]
}

void App_task_0010ms::setInterval(long  p_interval) {
    interval = p_interval;
}

void App_task_0010ms::setNTicks(long  p_nTicks) {
    nTicks = p_nTicks;
}

void App_task_0010ms::cleanUpRelations() {
    if(EstimatorVcBlock != NULL)
        {
            EstimatorVcBlock = NULL;
        }
    if(GuidanceLogicBlock != NULL)
        {
            GuidanceLogicBlock = NULL;
        }
    if(TargetBlock != NULL)
        {
            TargetBlock = NULL;
        }
    if(TrackingSubsystemBlock != NULL)
        {
            TrackingSubsystemBlock = NULL;
        }
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\App_task_0010ms.cpp
*********************************************************************/

