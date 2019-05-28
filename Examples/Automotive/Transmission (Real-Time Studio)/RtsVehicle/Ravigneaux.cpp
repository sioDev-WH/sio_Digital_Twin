//{{SCG_IMPLEMENTATION(Ravigneaux.cpp) [0]

//{{SCG_INCLUDE      

// Cg_Add
#include "StdAfx.h" 
#include "RigidConnector.h"                   

               
#include "Ravigneaux.h"

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

//{{SCG_OP(0.0)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   
Ravigneaux::Ravigneaux()
{
  init();

}

Ravigneaux::~Ravigneaux()
{
  clean();

}

HRESULT Ravigneaux::r_ifSunTorque(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = ifSun->torque - forwardSun.torque;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.1)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::r_iCouplerAcceleration(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = iCoupler->acceleration - carrier.acceleration;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.2)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::r_ifSunSpeed(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = ifSun->acceleration - forwardSun.DER(speed);
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.3)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::r_irSunAcceleration(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = irSun->acceleration - reverseSun.acceleration;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.4)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::r_irSunSpeed(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = irSun->acceleration - reverseSun.DER(speed);
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.5)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::r_irSunTorque(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = irSun->torque - reverseSun.torque;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.6)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::r_oRingTorque(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = oRing->torque - ring.torque;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.7)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::r_oRingAcceleration(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = oRing->acceleration - ring.acceleration;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.8)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::r_oRingSpeed(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = oRing->acceleration - ring.DER(speed);
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.9)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::r_iCouplerSpeed(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = iCoupler->acceleration - carrier.DER(speed);
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.10)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::r_iCouplerTorque(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = iCoupler->torque - carrier.torque;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.11)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::r_ifSunAcceleration(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = ifSun->acceleration - forwardSun.acceleration;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.12)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::r_longPinionSpeed(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = longPinion.acceleration - longPinion.DER(speed);
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.13)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::r_longPinionTorque(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = longPinion.torque;

return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.14)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::r_shortPinionSpeed(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res = shortPinion.acceleration - shortPinion.DER(speed);
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.15)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::r_shortPinionTorque(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = shortPinion.torque;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            





//{{SCG_OP(0.20)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Ravigneaux::clean()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  ifSun->Release();
  irSun->Release();
  iCoupler->Release();
  oRing->Release();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            








//{{SCG_OP(0.28)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::InitEsos()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

  ADD_LOCAL_ESO(ifSun)
  ADD_LOCAL_ESO(irSun)
  ADD_LOCAL_ESO(iCoupler)
  ADD_LOCAL_ESO(oRing)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.29)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::InitLocalEqns()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

  ADD_LOCAL_EQN(Ravigneaux, r_ifSunTorque)
  ADD_LOCAL_EQN(Ravigneaux, r_iCouplerAcceleration)
  ADD_LOCAL_EQN(Ravigneaux, r_ifSunSpeed)
  ADD_LOCAL_EQN(Ravigneaux, r_irSunAcceleration)
  ADD_LOCAL_EQN(Ravigneaux, r_irSunSpeed)
  ADD_LOCAL_EQN(Ravigneaux, r_irSunTorque)
  ADD_LOCAL_EQN(Ravigneaux, r_oRingTorque)
  ADD_LOCAL_EQN(Ravigneaux, r_oRingAcceleration)
  ADD_LOCAL_EQN(Ravigneaux, r_oRingSpeed)
  ADD_LOCAL_EQN(Ravigneaux, r_iCouplerSpeed)
  ADD_LOCAL_EQN(Ravigneaux, r_iCouplerTorque)
  ADD_LOCAL_EQN(Ravigneaux, r_ifSunAcceleration)
  ADD_LOCAL_EQN(Ravigneaux, r_longPinionSpeed)
  ADD_LOCAL_EQN(Ravigneaux, r_longPinionTorque)
  ADD_LOCAL_EQN(Ravigneaux, r_shortPinionSpeed)
  ADD_LOCAL_EQN(Ravigneaux, r_shortPinionTorque)
  ADD_LOCAL_EQN(Ravigneaux, r_ReverseToPinionKinematics)
  ADD_LOCAL_EQN(Ravigneaux, r_ForwardSunDynamics)
  ADD_LOCAL_EQN(Ravigneaux, r_ShortPinionDynamics)
  ADD_LOCAL_EQN(Ravigneaux, r_LongPinionDynamics)
  ADD_LOCAL_EQN(Ravigneaux, r_ForwardToPinionKinematics)
  ADD_LOCAL_EQN(Ravigneaux, r_PinionToPinionKinematics)
  ADD_LOCAL_EQN(Ravigneaux, r_PinionToRingKinematics)
  ADD_LOCAL_EQN(Ravigneaux, r_CarrierDynamics)
  ADD_LOCAL_EQN(Ravigneaux, r_ReverseSunDynamics)
  ADD_LOCAL_EQN(Ravigneaux, r_RingDynamics)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.30)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::InitLocalADEqns()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY

  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_ifSunTorque)
  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_iCouplerAcceleration)
  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_ifSunSpeed)
  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_irSunAcceleration)
  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_irSunSpeed)
  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_irSunTorque)
  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_oRingTorque)
  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_oRingAcceleration)
  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_oRingSpeed)
  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_iCouplerSpeed)
  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_iCouplerTorque)
  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_ifSunAcceleration)
  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_longPinionSpeed)
  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_longPinionTorque)
  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_shortPinionSpeed)
  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_shortPinionTorque)
  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_ReverseToPinionKinematics)
  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_ForwardSunDynamics)
  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_ShortPinionDynamics)
  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_LongPinionDynamics)
  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_ForwardToPinionKinematics)
  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_PinionToPinionKinematics)
  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_PinionToRingKinematics)
  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_CarrierDynamics)
  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_ReverseSunDynamics)
  ADD_LOCAL_AD_EQN(Ravigneaux, ad_r_RingDynamics)

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.31)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::InitEqnForm(OnEqnForm* *form, OnEqnDiffForm* *diff_form)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


const long idx_eqn_r_ifSunTorque = 0;
const long idx_eqn_r_iCouplerAcceleration = 1;
const long idx_eqn_r_ifSunSpeed = 2;
const long idx_eqn_r_irSunAcceleration = 3;
const long idx_eqn_r_irSunSpeed = 4;
const long idx_eqn_r_irSunTorque = 5;
const long idx_eqn_r_oRingTorque = 6;
const long idx_eqn_r_oRingAcceleration = 7;
const long idx_eqn_r_oRingSpeed = 8;
const long idx_eqn_r_iCouplerSpeed = 9;
const long idx_eqn_r_iCouplerTorque = 10;
const long idx_eqn_r_ifSunAcceleration = 11;
const long idx_eqn_r_longPinionSpeed = 12;
const long idx_eqn_r_longPinionTorque = 13;
const long idx_eqn_r_shortPinionSpeed = 14;
const long idx_eqn_r_shortPinionTorque = 15;
const long idx_eqn_r_ReverseToPinionKinematics = 16;
const long idx_eqn_r_ForwardSunDynamics = 17;
const long idx_eqn_r_ShortPinionDynamics = 18;
const long idx_eqn_r_LongPinionDynamics = 19;
const long idx_eqn_r_ForwardToPinionKinematics = 20;
const long idx_eqn_r_PinionToPinionKinematics = 21;
const long idx_eqn_r_PinionToRingKinematics = 22;
const long idx_eqn_r_CarrierDynamics = 23;
const long idx_eqn_r_ReverseSunDynamics = 24;
const long idx_eqn_r_RingDynamics = 25;

  DESTROY_VECTOR(*form)
  *form = new OnEqnForm[m_nLocalEqns];
  (*form)[idx_eqn_r_ifSunTorque] = continuous;
  (*form)[idx_eqn_r_iCouplerAcceleration] = continuous;
  (*form)[idx_eqn_r_ifSunSpeed] = continuous;
  (*form)[idx_eqn_r_irSunAcceleration] = continuous;
  (*form)[idx_eqn_r_irSunSpeed] = continuous;
  (*form)[idx_eqn_r_irSunTorque] = continuous;
  (*form)[idx_eqn_r_oRingTorque] = continuous;
  (*form)[idx_eqn_r_oRingAcceleration] = continuous;
  (*form)[idx_eqn_r_oRingSpeed] = continuous;
  (*form)[idx_eqn_r_iCouplerSpeed] = continuous;
  (*form)[idx_eqn_r_iCouplerTorque] = continuous;
  (*form)[idx_eqn_r_ifSunAcceleration] = continuous;
  (*form)[idx_eqn_r_longPinionSpeed] = continuous;
  (*form)[idx_eqn_r_longPinionTorque] = continuous;
  (*form)[idx_eqn_r_shortPinionSpeed] = continuous;
  (*form)[idx_eqn_r_shortPinionTorque] = continuous;
  (*form)[idx_eqn_r_ReverseToPinionKinematics] = continuous;
  (*form)[idx_eqn_r_ForwardSunDynamics] = continuous;
  (*form)[idx_eqn_r_ShortPinionDynamics] = continuous;
  (*form)[idx_eqn_r_LongPinionDynamics] = continuous;
  (*form)[idx_eqn_r_ForwardToPinionKinematics] = continuous;
  (*form)[idx_eqn_r_PinionToPinionKinematics] = continuous;
  (*form)[idx_eqn_r_PinionToRingKinematics] = continuous;
  (*form)[idx_eqn_r_CarrierDynamics] = continuous;
  (*form)[idx_eqn_r_ReverseSunDynamics] = continuous;
  (*form)[idx_eqn_r_RingDynamics] = continuous;

  DESTROY_VECTOR(*diff_form)
  *diff_form = new OnEqnDiffForm[m_nLocalEqns];
  (*diff_form)[idx_eqn_r_ifSunTorque] = numeric;
  (*diff_form)[idx_eqn_r_iCouplerAcceleration] = numeric;
  (*diff_form)[idx_eqn_r_ifSunSpeed] = numeric;
  (*diff_form)[idx_eqn_r_irSunAcceleration] = numeric;
  (*diff_form)[idx_eqn_r_irSunSpeed] = numeric;
  (*diff_form)[idx_eqn_r_irSunTorque] = numeric;
  (*diff_form)[idx_eqn_r_oRingTorque] = numeric;
  (*diff_form)[idx_eqn_r_oRingAcceleration] = numeric;
  (*diff_form)[idx_eqn_r_oRingSpeed] = numeric;
  (*diff_form)[idx_eqn_r_iCouplerSpeed] = numeric;
  (*diff_form)[idx_eqn_r_iCouplerTorque] = numeric;
  (*diff_form)[idx_eqn_r_ifSunAcceleration] = numeric;
  (*diff_form)[idx_eqn_r_longPinionSpeed] = numeric;
  (*diff_form)[idx_eqn_r_longPinionTorque] = numeric;
  (*diff_form)[idx_eqn_r_shortPinionSpeed] = numeric;
  (*diff_form)[idx_eqn_r_shortPinionTorque] = numeric;
  (*diff_form)[idx_eqn_r_ReverseToPinionKinematics] = numeric;
  (*diff_form)[idx_eqn_r_ForwardSunDynamics] = numeric;
  (*diff_form)[idx_eqn_r_ShortPinionDynamics] = numeric;
  (*diff_form)[idx_eqn_r_LongPinionDynamics] = numeric;
  (*diff_form)[idx_eqn_r_ForwardToPinionKinematics] = numeric;
  (*diff_form)[idx_eqn_r_PinionToPinionKinematics] = numeric;
  (*diff_form)[idx_eqn_r_PinionToRingKinematics] = numeric;
  (*diff_form)[idx_eqn_r_CarrierDynamics] = numeric;
  (*diff_form)[idx_eqn_r_ReverseSunDynamics] = numeric;
  (*diff_form)[idx_eqn_r_RingDynamics] = numeric;

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.32)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY


  ADD_LOCAL_SVAR(pinionToPinionForce)
  ADD_LOCAL_SVAR(ringToPinionForce)
  ADD_LOCAL_SVAR(pinionToReverseForce)
  ADD_LOCAL_SVAR(forwardToPinionForce)

  ADD_LOCAL_CVAR(&forwardSun)
  ADD_LOCAL_CVAR(&shortPinion)
  ADD_LOCAL_CVAR(&longPinion)
  ADD_LOCAL_CVAR(&reverseSun)
  ADD_LOCAL_CVAR(&ring)     
  ADD_LOCAL_CVAR(&carrier)

for (long i = 0; i < m_nEsos; i++)
  AddLocalVar(m_Esos[i], NULL, NULL, varC, true);

  return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.33)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_ifSunTorque(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = ifSun->ad_torque - forwardSun.ad_torque;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.34)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_iCouplerAcceleration(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = iCoupler->ad_acceleration - carrier.ad_acceleration;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.35)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_ifSunSpeed(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = ifSun->ad_acceleration - forwardSun.DER(ad_speed);
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.36)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_irSunAcceleration(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = irSun->ad_acceleration - reverseSun.ad_acceleration;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.37)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_irSunSpeed(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = irSun->ad_acceleration - reverseSun.DER(ad_speed);
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.38)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_irSunTorque(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = irSun->ad_torque - reverseSun.ad_torque;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.39)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_oRingTorque(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = oRing->ad_torque - ring.ad_torque;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.40)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_oRingAcceleration(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = oRing->ad_acceleration - ring.ad_acceleration;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.41)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_oRingSpeed(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = oRing->ad_acceleration - ring.DER(ad_speed);
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.42)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_iCouplerSpeed(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = iCoupler->ad_acceleration - carrier.DER(ad_speed);
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.43)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_iCouplerTorque(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = iCoupler->ad_torque - carrier.ad_torque;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.44)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_ifSunAcceleration(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = ifSun->ad_acceleration - forwardSun.ad_acceleration;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.45)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_longPinionSpeed(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = longPinion.ad_acceleration - longPinion.DER(ad_speed);
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.46)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_longPinionTorque(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = longPinion.ad_torque;

return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.47)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_shortPinionSpeed(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res = shortPinion.ad_acceleration - shortPinion.DER(ad_speed);
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.48)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_shortPinionTorque(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = shortPinion.ad_torque;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.49)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_ReverseToPinionKinematics(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = longPinion.ad_acceleration * longPinion.nTeeth + 
         (reverseSun.ad_acceleration - carrier.ad_acceleration) * reverseSun.nTeeth;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.50)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_ForwardSunDynamics(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = forwardSun.ad_torque - 
         3.0 * ad_forwardToPinionForce * forwardSun.radius - 
         forwardSun.inertia * forwardSun.ad_acceleration;

return S_OK;

 

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.51)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_ShortPinionDynamics(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res =  shortPinion.ad_torque - (ad_forwardToPinionForce
           + ad_pinionToPinionForce) * shortPinion.radius - 
          shortPinion.inertia * shortPinion.ad_acceleration;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.52)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_LongPinionDynamics(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = longPinion.ad_torque - (ad_pinionToPinionForce + ad_pinionToReverseForce + ad_ringToPinionForce) * longPinion.radius -
         longPinion.inertia * longPinion.ad_acceleration;

return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.53)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_ForwardToPinionKinematics(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res = shortPinion.ad_acceleration * shortPinion.nTeeth + 
         (forwardSun.ad_acceleration - carrier.ad_acceleration) * forwardSun.nTeeth;

return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.54)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_PinionToPinionKinematics(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = longPinion.ad_acceleration * longPinion.nTeeth + 
         shortPinion.ad_acceleration * shortPinion.nTeeth;

return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.55)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_PinionToRingKinematics(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = longPinion.ad_acceleration * longPinion.nTeeth - 
         (ring.ad_acceleration - carrier.ad_acceleration) * ring.nTeeth;

return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.56)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_CarrierDynamics(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = carrier.ad_torque - 3.0 * (
           -ad_forwardToPinionForce * forwardSun.radius +
           -ad_pinionToReverseForce * reverseSun.radius +
           ad_ringToPinionForce * ring.radius
         ) 
         - carrier.inertia * carrier.ad_acceleration;

return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.57)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_ReverseSunDynamics(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = reverseSun.ad_torque - 3.0 * ad_pinionToReverseForce * reverseSun.radius -
         reverseSun.inertia * reverseSun.ad_acceleration;

return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.58)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::ad_r_RingDynamics(Fdouble *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = ring.ad_torque + 
         3.0 * ad_ringToPinionForce * ring.radius - 
         ring.inertia * ring.ad_acceleration;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.3)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::r_ReverseToPinionKinematics(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = longPinion.acceleration * longPinion.nTeeth + 
         (reverseSun.acceleration - carrier.acceleration) * reverseSun.nTeeth;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.4)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::r_ForwardSunDynamics(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = forwardSun.torque - 
         3.0 * forwardToPinionForce * forwardSun.radius - 
         forwardSun.inertia * forwardSun.acceleration;

return S_OK;

 

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.5)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::r_ShortPinionDynamics(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res =  shortPinion.torque - (forwardToPinionForce
           + pinionToPinionForce) * shortPinion.radius - 
          shortPinion.inertia * shortPinion.acceleration;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.6)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::r_LongPinionDynamics(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = longPinion.torque - (pinionToPinionForce + pinionToReverseForce + ringToPinionForce) * longPinion.radius -
         longPinion.inertia * longPinion.acceleration;

return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.0)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::r_ForwardToPinionKinematics(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
*res = shortPinion.acceleration * shortPinion.nTeeth + 
         (forwardSun.acceleration - carrier.acceleration) * forwardSun.nTeeth;

return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.1)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::r_PinionToPinionKinematics(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = longPinion.acceleration * longPinion.nTeeth + 
         shortPinion.acceleration * shortPinion.nTeeth;

return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.2)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::r_PinionToRingKinematics(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = longPinion.acceleration * longPinion.nTeeth - 
         (ring.acceleration - carrier.acceleration) * ring.nTeeth;

return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.7)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::r_CarrierDynamics(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = carrier.torque - 3.0 * (
           -forwardToPinionForce * forwardSun.radius +
           -pinionToReverseForce * reverseSun.radius +
           ringToPinionForce * ring.radius
         ) 
         - carrier.inertia * carrier.acceleration;

return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.8)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::r_ReverseSunDynamics(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = reverseSun.torque - 3.0 * pinionToReverseForce * reverseSun.radius -
         reverseSun.inertia * reverseSun.acceleration;

return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.9)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

HRESULT Ravigneaux::r_RingDynamics(double *res)  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
  *res = ring.torque + 
         3.0 * ringToPinionForce * ring.radius - 
         ring.inertia * ring.acceleration;
return S_OK;

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            

//{{SCG_OP(0.10)   
//{{SCG_OP_INFO 
/////////////////////////////////////////////////////////////////////   

void Ravigneaux::init()  
//}}SCG_OP_INFO
{
/***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
//{{SCG_OP_BODY
 forwardSun.init();
 reverseSun.init();
 shortPinion.init();
 longPinion.init();
 carrier.init();
 ring.init();

  forwardToPinionForce = 0.0;
  pinionToPinionForce = 0.0;
  ringToPinionForce = 0.0;
  pinionToReverseForce = 0.0;

  DER(forwardToPinionForce) = 0.0;
  DER(pinionToPinionForce) = 0.0;
  DER(ringToPinionForce) = 0.0;
  DER(pinionToReverseForce) = 0.0;

  forwardSun.inertia = 0.03;
  forwardSun.nTeeth = 30;
  forwardSun.radius =  0.030;

  shortPinion.inertia = 0.02;
  shortPinion.nTeeth = 20;
  shortPinion.radius = 0.020;

  reverseSun.inertia = 0.036;
  reverseSun.nTeeth = 36;
  reverseSun.radius = 0.036;

  longPinion.inertia = 0.02;
  longPinion.nTeeth = 20;
  longPinion.radius = 0.020;

  carrier.inertia = 0.1;

  ring.inertia = 0.72;
  ring.nTeeth = 72;
  ring.radius = 0.072;



  ifSun = new CRigidConnector();
  irSun = new CRigidConnector();
  iCoupler = new CRigidConnector();
  oRing = new CRigidConnector();
  ifSun->AddRef();
  irSun->AddRef();
  iCoupler->AddRef();
  oRing->AddRef();

//}}SCG_OP_BODY
/***** End of automatically generated code *****/
}                     
//}}SCG_OP            
//}}SCG_OPS

//}}SCG_IMPLEMENTATION









