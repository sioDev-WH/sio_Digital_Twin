/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: AeroDynamics
//!	Generated Date	: Tue, 10, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\AeroDynamics.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "stdafx.h"
#include "AeroDynamics.h"
#include "AeroCoeff.h"
#include "Atmosphere.h"
#include "On1DConn.h"
#include "On3DConn.h"
#include "math.h"

//## package GuidancePkg 

//----------------------------------------------------------------------------
// AeroDynamics.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(GuidancePkg)
//## class AeroDynamics 



AeroDynamics::AeroDynamics() {
    pAtmosphere = NULL;
    pBody = NULL;
    pCoeff = NULL;
    pFinConn = NULL;
    //#[ operation AeroDynamics() 
    init();
    //#]
}

AeroDynamics::~AeroDynamics() {
    //#[ operation ~AeroDynamics() 
    clean();
    //#]
    cleanUpRelations();
}

HRESULT AeroDynamics::InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form) {
    //#[ operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
    const long idx_eqn_r_alpha = 0;
    const long idx_eqn_r_V = 1;
    const long idx_eqn_r_Mach = 2;
    const long idx_eqn_r_Cx_alpha = 3;
    const long idx_eqn_r_Cz_alpha = 4;
    const long idx_eqn_r_Cm_alpha = 5;
    const long idx_eqn_r_Fx = 6;
    const long idx_eqn_r_Fz = 7;
    const long idx_eqn_r_My = 8;
    
    // state machine implementation
    /*
    const long idx_eqn_s_alpha = 9;
    const long idx_eqn_s_u = 10;
    */
    
    DESTROY_VECTOR(*form)
    *form = new OnEqnForm[m_nLocalEqns];
    (*form)[idx_eqn_r_alpha] = continuous;
    (*form)[idx_eqn_r_V] = continuous;
    (*form)[idx_eqn_r_Mach] = continuous;
    (*form)[idx_eqn_r_Cx_alpha] = continuous;
    (*form)[idx_eqn_r_Cz_alpha] = continuous;
    (*form)[idx_eqn_r_Cm_alpha] = continuous;
    (*form)[idx_eqn_r_Fx] = continuous;
    (*form)[idx_eqn_r_Fz] = continuous;
    (*form)[idx_eqn_r_My] = continuous;
    
    // state machine implementation
    /*
    (*form)[idx_eqn_s_alpha] = reset;
    (*form)[idx_eqn_s_u] = reset;
    */
    
    DESTROY_VECTOR(*diff_form)
    *diff_form = new OnEqnDiffForm[m_nLocalEqns];
    (*diff_form)[idx_eqn_r_alpha] = automatic;
    (*diff_form)[idx_eqn_r_V] = automatic;
    (*diff_form)[idx_eqn_r_Mach] = automatic;
    (*diff_form)[idx_eqn_r_Cx_alpha] = automatic;
    (*diff_form)[idx_eqn_r_Cz_alpha] = automatic;
    (*diff_form)[idx_eqn_r_Cm_alpha] = automatic;
    (*diff_form)[idx_eqn_r_Fx] = automatic;
    (*diff_form)[idx_eqn_r_Fz] = automatic;
    (*diff_form)[idx_eqn_r_My] = automatic;
    
    // state machine implementation
    /*
    (*diff_form)[idx_eqn_s_alpha] = automatic;
    (*diff_form)[idx_eqn_s_u] = automatic;
    */
    
    return S_OK;
    //#]
}

HRESULT AeroDynamics::InitEsos() {
    //#[ operation InitEsos() 
    ADD_LOCAL_ESO(pBody)
    ADD_LOCAL_ESO(pFinConn)
    
    return S_OK;
    //#]
}

HRESULT AeroDynamics::InitLocalADEqns() {
    //#[ operation InitLocalADEqns() 
    ADD_LOCAL_AD_EQN(AeroDynamics, ad_r_alpha)
    ADD_LOCAL_AD_EQN(AeroDynamics, ad_r_V)
    ADD_LOCAL_AD_EQN(AeroDynamics, ad_r_Mach)
    ADD_LOCAL_AD_EQN(AeroDynamics, ad_r_Cx_alpha)
    ADD_LOCAL_AD_EQN(AeroDynamics, ad_r_Cz_alpha)
    ADD_LOCAL_AD_EQN(AeroDynamics, ad_r_Cm_alpha)
    ADD_LOCAL_AD_EQN(AeroDynamics, ad_r_Fx)
    ADD_LOCAL_AD_EQN(AeroDynamics, ad_r_Fz)
    ADD_LOCAL_AD_EQN(AeroDynamics, ad_r_My)
    
    // state machine implementation
    /*
    ADD_LOCAL_AD_EQN(AeroDynamics, ad_s_alpha)
    ADD_LOCAL_AD_EQN(AeroDynamics, ad_s_u)
    */
    
    return S_OK;
    //#]
}

HRESULT AeroDynamics::InitLocalEqns() {
    //#[ operation InitLocalEqns() 
    ADD_LOCAL_EQN(AeroDynamics, r_alpha)
    ADD_LOCAL_EQN(AeroDynamics, r_V)
    ADD_LOCAL_EQN(AeroDynamics, r_Mach)
    ADD_LOCAL_EQN(AeroDynamics, r_Cx_alpha)
    ADD_LOCAL_EQN(AeroDynamics, r_Cz_alpha)
    ADD_LOCAL_EQN(AeroDynamics, r_Cm_alpha)
    ADD_LOCAL_EQN(AeroDynamics, r_Fx)
    ADD_LOCAL_EQN(AeroDynamics, r_Fz)
    ADD_LOCAL_EQN(AeroDynamics, r_My)
    
    // state machine implementation
    /*
    ADD_LOCAL_EQN(AeroDynamics, s_alpha)
    ADD_LOCAL_EQN(AeroDynamics, s_u)
    */
    
    return S_OK;
    //#]
}

HRESULT AeroDynamics::InitLocalRPars(const _TCHAR * prefix, ppdouble * pars, ppchar * Names, long * nPars, long * dPars) {
    //#[ operation InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ) 
    
     ADD_LOCAL_SRPAR(Thrust)
     ADD_LOCAL_CRPAR(*pCoeff)
    
     return S_OK;
    //#]
}

HRESULT AeroDynamics::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    
     ADD_LOCAL_CVAR(pCoeff)
    
     for (long i = 0; i < m_nEsos; i++)
       AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
     return S_OK; 
    //#]
}

bool AeroDynamics::Load(FILE * fs) {
    //#[ operation Load(FILE * ) 
    return true;
    //#]
}

void AeroDynamics::Save(FILE * fs) {
    //#[ operation Save(FILE * ) 
    //#]
}

HRESULT AeroDynamics::ad_r_Cm_alpha(Fdouble * res) {
    //#[ operation ad_r_Cm_alpha(Fdouble * ) 
    *res = 	-pCoeff->AD(Cm_alpha) + pCoeff->AD(alpha) *
    					(	 pCoeff->cm * (7.0-8.0 * pCoeff->AD(Mach) / 3.0) 
    					   + pCoeff->bm * fabs(pCoeff->alpha)
    					   - pCoeff->am * pCoeff->AD(alpha) * pCoeff->AD(alpha) );
    return S_OK;
    //#]
}

HRESULT AeroDynamics::ad_r_Cx_alpha(Fdouble * res) {
    //#[ operation ad_r_Cx_alpha(Fdouble * ) 
    *res = -pCoeff->AD(Cx_alpha) - 0.3;
    return S_OK;
    //#]
}

HRESULT AeroDynamics::ad_r_Cz_alpha(Fdouble * res) {
    //#[ operation ad_r_Cz_alpha(Fdouble * ) 
    *res = -pCoeff->AD(Cz_alpha) + pCoeff->AD(alpha) *
    					(	 pCoeff->cn * (2.0 - pCoeff->AD(Mach) / 3.0) 
    					   + pCoeff->bn * fabs(pCoeff->alpha)
    					   + pCoeff->an * pCoeff->AD(alpha) * pCoeff->AD(alpha) );
    return S_OK;
    //#]
}

HRESULT AeroDynamics::ad_r_Fx(Fdouble * res) {
    //#[ operation ad_r_Fx(Fdouble * ) 
    Fdouble dynamicPressure;
    Fdouble& Fx = pBody->AD(Fx);
    
    dynamicPressure = 0.5 * pCoeff->AD(V) * pCoeff->AD(V) * pAtmosphere->airDensity;
    *res = -Fx + pCoeff->S_ref * dynamicPressure * (pCoeff->AD(Cx_alpha) + pCoeff->Cx_el * pFinConn->AD(pos)) + Thrust;
    
    return S_OK;
    //#]
}

HRESULT AeroDynamics::ad_r_Fz(Fdouble * res) {
    //#[ operation ad_r_Fz(Fdouble * ) 
    Fdouble dynamicPressure;
    Fdouble& Fz = pBody->AD(Fz);
    
    dynamicPressure = 0.5 * pCoeff->AD(V) * pCoeff->AD(V) * pAtmosphere->airDensity;
    *res = -Fz + pCoeff->S_ref * dynamicPressure * (pCoeff->AD(Cz_alpha) + pCoeff->Cz_el * pFinConn->AD(pos) );
    
    return S_OK;
    //#]
}

HRESULT AeroDynamics::ad_r_Mach(Fdouble * res) {
    //#[ operation ad_r_Mach(Fdouble * ) 
    *res = -pCoeff->AD(Mach) + pCoeff->AD(V) / pAtmosphere->speedOfSound;
    return S_OK;
    //#]
}

HRESULT AeroDynamics::ad_r_My(Fdouble * res) {
    //#[ operation ad_r_My(Fdouble * ) 
    Fdouble dynamicPressure;
    Fdouble& q = pBody->AD(q);
    Fdouble& My = pBody->AD(My);
    
    dynamicPressure = 0.5 * pCoeff->AD(V) * pCoeff->AD(V) * pAtmosphere->airDensity;
    *res = -My + pCoeff->d_ref * pCoeff->S_ref * dynamicPressure *
         (pCoeff->AD(Cm_alpha) + pCoeff->Cm_el * pFinConn->AD(pos) + pCoeff->Cm_q * q);
    
    return S_OK;
    //#]
}

HRESULT AeroDynamics::ad_r_V(Fdouble * res) {
    //#[ operation ad_r_V(Fdouble * ) 
    Fdouble& u = pBody->AD(u);
    Fdouble& w = pBody->AD(w);
    
    *res = -pCoeff->AD(V) + sqrt(u*u+w*w);
    return S_OK;
    //#]
}

HRESULT AeroDynamics::ad_r_alpha(Fdouble * res) {
    //#[ operation ad_r_alpha(Fdouble * ) 
    Fdouble& u = pBody->AD(u);
    Fdouble& w = pBody->AD(w);
    
    //*res = -pCoeff->AD(alpha) + atan2(w, u);
    if (u.v == 0.0) u.v = 1.0e-15; 
    *res = -pCoeff->AD(alpha) + atan(w / u);
    
    return S_OK;
    //#]
}

void AeroDynamics::clean() {
    //#[ operation clean() 
    if (pAtmosphere)
    {
      delete pAtmosphere;
      pAtmosphere = NULL;
    }
    if (pCoeff)
    {
      delete pCoeff;
      pAtmosphere = NULL;
    }
    if (pBody)
    {
      pBody->Release();
      pBody = NULL;
    }
    if (pFinConn)
    {
      pFinConn->Release();
      pFinConn = NULL;
    }
    //#]
}

void AeroDynamics::init() {
    //#[ operation init() 
    double initialHeight = 10000/m2ft;
    
    pAtmosphere = new Atmosphere();
    // Assumption: atmosphere data is only calculated on initialization
    pAtmosphere->updateData(initialHeight); 
    pCoeff = new AeroCoeff();
    pBody = new On3DConn();
    pBody->AddRef();
    pFinConn = new On1DConn();
    pFinConn->AddRef();
    
    // WAH initializing u to mach 3 - REPLACED by STATE MACHINE Reset equations
    // pBody->u = 3.0 * 328;
    // pBody->w = 0.0;
    
    Thrust = 10000.0;
    
    // state machine implementation
    //initStateMachine();
    //#]
}

HRESULT AeroDynamics::r_Cm_alpha(double * res) {
    //#[ operation r_Cm_alpha(double * ) 
    *res = 	-pCoeff->Cm_alpha + pCoeff->alpha*
    					(  - pCoeff->cm*(7.0-8.0*pCoeff->Mach/3.0) 
    					   + pCoeff->bm*fabs(pCoeff->alpha)
    					   + pCoeff->am*pCoeff->alpha*pCoeff->alpha);
    return S_OK;
    //#]
}

HRESULT AeroDynamics::r_Cx_alpha(double * res) {
    //#[ operation r_Cx_alpha(double * ) 
    *res = -pCoeff->Cx_alpha - 0.3;
    return S_OK;
    //#]
}

HRESULT AeroDynamics::r_Cz_alpha(double * res) {
    //#[ operation r_Cz_alpha(double * ) 
    *res = -pCoeff->Cz_alpha + pCoeff->alpha*
    					(	 pCoeff->cn*(2.0-pCoeff->Mach/3.0) 
    					   + pCoeff->bn*fabs(pCoeff->alpha)
    					   + pCoeff->an*pCoeff->alpha*pCoeff->alpha);
    return S_OK;
    //#]
}

HRESULT AeroDynamics::r_Fx(double * res) {
    //#[ operation r_Fx(double * ) 
    double dynamicPressure;
    double& Fx = pBody->Fx;
    
    dynamicPressure = 0.5 * pCoeff->V * pCoeff->V * pAtmosphere->airDensity;
    *res = -Fx + pCoeff->S_ref*dynamicPressure*(pCoeff->Cx_alpha+pCoeff->Cx_el * pFinConn->pos )+ Thrust ;
    
    return S_OK;
    //#]
}

HRESULT AeroDynamics::r_Fz(double * res) {
    //#[ operation r_Fz(double * ) 
    double dynamicPressure;
    double& Fz = pBody->Fz;
    
    dynamicPressure = 0.5 * pCoeff->V * pCoeff->V * pAtmosphere->airDensity;
    *res = -Fz + pCoeff->S_ref*dynamicPressure*(pCoeff->Cz_alpha+pCoeff->Cz_el * pFinConn->pos);
    
    return S_OK;
    //#]
}

HRESULT AeroDynamics::r_Mach(double * res) {
    //#[ operation r_Mach(double * ) 
    *res = -pCoeff->Mach + pCoeff->V/pAtmosphere->speedOfSound;
    return S_OK;
    //#]
}

HRESULT AeroDynamics::r_My(double * res) {
    //#[ operation r_My(double * ) 
    double dynamicPressure;
    double& My = pBody->My;
    double& q = pBody->q;
    
    dynamicPressure = 0.5 * pCoeff->V * pCoeff->V * pAtmosphere->airDensity;
    *res = -My + pCoeff->d_ref*pCoeff->S_ref*dynamicPressure *
         (pCoeff->Cm_alpha+pCoeff->Cm_el * pFinConn->pos + pCoeff->Cm_q*q);
    
    return S_OK;
    //#]
}

HRESULT AeroDynamics::r_V(double * res) {
    //#[ operation r_V(double * ) 
    double& u = pBody->u;
    double& w = pBody->w;
    
    *res = -pCoeff->V + sqrt(u*u+w*w);
    return S_OK;
    //#]
}

HRESULT AeroDynamics::r_alpha(double * res) {
    //#[ operation r_alpha(double * ) 
    double& u = pBody->u;
    double& w = pBody->w;
    
    // TODO: put this back
    //*res = -pCoeff->alpha + atan2(w, u);
    
    // WAH See note below on atan2(y,x)
    if (u == 0.0) u = 1.0e-15;
    *res = -pCoeff->alpha + atan(w/u);
    
    //KB *res = -pCoeff->alpha; 
    return S_OK;
    //#]
}

void AeroDynamics::setThrust(const double time, double * val) {
    //#[ operation setThrust(const double ,double * ) 
    const long idx_rpar_Thrust = 0;
    PostRealParameter(time, idx_rpar_Thrust, *val);
    //#]
}

void AeroDynamics::setThrust(double  p_Thrust) {
    Thrust = p_Thrust;
}

Atmosphere* AeroDynamics::getPAtmosphere() const {
    return pAtmosphere;
}

void AeroDynamics::setPAtmosphere(Atmosphere*  p_Atmosphere) {
    pAtmosphere = p_Atmosphere;
    if(p_Atmosphere != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("pAtmosphere", p_Atmosphere, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("pAtmosphere");
        }
}

On3DConn* AeroDynamics::getPBody() const {
    return pBody;
}

void AeroDynamics::setPBody(On3DConn*  p_On3DConn) {
    pBody = p_On3DConn;
    if(p_On3DConn != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("pBody", p_On3DConn, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("pBody");
        }
}

AeroCoeff* AeroDynamics::getPCoeff() const {
    return pCoeff;
}

void AeroDynamics::setPCoeff(AeroCoeff*  p_AeroCoeff) {
    pCoeff = p_AeroCoeff;
    if(p_AeroCoeff != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("pCoeff", p_AeroCoeff, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("pCoeff");
        }
}

On1DConn* AeroDynamics::getPFinConn() const {
    return pFinConn;
}

void AeroDynamics::setPFinConn(On1DConn*  p_On1DConn) {
    pFinConn = p_On1DConn;
    if(p_On1DConn != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("pFinConn", p_On1DConn, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("pFinConn");
        }
}

void AeroDynamics::cleanUpRelations() {
    if(pAtmosphere != NULL)
        {
            NOTIFY_RELATION_CLEARED("pAtmosphere");
            pAtmosphere = NULL;
        }
    if(pBody != NULL)
        {
            NOTIFY_RELATION_CLEARED("pBody");
            pBody = NULL;
        }
    if(pCoeff != NULL)
        {
            NOTIFY_RELATION_CLEARED("pCoeff");
            pCoeff = NULL;
        }
    if(pFinConn != NULL)
        {
            NOTIFY_RELATION_CLEARED("pFinConn");
            pFinConn = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedAeroDynamics::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedAeroDynamics::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("pCoeff", FALSE, TRUE);
    if(myReal->pCoeff)
        aomsRelations->ADD_ITEM(myReal->pCoeff);
    aomsRelations->addRelation("pAtmosphere", FALSE, TRUE);
    if(myReal->pAtmosphere)
        aomsRelations->ADD_ITEM(myReal->pAtmosphere);
    aomsRelations->addRelation("pBody", FALSE, TRUE);
    if(myReal->pBody)
        aomsRelations->ADD_ITEM(myReal->pBody);
    aomsRelations->addRelation("pFinConn", FALSE, TRUE);
    if(myReal->pFinConn)
        aomsRelations->ADD_ITEM(myReal->pFinConn);
}

IMPLEMENT_META(AeroDynamics, GuidancePkg, FALSE, OMAnimatedAeroDynamics)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\AeroDynamics.cpp
*********************************************************************/

