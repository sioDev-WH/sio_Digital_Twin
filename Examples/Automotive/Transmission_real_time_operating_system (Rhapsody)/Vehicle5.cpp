/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Vehicle5
//!	Generated Date	: Thu, 9, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Vehicle5.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 
//#]

#include "Vehicle5.h"
#include "BrakeActuator.h"
#include "CFrame.h"
#include "Clutch.h"
#include "CRigidConnector.h"
#include "stdafx.h"
#include "math.h"
#include "OnUMLEso.h"

//## package VehicleModels 


//#[ ignore 
#define VehicleModels_Vehicle5_Vehicle5_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle5_GetAssociations_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle5_InitEqnForm_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle5_InitEsos_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle5_InitLocalADEqns_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle5_InitLocalEqns_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle5_InitLocalRPars_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle5_InitLocalVars_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle5_Load_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle5_Save_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle5_clean_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle5_getSpeed_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle5_handle_aerodynamicDrag_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle5_handle_brakePedal_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle5_handle_finalDriveRatio_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle5_handle_vehicleInertia_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle5_handle_wheelFrictionDrag_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle5_handle_wheelRadius_SERIALIZE OM_NO_OP


#define VehicleModels_Vehicle5_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// Vehicle5.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(VehicleModels)
//## class Vehicle5 



Vehicle5::Vehicle5() {
    NOTIFY_CONSTRUCTOR(Vehicle5, Vehicle5(), 0, VehicleModels_Vehicle5_Vehicle5_SERIALIZE);
    Brake = NULL;
    aBrakeActuator = NULL;
    gBrake = NULL;
    p = NULL;
    //#[ operation Vehicle5() 
    init();
    //#]
}

Vehicle5::~Vehicle5() {
    NOTIFY_DESTRUCTOR(~Vehicle5, TRUE);
    //#[ operation ~Vehicle5() 
    clean();
    //#]
    cleanUpRelations();
}

HRESULT Vehicle5::GetAssociations(long * * Assoc, long * * Size, long * nSize) {
    NOTIFY_OPERATION(GetAssociations, GetAssociations(long * * ,long * * ,long * ), 0, VehicleModels_Vehicle5_GetAssociations_SERIALIZE);
    //#[ operation GetAssociations(long * * ,long * * ,long * ) 
    
    long nAssoc;
    long i;
    
    //ADD_LOCAL_ESO(p)               // 0 - physics-based connector
    //ADD_LOCAL_ESO(aBrakeActuator)  // 1, 0 - pressure
    //ADD_LOCAL_ESO(gBrake)          // 2, 0 - frame connection
    //ADD_LOCAL_ESO(Brake)           // 3, 0 - pressure, 1 - n, 2 - p
    
    const long assoc[] =
    {
      0,          3, 2,
      1, 0,       3, 0,
      2, 0,       3, 1,
    };
    
    const long size[] =
    {
      1, 2,
      2, 2,
      2, 2,
    };
    
    *nSize = sizeof(size) / sizeof(long);
    nAssoc = sizeof(assoc) / sizeof(long);
    
    *Size = new long[*nSize];
    *Assoc = new long[nAssoc];
    
    for (i = 0; i < *nSize; i++) (*Size)[i] = size[i];
    for (i = 0; i < nAssoc; i++) (*Assoc)[i] = assoc[i];
    
    return S_OK;
    //#]
}

HRESULT Vehicle5::InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form) {
    NOTIFY_OPERATION(InitEqnForm, InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ), 0, VehicleModels_Vehicle5_InitEqnForm_SERIALIZE);
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

HRESULT Vehicle5::InitEsos() {
    NOTIFY_OPERATION(InitEsos, InitEsos(), 0, VehicleModels_Vehicle5_InitEsos_SERIALIZE);
    //#[ operation InitEsos() 
    ADD_LOCAL_ESO(p)
    ADD_LOCAL_ESO(aBrakeActuator)
    ADD_LOCAL_ESO(gBrake)
    ADD_LOCAL_ESO(Brake)
    
    return S_OK;
    //#]
}

HRESULT Vehicle5::InitLocalADEqns() {
    NOTIFY_OPERATION(InitLocalADEqns, InitLocalADEqns(), 0, VehicleModels_Vehicle5_InitLocalADEqns_SERIALIZE);
    //#[ operation InitLocalADEqns() 
    
      ADD_LOCAL_AD_EQN(Vehicle5, ad_r_Newton)
      ADD_LOCAL_AD_EQN(Vehicle5, ad_r_Speed)
      ADD_LOCAL_AD_EQN(Vehicle5, ad_r_wheelSpeed)
    
      return S_OK;
    //#]
}

HRESULT Vehicle5::InitLocalEqns() {
    NOTIFY_OPERATION(InitLocalEqns, InitLocalEqns(), 0, VehicleModels_Vehicle5_InitLocalEqns_SERIALIZE);
    //#[ operation InitLocalEqns() 
    
      ADD_LOCAL_EQN(Vehicle5, r_Newton)
      ADD_LOCAL_EQN(Vehicle5, r_Speed)
      ADD_LOCAL_EQN(Vehicle5, r_wheelSpeed)
    
      return S_OK;
    //#]
}

HRESULT Vehicle5::InitLocalRPars(const _TCHAR * prefix, ppdouble * pars, ppchar * Names, long * nPars, long * dPars) {
    NOTIFY_OPERATION(InitLocalRPars, InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ), 0, VehicleModels_Vehicle5_InitLocalRPars_SERIALIZE);
    //#[ operation InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ) 
    ADD_LOCAL_SRPAR(finalDriveRatio)
    ADD_LOCAL_SRPAR(wheelRadius)
    ADD_LOCAL_SRPAR(vehicleInertia)
    ADD_LOCAL_SRPAR(wheelFrictionDrag)
    ADD_LOCAL_SRPAR(aerodynamicDrag)
    
    return S_OK;
    //#]
}

HRESULT Vehicle5::InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly) {
    NOTIFY_OPERATION(InitLocalVars, InitLocalVars(const _TCHAR * ,VarCont * ,const bool ), 0, VehicleModels_Vehicle5_InitLocalVars_SERIALIZE);
    //#[ operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    
    
      ADD_LOCAL_SVAR(wheelSpeed)
      ADD_LOCAL_SVAR(speed)
    
     for (long i = 0; i < m_nEsos; i++)
       AddLocalVar(m_Esos[i], NULL, NULL, varC, true);
    
      return S_OK;
    //#]
}

bool Vehicle5::Load(FILE * fs) {
    NOTIFY_OPERATION(Load, Load(FILE * ), 0, VehicleModels_Vehicle5_Load_SERIALIZE);
    //#[ operation Load(FILE * ) 
    
    return true;
    //#]
}

void Vehicle5::Save(FILE * fs) {
    NOTIFY_OPERATION(Save, Save(FILE * ), 0, VehicleModels_Vehicle5_Save_SERIALIZE);
    //#[ operation Save(FILE * ) 
    //#]
}

HRESULT Vehicle5::ad_r_Newton(Fdouble * res) {
    //#[ operation ad_r_Newton(Fdouble * ) 
    *res = p->AD(torque) * finalDriveRatio 
             - (vehicleInertia * (p->AD(acceleration) / finalDriveRatio) + 
                wheelFrictionDrag +
                aerodynamicDrag * AD(speed) * AD(speed));
    return S_OK;
    //#]
}

HRESULT Vehicle5::ad_r_Speed(Fdouble * res) {
    //#[ operation ad_r_Speed(Fdouble * ) 
    #define PI 3.1415926535897932384626433832795
    #define RPM2KMPH 1.13636363636363636363636363636e-2
    *res = AD(speed) - 2.0*PI*wheelRadius *RPM2KMPH* AD(wheelSpeed);
    return S_OK;
    //#]
}

HRESULT Vehicle5::ad_r_wheelSpeed(Fdouble * res) {
    //#[ operation ad_r_wheelSpeed(Fdouble * ) 
    #define PI 3.1415926535897932384626433832795
    
      *res = DER_AD(wheelSpeed) - (60.0 / (2.0 * PI)) * (p->AD(acceleration) / finalDriveRatio);
    return S_OK;
    //#]
}

void Vehicle5::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, VehicleModels_Vehicle5_clean_SERIALIZE);
    //#[ operation clean() 
    if (p)
    {
      p->Release();
      p = NULL;
    }
    
    if (aBrakeActuator)
    {
      aBrakeActuator->Release();
      aBrakeActuator = NULL;
    }
    
    if (Brake)
    {
      Brake->Release();
      Brake = NULL;
    }
    
    if (gBrake)
    {
      gBrake->Release();
      gBrake = NULL;
    }
    
    //#]
}

void Vehicle5::getSpeed(const double t, double * val) {
    NOTIFY_OPERATION(getSpeed, getSpeed(const double ,double * ), 0, VehicleModels_Vehicle5_getSpeed_SERIALIZE);
    //#[ operation getSpeed(const double ,double * ) 
    const long idx_var_wheelSpeed = 0;
    const long idx_var_speed = 1;
    if (m_pOnModel) 
      m_pOnModel->GetVariable(idx_var_speed, t, val);
    //#]
}

void Vehicle5::handle_aerodynamicDrag(const double t, const double * val) {
    NOTIFY_OPERATION(handle_aerodynamicDrag, handle_aerodynamicDrag(const double ,const double * ), 0, VehicleModels_Vehicle5_handle_aerodynamicDrag_SERIALIZE);
    //#[ operation handle_aerodynamicDrag(const double ,const double * ) 
    
    PostRealParameter(t, 4, *val);
    //#]
}

void Vehicle5::handle_brakePedal(const double t, double * val) {
    NOTIFY_OPERATION(handle_brakePedal, handle_brakePedal(const double ,double * ), 0, VehicleModels_Vehicle5_handle_brakePedal_SERIALIZE);
    //#[ operation handle_brakePedal(const double ,double * ) 
    aBrakeActuator->handle_brakePedal(t, val);
    //#]
}

void Vehicle5::handle_finalDriveRatio(const double t, const double * val) {
    NOTIFY_OPERATION(handle_finalDriveRatio, handle_finalDriveRatio(const double ,const double * ), 0, VehicleModels_Vehicle5_handle_finalDriveRatio_SERIALIZE);
    //#[ operation handle_finalDriveRatio(const double ,const double * ) 
    
    PostRealParameter(t, 0, *val);
    //#]
}

void Vehicle5::handle_vehicleInertia(const double t, const double * val) {
    NOTIFY_OPERATION(handle_vehicleInertia, handle_vehicleInertia(const double ,const double * ), 0, VehicleModels_Vehicle5_handle_vehicleInertia_SERIALIZE);
    //#[ operation handle_vehicleInertia(const double ,const double * ) 
    
    PostRealParameter(t, 2, *val);
    //#]
}

void Vehicle5::handle_wheelFrictionDrag(const double t, const double * val) {
    NOTIFY_OPERATION(handle_wheelFrictionDrag, handle_wheelFrictionDrag(const double ,const double * ), 0, VehicleModels_Vehicle5_handle_wheelFrictionDrag_SERIALIZE);
    //#[ operation handle_wheelFrictionDrag(const double ,const double * ) 
    
    PostRealParameter(t, 3, *val);
    //#]
}

void Vehicle5::handle_wheelRadius(const double t, const double * val) {
    NOTIFY_OPERATION(handle_wheelRadius, handle_wheelRadius(const double ,const double * ), 0, VehicleModels_Vehicle5_handle_wheelRadius_SERIALIZE);
    //#[ operation handle_wheelRadius(const double ,const double * ) 
    
    PostRealParameter(t, 1, *val);
    //#]
}

void Vehicle5::init() {
    NOTIFY_OPERATION(init, init(), 0, VehicleModels_Vehicle5_init_SERIALIZE);
    //#[ operation init() 
    p = new CRigidConnector();
    p->AddRef();
    
    aBrakeActuator = new BrakeActuator();
    aBrakeActuator->AddRef();
    
    Brake = new Clutch();
    Brake->AddRef();
    
    gBrake = new CFrame();
    gBrake->AddRef();
    
    wheelSpeed = 0.0;
    DER(wheelSpeed) = 0.0;
    speed = 0.0;
    DER(speed) = 0.0;
    
    #define PI 3.1415926535897932384626433832795
    
    aerodynamicDrag = 0.02;
    finalDriveRatio = 3.23;
    vehicleInertia = 12.0941 * (60.0 / (2.0 * PI));
    wheelFrictionDrag = 40.0;
    wheelRadius = 1.0;
    
    //#]
}

HRESULT Vehicle5::r_Newton(double * res) {
    //#[ operation r_Newton(double * ) 
    *res = p->torque * finalDriveRatio 
             - (vehicleInertia * (p->acceleration / finalDriveRatio) + 
                wheelFrictionDrag +
                aerodynamicDrag * speed * speed);
    return S_OK;
    //#]
}

HRESULT Vehicle5::r_Speed(double * res) {
    //#[ operation r_Speed(double * ) 
    #define PI 3.1415926535897932384626433832795
    #define RPM2KMPH 1.13636363636363636363636363636e-2
    *res = speed - 2.0*PI*wheelRadius *RPM2KMPH* wheelSpeed;
    return S_OK;
    //#]
}

HRESULT Vehicle5::r_wheelSpeed(double * res) {
    //#[ operation r_wheelSpeed(double * ) 
    #define PI 3.1415926535897932384626433832795
    
      *res = DER(wheelSpeed) - (60.0 / (2.0 * PI)) * (p->acceleration / finalDriveRatio);
    return S_OK;
    //#]
}

VarEx Vehicle5::get_speed() const {
    return _speed;
}

void Vehicle5::set_speed(VarEx  p__speed) {
    _speed = p__speed;
}

VarEx Vehicle5::get_wheelSpeed() const {
    return _wheelSpeed;
}

void Vehicle5::set_wheelSpeed(VarEx  p__wheelSpeed) {
    _wheelSpeed = p__wheelSpeed;
}

double Vehicle5::getAerodynamicDrag() const {
    return aerodynamicDrag;
}

void Vehicle5::setAerodynamicDrag(double  p_aerodynamicDrag) {
    aerodynamicDrag = p_aerodynamicDrag;
}

double Vehicle5::getFinalDriveRatio() const {
    return finalDriveRatio;
}

void Vehicle5::setFinalDriveRatio(double  p_finalDriveRatio) {
    finalDriveRatio = p_finalDriveRatio;
}

double Vehicle5::getSpeed() const {
    return speed;
}

void Vehicle5::setSpeed(double  p_speed) {
    speed = p_speed;
}

double Vehicle5::getVehicleInertia() const {
    return vehicleInertia;
}

void Vehicle5::setVehicleInertia(double  p_vehicleInertia) {
    vehicleInertia = p_vehicleInertia;
}

double Vehicle5::getWheelFrictionDrag() const {
    return wheelFrictionDrag;
}

void Vehicle5::setWheelFrictionDrag(double  p_wheelFrictionDrag) {
    wheelFrictionDrag = p_wheelFrictionDrag;
}

double Vehicle5::getWheelRadius() const {
    return wheelRadius;
}

void Vehicle5::setWheelRadius(double  p_wheelRadius) {
    wheelRadius = p_wheelRadius;
}

double Vehicle5::getWheelSpeed() const {
    return wheelSpeed;
}

void Vehicle5::setWheelSpeed(double  p_wheelSpeed) {
    wheelSpeed = p_wheelSpeed;
}

Clutch* Vehicle5::getBrake() const {
    return Brake;
}

void Vehicle5::setBrake(Clutch*  p_Clutch) {
    Brake = p_Clutch;
    if(p_Clutch != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("Brake", p_Clutch, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("Brake");
        }
}

BrakeActuator* Vehicle5::getABrakeActuator() const {
    return aBrakeActuator;
}

void Vehicle5::setABrakeActuator(BrakeActuator*  p_BrakeActuator) {
    aBrakeActuator = p_BrakeActuator;
    if(p_BrakeActuator != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("aBrakeActuator", p_BrakeActuator, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("aBrakeActuator");
        }
}

CFrame* Vehicle5::getGBrake() const {
    return gBrake;
}

void Vehicle5::setGBrake(CFrame*  p_CFrame) {
    gBrake = p_CFrame;
    if(p_CFrame != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("gBrake", p_CFrame, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("gBrake");
        }
}

CRigidConnector* Vehicle5::getP() const {
    return p;
}

void Vehicle5::setP(CRigidConnector*  p_CRigidConnector) {
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

void Vehicle5::cleanUpRelations() {
    if(Brake != NULL)
        {
            NOTIFY_RELATION_CLEARED("Brake");
            Brake = NULL;
        }
    if(aBrakeActuator != NULL)
        {
            NOTIFY_RELATION_CLEARED("aBrakeActuator");
            aBrakeActuator = NULL;
        }
    if(gBrake != NULL)
        {
            NOTIFY_RELATION_CLEARED("gBrake");
            gBrake = NULL;
        }
    if(p != NULL)
        {
            NOTIFY_RELATION_CLEARED("p");
            p = NULL;
        }
}



#ifdef _OMINSTRUMENT


void OMAnimatedVehicle5::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedVehicle5::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("gBrake", FALSE, TRUE);
    if(myReal->gBrake)
        aomsRelations->ADD_ITEM(myReal->gBrake);
    aomsRelations->addRelation("Brake", FALSE, TRUE);
    if(myReal->Brake)
        aomsRelations->ADD_ITEM(myReal->Brake);
    aomsRelations->addRelation("p", FALSE, TRUE);
    if(myReal->p)
        aomsRelations->ADD_ITEM(myReal->p);
    aomsRelations->addRelation("aBrakeActuator", FALSE, TRUE);
    if(myReal->aBrakeActuator)
        aomsRelations->ADD_ITEM(myReal->aBrakeActuator);
}

IMPLEMENT_META(Vehicle5, VehicleModels, FALSE, OMAnimatedVehicle5)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Vehicle5.cpp
*********************************************************************/

