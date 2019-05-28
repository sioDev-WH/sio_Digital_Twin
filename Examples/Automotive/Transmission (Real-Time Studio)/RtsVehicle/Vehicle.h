#ifndef __VEHICLE_H
#define __VEHICLE_H


#include "ClutchBase.h"
#include "OnUMLDaeEsoImpl.h"
#include "RtsOnTransmissionExport.h"

class CRigidConnector;


//{{SCG_HEADER(Vehicle.h) [0]

//{{SCG_INCLUDE                     
//}}SCG_INCLUDE

//{{SCG_FORWARD                    
//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

class RTSONTRANSMISSION_API Vehicle 
                  :public COnUMLDaeEsoImpl<Vehicle>
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)
    public:
        double wheelSpeed;     
        double speed;     
        double brakeTorque;     
        double finalDriveRatio;     
        double wheelRadius;     
        double vehicleInertia;     
        double wheelFrictionDrag;     
        double aerodynamicDrag;     
        CRigidConnector* p;     
    public:
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
        double der_brakeTorque;     
        double old_brakeTorque;     
        double der_old_brakeTorque;     
        Fdouble ad_brakeTorque;     
        Fdouble der_ad_brakeTorque;     
        void clean();             
        HRESULT r_Newton(double *res);             
        HRESULT r_Speed(double *res);             
        HRESULT r_wheelSpeed(double *res);             
        void init();             
        void handle_brakeTorque(const double t, const double* val);
        void handle_finalDriveRatio(const double t, const double* val);             
        void handle_wheelRadius(const double t, const double* val);             
        void handle_vehicleInertia(const double t, const double* val);             
        void handle_wheelFrictionDrag(const double t, const double* val);             
        void handle_aerodynamicDrag(const double t, const double* val);             
        void Save(FILE* fs) { }
        bool Load(FILE* fs) { return true; }
    protected:


        HRESULT InitEsos();             
        HRESULT InitLocalEqns();             
        HRESULT InitLocalADEqns();             
        HRESULT InitEqnForm(OnEqnForm* *form, OnEqnDiffForm* *diff_form);             
        HRESULT InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly);
        HRESULT InitLocalRPars(const _TCHAR* prefix, ppdouble *pars, ppchar *Names, long *nPars, long *dPars);             
    public:
      Vehicle();
      ~Vehicle();
        HRESULT ad_r_Newton(Fdouble *res);             
        HRESULT ad_r_Speed(Fdouble *res);             
        HRESULT ad_r_wheelSpeed(Fdouble *res);             
    //}}SCG_CLASS_PROPS
};
//}}SCG_CLASS

//}}SCG_HEADER      
#endif










