/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Heater
//!	Generated Date	: Sun, 15, Sep 2002  
	File Path	: DefaultComponent\DefaultConfig\Heater.cpp
*********************************************************************/

#include "stdafx.h"
#include <oxf/omthread.h>
#include "Heater.h"
#include "Controller.h"
#include "OnAD.h"

//## package ProcessModels 

//----------------------------------------------------------------------------
// Heater.cpp                                                                  
//----------------------------------------------------------------------------
//## class Heater 



Heater::Heater(OMThread*  p_thread) : T_heater(889.0) ,T_in(740.0) ,Q_in(0.0) ,Sh(223.0) ,tau(0.2) ,Gain(1.0) ,Recycle_Ratio(0.9) {
    setThread(p_thread, FALSE);
    initRelations();

    DER(T_heater) = 0.0;
    DER(T_in) = 0.0;
    DER(Q_in) = 0.0;
}

Heater::~Heater() {
    cleanUpRelations();
}

HRESULT Heater::InitEqnForm(OnEqnForm**  form, OnEqnDiffForm**  diff_form) {
    //#[ operation InitEqnForm(OnEqnForm**,OnEqnDiffForm**) 
    
    
    const long idx_eqn_r_HeaterEnergyBalance = 0;
    
      DESTROY_VECTOR(*form)
      *form = new OnEqnForm[m_nLocalEqns];
      (*form)[idx_eqn_r_HeaterEnergyBalance] = continuous;
    
      DESTROY_VECTOR(*diff_form)
      *diff_form = new OnEqnDiffForm[m_nLocalEqns];
      (*diff_form)[idx_eqn_r_HeaterEnergyBalance] = automatic;
    
      return S_OK;
    //#]
}

HRESULT Heater::InitLocalADEqns() {
    //#[ operation InitLocalADEqns() 
    
      ADD_LOCAL_AD_EQN(Heater, ad_r_HeaterEnergyBalance)
    
      return S_OK;
    //#]
}

HRESULT Heater::InitLocalEqns() {
    //#[ operation InitLocalEqns() 
    
      ADD_LOCAL_EQN(Heater, r_HeaterEnergyBalance)
    
      return S_OK;
    //#]
}

HRESULT Heater::InitLocalRPars(const _TCHAR*  prefix, ppdouble*  pars, ppchar*  Names, long*  nPars, long*  dPars) {
    //#[ operation InitLocalRPars(_TCHAR*,ppdouble*,ppchar*,long*,long*) 
    
    
      ADD_LOCAL_SRPAR(Sh)
      ADD_LOCAL_SRPAR(tau)
      ADD_LOCAL_SRPAR(Gain)
      ADD_LOCAL_SRPAR(Recycle_Ratio)
    
      return S_OK;
    //#]
}

HRESULT Heater::InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly) {
    //#[ operation InitLocalVars(_TCHAR*,ppdouble*,ppdouble*,ppdouble*,ppdouble*,ppfdouble*,ppfdouble*,ppchar*,long*,long*,long*,long*,bool) 
    
    
      ADD_LOCAL_SVAR(T_heater)
      ADD_LOCAL_SVAR(T_in)
      ADD_LOCAL_SVAR(Q_in)
    
    for (long i = 0; i < m_nEsos; i++)
      AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
      return S_OK;
    //#]
}

bool Heater::Load(FILE*  fs) {
    //#[ operation Load(FILE*) 
  READ_SCALAR( Gain )
  READ_SCALAR( Q_in )
  READ_SCALAR( Recycle_Ratio )
  READ_SCALAR( Sh )
  READ_SCALAR( T_heater )
  READ_SCALAR( T_in )
  READ_SCALAR( der_Q_in )
  READ_SCALAR( der_T_heater )
  READ_SCALAR( der_T_in )
  READ_SCALAR( tau )
    
    return true;
    //#]
}

void Heater::Save(FILE*  fs) {
    //#[ operation Save(FILE*) 
  WRITE_SCALAR( Gain )
  WRITE_SCALAR( Q_in )
  WRITE_SCALAR( Recycle_Ratio )
  WRITE_SCALAR( Sh )
  WRITE_SCALAR( T_heater )
  WRITE_SCALAR( T_in )
  WRITE_SCALAR( der_Q_in )
  WRITE_SCALAR( der_T_heater )
  WRITE_SCALAR( der_T_in )
  WRITE_SCALAR( tau )
    //#]
}

HRESULT Heater::ad_r_HeaterEnergyBalance(Fdouble*  res) {
    //#[ operation ad_r_HeaterEnergyBalance(Fdouble*) 
    //Sh = itsController->get_Output(); 
    *res = DER(ad_T_heater) - (Recycle_Ratio * ad_T_in - ad_T_heater) / tau - Gain * Sh / tau;
    return S_OK;
    //#]
}

void Heater::handle_Gain(double  t, double*  val) {
    //#[ operation handle_Gain(double,double*) 
    
    PostRealParameter(t, 2, *val);
    //#]
}

void Heater::handle_Recycle_Ratio(double  t, double*  val) {
    //#[ operation handle_Recycle_Ratio(double,double*) 
    
    PostRealParameter(t, 3, *val);
    //#]
}

void Heater::handle_Sh(double  t, double*  val) {
    //#[ operation handle_Sh(double,double*) 
    
    PostRealParameter(t, 0, *val);
    //#]
}

void Heater::handle_tau(double  t, double*  val) {
    //#[ operation handle_tau(double,double*) 
    
    PostRealParameter(t, 1, *val);
    //#]
}

HRESULT Heater::r_HeaterEnergyBalance(double*  res) {
    //#[ operation r_HeaterEnergyBalance(double*) 
    //Sh = itsController->get_Output(); 
    *res = DER(T_heater) - (Recycle_Ratio * T_in - T_heater) / tau - Gain * Sh / tau;
    return S_OK;
    //#]
}

double Heater::getGain() const {
    return Gain;
}

void Heater::setGain(double  p_Gain) {
    Gain = p_Gain;
}

double Heater::getQ_in() const {
    return Q_in;
}

void Heater::setQ_in(double  p_Q_in) {
    Q_in = p_Q_in;
}

double Heater::getRecycle_Ratio() const {
    return Recycle_Ratio;
}

void Heater::setRecycle_Ratio(double  p_Recycle_Ratio) {
    Recycle_Ratio = p_Recycle_Ratio;
}

double Heater::getSh() const {
    return Sh;
}

void Heater::setSh(double  p_Sh) {
    Sh = p_Sh;
}

double Heater::getT_heater() const {
    return T_heater;
}

void Heater::setT_heater(double  p_T_heater) {
    T_heater = p_T_heater;
}

double Heater::getT_in() const {
    return T_in;
}

void Heater::setT_in(double  p_T_in) {
    T_in = p_T_in;
}

double Heater::getDer_Q_in() const {
    return der_Q_in;
}

void Heater::setDer_Q_in(double  p_der_Q_in) {
    der_Q_in = p_der_Q_in;
}

double Heater::getDer_T_heater() const {
    return der_T_heater;
}

void Heater::setDer_T_heater(double  p_der_T_heater) {
    der_T_heater = p_der_T_heater;
}

double Heater::getDer_T_in() const {
    return der_T_in;
}

void Heater::setDer_T_in(double  p_der_T_in) {
    der_T_in = p_der_T_in;
}

double Heater::getDer_old_Q_in() const {
    return der_old_Q_in;
}

void Heater::setDer_old_Q_in(double  p_der_old_Q_in) {
    der_old_Q_in = p_der_old_Q_in;
}

double Heater::getDer_old_T_heater() const {
    return der_old_T_heater;
}

void Heater::setDer_old_T_heater(double  p_der_old_T_heater) {
    der_old_T_heater = p_der_old_T_heater;
}

double Heater::getDer_old_T_in() const {
    return der_old_T_in;
}

void Heater::setDer_old_T_in(double  p_der_old_T_in) {
    der_old_T_in = p_der_old_T_in;
}

double Heater::getOld_Q_in() const {
    return old_Q_in;
}

void Heater::setOld_Q_in(double  p_old_Q_in) {
    old_Q_in = p_old_Q_in;
}

double Heater::getOld_T_heater() const {
    return old_T_heater;
}

void Heater::setOld_T_heater(double  p_old_T_heater) {
    old_T_heater = p_old_T_heater;
}

double Heater::getOld_T_in() const {
    return old_T_in;
}

void Heater::setOld_T_in(double  p_old_T_in) {
    old_T_in = p_old_T_in;
}

double Heater::getTau() const {
    return tau;
}

void Heater::setTau(double  p_tau) {
    tau = p_tau;
}

Fdouble Heater::getAd_Q_in() const {
    return ad_Q_in;
}

Fdouble Heater::getAd_T_heater() const {
    return ad_T_heater;
}

Fdouble Heater::getAd_T_in() const {
    return ad_T_in;
}

Fdouble Heater::getDer_ad_Q_in() const {
    return der_ad_Q_in;
}

Fdouble Heater::getDer_ad_T_heater() const {
    return der_ad_T_heater;
}

Fdouble Heater::getDer_ad_T_in() const {
    return der_ad_T_in;
}

void Heater::initRelations() {
}

void Heater::cleanUpRelations() {
}

OMBoolean Heater::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Heater.cpp
*********************************************************************/

