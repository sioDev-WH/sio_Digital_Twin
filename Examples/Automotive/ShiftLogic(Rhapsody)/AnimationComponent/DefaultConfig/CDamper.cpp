/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: CDamper
//!	Generated Date	: Thu, 9, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\CDamper.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "CDamper.h"
#include "CRigidConnector.h"
#include "stdafx.h"
#include "math.h"

//## package StandardModels 


//#[ ignore 
#define StandardModels_CDamper_CDamper_SERIALIZE OM_NO_OP


#define StandardModels_CDamper_InitEqnForm_SERIALIZE OM_NO_OP


#define StandardModels_CDamper_InitEsos_SERIALIZE OM_NO_OP


#define StandardModels_CDamper_InitLocalADEqns_SERIALIZE OM_NO_OP


#define StandardModels_CDamper_InitLocalEqns_SERIALIZE OM_NO_OP


#define StandardModels_CDamper_InitLocalRPars_SERIALIZE OM_NO_OP


#define StandardModels_CDamper_InitLocalVars_SERIALIZE OM_NO_OP


#define StandardModels_CDamper_Load_SERIALIZE OM_NO_OP


#define StandardModels_CDamper_Save_SERIALIZE OM_NO_OP


#define StandardModels_CDamper_clean_SERIALIZE OM_NO_OP


#define StandardModels_CDamper_handle_Kd_SERIALIZE OM_NO_OP


#define StandardModels_CDamper_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// CDamper.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(StandardModels)
//## class CDamper 



CDamper::CDamper() {
    NOTIFY_CONSTRUCTOR(CDamper, CDamper(), 0, StandardModels_CDamper_CDamper_SERIALIZE);
    n = NULL;
    p = NULL;
    //#[ operation CDamper() 
    init();
    //#]
}

CDamper::~CDamper() {
    NOTIFY_DESTRUCTOR(~CDamper, TRUE);
    //#[ operation ~CDamper() 
    clean();
    //#]
    cleanUpRelations();
}

HRESULT CDamper::InitEqnForm(OnEqnForm**  form, OnEqnDiffForm**  diff_form) {
    NOTIFY_OPERATION(InitEqnForm, InitEqnForm(OnEqnForm**,OnEqnDiffForm**), 0, StandardModels_CDamper_InitEqnForm_SERIALIZE);
    //#[ operation InitEqnForm(OnEqnForm**,OnEqnDiffForm**) 
    
    
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
      (*diff_form)[idx_eqn_res0] = automatic;
      (*diff_form)[idx_eqn_res1] = automatic;
      (*diff_form)[idx_eqn_res2] = automatic;
    
      return S_OK;
    //#]
}

HRESULT CDamper::InitEsos() {
    NOTIFY_OPERATION(InitEsos, InitEsos(), 0, StandardModels_CDamper_InitEsos_SERIALIZE);
    //#[ operation InitEsos() 
    
      ADD_LOCAL_ESO(n)
      ADD_LOCAL_ESO(p)
    
      return S_OK;
    //#]
}

HRESULT CDamper::InitLocalADEqns() {
    NOTIFY_OPERATION(InitLocalADEqns, InitLocalADEqns(), 0, StandardModels_CDamper_InitLocalADEqns_SERIALIZE);
    //#[ operation InitLocalADEqns() 
    
      ADD_LOCAL_AD_EQN(CDamper, ad_res0)
      ADD_LOCAL_AD_EQN(CDamper, ad_res1)
      ADD_LOCAL_AD_EQN(CDamper, ad_res2)
    
      return S_OK;
    //#]
}

HRESULT CDamper::InitLocalEqns() {
    NOTIFY_OPERATION(InitLocalEqns, InitLocalEqns(), 0, StandardModels_CDamper_InitLocalEqns_SERIALIZE);
    //#[ operation InitLocalEqns() 
    
      ADD_LOCAL_EQN(CDamper, res0)
      ADD_LOCAL_EQN(CDamper, res1)
      ADD_LOCAL_EQN(CDamper, res2)
    
      return S_OK;
    //#]
}

HRESULT CDamper::InitLocalRPars(const _TCHAR * prefix, ppdouble*  pars, ppchar*  Names, long*  nPars, long*  dPars) {
    NOTIFY_OPERATION(InitLocalRPars, InitLocalRPars(const _TCHAR * ,ppdouble*,ppchar*,long*,long*), 0, StandardModels_CDamper_InitLocalRPars_SERIALIZE);
    //#[ operation InitLocalRPars(const _TCHAR * ,ppdouble*,ppchar*,long*,long*) 
    
    
      ADD_LOCAL_SRPAR(Kd)
    
      return S_OK;
    //#]
}

HRESULT CDamper::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    NOTIFY_OPERATION(InitLocalVars, InitLocalVars(const _TCHAR * ,VarCont * ,const bool ), 0, StandardModels_CDamper_InitLocalVars_SERIALIZE);
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    
    
      ADD_LOCAL_SVAR(velocity)
    
     for (long i = 0; i < m_nEsos; i++)
       AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
      return S_OK;
    //#]
}

bool CDamper::Load(FILE*  fs) {
    NOTIFY_OPERATION(Load, Load(FILE*), 0, StandardModels_CDamper_Load_SERIALIZE);
    //#[ operation Load(FILE*) 
    
    return true;
    //#]
}

void CDamper::Save(FILE*  fs) {
    NOTIFY_OPERATION(Save, Save(FILE*), 0, StandardModels_CDamper_Save_SERIALIZE);
    //#[ operation Save(FILE*) 
    //#]
}

HRESULT CDamper::ad_res0(Fdouble*  res) {
    //#[ operation ad_res0(Fdouble*) 
      *res = p->AD(torque) - Kd * AD(velocity);
      return S_OK;
    
    //#]
}

HRESULT CDamper::ad_res1(Fdouble*  res) {
    //#[ operation ad_res1(Fdouble*) 
      *res = p->AD(torque) + n->AD(torque); 
      return S_OK;
    
    //#]
}

HRESULT CDamper::ad_res2(Fdouble*  res) {
    //#[ operation ad_res2(Fdouble*) 
      *res = DER_AD(velocity) - (p->AD(acceleration) - n->AD(acceleration));
      return S_OK;
    
    //#]
}

void CDamper::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, StandardModels_CDamper_clean_SERIALIZE);
    //#[ operation clean() 
      p->Release();
      n->Release();
    
    //#]
}

void CDamper::handle_Kd(const double t, const double * val) {
    NOTIFY_OPERATION(handle_Kd, handle_Kd(const double ,const double * ), 0, StandardModels_CDamper_handle_Kd_SERIALIZE);
    //#[ operation handle_Kd(const double ,const double * ) 
    PostRealParameter(t, 0, *val);
    
    //#]
}

void CDamper::init() {
    NOTIFY_OPERATION(init, init(), 0, StandardModels_CDamper_init_SERIALIZE);
    //#[ operation init() 
      Kd = 1.0;
    
      velocity = 0.0;
      DER(velocity) = 0.0;
    
      p = new CRigidConnector();
      n = new CRigidConnector();
      p->AddRef();
      n->AddRef();
    
    //#]
}

HRESULT CDamper::res0(double * res) {
    //#[ operation res0(double * ) 
      *res = p->torque - Kd * velocity;
      return S_OK;
    
    //#]
}

HRESULT CDamper::res1(double * res) {
    //#[ operation res1(double * ) 
      *res = p->torque + n->torque; 
      return S_OK;
    
    //#]
}

HRESULT CDamper::res2(double * res) {
    //#[ operation res2(double * ) 
      *res = DER(velocity) - (p->acceleration - n->acceleration);
      return S_OK;
    
    //#]
}

double CDamper::getKd() const {
    return Kd;
}

void CDamper::setKd(double  p_Kd) {
    Kd = p_Kd;
}

VarEx CDamper::get_velocity() const {
    return _velocity;
}

void CDamper::set_velocity(VarEx  p__velocity) {
    _velocity = p__velocity;
}

double CDamper::getVelocity() const {
    return velocity;
}

void CDamper::setVelocity(double  p_velocity) {
    velocity = p_velocity;
}

CRigidConnector* CDamper::getN() const {
    return n;
}

void CDamper::setN(CRigidConnector*  p_CRigidConnector) {
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

CRigidConnector* CDamper::getP() const {
    return p;
}

void CDamper::setP(CRigidConnector*  p_CRigidConnector) {
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

void CDamper::cleanUpRelations() {
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


void OMAnimatedCDamper::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedCDamper::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("n", FALSE, TRUE);
    if(myReal->n)
        aomsRelations->ADD_ITEM(myReal->n);
    aomsRelations->addRelation("p", FALSE, TRUE);
    if(myReal->p)
        aomsRelations->ADD_ITEM(myReal->p);
}

IMPLEMENT_META(CDamper, StandardModels, FALSE, OMAnimatedCDamper)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\CDamper.cpp
*********************************************************************/

