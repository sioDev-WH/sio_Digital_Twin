// implementation for class Vehicle5
#include "StdAfx.h"
#include "RtsOnTransmission.h"
#include <math.h>

#include "Vehicle5.h"

#include "RigidConnector.h"
#include "CFrame.h"
#include "BrakeActuator.h"
#include "Clutch.h"

// includes

Vehicle5::Vehicle5()
{
  init();
}

Vehicle5::~Vehicle5()
{
 clean();
}

void Vehicle5::init()
{
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


}


HRESULT Vehicle5::GetAssociations(long** Assoc, long** Size, long* nSize)
{

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
}


void Vehicle5::clean()
{
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

}

void Vehicle5::handle_brakePedal(const double t, double* val)
{
aBrakeActuator->handle_brakePedal(t, val);
}


HRESULT Vehicle5::r_Newton(double* res)
{
*res = p->torque * finalDriveRatio 
         - (vehicleInertia * (p->acceleration / finalDriveRatio) + 
            wheelFrictionDrag +
            aerodynamicDrag * speed * speed);
return S_OK;
}


HRESULT Vehicle5::r_Speed(double* res)
{
#define PI 3.1415926535897932384626433832795
#define RPM2KMPH 1.13636363636363636363636363636e-2
*res = speed - 2.0*PI*wheelRadius *RPM2KMPH* wheelSpeed;
return S_OK;
}


HRESULT Vehicle5::r_wheelSpeed(double* res)
{
#define PI 3.1415926535897932384626433832795

  *res = DER(wheelSpeed) - (60.0 / (2.0 * PI)) * (p->acceleration / finalDriveRatio);
return S_OK;
}


void Vehicle5::handle_finalDriveRatio(const double t, const double* val)
{

PostRealParameter(t, 0, *val);
}


void Vehicle5::handle_wheelRadius(const double t, const double* val)
{

PostRealParameter(t, 1, *val);
}


void Vehicle5::handle_vehicleInertia(const double t, const double* val)
{

PostRealParameter(t, 2, *val);
}


void Vehicle5::handle_wheelFrictionDrag(const double t, const double* val)
{

PostRealParameter(t, 3, *val);
}


void Vehicle5::handle_aerodynamicDrag(const double t, const double* val)
{

PostRealParameter(t, 4, *val);
}


HRESULT Vehicle5::InitEsos()
{
  ADD_LOCAL_ESO(p)
  ADD_LOCAL_ESO(aBrakeActuator)
  ADD_LOCAL_ESO(gBrake)
  ADD_LOCAL_ESO(Brake)
  
  return S_OK;
}


HRESULT Vehicle5::InitLocalEqns()
{

  ADD_LOCAL_EQN(Vehicle5, r_Newton)
  ADD_LOCAL_EQN(Vehicle5, r_Speed)
  ADD_LOCAL_EQN(Vehicle5, r_wheelSpeed)

  return S_OK;
}


HRESULT Vehicle5::InitLocalADEqns()
{

  ADD_LOCAL_AD_EQN(Vehicle5, ad_r_Newton)
  ADD_LOCAL_AD_EQN(Vehicle5, ad_r_Speed)
  ADD_LOCAL_AD_EQN(Vehicle5, ad_r_wheelSpeed)

  return S_OK;
}


HRESULT Vehicle5::InitEqnForm(OnEqnForm** form, OnEqnDiffForm** diff_form)
{


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
}


HRESULT Vehicle5::InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly)
{


  ADD_LOCAL_SVAR(wheelSpeed)
  ADD_LOCAL_SVAR(speed)

for (long i = 0; i < m_nEsos; i++)
  AddLocalVar(m_Esos[i], NULL, NULL, varC, true);

  return S_OK;
}


HRESULT Vehicle5::InitLocalRPars(const _TCHAR* prefix, ppdouble* pars, ppchar* Names, long* nPars, long* dPars)
{
  ADD_LOCAL_SRPAR(finalDriveRatio)
  ADD_LOCAL_SRPAR(wheelRadius)
  ADD_LOCAL_SRPAR(vehicleInertia)
  ADD_LOCAL_SRPAR(wheelFrictionDrag)
  ADD_LOCAL_SRPAR(aerodynamicDrag)

  return S_OK;
}


HRESULT Vehicle5::ad_r_Newton(Fdouble* res)
{
*res = p->ad_torque * finalDriveRatio 
         - (vehicleInertia * (p->ad_acceleration / finalDriveRatio) + 
            wheelFrictionDrag +
            aerodynamicDrag * ad_speed * ad_speed);
return S_OK;
}


HRESULT Vehicle5::ad_r_Speed(Fdouble* res)
{
#define PI 3.1415926535897932384626433832795
#define RPM2KMPH 1.13636363636363636363636363636e-2
*res = ad_speed - 2.0*PI*wheelRadius *RPM2KMPH* ad_wheelSpeed;
return S_OK;
}


HRESULT Vehicle5::ad_r_wheelSpeed(Fdouble* res)
{
#define PI 3.1415926535897932384626433832795

  *res = DER(ad_wheelSpeed) - (60.0 / (2.0 * PI)) * (p->ad_acceleration / finalDriveRatio);
return S_OK;
}


void Vehicle5::Save(FILE* fs)
{

}


bool Vehicle5::Load(FILE* fs)
{

return true;
}


