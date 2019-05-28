//{{SCG_IMPLEMENTATION(Controller.cpp) [0]

//{{SCG_INCLUDE   
//{{SCG_INCLUDE  
#include "StdAfx.h"
#include "Controller.h"
#include "Clutch_Schedule.h"
#include "OnUMLEsoMacros.h"

// Include for Template Class should go here.
//#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

//{{SCG_CLASS_ID
#ifdef RTS_SIMULATION
const static RtsClassInfo RtsController_ClassInfo("eafa135c-6337-11d5-b148-00c04f680d9d", RTS_STM);
#endif
//}}SCG_CLASS_ID

//{{SCG_ICLASS_INFO(0)


//}}SCG_ICLASS_INFO
//{{SCG_ATTS(0)
//}}SCG_ATTS

//{{SCG_ROLES(0)
//}}SCG_ROLES

//{{SCG_OPS(0)

//{{SCG_OP(0.0)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::updateThresholds()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
shiftData.getDownShiftThreshold (throttleData, currentGear, &downShiftThreshold);

shiftData.getUpShiftThreshold(throttleData, currentGear, &upShiftThreshold);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.1)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::init()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
m_cRef = 0;

transition_time = 0.0;

upshiftDelay[0] = 0.0;
upshiftDelay[1] = 0.0;
upshiftDelay[2] = 0.0;
upshiftDelay[3] = 0.1;

downshiftDelay[0] = 0.2;
downshiftDelay[1] = 0.2;
downshiftDelay[2] = 0.2;
downshiftDelay[3] = 0.2;

  
currentGear=0;
throttleData=0.0;
vehicleSpeedData=0.0;
shiftLeverData=0; // for N; +/-1 for D and R
shiftData.init();

for (long i = 0; i < 10; i++)
{
  pActuatorPorts[i] = new Port_Int();
  pActuatorPorts[i]->AddRef();
}

Port_0 = pActuatorPorts[0];
Port_1 = pActuatorPorts[1];
Port_2 = pActuatorPorts[2];
Port_3 = pActuatorPorts[3];
Port_4 = pActuatorPorts[4];
Port_5 = pActuatorPorts[5];
Port_6 = pActuatorPorts[6];
Port_7 = pActuatorPorts[7];
Port_8 = pActuatorPorts[8];

Port_Shift = pActuatorPorts[9];
//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.4)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::downShift()  
//}}SCG_OP_INFO
{
#if 1
  ATLTRACE("\nController::downShift()");
#endif

/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsLock(RtsBusy);

    long downshift = 0;
    Port_Shift->gen(&downshift);

    if (RtsCurrent_Controller == RtsControllerController_States_Second)
    {
        RtsExit_Second();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"eafa13cc-6337-11d5-b148-00c04f680d9d",0,NULL);

        RtsEnter_SecondToFirst();
    }
    else if (RtsCurrent_Controller == RtsControllerController_States_Third)
    {
        RtsExit_Third();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"eafa13d1-6337-11d5-b148-00c04f680d9d",0,NULL);

        RtsEnter_ThirdToSecond();
    }
    else if (RtsCurrent_Controller == RtsControllerController_States_Fourth)
    {
        RtsExit_Fourth();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"eafa13db-6337-11d5-b148-00c04f680d9d",0,NULL);

        RtsEnter_FourthToThird();
    }
    else
    {
        /* Event not handled */
    }
    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.3)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::upShift()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsLock(RtsBusy);

    long upshift = 1;
    Port_Shift->gen(&upshift);


    if (RtsCurrent_Controller == RtsControllerController_States_First)
    {
        RtsExit_First();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"eafa139f-6337-11d5-b148-00c04f680d9d",0,NULL);

        RtsEnter_FirstToSecond();
    }
    else if (RtsCurrent_Controller == RtsControllerController_States_Second)
    {
        RtsExit_Second();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"eafa13a4-6337-11d5-b148-00c04f680d9d",0,NULL);

        RtsEnter_SecondToThird();
    }
    else if (RtsCurrent_Controller == RtsControllerController_States_Third)
    {
        RtsExit_Third();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"eafa13b8-6337-11d5-b148-00c04f680d9d",0,NULL);

        RtsEnter_ThirdToFourth();
    }
    else
    {
        /* Event not handled */
    }
    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.2)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::runShiftLogic()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
if(vehicleSpeedData<=downShiftThreshold && currentGear > 1)
{
  shiftData.clutchSchedule->update(currentGear,currentGear-1);
  downShift(); 
}
else if(vehicleSpeedData>upShiftThreshold)
{
  shiftData.clutchSchedule->update(currentGear,currentGear+1);
  upShift();
}

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.5)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::Fire_DisengageEvents()  
//}}SCG_OP_INFO
{
#if 1
  ATLTRACE("\nController::Fire_DisengageEvents()");
#endif

/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int i;
long engageMsg = 0;
for(i=0;i<shiftData.clutchSchedule->nClutches;i++)
if(shiftData.clutchSchedule->disengageList[i])
{
  pActuatorPorts[i]->gen(&engageMsg );
}

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.6)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::clean()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
for (long i = 0; i < 10; i++)
{
  if (pActuatorPorts[i]) pActuatorPorts[i]->Release();
  pActuatorPorts[i] = NULL;
}
//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.7)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::Fire_EngageEvents()  
//}}SCG_OP_INFO
{

#if 1
  ATLTRACE("\nController::Fire_EngageEvents()");
#endif

/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
long i;
long engageMsg=1;
for(i=0;i<shiftData.clutchSchedule->nClutches;i++)
if(shiftData.clutchSchedule->engageList[i])
{
  pActuatorPorts[i]->gen(&engageMsg);
}

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.8)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::handle_ThrottleData(const double time, double *val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
throttleData = *val;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.9)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::handle_SpeedData(double val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
vehicleSpeedData = val;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.10)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::handle_ShiftLeverData(const double time, long *val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
shiftLeverData = *val;
if(shiftLeverData==0)
  RtsmanualNeutralShift();
else if(shiftLeverData==1)
  RtsmanualForwardShift();
if(shiftLeverData==-1)
  RtsmanualReverseShift();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.11)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::handle_tick(double *time)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  
  receive();
  local_time = *time;
  Rtsclock_tic();
  broadcast();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.12)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsEnter_First()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : First */
    RtsNotify(1,"eafa136e-6337-11d5-b148-00c04f680d9d",0,NULL);

    RtsCurrent_Controller = RtsControllerController_States_First;
    ATLTRACE("\ncontroller::enter_first");
    /* Entry Actions */
    if (bReverse)
      Fire_DisengageEvents ();
    else
      Fire_EngageEvents ();

    currentGear=1;
    updateThresholds();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.13)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsExit_First()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Controller == RtsControllerController_States_First)
    {
        /* Simulation support : Notification function call for exiting state : First */
        RtsNotify(2,"eafa136e-6337-11d5-b148-00c04f680d9d",0,NULL);

    ATLTRACE("\ncontroller::exit_First");

        /* Exit Actions */
        if (bReverse)
          Fire_EngageEvents ();
        else
          Fire_DisengageEvents ();
    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.14)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsEnter_Second()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Second */
    RtsNotify(1,"eafa1376-6337-11d5-b148-00c04f680d9d",0,NULL);

    RtsCurrent_Controller = RtsControllerController_States_Second;
    ATLTRACE("\ncontroller::enter_second");

    /* Entry Actions */
    if (bReverse)
      Fire_DisengageEvents ();
    else
      Fire_EngageEvents ();
    currentGear=2;
    updateThresholds();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.15)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsExit_Second()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Controller == RtsControllerController_States_Second)
    {
        /* Simulation support : Notification function call for exiting state : Second */
        RtsNotify(2,"eafa1376-6337-11d5-b148-00c04f680d9d",0,NULL);


        /* Exit Actions */
        if (bReverse)
          Fire_EngageEvents ();
        else
          Fire_DisengageEvents ();
    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.16)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsEnter_Third()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Third */
    RtsNotify(1,"eafa137d-6337-11d5-b148-00c04f680d9d",0,NULL);

    RtsCurrent_Controller = RtsControllerController_States_Third;
    ATLTRACE("\ncontroller::enter_third");

    /* Entry Actions */
    if (bReverse)
      Fire_DisengageEvents ();
    else
      Fire_EngageEvents ();

    currentGear=3;
    updateThresholds();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.17)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsExit_Third()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Controller == RtsControllerController_States_Third)
    {
        /* Simulation support : Notification function call for exiting state : Third */
        RtsNotify(2,"eafa137d-6337-11d5-b148-00c04f680d9d",0,NULL);


        /* Exit Actions */
        if (bReverse)
          Fire_EngageEvents ();
        else
          Fire_DisengageEvents ();
    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.18)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsEnter_Fourth()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Fourth */
    RtsNotify(1,"eafa1383-6337-11d5-b148-00c04f680d9d",0,NULL);

    RtsCurrent_Controller = RtsControllerController_States_Fourth;
    ATLTRACE("\ncontroller::enter_fourth");

    /* Entry Actions */
    if (bReverse)
      Fire_DisengageEvents ();
    else
      Fire_EngageEvents ();

    currentGear=4;
    updateThresholds();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.19)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsExit_Fourth()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Controller == RtsControllerController_States_Fourth)
    {
        /* Simulation support : Notification function call for exiting state : Fourth */
        RtsNotify(2,"eafa1383-6337-11d5-b148-00c04f680d9d",0,NULL);


        /* Exit Actions */
        if (bReverse)
          Fire_EngageEvents ();
        else
          Fire_DisengageEvents ();
    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.20)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsEnter_Reverse()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Reverse */
    RtsNotify(1,"eafa138a-6337-11d5-b148-00c04f680d9d",0,NULL);

    RtsCurrent_Controller = RtsControllerController_States_Reverse;
    ATLTRACE("\ncontroller::enter_reverse");
    
    /* Entry Actions */
    if (bReverse)
      Fire_DisengageEvents ();
    else
      Fire_EngageEvents ();

    currentGear=-1;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.21)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsExit_Reverse()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Controller == RtsControllerController_States_Reverse)
    {
        /* Simulation support : Notification function call for exiting state : Reverse */
        RtsNotify(2,"eafa138a-6337-11d5-b148-00c04f680d9d",0,NULL);

        switch(RtsCurrent_Reverse)
        {
            case RtsControllerReverse_States_Active:
                RtsExit_Active();
                break;
            default:
                break;
        }
        RtsCurrent_Reverse = RtsControllerReverse_States_NotIn_Reverse;

        /* Exit Actions */
        if (bReverse)
          Fire_EngageEvents ();
        else
          Fire_DisengageEvents ();
    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.22)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsEnter_Idle()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Idle */
    RtsNotify(1,"eafa1367-6337-11d5-b148-00c04f680d9d",0,NULL);

    RtsCurrent_Controller = RtsControllerController_States_Idle;
    ATLTRACE("\ncontroller::enter_idle");

    /* Entry Actions */
    currentGear = 0;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.23)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsExit_Idle()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Controller == RtsControllerController_States_Idle)
    {
        /* Simulation support : Notification function call for exiting state : Idle */
        RtsNotify(2,"eafa1367-6337-11d5-b148-00c04f680d9d",0,NULL);

        switch(RtsCurrent_Idle)
        {
            case RtsControllerIdle_States_Ready:
                RtsExit_Ready();
                break;
            default:
                break;
        }
        RtsCurrent_Idle = RtsControllerIdle_States_NotIn_Idle;
    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.63)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

 Controller::~Controller()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsUnregister(this);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.44)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsEnter_Active()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Active */
    RtsNotify(1,"4fc37584-6418-11d5-b149-00c04f680d9d",0,NULL);

    RtsCurrent_Reverse = RtsControllerReverse_States_Active;


//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.45)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsExit_Active()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Reverse == RtsControllerReverse_States_Active)
    {
        /* Simulation support : Notification function call for exiting state : Active */
        RtsNotify(2,"4fc37584-6418-11d5-b149-00c04f680d9d",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.46)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsDefault_Reverse()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function calls for entry and exit of initial state */
    RtsNotify(1,"4fc37586-6418-11d5-b149-00c04f680d9d",0,NULL);
    RtsNotify(2,"4fc37586-6418-11d5-b149-00c04f680d9d",0,NULL);

    RtsEnter_Reverse();
    /* Simulation support : Notification function calls for default transition */
    RtsNotify(3,"4fc37588-6418-11d5-b149-00c04f680d9d",0,NULL);

    RtsEnter_Active();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.47)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsDefault_Idle()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function calls for entry and exit of initial state */
    RtsNotify(1,"4fc37566-6418-11d5-b149-00c04f680d9d",0,NULL);
    RtsNotify(2,"4fc37566-6418-11d5-b149-00c04f680d9d",0,NULL);

    RtsEnter_Idle();
    /* Simulation support : Notification function calls for default transition */
    RtsNotify(3,"4fc37568-6418-11d5-b149-00c04f680d9d",0,NULL);

    RtsEnter_Ready();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.48)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsEnter_Ready()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Ready */
    RtsNotify(1,"4fc37564-6418-11d5-b149-00c04f680d9d",0,NULL);

    RtsCurrent_Idle = RtsControllerIdle_States_Ready;


//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.49)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsExit_Ready()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Idle == RtsControllerIdle_States_Ready)
    {
        /* Simulation support : Notification function call for exiting state : Ready */
        RtsNotify(2,"4fc37564-6418-11d5-b149-00c04f680d9d",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.50)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::Rtsclock_tic()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsLock(RtsBusy);

    // upshift
    if (RtsCurrent_Controller == RtsControllerController_States_FirstToSecond)
    {
      if (local_time - transition_time - upshiftDelay[1] > 0.0)
      {
        shiftData.clutchSchedule->update(currentGear,currentGear+1);
        RtsFirstToSecond_Timer1();
      }
    }
    else if (RtsCurrent_Controller == RtsControllerController_States_SecondToThird)
    {
      if (local_time - transition_time - upshiftDelay[2] > 0.0)
      {
        shiftData.clutchSchedule->update(currentGear,currentGear+1);
        RtsSecondToThird_Timer1();
      }
    }
    else if (RtsCurrent_Controller == RtsControllerController_States_ThirdToFourth)
    {
      if (local_time - transition_time - upshiftDelay[3] > 0.0)
      {
        shiftData.clutchSchedule->update(currentGear,currentGear+1);
        RtsThirdToFourth_Timer1();
      }
    }

    // downshift
    if (RtsCurrent_Controller == RtsControllerController_States_FourthToThird)
    {
      if (local_time - transition_time - downshiftDelay[3] > 0.0)
      {
        shiftData.clutchSchedule->update(currentGear,currentGear-1);
        RtsFourthToThird_Timer1();
      }
    }
    else if (RtsCurrent_Controller == RtsControllerController_States_ThirdToSecond)
    {
      if (local_time - transition_time - downshiftDelay[2] > 0.0)
      {
        shiftData.clutchSchedule->update(currentGear,currentGear-1);
        RtsThirdToSecond_Timer1();
      }
    }
    else if (RtsCurrent_Controller == RtsControllerController_States_SecondToFirst)
    {
      if (local_time - transition_time - downshiftDelay[1] > 0.0)
      {
        shiftData.clutchSchedule->update(currentGear,currentGear-1);
        RtsSecondToFirst_Timer1();
      }
    }

    // running in a gear
    if (RtsCurrent_Controller == RtsControllerController_States_Fourth)
    {
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"e00f88c2-63ec-11d5-b149-00c04f680d9d",0,NULL);

        runShiftLogic( );
updateThresholds();
    }
    else if (RtsCurrent_Controller == RtsControllerController_States_Third)
    {
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"e00f88be-63ec-11d5-b149-00c04f680d9d",0,NULL);

        runShiftLogic( );
updateThresholds();
    }
    else if (RtsCurrent_Controller == RtsControllerController_States_Second)
    {
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"e00f88ba-63ec-11d5-b149-00c04f680d9d",0,NULL);

        runShiftLogic( );
updateThresholds();
    }
    else if (RtsCurrent_Controller == RtsControllerController_States_First)
    {
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"e00f88b5-63ec-11d5-b149-00c04f680d9d",0,NULL);

        runShiftLogic( );
updateThresholds();
    }
    else
    {
        /* Event not handled */
    }
    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.51)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsmanualNeutralShift()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsLock(RtsBusy);
    if (RtsCurrent_Controller == RtsControllerController_States_First)
    {
        RtsExit_First();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"eafa13c7-6337-11d5-b148-00c04f680d9d",0,NULL);

        shiftData.clutchSchedule->update(currentGear,currentGear-1);
        RtsDefault_Idle();
    }
    else if (RtsCurrent_Controller == RtsControllerController_States_Reverse)
    {
        RtsExit_Reverse();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"eafa13c2-6337-11d5-b148-00c04f680d9d",0,NULL);

        shiftData.clutchSchedule->update(currentGear,currentGear+1);  
        RtsDefault_Idle();
    }
    else
    {
        /* Event not handled */
    }
    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.60)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsmanualForwardShift()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsLock(RtsBusy);
    if (RtsCurrent_Controller == RtsControllerController_States_Idle)
    {
        RtsExit_Idle();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"eafa13ae-6337-11d5-b148-00c04f680d9d",0,NULL);

        shiftData.clutchSchedule->update(currentGear,currentGear+1);
        long upshift = 1;
        Port_Shift->gen(&upshift);
        RtsEnter_First();
    }
    else
    {
        /* Event not handled */
    }
    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.61)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsmanualReverseShift()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsLock(RtsBusy);
    if (RtsCurrent_Controller == RtsControllerController_States_Idle)
    {
        RtsExit_Idle();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"e00f88af-63ec-11d5-b149-00c04f680d9d",0,NULL);

        shiftData.clutchSchedule->update(currentGear,currentGear-1);
        RtsDefault_Reverse();
    }
    else
    {
        /* Event not handled */
    }
    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.62)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

 Controller::Controller()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

    bReverse = false;

    RtsRegisterStateMachine(this,RtsInjectEvent,RtsGetAttributeValue,RtsSetAttributeValue);
    RtsCreateSemaphore(RtsBusy);
    RtsLock(RtsBusy);

    /* Initialising State Vectors to NotIn */
    RtsCurrent_Controller=RtsControllerController_States_NotIn_Controller;
    RtsCurrent_Idle=RtsControllerIdle_States_NotIn_Idle;
    RtsCurrent_Reverse=RtsControllerReverse_States_NotIn_Reverse;

    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.64)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsRunToCompletion()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int EndOfLoop;
    for(EndOfLoop=0;EndOfLoop==0;)
    {
        EndOfLoop = 1;
        /* All completion transitions included here */
        if (RtsCurrent_Controller == RtsControllerController_States_NotIn_Controller)
        {
            /* Simulation support : Notification function calls for transition */
            RtsNotify(3,"eafa13e2-6337-11d5-b148-00c04f680d9d",0,NULL);

            init();
            RtsDefault_Idle();

            EndOfLoop = 0;
        }
    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            




//{{SCG_OP(0.40)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::enterSecond()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsLock(RtsBusy);
    if (RtsCurrent_Controller == RtsControllerController_States_FirstToSecond)
    {
        RtsExit_FirstToSecond();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"85184374-1b2e-409e-a6e7-54c600c0bae1",0,NULL);

        RtsEnter_Second();
    }
    else if (RtsCurrent_Controller == RtsControllerController_States_ThirdToSecond)
    {
        RtsExit_ThirdToSecond();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"4b8c8c53-5905-4940-a98c-1852ee85794c",0,NULL);

        RtsEnter_Second();
    }
    else
    {
        /* Event not handled */
    }
    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.41)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::enterThird()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsLock(RtsBusy);
    if (RtsCurrent_Controller == RtsControllerController_States_FourthToThird)
    {
        RtsExit_FourthToThird();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"1f102301-e981-4a21-9e62-1e4d9e626b7b",0,NULL);

        RtsEnter_Third();
    }
    else if (RtsCurrent_Controller == RtsControllerController_States_SecondToThird)
    {
        RtsExit_SecondToThird();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"b54cd907-3245-4fe6-a50a-46a5c24567e2",0,NULL);

        RtsEnter_Third();
    }
    else
    {
        /* Event not handled */
    }
    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.42)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::enterFourth()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsLock(RtsBusy);
    if (RtsCurrent_Controller == RtsControllerController_States_ThirdToFourth)
    {
        RtsExit_ThirdToFourth();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"ac39999d-fb02-4c51-9038-ad0e0042bd22",0,NULL);

        RtsEnter_Fourth();
    }
    else
    {
        /* Event not handled */
    }
    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.43)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::enterFirst()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsLock(RtsBusy);
    if (RtsCurrent_Controller == RtsControllerController_States_SecondToFirst)
    {
        RtsExit_SecondToFirst();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"bc6bd9f4-c05b-471b-8bf4-6fbe2b2e6f43",0,NULL);

        RtsEnter_First();
    }
    else
    {
        /* Event not handled */
    }
    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            


       

//{{SCG_OP(0.52)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsEnter_ThirdToFourth()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : ThirdToFourth */
    RtsNotify(1,"cefeba27-5d2a-4e22-8e8e-428f05f0e364",0,NULL);

    transition_time = local_time;
    RtsCurrent_Controller = RtsControllerController_States_ThirdToFourth;

    /* Start Timers */
    //RtsStartTimer(RtsAttThirdToFourth_Timer1,RtsThirdToFourth_Timer1_CallBack,(long) 1000 * upshiftDelay[3]);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.53)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsExit_ThirdToFourth()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Controller == RtsControllerController_States_ThirdToFourth)
    {
        /* Simulation support : Notification function call for exiting state : ThirdToFourth */
        RtsNotify(2,"cefeba27-5d2a-4e22-8e8e-428f05f0e364",0,NULL);

        /* Stop Timers */
        RtsStopTimer(RtsAttThirdToFourth_Timer1);
    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.54)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsEnter_ThirdToSecond()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : ThirdToSecond */
    RtsNotify(1,"d722077c-e970-4e22-9c2a-dd9ce2c1b605",0,NULL);

    transition_time = local_time;
    RtsCurrent_Controller = RtsControllerController_States_ThirdToSecond;

    /* Start Timers */
    //RtsStartTimer(RtsAttThirdToSecond_Timer1,RtsThirdToSecond_Timer1_CallBack,(long) 1000 * downshiftDelay[2]);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.55)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsExit_ThirdToSecond()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Controller == RtsControllerController_States_ThirdToSecond)
    {
        /* Simulation support : Notification function call for exiting state : ThirdToSecond */
        RtsNotify(2,"d722077c-e970-4e22-9c2a-dd9ce2c1b605",0,NULL);

        /* Stop Timers */
        RtsStopTimer(RtsAttThirdToSecond_Timer1);
    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.56)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsSecondToFirst_Timer1()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsStopTimer(RtsAttSecondToFirst_Timer1);
    RtsLock(RtsBusy);
    if (RtsCurrent_Controller == RtsControllerController_States_SecondToFirst)
    {
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"2fd4d318-e071-4c81-aa1b-6467b6746d28",0,NULL);

        enterFirst();
    }
    else
    {
        /* Event not handled */
    }
    //RtsStartTimer(RtsAttSecondToFirst_Timer1,RtsSecondToFirst_Timer1_CallBack,(long) 1000 * downshiftDelay[1]);
    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.57)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsSecondToFirst_Timer1_CallBack(Controller *pInstance)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    pInstance->RtsSecondToFirst_Timer1();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.58)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsFourthToThird_Timer1()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsStopTimer(RtsAttFourthToThird_Timer1);
    RtsLock(RtsBusy);
    if (RtsCurrent_Controller == RtsControllerController_States_FourthToThird)
    {
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"4d44091f-6921-43bc-a8c7-397b4249da7d",0,NULL);

        enterThird();
    }
    else
    {
        /* Event not handled */
    }
    //RtsStartTimer(RtsAttFourthToThird_Timer1,RtsFourthToThird_Timer1_CallBack,(long) 1000 * downshiftDelay[3]);
    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.59)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsFourthToThird_Timer1_CallBack(Controller *pInstance)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    pInstance->RtsFourthToThird_Timer1();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            






//{{SCG_OP(0.65)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

#ifdef RTS_SIMULATION
int Controller::RtsInjectEvent(const char* Event, const int NumParams, const StringArray params, Controller *pInstance)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int Ret;
char *StopString;
    Ret = 1;
    if (strlen(Event) == 0)
    {
        pInstance->RtsRunToCompletion();
    }
    else
    {
        if ((strcmp(Event, "manualForwardShift") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->RtsmanualForwardShift();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "manualReverseShift") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->RtsmanualReverseShift();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "clock_tic") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->Rtsclock_tic();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "manualNeutralShift") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->RtsmanualNeutralShift();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "upShift") == 0) || (strcmp(Event, "Controller.upShift") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->upShift();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "downShift") == 0) || (strcmp(Event, "Controller.downShift") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->downShift();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "2fd4d318-e071-4c81-aa1b-6467b6746d28") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->RtsSecondToFirst_Timer1();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "enterFirst") == 0) || (strcmp(Event, "Controller.enterFirst") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->enterFirst();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "4d44091f-6921-43bc-a8c7-397b4249da7d") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->RtsFourthToThird_Timer1();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "enterThird") == 0) || (strcmp(Event, "Controller.enterThird") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->enterThird();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "b67a4b8b-2579-40d0-892e-94cbd63c8de5") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->RtsFirstToSecond_Timer1();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "enterSecond") == 0) || (strcmp(Event, "Controller.enterSecond") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->enterSecond();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "3b4c2968-7f22-4e91-aee2-6a31a8caf0c8") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->RtsSecondToThird_Timer1();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "b4945c4b-9f7a-466e-9be4-f09ab6af8401") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->RtsThirdToFourth_Timer1();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "enterFourth") == 0) || (strcmp(Event, "Controller.enterFourth") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->enterFourth();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "d3b9df92-d939-4b23-ae7d-6c5bfbf58cb2") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->RtsThirdToSecond_Timer1();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
    }
    return Ret;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}
#endif                     
//}}SCG_OP            

//{{SCG_OP(0.66)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

#ifdef RTS_SIMULATION
int Controller::RtsGetAttributeValue(const char* Name, char* Value, const int buflen, Controller *pInstance)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int Ret;
    Ret = 1;
    if (strcmp(Name, "shiftData") == 0)
    {
        /* shiftData is a complex type ( Class ) */
        Ret = 0;
    }
    else if (strcmp(Name, "throttleData") == 0)
    {
        sprintf(Value,"%.8g",pInstance->throttleData);
    }
    else if (strcmp(Name, "vehicleSpeedData") == 0)
    {
        sprintf(Value,"%.8g",pInstance->vehicleSpeedData);
    }
    else if (strcmp(Name, "upShiftThreshold") == 0)
    {
        sprintf(Value,"%.8g",pInstance->upShiftThreshold);
    }
    else if (strcmp(Name, "downShiftThreshold") == 0)
    {
        sprintf(Value,"%.8g",pInstance->downShiftThreshold);
    }
    else if (strcmp(Name, "currentGear") == 0)
    {
        _ltoa(pInstance->currentGear,Value,10);
    }
    else if (strcmp(Name, "Port_0") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "Port_1") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "Port_2") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "Port_3") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "Port_4") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "Port_5") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "Port_6") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "Port_7") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "Port_8") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "shiftLeverData") == 0)
    {
        _ltoa(pInstance->shiftLeverData,Value,10);
    }
    else if (strcmp(Name, "RtsCurrent_Controller") == 0)
    {
        switch(pInstance->RtsCurrent_Controller)
        {
            case RtsControllerController_States_First:
                strncpy(Value,"First",buflen);
                break;
            case RtsControllerController_States_Second:
                strncpy(Value,"Second",buflen);
                break;
            case RtsControllerController_States_Third:
                strncpy(Value,"Third",buflen);
                break;
            case RtsControllerController_States_Fourth:
                strncpy(Value,"Fourth",buflen);
                break;
            case RtsControllerController_States_Reverse:
                strncpy(Value,"Reverse",buflen);
                break;
            case RtsControllerController_States_Idle:
                strncpy(Value,"Idle",buflen);
                break;
            case RtsControllerController_States_NotIn_Controller:
                strncpy(Value,"NotIn_Controller",buflen);
                break;
            case RtsControllerController_States_SecondToFirst:
                strncpy(Value,"SecondToFirst",buflen);
                break;
            case RtsControllerController_States_FourthToThird:
                strncpy(Value,"FourthToThird",buflen);
                break;
            case RtsControllerController_States_FirstToSecond:
                strncpy(Value,"FirstToSecond",buflen);
                break;
            case RtsControllerController_States_SecondToThird:
                strncpy(Value,"SecondToThird",buflen);
                break;
            case RtsControllerController_States_ThirdToFourth:
                strncpy(Value,"ThirdToFourth",buflen);
                break;
            case RtsControllerController_States_ThirdToSecond:
                strncpy(Value,"ThirdToSecond",buflen);
                break;
            default:
                /* Invalid enumeration */
                Ret = 0;
                break;
        }
    }
    else if (strcmp(Name, "RtsCurrent_Reverse") == 0)
    {
        switch(pInstance->RtsCurrent_Reverse)
        {
            case RtsControllerReverse_States_Active:
                strncpy(Value,"Active",buflen);
                break;
            case RtsControllerReverse_States_NotIn_Reverse:
                strncpy(Value,"NotIn_Reverse",buflen);
                break;
            default:
                /* Invalid enumeration */
                Ret = 0;
                break;
        }
    }
    else if (strcmp(Name, "RtsCurrent_Idle") == 0)
    {
        switch(pInstance->RtsCurrent_Idle)
        {
            case RtsControllerIdle_States_Ready:
                strncpy(Value,"Ready",buflen);
                break;
            case RtsControllerIdle_States_NotIn_Idle:
                strncpy(Value,"NotIn_Idle",buflen);
                break;
            default:
                /* Invalid enumeration */
                Ret = 0;
                break;
        }
    }
    else if (strcmp(Name, "RtsBusy") == 0)
    {
        strncpy(Value, (RtsIsLocked(pInstance->RtsBusy)?"1":"0"), buflen );
    }
    else if (strcmp(Name, "pActuatorPorts[9]") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "upshiftDelay[4]") == 0)
    {
        sprintf(Value,"%.8g",pInstance->upshiftDelay[4]);
    }
    else if (strcmp(Name, "downshiftDelay[4]") == 0)
    {
        sprintf(Value,"%.8g",pInstance->downshiftDelay[4]);
    }
    else if (strcmp(Name,"$ClassID") == 0)
    {
        /* Return the Current Class ID */
        strncpy(Value,"eafa135c-6337-11d5-b148-00c04f680d9d", buflen);
    }
    else if (strcmp(Name,"$Model") == 0)
    {
        /* Return the Current Model ID */
        strncpy(Value,"eafa134c-6337-11d5-b148-00c04f680d9d", buflen);
    }
    else
    {
        /* Attribute Not Found or attribute has a complex type */
        Ret = 0;
    }
    return Ret;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}     
#endif                
//}}SCG_OP            

//{{SCG_OP(0.67)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

#ifdef RTS_SIMULATION
int Controller::RtsSetAttributeValue(const char* Name, const char* Value, Controller *pInstance)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int Ret;
char *StopString;
    Ret = 1;
    if (strcmp(Name, "shiftData") == 0)
    {
        Ret = 0;
    }
    else if (strcmp(Name, "throttleData") == 0)
    {
        pInstance->throttleData = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "vehicleSpeedData") == 0)
    {
        pInstance->vehicleSpeedData = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "upShiftThreshold") == 0)
    {
        pInstance->upShiftThreshold = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "downShiftThreshold") == 0)
    {
        pInstance->downShiftThreshold = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "currentGear") == 0)
    {
        pInstance->currentGear = atol(Value);
    }
    else if (strcmp(Name, "Port_0") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "Port_1") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "Port_2") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "Port_3") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "Port_4") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "Port_5") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "Port_6") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "Port_7") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "Port_8") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "shiftLeverData") == 0)
    {
        pInstance->shiftLeverData = atol(Value);
    }
    else if (strcmp(Name, "RtsCurrent_Controller") == 0)
    {
        if (strcmp(Value, "First") == 0 )
        {
            pInstance->RtsCurrent_Controller = RtsControllerController_States_First;
        }
        else if (strcmp(Value, "Second") == 0 )
        {
            pInstance->RtsCurrent_Controller = RtsControllerController_States_Second;
        }
        else if (strcmp(Value, "Third") == 0 )
        {
            pInstance->RtsCurrent_Controller = RtsControllerController_States_Third;
        }
        else if (strcmp(Value, "Fourth") == 0 )
        {
            pInstance->RtsCurrent_Controller = RtsControllerController_States_Fourth;
        }
        else if (strcmp(Value, "Reverse") == 0 )
        {
            pInstance->RtsCurrent_Controller = RtsControllerController_States_Reverse;
        }
        else if (strcmp(Value, "Idle") == 0 )
        {
            pInstance->RtsCurrent_Controller = RtsControllerController_States_Idle;
        }
        else if (strcmp(Value, "NotIn_Controller") == 0 )
        {
            pInstance->RtsCurrent_Controller = RtsControllerController_States_NotIn_Controller;
        }
        else if (strcmp(Value, "SecondToFirst") == 0 )
        {
            pInstance->RtsCurrent_Controller = RtsControllerController_States_SecondToFirst;
        }
        else if (strcmp(Value, "FourthToThird") == 0 )
        {
            pInstance->RtsCurrent_Controller = RtsControllerController_States_FourthToThird;
        }
        else if (strcmp(Value, "FirstToSecond") == 0 )
        {
            pInstance->RtsCurrent_Controller = RtsControllerController_States_FirstToSecond;
        }
        else if (strcmp(Value, "SecondToThird") == 0 )
        {
            pInstance->RtsCurrent_Controller = RtsControllerController_States_SecondToThird;
        }
        else if (strcmp(Value, "ThirdToFourth") == 0 )
        {
            pInstance->RtsCurrent_Controller = RtsControllerController_States_ThirdToFourth;
        }
        else if (strcmp(Value, "ThirdToSecond") == 0 )
        {
            pInstance->RtsCurrent_Controller = RtsControllerController_States_ThirdToSecond;
        }
        else
        {
            /* No matching enumeration */
            Ret = 0;
        }
    }
    else if (strcmp(Name, "RtsCurrent_Reverse") == 0)
    {
        if (strcmp(Value, "Active") == 0 )
        {
            pInstance->RtsCurrent_Reverse = RtsControllerReverse_States_Active;
        }
        else if (strcmp(Value, "NotIn_Reverse") == 0 )
        {
            pInstance->RtsCurrent_Reverse = RtsControllerReverse_States_NotIn_Reverse;
        }
        else
        {
            /* No matching enumeration */
            Ret = 0;
        }
    }
    else if (strcmp(Name, "RtsCurrent_Idle") == 0)
    {
        if (strcmp(Value, "Ready") == 0 )
        {
            pInstance->RtsCurrent_Idle = RtsControllerIdle_States_Ready;
        }
        else if (strcmp(Value, "NotIn_Idle") == 0 )
        {
            pInstance->RtsCurrent_Idle = RtsControllerIdle_States_NotIn_Idle;
        }
        else
        {
            /* No matching enumeration */
            Ret = 0;
        }
    }
    else if (strcmp(Name, "pActuatorPorts[9]") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "upshiftDelay[4]") == 0)
    {
        pInstance->upshiftDelay[4] = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "downshiftDelay[4]") == 0)
    {
        pInstance->downshiftDelay[4] = strtod(Value,&StopString);
    }
    else
    {
        /* Attribute Not Found or attribute has a complex type */
        Ret = 0;
    }
    return Ret;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}     
#endif                
//}}SCG_OP            

//{{SCG_OP(0.44)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsEnter_SecondToFirst()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : SecondToFirst */
    RtsNotify(1,"51318367-0ac6-4929-b69c-9e40052afd5b",0,NULL);

    transition_time = local_time;
    RtsCurrent_Controller = RtsControllerController_States_SecondToFirst;

    /* Start Timers */
    //RtsStartTimer(RtsAttSecondToFirst_Timer1,RtsSecondToFirst_Timer1_CallBack,(long) 1000 * downshiftDelay[1]);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.45)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsExit_SecondToFirst()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Controller == RtsControllerController_States_SecondToFirst)
    {
        /* Simulation support : Notification function call for exiting state : SecondToFirst */
        RtsNotify(2,"51318367-0ac6-4929-b69c-9e40052afd5b",0,NULL);

        /* Stop Timers */
        RtsStopTimer(RtsAttSecondToFirst_Timer1);
    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.46)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsEnter_FourthToThird()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : FourthToThird */
    RtsNotify(1,"1cde5aad-2809-49e9-b201-408c4400bd7f",0,NULL);

    transition_time = local_time;
    RtsCurrent_Controller = RtsControllerController_States_FourthToThird;

    /* Start Timers */
    //RtsStartTimer(RtsAttFourthToThird_Timer1,RtsFourthToThird_Timer1_CallBack,(long) 1000 * downshiftDelay[3]);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.47)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsExit_FourthToThird()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Controller == RtsControllerController_States_FourthToThird)
    {
        /* Simulation support : Notification function call for exiting state : FourthToThird */
        RtsNotify(2,"1cde5aad-2809-49e9-b201-408c4400bd7f",0,NULL);

        /* Stop Timers */
        RtsStopTimer(RtsAttFourthToThird_Timer1);
    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.48)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsEnter_FirstToSecond()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : FirstToSecond */
    RtsNotify(1,"8c1d7329-f073-478c-a920-ca6d366b539a",0,NULL);

    ATLTRACE("\ncontroller::enter_FirstToSecond");
    transition_time = local_time;
    RtsCurrent_Controller = RtsControllerController_States_FirstToSecond;

    /* Start Timers */
    //RtsStartTimer(RtsAttFirstToSecond_Timer1,RtsFirstToSecond_Timer1_CallBack,(long) 1000 * upshiftDelay[1]);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.49)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsExit_FirstToSecond()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Controller == RtsControllerController_States_FirstToSecond)
    {
        /* Simulation support : Notification function call for exiting state : FirstToSecond */
        RtsNotify(2,"8c1d7329-f073-478c-a920-ca6d366b539a",0,NULL);

        /* Stop Timers */
        RtsStopTimer(RtsAttFirstToSecond_Timer1);
    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.50)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsEnter_SecondToThird()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : SecondToThird */
    RtsNotify(1,"6f90f4d7-1b91-43b3-99d3-26b36ef82bb0",0,NULL);

    transition_time = local_time;
    RtsCurrent_Controller = RtsControllerController_States_SecondToThird;

    /* Start Timers */
    //RtsStartTimer(RtsAttSecondToThird_Timer1,RtsSecondToThird_Timer1_CallBack,(long) 1000 * upshiftDelay[2]);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.51)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsExit_SecondToThird()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Controller == RtsControllerController_States_SecondToThird)
    {
        /* Simulation support : Notification function call for exiting state : SecondToThird */
        RtsNotify(2,"6f90f4d7-1b91-43b3-99d3-26b36ef82bb0",0,NULL);

        /* Stop Timers */
        RtsStopTimer(RtsAttSecondToThird_Timer1);
    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.60)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsFirstToSecond_Timer1()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsStopTimer(RtsAttFirstToSecond_Timer1);
    RtsLock(RtsBusy);
    if (RtsCurrent_Controller == RtsControllerController_States_FirstToSecond)
    {
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"b67a4b8b-2579-40d0-892e-94cbd63c8de5",0,NULL);

        enterSecond();
    }
    else
    {
        /* Event not handled */
    }
    //RtsStartTimer(RtsAttFirstToSecond_Timer1,RtsFirstToSecond_Timer1_CallBack,(long) 1000 * upshiftDelay[1]);
    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.61)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsFirstToSecond_Timer1_CallBack(Controller *pInstance)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    pInstance->RtsFirstToSecond_Timer1();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.62)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsSecondToThird_Timer1()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsStopTimer(RtsAttSecondToThird_Timer1);
    RtsLock(RtsBusy);
    if (RtsCurrent_Controller == RtsControllerController_States_SecondToThird)
    {
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"3b4c2968-7f22-4e91-aee2-6a31a8caf0c8",0,NULL);

        enterThird();
    }
    else
    {
        /* Event not handled */
    }
    //RtsStartTimer(RtsAttSecondToThird_Timer1,RtsSecondToThird_Timer1_CallBack,(long) 1000 * upshiftDelay[2]);
    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.63)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsSecondToThird_Timer1_CallBack(Controller *pInstance)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    pInstance->RtsSecondToThird_Timer1();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.64)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsThirdToFourth_Timer1()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsStopTimer(RtsAttThirdToFourth_Timer1);
    RtsLock(RtsBusy);
    if (RtsCurrent_Controller == RtsControllerController_States_ThirdToFourth)
    {
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"b4945c4b-9f7a-466e-9be4-f09ab6af8401",0,NULL);

        enterFourth();
    }
    else
    {
        /* Event not handled */
    }
    //RtsStartTimer(RtsAttThirdToFourth_Timer1,RtsThirdToFourth_Timer1_CallBack,upshiftDelay[3]);
    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.65)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsThirdToFourth_Timer1_CallBack(Controller *pInstance)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    pInstance->RtsThirdToFourth_Timer1();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.66)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsThirdToSecond_Timer1()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsStopTimer(RtsAttThirdToSecond_Timer1);
    RtsLock(RtsBusy);
    if (RtsCurrent_Controller == RtsControllerController_States_ThirdToSecond)
    {
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"d3b9df92-d939-4b23-ae7d-6c5bfbf58cb2",0,NULL);

        enterSecond();
    }
    else
    {
        /* Event not handled */
    }
    //RtsStartTimer(RtsAttThirdToSecond_Timer1,RtsThirdToSecond_Timer1_CallBack,(long) 1000 * downshiftDelay[2]);
    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.67)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsThirdToSecond_Timer1_CallBack(Controller *pInstance)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    pInstance->RtsThirdToSecond_Timer1();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.68)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

bool Controller::Load(FILE *fs)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  READ_SCALAR( currentGear )     
  READ_SCALAR( throttleData )     
  READ_SCALAR( vehicleSpeedData )     
  READ_SCALAR( upShiftThreshold )     
  READ_SCALAR( downShiftThreshold )     
  READ_SCALAR( shiftLeverData )     
  READ_SCALAR( RtsCurrent_Controller )     
  READ_SCALAR( local_time )
  READ_SCALAR( transition_time )

  long count = 4;
  READ_VECTOR( upshiftDelay, double, count);
  READ_VECTOR( downshiftDelay, double, count);
 
  return true;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.69)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::Save(FILE *fs)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  WRITE_SCALAR( currentGear )     
  WRITE_SCALAR( throttleData )     
  WRITE_SCALAR( vehicleSpeedData )     
  WRITE_SCALAR( upShiftThreshold )     
  WRITE_SCALAR( downShiftThreshold )     
  WRITE_SCALAR( shiftLeverData )     
  WRITE_SCALAR( RtsCurrent_Controller )     
  WRITE_SCALAR( local_time )
  WRITE_SCALAR( transition_time )

  long count = 4;
  WRITE_VECTOR( upshiftDelay, double, count);
  WRITE_VECTOR( downshiftDelay, double, count);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.70)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

long Controller::AddRef()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  return ++m_cRef;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.71)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

long Controller::Release()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  m_cRef--;
  if (m_cRef <= 0)
    delete this;

  return m_cRef;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            
//}}SCG_OPS

//}}SCG_IMPLEMENTATION









