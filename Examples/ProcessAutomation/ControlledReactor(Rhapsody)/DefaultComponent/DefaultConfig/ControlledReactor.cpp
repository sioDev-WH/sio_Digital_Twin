/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ControlledReactor
//!	Generated Date	: Sun, 15, Sep 2002  
	File Path	: DefaultComponent\DefaultConfig\ControlledReactor.cpp
*********************************************************************/

#include "stdafx.h"
#include "ControlledReactor.h"
#include "Controller.h"
#include "OnAD.h"
#include "Heater.h"
#include "Reactor.h"

//## package ProcessModels 

//----------------------------------------------------------------------------
// ControlledReactor.cpp                                                                  
//----------------------------------------------------------------------------
//## class ControlledReactor 



ControlledReactor::ControlledReactor() {
    itsController = NULL;
    itsHeater = NULL;
    itsReactor = NULL;
    init();
}

ControlledReactor::~ControlledReactor() {
    cleanUpRelations();
    clean();
}


HRESULT ControlledReactor::InitEqnForm(OnEqnForm**  form, OnEqnDiffForm**  diff_form) {
    //#[ operation InitEqnForm(OnEqnForm**,OnEqnDiffForm**) 
    
    
    const long idx_eqn_r_RecycleTempBalance = 0;
    const long idx_eqn_r_HeaterTempBalance = 1;
    const long idx_eqn_r_FlowBalance = 2;
    const long idx_eqn_r_ControllerTempBalance = 3;
    
      DESTROY_VECTOR(*form)
      *form = new OnEqnForm[m_nLocalEqns];
      (*form)[idx_eqn_r_RecycleTempBalance] = continuous;
      (*form)[idx_eqn_r_HeaterTempBalance] = continuous;
      (*form)[idx_eqn_r_FlowBalance] = continuous;
    
      DESTROY_VECTOR(*diff_form)
      *diff_form = new OnEqnDiffForm[m_nLocalEqns];
      (*diff_form)[idx_eqn_r_RecycleTempBalance] = automatic;
      (*diff_form)[idx_eqn_r_HeaterTempBalance] = automatic;
      (*diff_form)[idx_eqn_r_FlowBalance] = automatic;
    
      return S_OK;
    //#]
}

HRESULT ControlledReactor::InitEsos() {
    //#[ operation InitEsos() 
    
      ADD_LOCAL_ESO(itsReactor)
      ADD_LOCAL_ESO(itsHeater)
    
      return S_OK;
    //#]
}

HRESULT ControlledReactor::InitLocalADEqns() {
    //#[ operation InitLocalADEqns() 
    
      ADD_LOCAL_AD_EQN(ControlledReactor, ad_r_RecycleTempBalance)
      ADD_LOCAL_AD_EQN(ControlledReactor, ad_r_HeaterTempBalance)
      ADD_LOCAL_AD_EQN(ControlledReactor, ad_r_FlowBalance)
    
      return S_OK;
    //#]
}

HRESULT ControlledReactor::InitLocalEqns() {
    //#[ operation InitLocalEqns() 
    
      ADD_LOCAL_EQN(ControlledReactor, r_RecycleTempBalance)
      ADD_LOCAL_EQN(ControlledReactor, r_HeaterTempBalance)
      ADD_LOCAL_EQN(ControlledReactor, r_FlowBalance)
    
      return S_OK;
    //#]
}

HRESULT ControlledReactor::InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly) {
    //#[ operation InitLocalVars(_TCHAR*,ppdouble*,ppdouble*,ppdouble*,ppdouble*,ppfdouble*,ppfdouble*,ppchar*,long*,long*,long*,long*,bool) 
    
    for (long i = 0; i < m_nEsos; i++)
      AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
      return S_OK;
    //#]
}

bool ControlledReactor::Load(FILE*  fs) {
    //#[ operation Load(FILE*) 
  getItsController()->Load(fs);
  getItsHeater()->Load(fs);
  getItsReactor()->Load(fs);
    return true;
    //#]
}

void ControlledReactor::Save(FILE*  fs) {
    //#[ operation Save(FILE*) 
  getItsController()->Save(fs);
  getItsHeater()->Save(fs);
  getItsReactor()->Save(fs);
    //#]
}

HRESULT ControlledReactor::ad_r_FlowBalance(Fdouble*  res) {
    //#[ operation ad_r_FlowBalance(Fdouble*) 
    *res = itsReactor->Q_heptane_in - itsHeater->ad_Q_in;
    return S_OK;
    //#]
}

HRESULT ControlledReactor::ad_r_HeaterTempBalance(Fdouble*  res) {
    //#[ operation ad_r_HeaterTempBalance(Fdouble*) 
    *res = itsReactor->ad_T_reactor - itsHeater->ad_T_in;
    return S_OK; 
    //#]
}

HRESULT ControlledReactor::ad_r_RecycleTempBalance(Fdouble*  res) {
    //#[ operation ad_r_RecycleTempBalance(Fdouble*) 
    *res = itsReactor->ad_T_recycle_in - itsHeater->ad_T_heater;
    return S_OK;
    //#]
}

void ControlledReactor::clean() {
    //#[ operation clean() 
    if (itsReactor)
    {
      itsReactor->Release();
      itsReactor = NULL;
    }
    
    if (itsHeater)
    {
      itsHeater->Release();
      itsHeater = NULL;
    }
    
    if (itsController)
    {
      delete itsController;
      itsController = NULL;
    }
    
    //#]
}

void ControlledReactor::init() {
    //#[ operation init() 
    if (!itsController)
    {
      itsController = new Controller();
    }

    if (!itsHeater)
    {
      itsHeater = new Heater();
      itsHeater->AddRef();
    }

    if (!itsReactor)
    {
      itsReactor = new Reactor();
      itsReactor->AddRef();
    }
    
    itsController->itsHeater = itsHeater;
    itsController->itsReactor = itsReactor;

    //#]
}

HRESULT ControlledReactor::r_ControllerTempBalance(double*  res) {
    //#[ operation r_ControllerTempBalance(double*) 
    *res = itsReactor->T_reactor - itsController->T_data_in;
    return S_OK;
    //#]
}

HRESULT ControlledReactor::r_FlowBalance(double*  res) {
    //#[ operation r_FlowBalance(double) 
    *res = itsReactor->Q_heptane_in - itsHeater->Q_in;
    return S_OK;
    //#]
}

HRESULT ControlledReactor::r_HeaterTempBalance(double*  res) {
    //#[ operation r_HeaterTempBalance(double*) 
    *res = itsReactor->T_reactor - itsHeater->T_in;
    return S_OK; 
    //#]
}

HRESULT ControlledReactor::r_RecycleTempBalance(double*  res) {
    //#[ operation r_RecycleTempBalance(double*) 
    *res = itsReactor->T_recycle_in - itsHeater->T_heater;
    return S_OK;
    //#]
}

Controller* ControlledReactor::getItsController() const {
    return itsController;
}

void ControlledReactor::setItsController(Controller*  p_Controller) {
    itsController = p_Controller;
}

Heater* ControlledReactor::getItsHeater() const {
    return itsHeater;
}

void ControlledReactor::setItsHeater(Heater*  p_Heater) {
    itsHeater = p_Heater;
}

Reactor* ControlledReactor::getItsReactor() const {
    return itsReactor;
}

void ControlledReactor::setItsReactor(Reactor*  p_Reactor) {
    itsReactor = p_Reactor;
}

void ControlledReactor::cleanUpRelations() {
    if(itsController != NULL)
        {
            itsController = NULL;
        }
    if(itsHeater != NULL)
        {
            itsHeater = NULL;
        }
    if(itsReactor != NULL)
        {
            itsReactor = NULL;
        }
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\ControlledReactor.cpp
*********************************************************************/

