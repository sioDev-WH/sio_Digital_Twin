/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: StdApp_task_0100ms
//!	Generated Date	: Thu, 12, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\StdApp_task_0100ms.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "StdApp_task_0100ms.h"
#include "Brakes.h"
#include "Chart.h"
#include "Controller.h"
#include "ShiftLever.h"
#include "StdCarSS.h"
#include "Throttle.h"

//## package AppSimple 

//----------------------------------------------------------------------------
// StdApp_task_0100ms.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(AppSimple)
//## class StdApp_task_0100ms 



StdApp_task_0100ms::StdApp_task_0100ms() : nTicks(0) ,interval(0) {
    itsBrake = NULL;
    itsRPMChart = NULL;
    itsShiftController = NULL;
    itsShiftLever = NULL;
    itsSpeedChart = NULL;
    itsStdCarSS = NULL;
    itsThrottle = NULL;
    //#[ operation StdApp_task_0100ms() 
    
    init();
    //#]
}

StdApp_task_0100ms::~StdApp_task_0100ms() {
    //#[ operation ~StdApp_task_0100ms() 
    
    clean();
    //#]
    cleanUpRelations();
}

void StdApp_task_0100ms::broadcast() {
    //#[ operation broadcast() 
    
    itsRPMChart->broadcast();
    itsSpeedChart->broadcast();
    itsShiftLever->broadcast();
    itsBrake->broadcast();
    itsThrottle->broadcast();
    itsShiftController->broadcast();
    itsStdCarSS->broadcast();
    //#]
}

void StdApp_task_0100ms::clean() {
    //#[ operation clean() 
    
    if (itsRPMChart)
    {
      delete itsRPMChart;
      itsRPMChart = NULL;
    }
    
    if (itsSpeedChart)
    {
      delete itsSpeedChart;
      itsSpeedChart = NULL;
    }
    
    if (itsShiftLever)
    {
      delete itsShiftLever;
      itsShiftLever = NULL;
    }
    
    if (itsBrake)
    {
      delete itsBrake;
      itsBrake = NULL;
    }
    
    if (itsThrottle)
    {
      delete itsThrottle;
      itsThrottle = NULL;
    }
    
    if (itsShiftController)
    {
      delete itsShiftController;
      itsShiftController = NULL;
    }
    
    if (itsStdCarSS)
    {
      delete itsStdCarSS;
      itsStdCarSS = NULL;
    }
    
    //#]
}

void StdApp_task_0100ms::handle_tick() {
    //#[ operation handle_tick() 
    
    if (nTicks == 0)
    {
      itsStdCarSS->handle_tick();
      itsRPMChart->handle_tick();
      itsSpeedChart->handle_tick();
      itsShiftLever->handle_tick();
      itsBrake->handle_tick();
      itsThrottle->handle_tick();
      itsShiftController->handle_tick();
    }
    if (++nTicks == interval) nTicks = 0;
    //#]
}

void StdApp_task_0100ms::init() {
    //#[ operation init() 
    
    // calculate the number of ticks (period) before broadcasting tick()
    long task_TS = 100;
    long fastest_task_TS = 100;
    interval = task_TS / fastest_task_TS;
    nTicks = 0;
    itsRPMChart = new Chart();
    itsRPMChart->setPeriod(task_TS);
    
    itsSpeedChart = new Chart();
    itsSpeedChart->setPeriod(task_TS);
    
    itsShiftLever = new ShiftLever();
    itsShiftLever->setPeriod(task_TS);
    
    itsBrake = new Brakes();
    itsBrake->setPeriod(task_TS);
    
    itsThrottle = new Throttle();
    itsThrottle->setPeriod(task_TS);
    
    itsShiftController = new Controller();
    itsShiftController->setPeriod(task_TS);
    itsShiftController->startBehavior();
    
    itsStdCarSS = new StdCarSS();
    
    //#]
}

void StdApp_task_0100ms::setTime(const double  t) {
    //#[ operation setTime(const double) 
    
    itsRPMChart->setTime(t);
    itsSpeedChart->setTime(t);
    itsShiftLever->setTime(t);
    itsBrake->setTime(t);
    itsThrottle->setTime(t);
    itsShiftController->setTime(t);
    itsStdCarSS->setTime(t);
    //#]
}

void StdApp_task_0100ms::setInterval(long  p_interval) {
    interval = p_interval;
}

void StdApp_task_0100ms::setNTicks(long  p_nTicks) {
    nTicks = p_nTicks;
}

void StdApp_task_0100ms::cleanUpRelations() {
    if(itsBrake != NULL)
        {
            itsBrake = NULL;
        }
    if(itsRPMChart != NULL)
        {
            itsRPMChart = NULL;
        }
    if(itsShiftController != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsShiftController");
            itsShiftController = NULL;
        }
    if(itsShiftLever != NULL)
        {
            itsShiftLever = NULL;
        }
    if(itsSpeedChart != NULL)
        {
            itsSpeedChart = NULL;
        }
    if(itsStdCarSS != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsStdCarSS");
            itsStdCarSS = NULL;
        }
    if(itsThrottle != NULL)
        {
            itsThrottle = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedStdApp_task_0100ms::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedStdApp_task_0100ms::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("itsShiftController", FALSE, TRUE);
    if(myReal->itsShiftController)
        aomsRelations->ADD_ITEM(myReal->itsShiftController);
    aomsRelations->addRelation("itsStdCarSS", FALSE, TRUE);
    if(myReal->itsStdCarSS)
        aomsRelations->ADD_ITEM(myReal->itsStdCarSS);
}

IMPLEMENT_META(StdApp_task_0100ms, AppSimple, FALSE, OMAnimatedStdApp_task_0100ms)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\StdApp_task_0100ms.cpp
*********************************************************************/

