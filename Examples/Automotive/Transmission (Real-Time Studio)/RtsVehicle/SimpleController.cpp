//{{SCG_IMPLEMENTATION(SimpleController.cpp) [0]

//{{SCG_INCLUDE 
#include "StdAfx.h"
#include "SimpleController.h"
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
const static RtsClassInfo RtsSimpleController_ClassInfo("cc4d8e9c-1789-47c4-8ef6-9ff563abf316", RTS_STM);
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

void SimpleController::handle_tick(const double* t)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
sim_time = *t;
ec_Tick();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.1)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

long SimpleController::AddRef()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
return ++m_cRef;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.2)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

long SimpleController::Release()  
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

//{{SCG_OP(0.3)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::ec_Tick()  
//}}SCG_OP_INFO
{
  static bEngagedOB = false;
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsLock(RtsBusy);
    if ((RtsCurrent_SimpleController == RtsSimpleControllerSimpleController_States_FourthGear) && (sim_time >= 16.0 && !bUpshift))
    {
        RtsExit_FourthGear();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"4063f634-09ca-4dd9-8bb0-396f06a52455",0,NULL);

        Fire_FourthToThird();
        RtsEnter_ThirdGear();
    }
    else if ((RtsCurrent_SimpleController == RtsSimpleControllerSimpleController_States_EngineRunning) && (sim_time >= 0.5 && bUpshift))
    {
        RtsExit_EngineRunning();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"ccef1b65-9237-4dc2-a87e-8c2bbef5d616",0,NULL);

        Fire_NeutralToFirst();
        RtsEnter_FirstGear();
    }
    else if ((RtsCurrent_SimpleController == RtsSimpleControllerSimpleController_States_FirstGear) && (sim_time >= 28.0 && !bUpshift))
    {
        RtsExit_FirstGear();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"fdbc94c7-8102-45b2-b3e3-c83cca8cb4b4",0,NULL);

        Fire_FirstToNeutral();
        RtsEnter_EngineRunning();
    }
    else if ((RtsCurrent_SimpleController == RtsSimpleControllerSimpleController_States_FirstGear) && (sim_time >= 4.0 && bUpshift))
    {
        RtsExit_FirstGear();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"8f0319b5-59be-4e3a-8179-975257ed5311",0,NULL);

        Fire_FirstToSecond();
        RtsEnter_SecondGear();
    }
    else if ((RtsCurrent_SimpleController == RtsSimpleControllerSimpleController_States_SecondGear) && (sim_time >= 24.0 && !bUpshift))
    {
        RtsExit_SecondGear();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"31181811-85c0-4a5f-9499-04ae951e072a",0,NULL);

        Fire_SecondToFirst();
        RtsEnter_FirstGear();
    }
    else if ((RtsCurrent_SimpleController == RtsSimpleControllerSimpleController_States_SecondGear) && (sim_time >= 8.0 && bUpshift))
    {
        RtsExit_SecondGear();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"2fb362ba-eb57-499e-93f8-177baa201ab5",0,NULL);

        Fire_SecondToThird();
        RtsEnter_ThirdGear();
    }
    else if ((RtsCurrent_SimpleController == RtsSimpleControllerSimpleController_States_ThirdGear) && (sim_time >= 12.0 && bUpshift))
    {
        RtsExit_ThirdGear();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"dc710a09-5ff1-4268-9f47-0a747be44d15",0,NULL);

        // release FC
        long val = 0;
        //ATLTRACE("\n<external command> disengage FC");
        ClutchPort5->gen(&val);

        //Fire_ThirdToFourth();
        RtsEnter_FourthGear();
    }
    else if ((RtsCurrent_SimpleController == RtsSimpleControllerSimpleController_States_FourthGear) && (sim_time >= 12.25 && !bEngagedOB))
    {
        RtsExit_ThirdGear();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"dc710a09-5ff1-4268-9f47-0a747be44d15",0,NULL);

        // engage OB
        long val = 1;
        //ATLTRACE("\n<external command> engage OB");
        ClutchPort10->gen(&val);
        bEngagedOB = true;

        //Fire_ThirdToFourth();
        //RtsEnter_FourthGear();
    }
    else if ((RtsCurrent_SimpleController == RtsSimpleControllerSimpleController_States_ThirdGear) && (sim_time >= 20.0 && !bUpshift))
    {
        RtsExit_ThirdGear();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"4549777e-a36f-4e3e-a8ea-ff813b522282",0,NULL);

        Fire_ThirdToSecond();
        RtsEnter_SecondGear();
    }
    else if (RtsCurrent_SimpleController == RtsSimpleControllerSimpleController_States_init)
    {
        RtsExit_init();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"17584507-f90d-4919-b774-223937559fac",0,NULL);


        Fire_StartEngine();
        RtsEnter_EngineRunning();
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

//{{SCG_OP(0.4)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::init()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
m_cRef = 0;
bUpshift = true;
EnginePort = new COnBroadcaster<long>();
ClutchPort5 = new COnBroadcaster<long>(); 
ClutchPort6 = new COnBroadcaster<long>(); 
ClutchPort7 = new COnBroadcaster<long>(); 
ClutchPort8 = new COnBroadcaster<long>(); 
ClutchPort9 = new COnBroadcaster<long>(); 
ClutchPort10 = new COnBroadcaster<long>(); 
ClutchPort11 = new COnBroadcaster<long>(); 
ClutchPort12 = new COnBroadcaster<long>(); 

EnginePort->AddRef();
ClutchPort5->AddRef(); 
ClutchPort6->AddRef(); 
ClutchPort7->AddRef(); 
ClutchPort8->AddRef(); 
ClutchPort9->AddRef(); 
ClutchPort10->AddRef(); 
ClutchPort11->AddRef(); 
ClutchPort12->AddRef(); 

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.5)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::Fire_StartEngine()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
long val = 1;
//ATLTRACE("\nstart engine");
EnginePort->gen(&val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.6)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::Fire_NeutralToFirst()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
long val = 1;

// engage FC, POC
//ATLTRACE("\n<external command> engage FC");
ClutchPort5->gen(&val);
//ATLTRACE("\n<external command> engage POC");
ClutchPort6->gen(&val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.7)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::clean()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
EnginePort->Release();
ClutchPort5->Release();
ClutchPort6->Release();
ClutchPort7->Release();
ClutchPort8->Release();
ClutchPort9->Release();
ClutchPort10->Release();
ClutchPort11->Release();
ClutchPort12->Release();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            


//{{SCG_OP(0.10)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::RtsEnter_EngineRunning()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : EngineRunning */
    RtsNotify(1,"89a508dd-de3d-47e6-b536-bdc128c0f558",0,NULL);

    RtsCurrent_SimpleController = RtsSimpleControllerSimpleController_States_EngineRunning;


//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.11)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::RtsExit_EngineRunning()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_SimpleController == RtsSimpleControllerSimpleController_States_EngineRunning)
    {
        /* Simulation support : Notification function call for exiting state : EngineRunning */
        RtsNotify(2,"89a508dd-de3d-47e6-b536-bdc128c0f558",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.12)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::RtsEnter_init()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : init */
    RtsNotify(1,"1ce1f184-b377-4c48-a1e8-6f437c057866",0,NULL);

    RtsCurrent_SimpleController = RtsSimpleControllerSimpleController_States_init;

    /* Entry Actions */
    init();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.13)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::RtsExit_init()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_SimpleController == RtsSimpleControllerSimpleController_States_init)
    {
        /* Simulation support : Notification function call for exiting state : init */
        RtsNotify(2,"1ce1f184-b377-4c48-a1e8-6f437c057866",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.14)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

 SimpleController::SimpleController()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsRegisterStateMachine(this,RtsInjectEvent,RtsGetAttributeValue,RtsSetAttributeValue);
    RtsCreateSemaphore(RtsBusy);
    RtsLock(RtsBusy);

    /* Initialising State Vectors to NotIn */
    RtsCurrent_SimpleController=RtsSimpleControllerSimpleController_States_NotIn_SimpleController;

    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.15)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

 SimpleController::~SimpleController()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsUnregister(this);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.16)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::RtsRunToCompletion()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int EndOfLoop;
    for(EndOfLoop=0;EndOfLoop==0;)
    {
        EndOfLoop = 1;
        /* All completion transitions included here */
        if (RtsCurrent_SimpleController == RtsSimpleControllerSimpleController_States_NotIn_SimpleController)
        {
            /* Simulation support : Notification function calls for transition */
            RtsNotify(3,"d38caa33-e7c0-43e7-9528-3415fd28c0fe",0,NULL);

            RtsEnter_init();

            EndOfLoop = 0;
        }
    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.17)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

#ifdef RTS_SIMULATION
int SimpleController::RtsInjectEvent(const char* Event, const int NumParams, const StringArray params, SimpleController *pInstance)  
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
        if ((strcmp(Event, "ec_Tick") == 0) || (strcmp(Event, "SimpleController.ec_Tick") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->ec_Tick();
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

//{{SCG_OP(0.18)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

#ifdef RTS_SIMULATION
int SimpleController::RtsGetAttributeValue(const char* Name, char* Value, const int buflen, SimpleController *pInstance)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int Ret;
    Ret = 1;
    if (strcmp(Name, "m_cRef") == 0)
    {
        _ltoa(pInstance->m_cRef,Value,10);
    }
    else if (strcmp(Name, "EnginePort") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "sim_time") == 0)
    {
        sprintf(Value,"%.8g",pInstance->sim_time);
    }
    else if (strcmp(Name, "RtsCurrent_SimpleController") == 0)
    {
        switch(pInstance->RtsCurrent_SimpleController)
        {
            case RtsSimpleControllerSimpleController_States_EngineRunning:
                strncpy(Value,"EngineRunning",buflen);
                break;
            case RtsSimpleControllerSimpleController_States_init:
                strncpy(Value,"init",buflen);
                break;
            case RtsSimpleControllerSimpleController_States_NotIn_SimpleController:
                strncpy(Value,"NotIn_SimpleController",buflen);
                break;
            case RtsSimpleControllerSimpleController_States_SecondGear:
                strncpy(Value,"SecondGear",buflen);
                break;
            case RtsSimpleControllerSimpleController_States_FirstGear:
                strncpy(Value,"FirstGear",buflen);
                break;
            case RtsSimpleControllerSimpleController_States_FourthGear:
                strncpy(Value,"FourthGear",buflen);
                break;
            case RtsSimpleControllerSimpleController_States_ThirdGear:
                strncpy(Value,"ThirdGear",buflen);
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
    else if (strcmp(Name, "ClutchPort5") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "ClutchPort6") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "ClutchPort7") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "ClutchPort8") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "ClutchPort9") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "ClutchPort10") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "ClutchPort11") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "ClutchPort12") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "bUpshift") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name,"$ClassID") == 0)
    {
        /* Return the Current Class ID */
        strncpy(Value,"cc4d8e9c-1789-47c4-8ef6-9ff563abf316", buflen);
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

//{{SCG_OP(0.19)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

#ifdef RTS_SIMULATION
int SimpleController::RtsSetAttributeValue(const char* Name, const char* Value, SimpleController *pInstance)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int Ret;
char *StopString;
    Ret = 1;
    if (strcmp(Name, "m_cRef") == 0)
    {
        pInstance->m_cRef = atol(Value);
    }
    else if (strcmp(Name, "EnginePort") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "sim_time") == 0)
    {
        pInstance->sim_time = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "RtsCurrent_SimpleController") == 0)
    {
        if (strcmp(Value, "EngineRunning") == 0 )
        {
            pInstance->RtsCurrent_SimpleController = RtsSimpleControllerSimpleController_States_EngineRunning;
        }
        else if (strcmp(Value, "init") == 0 )
        {
            pInstance->RtsCurrent_SimpleController = RtsSimpleControllerSimpleController_States_init;
        }
        else if (strcmp(Value, "NotIn_SimpleController") == 0 )
        {
            pInstance->RtsCurrent_SimpleController = RtsSimpleControllerSimpleController_States_NotIn_SimpleController;
        }
        else if (strcmp(Value, "SecondGear") == 0 )
        {
            pInstance->RtsCurrent_SimpleController = RtsSimpleControllerSimpleController_States_SecondGear;
        }
        else if (strcmp(Value, "FirstGear") == 0 )
        {
            pInstance->RtsCurrent_SimpleController = RtsSimpleControllerSimpleController_States_FirstGear;
        }
        else if (strcmp(Value, "FourthGear") == 0 )
        {
            pInstance->RtsCurrent_SimpleController = RtsSimpleControllerSimpleController_States_FourthGear;
        }
        else if (strcmp(Value, "ThirdGear") == 0 )
        {
            pInstance->RtsCurrent_SimpleController = RtsSimpleControllerSimpleController_States_ThirdGear;
        }
        else
        {
            /* No matching enumeration */
            Ret = 0;
        }
    }
    else if (strcmp(Name, "ClutchPort5") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "ClutchPort6") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "ClutchPort7") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "ClutchPort8") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "ClutchPort9") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "ClutchPort10") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "ClutchPort11") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "ClutchPort12") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "bUpshift") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
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

//{{SCG_OP(0.20)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::SetName(const _TCHAR* caption)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.21)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::Fire_FirstToSecond()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
long val;
// release POC, engage IOC
val = 0;
//ATLTRACE("\n<external command> disengage POC");
ClutchPort6->gen(&val);
val = 1;
//ATLTRACE("\n<external command> engage IOC");
ClutchPort7->gen(&val);


//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.22)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::RtsEnter_SecondGear()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : SecondGear */
    RtsNotify(1,"452ff7a9-a17a-484c-9fb6-ebb2d4f4ce22",0,NULL);

    RtsCurrent_SimpleController = RtsSimpleControllerSimpleController_States_SecondGear;

    /* Entry Actions */
    

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.23)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::RtsExit_SecondGear()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_SimpleController == RtsSimpleControllerSimpleController_States_SecondGear)
    {
        /* Simulation support : Notification function call for exiting state : SecondGear */
        RtsNotify(2,"452ff7a9-a17a-484c-9fb6-ebb2d4f4ce22",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.24)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::RtsEnter_FirstGear()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : FirstGear */
    RtsNotify(1,"cdb34f70-cd62-49b0-b4dc-3c7a502c7f83",0,NULL);

    RtsCurrent_SimpleController = RtsSimpleControllerSimpleController_States_FirstGear;


//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.25)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::RtsExit_FirstGear()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_SimpleController == RtsSimpleControllerSimpleController_States_FirstGear)
    {
        /* Simulation support : Notification function call for exiting state : FirstGear */
        RtsNotify(2,"cdb34f70-cd62-49b0-b4dc-3c7a502c7f83",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.26)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::Fire_SecondToThird()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
long val;
// release IOC, engage TCC, DC
val = 0;
//ATLTRACE("\n<external command> disengage IOC");
ClutchPort7->gen(&val);
val = 1;
//ATLTRACE("\n<external command> engage TCC");
ClutchPort8->gen(&val);
//ATLTRACE("\n<external command> engage DC");
ClutchPort9->gen(&val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.27)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::Fire_ThirdToFourth()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
long val;

// release FC, engage OB
val = 0;
//ATLTRACE("\n<external command> disengage FC");
ClutchPort5->gen(&val);
val = 1;
//ATLTRACE("\n<external command> engage OB");
ClutchPort10->gen(&val);


//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.28)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::RtsEnter_FourthGear()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : FourthGear */
    RtsNotify(1,"df523a50-4685-469f-a9d9-30292f4e5fc3",0,NULL);

    RtsCurrent_SimpleController = RtsSimpleControllerSimpleController_States_FourthGear;

    /* Entry Actions */
    bUpshift = false;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.29)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::RtsExit_FourthGear()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_SimpleController == RtsSimpleControllerSimpleController_States_FourthGear)
    {
        /* Simulation support : Notification function call for exiting state : FourthGear */
        RtsNotify(2,"df523a50-4685-469f-a9d9-30292f4e5fc3",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.30)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::RtsEnter_ThirdGear()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : ThirdGear */
    RtsNotify(1,"f2c2277b-6000-44f9-9683-fe9a5429d22e",0,NULL);

    RtsCurrent_SimpleController = RtsSimpleControllerSimpleController_States_ThirdGear;

    /* Entry Actions */
    

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.31)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::RtsExit_ThirdGear()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_SimpleController == RtsSimpleControllerSimpleController_States_ThirdGear)
    {
        /* Simulation support : Notification function call for exiting state : ThirdGear */
        RtsNotify(2,"f2c2277b-6000-44f9-9683-fe9a5429d22e",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.32)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::Fire_SecondToFirst()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
long val;
// release IOC, engage POC
val = 0;
//ATLTRACE("\n<external command> disengage IOC");
ClutchPort7->gen(&val);
val = 1;
//ATLTRACE("\n<external command> engage POC");
ClutchPort6->gen(&val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.33)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::Fire_FirstToNeutral()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
long val = 0;

// release FC, POC
//ATLTRACE("\n<external command> disengage FC");
ClutchPort5->gen(&val);
//ATLTRACE("\n<external command> disengage POC");
ClutchPort6->gen(&val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.34)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::Fire_ThirdToSecond()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
long val;
// engage IOC, release TCC, DC
val = 0;
//ATLTRACE("\n<external command> disengage DC");
ClutchPort8->gen(&val);
//ATLTRACE("\n<external command> disengage TCC");
ClutchPort9->gen(&val);
val = 1;
//ATLTRACE("\n<external command> engage IOC");
ClutchPort7->gen(&val);


//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.35)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void SimpleController::Fire_FourthToThird()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
long val;

// release OB, engage FC
val = 0;
//ATLTRACE("\n<external command> disengage OB");
ClutchPort10->gen(&val);
val = 1;
//ATLTRACE("\n<external command> engage FC");
ClutchPort5->gen(&val);


//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            
//}}SCG_OPS

//}}SCG_IMPLEMENTATION




