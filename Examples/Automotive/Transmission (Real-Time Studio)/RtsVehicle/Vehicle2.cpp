// implementation for class Vehicle2
#include "StdAfx.h"
#include "RtsOnTransmission.h"
#include "RigidConnector.h"
#include <math.h>

#include "Vehicle2.h"
// includes

HRESULT Vehicle2::r_ForwardNewton(double* res)
{
*res = p->torque * finalDriveRatio 
         - (vehicleInertia * (p->acceleration / finalDriveRatio) + 
            brakeTorque * 10.0 +
            wheelFrictionDrag +
            aerodynamicDrag * speed * speed);
return S_OK;
}


HRESULT Vehicle2::r_ReverseNewton(double* res)
{
*res = p->torque * finalDriveRatio 
         - (vehicleInertia * (p->acceleration / finalDriveRatio) -
            brakeTorque * 10.0 +
            wheelFrictionDrag +
            aerodynamicDrag * speed * speed);
return S_OK;
}


HRESULT Vehicle2::r_Speed(double* res)
{
#define PI 3.1415926535897932384626433832795
#define RPM2KMPH 1.13636363636363636363636363636e-2
*res = speed - 2.0*PI*wheelRadius *RPM2KMPH* wheelSpeed;
return S_OK;
}


HRESULT Vehicle2::r_wheelSpeed(double* res)
{
#define PI 3.1415926535897932384626433832795

  *res = DER(wheelSpeed) - (60.0 / (2.0 * PI)) * (p->acceleration / finalDriveRatio);
return S_OK;
}


void Vehicle2::init()
{
  p = new CRigidConnector();
  p->AddRef();
wheelSpeed = 0.0;
DER(wheelSpeed) = 0.0;
speed = 0.01;
DER(speed) = 0.0;

#define PI 3.1415926535897932384626433832795

aerodynamicDrag = 0.02;
brakeTorque = 0.0;
finalDriveRatio = 3.23;
vehicleInertia = 12.0941 * (60.0 / (2.0 * PI));
wheelFrictionDrag = 40.0;
wheelRadius = 1.0;


}


void Vehicle2::clean()
{
if (p)
{
  p->Release();
  p = NULL;
}
}


HRESULT Vehicle2::z_ForwardDirection(double* res)
{
*res = speed;
return S_OK;
}


HRESULT Vehicle2::z_ReverseDirection(double* res)
{
*res = 0.0 - speed;
return S_OK;
}


void Vehicle2::handle_brakeTorque(const double t, const double* val)
{

PostRealParameter(t, 0, *val);
}


void Vehicle2::handle_finalDriveRatio(const double t, const double* val)
{

PostRealParameter(t, 1, *val);
}


void Vehicle2::handle_wheelRadius(const double t, const double* val)
{

PostRealParameter(t, 2, *val);
}


void Vehicle2::handle_vehicleInertia(const double t, const double* val)
{

PostRealParameter(t, 3, *val);
}


void Vehicle2::handle_wheelFrictionDrag(const double t, const double* val)
{

PostRealParameter(t, 4, *val);
}


void Vehicle2::handle_aerodynamicDrag(const double t, const double* val)
{

PostRealParameter(t, 5, *val);
}


HRESULT Vehicle2::InitEsos()
{

  ADD_LOCAL_ESO(p)

  return S_OK;
}


HRESULT Vehicle2::InitLocalEqns()
{

  ADD_LOCAL_EQN(Vehicle2, r_ForwardNewton)
  ADD_LOCAL_EQN(Vehicle2, r_ReverseNewton)
  ADD_LOCAL_EQN(Vehicle2, r_Speed)
  ADD_LOCAL_EQN(Vehicle2, r_wheelSpeed)
  ADD_LOCAL_EQN(Vehicle2, z_ForwardDirection)
  ADD_LOCAL_EQN(Vehicle2, z_ReverseDirection)

  return S_OK;
}


HRESULT Vehicle2::InitLocalADEqns()
{

  ADD_LOCAL_AD_EQN(Vehicle2, ad_r_ForwardNewton)
  ADD_LOCAL_AD_EQN(Vehicle2, ad_r_ReverseNewton)
  ADD_LOCAL_AD_EQN(Vehicle2, ad_r_Speed)
  ADD_LOCAL_AD_EQN(Vehicle2, ad_r_wheelSpeed)
  ADD_LOCAL_AD_EQN(Vehicle2, ad_z_ForwardDirection)
  ADD_LOCAL_AD_EQN(Vehicle2, ad_z_ReverseDirection)

  return S_OK;
}


HRESULT Vehicle2::InitEqnForm(OnEqnForm** form, OnEqnDiffForm** diff_form)
{


const long idx_eqn_r_ForwardNewton = 0;
const long idx_eqn_r_ReverseNewton = 1;
const long idx_eqn_r_Speed = 2;
const long idx_eqn_r_wheelSpeed = 3;
const long idx_eqn_z_ForwardDirection = 4;
const long idx_eqn_z_ReverseDirection = 5;

  DESTROY_VECTOR(*form)
  *form = new OnEqnForm[m_nLocalEqns];
  (*form)[idx_eqn_r_ForwardNewton] = continuous;
  (*form)[idx_eqn_r_ReverseNewton] = continuous;
  (*form)[idx_eqn_r_Speed] = continuous;
  (*form)[idx_eqn_r_wheelSpeed] = continuous;
  (*form)[idx_eqn_z_ForwardDirection] = discontinuous;
  (*form)[idx_eqn_z_ReverseDirection] = discontinuous;

  DESTROY_VECTOR(*diff_form)
  *diff_form = new OnEqnDiffForm[m_nLocalEqns];
  (*diff_form)[idx_eqn_r_ForwardNewton] = automatic;
  (*diff_form)[idx_eqn_r_ReverseNewton] = automatic;
  (*diff_form)[idx_eqn_r_Speed] = automatic;
  (*diff_form)[idx_eqn_r_wheelSpeed] = automatic;
  (*diff_form)[idx_eqn_z_ForwardDirection] = automatic;
  (*diff_form)[idx_eqn_z_ReverseDirection] = automatic;

  return S_OK;
}


HRESULT Vehicle2::InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
{


  ADD_LOCAL_SVAR(wheelSpeed)
  ADD_LOCAL_SVAR(speed)

for (long i = 0; i < m_nEsos; i++)
  AddLocalVar(m_Esos[i], NULL, NULL, varC, true);

  return S_OK;
}


HRESULT Vehicle2::InitLocalRPars(const _TCHAR* prefix, ppdouble* pars, ppchar* Names, long* nPars, long* dPars)
{


  ADD_LOCAL_SRPAR(brakeTorque)
  ADD_LOCAL_SRPAR(finalDriveRatio)
  ADD_LOCAL_SRPAR(wheelRadius)
  ADD_LOCAL_SRPAR(vehicleInertia)
  ADD_LOCAL_SRPAR(wheelFrictionDrag)
  ADD_LOCAL_SRPAR(aerodynamicDrag)

  return S_OK;
}


HRESULT Vehicle2::InitTransitions()
{

HRESULT hr;
HRESULT hrRet = S_OK;


// equation constants
const long idx_eqn_r_ForwardNewton = 0;
const long idx_eqn_r_ReverseNewton = 1;
const long idx_eqn_r_Speed = 2;
const long idx_eqn_r_wheelSpeed = 3;
const long idx_eqn_z_ForwardDirection = 4;
const long idx_eqn_z_ReverseDirection = 5;

// state constants
const long idx_state_Forward = 0;
const long idx_state_Reverse = 1;

const long idx_eqns_es_ReverseForwardReverse[] = { 
  idx_eqn_z_ReverseDirection,
 };
const long idx_eqns_es_ForwardReverseForward[] = { 
  idx_eqn_z_ForwardDirection,
 };

// Transition_Name, Source_State, Event_Name, Transition_Eqns, Eqn_Count
hr = AddTransition(L"es_ReverseForwardReverse", idx_state_Forward, L"es_Reverse", idx_eqns_es_ReverseForwardReverse, 1);
if (FAILED(hr)) hrRet = hr;
hr = AddTransition(L"es_ForwardReverseForward", idx_state_Reverse, L"es_Forward", idx_eqns_es_ForwardReverseForward, 1);
if (FAILED(hr)) hrRet = hr;

return hrRet;
}


HRESULT Vehicle2::InitStates()
{

HRESULT hr;
HRESULT hrRet = S_OK;

// equation constants
const long idx_eqn_r_ForwardNewton = 0;
const long idx_eqn_r_ReverseNewton = 1;
const long idx_eqn_r_Speed = 2;
const long idx_eqn_r_wheelSpeed = 3;
const long idx_eqn_z_ForwardDirection = 4;
const long idx_eqn_z_ReverseDirection = 5;

// state constants
const long idx_state_Forward = 0;
const long idx_state_Reverse = 1;

const long idx_eqns_Forward[] = { 
  idx_eqn_r_ForwardNewton,
  idx_eqn_r_Speed,
  idx_eqn_r_wheelSpeed,
 };
const long idx_eqns_Reverse[] = { 
  idx_eqn_r_ReverseNewton,
  idx_eqn_r_Speed,
  idx_eqn_r_wheelSpeed,
 };

hr = AddState(L"Forward", 1, idx_eqns_Forward, 3);
if (FAILED(hr)) hrRet = hr;
hr = AddState(L"Reverse", 0, idx_eqns_Reverse, 3);
if (FAILED(hr)) hrRet = hr;


return hrRet;
}


HRESULT Vehicle2::OnTransition()
{

HRESULT hr = S_OK;

const long idx_state_Forward = 0;
const long idx_state_Reverse = 1;
switch (RtsCurrent_Vehicle2)
{
  case RtsVehicle2Vehicle2_States_Forward:
    ATLTRACE("\nForward");
    PostTransition(idx_state_Forward);
    break;
  case RtsVehicle2Vehicle2_States_Reverse:
    ATLTRACE("\nReverse");
    PostTransition(idx_state_Reverse);
    break;
}

return hr;
}


HRESULT Vehicle2::ad_r_ForwardNewton(Fdouble* res)
{
*res = p->ad_torque * finalDriveRatio 
         - (vehicleInertia * (p->ad_acceleration / finalDriveRatio) + 
            brakeTorque * 10.0 +
            wheelFrictionDrag +
            aerodynamicDrag * ad_speed * ad_speed);
return S_OK;
}


HRESULT Vehicle2::ad_r_ReverseNewton(Fdouble* res)
{
*res = p->ad_torque * finalDriveRatio 
         - (vehicleInertia * (p->ad_acceleration / finalDriveRatio) -
            brakeTorque * 10.0 +
            wheelFrictionDrag +
            aerodynamicDrag * ad_speed * ad_speed);
return S_OK;
}


HRESULT Vehicle2::ad_r_Speed(Fdouble* res)
{
#define PI 3.1415926535897932384626433832795
#define RPM2KMPH 1.13636363636363636363636363636e-2
*res = ad_speed - 2.0*PI*wheelRadius *RPM2KMPH* ad_wheelSpeed;
return S_OK;
}


HRESULT Vehicle2::ad_r_wheelSpeed(Fdouble* res)
{
#define PI 3.1415926535897932384626433832795

  *res = DER(ad_wheelSpeed) - (60.0 / (2.0 * PI)) * (p->ad_acceleration / finalDriveRatio);
return S_OK;
}


HRESULT Vehicle2::ad_z_ForwardDirection(Fdouble* res)
{
*res = ad_speed;
return S_OK;
}


HRESULT Vehicle2::ad_z_ReverseDirection(Fdouble* res)
{
*res = 0.0 - ad_speed;
return S_OK;
}


void Vehicle2::Save(FILE* fs)
{
WRITE_SCALAR(RtsCurrent_Vehicle2)
}


bool Vehicle2::Load(FILE* fs)
{
READ_SCALAR(RtsCurrent_Vehicle2)
return true;
}


void Vehicle2::RtsEnter_Reverse()
{
    /* Simulation support : Notification function call for entering state : Reverse */
    RtsNotify(1,"c3646ecd-6f06-47a7-b1a4-44cb3c7bcf08",0,NULL);

    RtsCurrent_Vehicle2 = RtsVehicle2Vehicle2_States_Reverse;

    /* Entry Actions */
    OnTransition();

}


void Vehicle2::RtsExit_Reverse()
{
    if (RtsCurrent_Vehicle2 == RtsVehicle2Vehicle2_States_Reverse)
    {
        /* Simulation support : Notification function call for exiting state : Reverse */
        RtsNotify(2,"c3646ecd-6f06-47a7-b1a4-44cb3c7bcf08",0,NULL);

    }

}


void Vehicle2::RtsEnter_Forward()
{
    /* Simulation support : Notification function call for entering state : Forward */
    RtsNotify(1,"6db7a876-42a0-4d5c-810a-3adb57fa5d58",0,NULL);

    RtsCurrent_Vehicle2 = RtsVehicle2Vehicle2_States_Forward;

    /* Entry Actions */
    OnTransition();

}


void Vehicle2::RtsExit_Forward()
{
    if (RtsCurrent_Vehicle2 == RtsVehicle2Vehicle2_States_Forward)
    {
        /* Simulation support : Notification function call for exiting state : Forward */
        RtsNotify(2,"6db7a876-42a0-4d5c-810a-3adb57fa5d58",0,NULL);

    }
}


void Vehicle2::RtsMovingReverse()
{
    RtsLock(RtsBusy);
    if (RtsCurrent_Vehicle2 == RtsVehicle2Vehicle2_States_Reverse)
    {
        RtsExit_Reverse();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"df7f09b7-58e1-4d8e-aa63-6a5fa201e2d6",0,NULL);

        RtsEnter_Forward();
    }
    else
    {
        /* Event not handled */
    }
    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

}


void Vehicle2::RtsMovingForward()
{
    RtsLock(RtsBusy);
    if (RtsCurrent_Vehicle2 == RtsVehicle2Vehicle2_States_Forward)
    {
        RtsExit_Forward();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"0a2f4ac1-fd65-4f35-aae2-2f6fa0a1f1a2",0,NULL);

        RtsEnter_Reverse();
    }
    else
    {
        /* Event not handled */
    }
    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

}


Vehicle2::Vehicle2()
{
    RtsRegisterStateMachine(this,RtsInjectEvent,RtsGetAttributeValue,RtsSetAttributeValue);
    RtsCreateSemaphore(RtsBusy);
    RtsLock(RtsBusy);

    /* Initialising State Vectors to NotIn */
    RtsCurrent_Vehicle2 = RtsVehicle2Vehicle2_States_NotIn_Vehicle2;

    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

}


Vehicle2::~Vehicle2()
{
    RtsUnregister(this);
    clean();
}


void Vehicle2::RtsRunToCompletion()
{
int EndOfLoop;
    for(EndOfLoop=0;EndOfLoop==0;)
    {
        EndOfLoop = 1;
        /* All completion transitions included here */
        if (RtsCurrent_Vehicle2 == RtsVehicle2Vehicle2_States_NotIn_Vehicle2)
        {
            /* Simulation support : Notification function calls for transition */
            RtsNotify(3,"fe37a707-5eec-45f4-8ca5-638adc902d03",0,NULL);

            init();
            RtsEnter_Forward();

            EndOfLoop = 0;
        }
    }
}

#ifdef RTS_SIMULATION
int Vehicle2::RtsInjectEvent(const char* Event, const int NumParams, const StringArray params, Vehicle2* pInstance)
{
int Ret;
char *StopString;
    Ret = 1;
    if (strlen(Event) == 0)
    {
        pInstance->RtsRunToCompletion();
    }
    else
    {
        if ((strcmp(Event, "es_Forward") == 0) || (strcmp(Event, "Vehicle2.es_Forward") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->es_Forward();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "es_Reverse") == 0) || (strcmp(Event, "Vehicle2.es_Reverse") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->es_Reverse();
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

}
#endif

#ifdef RTS_SIMULATION
int Vehicle2::RtsGetAttributeValue(const char* Name, char* Value, const int buflen, Vehicle2* pInstance)
{
int Ret;
    Ret = 1;
    if (strcmp(Name, "wheelSpeed") == 0)
    {
        sprintf(Value,"%.8g",pInstance->wheelSpeed);
    }
    else if (strcmp(Name, "speed") == 0)
    {
        sprintf(Value,"%.8g",pInstance->speed);
    }
    else if (strcmp(Name, "brakeTorque") == 0)
    {
        sprintf(Value,"%.8g",pInstance->brakeTorque);
    }
    else if (strcmp(Name, "finalDriveRatio") == 0)
    {
        sprintf(Value,"%.8g",pInstance->finalDriveRatio);
    }
    else if (strcmp(Name, "wheelRadius") == 0)
    {
        sprintf(Value,"%.8g",pInstance->wheelRadius);
    }
    else if (strcmp(Name, "vehicleInertia") == 0)
    {
        sprintf(Value,"%.8g",pInstance->vehicleInertia);
    }
    else if (strcmp(Name, "wheelFrictionDrag") == 0)
    {
        sprintf(Value,"%.8g",pInstance->wheelFrictionDrag);
    }
    else if (strcmp(Name, "aerodynamicDrag") == 0)
    {
        sprintf(Value,"%.8g",pInstance->aerodynamicDrag);
    }
    else if (strcmp(Name, "der_wheelSpeed") == 0)
    {
        sprintf(Value,"%.8g",pInstance->der_wheelSpeed);
    }
    else if (strcmp(Name, "old_wheelSpeed") == 0)
    {
        sprintf(Value,"%.8g",pInstance->old_wheelSpeed);
    }
    else if (strcmp(Name, "der_old_wheelSpeed") == 0)
    {
        sprintf(Value,"%.8g",pInstance->der_old_wheelSpeed);
    }
    else if (strcmp(Name, "ad_wheelSpeed") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_ad_wheelSpeed") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_speed") == 0)
    {
        sprintf(Value,"%.8g",pInstance->der_speed);
    }
    else if (strcmp(Name, "old_speed") == 0)
    {
        sprintf(Value,"%.8g",pInstance->old_speed);
    }
    else if (strcmp(Name, "der_old_speed") == 0)
    {
        sprintf(Value,"%.8g",pInstance->der_old_speed);
    }
    else if (strcmp(Name, "ad_speed") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_ad_speed") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "RtsCurrent_Vehicle2") == 0)
    {
        switch(pInstance->RtsCurrent_Vehicle2)
        {
            case RtsVehicle2Vehicle2_States_Reverse:
                strncpy(Value,"Reverse",buflen);
                break;
            case RtsVehicle2Vehicle2_States_Forward:
                strncpy(Value,"Forward",buflen);
                break;
            case RtsVehicle2Vehicle2_States_NotIn_Vehicle2:
                strncpy(Value,"NotIn_Vehicle2",buflen);
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
        strncpy(Value,"12880e78-bc67-4ddf-b940-65b8ac2c65c5", buflen);
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

}
#endif

#ifdef RTS_SIMULATION
int Vehicle2::RtsSetAttributeValue(const char* Name, const char* Value, Vehicle2* pInstance)
{
int Ret;
char *StopString;
    Ret = 1;
    if (strcmp(Name, "wheelSpeed") == 0)
    {
        pInstance->wheelSpeed = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "speed") == 0)
    {
        pInstance->speed = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "brakeTorque") == 0)
    {
        pInstance->brakeTorque = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "finalDriveRatio") == 0)
    {
        pInstance->finalDriveRatio = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "wheelRadius") == 0)
    {
        pInstance->wheelRadius = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "vehicleInertia") == 0)
    {
        pInstance->vehicleInertia = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "wheelFrictionDrag") == 0)
    {
        pInstance->wheelFrictionDrag = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "aerodynamicDrag") == 0)
    {
        pInstance->aerodynamicDrag = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "der_wheelSpeed") == 0)
    {
        pInstance->der_wheelSpeed = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "old_wheelSpeed") == 0)
    {
        pInstance->old_wheelSpeed = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "der_old_wheelSpeed") == 0)
    {
        pInstance->der_old_wheelSpeed = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "ad_wheelSpeed") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_ad_wheelSpeed") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_speed") == 0)
    {
        pInstance->der_speed = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "old_speed") == 0)
    {
        pInstance->old_speed = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "der_old_speed") == 0)
    {
        pInstance->der_old_speed = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "ad_speed") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_ad_speed") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "RtsCurrent_Vehicle2") == 0)
    {
        if (strcmp(Value, "Reverse") == 0 )
        {
            pInstance->RtsCurrent_Vehicle2 = RtsVehicle2Vehicle2_States_Reverse;
        }
        else if (strcmp(Value, "Forward") == 0 )
        {
            pInstance->RtsCurrent_Vehicle2 = RtsVehicle2Vehicle2_States_Forward;
        }
        else if (strcmp(Value, "NotIn_Vehicle2") == 0 )
        {
            pInstance->RtsCurrent_Vehicle2 = RtsVehicle2Vehicle2_States_NotIn_Vehicle2;
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

}
#endif


HRESULT Vehicle2::TriggerEvent(const double EventTime, const BSTR bstrEventId)
{

USES_CONVERSION;

CComBSTR EventId = bstrEventId;
HRESULT hr = S_OK;

if (EventId == L"es_Reverse")
  es_Reverse();
else if (EventId == L"es_Forward")
  es_Forward();

m_time = EventTime;

// update old variables
old_wheelSpeed = wheelSpeed;
old_speed = speed;

return S_OK;
}

void Vehicle2::es_Reverse()
{
    RtsLock(RtsBusy);
    if (RtsCurrent_Vehicle2 == RtsVehicle2Vehicle2_States_Forward)
    {
        RtsExit_Forward();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"0a2f4ac1-fd65-4f35-aae2-2f6fa0a1f1a2",0,NULL);

        RtsEnter_Reverse();
    }
    else
    {
        /* Event not handled */
    }
    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

}

void Vehicle2::es_Forward()
{
    RtsLock(RtsBusy);
    if (RtsCurrent_Vehicle2 == RtsVehicle2Vehicle2_States_Reverse)
    {
        RtsExit_Reverse();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"df7f09b7-58e1-4d8e-aa63-6a5fa201e2d6",0,NULL);

        RtsEnter_Forward();
    }
    else
    {
        /* Event not handled */
    }
    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

}
