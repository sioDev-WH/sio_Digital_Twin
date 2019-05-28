//{{SCG_IMPLEMENTATION(Engine.cpp) [0]

//{{SCG_INCLUDE  

// Cg_Add
#include "StdAfx.h" 
#include "RtsOnTransmission.h"
#include "RigidConnector.h"                   
#include "fstream.h"

                   
#include "Engine.h"
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
const static RtsClassInfo RtsEngine_ClassInfo("186e21fa-68a4-11d5-b153-00c04f680d9d", RTS_STM);
#endif
//}}SCG_CLASS_ID

//{{SCG_ICLASS_INFO(0)


//}}SCG_ICLASS_INFO
//{{SCG_ATTS(0)
//}}SCG_ATTS

//{{SCG_ROLES(0)
//}}SCG_ROLES

//{{SCG_OPS(0)

//{{SCG_OP(0.2)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Engine::init()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

  int i,j;
  long nThrottle,nRPM;
  double *Throttle_Data,*RPM_Data,**Torque_Data;

  BSTR path = NULL;
  CComBSTR filename;
  USES_CONVERSION;

  HRESULT hr = GetDataPath(&path);

  if (SUCCEEDED(hr))
  {
    filename.Attach(path);
    filename.Append(L"engineData.txt");
    ifstream eMap(W2CA(filename.m_str),ios::in|ios::nocreate);

   // Engine Data header
    eMap >> nThrottle;
    eMap >> nRPM;

    Throttle_Data=new double [nThrottle];
    RPM_Data=new double [nRPM];

	  Torque_Data=new double* [nThrottle];
    for(i=0;i<nThrottle;i++)
        Torque_Data[i] = new double[nRPM];

    for(i=0;i<nThrottle;i++)
    eMap >> Throttle_Data[i];
    for(i=0;i<nRPM;i++)
    eMap >> RPM_Data[i];
    for (i=0;i<nThrottle;i++) 
    for (j=0;j<nRPM;j++)
	    eMap >> Torque_Data[i][j];
    torqueMap.init_2D(nThrottle, nRPM, Throttle_Data,  RPM_Data,  (const double**) Torque_Data);
    eMap.close();
    delete Throttle_Data;
    delete RPM_Data;
    for(i=0;i<nThrottle;i++)
    delete Torque_Data[i];
    delete Torque_Data;

    inertia = 0.0220*2.0/3.0 * 60.0 / 3.1415; //See TC init();
    RPM = 0.0;
    DER(RPM) = 0.0;
    engineTorque = 0.0;
    DER(engineTorque) = 0.0;

    throttle = 0.0;
    engineThrottleLag = 0.2;

    n = new CRigidConnector();
    n->AddRef();
    n->torque = 0.0;
    n->acceleration = 0.0;
  }

  _ASSERTE(SUCCEEDED(hr));

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.1)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Engine::es_Stop()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsLock(RtsBusy);
    if (RtsCurrent_Engine == RtsEngineEngine_States_On)
    {
        RtsExit_On();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"7565fedb-4205-4c7d-b799-1619b5141a7c",0,NULL);

        RtsEnter_Off();
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

HRESULT Engine::r_StartupTorque(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  double lookupTorque = 0.0;
  torqueMap.interpolate_2D(100.0, 1000.0, &lookupTorque); 
  *res = DER(engineTorque) + engineThrottleLag * engineTorque - lookupTorque;
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.4)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Engine::z_OnRPM(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res = RPM - 1000.0;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.5)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Engine::r_OnTorque(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  double lookupTorque = 0.0;
  torqueMap.interpolate_2D(throttle, RPM, &lookupTorque); 
  *res = DER(engineTorque) + engineThrottleLag * engineTorque - engineThrottleLag * lookupTorque;

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.6)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Engine::es_Start()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsLock(RtsBusy);
    if (RtsCurrent_Engine == RtsEngineEngine_States_Off)
    {
        RtsExit_Off();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"409bb8cd-7c4a-495d-85c6-a0840169fc40",0,NULL);

        RtsEnter_Starting();
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

//{{SCG_OP(0.7)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Engine::es_On()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsLock(RtsBusy);
    if (RtsCurrent_Engine == RtsEngineEngine_States_Starting)
    {
        RtsExit_Starting();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"261abfe1-0d05-4e35-90bb-30aedb4ba4f9",0,NULL);

        RtsEnter_On();
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

//{{SCG_OP(0.8)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Engine::clean()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  if (m_pOnEnv)
  {
    m_pOnEnv->Release();
    m_pOnEnv = NULL;
  }

  n->Release();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.0)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Engine::r_RPM(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
#define PI 3.1415926535897932384626433832795
#define W_TO_RPM (60.0 / (2.0 * PI))
*res = DER(RPM) - W_TO_RPM * n->acceleration;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.10)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Engine::handle_inertia(const double t, const double* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

PostRealParameter(t, 1, *val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            


//{{SCG_OP(0.10)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Engine::handle_throttle(const double t, double* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

// ensure always have positive engine torque at 1000 RPM and below
*val += 6.5;
PostRealParameter(t, 0, *val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            


//{{SCG_OP(0.11)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Engine::InitEsos()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

  ADD_LOCAL_ESO(n)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.12)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Engine::InitLocalEqns()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

  ADD_LOCAL_EQN(Engine, r_OffTorque)
  ADD_LOCAL_EQN(Engine, r_StartupTorque)
  ADD_LOCAL_EQN(Engine, z_OnRPM)
  ADD_LOCAL_EQN(Engine, r_OnTorque)
  ADD_LOCAL_EQN(Engine, r_RPM)
  ADD_LOCAL_EQN(Engine, r_EngineDynamics)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.13)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Engine::InitLocalADEqns()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

  ADD_LOCAL_AD_EQN(Engine, ad_r_OffTorque)
  ADD_LOCAL_AD_EQN(Engine, ad_r_StartupTorque)
  ADD_LOCAL_AD_EQN(Engine, ad_z_OnRPM)
  ADD_LOCAL_AD_EQN(Engine, ad_r_OnTorque)
  ADD_LOCAL_AD_EQN(Engine, ad_r_RPM)
  ADD_LOCAL_AD_EQN(Engine, ad_r_EngineDynamics)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.14)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Engine::InitEqnForm(OnEqnForm* *form, OnEqnDiffForm* *diff_form)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


const long idx_eqn_r_OffTorque = 0;
const long idx_eqn_r_StartupTorque = 1;
const long idx_eqn_z_OnRPM = 2;
const long idx_eqn_r_OnTorque = 3;
const long idx_eqn_r_RPM = 4;
const long idx_eqn_r_EngineDynamics = 5;

  DESTROY_VECTOR(*form)
  *form = new OnEqnForm[m_nLocalEqns];
  (*form)[idx_eqn_r_OffTorque] = continuous;
  (*form)[idx_eqn_r_StartupTorque] = continuous;
  (*form)[idx_eqn_z_OnRPM] = discontinuous;
  (*form)[idx_eqn_r_OnTorque] = continuous;
  (*form)[idx_eqn_r_RPM] = continuous;
  (*form)[idx_eqn_r_EngineDynamics] = continuous;

  DESTROY_VECTOR(*diff_form)
  *diff_form = new OnEqnDiffForm[m_nLocalEqns];
  (*diff_form)[idx_eqn_r_OffTorque] = automatic;
  (*diff_form)[idx_eqn_r_StartupTorque] = numeric;
  (*diff_form)[idx_eqn_z_OnRPM] = automatic;
  (*diff_form)[idx_eqn_r_OnTorque] = numeric;
  (*diff_form)[idx_eqn_r_RPM] = automatic;
  (*diff_form)[idx_eqn_r_EngineDynamics] = automatic;

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.15)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Engine::InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


  ADD_LOCAL_SVAR(RPM)
  ADD_LOCAL_SVAR(engineTorque)

for (long i = 0; i < m_nEsos; i++)
  AddLocalVar(m_Esos[i], NULL, NULL, varC, true);

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.16)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Engine::InitLocalRPars(const _TCHAR* prefix, ppdouble *pars, ppchar *Names, long *nPars, long *dPars)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


  ADD_LOCAL_SRPAR(throttle)
  ADD_LOCAL_SRPAR(inertia)
  ADD_LOCAL_SRPAR(engineThrottleLag)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.17)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Engine::InitTransitions()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

HRESULT hr;
HRESULT hrRet = S_OK;


// equation constants
const long idx_eqn_r_OffTorque = 0;
const long idx_eqn_r_StartupTorque = 1;
const long idx_eqn_z_OnRPM = 2;
const long idx_eqn_r_OnTorque = 3;
const long idx_eqn_r_RPM = 4;

// state constants
const long idx_state_Off = 0;
const long idx_state_On = 1;
const long idx_state_Starting = 2;

const long* idx_eqns_es_StartOffStarting = NULL;
const long* idx_eqns_es_StopOnOff = NULL;

const long idx_eqns_es_OnStartingOn[] = 
{ 
  idx_eqn_z_OnRPM,
};

// Transition_Name, Source_State, Event_Name, Transition_Eqns, Eqn_Count
hr = AddTransition(L"es_StartOffStarting", idx_state_Off, L"es_Start", idx_eqns_es_StartOffStarting, 0);
if (FAILED(hr)) hrRet = hr;
hr = AddTransition(L"es_StopOnOff", idx_state_On, L"es_Stop", idx_eqns_es_StopOnOff, 0);
if (FAILED(hr)) hrRet = hr;
hr = AddTransition(L"es_OnStartingOn", idx_state_Starting, L"es_On", idx_eqns_es_OnStartingOn, 1);
if (FAILED(hr)) hrRet = hr;

return hrRet;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.18)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Engine::InitStates()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

HRESULT hr;
HRESULT hrRet = S_OK;

// equation constants
const long idx_eqn_r_OffTorque = 0;
const long idx_eqn_r_StartupTorque = 1;
const long idx_eqn_z_OnRPM = 2;
const long idx_eqn_r_OnTorque = 3;
const long idx_eqn_r_RPM = 4;
const long idx_eqn_r_EngineDynamics = 5;

// state constants
const long idx_state_Off = 0;
const long idx_state_On = 1;
const long idx_state_Starting = 2;

const long idx_eqns_Off[] = { 
  idx_eqn_r_OffTorque,
  idx_eqn_r_RPM,
  idx_eqn_r_EngineDynamics,
 };
const long idx_eqns_On[] = { 
  idx_eqn_r_OnTorque,
  idx_eqn_r_RPM,
  idx_eqn_r_EngineDynamics,
 };
const long idx_eqns_Starting[] = { 
  idx_eqn_r_StartupTorque,
  idx_eqn_r_RPM,
  idx_eqn_r_EngineDynamics,
 };

hr = AddState(L"Off", 1, idx_eqns_Off, 3);
if (FAILED(hr)) hrRet = hr;
hr = AddState(L"On", 0, idx_eqns_On, 3);
if (FAILED(hr)) hrRet = hr;
hr = AddState(L"Starting", 0, idx_eqns_Starting, 3);
if (FAILED(hr)) hrRet = hr;


return hrRet;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.19)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Engine::OnTransition()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

HRESULT hr = S_OK;

const long idx_state_Off = 0;
const long idx_state_On = 1;
const long idx_state_Starting = 2;
switch (RtsCurrent_Engine)
{
  case RtsEngineEngine_States_Off:
    ATLTRACE("\nOff");
    PostTransition(idx_state_Off);
    break;
  case RtsEngineEngine_States_On:
    ATLTRACE("\nOn");
    PostTransition(idx_state_On);
    break;
  case RtsEngineEngine_States_Starting:
    ATLTRACE("\nStarting");
    PostTransition(idx_state_Starting);
    break;
}

return hr;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.20)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Engine::ad_r_OffTorque(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res = DER(ad_engineTorque) + ad_engineTorque;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.21)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Engine::ad_r_StartupTorque(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
return S_OK; // placeholder

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.22)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Engine::ad_z_OnRPM(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res = ad_RPM - 1000.0;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.23)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Engine::ad_r_OnTorque(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
return S_OK; // placeholder

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.24)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Engine::ad_r_RPM(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
#define PI 3.1415926535897932384626433832795
#define W_TO_ad_RPM 60.0 / 2 * PI
*res = DER(ad_RPM) - W_TO_ad_RPM * n->ad_acceleration;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.25)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Engine::RtsEnter_Starting()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Starting */
    RtsNotify(1,"79b263d7-998e-11d5-b192-00c04f680d9d",0,NULL);

    RtsCurrent_Engine = RtsEngineEngine_States_Starting;

    /* Entry Actions */
    OnTransition();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.26)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Engine::RtsExit_Starting()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Engine == RtsEngineEngine_States_Starting)
    {
        /* Simulation support : Notification function call for exiting state : Starting */
        RtsNotify(2,"79b263d7-998e-11d5-b192-00c04f680d9d",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.27)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Engine::RtsEnter_On()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : On */
    RtsNotify(1,"79b263d9-998e-11d5-b192-00c04f680d9d",0,NULL);

    RtsCurrent_Engine = RtsEngineEngine_States_On;

    /* Entry Actions */
    OnTransition();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.28)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Engine::RtsExit_On()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Engine == RtsEngineEngine_States_On)
    {
        /* Simulation support : Notification function call for exiting state : On */
        RtsNotify(2,"79b263d9-998e-11d5-b192-00c04f680d9d",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.29)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Engine::RtsEnter_Off()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Off */
    RtsNotify(1,"79b263d5-998e-11d5-b192-00c04f680d9d",0,NULL);

    RtsCurrent_Engine = RtsEngineEngine_States_Off;

    /* Entry Actions */
    OnTransition();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.30)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Engine::RtsExit_Off()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Engine == RtsEngineEngine_States_Off)
    {
        /* Simulation support : Notification function call for exiting state : Off */
        RtsNotify(2,"79b263d5-998e-11d5-b192-00c04f680d9d",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.31)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

 Engine::Engine()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    m_pOnEnv = NULL;

    RtsRegisterStateMachine(this,RtsInjectEvent,RtsGetAttributeValue,RtsSetAttributeValue);
    RtsCreateSemaphore(RtsBusy);
    RtsLock(RtsBusy);

    /* Initialising State Vectors to NotIn */
    RtsCurrent_Engine=RtsEngineEngine_States_NotIn_Engine;

    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.32)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

 Engine::~Engine()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsUnregister(this);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.33)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Engine::RtsRunToCompletion()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int EndOfLoop;
    for(EndOfLoop=0;EndOfLoop==0;)
    {
        EndOfLoop = 1;
        /* All completion transitions included here */
        if (RtsCurrent_Engine == RtsEngineEngine_States_NotIn_Engine)
        {
            /* Simulation support : Notification function calls for transition */
            RtsNotify(3,"50ee1e94-d09d-4580-b1b2-c3c79b9a924b",0,NULL);

            init();
            RtsEnter_Off();

            EndOfLoop = 0;
        }
    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.34)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

#ifdef RTS_SIMULATION
int Engine::RtsInjectEvent(const char* Event, const int NumParams, const StringArray params, Engine *pInstance)  
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
        if ((strcmp(Event, "es_On") == 0) || (strcmp(Event, "Engine.es_On") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->es_On();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "es_Stop") == 0) || (strcmp(Event, "Engine.es_Stop") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->es_Stop();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "es_Start") == 0) || (strcmp(Event, "Engine.es_Start") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->es_Start();
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

//{{SCG_OP(0.35)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

#ifdef RTS_SIMULATION
int Engine::RtsGetAttributeValue(const char* Name, char* Value, const int buflen, Engine *pInstance)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int Ret;
    Ret = 1;
    if (strcmp(Name, "n") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "RPM") == 0)
    {
        sprintf(Value,"%.8g",pInstance->RPM);
    }
    else if (strcmp(Name, "throttle") == 0)
    {
        sprintf(Value,"%.8g",pInstance->throttle);
    }
    else if (strcmp(Name, "torqueMap") == 0)
    {
        /* torqueMap is a complex type ( Class ) */
        Ret = 0;
    }
    else if (strcmp(Name, "inertia") == 0)
    {
        sprintf(Value,"%.8g",pInstance->inertia);
    }
    else if (strcmp(Name, "der_RPM") == 0)
    {
        sprintf(Value,"%.8g",pInstance->der_RPM);
    }
    else if (strcmp(Name, "old_RPM") == 0)
    {
        sprintf(Value,"%.8g",pInstance->old_RPM);
    }
    else if (strcmp(Name, "der_old_RPM") == 0)
    {
        sprintf(Value,"%.8g",pInstance->der_old_RPM);
    }
    else if (strcmp(Name, "ad_RPM") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_ad_RPM") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "RtsCurrent_Engine") == 0)
    {
        switch(pInstance->RtsCurrent_Engine)
        {
            case RtsEngineEngine_States_Starting:
                strncpy(Value,"Starting",buflen);
                break;
            case RtsEngineEngine_States_On:
                strncpy(Value,"On",buflen);
                break;
            case RtsEngineEngine_States_Off:
                strncpy(Value,"Off",buflen);
                break;
            case RtsEngineEngine_States_NotIn_Engine:
                strncpy(Value,"NotIn_Engine",buflen);
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
        strncpy(Value,"186e21fa-68a4-11d5-b153-00c04f680d9d", buflen);
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

//{{SCG_OP(0.36)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

#ifdef RTS_SIMULATION
int Engine::RtsSetAttributeValue(const char* Name, const char* Value, Engine *pInstance)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int Ret;
char *StopString;
    Ret = 1;
    if (strcmp(Name, "n") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "RPM") == 0)
    {
        pInstance->RPM = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "throttle") == 0)
    {
        pInstance->throttle = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "torqueMap") == 0)
    {
        Ret = 0;
    }
    else if (strcmp(Name, "inertia") == 0)
    {
        pInstance->inertia = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "der_RPM") == 0)
    {
        pInstance->der_RPM = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "old_RPM") == 0)
    {
        pInstance->old_RPM = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "der_old_RPM") == 0)
    {
        pInstance->der_old_RPM = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "ad_RPM") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_ad_RPM") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "RtsCurrent_Engine") == 0)
    {
        if (strcmp(Value, "Starting") == 0 )
        {
            pInstance->RtsCurrent_Engine = RtsEngineEngine_States_Starting;
        }
        else if (strcmp(Value, "On") == 0 )
        {
            pInstance->RtsCurrent_Engine = RtsEngineEngine_States_On;
        }
        else if (strcmp(Value, "Off") == 0 )
        {
            pInstance->RtsCurrent_Engine = RtsEngineEngine_States_Off;
        }
        else if (strcmp(Value, "NotIn_Engine") == 0 )
        {
            pInstance->RtsCurrent_Engine = RtsEngineEngine_States_NotIn_Engine;
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

//{{SCG_OP(0.2)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Engine::r_OffTorque(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res = DER(engineTorque) + engineTorque;

return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            
//}}SCG_OPS

//}}SCG_IMPLEMENTATION


HRESULT Engine::EvalStateCondition(
  const bool* EqnState, 
  const double* x, 
  const double* xdot, 
  const double EventTime, 
  const long iDisEqn, 
  const long iTransition, 
  bool* bEvent)
{
  const long idx_state_Off = 0;
  const long idx_state_On = 1;
  const long idx_state_Starting = 2;

  const long idx_transition_OffStarting = 0;
  const long idx_transition_OnOff = 1;
  const long idx_transition_StartingOn = 2;

  const long idx_eqn_z_OnRPM = 2;

  long currentState;

  if (RtsCurrent_Engine == RtsEngineEngine_States_Off)
    currentState = idx_state_Off;
  else if (RtsCurrent_Engine == RtsEngineEngine_States_On)
    currentState = idx_state_On;
  else if (RtsCurrent_Engine == RtsEngineEngine_States_Starting)
    currentState = idx_state_Starting;

  switch (currentState)
  {
    case idx_state_Starting:
      if (iTransition == idx_transition_StartingOn)
      {
        *bEvent = EqnState[idx_eqn_z_OnRPM];
      }
      break;

  }


  return S_OK;
}


HRESULT Engine::TriggerEvent(const double EventTime, const BSTR bstrEventId)
{
  CComBSTR name = bstrEventId;

  if (name == L"es_Start")
    es_Start();
  else if (name == L"es_Stop")
    es_Stop();
  else if (name == L"es_On")
    es_On();

  return S_OK;
}


void Engine::handle_Start(const double t, long *val)
{
  if (*val == 1)
    PostStateEvent(t, L"es_Start");
  else
    PostStateEvent(t, L"es_Stop");
}


HRESULT Engine::r_EngineDynamics(double *res)  
{
  *res = engineTorque - inertia * n->acceleration + n->torque;
  return S_OK;
}


HRESULT Engine::ad_r_EngineDynamics(Fdouble *res)  
{
  *res = ad_engineTorque - inertia * n->ad_acceleration + n->ad_torque;
  return S_OK;
}

void Engine::Save(FILE* fs)
{
  WRITE_SCALAR( RtsCurrent_Engine )
}

bool Engine::Load(FILE* fs)
{
  READ_SCALAR( RtsCurrent_Engine )
  return true;
}
