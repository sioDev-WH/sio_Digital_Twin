//{{SCG_IMPLEMENTATION(Controller.cpp) [0]

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

//}}SCG_INCLUDE
                      
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

shiftData. getUpShiftThreshold(throttleData, currentGear, &upShiftThreshold);

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
currentGear=0;
throttleData=0.0;
vehicleSpeedData=0.0;
shiftLeverData=0; // for N; +/-1 for D and R
shiftData.init();

//shiftData.clutchSchedule->update(0, 1);  

for (long i = 0; i < 9; i++)
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
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsLock(RtsBusy);
    if (RtsCurrent_Controller == RtsControllerController_States_Second)
    {
        RtsExit_Second();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"eafa13cc-6337-11d5-b148-00c04f680d9d",0,NULL);

        RtsDefault_First();
    }
    else if (RtsCurrent_Controller == RtsControllerController_States_Third)
    {
        RtsExit_Third();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"eafa13d1-6337-11d5-b148-00c04f680d9d",0,NULL);

        RtsDefault_Second();
    }
    else if (RtsCurrent_Controller == RtsControllerController_States_Fourth)
    {
        RtsExit_Fourth();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"eafa13db-6337-11d5-b148-00c04f680d9d",0,NULL);

        RtsDefault_Third();
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
    if (RtsCurrent_Controller == RtsControllerController_States_First)
    {
        RtsExit_First();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"eafa139f-6337-11d5-b148-00c04f680d9d",0,NULL);

        RtsDefault_Second();
    }
    else if (RtsCurrent_Controller == RtsControllerController_States_Second)
    {
        RtsExit_Second();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"eafa13a4-6337-11d5-b148-00c04f680d9d",0,NULL);

        RtsDefault_Third();
    }
    else if (RtsCurrent_Controller == RtsControllerController_States_Third)
    {
        RtsExit_Third();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"eafa13b8-6337-11d5-b148-00c04f680d9d",0,NULL);

        RtsDefault_Fourth();
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
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int i;
long engageMsg = 0;
for(i=0;i<shiftData.clutchSchedule->nClutches;i++)
if(shiftData.clutchSchedule->disengageList[i])
{
  pActuatorPorts[i]->Fire_Event(local_time, &engageMsg );
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
for (long i = 0; i < 9; i++)
  pActuatorPorts[i]->Release();

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
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
long i;
long engageMsg=1;
for(i=0;i<shiftData.clutchSchedule->nClutches;i++)
if(shiftData.clutchSchedule->engageList[i])
{
  pActuatorPorts[i]->Fire_Event(local_time, &engageMsg);
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

void Controller::handle_SpeedData(const double * time, const double *vals, const long cVals)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
vehicleSpeedData = *vals;

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
  local_time = *time;
  Rtsclock_tic();

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

    /* Entry Actions */
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

        switch(RtsCurrent_First)
        {
            case RtsControllerFirst_States_Inertia:
                RtsExit_Inertia();
                break;
            case RtsControllerFirst_States_Torque:
                RtsExit_Torque();
                break;
            default:
                break;
        }
        RtsCurrent_First = RtsControllerFirst_States_NotIn_First;

        /* Exit Actions */
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

    /* Entry Actions */
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

        switch(RtsCurrent_Second)
        {
            case RtsControllerSecond_States_Inertia_1:
                RtsExit_Inertia_1();
                break;
            case RtsControllerSecond_States_Torque_1:
                RtsExit_Torque_1();
                break;
            default:
                break;
        }
        RtsCurrent_Second = RtsControllerSecond_States_NotIn_Second;

        /* Exit Actions */
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

    /* Entry Actions */
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

        switch(RtsCurrent_Third)
        {
            case RtsControllerThird_States_Inertia_2:
                RtsExit_Inertia_2();
                break;
            case RtsControllerThird_States_Torque_2:
                RtsExit_Torque_2();
                break;
            default:
                break;
        }
        RtsCurrent_Third = RtsControllerThird_States_NotIn_Third;

        /* Exit Actions */
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

    /* Entry Actions */
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

        switch(RtsCurrent_Fourth)
        {
            case RtsControllerFourth_States_Inertia_3:
                RtsExit_Inertia_3();
                break;
            case RtsControllerFourth_States_Torque_3:
                RtsExit_Torque_3();
                break;
            default:
                break;
        }
        RtsCurrent_Fourth = RtsControllerFourth_States_NotIn_Fourth;

        /* Exit Actions */
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

    /* Entry Actions */
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

//{{SCG_OP(0.24)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsEnter_Inertia()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Inertia */
    RtsNotify(1,"4fc3756f-6418-11d5-b149-00c04f680d9d",0,NULL);

    RtsCurrent_First = RtsControllerFirst_States_Inertia;


//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.25)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsExit_Inertia()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_First == RtsControllerFirst_States_Inertia)
    {
        /* Simulation support : Notification function call for exiting state : Inertia */
        RtsNotify(2,"4fc3756f-6418-11d5-b149-00c04f680d9d",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.26)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsDefault_First()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function calls for entry and exit of initial state */
    RtsNotify(1,"4fc37571-6418-11d5-b149-00c04f680d9d",0,NULL);
    RtsNotify(2,"4fc37571-6418-11d5-b149-00c04f680d9d",0,NULL);

    RtsEnter_First();
    /* Simulation support : Notification function calls for default transition */
    RtsNotify(3,"4fc37573-6418-11d5-b149-00c04f680d9d",0,NULL);

    RtsEnter_Torque();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.27)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsEnter_Torque()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Torque */
    RtsNotify(1,"4fc3756d-6418-11d5-b149-00c04f680d9d",0,NULL);

    RtsCurrent_First = RtsControllerFirst_States_Torque;

    /* Start Timers */
    RtsStartTimer(RtsAttTorque_Timer1,RtsTorque_Timer1_CallBack,500);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.28)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsExit_Torque()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_First == RtsControllerFirst_States_Torque)
    {
        /* Simulation support : Notification function call for exiting state : Torque */
        RtsNotify(2,"4fc3756d-6418-11d5-b149-00c04f680d9d",0,NULL);

        /* Stop Timers */
        RtsStopTimer(RtsAttTorque_Timer1);
    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.29)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsEnter_Inertia_1()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Inertia */
    RtsNotify(1,"4fc3757a-6418-11d5-b149-00c04f680d9d",0,NULL);

    RtsCurrent_Second = RtsControllerSecond_States_Inertia_1;


//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.30)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsExit_Inertia_1()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Second == RtsControllerSecond_States_Inertia_1)
    {
        /* Simulation support : Notification function call for exiting state : Inertia */
        RtsNotify(2,"4fc3757a-6418-11d5-b149-00c04f680d9d",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.31)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsDefault_Second()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function calls for entry and exit of initial state */
    RtsNotify(1,"4fc3758d-6418-11d5-b149-00c04f680d9d",0,NULL);
    RtsNotify(2,"4fc3758d-6418-11d5-b149-00c04f680d9d",0,NULL);

    RtsEnter_Second();
    /* Simulation support : Notification function calls for default transition */
    RtsNotify(3,"4fc3758f-6418-11d5-b149-00c04f680d9d",0,NULL);

    RtsEnter_Torque_1();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.32)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsEnter_Torque_1()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Torque */
    RtsNotify(1,"4fc37578-6418-11d5-b149-00c04f680d9d",0,NULL);

    RtsCurrent_Second = RtsControllerSecond_States_Torque_1;

    /* Start Timers */
    RtsStartTimer(RtsAttTorque_1_Timer1,RtsTorque_1_Timer1_CallBack,500);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.33)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsExit_Torque_1()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Second == RtsControllerSecond_States_Torque_1)
    {
        /* Simulation support : Notification function call for exiting state : Torque */
        RtsNotify(2,"4fc37578-6418-11d5-b149-00c04f680d9d",0,NULL);

        /* Stop Timers */
        RtsStopTimer(RtsAttTorque_1_Timer1);
    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.34)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsEnter_Inertia_2()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Inertia */
    RtsNotify(1,"4fc3757e-6418-11d5-b149-00c04f680d9d",0,NULL);

    RtsCurrent_Third = RtsControllerThird_States_Inertia_2;


//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.35)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsExit_Inertia_2()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Third == RtsControllerThird_States_Inertia_2)
    {
        /* Simulation support : Notification function call for exiting state : Inertia */
        RtsNotify(2,"4fc3757e-6418-11d5-b149-00c04f680d9d",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.36)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsDefault_Third()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function calls for entry and exit of initial state */
    RtsNotify(1,"4fc37594-6418-11d5-b149-00c04f680d9d",0,NULL);
    RtsNotify(2,"4fc37594-6418-11d5-b149-00c04f680d9d",0,NULL);

    RtsEnter_Third();
    /* Simulation support : Notification function calls for default transition */
    RtsNotify(3,"4fc37596-6418-11d5-b149-00c04f680d9d",0,NULL);

    RtsEnter_Torque_2();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.37)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsEnter_Torque_2()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Torque */
    RtsNotify(1,"4fc3757c-6418-11d5-b149-00c04f680d9d",0,NULL);

    RtsCurrent_Third = RtsControllerThird_States_Torque_2;

    /* Start Timers */
    RtsStartTimer(RtsAttTorque_2_Timer1,RtsTorque_2_Timer1_CallBack,500);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.38)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsExit_Torque_2()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Third == RtsControllerThird_States_Torque_2)
    {
        /* Simulation support : Notification function call for exiting state : Torque */
        RtsNotify(2,"4fc3757c-6418-11d5-b149-00c04f680d9d",0,NULL);

        /* Stop Timers */
        RtsStopTimer(RtsAttTorque_2_Timer1);
    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.39)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsEnter_Inertia_3()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Inertia */
    RtsNotify(1,"4fc37582-6418-11d5-b149-00c04f680d9d",0,NULL);

    RtsCurrent_Fourth = RtsControllerFourth_States_Inertia_3;


//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.40)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsExit_Inertia_3()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Fourth == RtsControllerFourth_States_Inertia_3)
    {
        /* Simulation support : Notification function call for exiting state : Inertia */
        RtsNotify(2,"4fc37582-6418-11d5-b149-00c04f680d9d",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.41)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsDefault_Fourth()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function calls for entry and exit of initial state */
    RtsNotify(1,"4fc3759b-6418-11d5-b149-00c04f680d9d",0,NULL);
    RtsNotify(2,"4fc3759b-6418-11d5-b149-00c04f680d9d",0,NULL);

    RtsEnter_Fourth();
    /* Simulation support : Notification function calls for default transition */
    RtsNotify(3,"4fc3759d-6418-11d5-b149-00c04f680d9d",0,NULL);

    RtsEnter_Torque_3();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.42)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsEnter_Torque_3()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Torque */
    RtsNotify(1,"4fc37580-6418-11d5-b149-00c04f680d9d",0,NULL);

    RtsCurrent_Fourth = RtsControllerFourth_States_Torque_3;

    /* Start Timers */
    RtsStartTimer(RtsAttTorque_3_Timer1,RtsTorque_3_Timer1_CallBack,500);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.43)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsExit_Torque_3()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Fourth == RtsControllerFourth_States_Torque_3)
    {
        /* Simulation support : Notification function call for exiting state : Torque */
        RtsNotify(2,"4fc37580-6418-11d5-b149-00c04f680d9d",0,NULL);

        /* Stop Timers */
        RtsStopTimer(RtsAttTorque_3_Timer1);
    }

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

//{{SCG_OP(0.52)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsTorque_Timer1()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsStopTimer(RtsAttTorque_Timer1);
    RtsLock(RtsBusy);
    if (RtsCurrent_First == RtsControllerFirst_States_Torque)
    {
        RtsExit_Torque();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"4fc375a2-6418-11d5-b149-00c04f680d9d",0,NULL);

        RtsEnter_Inertia();
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

//{{SCG_OP(0.53)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsTorque_Timer1_CallBack(Controller *pInstance)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    pInstance->RtsTorque_Timer1();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.54)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsTorque_1_Timer1()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsStopTimer(RtsAttTorque_1_Timer1);
    RtsLock(RtsBusy);
    if (RtsCurrent_Second == RtsControllerSecond_States_Torque_1)
    {
        RtsExit_Torque_1();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"4fc375a7-6418-11d5-b149-00c04f680d9d",0,NULL);

        RtsEnter_Inertia_1();
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

//{{SCG_OP(0.55)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsTorque_1_Timer1_CallBack(Controller *pInstance)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    pInstance->RtsTorque_1_Timer1();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.56)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsTorque_2_Timer1()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsStopTimer(RtsAttTorque_2_Timer1);
    RtsLock(RtsBusy);
    if (RtsCurrent_Third == RtsControllerThird_States_Torque_2)
    {
        RtsExit_Torque_2();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"4fc375ac-6418-11d5-b149-00c04f680d9d",0,NULL);

        RtsEnter_Inertia_2();
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

//{{SCG_OP(0.57)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsTorque_2_Timer1_CallBack(Controller *pInstance)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    pInstance->RtsTorque_2_Timer1();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.58)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsTorque_3_Timer1()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsStopTimer(RtsAttTorque_3_Timer1);
    RtsLock(RtsBusy);
    if (RtsCurrent_Fourth == RtsControllerFourth_States_Torque_3)
    {
        RtsExit_Torque_3();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"4fc375b1-6418-11d5-b149-00c04f680d9d",0,NULL);

        RtsEnter_Inertia_3();
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

//{{SCG_OP(0.59)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Controller::RtsTorque_3_Timer1_CallBack(Controller *pInstance)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    pInstance->RtsTorque_3_Timer1();

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
        RtsDefault_First();
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
    RtsRegisterStateMachine(this,RtsInjectEvent,RtsGetAttributeValue,RtsSetAttributeValue);
    RtsCreateSemaphore(RtsBusy);
    RtsLock(RtsBusy);

    /* Initialising State Vectors to NotIn */
    RtsCurrent_Controller=RtsControllerController_States_NotIn_Controller;
    RtsCurrent_First=RtsControllerFirst_States_NotIn_First;
    RtsCurrent_Second=RtsControllerSecond_States_NotIn_Second;
    RtsCurrent_Third=RtsControllerThird_States_NotIn_Third;
    RtsCurrent_Fourth=RtsControllerFourth_States_NotIn_Fourth;
    RtsCurrent_Reverse=RtsControllerReverse_States_NotIn_Reverse;
    RtsCurrent_Idle=RtsControllerIdle_States_NotIn_Idle;

    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

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
        if ((strcmp(Event, "clock_tic") == 0))
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
        else if ((strcmp(Event, "4fc375a4-6418-11d5-b149-00c04f680d9d") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->RtsTorque_Timer1();
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
        else if ((strcmp(Event, "4fc375a9-6418-11d5-b149-00c04f680d9d") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->RtsTorque_1_Timer1();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "4fc375ae-6418-11d5-b149-00c04f680d9d") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->RtsTorque_2_Timer1();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "4fc375b3-6418-11d5-b149-00c04f680d9d") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->RtsTorque_3_Timer1();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "manualForwardShift") == 0))
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
            default:
                /* Invalid enumeration */
                Ret = 0;
                break;
        }
    }
    else if (strcmp(Name, "RtsCurrent_First") == 0)
    {
        switch(pInstance->RtsCurrent_First)
        {
            case RtsControllerFirst_States_Inertia:
                strncpy(Value,"Inertia",buflen);
                break;
            case RtsControllerFirst_States_Torque:
                strncpy(Value,"Torque",buflen);
                break;
            case RtsControllerFirst_States_NotIn_First:
                strncpy(Value,"NotIn_First",buflen);
                break;
            default:
                /* Invalid enumeration */
                Ret = 0;
                break;
        }
    }
    else if (strcmp(Name, "RtsCurrent_Second") == 0)
    {
        switch(pInstance->RtsCurrent_Second)
        {
            case RtsControllerSecond_States_Inertia_1:
                strncpy(Value,"Inertia_1",buflen);
                break;
            case RtsControllerSecond_States_Torque_1:
                strncpy(Value,"Torque_1",buflen);
                break;
            case RtsControllerSecond_States_NotIn_Second:
                strncpy(Value,"NotIn_Second",buflen);
                break;
            default:
                /* Invalid enumeration */
                Ret = 0;
                break;
        }
    }
    else if (strcmp(Name, "RtsCurrent_Third") == 0)
    {
        switch(pInstance->RtsCurrent_Third)
        {
            case RtsControllerThird_States_Inertia_2:
                strncpy(Value,"Inertia_2",buflen);
                break;
            case RtsControllerThird_States_Torque_2:
                strncpy(Value,"Torque_2",buflen);
                break;
            case RtsControllerThird_States_NotIn_Third:
                strncpy(Value,"NotIn_Third",buflen);
                break;
            default:
                /* Invalid enumeration */
                Ret = 0;
                break;
        }
    }
    else if (strcmp(Name, "RtsCurrent_Fourth") == 0)
    {
        switch(pInstance->RtsCurrent_Fourth)
        {
            case RtsControllerFourth_States_Inertia_3:
                strncpy(Value,"Inertia_3",buflen);
                break;
            case RtsControllerFourth_States_Torque_3:
                strncpy(Value,"Torque_3",buflen);
                break;
            case RtsControllerFourth_States_NotIn_Fourth:
                strncpy(Value,"NotIn_Fourth",buflen);
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
        else
        {
            /* No matching enumeration */
            Ret = 0;
        }
    }
    else if (strcmp(Name, "RtsCurrent_First") == 0)
    {
        if (strcmp(Value, "Inertia") == 0 )
        {
            pInstance->RtsCurrent_First = RtsControllerFirst_States_Inertia;
        }
        else if (strcmp(Value, "Torque") == 0 )
        {
            pInstance->RtsCurrent_First = RtsControllerFirst_States_Torque;
        }
        else if (strcmp(Value, "NotIn_First") == 0 )
        {
            pInstance->RtsCurrent_First = RtsControllerFirst_States_NotIn_First;
        }
        else
        {
            /* No matching enumeration */
            Ret = 0;
        }
    }
    else if (strcmp(Name, "RtsCurrent_Second") == 0)
    {
        if (strcmp(Value, "Inertia_1") == 0 )
        {
            pInstance->RtsCurrent_Second = RtsControllerSecond_States_Inertia_1;
        }
        else if (strcmp(Value, "Torque_1") == 0 )
        {
            pInstance->RtsCurrent_Second = RtsControllerSecond_States_Torque_1;
        }
        else if (strcmp(Value, "NotIn_Second") == 0 )
        {
            pInstance->RtsCurrent_Second = RtsControllerSecond_States_NotIn_Second;
        }
        else
        {
            /* No matching enumeration */
            Ret = 0;
        }
    }
    else if (strcmp(Name, "RtsCurrent_Third") == 0)
    {
        if (strcmp(Value, "Inertia_2") == 0 )
        {
            pInstance->RtsCurrent_Third = RtsControllerThird_States_Inertia_2;
        }
        else if (strcmp(Value, "Torque_2") == 0 )
        {
            pInstance->RtsCurrent_Third = RtsControllerThird_States_Torque_2;
        }
        else if (strcmp(Value, "NotIn_Third") == 0 )
        {
            pInstance->RtsCurrent_Third = RtsControllerThird_States_NotIn_Third;
        }
        else
        {
            /* No matching enumeration */
            Ret = 0;
        }
    }
    else if (strcmp(Name, "RtsCurrent_Fourth") == 0)
    {
        if (strcmp(Value, "Inertia_3") == 0 )
        {
            pInstance->RtsCurrent_Fourth = RtsControllerFourth_States_Inertia_3;
        }
        else if (strcmp(Value, "Torque_3") == 0 )
        {
            pInstance->RtsCurrent_Fourth = RtsControllerFourth_States_Torque_3;
        }
        else if (strcmp(Value, "NotIn_Fourth") == 0 )
        {
            pInstance->RtsCurrent_Fourth = RtsControllerFourth_States_NotIn_Fourth;
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
//}}SCG_OPS

//}}SCG_IMPLEMENTATION



long Controller::AddRef()
{
  return ++m_cRef;
}

long Controller::Release()
{
  m_cRef--;
  if (m_cRef <= 0)
    delete this;

  return m_cRef;
}



void Controller::Save(FILE* fs)
{
  WRITE_SCALAR( currentGear )     
  WRITE_SCALAR( throttleData )     
  WRITE_SCALAR( vehicleSpeedData )     
  WRITE_SCALAR( upShiftThreshold )     
  WRITE_SCALAR( downShiftThreshold )     
  WRITE_SCALAR( shiftLeverData )     
  WRITE_SCALAR( RtsCurrent_Controller )     
  WRITE_SCALAR( RtsCurrent_First )     
  WRITE_SCALAR( RtsAttTorque_Timer1 )     
  WRITE_SCALAR( RtsCurrent_Second )     
  WRITE_SCALAR( RtsAttTorque_1_Timer1 )     
  WRITE_SCALAR( RtsCurrent_Third )     
  WRITE_SCALAR( RtsAttTorque_2_Timer1 )     
  WRITE_SCALAR( RtsCurrent_Fourth )     
  WRITE_SCALAR( RtsAttTorque_3_Timer1 )     
  WRITE_SCALAR( RtsCurrent_Reverse )     
}


bool Controller::Load(FILE* fs)
{
  READ_SCALAR( currentGear )     
  READ_SCALAR( throttleData )     
  READ_SCALAR( vehicleSpeedData )     
  READ_SCALAR( upShiftThreshold )     
  READ_SCALAR( downShiftThreshold )     
  READ_SCALAR( shiftLeverData )     
  READ_SCALAR( RtsCurrent_Controller )     
  READ_SCALAR( RtsCurrent_First )     
  READ_SCALAR( RtsAttTorque_Timer1 )     
  READ_SCALAR( RtsCurrent_Second )     
  READ_SCALAR( RtsAttTorque_1_Timer1 )     
  READ_SCALAR( RtsCurrent_Third )     
  READ_SCALAR( RtsAttTorque_2_Timer1 )     
  READ_SCALAR( RtsCurrent_Fourth )     
  READ_SCALAR( RtsAttTorque_3_Timer1 )     
  READ_SCALAR( RtsCurrent_Reverse )     
  return true;
}
