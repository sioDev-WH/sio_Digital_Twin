/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Reactor
//!	Generated Date	: Sun, 15, Sep 2002  
	File Path	: DefaultComponent\DefaultConfig\Reactor.cpp
*********************************************************************/

#include "stdafx.h"
#include "RpyReactor.h"
#include <oxf/omthread.h>
#include "Reactor.h"
#include "OnAD.h"
#include <math.h>
#include "OnUMLEso.h"

//## package ProcessModels 

//----------------------------------------------------------------------------
// Reactor.cpp                                                                  
//----------------------------------------------------------------------------
//## class Reactor 



Reactor::Reactor(OMThread*  p_thread) : T_reactor(740.0) ,C_heptane(476.0) ,C_toluene(524.0) ,C_hydrogen(2097.0) ,Delta_H(0.0) ,K(0.0) ,Q_heptane_in(3.0) ,T_heptane_in(300.0) ,C_heptane_in(1000.0) ,T_recycle_in(889.0) ,K0(5.01e8) ,E0(1.369e5) ,R(8.319) ,Cp(490.7) ,rho(593.0) ,a(10.0) ,h(6.05e5) ,V(30.0) {
    setThread(p_thread, FALSE);
    initRelations();

    // fault 1: set K0
    // K0 = 0.75 * 5.01e8;

    // fault 2: set h
    // h = 0.75 * 6.05e5;

    // fault 4: set Q_heptane
    // Q_heptane_in = 0.8 * 3.0;


    DER(T_reactor) = 0.0;
    DER(C_heptane) = 0.0;
    DER(C_toluene) = 0.0;
    DER(C_hydrogen) = 0.0;
    DER(T_recycle_in) = 0.0;
}

Reactor::~Reactor() {
    cleanUpRelations();
}

HRESULT Reactor::InitEqnForm(OnEqnForm**  form, OnEqnDiffForm**  diff_form) {
    //#[ operation InitEqnForm(OnEqnForm**,OnEqnDiffForm**) 
    
    
    const long idx_eqn_r_ReactorEnergyBalance = 0;
    const long idx_eqn_r_ReactorMassBalance0 = 1;
    const long idx_eqn_r_ReactorMassBalance1 = 2;
    const long idx_eqn_r_ReactorMassBalance2 = 3;
    
      DESTROY_VECTOR(*form)
      *form = new OnEqnForm[m_nLocalEqns];
      (*form)[idx_eqn_r_ReactorEnergyBalance] = continuous;
      (*form)[idx_eqn_r_ReactorMassBalance0] = continuous;
      (*form)[idx_eqn_r_ReactorMassBalance1] = continuous;
      (*form)[idx_eqn_r_ReactorMassBalance2] = continuous;
    
      DESTROY_VECTOR(*diff_form)
      *diff_form = new OnEqnDiffForm[m_nLocalEqns];
      (*diff_form)[idx_eqn_r_ReactorEnergyBalance] = automatic;
      (*diff_form)[idx_eqn_r_ReactorMassBalance0] = automatic;
      (*diff_form)[idx_eqn_r_ReactorMassBalance1] = automatic;
      (*diff_form)[idx_eqn_r_ReactorMassBalance2] = automatic;
    
      return S_OK;
    //#]
}

HRESULT Reactor::InitLocalADEqns() {
    //#[ operation InitLocalADEqns() 
    
      ADD_LOCAL_AD_EQN(Reactor, ad_r_ReactorEnergyBalance)
      ADD_LOCAL_AD_EQN(Reactor, ad_r_ReactorMassBalance0)
      ADD_LOCAL_AD_EQN(Reactor, ad_r_ReactorMassBalance1)
      ADD_LOCAL_AD_EQN(Reactor, ad_r_ReactorMassBalance2)
    
      return S_OK;
    //#]
}

HRESULT Reactor::InitLocalEqns() {
    //#[ operation InitLocalEqns() 
    
      ADD_LOCAL_EQN(Reactor, r_ReactorEnergyBalance)
      ADD_LOCAL_EQN(Reactor, r_ReactorMassBalance0)
      ADD_LOCAL_EQN(Reactor, r_ReactorMassBalance1)
      ADD_LOCAL_EQN(Reactor, r_ReactorMassBalance2)
    
      return S_OK;
    //#]
}

HRESULT Reactor::InitLocalRPars(const _TCHAR*  prefix, ppdouble*  pars, ppchar*  Names, long*  nPars, long*  dPars) {
    //#[ operation InitLocalRPars(_TCHAR*,ppdouble*,ppchar*,long*,long*) 
    
    
      ADD_LOCAL_SRPAR(Q_heptane_in)
      ADD_LOCAL_SRPAR(T_heptane_in)
      ADD_LOCAL_SRPAR(C_heptane_in)
      ADD_LOCAL_SRPAR(K0)
      ADD_LOCAL_SRPAR(E0)
      ADD_LOCAL_SRPAR(R)
      ADD_LOCAL_SRPAR(Cp)
      ADD_LOCAL_SRPAR(rho)
      ADD_LOCAL_SRPAR(a)
      ADD_LOCAL_SRPAR(h)
      ADD_LOCAL_SRPAR(V)
    
      return S_OK;
    //#]
}

HRESULT Reactor::InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly) {
    //#[ operation InitLocalVars(_TCHAR*,ppdouble*,ppdouble*,ppdouble*,ppdouble*,ppfdouble*,ppfdouble*,ppchar*,long*,long*,long*,long*,bool) 
    
    
      ADD_LOCAL_SVAR(T_reactor)
      ADD_LOCAL_SVAR(C_heptane)
      ADD_LOCAL_SVAR(C_toluene)
      ADD_LOCAL_SVAR(C_hydrogen)
      ADD_LOCAL_SVAR(T_recycle_in)
    
    for (long i = 0; i < m_nEsos; i++)
      AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
      return S_OK;
    //#]
}

bool Reactor::Load(FILE*  fs) {
    //#[ operation Load(FILE*) 
  READ_SCALAR( C_heptane )
  READ_SCALAR( C_heptane_in )
  READ_SCALAR( C_hydrogen )
  READ_SCALAR( C_toluene )
  READ_SCALAR( Cp )
  READ_SCALAR( Delta_H )
  READ_SCALAR( E0 )
  READ_SCALAR( K )
  READ_SCALAR( K0 )
  READ_SCALAR( Q_heptane_in )
  READ_SCALAR( R )
  READ_SCALAR( T_heptane_in )
  READ_SCALAR( T_reactor )
  READ_SCALAR( T_recycle_in )
  READ_SCALAR( V )
  READ_SCALAR( a )
  READ_SCALAR( der_C_heptane )
  READ_SCALAR( der_C_hydrogen )
  READ_SCALAR( der_C_toluene )
  READ_SCALAR( der_T_reactor )
  READ_SCALAR( der_T_recycle_in )
  READ_SCALAR( h )
  READ_SCALAR( rho )
    
    return true;
    //#]
}

void Reactor::Save(FILE*  fs) {
    //#[ operation Save(FILE*) 
  WRITE_SCALAR( C_heptane )
  WRITE_SCALAR( C_heptane_in )
  WRITE_SCALAR( C_hydrogen )
  WRITE_SCALAR( C_toluene )
  WRITE_SCALAR( Cp )
  WRITE_SCALAR( Delta_H )
  WRITE_SCALAR( E0 )
  WRITE_SCALAR( K )
  WRITE_SCALAR( K0 )
  WRITE_SCALAR( Q_heptane_in )
  WRITE_SCALAR( R )
  WRITE_SCALAR( T_heptane_in )
  WRITE_SCALAR( T_reactor )
  WRITE_SCALAR( T_recycle_in )
  WRITE_SCALAR( V )
  WRITE_SCALAR( a )
  WRITE_SCALAR( der_C_heptane )
  WRITE_SCALAR( der_C_hydrogen )
  WRITE_SCALAR( der_C_toluene )
  WRITE_SCALAR( der_T_reactor )
  WRITE_SCALAR( der_T_recycle_in )
  WRITE_SCALAR( h )
  WRITE_SCALAR( rho )
    //#]
}

HRESULT Reactor::ad_r_ReactorEnergyBalance(Fdouble*  res) {
    //#[ operation ad_r_ReactorEnergyBalance(Fdouble*) 
    // have to expand get_Delta_H() because it is expressed in terms of variables
    Fdouble ad_Delta_H;
    Fdouble ad_K;

    ad_Delta_H = (((3.1496e-7 * ad_T_reactor - 1.15e-6) * ad_T_reactor - 5.536e-2) * ad_T_reactor + 6.2044e1) * ad_T_reactor + 2.2026e5;
    // have to expand get_K() because it is expressed in terms of variables
    ad_K = K0 * exp(-E0/R/ad_T_reactor);

    
    *res = 
    DER(ad_T_reactor) - Q_heptane_in * ( T_heptane_in  - ad_T_reactor) / V   
    + ad_Delta_H * ad_K * ad_C_heptane / rho / Cp
    - a * h * (ad_T_recycle_in  - ad_T_reactor) / rho / Cp / V;
    return S_OK;
     
    //#]
}

HRESULT Reactor::ad_r_ReactorMassBalance0(Fdouble*  res) {
    //#[ operation ad_r_ReactorMassBalance0(Fdouble*) 
    Fdouble ad_K;

    ad_K = K0 * exp(-E0/R/ad_T_reactor);
    *res = DER(ad_C_toluene) + Q_heptane_in* ad_C_toluene / V - ad_K * ad_C_heptane;
    return S_OK;
    //#]
}

HRESULT Reactor::ad_r_ReactorMassBalance1(Fdouble*  res) {
    //#[ operation ad_r_ReactorMassBalance1(Fdouble*) 
    Fdouble ad_K;

    ad_K = K0 * exp(-E0/R/ad_T_reactor);
    *res = DER(ad_C_hydrogen) + Q_heptane_in* ad_C_hydrogen / V - 4 * ad_K * ad_C_heptane;
    return S_OK;
    //#]
}

HRESULT Reactor::ad_r_ReactorMassBalance2(Fdouble*  res) {
    //#[ operation ad_r_ReactorMassBalance2(Fdouble*) 
    Fdouble ad_K;

    ad_K = K0 * exp(-E0/R/ad_T_reactor);
    *res = DER(ad_C_heptane) + Q_heptane_in* (ad_C_heptane - C_heptane_in) / V + ad_K * ad_C_heptane; 
    return S_OK;
    //#]
}

double Reactor::get_Delta_H() {
    //#[ operation get_Delta_H() 
    return (((3.1496e-7 * T_reactor - 1.15e-6) * T_reactor - 5.536e-2) * T_reactor + 6.2044e1) * T_reactor + 2.2026e5;
    
    //#]
}

double Reactor::get_K() {
    //#[ operation get_K() 
    //return K0 * exp(-Ea/R/T);
    return K0 * exp(-E0/R/T_reactor);
    //#]
}

void Reactor::handle_C_heptane_in(double  t, double*  val) {
    //#[ operation handle_C_heptane_in(double,double*) 
    
    PostRealParameter(t, 2, *val);
    //#]
}

void Reactor::handle_Cp(double  t, double*  val) {
    //#[ operation handle_Cp(double,double*) 
    
    PostRealParameter(t, 6, *val);
    //#]
}

void Reactor::handle_E0(double  t, double*  val) {
    //#[ operation handle_E0(double,double*) 
    
    PostRealParameter(t, 4, *val);
    //#]
}

void Reactor::handle_K0(double  t, double*  val) {
    //#[ operation handle_K0(double,double*) 
    
    PostRealParameter(t, 3, *val);
    //#]
}

void Reactor::handle_Q_heptane_in(double  t, double*  val) {
    //#[ operation handle_Q_heptane_in(double,double*) 
    
    PostRealParameter(t, 0, *val);
    //#]
}

void Reactor::handle_R(double  t, double*  val) {
    //#[ operation handle_R(double,double*) 
    
    PostRealParameter(t, 5, *val);
    //#]
}

void Reactor::handle_T_heptane_in(double  t, double*  val) {
    //#[ operation handle_T_heptane_in(double,double*) 
    
    PostRealParameter(t, 1, *val);
    //#]
}

void Reactor::handle_V(double  t, double*  val) {
    //#[ operation handle_V(double,double*) 
    
    PostRealParameter(t, 10, *val);
    //#]
}

void Reactor::handle_a(double  t, double*  val) {
    //#[ operation handle_a(double,double*) 
    
    PostRealParameter(t, 8, *val);
    //#]
}

void Reactor::handle_h(double  t, double*  val) {
    //#[ operation handle_h(double,double*) 
    
    PostRealParameter(t, 9, *val);
    //#]
}

void Reactor::handle_rho(double  t, double*  val) {
    //#[ operation handle_rho(double,double*) 
    
    PostRealParameter(t, 7, *val);
    //#]
}

HRESULT Reactor::r_ReactorEnergyBalance(double*  res) {
    //#[ operation r_ReactorEnergyBalance(double*) 
    Delta_H = get_Delta_H();
    K = get_K();
    
    *res = 
    DER(T_reactor) - Q_heptane_in * ( T_heptane_in  - T_reactor) / V   
    + Delta_H * K * C_heptane / rho / Cp
    - a * h * (T_recycle_in  - T_reactor) / rho / Cp / V;
    return S_OK;
     
    //#]
}

HRESULT Reactor::r_ReactorMassBalance0(double*  res) {
    //#[ operation r_ReactorMassBalance0(double*) 
    K = get_K();
    
    *res = DER(C_toluene) + Q_heptane_in* C_toluene / V - K * C_heptane;
    return S_OK;
    //#]
}

HRESULT Reactor::r_ReactorMassBalance1(double*  res) {
    //#[ operation r_ReactorMassBalance1(double*) 
    K = get_K();
    
    *res = DER(C_hydrogen) + Q_heptane_in* C_hydrogen / V - 4 * K * C_heptane;
    return S_OK;
    //#]
}

HRESULT Reactor::r_ReactorMassBalance2(double*  res) {
    //#[ operation r_ReactorMassBalance2(double*) 
    K = get_K();
    
    *res = DER(C_heptane) + Q_heptane_in* (C_heptane - C_heptane_in) / V + K * C_heptane; 
    return S_OK;
    //#]
}

double Reactor::getC_heptane() const {
    return C_heptane;
}

void Reactor::setC_heptane(double  p_C_heptane) {
    C_heptane = p_C_heptane;
}

double Reactor::getC_heptane_in() const {
    return C_heptane_in;
}

void Reactor::setC_heptane_in(double  p_C_heptane_in) {
    C_heptane_in = p_C_heptane_in;
}

double Reactor::getC_hydrogen() const {
    return C_hydrogen;
}

void Reactor::setC_hydrogen(double  p_C_hydrogen) {
    C_hydrogen = p_C_hydrogen;
}

double Reactor::getC_toluene() const {
    return C_toluene;
}

void Reactor::setC_toluene(double  p_C_toluene) {
    C_toluene = p_C_toluene;
}

double Reactor::getCp() const {
    return Cp;
}

void Reactor::setCp(double  p_Cp) {
    Cp = p_Cp;
}

double Reactor::getDelta_H() const {
    return Delta_H;
}

void Reactor::setDelta_H(double  p_Delta_H) {
    Delta_H = p_Delta_H;
}

double Reactor::getE0() const {
    return E0;
}

void Reactor::setE0(double  p_E0) {
    E0 = p_E0;
}

double Reactor::getK() const {
    return K;
}

void Reactor::setK(double  p_K) {
    K = p_K;
}

double Reactor::getK0() const {
    return K0;
}

void Reactor::setK0(double  p_K0) {
    K0 = p_K0;
}

double Reactor::getQ_heptane_in() const {
    return Q_heptane_in;
}

void Reactor::setQ_heptane_in(double  p_Q_heptane_in) {
    Q_heptane_in = p_Q_heptane_in;
}

double Reactor::getR() const {
    return R;
}

void Reactor::setR(double  p_R) {
    R = p_R;
}

double Reactor::getT_heptane_in() const {
    return T_heptane_in;
}

void Reactor::setT_heptane_in(double  p_T_heptane_in) {
    T_heptane_in = p_T_heptane_in;
}

double Reactor::getT_reactor(double t) const {
    //return T_reactor;
    
    // get the interpolated value
    double val;
    m_pOnModel->GetVariable(0, t, &val);
    return val;
}

void Reactor::setT_reactor(double  p_T_reactor) {
    T_reactor = p_T_reactor;
}

double Reactor::getT_recycle_in() const {
    return T_recycle_in;
}

void Reactor::setT_recycle_in(double  p_T_recycle_in) {
    T_recycle_in = p_T_recycle_in;
}

double Reactor::getV() const {
    return V;
}

void Reactor::setV(double  p_V) {
    V = p_V;
}

double Reactor::getA() const {
    return a;
}

void Reactor::setA(double  p_a) {
    a = p_a;
}

double Reactor::getDer_C_heptane() const {
    return der_C_heptane;
}

void Reactor::setDer_C_heptane(double  p_der_C_heptane) {
    der_C_heptane = p_der_C_heptane;
}

double Reactor::getDer_C_hydrogen() const {
    return der_C_hydrogen;
}

void Reactor::setDer_C_hydrogen(double  p_der_C_hydrogen) {
    der_C_hydrogen = p_der_C_hydrogen;
}

double Reactor::getDer_C_toluene() const {
    return der_C_toluene;
}

void Reactor::setDer_C_toluene(double  p_der_C_toluene) {
    der_C_toluene = p_der_C_toluene;
}

double Reactor::getDer_T_reactor() const {
    return der_T_reactor;
}

void Reactor::setDer_T_reactor(double  p_der_T_reactor) {
    der_T_reactor = p_der_T_reactor;
}

double Reactor::getDer_T_recycle_in() const {
    return der_T_recycle_in;
}

void Reactor::setDer_T_recycle_in(double  p_der_T_recycle_in) {
    der_T_recycle_in = p_der_T_recycle_in;
}

double Reactor::getDer_old_C_heptane() const {
    return der_old_C_heptane;
}

void Reactor::setDer_old_C_heptane(double  p_der_old_C_heptane) {
    der_old_C_heptane = p_der_old_C_heptane;
}

double Reactor::getDer_old_C_hydrogen() const {
    return der_old_C_hydrogen;
}

void Reactor::setDer_old_C_hydrogen(double  p_der_old_C_hydrogen) {
    der_old_C_hydrogen = p_der_old_C_hydrogen;
}

double Reactor::getDer_old_C_toluene() const {
    return der_old_C_toluene;
}

void Reactor::setDer_old_C_toluene(double  p_der_old_C_toluene) {
    der_old_C_toluene = p_der_old_C_toluene;
}

double Reactor::getDer_old_T_reactor() const {
    return der_old_T_reactor;
}

void Reactor::setDer_old_T_reactor(double  p_der_old_T_reactor) {
    der_old_T_reactor = p_der_old_T_reactor;
}

double Reactor::getDer_old_T_recycle_in() const {
    return der_old_T_recycle_in;
}

void Reactor::setDer_old_T_recycle_in(double  p_der_old_T_recycle_in) {
    der_old_T_recycle_in = p_der_old_T_recycle_in;
}

double Reactor::getH() const {
    return h;
}

void Reactor::setH(double  p_h) {
    h = p_h;
}

double Reactor::getOld_C_heptane() const {
    return old_C_heptane;
}

void Reactor::setOld_C_heptane(double  p_old_C_heptane) {
    old_C_heptane = p_old_C_heptane;
}

double Reactor::getOld_C_hydrogen() const {
    return old_C_hydrogen;
}

void Reactor::setOld_C_hydrogen(double  p_old_C_hydrogen) {
    old_C_hydrogen = p_old_C_hydrogen;
}

double Reactor::getOld_C_toluene() const {
    return old_C_toluene;
}

void Reactor::setOld_C_toluene(double  p_old_C_toluene) {
    old_C_toluene = p_old_C_toluene;
}

double Reactor::getOld_T_reactor() const {
    return old_T_reactor;
}

void Reactor::setOld_T_reactor(double  p_old_T_reactor) {
    old_T_reactor = p_old_T_reactor;
}

double Reactor::getOld_T_recycle_in() const {
    return old_T_recycle_in;
}

void Reactor::setOld_T_recycle_in(double  p_old_T_recycle_in) {
    old_T_recycle_in = p_old_T_recycle_in;
}

double Reactor::getRho() const {
    return rho;
}

void Reactor::setRho(double  p_rho) {
    rho = p_rho;
}

Fdouble Reactor::getAd_C_heptane() const {
    return ad_C_heptane;
}

Fdouble Reactor::getAd_C_hydrogen() const {
    return ad_C_hydrogen;
}

Fdouble Reactor::getAd_C_toluene() const {
    return ad_C_toluene;
}

Fdouble Reactor::getAd_T_reactor() const {
    return ad_T_reactor;
}

Fdouble Reactor::getAd_T_recycle_in() const {
    return ad_T_recycle_in;
}

Fdouble Reactor::getDer_ad_C_heptane() const {
    return der_ad_C_heptane;
}

Fdouble Reactor::getDer_ad_C_hydrogen() const {
    return der_ad_C_hydrogen;
}

Fdouble Reactor::getDer_ad_C_toluene() const {
    return der_ad_C_toluene;
}

Fdouble Reactor::getDer_ad_T_reactor() const {
    return der_ad_T_reactor;
}

Fdouble Reactor::getDer_ad_T_recycle_in() const {
    return der_ad_T_recycle_in;
}

void Reactor::initRelations() {
}

void Reactor::cleanUpRelations() {
}

OMBoolean Reactor::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Reactor.cpp
*********************************************************************/

