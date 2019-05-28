/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Ravigneaux
//!	Generated Date	: Thu, 9, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Ravigneaux.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "Ravigneaux.h"
#include "CRigidConnector.h"
#include "stdafx.h"
#include "math.h"

//## package TransmissionModels 


//#[ ignore 
#define TransmissionModels_Ravigneaux_Ravigneaux_SERIALIZE OM_NO_OP


#define TransmissionModels_Ravigneaux_InitEqnForm_SERIALIZE OM_NO_OP


#define TransmissionModels_Ravigneaux_InitEsos_SERIALIZE OM_NO_OP


#define TransmissionModels_Ravigneaux_InitLocalADEqns_SERIALIZE OM_NO_OP


#define TransmissionModels_Ravigneaux_InitLocalEqns_SERIALIZE OM_NO_OP


#define TransmissionModels_Ravigneaux_InitLocalVars_SERIALIZE OM_NO_OP


#define TransmissionModels_Ravigneaux_Load_SERIALIZE OM_NO_OP


#define TransmissionModels_Ravigneaux_Save_SERIALIZE OM_NO_OP


#define TransmissionModels_Ravigneaux_clean_SERIALIZE OM_NO_OP


#define TransmissionModels_Ravigneaux_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// Ravigneaux.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(TransmissionModels)
//## class Ravigneaux 



Ravigneaux::Ravigneaux(OMThread*  p_thread) {
    NOTIFY_REACTIVE_CONSTRUCTOR(Ravigneaux, Ravigneaux(), 0, TransmissionModels_Ravigneaux_Ravigneaux_SERIALIZE);
    setThread(p_thread, FALSE);
    iCoupler = NULL;
    ifSun = NULL;
    irSun = NULL;
    oRing = NULL;
    //#[ operation Ravigneaux() 
    init();
    
    //#]
}

Ravigneaux::~Ravigneaux() {
    NOTIFY_DESTRUCTOR(~Ravigneaux, TRUE);
    //#[ operation ~Ravigneaux() 
    clean();
    
    //#]
    cleanUpRelations();
}

HRESULT Ravigneaux::InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form) {
    NOTIFY_OPERATION(InitEqnForm, InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ), 0, TransmissionModels_Ravigneaux_InitEqnForm_SERIALIZE);
    //#[ operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
    
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
    
    //#]
}

HRESULT Ravigneaux::InitEsos() {
    NOTIFY_OPERATION(InitEsos, InitEsos(), 0, TransmissionModels_Ravigneaux_InitEsos_SERIALIZE);
    //#[ operation InitEsos() 
      ADD_LOCAL_ESO(ifSun)
      ADD_LOCAL_ESO(irSun)
      ADD_LOCAL_ESO(iCoupler)
      ADD_LOCAL_ESO(oRing)
    
      return S_OK;
    
    //#]
}

HRESULT Ravigneaux::InitLocalADEqns() {
    NOTIFY_OPERATION(InitLocalADEqns, InitLocalADEqns(), 0, TransmissionModels_Ravigneaux_InitLocalADEqns_SERIALIZE);
    //#[ operation InitLocalADEqns() 
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
    
    //#]
}

HRESULT Ravigneaux::InitLocalEqns() {
    NOTIFY_OPERATION(InitLocalEqns, InitLocalEqns(), 0, TransmissionModels_Ravigneaux_InitLocalEqns_SERIALIZE);
    //#[ operation InitLocalEqns() 
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
    
    //#]
}

HRESULT Ravigneaux::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    NOTIFY_OPERATION(InitLocalVars, InitLocalVars(const _TCHAR * ,VarCont * ,const bool ), 0, TransmissionModels_Ravigneaux_InitLocalVars_SERIALIZE);
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
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
    
    //#]
}

bool Ravigneaux::Load(FILE * fs) {
    NOTIFY_OPERATION(Load, Load(FILE * ), 0, TransmissionModels_Ravigneaux_Load_SERIALIZE);
    //#[ operation Load(FILE * ) 
    return true;
    //#]
}

void Ravigneaux::Save(FILE * fs) {
    NOTIFY_OPERATION(Save, Save(FILE * ), 0, TransmissionModels_Ravigneaux_Save_SERIALIZE);
    //#[ operation Save(FILE * ) 
    //#]
}

HRESULT Ravigneaux::ad_r_CarrierDynamics(Fdouble * res) {
    //#[ operation ad_r_CarrierDynamics(Fdouble * ) 
      *res = carrier.AD(torque) - 3.0 * (
               -AD(forwardToPinionForce) * forwardSun.radius +
               -AD(pinionToReverseForce) * reverseSun.radius +
               AD(ringToPinionForce) * ring.radius
             ) 
             - carrier.inertia * carrier.AD(acceleration);
    
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::ad_r_ForwardSunDynamics(Fdouble * res) {
    //#[ operation ad_r_ForwardSunDynamics(Fdouble * ) 
      *res = forwardSun.AD(torque) - 
             3.0 * AD(forwardToPinionForce) * forwardSun.radius - 
             forwardSun.inertia * forwardSun.AD(acceleration);
    
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::ad_r_ForwardToPinionKinematics(Fdouble * res) {
    //#[ operation ad_r_ForwardToPinionKinematics(Fdouble * ) 
    *res = shortPinion.AD(acceleration) * shortPinion.nTeeth + 
             (forwardSun.AD(acceleration) - carrier.AD(acceleration)) * forwardSun.nTeeth;
    
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::ad_r_LongPinionDynamics(Fdouble * res) {
    //#[ operation ad_r_LongPinionDynamics(Fdouble * ) 
      *res = longPinion.AD(torque) - (AD(pinionToPinionForce) + AD(pinionToReverseForce) + AD(ringToPinionForce)) * longPinion.radius -
             longPinion.inertia * longPinion.AD(acceleration);
    
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::ad_r_PinionToPinionKinematics(Fdouble * res) {
    //#[ operation ad_r_PinionToPinionKinematics(Fdouble * ) 
      *res = longPinion.AD(acceleration) * longPinion.nTeeth + 
             shortPinion.AD(acceleration) * shortPinion.nTeeth;
    
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::ad_r_PinionToRingKinematics(Fdouble * res) {
    //#[ operation ad_r_PinionToRingKinematics(Fdouble * ) 
      *res = longPinion.AD(acceleration) * longPinion.nTeeth - 
             (ring.AD(acceleration) - carrier.AD(acceleration)) * ring.nTeeth;
    
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::ad_r_ReverseSunDynamics(Fdouble * res) {
    //#[ operation ad_r_ReverseSunDynamics(Fdouble * ) 
      *res = reverseSun.AD(torque) - 3.0 * AD(pinionToReverseForce) * reverseSun.radius -
             reverseSun.inertia * reverseSun.AD(acceleration);
    
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::ad_r_ReverseToPinionKinematics(Fdouble * res) {
    //#[ operation ad_r_ReverseToPinionKinematics(Fdouble * ) 
      *res = longPinion.AD(acceleration) * longPinion.nTeeth + 
             (reverseSun.AD(acceleration) - carrier.AD(acceleration)) * reverseSun.nTeeth;
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::ad_r_RingDynamics(Fdouble * res) {
    //#[ operation ad_r_RingDynamics(Fdouble * ) 
      *res = ring.AD(torque) + 
             3.0 * AD(ringToPinionForce) * ring.radius - 
             ring.inertia * ring.AD(acceleration);
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::ad_r_ShortPinionDynamics(Fdouble * res) {
    //#[ operation ad_r_ShortPinionDynamics(Fdouble * ) 
      *res =  shortPinion.AD(torque) - (AD(forwardToPinionForce)
               + AD(pinionToPinionForce)) * shortPinion.radius - 
              shortPinion.inertia * shortPinion.AD(acceleration);
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::ad_r_iCouplerAcceleration(Fdouble * res) {
    //#[ operation ad_r_iCouplerAcceleration(Fdouble * ) 
      *res = iCoupler->AD(acceleration) - carrier.AD(acceleration);
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::ad_r_iCouplerSpeed(Fdouble * res) {
    //#[ operation ad_r_iCouplerSpeed(Fdouble * ) 
      *res = iCoupler->AD(acceleration) - carrier.DER_AD(speed);
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::ad_r_iCouplerTorque(Fdouble * res) {
    //#[ operation ad_r_iCouplerTorque(Fdouble * ) 
      *res = iCoupler->AD(torque) - carrier.AD(torque);
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::ad_r_ifSunAcceleration(Fdouble * res) {
    //#[ operation ad_r_ifSunAcceleration(Fdouble * ) 
      *res = ifSun->AD(acceleration) - forwardSun.AD(acceleration);
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::ad_r_ifSunSpeed(Fdouble * res) {
    //#[ operation ad_r_ifSunSpeed(Fdouble * ) 
      *res = ifSun->AD(acceleration) - forwardSun.DER_AD(speed);
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::ad_r_ifSunTorque(Fdouble * res) {
    //#[ operation ad_r_ifSunTorque(Fdouble * ) 
      *res = ifSun->AD(torque) - forwardSun.AD(torque);
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::ad_r_irSunAcceleration(Fdouble * res) {
    //#[ operation ad_r_irSunAcceleration(Fdouble * ) 
      *res = irSun->AD(acceleration) - reverseSun.AD(acceleration);
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::ad_r_irSunSpeed(Fdouble * res) {
    //#[ operation ad_r_irSunSpeed(Fdouble * ) 
      *res = irSun->AD(acceleration) - reverseSun.DER_AD(speed);
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::ad_r_irSunTorque(Fdouble * res) {
    //#[ operation ad_r_irSunTorque(Fdouble * ) 
      *res = irSun->AD(torque) - reverseSun.AD(torque);
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::ad_r_longPinionSpeed(Fdouble * res) {
    //#[ operation ad_r_longPinionSpeed(Fdouble * ) 
      *res = longPinion.AD(acceleration) - longPinion.DER_AD(speed);
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::ad_r_longPinionTorque(Fdouble * res) {
    //#[ operation ad_r_longPinionTorque(Fdouble * ) 
      *res = longPinion.AD(torque);
    
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::ad_r_oRingAcceleration(Fdouble * res) {
    //#[ operation ad_r_oRingAcceleration(Fdouble * ) 
      *res = oRing->AD(acceleration) - ring.AD(acceleration);
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::ad_r_oRingSpeed(Fdouble * res) {
    //#[ operation ad_r_oRingSpeed(Fdouble * ) 
      *res = oRing->AD(acceleration) - ring.DER_AD(speed);
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::ad_r_oRingTorque(Fdouble * res) {
    //#[ operation ad_r_oRingTorque(Fdouble * ) 
      *res = oRing->AD(torque) - ring.AD(torque);
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::ad_r_shortPinionSpeed(Fdouble * res) {
    //#[ operation ad_r_shortPinionSpeed(Fdouble * ) 
    *res = shortPinion.AD(acceleration) - shortPinion.DER_AD(speed);
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::ad_r_shortPinionTorque(Fdouble * res) {
    //#[ operation ad_r_shortPinionTorque(Fdouble * ) 
      *res = shortPinion.AD(torque);
    return S_OK;
    
    //#]
}

void Ravigneaux::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, TransmissionModels_Ravigneaux_clean_SERIALIZE);
    //#[ operation clean() 
      ifSun->Release();
      irSun->Release();
      iCoupler->Release();
      oRing->Release();
    
    //#]
}

void Ravigneaux::init() {
    NOTIFY_OPERATION(init, init(), 0, TransmissionModels_Ravigneaux_init_SERIALIZE);
    //#[ operation init() 
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
    
    //#]
}

HRESULT Ravigneaux::r_CarrierDynamics(double * res) {
    //#[ operation r_CarrierDynamics(double * ) 
      *res = carrier.torque - 3.0 * (
               -forwardToPinionForce * forwardSun.radius +
               -pinionToReverseForce * reverseSun.radius +
               ringToPinionForce * ring.radius
             ) 
             - carrier.inertia * carrier.acceleration;
    
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::r_ForwardSunDynamics(double * res) {
    //#[ operation r_ForwardSunDynamics(double * ) 
      *res = forwardSun.torque - 
             3.0 * forwardToPinionForce * forwardSun.radius - 
             forwardSun.inertia * forwardSun.acceleration;
    
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::r_ForwardToPinionKinematics(double * res) {
    //#[ operation r_ForwardToPinionKinematics(double * ) 
    *res = shortPinion.acceleration * shortPinion.nTeeth + 
             (forwardSun.acceleration - carrier.acceleration) * forwardSun.nTeeth;
    
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::r_LongPinionDynamics(double * res) {
    //#[ operation r_LongPinionDynamics(double * ) 
      *res = longPinion.torque - (pinionToPinionForce + pinionToReverseForce + ringToPinionForce) * longPinion.radius -
             longPinion.inertia * longPinion.acceleration;
    
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::r_PinionToPinionKinematics(double * res) {
    //#[ operation r_PinionToPinionKinematics(double * ) 
      *res = longPinion.acceleration * longPinion.nTeeth + 
             shortPinion.acceleration * shortPinion.nTeeth;
    
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::r_PinionToRingKinematics(double * res) {
    //#[ operation r_PinionToRingKinematics(double * ) 
      *res = longPinion.acceleration * longPinion.nTeeth - 
             (ring.acceleration - carrier.acceleration) * ring.nTeeth;
    
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::r_ReverseSunDynamics(double * res) {
    //#[ operation r_ReverseSunDynamics(double * ) 
      *res = reverseSun.torque - 3.0 * pinionToReverseForce * reverseSun.radius -
             reverseSun.inertia * reverseSun.acceleration;
    
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::r_ReverseToPinionKinematics(double * res) {
    //#[ operation r_ReverseToPinionKinematics(double * ) 
      *res = longPinion.acceleration * longPinion.nTeeth + 
             (reverseSun.acceleration - carrier.acceleration) * reverseSun.nTeeth;
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::r_RingDynamics(double * res) {
    //#[ operation r_RingDynamics(double * ) 
      *res = ring.torque + 
             3.0 * ringToPinionForce * ring.radius - 
             ring.inertia * ring.acceleration;
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::r_ShortPinionDynamics(double * res) {
    //#[ operation r_ShortPinionDynamics(double * ) 
      *res =  shortPinion.torque - (forwardToPinionForce
               + pinionToPinionForce) * shortPinion.radius - 
              shortPinion.inertia * shortPinion.acceleration;
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::r_iCouplerAcceleration(double * res) {
    //#[ operation r_iCouplerAcceleration(double * ) 
      *res = iCoupler->acceleration - carrier.acceleration;
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::r_iCouplerSpeed(double * res) {
    //#[ operation r_iCouplerSpeed(double * ) 
      *res = iCoupler->acceleration - carrier.DER(speed);
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::r_iCouplerTorque(double * res) {
    //#[ operation r_iCouplerTorque(double * ) 
      *res = iCoupler->torque - carrier.torque;
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::r_ifSunAcceleration(double * res) {
    //#[ operation r_ifSunAcceleration(double * ) 
      *res = ifSun->acceleration - forwardSun.acceleration;
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::r_ifSunSpeed(double * res) {
    //#[ operation r_ifSunSpeed(double * ) 
      *res = ifSun->acceleration - forwardSun.DER(speed);
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::r_ifSunTorque(double * res) {
    //#[ operation r_ifSunTorque(double * ) 
      *res = ifSun->torque - forwardSun.torque;
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::r_irSunAcceleration(double * res) {
    //#[ operation r_irSunAcceleration(double * ) 
      *res = irSun->acceleration - reverseSun.acceleration;
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::r_irSunSpeed(double * res) {
    //#[ operation r_irSunSpeed(double * ) 
      *res = irSun->acceleration - reverseSun.DER(speed);
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::r_irSunTorque(double * res) {
    //#[ operation r_irSunTorque(double * ) 
      *res = irSun->torque - reverseSun.torque;
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::r_longPinionSpeed(double * res) {
    //#[ operation r_longPinionSpeed(double * ) 
      *res = longPinion.acceleration - longPinion.DER(speed);
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::r_longPinionTorque(double * res) {
    //#[ operation r_longPinionTorque(double * ) 
      *res = longPinion.torque;
    
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::r_oRingAcceleration(double * res) {
    //#[ operation r_oRingAcceleration(double * ) 
      *res = oRing->acceleration - ring.acceleration;
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::r_oRingSpeed(double * res) {
    //#[ operation r_oRingSpeed(double * ) 
      *res = oRing->acceleration - ring.DER(speed);
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::r_oRingTorque(double * res) {
    //#[ operation r_oRingTorque(double * ) 
      *res = oRing->torque - ring.torque;
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::r_shortPinionSpeed(double * res) {
    //#[ operation r_shortPinionSpeed(double * ) 
    *res = shortPinion.acceleration - shortPinion.DER(speed);
    return S_OK;
    
    //#]
}

HRESULT Ravigneaux::r_shortPinionTorque(double * res) {
    //#[ operation r_shortPinionTorque(double * ) 
      *res = shortPinion.torque;
    return S_OK;
    
    //#]
}

VarEx Ravigneaux::get_forwardToPinionForce() const {
    return _forwardToPinionForce;
}

void Ravigneaux::set_forwardToPinionForce(VarEx  p__forwardToPinionForce) {
    _forwardToPinionForce = p__forwardToPinionForce;
}

VarEx Ravigneaux::get_pinionToPinionForce() const {
    return _pinionToPinionForce;
}

void Ravigneaux::set_pinionToPinionForce(VarEx  p__pinionToPinionForce) {
    _pinionToPinionForce = p__pinionToPinionForce;
}

VarEx Ravigneaux::get_pinionToReverseForce() const {
    return _pinionToReverseForce;
}

void Ravigneaux::set_pinionToReverseForce(VarEx  p__pinionToReverseForce) {
    _pinionToReverseForce = p__pinionToReverseForce;
}

VarEx Ravigneaux::get_ringToPinionForce() const {
    return _ringToPinionForce;
}

void Ravigneaux::set_ringToPinionForce(VarEx  p__ringToPinionForce) {
    _ringToPinionForce = p__ringToPinionForce;
}

double Ravigneaux::getForwardToPinionForce() const {
    return forwardToPinionForce;
}

void Ravigneaux::setForwardToPinionForce(double  p_forwardToPinionForce) {
    forwardToPinionForce = p_forwardToPinionForce;
}

double Ravigneaux::getPinionToPinionForce() const {
    return pinionToPinionForce;
}

void Ravigneaux::setPinionToPinionForce(double  p_pinionToPinionForce) {
    pinionToPinionForce = p_pinionToPinionForce;
}

double Ravigneaux::getPinionToReverseForce() const {
    return pinionToReverseForce;
}

void Ravigneaux::setPinionToReverseForce(double  p_pinionToReverseForce) {
    pinionToReverseForce = p_pinionToReverseForce;
}

double Ravigneaux::getRingToPinionForce() const {
    return ringToPinionForce;
}

void Ravigneaux::setRingToPinionForce(double  p_ringToPinionForce) {
    ringToPinionForce = p_ringToPinionForce;
}

PlanetaryCoupler* Ravigneaux::getCarrier() const {
    return (PlanetaryCoupler*) &carrier;
}

Gear* Ravigneaux::getForwardSun() const {
    return (Gear*) &forwardSun;
}

CRigidConnector* Ravigneaux::getICoupler() const {
    return iCoupler;
}

void Ravigneaux::setICoupler(CRigidConnector*  p_CRigidConnector) {
    iCoupler = p_CRigidConnector;
    if(p_CRigidConnector != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("iCoupler", p_CRigidConnector, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("iCoupler");
        }
}

CRigidConnector* Ravigneaux::getIfSun() const {
    return ifSun;
}

void Ravigneaux::setIfSun(CRigidConnector*  p_CRigidConnector) {
    ifSun = p_CRigidConnector;
    if(p_CRigidConnector != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("ifSun", p_CRigidConnector, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("ifSun");
        }
}

CRigidConnector* Ravigneaux::getIrSun() const {
    return irSun;
}

void Ravigneaux::setIrSun(CRigidConnector*  p_CRigidConnector) {
    irSun = p_CRigidConnector;
    if(p_CRigidConnector != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("irSun", p_CRigidConnector, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("irSun");
        }
}

Gear* Ravigneaux::getLongPinion() const {
    return (Gear*) &longPinion;
}

CRigidConnector* Ravigneaux::getORing() const {
    return oRing;
}

void Ravigneaux::setORing(CRigidConnector*  p_CRigidConnector) {
    oRing = p_CRigidConnector;
    if(p_CRigidConnector != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("oRing", p_CRigidConnector, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("oRing");
        }
}

Gear* Ravigneaux::getReverseSun() const {
    return (Gear*) &reverseSun;
}

Gear* Ravigneaux::getRing() const {
    return (Gear*) &ring;
}

Gear* Ravigneaux::getShortPinion() const {
    return (Gear*) &shortPinion;
}

void Ravigneaux::cleanUpRelations() {
    if(iCoupler != NULL)
        {
            NOTIFY_RELATION_CLEARED("iCoupler");
            iCoupler = NULL;
        }
    if(ifSun != NULL)
        {
            NOTIFY_RELATION_CLEARED("ifSun");
            ifSun = NULL;
        }
    if(irSun != NULL)
        {
            NOTIFY_RELATION_CLEARED("irSun");
            irSun = NULL;
        }
    if(oRing != NULL)
        {
            NOTIFY_RELATION_CLEARED("oRing");
            oRing = NULL;
        }
}

OMBoolean Ravigneaux::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



#ifdef _OMINSTRUMENT


void OMAnimatedRavigneaux::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedRavigneaux::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("ifSun", FALSE, TRUE);
    if(myReal->ifSun)
        aomsRelations->ADD_ITEM(myReal->ifSun);
    aomsRelations->addRelation("irSun", FALSE, TRUE);
    if(myReal->irSun)
        aomsRelations->ADD_ITEM(myReal->irSun);
    aomsRelations->addRelation("iCoupler", FALSE, TRUE);
    if(myReal->iCoupler)
        aomsRelations->ADD_ITEM(myReal->iCoupler);
    aomsRelations->addRelation("oRing", FALSE, TRUE);
    if(myReal->oRing)
        aomsRelations->ADD_ITEM(myReal->oRing);
    aomsRelations->addRelation("forwardSun", TRUE, TRUE);
    if((Gear*) &myReal->forwardSun)
        aomsRelations->ADD_ITEM((Gear*) &myReal->forwardSun);
    aomsRelations->addRelation("reverseSun", TRUE, TRUE);
    if((Gear*) &myReal->reverseSun)
        aomsRelations->ADD_ITEM((Gear*) &myReal->reverseSun);
    aomsRelations->addRelation("carrier", TRUE, TRUE);
    if((PlanetaryCoupler*) &myReal->carrier)
        aomsRelations->ADD_ITEM((PlanetaryCoupler*) &myReal->carrier);
    aomsRelations->addRelation("shortPinion", TRUE, TRUE);
    if((Gear*) &myReal->shortPinion)
        aomsRelations->ADD_ITEM((Gear*) &myReal->shortPinion);
    aomsRelations->addRelation("longPinion", TRUE, TRUE);
    if((Gear*) &myReal->longPinion)
        aomsRelations->ADD_ITEM((Gear*) &myReal->longPinion);
    aomsRelations->addRelation("ring", TRUE, TRUE);
    if((Gear*) &myReal->ring)
        aomsRelations->ADD_ITEM((Gear*) &myReal->ring);
}

IMPLEMENT_REACTIVE_META(Ravigneaux, TransmissionModels, FALSE, OMAnimatedRavigneaux)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Ravigneaux.cpp
*********************************************************************/

