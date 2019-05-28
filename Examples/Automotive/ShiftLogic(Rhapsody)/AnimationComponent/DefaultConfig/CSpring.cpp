/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: CSpring
//!	Generated Date	: Thu, 9, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\CSpring.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "CSpring.h"
#include "CRigidConnector.h"
#include "stdafx.h"
#include "math.h"

//## package StandardModels 


//#[ ignore 
#define StandardModels_CSpring_CSpring_SERIALIZE OM_NO_OP


#define StandardModels_CSpring_InitEqnForm_SERIALIZE OM_NO_OP


#define StandardModels_CSpring_InitEsos_SERIALIZE OM_NO_OP


#define StandardModels_CSpring_InitLocalADEqns_SERIALIZE OM_NO_OP


#define StandardModels_CSpring_InitLocalEqns_SERIALIZE OM_NO_OP


#define StandardModels_CSpring_InitLocalRPars_SERIALIZE OM_NO_OP


#define StandardModels_CSpring_InitLocalVars_SERIALIZE OM_NO_OP


#define StandardModels_CSpring_Load_SERIALIZE OM_NO_OP


#define StandardModels_CSpring_Save_SERIALIZE OM_NO_OP


#define StandardModels_CSpring_clean_SERIALIZE OM_NO_OP


#define StandardModels_CSpring_handle_Ks_SERIALIZE OM_NO_OP


#define StandardModels_CSpring_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// CSpring.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(StandardModels)
//## class CSpring 



CSpring::CSpring() {
    NOTIFY_CONSTRUCTOR(CSpring, CSpring(), 0, StandardModels_CSpring_CSpring_SERIALIZE);
    n = NULL;
    p = NULL;
    //#[ operation CSpring() 
    init();
    //#]
}

CSpring::~CSpring() {
    NOTIFY_DESTRUCTOR(~CSpring, TRUE);
    //#[ operation ~CSpring() 
    clean();
    //#]
    cleanUpRelations();
}

HRESULT CSpring::InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form) {
    NOTIFY_OPERATION(InitEqnForm, InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ), 0, StandardModels_CSpring_InitEqnForm_SERIALIZE);
    //#[ operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
    const long idx_eqn_res2 = 0;
    const long idx_eqn_res3 = 1;
    const long idx_eqn_res0 = 2;
    const long idx_eqn_res1 = 3;
    
      DESTROY_VECTOR(*form)
      *form = new OnEqnForm[m_nLocalEqns];
      (*form)[idx_eqn_res2] = continuous;
      (*form)[idx_eqn_res3] = continuous;
      (*form)[idx_eqn_res0] = continuous;
      (*form)[idx_eqn_res1] = continuous;
    
      DESTROY_VECTOR(*diff_form)
      *diff_form = new OnEqnDiffForm[m_nLocalEqns];
      (*diff_form)[idx_eqn_res2] = automatic;
      (*diff_form)[idx_eqn_res3] = automatic;
      (*diff_form)[idx_eqn_res0] = automatic;
      (*diff_form)[idx_eqn_res1] = automatic;
    
      return S_OK;
    
    //#]
}

HRESULT CSpring::InitEsos() {
    NOTIFY_OPERATION(InitEsos, InitEsos(), 0, StandardModels_CSpring_InitEsos_SERIALIZE);
    //#[ operation InitEsos() 
      ADD_LOCAL_ESO(p)
      ADD_LOCAL_ESO(n)
    
      return S_OK;
    
    //#]
}

HRESULT CSpring::InitLocalADEqns() {
    NOTIFY_OPERATION(InitLocalADEqns, InitLocalADEqns(), 0, StandardModels_CSpring_InitLocalADEqns_SERIALIZE);
    //#[ operation InitLocalADEqns() 
      ADD_LOCAL_AD_EQN(CSpring, ad_res2)
      ADD_LOCAL_AD_EQN(CSpring, ad_res3)
      ADD_LOCAL_AD_EQN(CSpring, ad_res0)
      ADD_LOCAL_AD_EQN(CSpring, ad_res1)
    
      return S_OK;
    
    //#]
}

HRESULT CSpring::InitLocalEqns() {
    NOTIFY_OPERATION(InitLocalEqns, InitLocalEqns(), 0, StandardModels_CSpring_InitLocalEqns_SERIALIZE);
    //#[ operation InitLocalEqns() 
      ADD_LOCAL_EQN(CSpring, res2)
      ADD_LOCAL_EQN(CSpring, res3)
      ADD_LOCAL_EQN(CSpring, res0)
      ADD_LOCAL_EQN(CSpring, res1)
    
      return S_OK;
    
    //#]
}

HRESULT CSpring::InitLocalRPars(const _TCHAR * prefix, ppdouble * pars, ppchar * Names, long * nPars, long * dPars) {
    NOTIFY_OPERATION(InitLocalRPars, InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ), 0, StandardModels_CSpring_InitLocalRPars_SERIALIZE);
    //#[ operation InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ) 
      ADD_LOCAL_SRPAR(Ks)
    
      return S_OK;
    
    //#]
}

HRESULT CSpring::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    NOTIFY_OPERATION(InitLocalVars, InitLocalVars(const _TCHAR * ,VarCont * ,const bool ), 0, StandardModels_CSpring_InitLocalVars_SERIALIZE);
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
      ADD_LOCAL_SVAR(ddTorque)
      ADD_LOCAL_SVAR(dTorque)
    
     for (long i = 0; i < m_nEsos; i++)
       AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
      return S_OK;
    
    //#]
}

bool CSpring::Load(FILE * fs) {
    NOTIFY_OPERATION(Load, Load(FILE * ), 0, StandardModels_CSpring_Load_SERIALIZE);
    //#[ operation Load(FILE * ) 
    return true;
    //#]
}

void CSpring::Save(FILE * fs) {
    NOTIFY_OPERATION(Save, Save(FILE * ), 0, StandardModels_CSpring_Save_SERIALIZE);
    //#[ operation Save(FILE * ) 
    //#]
}

HRESULT CSpring::ad_res0(Fdouble * res) {
    //#[ operation ad_res0(Fdouble * ) 
      *res = p->DER_AD(torque) - AD(dTorque);
      return S_OK;
    
    //#]
}

HRESULT CSpring::ad_res1(Fdouble * res) {
    //#[ operation ad_res1(Fdouble * ) 
      *res = DER_AD(dTorque) - AD(ddTorque);
      return S_OK;
    
    //#]
}

HRESULT CSpring::ad_res2(Fdouble * res) {
    //#[ operation ad_res2(Fdouble * ) 
      *res = AD(ddTorque) - Ks * (p->AD(acceleration) - n->AD(acceleration));
      return S_OK;
    
    //#]
}

HRESULT CSpring::ad_res3(Fdouble * res) {
    //#[ operation ad_res3(Fdouble * ) 
      *res = p->AD(torque) + n->AD(torque);
      return S_OK;
    
    //#]
}

void CSpring::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, StandardModels_CSpring_clean_SERIALIZE);
    //#[ operation clean() 
      p->Release();
      n->Release();
    
    //#]
}

void CSpring::handle_Ks(const double t, const double * val) {
    NOTIFY_OPERATION(handle_Ks, handle_Ks(const double ,const double * ), 0, StandardModels_CSpring_handle_Ks_SERIALIZE);
    //#[ operation handle_Ks(const double ,const double * ) 
    PostRealParameter(t, 0, *val);
    
    //#]
}

void CSpring::init() {
    NOTIFY_OPERATION(init, init(), 0, StandardModels_CSpring_init_SERIALIZE);
    //#[ operation init() 
      Ks = 160;
    
      dTorque = 0.0;
      DER(dTorque) = 0.0;
    
      ddTorque = 0.0;
      DER(ddTorque) = 0.0;
    
      p = new CRigidConnector();
      n = new CRigidConnector();
    
      p->AddRef();
      n->AddRef();
    
    //#]
}

HRESULT CSpring::res0(double * res) {
    //#[ operation res0(double * ) 
      *res = p->DER(torque) - dTorque;
      return S_OK;
    
    //#]
}

HRESULT CSpring::res1(double * res) {
    //#[ operation res1(double * ) 
      *res = DER(dTorque) - ddTorque;
      return S_OK;
    
    //#]
}

HRESULT CSpring::res2(double * res) {
    //#[ operation res2(double * ) 
      *res = ddTorque - Ks * (p->acceleration - n->acceleration);
      return S_OK;
    
    //#]
}

HRESULT CSpring::res3(double * res) {
    //#[ operation res3(double * ) 
      *res = p->torque + n->torque;
      return S_OK;
    
    //#]
}

double CSpring::getKs() const {
    return Ks;
}

void CSpring::setKs(double  p_Ks) {
    Ks = p_Ks;
}

VarEx CSpring::get_dTorque() const {
    return _dTorque;
}

void CSpring::set_dTorque(VarEx  p__dTorque) {
    _dTorque = p__dTorque;
}

VarEx CSpring::get_ddTorque() const {
    return _ddTorque;
}

void CSpring::set_ddTorque(VarEx  p__ddTorque) {
    _ddTorque = p__ddTorque;
}

double CSpring::getDTorque() const {
    return dTorque;
}

void CSpring::setDTorque(double  p_dTorque) {
    dTorque = p_dTorque;
}

double CSpring::getDdTorque() const {
    return ddTorque;
}

void CSpring::setDdTorque(double  p_ddTorque) {
    ddTorque = p_ddTorque;
}

CRigidConnector* CSpring::getN() const {
    return n;
}

void CSpring::setN(CRigidConnector*  p_CRigidConnector) {
    n = p_CRigidConnector;
    if(p_CRigidConnector != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("n", p_CRigidConnector, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("n");
        }
}

CRigidConnector* CSpring::getP() const {
    return p;
}

void CSpring::setP(CRigidConnector*  p_CRigidConnector) {
    p = p_CRigidConnector;
    if(p_CRigidConnector != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("p", p_CRigidConnector, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("p");
        }
}

void CSpring::cleanUpRelations() {
    if(n != NULL)
        {
            NOTIFY_RELATION_CLEARED("n");
            n = NULL;
        }
    if(p != NULL)
        {
            NOTIFY_RELATION_CLEARED("p");
            p = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedCSpring::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedCSpring::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("p", FALSE, TRUE);
    if(myReal->p)
        aomsRelations->ADD_ITEM(myReal->p);
    aomsRelations->addRelation("n", FALSE, TRUE);
    if(myReal->n)
        aomsRelations->ADD_ITEM(myReal->n);
}

IMPLEMENT_META(CSpring, StandardModels, FALSE, OMAnimatedCSpring)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\CSpring.cpp
*********************************************************************/

