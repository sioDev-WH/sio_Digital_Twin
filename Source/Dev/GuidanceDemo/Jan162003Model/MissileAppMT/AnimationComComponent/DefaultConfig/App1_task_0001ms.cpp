/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: App1_task_0001ms
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\App1_task_0001ms.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "App1_task_0001ms.h"
#include "AirframeSubsystem.h"
#include "AutoPilot.h"

//## package Application 


//#[ ignore 
#define Application_App1_task_0001ms_App1_task_0001ms_SERIALIZE OM_NO_OP


#define Application_App1_task_0001ms_broadcast_SERIALIZE aomsmethod->addAttribute("t", x2String(t));


#define Application_App1_task_0001ms_clean_SERIALIZE OM_NO_OP


#define Application_App1_task_0001ms_handle_tick_SERIALIZE aomsmethod->addAttribute("t", x2String(t));


#define Application_App1_task_0001ms_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// App1_task_0001ms.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(Application)
//## class App1_task_0001ms 



App1_task_0001ms::App1_task_0001ms() : nTicks(0) ,period(0) {
    NOTIFY_ACTIVE_NOT_REACTIVE_CONSTRUCTOR(App1_task_0001ms, App1_task_0001ms(), 0, Application_App1_task_0001ms_App1_task_0001ms_SERIALIZE);
    itsAirframeSubsystem = NULL;
    itsAutoPilot = NULL;
    //#[ operation App1_task_0001ms() 
    
    init();
    //#]
}

App1_task_0001ms::~App1_task_0001ms() {
    NOTIFY_DESTRUCTOR(~App1_task_0001ms, TRUE);
    //#[ operation ~App1_task_0001ms() 
    
    clean();
    //#]
    cleanUpRelations();
}

void App1_task_0001ms::broadcast(const double  t) {
    NOTIFY_OPERATION(broadcast, broadcast(const double), 1, Application_App1_task_0001ms_broadcast_SERIALIZE);
    //#[ operation broadcast(const double) 
    
    itsAutoPilot->broadcast(t);
    itsAirframeSubsystem->broadcast(t);
    //#]
}

void App1_task_0001ms::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, Application_App1_task_0001ms_clean_SERIALIZE);
    //#[ operation clean() 
    
    if (itsAutoPilot)
    {
      delete itsAutoPilot;
      itsAutoPilot = NULL;
    }
    
    if (itsAirframeSubsystem)
    {
      delete itsAirframeSubsystem;
      itsAirframeSubsystem = NULL;
    }
    
    //#]
}

void App1_task_0001ms::handle_tick(const double  t) {
    NOTIFY_OPERATION(handle_tick, handle_tick(const double), 1, Application_App1_task_0001ms_handle_tick_SERIALIZE);
    //#[ operation handle_tick(const double) 
    
    if (nTicks == 0)
    {
      itsAutoPilot->handle_tick(t);
      itsAirframeSubsystem->handle_tick(t);
    }
    if (++nTicks == period) nTicks = 0;
    //#]
}

void App1_task_0001ms::init() {
    NOTIFY_OPERATION(init, init(), 0, Application_App1_task_0001ms_init_SERIALIZE);
    //#[ operation init() 
    
    // calculate the number of ticks (period) before broadcasting tick()
    long task_TS = 10;
    long fastest_task_TS = 1;
    period = task_TS / fastest_task_TS;
    nTicks = 0;
    itsAutoPilot = new AutoPilot();
    
    itsAirframeSubsystem = new AirframeSubsystem();
    
    //#]
}

void App1_task_0001ms::setNTicks(long  p_nTicks) {
    nTicks = p_nTicks;
}

void App1_task_0001ms::setPeriod(long  p_period) {
    period = p_period;
}

void App1_task_0001ms::cleanUpRelations() {
    if(itsAirframeSubsystem != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsAirframeSubsystem");
            itsAirframeSubsystem = NULL;
        }
    if(itsAutoPilot != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsAutoPilot");
            itsAutoPilot = NULL;
        }
}

OMBoolean App1_task_0001ms::startBehavior() {
    OMBoolean done = FALSE;
    if(done)
        start();
    return done;
}



#ifdef _OMINSTRUMENT


void OMAnimatedApp1_task_0001ms::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("nTicks", x2String(myReal->nTicks));
    aomsAttributes->addAttribute("period", x2String(myReal->period));
}

void OMAnimatedApp1_task_0001ms::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("itsAutoPilot", FALSE, TRUE);
    if(myReal->itsAutoPilot)
        aomsRelations->ADD_ITEM(myReal->itsAutoPilot);
    aomsRelations->addRelation("itsAirframeSubsystem", FALSE, TRUE);
    if(myReal->itsAirframeSubsystem)
        aomsRelations->ADD_ITEM(myReal->itsAirframeSubsystem);
}

IMPLEMENT_META(App1_task_0001ms, Application, FALSE, OMAnimatedApp1_task_0001ms)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\App1_task_0001ms.cpp
*********************************************************************/

