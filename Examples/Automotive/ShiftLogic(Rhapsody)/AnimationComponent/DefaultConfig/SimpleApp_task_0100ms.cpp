/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: SimpleApp_task_0100ms
//!	Generated Date	: Wed, 11, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\SimpleApp_task_0100ms.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "SimpleApp_task_0100ms.h"
#include "Chart.h"
#include "Controller.h"
#include "ShiftLever.h"
#include "SimpleGearbox.h"
#include "Throttle.h"

//## package AppSimple 

//----------------------------------------------------------------------------
// SimpleApp_task_0100ms.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(AppSimple)
//## class SimpleApp_task_0100ms 



SimpleApp_task_0100ms::SimpleApp_task_0100ms() : nTicks(0) ,interval(0) {
    itsGearChart = NULL;
    itsShiftController = NULL;
    itsShiftLever = NULL;
    itsSimpleGearbox = NULL;
    itsSpeed = NULL;
    itsSpeedChart = NULL;
    itsThrottle = NULL;
    //#[ operation SimpleApp_task_0100ms() 
    
    init();
    //#]
}

SimpleApp_task_0100ms::~SimpleApp_task_0100ms() {
    //#[ operation ~SimpleApp_task_0100ms() 
    
    clean();
    //#]
    cleanUpRelations();
}

void SimpleApp_task_0100ms::broadcast() {
    //#[ operation broadcast() 
    
    itsSimpleGearbox->broadcast();
    itsSpeedChart->broadcast();
    itsShiftLever->broadcast();
    itsSpeed->broadcast();
    itsThrottle->broadcast();
    itsGearChart->broadcast();
    itsShiftController->broadcast();
    //#]
}

void SimpleApp_task_0100ms::clean() {
    //#[ operation clean() 
    
    if (itsSimpleGearbox)
    {
      delete itsSimpleGearbox;
      itsSimpleGearbox = NULL;
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
    
    if (itsSpeed)
    {
      delete itsSpeed;
      itsSpeed = NULL;
    }
    
    if (itsThrottle)
    {
      delete itsThrottle;
      itsThrottle = NULL;
    }
    
    if (itsGearChart)
    {
      delete itsGearChart;
      itsGearChart = NULL;
    }
    
    if (itsShiftController)
    {
      delete itsShiftController;
      itsShiftController = NULL;
    }
    
    //#]
}

void SimpleApp_task_0100ms::handle_tick() {
    //#[ operation handle_tick() 
    
    if (nTicks == 0)
    {
      itsSimpleGearbox->handle_tick();
      itsSpeedChart->handle_tick();
      itsShiftLever->handle_tick();
      itsSpeed->handle_tick();
      itsThrottle->handle_tick();
      itsGearChart->handle_tick();
      itsShiftController->handle_tick();
    }
    if (++nTicks == interval) nTicks = 0;
    //#]
}

void SimpleApp_task_0100ms::init() {
    //#[ operation init() 
    
    // calculate the number of ticks (period) before broadcasting tick()
    long task_TS = 100;
    long fastest_task_TS = 1;
    interval = task_TS / fastest_task_TS;
    nTicks = 0;
    itsSimpleGearbox = new SimpleGearbox();
    itsSimpleGearbox->setPeriod(task_TS);
    itsSimpleGearbox->startBehavior();
    
    itsSpeedChart = new Chart();
    itsSpeedChart->setPeriod(task_TS);
    itsSpeedChart->SetName(L"Speed");
    
    itsShiftLever = new ShiftLever();
    itsShiftLever->setPeriod(task_TS);
    
    itsSpeed = new Throttle();
    itsSpeed->setPeriod(task_TS);
    itsSpeed->SetName(L"Speed");
    
    itsThrottle = new Throttle();
    itsThrottle->setPeriod(task_TS);
    itsThrottle->SetName(L"Throttle");
    
    itsGearChart = new Chart();
    itsGearChart->setPeriod(task_TS);
    itsGearChart->SetName(L"Gears");
    
    itsShiftController = new Controller();
    itsShiftController->setPeriod(task_TS);
    itsShiftController->startBehavior();
    
    //#]
}

void SimpleApp_task_0100ms::setTime(const double  t) {
    //#[ operation setTime(const double) 
    
    itsSimpleGearbox->setTime(t);
    itsSpeedChart->setTime(t);
    itsShiftLever->setTime(t);
    itsSpeed->setTime(t);
    itsThrottle->setTime(t);
    itsGearChart->setTime(t);
    itsShiftController->setTime(t);
    //#]
}

void SimpleApp_task_0100ms::setInterval(long  p_interval) {
    interval = p_interval;
}

void SimpleApp_task_0100ms::setNTicks(long  p_nTicks) {
    nTicks = p_nTicks;
}

void SimpleApp_task_0100ms::cleanUpRelations() {
    if(itsGearChart != NULL)
        {
            itsGearChart = NULL;
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
    if(itsSimpleGearbox != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsSimpleGearbox");
            itsSimpleGearbox = NULL;
        }
    if(itsSpeed != NULL)
        {
            itsSpeed = NULL;
        }
    if(itsSpeedChart != NULL)
        {
            itsSpeedChart = NULL;
        }
    if(itsThrottle != NULL)
        {
            itsThrottle = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedSimpleApp_task_0100ms::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedSimpleApp_task_0100ms::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("itsSimpleGearbox", FALSE, TRUE);
    if(myReal->itsSimpleGearbox)
        aomsRelations->ADD_ITEM(myReal->itsSimpleGearbox);
    aomsRelations->addRelation("itsShiftController", FALSE, TRUE);
    if(myReal->itsShiftController)
        aomsRelations->ADD_ITEM(myReal->itsShiftController);
}

IMPLEMENT_META(SimpleApp_task_0100ms, AppSimple, FALSE, OMAnimatedSimpleApp_task_0100ms)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\SimpleApp_task_0100ms.cpp
*********************************************************************/

