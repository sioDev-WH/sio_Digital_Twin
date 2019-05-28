#ifndef __APPHARNESS_H
#define __APPHARNESS_H

//{{SCG_HEADER(AppHarness.h) [0]

//{{SCG_INCLUDE                     
#include "ShiftLogic.h"
#include "RtsSmInt.h"
//}}SCG_INCLUDE

//{{SCG_FORWARD                    

//}}SCG_FORWARD
void SetRtsRunning();

//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

template<class T> 
class AppHarness 
                  
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)
    public:
        T* m_app;
        RtsAppHarnessAppHarness_States RtsCurrent_AppHarness;     
        RtsMutex RtsBusy;     
    //{{CLASS_TEMPLATE_OPS
    private:
        
        //{{SCG_OP(.0)   
        //{{SCG_OP_INFO 
        /////////////////////////////////////////////////////////////////////   
        
        void RtsEnter_Init()  
        //}}SCG_OP_INFO
        {
        /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
        //{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Init */
    RtsNotify(1,"4cb6ff11-b0e7-4e06-aee7-a273af84c700",0,NULL);

    RtsCurrent_AppHarness = RtsAppHarnessAppHarness_States_Init;

    /* Entry Actions */
    m_app = new T();

        //}}SCG_OP_BODY
        /***** End of automatically generated code *****/
        }                     
        //}}SCG_OP            
    private:
        
        //{{SCG_OP(.1)   
        //{{SCG_OP_INFO 
        /////////////////////////////////////////////////////////////////////   
        
        void RtsExit_Init()  
        //}}SCG_OP_INFO
        {
        /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
        //{{SCG_OP_BODY
    if (RtsCurrent_AppHarness == RtsAppHarnessAppHarness_States_Init)
    {
        /* Simulation support : Notification function call for exiting state : Init */
        RtsNotify(2,"4cb6ff11-b0e7-4e06-aee7-a273af84c700",0,NULL);

    }

        //}}SCG_OP_BODY
        /***** End of automatically generated code *****/
        }                     
        //}}SCG_OP            
    private:
        
        //{{SCG_OP(.2)   
        //{{SCG_OP_INFO 
        /////////////////////////////////////////////////////////////////////   
        
        void RtsEnter_Clean()  
        //}}SCG_OP_INFO
        {
        /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
        //{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Clean */
    RtsNotify(1,"0907a3da-41af-48fa-9261-6b717b79e538",0,NULL);

    RtsCurrent_AppHarness = RtsAppHarnessAppHarness_States_Clean;

    /* Entry Actions */
    delete m_app;

        //}}SCG_OP_BODY
        /***** End of automatically generated code *****/
        }                     
        //}}SCG_OP            
    private:
        
        //{{SCG_OP(.3)   
        //{{SCG_OP_INFO 
        /////////////////////////////////////////////////////////////////////   
        
        void RtsExit_Clean()  
        //}}SCG_OP_INFO
        {
        /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
        //{{SCG_OP_BODY
    if (RtsCurrent_AppHarness == RtsAppHarnessAppHarness_States_Clean)
    {
        /* Simulation support : Notification function call for exiting state : Clean */
        RtsNotify(2,"0907a3da-41af-48fa-9261-6b717b79e538",0,NULL);

    }

        //}}SCG_OP_BODY
        /***** End of automatically generated code *****/
        }                     
        //}}SCG_OP            
    private:
        
        //{{SCG_OP(.4)   
        //{{SCG_OP_INFO 
        /////////////////////////////////////////////////////////////////////   
        
        void RtsEnter_Run()  
        //}}SCG_OP_INFO
        {
        /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
        //{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Run */
    RtsNotify(1,"2fddc45f-f4f2-4830-a15c-881f58d47b39",0,NULL);

    RtsCurrent_AppHarness = RtsAppHarnessAppHarness_States_Run;

    /* Entry Actions */
    m_app->runSimulation();

        //}}SCG_OP_BODY
        /***** End of automatically generated code *****/
        }                     
        //}}SCG_OP            
    private:
        
        //{{SCG_OP(.5)   
        //{{SCG_OP_INFO 
        /////////////////////////////////////////////////////////////////////   
        
        void RtsExit_Run()  
        //}}SCG_OP_INFO
        {
        /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
        //{{SCG_OP_BODY
    if (RtsCurrent_AppHarness == RtsAppHarnessAppHarness_States_Run)
    {
        /* Simulation support : Notification function call for exiting state : Run */
        RtsNotify(2,"2fddc45f-f4f2-4830-a15c-881f58d47b39",0,NULL);

    }

        //}}SCG_OP_BODY
        /***** End of automatically generated code *****/
        }                     
        //}}SCG_OP            
    public:
        
        //{{SCG_OP(.6)   
        //{{SCG_OP_INFO 
        /////////////////////////////////////////////////////////////////////   
        
        void RtsrunSim()  
        //}}SCG_OP_INFO
        {
        /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
        //{{SCG_OP_BODY

    SetRtsRunning();
    RtsLock(RtsBusy);
    if (RtsCurrent_AppHarness == RtsAppHarnessAppHarness_States_Init)
    {
        RtsExit_Init();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"f2f7e796-5e71-4755-996b-8d1d646e9a8e",0,NULL);

        RtsEnter_Run();
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
    public:
        
        //{{SCG_OP(.7)   
        //{{SCG_OP_INFO 
        /////////////////////////////////////////////////////////////////////   
        
        void RtsexitSim()  
        //}}SCG_OP_INFO
        {
        /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
        //{{SCG_OP_BODY
    RtsLock(RtsBusy);
    if (RtsCurrent_AppHarness == RtsAppHarnessAppHarness_States_Run)
    {
        RtsExit_Run();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"d596b18a-7f0d-4b72-a1d2-7fff776fd5e1",0,NULL);

        RtsEnter_Clean();
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
    public:
        
        //{{SCG_OP(.8)   
        //{{SCG_OP_INFO 
        /////////////////////////////////////////////////////////////////////   
        
        AppHarness()  
        //}}SCG_OP_INFO
        {
        /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
        //{{SCG_OP_BODY
    RtsRegisterStateMachine(this,RtsInjectEvent,RtsGetAttributeValue,RtsSetAttributeValue);
    RtsCreateSemaphore(RtsBusy);
    RtsLock(RtsBusy);

    /* Initialising State Vectors to NotIn */
    RtsCurrent_AppHarness=RtsAppHarnessAppHarness_States_NotIn_AppHarness;

    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

        //}}SCG_OP_BODY
        /***** End of automatically generated code *****/
        }                     
        //}}SCG_OP            
    public:
        
        //{{SCG_OP(.9)   
        //{{SCG_OP_INFO 
        /////////////////////////////////////////////////////////////////////   
        
        ~AppHarness()  
        //}}SCG_OP_INFO
        {
        /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
        //{{SCG_OP_BODY
    RtsUnregister(this);

        //}}SCG_OP_BODY
        /***** End of automatically generated code *****/
        }                     
        //}}SCG_OP            
    private:
        
        //{{SCG_OP(.10)   
        //{{SCG_OP_INFO 
        /////////////////////////////////////////////////////////////////////   
        
        void RtsRunToCompletion()  
        //}}SCG_OP_INFO
        {
        /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
        //{{SCG_OP_BODY
int EndOfLoop;
    for(EndOfLoop=0;EndOfLoop==0;)
    {
        EndOfLoop = 1;
        /* All completion transitions included here */
        if (RtsCurrent_AppHarness == RtsAppHarnessAppHarness_States_NotIn_AppHarness)
        {
            /* Simulation support : Notification function calls for transition */
            RtsNotify(3,"da69dd17-1901-4237-b35e-d900f20934c9",0,NULL);

            RtsEnter_Init();

            EndOfLoop = 0;
        }
    }

        //}}SCG_OP_BODY
        /***** End of automatically generated code *****/
        }                     
        //}}SCG_OP            
    private:
        
        //{{SCG_OP(.11)   
        //{{SCG_OP_INFO 
        /////////////////////////////////////////////////////////////////////   
        
        #ifdef RTS_SIMULATION
static int RtsInjectEvent(const char* Event, const int NumParams, const StringArray params, AppHarness *pInstance)  
        //}}SCG_OP_INFO
        {
        /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
        //{{SCG_OP_BODY
int Ret;
//char *StopString;
    Ret = 1;
    if (strlen(Event) == 0)
    {
        pInstance->RtsRunToCompletion();
    }
    else
    {
        if ((strcmp(Event, "runSim") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->RtsrunSim();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "exitSim") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->RtsexitSim();
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
    private:
        
        //{{SCG_OP(.12)   
        //{{SCG_OP_INFO 
        /////////////////////////////////////////////////////////////////////   
        
        #ifdef RTS_SIMULATION
static int RtsGetAttributeValue(const char* Name, char* Value, const int buflen, AppHarness *pInstance)  
        //}}SCG_OP_INFO
        {
        /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
        //{{SCG_OP_BODY
int Ret;
    Ret = 1;
    if (strcmp(Name, "m_app") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "RtsCurrent_AppHarness") == 0)
    {
        switch(pInstance->RtsCurrent_AppHarness)
        {
            case RtsAppHarnessAppHarness_States_Init:
                strncpy(Value,"Init",buflen);
                break;
            case RtsAppHarnessAppHarness_States_Clean:
                strncpy(Value,"Clean",buflen);
                break;
            case RtsAppHarnessAppHarness_States_Run:
                strncpy(Value,"Run",buflen);
                break;
            case RtsAppHarnessAppHarness_States_NotIn_AppHarness:
                strncpy(Value,"NotIn_AppHarness",buflen);
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
        strncpy(Value,"5cb1f156-22e3-4513-a231-eb7a5cc1f1a6", buflen);
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
    private:
        
        //{{SCG_OP(.13)   
        //{{SCG_OP_INFO 
        /////////////////////////////////////////////////////////////////////   
        
        #ifdef RTS_SIMULATION
static int RtsSetAttributeValue(const char* Name, const char* Value, AppHarness *pInstance)  
        //}}SCG_OP_INFO
        {
        /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
        //{{SCG_OP_BODY
int Ret;
//char *StopString;
    Ret = 1;
    if (strcmp(Name, "m_app") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "RtsCurrent_AppHarness") == 0)
    {
        if (strcmp(Value, "Init") == 0 )
        {
            pInstance->RtsCurrent_AppHarness = RtsAppHarnessAppHarness_States_Init;
        }
        else if (strcmp(Value, "Clean") == 0 )
        {
            pInstance->RtsCurrent_AppHarness = RtsAppHarnessAppHarness_States_Clean;
        }
        else if (strcmp(Value, "Run") == 0 )
        {
            pInstance->RtsCurrent_AppHarness = RtsAppHarnessAppHarness_States_Run;
        }
        else if (strcmp(Value, "NotIn_AppHarness") == 0 )
        {
            pInstance->RtsCurrent_AppHarness = RtsAppHarnessAppHarness_States_NotIn_AppHarness;
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
    //}}CLASS_TEMPLATE_OPS
    //}}SCG_CLASS_PROPS
};

//}}SCG_CLASS

//}}SCG_HEADER      
#endif










