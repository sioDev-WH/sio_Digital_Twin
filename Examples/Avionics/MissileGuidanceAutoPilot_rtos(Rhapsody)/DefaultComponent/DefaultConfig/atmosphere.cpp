/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: atmosphere
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\atmosphere.cpp
*********************************************************************/

#include <oxf/omthread.h>
#include "atmosphere.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// atmosphere.cpp                                                                  
//----------------------------------------------------------------------------
//## class atmosphere 



atmosphere::atmosphere(OMThread*  p_thread) {
    setThread(p_thread, FALSE);
    //#[ operation atmosphere() 
    init();
    //#]
}

atmosphere::~atmosphere() {
    //#[ operation ~atmosphere() 
    clean();
    //#]
}

HRESULT atmosphere::InitEqnForm(OnEqnForm**  form, OnEqnDiffForm**  diff_form) {
    //#[ operation InitEqnForm(OnEqnForm**,OnEqnDiffForm**) 
    
    
    const long idx_eqn_r_airDensity = 0;
    const long idx_eqn_r_speedOfSound = 1;
    
      DESTROY_VECTOR(*form)
      *form = new OnEqnForm[m_nLocalEqns];
      (*form)[idx_eqn_r_airDensity] = continuous;
      (*form)[idx_eqn_r_speedOfSound] = continuous;
    
      DESTROY_VECTOR(*diff_form)
      *diff_form = new OnEqnDiffForm[m_nLocalEqns];
      (*diff_form)[idx_eqn_r_airDensity] = automatic;
      (*diff_form)[idx_eqn_r_speedOfSound] = automatic;
    
      return S_OK;
    //#]
}

HRESULT atmosphere::InitEsos() {
    //#[ operation InitEsos() 
    
      ADD_LOCAL_ESO(&pAtmo)
      ADD_LOCAL_ESO(&ph)
    
      return S_OK;
    //#]
}

HRESULT atmosphere::InitLocalADEqns() {
    //#[ operation InitLocalADEqns() 
    
      ADD_LOCAL_AD_EQN(atmosphere, ad_r_airDensity)
      ADD_LOCAL_AD_EQN(atmosphere, ad_r_speedOfSound)
    
      return S_OK;
    //#]
}

HRESULT atmosphere::InitLocalEqns() {
    //#[ operation InitLocalEqns() 
    
      ADD_LOCAL_EQN(atmosphere, r_airDensity)
      ADD_LOCAL_EQN(atmosphere, r_speedOfSound)
    
      return S_OK;
    //#]
}

HRESULT atmosphere::InitLocalRPars(const _TCHAR*  prefix, ppdouble*  pars, ppchar*  Names, long*  nPars, long*  dPars) {
    //#[ operation InitLocalRPars(const _TCHAR*,ppdouble*,ppchar*,long*,long*) 
    
    
      ADD_LOCAL_SRPAR(seaLevelTemperature)
      ADD_LOCAL_SRPAR(seaLevelPressure)
      ADD_LOCAL_SRPAR(seaLevelDensity)
      ADD_LOCAL_SRPAR(lapseRate)
      ADD_LOCAL_SRPAR(R)
      ADD_LOCAL_SRPAR(specificHeatRatio)
      ADD_LOCAL_SRPAR(troposphere)
      ADD_LOCAL_SRPAR(maxHeightRange)
      ADD_LOCAL_SRPAR(gravity)
    
      return S_OK;
    //#]
}

HRESULT atmosphere::InitLocalVars(const _TCHAR*  prefix, VarCont*  varC, const bool  bADOnly) {
    //#[ operation InitLocalVars(const _TCHAR*,VarCont*,const bool) 
    
    
    
    for (long i = 0; i < m_nEsos; i++)
      AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
      return S_OK;
    //#]
}

bool atmosphere::Load(FILE*  fs) {
    //#[ operation Load(FILE*) 
    
    return true;
    //#]
}

void atmosphere::Save(FILE*  fs) {
    //#[ operation Save(FILE*) 
    //#]
}

HRESULT atmosphere::ad_r_airDensity(Fdouble*  res) {
    //#[ operation ad_r_airDensity(Fdouble*) 
    
    Fdouble h = (- ph.AD(height)[0]);
    if (h < 0) h = 0.0;
    if (h > troposphere) h = troposphere;
    
    Fdouble temperature = seaLevelTemperature - lapseRate * h;
    Fdouble temperatureRatio = temperature / seaLevelTemperature;
    if (temperatureRatio < 0.0) temperatureRatio = -1.0 * temperatureRatio;
    Fdouble temp1 = pow(temperatureRatio, gravity / lapseRate / R);
    Fdouble temp2 = temp1 / temperatureRatio;
    temp1 *= seaLevelPressure;
    temp2 *= seaLevelDensity;
    
    // Saturation block [troposphere - maxHeightRange,0]
    h = (- ph.AD(height)[0]) - troposphere;
    if (h < 0) h = 0.0;
    if (h > maxHeightRange) h = maxHeightRange;
    
    Fdouble temp3 = exp( h * gravity / R / temperature);
    
    *res = pAtmo.AD(airDensity)[0] - temp2 * temp3;
    
    return S_OK;
    
    //#]
}

HRESULT atmosphere::ad_r_speedOfSound(Fdouble*  res) {
    //#[ operation ad_r_speedOfSound(Fdouble*) 
    
    Fdouble h = (- ph.AD(height)[0]);
    if (h < 0) h = 0.0;
    if (h > troposphere) h = troposphere;
    
    Fdouble temperature = seaLevelTemperature - lapseRate * h;
    *res = pAtmo.AD(speedOfSound)[0] - sqrt(specificHeatRatio * R * temperature);
    return S_OK;
    
    //#]
}

void atmosphere::clean() {
    //#[ operation clean() 
    //#]
}

void atmosphere::handle_R(const double  t, const double*  val) {
    //#[ operation handle_R(const double,const double*) 
    
    PostRealParameter(t, 4, *val);
    //#]
}

void atmosphere::handle_gravity(const double  t, const double*  val) {
    //#[ operation handle_gravity(const double,const double*) 
    
    PostRealParameter(t, 8, *val);
    //#]
}

void atmosphere::handle_lapseRate(const double  t, const double*  val) {
    //#[ operation handle_lapseRate(const double,const double*) 
    
    PostRealParameter(t, 3, *val);
    //#]
}

void atmosphere::handle_maxHeightRange(const double  t, const double*  val) {
    //#[ operation handle_maxHeightRange(const double,const double*) 
    
    PostRealParameter(t, 7, *val);
    //#]
}

void atmosphere::handle_seaLevelDensity(const double  t, const double*  val) {
    //#[ operation handle_seaLevelDensity(const double,const double*) 
    
    PostRealParameter(t, 2, *val);
    //#]
}

void atmosphere::handle_seaLevelPressure(const double  t, const double*  val) {
    //#[ operation handle_seaLevelPressure(const double,const double*) 
    
    PostRealParameter(t, 1, *val);
    //#]
}

void atmosphere::handle_seaLevelTemperature(const double  t, const double*  val) {
    //#[ operation handle_seaLevelTemperature(const double,const double*) 
    
    PostRealParameter(t, 0, *val);
    //#]
}

void atmosphere::handle_specificHeatRatio(const double  t, const double*  val) {
    //#[ operation handle_specificHeatRatio(const double,const double*) 
    
    PostRealParameter(t, 5, *val);
    //#]
}

void atmosphere::handle_troposphere(const double  t, const double*  val) {
    //#[ operation handle_troposphere(const double,const double*) 
    
    PostRealParameter(t, 6, *val);
    //#]
}

void atmosphere::init() {
    //#[ operation init() 
    #define m2ft 3.280840
    
    ph.height[0] = 10000/m2ft;
    seaLevelTemperature=288.16;
    seaLevelPressure=101325.0;	
    seaLevelDensity=1.225;
    lapseRate=0.0065;
    R=287.26;
    specificHeatRatio=1.403;
    troposphere=11000.0/m2ft;
    maxHeightRange = 20000/m2ft;
    gravity = 9.81;
    
    double h = ph.height[0];
    if (h < 0) h = 0.0;
    if (h > troposphere) h = troposphere;
    
    double temperature = seaLevelTemperature - lapseRate * h;
    double temperatureRatio = temperature / seaLevelTemperature;
    double temp1 = pow(temperatureRatio, gravity / lapseRate / R);
    double temp2 = temp1 / temperatureRatio;
    temp1 *= seaLevelPressure;
    temp2 *= seaLevelDensity;
    
    pAtmo.speedOfSound[0] = sqrt(specificHeatRatio * R * temperature);
    
    // Saturation block [troposphere - maxHeightRange,0]
    h = ph.height[0] - troposphere;
    if (h < 0) h = 0.0;
    if (h > maxHeightRange) h = maxHeightRange;
    
    double temp3 = exp( h * gravity / R / temperature);
    
    pAtmo.airDensity[0] = temp2 * temp3;
    //#]
}

HRESULT atmosphere::r_airDensity(double * res) {
    //#[ operation r_airDensity(double * ) 
    double h = (- ph.height[0]);
    if (h < 0) h = 0.0;
    if (h > troposphere) h = troposphere;
    
    double temperature = seaLevelTemperature - lapseRate * h;
    double temperatureRatio = temperature / seaLevelTemperature;
    if (temperatureRatio < 0.0) temperatureRatio = -1.0 * temperatureRatio;
    double temp1 = pow(temperatureRatio, gravity / lapseRate / R);
    double temp2 = temp1 / temperatureRatio;
    temp1 *= seaLevelPressure;
    temp2 *= seaLevelDensity;
    
    // Saturation block [troposphere - maxHeightRange,0]
    h = (- ph.height[0]) - troposphere;
    if (h < 0) h = 0.0;
    if (h > maxHeightRange) h = maxHeightRange;
    
    double temp3 = exp( h * gravity / R / temperature);
    
    *res = pAtmo.airDensity[0] - temp2 * temp3;
    
    return S_OK;
    //#]
}

HRESULT atmosphere::r_speedOfSound(double * res) {
    //#[ operation r_speedOfSound(double * ) 
    double h = (- ph.height[0]);
    if (h < 0) h = 0.0;
    if (h > troposphere) h = troposphere;
    
    double temperature = seaLevelTemperature - lapseRate * h;
    *res = pAtmo.speedOfSound[0] - sqrt(specificHeatRatio * R * temperature);
    return S_OK;
    //#]
}

double atmosphere::getR() const {
    return R;
}

void atmosphere::setR(double  p_R) {
    R = p_R;
}

double atmosphere::getGravity() const {
    return gravity;
}

void atmosphere::setGravity(double  p_gravity) {
    gravity = p_gravity;
}

double atmosphere::getLapseRate() const {
    return lapseRate;
}

void atmosphere::setLapseRate(double  p_lapseRate) {
    lapseRate = p_lapseRate;
}

double atmosphere::getMaxHeightRange() const {
    return maxHeightRange;
}

void atmosphere::setMaxHeightRange(double  p_maxHeightRange) {
    maxHeightRange = p_maxHeightRange;
}

double atmosphere::getSeaLevelDensity() const {
    return seaLevelDensity;
}

void atmosphere::setSeaLevelDensity(double  p_seaLevelDensity) {
    seaLevelDensity = p_seaLevelDensity;
}

double atmosphere::getSeaLevelPressure() const {
    return seaLevelPressure;
}

void atmosphere::setSeaLevelPressure(double  p_seaLevelPressure) {
    seaLevelPressure = p_seaLevelPressure;
}

double atmosphere::getSeaLevelTemperature() const {
    return seaLevelTemperature;
}

void atmosphere::setSeaLevelTemperature(double  p_seaLevelTemperature) {
    seaLevelTemperature = p_seaLevelTemperature;
}

double atmosphere::getSpecificHeatRatio() const {
    return specificHeatRatio;
}

void atmosphere::setSpecificHeatRatio(double  p_specificHeatRatio) {
    specificHeatRatio = p_specificHeatRatio;
}

double atmosphere::getTroposphere() const {
    return troposphere;
}

void atmosphere::setTroposphere(double  p_troposphere) {
    troposphere = p_troposphere;
}

AtmoPort* atmosphere::getPAtmo() const {
    return (AtmoPort*) &pAtmo;
}

AtmoHeightPort* atmosphere::getPh() const {
    return (AtmoHeightPort*) &ph;
}

OMBoolean atmosphere::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\atmosphere.cpp
*********************************************************************/

