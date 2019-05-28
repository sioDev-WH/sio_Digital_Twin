/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: engineDynamics
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\engineDynamics.cpp
*********************************************************************/

#include <oxf/omthread.h>
#include "engineDynamics.h"
#include "OnUMLEso.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// engineDynamics.cpp                                                                  
//----------------------------------------------------------------------------
//## class engineDynamics 



engineDynamics::engineDynamics(OMThread*  p_thread) {
    setThread(p_thread, FALSE);
    //#[ operation engineDynamics() 
    init();
    //#]
}

engineDynamics::~engineDynamics() {
    //#[ operation ~engineDynamics() 
    clean();
    //#]
}

HRESULT engineDynamics::InitEqnForm(OnEqnForm**  form, OnEqnDiffForm**  diff_form) {
    //#[ operation InitEqnForm(OnEqnForm**,OnEqnDiffForm**) 
    
    
    const long idx_eqn_r_Force = 0;
    const long idx_eqn_r_Moments = 1;
    
      DESTROY_VECTOR(*form)
      *form = new OnEqnForm[m_nLocalEqns];
      (*form)[idx_eqn_r_Force] = continuous;
      (*form)[idx_eqn_r_Moments] = continuous;
    
      DESTROY_VECTOR(*diff_form)
      *diff_form = new OnEqnDiffForm[m_nLocalEqns];
      (*diff_form)[idx_eqn_r_Force] = automatic;
      (*diff_form)[idx_eqn_r_Moments] = automatic;
    
      return S_OK;
    //#]
}

HRESULT engineDynamics::InitEsos() {
    //#[ operation InitEsos() 
    
      ADD_LOCAL_ESO(&p)
    
      return S_OK;
    //#]
}

HRESULT engineDynamics::InitLocalADEqns() {
    //#[ operation InitLocalADEqns() 
    
      ADD_LOCAL_STL_AD_EQN(engineDynamics, ad_r_Force, 1)
      ADD_LOCAL_STL_AD_EQN(engineDynamics, ad_r_Moments, 1)
    
      return S_OK;
    //#]
}

HRESULT engineDynamics::InitLocalEqns() {
    //#[ operation InitLocalEqns() 
    
      ADD_LOCAL_STL_EQN(engineDynamics, r_Force, 1)
      ADD_LOCAL_STL_EQN(engineDynamics, r_Moments, 1)
    
      return S_OK;
    //#]
}

HRESULT engineDynamics::InitLocalVars(const _TCHAR*  prefix, VarCont*  varC, const bool  bADOnly) {
    //#[ operation InitLocalVars(const _TCHAR*,VarCont*,const bool) 
    
    
    
    for (long i = 0; i < m_nEsos; i++)
      AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
      return S_OK;
    //#]
}

bool engineDynamics::Load(FILE*  fs) {
    //#[ operation Load(FILE*) 
    
    return true;
    //#]
}

void engineDynamics::Save(FILE*  fs) {
    //#[ operation Save(FILE*) 
    //#]
}

HRESULT engineDynamics::ad_r_Force(valarray<Fdouble>*  res) {
    //#[ operation ad_r_Force(valarray<Fdouble>*) 
    
    valarray<Fdouble>& force = p.AD(force);
    
    if (res->size() != 3) res->resize(3);
    
    
    (*res)[0] = force[0] - 10000.0;
    (*res)[1] = force[1];
    (*res)[2] = force[2];
    
    return S_OK;
    
    //#]
}

HRESULT engineDynamics::ad_r_Moments(valarray<Fdouble>*  res) {
    //#[ operation ad_r_Moments(valarray<Fdouble>*) 
    
    valarray<Fdouble>& moment = p.AD(moment);
    
    if (res->size() != 3) res->resize(3);
    
    (*res) = moment;
    
    return S_OK;
    
    //#]
}

void engineDynamics::clean() {
    //#[ operation clean() 
    //#]
}

void engineDynamics::init() {
    //#[ operation init() 
    p.velocity[0] = 984.0; // u
    //#]
}

HRESULT engineDynamics::r_Force(valarray<double>*  res) {
    //#[ operation r_Force(valarray<double>*) 
    Force& force = p.force;
    
    if (res->size() != 3) res->resize(3);
    
    
    (*res)[0] = force[0] - 10000.0;
    (*res)[1] = force[1];
    (*res)[2] = force[2];
    
    return S_OK;
    //#]
}

HRESULT engineDynamics::r_Moments(valarray<double>*  res) {
    //#[ operation r_Moments(valarray<double>*) 
    Moment& moment = p.moment;
    
    if (res->size() != 3) res->resize(3);
    
    (*res) = moment;
    
    return S_OK;
    //#]
}

aeroPort* engineDynamics::getP() const {
    return (aeroPort*) &p;
}

OMBoolean engineDynamics::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\engineDynamics.cpp
*********************************************************************/

