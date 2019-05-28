//{{SCG_IMPLEMENTATION(simpleGearbox.cpp) [0]

//{{SCG_INCLUDE      
#include "StdAfx.h"
#include "simpleGearbox.h"
#include "RigidConnector.h"                   
#include <math.h>

// Include for Template Class should go here.
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//}}SCG_INCLUDE
                      
//{{SCG_CLASS_ID
#ifdef RTS_SIMULATION
const static RtsClassInfo RtssimpleGearbox_ClassInfo("5220c31b-2cc7-4696-b47f-90b785c32af4", RTS_STM);
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

void simpleGearbox::ec_downShift()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsLock(RtsBusy);
    if (RtsCurrent_simpleGearbox == RtssimpleGearboxsimpleGearbox_States_Neutral)
    {
        RtsExit_Neutral();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"1cef6eb3-3ffc-4443-afd3-584b9d9b71fd",0,NULL);

        RtsEnter_Reverse();
    }
    else if (RtsCurrent_simpleGearbox == RtssimpleGearboxsimpleGearbox_States_First)
    {
        RtsExit_First();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"ebb65446-145c-4871-a76c-73614e9012dc",0,NULL);

        RtsEnter_Neutral();
    }
    else if (RtsCurrent_simpleGearbox == RtssimpleGearboxsimpleGearbox_States_Second)
    {
        RtsExit_Second();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"31833d00-2c5b-4aee-83de-f6cf05c28249",0,NULL);

        RtsEnter_First();
    }
    else if (RtsCurrent_simpleGearbox == RtssimpleGearboxsimpleGearbox_States_Third)
    {
        RtsExit_Third();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"d8abbd50-ae7d-4eb7-a728-d9cccf5617c2",0,NULL);

        RtsEnter_Second();
    }
    else if (RtsCurrent_simpleGearbox == RtssimpleGearboxsimpleGearbox_States_Fourth)
    {
        RtsExit_Fourth();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"fa0c8cd8-c1c2-4ecc-8a67-ba1145edab13",0,NULL);

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

//{{SCG_OP(0.1)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void simpleGearbox::ec_upShift()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsLock(RtsBusy);
    if (RtsCurrent_simpleGearbox == RtssimpleGearboxsimpleGearbox_States_Neutral)
    {
        RtsExit_Neutral();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"54dc272a-9be5-4855-9a5c-2aa5d141abfe",0,NULL);

        RtsEnter_First();
    }
    else if (RtsCurrent_simpleGearbox == RtssimpleGearboxsimpleGearbox_States_First)
    {
        RtsExit_First();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"f3ba38e7-8e24-43be-96c5-b9da80d53831",0,NULL);

        RtsEnter_Second();
    }
    else if (RtsCurrent_simpleGearbox == RtssimpleGearboxsimpleGearbox_States_Second)
    {
        RtsExit_Second();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"190fca73-ed12-410e-86af-7c8c733db6db",0,NULL);

        RtsEnter_Third();
    }
    else if (RtsCurrent_simpleGearbox == RtssimpleGearboxsimpleGearbox_States_Third)
    {
        RtsExit_Third();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"c1589d92-2fbd-4009-b898-3f589ba002c1",0,NULL);

        RtsEnter_Fourth();
    }
    else if (RtsCurrent_simpleGearbox == RtssimpleGearboxsimpleGearbox_States_Reverse)
    {
        RtsExit_Reverse();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"4aab7cf4-8f71-465c-a3bb-930d4f662c03",0,NULL);

        RtsEnter_Neutral();
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

void simpleGearbox::init()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
gear = lastGear = 0;
oldRatio = gearRatio[lastGear+1];
newRatio = gearRatio[gear+1];

gearRatioCount = 6;
gearRatio[0] = -1.8;  // reverse
gearRatio[1] = 0.0;   // neutral
gearRatio[2] = 2.4;   // first
gearRatio[3] = 1.83;  // second
gearRatio[4] = 1.0;   // third
gearRatio[5] = 0.667; // fourth


tolerance=0.001;
shiftTime=0.0;
der(shiftTime) = 1.0;
shiftPeriod=0.5;
rate=log(2.0/tolerance - 1.0)/(shiftPeriod*shiftPeriod);
ratio = 0.0;
der(ratio) = 0.0;

p_Speed = 0.0;
der(p_Speed) = 0.0;

n_Speed = 0.0;
der(n_Speed) = 0.0;

p = new CRigidConnector();
p->AddRef();
n = new CRigidConnector();
n->AddRef();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.3)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void simpleGearbox::clean()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
p->Release();
n->Release();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.4)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT simpleGearbox::r_shiftTime(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res = DER(shiftTime)-1.0;
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.5)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT simpleGearbox::r_shiftProfile(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
double factor = (2.0/(1.0+exp(rate*shiftTime*shiftTime)));
*res = ratio - ( oldRatio*factor + newRatio*(1.0-factor) );

return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.6)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT simpleGearbox::s_shiftTime(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res = shiftTime;
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.7)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void simpleGearbox::handle_shiftEvent(const double t, long *val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
if(*val == 0)
  PostStateEvent(t, L"ec_downShift");
else
  PostStateEvent(t, L"ec_upShift");

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.8)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void simpleGearbox::RtsEnter_Neutral()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Neutral */
    RtsNotify(1,"75a2ffa4-5939-4c13-8640-1e8496faf7b4",0,NULL);

    RtsCurrent_simpleGearbox = RtssimpleGearboxsimpleGearbox_States_Neutral;

    /* Entry Actions */
    lastGear = gear; gear = 0;
    oldRatio = gearRatio[lastGear+1];
    newRatio = gearRatio[gear+1];

    OnTransition();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.9)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void simpleGearbox::RtsExit_Neutral()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_simpleGearbox == RtssimpleGearboxsimpleGearbox_States_Neutral)
    {
        /* Simulation support : Notification function call for exiting state : Neutral */
        RtsNotify(2,"75a2ffa4-5939-4c13-8640-1e8496faf7b4",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.10)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void simpleGearbox::RtsEnter_First()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : First */
    RtsNotify(1,"2d089edd-8bce-49c2-b657-0a122f676ebe",0,NULL);

    RtsCurrent_simpleGearbox = RtssimpleGearboxsimpleGearbox_States_First;

    /* Entry Actions */
    lastGear = gear; gear = 1;
    oldRatio = gearRatio[lastGear+1];
    newRatio = gearRatio[gear+1];

    OnTransition();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.11)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void simpleGearbox::RtsExit_First()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_simpleGearbox == RtssimpleGearboxsimpleGearbox_States_First)
    {
        /* Simulation support : Notification function call for exiting state : First */
        RtsNotify(2,"2d089edd-8bce-49c2-b657-0a122f676ebe",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.12)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void simpleGearbox::RtsEnter_Second()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Second */
    RtsNotify(1,"810689f8-ce8b-4298-ab9c-b289bfd9c17f",0,NULL);

    RtsCurrent_simpleGearbox = RtssimpleGearboxsimpleGearbox_States_Second;

    /* Entry Actions */
    lastGear = gear; gear = 2;
    oldRatio = gearRatio[lastGear+1];
    newRatio = gearRatio[gear+1];

    OnTransition();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.13)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void simpleGearbox::RtsExit_Second()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_simpleGearbox == RtssimpleGearboxsimpleGearbox_States_Second)
    {
        /* Simulation support : Notification function call for exiting state : Second */
        RtsNotify(2,"810689f8-ce8b-4298-ab9c-b289bfd9c17f",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.14)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void simpleGearbox::RtsEnter_Third()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Third */
    RtsNotify(1,"e2f16ef4-8b18-43f5-8087-887c356da3f0",0,NULL);

    RtsCurrent_simpleGearbox = RtssimpleGearboxsimpleGearbox_States_Third;

    /* Entry Actions */
    lastGear = gear; gear = 3;
    oldRatio = gearRatio[lastGear+1];
    newRatio = gearRatio[gear+1];

    OnTransition();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.15)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void simpleGearbox::RtsExit_Third()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_simpleGearbox == RtssimpleGearboxsimpleGearbox_States_Third)
    {
        /* Simulation support : Notification function call for exiting state : Third */
        RtsNotify(2,"e2f16ef4-8b18-43f5-8087-887c356da3f0",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.16)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void simpleGearbox::RtsEnter_Fourth()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Fourth */
    RtsNotify(1,"411811d9-7c38-4531-9160-6266ea3cbae7",0,NULL);

    RtsCurrent_simpleGearbox = RtssimpleGearboxsimpleGearbox_States_Fourth;

    /* Entry Actions */
    lastGear = gear; gear = 4;
    oldRatio = gearRatio[lastGear+1];
    newRatio = gearRatio[gear+1];

    OnTransition();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.17)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void simpleGearbox::RtsExit_Fourth()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_simpleGearbox == RtssimpleGearboxsimpleGearbox_States_Fourth)
    {
        /* Simulation support : Notification function call for exiting state : Fourth */
        RtsNotify(2,"411811d9-7c38-4531-9160-6266ea3cbae7",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.18)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void simpleGearbox::RtsEnter_Reverse()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Reverse */
    RtsNotify(1,"ba3d1e3a-f071-470f-b018-f8065c778fa0",0,NULL);

    RtsCurrent_simpleGearbox = RtssimpleGearboxsimpleGearbox_States_Reverse;

    /* Entry Actions */
    lastGear = gear; gear = -1;
    oldRatio = gearRatio[lastGear+1];
    newRatio = gearRatio[gear+1];

    OnTransition();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.19)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void simpleGearbox::RtsExit_Reverse()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_simpleGearbox == RtssimpleGearboxsimpleGearbox_States_Reverse)
    {
        /* Simulation support : Notification function call for exiting state : Reverse */
        RtsNotify(2,"ba3d1e3a-f071-470f-b018-f8065c778fa0",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.20)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

 simpleGearbox::simpleGearbox()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

    init();

    RtsRegisterStateMachine(this,RtsInjectEvent,RtsGetAttributeValue,RtsSetAttributeValue);
    RtsCreateSemaphore(RtsBusy);
    RtsLock(RtsBusy);

    /* Initialising State Vectors to NotIn */
    RtsCurrent_simpleGearbox=RtssimpleGearboxsimpleGearbox_States_NotIn_simpleGearbox;

    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.21)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

 simpleGearbox::~simpleGearbox()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    clean();
    RtsUnregister(this);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.22)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void simpleGearbox::RtsRunToCompletion()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int EndOfLoop;
    for(EndOfLoop=0;EndOfLoop==0;)
    {
        EndOfLoop = 1;
        /* All completion transitions included here */
        if (RtsCurrent_simpleGearbox == RtssimpleGearboxsimpleGearbox_States_NotIn_simpleGearbox)
        {
            /* Simulation support : Notification function calls for transition */
            RtsNotify(3,"184fc60a-fa2c-4380-ba3f-4e384bb3198a",0,NULL);

            RtsEnter_Neutral();

            EndOfLoop = 0;
        }
    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.23)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

#ifdef RTS_SIMULATION
int simpleGearbox::RtsInjectEvent(const char* Event, const int NumParams, const StringArray params, simpleGearbox *pInstance)  
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
        if ((strcmp(Event, "ec_downShift") == 0) || (strcmp(Event, "simpleGearbox.ec_downShift") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->ec_downShift();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "ec_upShift") == 0) || (strcmp(Event, "simpleGearbox.ec_upShift") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->ec_upShift();
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

//{{SCG_OP(0.24)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

#ifdef RTS_SIMULATION
int simpleGearbox::RtsGetAttributeValue(const char* Name, char* Value, const int buflen, simpleGearbox *pInstance)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int Ret;
    Ret = 1;
    if (strcmp(Name, "gear") == 0)
    {
        _ltoa(pInstance->gear,Value,10);
    }
    else if (strcmp(Name, "rate") == 0)
    {
        sprintf(Value,"%.8g",pInstance->rate);
    }
    else if (strcmp(Name, "tolerance") == 0)
    {
        sprintf(Value,"%.8g",pInstance->tolerance);
    }
    else if (strcmp(Name, "gearRatio[6]") == 0)
    {
        sprintf(Value,"%.8g",pInstance->gearRatio[6]);
    }
    else if (strcmp(Name, "shiftPeriod") == 0)
    {
        sprintf(Value,"%.8g",pInstance->shiftPeriod);
    }
    else if (strcmp(Name, "shiftTime") == 0)
    {
        sprintf(Value,"%.8g",pInstance->shiftTime);
    }
    else if (strcmp(Name, "lastGear") == 0)
    {
        _ltoa(pInstance->lastGear,Value,10);
    }
    else if (strcmp(Name, "ratio") == 0)
    {
        sprintf(Value,"%.8g",pInstance->ratio);
    }
    else if (strcmp(Name, "p") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "n") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "RtsCurrent_simpleGearbox") == 0)
    {
        switch(pInstance->RtsCurrent_simpleGearbox)
        {
            case RtssimpleGearboxsimpleGearbox_States_Neutral:
                strncpy(Value,"Neutral",buflen);
                break;
            case RtssimpleGearboxsimpleGearbox_States_First:
                strncpy(Value,"First",buflen);
                break;
            case RtssimpleGearboxsimpleGearbox_States_Second:
                strncpy(Value,"Second",buflen);
                break;
            case RtssimpleGearboxsimpleGearbox_States_Third:
                strncpy(Value,"Third",buflen);
                break;
            case RtssimpleGearboxsimpleGearbox_States_Fourth:
                strncpy(Value,"Fourth",buflen);
                break;
            case RtssimpleGearboxsimpleGearbox_States_Reverse:
                strncpy(Value,"Reverse",buflen);
                break;
            case RtssimpleGearboxsimpleGearbox_States_NotIn_simpleGearbox:
                strncpy(Value,"NotIn_simpleGearbox",buflen);
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
        strncpy(Value,"5220c31b-2cc7-4696-b47f-90b785c32af4", buflen);
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

//{{SCG_OP(0.25)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

#ifdef RTS_SIMULATION
int simpleGearbox::RtsSetAttributeValue(const char* Name, const char* Value, simpleGearbox *pInstance)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int Ret;
char *StopString;
    Ret = 1;
    if (strcmp(Name, "gear") == 0)
    {
        pInstance->gear = atol(Value);
    }
    else if (strcmp(Name, "rate") == 0)
    {
        pInstance->rate = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "tolerance") == 0)
    {
        pInstance->tolerance = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "gearRatio[6]") == 0)
    {
        pInstance->gearRatio[6] = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "shiftPeriod") == 0)
    {
        pInstance->shiftPeriod = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "shiftTime") == 0)
    {
        pInstance->shiftTime = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "lastGear") == 0)
    {
        pInstance->lastGear = atol(Value);
    }
    else if (strcmp(Name, "ratio") == 0)
    {
        pInstance->ratio = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "p") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "n") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "RtsCurrent_simpleGearbox") == 0)
    {
        if (strcmp(Value, "Neutral") == 0 )
        {
            pInstance->RtsCurrent_simpleGearbox = RtssimpleGearboxsimpleGearbox_States_Neutral;
        }
        else if (strcmp(Value, "First") == 0 )
        {
            pInstance->RtsCurrent_simpleGearbox = RtssimpleGearboxsimpleGearbox_States_First;
        }
        else if (strcmp(Value, "Second") == 0 )
        {
            pInstance->RtsCurrent_simpleGearbox = RtssimpleGearboxsimpleGearbox_States_Second;
        }
        else if (strcmp(Value, "Third") == 0 )
        {
            pInstance->RtsCurrent_simpleGearbox = RtssimpleGearboxsimpleGearbox_States_Third;
        }
        else if (strcmp(Value, "Fourth") == 0 )
        {
            pInstance->RtsCurrent_simpleGearbox = RtssimpleGearboxsimpleGearbox_States_Fourth;
        }
        else if (strcmp(Value, "Reverse") == 0 )
        {
            pInstance->RtsCurrent_simpleGearbox = RtssimpleGearboxsimpleGearbox_States_Reverse;
        }
        else if (strcmp(Value, "NotIn_simpleGearbox") == 0 )
        {
            pInstance->RtsCurrent_simpleGearbox = RtssimpleGearboxsimpleGearbox_States_NotIn_simpleGearbox;
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

//{{SCG_OP(0.26)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT simpleGearbox::r_forceRatio(double *res)  
{
  *res = p->torque * ratio + n->torque;
  return S_OK;
}                     

HRESULT simpleGearbox::r_p_Speed(double* res)
{
  *res = der(p_Speed) - p->acceleration;
  return S_OK;
}

HRESULT simpleGearbox::r_n_Speed(double* res)
{
  *res = der(n_Speed) - n->acceleration;
  return S_OK;
}

HRESULT simpleGearbox::r_speedRatio(double* res)
{
  *res = p_Speed - ratio * n_Speed;
  return S_OK;
}

//{{SCG_OP(0.28)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void simpleGearbox::handle_tolerance(const double t, const double* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

PostRealParameter(t, 0, *val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.29)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void simpleGearbox::handle_shiftPeriod(const double t, const double* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

PostRealParameter(t, 1, *val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.30)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT simpleGearbox::InitEsos()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

  ADD_LOCAL_ESO(p)
  ADD_LOCAL_ESO(n)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.31)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT simpleGearbox::InitLocalEqns()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

  ADD_LOCAL_EQN(simpleGearbox, r_shiftTime)
  ADD_LOCAL_EQN(simpleGearbox, r_shiftProfile)
  ADD_LOCAL_EQN(simpleGearbox, s_shiftTime)
  ADD_LOCAL_EQN(simpleGearbox, r_forceRatio)  
  ADD_LOCAL_EQN(simpleGearbox, r_p_Speed)
  ADD_LOCAL_EQN(simpleGearbox, r_n_Speed)
  ADD_LOCAL_EQN(simpleGearbox, r_speedRatio)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.32)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT simpleGearbox::InitLocalADEqns()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

  ADD_LOCAL_AD_EQN(simpleGearbox, ad_r_shiftTime)
  ADD_LOCAL_AD_EQN(simpleGearbox, ad_r_shiftProfile)
  ADD_LOCAL_AD_EQN(simpleGearbox, ad_s_shiftTime)
  ADD_LOCAL_AD_EQN(simpleGearbox, ad_r_forceRatio)  
  ADD_LOCAL_AD_EQN(simpleGearbox, ad_r_p_Speed)
  ADD_LOCAL_AD_EQN(simpleGearbox, ad_r_n_Speed)
  ADD_LOCAL_AD_EQN(simpleGearbox, ad_r_speedRatio)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.33)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT simpleGearbox::InitEqnForm(OnEqnForm* *form, OnEqnDiffForm* *diff_form)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


const long idx_eqn_r_shiftTime = 0;
const long idx_eqn_r_shiftProfile = 1;
const long idx_eqn_s_shiftTime = 2;
const long idx_eqn_r_forceRatio = 3;
const long idx_eqn_r_p_Speed = 4;
const long idx_eqn_r_n_Speed = 5;
const long idx_eqn_r_speedRatio = 6;

  DESTROY_VECTOR(*form)
  *form = new OnEqnForm[m_nLocalEqns];
  (*form)[idx_eqn_r_shiftTime] = continuous;
  (*form)[idx_eqn_r_shiftProfile] = continuous;
  (*form)[idx_eqn_s_shiftTime] = reset;
  (*form)[idx_eqn_r_forceRatio] = continuous;
  (*form)[idx_eqn_r_p_Speed] = continuous;
  (*form)[idx_eqn_r_n_Speed] = continuous;
  (*form)[idx_eqn_r_speedRatio] = continuous;

  DESTROY_VECTOR(*diff_form)
  *diff_form = new OnEqnDiffForm[m_nLocalEqns];
  (*diff_form)[idx_eqn_r_shiftTime] = automatic;
  (*diff_form)[idx_eqn_r_shiftProfile] = automatic;
  (*diff_form)[idx_eqn_s_shiftTime] = automatic;
  (*diff_form)[idx_eqn_r_forceRatio] = automatic;
  (*diff_form)[idx_eqn_r_p_Speed] = automatic;
  (*diff_form)[idx_eqn_r_n_Speed] = automatic;
  (*diff_form)[idx_eqn_r_speedRatio] = automatic;

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.34)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT simpleGearbox::InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


  ADD_LOCAL_SVAR(shiftTime)
  ADD_LOCAL_SVAR(ratio)
  ADD_LOCAL_SVAR(p_Speed)
  ADD_LOCAL_SVAR(n_Speed)

for (long i = 0; i < m_nEsos; i++)
  AddLocalVar(m_Esos[i], NULL, NULL, varC, true);

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.35)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT simpleGearbox::InitLocalRPars(const _TCHAR* prefix, ppdouble *pars, ppchar *Names, long *nPars, long *dPars)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


  ADD_LOCAL_SRPAR(tolerance)
  ADD_LOCAL_SRPAR(shiftPeriod)
  ADD_LOCAL_VRPAR(gearRatio, gearRatioCount)
  ADD_LOCAL_SRPAR(oldRatio)
  ADD_LOCAL_SRPAR(newRatio)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.36)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT simpleGearbox::InitTransitions()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

HRESULT hr;
HRESULT hrRet = S_OK;


// equation constants
const long idx_eqn_r_shiftTime = 0;
const long idx_eqn_r_shiftProfile = 1;
const long idx_eqn_s_shiftTime = 2;
const long idx_eqn_r_forceRatio = 3;
const long idx_eqn_r_p_Speed = 4;
const long idx_eqn_r_n_Speed = 5;
const long idx_eqn_r_speedRatio = 6;

// state constants
const long idx_state_First = 0;
const long idx_state_Fourth = 1;
const long idx_state_Neutral = 2;
const long idx_state_Reverse = 3;
const long idx_state_Second = 4;
const long idx_state_Third = 5;

const long idx_eqns_ec_downShiftFirstNeutral[] = { 
  idx_eqn_s_shiftTime,
 };
const long idx_eqns_ec_upShiftFirstSecond[] = { 
  idx_eqn_s_shiftTime,
 };
const long idx_eqns_ec_downShiftFourthThird[] = { 
  idx_eqn_s_shiftTime,
 };
const long idx_eqns_ec_downShiftNeutralReverse[] = { 
  idx_eqn_s_shiftTime,
 };
const long idx_eqns_ec_upShiftNeutralFirst[] = { 
  idx_eqn_s_shiftTime,
 };
const long idx_eqns_ec_upShiftReverseNeutral[] = { 
  idx_eqn_s_shiftTime,
 };
const long idx_eqns_ec_downShiftSecondFirst[] = { 
  idx_eqn_s_shiftTime,
 };
const long idx_eqns_ec_upShiftSecondThird[] = { 
  idx_eqn_s_shiftTime,
 };
const long idx_eqns_ec_downShiftThirdSecond[] = { 
  idx_eqn_s_shiftTime,
 };
const long idx_eqns_ec_upShiftThirdFourth[] = { 
  idx_eqn_s_shiftTime,
 };

// Transition_Name, Source_State, Event_Name, Transition_Eqns, Eqn_Count
hr = AddTransition(L"ec_downShiftFirstNeutral", idx_state_First, L"ec_downShift", idx_eqns_ec_downShiftFirstNeutral, 1);
if (FAILED(hr)) hrRet = hr;
hr = AddTransition(L"ec_upShiftFirstSecond", idx_state_First, L"ec_upShift", idx_eqns_ec_upShiftFirstSecond, 1);
if (FAILED(hr)) hrRet = hr;
hr = AddTransition(L"ec_downShiftFourthThird", idx_state_Fourth, L"ec_downShift", idx_eqns_ec_downShiftFourthThird, 1);
if (FAILED(hr)) hrRet = hr;
hr = AddTransition(L"ec_downShiftNeutralReverse", idx_state_Neutral, L"ec_downShift", idx_eqns_ec_downShiftNeutralReverse, 1);
if (FAILED(hr)) hrRet = hr;
hr = AddTransition(L"ec_upShiftNeutralFirst", idx_state_Neutral, L"ec_upShift", idx_eqns_ec_upShiftNeutralFirst, 1);
if (FAILED(hr)) hrRet = hr;
hr = AddTransition(L"ec_upShiftReverseNeutral", idx_state_Reverse, L"ec_upShift", idx_eqns_ec_upShiftReverseNeutral, 1);
if (FAILED(hr)) hrRet = hr;
hr = AddTransition(L"ec_downShiftSecondFirst", idx_state_Second, L"ec_downShift", idx_eqns_ec_downShiftSecondFirst, 1);
if (FAILED(hr)) hrRet = hr;
hr = AddTransition(L"ec_upShiftSecondThird", idx_state_Second, L"ec_upShift", idx_eqns_ec_upShiftSecondThird, 1);
if (FAILED(hr)) hrRet = hr;
hr = AddTransition(L"ec_downShiftThirdSecond", idx_state_Third, L"ec_downShift", idx_eqns_ec_downShiftThirdSecond, 1);
if (FAILED(hr)) hrRet = hr;
hr = AddTransition(L"ec_upShiftThirdFourth", idx_state_Third, L"ec_upShift", idx_eqns_ec_upShiftThirdFourth, 1);
if (FAILED(hr)) hrRet = hr;

return hrRet;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.37)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT simpleGearbox::InitStates()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

HRESULT hr;
HRESULT hrRet = S_OK;

// equation constants
const long idx_eqn_r_shiftTime = 0;
const long idx_eqn_r_shiftProfile = 1;
const long idx_eqn_s_shiftTime = 2;
const long idx_eqn_r_forceRatio = 3;
const long idx_eqn_r_p_Speed = 4;
const long idx_eqn_r_n_Speed = 5;
const long idx_eqn_r_speedRatio = 6;

// state constants
const long idx_state_First = 0;
const long idx_state_Fourth = 1;
const long idx_state_Neutral = 2;
const long idx_state_Reverse = 3;
const long idx_state_Second = 4;
const long idx_state_Third = 5;

const long idx_eqns_First[] = { 
  idx_eqn_r_shiftTime,
  idx_eqn_r_shiftProfile,
  idx_eqn_r_forceRatio,
  idx_eqn_r_p_Speed,
  idx_eqn_r_n_Speed,
  idx_eqn_r_speedRatio,
 };
const long idx_eqns_Fourth[] = { 
  idx_eqn_r_shiftTime,
  idx_eqn_r_shiftProfile,
  idx_eqn_r_forceRatio,
  idx_eqn_r_p_Speed,
  idx_eqn_r_n_Speed,
  idx_eqn_r_speedRatio,
 };
const long idx_eqns_Neutral[] = { 
  idx_eqn_r_shiftTime,
  idx_eqn_r_shiftProfile,
  idx_eqn_r_forceRatio,
  idx_eqn_r_p_Speed,
  idx_eqn_r_n_Speed,
  idx_eqn_r_speedRatio,
 };
const long idx_eqns_Reverse[] = { 
  idx_eqn_r_shiftTime,
  idx_eqn_r_shiftProfile,
  idx_eqn_r_forceRatio,
  idx_eqn_r_p_Speed,
  idx_eqn_r_n_Speed,
  idx_eqn_r_speedRatio,
 };
const long idx_eqns_Second[] = { 
  idx_eqn_r_shiftTime,
  idx_eqn_r_shiftProfile,
  idx_eqn_r_forceRatio,
  idx_eqn_r_p_Speed,
  idx_eqn_r_n_Speed,
  idx_eqn_r_speedRatio,
 };
const long idx_eqns_Third[] = { 
  idx_eqn_r_shiftTime,
  idx_eqn_r_shiftProfile,
  idx_eqn_r_forceRatio,
  idx_eqn_r_p_Speed,
  idx_eqn_r_n_Speed,
  idx_eqn_r_speedRatio,
 };

hr = AddState(L"First", 0, idx_eqns_First, 6);
if (FAILED(hr)) hrRet = hr;
hr = AddState(L"Fourth", 0, idx_eqns_Fourth, 6);
if (FAILED(hr)) hrRet = hr;
hr = AddState(L"Neutral", 1, idx_eqns_Neutral, 6);
if (FAILED(hr)) hrRet = hr;
hr = AddState(L"Reverse", 0, idx_eqns_Reverse, 6);
if (FAILED(hr)) hrRet = hr;
hr = AddState(L"Second", 0, idx_eqns_Second, 6);
if (FAILED(hr)) hrRet = hr;
hr = AddState(L"Third", 0, idx_eqns_Third, 6);
if (FAILED(hr)) hrRet = hr;


return hrRet;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.38)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT simpleGearbox::OnTransition()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

HRESULT hr = S_OK;

const long idx_state_First = 0;
const long idx_state_Fourth = 1;
const long idx_state_Neutral = 2;
const long idx_state_Reverse = 3;
const long idx_state_Second = 4;
const long idx_state_Third = 5;

switch (RtsCurrent_simpleGearbox)
{
  case RtssimpleGearboxsimpleGearbox_States_First:
    PostTransition(idx_state_First);
    break;
  case RtssimpleGearboxsimpleGearbox_States_Fourth:
    PostTransition(idx_state_Fourth);
    break;
  case RtssimpleGearboxsimpleGearbox_States_Neutral:
    PostTransition(idx_state_Neutral);
    break;
  case RtssimpleGearboxsimpleGearbox_States_Reverse:
    PostTransition(idx_state_Reverse);
    break;
  case RtssimpleGearboxsimpleGearbox_States_Second:
    PostTransition(idx_state_Second);
    break;
  case RtssimpleGearboxsimpleGearbox_States_Third:
    PostTransition(idx_state_Third);
    break;
}

return hr;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.39)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT simpleGearbox::ad_r_shiftTime(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res = DER(ad_shiftTime)-1.0;
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.40)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT simpleGearbox::ad_r_shiftProfile(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

Fdouble ad_factor = (2.0/(1.0+exp(rate*ad_shiftTime*ad_shiftTime)));
*res = ad_ratio - ( oldRatio*ad_factor + newRatio*(1.0-ad_factor) );

return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.41)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT simpleGearbox::ad_s_shiftTime(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res = ad_shiftTime;
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            


//}}SCG_IMPLEMENTATION


HRESULT simpleGearbox::ad_r_forceRatio(Fdouble *res)  
{
  *res = p->ad_torque * ad_ratio + n->ad_torque;
  return S_OK;
}                     

HRESULT simpleGearbox::ad_r_p_Speed(Fdouble* res)
{
  *res = der(ad_p_Speed) - p->ad_acceleration;
  return S_OK;
}

HRESULT simpleGearbox::ad_r_n_Speed(Fdouble* res)
{
  *res = der(ad_n_Speed) - n->ad_acceleration;
  return S_OK;
}

HRESULT simpleGearbox::ad_r_speedRatio(Fdouble* res)
{
  *res = ad_p_Speed - ad_ratio * ad_n_Speed;
  return S_OK;
}



void simpleGearbox::Save(FILE* fs)
{
  WRITE_SCALAR( lastGear )  
  WRITE_SCALAR( gear )     
  WRITE_SCALAR( RtsCurrent_simpleGearbox )     
}


bool simpleGearbox::Load(FILE* fs)
{
  READ_SCALAR( lastGear )  
  READ_SCALAR( gear )     
  READ_SCALAR( RtsCurrent_simpleGearbox )     

  return true;
}

HRESULT simpleGearbox::TriggerEvent(const double EventTime, const BSTR bstrEventId)
{

CComBSTR EventId = bstrEventId;
HRESULT hr = S_OK;

if (EventId == L"ec_downShift")
  ec_downShift();
else if (EventId == L"ec_upShift")
  ec_upShift();

m_time = EventTime;
ATLTRACE("\ngearbox gear: %d, time: %f", gear, EventTime);

return S_OK;

}


