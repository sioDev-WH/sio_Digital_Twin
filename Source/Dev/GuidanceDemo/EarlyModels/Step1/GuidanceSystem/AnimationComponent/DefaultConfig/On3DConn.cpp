/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: On3DConn
//!	Generated Date	: Tue, 10, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\On3DConn.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "stdafx.h"
#include "OnUMLEso.h"
#include "On3DConn.h"

//## package GuidancePkg 

//----------------------------------------------------------------------------
// On3DConn.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(GuidancePkg)
//## class On3DConn 



On3DConn::On3DConn() {
    //#[ operation On3DConn() 
    F = NULL;
    V = NULL;
    _F = NULL;
    _V = NULL;
    
    m_TypedEsos = NULL;
    
    init();
    //#]
}

On3DConn::~On3DConn() {
    //#[ operation ~On3DConn() 
    clean();
    //#]
}

HRESULT On3DConn::GetADResidual(long  iEqn, double  t, Fdouble * residual) {
    //#[ operation GetADResidual(long,double,Fdouble * ) 
    long iVar, iEso;
    
    // initialize m_TypedEsos if it hasn't already been initialized
    if (m_TypedEsos == NULL)
    {
      m_TypedEsos = new On3DConn*[m_nEsos];
      for (long i = 0; i < m_nEsos; i++)
      {
        m_TypedEsos[i] = dynamic_cast<On3DConn*> (m_Esos[i]);
        _ASSERTE(m_TypedEsos[i]);
      }
    }
    
    if (iEqn < 3) 
    {
      iVar = iEqn;
      *residual = _F[iVar]->ad;
      for (iEso = 0; iEso < m_nEsos; iEso++)
        *residual += m_TypedEsos[iEso]->_F[iVar]->ad;
    }
    else
    {
      iEso = (iEqn - 3) / 3;
      iVar = (iEqn - 3) % 3;
      // state machine implementation
      //*residual = _V[iVar]->der_ad - m_TypedEsos[iEso]->_V[iVar]->der_ad;
      *residual = _V[iVar]->ad - m_TypedEsos[iEso]->_V[iVar]->ad;
    }
    
    return S_OK;
    //#]
}

HRESULT On3DConn::GetResiduals(long * iEqns, long  nEqn, double  t, double * residuals) {
    //#[ operation GetResiduals(long * ,long,double,double * ) 
    long iRes, iEqn, iVar, iEso;
    
    // initialize m_TypedEsos if it hasn't already been initialized
    if (m_TypedEsos == NULL)
    {
      m_TypedEsos = new On3DConn*[m_nEsos];
      for (long i = 0; i < m_nEsos; i++)
      {
        m_TypedEsos[i] = dynamic_cast<On3DConn*> (m_Esos[i]);
        _ASSERTE(m_TypedEsos[i]);
      }
    }
    
    for (iRes = 0; iRes < nEqn; iRes++)
    {
      iEqn = iEqns[iRes];
    
      if (iEqn < 3) 
      {
        iVar = iEqn;
        residuals[iRes] = *(F[iVar]);
        for (iEso = 0; iEso < m_nEsos; iEso++)
          residuals[iRes] += *(m_TypedEsos[iEso]->F[iVar]);
      }
      else
      {
        iEqn -= 3;
        iEso = iEqn / 3;
        iVar = iEqn % 3;
        // state machine implementation
        //residuals[iRes] = _V[iVar]->der - m_TypedEsos[iEso]->_V[iVar]->der;
        residuals[iRes] = *(V[iVar]) - *(m_TypedEsos[iEso]->V[iVar]);
      }
    }
    
    return S_OK;
    //#]
}

HRESULT On3DConn::InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form) {
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

HRESULT On3DConn::InitLocalADEqns() {
    //#[ operation InitLocalADEqns() 
    if (m_bMasterNode)
      m_nLocalADEqns = m_nEsos * 3 + 3;
    else
      m_nLocalADEqns = 0;
    
    return S_OK;
    //#]
}

HRESULT On3DConn::InitLocalEqns() {
    //#[ operation InitLocalEqns() 
    if (m_bMasterNode)
      m_nLocalEqns = m_nEsos * 3 + 3;
    else
      m_nLocalEqns = 0;
    
    return S_OK;
    //#]
}

HRESULT On3DConn::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    ADD_LOCAL_SVAR(Fx)
    ADD_LOCAL_SVAR(Fz)
    ADD_LOCAL_SVAR(My)
    ADD_LOCAL_SVAR(q)
    ADD_LOCAL_SVAR(u)
    ADD_LOCAL_SVAR(w)
    
    for (long i = 0; i < m_nEsos; i++) 
      AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
    return S_OK;
    //#]
}

bool On3DConn::Load(FILE * fs) {
    //#[ operation Load(FILE * ) 
    return true;
    //#]
}

void On3DConn::Save(FILE * fs) {
    //#[ operation Save(FILE * ) 
    //#]
}

void On3DConn::clean() {
    //#[ operation clean() 
    DESTROY_VECTOR(F)
    DESTROY_VECTOR(V)
    DESTROY_VECTOR(_F)
    DESTROY_VECTOR(_V)
    DESTROY_VECTOR(m_TypedEsos)
    //#]
}

double On3DConn::get_Fx(const double time) {
    //#[ operation get_Fx(const double ) 
    if (m_pOnModel) m_pOnModel->GetVariable(idx_var_Fx, time, &tmpVal);
    return tmpVal;
    //#]
}

double On3DConn::get_Fz(const double time) {
    //#[ operation get_Fz(const double ) 
    if (m_pOnModel) m_pOnModel->GetVariable(idx_var_Fz, time, &tmpVal);
    return tmpVal;
    //#]
}

double On3DConn::get_My(const double time) {
    //#[ operation get_My(const double ) 
    if (m_pOnModel) m_pOnModel->GetVariable(idx_var_My, time, &tmpVal);
    return tmpVal;
    //#]
}

double On3DConn::get_der_Fx(const double time) {
    //#[ operation get_der_Fx(const double ) 
    if (m_pOnModel) m_pOnModel->GetDerivative(idx_var_Fx, time, &tmpVal);
    return tmpVal;
    //#]
}

double On3DConn::get_der_Fz(const double time) {
    //#[ operation get_der_Fz(const double ) 
    if (m_pOnModel) m_pOnModel->GetDerivative(idx_var_Fz, time, &tmpVal);
    return tmpVal;
    //#]
}

double On3DConn::get_der_My(const double time) {
    //#[ operation get_der_My(const double ) 
    if (m_pOnModel) m_pOnModel->GetDerivative(idx_var_My, time, &tmpVal);
    return tmpVal;
    //#]
}

double On3DConn::get_der_q(const double time) {
    //#[ operation get_der_q(const double ) 
    if (m_pOnModel) m_pOnModel->GetDerivative(idx_var_q, time, &tmpVal);
    return tmpVal;
    //#]
}

double On3DConn::get_der_u(const double time) {
    //#[ operation get_der_u(const double ) 
    if (m_pOnModel) m_pOnModel->GetDerivative(idx_var_u, time, &tmpVal);
    return tmpVal;
    //#]
}

double On3DConn::get_der_w(const double time) {
    //#[ operation get_der_w(const double ) 
    if (m_pOnModel) m_pOnModel->GetDerivative(idx_var_w, time, &tmpVal);
    return tmpVal;
    //#]
}

double On3DConn::get_q(const double time) {
    //#[ operation get_q(const double ) 
    if (m_pOnModel) m_pOnModel->GetVariable(idx_var_q, time, &tmpVal);
    return tmpVal;
    //#]
}

double On3DConn::get_u(const double time) {
    //#[ operation get_u(const double ) 
    if (m_pOnModel) m_pOnModel->GetVariable(idx_var_u, time, &tmpVal);
    return tmpVal;
    //#]
}

double On3DConn::get_w(const double time) {
    //#[ operation get_w(const double ) 
    if (m_pOnModel) m_pOnModel->GetVariable(idx_var_w, time, &tmpVal);
    return tmpVal;
    //#]
}

void On3DConn::init() {
    //#[ operation init() 
    // initialize all forces and velocities to zero
    Fx = 0.0;
    Fz = 0.0;
    My = 0.0;
    DER(Fx) = 0.0;
    DER(Fz) = 0.0;
    DER(My) = 0.0;
    
    q = 0.0;
    u = 0.0;
    w = 0.0;
    DER(q) = 0.0;
    DER(u) = 0.0;
    DER(w) = 0.0;
    
    F = new double*[3];
    V = new double*[3];
    _F = new VarEx*[3];
    _V = new VarEx*[3];
    
    F[0] = &Fx;
    F[1] = &Fz;
    F[2] = &My;
    
    V[0] = &q;
    V[1] = &u;
    V[2] = &w;
    
    _F[0] = &_Fx;
    _F[1] = &_Fz;
    _F[2] = &_My;
    
    _V[0] = &_q;
    _V[1] = &_u;
    _V[2] = &_w;
    
    idx_var_Fx = 0;
    idx_var_Fz = 1;
    idx_var_My = 2;
    idx_var_q = 3;
    idx_var_u = 4;
    idx_var_w = 5;
    //#]
}

void On3DConn::setF(double * * p_F) {
    F = p_F;
}

void On3DConn::setFx(double  p_Fx) {
    Fx = p_Fx;
}

void On3DConn::setFz(double  p_Fz) {
    Fz = p_Fz;
}

void On3DConn::setMy(double  p_My) {
    My = p_My;
}

void On3DConn::setV(double * * p_V) {
    V = p_V;
}

void On3DConn::set_F(VarEx * * p__F) {
    _F = p__F;
}

void On3DConn::set_Fx(VarEx p__Fx) {
    _Fx = p__Fx;
}

void On3DConn::set_Fz(VarEx p__Fz) {
    _Fz = p__Fz;
}

void On3DConn::set_My(VarEx p__My) {
    _My = p__My;
}

void On3DConn::set_V(VarEx * * p__V) {
    _V = p__V;
}

void On3DConn::set_q(VarEx p__q) {
    _q = p__q;
}

void On3DConn::set_u(VarEx p__u) {
    _u = p__u;
}

void On3DConn::set_w(VarEx p__w) {
    _w = p__w;
}

void On3DConn::setIdx_var_Fx(long  p_idx_var_Fx) {
    idx_var_Fx = p_idx_var_Fx;
}

void On3DConn::setIdx_var_Fz(long  p_idx_var_Fz) {
    idx_var_Fz = p_idx_var_Fz;
}

void On3DConn::setIdx_var_My(long  p_idx_var_My) {
    idx_var_My = p_idx_var_My;
}

void On3DConn::setIdx_var_q(long  p_idx_var_q) {
    idx_var_q = p_idx_var_q;
}

void On3DConn::setIdx_var_u(long  p_idx_var_u) {
    idx_var_u = p_idx_var_u;
}

void On3DConn::setIdx_var_w(long  p_idx_var_w) {
    idx_var_w = p_idx_var_w;
}

void On3DConn::setM_TypedEsos(On3DConn * * p_m_TypedEsos) {
    m_TypedEsos = p_m_TypedEsos;
}

void On3DConn::setQ(double  p_q) {
    q = p_q;
}

void On3DConn::setTmpVal(double  p_tmpVal) {
    tmpVal = p_tmpVal;
}

void On3DConn::setU(double  p_u) {
    u = p_u;
}

void On3DConn::setW(double  p_w) {
    w = p_w;
}



#ifdef _OMINSTRUMENT


void OMAnimatedOn3DConn::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedOn3DConn::serializeRelations(AOMSRelations*  aomsRelations) const {
}

IMPLEMENT_META(On3DConn, GuidancePkg, FALSE, OMAnimatedOn3DConn)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\On3DConn.cpp
*********************************************************************/

