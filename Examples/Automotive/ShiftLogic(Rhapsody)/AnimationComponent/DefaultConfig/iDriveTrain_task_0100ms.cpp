/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: iDriveTrain_task_0100ms
//!	Generated Date	: Tue, 21, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\iDriveTrain_task_0100ms.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "iDriveTrain_task_0100ms.h"
#include "Chart.h"
#include "Controller.h"
#include "Driver.h"
#include "iDriveTrainSubsystem.h"

//## package Application 


//#[ ignore 
#define Application_iDriveTrain_task_0100ms_iDriveTrain_task_0100ms_SERIALIZE OM_NO_OP


#define Application_iDriveTrain_task_0100ms_broadcast_SERIALIZE OM_NO_OP


#define Application_iDriveTrain_task_0100ms_clean_SERIALIZE OM_NO_OP


#define Application_iDriveTrain_task_0100ms_handle_tick_SERIALIZE OM_NO_OP


#define Application_iDriveTrain_task_0100ms_init_SERIALIZE OM_NO_OP


#define Application_iDriveTrain_task_0100ms_setTime_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// iDriveTrain_task_0100ms.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(Application)
//## class iDriveTrain_task_0100ms 



iDriveTrain_task_0100ms::iDriveTrain_task_0100ms() : nTicks(0) ,interval(0) {
    NOTIFY_CONSTRUCTOR(iDriveTrain_task_0100ms, iDriveTrain_task_0100ms(), 0, Application_iDriveTrain_task_0100ms_iDriveTrain_task_0100ms_SERIALIZE);
    ShiftLogicController = NULL;
    SpeedChart = NULL;
    itsDriver = NULL;
    itsEngineChart = NULL;
    itsiDriveTrainSubsystem = NULL;
    //#[ operation iDriveTrain_task_0100ms() 
    
    init();
    //#]
}

iDriveTrain_task_0100ms::~iDriveTrain_task_0100ms() {
    NOTIFY_DESTRUCTOR(~iDriveTrain_task_0100ms, TRUE);
    //#[ operation ~iDriveTrain_task_0100ms() 
    
    clean();
    //#]
    cleanUpRelations();
}

void iDriveTrain_task_0100ms::broadcast() {
    NOTIFY_OPERATION(broadcast, broadcast(), 0, Application_iDriveTrain_task_0100ms_broadcast_SERIALIZE);
    //#[ operation broadcast() 
    
    itsDriver->broadcast();
    ShiftLogicController->broadcast();
    SpeedChart->broadcast();
    itsEngineChart->broadcast();
    itsiDriveTrainSubsystem->broadcast();
    //#]
}

void iDriveTrain_task_0100ms::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, Application_iDriveTrain_task_0100ms_clean_SERIALIZE);
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
    
    if (itsiDriveTrainSubsystem)
    {
      delete itsiDriveTrainSubsystem;
      itsiDriveTrainSubsystem = NULL;
    }
    
    //#]
}


void iDriveTrain_task_0100ms::handle_tick() {
    NOTIFY_OPERATION(handle_tick, handle_tick(), 0, Application_iDriveTrain_task_0100ms_handle_tick_SERIALIZE);
    //#[ operation handle_tick() 
    
    if (nTicks == 0)
    {
      itsDriver->handle_tick();
      ShiftLogicController->handle_tick();
      itsiDriveTrainSubsystem->handle_tick();
      SpeedChart->handle_tick();
      itsEngineChart->handle_tick();
    }
    if (++nTicks == interval) nTicks = 0;
    //#]
}

void iDriveTrain_task_0100ms::init() {
    NOTIFY_OPERATION(init, init(), 0, Application_iDriveTrain_task_0100ms_init_SERIALIZE);
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
    
    itsiDriveTrainSubsystem = new iDriveTrainSubsystem();
    
    //#]
}

void iDriveTrain_task_0100ms::setTime(const double  t) {
    NOTIFY_OPERATION(setTime, setTime(const double), 0, Application_iDriveTrain_task_0100ms_setTime_SERIALIZE);
    //#[ operation setTime(const double) 
    
    itsDriver->setTime(t);
    ShiftLogicController->setTime(t);
    SpeedChart->setTime(t);
    itsEngineChart->setTime(t);
    itsiDriveTrainSubsystem->setTime(t);
    //#]
}

void iDriveTrain_task_0100ms::setInterval(long  p_interval) {
    interval = p_interval;
}

void iDriveTrain_task_0100ms::setNTicks(long  p_nTicks) {
    nTicks = p_nTicks;
}

void iDriveTrain_task_0100ms::cleanUpRelations() {
    if(ShiftLogicController != NULL)
        {
            NOTIFY_RELATION_CLEARED("ShiftLogicController");
            ShiftLogicController = NULL;
        }
    if(SpeedChart != NULL)
        {
            SpeedChart = NULL;
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
    if(itsiDriveTrainSubsystem != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsiDriveTrainSubsystem");
            itsiDriveTrainSubsystem = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatediDriveTrain_task_0100ms::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatediDriveTrain_task_0100ms::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("itsDriver", FALSE, TRUE);
    if(myReal->itsDriver)
        aomsRelations->ADD_ITEM(myReal->itsDriver);
    aomsRelations->addRelation("ShiftLogicController", FALSE, TRUE);
    if(myReal->ShiftLogicController)
        aomsRelations->ADD_ITEM(myReal->ShiftLogicController);
    aomsRelations->addRelation("itsiDriveTrainSubsystem", FALSE, TRUE);
    if(myReal->itsiDriveTrainSubsystem)
        aomsRelations->ADD_ITEM(myReal->itsiDriveTrainSubsystem);
}

IMPLEMENT_META(iDriveTrain_task_0100ms, Application, FALSE, OMAnimatediDriveTrain_task_0100ms)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\iDriveTrain_task_0100ms.cpp
*********************************************************************/

