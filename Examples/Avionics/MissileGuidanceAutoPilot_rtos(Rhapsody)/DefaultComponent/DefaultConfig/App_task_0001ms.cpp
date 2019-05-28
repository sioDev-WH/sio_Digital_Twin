/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: App_task_0001ms
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\App_task_0001ms.cpp
*********************************************************************/

#include "App_task_0001ms.h"
#include "AppAirFrame.h"
#include "AutoPilot.h"

//## package Default 

//----------------------------------------------------------------------------
// App_task_0001ms.cpp                                                                  
//----------------------------------------------------------------------------
//## class App_task_0001ms 



App_task_0001ms::App_task_0001ms() : nTicks(0) ,interval(0) {
    AutoPilotBlock = NULL;
    itsAppAirFrame = NULL;
    //#[ operation App_task_0001ms() 
    
    init();
    //#]
}

App_task_0001ms::~App_task_0001ms() {
    //#[ operation ~App_task_0001ms() 
    
    clean();
    //#]
    cleanUpRelations();
}

void App_task_0001ms::broadcast() {
    //#[ operation broadcast() 
    
    AutoPilotBlock->broadcast();
    itsAppAirFrame->broadcast();
    //#]
}

void App_task_0001ms::clean() {
    //#[ operation clean() 
    
    if (AutoPilotBlock)
    {
      delete AutoPilotBlock;
      AutoPilotBlock = NULL;
    }
    
    if (itsAppAirFrame)
    {
      delete itsAppAirFrame;
      itsAppAirFrame = NULL;
    }
    
    //#]
}

void App_task_0001ms::handle_tick() {
    //#[ operation handle_tick() 

    // KAB
  	double Fin;
    double accelData;
    static double t = 0.0;
    static int skipIndex = 0;
    // KAB

    if (nTicks == 0)
    {
      itsAppAirFrame->handle_tick();
      AutoPilotBlock->handle_tick();
    }
    if (++nTicks == interval) nTicks = 0;
    
    
    // KAB
    t += itsChart->getPeriod() / 1000.0;
    if(++skipIndex == 20){
    	Fin = AutoPilotBlock->getFin()*57.295779513082320876798154814105;
    	accelData = AutoPilotBlock->getAccelData()/9.81;
    	itsChart->handle_plotData(t, &Fin, 1);
    	itsChart1->handle_plotData(t, &accelData, 1);
    	skipIndex=0;
    }
    // KAB

    //#]
}

void App_task_0001ms::init() {
    //#[ operation init() 
    
    // calculate the number of ticks (period) before broadcasting tick()
    long task_TS = 1;
    long fastest_task_TS = 1;
    interval = task_TS / fastest_task_TS;
    nTicks = 0;
    AutoPilotBlock = new AutoPilot();
    AutoPilotBlock->setPeriod(task_TS);
    
    itsAppAirFrame = new AppAirFrame();
    
    // KAB
    itsChart = new Chart();
    itsChart1 = new Chart();
    itsChart->setPeriod(task_TS);
    itsChart1->setPeriod(task_TS);
    BSTR nameFin = ::SysAllocString(L"FinPosition");
    BSTR nameAccelData = ::SysAllocString(L"Acceleration");
    itsChart->initPlot(1, false, &nameFin);
    itsChart1->initPlot(1, false, &nameAccelData);
    ::SysFreeString(nameFin);
    ::SysFreeString(nameAccelData);
    // KAB

    //#]
}

void App_task_0001ms::setTime(const double  t) {
    //#[ operation setTime(const double) 
    
    AutoPilotBlock->setTime(t);
    itsAppAirFrame->setTime(t);
    //#]
}

void App_task_0001ms::setInterval(long  p_interval) {
    interval = p_interval;
}

void App_task_0001ms::setNTicks(long  p_nTicks) {
    nTicks = p_nTicks;
}

void App_task_0001ms::cleanUpRelations() {
    if(AutoPilotBlock != NULL)
        {
            AutoPilotBlock = NULL;
        }
    if(itsAppAirFrame != NULL)
        {
            itsAppAirFrame = NULL;
        }
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\App_task_0001ms.cpp
*********************************************************************/

