/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: App1_task_0040ms
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\App1_task_0040ms.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "App1_task_0040ms.h"
#include "Animation.h"
#include "EstimatorLOS.h"

//## package Application 


//#[ ignore 
#define Application_App1_task_0040ms_App1_task_0040ms_SERIALIZE OM_NO_OP


#define Application_App1_task_0040ms_broadcast_SERIALIZE aomsmethod->addAttribute("t", x2String(t));


#define Application_App1_task_0040ms_clean_SERIALIZE OM_NO_OP


#define Application_App1_task_0040ms_handle_tick_SERIALIZE aomsmethod->addAttribute("t", x2String(t));


#define Application_App1_task_0040ms_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// App1_task_0040ms.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(Application)
//## class App1_task_0040ms 



App1_task_0040ms::App1_task_0040ms() : nTicks(0) ,period(0) {
    NOTIFY_ACTIVE_NOT_REACTIVE_CONSTRUCTOR(App1_task_0040ms, App1_task_0040ms(), 0, Application_App1_task_0040ms_App1_task_0040ms_SERIALIZE);
    itsAvionicsAnimation = NULL;
    itsLOSEstimator = NULL;
    //#[ operation App1_task_0040ms() 
    
    init();
    //#]
}

App1_task_0040ms::~App1_task_0040ms() {
    NOTIFY_DESTRUCTOR(~App1_task_0040ms, TRUE);
    //#[ operation ~App1_task_0040ms() 
    
    clean();
    //#]
    cleanUpRelations();
}

void App1_task_0040ms::broadcast(const double  t) {
    NOTIFY_OPERATION(broadcast, broadcast(const double), 1, Application_App1_task_0040ms_broadcast_SERIALIZE);
    //#[ operation broadcast(const double) 
    
    itsLOSEstimator->broadcast(t);
    itsAvionicsAnimation->broadcast(t);
    //#]
}

void App1_task_0040ms::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, Application_App1_task_0040ms_clean_SERIALIZE);
    //#[ operation clean() 
    
    if (itsLOSEstimator)
    {
      delete itsLOSEstimator;
      itsLOSEstimator = NULL;
    }
    
    if (itsAvionicsAnimation)
    {
      delete itsAvionicsAnimation;
      itsAvionicsAnimation = NULL;
    }
    
    
    //#]
}

void App1_task_0040ms::handle_tick(const double  t) {
    NOTIFY_OPERATION(handle_tick, handle_tick(const double), 1, Application_App1_task_0040ms_handle_tick_SERIALIZE);
    //#[ operation handle_tick(const double) 
    
    if (nTicks == 0)
    {
      itsLOSEstimator->handle_tick(t);
      itsAvionicsAnimation->handle_tick(t);
    }
    if (++nTicks == period) nTicks = 0;
    //#]
}

void App1_task_0040ms::init() {
    NOTIFY_OPERATION(init, init(), 0, Application_App1_task_0040ms_init_SERIALIZE);
    //#[ operation init() 
    
    // calculate the number of ticks (period) before broadcasting tick()
    long task_TS = 40;
    long fastest_task_TS = 1;
    period = task_TS / fastest_task_TS;
    nTicks = 0;
    itsLOSEstimator = new EstimatorLOS();
    
    itsAvionicsAnimation = new Animation();
    
    //#]
}

void App1_task_0040ms::setNTicks(long  p_nTicks) {
    nTicks = p_nTicks;
}

void App1_task_0040ms::setPeriod(long  p_period) {
    period = p_period;
}

void App1_task_0040ms::cleanUpRelations() {
    if(itsAvionicsAnimation != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsAvionicsAnimation");
            itsAvionicsAnimation = NULL;
        }
    if(itsLOSEstimator != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsLOSEstimator");
            itsLOSEstimator = NULL;
        }
}

OMBoolean App1_task_0040ms::startBehavior() {
    OMBoolean done = FALSE;
    if(done)
        start();
    return done;
}



#ifdef _OMINSTRUMENT


void OMAnimatedApp1_task_0040ms::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("nTicks", x2String(myReal->nTicks));
    aomsAttributes->addAttribute("period", x2String(myReal->period));
}

void OMAnimatedApp1_task_0040ms::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("itsLOSEstimator", FALSE, TRUE);
    if(myReal->itsLOSEstimator)
        aomsRelations->ADD_ITEM(myReal->itsLOSEstimator);
    aomsRelations->addRelation("itsAvionicsAnimation", FALSE, TRUE);
    if(myReal->itsAvionicsAnimation)
        aomsRelations->ADD_ITEM(myReal->itsAvionicsAnimation);
}

IMPLEMENT_META(App1_task_0040ms, Application, FALSE, OMAnimatedApp1_task_0040ms)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\App1_task_0040ms.cpp
*********************************************************************/

