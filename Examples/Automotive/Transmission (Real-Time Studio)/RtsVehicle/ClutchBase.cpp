//{{SCG_IMPLEMENTATION(ClutchBase.cpp) [0]

//{{SCG_INCLUDE    
#include "StdAfx.h" 
#include "ActuatorClutchConnector.h"                   
#include "RigidConnector.h"

                 
#include "ClutchBase.h"
// Include for Template Class should go here.
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//}}SCG_INCLUDE
                      
//{{SCG_CLASS_ID
#ifdef RTS_SIMULATION
const static RtsClassInfo RtsClutchBase_ClassInfo("6b2e8ee9-64b1-11d5-b14b-00c04f680d9d", RTS_STM);
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

void ClutchBase::es_LockToCCSlip()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsLock(RtsBusy);
    if (RtsCurrent_Clutch == RtsClutchBaseClutch_States_Lock)
    {
        RtsExit_Lock();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"13249277-9bcd-11d5-b195-00c04f680d9d",0,NULL);

        RtsEnter_ccSlip();
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

//{{SCG_OP(0.10)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::r_clockwiseBreakfreeDisp(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res = cBreakfreeDisp - cOilDisp - cBreakfreeDispMax*actuatorConnector->pressure/pressureMax;

return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.11)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::r_counterclockwiseBreakfreeDisp(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res = ccBreakfreeDisp - ccOilDisp - ccBreakfreeDispMax*actuatorConnector->pressure/pressureMax;

return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.12)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void ClutchBase::es_LockToCSlip()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsLock(RtsBusy);
    if (RtsCurrent_Clutch == RtsClutchBaseClutch_States_Lock)
    {
        RtsExit_Lock();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"d02622ca-673c-11d5-b150-00c04f680d9d",0,NULL);

        RtsEnter_cSlip();
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

//{{SCG_OP(0.9)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void ClutchBase::init()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  p = new CRigidConnector();
  n = new CRigidConnector();
  actuatorConnector = new ActuatorClutchConnector();     
  p->AddRef();
  n->AddRef();
  actuatorConnector->AddRef();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.0)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::r_cSlipDisplacement(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res= DER(displacement);
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.1)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::r_stickDisplacement(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res=DER(displacement) - relativeVelocity;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.3)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::z_velocity_neg(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res=-relativeVelocity;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.4)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::z_velocity_pos(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res=relativeVelocity;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.5)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::z_disp_pos_slip(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res=displacement-cBreakfreeDisp;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.6)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::z_disp_neg_slip(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res=-displacement-ccBreakfreeDisp;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.17)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void ClutchBase::es_SlipToLock()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsLock(RtsBusy);
    if (RtsCurrent_Clutch == RtsClutchBaseClutch_States_cSlip)
    {
        RtsExit_cSlip();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"8c7d129a-9c8e-11d5-b196-00c04f680d9d",0,NULL);

        RtsEnter_Lock();
    }
    else if (RtsCurrent_Clutch == RtsClutchBaseClutch_States_ccSlip)
    {
        RtsExit_ccSlip();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"8c7d129f-9c8e-11d5-b196-00c04f680d9d",0,NULL);

        RtsEnter_Lock();
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

//{{SCG_OP(0.18)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void ClutchBase::clean()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  p->Release();
  n->Release();
  actuatorConnector->Release();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.19)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::r_ccSlipDisplacement(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res= DER(displacement);
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.20)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::r_forceBalance(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res = p->torque + n->torque;
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.21)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::r_relativeVelocity(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res = DER(relativeVelocity) - (p->acceleration - n->acceleration);
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.16)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::ad_r_ccSlipDisplacement(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res= DER(ad_displacement);
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.17)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::ad_r_clockwiseBreakfreeDisp(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res = ad_cBreakfreeDisp - cOilDisp - cBreakfreeDispMax*actuatorConnector->ad_pressure/pressureMax;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.18)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::ad_r_counterclockwiseBreakfreeDisp(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res = ad_ccBreakfreeDisp - ccOilDisp - ccBreakfreeDispMax*actuatorConnector->ad_pressure/pressureMax;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.19)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::ad_r_cSlipDisplacement(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res= DER(ad_displacement);
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.20)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::ad_r_forceBalance(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res = p->ad_torque + n->ad_torque;
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.21)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::ad_r_relativeVelocity(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res = DER(ad_relativeVelocity) - (p->ad_acceleration - n->ad_acceleration);
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.22)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::ad_r_stickDisplacement(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res=DER(ad_displacement) - ad_relativeVelocity;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.23)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::ad_s_ccLockDisplacement(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = ad_displacement - (-old_ccBreakfreeDisp + 1.0e-5);
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.24)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::ad_s_cLockDisplacement(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = ad_displacement - (old_cBreakfreeDisp - 1.0e-5);
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.25)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::ad_z_disp_neg_slip(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res=-ad_displacement-ad_ccBreakfreeDisp;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.26)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::ad_z_disp_pos_slip(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res=ad_displacement-ad_cBreakfreeDisp;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.27)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::ad_z_velocity_neg(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res=-ad_relativeVelocity;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.28)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::ad_z_velocity_pos(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res=ad_relativeVelocity;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.30)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void ClutchBase::RtsEnter_cSlip()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : cSlip */
    RtsNotify(1,"d02622b6-673c-11d5-b150-00c04f680d9d",0,NULL);

    RtsCurrent_Clutch = RtsClutchBaseClutch_States_cSlip;

    /* Entry Actions */
    if (!bInConstruction) OnTransition();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.31)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void ClutchBase::RtsExit_cSlip()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Clutch == RtsClutchBaseClutch_States_cSlip)
    {
        /* Simulation support : Notification function call for exiting state : cSlip */
        RtsNotify(2,"d02622b6-673c-11d5-b150-00c04f680d9d",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.32)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void ClutchBase::RtsEnter_Lock()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Lock */
    RtsNotify(1,"d02622b8-673c-11d5-b150-00c04f680d9d",0,NULL);

    RtsCurrent_Clutch = RtsClutchBaseClutch_States_Lock;

    /* Entry Actions */
    if (!bInConstruction) OnTransition();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.33)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void ClutchBase::RtsExit_Lock()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Clutch == RtsClutchBaseClutch_States_Lock)
    {
        /* Simulation support : Notification function call for exiting state : Lock */
        RtsNotify(2,"d02622b8-673c-11d5-b150-00c04f680d9d",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.34)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void ClutchBase::RtsEnter_ccSlip()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : ccSlip */
    RtsNotify(1,"13249266-9bcd-11d5-b195-00c04f680d9d",0,NULL);

    RtsCurrent_Clutch = RtsClutchBaseClutch_States_ccSlip;

    /* Entry Actions */
    if (!bInConstruction) OnTransition();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.35)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void ClutchBase::RtsExit_ccSlip()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Clutch == RtsClutchBaseClutch_States_ccSlip)
    {
        /* Simulation support : Notification function call for exiting state : ccSlip */
        RtsNotify(2,"13249266-9bcd-11d5-b195-00c04f680d9d",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.36)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

 ClutchBase::ClutchBase() : bInConstruction(false),ccOilDisp(1.0e-3),cOilDisp(1.0e-3)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    bInConstruction = true;

    RtsRegisterStateMachine(this,RtsInjectEvent,RtsGetAttributeValue,RtsSetAttributeValue);
    RtsCreateSemaphore(RtsBusy);
    RtsLock(RtsBusy);

    /* Initialising State Vectors to NotIn */
    RtsCurrent_Clutch=RtsClutchBaseClutch_States_NotIn_Clutch;

    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

    bInConstruction = false;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.37)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

 ClutchBase::~ClutchBase()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsUnregister(this);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.38)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void ClutchBase::RtsRunToCompletion()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int EndOfLoop;
    for(EndOfLoop=0;EndOfLoop==0;)
    {
        EndOfLoop = 1;
        /* All completion transitions included here */
        if (RtsCurrent_Clutch == RtsClutchBaseClutch_States_NotIn_Clutch)
        {
            /* Simulation support : Notification function calls for transition */
            RtsNotify(3,"8c7d12a4-9c8e-11d5-b196-00c04f680d9d",0,NULL);

            init();
            RtsEnter_Lock();

            EndOfLoop = 0;
        }
    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.39)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

#ifdef RTS_SIMULATION
int ClutchBase::RtsInjectEvent(const char* Event, const int NumParams, const StringArray params, ClutchBase *pInstance)  
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
        if ((strcmp(Event, "es_SlipToLock") == 0) || (strcmp(Event, "ClutchBase.es_SlipToLock") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->es_SlipToLock();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "es_LockToCCSlip") == 0) || (strcmp(Event, "ClutchBase.es_LockToCCSlip") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->es_LockToCCSlip();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "es_LockToCSlip") == 0) || (strcmp(Event, "ClutchBase.es_LockToCSlip") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->es_LockToCSlip();
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

//{{SCG_OP(0.40)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

#ifdef RTS_SIMULATION
int ClutchBase::RtsGetAttributeValue(const char* Name, char* Value, const int buflen, ClutchBase *pInstance)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int Ret;
    Ret = 1;
    if (strcmp(Name, "actuatorConnector") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "n") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "p") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "area") == 0)
    {
        sprintf(Value,"%.8g",pInstance->area);
    }
    else if (strcmp(Name, "radius") == 0)
    {
        sprintf(Value,"%.8g",pInstance->radius);
    }
    else if (strcmp(Name, "relativeVelocity") == 0)
    {
        sprintf(Value,"%.8g",pInstance->relativeVelocity);
    }
    else if (strcmp(Name, "cBreakfreeDisp") == 0)
    {
        sprintf(Value,"%.8g",pInstance->cBreakfreeDisp);
    }
    else if (strcmp(Name, "torqueRatio") == 0)
    {
        sprintf(Value,"%.8g",pInstance->torqueRatio);
    }
    else if (strcmp(Name, "damping") == 0)
    {
        sprintf(Value,"%.8g",pInstance->damping);
    }
    else if (strcmp(Name, "stiffness") == 0)
    {
        sprintf(Value,"%.8g",pInstance->stiffness);
    }
    else if (strcmp(Name, "displacement") == 0)
    {
        sprintf(Value,"%.8g",pInstance->displacement);
    }
    else if (strcmp(Name, "frictionCoefficient") == 0)
    {
        sprintf(Value,"%.8g",pInstance->frictionCoefficient);
    }
    else if (strcmp(Name, "ccBreakfreeDisp") == 0)
    {
        sprintf(Value,"%.8g",pInstance->ccBreakfreeDisp);
    }
    else if (strcmp(Name, "pressureMax") == 0)
    {
        sprintf(Value,"%.8g",pInstance->pressureMax);
    }
    else if (strcmp(Name, "cBreakfreeDispMax") == 0)
    {
        sprintf(Value,"%.8g",pInstance->cBreakfreeDispMax);
    }
    else if (strcmp(Name, "ccBreakfreeDispMax") == 0)
    {
        sprintf(Value,"%.8g",pInstance->ccBreakfreeDispMax);
    }
    else if (strcmp(Name, "ad_cBreakfreeDisp") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "ad_ccBreakfreeDisp") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "ad_displacement") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "ad_relativeVelocity") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "bInConstruction") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "ccOilDisp") == 0)
    {
        sprintf(Value,"%.8g",pInstance->ccOilDisp);
    }
    else if (strcmp(Name, "cOilDisp") == 0)
    {
        sprintf(Value,"%.8g",pInstance->cOilDisp);
    }
    else if (strcmp(Name, "der_ad_cBreakfreeDisp") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_ad_ccBreakfreeDisp") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_ad_displacement") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_ad_relativeVelocity") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_cBreakfreeDisp") == 0)
    {
        sprintf(Value,"%.8g",pInstance->der_cBreakfreeDisp);
    }
    else if (strcmp(Name, "der_ccBreakfreeDisp") == 0)
    {
        sprintf(Value,"%.8g",pInstance->der_ccBreakfreeDisp);
    }
    else if (strcmp(Name, "der_displacement") == 0)
    {
        sprintf(Value,"%.8g",pInstance->der_displacement);
    }
    else if (strcmp(Name, "der_old_cBreakfreeDisp") == 0)
    {
        sprintf(Value,"%.8g",pInstance->der_old_cBreakfreeDisp);
    }
    else if (strcmp(Name, "der_old_ccBreakfreeDisp") == 0)
    {
        sprintf(Value,"%.8g",pInstance->der_old_ccBreakfreeDisp);
    }
    else if (strcmp(Name, "der_old_displacement") == 0)
    {
        sprintf(Value,"%.8g",pInstance->der_old_displacement);
    }
    else if (strcmp(Name, "der_old_relativeVelocity") == 0)
    {
        sprintf(Value,"%.8g",pInstance->der_old_relativeVelocity);
    }
    else if (strcmp(Name, "der_relativeVelocity") == 0)
    {
        sprintf(Value,"%.8g",pInstance->der_relativeVelocity);
    }
    else if (strcmp(Name, "old_cBreakfreeDisp") == 0)
    {
        sprintf(Value,"%.8g",pInstance->old_cBreakfreeDisp);
    }
    else if (strcmp(Name, "old_ccBreakfreeDisp") == 0)
    {
        sprintf(Value,"%.8g",pInstance->old_ccBreakfreeDisp);
    }
    else if (strcmp(Name, "old_displacement") == 0)
    {
        sprintf(Value,"%.8g",pInstance->old_displacement);
    }
    else if (strcmp(Name, "old_relativeVelocity") == 0)
    {
        sprintf(Value,"%.8g",pInstance->old_relativeVelocity);
    }
    else if (strcmp(Name, "RtsCurrent_Clutch") == 0)
    {
        switch(pInstance->RtsCurrent_Clutch)
        {
            case RtsClutchBaseClutch_States_cSlip:
                strncpy(Value,"cSlip",buflen);
                break;
            case RtsClutchBaseClutch_States_Lock:
                strncpy(Value,"Lock",buflen);
                break;
            case RtsClutchBaseClutch_States_ccSlip:
                strncpy(Value,"ccSlip",buflen);
                break;
            case RtsClutchBaseClutch_States_NotIn_Clutch:
                strncpy(Value,"NotIn_Clutch",buflen);
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
        strncpy(Value,"6b2e8ee9-64b1-11d5-b14b-00c04f680d9d", buflen);
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

//{{SCG_OP(0.41)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

#ifdef RTS_SIMULATION
int ClutchBase::RtsSetAttributeValue(const char* Name, const char* Value, ClutchBase *pInstance)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int Ret;
char *StopString;
    Ret = 1;
    if (strcmp(Name, "actuatorConnector") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "n") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "p") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "area") == 0)
    {
        pInstance->area = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "radius") == 0)
    {
        pInstance->radius = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "relativeVelocity") == 0)
    {
        pInstance->relativeVelocity = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "cBreakfreeDisp") == 0)
    {
        pInstance->cBreakfreeDisp = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "torqueRatio") == 0)
    {
        pInstance->torqueRatio = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "damping") == 0)
    {
        pInstance->damping = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "stiffness") == 0)
    {
        pInstance->stiffness = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "displacement") == 0)
    {
        pInstance->displacement = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "frictionCoefficient") == 0)
    {
        pInstance->frictionCoefficient = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "ccBreakfreeDisp") == 0)
    {
        pInstance->ccBreakfreeDisp = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "pressureMax") == 0)
    {
        pInstance->pressureMax = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "cBreakfreeDispMax") == 0)
    {
        pInstance->cBreakfreeDispMax = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "ccBreakfreeDispMax") == 0)
    {
        pInstance->ccBreakfreeDispMax = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "ad_cBreakfreeDisp") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "ad_ccBreakfreeDisp") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "ad_displacement") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "ad_relativeVelocity") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "bInConstruction") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "ccOilDisp") == 0)
    {
        pInstance->ccOilDisp = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "cOilDisp") == 0)
    {
        pInstance->cOilDisp = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "der_ad_cBreakfreeDisp") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_ad_ccBreakfreeDisp") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_ad_displacement") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_ad_relativeVelocity") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_cBreakfreeDisp") == 0)
    {
        pInstance->der_cBreakfreeDisp = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "der_ccBreakfreeDisp") == 0)
    {
        pInstance->der_ccBreakfreeDisp = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "der_displacement") == 0)
    {
        pInstance->der_displacement = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "der_old_cBreakfreeDisp") == 0)
    {
        pInstance->der_old_cBreakfreeDisp = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "der_old_ccBreakfreeDisp") == 0)
    {
        pInstance->der_old_ccBreakfreeDisp = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "der_old_displacement") == 0)
    {
        pInstance->der_old_displacement = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "der_old_relativeVelocity") == 0)
    {
        pInstance->der_old_relativeVelocity = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "der_relativeVelocity") == 0)
    {
        pInstance->der_relativeVelocity = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "old_cBreakfreeDisp") == 0)
    {
        pInstance->old_cBreakfreeDisp = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "old_ccBreakfreeDisp") == 0)
    {
        pInstance->old_ccBreakfreeDisp = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "old_displacement") == 0)
    {
        pInstance->old_displacement = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "old_relativeVelocity") == 0)
    {
        pInstance->old_relativeVelocity = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "RtsCurrent_Clutch") == 0)
    {
        if (strcmp(Value, "cSlip") == 0 )
        {
            pInstance->RtsCurrent_Clutch = RtsClutchBaseClutch_States_cSlip;
        }
        else if (strcmp(Value, "Lock") == 0 )
        {
            pInstance->RtsCurrent_Clutch = RtsClutchBaseClutch_States_Lock;
        }
        else if (strcmp(Value, "ccSlip") == 0 )
        {
            pInstance->RtsCurrent_Clutch = RtsClutchBaseClutch_States_ccSlip;
        }
        else if (strcmp(Value, "NotIn_Clutch") == 0 )
        {
            pInstance->RtsCurrent_Clutch = RtsClutchBaseClutch_States_NotIn_Clutch;
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

//{{SCG_OP(0.42)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::s_cLockDisplacement(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = displacement - (old_cBreakfreeDisp - 1.0e-5);
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.43)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT ClutchBase::s_ccLockDisplacement(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = displacement - (-old_ccBreakfreeDisp + 1.0e-5);
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            
//}}SCG_OPS

//}}SCG_IMPLEMENTATION









