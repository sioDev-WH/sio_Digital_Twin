/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: aeroDynamics
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\aeroDynamics.cpp
*********************************************************************/

#include <oxf/omthread.h>
#include "aeroDynamics.h"
#include "OnUMLEso.h"
#include "math.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// aeroDynamics.cpp                                                                  
//----------------------------------------------------------------------------
//## class aeroDynamics 



aeroDynamics::aeroDynamics(OMThread*  p_thread) {
    setThread(p_thread, FALSE);
    //#[ operation aeroDynamics() 
    init();
    //#]
}

aeroDynamics::~aeroDynamics() {
    //#[ operation ~aeroDynamics() 
    clean();
    //#]
}

HRESULT aeroDynamics::InitEqnForm(OnEqnForm**  form, OnEqnDiffForm**  diff_form) {
    //#[ operation InitEqnForm(OnEqnForm**,OnEqnDiffForm**) 
    
    
    const long idx_eqn_r_AoA = 0;
    const long idx_eqn_r_SSA = 1;
    const long idx_eqn_r_V = 2;
    const long idx_eqn_r_Mach = 3;
    const long idx_eqn_r_C = 4;
    const long idx_eqn_r_Forces = 5;
    const long idx_eqn_r_Moments = 6;
    
      DESTROY_VECTOR(*form)
      *form = new OnEqnForm[m_nLocalEqns];
      (*form)[idx_eqn_r_AoA] = continuous;
      (*form)[idx_eqn_r_SSA] = continuous;
      (*form)[idx_eqn_r_V] = continuous;
      (*form)[idx_eqn_r_Mach] = continuous;
      (*form)[idx_eqn_r_C] = continuous;
      (*form)[idx_eqn_r_Forces] = continuous;
      (*form)[idx_eqn_r_Moments] = continuous;
    
      DESTROY_VECTOR(*diff_form)
      *diff_form = new OnEqnDiffForm[m_nLocalEqns];
      (*diff_form)[idx_eqn_r_AoA] = automatic;
      (*diff_form)[idx_eqn_r_SSA] = automatic;
      (*diff_form)[idx_eqn_r_V] = automatic;
      (*diff_form)[idx_eqn_r_Mach] = automatic;
      (*diff_form)[idx_eqn_r_C] = automatic;
      (*diff_form)[idx_eqn_r_Forces] = automatic;
      (*diff_form)[idx_eqn_r_Moments] = automatic;
    
      return S_OK;
    //#]
}

HRESULT aeroDynamics::InitEsos() {
    //#[ operation InitEsos() 
    
      ADD_LOCAL_ESO(&p)
      ADD_LOCAL_ESO(&pAtmosphere)
      ADD_LOCAL_ESO(&pFin)
    
      return S_OK;
    //#]
}

HRESULT aeroDynamics::InitLocalADEqns() {
    //#[ operation InitLocalADEqns() 
    
      ADD_LOCAL_AD_EQN(aeroDynamics, ad_r_AoA)
      ADD_LOCAL_AD_EQN(aeroDynamics, ad_r_SSA)
      ADD_LOCAL_AD_EQN(aeroDynamics, ad_r_V)
      ADD_LOCAL_AD_EQN(aeroDynamics, ad_r_Mach)
      ADD_LOCAL_STL_AD_EQN(aeroDynamics, ad_r_C, 1)
      ADD_LOCAL_STL_AD_EQN(aeroDynamics, ad_r_Forces, 1)
      ADD_LOCAL_STL_AD_EQN(aeroDynamics, ad_r_Moments, 1)
    
      return S_OK;
    //#]
}

HRESULT aeroDynamics::InitLocalEqns() {
    //#[ operation InitLocalEqns() 
    
      ADD_LOCAL_EQN(aeroDynamics, r_AoA)
      ADD_LOCAL_EQN(aeroDynamics, r_SSA)
      ADD_LOCAL_EQN(aeroDynamics, r_V)
      ADD_LOCAL_EQN(aeroDynamics, r_Mach)
      ADD_LOCAL_STL_EQN(aeroDynamics, r_C, 1)
      ADD_LOCAL_STL_EQN(aeroDynamics, r_Forces, 1)
      ADD_LOCAL_STL_EQN(aeroDynamics, r_Moments, 1)
    
      return S_OK;
    //#]
}

HRESULT aeroDynamics::InitLocalRPars(const _TCHAR*  prefix, ppdouble*  pars, ppchar*  Names, long*  nPars, long*  dPars) {
    //#[ operation InitLocalRPars(const _TCHAR*,ppdouble*,ppchar*,long*,long*) 
    
    
      ADD_LOCAL_SRPAR(mass)
      ADD_LOCAL_SRPAR(g)
      ADD_LOCAL_SRPAR(Cx_el)
      ADD_LOCAL_SRPAR(Cy_rudder)
      ADD_LOCAL_SRPAR(Cz_el)
      ADD_LOCAL_SRPAR(Cl_p)
      ADD_LOCAL_SRPAR(Cl_al)
      ADD_LOCAL_SRPAR(Cm_q)
      ADD_LOCAL_SRPAR(Cm_el)
      ADD_LOCAL_SRPAR(Cn_beta)
      ADD_LOCAL_SRPAR(Cn_r)
      ADD_LOCAL_SRPAR(Cn_rudder)
      ADD_LOCAL_SRPAR(CX)
      ADD_LOCAL_SRPAR(CY)
      ADD_LOCAL_SRPAR(CZ)
      ADD_LOCAL_SRPAR(Cm)
      ADD_LOCAL_SRPAR(Cl)
      ADD_LOCAL_SRPAR(Cn)
      ADD_LOCAL_SRPAR(am)
      ADD_LOCAL_SRPAR(an)
      ADD_LOCAL_SRPAR(bm)
      ADD_LOCAL_SRPAR(bn)
      ADD_LOCAL_SRPAR(d_ref)
      ADD_LOCAL_SRPAR(S_ref)
    
      return S_OK;
    //#]
}

HRESULT aeroDynamics::InitLocalVars(const _TCHAR*  prefix, VarCont*  varC, const bool  bADOnly) {
    //#[ operation InitLocalVars(const _TCHAR*,VarCont*,const bool) 
    
    
      ADD_LOCAL_SVAR(Cx_alpha)
      ADD_LOCAL_SVAR(Cz_alpha)
      ADD_LOCAL_SVAR(Cm_alpha)
      ADD_LOCAL_SVAR(AoA)
      ADD_LOCAL_SVAR(SSA)
      ADD_LOCAL_SVAR(V)
      ADD_LOCAL_SVAR(Mach)
    
    for (long i = 0; i < m_nEsos; i++)
      AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
      return S_OK;
    //#]
}

bool aeroDynamics::Load(FILE*  fs) {
    //#[ operation Load(FILE*) 
    
    return true;
    //#]
}

void aeroDynamics::Save(FILE*  fs) {
    //#[ operation Save(FILE*) 
    //#]
}

HRESULT aeroDynamics::ad_r_AoA(Fdouble*  res) {
    //#[ operation ad_r_AoA(Fdouble*) 
    
    // Incidence valarray<Fdouble> (angle of attack)
    
    valarray<Fdouble>& vel = p.AD(velocity);	// Should use p.AD(velocity) - Gust.velocity
    
    if (vel[0] == 0.0)
    vel[0] = 1.0e-15;
    
    #if 1
    *res = -S_AD(AoA) + atan(vel[2]/vel[0]);						// arctan(w/u)
    #else
    *res = -S_AD(AoA) + atan2(vel[2],vel[0]);						// arctan(w/u)
    #endif
    return S_OK;
    
    //#]
}

HRESULT aeroDynamics::ad_r_C(valarray<Fdouble> *  res) {
    //#[ operation ad_r_C(valarray<Fdouble> *) 
    
    if (res->size() != 3) res->resize(3);
    
    (*res)[0] = -S_AD(Cm_alpha) + S_AD(AoA)*
      			  (  - cm*(7.0-8.0*S_AD(Mach)/3.0) 
      				   + bm*fabs(AoA)
      				   + am*S_AD(AoA)*S_AD(AoA));
    (*res)[1] = -S_AD(Cx_alpha) - 0.3;
    (*res)[2] = -S_AD(Cz_alpha) + S_AD(AoA)*
      			  (	 cn*(2.0-S_AD(Mach)/3.0) 
      				   + bn*fabs(AoA)
      				   + an*S_AD(AoA)*S_AD(AoA));
    return S_OK;
    
    //#]
}

HRESULT aeroDynamics::ad_r_Forces(valarray<Fdouble> *  res) {
    //#[ operation ad_r_Forces(valarray<Fdouble> *) 
    
    Fdouble dynamicPressure;
    Fdouble& Fx = p.AD(force)[0];
    Fdouble& Fy = p.AD(force)[1];
    Fdouble& Fz = p.AD(force)[2];
    
    // pFin->pos is a valarray(3)
    Fdouble aileron	= pFin.AD(angle)[0]; // angle rotates around x-axis
    Fdouble elevator	= pFin.AD(angle)[1];	// angle rotates around y-axis
    Fdouble rudder	= pFin.AD(angle)[2]; // angle rotates around z-axis
    
    if (res->size() != 3) res->resize(3);
    
    dynamicPressure = 0.5 * S_AD(V) * S_AD(V) * pAtmosphere.AD(airDensity)[0];
    
    // Important Thrust should not be added here, it should in an engine object
    // that connects to the bodydynamics at the same port that connects
    // aeroDynamics to bodydynamics -- supernode then will sum thrust as -Fx
    // This way we can add also gravity object, other engines, and other external forces
    // that acts on the bodydynamics.
    (*res)[0] = -Fx + S_ref*dynamicPressure*(S_AD(Cx_alpha)+Cx_el * elevator ); // Careful here assumed port added + Thrust ;
    (*res)[1] = -Fy - S_ref*dynamicPressure*(Cy_beta +Cy_rudder * rudder ); // check signs
    (*res)[2] = -Fz + S_ref*dynamicPressure*(S_AD(Cz_alpha)+Cz_el * elevator);
    
    return S_OK;
    
    //#]
}

HRESULT aeroDynamics::ad_r_Mach(Fdouble*  res) {
    //#[ operation ad_r_Mach(Fdouble*) 
    
    
       *res = -S_AD(Mach) + S_AD(V)/pAtmosphere.AD(speedOfSound)[0];
       return S_OK;
    
    //#]
}

HRESULT aeroDynamics::ad_r_Moments(valarray<Fdouble> *  res) {
    //#[ operation ad_r_Moments(valarray<Fdouble> *) 
    
    
     Fdouble dynamicPressure;
     Fdouble& Mx = p.AD(moment)[0];
     Fdouble& My = p.AD(moment)[1];
     Fdouble& Mz = p.AD(moment)[2];
     Fdouble& rp = p.AD(rate)[0];
     Fdouble& rq = p.AD(rate)[1];
     Fdouble& rr = p.AD(rate)[2];
    
       // pFin->pos is a valarray(3)
     Fdouble aileron	= pFin.AD(angle)[0]; // angle rotates around x-axis
     Fdouble elevator	= pFin.AD(angle)[1];	// angle rotates around y-axis
     Fdouble rudder	= pFin.AD(angle)[2]; // angle rotates around z-axis
    
     if (res->size() != 3) res->resize(3);
    
     dynamicPressure = 0.5 * S_AD(V) * S_AD(V) * pAtmosphere.AD(airDensity)[0];
     (*res)[0] = -Mx + d_ref*S_ref*dynamicPressure *
          (         Cl_al * aileron + Cl_p*rp);
     (*res)[1] = -My + d_ref*S_ref*dynamicPressure *
          (S_AD(Cm_alpha)+Cm_el * elevator + Cm_q*rq);
     (*res)[2] = -Mz + d_ref*S_ref*dynamicPressure *
          (Cn_beta+Cn_rudder * rudder + Cn_r*rr);
    
     return S_OK;
       //#]
    
    //#]
}

HRESULT aeroDynamics::ad_r_SSA(Fdouble*  res) {
    //#[ operation ad_r_SSA(Fdouble*) 
    
    // Side Slip valarray<Fdouble>
    
    valarray<Fdouble>& vel = p.AD(velocity);	// Should use p.AD(velocity) - Gust.velocity
    // KAB fix for AD
    Fdouble& u = vel[0];
    if (u.v == 0.0) u.v = 1.0e-15;
    *res = -S_AD(SSA) + atan(vel[1] / u);						// arctan(v/u)
    return S_OK;
    
    //#]
}

HRESULT aeroDynamics::ad_r_V(Fdouble*  res) {
    //#[ operation ad_r_V(Fdouble*) 
    
    
     valarray<Fdouble>& vel = p.AD(velocity);  // Should use p.AD(velocity) - Gust.velocity
    
     *res = -S_AD(V) + sqrt(dot(vel,vel));							// Speed
     return S_OK;
    
    //#]
}

void aeroDynamics::clean() {
    //#[ operation clean() 
    //#]
}

void aeroDynamics::getAlpha(const double t, double * val) {
    //#[ operation getAlpha(const double ,double * ) 
    GET_VARIABLE_VALUE(L"AoA", t, val)
    //#]
}

void aeroDynamics::getMach(const double t, double * val) {
    //#[ operation getMach(const double ,double * ) 
    GET_VARIABLE_VALUE(L"Mach", t, val)
    //#]
}

void aeroDynamics::get_AoA(const double  t, double*  pVal) {
    //#[ operation get_AoA(const double,double*) 
    
    GET_VARIABLE_VALUE(L"AoA", t, pVal)
    //#]
}

void aeroDynamics::get_Cm_alpha(const double  t, double*  pVal) {
    //#[ operation get_Cm_alpha(const double,double*) 
    
    GET_VARIABLE_VALUE(L"Cm_alpha", t, pVal)
    //#]
}

void aeroDynamics::get_Cx_alpha(const double  t, double*  pVal) {
    //#[ operation get_Cx_alpha(const double,double*) 
    
    GET_VARIABLE_VALUE(L"Cx_alpha", t, pVal)
    //#]
}

void aeroDynamics::get_Cz_alpha(const double  t, double*  pVal) {
    //#[ operation get_Cz_alpha(const double,double*) 
    
    GET_VARIABLE_VALUE(L"Cz_alpha", t, pVal)
    //#]
}

void aeroDynamics::get_Mach(const double  t, double*  pVal) {
    //#[ operation get_Mach(const double,double*) 
    
    GET_VARIABLE_VALUE(L"Mach", t, pVal)
    //#]
}

void aeroDynamics::get_SSA(const double  t, double*  pVal) {
    //#[ operation get_SSA(const double,double*) 
    
    GET_VARIABLE_VALUE(L"SSA", t, pVal)
    //#]
}

void aeroDynamics::get_V(const double  t, double*  pVal) {
    //#[ operation get_V(const double,double*) 
    
    GET_VARIABLE_VALUE(L"V", t, pVal)
    //#]
}

void aeroDynamics::get_der_AoA(const double  t, double*  pVal) {
    //#[ operation get_der_AoA(const double,double*) 
    
    GET_VARIABLE_DER_VALUE(L"AoA", t, pVal)
    //#]
}

void aeroDynamics::get_der_Cm_alpha(const double  t, double*  pVal) {
    //#[ operation get_der_Cm_alpha(const double,double*) 
    
    GET_VARIABLE_DER_VALUE(L"Cm_alpha", t, pVal)
    //#]
}

void aeroDynamics::get_der_Cx_alpha(const double  t, double*  pVal) {
    //#[ operation get_der_Cx_alpha(const double,double*) 
    
    GET_VARIABLE_DER_VALUE(L"Cx_alpha", t, pVal)
    //#]
}

void aeroDynamics::get_der_Cz_alpha(const double  t, double*  pVal) {
    //#[ operation get_der_Cz_alpha(const double,double*) 
    
    GET_VARIABLE_DER_VALUE(L"Cz_alpha", t, pVal)
    //#]
}

void aeroDynamics::get_der_Mach(const double  t, double*  pVal) {
    //#[ operation get_der_Mach(const double,double*) 
    
    GET_VARIABLE_DER_VALUE(L"Mach", t, pVal)
    //#]
}

void aeroDynamics::get_der_SSA(const double  t, double*  pVal) {
    //#[ operation get_der_SSA(const double,double*) 
    
    GET_VARIABLE_DER_VALUE(L"SSA", t, pVal)
    //#]
}

void aeroDynamics::get_der_V(const double  t, double*  pVal) {
    //#[ operation get_der_V(const double,double*) 
    
    GET_VARIABLE_DER_VALUE(L"V", t, pVal)
    //#]
}

void aeroDynamics::handle_CX(const double  t, const double*  val) {
    //#[ operation handle_CX(const double,const double*) 
    
    PostRealParameter(t, 12, *val);
    //#]
}

void aeroDynamics::handle_CY(const double  t, const double*  val) {
    //#[ operation handle_CY(const double,const double*) 
    
    PostRealParameter(t, 13, *val);
    //#]
}

void aeroDynamics::handle_CZ(const double  t, const double*  val) {
    //#[ operation handle_CZ(const double,const double*) 
    
    PostRealParameter(t, 14, *val);
    //#]
}

void aeroDynamics::handle_Cl(const double  t, const double*  val) {
    //#[ operation handle_Cl(const double,const double*) 
    
    PostRealParameter(t, 16, *val);
    //#]
}

void aeroDynamics::handle_Cl_al(const double  t, const double*  val) {
    //#[ operation handle_Cl_al(const double,const double*) 
    
    PostRealParameter(t, 6, *val);
    //#]
}

void aeroDynamics::handle_Cl_p(const double  t, const double*  val) {
    //#[ operation handle_Cl_p(const double,const double*) 
    
    PostRealParameter(t, 5, *val);
    //#]
}

void aeroDynamics::handle_Cm(const double  t, const double*  val) {
    //#[ operation handle_Cm(const double,const double*) 
    
    PostRealParameter(t, 15, *val);
    //#]
}

void aeroDynamics::handle_Cm_el(const double  t, const double*  val) {
    //#[ operation handle_Cm_el(const double,const double*) 
    
    PostRealParameter(t, 8, *val);
    //#]
}

void aeroDynamics::handle_Cm_q(const double  t, const double*  val) {
    //#[ operation handle_Cm_q(const double,const double*) 
    
    PostRealParameter(t, 7, *val);
    //#]
}

void aeroDynamics::handle_Cn(const double  t, const double*  val) {
    //#[ operation handle_Cn(const double,const double*) 
    
    PostRealParameter(t, 17, *val);
    //#]
}

void aeroDynamics::handle_Cn_beta(const double  t, const double*  val) {
    //#[ operation handle_Cn_beta(const double,const double*) 
    
    PostRealParameter(t, 9, *val);
    //#]
}

void aeroDynamics::handle_Cn_r(const double  t, const double*  val) {
    //#[ operation handle_Cn_r(const double,const double*) 
    
    PostRealParameter(t, 10, *val);
    //#]
}

void aeroDynamics::handle_Cn_rudder(const double  t, const double*  val) {
    //#[ operation handle_Cn_rudder(const double,const double*) 
    
    PostRealParameter(t, 11, *val);
    //#]
}

void aeroDynamics::handle_Cx_el(const double  t, const double*  val) {
    //#[ operation handle_Cx_el(const double,const double*) 
    
    PostRealParameter(t, 2, *val);
    //#]
}

void aeroDynamics::handle_Cy_rudder(const double  t, const double*  val) {
    //#[ operation handle_Cy_rudder(const double,const double*) 
    
    PostRealParameter(t, 3, *val);
    //#]
}

void aeroDynamics::handle_Cz_el(const double  t, const double*  val) {
    //#[ operation handle_Cz_el(const double,const double*) 
    
    PostRealParameter(t, 4, *val);
    //#]
}

void aeroDynamics::handle_S_ref(const double  t, const double*  val) {
    //#[ operation handle_S_ref(const double,const double*) 
    
    PostRealParameter(t, 23, *val);
    //#]
}

void aeroDynamics::handle_am(const double  t, const double*  val) {
    //#[ operation handle_am(const double,const double*) 
    
    PostRealParameter(t, 18, *val);
    //#]
}

void aeroDynamics::handle_an(const double  t, const double*  val) {
    //#[ operation handle_an(const double,const double*) 
    
    PostRealParameter(t, 19, *val);
    //#]
}

void aeroDynamics::handle_bm(const double  t, const double*  val) {
    //#[ operation handle_bm(const double,const double*) 
    
    PostRealParameter(t, 20, *val);
    //#]
}

void aeroDynamics::handle_bn(const double  t, const double*  val) {
    //#[ operation handle_bn(const double,const double*) 
    
    PostRealParameter(t, 21, *val);
    //#]
}

void aeroDynamics::handle_d_ref(const double  t, const double*  val) {
    //#[ operation handle_d_ref(const double,const double*) 
    
    PostRealParameter(t, 22, *val);
    //#]
}

void aeroDynamics::handle_g(const double  t, const double*  val) {
    //#[ operation handle_g(const double,const double*) 
    
    PostRealParameter(t, 1, *val);
    //#]
}

void aeroDynamics::handle_mass(const double  t, const double*  val) {
    //#[ operation handle_mass(const double,const double*) 
    
    PostRealParameter(t, 0, *val);
    //#]
}

void aeroDynamics::init() {
    //#[ operation init() 
    
      #define d2r 0.017453292519943295769236907684886
      #define m2ft 3.280840
    
      an =  0.000103/pow(d2r,3);
      bn = -0.009450/pow(d2r,2);
      cn = -0.169600/d2r;
      am =  0.000215/pow(d2r,3);
      bm = -0.019500/pow(d2r,2);
      cm =  0.051000/d2r;
      
      
      S_ref = 0.44/m2ft/m2ft;
      d_ref = 0.75/m2ft;
      
      Cx_el = 0.00000;
      Cz_el = -0.0340/d2r;
      Cm_el = -0.2060/d2r;
      
      Cm_q = -1.7190;
      
      Cx_alpha = -0.3;
      Cz_alpha = 0.0;
      Cm_alpha = 0.0;
      S_DER(Cx_alpha) = 0.0;
      S_DER(Cz_alpha) = 0.0;
      S_DER(Cm_alpha) = 0.0;
    
    	AoA = 0.0;
    	SSA = 0.0;
    	V = 0.0;
      Mach = 0.0;
    	S_DER(AoA) = 0.0;
    	S_DER(SSA) = 0.0;
    	S_DER(V) = 0.0;
      S_DER(Mach) = 0.0;
    
      p.velocity[0] = 984.0; // u
    
    // Assumptions:
      Cy_beta = 0.0;
      Cy_rudder = 0.0;
      Cl_al = 0.0;
      Cl_p = 0.0;
      Cn_beta = 0.0;
      Cn_rudder = 0.0;
      Cn_r = 0.0;
    
    //#]
}

HRESULT aeroDynamics::r_AoA(double * res) {
    //#[ operation r_AoA(double * ) 
    // Incidence Angle (angle of attack)
    
    Vel& vel = p.velocity;	// Should use p.velocity - Gust.velocity
    
    if (vel[0] == 0.0)
    vel[0] = 1.0e-15;
    
    #if 1
    *res = -AoA + atan(vel[2]/vel[0]);						// arctan(w/u)
    #else
    *res = -AoA + atan2(vel[2],vel[0]);						// arctan(w/u)
    #endif
    return S_OK;
    //#]
}

HRESULT aeroDynamics::r_C(valarray<double>*  res) {
    //#[ operation r_C(valarray<double>*) 
    if (res->size() != 3) res->resize(3);
    
    (*res)[0] = -Cm_alpha + AoA*
      			  (  - cm*(7.0-8.0*Mach/3.0) 
      				   + bm*fabs(AoA)
      				   + am*AoA*AoA);
    (*res)[1] = -Cx_alpha - 0.3;
    (*res)[2] = -Cz_alpha + AoA*
      			  (	 cn*(2.0-Mach/3.0) 
      				   + bn*fabs(AoA)
      				   + an*AoA*AoA);
    return S_OK;
    //#]
}

HRESULT aeroDynamics::r_Forces(valarray<double>*  res) {
    //#[ operation r_Forces(valarray<double>*) 
    double dynamicPressure;
    double& Fx = p.force[0];
    double& Fy = p.force[1];
    double& Fz = p.force[2];
    
    // pFin->pos is a valarray(3)
    double aileron	= pFin.angle[0]; // angle rotates around x-axis
    double elevator	= pFin.angle[1];	// angle rotates around y-axis
    double rudder	= pFin.angle[2]; // angle rotates around z-axis
    
    if (res->size() != 3) res->resize(3);
    
    dynamicPressure = 0.5 * V * V * pAtmosphere.airDensity[0];
    
    // Important Thrust should not be added here, it should in an engine object
    // that connects to the bodydynamics at the same port that connects
    // aeroDynamics to bodydynamics -- supernode then will sum thrust as -Fx
    // This way we can add also gravity object, other engines, and other external forces
    // that acts on the bodydynamics.
    (*res)[0] = -Fx + S_ref*dynamicPressure*(Cx_alpha+Cx_el * elevator ); // Careful here assumed port added + Thrust ;
    (*res)[1] = -Fy - S_ref*dynamicPressure*(Cy_beta +Cy_rudder * rudder ); // check signs
    (*res)[2] = -Fz + S_ref*dynamicPressure*(Cz_alpha+Cz_el * elevator);
    
    return S_OK;
    //#]
}

HRESULT aeroDynamics::r_Mach(double * res) {
    //#[ operation r_Mach(double * ) 
    
       *res = -Mach + V/pAtmosphere.speedOfSound[0];
       return S_OK;
    //#]
}

HRESULT aeroDynamics::r_Moments(valarray<double>*  res) {
    //#[ operation r_Moments(valarray<double>*) 
    
     double dynamicPressure;
     double& Mx = p.moment[0];
     double& My = p.moment[1];
     double& Mz = p.moment[2];
     double& rp = p.rate[0];
     double& rq = p.rate[1];
     double& rr = p.rate[2];
    
       // pFin->pos is a valarray(3)
     double aileron	= pFin.angle[0]; // angle rotates around x-axis
     double elevator	= pFin.angle[1];	// angle rotates around y-axis
     double rudder	= pFin.angle[2]; // angle rotates around z-axis
    
     if (res->size() != 3) res->resize(3);
    
     dynamicPressure = 0.5 * V * V * pAtmosphere.airDensity[0];
     (*res)[0] = -Mx + d_ref*S_ref*dynamicPressure *
          (         Cl_al * aileron + Cl_p*rp);
     (*res)[1] = -My + d_ref*S_ref*dynamicPressure *
          (Cm_alpha+Cm_el * elevator + Cm_q*rq);
     (*res)[2] = -Mz + d_ref*S_ref*dynamicPressure *
          (Cn_beta+Cn_rudder * rudder + Cn_r*rr);
    
     return S_OK;
       //#]
    //#]
}

HRESULT aeroDynamics::r_SSA(double * res) {
    //#[ operation r_SSA(double * ) 
    // Side Slip Angle
    
    Vel& vel = p.velocity;	// Should use p.velocity - Gust.velocity
    // if (u == 0.0) u = 1.0e-15;
    *res = -SSA + atan2(vel[1],vel[0]);						// arctan(v/u)
    return S_OK;
    //#]
}

HRESULT aeroDynamics::r_V(double * res) {
    //#[ operation r_V(double * ) 
    
     Vel& vel = p.velocity;  // Should use p.velocity - Gust.velocity
    
     *res = -V + sqrt(dot(vel,vel));							// Speed
     return S_OK;
    //#]
}

aeroPort* aeroDynamics::getP() const {
    return (aeroPort*) &p;
}

AtmoPort* aeroDynamics::getPAtmosphere() const {
    return (AtmoPort*) &pAtmosphere;
}

FinPort* aeroDynamics::getPFin() const {
    return (FinPort*) &pFin;
}

OMBoolean aeroDynamics::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\aeroDynamics.cpp
*********************************************************************/

