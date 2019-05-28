/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: App1_task_0010ms
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\App1_task_0010ms.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "App1_task_0010ms.h"
#include "Chart.h"
#include "GuidanceLogic.h"
#include "SeekerSubsystem.h"
#include "Target.h"

//## package Application 


//#[ ignore 
#define Application_App1_task_0010ms_App1_task_0010ms_SERIALIZE OM_NO_OP


#define Application_App1_task_0010ms_broadcast_SERIALIZE aomsmethod->addAttribute("t", x2String(t));


#define Application_App1_task_0010ms_clean_SERIALIZE OM_NO_OP


#define Application_App1_task_0010ms_handle_tick_SERIALIZE aomsmethod->addAttribute("t", x2String(t));


#define Application_App1_task_0010ms_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// App1_task_0010ms.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(Application)
//## class App1_task_0010ms 



App1_task_0010ms::App1_task_0010ms() : nTicks(0) ,period(0) {
    NOTIFY_ACTIVE_NOT_REACTIVE_CONSTRUCTOR(App1_task_0010ms, App1_task_0010ms(), 0, Application_App1_task_0010ms_App1_task_0010ms_SERIALIZE);
    itsChart = NULL;
    itsGuidanceLogic = NULL;
    itsSeeker = NULL;
    itsTarget = NULL;
    //#[ operation App1_task_0010ms() 
    
    init();
    //#]
}

App1_task_0010ms::~App1_task_0010ms() {
    NOTIFY_DESTRUCTOR(~App1_task_0010ms, TRUE);
    //#[ operation ~App1_task_0010ms() 
    
    clean();
    //#]
    cleanUpRelations();
}

void App1_task_0010ms::broadcast(const double  t) {
    NOTIFY_OPERATION(broadcast, broadcast(const double), 1, Application_App1_task_0010ms_broadcast_SERIALIZE);
    //#[ operation broadcast(const double) 
    
    itsTarget->broadcast(t);
    itsGuidanceLogic->broadcast(t);
    itsSeeker->broadcast(t);
    //#]
}

void App1_task_0010ms::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, Application_App1_task_0010ms_clean_SERIALIZE);
    //#[ operation clean() 
    
    if (itsTarget)
    {
      delete itsTarget;
      itsTarget = NULL;
    }
    
    if (itsGuidanceLogic)
    {
      delete itsGuidanceLogic;
      itsGuidanceLogic = NULL;
    }
    
    if (itsSeeker)
    {
      delete itsSeeker;
      itsSeeker = NULL;
    }
    
    if (itsChart)
    {
      delete itsChart;
      itsChart = NULL;
    }
    
    //#]
}

void App1_task_0010ms::handle_tick(const double  t) {
    NOTIFY_OPERATION(handle_tick, handle_tick(const double), 1, Application_App1_task_0010ms_handle_tick_SERIALIZE);
    //#[ operation handle_tick(const double) 
    double data[3];
    if (nTicks == 0)
    {
      itsTarget->handle_tick(t);
      itsGuidanceLogic->handle_tick(t);
      itsSeeker->handle_tick(t); 
      data[0] = itsSeeker->gimbalAngle/d2r;
      data[1] = itsGuidanceLogic->getGuidanceMode();
      data[2] = itsGuidanceLogic->getRange()/500.0;
      itsChart->handle_plotData(t, data, 3);
    }
    if (++nTicks == period) nTicks = 0;
    //#]
}

void App1_task_0010ms::init() {
    NOTIFY_OPERATION(init, init(), 0, Application_App1_task_0010ms_init_SERIALIZE);
    //#[ operation init() 
    
    // calculate the number of ticks (period) before broadcasting tick()
    long task_TS = 10;
    long fastest_task_TS = 1;
    period = task_TS / fastest_task_TS;
    nTicks = 0;
    itsTarget = new Target();
    
    itsGuidanceLogic = new GuidanceLogic();
    itsGuidanceLogic->startBehavior();
    
    itsSeeker = new SeekerSubsystem();
    
    itsSeeker->itsGuidanceLogic = itsGuidanceLogic;
    
    itsChart = new Chart();
    const long numberOfSeries = 3;
    const bool bPoint=0;
    
    BSTR  pNames[3];
    
    pNames[0] = ::SysAllocString(L"Gimbal Angle");
    pNames[1] = ::SysAllocString(L"Guidance Mode");
    pNames[2] = ::SysAllocString(L"Range"); 
    
    itsChart->initPlot(3,0, pNames);
    itsChart->SetName(L"Guidance Data");
    
    ::SysFreeString(pNames[0]); 
    ::SysFreeString(pNames[1]);
    ::SysFreeString(pNames[2]);
    
    //#]
}

void App1_task_0010ms::setNTicks(long  p_nTicks) {
    nTicks = p_nTicks;
}

void App1_task_0010ms::setPeriod(long  p_period) {
    period = p_period;
}

Chart* App1_task_0010ms::getItsChart() const {
    return itsChart;
}

void App1_task_0010ms::setItsChart(Chart*  p_Chart) {
    itsChart = p_Chart;
    if(p_Chart != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("itsChart", p_Chart, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("itsChart");
        }
}

void App1_task_0010ms::cleanUpRelations() {
    if(itsChart != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsChart");
            itsChart = NULL;
        }
    if(itsGuidanceLogic != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsGuidanceLogic");
            itsGuidanceLogic = NULL;
        }
    if(itsSeeker != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsSeeker");
            itsSeeker = NULL;
        }
    if(itsTarget != NULL)
        {
            NOTIFY_RELATION_CLEARED("itsTarget");
            itsTarget = NULL;
        }
}

OMBoolean App1_task_0010ms::startBehavior() {
    OMBoolean done = FALSE;
    if(done)
        start();
    return done;
}



#ifdef _OMINSTRUMENT


void OMAnimatedApp1_task_0010ms::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    aomsAttributes->addAttribute("nTicks", x2String(myReal->nTicks));
    aomsAttributes->addAttribute("period", x2String(myReal->period));
}

void OMAnimatedApp1_task_0010ms::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("itsTarget", FALSE, TRUE);
    if(myReal->itsTarget)
        aomsRelations->ADD_ITEM(myReal->itsTarget);
    aomsRelations->addRelation("itsGuidanceLogic", FALSE, TRUE);
    if(myReal->itsGuidanceLogic)
        aomsRelations->ADD_ITEM(myReal->itsGuidanceLogic);
    aomsRelations->addRelation("itsSeeker", FALSE, TRUE);
    if(myReal->itsSeeker)
        aomsRelations->ADD_ITEM(myReal->itsSeeker);
    aomsRelations->addRelation("itsChart", FALSE, TRUE);
    if(myReal->itsChart)
        aomsRelations->ADD_ITEM(myReal->itsChart);
}

IMPLEMENT_META(App1_task_0010ms, Application, FALSE, OMAnimatedApp1_task_0010ms)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\App1_task_0010ms.cpp
*********************************************************************/

