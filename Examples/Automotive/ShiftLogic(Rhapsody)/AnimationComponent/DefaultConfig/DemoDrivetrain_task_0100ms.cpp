/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: DemoDrivetrain_task_0100ms
//!	Generated Date	: Tue, 21, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\DemoDrivetrain_task_0100ms.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "DemoDrivetrain_task_0100ms.h"
#include "Chart.h"
#include "Controller.h"
#include "DemoDrivetrainSubsystem.h"
#include "Driver.h"

//## package Application 


//#[ ignore 
#define Application_DemoDrivetrain_task_0100ms_DemoDrivetrain_task_0100ms_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrain_task_0100ms_broadcast_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrain_task_0100ms_clean_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrain_task_0100ms_handle_tick_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrain_task_0100ms_init_SERIALIZE OM_NO_OP


#define Application_DemoDrivetrain_task_0100ms_setTime_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// DemoDrivetrain_task_0100ms.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(Application)
//## class DemoDrivetrain_task_0100ms 



DemoDrivetrain_task_0100ms::DemoDrivetrain_task_0100ms() : nTicks(0) ,interval(0) {
    NOTIFY_CONSTRUCTOR(DemoDrivetrain_task_0100ms, DemoDrivetrain_task_0100ms(), 0, Application_DemoDrivetrain_task_0100ms_DemoDrivetrain_task_0100ms_SERIALIZE);
    ShiftLogicController = NULL;
    SpeedChart = NULL;
    itsDemoDrivetrainSubsystem = NULL;
    itsDriver = NULL;
    itsEngineChart = NULL;
    //#[ operation DemoDrivetrain_task_0100ms() 
    
    init();
    //#]
}

DemoDrivetrain_task_0100ms::~DemoDrivetrain_task_0100ms() {
    NOTIFY_DESTRUCTOR(~DemoDrivetrain_task_0100ms, TRUE);
    //#[ operation ~DemoDrivetrain_task_0100ms() 
    
    clean();
    //#]
    cleanUpRelations();
}

void DemoDrivetrain_task_0100ms::broadcast() {
    NOTIFY_OPERATION(broadcast, broadcast(), 0, Application_DemoDrivetrain_task_0100ms_broadcast_SERIALIZE);
    //#[ operation broadcast() 
    
    itsDriver->broadcast();
    ShiftLogicController->broadcast();
    SpeedChart->broadcast();
    itsEngineChart->broadcast();
    itsDemoDrivetrainSubsystem->broadcast();
    //#]
}

void DemoDrivetrain_task_0100ms::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, Application_DemoDrivetrain_task_0100ms_clean_SERIALIZE);
    //#[ operation clean() 
    
    if (itsDriver)
    {
      delete itsDriver;
      itsDriver = NULL;
    }
    
    if (ShiftLogicController)
    {
      delete ShiftLogicController;
      ShiftLogicController = NULL;
    }
    
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
    
    if (itsDemoDrivetrainSubsystem)
    {
      delete itsDemoDrivetrainSubsystem;
      itsDemoDrivetrainSubsystem = NULL;
    }
    
    //#]
}

void DemoDrivetrain_task_0100ms::handle_tick() {
    NOTIFY_OPERATION(handle_tick, handle_tick(), 0, Application_DemoDrivetrain_task_0100ms_handle_tick_SERIALIZE);
    //#[ operation handle_tick() 
    
    if (nTicks == 0)
    {
      itsDemoDrivetrainSubsystem->handle_tick();
      itsDriver->handle_tick();
      ShiftLogicController->handle_tick();
      SpeedChart->handle_tick();
      itsEngineChart->handle_tick();
    }
    if (++nTicks == interval) nTicks = 0;
    //#]
}

void DemoDrivetrain_task_0100ms::init() {
    NOTIFY_OPERATION(init, init(), 0, Application_DemoDrivetrain_task_0100ms_init_SERIALIZE);
    //#[ operation init() 
    
    // calculate the number of ticks (period) before broadcasting tick()
    long task_TS = 100;
    long fastest_task_TS = 100;
    interval = task_TS / fastest_task_TS;
    nTicks = 0;
    itsDriver = new Driver();
    itsDriver->setPeriod(task_TS);
    itsDriver->startBehavior();
    
    ShiftLogicController = new Controller();
    ShiftLogicController->setPeriod(task_TS);
    ShiftLogicController->startBehavior();
    
    SpeedChart = new Chart();
    SpeedChart->setPeriod(task_TS);
    
    itsEngineChart = new Chart();
    itsEngineChart->setPeriod(task_TS);
    
    itsDemoDrivetrainSubsystem = new DemoDrivetrainSubsystem();
    
    //#]
}

void DemoDrivetrain_task_0100ms::setTime(const double  t) {
    NOTIFY_OPERATION(setTime, setTime(const double), 0, Application_DemoDrivetrain_task_0100ms_setTime_SERIALIZE);
    //#[ operation setTime(const double) 
    
    itsDriver->setTime(t);
    ShiftLogicController->setTime(t);
    SpeedChart->setTime(t);
    itsEngineChart->setTime(t);
    itsDemoDrivetrainSubsystem->setTime(t);
    //#]
}

void DemoDrivetrain_task_0100ms::setInterval(long  p_interval) {
    interval = p_interval;
}

void DemoDrivetrain_task_0100ms::setNTicks(long  p_nTicks) {
    nTicks = p_nTicks;
}

void DemoDrivetrain_task_0100ms::cleanUpRelations() {
    if(ShiftLogicController != NULL)
        {
            NOTIFY_RELATION_CLEARED("ShiftLogicController");
            ShiftLogicController = NULL;
        }
    if(SpeedChart != NULL)
        {
            SpeedChart = NULL;
        }
    if(itsDemoDrivetrainSubsystem != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsDemoDrivetrainSubsystem");
            itsDemoDrivetrainSubsystem = NULL;
        }
    if(itsDriver != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsDriver");
            itsDriver = NULL;
        }
    if(itsEngineChart != NULL)
        {
            itsEngineChart = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedDemoDrivetrain_task_0100ms::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedDemoDrivetrain_task_0100ms::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("itsDriver", FALSE, TRUE);
    if(myReal->itsDriver)
        aomsRelations->ADD_ITEM(myReal->itsDriver);
    aomsRelations->addRelation("ShiftLogicController", FALSE, TRUE);
    if(myReal->ShiftLogicController)
        aomsRelations->ADD_ITEM(myReal->ShiftLogicController);
    aomsRelations->addRelation("itsDemoDrivetrainSubsystem", FALSE, TRUE);
    if(myReal->itsDemoDrivetrainSubsystem)
        aomsRelations->ADD_ITEM(myReal->itsDemoDrivetrainSubsystem);
}

IMPLEMENT_META(DemoDrivetrain_task_0100ms, Application, FALSE, OMAnimatedDemoDrivetrain_task_0100ms)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\DemoDrivetrain_task_0100ms.cpp
*********************************************************************/

