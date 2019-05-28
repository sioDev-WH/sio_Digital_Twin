/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: CFrame
//!	Generated Date	: Thu, 9, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\CFrame.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "CFrame.h"
#include "CRigidConnector.h"
#include "stdafx.h"
#include "math.h"

//## package StandardModels 


//#[ ignore 
#define StandardModels_CFrame_CFrame_SERIALIZE OM_NO_OP


#define StandardModels_CFrame_InitEqnForm_SERIALIZE OM_NO_OP


#define StandardModels_CFrame_InitEsos_SERIALIZE OM_NO_OP


#define StandardModels_CFrame_InitLocalADEqns_SERIALIZE OM_NO_OP


#define StandardModels_CFrame_InitLocalEqns_SERIALIZE OM_NO_OP


#define StandardModels_CFrame_InitLocalVars_SERIALIZE OM_NO_OP


#define StandardModels_CFrame_Load_SERIALIZE OM_NO_OP


#define StandardModels_CFrame_Save_SERIALIZE OM_NO_OP


#define StandardModels_CFrame_clean_SERIALIZE OM_NO_OP


#define StandardModels_CFrame_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// CFrame.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(StandardModels)
//## class CFrame 



CFrame::CFrame() {
    NOTIFY_CONSTRUCTOR(CFrame, CFrame(), 0, StandardModels_CFrame_CFrame_SERIALIZE);
    p = NULL;
    //#[ operation CFrame() 
    init();
    //#]
}

CFrame::~CFrame() {
    NOTIFY_DESTRUCTOR(~CFrame, TRUE);
    //#[ operation ~CFrame() 
    clean();
    //#]
    cleanUpRelations();
}

HRESULT CFrame::InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form) {
    NOTIFY_OPERATION(InitEqnForm, InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ), 0, StandardModels_CFrame_InitEqnForm_SERIALIZE);
    //#[ operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
    const long idx_eqn_res0 = 0;
    
      DESTROY_VECTOR(*form)
      *form = new OnEqnForm[m_nLocalEqns];
      (*form)[idx_eqn_res0] = continuous;
    
      DESTROY_VECTOR(*diff_form)
      *diff_form = new OnEqnDiffForm[m_nLocalEqns];
      (*diff_form)[idx_eqn_res0] = numeric;
    
      return S_OK;
    
    //#]
}

HRESULT CFrame::InitEsos() {
    NOTIFY_OPERATION(InitEsos, InitEsos(), 0, StandardModels_CFrame_InitEsos_SERIALIZE);
    //#[ operation InitEsos() 
      ADD_LOCAL_ESO(p)
    
      return S_OK;
    
    //#]
}

HRESULT CFrame::InitLocalADEqns() {
    NOTIFY_OPERATION(InitLocalADEqns, InitLocalADEqns(), 0, StandardModels_CFrame_InitLocalADEqns_SERIALIZE);
    //#[ operation InitLocalADEqns() 
      ADD_LOCAL_AD_EQN(CFrame, ad_res0)
    
      return S_OK;
    
    //#]
}

HRESULT CFrame::InitLocalEqns() {
    NOTIFY_OPERATION(InitLocalEqns, InitLocalEqns(), 0, StandardModels_CFrame_InitLocalEqns_SERIALIZE);
    //#[ operation InitLocalEqns() 
      ADD_LOCAL_EQN(CFrame, res0)
    
      return S_OK;
    
    //#]
}

HRESULT CFrame::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    NOTIFY_OPERATION(InitLocalVars, InitLocalVars(const _TCHAR * ,VarCont * ,const bool ), 0, StandardModels_CFrame_InitLocalVars_SERIALIZE);
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    
     for (long i = 0; i < m_nEsos; i++)
       AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
      return S_OK;
    
    //#]
}

bool CFrame::Load(FILE * fs) {
    NOTIFY_OPERATION(Load, Load(FILE * ), 0, StandardModels_CFrame_Load_SERIALIZE);
    //#[ operation Load(FILE * ) 
    return true;
    //#]
}

void CFrame::Save(FILE * fs) {
    NOTIFY_OPERATION(Save, Save(FILE * ), 0, StandardModels_CFrame_Save_SERIALIZE);
    //#[ operation Save(FILE * ) 
    //#]
}

HRESULT CFrame::ad_res0(Fdouble * res) {
    //#[ operation ad_res0(Fdouble * ) 
      *res = p->AD(acceleration);
      return S_OK;
    
    //#]
}

void CFrame::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, StandardModels_CFrame_clean_SERIALIZE);
    //#[ operation clean() 
    p->Release();
    
    //#]
}

void CFrame::init() {
    NOTIFY_OPERATION(init, init(), 0, StandardModels_CFrame_init_SERIALIZE);
    //#[ operation init() 
    p = new CRigidConnector();
    p->AddRef();
    
    //#]
}

HRESULT CFrame::res0(double * res) {
    //#[ operation res0(double * ) 
      *res = p->acceleration;
      return S_OK;
    
    //#]
}

CRigidConnector* CFrame::getP() const {
    return p;
}

void CFrame::setP(CRigidConnector*  p_CRigidConnector) {
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

void CFrame::cleanUpRelations() {
    if(p != NULL)
        {
            NOTIFY_RELATION_CLEARED("p");
            p = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedCFrame::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("p", FALSE, TRUE);
    if(myReal->p)
        aomsRelations->ADD_ITEM(myReal->p);
}

IMPLEMENT_META(CFrame, StandardModels, FALSE, OMAnimatedCFrame)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\CFrame.cpp
*********************************************************************/

