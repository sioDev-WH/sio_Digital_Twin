/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Vehicle
//!	Generated Date	: Thu, 9, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Vehicle.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "Vehicle.h"
#include "CRigidConnector.h"
#include "stdafx.h"
#include "math.h"

//## package VehicleModels 


//#[ ignore 
#define VehicleModels_Vehicle_Vehicle_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle_InitEqnForm_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle_InitEsos_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle_InitLocalADEqns_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle_InitLocalEqns_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle_InitLocalRPars_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle_InitLocalVars_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle_Load_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle_Save_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle_clean_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle_handle_aerodynamicDrag_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle_handle_brakeTorque_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle_handle_finalDriveRatio_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle_handle_vehicleInertia_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle_handle_wheelFrictionDrag_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle_handle_wheelRadius_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// Vehicle.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(VehicleModels)
//## class Vehicle 



Vehicle::Vehicle() {
    NOTIFY_CONSTRUCTOR(Vehicle, Vehicle(), 0, VehicleModels_Vehicle_Vehicle_SERIALIZE);
    p = NULL;
    //#[ operation Vehicle() 
    init();
    //#]
}

Vehicle::~Vehicle() {
    NOTIFY_DESTRUCTOR(~Vehicle, TRUE);
    //#[ operation ~Vehicle() 
    clean();
    //#]
    cleanUpRelations();
}

HRESULT Vehicle::InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form) {
    NOTIFY_OPERATION(InitEqnForm, InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ), 0, VehicleModels_Vehicle_InitEqnForm_SERIALIZE);
    //#[ operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
    
    const long idx_eqn_r_Newton = 0;
    const long idx_eqn_r_Speed = 1;
    const long idx_eqn_r_wheelSpeed = 2;
    
      DESTROY_VECTOR(*form)
      *form = new OnEqnForm[m_nLocalEqns];
      (*form)[idx_eqn_r_Newton] = continuous;
      (*form)[idx_eqn_r_Speed] = continuous;
      (*form)[idx_eqn_r_wheelSpeed] = continuous;
    
      DESTROY_VECTOR(*diff_form)
      *diff_form = new OnEqnDiffForm[m_nLocalEqns];
      (*diff_form)[idx_eqn_r_Newton] = automatic;
      (*diff_form)[idx_eqn_r_Speed] = automatic;
      (*diff_form)[idx_eqn_r_wheelSpeed] = automatic;
    
      return S_OK;
    
    //#]
}

HRESULT Vehicle::InitEsos() {
    NOTIFY_OPERATION(InitEsos, InitEsos(), 0, VehicleModels_Vehicle_InitEsos_SERIALIZE);
    //#[ operation InitEsos() 
      ADD_LOCAL_ESO(p)
    
      return S_OK;
    
    //#]
}

HRESULT Vehicle::InitLocalADEqns() {
    NOTIFY_OPERATION(InitLocalADEqns, InitLocalADEqns(), 0, VehicleModels_Vehicle_InitLocalADEqns_SERIALIZE);
    //#[ operation InitLocalADEqns() 
      ADD_LOCAL_AD_EQN(Vehicle, ad_r_Newton)
      ADD_LOCAL_AD_EQN(Vehicle, ad_r_Speed)
      ADD_LOCAL_AD_EQN(Vehicle, ad_r_wheelSpeed)
    
      return S_OK;
    
    //#]
}

HRESULT Vehicle::InitLocalEqns() {
    NOTIFY_OPERATION(InitLocalEqns, InitLocalEqns(), 0, VehicleModels_Vehicle_InitLocalEqns_SERIALIZE);
    //#[ operation InitLocalEqns() 
      ADD_LOCAL_EQN(Vehicle, r_Newton)
      ADD_LOCAL_EQN(Vehicle, r_Speed)
      ADD_LOCAL_EQN(Vehicle, r_wheelSpeed)
    
      return S_OK;
    
    //#]
}

HRESULT Vehicle::InitLocalRPars(const _TCHAR * prefix, ppdouble * pars, ppchar * Names, long * nPars, long * dPars) {
    NOTIFY_OPERATION(InitLocalRPars, InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ), 0, VehicleModels_Vehicle_InitLocalRPars_SERIALIZE);
    //#[ operation InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ) 
      ADD_LOCAL_SRPAR(finalDriveRatio)
      ADD_LOCAL_SRPAR(wheelRadius)
      ADD_LOCAL_SRPAR(vehicleInertia)
      ADD_LOCAL_SRPAR(wheelFrictionDrag)
      ADD_LOCAL_SRPAR(aerodynamicDrag)
      ADD_LOCAL_SRPAR(brakeTorque)
    
      return S_OK;
    
    //#]
}

HRESULT Vehicle::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    NOTIFY_OPERATION(InitLocalVars, InitLocalVars(const _TCHAR * ,VarCont * ,const bool ), 0, VehicleModels_Vehicle_InitLocalVars_SERIALIZE);
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
      ADD_LOCAL_SVAR(wheelSpeed)
      ADD_LOCAL_SVAR(speed)
    
     for (long i = 0; i < m_nEsos; i++)
       AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
      return S_OK;
    
    //#]
}

bool Vehicle::Load(FILE * fs) {
    NOTIFY_OPERATION(Load, Load(FILE * ), 0, VehicleModels_Vehicle_Load_SERIALIZE);
    //#[ operation Load(FILE * ) 
    return true;
    //#]
}

void Vehicle::Save(FILE * fs) {
    NOTIFY_OPERATION(Save, Save(FILE * ), 0, VehicleModels_Vehicle_Save_SERIALIZE);
    //#[ operation Save(FILE * ) 
    //#]
}

HRESULT Vehicle::ad_r_Newton(Fdouble * res) {
    //#[ operation ad_r_Newton(Fdouble * ) 
    *res = p->AD(torque) * finalDriveRatio 
             - (vehicleInertia * (p->AD(acceleration) / finalDriveRatio) + 
                brakeTorque * 10.0 +
                wheelFrictionDrag +
                aerodynamicDrag * AD(speed) * AD(speed));
    return S_OK;
    
    //#]
}

HRESULT Vehicle::ad_r_Speed(Fdouble * res) {
    //#[ operation ad_r_Speed(Fdouble * ) 
    #define PI 3.1415926535897932384626433832795
    #define RPM2KMPH 1.13636363636363636363636363636e-2
    *res = AD(speed) - 2.0*PI*wheelRadius *RPM2KMPH* AD(wheelSpeed);
    return S_OK;
    
    //#]
}

HRESULT Vehicle::ad_r_wheelSpeed(Fdouble * res) {
    //#[ operation ad_r_wheelSpeed(Fdouble * ) 
    #define PI 3.1415926535897932384626433832795
    
      *res = DER_AD(wheelSpeed) - (60.0 / (2.0 * PI)) * (p->AD(acceleration) / finalDriveRatio);
    return S_OK;
    
    //#]
}

void Vehicle::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, VehicleModels_Vehicle_clean_SERIALIZE);
    //#[ operation clean() 
      p->Release();
    
    //#]
}

void Vehicle::handle_aerodynamicDrag(const double t, const double * val) {
    NOTIFY_OPERATION(handle_aerodynamicDrag, handle_aerodynamicDrag(const double ,const double * ), 0, VehicleModels_Vehicle_handle_aerodynamicDrag_SERIALIZE);
    //#[ operation handle_aerodynamicDrag(const double ,const double * ) 
    PostRealParameter(t, 4, *val);
    
    //#]
}

void Vehicle::handle_brakeTorque(const double t, const double * val) {
    NOTIFY_OPERATION(handle_brakeTorque, handle_brakeTorque(const double ,const double * ), 0, VehicleModels_Vehicle_handle_brakeTorque_SERIALIZE);
    //#[ operation handle_brakeTorque(const double ,const double * ) 
    PostRealParameter(t, 5, *val);
    //#]
}

void Vehicle::handle_finalDriveRatio(const double t, const double * val) {
    NOTIFY_OPERATION(handle_finalDriveRatio, handle_finalDriveRatio(const double ,const double * ), 0, VehicleModels_Vehicle_handle_finalDriveRatio_SERIALIZE);
    //#[ operation handle_finalDriveRatio(const double ,const double * ) 
    PostRealParameter(t, 0, *val);
    
    //#]
}

void Vehicle::handle_vehicleInertia(const double t, const double * val) {
    NOTIFY_OPERATION(handle_vehicleInertia, handle_vehicleInertia(const double ,const double * ), 0, VehicleModels_Vehicle_handle_vehicleInertia_SERIALIZE);
    //#[ operation handle_vehicleInertia(const double ,const double * ) 
    PostRealParameter(t, 2, *val);
    
    //#]
}

void Vehicle::handle_wheelFrictionDrag(const double t, const double * val) {
    NOTIFY_OPERATION(handle_wheelFrictionDrag, handle_wheelFrictionDrag(const double ,const double * ), 0, VehicleModels_Vehicle_handle_wheelFrictionDrag_SERIALIZE);
    //#[ operation handle_wheelFrictionDrag(const double ,const double * ) 
    PostRealParameter(t, 3, *val);
    
    //#]
}

void Vehicle::handle_wheelRadius(const double t, const double * val) {
    NOTIFY_OPERATION(handle_wheelRadius, handle_wheelRadius(const double ,const double * ), 0, VehicleModels_Vehicle_handle_wheelRadius_SERIALIZE);
    //#[ operation handle_wheelRadius(const double ,const double * ) 
    PostRealParameter(t, 1, *val);
    
    //#]
}

void Vehicle::init() {
    NOTIFY_OPERATION(init, init(), 0, VehicleModels_Vehicle_init_SERIALIZE);
    //#[ operation init() 
      p = new CRigidConnector();
      p->AddRef();
    wheelSpeed = 0.0;
    DER(wheelSpeed) = 0.0;
    speed = 0.0;
    DER(speed) = 0.0;
    
    #define PI 3.1415926535897932384626433832795
    
    aerodynamicDrag = 0.02;
    brakeTorque = 0.0;
    finalDriveRatio = 3.23;
    vehicleInertia = 12.0941 * (60.0 / (2.0 * PI));
    wheelFrictionDrag = 40.0;
    wheelRadius = 1.0;
    
    //#]
}

HRESULT Vehicle::r_Newton(double * res) {
    //#[ operation r_Newton(double * ) 
    *res = p->torque * finalDriveRatio 
             - (vehicleInertia * (p->acceleration / finalDriveRatio) + 
                brakeTorque * 10.0 +
                wheelFrictionDrag +
                aerodynamicDrag * speed * speed);
    return S_OK;
    
    //#]
}

HRESULT Vehicle::r_Speed(double * res) {
    //#[ operation r_Speed(double * ) 
    #define PI 3.1415926535897932384626433832795
    #define RPM2KMPH 1.13636363636363636363636363636e-2
    *res = speed - 2.0*PI*wheelRadius *RPM2KMPH* wheelSpeed;
    return S_OK;
    
    //#]
}

HRESULT Vehicle::r_wheelSpeed(double * res) {
    //#[ operation r_wheelSpeed(double * ) 
    #define PI 3.1415926535897932384626433832795
    
      *res = DER(wheelSpeed) - (60.0 / (2.0 * PI)) * (p->acceleration / finalDriveRatio);
    return S_OK;
    
    //#]
}

VarEx Vehicle::get_speed() const {
    return _speed;
}

void Vehicle::set_speed(VarEx  p__speed) {
    _speed = p__speed;
}

VarEx Vehicle::get_wheelSpeed() const {
    return _wheelSpeed;
}

void Vehicle::set_wheelSpeed(VarEx  p__wheelSpeed) {
    _wheelSpeed = p__wheelSpeed;
}

double Vehicle::getAerodynamicDrag() const {
    return aerodynamicDrag;
}

void Vehicle::setAerodynamicDrag(double  p_aerodynamicDrag) {
    aerodynamicDrag = p_aerodynamicDrag;
}

double Vehicle::getBrakeTorque() const {
    return brakeTorque;
}

void Vehicle::setBrakeTorque(double  p_brakeTorque) {
    brakeTorque = p_brakeTorque;
}

double Vehicle::getFinalDriveRatio() const {
    return finalDriveRatio;
}

void Vehicle::setFinalDriveRatio(double  p_finalDriveRatio) {
    finalDriveRatio = p_finalDriveRatio;
}

double Vehicle::getSpeed() const {
    return speed;
}

void Vehicle::setSpeed(double  p_speed) {
    speed = p_speed;
}

double Vehicle::getVehicleInertia() const {
    return vehicleInertia;
}

void Vehicle::setVehicleInertia(double  p_vehicleInertia) {
    vehicleInertia = p_vehicleInertia;
}

double Vehicle::getWheelFrictionDrag() const {
    return wheelFrictionDrag;
}

void Vehicle::setWheelFrictionDrag(double  p_wheelFrictionDrag) {
    wheelFrictionDrag = p_wheelFrictionDrag;
}

double Vehicle::getWheelRadius() const {
    return wheelRadius;
}

void Vehicle::setWheelRadius(double  p_wheelRadius) {
    wheelRadius = p_wheelRadius;
}

double Vehicle::getWheelSpeed() const {
    return wheelSpeed;
}

void Vehicle::setWheelSpeed(double  p_wheelSpeed) {
    wheelSpeed = p_wheelSpeed;
}

CRigidConnector* Vehicle::getP() const {
    return p;
}

void Vehicle::setP(CRigidConnector*  p_CRigidConnector) {
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

void Vehicle::cleanUpRelations() {
    if(p != NULL)
        {
            NOTIFY_RELATION_CLEARED("p");
            p = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedVehicle::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedVehicle::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("p", FALSE, TRUE);
    if(myReal->p)
        aomsRelations->ADD_ITEM(myReal->p);
}

IMPLEMENT_META(Vehicle, VehicleModels, FALSE, OMAnimatedVehicle)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Vehicle.cpp
*********************************************************************/

