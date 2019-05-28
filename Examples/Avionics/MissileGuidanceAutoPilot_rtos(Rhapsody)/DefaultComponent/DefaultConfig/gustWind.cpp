/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: gustWind
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\gustWind.cpp
*********************************************************************/

#include <oxf/omthread.h>
#include "gustWind.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// gustWind.cpp                                                                  
//----------------------------------------------------------------------------
//## class gustWind 



gustWind::gustWind(OMThread*  p_thread) {
    setThread(p_thread, FALSE);
    //#[ operation gustWind() 
    init();
    //#]
}

gustWind::~gustWind() {
    //#[ operation ~gustWind() 
    clean();
    //#]
}

HRESULT gustWind::InitEqnForm(OnEqnForm**  form, OnEqnDiffForm**  diff_form) {
    //#[ operation InitEqnForm(OnEqnForm**,OnEqnDiffForm**) 
    
    
    const long idx_eqn_r_thrust = 0;
    
      DESTROY_VECTOR(*form)
      *form = new OnEqnForm[m_nLocalEqns];
      (*form)[idx_eqn_r_thrust] = continuous;
    
      DESTROY_VECTOR(*diff_form)
      *diff_form = new OnEqnDiffForm[m_nLocalEqns];
      (*diff_form)[idx_eqn_r_thrust] = automatic;
    
      return S_OK;
    //#]
}

HRESULT gustWind::InitEsos() {
    //#[ operation InitEsos() 
    
      ADD_LOCAL_ESO(p)
    
      return S_OK;
    //#]
}

HRESULT gustWind::InitLocalADEqns() {
    //#[ operation InitLocalADEqns() 
    
      ADD_LOCAL_AD_EQN(gustWind, ad_r_thrust)
    
      return S_OK;
    //#]
}

HRESULT gustWind::InitLocalEqns() {
    //#[ operation InitLocalEqns() 
    
      ADD_LOCAL_EQN(gustWind, r_thrust)
    
      return S_OK;
    //#]
}

HRESULT gustWind::InitLocalVars(const _TCHAR*  prefix, VarCont*  varC, const bool  bADOnly) {
    //#[ operation InitLocalVars(const _TCHAR*,VarCont*,const bool) 
    
    
    
    for (long i = 0; i < m_nEsos; i++)
      AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
      return S_OK;
    //#]
}

bool gustWind::Load(FILE*  fs) {
    //#[ operation Load(FILE*) 
    
    return true;
    //#]
}

void gustWind::Save(FILE*  fs) {
    //#[ operation Save(FILE*) 
    //#]
}

HRESULT gustWind::ad_r_thrust(Fdouble*  res) {
    //#[ operation ad_r_thrust(Fdouble*) 
    Force& force = p.force;
    
    if (res->size() != 3) res->resize(3);
    
    
    // TODO: not sure what to use for gust model
    (*res)[0] = force[0];
    (*res)[1] = force[1] - 0.0;
    (*res)[2] = force[2] - 0.0;
    
    return S_OK;
    //#]
}

void gustWind::clean() {
    //#[ operation clean() 
    //#]
}

void gustWind::init() {
    //#[ operation init() 
    //#]
}

HRESULT gustWind::r_thrust(valarray<double>*  res) {
    //#[ operation r_thrust(valarray<double>*) 
    Force& force = p.force;
    
    if (res->size() != 3) res->resize(3);
    
    
    // TODO: not sure what to use for gust model
    (*res)[0] = force[0];
    (*res)[1] = force[1] - 0.0;
    (*res)[2] = force[2] - 0.0;
    
    return S_OK;
    //#]
}

aeroPort* gustWind::getP() const {
    return (aeroPort*) &p;
}

OMBoolean gustWind::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\gustWind.cpp
*********************************************************************/

