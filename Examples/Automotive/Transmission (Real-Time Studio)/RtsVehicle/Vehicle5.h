#ifndef __VEHICLE5_H
#define __VEHICLE5_H

// includes
#include "OnUMLDaeEsoImpl.h"
#include "ShiftLogic.h"
#include "RtsOnTransmissionExport.h"

// forward declarations
class CFrame;
class Clutch;
class CRigidConnector;
class BrakeActuator;


class RTSONTRANSMISSION_API Vehicle5 : public COnUMLDaeEsoImpl<Vehicle5>
{
public:
Vehicle5();
virtual ~Vehicle5();

public:
CFrame* gBrake;
Clutch* Brake;
CRigidConnector* p;
BrakeActuator* aBrakeActuator;
double wheelSpeed;
double speed;
double finalDriveRatio;
double wheelRadius;
double vehicleInertia;
double wheelFrictionDrag;
double aerodynamicDrag;
double der_wheelSpeed;
double old_wheelSpeed;
double der_old_wheelSpeed;
Fdouble ad_wheelSpeed;
Fdouble der_ad_wheelSpeed;
double der_speed;
double old_speed;
double der_old_speed;
Fdouble ad_speed;
Fdouble der_ad_speed;

public:
void init();
void clean();

void handle_brakePedal(const double t, double* val);
HRESULT r_Newton( double* res);
HRESULT r_Speed( double* res);
HRESULT r_wheelSpeed( double* res);
void handle_finalDriveRatio(const double t, const double* val);
void handle_wheelRadius(const double t, const double* val);
void handle_vehicleInertia(const double t, const double* val);
void handle_wheelFrictionDrag(const double t, const double* val);
void handle_aerodynamicDrag(const double t, const double* val);
HRESULT GetAssociations(long** Assoc, long** Size, long* nSize);
HRESULT InitEsos();
HRESULT InitLocalEqns();
HRESULT InitLocalADEqns();
HRESULT InitEqnForm( OnEqnForm** form,  OnEqnDiffForm** diff_form);
HRESULT InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly);
HRESULT InitLocalRPars(const _TCHAR* prefix,  ppdouble* pars,  ppchar* Names,  long* nPars,  long* dPars);
HRESULT ad_r_Newton( Fdouble* res);
HRESULT ad_r_Speed( Fdouble* res);
HRESULT ad_r_wheelSpeed( Fdouble* res);
void Save( FILE* fs);
bool Load( FILE* fs);

};

#endif
