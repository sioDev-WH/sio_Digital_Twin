//{{SCG_IMPLEMENTATION(Actuator.cpp) [0]

//{{SCG_INCLUDE  

// Cg_Add
#include "StdAfx.h" 
#include "ActuatorClutchConnector.h"
#include "math.h"
#include "ShiftLogic.h"


#include "Actuator.h"
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
const static RtsClassInfo RtsActuator_ClassInfo("3fd88f70-6811-11d5-b152-00c04f680d9d", RTS_STM);
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

void Actuator::ec_Engage()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsLock(RtsBusy);
    if (RtsCurrent_Actuator == RtsActuatorActuator_States_Disengaged)
    {
        RtsExit_Disengaged();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"79b263cd-998e-11d5-b192-00c04f680d9d",0,NULL);

        RtsEnter_Engaged();
    }
    else if (RtsCurrent_Actuator == RtsActuatorActuator_States_Waiting)
    {
        RtsExit_Waiting();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"3fd88faa-6811-11d5-b152-00c04f680d9d",0,NULL);

        RtsEnter_Engaged();
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

void Actuator::ec_Disengage()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsLock(RtsBusy);
    if (RtsCurrent_Actuator == RtsActuatorActuator_States_Engaged)
    {
        RtsExit_Engaged();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"3fd88f95-6811-11d5-b152-00c04f680d9d",0,NULL);

        RtsEnter_Disengaged();
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

HRESULT Actuator::r_ShiftTime(double *res)  
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

//{{SCG_OP(0.3)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Actuator::r_EngageProfile(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res = clutchConnector->pressure-pressureMax*(1-2.0/(1.0+exp(rate*shiftTime*shiftTime)));
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.4)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Actuator::r_DisengageProfile(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res=clutchConnector->pressure - pressureMax * 
    (2.0/(1.0+exp(rate*shiftTime*shiftTime)));
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.5)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Actuator::s_ShiftTime(double *res)  
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

//{{SCG_OP(0.6)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Actuator::init()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
clutchConnector = new ActuatorClutchConnector(); 
clutchConnector->AddRef();

clutchConnector->pressure=0.0;
clutchConnector->der(pressure) = 0.0;
pressureMax=1000.0;
tolerance=0.001;
shiftTime=0.0;
der(shiftTime) = 1.0;
shiftPeriod=0.5;
rate=log(2.0/tolerance - 1.0)/(shiftPeriod*shiftPeriod);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            


void Actuator::SetShiftPeriod(double val)
{
  shiftPeriod = val;
  rate=log(2.0/tolerance - 1.0)/(shiftPeriod*shiftPeriod);
}

//{{SCG_OP(0.7)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Actuator::clean()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
clutchConnector->Release();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.8)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Actuator::r_WaitProfile(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = clutchConnector->pressure;
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.9)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Actuator::handle_shiftEvent(const double t, long* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

if(*val == 0)
  PostStateEvent(t, L"ec_Disengage");
else
  PostStateEvent(t, L"ec_Engage");

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.10)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Actuator::handle_shiftPeriod(const double t, double* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

PostRealParameter(t, 0, *val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.11)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Actuator::handle_rate(const double t, double* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

PostRealParameter(t, 1, *val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.12)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Actuator::handle_tolerance(const double t, double* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

PostRealParameter(t, 2, *val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.13)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Actuator::handle_pressureMax(const double t, double* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

PostRealParameter(t, 3, *val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            


//{{SCG_OP(0.15)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Actuator::InitEsos()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

  ADD_LOCAL_ESO(clutchConnector)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.16)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Actuator::InitLocalEqns()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

  ADD_LOCAL_EQN(Actuator, r_ShiftTime)
  ADD_LOCAL_EQN(Actuator, r_EngageProfile)
  ADD_LOCAL_EQN(Actuator, r_DisengageProfile)
  ADD_LOCAL_EQN(Actuator, s_ShiftTime)
  ADD_LOCAL_EQN(Actuator, r_WaitProfile)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.17)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Actuator::InitLocalADEqns()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

  ADD_LOCAL_AD_EQN(Actuator, ad_r_ShiftTime)
  ADD_LOCAL_AD_EQN(Actuator, ad_r_EngageProfile)
  ADD_LOCAL_AD_EQN(Actuator, ad_r_DisengageProfile)
  ADD_LOCAL_AD_EQN(Actuator, ad_s_ShiftTime)
  ADD_LOCAL_AD_EQN(Actuator, ad_r_WaitProfile)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.18)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Actuator::InitEqnForm(OnEqnForm* *form, OnEqnDiffForm* *diff_form)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


const long idx_eqn_r_ShiftTime = 0;
const long idx_eqn_r_EngageProfile = 1;
const long idx_eqn_r_DisengageProfile = 2;
const long idx_eqn_s_ShiftTime = 3;
const long idx_eqn_r_WaitProfile = 4;

  DESTROY_VECTOR(*form)
  *form = new OnEqnForm[m_nLocalEqns];
  (*form)[idx_eqn_r_ShiftTime] = continuous;
  (*form)[idx_eqn_r_EngageProfile] = continuous;
  (*form)[idx_eqn_r_DisengageProfile] = continuous;
  (*form)[idx_eqn_s_ShiftTime] = reset;
  (*form)[idx_eqn_r_WaitProfile] = continuous;

  DESTROY_VECTOR(*diff_form)
  *diff_form = new OnEqnDiffForm[m_nLocalEqns];
  (*diff_form)[idx_eqn_r_ShiftTime] = numeric;
  (*diff_form)[idx_eqn_r_EngageProfile] = numeric;
  (*diff_form)[idx_eqn_r_DisengageProfile] = numeric;
  (*diff_form)[idx_eqn_s_ShiftTime] = numeric;
  (*diff_form)[idx_eqn_r_WaitProfile] = numeric;

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.19)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Actuator::InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


  ADD_LOCAL_SVAR(shiftTime)

for (long i = 0; i < m_nEsos; i++)
  AddLocalVar(m_Esos[i], NULL, NULL, varC, true);

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.20)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Actuator::InitLocalRPars(const _TCHAR* prefix, ppdouble *pars, ppchar *Names, long *nPars, long *dPars)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


  ADD_LOCAL_SRPAR(shiftPeriod)
  ADD_LOCAL_SRPAR(rate)
  ADD_LOCAL_SRPAR(tolerance)
  ADD_LOCAL_SRPAR(pressureMax)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.21)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Actuator::InitLocalIPars(const _TCHAR* prefix, pplong *pars, ppchar *Names, long *nPars, long *dPars)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY



  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.22)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Actuator::InitTransitions()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

HRESULT hr;
HRESULT hrRet = S_OK;


// equation constants
const long idx_eqn_r_ShiftTime = 0;
const long idx_eqn_r_EngageProfile = 1;
const long idx_eqn_r_DisengageProfile = 2;
const long idx_eqn_s_ShiftTime = 3;
const long idx_eqn_r_WaitProfile = 4;

// state constants
const long idx_state_Disengaged = 0;
const long idx_state_Engaged = 1;
const long idx_state_Waiting = 2;

const long idx_eqns_ec_EngageDisengagedEngaged[] = { 
  idx_eqn_s_ShiftTime,
 };
const long idx_eqns_ec_DisengageEngagedDisengaged[] = { 
  idx_eqn_s_ShiftTime,
 };
const long idx_eqns_ec_EngageWaitingEngaged[] = { 
  idx_eqn_s_ShiftTime,
 };

// Transition_Name, Source_State, Event_Name, Transition_Eqns, Eqn_Count
hr = AddTransition(L"ec_EngageDisengagedEngaged", idx_state_Disengaged, L"ec_Engage", idx_eqns_ec_EngageDisengagedEngaged, 1);
if (FAILED(hr)) hrRet = hr;
hr = AddTransition(L"ec_DisengageEngagedDisengaged", idx_state_Engaged, L"ec_Disengage", idx_eqns_ec_DisengageEngagedDisengaged, 1);
if (FAILED(hr)) hrRet = hr;
hr = AddTransition(L"ec_EngageWaitingEngaged", idx_state_Waiting, L"ec_Engage", idx_eqns_ec_EngageWaitingEngaged, 1);
if (FAILED(hr)) hrRet = hr;

return hrRet;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.23)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Actuator::InitStates()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

HRESULT hr;
HRESULT hrRet = S_OK;

// equation constants
const long idx_eqn_r_ShiftTime = 0;
const long idx_eqn_r_EngageProfile = 1;
const long idx_eqn_r_DisengageProfile = 2;
const long idx_eqn_s_ShiftTime = 3;
const long idx_eqn_r_WaitProfile = 4;

// state constants
const long idx_state_Disengaged = 0;
const long idx_state_Engaged = 1;
const long idx_state_Waiting = 2;

const long idx_eqns_Disengaged[] = { 
  idx_eqn_r_ShiftTime,
  idx_eqn_r_DisengageProfile,
 };
const long idx_eqns_Engaged[] = { 
  idx_eqn_r_ShiftTime,
  idx_eqn_r_EngageProfile,
 };
const long idx_eqns_Waiting[] = { 
  idx_eqn_r_ShiftTime,
  idx_eqn_r_WaitProfile,
 };

hr = AddState(L"Disengaged", 0, idx_eqns_Disengaged, 2);
if (FAILED(hr)) hrRet = hr;
hr = AddState(L"Engaged", 0, idx_eqns_Engaged, 2);
if (FAILED(hr)) hrRet = hr;
hr = AddState(L"Waiting", 1, idx_eqns_Waiting, 2);
if (FAILED(hr)) hrRet = hr;


return hrRet;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.24)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Actuator::OnTransition()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

HRESULT hr = S_OK;

const long idx_state_Disengaged = 0;
const long idx_state_Engaged = 1;
const long idx_state_Waiting = 2;

switch (RtsCurrent_Actuator)
{
  case RtsActuatorActuator_States_Disengaged:
    ATLTRACE("\nDisengaged");
    hr = PostTransition(idx_state_Disengaged);
    break;
  case RtsActuatorActuator_States_Engaged:
    ATLTRACE("\nEngaged");
    hr = PostTransition(idx_state_Engaged);
    break;
  case RtsActuatorActuator_States_Waiting:
    ATLTRACE("\nWaiting");
    hr = PostTransition(idx_state_Waiting);
    break;
}

return hr;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.25)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Actuator::ad_r_ShiftTime(Fdouble *res)  
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

//{{SCG_OP(0.26)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Actuator::ad_r_EngageProfile(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res=clutchConnector->ad_pressure-pressureMax*(1-2.0/(1.0+exp(rate*ad_shiftTime*ad_shiftTime)));
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.27)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Actuator::ad_r_DisengageProfile(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res=clutchConnector->ad_pressure - pressureMax * 
    (2.0/(1.0+exp(rate*ad_shiftTime*ad_shiftTime)));
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.28)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Actuator::ad_s_ShiftTime(Fdouble *res)  
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

//{{SCG_OP(0.29)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Actuator::ad_r_WaitProfile(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = clutchConnector->ad_pressure;
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.30)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Actuator::RtsEnter_Disengaged()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Disengaged */
    RtsNotify(1,"3fd88f93-6811-11d5-b152-00c04f680d9d",0,NULL);

    RtsCurrent_Actuator = RtsActuatorActuator_States_Disengaged;

    /* Entry Actions */
    OnTransition();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.31)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Actuator::RtsExit_Disengaged()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Actuator == RtsActuatorActuator_States_Disengaged)
    {
        /* Simulation support : Notification function call for exiting state : Disengaged */
        RtsNotify(2,"3fd88f93-6811-11d5-b152-00c04f680d9d",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.32)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Actuator::RtsEnter_Waiting()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Waiting */
    RtsNotify(1,"79b263bf-998e-11d5-b192-00c04f680d9d",0,NULL);

    RtsCurrent_Actuator = RtsActuatorActuator_States_Waiting;

    /* Entry Actions */
    OnTransition();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.33)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Actuator::RtsExit_Waiting()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Actuator == RtsActuatorActuator_States_Waiting)
    {
        /* Simulation support : Notification function call for exiting state : Waiting */
        RtsNotify(2,"79b263bf-998e-11d5-b192-00c04f680d9d",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.34)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Actuator::RtsEnter_Engaged()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Engaged */
    RtsNotify(1,"3fd88f91-6811-11d5-b152-00c04f680d9d",0,NULL);

    RtsCurrent_Actuator = RtsActuatorActuator_States_Engaged;

    /* Entry Actions */
    OnTransition();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.35)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Actuator::RtsExit_Engaged()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Actuator == RtsActuatorActuator_States_Engaged)
    {
        /* Simulation support : Notification function call for exiting state : Engaged */
        RtsNotify(2,"3fd88f91-6811-11d5-b152-00c04f680d9d",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.36)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

 Actuator::Actuator()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsRegisterStateMachine(this,RtsInjectEvent,RtsGetAttributeValue,RtsSetAttributeValue);
    RtsCreateSemaphore(RtsBusy);
    RtsLock(RtsBusy);

    /* Initialising State Vectors to NotIn */
    RtsCurrent_Actuator=RtsActuatorActuator_States_NotIn_Actuator;

    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.37)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

 Actuator::~Actuator()  
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

void Actuator::RtsRunToCompletion()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int EndOfLoop;
    for(EndOfLoop=0;EndOfLoop==0;)
    {
        EndOfLoop = 1;
        /* All completion transitions included here */
        if (RtsCurrent_Actuator == RtsActuatorActuator_States_NotIn_Actuator)
        {
            /* Simulation support : Notification function calls for transition */
            RtsNotify(3,"79b263c3-998e-11d5-b192-00c04f680d9d",0,NULL);

            init();
            RtsEnter_Waiting();

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
int Actuator::RtsInjectEvent(const char* Event, const int NumParams, const StringArray params, Actuator *pInstance)  
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
        if ((strcmp(Event, "ec_Engage") == 0) || (strcmp(Event, "Actuator.ec_Engage") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->ec_Engage();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "ec_Disengage") == 0) || (strcmp(Event, "Actuator.ec_Disengage") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->ec_Disengage();
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
int Actuator::RtsGetAttributeValue(const char* Name, char* Value, const int buflen, Actuator *pInstance)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int Ret;
    Ret = 1;
    if (strcmp(Name, "clutchConnector") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "shiftTime") == 0)
    {
        sprintf(Value,"%.8g",pInstance->shiftTime);
    }
    else if (strcmp(Name, "shiftPeriod") == 0)
    {
        sprintf(Value,"%.8g",pInstance->shiftPeriod);
    }
    else if (strcmp(Name, "rate") == 0)
    {
        sprintf(Value,"%.8g",pInstance->rate);
    }
    else if (strcmp(Name, "tolerance") == 0)
    {
        sprintf(Value,"%.8g",pInstance->tolerance);
    }
    else if (strcmp(Name, "pressureMax") == 0)
    {
        sprintf(Value,"%.8g",pInstance->pressureMax);
    }
    else if (strcmp(Name, "der_shiftTime") == 0)
    {
        sprintf(Value,"%.8g",pInstance->der_shiftTime);
    }
    else if (strcmp(Name, "old_shiftTime") == 0)
    {
        sprintf(Value,"%.8g",pInstance->old_shiftTime);
    }
    else if (strcmp(Name, "der_old_shiftTime") == 0)
    {
        sprintf(Value,"%.8g",pInstance->der_old_shiftTime);
    }
    else if (strcmp(Name, "ad_shiftTime") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_ad_shiftTime") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "RtsCurrent_Actuator") == 0)
    {
        switch(pInstance->RtsCurrent_Actuator)
        {
            case RtsActuatorActuator_States_Disengaged:
                strncpy(Value,"Disengaged",buflen);
                break;
            case RtsActuatorActuator_States_Waiting:
                strncpy(Value,"Waiting",buflen);
                break;
            case RtsActuatorActuator_States_Engaged:
                strncpy(Value,"Engaged",buflen);
                break;
            case RtsActuatorActuator_States_NotIn_Actuator:
                strncpy(Value,"NotIn_Actuator",buflen);
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
        strncpy(Value,"3fd88f70-6811-11d5-b152-00c04f680d9d", buflen);
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
int Actuator::RtsSetAttributeValue(const char* Name, const char* Value, Actuator *pInstance)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int Ret;
char *StopString;
    Ret = 1;
    if (strcmp(Name, "clutchConnector") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "shiftTime") == 0)
    {
        pInstance->shiftTime = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "shiftPeriod") == 0)
    {
        pInstance->shiftPeriod = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "rate") == 0)
    {
        pInstance->rate = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "tolerance") == 0)
    {
        pInstance->tolerance = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "pressureMax") == 0)
    {
        pInstance->pressureMax = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "der_shiftTime") == 0)
    {
        pInstance->der_shiftTime = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "old_shiftTime") == 0)
    {
        pInstance->old_shiftTime = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "der_old_shiftTime") == 0)
    {
        pInstance->der_old_shiftTime = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "ad_shiftTime") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_ad_shiftTime") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "RtsCurrent_Actuator") == 0)
    {
        if (strcmp(Value, "Disengaged") == 0 )
        {
            pInstance->RtsCurrent_Actuator = RtsActuatorActuator_States_Disengaged;
        }
        else if (strcmp(Value, "Waiting") == 0 )
        {
            pInstance->RtsCurrent_Actuator = RtsActuatorActuator_States_Waiting;
        }
        else if (strcmp(Value, "Engaged") == 0 )
        {
            pInstance->RtsCurrent_Actuator = RtsActuatorActuator_States_Engaged;
        }
        else if (strcmp(Value, "NotIn_Actuator") == 0 )
        {
            pInstance->RtsCurrent_Actuator = RtsActuatorActuator_States_NotIn_Actuator;
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


HRESULT Actuator::TriggerEvent(const double EventTime, const BSTR bstrEventId)
{
  CComBSTR name = bstrEventId;

  if (name == L"ec_Engage")
    ec_Engage();
  else if (name == L"ec_Disengage")
    ec_Disengage();

  return S_OK;
}


void Actuator::Save(FILE* fs)
{
  WRITE_SCALAR( RtsCurrent_Actuator )
}

bool Actuator::Load(FILE* fs)
{
  READ_SCALAR( RtsCurrent_Actuator )
  return true;
}




