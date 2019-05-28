/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: TestDrivetrainApp_task_0100ms
//!	Generated Date	: Fri, 27, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\TestDrivetrainApp_task_0100ms.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "TestDrivetrainApp_task_0100ms.h"
#include "Brakes.h"
#include "Chart.h"
#include "Controller.h"
#include "ShiftLever.h"
#include "TestDrivetrainSS.h"
#include "Throttle.h"

//## package Application 

//----------------------------------------------------------------------------
// TestDrivetrainApp_task_0100ms.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(Application)
//## class TestDrivetrainApp_task_0100ms 



TestDrivetrainApp_task_0100ms::TestDrivetrainApp_task_0100ms() : nTicks(0) ,interval(0) {
    itsEngineChart = NULL;
    itsShiftController = NULL;
    itsShiftLever = NULL;
    itsSpeedChart = NULL;
    itsTestDrivetrainSS = NULL;
    itsThrottle = NULL;
    itsWheelBrake = NULL;
    //#[ operation TestDrivetrainApp_task_0100ms() 
    
    init();
    //#]
}

TestDrivetrainApp_task_0100ms::~TestDrivetrainApp_task_0100ms() {
    //#[ operation ~TestDrivetrainApp_task_0100ms() 
    
    clean();
    //#]
    cleanUpRelations();
}

void TestDrivetrainApp_task_0100ms::broadcast() {
    //#[ operation broadcast() 
    
    itsShiftLever->broadcast();
    itsWheelBrake->broadcast();
    itsSpeedChart->broadcast();
    itsEngineChart->broadcast();
    itsThrottle->broadcast();
    itsShiftController->broadcast();
    itsTestDrivetrainSS->broadcast();
    //#]
}

void TestDrivetrainApp_task_0100ms::clean() {
    //#[ operation clean() 
    
    if (itsShiftLever)
    {
      delete itsShiftLever;
      itsShiftLever = NULL;
    }
    
    if (itsWheelBrake)
    {
      delete itsWheelBrake;
      itsWheelBrake = NULL;
    }
    
    if (itsSpeedChart)
    {
      delete itsSpeedChart;
      itsSpeedChart = NULL;
    }
    
    if (itsEngineChart)
    {
      delete itsEngineChart;
      itsEngineChart = NULL;
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
    
    if (itsTestDrivetrainSS)
    {
      delete itsTestDrivetrainSS;
      itsTestDrivetrainSS = NULL;
    }
    
    //#]
}

void TestDrivetrainApp_task_0100ms::handle_tick() {
    //#[ operation handle_tick() 
    
    if (nTicks == 0)
    {
      itsTestDrivetrainSS->handle_tick();
      itsShiftLever->handle_tick();
      itsWheelBrake->handle_tick();
      itsSpeedChart->handle_tick();
      itsEngineChart->handle_tick();
      itsThrottle->handle_tick();
      itsShiftController->handle_tick();
    }
    if (++nTicks == interval) nTicks = 0;
    //#]
}

void TestDrivetrainApp_task_0100ms::init() {
    //#[ operation init() 
    
    // calculate the number of ticks (period) before broadcasting tick()
    long task_TS = 100;
    long fastest_task_TS = 100;
    interval = task_TS / fastest_task_TS;
    nTicks = 0;
    itsShiftLever = new ShiftLever();
    itsShiftLever->setPeriod(task_TS);
    
    itsWheelBrake = new Brakes();
    itsWheelBrake->setPeriod(task_TS);
    
    itsSpeedChart = new Chart();
    itsSpeedChart->setPeriod(task_TS);
    
    itsEngineChart = new Chart();
    itsEngineChart->setPeriod(task_TS);
    
    itsThrottle = new Throttle();
    itsThrottle->setPeriod(task_TS);
    
    itsShiftController = new Controller();
    itsShiftController->setPeriod(task_TS);
    itsShiftController->startBehavior();
    
    itsTestDrivetrainSS = new TestDrivetrainSS();
    
    //#]
}

void TestDrivetrainApp_task_0100ms::setTime(const double  t) {
    //#[ operation setTime(const double) 
    
    itsShiftLever->setTime(t);
    itsWheelBrake->setTime(t);
    itsSpeedChart->setTime(t);
    itsEngineChart->setTime(t);
    itsThrottle->setTime(t);
    itsShiftController->setTime(t);
    itsTestDrivetrainSS->setTime(t);
    //#]
}

void TestDrivetrainApp_task_0100ms::setInterval(long  p_interval) {
    interval = p_interval;
}

void TestDrivetrainApp_task_0100ms::setNTicks(long  p_nTicks) {
    nTicks = p_nTicks;
}

void TestDrivetrainApp_task_0100ms::cleanUpRelations() {
    if(itsEngineChart != NULL)
        {
            itsEngineChart = NULL;
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
    if(itsTestDrivetrainSS != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsTestDrivetrainSS");
            itsTestDrivetrainSS = NULL;
        }
    if(itsThrottle != NULL)
        {
            itsThrottle = NULL;
        }
    if(itsWheelBrake != NULL)
        {
            itsWheelBrake = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedTestDrivetrainApp_task_0100ms::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedTestDrivetrainApp_task_0100ms::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("itsShiftController", FALSE, TRUE);
    if(myReal->itsShiftController)
        aomsRelations->ADD_ITEM(myReal->itsShiftController);
    aomsRelations->addRelation("itsTestDrivetrainSS", FALSE, TRUE);
    if(myReal->itsTestDrivetrainSS)
        aomsRelations->ADD_ITEM(myReal->itsTestDrivetrainSS);
}

IMPLEMENT_META(TestDrivetrainApp_task_0100ms, Application, FALSE, OMAnimatedTestDrivetrainApp_task_0100ms)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\TestDrivetrainApp_task_0100ms.cpp
*********************************************************************/

