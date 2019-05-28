/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: BodyDynamics
//!	Generated Date	: Tue, 10, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\BodyDynamics.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 


#define _OMSTATECHART_ANIMATED 
//#]

#include "stdafx.h"
#include "BodyDynamics.h"
#include "BodyDynamicsCoeff.h"
#include "On3DConn.h"
#include "OnUMLEso.h"
#include "math.h"

//## package GuidancePkg 

//----------------------------------------------------------------------------
// BodyDynamics.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(GuidancePkg)
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

double BodyDynamics::getAccData(double  time) {
    //#[ operation getAccData(double) 
    // WAH double Fz = pAero->get_Fz(time);
    double Fz = - pAero->get_Fz(time);
    double der_q = pAero->get_der_q(time);//WAH changed der_w to der_q
    
    return Fz / pCoeff->Mass - der_q * pCoeff->accPos;
    //#]
}

double BodyDynamics::getGyroData(double  time) {
    //#[ operation getGyroData(double) 
    return pAero->get_q(time);
    //#]
}

double BodyDynamics::getSpeed(double  time) {
    //#[ operation getSpeed(double) 
    double u = pAero->get_u(time);
    double w = pAero->get_w(time);
    
    return sqrt(u*u+w*w);
    //#]
}

double BodyDynamics::get_theta(double  time) {
    //#[ operation get_theta(double) 
    const long idx_var_theta = 0;
    const long idx_var_x = 1;
    const long idx_var_z = 2;
    double tmpVal;
    if (m_pOnModel) m_pOnModel->GetVariable(idx_var_theta, time, &tmpVal);
    return tmpVal;
    //#]
}

double BodyDynamics::get_x(double  time) {
    //#[ operation get_x(double) 
    const long idx_var_theta = 0;
    const long idx_var_x = 1;
    const long idx_var_z = 2;
    double tmpVal;
    if (m_pOnModel) m_pOnModel->GetVariable(idx_var_x, time, &tmpVal);
    return tmpVal;
    //#]
}

double BodyDynamics::get_z(double  time) {
    //#[ operation get_z(double) 
    const long idx_var_theta = 0;
    const long idx_var_x = 1;
    const long idx_var_z = 2;
    double tmpVal;
    if (m_pOnModel) m_pOnModel->GetVariable(idx_var_z, time, &tmpVal);
    return tmpVal;
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

void BodyDynamics::set_theta(VarEx p__theta) {
    _theta = p__theta;
}

void BodyDynamics::set_x(VarEx p__x) {
    _x = p__x;
}

void BodyDynamics::set_z(VarEx p__z) {
    _z = p__z;
}

void BodyDynamics::setTheta(double  p_theta) {
    theta = p_theta;
}

void BodyDynamics::setX(double  p_x) {
    x = p_x;
}

void BodyDynamics::setZ(double  p_z) {
    z = p_z;
}

On3DConn* BodyDynamics::getPAero() const {
    return pAero;
}

void BodyDynamics::setPAero(On3DConn*  p_On3DConn) {
    pAero = p_On3DConn;
    if(p_On3DConn != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("pAero", p_On3DConn, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("pAero");
        }
}

BodyDynamicsCoeff* BodyDynamics::getPCoeff() const {
    return pCoeff;
}

void BodyDynamics::setPCoeff(BodyDynamicsCoeff*  p_BodyDynamicsCoeff) {
    pCoeff = p_BodyDynamicsCoeff;
    if(p_BodyDynamicsCoeff != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("pCoeff", p_BodyDynamicsCoeff, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("pCoeff");
        }
}

void BodyDynamics::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        NOTIFY_STATE_ENTERED("ROOT.Init");
        rootState_subState = Init;
        rootState_active = Init;
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

int BodyDynamics::rootState_dispatchEvent(short  id) {
    int res = eventNotConsumed;
    switch (rootState_active) {
        case Init:
        {
            if(IS_EVENT_TYPE_OF(evRun_GuidancePkg_id))
                {
                    NOTIFY_TRANSITION_STARTED("1");
                    NOTIFY_STATE_EXITED("ROOT.Init");
                    NOTIFY_STATE_ENTERED("ROOT.Run");
                    rootState_subState = Run;
                    rootState_active = Run;
                    //#[ state ROOT.Run.(Entry) 
                    OnTransition();
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("1");
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
            NOTIFY_RELATION_CLEARED("pAero");
            pAero = NULL;
        }
    if(pCoeff != NULL)
        {
            NOTIFY_RELATION_CLEARED("pCoeff");
            pCoeff = NULL;
        }
}

OMBoolean BodyDynamics::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



#ifdef _OMINSTRUMENT


void OMAnimatedBodyDynamics::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedBodyDynamics::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("pCoeff", FALSE, TRUE);
    if(myReal->pCoeff)
        aomsRelations->ADD_ITEM(myReal->pCoeff);
    aomsRelations->addRelation("pAero", FALSE, TRUE);
    if(myReal->pAero)
        aomsRelations->ADD_ITEM(myReal->pAero);
}

void OMAnimatedBodyDynamics::rootState_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case BodyDynamics::Init:
        {
            Init_serializeStates(aomsState);
            break;
        };
        case BodyDynamics::Run:
        {
            Run_serializeStates(aomsState);
            break;
        };
        default:
            break;
    };
}

void OMAnimatedBodyDynamics::Run_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Run");
}

void OMAnimatedBodyDynamics::Init_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Init");
}

IMPLEMENT_REACTIVE_META(BodyDynamics, GuidancePkg, FALSE, OMAnimatedBodyDynamics)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\BodyDynamics.cpp
*********************************************************************/

