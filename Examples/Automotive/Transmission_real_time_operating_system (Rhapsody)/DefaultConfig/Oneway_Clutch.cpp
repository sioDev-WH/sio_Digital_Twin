/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Oneway_Clutch
//!	Generated Date	: Thu, 9, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Oneway_Clutch.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 


#define _OMSTATECHART_ANIMATED 
//#]

#include "Oneway_Clutch.h"
#include "ActuatorClutchConnector.h"
#include "CRigidConnector.h"
#include "stdafx.h"
#include "math.h"

//## package TransmissionModels 


//#[ ignore 
#define TransmissionModels_Oneway_Clutch_Oneway_Clutch_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_EvalStateCondition_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_InitEqnForm_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_InitEsos_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_InitLocalADEqns_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_InitLocalEqns_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_InitLocalIPars_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_InitLocalRPars_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_InitLocalVars_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_InitStates_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_InitTransitions_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_Load_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_OnTransition_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_Save_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_TriggerEvent_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_clean_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_handle_area_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_handle_cBreakfreeDispMax_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_handle_ccBreakfreeDispMax_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_handle_damping_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_handle_frictionCoefficient_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_handle_nSurfaces_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_handle_pressureMax_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_handle_radius_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_handle_stiffness_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_handle_torqueRatio_SERIALIZE OM_NO_OP


#define TransmissionModels_Oneway_Clutch_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// Oneway_Clutch.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(TransmissionModels)
//## class Oneway_Clutch 



Oneway_Clutch::Oneway_Clutch(OMThread*  p_thread) {
    NOTIFY_REACTIVE_CONSTRUCTOR(Oneway_Clutch, Oneway_Clutch(), 0, TransmissionModels_Oneway_Clutch_Oneway_Clutch_SERIALIZE);
    setThread(p_thread, FALSE);
    initStatechart();
    //#[ operation Oneway_Clutch() 
    init();
    startBehavior();
    //#]
}

Oneway_Clutch::~Oneway_Clutch() {
    NOTIFY_DESTRUCTOR(~Oneway_Clutch, FALSE);
    //#[ operation ~Oneway_Clutch() 
    clean();
    //#]
}

HRESULT Oneway_Clutch::EvalStateCondition(const bool * EqnState, const double * x, const double * xdot, const double EventTime, const long iDisEqn, const long iTransition, bool * bEvent) {
    NOTIFY_OPERATION(EvalStateCondition, EvalStateCondition(const bool * ,const double * ,const double * ,const double ,const long ,const long ,bool * ), 0, TransmissionModels_Oneway_Clutch_EvalStateCondition_SERIALIZE);
    //#[ operation EvalStateCondition(const bool * ,const double * ,const double * ,const double ,const long ,const long ,bool * ) 
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
    
    const long idx_eqn_z_cSlipTorque = 14;
    const long idx_eqn_z_ccSlipTorque = 15;
    const long idx_eqn_s_cLockDisplacement = 16;
    const long idx_eqn_s_ccLockDisplacement = 17;
    const long idx_eqn_s_cSlipDisplacement = 18;
    const long idx_eqn_s_ccSlipDisplacement = 19;
    
    
    
    long currentState = 0;
    if (rootState_active == ccSlip)
    {
        currentState = idx_state_ccSlip;
    }
    else if (rootState_active == cSlip)
    {
        currentState = idx_state_cSlip;
    }
    else if (rootState_active == Lock)
    {
        currentState = idx_state_Lock;
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
      {
        if (direction == Direction_CLOCKWISE)
          *bEvent = EqnState[idx_eqn_z_velocity_neg] || EqnState[idx_eqn_z_ccSlipTorque];
          //*bEvent = EqnState[idx_eqn_z_velocity_neg] || EqnState[idx_eqn_z_disp_neg_slip];
        else // direction == Direction_COUNTERCLOCKWISE
          *bEvent = (EqnState[idx_eqn_z_velocity_neg] && EqnState[idx_eqn_z_disp_neg_slip]);
      }
      else if (iTransition == idx_transition_es_LockToCSlipLockcSlip)
      {
        if (direction == Direction_CLOCKWISE)
          *bEvent = (EqnState[idx_eqn_z_velocity_pos] && EqnState[idx_eqn_z_disp_pos_slip]);
        else // direction == Direction_COUNTERCLOCKWISE
          *bEvent = EqnState[idx_eqn_z_velocity_pos] || EqnState[idx_eqn_z_cSlipTorque];
          //*bEvent = EqnState[idx_eqn_z_velocity_pos] || EqnState[idx_eqn_z_disp_pos_slip];
      }
      break;
    }
      return S_OK;
    
    //#]
}

HRESULT Oneway_Clutch::InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form) {
    NOTIFY_OPERATION(InitEqnForm, InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ), 0, TransmissionModels_Oneway_Clutch_InitEqnForm_SERIALIZE);
    //#[ operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
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
    
    const long idx_eqn_z_cSlipTorque = 14;
    const long idx_eqn_z_ccSlipTorque = 15;
    const long idx_eqn_s_cLockDisplacement = 16;
    const long idx_eqn_s_ccLockDisplacement = 17;
    const long idx_eqn_s_cSlipDisplacement = 18;
    const long idx_eqn_s_ccSlipDisplacement = 19;
    
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
    
      (*form)[idx_eqn_z_cSlipTorque] = discontinuous;
      (*form)[idx_eqn_z_ccSlipTorque] = discontinuous;
      (*form)[idx_eqn_s_cLockDisplacement] = reset;
      (*form)[idx_eqn_s_ccLockDisplacement] = reset;
      (*form)[idx_eqn_s_cSlipDisplacement] = reset;
      (*form)[idx_eqn_s_ccSlipDisplacement] = reset;
    
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
    
      (*diff_form)[idx_eqn_z_cSlipTorque] = automatic;
      (*diff_form)[idx_eqn_z_ccSlipTorque] = automatic;
      (*diff_form)[idx_eqn_s_cLockDisplacement] = automatic;
      (*diff_form)[idx_eqn_s_ccLockDisplacement] = automatic;
      (*diff_form)[idx_eqn_s_cSlipDisplacement] = automatic;
      (*diff_form)[idx_eqn_s_ccSlipDisplacement] = automatic;
    
      return S_OK;
    
    //#]
}

HRESULT Oneway_Clutch::InitEsos() {
    NOTIFY_OPERATION(InitEsos, InitEsos(), 0, TransmissionModels_Oneway_Clutch_InitEsos_SERIALIZE);
    //#[ operation InitEsos() 
      ADD_LOCAL_ESO(actuatorConnector)
      ADD_LOCAL_ESO(n)
      ADD_LOCAL_ESO(p)
    
      return S_OK;
    
    //#]
}

HRESULT Oneway_Clutch::InitLocalADEqns() {
    NOTIFY_OPERATION(InitLocalADEqns, InitLocalADEqns(), 0, TransmissionModels_Oneway_Clutch_InitLocalADEqns_SERIALIZE);
    //#[ operation InitLocalADEqns() 
      ADD_LOCAL_AD_EQN(Oneway_Clutch, ad_r_StickFrictionTorque)
      ADD_LOCAL_AD_EQN(Oneway_Clutch, ad_r_cSlipFrictionTorque)
      ADD_LOCAL_AD_EQN(Oneway_Clutch, ad_r_ccSlipFrictionTorque)
    
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
    
      ADD_LOCAL_AD_EQN(Oneway_Clutch, ad_z_cSlipTorque)
      ADD_LOCAL_AD_EQN(Oneway_Clutch, ad_z_ccSlipTorque)
      ADD_LOCAL_AD_EQN(ClutchBase, ad_s_cLockDisplacement)
      ADD_LOCAL_AD_EQN(ClutchBase, ad_s_ccLockDisplacement)
      ADD_LOCAL_AD_EQN(Oneway_Clutch, ad_s_cSlipDisplacement)
      ADD_LOCAL_AD_EQN(Oneway_Clutch, ad_s_ccSlipDisplacement)
    
      return S_OK;
    
    //#]
}

HRESULT Oneway_Clutch::InitLocalEqns() {
    NOTIFY_OPERATION(InitLocalEqns, InitLocalEqns(), 0, TransmissionModels_Oneway_Clutch_InitLocalEqns_SERIALIZE);
    //#[ operation InitLocalEqns() 
      ADD_LOCAL_EQN(Oneway_Clutch, r_StickFrictionTorque)
      ADD_LOCAL_EQN(Oneway_Clutch, r_cSlipFrictionTorque)
      ADD_LOCAL_EQN(Oneway_Clutch, r_ccSlipFrictionTorque)
    
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
      
      ADD_LOCAL_EQN(Oneway_Clutch, z_cSlipTorque)
      ADD_LOCAL_EQN(Oneway_Clutch, z_ccSlipTorque)
      ADD_LOCAL_EQN(ClutchBase, s_cLockDisplacement)
      ADD_LOCAL_EQN(ClutchBase, s_ccLockDisplacement)
      ADD_LOCAL_EQN(Oneway_Clutch, s_cSlipDisplacement)
      ADD_LOCAL_EQN(Oneway_Clutch, s_ccSlipDisplacement)
    
      return S_OK;
    
    //#]
}

HRESULT Oneway_Clutch::InitLocalIPars(const _TCHAR * prefix, pplong * pars, ppchar * Names, long * nPars, long * dPars) {
    NOTIFY_OPERATION(InitLocalIPars, InitLocalIPars(const _TCHAR * ,pplong * ,ppchar * ,long * ,long * ), 0, TransmissionModels_Oneway_Clutch_InitLocalIPars_SERIALIZE);
    //#[ operation InitLocalIPars(const _TCHAR * ,pplong * ,ppchar * ,long * ,long * ) 
      ADD_LOCAL_SIPAR(nSurfaces)
    
      return S_OK;
    
    //#]
}

HRESULT Oneway_Clutch::InitLocalRPars(const _TCHAR * prefix, ppdouble * pars, ppchar * Names, long * nPars, long * dPars) {
    NOTIFY_OPERATION(InitLocalRPars, InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ), 0, TransmissionModels_Oneway_Clutch_InitLocalRPars_SERIALIZE);
    //#[ operation InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ) 
      ADD_LOCAL_SRPAR(area)
      ADD_LOCAL_SRPAR(radius)
      ADD_LOCAL_SRPAR(torqueRatio)
      ADD_LOCAL_SRPAR(damping)
      ADD_LOCAL_SRPAR(pressureMax)
      ADD_LOCAL_SRPAR(cBreakfreeDispMax)
      ADD_LOCAL_SRPAR(ccBreakfreeDispMax)
    
      return S_OK;
    
    //#]
}

HRESULT Oneway_Clutch::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    NOTIFY_OPERATION(InitLocalVars, InitLocalVars(const _TCHAR * ,VarCont * ,const bool ), 0, TransmissionModels_Oneway_Clutch_InitLocalVars_SERIALIZE);
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
      ADD_LOCAL_SVAR(relativeVelocity)
      ADD_LOCAL_SVAR(cBreakfreeDisp)
      ADD_LOCAL_SVAR(displacement)
      ADD_LOCAL_SVAR(ccBreakfreeDisp)
    
     for (long i = 0; i < m_nEsos; i++)
       AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
      return S_OK;
    
    //#]
}

HRESULT Oneway_Clutch::InitStates() {
    NOTIFY_OPERATION(InitStates, InitStates(), 0, TransmissionModels_Oneway_Clutch_InitStates_SERIALIZE);
    //#[ operation InitStates() 
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
    
    const long idx_eqn_z_cSlipTorque = 14;
    const long idx_eqn_z_ccSlipTorque = 15;
    const long idx_eqn_s_cLockDisplacement = 16;
    const long idx_eqn_s_ccLockDisplacement = 17;
    const long idx_eqn_s_cSlipDisplacement = 18;
    const long idx_eqn_s_ccSlipDisplacement = 19;
    
    
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
    
    //#]
}

HRESULT Oneway_Clutch::InitTransitions() {
    NOTIFY_OPERATION(InitTransitions, InitTransitions(), 0, TransmissionModels_Oneway_Clutch_InitTransitions_SERIALIZE);
    //#[ operation InitTransitions() 
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
    
    const long idx_eqn_z_cSlipTorque = 14;
    const long idx_eqn_z_ccSlipTorque = 15;
    const long idx_eqn_s_cLockDisplacement = 16;
    const long idx_eqn_s_ccLockDisplacement = 17;
    const long idx_eqn_s_cSlipDisplacement = 18;
    const long idx_eqn_s_ccSlipDisplacement = 19;
    
    
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
    
    // clockwise condition for lock to ccSlip (switch immediately upon velocity direction change)
    const long c_idx_eqns_es_LockToCCSlipLockccSlip[] = { 
      idx_eqn_z_velocity_neg,
      idx_eqn_z_ccSlipTorque,
      idx_eqn_s_ccSlipDisplacement,
     };
    
    // counter clockwise condition for lock to ccSlip (wait until p < break free displacement)
    const long cc_idx_eqns_es_LockToCCSlipLockccSlip[] = { 
      idx_eqn_z_velocity_neg,
      idx_eqn_z_disp_neg_slip,
     };
    
    // counter clockwise condition for lock to cSlip (switch immediately upon velocity direction change)
    const long cc_idx_eqns_es_LockToCSlipLockcSlip[] = { 
      idx_eqn_z_velocity_pos,
      idx_eqn_z_cSlipTorque,
      idx_eqn_s_cSlipDisplacement,
     };
    
    // clockwise condition for lock to cSlip (wait until p > break free displacement)
    const long c_idx_eqns_es_LockToCSlipLockcSlip[] = { 
      idx_eqn_z_velocity_pos,
      idx_eqn_z_disp_pos_slip,
     };
    
    // Transition_Name, Source_State, Event_Name, Transition_Eqns, Eqn_Count
    hr = AddTransition(L"es_SlipToLockccSlipLock", idx_state_ccSlip, L"es_SlipToLock", idx_eqns_es_SlipToLockccSlipLock, 2);
    if (FAILED(hr)) hrRet = hr;
    hr = AddTransition(L"es_SlipToLockcSlipLock", idx_state_cSlip, L"es_SlipToLock", idx_eqns_es_SlipToLockcSlipLock, 2);
    if (FAILED(hr)) hrRet = hr;
    
    if (direction == Direction_CLOCKWISE)
    {
      hr = AddTransition(L"es_LockToCCSlipLockccSlip", idx_state_Lock, L"es_LockToCCSlip", c_idx_eqns_es_LockToCCSlipLockccSlip, 3);
      if (FAILED(hr)) hrRet = hr;
      hr = AddTransition(L"es_LockToCSlipLockcSlip", idx_state_Lock, L"es_LockToCSlip", c_idx_eqns_es_LockToCSlipLockcSlip, 2);
      if (FAILED(hr)) hrRet = hr;
    }
    else
    {
      hr = AddTransition(L"es_LockToCCSlipLockccSlip", idx_state_Lock, L"es_LockToCCSlip", cc_idx_eqns_es_LockToCCSlipLockccSlip, 2);
      if (FAILED(hr)) hrRet = hr;
      hr = AddTransition(L"es_LockToCSlipLockcSlip", idx_state_Lock, L"es_LockToCSlip", cc_idx_eqns_es_LockToCSlipLockcSlip, 3);
      if (FAILED(hr)) hrRet = hr;
    }
    
    return hrRet;
    
    //#]
}

bool Oneway_Clutch::Load(FILE * fs) {
    NOTIFY_OPERATION(Load, Load(FILE * ), 0, TransmissionModels_Oneway_Clutch_Load_SERIALIZE);
    //#[ operation Load(FILE * ) 
    READ_SCALAR( rootState_active )
    return true;
    //#]
}

HRESULT Oneway_Clutch::OnTransition() {
    NOTIFY_OPERATION(OnTransition, OnTransition(), 0, TransmissionModels_Oneway_Clutch_OnTransition_SERIALIZE);
    //#[ operation OnTransition() 
    HRESULT hr = S_OK;
    
    const long idx_state_ccSlip = 0;
    const long idx_state_cSlip = 1;
    const long idx_state_Lock = 2;
    
    // Cg_Add (fixed references to base class (wizard fix))
    if (rootState_active == ccSlip)
    {
        ATLTRACE("\nccSlip");
        hr = PostTransition(idx_state_ccSlip);
    }
    else if (rootState_active == cSlip)
    {
        ATLTRACE("\ncSlip");
        hr = PostTransition(idx_state_cSlip);
    }
    else if (rootState_active == Lock)
    {
        ATLTRACE("\nLock");
        hr = PostTransition(idx_state_Lock);
    }
      
    #if 1
      //ATLTRACE("\ndisplacement: %e cBreakfreeDisp: %e ccBreakfreeDisp: %e relativeVelocity: %e", displacement, cBreakfreeDisp, ccBreakfreeDisp, relativeVelocity);
    #endif
    
    return hr;
    
    //#]
}

void Oneway_Clutch::Save(FILE * fs) {
    NOTIFY_OPERATION(Save, Save(FILE * ), 0, TransmissionModels_Oneway_Clutch_Save_SERIALIZE);
    //#[ operation Save(FILE * ) 
    WRITE_SCALAR( rootState_active )
    //#]
}

HRESULT Oneway_Clutch::TriggerEvent(const double EventTime, const BSTR bstrEventId) {
    NOTIFY_OPERATION(TriggerEvent, TriggerEvent(const double ,const BSTR ), 0, TransmissionModels_Oneway_Clutch_TriggerEvent_SERIALIZE);
    //#[ operation TriggerEvent(const double ,const BSTR ) 
    USES_CONVERSION;
    
    // filter high frequency content
    static double last_event_time = 0.0;
    if (fabs(EventTime - last_event_time) < 0.001)
      return S_OK;
    else
      last_event_time = EventTime;
    // end filter code

    CComBSTR EventId = bstrEventId;
    HRESULT hr = S_OK;
    
    if (EventId == L"es_SlipToLock")
    {
      es_SlipToLock ev;
      takeTrigger(&ev);
    }
    else if (EventId == L"es_LockToCCSlip")
    {
      es_LockToccSlip ev;
      takeTrigger(&ev);
    }
    else if (EventId == L"es_LockToCSlip")
    {
      es_LockTocSlip ev;
      takeTrigger(&ev);
    }
    
    m_time = EventTime;
    
    // update old variables
    OLD(relativeVelocity) = relativeVelocity;
    OLD(cBreakfreeDisp) = cBreakfreeDisp;
    OLD(displacement) = displacement;
    OLD(ccBreakfreeDisp) = ccBreakfreeDisp;
    
    return S_OK;
    
    //#]
}

HRESULT Oneway_Clutch::ad_r_StickFrictionTorque(Fdouble * res) {
    //#[ operation ad_r_StickFrictionTorque(Fdouble * ) 
    Fdouble ad_stiffness;
      
    frictionCoefficient=0.1545; // frictionCoefficient=0.1545;
    
    if (direction == Direction_CLOCKWISE)
      ad_stiffness=actuatorConnector->AD(pressure)*1000.0*area*radius*frictionCoefficient/(cBreakfreeDispMax + 1.0e-20) + 1.0e-10;
    else
      ad_stiffness=actuatorConnector->AD(pressure)*1000.0*area*radius*frictionCoefficient/(ccBreakfreeDispMax + 1.0e-20) + 1.0e-10;
    
    *res = p->AD(torque) - nSurfaces * ad_stiffness * (1+torqueRatio) * AD(displacement) 
           - ((actuatorConnector->AD(pressure) / pressureMax) + 1.0e-10) * damping * DER_AD(displacement);
    
    
    return S_OK;
    
    //#]
}

HRESULT Oneway_Clutch::ad_r_cSlipFrictionTorque(Fdouble * res) {
    //#[ operation ad_r_cSlipFrictionTorque(Fdouble * ) 
    Fdouble ad_stiffness;
    
    frictionCoefficient=0.0631+0.0504*exp(-0.033*fabs(relativeVelocity));
    double BreakfreeDispMax = cBreakfreeDispMax == 0.0 ? 1.0 : cBreakfreeDispMax;
    ad_stiffness=actuatorConnector->AD(pressure)*1000.0*area*radius*frictionCoefficient/(BreakfreeDispMax + 1.0e-20) + 1.0e-10;
    
    *res = p->AD(torque) - nSurfaces * ad_stiffness * AD(cBreakfreeDisp);
    
    return S_OK;
    
    //#]
}

HRESULT Oneway_Clutch::ad_r_ccSlipFrictionTorque(Fdouble * res) {
    //#[ operation ad_r_ccSlipFrictionTorque(Fdouble * ) 
    Fdouble ad_stiffness;
    
    frictionCoefficient=0.0631+0.0504*exp(-0.033*fabs(relativeVelocity));
    double BreakfreeDispMax = ccBreakfreeDispMax == 0.0 ? 1.0 : ccBreakfreeDispMax;
    ad_stiffness=actuatorConnector->AD(pressure)*1000.0*area*radius*frictionCoefficient/(BreakfreeDispMax + 1.0e-20) + 1.0e-10;
    
    *res = p->AD(torque) + nSurfaces * ad_stiffness * AD(ccBreakfreeDisp);
    
    return S_OK;
    
    //#]
}

HRESULT Oneway_Clutch::ad_s_cSlipDisplacement(Fdouble * res) {
    //#[ operation ad_s_cSlipDisplacement(Fdouble * ) 
    *res = AD(displacement) - (OLD(cBreakfreeDisp) + 1.0e-5);
    return S_OK;
    //#]
}

HRESULT Oneway_Clutch::ad_s_ccSlipDisplacement(Fdouble * res) {
    //#[ operation ad_s_ccSlipDisplacement(Fdouble * ) 
    *res = AD(displacement) - (-OLD(ccBreakfreeDisp) - 1.0e-5);
    return S_OK;
    //#]
}

HRESULT Oneway_Clutch::ad_z_cSlipTorque(Fdouble * res) {
    //#[ operation ad_z_cSlipTorque(Fdouble * ) 
    *res = p->AD(torque) - 1.0e-5;
    return S_OK;
    //#]
}

HRESULT Oneway_Clutch::ad_z_ccSlipTorque(Fdouble * res) {
    //#[ operation ad_z_ccSlipTorque(Fdouble * ) 
    *res = n->AD(torque) - 1.0e-5;
    return S_OK;
    //#]
}

void Oneway_Clutch::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, TransmissionModels_Oneway_Clutch_clean_SERIALIZE);
    //#[ operation clean() 
    ClutchBase::clean();
    //#]
}

void Oneway_Clutch::handle_area(const double t, const double * val) {
    NOTIFY_OPERATION(handle_area, handle_area(const double ,const double * ), 0, TransmissionModels_Oneway_Clutch_handle_area_SERIALIZE);
    //#[ operation handle_area(const double ,const double * ) 
    PostRealParameter(t, 0, *val);
    
    //#]
}

void Oneway_Clutch::handle_cBreakfreeDispMax(const double t, const double * val) {
    NOTIFY_OPERATION(handle_cBreakfreeDispMax, handle_cBreakfreeDispMax(const double ,const double * ), 0, TransmissionModels_Oneway_Clutch_handle_cBreakfreeDispMax_SERIALIZE);
    //#[ operation handle_cBreakfreeDispMax(const double ,const double * ) 
    PostRealParameter(t, 7, *val);
    
    //#]
}

void Oneway_Clutch::handle_ccBreakfreeDispMax(const double t, const double * val) {
    NOTIFY_OPERATION(handle_ccBreakfreeDispMax, handle_ccBreakfreeDispMax(const double ,const double * ), 0, TransmissionModels_Oneway_Clutch_handle_ccBreakfreeDispMax_SERIALIZE);
    //#[ operation handle_ccBreakfreeDispMax(const double ,const double * ) 
    PostRealParameter(t, 8, *val);
    
    //#]
}

void Oneway_Clutch::handle_damping(const double t, const double * val) {
    NOTIFY_OPERATION(handle_damping, handle_damping(const double ,const double * ), 0, TransmissionModels_Oneway_Clutch_handle_damping_SERIALIZE);
    //#[ operation handle_damping(const double ,const double * ) 
    PostRealParameter(t, 3, *val);
    
    //#]
}

void Oneway_Clutch::handle_frictionCoefficient(const double t, const double * val) {
    NOTIFY_OPERATION(handle_frictionCoefficient, handle_frictionCoefficient(const double ,const double * ), 0, TransmissionModels_Oneway_Clutch_handle_frictionCoefficient_SERIALIZE);
    //#[ operation handle_frictionCoefficient(const double ,const double * ) 
    PostRealParameter(t, 5, *val);
    
    //#]
}

void Oneway_Clutch::handle_nSurfaces(const double t, const long * val) {
    NOTIFY_OPERATION(handle_nSurfaces, handle_nSurfaces(const double ,const long * ), 0, TransmissionModels_Oneway_Clutch_handle_nSurfaces_SERIALIZE);
    //#[ operation handle_nSurfaces(const double ,const long * ) 
    PostIntegerParameter(t, 0, *val);
    
    //#]
}

void Oneway_Clutch::handle_pressureMax(const double t, const double * val) {
    NOTIFY_OPERATION(handle_pressureMax, handle_pressureMax(const double ,const double * ), 0, TransmissionModels_Oneway_Clutch_handle_pressureMax_SERIALIZE);
    //#[ operation handle_pressureMax(const double ,const double * ) 
    PostRealParameter(t, 6, *val);
    
    //#]
}

void Oneway_Clutch::handle_radius(const double t, const double * val) {
    NOTIFY_OPERATION(handle_radius, handle_radius(const double ,const double * ), 0, TransmissionModels_Oneway_Clutch_handle_radius_SERIALIZE);
    //#[ operation handle_radius(const double ,const double * ) 
    PostRealParameter(t, 1, *val);
    
    //#]
}

void Oneway_Clutch::handle_stiffness(const double t, const double * val) {
    NOTIFY_OPERATION(handle_stiffness, handle_stiffness(const double ,const double * ), 0, TransmissionModels_Oneway_Clutch_handle_stiffness_SERIALIZE);
    //#[ operation handle_stiffness(const double ,const double * ) 
    PostRealParameter(t, 4, *val);
    
    //#]
}

void Oneway_Clutch::handle_torqueRatio(const double t, const double * val) {
    NOTIFY_OPERATION(handle_torqueRatio, handle_torqueRatio(const double ,const double * ), 0, TransmissionModels_Oneway_Clutch_handle_torqueRatio_SERIALIZE);
    //#[ operation handle_torqueRatio(const double ,const double * ) 
    PostRealParameter(t, 2, *val);
    
    //#]
}

void Oneway_Clutch::init() {
    NOTIFY_OPERATION(init, init(), 0, TransmissionModels_Oneway_Clutch_init_SERIALIZE);
    //#[ operation init() 
    ClutchBase::init();
    
    nSurfaces=8;
    area=0.0075;
    direction=Direction_CLOCKWISE;
    cBreakfreeDisp= 1.0e-3;  
    der(cBreakfreeDisp)=0.0;
    ccBreakfreeDisp=0.0;
    der(ccBreakfreeDisp)=0.0;
    
    if(direction==Direction_CLOCKWISE)
    {
      cBreakfreeDispMax=1.0e-2; 
      ccBreakfreeDispMax=0.0;
      cOilDisp = 1.0e-4;
      ccOilDisp = 0.0;
    }
    else
    {
      cBreakfreeDispMax=0.0;
      ccBreakfreeDispMax=1.0e-2; 
      cOilDisp = 0.0;
      ccOilDisp = 1.0e-4;
    }
    
    damping=100000.0;
    displacement=0.0;
    DER(displacement) = 0.0;
    frictionCoefficient=0.0631+0.0504*exp(-0.033*fabs(relativeVelocity));
    actuatorConnector->pressure = 0.0;
    pressureMax=1000.0;
    radius=0.055;
    relativeVelocity=0.0; 
    DER(relativeVelocity) = 0.0;
    stiffness=actuatorConnector->pressure*1000.0*area*radius*frictionCoefficient/(cBreakfreeDisp + 1.0e-20);
    p->torque = 0.0;
    torqueRatio = 0.3; 
    
    //#]
}

HRESULT Oneway_Clutch::r_StickFrictionTorque(double * res) {
    //#[ operation r_StickFrictionTorque(double * ) 
    frictionCoefficient=0.1545; // frictionCoefficient=0.1545;
    
    if (direction == Direction_CLOCKWISE)
      stiffness=actuatorConnector->pressure*1000.0*area*radius*frictionCoefficient/(cBreakfreeDispMax + 1.0e-20) + 1.0e-10;
    else
      stiffness=actuatorConnector->pressure*1000.0*area*radius*frictionCoefficient/(ccBreakfreeDispMax + 1.0e-20) + 1.0e-10;
    
    *res = p->torque - nSurfaces * stiffness * (1+torqueRatio) * displacement 
           - ((actuatorConnector->pressure / pressureMax) + 1.0e-10) * damping * DER(displacement);
    
    
    return S_OK;
    
    //#]
}

HRESULT Oneway_Clutch::r_cSlipFrictionTorque(double * res) {
    //#[ operation r_cSlipFrictionTorque(double * ) 
    frictionCoefficient=0.0631+0.0504*exp(-0.033*fabs(relativeVelocity));
    double BreakfreeDispMax = cBreakfreeDispMax == 0.0 ? 1.0 : cBreakfreeDispMax;
    stiffness=actuatorConnector->pressure*1000.0*area*radius*frictionCoefficient/(BreakfreeDispMax + 1.0e-20) + 1.0e-10;
    
    *res = p->torque - nSurfaces * stiffness * cBreakfreeDisp;
    
    return S_OK;
    
    //#]
}

HRESULT Oneway_Clutch::r_ccSlipFrictionTorque(double * res) {
    //#[ operation r_ccSlipFrictionTorque(double * ) 
    frictionCoefficient=0.0631+0.0504*exp(-0.033*fabs(relativeVelocity));
    double BreakfreeDispMax = ccBreakfreeDispMax == 0.0 ? 1.0 : ccBreakfreeDispMax;
    stiffness=actuatorConnector->pressure*1000.0*area*radius*frictionCoefficient/(BreakfreeDispMax + 1.0e-20) + 1.0e-10;
    
    *res = p->torque + nSurfaces * stiffness * ccBreakfreeDisp;
    
    return S_OK;
    
    //#]
}

HRESULT Oneway_Clutch::s_cSlipDisplacement(double * res) {
    //#[ operation s_cSlipDisplacement(double * ) 
    *res = displacement - (OLD(cBreakfreeDisp) + 1.0e-5);
    return S_OK;
    //#]
}

HRESULT Oneway_Clutch::s_ccSlipDisplacement(double * res) {
    //#[ operation s_ccSlipDisplacement(double * ) 
    *res = displacement - (-OLD(ccBreakfreeDisp) - 1.0e-5);
    return S_OK;
    //#]
}

HRESULT Oneway_Clutch::z_cSlipTorque(double * res) {
    //#[ operation z_cSlipTorque(double * ) 
    *res = p->torque - 1.0e-5;
    return S_OK;
    //#]
}

HRESULT Oneway_Clutch::z_ccSlipTorque(double * res) {
    //#[ operation z_ccSlipTorque(double * ) 
    *res = n->torque - 1.0e-5;
    return S_OK;
    //#]
}

Direction  Oneway_Clutch::getDirection() const {
    return direction;
}

void Oneway_Clutch::setDirection(Direction p_direction) {
    direction = p_direction;
}

long Oneway_Clutch::getNSurfaces() const {
    return nSurfaces;
}

void Oneway_Clutch::setNSurfaces(long  p_nSurfaces) {
    nSurfaces = p_nSurfaces;
}

void Oneway_Clutch::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        NOTIFY_STATE_ENTERED("ROOT.Lock");
        rootState_subState = Lock;
        rootState_active = Lock;
        //#[ state ROOT.Lock.(Entry) 
        if (!bInConstruction) OnTransition();
        //#]
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

int Oneway_Clutch::rootState_dispatchEvent(short  id) {
    int res = eventNotConsumed;
    switch (rootState_active) {
        case cSlip:
        {
            if(IS_EVENT_TYPE_OF(es_SlipToLock_TransmissionModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("1");
                    NOTIFY_STATE_EXITED("ROOT.cSlip");
                    NOTIFY_STATE_ENTERED("ROOT.Lock");
                    rootState_subState = Lock;
                    rootState_active = Lock;
                    //#[ state ROOT.Lock.(Entry) 
                    if (!bInConstruction) OnTransition();
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("1");
                    res = eventConsumed;
                }
            
            break;
        };
        case Lock:
        {
            if(IS_EVENT_TYPE_OF(es_LockTocSlip_TransmissionModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("2");
                    NOTIFY_STATE_EXITED("ROOT.Lock");
                    NOTIFY_STATE_ENTERED("ROOT.cSlip");
                    rootState_subState = cSlip;
                    rootState_active = cSlip;
                    //#[ state ROOT.cSlip.(Entry) 
                    if (!bInConstruction) OnTransition();
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("2");
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(es_LockToccSlip_TransmissionModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("4");
                    NOTIFY_STATE_EXITED("ROOT.Lock");
                    NOTIFY_STATE_ENTERED("ROOT.ccSlip");
                    rootState_subState = ccSlip;
                    rootState_active = ccSlip;
                    //#[ state ROOT.ccSlip.(Entry) 
                    if (!bInConstruction) OnTransition();
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("4");
                    res = eventConsumed;
                }
            
            break;
        };
        case ccSlip:
        {
            if(IS_EVENT_TYPE_OF(es_SlipToLock_TransmissionModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("3");
                    NOTIFY_STATE_EXITED("ROOT.ccSlip");
                    NOTIFY_STATE_ENTERED("ROOT.Lock");
                    rootState_subState = Lock;
                    rootState_active = Lock;
                    //#[ state ROOT.Lock.(Entry) 
                    if (!bInConstruction) OnTransition();
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("3");
                    res = eventConsumed;
                }
            
            break;
        };
        default:
            break;
    };
    return res;
}

void Oneway_Clutch::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

OMBoolean Oneway_Clutch::startBehavior() {
    OMBoolean done = FALSE;
    done = ClutchBase::startBehavior();
    return done;
}



#ifdef _OMINSTRUMENT


void OMAnimatedOneway_Clutch::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
    OMAnimatedClutchBase::serializeAttributes(aomsAttributes);
}

void OMAnimatedOneway_Clutch::serializeRelations(AOMSRelations*  aomsRelations) const {
    OMAnimatedClutchBase::serializeRelations(aomsRelations);
}

void OMAnimatedOneway_Clutch::rootState_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case Oneway_Clutch::cSlip:
        {
            cSlip_serializeStates(aomsState);
            break;
        };
        case Oneway_Clutch::Lock:
        {
            Lock_serializeStates(aomsState);
            break;
        };
        case Oneway_Clutch::ccSlip:
        {
            ccSlip_serializeStates(aomsState);
            break;
        };
        default:
            break;
    };
}

void OMAnimatedOneway_Clutch::Lock_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Lock");
}

void OMAnimatedOneway_Clutch::cSlip_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.cSlip");
}

void OMAnimatedOneway_Clutch::ccSlip_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.ccSlip");
}

IMPLEMENT_REACTIVE_META_S(Oneway_Clutch, FALSE, ClutchBase, OMAnimatedClutchBase, OMAnimatedOneway_Clutch)
OMINIT_SUPERCLASS(ClutchBase, OMAnimatedClutchBase)
OMREGISTER_REACTIVE_CLASS
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Oneway_Clutch.cpp
*********************************************************************/

