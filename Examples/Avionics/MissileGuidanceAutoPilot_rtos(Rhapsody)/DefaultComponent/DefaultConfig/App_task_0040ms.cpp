/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: App_task_0040ms
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\App_task_0040ms.cpp
*********************************************************************/

#include "App_task_0040ms.h"
#include "Animation.h"
#include "EstimatorLOS.h"

//## package Default 

//----------------------------------------------------------------------------
// App_task_0040ms.cpp                                                                  
//----------------------------------------------------------------------------
//## class App_task_0040ms 



App_task_0040ms::App_task_0040ms() : nTicks(0) ,interval(0) {
    AnimationBlock = NULL;
    EstimatorLOSBlock = NULL;
    //#[ operation App_task_0040ms() 
    
    init();
    //#]
}

App_task_0040ms::~App_task_0040ms() {
    //#[ operation ~App_task_0040ms() 
    
    clean();
    //#]
    cleanUpRelations();
}

void App_task_0040ms::broadcast() {
    //#[ operation broadcast() 
    
    AnimationBlock->broadcast();
    EstimatorLOSBlock->broadcast();
    //#]
}

void App_task_0040ms::clean() {
    //#[ operation clean() 
    
    if (AnimationBlock)
    {
      delete AnimationBlock;
      AnimationBlock = NULL;
    }
    
    if (EstimatorLOSBlock)
    {
      delete EstimatorLOSBlock;
      EstimatorLOSBlock = NULL;
    }
    
    //#]
}

void App_task_0040ms::handle_tick() {
    //#[ operation handle_tick() 
    
    if (nTicks == 0)
    {
      AnimationBlock->handle_tick();
      EstimatorLOSBlock->handle_tick();
    }
    if (++nTicks == interval) nTicks = 0;
    //#]
}

void App_task_0040ms::init() {
    //#[ operation init() 
    
    // calculate the number of ticks (period) before broadcasting tick()
    long task_TS = 40;
    long fastest_task_TS = 1;
    interval = task_TS / fastest_task_TS;
    nTicks = 0;
    AnimationBlock = new Animation();
    AnimationBlock->setPeriod(task_TS);
    
    EstimatorLOSBlock = new EstimatorLOS();
    EstimatorLOSBlock->setPeriod(task_TS);
    EstimatorLOSBlock->startBehavior();
    
    //#]
}

void App_task_0040ms::setTime(const double  t) {
    //#[ operation setTime(const double) 
    
    AnimationBlock->setTime(t);
    EstimatorLOSBlock->setTime(t);
    //#]
}

void App_task_0040ms::setInterval(long  p_interval) {
    interval = p_interval;
}

void App_task_0040ms::setNTicks(long  p_nTicks) {
    nTicks = p_nTicks;
}

void App_task_0040ms::cleanUpRelations() {
    if(AnimationBlock != NULL)
        {
            AnimationBlock = NULL;
        }
    if(EstimatorLOSBlock != NULL)
        {
            EstimatorLOSBlock = NULL;
        }
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\App_task_0040ms.cpp
*********************************************************************/

