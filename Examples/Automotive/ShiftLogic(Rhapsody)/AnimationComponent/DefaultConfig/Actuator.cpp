/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Actuator
//!	Generated Date	: Thu, 9, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Actuator.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 


#define _OMSTATECHART_ANIMATED 
//#]

#include "Actuator.h"
#include "ActuatorClutchConnector.h"
#include "stdafx.h"
#include "math.h"

//## package TransmissionModels 


//#[ ignore 
#define TransmissionModels_Actuator_Actuator_SERIALIZE OM_NO_OP


#define TransmissionModels_Actuator_InitEqnForm_SERIALIZE OM_NO_OP


#define TransmissionModels_Actuator_InitEsos_SERIALIZE OM_NO_OP


#define TransmissionModels_Actuator_InitLocalADEqns_SERIALIZE OM_NO_OP


#define TransmissionModels_Actuator_InitLocalEqns_SERIALIZE OM_NO_OP


#define TransmissionModels_Actuator_InitLocalRPars_SERIALIZE OM_NO_OP


#define TransmissionModels_Actuator_InitLocalVars_SERIALIZE OM_NO_OP


#define TransmissionModels_Actuator_InitStates_SERIALIZE OM_NO_OP


#define TransmissionModels_Actuator_InitTransitions_SERIALIZE OM_NO_OP


#define TransmissionModels_Actuator_Load_SERIALIZE OM_NO_OP


#define TransmissionModels_Actuator_OnTransition_SERIALIZE OM_NO_OP


#define TransmissionModels_Actuator_Save_SERIALIZE OM_NO_OP


#define TransmissionModels_Actuator_SetShiftPeriod_SERIALIZE OM_NO_OP


#define TransmissionModels_Actuator_TriggerEvent_SERIALIZE OM_NO_OP


#define TransmissionModels_Actuator_clean_SERIALIZE OM_NO_OP


#define TransmissionModels_Actuator_handle_pressureMax_SERIALIZE OM_NO_OP


#define TransmissionModels_Actuator_handle_rate_SERIALIZE OM_NO_OP


#define TransmissionModels_Actuator_handle_shiftEvent_SERIALIZE OM_NO_OP


#define TransmissionModels_Actuator_handle_shiftPeriod_SERIALIZE OM_NO_OP


#define TransmissionModels_Actuator_handle_tolerance_SERIALIZE OM_NO_OP


#define TransmissionModels_Actuator_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// Actuator.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(TransmissionModels)
//## class Actuator 



Actuator::Actuator(OMThread*  p_thread) {
    NOTIFY_REACTIVE_CONSTRUCTOR(Actuator, Actuator(), 0, TransmissionModels_Actuator_Actuator_SERIALIZE);
    setThread(p_thread, FALSE);
    clutchConnector = NULL;
    initStatechart();
    //#[ operation Actuator() 
    startBehavior();
    init();
    //#]
}

Actuator::~Actuator() {
    NOTIFY_DESTRUCTOR(~Actuator, TRUE);
    //#[ operation ~Actuator() 
    clean();
    //#]
    cleanUpRelations();
}

HRESULT Actuator::InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form) {
    NOTIFY_OPERATION(InitEqnForm, InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ), 0, TransmissionModels_Actuator_InitEqnForm_SERIALIZE);
    //#[ operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
    const long idx_eqn_r_ShiftTime = 0;
    const long idx_eqn_r_EngageProfile = 1;
    const long idx_eqn_r_DisengageProfile = 2;
    const long idx_eqn_s_ShiftTime = 3;
    const long idx_eqn_r_WaitProfile = 4;
    
      DESTROY_VECTOR(*form)
      *form = new OnEqnForm[m_nLocalEqns];
      (*form)[idx_eqn_r_ShiftTime] = continuous;
      (*form)[idx_eqn_r_EngageProfile] = continuous;
      (*form)[idx_eqn_r_DisengageProfile] = continuous;
      (*form)[idx_eqn_s_ShiftTime] = reset;
      (*form)[idx_eqn_r_WaitProfile] = continuous;
    
      DESTROY_VECTOR(*diff_form)
      *diff_form = new OnEqnDiffForm[m_nLocalEqns];
      (*diff_form)[idx_eqn_r_ShiftTime] = numeric;
      (*diff_form)[idx_eqn_r_EngageProfile] = numeric;
      (*diff_form)[idx_eqn_r_DisengageProfile] = numeric;
      (*diff_form)[idx_eqn_s_ShiftTime] = numeric;
      (*diff_form)[idx_eqn_r_WaitProfile] = numeric;
    
      return S_OK;
    
    //#]
}

HRESULT Actuator::InitEsos() {
    NOTIFY_OPERATION(InitEsos, InitEsos(), 0, TransmissionModels_Actuator_InitEsos_SERIALIZE);
    //#[ operation InitEsos() 
      ADD_LOCAL_ESO(clutchConnector)
    
      return S_OK;
    
    //#]
}

HRESULT Actuator::InitLocalADEqns() {
    NOTIFY_OPERATION(InitLocalADEqns, InitLocalADEqns(), 0, TransmissionModels_Actuator_InitLocalADEqns_SERIALIZE);
    //#[ operation InitLocalADEqns() 
      ADD_LOCAL_AD_EQN(Actuator, ad_r_ShiftTime)
      ADD_LOCAL_AD_EQN(Actuator, ad_r_EngageProfile)
      ADD_LOCAL_AD_EQN(Actuator, ad_r_DisengageProfile)
      ADD_LOCAL_AD_EQN(Actuator, ad_s_ShiftTime)
      ADD_LOCAL_AD_EQN(Actuator, ad_r_WaitProfile)
    
      return S_OK;
    
    //#]
}

HRESULT Actuator::InitLocalEqns() {
    NOTIFY_OPERATION(InitLocalEqns, InitLocalEqns(), 0, TransmissionModels_Actuator_InitLocalEqns_SERIALIZE);
    //#[ operation InitLocalEqns() 
      ADD_LOCAL_EQN(Actuator, r_ShiftTime)
      ADD_LOCAL_EQN(Actuator, r_EngageProfile)
      ADD_LOCAL_EQN(Actuator, r_DisengageProfile)
      ADD_LOCAL_EQN(Actuator, s_ShiftTime)
      ADD_LOCAL_EQN(Actuator, r_WaitProfile)
    
      return S_OK;
    
    //#]
}

HRESULT Actuator::InitLocalRPars(const _TCHAR * prefix, ppdouble * pars, ppchar * Names, long * nPars, long * dPars) {
    NOTIFY_OPERATION(InitLocalRPars, InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ), 0, TransmissionModels_Actuator_InitLocalRPars_SERIALIZE);
    //#[ operation InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ) 
      ADD_LOCAL_SRPAR(shiftPeriod)
      ADD_LOCAL_SRPAR(rate)
      ADD_LOCAL_SRPAR(tolerance)
      ADD_LOCAL_SRPAR(pressureMax)
    
      return S_OK;
    
    //#]
}

HRESULT Actuator::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    NOTIFY_OPERATION(InitLocalVars, InitLocalVars(const _TCHAR * ,VarCont * ,const bool ), 0, TransmissionModels_Actuator_InitLocalVars_SERIALIZE);
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
      ADD_LOCAL_SVAR(shiftTime)
    
     for (long i = 0; i < m_nEsos; i++)
       AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
      return S_OK;
    
    //#]
}

HRESULT Actuator::InitStates() {
    NOTIFY_OPERATION(InitStates, InitStates(), 0, TransmissionModels_Actuator_InitStates_SERIALIZE);
    //#[ operation InitStates() 
    HRESULT hr;
    HRESULT hrRet = S_OK;
    
    // equation constants
    const long idx_eqn_r_ShiftTime = 0;
    const long idx_eqn_r_EngageProfile = 1;
    const long idx_eqn_r_DisengageProfile = 2;
    const long idx_eqn_s_ShiftTime = 3;
    const long idx_eqn_r_WaitProfile = 4;
    
    // state constants
    const long idx_state_Disengaged = 0;
    const long idx_state_Engaged = 1;
    const long idx_state_Waiting = 2;
    
    const long idx_eqns_Disengaged[] = { 
      idx_eqn_r_ShiftTime,
      idx_eqn_r_DisengageProfile,
     };
    const long idx_eqns_Engaged[] = { 
      idx_eqn_r_ShiftTime,
      idx_eqn_r_EngageProfile,
     };
    const long idx_eqns_Waiting[] = { 
      idx_eqn_r_ShiftTime,
      idx_eqn_r_WaitProfile,
     };
    
    hr = AddState(L"Disengaged", 0, idx_eqns_Disengaged, 2);
    if (FAILED(hr)) hrRet = hr;
    hr = AddState(L"Engaged", 0, idx_eqns_Engaged, 2);
    if (FAILED(hr)) hrRet = hr;
    hr = AddState(L"Waiting", 1, idx_eqns_Waiting, 2);
    if (FAILED(hr)) hrRet = hr;
    
    
    return hrRet;
    
    //#]
}

HRESULT Actuator::InitTransitions() {
    NOTIFY_OPERATION(InitTransitions, InitTransitions(), 0, TransmissionModels_Actuator_InitTransitions_SERIALIZE);
    //#[ operation InitTransitions() 
    HRESULT hr;
    HRESULT hrRet = S_OK;
    
    
    // equation constants
    const long idx_eqn_r_ShiftTime = 0;
    const long idx_eqn_r_EngageProfile = 1;
    const long idx_eqn_r_DisengageProfile = 2;
    const long idx_eqn_s_ShiftTime = 3;
    const long idx_eqn_r_WaitProfile = 4;
    
    // state constants
    const long idx_state_Disengaged = 0;
    const long idx_state_Engaged = 1;
    const long idx_state_Waiting = 2;
    
    const long idx_eqns_ec_EngageDisengagedEngaged[] = { 
      idx_eqn_s_ShiftTime,
     };
    const long idx_eqns_ec_DisengageEngagedDisengaged[] = { 
      idx_eqn_s_ShiftTime,
     };
    const long idx_eqns_ec_EngageWaitingEngaged[] = { 
      idx_eqn_s_ShiftTime,
     };
    
    // Transition_Name, Source_State, Event_Name, Transition_Eqns, Eqn_Count
    hr = AddTransition(L"ec_EngageDisengagedEngaged", idx_state_Disengaged, L"ec_Engage", idx_eqns_ec_EngageDisengagedEngaged, 1);
    if (FAILED(hr)) hrRet = hr;
    hr = AddTransition(L"ec_DisengageEngagedDisengaged", idx_state_Engaged, L"ec_Disengage", idx_eqns_ec_DisengageEngagedDisengaged, 1);
    if (FAILED(hr)) hrRet = hr;
    hr = AddTransition(L"ec_EngageWaitingEngaged", idx_state_Waiting, L"ec_Engage", idx_eqns_ec_EngageWaitingEngaged, 1);
    if (FAILED(hr)) hrRet = hr;
    
    return hrRet;
    
    //}}SCG_OP_BODY
    /***** End of automatically generated code *****/
    //#]
}

bool Actuator::Load(FILE * fs) {
    NOTIFY_OPERATION(Load, Load(FILE * ), 0, TransmissionModels_Actuator_Load_SERIALIZE);
    //#[ operation Load(FILE * ) 
    READ_SCALAR( rootState_active )
    return true;
    //#]
}

HRESULT Actuator::OnTransition() {
    NOTIFY_OPERATION(OnTransition, OnTransition(), 0, TransmissionModels_Actuator_OnTransition_SERIALIZE);
    //#[ operation OnTransition() 
    /***** Code between the BODY tags is automatically generated code. DO NOT DELETE or MODIFY. *****/
    //{{SCG_OP_BODY
    
    HRESULT hr = S_OK;
    
    const long idx_state_Disengaged = 0;
    const long idx_state_Engaged = 1;
    const long idx_state_Waiting = 2;
    
    if (rootState_active == Disengaged)
    {
        ATLTRACE("\nDisengaged");
        hr = PostTransition(idx_state_Disengaged);
    }
    else if (rootState_active == Engaged)
    {
        ATLTRACE("\nEngaged");
        hr = PostTransition(idx_state_Engaged);
    }
    else if (rootState_active == Waiting)
    {
        ATLTRACE("\nWaiting");
        hr = PostTransition(idx_state_Waiting);
    }
    
    return hr;
    
    //#]
}

void Actuator::Save(FILE * fs) {
    NOTIFY_OPERATION(Save, Save(FILE * ), 0, TransmissionModels_Actuator_Save_SERIALIZE);
    //#[ operation Save(FILE * ) 
    WRITE_SCALAR( rootState_active )
    //#]
}

void Actuator::SetShiftPeriod(double  val) {
    NOTIFY_OPERATION(SetShiftPeriod, SetShiftPeriod(double), 0, TransmissionModels_Actuator_SetShiftPeriod_SERIALIZE);
    //#[ operation SetShiftPeriod(double) 
    shiftPeriod = val;
    rate=log(2.0/tolerance - 1.0)/(shiftPeriod*shiftPeriod);
    //#]
}

HRESULT Actuator::TriggerEvent(const double EventTime, const BSTR bstrEventId) {
    NOTIFY_OPERATION(TriggerEvent, TriggerEvent(const double ,const BSTR ), 0, TransmissionModels_Actuator_TriggerEvent_SERIALIZE);
    //#[ operation TriggerEvent(const double ,const BSTR ) 
    CComBSTR name = bstrEventId;
    
    if (name == L"ec_Engage")   
    {
      ec_Engage ev;
      takeTrigger(&ev);
    }
    else if (name == L"ec_Disengage")
    {
      ec_Disengage ev;
      takeTrigger(&ev);
    }
                                   
    return S_OK;
    //#]
}

HRESULT Actuator::ad_r_DisengageProfile(Fdouble * res) {
    //#[ operation ad_r_DisengageProfile(Fdouble * ) 
      *res=clutchConnector->AD(pressure) - pressureMax * 
        (2.0/(1.0+exp(rate*AD(shiftTime)*AD(shiftTime))));
      return S_OK;
    
    //#]
}

HRESULT Actuator::ad_r_EngageProfile(Fdouble * res) {
    //#[ operation ad_r_EngageProfile(Fdouble * ) 
    *res=clutchConnector->AD(pressure)-pressureMax*(1-2.0/(1.0+exp(rate*AD(shiftTime)*AD(shiftTime))));
      return S_OK;
    
    //#]
}

HRESULT Actuator::ad_r_ShiftTime(Fdouble * res) {
    //#[ operation ad_r_ShiftTime(Fdouble * ) 
    *res = DER_AD(shiftTime)-1.0;
      return S_OK;
    
    //#]
}

HRESULT Actuator::ad_r_WaitProfile(Fdouble * res) {
    //#[ operation ad_r_WaitProfile(Fdouble * ) 
      *res = clutchConnector->AD(pressure);
      return S_OK;
    
    //#]
}

HRESULT Actuator::ad_s_ShiftTime(Fdouble * res) {
    //#[ operation ad_s_ShiftTime(Fdouble * ) 
    *res = AD(shiftTime);
      return S_OK;
    
    //#]
}

void Actuator::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, TransmissionModels_Actuator_clean_SERIALIZE);
    //#[ operation clean() 
    clutchConnector->Release();
    
    //#]
}

void Actuator::handle_pressureMax(const double t, double * val) {
    NOTIFY_OPERATION(handle_pressureMax, handle_pressureMax(const double ,double * ), 0, TransmissionModels_Actuator_handle_pressureMax_SERIALIZE);
    //#[ operation handle_pressureMax(const double ,double * ) 
    PostRealParameter(t, 3, *val);
    
    //#]
}

void Actuator::handle_rate(const double t, double * val) {
    NOTIFY_OPERATION(handle_rate, handle_rate(const double ,double * ), 0, TransmissionModels_Actuator_handle_rate_SERIALIZE);
    //#[ operation handle_rate(const double ,double * ) 
    PostRealParameter(t, 1, *val);
    
    //#]
}

void Actuator::handle_shiftEvent(const double t, long * val) {
    NOTIFY_OPERATION(handle_shiftEvent, handle_shiftEvent(const double ,long * ), 0, TransmissionModels_Actuator_handle_shiftEvent_SERIALIZE);
    //#[ operation handle_shiftEvent(const double ,long * ) 
    if(*val == 0)
      PostStateEvent(t, L"ec_Disengage");
    else if (*val == 1)
      PostStateEvent(t, L"ec_Engage");
    
    //#]
}

void Actuator::handle_shiftPeriod(const double t, double * val) {
    NOTIFY_OPERATION(handle_shiftPeriod, handle_shiftPeriod(const double ,double * ), 0, TransmissionModels_Actuator_handle_shiftPeriod_SERIALIZE);
    //#[ operation handle_shiftPeriod(const double ,double * ) 
    PostRealParameter(t, 0, *val);
    
    //#]
}

void Actuator::handle_tolerance(const double t, double * val) {
    NOTIFY_OPERATION(handle_tolerance, handle_tolerance(const double ,double * ), 0, TransmissionModels_Actuator_handle_tolerance_SERIALIZE);
    //#[ operation handle_tolerance(const double ,double * ) 
    PostRealParameter(t, 2, *val);
    
    //#]
}

void Actuator::init() {
    NOTIFY_OPERATION(init, init(), 0, TransmissionModels_Actuator_init_SERIALIZE);
    //#[ operation init() 
    clutchConnector = new ActuatorClutchConnector(); 
    clutchConnector->AddRef();
    
    clutchConnector->pressure=0.0;
    clutchConnector->der(pressure) = 0.0;
    pressureMax=1000.0;
    tolerance=0.001;
    shiftTime=0.0;
    DER(shiftTime) = 1.0;
    shiftPeriod=0.5;
    rate=log(2.0/tolerance - 1.0)/(shiftPeriod*shiftPeriod);
    
    //#]
}

HRESULT Actuator::r_DisengageProfile(double * res) {
    //#[ operation r_DisengageProfile(double * ) 
      *res=clutchConnector->pressure - pressureMax * 
        (2.0/(1.0+exp(rate*shiftTime*shiftTime)));
      return S_OK;
    
    //#]
}

HRESULT Actuator::r_EngageProfile(double * res) {
    //#[ operation r_EngageProfile(double * ) 
    *res = clutchConnector->pressure-pressureMax*(1-2.0/(1.0+exp(rate*shiftTime*shiftTime)));
      return S_OK;
    
    //#]
}

HRESULT Actuator::r_ShiftTime(double * res) {
    //#[ operation r_ShiftTime(double * ) 
    *res = DER(shiftTime)-1.0;
      return S_OK;
    
    //#]
}

HRESULT Actuator::r_WaitProfile(double * res) {
    //#[ operation r_WaitProfile(double * ) 
      *res = clutchConnector->pressure;
      return S_OK;
    
    //#]
}

HRESULT Actuator::s_ShiftTime(double * res) {
    //#[ operation s_ShiftTime(double * ) 
    *res = shiftTime;
      return S_OK;
    
    //#]
}

VarEx Actuator::get_shiftTime() const {
    return _shiftTime;
}

void Actuator::set_shiftTime(VarEx  p__shiftTime) {
    _shiftTime = p__shiftTime;
}

double Actuator::getPressureMax() const {
    return pressureMax;
}

void Actuator::setPressureMax(double  p_pressureMax) {
    pressureMax = p_pressureMax;
}

double Actuator::getRate() const {
    return rate;
}

void Actuator::setRate(double  p_rate) {
    rate = p_rate;
}

double Actuator::getShiftPeriod() const {
    return shiftPeriod;
}

void Actuator::setShiftPeriod(double  p_shiftPeriod) {
    shiftPeriod = p_shiftPeriod;
}

double Actuator::getShiftTime() const {
    return shiftTime;
}

void Actuator::setShiftTime(double  p_shiftTime) {
    shiftTime = p_shiftTime;
}

double Actuator::getTolerance() const {
    return tolerance;
}

void Actuator::setTolerance(double  p_tolerance) {
    tolerance = p_tolerance;
}

ActuatorClutchConnector* Actuator::getClutchConnector() const {
    return clutchConnector;
}

void Actuator::setClutchConnector(ActuatorClutchConnector*  p_ActuatorClutchConnector) {
    clutchConnector = p_ActuatorClutchConnector;
    if(p_ActuatorClutchConnector != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("clutchConnector", p_ActuatorClutchConnector, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("clutchConnector");
        }
}

void Actuator::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        NOTIFY_STATE_ENTERED("ROOT.Waiting");
        rootState_subState = Waiting;
        rootState_active = Waiting;
        //#[ state ROOT.Waiting.(Entry) 
        OnTransition();
        //#]
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

int Actuator::rootState_dispatchEvent(short  id) {
    int res = eventNotConsumed;
    switch (rootState_active) {
        case Engaged:
        {
            if(IS_EVENT_TYPE_OF(ec_Disengage_TransmissionModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("3");
                    NOTIFY_STATE_EXITED("ROOT.Engaged");
                    NOTIFY_STATE_ENTERED("ROOT.Disengaged");
                    rootState_subState = Disengaged;
                    rootState_active = Disengaged;
                    //#[ state ROOT.Disengaged.(Entry) 
                    OnTransition();
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("3");
                    res = eventConsumed;
                }
            
            break;
        };
        case Disengaged:
        {
            if(IS_EVENT_TYPE_OF(ec_Engage_TransmissionModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("2");
                    NOTIFY_STATE_EXITED("ROOT.Disengaged");
                    NOTIFY_STATE_ENTERED("ROOT.Engaged");
                    rootState_subState = Engaged;
                    rootState_active = Engaged;
                    //#[ state ROOT.Engaged.(Entry) 
                    OnTransition();
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("2");
                    res = eventConsumed;
                }
            
            break;
        };
        case Waiting:
        {
            if(IS_EVENT_TYPE_OF(ec_Engage_TransmissionModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("1");
                    NOTIFY_STATE_EXITED("ROOT.Waiting");
                    NOTIFY_STATE_ENTERED("ROOT.Engaged");
                    rootState_subState = Engaged;
                    rootState_active = Engaged;
                    //#[ state ROOT.Engaged.(Entry) 
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

void Actuator::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void Actuator::cleanUpRelations() {
    if(clutchConnector != NULL)
        {
            NOTIFY_RELATION_CLEARED("clutchConnector");
            clutchConnector = NULL;
        }
}

OMBoolean Actuator::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



#ifdef _OMINSTRUMENT


void OMAnimatedActuator::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedActuator::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("clutchConnector", FALSE, TRUE);
    if(myReal->clutchConnector)
        aomsRelations->ADD_ITEM(myReal->clutchConnector);
}

void OMAnimatedActuator::rootState_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case Actuator::Engaged:
        {
            Engaged_serializeStates(aomsState);
            break;
        };
        case Actuator::Disengaged:
        {
            Disengaged_serializeStates(aomsState);
            break;
        };
        case Actuator::Waiting:
        {
            Waiting_serializeStates(aomsState);
            break;
        };
        default:
            break;
    };
}

void OMAnimatedActuator::Waiting_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Waiting");
}

void OMAnimatedActuator::Engaged_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Engaged");
}

void OMAnimatedActuator::Disengaged_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Disengaged");
}

IMPLEMENT_REACTIVE_META(Actuator, TransmissionModels, FALSE, OMAnimatedActuator)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Actuator.cpp
*********************************************************************/

