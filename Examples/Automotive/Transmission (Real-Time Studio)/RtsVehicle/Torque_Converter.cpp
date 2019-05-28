//{{SCG_IMPLEMENTATION(Torque_Converter.cpp) [0]

//{{SCG_INCLUDE   
#include "StdAfx.h" 
#include "RigidConnector.h"
#include "math.h"
                  
#include "Torque_Converter.h"
// Include for Template Class should go here.
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
//}}SCG_INCLUDE
                      
//{{SCG_CLASS_ID
#ifdef RTS_SIMULATION
const static RtsClassInfo RtsTorque_Converter_ClassInfo("345817f8-6969-11d5-b154-00c04f680d9d", RTS_STM);
#endif
//}}SCG_CLASS_ID

//{{SCG_ICLASS_INFO(0)


//}}SCG_ICLASS_INFO
//{{SCG_ATTS(0)
//}}SCG_ATTS

//{{SCG_ROLES(0)
//}}SCG_ROLES

//{{SCG_OPS(0)

//{{SCG_OP(0.4)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::r_TMM_ImpellerTorque(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = impellerTorque - 
    ( c[1] * impellerSpeed * impellerSpeed + 
      c[2] * impellerSpeed * turbineSpeed + 
      c[3] * turbineSpeed * turbineSpeed);

return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.5)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::r_TMM_TurbineTorque(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = turbineTorque - 
    ( c[4] * impellerSpeed * impellerSpeed + 
      c[5] * impellerSpeed * turbineSpeed + 
      c[6] * turbineSpeed * turbineSpeed);


return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.6)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::r_FCM_ImpellerTorque(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = impellerTorque - 
    ( c[7] * impellerSpeed * impellerSpeed + 
      c[8] * impellerSpeed * turbineSpeed + 
      c[9] * turbineSpeed * turbineSpeed);


return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.7)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::r_FCM_TurbineTorque(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = turbineTorque - impellerTorque;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.9)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Torque_Converter::es_TMM()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsLock(RtsBusy);
    if (RtsCurrent_Torque_Converter == RtsTorque_ConverterTorque_Converter_States_Fluid_Coupling)
    {
        RtsExit_Fluid_Coupling();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"9f17f701-6978-11d5-b154-00c04f680d9d",0,NULL);

        RtsEnter_Torque_Multiplication();
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

void Torque_Converter::es_FCM()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsLock(RtsBusy);
    if (RtsCurrent_Torque_Converter == RtsTorque_ConverterTorque_Converter_States_Locked)
    {
        RtsExit_Locked();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"69360587-54b4-4237-b579-cf88c88e0337",0,NULL);

        RtsEnter_Fluid_Coupling();
    }
    else if (RtsCurrent_Torque_Converter == RtsTorque_ConverterTorque_Converter_States_Torque_Multiplication)
    {
        RtsExit_Torque_Multiplication();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"9f17f706-6978-11d5-b154-00c04f680d9d",0,NULL);

        RtsEnter_Fluid_Coupling();
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

//{{SCG_OP(0.11)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::z_TorqueRatio_gt_one(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  double speedRatio;

  if(fabs(impellerSpeed) > 1e-10)
    speedRatio = turbineSpeed / impellerSpeed;
  else
    speedRatio = turbineSpeed / (impellerSpeed + 1e-10);

  *res = 0.9 - speedRatio;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.12)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Torque_Converter::init()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    long i;

  // equation format:
  //   torque = c[n] * wp^2 + c[n+1] * wp * wt + c[n+2] * wt^2
  //   where wp = impeller or pump speed
  //   and   wt = turbine speed


  const double torque_constants[] = 
  { 0,                                      // unused
    3.4325e-3, 2.2210e-3, -4.6041e-3,       // impellerTorque in TMM
    5.7656e-3, 0.3107e-3, -5.4323e-3,       // turbineTorque in TMM
    -6.65776e-3, 32.0084e-3, -25.2441e-3,   // impellerTorque and turbineTorque in FCM
  };
  
  for (i = 0; i < 10; i++) c[i] = torque_constants[i];

  impeller = new CRigidConnector();
  turbine = new CRigidConnector();
  impeller->AddRef();
  turbine->AddRef();  

// variable initial values
  impellerSpeed = 0.0;
  DER(impellerSpeed) = 0.0;
  impellerTorque = 0.0;
  DER(impellerTorque) = 0.0;

  turbineSpeed = 0.0;
  DER(turbineSpeed) = 0.0;
  turbineTorque = 0.0;
  DER(turbineTorque) = 0.0;

  // parameter initial values
  impellerInertia = (0.0220 / 3.0) * 60.0 / 3.1415;
  turbineInertia = impellerInertia * 0.85;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.0)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::r_ImpellerSpeed(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
#define PI 3.1415926535897932384626433832795
#define W_TO_RPM (60.0 / (2 * PI))

  //*res = DER(impellerSpeed) - W_TO_RPM * impeller->acceleration;
  *res = DER(impellerSpeed) - impeller->acceleration;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.1)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::r_ImpellerNewton(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = impeller->torque - impellerInertia * impeller->acceleration - impellerTorque;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.2)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::r_TurbineSpeed(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
#define PI 3.1415926535897932384626433832795
#define W_TO_RPM (60.0 / (2 * PI))

  *res = DER(turbineSpeed) - turbine->acceleration;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.3)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::r_TurbineNewton(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = turbineTorque - turbineInertia * turbine->acceleration + turbine->torque ;
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.12)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Torque_Converter::clean()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  impeller->Release();
  turbine->Release();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.13)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::z_TorqueRatio_lt_one(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  double speedRatio;

  if(fabs(impellerSpeed) > 1e-10)
    speedRatio = turbineSpeed / impellerSpeed;
  else
    speedRatio = turbineSpeed / (impellerSpeed + 1e-10);

  *res = speedRatio - 0.9;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.36)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::ad_z_TorqueRatio_lt_one(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  Fdouble ad_speedRatio;

  if(fabs(impellerSpeed) > 1e-10)
    ad_speedRatio = ad_turbineSpeed / ad_impellerSpeed;
  else
    ad_speedRatio = ad_turbineSpeed / (ad_impellerSpeed + 1e-10);

  *res = ad_speedRatio - 0.90;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.14)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Torque_Converter::handle_turbineInertia(const double t, double *val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

PostRealParameter(t, 0, *val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.15)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Torque_Converter::handle_impellerInertia(const double t, double *val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

PostRealParameter(t, 1, *val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.16)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::InitEsos()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

  ADD_LOCAL_ESO(turbine)
  ADD_LOCAL_ESO(impeller)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.17)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::InitLocalEqns()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  ADD_LOCAL_EQN(Torque_Converter, r_TMM_ImpellerTorque)
  ADD_LOCAL_EQN(Torque_Converter, r_TMM_TurbineTorque)
  ADD_LOCAL_EQN(Torque_Converter, r_FCM_ImpellerTorque)
  ADD_LOCAL_EQN(Torque_Converter, r_FCM_TurbineTorque)
  ADD_LOCAL_EQN(Torque_Converter, z_TorqueRatio_gt_one)
  ADD_LOCAL_EQN(Torque_Converter, r_ImpellerSpeed)
  ADD_LOCAL_EQN(Torque_Converter, r_ImpellerNewton)
  ADD_LOCAL_EQN(Torque_Converter, r_TurbineSpeed)
  ADD_LOCAL_EQN(Torque_Converter, r_TurbineNewton)
  ADD_LOCAL_EQN(Torque_Converter, z_TorqueRatio_lt_one)

  ADD_LOCAL_EQN(Torque_Converter, r_SpeedLocked)
  ADD_LOCAL_EQN(Torque_Converter, z_Speed_gt_LockedSpeed)
  ADD_LOCAL_EQN(Torque_Converter, z_Speed_lt_LockedSpeed)
  ADD_LOCAL_EQN(Torque_Converter, z_ImpellerTorque_lt_TurbineTorque)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.18)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::InitLocalADEqns()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  ADD_LOCAL_AD_EQN(Torque_Converter, ad_r_TMM_ImpellerTorque)
  ADD_LOCAL_AD_EQN(Torque_Converter, ad_r_TMM_TurbineTorque)
  ADD_LOCAL_AD_EQN(Torque_Converter, ad_r_FCM_ImpellerTorque)
  ADD_LOCAL_AD_EQN(Torque_Converter, ad_r_FCM_TurbineTorque)
  ADD_LOCAL_AD_EQN(Torque_Converter, ad_z_TorqueRatio_gt_one)
  ADD_LOCAL_AD_EQN(Torque_Converter, ad_r_ImpellerSpeed)
  ADD_LOCAL_AD_EQN(Torque_Converter, ad_r_ImpellerNewton)
  ADD_LOCAL_AD_EQN(Torque_Converter, ad_r_TurbineSpeed)
  ADD_LOCAL_AD_EQN(Torque_Converter, ad_r_TurbineNewton)
  ADD_LOCAL_AD_EQN(Torque_Converter, ad_z_TorqueRatio_lt_one)

  ADD_LOCAL_AD_EQN(Torque_Converter, ad_r_SpeedLocked)
  ADD_LOCAL_AD_EQN(Torque_Converter, ad_z_Speed_gt_LockedSpeed)
  ADD_LOCAL_AD_EQN(Torque_Converter, ad_z_Speed_lt_LockedSpeed)
  ADD_LOCAL_AD_EQN(Torque_Converter, ad_z_ImpellerTorque_lt_TurbineTorque)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.19)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::InitEqnForm(OnEqnForm* *form, OnEqnDiffForm* *diff_form)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
const long idx_eqn_r_TMM_ImpellerTorque = 0;
const long idx_eqn_r_TMM_TurbineTorque = 1;
const long idx_eqn_r_FCM_ImpellerTorque = 2;
const long idx_eqn_r_FCM_TurbineTorque = 3;
const long idx_eqn_z_TorqueRatio_gt_one = 4;
const long idx_eqn_r_ImpellerSpeed = 5;
const long idx_eqn_r_ImpellerNewton = 6;
const long idx_eqn_r_TurbineSpeed = 7;
const long idx_eqn_r_TurbineNewton = 8;
const long idx_eqn_z_TorqueRatio_lt_one = 9;

const long idx_eqn_r_SpeedLocked = 10;
const long idx_eqn_z_Speed_gt_LockedSpeed = 11;
const long idx_eqn_z_Speed_lt_LockedSpeed = 12;
const long idx_eqn_z_ImpellerTorque_lt_TurbineTorque = 13;

  DESTROY_VECTOR(*form)
  *form = new OnEqnForm[m_nLocalEqns];
  (*form)[idx_eqn_r_TMM_ImpellerTorque] = continuous;
  (*form)[idx_eqn_r_TMM_TurbineTorque] = continuous;
  (*form)[idx_eqn_r_FCM_ImpellerTorque] = continuous;
  (*form)[idx_eqn_r_FCM_TurbineTorque] = continuous;
  (*form)[idx_eqn_z_TorqueRatio_gt_one] = discontinuous;
  (*form)[idx_eqn_r_ImpellerSpeed] = continuous;
  (*form)[idx_eqn_r_ImpellerNewton] = continuous;
  (*form)[idx_eqn_r_TurbineSpeed] = continuous;
  (*form)[idx_eqn_r_TurbineNewton] = continuous;
  (*form)[idx_eqn_z_TorqueRatio_lt_one] = discontinuous;

  (*form)[idx_eqn_r_SpeedLocked] = continuous;
  (*form)[idx_eqn_z_Speed_gt_LockedSpeed] = discontinuous;
  (*form)[idx_eqn_z_Speed_lt_LockedSpeed] = discontinuous;
  (*form)[idx_eqn_z_ImpellerTorque_lt_TurbineTorque] = discontinuous;
 

  DESTROY_VECTOR(*diff_form)
  *diff_form = new OnEqnDiffForm[m_nLocalEqns];
  (*diff_form)[idx_eqn_r_TMM_ImpellerTorque] = automatic;
  (*diff_form)[idx_eqn_r_TMM_TurbineTorque] = automatic;
  (*diff_form)[idx_eqn_r_FCM_ImpellerTorque] = automatic;
  (*diff_form)[idx_eqn_r_FCM_TurbineTorque] = automatic;
  (*diff_form)[idx_eqn_z_TorqueRatio_gt_one] = automatic;
  (*diff_form)[idx_eqn_r_ImpellerSpeed] = automatic;
  (*diff_form)[idx_eqn_r_ImpellerNewton] = automatic;
  (*diff_form)[idx_eqn_r_TurbineSpeed] = automatic;
  (*diff_form)[idx_eqn_r_TurbineNewton] = automatic;
  (*diff_form)[idx_eqn_z_TorqueRatio_lt_one] = automatic;

  (*diff_form)[idx_eqn_r_SpeedLocked] = automatic;
  (*diff_form)[idx_eqn_z_Speed_gt_LockedSpeed] = automatic;
  (*diff_form)[idx_eqn_z_Speed_lt_LockedSpeed] = automatic;
  (*diff_form)[idx_eqn_z_ImpellerTorque_lt_TurbineTorque] = automatic;

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.20)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


  ADD_LOCAL_SVAR(turbineTorque)
  ADD_LOCAL_SVAR(turbineSpeed)
  ADD_LOCAL_SVAR(impellerTorque)
  ADD_LOCAL_SVAR(impellerSpeed)

for (long i = 0; i < m_nEsos; i++)
  AddLocalVar(m_Esos[i], NULL, NULL, varC, true);

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.21)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::InitLocalRPars(const _TCHAR* prefix, ppdouble *pars, ppchar *Names, long *nPars, long *dPars)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


  ADD_LOCAL_SRPAR(turbineInertia)
  ADD_LOCAL_SRPAR(impellerInertia)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.22)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::InitTransitions()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
HRESULT hr;
HRESULT hrRet = S_OK;


// equation constants
const long idx_eqn_r_TMM_ImpellerTorque = 0;
const long idx_eqn_r_TMM_TurbineTorque = 1;
const long idx_eqn_r_FCM_ImpellerTorque = 2;
const long idx_eqn_r_FCM_TurbineTorque = 3;
const long idx_eqn_z_TorqueRatio_gt_one = 4;
const long idx_eqn_r_ImpellerSpeed = 5;
const long idx_eqn_r_ImpellerNewton = 6;
const long idx_eqn_r_TurbineSpeed = 7;
const long idx_eqn_r_TurbineNewton = 8;
const long idx_eqn_z_TorqueRatio_lt_one = 9;

const long idx_eqn_r_SpeedLocked = 10;
const long idx_eqn_z_Speed_gt_LockedSpeed = 11;
const long idx_eqn_z_Speed_lt_LockedSpeed = 12;
const long idx_eqn_z_ImpellerTorque_lt_TurbineTorque = 13;

// state constants
const long idx_state_Fluid_Coupling = 0;
const long idx_state_Torque_Multiplication = 1;
const long idx_state_Locked = 2;

const long idx_eqns_es_TMMFluidCouplingTorqueMultiplication[] = { 
  idx_eqn_z_TorqueRatio_gt_one,
 };
const long idx_eqns_es_FCMTorqueMultiplicationFluidCoupling[] = { 
  idx_eqn_z_TorqueRatio_lt_one,
 };
const long idx_eqns_es_LockFluidCouplingLocked[] = { 
  idx_eqn_z_Speed_gt_LockedSpeed,
 };
const long idx_eqns_es_FCMLockedFluidCoupling[] = { 
  idx_eqn_z_Speed_lt_LockedSpeed,
  idx_eqn_z_ImpellerTorque_lt_TurbineTorque,
 };

// Transition_Name, Source_State, Event_Name, Transition_Eqns, Eqn_Count
hr = AddTransition(L"es_TMMFluidCouplingTorqueMultiplication", idx_state_Fluid_Coupling, L"es_TMM", idx_eqns_es_TMMFluidCouplingTorqueMultiplication, 1);
if (FAILED(hr)) hrRet = hr;
hr = AddTransition(L"es_FCMTorqueMultiplicationFluidCoupling", idx_state_Torque_Multiplication, L"es_FCM", idx_eqns_es_FCMTorqueMultiplicationFluidCoupling, 1);
if (FAILED(hr)) hrRet = hr;
hr = AddTransition(L"es_LockFluidCouplingLocked", idx_state_Fluid_Coupling, L"es_Lock", idx_eqns_es_LockFluidCouplingLocked, 1);
if (FAILED(hr)) hrRet = hr;
hr = AddTransition(L"es_FCMLockedFluidCoupling", idx_state_Locked, L"es_FCM", idx_eqns_es_FCMLockedFluidCoupling, 2);
if (FAILED(hr)) hrRet = hr;

return hrRet;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.23)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::InitStates()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
HRESULT hr;
HRESULT hrRet = S_OK;

// equation constants
const long idx_eqn_r_TMM_ImpellerTorque = 0;
const long idx_eqn_r_TMM_TurbineTorque = 1;
const long idx_eqn_r_FCM_ImpellerTorque = 2;
const long idx_eqn_r_FCM_TurbineTorque = 3;
const long idx_eqn_z_TorqueRatio_gt_one = 4;
const long idx_eqn_r_ImpellerSpeed = 5;
const long idx_eqn_r_ImpellerNewton = 6;
const long idx_eqn_r_TurbineSpeed = 7;
const long idx_eqn_r_TurbineNewton = 8;
const long idx_eqn_z_TorqueRatio_lt_one = 9;

const long idx_eqn_r_SpeedLocked = 10;
const long idx_eqn_z_Speed_gt_LockedSpeed = 11;
const long idx_eqn_z_Speed_lt_LockedSpeed = 12;

// state constants
const long idx_state_Fluid_Coupling = 0;
const long idx_state_Torque_Multiplication = 1;
const long idx_state_Locked = 2;

const long idx_eqns_Fluid_Coupling[] = { 
  idx_eqn_r_FCM_ImpellerTorque,
  idx_eqn_r_FCM_TurbineTorque,
  idx_eqn_r_ImpellerSpeed,
  idx_eqn_r_ImpellerNewton,
  idx_eqn_r_TurbineSpeed,
  idx_eqn_r_TurbineNewton,
 };
const long idx_eqns_Torque_Multiplication[] = { 
  idx_eqn_r_TMM_ImpellerTorque,
  idx_eqn_r_TMM_TurbineTorque,
  idx_eqn_r_ImpellerSpeed,
  idx_eqn_r_ImpellerNewton,
  idx_eqn_r_TurbineSpeed,
  idx_eqn_r_TurbineNewton,
 };

const long idx_eqns_Locked[] = { 
  idx_eqn_r_SpeedLocked,          // impeller->acceleration = turbine->acceleration
  idx_eqn_r_FCM_TurbineTorque,    // impellerTorque = turbineTorque
  idx_eqn_r_ImpellerSpeed,
  idx_eqn_r_ImpellerNewton,
  idx_eqn_r_TurbineSpeed,
  idx_eqn_r_TurbineNewton,
 };

hr = AddState(L"Fluid Coupling", 0, idx_eqns_Fluid_Coupling, 6);
if (FAILED(hr)) hrRet = hr;
hr = AddState(L"Torque Multiplication", 1, idx_eqns_Torque_Multiplication, 6);
if (FAILED(hr)) hrRet = hr;
hr = AddState(L"Locked", 0, idx_eqns_Locked, 6);
if (FAILED(hr)) hrRet = hr;

return hrRet;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.24)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::OnTransition()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
HRESULT hr = S_OK;

const long idx_state_Fluid_Coupling = 0;
const long idx_state_Torque_Multiplication = 1;
const long idx_state_Locked = 2;

switch (RtsCurrent_Torque_Converter)
{
  case RtsTorque_ConverterTorque_Converter_States_Fluid_Coupling:
    ATLTRACE("\nFluid_Coupling");
    PostTransition(idx_state_Fluid_Coupling);
    break;
  case RtsTorque_ConverterTorque_Converter_States_Torque_Multiplication:
    ATLTRACE("\nTorque_Multiplication");
    PostTransition(idx_state_Torque_Multiplication);
    break;
  case RtsTorque_ConverterTorque_Converter_States_Locked:
    ATLTRACE("\nLocked");
    PostTransition(idx_state_Locked);
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

HRESULT Torque_Converter::TriggerEvent(const double EventTime, const BSTR bstrEventId)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
USES_CONVERSION;

CComBSTR EventId = bstrEventId;
HRESULT hr = S_OK;

if (EventId == L"es_TMM")
  es_TMM();
else if (EventId == L"es_FCM")
  es_FCM();
else if (EventId == L"es_Lock")
  es_Lock();

m_time = EventTime;

// update old variables
old_turbineTorque = turbineTorque;
old_turbineSpeed = turbineSpeed;
old_impellerTorque = impellerTorque;
old_impellerSpeed = impellerSpeed;

return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.26)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::EvalStateCondition(const bool* EqnState, const double* x, const double* xdot, const double EventTime, const long iDisEqn, const long iTransition, bool *bEvent)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
const long idx_state_Fluid_Coupling = 0;
const long idx_state_Torque_Multiplication = 1;
const long idx_state_Locked = 2;

const long idx_transition_es_TMMFluidCouplingTorqueMultiplication = 0;
const long idx_transition_es_FCMTorqueMultiplicationFluidCoupling = 1;
const long idx_transition_es_LockFluidCouplingLocked = 2;
const long idx_transition_es_FCMLockedFluidCoupling = 3;

const long idx_eqn_z_TorqueRatio_gt_one = 4;
const long idx_eqn_z_TorqueRatio_lt_one = 9;
const long idx_eqn_z_Speed_gt_LockedSpeed = 11;
const long idx_eqn_z_Speed_lt_LockedSpeed = 12;
const long idx_eqn_z_ImpellerTorque_lt_TurbineTorque = 13;

long currentState = 0;
switch (RtsCurrent_Torque_Converter)
{
  case RtsTorque_ConverterTorque_Converter_States_Fluid_Coupling:
    currentState = idx_state_Fluid_Coupling;
    break;
  case RtsTorque_ConverterTorque_Converter_States_Torque_Multiplication:
    currentState = idx_state_Torque_Multiplication;
    break;
  case RtsTorque_ConverterTorque_Converter_States_Locked:
    currentState = idx_state_Locked;
    break;
}

*bEvent = false;
switch (currentState)
{
case idx_state_Fluid_Coupling:
  if (iTransition == idx_transition_es_TMMFluidCouplingTorqueMultiplication)
    *bEvent = (EqnState[idx_eqn_z_TorqueRatio_gt_one]);
  if (iTransition == idx_transition_es_LockFluidCouplingLocked)
    *bEvent = (EqnState[idx_eqn_z_Speed_gt_LockedSpeed] && EqnState[idx_eqn_z_ImpellerTorque_lt_TurbineTorque]);
    break;

case idx_state_Torque_Multiplication:
  if (iTransition == idx_transition_es_FCMTorqueMultiplicationFluidCoupling)
    *bEvent = (EqnState[idx_eqn_z_TorqueRatio_lt_one]);
    break;

case idx_state_Locked:
  if (iTransition == idx_transition_es_FCMLockedFluidCoupling)
    *bEvent = (EqnState[idx_eqn_z_Speed_lt_LockedSpeed]);
    break;

}
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.27)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::ad_r_TMM_ImpellerTorque(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = ad_impellerTorque - 
    ( c[1] * ad_impellerSpeed * ad_impellerSpeed + 
      c[2] * ad_impellerSpeed * ad_turbineSpeed + 
      c[3] * ad_turbineSpeed * ad_turbineSpeed);


return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.28)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::ad_r_TMM_TurbineTorque(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = ad_turbineTorque - 
    ( c[4] * ad_impellerSpeed * ad_impellerSpeed + 
      c[5] * ad_impellerSpeed * ad_turbineSpeed + 
      c[6] * ad_turbineSpeed * ad_turbineSpeed);


return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.29)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::ad_r_FCM_ImpellerTorque(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = ad_impellerTorque - 
    ( c[7] * ad_impellerSpeed * ad_impellerSpeed + 
      c[8] * ad_impellerSpeed * ad_turbineSpeed + 
      c[9] * ad_turbineSpeed * ad_turbineSpeed);


return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.30)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::ad_r_FCM_TurbineTorque(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = ad_turbineTorque - ad_impellerTorque;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.31)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::ad_z_TorqueRatio_gt_one(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  Fdouble ad_speedRatio;

  if(fabs(impellerSpeed) > 1e-10)
    ad_speedRatio = ad_turbineSpeed / ad_impellerSpeed;
  else
    ad_speedRatio = ad_turbineSpeed / (ad_impellerSpeed + 1e-10);

  *res = 0.90 - ad_speedRatio;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.32)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::ad_r_ImpellerSpeed(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
#define PI 3.1415926535897932384626433832795
#define W_TO_RPM (60.0 / (2 * PI))

  //*res = DER(ad_impellerSpeed) - W_TO_RPM * impeller->ad_acceleration;
  *res = DER(ad_impellerSpeed) - impeller->ad_acceleration;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.33)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::ad_r_ImpellerNewton(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = impeller->ad_torque - impellerInertia * impeller->ad_acceleration - ad_impellerTorque;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.34)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::ad_r_TurbineSpeed(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
#define PI 3.1415926535897932384626433832795
#define W_TO_RPM (60.0 / (2 * PI))

  *res = DER(ad_turbineSpeed) - turbine->ad_acceleration;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.35)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::ad_r_TurbineNewton(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = ad_turbineTorque - turbineInertia * turbine->ad_acceleration + turbine->ad_torque ;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.47)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Torque_Converter::es_Lock()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsLock(RtsBusy);
    if (RtsCurrent_Torque_Converter == RtsTorque_ConverterTorque_Converter_States_Fluid_Coupling)
    {
        RtsExit_Fluid_Coupling();
        /* Simulation support : Notification function calls for transition */
        RtsNotify(3,"898ede88-00a6-41ad-8e5e-3d2d5e61cf22",0,NULL);

        RtsEnter_Locked();
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

//{{SCG_OP(0.48)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::ad_r_SpeedLocked(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = impeller->ad_acceleration - turbine->ad_acceleration;
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.49)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::ad_z_Speed_gt_LockedSpeed(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = ad_turbineSpeed - ad_impellerSpeed;
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.50)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::ad_z_Speed_lt_LockedSpeed(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = ( c[7] + c[8] + c[9] ) - ( ad_impellerTorque / (ad_impellerSpeed * ad_impellerSpeed) ); 

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.51)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

bool Torque_Converter::Load(FILE *fs)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  READ_SCALAR( RtsCurrent_Torque_Converter )
  return true;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.52)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::r_SpeedLocked(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = impeller->acceleration - turbine->acceleration;
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.53)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Torque_Converter::Save(FILE *fs)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  WRITE_SCALAR( RtsCurrent_Torque_Converter )

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.54)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::z_Speed_gt_LockedSpeed(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = turbineSpeed - impellerSpeed;
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}      

//}}SCG_OP            

//{{SCG_OP(0.55)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Torque_Converter::z_Speed_lt_LockedSpeed(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  // speed ratio = 1.0, therefore
  //   (torque / speed^2) = c[7] + c[8] * ratio + c[9] * ratio^2, therefore
  //   (torque / speed^2) = c[7] + c[8] + c[9] 
  *res = ( c[7] + c[8] + c[9] ) - ( impellerTorque / (impellerSpeed * impellerSpeed) ); 
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.56)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Torque_Converter::RtsEnter_Fluid_Coupling()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Fluid Coupling */
    RtsNotify(1,"9f17f6fd-6978-11d5-b154-00c04f680d9d",0,NULL);

    RtsCurrent_Torque_Converter = RtsTorque_ConverterTorque_Converter_States_Fluid_Coupling;

    /* Entry Actions */
    OnTransition();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.57)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Torque_Converter::RtsExit_Fluid_Coupling()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Torque_Converter == RtsTorque_ConverterTorque_Converter_States_Fluid_Coupling)
    {
        /* Simulation support : Notification function call for exiting state : Fluid Coupling */
        RtsNotify(2,"9f17f6fd-6978-11d5-b154-00c04f680d9d",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.58)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Torque_Converter::RtsEnter_Locked()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Locked */
    RtsNotify(1,"0fefb8c3-97cf-4986-88f4-d658f3b617ed",0,NULL);

    RtsCurrent_Torque_Converter = RtsTorque_ConverterTorque_Converter_States_Locked;

    /* Entry Actions */
    OnTransition();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.59)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Torque_Converter::RtsExit_Locked()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Torque_Converter == RtsTorque_ConverterTorque_Converter_States_Locked)
    {
        /* Simulation support : Notification function call for exiting state : Locked */
        RtsNotify(2,"0fefb8c3-97cf-4986-88f4-d658f3b617ed",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.60)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Torque_Converter::RtsEnter_Torque_Multiplication()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    /* Simulation support : Notification function call for entering state : Torque Multiplication */
    RtsNotify(1,"9f17f6ff-6978-11d5-b154-00c04f680d9d",0,NULL);

    RtsCurrent_Torque_Converter = RtsTorque_ConverterTorque_Converter_States_Torque_Multiplication;

    /* Entry Actions */
    OnTransition();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.61)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Torque_Converter::RtsExit_Torque_Multiplication()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    if (RtsCurrent_Torque_Converter == RtsTorque_ConverterTorque_Converter_States_Torque_Multiplication)
    {
        /* Simulation support : Notification function call for exiting state : Torque Multiplication */
        RtsNotify(2,"9f17f6ff-6978-11d5-b154-00c04f680d9d",0,NULL);

    }

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.62)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

 Torque_Converter::Torque_Converter()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
    RtsRegisterStateMachine(this,RtsInjectEvent,RtsGetAttributeValue,RtsSetAttributeValue);
    RtsCreateSemaphore(RtsBusy);
    RtsLock(RtsBusy);

    /* Initialising State Vectors to NotIn */
    RtsCurrent_Torque_Converter=RtsTorque_ConverterTorque_Converter_States_NotIn_Torque_Converter;

    RtsRunToCompletion();
    RtsUnlock(RtsBusy);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.63)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

 Torque_Converter::~Torque_Converter()  
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

void Torque_Converter::RtsRunToCompletion()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int EndOfLoop;
    for(EndOfLoop=0;EndOfLoop==0;)
    {
        EndOfLoop = 1;
        /* All completion transitions included here */
        if (RtsCurrent_Torque_Converter == RtsTorque_ConverterTorque_Converter_States_NotIn_Torque_Converter)
        {
            /* Simulation support : Notification function calls for transition */
            RtsNotify(3,"ff3fd9e3-6993-11d5-b154-00c04f680d9d",0,NULL);

            init();
            RtsEnter_Torque_Multiplication();

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
int Torque_Converter::RtsInjectEvent(const char* Event, const int NumParams, const StringArray params, Torque_Converter *pInstance)  
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
        if ((strcmp(Event, "es_Lock") == 0) || (strcmp(Event, "Torque Converter.es_Lock") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->es_Lock();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "es_TMM") == 0) || (strcmp(Event, "Torque Converter.es_TMM") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->es_TMM();
                }
            }
            else
            {
                /* Incorrect number of parameters for this event */
                Ret = 0;
            }
        }
        else if ((strcmp(Event, "es_FCM") == 0) || (strcmp(Event, "Torque Converter.es_FCM") == 0))
        {
            if (NumParams == 0)
            {
                if (Ret == 1)
                {
                    pInstance->es_FCM();
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
int Torque_Converter::RtsGetAttributeValue(const char* Name, char* Value, const int buflen, Torque_Converter *pInstance)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int Ret;
    Ret = 1;
    if (strcmp(Name, "turbineTorque") == 0)
    {
        sprintf(Value,"%.8g",pInstance->turbineTorque);
    }
    else if (strcmp(Name, "turbineSpeed") == 0)
    {
        sprintf(Value,"%.8g",pInstance->turbineSpeed);
    }
    else if (strcmp(Name, "turbineInertia") == 0)
    {
        sprintf(Value,"%.8g",pInstance->turbineInertia);
    }
    else if (strcmp(Name, "impellerTorque") == 0)
    {
        sprintf(Value,"%.8g",pInstance->impellerTorque);
    }
    else if (strcmp(Name, "impellerSpeed") == 0)
    {
        sprintf(Value,"%.8g",pInstance->impellerSpeed);
    }
    else if (strcmp(Name, "impellerInertia") == 0)
    {
        sprintf(Value,"%.8g",pInstance->impellerInertia);
    }
    else if (strcmp(Name, "turbine") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "impeller") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_turbineTorque") == 0)
    {
        sprintf(Value,"%.8g",pInstance->der_turbineTorque);
    }
    else if (strcmp(Name, "old_turbineTorque") == 0)
    {
        sprintf(Value,"%.8g",pInstance->old_turbineTorque);
    }
    else if (strcmp(Name, "der_old_turbineTorque") == 0)
    {
        sprintf(Value,"%.8g",pInstance->der_old_turbineTorque);
    }
    else if (strcmp(Name, "ad_turbineTorque") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_ad_turbineTorque") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_turbineSpeed") == 0)
    {
        sprintf(Value,"%.8g",pInstance->der_turbineSpeed);
    }
    else if (strcmp(Name, "old_turbineSpeed") == 0)
    {
        sprintf(Value,"%.8g",pInstance->old_turbineSpeed);
    }
    else if (strcmp(Name, "der_old_turbineSpeed") == 0)
    {
        sprintf(Value,"%.8g",pInstance->der_old_turbineSpeed);
    }
    else if (strcmp(Name, "ad_turbineSpeed") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_ad_turbineSpeed") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_impellerTorque") == 0)
    {
        sprintf(Value,"%.8g",pInstance->der_impellerTorque);
    }
    else if (strcmp(Name, "old_impellerTorque") == 0)
    {
        sprintf(Value,"%.8g",pInstance->old_impellerTorque);
    }
    else if (strcmp(Name, "der_old_impellerTorque") == 0)
    {
        sprintf(Value,"%.8g",pInstance->der_old_impellerTorque);
    }
    else if (strcmp(Name, "ad_impellerTorque") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_ad_impellerTorque") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_impellerSpeed") == 0)
    {
        sprintf(Value,"%.8g",pInstance->der_impellerSpeed);
    }
    else if (strcmp(Name, "old_impellerSpeed") == 0)
    {
        sprintf(Value,"%.8g",pInstance->old_impellerSpeed);
    }
    else if (strcmp(Name, "der_old_impellerSpeed") == 0)
    {
        sprintf(Value,"%.8g",pInstance->der_old_impellerSpeed);
    }
    else if (strcmp(Name, "ad_impellerSpeed") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_ad_impellerSpeed") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "c[10]") == 0)
    {
        sprintf(Value,"%.8g",pInstance->c[10]);
    }
    else if (strcmp(Name, "RtsCurrent_Torque_Converter") == 0)
    {
        switch(pInstance->RtsCurrent_Torque_Converter)
        {
            case RtsTorque_ConverterTorque_Converter_States_Fluid_Coupling:
                strncpy(Value,"Fluid_Coupling",buflen);
                break;
            case RtsTorque_ConverterTorque_Converter_States_Locked:
                strncpy(Value,"Locked",buflen);
                break;
            case RtsTorque_ConverterTorque_Converter_States_Torque_Multiplication:
                strncpy(Value,"Torque_Multiplication",buflen);
                break;
            case RtsTorque_ConverterTorque_Converter_States_NotIn_Torque_Converter:
                strncpy(Value,"NotIn_Torque_Converter",buflen);
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
        strncpy(Value,"345817f8-6969-11d5-b154-00c04f680d9d", buflen);
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
int Torque_Converter::RtsSetAttributeValue(const char* Name, const char* Value, Torque_Converter *pInstance)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
int Ret;
char *StopString;
    Ret = 1;
    if (strcmp(Name, "turbineTorque") == 0)
    {
        pInstance->turbineTorque = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "turbineSpeed") == 0)
    {
        pInstance->turbineSpeed = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "turbineInertia") == 0)
    {
        pInstance->turbineInertia = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "impellerTorque") == 0)
    {
        pInstance->impellerTorque = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "impellerSpeed") == 0)
    {
        pInstance->impellerSpeed = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "impellerInertia") == 0)
    {
        pInstance->impellerInertia = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "turbine") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "impeller") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_turbineTorque") == 0)
    {
        pInstance->der_turbineTorque = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "old_turbineTorque") == 0)
    {
        pInstance->old_turbineTorque = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "der_old_turbineTorque") == 0)
    {
        pInstance->der_old_turbineTorque = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "ad_turbineTorque") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_ad_turbineTorque") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_turbineSpeed") == 0)
    {
        pInstance->der_turbineSpeed = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "old_turbineSpeed") == 0)
    {
        pInstance->old_turbineSpeed = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "der_old_turbineSpeed") == 0)
    {
        pInstance->der_old_turbineSpeed = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "ad_turbineSpeed") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_ad_turbineSpeed") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_impellerTorque") == 0)
    {
        pInstance->der_impellerTorque = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "old_impellerTorque") == 0)
    {
        pInstance->old_impellerTorque = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "der_old_impellerTorque") == 0)
    {
        pInstance->der_old_impellerTorque = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "ad_impellerTorque") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_ad_impellerTorque") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_impellerSpeed") == 0)
    {
        pInstance->der_impellerSpeed = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "old_impellerSpeed") == 0)
    {
        pInstance->old_impellerSpeed = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "der_old_impellerSpeed") == 0)
    {
        pInstance->der_old_impellerSpeed = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "ad_impellerSpeed") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "der_ad_impellerSpeed") == 0)
    {
        /* cannot return or set the value of an attribute with no underlyingtype */
        Ret = 0;
    }
    else if (strcmp(Name, "c[10]") == 0)
    {
        pInstance->c[10] = strtod(Value,&StopString);
    }
    else if (strcmp(Name, "RtsCurrent_Torque_Converter") == 0)
    {
        if (strcmp(Value, "Fluid_Coupling") == 0 )
        {
            pInstance->RtsCurrent_Torque_Converter = RtsTorque_ConverterTorque_Converter_States_Fluid_Coupling;
        }
        else if (strcmp(Value, "Locked") == 0 )
        {
            pInstance->RtsCurrent_Torque_Converter = RtsTorque_ConverterTorque_Converter_States_Locked;
        }
        else if (strcmp(Value, "Torque_Multiplication") == 0 )
        {
            pInstance->RtsCurrent_Torque_Converter = RtsTorque_ConverterTorque_Converter_States_Torque_Multiplication;
        }
        else if (strcmp(Value, "NotIn_Torque_Converter") == 0 )
        {
            pInstance->RtsCurrent_Torque_Converter = RtsTorque_ConverterTorque_Converter_States_NotIn_Torque_Converter;
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



// added the following equations to address the lock - FCM chattering when
// turbine torque exceeds impeller torque (car driving the engine)
HRESULT Torque_Converter::z_ImpellerTorque_lt_TurbineTorque(double *res)
{
  *res = turbine->torque - impeller->torque;
  return S_OK;
}

HRESULT Torque_Converter::ad_z_ImpellerTorque_lt_TurbineTorque(Fdouble *res)
{
  *res = turbine->ad_torque - impeller->ad_torque;
  return S_OK;
}





