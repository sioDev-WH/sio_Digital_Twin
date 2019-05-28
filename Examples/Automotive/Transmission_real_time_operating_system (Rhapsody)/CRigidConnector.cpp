/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: CRigidConnector
//!	Generated Date	: Thu, 9, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\CRigidConnector.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "CRigidConnector.h"
#include "stdafx.h"

//## package TransmissionModels 


//#[ ignore 
#define TransmissionModels_CRigidConnector_CRigidConnector_SERIALIZE OM_NO_OP


#define TransmissionModels_CRigidConnector_InitEqnForm_SERIALIZE OM_NO_OP


#define TransmissionModels_CRigidConnector_InitLocalADEqns_SERIALIZE OM_NO_OP


#define TransmissionModels_CRigidConnector_InitLocalEqns_SERIALIZE OM_NO_OP


#define TransmissionModels_CRigidConnector_InitLocalVars_SERIALIZE OM_NO_OP


#define TransmissionModels_CRigidConnector_Load_SERIALIZE OM_NO_OP


#define TransmissionModels_CRigidConnector_Save_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// CRigidConnector.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(TransmissionModels)
//## class CRigidConnector 



CRigidConnector::CRigidConnector() {
    NOTIFY_CONSTRUCTOR(CRigidConnector, CRigidConnector(), 0, TransmissionModels_CRigidConnector_CRigidConnector_SERIALIZE);
    //#[ operation CRigidConnector() 
    torque = 0.0;
    DER(torque) = 0.0;
    OLD(torque) = 0.0;
    DER_OLD(torque) = 0.0;
    DER_AD(torque) = 0.0;
    AD(torque) = 0.0;
    
    acceleration = 0.0;
    DER(acceleration) = 0.0;
    OLD(acceleration) = 0.0;
    DER_OLD(acceleration) = 0.0;
    DER_AD(acceleration) = 0.0;
    AD(acceleration) = 0.0;
    //#]
}

CRigidConnector::~CRigidConnector() {
    NOTIFY_DESTRUCTOR(~CRigidConnector, TRUE);
    //#[ operation ~CRigidConnector() 
    //#]
}

HRESULT CRigidConnector::GetADResidual(long  iEqn, double  t, Fdouble * residual) {
    //#[ operation GetADResidual(long,double,Fdouble * ) 
    long i;
    CRigidConnector* pEso;
    
    #if 0
    //ATLTRACE( _T("\nCRigidConnector::GetADResidual") );
    #endif
    
    if (iEqn == 0)
    { 
      (*residual) = AD(torque);
      for (i = 0; i < m_nEsos; i++)
      {
        pEso = dynamic_cast<CRigidConnector*> (m_Esos[i]);
        (*residual) += pEso->AD(torque);
      }
    }
    else
    {
      pEso = dynamic_cast<CRigidConnector*> (m_Esos[iEqn-1]);
      (*residual) = AD(acceleration) - pEso->AD(acceleration);
    }
    
    return S_OK;
    //#]
}

HRESULT CRigidConnector::GetResiduals(long * iEqns, long  nEqn, double  t, double * residuals) {
    //#[ operation GetResiduals(long * ,long,double,double * ) 
    long i, j, iEqn;
    CRigidConnector* pEso;
    
    for (i = 0; i < nEqn; i++)
    {
      iEqn = iEqns[i];
      if (iEqn == 0)
      { 
    
    #if 0
    if (_verbose_print)
    //ATLTRACE("\n CRigidConnector::GetResiduals[%d]:\t%e", iEqn, torque);
    #endif
    
        residuals[i] = torque;
        for (j = 0; j < m_nEsos; j++)
        {
          pEso = dynamic_cast<CRigidConnector*> (m_Esos[j]);
          residuals[i] += pEso->torque;
    
    #if 0
    if (_verbose_print)
          //ATLTRACE("\t%e", pEso->torque);
    #endif
    
        }
      }
      else
      {
        pEso = dynamic_cast<CRigidConnector*> (m_Esos[iEqn-1]);
        residuals[i] = acceleration - pEso->acceleration;
    
    #if 0
    if (_verbose_print)
        //ATLTRACE("\n CRigidConnector::GetResiduals[%d]:\t%e\t%e", iEqn, acceleration, pEso->acceleration);
    #endif
    
      }
    }
    
    return S_OK;
    //#]
}

HRESULT CRigidConnector::InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form) {
    NOTIFY_OPERATION(InitEqnForm, InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ), 0, TransmissionModels_CRigidConnector_InitEqnForm_SERIALIZE);
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

HRESULT CRigidConnector::InitLocalADEqns() {
    NOTIFY_OPERATION(InitLocalADEqns, InitLocalADEqns(), 0, TransmissionModels_CRigidConnector_InitLocalADEqns_SERIALIZE);
    //#[ operation InitLocalADEqns() 
    if (m_bMasterNode)
      m_nLocalADEqns = m_nEsos + 1;
    else
      m_nLocalADEqns = 0;
    
    return S_OK;
    //#]
}

HRESULT CRigidConnector::InitLocalEqns() {
    NOTIFY_OPERATION(InitLocalEqns, InitLocalEqns(), 0, TransmissionModels_CRigidConnector_InitLocalEqns_SERIALIZE);
    //#[ operation InitLocalEqns() 
    if (m_bMasterNode)
      m_nLocalEqns = m_nEsos + 1;
    else
      m_nLocalEqns = 0;
    
    return S_OK;
    //#]
}

HRESULT CRigidConnector::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    NOTIFY_OPERATION(InitLocalVars, InitLocalVars(const _TCHAR * ,VarCont * ,const bool ), 0, TransmissionModels_CRigidConnector_InitLocalVars_SERIALIZE);
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    ADD_LOCAL_SVAR(torque)
    ADD_LOCAL_SVAR(acceleration)
    
     for (long i = 0; i < m_nEsos; i++)
       AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
    return S_OK;
    //#]
}

bool CRigidConnector::Load(FILE * fs) {
    NOTIFY_OPERATION(Load, Load(FILE * ), 0, TransmissionModels_CRigidConnector_Load_SERIALIZE);
    //#[ operation Load(FILE * ) 
    return true;
    //#]
}

void CRigidConnector::Save(FILE * fs) {
    NOTIFY_OPERATION(Save, Save(FILE * ), 0, TransmissionModels_CRigidConnector_Save_SERIALIZE);
    //#[ operation Save(FILE * ) 
    //#]
}

VarEx CRigidConnector::get_acceleration() const {
    return _acceleration;
}

void CRigidConnector::set_acceleration(VarEx  p__acceleration) {
    _acceleration = p__acceleration;
}

VarEx CRigidConnector::get_torque() const {
    return _torque;
}

void CRigidConnector::set_torque(VarEx  p__torque) {
    _torque = p__torque;
}

double CRigidConnector::getAcceleration() const {
    return acceleration;
}

void CRigidConnector::setAcceleration(double  p_acceleration) {
    acceleration = p_acceleration;
}

double CRigidConnector::getTorque() const {
    return torque;
}

void CRigidConnector::setTorque(double  p_torque) {
    torque = p_torque;
}



#ifdef _OMINSTRUMENT


void OMAnimatedCRigidConnector::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

IMPLEMENT_META(CRigidConnector, TransmissionModels, FALSE, OMAnimatedCRigidConnector)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\CRigidConnector.cpp
*********************************************************************/

