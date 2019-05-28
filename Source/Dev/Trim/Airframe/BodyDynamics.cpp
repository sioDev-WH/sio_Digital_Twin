/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: BodyDynamics
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\BodyDynamics.cpp
*********************************************************************/

#include <oxf/omthread.h>
#include "BodyDynamics.h"
#include "BodyDynamicsCoeff.h"
#include "On3DConn.h"
#include "stdafx.h"
#include "OnUMLEso.h"
#include "math.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// BodyDynamics.cpp                                                                  
//----------------------------------------------------------------------------
//## class BodyDynamics 



BodyDynamics::BodyDynamics(OMThread*  p_thread) {
    setThread(p_thread, FALSE);
    pAero = NULL;
    pCoeff = NULL;
    initStatechart();
    //#[ operation BodyDynamics() 
    init();
    //#]
}

BodyDynamics::~BodyDynamics() {
    //#[ operation ~BodyDynamics() 
    clean();
    //#]
    cleanUpRelations();
}

HRESULT BodyDynamics::InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form) {
    //#[ operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
    const long idx_eqn_r_theta = 0;
    const long idx_eqn_r_x = 1;
    const long idx_eqn_r_z = 2;
    const long idx_eqn_r_q = 3;
    const long idx_eqn_r_u = 4;
    const long idx_eqn_r_w = 5;
    
    // state machine implementation
    const long idx_eqn_s_alpha = 6;
    const long idx_eqn_s_u = 7;
    
    DESTROY_VECTOR(*form)
    *form = new OnEqnForm[m_nLocalEqns];
    (*form)[idx_eqn_r_theta] = continuous;
    (*form)[idx_eqn_r_x] = continuous;
    (*form)[idx_eqn_r_z] = continuous;
    (*form)[idx_eqn_r_q] = continuous;
    (*form)[idx_eqn_r_u] = continuous;
    (*form)[idx_eqn_r_w] = continuous;
    
    // state machine implementation
    (*form)[idx_eqn_s_alpha] = reset;
    (*form)[idx_eqn_s_u] = reset;
    
    DESTROY_VECTOR(*diff_form)
    *diff_form = new OnEqnDiffForm[m_nLocalEqns];
    (*diff_form)[idx_eqn_r_theta] = automatic;
    (*diff_form)[idx_eqn_r_x] = automatic;
    (*diff_form)[idx_eqn_r_z] = automatic;
    (*diff_form)[idx_eqn_r_q] = automatic;
    (*diff_form)[idx_eqn_r_u] = automatic;
    (*diff_form)[idx_eqn_r_w] = automatic;
    
    // state machine implementation
    (*diff_form)[idx_eqn_s_alpha] = automatic;
    (*diff_form)[idx_eqn_s_u] = automatic;
    
    return S_OK;
    //#]
}

HRESULT BodyDynamics::InitEsos() {
    //#[ operation InitEsos() 
    ADD_LOCAL_ESO(pAero)
    
    return S_OK;
    //#]
}

HRESULT BodyDynamics::InitLocalADEqns() {
    //#[ operation InitLocalADEqns() 
    ADD_LOCAL_AD_EQN(BodyDynamics, ad_r_theta)
    ADD_LOCAL_AD_EQN(BodyDynamics, ad_r_x)
    ADD_LOCAL_AD_EQN(BodyDynamics, ad_r_z)
    ADD_LOCAL_AD_EQN(BodyDynamics, ad_r_q)
    ADD_LOCAL_AD_EQN(BodyDynamics, ad_r_u)
    ADD_LOCAL_AD_EQN(BodyDynamics, ad_r_w)
    
    // state machine implementation
    ADD_LOCAL_AD_EQN(BodyDynamics, ad_s_alpha)
    ADD_LOCAL_AD_EQN(BodyDynamics, ad_s_u)
    
    return S_OK;
    //#]
}

HRESULT BodyDynamics::InitLocalEqns() {
    //#[ operation InitLocalEqns() 
    ADD_LOCAL_EQN(BodyDynamics, r_theta)
    ADD_LOCAL_EQN(BodyDynamics, r_x)
    ADD_LOCAL_EQN(BodyDynamics, r_z)
    ADD_LOCAL_EQN(BodyDynamics, r_q)
    ADD_LOCAL_EQN(BodyDynamics, r_u)
    ADD_LOCAL_EQN(BodyDynamics, r_w)
    
    // state machine implementation
    ADD_LOCAL_EQN(BodyDynamics, s_alpha)
    ADD_LOCAL_EQN(BodyDynamics, s_u)
    
    return S_OK;
    //#]
}

HRESULT BodyDynamics::InitLocalRPars(const _TCHAR * prefix, ppdouble * pars, ppchar * Names, long * nPars, long * dPars) {
    //#[ operation InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ) 
    
     ADD_LOCAL_CRPAR(*pCoeff)
    
     return S_OK;
    //#]
}

HRESULT BodyDynamics::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    
     ADD_LOCAL_SVAR(theta)
    ADD_LOCAL_SVAR(x)
     ADD_LOCAL_SVAR(z)
    
     for (long i = 0; i < m_nEsos; i++)
       AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
     return S_OK; 
    //#]
}

HRESULT BodyDynamics::InitStates() {
    //#[ operation InitStates() 
    
      HRESULT hr;
      HRESULT hrRet = S_OK;
    
    // equation constants
    	const long idx_eqn_r_theta = 0;
    	const long idx_eqn_r_x = 1;
    	const long idx_eqn_r_z = 2;
    	const long idx_eqn_r_q = 3;
    	const long idx_eqn_r_u = 4;
    	const long idx_eqn_r_w = 5;
      
      // state machine implementation
      const long idx_eqn_s_alpha = 6;
      const long idx_eqn_s_u = 7;
    
    
    // state constants
      const long idx_state_Init = 0;
      const long idx_state_Run = 1;
    
      const long idx_eqns_Init_Run[] = { 
    	  idx_eqn_r_theta,
    	  idx_eqn_r_x,
    	  idx_eqn_r_z,
    	  idx_eqn_r_q,
    	  idx_eqn_r_u,
    	  idx_eqn_r_w,
      };
    
    // add the two states with the same equation counts
      hr = AddState(L"Init", 1, idx_eqns_Init_Run, 6);
      if (FAILED(hr)) hrRet = hr;
      hr = AddState(L"Run", 0, idx_eqns_Init_Run, 6);
      if (FAILED(hr)) hrRet = hr;
    
      return hrRet;
    //#]
}

HRESULT BodyDynamics::InitTransitions() {
    //#[ operation InitTransitions() 
    
      HRESULT hr;
      HRESULT hrRet = S_OK;
    
    // reset equations
      const long idx_eqn_s_alpha = 6;
      const long idx_eqn_s_u = 7;
    
    // state constants
      const long idx_state_Init = 0;
      const long idx_state_Run = 1;
    
      const long idx_eqns_InitRun[] =
      { 
        idx_eqn_s_alpha,
        idx_eqn_s_u,
      };
    
      // transition defined with no trigger conditions
    
      // Transition_Name, Source_State, Event_Name, Transition_Eqns, Eqn_Count
      hr = AddTransition(L"es_RunInitRun", idx_state_Init, L"evRun", idx_eqns_InitRun, 2);
      if (FAILED(hr)) hrRet = hr;
    
    
      return hrRet;
    //#]
}

bool BodyDynamics::Load(FILE * fs) {
    //#[ operation Load(FILE * ) 
    return true;
    //#]
}

HRESULT BodyDynamics::OnTransition() {
    //#[ operation OnTransition() 
    HRESULT hr = S_OK;
    
    const long idx_state_Init = 0;
    const long idx_state_Run = 1;
    
    switch (rootState_active)
    {
      case idx_state_Init:
        PostTransition(idx_state_Init);
        break;
      case idx_state_Run:
        PostTransition(idx_state_Run);
        break;
    }
    
    return hr;
    //#]
}

void BodyDynamics::Save(FILE * fs) {
    //#[ operation Save(FILE * ) 
    //#]
}

HRESULT BodyDynamics::TriggerEvent(const double EventTime, const BSTR bstrEventId) {
    //#[ operation TriggerEvent(const double ,const BSTR ) 
    const long idx_state_Init = 0;
    const long idx_state_Run = 1;
    CComBSTR name = bstrEventId;
    
    if (name == L"evRun")
    {
      evRun ev;
      takeTrigger(&ev);
    }
    
    return S_OK;
    //#]
}

HRESULT BodyDynamics::ad_r_q(Fdouble * res) {
    //#[ operation ad_r_q(Fdouble * ) 
    // WAH Fdouble& My = pAero->AD(My);
    Fdouble& My = - pAero->AD(My);
    Fdouble& der_q = pAero->DER_AD(q);
    
    *res = der_q - My / (pCoeff->Iyy);
    return S_OK;
    //#]
}

HRESULT BodyDynamics::ad_r_theta(Fdouble * res) {
    //#[ operation ad_r_theta(Fdouble * ) 
    Fdouble& q = pAero->AD(q);
    
    *res = DER_AD(theta) - q;
    return S_OK;
    //#]
}

HRESULT BodyDynamics::ad_r_u(Fdouble * res) {
    //#[ operation ad_r_u(Fdouble * ) 
    
     //  Body axes
     Fdouble& der_u = pAero->DER_AD(u);
     // Fdouble& Fx = pAero->AD(Fx);
     Fdouble& Fx = - pAero->AD(Fx);
     Fdouble& q = pAero->AD(q);
     Fdouble& w = pAero->AD(w);
    
    
     *res  = der_u - (Fx / (pCoeff->Mass) - q * w);
     // *res  = der_u - (Fx / (pCoeff->Mass) - q * w - 9.81 * sin(AD(theta)) );
     return S_OK;
    //#]
}

HRESULT BodyDynamics::ad_r_w(Fdouble * res) {
    //#[ operation ad_r_w(Fdouble * ) 
    Fdouble& der_w = pAero->DER_AD(w);
    // WAH Fdouble& Fz = pAero->AD(Fz);
    Fdouble& Fz = - pAero->AD(Fz);
    Fdouble& q = pAero->AD(q);
    Fdouble& u = pAero->AD(u);
    
    *res  = der_w - (Fz / (pCoeff->Mass) + q * u);
    // *res  = -der_w + Fz / (pCoeff->Mass) + q * u + 9.81 * cos(AD(theta));
    return S_OK;
    //#]
}

HRESULT BodyDynamics::ad_r_x(Fdouble * res) {
    //#[ operation ad_r_x(Fdouble * ) 
    
     Fdouble& u = pAero->AD(u);
     Fdouble& w = pAero->AD(w);
    
     *res = DER_AD(x) - ( u * cos(AD(theta)) + w * sin(AD(theta)) );
     return S_OK;
    //#]
}

HRESULT BodyDynamics::ad_r_z(Fdouble * res) {
    //#[ operation ad_r_z(Fdouble * ) 
    Fdouble& u = pAero->AD(u);
    Fdouble& w = pAero->AD(w);
    
    *res = DER_AD(z) - (- u * sin(AD(theta))+ w * cos(AD(theta))) ;
    return S_OK;
    //#]
}

HRESULT BodyDynamics::ad_s_alpha(Fdouble * res) {
    //#[ operation ad_s_alpha(Fdouble * ) 
    Fdouble& ad_w = pAero->AD(w);
    *res = ad_w - - 85.98700167; // WAH
    return S_OK;
    //#]
}

HRESULT BodyDynamics::ad_s_u(Fdouble * res) {
    //#[ operation ad_s_u(Fdouble * ) 
    Fdouble& ad_u = pAero->AD(u);
    
    *res = ad_u - 982.8359264; // WAH -3.0*328.0;
    
    return S_OK;
    //#]
}

void BodyDynamics::clean() {
    //#[ operation clean() 
    if (pCoeff)
    {
      delete pCoeff;
      pCoeff = NULL;
    }
    
    if (pAero)
    {
      pAero->Release();
      pAero = NULL;
    }
    //#]
}

void BodyDynamics::getAccData(const double  t, double*  val) {
    //#[ operation getAccData(const double,double*) 
    // WAH double Fz = pAero->get_Fz(time);
    double Fz = - pAero->get_Fz(t);
    double der_q = pAero->get_der_q(t);//WAH changed der_w to der_q
    
    *val = Fz / pCoeff->Mass - der_q * pCoeff->accPos;
    //#]
}

void BodyDynamics::getGyroData(const double  t, double*  val) {
    //#[ operation getGyroData(const double,double*) 
    *val = pAero->get_q(t);
    //#]
}

void BodyDynamics::getSpeed(const double  t, double*  val) {
    //#[ operation getSpeed(const double,double*) 
    double u = pAero->get_u(t);
    double w = pAero->get_w(t);
    
    *val = sqrt(u*u+w*w);
    //#]
}

void BodyDynamics::get_theta(const double  t, double*  val) {
    //#[ operation get_theta(const double,double*) 
    const long idx_var_theta = 0;
    const long idx_var_x = 1;
    const long idx_var_z = 2;
    if (m_pOnModel) m_pOnModel->GetVariable(idx_var_theta, t, val);
    //#]
}

void BodyDynamics::get_x(const double  t, double *  val) {
    //#[ operation get_x(const double,double *) 
    const long idx_var_theta = 0;
    const long idx_var_x = 1;
    const long idx_var_z = 2;
    if (m_pOnModel) m_pOnModel->GetVariable(idx_var_x, t, val);
    //#]
}

void BodyDynamics::get_z(const double  t, double *  val) {
    //#[ operation get_z(const double,double *) 
    const long idx_var_theta = 0;
    const long idx_var_x = 1;
    const long idx_var_z = 2;
    if (m_pOnModel) m_pOnModel->GetVariable(idx_var_z, t, val);
    //#]
}

void BodyDynamics::handle_Run(double  time) {
    //#[ operation handle_Run(double) 
    PostStateEvent(time, L"evRun");
    //#]
}

void BodyDynamics::init() {
    //#[ operation init() 
    pCoeff = new BodyDynamicsCoeff();
    pAero = new On3DConn();
    pAero->AddRef();
    
    // WAH initializing u to mach 3 - REPLACED by STATE MACHINE Reset equations
    // pAero->u = 3.0 * 328;
    // pAero->w = 0.0;
    
    theta = 0.0;
    x = 0.0;
    // WAH z = 0.0;
    z = -10000/m2ft;
    DER(theta) = 0.0;
    DER(x) = 0.0; 
    DER(z) = 0.0;
    
    // state machine implementation
    initStateMachine();
    
    //#]
}

void BodyDynamics::initStateMachine() {
    //#[ operation initStateMachine() 
    startBehavior();
    //#]
}

HRESULT BodyDynamics::r_q(double * res) {
    //#[ operation r_q(double * ) 
    double& My =  pAero->My;
    double& der_q = pAero->DER(q);
    // WAH 
    My = -My;
    
    *res = der_q - My / (pCoeff->Iyy);
    return S_OK;
    //#]
}

HRESULT BodyDynamics::r_theta(double * res) {
    //#[ operation r_theta(double * ) 
    double& q = pAero->q;
    
    *res = DER(theta) - q;
    return S_OK;
    //#]
}

HRESULT BodyDynamics::r_u(double * res) {
    //#[ operation r_u(double * ) 
    
     //  Body axes
     double& der_u = pAero->DER(u);
     double& Fx = pAero->Fx;
     double& q = pAero->q;
     double& w = pAero->w;
    
     // WAH
     Fx  = - Fx;
    
     *res  = der_u - (Fx / (pCoeff->Mass) - q * w);
    // *res  = der_u - (Fx / (pCoeff->Mass) - q * w - 9.81 * sin(theta));
     return S_OK;
    //#]
}

HRESULT BodyDynamics::r_w(double * res) {
    //#[ operation r_w(double * ) 
    double& der_w = pAero->DER(w);
    double& Fz = pAero->Fz;
    double& q = pAero->q;
    double& u = pAero->u;
    
    // WAH
    Fz = -Fz;
    
    *res  = der_w - (Fz / (pCoeff->Mass) + q * u);
    // *res  = -der_w + Fz / (pCoeff->Mass) + q * u + 9.81 * cos(theta);
    return S_OK;
    //#]
}

HRESULT BodyDynamics::r_x(double * res) {
    //#[ operation r_x(double * ) 
    
     double& u = pAero->u;
     double& w = pAero->w;
    
     *res = DER(x) - (u * cos(theta) + w * sin(theta));
     return S_OK;
    //#]
}

HRESULT BodyDynamics::r_z(double * res) {
    //#[ operation r_z(double * ) 
    double& u = pAero->u;
    double& w = pAero->w;
    
    *res = DER(z) - (- u * sin(theta)+ w * cos(theta));
    return S_OK;
    //#]
}

HRESULT BodyDynamics::s_alpha(double * res) {
    //#[ operation s_alpha(double * ) 
    double& w = pAero->w;
    
    *res = w - 85.98700167; // WAH
    return S_OK;
    //#]
}

HRESULT BodyDynamics::s_u(double * res) {
    //#[ operation s_u(double * ) 
    
     double& u = pAero->u;
    
      *res = u - 982.8359264; // WAH 3.0*328.0;
      return S_OK;
    //#]
}

VarEx  BodyDynamics::get_theta() const {
    return _theta;
}

void BodyDynamics::set_theta(VarEx p__theta) {
    _theta = p__theta;
}

VarEx  BodyDynamics::get_x() const {
    return _x;
}

void BodyDynamics::set_x(VarEx p__x) {
    _x = p__x;
}

VarEx  BodyDynamics::get_z() const {
    return _z;
}

void BodyDynamics::set_z(VarEx p__z) {
    _z = p__z;
}

double BodyDynamics::getTheta() const {
    return theta;
}

void BodyDynamics::setTheta(double  p_theta) {
    theta = p_theta;
}

double BodyDynamics::getX() const {
    return x;
}

void BodyDynamics::setX(double  p_x) {
    x = p_x;
}

double BodyDynamics::getZ() const {
    return z;
}

void BodyDynamics::setZ(double  p_z) {
    z = p_z;
}

On3DConn* BodyDynamics::getPAero() const {
    return pAero;
}

void BodyDynamics::setPAero(On3DConn*  p_On3DConn) {
    pAero = p_On3DConn;
}

BodyDynamicsCoeff* BodyDynamics::getPCoeff() const {
    return pCoeff;
}

void BodyDynamics::setPCoeff(BodyDynamicsCoeff*  p_BodyDynamicsCoeff) {
    pCoeff = p_BodyDynamicsCoeff;
}

void BodyDynamics::rootState_entDef() {
    {
        rootState_subState = Init;
        rootState_active = Init;
    }
}

int BodyDynamics::rootState_dispatchEvent(short  id) {
    int res = eventNotConsumed;
    switch (rootState_active) {
        case Init:
        {
            if(IS_EVENT_TYPE_OF(evRun_AirframePkg_id))
                {
                    rootState_subState = Run;
                    rootState_active = Run;
                    //#[ state ROOT.Run.(Entry) 
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

void BodyDynamics::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void BodyDynamics::cleanUpRelations() {
    if(pAero != NULL)
        {
            pAero = NULL;
        }
    if(pCoeff != NULL)
        {
            pCoeff = NULL;
        }
}

OMBoolean BodyDynamics::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\BodyDynamics.cpp
*********************************************************************/

