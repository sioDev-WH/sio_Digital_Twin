/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: bodyDynamics
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\bodyDynamics.cpp
*********************************************************************/

#include <oxf/omthread.h>
#include "bodyDynamics.h"
#include "OnUMLEso.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// bodyDynamics.cpp                                                                  
//----------------------------------------------------------------------------
//## class bodyDynamics 



bodyDynamics::bodyDynamics(OMThread*  p_thread) {
    setThread(p_thread, FALSE);
    //#[ operation bodyDynamics() 
    init();
    invReady=false;
    //#]
}

bodyDynamics::~bodyDynamics() {
    //#[ operation ~bodyDynamics() 
    clean();
    //#]
}

HRESULT bodyDynamics::InitEqnForm(OnEqnForm**  form, OnEqnDiffForm**  diff_form) {
    //#[ operation InitEqnForm(OnEqnForm**,OnEqnDiffForm**) 
    
    
    const long idx_eqn_r_velocity = 0;
    const long idx_eqn_r_position = 1;
    const long idx_eqn_r_rate = 2;
    const long idx_eqn_r_euler = 3;
    
      DESTROY_VECTOR(*form)
      *form = new OnEqnForm[m_nLocalEqns];
      (*form)[idx_eqn_r_velocity] = continuous;
      (*form)[idx_eqn_r_position] = continuous;
      (*form)[idx_eqn_r_rate] = continuous;
      (*form)[idx_eqn_r_euler] = continuous;
    
      DESTROY_VECTOR(*diff_form)
      *diff_form = new OnEqnDiffForm[m_nLocalEqns];
      (*diff_form)[idx_eqn_r_velocity] = automatic;
      (*diff_form)[idx_eqn_r_position] = automatic;
      (*diff_form)[idx_eqn_r_rate] = automatic;
      (*diff_form)[idx_eqn_r_euler] = automatic;
    
      return S_OK;
    //#]
}

HRESULT bodyDynamics::InitEsos() {
    //#[ operation InitEsos() 
    
      ADD_LOCAL_ESO(&p)
    
      return S_OK;
    //#]
}

HRESULT bodyDynamics::InitLocalADEqns() {
    //#[ operation InitLocalADEqns() 
    
      ADD_LOCAL_STL_AD_EQN(bodyDynamics, ad_r_velocity, 1)
      ADD_LOCAL_STL_AD_EQN(bodyDynamics, ad_r_position, 1)
      ADD_LOCAL_STL_AD_EQN(bodyDynamics, ad_r_rate, 1)
      ADD_LOCAL_STL_AD_EQN(bodyDynamics, ad_r_euler, 1)
    
      return S_OK;
    //#]
}

HRESULT bodyDynamics::InitLocalEqns() {
    //#[ operation InitLocalEqns() 
    
      ADD_LOCAL_STL_EQN(bodyDynamics, r_velocity, 1)
      ADD_LOCAL_STL_EQN(bodyDynamics, r_position, 1)
      ADD_LOCAL_STL_EQN(bodyDynamics, r_rate, 1)
      ADD_LOCAL_STL_EQN(bodyDynamics, r_euler, 1)
    
      return S_OK;
    //#]
}

HRESULT bodyDynamics::InitLocalRPars(const _TCHAR*  prefix, ppdouble*  pars, ppchar*  Names, long*  nPars, long*  dPars) {
    //#[ operation InitLocalRPars(const _TCHAR*,ppdouble*,ppchar*,long*,long*) 
    
    
      ADD_LOCAL_SRPAR(mass)
    
      return S_OK;
    //#]
}

HRESULT bodyDynamics::InitLocalVars(const _TCHAR*  prefix, VarCont*  varC, const bool  bADOnly) {
    //#[ operation InitLocalVars(const _TCHAR*,VarCont*,const bool) 
    
    
    
    for (long i = 0; i < m_nEsos; i++)
      AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
      return S_OK;
    //#]
}

bool bodyDynamics::Load(FILE*  fs) {
    //#[ operation Load(FILE*) 
    
    return true;
    //#]
}

void bodyDynamics::Save(FILE*  fs) {
    //#[ operation Save(FILE*) 
    //#]
}

HRESULT bodyDynamics::ad_r_euler(valarray<Fdouble>*  res) {
    //#[ operation ad_r_euler(valarray<Fdouble>*) 
    // [phi,theta,psi]
    
    valarray<Fdouble> eulerRate;
    valarray<Fdouble>& rate = p.AD(rate);
    valarray<Fdouble>& angleDot = p.DER_AD(angle);
    
    BodyRate2EulerRate(rate, angleDot, eulerRate);
    
    if (res->size() != 3) res->resize(3);
    
    (*res) = angleDot - eulerRate;					// Inertial Coordinates
    return S_OK;
    //#]
}

HRESULT bodyDynamics::ad_r_position(valarray<Fdouble>*  res) {
    //#[ operation ad_r_position(valarray<Fdouble>*) 
    // [x,y,z]
    
    valarray<Fdouble> positionDot;
    valarray<Fdouble>& velocity = p.AD(velocity);
    valarray<Fdouble>& angle = p.AD(angle);
    
    if (res->size() != 3) res->resize(3);
    
    B2I(velocity, angle, positionDot);
    (*res) = p.DER_AD(position) - positionDot;						// Inertial Coordinates
    return S_OK;
    //#]
}

HRESULT bodyDynamics::ad_r_rate(valarray<Fdouble>*  res) {
    //#[ operation ad_r_rate(valarray<Fdouble>*) 
    // [p,q,r]
    
    valarray<Fdouble>& rateDot = p.DER_AD(rate);
    valarray<Fdouble>& moment = p.AD(moment);
    valarray<Fdouble>& rate	= p.AD(rate);
    
    if (res->size() != 3) res->resize(3);
    
    // Body Coordinates
    (*res) = - rateDot + product(invInertia, (valarray<Fdouble>&) ((-moment) - cross(p.AD(rate),product(inertia,rate))));
    
    return S_OK;
    //#]
}

HRESULT bodyDynamics::ad_r_velocity(valarray<Fdouble>*  res) {
    //#[ operation ad_r_velocity(valarray<Fdouble>*) 
    // [u,v,w]
    
    valarray<Fdouble>& acc = p.DER_AD(velocity);
    
    
    valarray<Fdouble>& force = p.AD(force);
    valarray<Fdouble>& rate = p.AD(rate);									// Body Coordinates
    valarray<Fdouble>& angle = p.AD(angle);
    
    if (res->size() != 3) res->resize(3);
    
    // KAB
    //(*res) = - acc - force/mass + cross(p.AD(velocity),rate);
    (*res) = - acc - div(force, mass) + cross(p.AD(velocity),rate);
    
    return S_OK;
    //#]
}

void bodyDynamics::clean() {
    //#[ operation clean() 
    //#]
}

void bodyDynamics::getAccel(const double t, double * val) {
    //#[ operation getAccel(const double ,double * ) 
    double Fz = 0.0;
    double der_q = 0.0;
    double accPos = 0.5;  
    double angle = 0.0;
    
    GET_VARIABLE_VALUE(L"&p.force[2]", t, &Fz)
    GET_VARIABLE_DER_VALUE(L"&p.rate[1]", t, &der_q)
    GET_VARIABLE_VALUE(L"&p.angle[1]", t, &angle)
    
    *val = -Fz / mass  - der_q * accPos - 9.81 * cos(angle); //theta
    
    //#]
}

void bodyDynamics::getAttitude(const double t, double * val) {
    //#[ operation getAttitude(const double ,double * ) 
    GET_VARIABLE_VALUE(L"&p.angle[1]", t, val)
    
    //#]
}

void bodyDynamics::getGyro(const double t, double * val) {
    //#[ operation getGyro(const double ,double * ) 
    GET_VARIABLE_VALUE(L"&p.rate[1]", t, val)
    //#]
}

void bodyDynamics::getX(const double t, double * val) {
    //#[ operation getX(const double ,double * ) 
    GET_VARIABLE_VALUE(L"&p.position[0]", t, val)
    
    //#]
}

void bodyDynamics::getZ(const double t, double * val) {
    //#[ operation getZ(const double ,double * ) 
    GET_VARIABLE_VALUE(L"&p.position[2]", t, val)
    
    //#]
}

void bodyDynamics::handle_mass(const double  t, const double*  val) {
    //#[ operation handle_mass(const double,const double*) 
    
    PostRealParameter(t, 0, *val);
    //#]
}

void bodyDynamics::init() {
    //#[ operation init() 
    #define Kg2slug 0.0685218
    #define m2ft 3.280840
    
    
    
    //WAH
    for(int i=0;i<inertia.RowNo();i++)
    	for(int j=0;j<inertia.ColNo();j++) 
        inertia(i,j)=0.0;
    
    
    inertia(0,0) = 1.0; // x
    inertia(1,1) = 182.5/(Kg2slug*m2ft*m2ft); // y
    inertia(2,2) = 1.0; // z
    
    // WAH
    Matrix temp=inertia;
    invInertia = temp.Inv();
    invReady = true;
    
    mass = 13.98/Kg2slug;
    // accPos = 0.5;  
    
    p.velocity[0] = 984.0; // u
    
    p.position[2] = -10000/m2ft;
    //#]
}

HRESULT bodyDynamics::r_euler(valarray<double>*  res) {
    //#[ operation r_euler(valarray<double>*) 
    // [phi,theta,psi]
    
    RotVel eulerRate;
    RotVel& rate = p.rate;
    valarray<double>& angleDot = p.DER(angle);
    
    BodyRate2EulerRate(rate, angleDot, eulerRate);
    
    if (res->size() != 3) res->resize(3);
    
    (*res) = angleDot - eulerRate;					// Inertial Coordinates
    return S_OK;
    //#]
}

HRESULT bodyDynamics::r_position(valarray<double>*  res) {
    //#[ operation r_position(valarray<double>*) 
    // [x,y,z]
    
    Vel positionDot;
    Vel& velocity = p.velocity;
    Angle& angle = p.angle;
    
    if (res->size() != 3) res->resize(3);
    
    B2I(velocity, angle, positionDot);
    (*res) = p.DER(position) - positionDot;						// Inertial Coordinates
    return S_OK;
    //#]
}

HRESULT bodyDynamics::r_rate(valarray<double>*  res) {
    //#[ operation r_rate(valarray<double>*) 
    // [p,q,r]
    
    valarray<double>& rateDot = p.DER(rate);
    Moment& moment = p.moment;
    RotVel& rate	= p.rate;
    
    if (res->size() != 3) res->resize(3);
    
    // Body Coordinates
    (*res) = - rateDot + product(invInertia, (OnStlVec<double>&) ((-moment) - cross(p.rate,product(inertia,rate))));
    
    return S_OK;
    //#]
}

HRESULT bodyDynamics::r_velocity(valarray<double>*  res) {
    //#[ operation r_velocity(valarray<double>*) 
    // [u,v,w]
    
    valarray<double>& acc = p.DER(velocity);
    
    
    Force& force = p.force;
    RotVel& rate = p.rate;									// Body Coordinates
    Angle& angle = p.angle;
    
    if (res->size() != 3) res->resize(3);
    
    (*res) = - acc - force/mass + cross(p.velocity,rate);
    
    return S_OK;
    //#]
}

aeroInertia<double>  bodyDynamics::getInertia() const {
    return inertia;
}

void bodyDynamics::setInertia(aeroInertia<double> p_inertia) {
    inertia = p_inertia;
}

Matrix bodyDynamics::getInvInertia() const {
    return invInertia;
}

void bodyDynamics::setInvInertia(Matrix  p_invInertia) {
    invInertia = p_invInertia;
}

bool  bodyDynamics::getInvReady() const {
    return invReady;
}

void bodyDynamics::setInvReady(bool p_invReady) {
    invReady = p_invReady;
}

double bodyDynamics::getMass() const {
    return mass;
}

void bodyDynamics::setMass(double  p_mass) {
    mass = p_mass;
}

aeroPort* bodyDynamics::getP() const {
    return (aeroPort*) &p;
}

OMBoolean bodyDynamics::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\bodyDynamics.cpp
*********************************************************************/

