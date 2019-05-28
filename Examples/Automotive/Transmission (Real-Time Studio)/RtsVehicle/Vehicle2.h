#ifndef __VEHICLE2_H
#define __VEHICLE2_H

// includes
#include "OnUMLDaeEsoImpl.h"
#include "ShiftLogic.h"
#include "RtsSmInt.h"
#include "RtsOnTransmissionExport.h"


// forward declarations
class CRigidConnector;


class RTSONTRANSMISSION_API Vehicle2 : public COnUMLDaeEsoImpl<Vehicle2>
{
public:
Vehicle2();
virtual ~Vehicle2();

public:
CRigidConnector* p;
double wheelSpeed;
double speed;
double brakeTorque;
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


RtsVehicle2Vehicle2_States RtsCurrent_Vehicle2;
RtsMutex RtsBusy;

public:
HRESULT r_ForwardNewton( double* res);
HRESULT r_ReverseNewton( double* res);
HRESULT r_Speed( double* res);
HRESULT r_wheelSpeed( double* res);
void init();
void clean();
HRESULT z_ForwardDirection( double* res);
HRESULT z_ReverseDirection( double* res);
void handle_brakeTorque(const double t, const double* val);
void handle_finalDriveRatio(const double t, const double* val);
void handle_wheelRadius(const double t, const double* val);
void handle_vehicleInertia(const double t, const double* val);
void handle_wheelFrictionDrag(const double t, const double* val);
void handle_aerodynamicDrag(const double t, const double* val);
HRESULT InitEsos();
HRESULT InitLocalEqns();
HRESULT InitLocalADEqns();
HRESULT InitEqnForm( OnEqnForm** form,  OnEqnDiffForm** diff_form);
HRESULT InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly);
HRESULT InitLocalRPars(const _TCHAR* prefix,  ppdouble* pars,  ppchar* Names,  long* nPars,  long* dPars);
HRESULT InitTransitions();
HRESULT InitStates();
HRESULT OnTransition();
HRESULT TriggerEvent(const double EventTime, const BSTR bstrEventId);
HRESULT ad_r_ForwardNewton( Fdouble* res);
HRESULT ad_r_ReverseNewton( Fdouble* res);
HRESULT ad_r_Speed( Fdouble* res);
HRESULT ad_r_wheelSpeed( Fdouble* res);
HRESULT ad_z_ForwardDirection( Fdouble* res);
HRESULT ad_z_ReverseDirection( Fdouble* res);
void Save( FILE* fs);
bool Load( FILE* fs);
void RtsEnter_Reverse();
void RtsExit_Reverse();
void RtsEnter_Forward();
void RtsExit_Forward();
void RtsMovingReverse();
void RtsMovingForward();
void RtsRunToCompletion();

void es_Reverse();
void es_Forward();

#ifdef RTS_SIMULATION
    static int RtsInjectEvent(const char* Event, const int NumParams, const StringArray params, Vehicle2 *pInstance);             
#endif

#ifdef RTS_SIMULATION
    static int RtsGetAttributeValue(const char* Name, char* Value, const int buflen, Vehicle2 *pInstance);             
#endif

#ifdef RTS_SIMULATION
    static int RtsSetAttributeValue(const char* Name, const char* Value, Vehicle2 *pInstance);             
#endif

};

#endif
