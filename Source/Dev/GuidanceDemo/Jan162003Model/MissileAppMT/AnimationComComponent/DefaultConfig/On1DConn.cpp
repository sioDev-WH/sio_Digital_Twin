/********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: On1DConn
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\On1DConn.cpp
*********************************************************************/

#include "On1DConn.h"
#include "stdafx.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// On1DConn.cpp                                                                  
//----------------------------------------------------------------------------
//## class On1DConn 



On1DConn::On1DConn() {
    //#[ operation On1DConn() 
    m_TypedEsos = NULL;
    init();
    //#]
}

On1DConn::~On1DConn() {
    //#[ operation ~On1DConn() 
    clean();
    //#]
}

HRESULT On1DConn::GetADResidual(long  iEqn, double  t, Fdouble * residual) {
    //#[ operation GetADResidual(long,double,Fdouble * ) 
    // initialize m_TypedEsos if it hasn't already been initialized
    if (m_TypedEsos == NULL)
    {
      m_TypedEsos = new On1DConn*[m_nEsos];
      for (long i = 0; i < m_nEsos; i++)
      {
        m_TypedEsos[i] = dynamic_cast<On1DConn*> (m_Esos[i]);
        _ASSERTE(m_TypedEsos[i]);
      }
    }
    
    if (m_nEsos == 0)
      *residual = AD(pos);
    else
    {
      *residual = AD(pos) - m_TypedEsos[iEqn]->AD(pos);
    }
    
    return S_OK;
    //#]
}

HRESULT On1DConn::GetResiduals(long * iEqns, long  nEqn, double  t, double * residuals) {
    //#[ operation GetResiduals(long * ,long,double,double * ) 
    long iRes, iEqn;
    
    // initialize m_TypedEsos if it hasn't already been initialized
    if (m_TypedEsos == NULL)
    {
      m_TypedEsos = new On1DConn*[m_nEsos];
      for (long i = 0; i < m_nEsos; i++)
      {
        m_TypedEsos[i] = dynamic_cast<On1DConn*> (m_Esos[i]);
        _ASSERTE(m_TypedEsos[i]);
      }
    }
    
    if (m_nEsos == 0 && nEqn == 1)
    {
      residuals[0] = pos;
    }
    else
    {
      for (iRes = 0; iRes < nEqn; iRes++)
      {
        iEqn = iEqns[iRes];
        residuals[iRes] = pos - m_TypedEsos[iEqn]->pos;
      }
    }
    
    return S_OK;
    //#]
}

HRESULT On1DConn::InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form) {
    //#[ operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
    long i;
    DESTROY_VECTOR(*form)
    *form = new OnEqnForm[m_nLocalEqns];
    
    for (i = 0; i < m_nLocalEqns; i++) (*form)[i] = continuous;
    
    DESTROY_VECTOR(*diff_form)
    *diff_form = new OnEqnDiffForm[m_nLocalEqns];
    
    for (i = 0; i < m_nLocalEqns; i++) (*diff_form)[i] = automatic;
    
    return S_OK;
    //#]
}

HRESULT On1DConn::InitLocalADEqns() {
    //#[ operation InitLocalADEqns() 
    if (m_bMasterNode)
    {
      if (m_nEsos == 0)
        m_nLocalADEqns = 1;
      else
        m_nLocalADEqns = m_nEsos;
    }
    else
    {
      m_nLocalADEqns = 0;
    }
    
    return S_OK;
    //#]
}

HRESULT On1DConn::InitLocalEqns() {
    //#[ operation InitLocalEqns() 
    if (m_bMasterNode)
    {
      if (m_nEsos == 0)
        m_nLocalEqns = 1;
      else
        m_nLocalEqns = m_nEsos;
    }
    else
    {
      m_nLocalEqns = 0;
    }
    
    return S_OK;
    //#]
}

HRESULT On1DConn::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    ADD_LOCAL_SVAR(pos)
    
    for (long i = 0; i < m_nEsos; i++) 
      AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
    return S_OK;
    //#]
}

bool On1DConn::Load(FILE * fs) {
    //#[ operation Load(FILE * ) 
    return true;
    //#]
}

void On1DConn::Save(FILE * fs) {
    //#[ operation Save(FILE * ) 
    //#]
}

void On1DConn::clean() {
    //#[ operation clean() 
    DESTROY_VECTOR(m_TypedEsos)
    //#]
}

void On1DConn::init() {
    //#[ operation init() 
    // initialize all forces and velocities to zero
    pos = 0.0;
    DER(pos) = 0.0;
    //#]
}

VarEx  On1DConn::get_pos() const {
    return _pos;
}

void On1DConn::set_pos(VarEx p__pos) {
    _pos = p__pos;
}

On1DConn * *  On1DConn::getM_TypedEsos() const {
    return m_TypedEsos;
}

void On1DConn::setM_TypedEsos(On1DConn * * p_m_TypedEsos) {
    m_TypedEsos = p_m_TypedEsos;
}

double On1DConn::getPos() const {
    return pos;
}

void On1DConn::setPos(double  p_pos) {
    pos = p_pos;
}



/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\On1DConn.cpp
*********************************************************************/

