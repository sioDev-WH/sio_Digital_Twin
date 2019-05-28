//{{SCG_IMPLEMENTATION(Band_Break.cpp) [0]

//{{SCG_INCLUDE  

// Cg_Add
#include "StdAfx.h" 
#include "math.h"
#include "ActuatorClutchConnector.h"
#include "RigidConnector.h"
#include "ClutchBase.h"
#include "stdio.h"
                   
#include "Band_Break.h"
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif

// Include for Template Class should go here.
//}}SCG_INCLUDE
                      
//{{SCG_CLASS_ID
//}}SCG_CLASS_ID

//{{SCG_ICLASS_INFO(0)


//}}SCG_ICLASS_INFO
//{{SCG_ATTS(0)
//}}SCG_ATTS

//{{SCG_ROLES(0)
//}}SCG_ROLES

//{{SCG_OPS(0)

//{{SCG_OP(0.1)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   


Band_Break::Band_Break()
{
  init();
}


Band_Break::~Band_Break()
{
  clean();
}


HRESULT Band_Break::r_StickFrictionTorque(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


frictionCoefficient=0.1545; // frictionCoefficient=0.1545;
frictionCoefficient=exp(frictionCoefficient*wrapAngle)-1.0;
stiffness=area*actuatorConnector->pressure*1000.0*radius*frictionCoefficient/(cBreakfreeDispMax + 1.0e-20) + 1.0e-10;
*res= p->torque - stiffness * (1+torqueRatio) * displacement
      - ((actuatorConnector->pressure / pressureMax) + 1.0e-10) * damping * DER(displacement);
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.2)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Band_Break::r_cSlipFrictionTorque(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
frictionCoefficient=0.0631+0.0504*exp(-0.033*fabs(relativeVelocity));
frictionCoefficient=exp(frictionCoefficient*wrapAngle)-1.0;
stiffness=area*actuatorConnector->pressure*1000.0*radius*frictionCoefficient/(cBreakfreeDispMax + 1.0e-20) + 1.0e-10;
*res=p->torque - stiffness * cBreakfreeDisp;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

HRESULT Band_Break::r_ccSlipFrictionTorque(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
frictionCoefficient=0.0631+0.0504*exp(-0.033*fabs(relativeVelocity));
frictionCoefficient=exp(frictionCoefficient*wrapAngle)-1.0;
stiffness=area*actuatorConnector->pressure*1000.0*radius*frictionCoefficient/(ccBreakfreeDispMax + 1.0e-20) + 1.0e-10;
//*res=p->torque - stiffness * ccBreakfreeDisp;
*res=p->torque + stiffness * ccBreakfreeDisp;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     



//{{SCG_OP(0.0)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Band_Break::init()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


wrapAngle=6.0;
area=0.075;
cBreakfreeDispMax= 1.0e-2;  //1.0e-5;
ccBreakfreeDispMax=cBreakfreeDispMax;
DER(cBreakfreeDisp) = 0.0;
DER(ccBreakfreeDisp) = 0.0;
damping=100000.0;
displacement=0.0;
DER(displacement) = 0.0;
frictionCoefficient=0.0631+0.0504*exp(-0.033*fabs(relativeVelocity));
actuatorConnector->pressure = 0.0;
pressureMax=1000.0;
radius=0.055;
relativeVelocity=0.0; // Use connectors' vel.
DER(relativeVelocity) = 0.0;
stiffness=actuatorConnector->pressure*1000.0*area*radius*frictionCoefficient/(cBreakfreeDisp + 1.0e-20);

p->torque = 0.0;
n->torque = 0.0;

cBreakfreeDisp = 1.0e-3;  // 1.0e-7;
ccBreakfreeDisp = 1.0e-3; // 1.0e-7;

torqueRatio = 0.3;
cOilDisp = 1.0e-4; 
ccOilDisp = 1.0e-4;
//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.3)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Band_Break::clean()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.4)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Band_Break::handle_wrapAngle(const double t, const double* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

PostRealParameter(t, 0, *val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.5)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Band_Break::handle_area(const double t, const double* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

PostRealParameter(t, 1, *val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.6)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Band_Break::handle_radius(const double t, const double* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

PostRealParameter(t, 2, *val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.7)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Band_Break::handle_torqueRatio(const double t, const double* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

PostRealParameter(t, 3, *val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.8)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Band_Break::handle_damping(const double t, const double* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

PostRealParameter(t, 4, *val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.9)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Band_Break::handle_stiffness(const double t, const double* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

PostRealParameter(t, 5, *val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.10)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Band_Break::handle_frictionCoefficient(const double t, const double* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

PostRealParameter(t, 6, *val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.11)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Band_Break::handle_pressureMax(const double t, const double* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

PostRealParameter(t, 7, *val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.12)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Band_Break::handle_cBreakfreeDispMax(const double t, const double* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

PostRealParameter(t, 8, *val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.13)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Band_Break::handle_ccBreakfreeDispMax(const double t, const double* val)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

PostRealParameter(t, 9, *val);

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.14)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Band_Break::InitEsos()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

  ADD_LOCAL_ESO(actuatorConnector)
  ADD_LOCAL_ESO(n)
  ADD_LOCAL_ESO(p)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.15)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Band_Break::InitLocalEqns()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

  ADD_LOCAL_EQN(Band_Break, r_StickFrictionTorque)
  ADD_LOCAL_EQN(Band_Break, r_cSlipFrictionTorque)
  ADD_LOCAL_EQN(Band_Break, r_ccSlipFrictionTorque)

  ADD_LOCAL_EQN(ClutchBase, r_clockwiseBreakfreeDisp)
  ADD_LOCAL_EQN(ClutchBase, r_counterclockwiseBreakfreeDisp)
  ADD_LOCAL_EQN(ClutchBase, r_cSlipDisplacement)
  ADD_LOCAL_EQN(ClutchBase, r_stickDisplacement)
  ADD_LOCAL_EQN(ClutchBase, z_velocity_neg)
  ADD_LOCAL_EQN(ClutchBase, z_velocity_pos)
  ADD_LOCAL_EQN(ClutchBase, z_disp_pos_slip)
  ADD_LOCAL_EQN(ClutchBase, z_disp_neg_slip)
  ADD_LOCAL_EQN(ClutchBase, r_ccSlipDisplacement)
  ADD_LOCAL_EQN(ClutchBase, r_forceBalance)
  ADD_LOCAL_EQN(ClutchBase, r_relativeVelocity)
  
  ADD_LOCAL_EQN(ClutchBase, s_cLockDisplacement)
  ADD_LOCAL_EQN(ClutchBase, s_ccLockDisplacement)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.16)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Band_Break::InitLocalADEqns()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


  ADD_LOCAL_AD_EQN(Band_Break, ad_r_StickFrictionTorque)
  ADD_LOCAL_AD_EQN(Band_Break, ad_r_cSlipFrictionTorque)
  ADD_LOCAL_AD_EQN(Band_Break, ad_r_ccSlipFrictionTorque)

  ADD_LOCAL_AD_EQN(ClutchBase, ad_r_clockwiseBreakfreeDisp)
  ADD_LOCAL_AD_EQN(ClutchBase, ad_r_counterclockwiseBreakfreeDisp)
  ADD_LOCAL_AD_EQN(ClutchBase, ad_r_cSlipDisplacement)
  ADD_LOCAL_AD_EQN(ClutchBase, ad_r_stickDisplacement)
  ADD_LOCAL_AD_EQN(ClutchBase, ad_z_velocity_neg)
  ADD_LOCAL_AD_EQN(ClutchBase, ad_z_velocity_pos)
  ADD_LOCAL_AD_EQN(ClutchBase, ad_z_disp_pos_slip)
  ADD_LOCAL_AD_EQN(ClutchBase, ad_z_disp_neg_slip)
  ADD_LOCAL_AD_EQN(ClutchBase, ad_r_ccSlipDisplacement)
  ADD_LOCAL_AD_EQN(ClutchBase, ad_r_forceBalance)
  ADD_LOCAL_AD_EQN(ClutchBase, ad_r_relativeVelocity)

  ADD_LOCAL_AD_EQN(ClutchBase, ad_s_cLockDisplacement)
  ADD_LOCAL_AD_EQN(ClutchBase, ad_s_ccLockDisplacement)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.17)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Band_Break::InitEqnForm(OnEqnForm* *form, OnEqnDiffForm* *diff_form)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


const long idx_eqn_r_StickFrictionTorque = 0;
const long idx_eqn_r_cSlipFrictionTorque = 1;
const long idx_eqn_r_ccSlipFrictionTorque = 2;

const long idx_eqn_r_clockwiseBreakfreeDisp = 3;
const long idx_eqn_r_counterclockwiseBreakfreeDisp = 4;
const long idx_eqn_r_cSlipDisplacement = 5;
const long idx_eqn_r_stickDisplacement = 6;
const long idx_eqn_z_velocity_neg = 7;
const long idx_eqn_z_velocity_pos = 8;
const long idx_eqn_z_disp_pos_slip = 9;
const long idx_eqn_z_disp_neg_slip = 10;
const long idx_eqn_r_ccSlipDisplacement = 11;
const long idx_eqn_r_forceBalance = 12;
const long idx_eqn_r_relativeVelocity = 13;

const long idx_eqn_s_cLockDisplacement = 14;
const long idx_eqn_s_ccLockDisplacement = 15;

  DESTROY_VECTOR(*form)
  *form = new OnEqnForm[m_nLocalEqns];
  (*form)[idx_eqn_r_StickFrictionTorque] = continuous;
  (*form)[idx_eqn_r_cSlipFrictionTorque] = continuous;
  (*form)[idx_eqn_r_ccSlipFrictionTorque] = continuous;

  (*form)[idx_eqn_r_clockwiseBreakfreeDisp] = continuous;
  (*form)[idx_eqn_r_counterclockwiseBreakfreeDisp] = continuous;
  (*form)[idx_eqn_r_cSlipDisplacement] = continuous;
  (*form)[idx_eqn_r_stickDisplacement] = continuous;
  (*form)[idx_eqn_z_velocity_neg] = discontinuous;
  (*form)[idx_eqn_z_velocity_pos] = discontinuous;
  (*form)[idx_eqn_z_disp_pos_slip] = discontinuous;
  (*form)[idx_eqn_z_disp_neg_slip] = discontinuous;
  (*form)[idx_eqn_r_ccSlipDisplacement] = continuous;
  (*form)[idx_eqn_r_forceBalance] = continuous;
  (*form)[idx_eqn_r_relativeVelocity] = continuous;

  (*form)[idx_eqn_s_cLockDisplacement] = reset;
  (*form)[idx_eqn_s_ccLockDisplacement] = reset;

  DESTROY_VECTOR(*diff_form)
  *diff_form = new OnEqnDiffForm[m_nLocalEqns];
  (*diff_form)[idx_eqn_r_StickFrictionTorque] = automatic;
  (*diff_form)[idx_eqn_r_cSlipFrictionTorque] = automatic;
  (*diff_form)[idx_eqn_r_ccSlipFrictionTorque] = automatic;

  (*diff_form)[idx_eqn_r_clockwiseBreakfreeDisp] = automatic;
  (*diff_form)[idx_eqn_r_counterclockwiseBreakfreeDisp] = automatic;
  (*diff_form)[idx_eqn_r_cSlipDisplacement] = automatic;
  (*diff_form)[idx_eqn_r_stickDisplacement] = automatic;
  (*diff_form)[idx_eqn_z_velocity_neg] = automatic;
  (*diff_form)[idx_eqn_z_velocity_pos] = automatic;
  (*diff_form)[idx_eqn_z_disp_pos_slip] = automatic;
  (*diff_form)[idx_eqn_z_disp_neg_slip] = automatic;
  (*diff_form)[idx_eqn_r_ccSlipDisplacement] = automatic;
  (*diff_form)[idx_eqn_r_forceBalance] = automatic;
  (*diff_form)[idx_eqn_r_relativeVelocity] = automatic;

  (*diff_form)[idx_eqn_s_cLockDisplacement] = automatic;
  (*diff_form)[idx_eqn_s_ccLockDisplacement] = automatic;

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.18)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Band_Break::InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


  ADD_LOCAL_SVAR(relativeVelocity)
  ADD_LOCAL_SVAR(cBreakfreeDisp)
  ADD_LOCAL_SVAR(displacement)
  ADD_LOCAL_SVAR(ccBreakfreeDisp)

for (long i = 0; i < m_nEsos; i++)
  AddLocalVar(m_Esos[i], NULL, NULL, varC, true);

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.19)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Band_Break::InitLocalRPars(const _TCHAR* prefix, ppdouble *pars, ppchar *Names, long *nPars, long *dPars)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


  ADD_LOCAL_SRPAR(wrapAngle)
  ADD_LOCAL_SRPAR(area)
  ADD_LOCAL_SRPAR(radius)
  ADD_LOCAL_SRPAR(torqueRatio)
  ADD_LOCAL_SRPAR(damping)
  ADD_LOCAL_SRPAR(pressureMax)
  ADD_LOCAL_SRPAR(cBreakfreeDispMax)
  ADD_LOCAL_SRPAR(ccBreakfreeDispMax)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.20)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Band_Break::InitTransitions()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

HRESULT hr;
HRESULT hrRet = S_OK;


// equation constants
const long idx_eqn_r_StickFrictionTorque = 0;
const long idx_eqn_r_cSlipFrictionTorque = 1;
const long idx_eqn_r_ccSlipFrictionTorque = 2;

const long idx_eqn_r_clockwiseBreakfreeDisp = 3;
const long idx_eqn_r_counterclockwiseBreakfreeDisp = 4;
const long idx_eqn_r_cSlipDisplacement = 5;
const long idx_eqn_r_stickDisplacement = 6;
const long idx_eqn_z_velocity_neg = 7;
const long idx_eqn_z_velocity_pos = 8;
const long idx_eqn_z_disp_pos_slip = 9;
const long idx_eqn_z_disp_neg_slip = 10;
const long idx_eqn_r_ccSlipDisplacement = 11;
const long idx_eqn_r_forceBalance = 12;
const long idx_eqn_r_relativeVelocity = 13;

const long idx_eqn_s_cLockDisplacement = 14;
const long idx_eqn_s_ccLockDisplacement = 15;

// state constants
const long idx_state_ccSlip = 0;
const long idx_state_cSlip = 1;
const long idx_state_Lock = 2;

const long idx_eqns_es_SlipToLockccSlipLock[] = { 
  idx_eqn_z_velocity_pos,
  idx_eqn_s_ccLockDisplacement,
 };
const long idx_eqns_es_SlipToLockcSlipLock[] = { 
  idx_eqn_z_velocity_neg,
  idx_eqn_s_cLockDisplacement,
 };
const long idx_eqns_es_LockToCCSlipLockccSlip[] = { 
  idx_eqn_z_velocity_neg,
  idx_eqn_z_disp_neg_slip,
 };
const long idx_eqns_es_LockToCSlipLockcSlip[] = { 
  idx_eqn_z_velocity_pos,
  idx_eqn_z_disp_pos_slip,
 };

// Transition_Name, Source_State, Event_Name, Transition_Eqns, Eqn_Count
hr = AddTransition(L"es_SlipToLockccSlipLock", idx_state_ccSlip, L"es_SlipToLock", idx_eqns_es_SlipToLockccSlipLock, 2);
if (FAILED(hr)) hrRet = hr;
hr = AddTransition(L"es_SlipToLockcSlipLock", idx_state_cSlip, L"es_SlipToLock", idx_eqns_es_SlipToLockcSlipLock, 2);
if (FAILED(hr)) hrRet = hr;
hr = AddTransition(L"es_LockToCCSlipLockccSlip", idx_state_Lock, L"es_LockToCCSlip", idx_eqns_es_LockToCCSlipLockccSlip, 2);
if (FAILED(hr)) hrRet = hr;
hr = AddTransition(L"es_LockToCSlipLockcSlip", idx_state_Lock, L"es_LockToCSlip", idx_eqns_es_LockToCSlipLockcSlip, 2);
if (FAILED(hr)) hrRet = hr;

return hrRet;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.21)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Band_Break::InitStates()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

HRESULT hr;
HRESULT hrRet = S_OK;

// equation constants
const long idx_eqn_r_StickFrictionTorque = 0;
const long idx_eqn_r_cSlipFrictionTorque = 1;
const long idx_eqn_r_ccSlipFrictionTorque = 2;

const long idx_eqn_r_clockwiseBreakfreeDisp = 3;
const long idx_eqn_r_counterclockwiseBreakfreeDisp = 4;
const long idx_eqn_r_cSlipDisplacement = 5;
const long idx_eqn_r_stickDisplacement = 6;
const long idx_eqn_z_velocity_neg = 7;
const long idx_eqn_z_velocity_pos = 8;
const long idx_eqn_z_disp_pos_slip = 9;
const long idx_eqn_z_disp_neg_slip = 10;
const long idx_eqn_r_ccSlipDisplacement = 11;
const long idx_eqn_r_forceBalance = 12;
const long idx_eqn_r_relativeVelocity = 13;

const long idx_eqn_s_cLockDisplacement = 14;
const long idx_eqn_s_ccLockDisplacement = 15;

// state constants
const long idx_state_ccSlip = 0;
const long idx_state_cSlip = 1;
const long idx_state_Lock = 2;

const long idx_eqns_ccSlip[] = { 
  idx_eqn_r_ccSlipFrictionTorque,
  idx_eqn_r_clockwiseBreakfreeDisp,
  idx_eqn_r_counterclockwiseBreakfreeDisp,
  idx_eqn_r_ccSlipDisplacement,
  idx_eqn_r_forceBalance,
  idx_eqn_r_relativeVelocity,
 };
const long idx_eqns_cSlip[] = { 
  idx_eqn_r_cSlipFrictionTorque,
  idx_eqn_r_clockwiseBreakfreeDisp,
  idx_eqn_r_counterclockwiseBreakfreeDisp,
  idx_eqn_r_cSlipDisplacement,
  idx_eqn_r_forceBalance,
  idx_eqn_r_relativeVelocity,
 };
const long idx_eqns_Lock[] = { 
  idx_eqn_r_StickFrictionTorque,
  idx_eqn_r_clockwiseBreakfreeDisp,
  idx_eqn_r_counterclockwiseBreakfreeDisp,
  idx_eqn_r_stickDisplacement,
  idx_eqn_r_forceBalance,
  idx_eqn_r_relativeVelocity,
 };

hr = AddState(L"ccSlip", 0, idx_eqns_ccSlip, 6);
if (FAILED(hr)) hrRet = hr;
hr = AddState(L"cSlip", 0, idx_eqns_cSlip, 6);
if (FAILED(hr)) hrRet = hr;
hr = AddState(L"Lock", 1, idx_eqns_Lock, 6);
if (FAILED(hr)) hrRet = hr;

return hrRet;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.22)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Band_Break::OnTransition()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

HRESULT hr = S_OK;

const long idx_state_ccSlip = 0;
const long idx_state_cSlip = 1;
const long idx_state_Lock = 2;

// Cg_Add (fixed references to base class (wizard fix))
switch (RtsCurrent_Clutch)
{
  case RtsClutchBaseClutch_States_ccSlip:
    ATLTRACE("\nccSlip");
    hr = PostTransition(idx_state_ccSlip);
    break;
  case RtsClutchBaseClutch_States_cSlip:
    ATLTRACE("\ncSlip");
    hr = PostTransition(idx_state_cSlip);
    break;
  case RtsClutchBaseClutch_States_Lock:
    ATLTRACE("\nLock");
    hr = PostTransition(idx_state_Lock);
    break;
}

#if 1
  //ATLTRACE("\ndisplacement: %e cBreakfreeDisp: %e ccBreakfreeDisp: %e relativeVelocity: %e", displacement, cBreakfreeDisp, ccBreakfreeDisp, relativeVelocity);
#endif

return hr;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.23)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Band_Break::TriggerEvent(const double EventTime, const BSTR bstrEventId)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

USES_CONVERSION;

CComBSTR EventId = bstrEventId;
HRESULT hr = S_OK;

if (EventId == L"es_SlipToLock")
  es_SlipToLock();
else if (EventId == L"es_LockToCCSlip")
  es_LockToCCSlip();
else if (EventId == L"es_LockToCSlip")
  es_LockToCSlip();

m_time = EventTime;

// update old variables
old_relativeVelocity = relativeVelocity;
old_cBreakfreeDisp = cBreakfreeDisp;
old_displacement = displacement;
old_ccBreakfreeDisp = ccBreakfreeDisp;

return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.24)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Band_Break::EvalStateCondition(const bool* EqnState, const double* x, const double* xdot, const double EventTime, const long iDisEqn, const long iTransition, bool *bEvent)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


const long idx_state_ccSlip = 0;
const long idx_state_cSlip = 1;
const long idx_state_Lock = 2;

const long idx_transition_es_SlipToLockccSlipLock = 0;
const long idx_transition_es_SlipToLockcSlipLock = 1;
const long idx_transition_es_LockToCCSlipLockccSlip = 2;
const long idx_transition_es_LockToCSlipLockcSlip = 3;

const long idx_eqn_z_velocity_neg = 7;
const long idx_eqn_z_velocity_pos = 8;
const long idx_eqn_z_disp_pos_slip = 9;
const long idx_eqn_z_disp_neg_slip = 10;


long currentState = 0;
switch (RtsCurrent_Clutch)
{
  case RtsClutchBaseClutch_States_ccSlip:
    currentState = idx_state_ccSlip;
    break;
  case RtsClutchBaseClutch_States_cSlip:
    currentState = idx_state_cSlip;
    break;
  case RtsClutchBaseClutch_States_Lock:
    currentState = idx_state_Lock;
    break;
}

*bEvent = false;
switch (currentState)
{
case idx_state_ccSlip:
  if (iTransition == idx_transition_es_SlipToLockccSlipLock)
    *bEvent = (EqnState[idx_eqn_z_velocity_pos]);
    break;
case idx_state_cSlip:
  if (iTransition == idx_transition_es_SlipToLockcSlipLock)
    *bEvent = (EqnState[idx_eqn_z_velocity_neg]);
    break;
case idx_state_Lock:
  if (iTransition == idx_transition_es_LockToCCSlipLockccSlip)
    *bEvent = (EqnState[idx_eqn_z_velocity_neg] && EqnState[idx_eqn_z_disp_neg_slip]);
  else if (iTransition == idx_transition_es_LockToCSlipLockcSlip)
    *bEvent = (EqnState[idx_eqn_z_velocity_pos] && EqnState[idx_eqn_z_disp_pos_slip]);
    break;
}
  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.25)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   


HRESULT Band_Break::ad_r_StickFrictionTorque(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
Fdouble ad_stiffness;
  
frictionCoefficient=0.1545; // frictionCoefficient=0.1545;
frictionCoefficient=exp(frictionCoefficient*wrapAngle)-1.0;
ad_stiffness=area*actuatorConnector->ad_pressure*1000.0*radius*frictionCoefficient/(cBreakfreeDispMax + 1.0e-20) + 1.0e-10;
*res= p->ad_torque - ad_stiffness * (1+torqueRatio) * ad_displacement
      - ((actuatorConnector->pressure / pressureMax) + 1.0e-10) * damping * DER(ad_displacement);
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.26)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Band_Break::ad_r_cSlipFrictionTorque(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

Fdouble ad_stiffness;

frictionCoefficient=0.0631+0.0504*exp(-0.033*fabs(relativeVelocity));
frictionCoefficient=exp(frictionCoefficient*wrapAngle)-1.0;
ad_stiffness=area*actuatorConnector->ad_pressure*1000.0*radius*frictionCoefficient/(cBreakfreeDispMax + 1.0e-20) + 1.0e-10;
*res=p->ad_torque - ad_stiffness * ad_cBreakfreeDisp;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     



HRESULT Band_Break::ad_r_ccSlipFrictionTorque(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

Fdouble ad_stiffness;

frictionCoefficient=0.0631+0.0504*exp(-0.033*fabs(relativeVelocity));
frictionCoefficient=exp(frictionCoefficient*wrapAngle)-1.0;
ad_stiffness=area*actuatorConnector->ad_pressure*1000.0*radius*frictionCoefficient/(ccBreakfreeDispMax + 1.0e-20) + 1.0e-10;
*res=p->ad_torque + ad_stiffness * ad_ccBreakfreeDisp;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     


void Band_Break::Save(FILE* fs)
{
  WRITE_SCALAR( RtsCurrent_Clutch )
}

bool Band_Break::Load(FILE* fs)
{
  READ_SCALAR( RtsCurrent_Clutch )
  return true;
}

