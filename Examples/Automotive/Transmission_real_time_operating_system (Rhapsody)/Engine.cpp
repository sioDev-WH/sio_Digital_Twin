/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Engine
//!	Generated Date	: Thu, 9, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Engine.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 


#define _OMSTATECHART_ANIMATED 
//#]

#include "Engine.h"
#include "CRigidConnector.h"
#include "stdafx.h"
#include "math.h"
#include "OnUMLEso.h"
#include "fstream.h"

//## package TransmissionModels 


//#[ ignore 
#define TransmissionModels_Engine_Engine_SERIALIZE OM_NO_OP


#define TransmissionModels_Engine_EvalStateCondition_SERIALIZE OM_NO_OP


#define TransmissionModels_Engine_InitEqnForm_SERIALIZE OM_NO_OP


#define TransmissionModels_Engine_InitEsos_SERIALIZE OM_NO_OP


#define TransmissionModels_Engine_InitLocalADEqns_SERIALIZE OM_NO_OP


#define TransmissionModels_Engine_InitLocalEqns_SERIALIZE OM_NO_OP


#define TransmissionModels_Engine_InitLocalRPars_SERIALIZE OM_NO_OP


#define TransmissionModels_Engine_InitLocalVars_SERIALIZE OM_NO_OP


#define TransmissionModels_Engine_InitStates_SERIALIZE OM_NO_OP


#define TransmissionModels_Engine_InitTransitions_SERIALIZE OM_NO_OP


#define TransmissionModels_Engine_Load_SERIALIZE OM_NO_OP


#define TransmissionModels_Engine_OnTransition_SERIALIZE OM_NO_OP


#define TransmissionModels_Engine_Save_SERIALIZE OM_NO_OP


#define TransmissionModels_Engine_TriggerEvent_SERIALIZE OM_NO_OP


#define TransmissionModels_Engine_clean_SERIALIZE OM_NO_OP


#define TransmissionModels_Engine_getRPM_SERIALIZE OM_NO_OP


#define TransmissionModels_Engine_handle_Start_SERIALIZE OM_NO_OP


#define TransmissionModels_Engine_handle_inertia_SERIALIZE OM_NO_OP


#define TransmissionModels_Engine_handle_throttle_SERIALIZE OM_NO_OP


#define TransmissionModels_Engine_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// Engine.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(TransmissionModels)
//## class Engine 



Engine::Engine(OMThread*  p_thread) {
    NOTIFY_REACTIVE_CONSTRUCTOR(Engine, Engine(), 0, TransmissionModels_Engine_Engine_SERIALIZE);
    setThread(p_thread, FALSE);
    n = NULL;
    initStatechart();
    //#[ operation Engine() 
        init();
        startBehavior(); // added by hand
        m_pOnEnv = NULL;
    
    //#]
}

Engine::~Engine() {
    NOTIFY_DESTRUCTOR(~Engine, TRUE);
    //#[ operation ~Engine() 
    clean();
    //#]
    cleanUpRelations();
}

HRESULT Engine::EvalStateCondition(const bool * EqnState, const double * x, const double * xdot, const double EventTime, const long iDisEqn, const long iTransition, bool * bEvent) {
    NOTIFY_OPERATION(EvalStateCondition, EvalStateCondition(const bool * ,const double * ,const double * ,const double ,const long ,const long ,bool * ), 0, TransmissionModels_Engine_EvalStateCondition_SERIALIZE);
    //#[ operation EvalStateCondition(const bool * ,const double * ,const double * ,const double ,const long ,const long ,bool * ) 
    const long idx_state_Off = 0;
    const long idx_state_On = 1;
    const long idx_state_Starting = 2;
    
    const long idx_transition_OffStarting = 0;
    const long idx_transition_OnOff = 1;
    const long idx_transition_StartingOn = 2;
    
    const long idx_eqn_z_OnRPM = 2;
    
    long currentState;
    
    if (rootState_active == Off)
      currentState = idx_state_Off;
    else if (rootState_active == On)
      currentState = idx_state_On;
    else if (rootState_active == Starting)
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
    //#]
}

HRESULT Engine::InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form) {
    NOTIFY_OPERATION(InitEqnForm, InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ), 0, TransmissionModels_Engine_InitEqnForm_SERIALIZE);
    //#[ operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
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
    
    //#]
}

HRESULT Engine::InitEsos() {
    NOTIFY_OPERATION(InitEsos, InitEsos(), 0, TransmissionModels_Engine_InitEsos_SERIALIZE);
    //#[ operation InitEsos() 
      ADD_LOCAL_ESO(n)
    
      return S_OK;
    
    //#]
}

HRESULT Engine::InitLocalADEqns() {
    NOTIFY_OPERATION(InitLocalADEqns, InitLocalADEqns(), 0, TransmissionModels_Engine_InitLocalADEqns_SERIALIZE);
    //#[ operation InitLocalADEqns() 
      ADD_LOCAL_AD_EQN(Engine, ad_r_OffTorque)
      ADD_LOCAL_AD_EQN(Engine, ad_r_StartupTorque)
      ADD_LOCAL_AD_EQN(Engine, ad_z_OnRPM)
      ADD_LOCAL_AD_EQN(Engine, ad_r_OnTorque)
      ADD_LOCAL_AD_EQN(Engine, ad_r_RPM)
      ADD_LOCAL_AD_EQN(Engine, ad_r_EngineDynamics)
    
      return S_OK;
    
    //#]
}

HRESULT Engine::InitLocalEqns() {
    NOTIFY_OPERATION(InitLocalEqns, InitLocalEqns(), 0, TransmissionModels_Engine_InitLocalEqns_SERIALIZE);
    //#[ operation InitLocalEqns() 
      ADD_LOCAL_EQN(Engine, r_OffTorque)
      ADD_LOCAL_EQN(Engine, r_StartupTorque)
      ADD_LOCAL_EQN(Engine, z_OnRPM)
      ADD_LOCAL_EQN(Engine, r_OnTorque)
      ADD_LOCAL_EQN(Engine, r_RPM)
      ADD_LOCAL_EQN(Engine, r_EngineDynamics)
    
      return S_OK;
    
    //#]
}

HRESULT Engine::InitLocalRPars(const _TCHAR * prefix, ppdouble * pars, ppchar * Names, long * nPars, long * dPars) {
    NOTIFY_OPERATION(InitLocalRPars, InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ), 0, TransmissionModels_Engine_InitLocalRPars_SERIALIZE);
    //#[ operation InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ) 
      ADD_LOCAL_SRPAR(throttle)
      ADD_LOCAL_SRPAR(inertia)
      ADD_LOCAL_SRPAR(engineThrottleLag)
    
      return S_OK;
    
    //#]
}

HRESULT Engine::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    NOTIFY_OPERATION(InitLocalVars, InitLocalVars(const _TCHAR * ,VarCont * ,const bool ), 0, TransmissionModels_Engine_InitLocalVars_SERIALIZE);
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
      ADD_LOCAL_SVAR(RPM)
      ADD_LOCAL_SVAR(engineTorque)
    
     for (long i = 0; i < m_nEsos; i++)
       AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
      return S_OK;
    
    //#]
}

HRESULT Engine::InitStates() {
    NOTIFY_OPERATION(InitStates, InitStates(), 0, TransmissionModels_Engine_InitStates_SERIALIZE);
    //#[ operation InitStates() 
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
    
    //#]
}

HRESULT Engine::InitTransitions() {
    NOTIFY_OPERATION(InitTransitions, InitTransitions(), 0, TransmissionModels_Engine_InitTransitions_SERIALIZE);
    //#[ operation InitTransitions() 
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
    
    //#]
}

bool Engine::Load(FILE * fs) {
    NOTIFY_OPERATION(Load, Load(FILE * ), 0, TransmissionModels_Engine_Load_SERIALIZE);
    //#[ operation Load(FILE * ) 
    READ_SCALAR( rootState_active )
    return true;
    //#]
}

HRESULT Engine::OnTransition() {
    NOTIFY_OPERATION(OnTransition, OnTransition(), 0, TransmissionModels_Engine_OnTransition_SERIALIZE);
    //#[ operation OnTransition() 
    HRESULT hr = S_OK;
    
    const long idx_state_Off = 0;
    const long idx_state_On = 1;
    const long idx_state_Starting = 2;
    
    if (rootState_active == Off)
    {
        ATLTRACE("\nOff");
        PostTransition(idx_state_Off);
    }
    else if (rootState_active == On)
    {
        ATLTRACE("\nOn");
        PostTransition(idx_state_On);
    }
    else if (rootState_active == Starting)
    {
        ATLTRACE("\nStarting");
        PostTransition(idx_state_Starting);
    }
    
    return hr;
    
    //#]
}

void Engine::Save(FILE * fs) {
    NOTIFY_OPERATION(Save, Save(FILE * ), 0, TransmissionModels_Engine_Save_SERIALIZE);
    //#[ operation Save(FILE * ) 
    WRITE_SCALAR( rootState_active )
    //#]
}

HRESULT Engine::TriggerEvent(const double EventTime, const BSTR bstrEventId) {
    NOTIFY_OPERATION(TriggerEvent, TriggerEvent(const double ,const BSTR ), 0, TransmissionModels_Engine_TriggerEvent_SERIALIZE);
    //#[ operation TriggerEvent(const double ,const BSTR ) 
    CComBSTR name = bstrEventId;
    
    if (name == L"es_Start")
    {
      es_Start ev;
      takeTrigger(&ev);
    }
    else if (name == L"es_Stop")
    {
      es_Stop ev;
      takeTrigger(&ev);
    }
    else if (name == L"es_On")
    {
      es_On ev;
      takeTrigger(&ev);
    }
    
    
    return S_OK;
    //#]
}

HRESULT Engine::ad_r_EngineDynamics(Fdouble * res) {
    //#[ operation ad_r_EngineDynamics(Fdouble * ) 
    *res = AD(engineTorque) - inertia * n->AD(acceleration) + n->AD(torque);
    return S_OK;
    //#]
}

HRESULT Engine::ad_r_OffTorque(Fdouble * res) {
    //#[ operation ad_r_OffTorque(Fdouble * ) 
    *res = DER_AD(engineTorque) + AD(engineTorque);
    return S_OK;
    
    //#]
}

HRESULT Engine::ad_r_OnTorque(Fdouble * res) {
    //#[ operation ad_r_OnTorque(Fdouble * ) 
    return S_OK; // placeholder 
    
    //#]
}

HRESULT Engine::ad_r_RPM(Fdouble * res) {
    //#[ operation ad_r_RPM(Fdouble * ) 
    #define PI 3.1415926535897932384626433832795
    #define W_TO_ad_RPM 60.0 / 2 * PI
    *res = DER_AD(RPM) - W_TO_ad_RPM * n->AD(acceleration);
    return S_OK;
    
    //#]
}

HRESULT Engine::ad_r_StartupTorque(Fdouble * res) {
    //#[ operation ad_r_StartupTorque(Fdouble * ) 
    return S_OK; // placeholder
    
    //#]
}

HRESULT Engine::ad_z_OnRPM(Fdouble * res) {
    //#[ operation ad_z_OnRPM(Fdouble * ) 
    *res = AD(RPM) - 1000.0;
    return S_OK;
    
    //#]
}

void Engine::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, TransmissionModels_Engine_clean_SERIALIZE);
    //#[ operation clean() 
      if (m_pOnEnv)
      {
        m_pOnEnv->Release();
        m_pOnEnv = NULL;
      }
      
      if (n)
      {
      	n->Release();
        n = NULL;
      }
    //#]
}

void Engine::getRPM(const double t, double * val) {
    NOTIFY_OPERATION(getRPM, getRPM(const double ,double * ), 0, TransmissionModels_Engine_getRPM_SERIALIZE);
    //#[ operation getRPM(const double ,double * ) 
    const long idx_var_RPM = 0;
    const long idx_var_engineTorque = 1;
    if (m_pOnModel) 
      m_pOnModel->GetVariable(idx_var_RPM, t, val);
    //#]
}

void Engine::handle_Start(const double t, long * val) {
    NOTIFY_OPERATION(handle_Start, handle_Start(const double ,long * ), 0, TransmissionModels_Engine_handle_Start_SERIALIZE);
    //#[ operation handle_Start(const double ,long * ) 
    if (*val == 1)
      PostStateEvent(t, L"es_Start");
    else if (*val == 0)
      PostStateEvent(t, L"es_Stop");
    //#]
}

void Engine::handle_inertia(const double t, const double * val) {
    NOTIFY_OPERATION(handle_inertia, handle_inertia(const double ,const double * ), 0, TransmissionModels_Engine_handle_inertia_SERIALIZE);
    //#[ operation handle_inertia(const double ,const double * ) 
    PostRealParameter(t, 1, *val);
    
    //#]
}

void Engine::handle_throttle(const double t, double * val) {
    NOTIFY_OPERATION(handle_throttle, handle_throttle(const double ,double * ), 0, TransmissionModels_Engine_handle_throttle_SERIALIZE);
    //#[ operation handle_throttle(const double ,double * ) 
    // ensure always have positive engine torque at 1000 RPM and below
    static double oldVal = 0.0;
    *val += 6.5;
    if (*val != oldVal)
    {
      PostRealParameter(t, 0, *val);
      oldVal = *val;
    }
    //#]
}

void Engine::init() {
    NOTIFY_OPERATION(init, init(), 0, TransmissionModels_Engine_init_SERIALIZE);
    //#[ operation init() 
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
    
    //#]
}

HRESULT Engine::r_EngineDynamics(double * res) {
    //#[ operation r_EngineDynamics(double * ) 
    *res = engineTorque - inertia * n->acceleration + n->torque;
    return S_OK;
    //#]
}

HRESULT Engine::r_OffTorque(double * res) {
    //#[ operation r_OffTorque(double * ) 
    *res = DER(engineTorque) + engineTorque;
    
    return S_OK;
    
    //#]
}

HRESULT Engine::r_OnTorque(double * res) {
    //#[ operation r_OnTorque(double * ) 
      double lookupTorque = 0.0;
      torqueMap.interpolate_2D(throttle, RPM, &lookupTorque); 
      *res = DER(engineTorque) + engineThrottleLag * engineTorque - engineThrottleLag * lookupTorque;
    
      return S_OK;
    
    //#]
}

HRESULT Engine::r_RPM(double * res) {
    //#[ operation r_RPM(double * ) 
    #define PI 3.1415926535897932384626433832795
    #define W_TO_RPM (60.0 / (2.0 * PI))
    *res = DER(RPM) - W_TO_RPM * n->acceleration;
    return S_OK;
    
    //#]
}

HRESULT Engine::r_StartupTorque(double * res) {
    //#[ operation r_StartupTorque(double * ) 
      double lookupTorque = 0.0;
      torqueMap.interpolate_2D(100.0, 1000.0, &lookupTorque); 
      *res = DER(engineTorque) + engineThrottleLag * engineTorque - lookupTorque;
      return S_OK;
    
    //#]
}

HRESULT Engine::z_OnRPM(double * res) {
    //#[ operation z_OnRPM(double * ) 
    *res = RPM - 1000.0;
    return S_OK;
    
    //#]
}

double Engine::getRPM() const {
    return RPM;
}

void Engine::setRPM(double  p_RPM) {
    RPM = p_RPM;
}

VarEx Engine::get_RPM() const {
    return _RPM;
}

void Engine::set_RPM(VarEx  p__RPM) {
    _RPM = p__RPM;
}

VarEx Engine::get_engineTorque() const {
    return _engineTorque;
}

void Engine::set_engineTorque(VarEx  p__engineTorque) {
    _engineTorque = p__engineTorque;
}

double Engine::getEngineThrottleLag() const {
    return engineThrottleLag;
}

void Engine::setEngineThrottleLag(double  p_engineThrottleLag) {
    engineThrottleLag = p_engineThrottleLag;
}

double Engine::getEngineTorque() const {
    return engineTorque;
}

void Engine::setEngineTorque(double  p_engineTorque) {
    engineTorque = p_engineTorque;
}

double Engine::getInertia() const {
    return inertia;
}

void Engine::setInertia(double  p_inertia) {
    inertia = p_inertia;
}

IOnEnv* Engine::getM_pOnEnv() const {
    return m_pOnEnv;
}

void Engine::setM_pOnEnv(IOnEnv*  p_m_pOnEnv) {
    m_pOnEnv = p_m_pOnEnv;
}

double Engine::getThrottle() const {
    return throttle;
}

void Engine::setThrottle(double  p_throttle) {
    throttle = p_throttle;
}

CRigidConnector* Engine::getN() const {
    return n;
}

void Engine::setN(CRigidConnector*  p_CRigidConnector) {
    n = p_CRigidConnector;
    if(p_CRigidConnector != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("n", p_CRigidConnector, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("n");
        }
}

LookupTable* Engine::getTorqueMap() const {
    return (LookupTable*) &torqueMap;
}

void Engine::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        NOTIFY_STATE_ENTERED("ROOT.Off");
        rootState_subState = Off;
        rootState_active = Off;
        //#[ state ROOT.Off.(Entry) 
        OnTransition();
        //#]
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

int Engine::rootState_dispatchEvent(short  id) {
    int res = eventNotConsumed;
    switch (rootState_active) {
        case Off:
        {
            if(IS_EVENT_TYPE_OF(es_Start_TransmissionModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("1");
                    NOTIFY_STATE_EXITED("ROOT.Off");
                    NOTIFY_STATE_ENTERED("ROOT.Starting");
                    rootState_subState = Starting;
                    rootState_active = Starting;
                    //#[ state ROOT.Starting.(Entry) 
                    OnTransition();
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("1");
                    res = eventConsumed;
                }
            
            break;
        };
        case Starting:
        {
            if(IS_EVENT_TYPE_OF(es_On_TransmissionModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("2");
                    NOTIFY_STATE_EXITED("ROOT.Starting");
                    NOTIFY_STATE_ENTERED("ROOT.On");
                    rootState_subState = On;
                    rootState_active = On;
                    //#[ state ROOT.On.(Entry) 
                    OnTransition();
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("2");
                    res = eventConsumed;
                }
            
            break;
        };
        case On:
        {
            if(IS_EVENT_TYPE_OF(es_Stop_TransmissionModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("3");
                    NOTIFY_STATE_EXITED("ROOT.On");
                    NOTIFY_STATE_ENTERED("ROOT.Off");
                    rootState_subState = Off;
                    rootState_active = Off;
                    //#[ state ROOT.Off.(Entry) 
                    OnTransition();
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

void Engine::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void Engine::cleanUpRelations() {
    if(n != NULL)
        {
            NOTIFY_RELATION_CLEARED("n");
            n = NULL;
        }
}

OMBoolean Engine::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



#ifdef _OMINSTRUMENT


void OMAnimatedEngine::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedEngine::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("n", FALSE, TRUE);
    if(myReal->n)
        aomsRelations->ADD_ITEM(myReal->n);
    aomsRelations->addRelation("torqueMap", TRUE, TRUE);
    if((LookupTable*) &myReal->torqueMap)
        aomsRelations->ADD_ITEM((LookupTable*) &myReal->torqueMap);
}

void OMAnimatedEngine::rootState_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case Engine::Off:
        {
            Off_serializeStates(aomsState);
            break;
        };
        case Engine::Starting:
        {
            Starting_serializeStates(aomsState);
            break;
        };
        case Engine::On:
        {
            On_serializeStates(aomsState);
            break;
        };
        default:
            break;
    };
}

void OMAnimatedEngine::Starting_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Starting");
}

void OMAnimatedEngine::On_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.On");
}

void OMAnimatedEngine::Off_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Off");
}

IMPLEMENT_REACTIVE_META(Engine, TransmissionModels, FALSE, OMAnimatedEngine)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Engine.cpp
*********************************************************************/

