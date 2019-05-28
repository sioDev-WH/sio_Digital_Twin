/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: BrakeActuator
//!	Generated Date	: Thu, 9, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\BrakeActuator.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "BrakeActuator.h"
#include "ActuatorClutchConnector.h"
#include "stdafx.h"

//## package TransmissionModels 


//#[ ignore 
#define TransmissionModels_BrakeActuator_BrakeActuator_SERIALIZE OM_NO_OP


#define TransmissionModels_BrakeActuator_InitEqnForm_SERIALIZE OM_NO_OP


#define TransmissionModels_BrakeActuator_InitEsos_SERIALIZE OM_NO_OP


#define TransmissionModels_BrakeActuator_InitLocalADEqns_SERIALIZE OM_NO_OP


#define TransmissionModels_BrakeActuator_InitLocalEqns_SERIALIZE OM_NO_OP


#define TransmissionModels_BrakeActuator_InitLocalRPars_SERIALIZE OM_NO_OP


#define TransmissionModels_BrakeActuator_InitLocalVars_SERIALIZE OM_NO_OP


#define TransmissionModels_BrakeActuator_Load_SERIALIZE OM_NO_OP


#define TransmissionModels_BrakeActuator_Save_SERIALIZE OM_NO_OP


#define TransmissionModels_BrakeActuator_clean_SERIALIZE OM_NO_OP


#define TransmissionModels_BrakeActuator_handle_brakePedal_SERIALIZE OM_NO_OP


#define TransmissionModels_BrakeActuator_handle_gain_SERIALIZE OM_NO_OP


#define TransmissionModels_BrakeActuator_handle_lag_SERIALIZE OM_NO_OP


#define TransmissionModels_BrakeActuator_handle_pressureMax_SERIALIZE OM_NO_OP


#define TransmissionModels_BrakeActuator_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// BrakeActuator.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(TransmissionModels)
//## class BrakeActuator 



BrakeActuator::BrakeActuator() {
    NOTIFY_CONSTRUCTOR(BrakeActuator, BrakeActuator(), 0, TransmissionModels_BrakeActuator_BrakeActuator_SERIALIZE);
    p = NULL;
    //#[ operation BrakeActuator() 
    init();
    //#]
}

BrakeActuator::~BrakeActuator() {
    NOTIFY_DESTRUCTOR(~BrakeActuator, TRUE);
    //#[ operation ~BrakeActuator() 
    clean();
    //#]
    cleanUpRelations();
}

HRESULT BrakeActuator::InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form) {
    NOTIFY_OPERATION(InitEqnForm, InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ), 0, TransmissionModels_BrakeActuator_InitEqnForm_SERIALIZE);
    //#[ operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
    const long idx_eqn_r_EngageProfile = 0;
    
      DESTROY_VECTOR(*form)
      *form = new OnEqnForm[m_nLocalEqns];
      (*form)[idx_eqn_r_EngageProfile] = continuous;
    
      DESTROY_VECTOR(*diff_form)
      *diff_form = new OnEqnDiffForm[m_nLocalEqns];
      (*diff_form)[idx_eqn_r_EngageProfile] = automatic;
    
      return S_OK;
    
    //#]
}

HRESULT BrakeActuator::InitEsos() {
    NOTIFY_OPERATION(InitEsos, InitEsos(), 0, TransmissionModels_BrakeActuator_InitEsos_SERIALIZE);
    //#[ operation InitEsos() 
      ADD_LOCAL_ESO(p)
    
      return S_OK;
    
    //#]
}

HRESULT BrakeActuator::InitLocalADEqns() {
    NOTIFY_OPERATION(InitLocalADEqns, InitLocalADEqns(), 0, TransmissionModels_BrakeActuator_InitLocalADEqns_SERIALIZE);
    //#[ operation InitLocalADEqns() 
      ADD_LOCAL_AD_EQN(BrakeActuator, ad_r_EngageProfile)
    
      return S_OK;
    
    //#]
}

HRESULT BrakeActuator::InitLocalEqns() {
    NOTIFY_OPERATION(InitLocalEqns, InitLocalEqns(), 0, TransmissionModels_BrakeActuator_InitLocalEqns_SERIALIZE);
    //#[ operation InitLocalEqns() 
      ADD_LOCAL_EQN(BrakeActuator, r_EngageProfile)
    
      return S_OK;
    
    //#]
}

HRESULT BrakeActuator::InitLocalRPars(const _TCHAR * prefix, ppdouble * pars, ppchar * Names, long * nPars, long * dPars) {
    NOTIFY_OPERATION(InitLocalRPars, InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ), 0, TransmissionModels_BrakeActuator_InitLocalRPars_SERIALIZE);
    //#[ operation InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ) 
      ADD_LOCAL_SRPAR(pressureMax)
      ADD_LOCAL_SRPAR(brakePedal)
      ADD_LOCAL_SRPAR(lag)
      ADD_LOCAL_SRPAR(gain)
    
      return S_OK;
    
    //#]
}

HRESULT BrakeActuator::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    NOTIFY_OPERATION(InitLocalVars, InitLocalVars(const _TCHAR * ,VarCont * ,const bool ), 0, TransmissionModels_BrakeActuator_InitLocalVars_SERIALIZE);
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
     for (long i = 0; i < m_nEsos; i++)
       AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
      return S_OK;
    
    //#]
}

bool BrakeActuator::Load(FILE * fs) {
    NOTIFY_OPERATION(Load, Load(FILE * ), 0, TransmissionModels_BrakeActuator_Load_SERIALIZE);
    //#[ operation Load(FILE * ) 
    return true;
    
    //#]
}

void BrakeActuator::Save(FILE * fs) {
    NOTIFY_OPERATION(Save, Save(FILE * ), 0, TransmissionModels_BrakeActuator_Save_SERIALIZE);
    //#[ operation Save(FILE * ) 
    //#]
}

HRESULT BrakeActuator::ad_r_EngageProfile(Fdouble * res) {
    //#[ operation ad_r_EngageProfile(Fdouble * ) 
    *res = p->DER_AD(pressure) + lag * p->AD(pressure) - lag * gain * brakePedal;
    return S_OK;
    
    //#]
}

void BrakeActuator::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, TransmissionModels_BrakeActuator_clean_SERIALIZE);
    //#[ operation clean() 
    if (p)
    {
      p->Release();
      p = NULL;
    }
    
    //#]
}

void BrakeActuator::handle_brakePedal(const double t, const double * val) {
    NOTIFY_OPERATION(handle_brakePedal, handle_brakePedal(const double ,const double * ), 0, TransmissionModels_BrakeActuator_handle_brakePedal_SERIALIZE);
    //#[ operation handle_brakePedal(const double ,const double * ) 
    PostRealParameter(t, 1, *val);
    
    //#]
}

void BrakeActuator::handle_gain(const double t, const double * val) {
    NOTIFY_OPERATION(handle_gain, handle_gain(const double ,const double * ), 0, TransmissionModels_BrakeActuator_handle_gain_SERIALIZE);
    //#[ operation handle_gain(const double ,const double * ) 
    PostRealParameter(t, 3, *val);
    
    //#]
}

void BrakeActuator::handle_lag(const double t, const double * val) {
    NOTIFY_OPERATION(handle_lag, handle_lag(const double ,const double * ), 0, TransmissionModels_BrakeActuator_handle_lag_SERIALIZE);
    //#[ operation handle_lag(const double ,const double * ) 
    PostRealParameter(t, 2, *val);
    
    //#]
}

void BrakeActuator::handle_pressureMax(const double t, const double * val) {
    NOTIFY_OPERATION(handle_pressureMax, handle_pressureMax(const double ,const double * ), 0, TransmissionModels_BrakeActuator_handle_pressureMax_SERIALIZE);
    //#[ operation handle_pressureMax(const double ,const double * ) 
    PostRealParameter(t, 0, *val);
    
    //#]
}

void BrakeActuator::init() {
    NOTIFY_OPERATION(init, init(), 0, TransmissionModels_BrakeActuator_init_SERIALIZE);
    //#[ operation init() 
    p = new ActuatorClutchConnector();
    p->AddRef();
    
    pressureMax = 1000.0;
    brakePedal = 0.0;
    lag = 0.2;
    gain = 10.0;
    
    //#]
}

HRESULT BrakeActuator::r_EngageProfile(double * res) {
    //#[ operation r_EngageProfile(double * ) 
    *res = p->DER(pressure) + lag * p->pressure - lag * gain * brakePedal;
    
    return S_OK; 
    
    //#]
}

double BrakeActuator::getBrakePedal() const {
    return brakePedal;
}

void BrakeActuator::setBrakePedal(double  p_brakePedal) {
    brakePedal = p_brakePedal;
}

double BrakeActuator::getGain() const {
    return gain;
}

void BrakeActuator::setGain(double  p_gain) {
    gain = p_gain;
}

double BrakeActuator::getLag() const {
    return lag;
}

void BrakeActuator::setLag(double  p_lag) {
    lag = p_lag;
}

double BrakeActuator::getPressureMax() const {
    return pressureMax;
}

void BrakeActuator::setPressureMax(double  p_pressureMax) {
    pressureMax = p_pressureMax;
}

ActuatorClutchConnector* BrakeActuator::getP() const {
    return p;
}

void BrakeActuator::setP(ActuatorClutchConnector*  p_ActuatorClutchConnector) {
    p = p_ActuatorClutchConnector;
    if(p_ActuatorClutchConnector != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("p", p_ActuatorClutchConnector, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("p");
        }
}

void BrakeActuator::cleanUpRelations() {
    if(p != NULL)
        {
            NOTIFY_RELATION_CLEARED("p");
            p = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedBrakeActuator::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedBrakeActuator::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("p", FALSE, TRUE);
    if(myReal->p)
        aomsRelations->ADD_ITEM(myReal->p);
}

IMPLEMENT_META(BrakeActuator, TransmissionModels, FALSE, OMAnimatedBrakeActuator)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\BrakeActuator.cpp
*********************************************************************/

