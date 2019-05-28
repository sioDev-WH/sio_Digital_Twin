/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Torque_Converter
//!	Generated Date	: Thu, 9, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Torque_Converter.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 


#define _OMSTATECHART_ANIMATED 
//#]

#include "Torque_Converter.h"
#include "CRigidConnector.h"
#include "stdafx.h"
#include "math.h"

//## package TransmissionModels 


//#[ ignore 
#define TransmissionModels_Torque_Converter_Torque_Converter_SERIALIZE OM_NO_OP


#define TransmissionModels_Torque_Converter_EvalStateCondition_SERIALIZE OM_NO_OP


#define TransmissionModels_Torque_Converter_InitEqnForm_SERIALIZE OM_NO_OP


#define TransmissionModels_Torque_Converter_InitEsos_SERIALIZE OM_NO_OP


#define TransmissionModels_Torque_Converter_InitLocalADEqns_SERIALIZE OM_NO_OP


#define TransmissionModels_Torque_Converter_InitLocalEqns_SERIALIZE OM_NO_OP


#define TransmissionModels_Torque_Converter_InitLocalRPars_SERIALIZE OM_NO_OP


#define TransmissionModels_Torque_Converter_InitLocalVars_SERIALIZE OM_NO_OP


#define TransmissionModels_Torque_Converter_InitStates_SERIALIZE OM_NO_OP


#define TransmissionModels_Torque_Converter_InitTransitions_SERIALIZE OM_NO_OP


#define TransmissionModels_Torque_Converter_Load_SERIALIZE OM_NO_OP


#define TransmissionModels_Torque_Converter_OnTransition_SERIALIZE OM_NO_OP


#define TransmissionModels_Torque_Converter_Save_SERIALIZE OM_NO_OP


#define TransmissionModels_Torque_Converter_TriggerEvent_SERIALIZE OM_NO_OP


#define TransmissionModels_Torque_Converter_clean_SERIALIZE OM_NO_OP


#define TransmissionModels_Torque_Converter_handle_impellerInertia_SERIALIZE OM_NO_OP


#define TransmissionModels_Torque_Converter_handle_turbineInertia_SERIALIZE OM_NO_OP


#define TransmissionModels_Torque_Converter_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// Torque_Converter.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(TransmissionModels)
//## class Torque_Converter 



Torque_Converter::Torque_Converter(OMThread*  p_thread) {
    NOTIFY_REACTIVE_CONSTRUCTOR(Torque_Converter, Torque_Converter(), 0, TransmissionModels_Torque_Converter_Torque_Converter_SERIALIZE);
    setThread(p_thread, FALSE);
    impeller = NULL;
    turbine = NULL;
    initStatechart();
    //#[ operation Torque_Converter() 
    init();
    startBehavior();
    //#]
}

Torque_Converter::~Torque_Converter() {
    NOTIFY_DESTRUCTOR(~Torque_Converter, TRUE);
    //#[ operation ~Torque_Converter() 
    clean();
    //#]
    cleanUpRelations();
}

HRESULT Torque_Converter::EvalStateCondition(const bool * EqnState, const double * x, const double * xdot, const double EventTime, const long iDisEqn, const long iTransition, bool * bEvent) {
    NOTIFY_OPERATION(EvalStateCondition, EvalStateCondition(const bool * ,const double * ,const double * ,const double ,const long ,const long ,bool * ), 0, TransmissionModels_Torque_Converter_EvalStateCondition_SERIALIZE);
    //#[ operation EvalStateCondition(const bool * ,const double * ,const double * ,const double ,const long ,const long ,bool * ) 
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
    if (rootState_active == Fluid_Coupling)
    {
        currentState = idx_state_Fluid_Coupling;
    }
    else if (rootState_active == Torque_Multiplication)
    {
        currentState = idx_state_Torque_Multiplication;
    }
    else if (rootState_active == Locked)
    {
        currentState = idx_state_Locked;
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
    
    //#]
}

HRESULT Torque_Converter::InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form) {
    NOTIFY_OPERATION(InitEqnForm, InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ), 0, TransmissionModels_Torque_Converter_InitEqnForm_SERIALIZE);
    //#[ operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
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
    
    //#]
}

HRESULT Torque_Converter::InitEsos() {
    NOTIFY_OPERATION(InitEsos, InitEsos(), 0, TransmissionModels_Torque_Converter_InitEsos_SERIALIZE);
    //#[ operation InitEsos() 
      ADD_LOCAL_ESO(turbine)
      ADD_LOCAL_ESO(impeller)
    
      return S_OK;
    
    //#]
}

HRESULT Torque_Converter::InitLocalADEqns() {
    NOTIFY_OPERATION(InitLocalADEqns, InitLocalADEqns(), 0, TransmissionModels_Torque_Converter_InitLocalADEqns_SERIALIZE);
    //#[ operation InitLocalADEqns() 
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
    
    //#]
}

HRESULT Torque_Converter::InitLocalEqns() {
    NOTIFY_OPERATION(InitLocalEqns, InitLocalEqns(), 0, TransmissionModels_Torque_Converter_InitLocalEqns_SERIALIZE);
    //#[ operation InitLocalEqns() 
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
    
    //#]
}

HRESULT Torque_Converter::InitLocalRPars(const _TCHAR * prefix, ppdouble * pars, ppchar * Names, long * nPars, long * dPars) {
    NOTIFY_OPERATION(InitLocalRPars, InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ), 0, TransmissionModels_Torque_Converter_InitLocalRPars_SERIALIZE);
    //#[ operation InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ) 
      ADD_LOCAL_SRPAR(turbineInertia)
      ADD_LOCAL_SRPAR(impellerInertia)
    
      return S_OK;
    
    //#]
}

HRESULT Torque_Converter::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    NOTIFY_OPERATION(InitLocalVars, InitLocalVars(const _TCHAR * ,VarCont * ,const bool ), 0, TransmissionModels_Torque_Converter_InitLocalVars_SERIALIZE);
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
      ADD_LOCAL_SVAR(turbineTorque)
      ADD_LOCAL_SVAR(turbineSpeed)
      ADD_LOCAL_SVAR(impellerTorque)
      ADD_LOCAL_SVAR(impellerSpeed)
    
     for (long i = 0; i < m_nEsos; i++)
       AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
      return S_OK;
    
    //#]
}

HRESULT Torque_Converter::InitStates() {
    NOTIFY_OPERATION(InitStates, InitStates(), 0, TransmissionModels_Torque_Converter_InitStates_SERIALIZE);
    //#[ operation InitStates() 
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
    
    //#]
}

HRESULT Torque_Converter::InitTransitions() {
    NOTIFY_OPERATION(InitTransitions, InitTransitions(), 0, TransmissionModels_Torque_Converter_InitTransitions_SERIALIZE);
    //#[ operation InitTransitions() 
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
    
    //#]
}

bool Torque_Converter::Load(FILE * fs) {
    NOTIFY_OPERATION(Load, Load(FILE * ), 0, TransmissionModels_Torque_Converter_Load_SERIALIZE);
    //#[ operation Load(FILE * ) 
      READ_SCALAR( rootState_active )
      return true;
    
    //#]
}

HRESULT Torque_Converter::OnTransition() {
    NOTIFY_OPERATION(OnTransition, OnTransition(), 0, TransmissionModels_Torque_Converter_OnTransition_SERIALIZE);
    //#[ operation OnTransition() 
    HRESULT hr = S_OK;
    
    const long idx_state_Fluid_Coupling = 0;
    const long idx_state_Torque_Multiplication = 1;
    const long idx_state_Locked = 2;
    
    if (rootState_active == Fluid_Coupling)
    {
        ATLTRACE("\nFluid_Coupling");
        PostTransition(idx_state_Fluid_Coupling);
    }
    else if (rootState_active == Torque_Multiplication) 
    {
        ATLTRACE("\nTorque_Multiplication");
        PostTransition(idx_state_Torque_Multiplication);
    }
    else if (rootState_active == Locked)
    {
        ATLTRACE("\nLocked");
        PostTransition(idx_state_Locked);
    }
    
    return hr;
    
    //#]
}

void Torque_Converter::Save(FILE * fs) {
    NOTIFY_OPERATION(Save, Save(FILE * ), 0, TransmissionModels_Torque_Converter_Save_SERIALIZE);
    //#[ operation Save(FILE * ) 
      WRITE_SCALAR( rootState_active )
    
    //#]
}

HRESULT Torque_Converter::TriggerEvent(const double EventTime, const BSTR bstrEventId) {
    NOTIFY_OPERATION(TriggerEvent, TriggerEvent(const double ,const BSTR ), 0, TransmissionModels_Torque_Converter_TriggerEvent_SERIALIZE);
    //#[ operation TriggerEvent(const double ,const BSTR ) 
    USES_CONVERSION;
    
    CComBSTR EventId = bstrEventId;
    HRESULT hr = S_OK;
    
    if (EventId == L"es_TMM")
    {
      es_TMM ev;
      takeTrigger(&ev);
    }
    else if (EventId == L"es_FCM")
    {
      es_FCM ev;
      takeTrigger(&ev);
    }
    else if (EventId == L"es_Lock")
    {
      es_Lock ev;
      takeTrigger(&ev);
    }
    
    m_time = EventTime;
    
    // update old variables
    OLD(turbineTorque) = turbineTorque;
    OLD(turbineSpeed) = turbineSpeed;
    OLD(impellerTorque) = impellerTorque;
    OLD(impellerSpeed) = impellerSpeed;
    
    return S_OK;
    
    //#]
}

HRESULT Torque_Converter::ad_r_FCM_ImpellerTorque(Fdouble * res) {
    //#[ operation ad_r_FCM_ImpellerTorque(Fdouble * ) 
      *res = AD(impellerTorque) - 
        ( c[7] * AD(impellerSpeed) * AD(impellerSpeed) + 
          c[8] * AD(impellerSpeed) * AD(turbineSpeed) + 
          c[9] * AD(turbineSpeed) * AD(turbineSpeed));
    
    
    return S_OK;
    
    //#]
}

HRESULT Torque_Converter::ad_r_FCM_TurbineTorque(Fdouble * res) {
    //#[ operation ad_r_FCM_TurbineTorque(Fdouble * ) 
      *res = AD(turbineTorque) - AD(impellerTorque);
    return S_OK;
    
    //#]
}

HRESULT Torque_Converter::ad_r_ImpellerNewton(Fdouble * res) {
    //#[ operation ad_r_ImpellerNewton(Fdouble * ) 
      *res = impeller->AD(torque) - impellerInertia * impeller->AD(acceleration) - AD(impellerTorque);
    return S_OK;
    
    //#]
}

HRESULT Torque_Converter::ad_r_ImpellerSpeed(Fdouble * res) {
    //#[ operation ad_r_ImpellerSpeed(Fdouble * ) 
    #define PI 3.1415926535897932384626433832795
    #define W_TO_RPM (60.0 / (2 * PI))
    
      *res = DER_AD(impellerSpeed) - impeller->AD(acceleration);
    return S_OK;
    
    //#]
}

HRESULT Torque_Converter::ad_r_SpeedLocked(Fdouble * res) {
    //#[ operation ad_r_SpeedLocked(Fdouble * ) 
      *res = impeller->AD(acceleration) - turbine->AD(acceleration);
      return S_OK;
    
    //#]
}

HRESULT Torque_Converter::ad_r_TMM_ImpellerTorque(Fdouble * res) {
    //#[ operation ad_r_TMM_ImpellerTorque(Fdouble * ) 
      *res = AD(impellerTorque) - 
        ( c[1] * AD(impellerSpeed) * AD(impellerSpeed) + 
          c[2] * AD(impellerSpeed) * AD(turbineSpeed) + 
          c[3] * AD(turbineSpeed) * AD(turbineSpeed));
    
    
    return S_OK;
    
    //#]
}

HRESULT Torque_Converter::ad_r_TMM_TurbineTorque(Fdouble * res) {
    //#[ operation ad_r_TMM_TurbineTorque(Fdouble * ) 
      *res = AD(turbineTorque) - 
        ( c[4] * AD(impellerSpeed) * AD(impellerSpeed) + 
          c[5] * AD(impellerSpeed) * AD(turbineSpeed) + 
          c[6] * AD(turbineSpeed) * AD(turbineSpeed));
    
    
    return S_OK;
    
    //#]
}

HRESULT Torque_Converter::ad_r_TurbineNewton(Fdouble * res) {
    //#[ operation ad_r_TurbineNewton(Fdouble * ) 
      *res = AD(turbineTorque) - turbineInertia * turbine->AD(acceleration) + turbine->AD(torque) ;
    return S_OK;
    
    //#]
}

HRESULT Torque_Converter::ad_r_TurbineSpeed(Fdouble * res) {
    //#[ operation ad_r_TurbineSpeed(Fdouble * ) 
    #define PI 3.1415926535897932384626433832795
    #define W_TO_RPM (60.0 / (2 * PI))
    
      *res = DER_AD(turbineSpeed) - turbine->AD(acceleration);
    return S_OK;
    
    //#]
}

HRESULT Torque_Converter::ad_z_ImpellerTorque_lt_TurbineTorque(Fdouble * res) {
    //#[ operation ad_z_ImpellerTorque_lt_TurbineTorque(Fdouble * ) 
    *res = turbine->AD(torque) - impeller->AD(torque);
    return S_OK;
    //#]
}

HRESULT Torque_Converter::ad_z_Speed_gt_LockedSpeed(Fdouble * res) {
    //#[ operation ad_z_Speed_gt_LockedSpeed(Fdouble * ) 
      *res = AD(turbineSpeed) - AD(impellerSpeed);
      return S_OK;
    
    //#]
}

HRESULT Torque_Converter::ad_z_Speed_lt_LockedSpeed(Fdouble * res) {
    //#[ operation ad_z_Speed_lt_LockedSpeed(Fdouble * ) 
      *res = ( c[7] + c[8] + c[9] ) - ( AD(impellerTorque) / (AD(impellerSpeed) * AD(impellerSpeed)) ); 
    
      return S_OK;
    
    //#]
}

HRESULT Torque_Converter::ad_z_TorqueRatio_gt_one(Fdouble * res) {
    //#[ operation ad_z_TorqueRatio_gt_one(Fdouble * ) 
      Fdouble ad_speedRatio;
    
      if(fabs(impellerSpeed) > 1e-10)
        ad_speedRatio = AD(turbineSpeed) / AD(impellerSpeed);
      else
        ad_speedRatio = AD(turbineSpeed) / (AD(impellerSpeed) + 1e-10);
    
      *res = 0.90 - ad_speedRatio;
    return S_OK;
    
    //#]
}

HRESULT Torque_Converter::ad_z_TorqueRatio_lt_one(Fdouble * res) {
    //#[ operation ad_z_TorqueRatio_lt_one(Fdouble * ) 
      Fdouble ad_speedRatio;
    
      if(fabs(impellerSpeed) > 1e-10)
        ad_speedRatio = AD(turbineSpeed) / AD(impellerSpeed);
      else
        ad_speedRatio = AD(turbineSpeed) / (AD(impellerSpeed) + 1e-10);
    
      *res = ad_speedRatio - 0.90;
    return S_OK;
    
    //#]
}

void Torque_Converter::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, TransmissionModels_Torque_Converter_clean_SERIALIZE);
    //#[ operation clean() 
    if (impeller)
    {
      impeller->Release();
      impeller = NULL;
    }
    
    if (turbine)
    {
      turbine->Release();
      turbine = NULL;
    }  
    //#]
}

void Torque_Converter::handle_impellerInertia(const double t, double * val) {
    NOTIFY_OPERATION(handle_impellerInertia, handle_impellerInertia(const double ,double * ), 0, TransmissionModels_Torque_Converter_handle_impellerInertia_SERIALIZE);
    //#[ operation handle_impellerInertia(const double ,double * ) 
    PostRealParameter(t, 1, *val);
    
    //#]
}

void Torque_Converter::handle_turbineInertia(const double t, double * val) {
    NOTIFY_OPERATION(handle_turbineInertia, handle_turbineInertia(const double ,double * ), 0, TransmissionModels_Torque_Converter_handle_turbineInertia_SERIALIZE);
    //#[ operation handle_turbineInertia(const double ,double * ) 
    PostRealParameter(t, 0, *val);
    
    //#]
}

void Torque_Converter::init() {
    NOTIFY_OPERATION(init, init(), 0, TransmissionModels_Torque_Converter_init_SERIALIZE);
    //#[ operation init() 
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
    
    //#]
}

HRESULT Torque_Converter::r_FCM_ImpellerTorque(double * res) {
    //#[ operation r_FCM_ImpellerTorque(double * ) 
      *res = impellerTorque - 
        ( c[7] * impellerSpeed * impellerSpeed + 
          c[8] * impellerSpeed * turbineSpeed + 
          c[9] * turbineSpeed * turbineSpeed);
    
    
    return S_OK;
    
    //#]
}

HRESULT Torque_Converter::r_FCM_TurbineTorque(double * res) {
    //#[ operation r_FCM_TurbineTorque(double * ) 
      *res = turbineTorque - impellerTorque;
    return S_OK;
    
    //#]
}

HRESULT Torque_Converter::r_ImpellerNewton(double * res) {
    //#[ operation r_ImpellerNewton(double * ) 
      *res = impeller->torque - impellerInertia * impeller->acceleration - impellerTorque;
    return S_OK;
    
    //#]
}

HRESULT Torque_Converter::r_ImpellerSpeed(double * res) {
    //#[ operation r_ImpellerSpeed(double * ) 
    #define PI 3.1415926535897932384626433832795
    #define W_TO_RPM (60.0 / (2 * PI))
    
      *res = DER(impellerSpeed) - impeller->acceleration;
    return S_OK;
    
    //#]
}

HRESULT Torque_Converter::r_SpeedLocked(double * res) {
    //#[ operation r_SpeedLocked(double * ) 
      *res = impeller->acceleration - turbine->acceleration;
      return S_OK;
    
    //#]
}

HRESULT Torque_Converter::r_TMM_ImpellerTorque(double * res) {
    //#[ operation r_TMM_ImpellerTorque(double * ) 
      *res = impellerTorque - 
        ( c[1] * impellerSpeed * impellerSpeed + 
          c[2] * impellerSpeed * turbineSpeed + 
          c[3] * turbineSpeed * turbineSpeed);
    
    return S_OK;
    
    //#]
}

HRESULT Torque_Converter::r_TMM_TurbineTorque(double * res) {
    //#[ operation r_TMM_TurbineTorque(double * ) 
      *res = turbineTorque - 
        ( c[4] * impellerSpeed * impellerSpeed + 
          c[5] * impellerSpeed * turbineSpeed + 
          c[6] * turbineSpeed * turbineSpeed);
    
    
    return S_OK;
    
    //#]
}

HRESULT Torque_Converter::r_TurbineNewton(double * res) {
    //#[ operation r_TurbineNewton(double * ) 
      *res = turbineTorque - turbineInertia * turbine->acceleration + turbine->torque ;
      return S_OK;
    
    //#]
}

HRESULT Torque_Converter::r_TurbineSpeed(double * res) {
    //#[ operation r_TurbineSpeed(double * ) 
    #define PI 3.1415926535897932384626433832795
    #define W_TO_RPM (60.0 / (2 * PI))
    
      *res = DER(turbineSpeed) - turbine->acceleration;
    return S_OK;
    
    //#]
}

HRESULT Torque_Converter::z_ImpellerTorque_lt_TurbineTorque(double * res) {
    //#[ operation z_ImpellerTorque_lt_TurbineTorque(double * ) 
    *res = turbine->torque - impeller->torque;
    return S_OK;
    //#]
}

HRESULT Torque_Converter::z_Speed_gt_LockedSpeed(double * res) {
    //#[ operation z_Speed_gt_LockedSpeed(double * ) 
      *res = turbineSpeed - impellerSpeed;
      return S_OK;
    
    //#]
}

HRESULT Torque_Converter::z_Speed_lt_LockedSpeed(double * res) {
    //#[ operation z_Speed_lt_LockedSpeed(double * ) 
      // speed ratio = 1.0, therefore
      //   (torque / speed^2) = c[7] + c[8] * ratio + c[9] * ratio^2, therefore
      //   (torque / speed^2) = c[7] + c[8] + c[9] 
      *res = ( c[7] + c[8] + c[9] ) - ( impellerTorque / (impellerSpeed * impellerSpeed) ); 
      return S_OK;
    
    //#]
}

HRESULT Torque_Converter::z_TorqueRatio_gt_one(double * res) {
    //#[ operation z_TorqueRatio_gt_one(double * ) 
      double speedRatio;
    
      if(fabs(impellerSpeed) > 1e-10)
        speedRatio = turbineSpeed / impellerSpeed;
      else
        speedRatio = turbineSpeed / (impellerSpeed + 1e-10);
    
      *res = 0.9 - speedRatio;
    return S_OK;
    
    //#]
}

HRESULT Torque_Converter::z_TorqueRatio_lt_one(double * res) {
    //#[ operation z_TorqueRatio_lt_one(double * ) 
      double speedRatio;
    
      if(fabs(impellerSpeed) > 1e-10)
        speedRatio = turbineSpeed / impellerSpeed;
      else
        speedRatio = turbineSpeed / (impellerSpeed + 1e-10);
    
      *res = speedRatio - 0.9;
    return S_OK;
    
    //#]
}

VarEx Torque_Converter::get_impellerSpeed() const {
    return _impellerSpeed;
}

void Torque_Converter::set_impellerSpeed(VarEx  p__impellerSpeed) {
    _impellerSpeed = p__impellerSpeed;
}

VarEx Torque_Converter::get_impellerTorque() const {
    return _impellerTorque;
}

void Torque_Converter::set_impellerTorque(VarEx  p__impellerTorque) {
    _impellerTorque = p__impellerTorque;
}

VarEx Torque_Converter::get_turbineSpeed() const {
    return _turbineSpeed;
}

void Torque_Converter::set_turbineSpeed(VarEx  p__turbineSpeed) {
    _turbineSpeed = p__turbineSpeed;
}

VarEx Torque_Converter::get_turbineTorque() const {
    return _turbineTorque;
}

void Torque_Converter::set_turbineTorque(VarEx  p__turbineTorque) {
    _turbineTorque = p__turbineTorque;
}

double Torque_Converter::getC(int  i1) const {
    return c[i1];
}

void Torque_Converter::setC(int  i1, double  p_c) {
    c[i1] = p_c;
}

double Torque_Converter::getImpellerInertia() const {
    return impellerInertia;
}

void Torque_Converter::setImpellerInertia(double  p_impellerInertia) {
    impellerInertia = p_impellerInertia;
}

double Torque_Converter::getImpellerSpeed() const {
    return impellerSpeed;
}

void Torque_Converter::setImpellerSpeed(double  p_impellerSpeed) {
    impellerSpeed = p_impellerSpeed;
}

double Torque_Converter::getImpellerTorque() const {
    return impellerTorque;
}

void Torque_Converter::setImpellerTorque(double  p_impellerTorque) {
    impellerTorque = p_impellerTorque;
}

double Torque_Converter::getTurbineInertia() const {
    return turbineInertia;
}

void Torque_Converter::setTurbineInertia(double  p_turbineInertia) {
    turbineInertia = p_turbineInertia;
}

double Torque_Converter::getTurbineSpeed() const {
    return turbineSpeed;
}

void Torque_Converter::setTurbineSpeed(double  p_turbineSpeed) {
    turbineSpeed = p_turbineSpeed;
}

double Torque_Converter::getTurbineTorque() const {
    return turbineTorque;
}

void Torque_Converter::setTurbineTorque(double  p_turbineTorque) {
    turbineTorque = p_turbineTorque;
}

CRigidConnector* Torque_Converter::getImpeller() const {
    return impeller;
}

void Torque_Converter::setImpeller(CRigidConnector*  p_CRigidConnector) {
    impeller = p_CRigidConnector;
    if(p_CRigidConnector != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("impeller", p_CRigidConnector, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("impeller");
        }
}

CRigidConnector* Torque_Converter::getTurbine() const {
    return turbine;
}

void Torque_Converter::setTurbine(CRigidConnector*  p_CRigidConnector) {
    turbine = p_CRigidConnector;
    if(p_CRigidConnector != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("turbine", p_CRigidConnector, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("turbine");
        }
}

void Torque_Converter::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("4");
        NOTIFY_STATE_ENTERED("ROOT.Torque_Multiplication");
        rootState_subState = Torque_Multiplication;
        rootState_active = Torque_Multiplication;
        NOTIFY_TRANSITION_TERMINATED("4");
    }
}

int Torque_Converter::rootState_dispatchEvent(short  id) {
    int res = eventNotConsumed;
    switch (rootState_active) {
        case Torque_Multiplication:
        {
            if(IS_EVENT_TYPE_OF(es_FCM_TransmissionModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("1");
                    NOTIFY_STATE_EXITED("ROOT.Torque_Multiplication");
                    NOTIFY_STATE_ENTERED("ROOT.Fluid_Coupling");
                    rootState_subState = Fluid_Coupling;
                    rootState_active = Fluid_Coupling;
                    NOTIFY_TRANSITION_TERMINATED("1");
                    res = eventConsumed;
                }
            
            break;
        };
        case Fluid_Coupling:
        {
            if(IS_EVENT_TYPE_OF(es_TMM_TransmissionModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("0");
                    NOTIFY_STATE_EXITED("ROOT.Fluid_Coupling");
                    NOTIFY_STATE_ENTERED("ROOT.Torque_Multiplication");
                    rootState_subState = Torque_Multiplication;
                    rootState_active = Torque_Multiplication;
                    NOTIFY_TRANSITION_TERMINATED("0");
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(es_Lock_TransmissionModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("3");
                    NOTIFY_STATE_EXITED("ROOT.Fluid_Coupling");
                    NOTIFY_STATE_ENTERED("ROOT.Locked");
                    rootState_subState = Locked;
                    rootState_active = Locked;
                    NOTIFY_TRANSITION_TERMINATED("3");
                    res = eventConsumed;
                }
            
            break;
        };
        case Locked:
        {
            if(IS_EVENT_TYPE_OF(es_FCM_TransmissionModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("2");
                    NOTIFY_STATE_EXITED("ROOT.Locked");
                    NOTIFY_STATE_ENTERED("ROOT.Fluid_Coupling");
                    rootState_subState = Fluid_Coupling;
                    rootState_active = Fluid_Coupling;
                    NOTIFY_TRANSITION_TERMINATED("2");
                    res = eventConsumed;
                }
            
            break;
        };
        default:
            break;
    };
    return res;
}

void Torque_Converter::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void Torque_Converter::cleanUpRelations() {
    if(impeller != NULL)
        {
            NOTIFY_RELATION_CLEARED("impeller");
            impeller = NULL;
        }
    if(turbine != NULL)
        {
            NOTIFY_RELATION_CLEARED("turbine");
            turbine = NULL;
        }
}

OMBoolean Torque_Converter::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



#ifdef _OMINSTRUMENT


void OMAnimatedTorque_Converter::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedTorque_Converter::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("turbine", FALSE, TRUE);
    if(myReal->turbine)
        aomsRelations->ADD_ITEM(myReal->turbine);
    aomsRelations->addRelation("impeller", FALSE, TRUE);
    if(myReal->impeller)
        aomsRelations->ADD_ITEM(myReal->impeller);
}

void OMAnimatedTorque_Converter::rootState_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case Torque_Converter::Torque_Multiplication:
        {
            Torque_Multiplication_serializeStates(aomsState);
            break;
        };
        case Torque_Converter::Fluid_Coupling:
        {
            Fluid_Coupling_serializeStates(aomsState);
            break;
        };
        case Torque_Converter::Locked:
        {
            Locked_serializeStates(aomsState);
            break;
        };
        default:
            break;
    };
}

void OMAnimatedTorque_Converter::Torque_Multiplication_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Torque_Multiplication");
}

void OMAnimatedTorque_Converter::Locked_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Locked");
}

void OMAnimatedTorque_Converter::Fluid_Coupling_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Fluid_Coupling");
}

IMPLEMENT_REACTIVE_META(Torque_Converter, TransmissionModels, FALSE, OMAnimatedTorque_Converter)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Torque_Converter.cpp
*********************************************************************/

