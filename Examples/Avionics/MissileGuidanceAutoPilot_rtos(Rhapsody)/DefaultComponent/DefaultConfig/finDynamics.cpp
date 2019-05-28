/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: finDynamics
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\finDynamics.cpp
*********************************************************************/

#include <oxf/omthread.h>
#include "finDynamics.h"
#include "OnUMLEso.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// finDynamics.cpp                                                                  
//----------------------------------------------------------------------------
//## class finDynamics 



finDynamics::finDynamics(OMThread*  p_thread) {
    setThread(p_thread, FALSE);
    initStatechart();
    //#[ operation finDynamics() 
    setThread(p_thread, FALSE);
    initStatechart();
    init();
    startBehavior();
    //#]
}

finDynamics::~finDynamics() {
    //#[ operation ~finDynamics() 
    clean();
    //#]
}

HRESULT finDynamics::EvalStateCondition(const bool*  EqnState, const double*  x, const double*  xdot, const double  EventTime, const long  iDisEqn, const long  iTransition, bool*  bEvent) {
    //#[ operation EvalStateCondition(const bool*,const double*,const double*,const double,const long,const long,bool*) 
    
    
    const long idx_state_Normal = 0;
    const long idx_state_LowSaturation = 1;
    const long idx_state_HighSaturation = 2;
    
    const long idx_transition_LowSaturation_evNorm = 0;
    const long idx_transition_Normal_evSH = 1;
    const long idx_transition_HighSaturation_evNorm = 2;
    const long idx_transition_Normal_evSL = 3;
    
    const long idx_eqn_s_rate_eq_zero = 6;
    const long idx_eqn_z_pos_gt_max = 7;
    const long idx_eqn_z_pos_lt_min = 8;
    const long idx_eqn_z_sp_gt_min = 9;
    const long idx_eqn_z_sp_lt_max = 10;
    long currentState = 0;
    switch (rootState_active)
    {
      case Normal:
        currentState = idx_state_Normal;
        break;
      case LowSaturation:
        currentState = idx_state_LowSaturation;
        break;
      case HighSaturation:
        currentState = idx_state_HighSaturation;
        break;
    }
    
    *bEvent = false;
    switch (currentState)
    {
    case idx_state_Normal:
      if (iTransition == idx_transition_Normal_evSH)
        *bEvent = (EqnState[idx_eqn_z_pos_gt_max]);
      else if (iTransition == idx_transition_Normal_evSL)
        *bEvent = (EqnState[idx_eqn_z_sp_gt_min]);
        break;
    case idx_state_LowSaturation:
      if (iTransition == idx_transition_LowSaturation_evNorm)
        *bEvent = (EqnState[idx_eqn_z_pos_lt_min]);
        break;
    case idx_state_HighSaturation:
      if (iTransition == idx_transition_HighSaturation_evNorm)
        *bEvent = (EqnState[idx_eqn_z_sp_lt_max]);
        break;
    
    }
      return S_OK;
    //#]
}

HRESULT finDynamics::InitEqnForm(OnEqnForm**  form, OnEqnDiffForm**  diff_form) {
    //#[ operation InitEqnForm(OnEqnForm**,OnEqnDiffForm**) 
    
    
    const long idx_eqn_r_angle_aileron = 0;
    const long idx_eqn_r_angle_rudder = 1;
    const long idx_eqn_r_angle = 2;
    const long idx_eqn_r_rate = 3;
    const long idx_eqn_r_saturation_angle = 4;
    const long idx_eqn_r_saturation_rate = 5;
    const long idx_eqn_s_rate_eq_zero = 6;
    const long idx_eqn_z_pos_gt_max = 7;
    const long idx_eqn_z_pos_lt_min = 8;
    const long idx_eqn_z_sp_gt_min = 9;
    const long idx_eqn_z_sp_lt_max = 10;
    
      DESTROY_VECTOR(*form)
      *form = new OnEqnForm[m_nLocalEqns];
      (*form)[idx_eqn_r_angle_aileron] = continuous;
      (*form)[idx_eqn_r_angle_rudder] = continuous;
      (*form)[idx_eqn_r_angle] = continuous;
      (*form)[idx_eqn_r_rate] = continuous;
      (*form)[idx_eqn_r_saturation_angle] = continuous;
      (*form)[idx_eqn_r_saturation_rate] = continuous;
      (*form)[idx_eqn_s_rate_eq_zero] = reset;
      (*form)[idx_eqn_z_pos_gt_max] = discontinuous;
      (*form)[idx_eqn_z_pos_lt_min] = discontinuous;
      (*form)[idx_eqn_z_sp_gt_min] = discontinuous;
      (*form)[idx_eqn_z_sp_lt_max] = discontinuous;
    
      DESTROY_VECTOR(*diff_form)
      *diff_form = new OnEqnDiffForm[m_nLocalEqns];
      (*diff_form)[idx_eqn_r_angle_aileron] = automatic;
      (*diff_form)[idx_eqn_r_angle_rudder] = automatic;
      (*diff_form)[idx_eqn_r_angle] = automatic;
      (*diff_form)[idx_eqn_r_rate] = automatic;
      (*diff_form)[idx_eqn_r_saturation_angle] = automatic;
      (*diff_form)[idx_eqn_r_saturation_rate] = automatic;
      (*diff_form)[idx_eqn_s_rate_eq_zero] = automatic;
      (*diff_form)[idx_eqn_z_pos_gt_max] = automatic;
      (*diff_form)[idx_eqn_z_pos_lt_min] = automatic;
      (*diff_form)[idx_eqn_z_sp_gt_min] = automatic;
      (*diff_form)[idx_eqn_z_sp_lt_max] = automatic;
    
      return S_OK;
    //#]
}

HRESULT finDynamics::InitEsos() {
    //#[ operation InitEsos() 
    
      ADD_LOCAL_ESO(&pFin)
    
      return S_OK;
    //#]
}

HRESULT finDynamics::InitLocalADEqns() {
    //#[ operation InitLocalADEqns() 
    
      ADD_LOCAL_AD_EQN(finDynamics, ad_r_angle_aileron)
      ADD_LOCAL_AD_EQN(finDynamics, ad_r_angle_rudder)
      ADD_LOCAL_AD_EQN(finDynamics, ad_r_angle)
      ADD_LOCAL_AD_EQN(finDynamics, ad_r_rate)
      ADD_LOCAL_AD_EQN(finDynamics, ad_r_saturation_angle)
      ADD_LOCAL_AD_EQN(finDynamics, ad_r_saturation_rate)
      ADD_LOCAL_AD_EQN(finDynamics, ad_s_rate_eq_zero)
      ADD_LOCAL_AD_EQN(finDynamics, ad_z_pos_gt_max)
      ADD_LOCAL_AD_EQN(finDynamics, ad_z_pos_lt_min)
      ADD_LOCAL_AD_EQN(finDynamics, ad_z_sp_gt_min)
      ADD_LOCAL_AD_EQN(finDynamics, ad_z_sp_lt_max)
    
      return S_OK;
    //#]
}

HRESULT finDynamics::InitLocalEqns() {
    //#[ operation InitLocalEqns() 
    
      ADD_LOCAL_EQN(finDynamics, r_angle_aileron)
      ADD_LOCAL_EQN(finDynamics, r_angle_rudder)
      ADD_LOCAL_EQN(finDynamics, r_angle)
      ADD_LOCAL_EQN(finDynamics, r_rate)
      ADD_LOCAL_EQN(finDynamics, r_saturation_angle)
      ADD_LOCAL_EQN(finDynamics, r_saturation_rate)
      ADD_LOCAL_EQN(finDynamics, s_rate_eq_zero)
      ADD_LOCAL_EQN(finDynamics, z_pos_gt_max)
      ADD_LOCAL_EQN(finDynamics, z_pos_lt_min)
      ADD_LOCAL_EQN(finDynamics, z_sp_gt_min)
      ADD_LOCAL_EQN(finDynamics, z_sp_lt_max)
    
      return S_OK;
    //#]
}

HRESULT finDynamics::InitLocalRPars(const _TCHAR*  prefix, ppdouble*  pars, ppchar*  Names, long*  nPars, long*  dPars) {
    //#[ operation InitLocalRPars(const _TCHAR*,ppdouble*,ppchar*,long*,long*) 
    
    
      ADD_LOCAL_SRPAR(AngleSetpoint)
      ADD_LOCAL_SRPAR(bandwidth)
      ADD_LOCAL_SRPAR(damping)
      ADD_LOCAL_SRPAR(gain)
      ADD_LOCAL_SRPAR(max_angle)
      ADD_LOCAL_SRPAR(max_rate)
      ADD_LOCAL_SRPAR(min_angle)
    
      return S_OK;
    //#]
}

HRESULT finDynamics::InitLocalVars(const _TCHAR*  prefix, VarCont*  varC, const bool  bADOnly) {
    //#[ operation InitLocalVars(const _TCHAR*,VarCont*,const bool) 
    
    
      ADD_LOCAL_SVAR(rate)
    
    for (long i = 0; i < m_nEsos; i++)
      AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
      return S_OK;
    //#]
}

HRESULT finDynamics::InitStates() {
    //#[ operation InitStates() 
    
    HRESULT hr;
    HRESULT hrRet = S_OK;
    
    // equation constants
    const long idx_eqn_r_angle_aileron = 0;
    const long idx_eqn_r_angle_rudder = 1;
    const long idx_eqn_r_angle = 2;
    const long idx_eqn_r_rate = 3;
    const long idx_eqn_r_saturation_angle = 4;
    const long idx_eqn_r_saturation_rate = 5;
    const long idx_eqn_s_rate_eq_zero = 6;
    const long idx_eqn_z_pos_gt_max = 7;
    const long idx_eqn_z_pos_lt_min = 8;
    const long idx_eqn_z_sp_gt_min = 9;
    const long idx_eqn_z_sp_lt_max = 10;
    
    // state constants
    const long idx_state_Normal = 0;
    const long idx_state_LowSaturation = 1;
    const long idx_state_HighSaturation = 2;
    
    const long idx_eqns_Normal[] = { 
      idx_eqn_r_angle_aileron,
      idx_eqn_r_angle_rudder,
      idx_eqn_r_angle,
      idx_eqn_r_rate,
     };
    const long idx_eqns_LowSaturation[] = { 
      idx_eqn_r_angle_aileron,
      idx_eqn_r_angle_rudder,
      idx_eqn_r_saturation_angle,
      idx_eqn_r_saturation_rate,
     };
    const long idx_eqns_HighSaturation[] = { 
      idx_eqn_r_angle_aileron,
      idx_eqn_r_angle_rudder,
      idx_eqn_r_saturation_angle,
      idx_eqn_r_saturation_rate,
     };
    
    hr = AddState(L"Normal", 1, idx_eqns_Normal, 4);
    if (FAILED(hr)) hrRet = hr;
    hr = AddState(L"LowSaturation", 0, idx_eqns_LowSaturation, 4);
    if (FAILED(hr)) hrRet = hr;
    hr = AddState(L"HighSaturation", 0, idx_eqns_HighSaturation, 4);
    if (FAILED(hr)) hrRet = hr;
    
    
    return hrRet;
    //#]
}

HRESULT finDynamics::InitTransitions() {
    //#[ operation InitTransitions() 
    
    HRESULT hr;
    HRESULT hrRet = S_OK;
    
    
    // equation constants
    const long idx_eqn_r_angle_aileron = 0;
    const long idx_eqn_r_angle_rudder = 1;
    const long idx_eqn_r_angle = 2;
    const long idx_eqn_r_rate = 3;
    const long idx_eqn_r_saturation_angle = 4;
    const long idx_eqn_r_saturation_rate = 5;
    const long idx_eqn_s_rate_eq_zero = 6;
    const long idx_eqn_z_pos_gt_max = 7;
    const long idx_eqn_z_pos_lt_min = 8;
    const long idx_eqn_z_sp_gt_min = 9;
    const long idx_eqn_z_sp_lt_max = 10;
    
    // state constants
    const long idx_state_Normal = 0;
    const long idx_state_LowSaturation = 1;
    const long idx_state_HighSaturation = 2;
    
    const long idx_eqns_LowSaturation_evNorm[] = { 
      idx_eqn_z_pos_lt_min,
     };
    const long idx_eqns_Normal_evSH[] = { 
      idx_eqn_s_rate_eq_zero,
      idx_eqn_z_pos_gt_max,
     };
    const long idx_eqns_HighSaturation_evNorm[] = { 
      idx_eqn_z_sp_lt_max,
     };
    const long idx_eqns_Normal_evSL[] = { 
      idx_eqn_s_rate_eq_zero,
      idx_eqn_z_sp_gt_min,
     };
    
    // Transition_Name, Source_State, Event_Name, Transition_Eqns, Eqn_Count
    hr = AddTransition(L"LowSaturation_evNorm", idx_state_LowSaturation, L"evNorm", idx_eqns_LowSaturation_evNorm, 1);
    if (FAILED(hr)) hrRet = hr;
    hr = AddTransition(L"Normal_evSH", idx_state_Normal, L"evSH", idx_eqns_Normal_evSH, 2);
    if (FAILED(hr)) hrRet = hr;
    hr = AddTransition(L"HighSaturation_evNorm", idx_state_HighSaturation, L"evNorm", idx_eqns_HighSaturation_evNorm, 1);
    if (FAILED(hr)) hrRet = hr;
    hr = AddTransition(L"Normal_evSL", idx_state_Normal, L"evSL", idx_eqns_Normal_evSL, 2);
    if (FAILED(hr)) hrRet = hr;
    
    return hrRet;
    //#]
}

bool finDynamics::Load(FILE*  fs) {
    //#[ operation Load(FILE*) 
    
    return true;
    //#]
}

HRESULT finDynamics::OnTransition() {
    //#[ operation OnTransition() 
    
    HRESULT hr = S_OK;
    
    const long idx_state_Normal = 0;
    const long idx_state_LowSaturation = 1;
    const long idx_state_HighSaturation = 2;
    switch ( rootState_active )
    {
      case Normal:
        ATLTRACE("\nNormal");
        PostTransition(idx_state_Normal);
        break;
      case LowSaturation:
        ATLTRACE("\nLowSaturation");
        PostTransition(idx_state_LowSaturation);
        break;
      case HighSaturation:
        ATLTRACE("\nHighSaturation");
        PostTransition(idx_state_HighSaturation);
        break;
    }
    
    return hr;
    //#]
}

void finDynamics::Save(FILE*  fs) {
    //#[ operation Save(FILE*) 
    //#]
}

HRESULT finDynamics::TriggerEvent(const double  EventTime, const BSTR  bstrEventId) {
    //#[ operation TriggerEvent(const double,const BSTR) 
    
    USES_CONVERSION;
    
    CComBSTR EventId = bstrEventId;
    HRESULT hr = S_OK;
    
    if (EventId == L"evNorm")
    {
      evNorm ev;
      takeTrigger(&ev);
    }
    else if (EventId == L"evSH")
    {
      evSH ev;
      takeTrigger(&ev);
    }
    else if (EventId == L"evNorm")
    {
      evNorm ev;
      takeTrigger(&ev);
    }
    else if (EventId == L"evSL")
    {
      evSL ev;
      takeTrigger(&ev);
    }
    
    m_time = EventTime;
    
    // update old variables
    S_OLD(rate) = rate;
    
    return S_OK;
    //#]
}

HRESULT finDynamics::ad_r_angle(Fdouble*  res) {
    //#[ operation ad_r_angle(Fdouble*) 
    
    *res = pFin.DER_AD(angle)[1] - S_AD(rate);
    return S_OK;
    
    //#]
}

HRESULT finDynamics::ad_r_angle_aileron(Fdouble*  res) {
    //#[ operation ad_r_angle_aileron(Fdouble*) 
    
    *res = pFin.DER_AD(angle)[0];
    return S_OK;
    
    //#]
}

HRESULT finDynamics::ad_r_angle_rudder(Fdouble*  res) {
    //#[ operation ad_r_angle_rudder(Fdouble*) 
    
    *res = pFin.DER_AD(angle)[2];
    return S_OK;
    
    //#]
}

HRESULT finDynamics::ad_r_rate(Fdouble*  res) {
    //#[ operation ad_r_rate(Fdouble*) 
    
    
        *res = S_DER_AD(rate) + 2.0 * damping * bandwidth * S_AD(rate) 
                       + bandwidth * bandwidth * pFin.AD(angle)[1] 
                       - bandwidth * bandwidth * AngleSetpoint * gain;
    
        return S_OK;
    
    //#]
}

HRESULT finDynamics::ad_r_saturation_angle(Fdouble*  res) {
    //#[ operation ad_r_saturation_angle(Fdouble*) 
    
    *res = pFin.DER_AD(angle)[1] - S_AD(rate);
    return S_OK;
    
    //#]
}

HRESULT finDynamics::ad_r_saturation_rate(Fdouble*  res) {
    //#[ operation ad_r_saturation_rate(Fdouble*) 
    
    *res = S_DER_AD(rate);
    return S_OK;
    
    //#]
}

HRESULT finDynamics::ad_s_rate_eq_zero(Fdouble*  res) {
    //#[ operation ad_s_rate_eq_zero(Fdouble*) 
    
    *res = S_AD(rate);
    return S_OK;
    
    //#]
}

HRESULT finDynamics::ad_z_pos_gt_max(Fdouble*  res) {
    //#[ operation ad_z_pos_gt_max(Fdouble*) 
    
    *res = pFin.AD(angle)[1] - max_angle;
    return S_OK;
    
    //#]
}

HRESULT finDynamics::ad_z_pos_lt_min(Fdouble*  res) {
    //#[ operation ad_z_pos_lt_min(Fdouble*) 
    
    *res = min_angle - pFin.AD(angle)[1];
    return S_OK;
    
    //#]
}

HRESULT finDynamics::ad_z_sp_gt_min(Fdouble*  res) {
    //#[ operation ad_z_sp_gt_min(Fdouble*) 
    
    *res = (AngleSetpoint ) - pFin.AD(angle)[1];
    return S_OK;
    
    //#]
}

HRESULT finDynamics::ad_z_sp_lt_max(Fdouble*  res) {
    //#[ operation ad_z_sp_lt_max(Fdouble*) 
    
    *res = pFin.AD(angle)[1] - (AngleSetpoint);
    return S_OK;
    
    //#]
}

void finDynamics::clean() {
    //#[ operation clean() 
    //#]
}

void finDynamics::get_der_rate(const double t, double*  pVal) {
    //#[ operation get_der_rate(const double ,double*) 
    
    GET_VARIABLE_DER_VALUE(L"rate", t, pVal)
    //#]
}

void finDynamics::get_rate(const double t, double*  pVal) {
    //#[ operation get_rate(const double ,double*) 
    
    GET_VARIABLE_VALUE(L"rate", t, pVal)
    //#]
}

void finDynamics::handle_AngleSetpoint(const double  t, const double*  val) {
    //#[ operation handle_AngleSetpoint(const double,const double*) 
    
    PostRealParameter(t, 0, *val);
    //#]
}

void finDynamics::handle_bandwidth(const double  t, const double*  val) {
    //#[ operation handle_bandwidth(const double,const double*) 
    
    PostRealParameter(t, 1, *val);
    //#]
}

void finDynamics::handle_damping(const double  t, const double*  val) {
    //#[ operation handle_damping(const double,const double*) 
    
    PostRealParameter(t, 2, *val);
    //#]
}

void finDynamics::handle_gain(const double  t, const double*  val) {
    //#[ operation handle_gain(const double,const double*) 
    
    PostRealParameter(t, 3, *val);
    //#]
}

void finDynamics::handle_max_angle(const double  t, const double*  val) {
    //#[ operation handle_max_angle(const double,const double*) 
    
    PostRealParameter(t, 4, *val);
    //#]
}

void finDynamics::handle_max_rate(const double  t, const double*  val) {
    //#[ operation handle_max_rate(const double,const double*) 
    
    PostRealParameter(t, 5, *val);
    //#]
}

void finDynamics::handle_min_angle(const double  t, const double*  val) {
    //#[ operation handle_min_angle(const double,const double*) 
    
    PostRealParameter(t, 6, *val);
    //#]
}

void finDynamics::init() {
    //#[ operation init() 
    AngleSetpoint = 0.0;
    rate = 0.0;
    S_DER(rate) = 0.0;  
    
    gain = 1.0;	
    damping = 0.7;
    bandwidth = 150.0;
    max_angle = 30.0 * d2r;	
    min_angle = -30.0 * d2r;
    max_rate = 500 * d2r;
    
    startBehavior();
    //#]
}

HRESULT finDynamics::r_angle(double * res) {
    //#[ operation r_angle(double * ) 
    *res = pFin.DER(angle)[1] - rate;
    return S_OK;
    //#]
}

HRESULT finDynamics::r_angle_aileron(double * res) {
    //#[ operation r_angle_aileron(double * ) 
    *res = pFin.DER(angle)[0];
    return S_OK;
    //#]
}

HRESULT finDynamics::r_angle_rudder(double * res) {
    //#[ operation r_angle_rudder(double * ) 
    *res = pFin.DER(angle)[2];
    return S_OK;
    //#]
}

HRESULT finDynamics::r_rate(double * res) {
    //#[ operation r_rate(double * ) 
    
        *res = S_DER(rate) + 2.0 * damping * bandwidth * rate 
                       + bandwidth * bandwidth * pFin.angle[1] 
                       - bandwidth * bandwidth * AngleSetpoint * gain;
    
        return S_OK;
    //#]
}

HRESULT finDynamics::r_saturation_angle(double * res) {
    //#[ operation r_saturation_angle(double * ) 
    *res = pFin.DER(angle)[1] - rate;
    return S_OK;
    //#]
}

HRESULT finDynamics::r_saturation_rate(double * res) {
    //#[ operation r_saturation_rate(double * ) 
    *res = S_DER(rate);
    return S_OK;
    //#]
}

HRESULT finDynamics::s_rate_eq_zero(double * res) {
    //#[ operation s_rate_eq_zero(double * ) 
    *res = rate;
    return S_OK;
    //#]
}

HRESULT finDynamics::z_pos_gt_max(double * res) {
    //#[ operation z_pos_gt_max(double * ) 
    *res = pFin.angle[1] - max_angle;
    return S_OK;
    //#]
}

HRESULT finDynamics::z_pos_lt_min(double * res) {
    //#[ operation z_pos_lt_min(double * ) 
    *res = min_angle - pFin.angle[1];
    return S_OK;
    //#]
}

HRESULT finDynamics::z_sp_gt_min(double * res) {
    //#[ operation z_sp_gt_min(double * ) 
    *res = (AngleSetpoint ) - pFin.angle[1];
    return S_OK;
    //#]
}

HRESULT finDynamics::z_sp_lt_max(double * res) {
    //#[ operation z_sp_lt_max(double * ) 
    *res = pFin.angle[1] - (AngleSetpoint);
    return S_OK;
    //#]
}

double finDynamics::getAngleSetpoint() const {
    return AngleSetpoint;
}

void finDynamics::setAngleSetpoint(double  p_AngleSetpoint) {
    AngleSetpoint = p_AngleSetpoint;
}

void finDynamics::set_rate(VarEx  p__rate) {
    _rate = p__rate;
}

double finDynamics::getBandwidth() const {
    return bandwidth;
}

void finDynamics::setBandwidth(double  p_bandwidth) {
    bandwidth = p_bandwidth;
}

double finDynamics::getDamping() const {
    return damping;
}

void finDynamics::setDamping(double  p_damping) {
    damping = p_damping;
}

double finDynamics::getGain() const {
    return gain;
}

void finDynamics::setGain(double  p_gain) {
    gain = p_gain;
}

double finDynamics::getMax_angle() const {
    return max_angle;
}

void finDynamics::setMax_angle(double  p_max_angle) {
    max_angle = p_max_angle;
}

double finDynamics::getMax_rate() const {
    return max_rate;
}

void finDynamics::setMax_rate(double  p_max_rate) {
    max_rate = p_max_rate;
}

double finDynamics::getMin_angle() const {
    return min_angle;
}

void finDynamics::setMin_angle(double  p_min_angle) {
    min_angle = p_min_angle;
}

double finDynamics::getRate() const {
    return rate;
}

void finDynamics::setRate(double  p_rate) {
    rate = p_rate;
}

FinPort* finDynamics::getPFin() const {
    return (FinPort*) &pFin;
}

void finDynamics::rootState_entDef() {
    {
        rootState_subState = Normal;
        rootState_active = Normal;
        //#[ state ROOT.Normal.(Entry) 
        OnTransition();
        //#]
    }
}

int finDynamics::rootState_dispatchEvent(short  id) {
    int res = eventNotConsumed;
    switch (rootState_active) {
        case Normal:
        {
            if(IS_EVENT_TYPE_OF(evSH_AirframePkg_id))
                {
                    rootState_subState = HighSaturation;
                    rootState_active = HighSaturation;
                    //#[ state ROOT.HighSaturation.(Entry) 
                    OnTransition();
                    //#]
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(evSL_AirframePkg_id))
                {
                    rootState_subState = LowSaturation;
                    rootState_active = LowSaturation;
                    //#[ state ROOT.LowSaturation.(Entry) 
                    OnTransition();
                    //#]
                    res = eventConsumed;
                }
            
            break;
        };
        case LowSaturation:
        {
            if(IS_EVENT_TYPE_OF(evNorm_AirframePkg_id))
                {
                    rootState_subState = Normal;
                    rootState_active = Normal;
                    //#[ state ROOT.Normal.(Entry) 
                    OnTransition();
                    //#]
                    res = eventConsumed;
                }
            
            break;
        };
        case HighSaturation:
        {
            if(IS_EVENT_TYPE_OF(evNorm_AirframePkg_id))
                {
                    rootState_subState = Normal;
                    rootState_active = Normal;
                    //#[ state ROOT.Normal.(Entry) 
                    OnTransition();
                    //#]
                    res = eventConsumed;
                }
            
            break;
        };
        default:
            break;
    };
    return res;
}

void finDynamics::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

OMBoolean finDynamics::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\finDynamics.cpp
*********************************************************************/

