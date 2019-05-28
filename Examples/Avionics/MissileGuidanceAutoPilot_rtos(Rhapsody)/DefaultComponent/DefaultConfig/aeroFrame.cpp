/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: aeroFrame
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\aeroFrame.cpp
*********************************************************************/

#include <oxf/omthread.h>
#include "aeroFrame.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// aeroFrame.cpp                                                                  
//----------------------------------------------------------------------------
//## class aeroFrame 



aeroFrame::aeroFrame(OMThread*  p_thread) {
    setThread(p_thread, FALSE);
    //#[ operation aeroFrame() 
    init();
    //#]
}

aeroFrame::~aeroFrame() {
    //#[ operation ~aeroFrame() 
    clean();
    //#]
}

HRESULT aeroFrame::InitEqnForm(OnEqnForm**  form, OnEqnDiffForm**  diff_form) {
    //#[ operation InitEqnForm(OnEqnForm**,OnEqnDiffForm**) 
    
    
    const long idx_eqn_r_Position = 0;
    const long idx_eqn_r_Force = 1;
    const long idx_eqn_r_Moments = 2;
    
      DESTROY_VECTOR(*form)
      *form = new OnEqnForm[m_nLocalEqns];
      (*form)[idx_eqn_r_Position] = continuous;
      (*form)[idx_eqn_r_Force] = continuous;
      (*form)[idx_eqn_r_Moments] = continuous;
    
      DESTROY_VECTOR(*diff_form)
      *diff_form = new OnEqnDiffForm[m_nLocalEqns];
      (*diff_form)[idx_eqn_r_Position] = automatic;
      (*diff_form)[idx_eqn_r_Force] = automatic;
      (*diff_form)[idx_eqn_r_Moments] = automatic;
    
      return S_OK;
    //#]
}

HRESULT aeroFrame::InitEsos() {
    //#[ operation InitEsos() 
    
      ADD_LOCAL_ESO(&p)
      ADD_LOCAL_ESO(&ph)
    
      return S_OK;
    //#]
}

HRESULT aeroFrame::InitLocalADEqns() {
    //#[ operation InitLocalADEqns() 
    
      ADD_LOCAL_AD_EQN(aeroFrame, ad_r_Position)
      ADD_LOCAL_STL_AD_EQN(aeroFrame, ad_r_Force, 1)
      ADD_LOCAL_STL_AD_EQN(aeroFrame, ad_r_Moments, 1)
    
      return S_OK;
    //#]
}

HRESULT aeroFrame::InitLocalEqns() {
    //#[ operation InitLocalEqns() 
    
      ADD_LOCAL_EQN(aeroFrame, r_Position)
      ADD_LOCAL_STL_EQN(aeroFrame, r_Force, 1)
      ADD_LOCAL_STL_EQN(aeroFrame, r_Moments, 1)
    
      return S_OK;
    //#]
}

HRESULT aeroFrame::InitLocalRPars(const _TCHAR*  prefix, ppdouble*  pars, ppchar*  Names, long*  nPars, long*  dPars) {
    //#[ operation InitLocalRPars(const _TCHAR*,ppdouble*,ppchar*,long*,long*) 
    
    
      ADD_LOCAL_SRPAR(gravity)
      ADD_LOCAL_SRPAR(mass)
    
      return S_OK;
    //#]
}

HRESULT aeroFrame::InitLocalVars(const _TCHAR*  prefix, VarCont*  varC, const bool  bADOnly) {
    //#[ operation InitLocalVars(const _TCHAR*,VarCont*,const bool) 
    
    
    
    for (long i = 0; i < m_nEsos; i++)
      AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
      return S_OK;
    //#]
}

bool aeroFrame::Load(FILE*  fs) {
    //#[ operation Load(FILE*) 
    
    return true;
    //#]
}

void aeroFrame::Save(FILE*  fs) {
    //#[ operation Save(FILE*) 
    //#]
}

HRESULT aeroFrame::ad_r_Force(valarray<Fdouble>*  res) {
    //#[ operation ad_r_Force(valarray<Fdouble>*) 
    
    if (res->size() != 3) res->resize(3);
    
    (*res)[0] = p.AD(force)[0] + gravity * mass * sin(p.AD(angle)[1]);
    (*res)[1] = p.AD(force)[1];
    (*res)[2] = p.AD(force)[2] - gravity * mass * cos(p.AD(angle)[1]);
    
    return S_OK;
    
    //#]
}

HRESULT aeroFrame::ad_r_Moments(valarray<Fdouble>*  res) {
    //#[ operation ad_r_Moments(valarray<Fdouble>*) 
    
    if (res->size() != 3) res->resize(3);
    
    (*res) = p.AD(moment);
    
    return S_OK;
    
    //#]
}

HRESULT aeroFrame::ad_r_Position(Fdouble*  res) {
    //#[ operation ad_r_Position(Fdouble*) 
    
    *res = ph.AD(height)[0] - p.AD(position)[2]; 
    return S_OK;
    
    //#]
}

void aeroFrame::clean() {
    //#[ operation clean() 
    //#]
}

void aeroFrame::handle_gravity(const double  t, const double*  val) {
    //#[ operation handle_gravity(const double,const double*) 
    
    PostRealParameter(t, 0, *val);
    //#]
}

void aeroFrame::handle_mass(const double  t, const double*  val) {
    //#[ operation handle_mass(const double,const double*) 
    
    PostRealParameter(t, 1, *val);
    //#]
}

void aeroFrame::init() {
    //#[ operation init() 
    #define m2ft 3.280840
    #define Kg2slug 0.0685218
    
    gravity = 9.81;
    mass = 13.98/Kg2slug;
    
    p.velocity[0] = 984.0; // u
    //#]
}

HRESULT aeroFrame::r_Force(valarray<double>*  res) {
    //#[ operation r_Force(valarray<double>*) 
    if (res->size() != 3) res->resize(3);
    
    (*res)[0] = p.force[0] + gravity * mass * sin(p.angle[1]);
    (*res)[1] = p.force[1];
    (*res)[2] = p.force[2] - gravity * mass * cos(p.angle[1]);
    
    return S_OK;
    //#]
}

HRESULT aeroFrame::r_Moments(valarray<double>*  res) {
    //#[ operation r_Moments(valarray<double>*) 
    if (res->size() != 3) res->resize(3);
    
    (*res) = p.moment;
    
    return S_OK;
    //#]
}

HRESULT aeroFrame::r_Position(double * res) {
    //#[ operation r_Position(double * ) 
    *res = ph.height[0] - p.position[2]; 
    return S_OK;
    //#]
}

double aeroFrame::getGravity() const {
    return gravity;
}

void aeroFrame::setGravity(double  p_gravity) {
    gravity = p_gravity;
}

double aeroFrame::getMass() const {
    return mass;
}

void aeroFrame::setMass(double  p_mass) {
    mass = p_mass;
}

aeroPort* aeroFrame::getP() const {
    return (aeroPort*) &p;
}

AtmoHeightPort* aeroFrame::getPh() const {
    return (AtmoHeightPort*) &ph;
}

OMBoolean aeroFrame::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\aeroFrame.cpp
*********************************************************************/

