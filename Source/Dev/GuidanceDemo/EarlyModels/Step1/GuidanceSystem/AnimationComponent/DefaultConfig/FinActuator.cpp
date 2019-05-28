/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: FinActuator
//!	Generated Date	: Tue, 10, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\FinActuator.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "stdafx.h"
#include "FinActuator.h"
#include "FinActuatorCoeff.h"
#include "On1DConn.h"

//## package GuidancePkg 

//----------------------------------------------------------------------------
// FinActuator.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(GuidancePkg)
//## class FinActuator 



FinActuator::FinActuator() {
    pCoeff = NULL;
    pFinConn = NULL;
    //#[ operation FinActuator() 
    init();
    //#]
}

FinActuator::~FinActuator() {
    //#[ operation ~FinActuator() 
    clean();
    //#]
    cleanUpRelations();
}

HRESULT FinActuator::InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form) {
    //#[ operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
    const long idx_eqn_r_angle = 0;
    const long idx_eqn_r_rate = 1;
    
    DESTROY_VECTOR(*form)
    *form = new OnEqnForm[m_nLocalEqns];
    (*form)[idx_eqn_r_angle] = continuous;
    (*form)[idx_eqn_r_rate] = continuous;
    
    DESTROY_VECTOR(*diff_form)
    *diff_form = new OnEqnDiffForm[m_nLocalEqns];
    (*diff_form)[idx_eqn_r_angle] = automatic;
    (*diff_form)[idx_eqn_r_rate] = automatic;
    
    return S_OK;
    //#]
}

HRESULT FinActuator::InitEsos() {
    //#[ operation InitEsos() 
    ADD_LOCAL_ESO(pFinConn)
    
    return S_OK;
    //#]
}

HRESULT FinActuator::InitLocalADEqns() {
    //#[ operation InitLocalADEqns() 
    ADD_LOCAL_AD_EQN(FinActuator, ad_r_angle)
    ADD_LOCAL_AD_EQN(FinActuator, ad_r_rate)
    
    return S_OK;
    //#]
}

HRESULT FinActuator::InitLocalEqns() {
    //#[ operation InitLocalEqns() 
    ADD_LOCAL_EQN(FinActuator, r_angle)
    ADD_LOCAL_EQN(FinActuator, r_rate)
    
    return S_OK;
    //#]
}

HRESULT FinActuator::InitLocalRPars(const _TCHAR * prefix, ppdouble * pars, ppchar * Names, long * nPars, long * dPars) {
    //#[ operation InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ) 
    
     ADD_LOCAL_SRPAR(AngleSetpoint)
    
     return S_OK;
    //#]
}

HRESULT FinActuator::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    
     ADD_LOCAL_SVAR(rate)
    
     for (long i = 0; i < m_nEsos; i++)
       AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
     return S_OK; 
    //#]
}

bool FinActuator::Load(FILE * fs) {
    //#[ operation Load(FILE * ) 
    return true;
    //#]
}

void FinActuator::Save(FILE * fs) {
    //#[ operation Save(FILE * ) 
    //#]
}

HRESULT FinActuator::ad_r_angle(Fdouble * res) {
    //#[ operation ad_r_angle(Fdouble * ) 
    *res = pFinConn->DER_AD(pos) - AD(rate);
    return S_OK;
    //#]
}

HRESULT FinActuator::ad_r_rate(Fdouble * res) {
    //#[ operation ad_r_rate(Fdouble * ) 
    double Zeta = pCoeff->damping;
    double Wn   = pCoeff->bandwidth;
    double gain = pCoeff->gain;
    
    *res = DER_AD(rate) + 2.0 * Zeta * Wn * AD(rate) 
                   + Wn * Wn * pFinConn->AD(pos) 
                   - Wn * Wn * AngleSetpoint * gain;
    return S_OK;
    //#]
}

void FinActuator::clean() {
    //#[ operation clean() 
    if (pCoeff)
    {
      delete pCoeff;
      pCoeff = NULL;
    }
    
    if (pFinConn)
    {
      pFinConn->Release();
      pFinConn = NULL;
    }
    //#]
}

void FinActuator::init() {
    //#[ operation init() 
    pCoeff = new FinActuatorCoeff();
    pFinConn = new On1DConn();
    pFinConn->AddRef();
    AngleSetpoint = 0.0;
    rate = 0.0;
    DER(rate) = 0.0;
    //#]
}

HRESULT FinActuator::r_angle(double * res) {
    //#[ operation r_angle(double * ) 
    *res = pFinConn->DER(pos) - rate;
    return S_OK;
    //#]
}

HRESULT FinActuator::r_rate(double * res) {
    //#[ operation r_rate(double * ) 
    double Zeta = pCoeff->damping;
    double Wn   = pCoeff->bandwidth;
    double gain = pCoeff->gain;
    
    *res = DER(rate) + 2.0 * Zeta * Wn * rate 
                   + Wn * Wn * pFinConn->pos 
                   - Wn * Wn * AngleSetpoint * gain;
    return S_OK;
    //#]
}

void FinActuator::setAngleSetpoint(const double time, double * val) {
    //#[ operation setAngleSetpoint(const double ,double * ) 
    const long idx_rpar_AngleSetpoint = 0;
    double angleVal;
    // WAH
    //if(*val < pCoeff->min_angle) angleVal = pCoeff->min_angle;
    //else if(*val > pCoeff->max_angle) angleVal = pCoeff->max_angle;
    //else angleVal = *val;
    angleVal = *val;
    // WAH PostRealParameter(time, idx_rpar_AngleSetpoint, *val);
    PostRealParameter(time, idx_rpar_AngleSetpoint, angleVal);
    //#]
}

void FinActuator::setAngleSetpoint(double  p_AngleSetpoint) {
    AngleSetpoint = p_AngleSetpoint;
}

void FinActuator::set_rate(VarEx p__rate) {
    _rate = p__rate;
}

void FinActuator::setRate(double  p_rate) {
    rate = p_rate;
}

FinActuatorCoeff* FinActuator::getPCoeff() const {
    return pCoeff;
}

void FinActuator::setPCoeff(FinActuatorCoeff*  p_FinActuatorCoeff) {
    pCoeff = p_FinActuatorCoeff;
    if(p_FinActuatorCoeff != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("pCoeff", p_FinActuatorCoeff, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("pCoeff");
        }
}

On1DConn* FinActuator::getPFinConn() const {
    return pFinConn;
}

void FinActuator::setPFinConn(On1DConn*  p_On1DConn) {
    pFinConn = p_On1DConn;
    if(p_On1DConn != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("pFinConn", p_On1DConn, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("pFinConn");
        }
}

void FinActuator::cleanUpRelations() {
    if(pCoeff != NULL)
        {
            NOTIFY_RELATION_CLEARED("pCoeff");
            pCoeff = NULL;
        }
    if(pFinConn != NULL)
        {
            NOTIFY_RELATION_CLEARED("pFinConn");
            pFinConn = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedFinActuator::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedFinActuator::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("pCoeff", FALSE, TRUE);
    if(myReal->pCoeff)
        aomsRelations->ADD_ITEM(myReal->pCoeff);
    aomsRelations->addRelation("pFinConn", FALSE, TRUE);
    if(myReal->pFinConn)
        aomsRelations->ADD_ITEM(myReal->pFinConn);
}

IMPLEMENT_META(FinActuator, GuidancePkg, FALSE, OMAnimatedFinActuator)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\FinActuator.cpp
*********************************************************************/

