/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: CMass
//!	Generated Date	: Thu, 9, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\CMass.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "CMass.h"
#include "CRigidConnector.h"
#include "stdafx.h"
#include "math.h"

//## package StandardModels 


//#[ ignore 
#define StandardModels_CMass_CMass_SERIALIZE OM_NO_OP


#define StandardModels_CMass_InitEqnForm_SERIALIZE OM_NO_OP


#define StandardModels_CMass_InitEsos_SERIALIZE OM_NO_OP


#define StandardModels_CMass_InitLocalADEqns_SERIALIZE OM_NO_OP


#define StandardModels_CMass_InitLocalEqns_SERIALIZE OM_NO_OP


#define StandardModels_CMass_InitLocalRPars_SERIALIZE OM_NO_OP


#define StandardModels_CMass_InitLocalVars_SERIALIZE OM_NO_OP


#define StandardModels_CMass_Load_SERIALIZE OM_NO_OP


#define StandardModels_CMass_Save_SERIALIZE OM_NO_OP


#define StandardModels_CMass_clean_SERIALIZE OM_NO_OP


#define StandardModels_CMass_handle_J_SERIALIZE OM_NO_OP


#define StandardModels_CMass_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// CMass.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(StandardModels)
//## class CMass 



CMass::CMass() {
    NOTIFY_CONSTRUCTOR(CMass, CMass(), 0, StandardModels_CMass_CMass_SERIALIZE);
    n = NULL;
    p = NULL;
    //#[ operation CMass() 
    init();
    //#]
}

CMass::~CMass() {
    NOTIFY_DESTRUCTOR(~CMass, TRUE);
    //#[ operation ~CMass() 
    clean();
    //#]
    cleanUpRelations();
}

HRESULT CMass::InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form) {
    NOTIFY_OPERATION(InitEqnForm, InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ), 0, StandardModels_CMass_InitEqnForm_SERIALIZE);
    //#[ operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
    
    const long idx_eqn_res0 = 0;
    const long idx_eqn_res1 = 1;
    const long idx_eqn_res2 = 2;
    
      DESTROY_VECTOR(*form)
      *form = new OnEqnForm[m_nLocalEqns];
      (*form)[idx_eqn_res0] = continuous;
      (*form)[idx_eqn_res1] = continuous;
      (*form)[idx_eqn_res2] = continuous;
    
      DESTROY_VECTOR(*diff_form)
      *diff_form = new OnEqnDiffForm[m_nLocalEqns];
      (*diff_form)[idx_eqn_res0] = numeric;
      (*diff_form)[idx_eqn_res1] = numeric;
      (*diff_form)[idx_eqn_res2] = numeric;
    
      return S_OK;
    
    //#]
}

HRESULT CMass::InitEsos() {
    NOTIFY_OPERATION(InitEsos, InitEsos(), 0, StandardModels_CMass_InitEsos_SERIALIZE);
    //#[ operation InitEsos() 
      ADD_LOCAL_ESO(p)
      ADD_LOCAL_ESO(n)
    
      return S_OK;
    
    //#]
}

HRESULT CMass::InitLocalADEqns() {
    NOTIFY_OPERATION(InitLocalADEqns, InitLocalADEqns(), 0, StandardModels_CMass_InitLocalADEqns_SERIALIZE);
    //#[ operation InitLocalADEqns() 
      ADD_LOCAL_AD_EQN(CMass, ad_res0)
      ADD_LOCAL_AD_EQN(CMass, ad_res1)
      ADD_LOCAL_AD_EQN(CMass, ad_res2)
    
      return S_OK;
    
    //#]
}

HRESULT CMass::InitLocalEqns() {
    NOTIFY_OPERATION(InitLocalEqns, InitLocalEqns(), 0, StandardModels_CMass_InitLocalEqns_SERIALIZE);
    //#[ operation InitLocalEqns() 
      ADD_LOCAL_EQN(CMass, res0)
      ADD_LOCAL_EQN(CMass, res1)
      ADD_LOCAL_EQN(CMass, res2)
    
      return S_OK;
    
    //#]
}

HRESULT CMass::InitLocalRPars(const _TCHAR * prefix, ppdouble * pars, ppchar * Names, long * nPars, long * dPars) {
    NOTIFY_OPERATION(InitLocalRPars, InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ), 0, StandardModels_CMass_InitLocalRPars_SERIALIZE);
    //#[ operation InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ) 
      ADD_LOCAL_SRPAR(J)
    
      return S_OK;
    
    //#]
}

HRESULT CMass::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    NOTIFY_OPERATION(InitLocalVars, InitLocalVars(const _TCHAR * ,VarCont * ,const bool ), 0, StandardModels_CMass_InitLocalVars_SERIALIZE);
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
      ADD_LOCAL_SVAR(velocity)
    
     for (long i = 0; i < m_nEsos; i++)
       AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
      return S_OK;
    
    //#]
}

bool CMass::Load(FILE * fs) {
    NOTIFY_OPERATION(Load, Load(FILE * ), 0, StandardModels_CMass_Load_SERIALIZE);
    //#[ operation Load(FILE * ) 
    return true;
    //#]
}

void CMass::Save(FILE * fs) {
    NOTIFY_OPERATION(Save, Save(FILE * ), 0, StandardModels_CMass_Save_SERIALIZE);
    //#[ operation Save(FILE * ) 
    //#]
}

HRESULT CMass::ad_res0(Fdouble * res) {
    //#[ operation ad_res0(Fdouble * ) 
      *res = p->AD(torque) + n->AD(torque) - J * p->AD(acceleration);
    
      return S_OK;
    
    //#]
}

HRESULT CMass::ad_res1(Fdouble * res) {
    //#[ operation ad_res1(Fdouble * ) 
      *res = DER_AD(velocity) - p->AD(acceleration);
    
      return S_OK;
    
    //#]
}

HRESULT CMass::ad_res2(Fdouble * res) {
    //#[ operation ad_res2(Fdouble * ) 
      *res = p->AD(acceleration) - n->AD(acceleration);
      return S_OK;
    
    //#]
}

void CMass::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, StandardModels_CMass_clean_SERIALIZE);
    //#[ operation clean() 
    if (p)
    {
      p->Release();
      p = NULL;
    }
    
    if (n)
    {  
      n->Release();
      n = NULL;
    }
    //#]
}

void CMass::handle_J(const double t, const double * val) {
    NOTIFY_OPERATION(handle_J, handle_J(const double ,const double * ), 0, StandardModels_CMass_handle_J_SERIALIZE);
    //#[ operation handle_J(const double ,const double * ) 
    
    PostRealParameter(t, 0, *val);
    
    //#]
}

void CMass::init() {
    NOTIFY_OPERATION(init, init(), 0, StandardModels_CMass_init_SERIALIZE);
    //#[ operation init() 
      J = 100.0;
    
     velocity = 0.0;
     DER(velocity) = 0.0;
    
      p = new CRigidConnector();
      n = new CRigidConnector();
    
      p->AddRef();
      n->AddRef();
    
    //#]
}

HRESULT CMass::res0(double * res) {
    //#[ operation res0(double * ) 
      *res = p->torque + n->torque - J * p->acceleration;
    
      return S_OK;
    
    //#]
}

HRESULT CMass::res1(double * res) {
    //#[ operation res1(double * ) 
      *res = DER(velocity) - p->acceleration;
    
      return S_OK;
    
    //#]
}

HRESULT CMass::res2(double * res) {
    //#[ operation res2(double * ) 
      *res = p->acceleration - n->acceleration;
      return S_OK;
    
    //#]
}

double CMass::getJ() const {
    return J;
}

void CMass::setJ(double  p_J) {
    J = p_J;
}

VarEx CMass::get_velocity() const {
    return _velocity;
}

void CMass::set_velocity(VarEx  p__velocity) {
    _velocity = p__velocity;
}

double CMass::getVelocity() const {
    return velocity;
}

void CMass::setVelocity(double  p_velocity) {
    velocity = p_velocity;
}

CRigidConnector* CMass::getN() const {
    return n;
}

void CMass::setN(CRigidConnector*  p_CRigidConnector) {
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

CRigidConnector* CMass::getP() const {
    return p;
}

void CMass::setP(CRigidConnector*  p_CRigidConnector) {
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

void CMass::cleanUpRelations() {
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


void OMAnimatedCMass::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedCMass::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("p", FALSE, TRUE);
    if(myReal->p)
        aomsRelations->ADD_ITEM(myReal->p);
    aomsRelations->addRelation("n", FALSE, TRUE);
    if(myReal->n)
        aomsRelations->ADD_ITEM(myReal->n);
}

IMPLEMENT_META(CMass, StandardModels, FALSE, OMAnimatedCMass)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\CMass.cpp
*********************************************************************/

