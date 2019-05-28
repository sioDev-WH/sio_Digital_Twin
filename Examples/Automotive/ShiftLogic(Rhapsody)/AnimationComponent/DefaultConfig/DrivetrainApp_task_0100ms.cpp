/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: DrivetrainApp_task_0100ms
//!	Generated Date	: Mon, 20, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\DrivetrainApp_task_0100ms.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "DrivetrainApp_task_0100ms.h"
#include "Chart.h"
#include "Controller.h"
#include "DrivetrainSubsystem.h"
#include "Throttle.h"

//## package Application 


//#[ ignore 
#define Application_DrivetrainApp_task_0100ms_DrivetrainApp_task_0100ms_SERIALIZE OM_NO_OP


#define Application_DrivetrainApp_task_0100ms_broadcast_SERIALIZE OM_NO_OP


#define Application_DrivetrainApp_task_0100ms_clean_SERIALIZE OM_NO_OP


#define Application_DrivetrainApp_task_0100ms_handle_tick_SERIALIZE OM_NO_OP


#define Application_DrivetrainApp_task_0100ms_init_SERIALIZE OM_NO_OP


#define Application_DrivetrainApp_task_0100ms_setTime_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// DrivetrainApp_task_0100ms.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(Application)
//## class DrivetrainApp_task_0100ms 



DrivetrainApp_task_0100ms::DrivetrainApp_task_0100ms() : nTicks(0) ,interval(0) {
    NOTIFY_CONSTRUCTOR(DrivetrainApp_task_0100ms, DrivetrainApp_task_0100ms(), 0, Application_DrivetrainApp_task_0100ms_DrivetrainApp_task_0100ms_SERIALIZE);
    SpeedChart = NULL;
    itsController = NULL;
    itsDrivetrainSubsystem = NULL;
    itsEngineChart = NULL;
    itsThrottle = NULL;
    //#[ operation DrivetrainApp_task_0100ms() 
    
    init();
    //#]
}

DrivetrainApp_task_0100ms::~DrivetrainApp_task_0100ms() {
    NOTIFY_DESTRUCTOR(~DrivetrainApp_task_0100ms, TRUE);
    //#[ operation ~DrivetrainApp_task_0100ms() 
    
    clean();
    //#]
    cleanUpRelations();
}

void DrivetrainApp_task_0100ms::broadcast() {
    NOTIFY_OPERATION(broadcast, broadcast(), 0, Application_DrivetrainApp_task_0100ms_broadcast_SERIALIZE);
    //#[ operation broadcast() 
    
    SpeedChart->broadcast();
    itsEngineChart->broadcast();
    itsThrottle->broadcast();
    itsController->broadcast();
    itsDrivetrainSubsystem->broadcast();
    //#]
}

void DrivetrainApp_task_0100ms::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, Application_DrivetrainApp_task_0100ms_clean_SERIALIZE);
    //#[ operation clean() 
    
    if (SpeedChart)
    {
      delete SpeedChart;
      SpeedChart = NULL;
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
    
    if (itsController)
    {
      delete itsController;
      itsController = NULL;
    }
    
    if (itsDrivetrainSubsystem)
    {
      delete itsDrivetrainSubsystem;
      itsDrivetrainSubsystem = NULL;
    }
    
    //#]
}

void DrivetrainApp_task_0100ms::handle_tick() {
    NOTIFY_OPERATION(handle_tick, handle_tick(), 0, Application_DrivetrainApp_task_0100ms_handle_tick_SERIALIZE);
    //#[ operation handle_tick() 
    
    if (nTicks == 0)
    {
      SpeedChart->handle_tick();
      itsEngineChart->handle_tick();
      itsThrottle->handle_tick();
      itsController->handle_tick();
      itsDrivetrainSubsystem->handle_tick();
    }
    if (++nTicks == interval) nTicks = 0;
    //#]
}

void DrivetrainApp_task_0100ms::init() {
    NOTIFY_OPERATION(init, init(), 0, Application_DrivetrainApp_task_0100ms_init_SERIALIZE);
    //#[ operation init() 
    
    // calculate the number of ticks (period) before broadcasting tick()
    long task_TS = 100;
    long fastest_task_TS = 100;
    interval = task_TS / fastest_task_TS;
    nTicks = 0;
    SpeedChart = new Chart();
    SpeedChart->setPeriod(task_TS);
    
    itsEngineChart = new Chart();
    itsEngineChart->setPeriod(task_TS);
    
    itsThrottle = new Throttle();
    itsThrottle->setPeriod(task_TS);
    
    itsController = new Controller();
    itsController->setPeriod(task_TS);
    itsController->startBehavior();
    
    itsDrivetrainSubsystem = new DrivetrainSubsystem();
    
    //#]
}

void DrivetrainApp_task_0100ms::setTime(const double  t) {
    NOTIFY_OPERATION(setTime, setTime(const double), 0, Application_DrivetrainApp_task_0100ms_setTime_SERIALIZE);
    //#[ operation setTime(const double) 
    
    SpeedChart->setTime(t);
    itsEngineChart->setTime(t);
    itsThrottle->setTime(t);
    itsController->setTime(t);
    itsDrivetrainSubsystem->setTime(t);
    //#]
}

void DrivetrainApp_task_0100ms::setInterval(long  p_interval) {
    interval = p_interval;
}

void DrivetrainApp_task_0100ms::setNTicks(long  p_nTicks) {
    nTicks = p_nTicks;
}

void DrivetrainApp_task_0100ms::cleanUpRelations() {
    if(SpeedChart != NULL)
        {
            SpeedChart = NULL;
        }
    if(itsController != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsController");
            itsController = NULL;
        }
    if(itsDrivetrainSubsystem != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsDrivetrainSubsystem");
            itsDrivetrainSubsystem = NULL;
        }
    if(itsEngineChart != NULL)
        {
            itsEngineChart = NULL;
        }
    if(itsThrottle != NULL)
        {
            itsThrottle = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedDrivetrainApp_task_0100ms::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedDrivetrainApp_task_0100ms::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("itsController", FALSE, TRUE);
    if(myReal->itsController)
        aomsRelations->ADD_ITEM(myReal->itsController);
    aomsRelations->addRelation("itsDrivetrainSubsystem", FALSE, TRUE);
    if(myReal->itsDrivetrainSubsystem)
        aomsRelations->ADD_ITEM(myReal->itsDrivetrainSubsystem);
}

IMPLEMENT_META(DrivetrainApp_task_0100ms, Application, FALSE, OMAnimatedDrivetrainApp_task_0100ms)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\DrivetrainApp_task_0100ms.cpp
*********************************************************************/

