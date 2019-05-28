#ifndef __TORQUE_CONVERTER_H
#define __TORQUE_CONVERTER_H

//{{SCG_HEADER(Torque_Converter.h) [0]
#include "OnUMLDaeEsoImpl.h"
#include "RtsOnTransmissionExport.h"
                   

//{{SCG_INCLUDE                     
#include "ShiftLogic.h"
// Include for Template Class should go here.
#include "RtsSmInt.h"
//}}SCG_INCLUDE

//{{SCG_FORWARD                    
class CRigidConnector;

//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)




class RTSONTRANSMISSION_API Torque_Converter 
                  :public COnUMLDaeEsoImpl<Torque_Converter>
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)
    public:
        double turbineTorque;     
        double turbineSpeed;     
        double turbineInertia;     
        double impellerTorque;     
        double impellerSpeed;     
        double impellerInertia;     
        CRigidConnector* turbine;     
        CRigidConnector* impeller;     
        double der_turbineTorque;     
        double old_turbineTorque;     
        double der_old_turbineTorque;     
        Fdouble ad_turbineTorque;     
        Fdouble der_ad_turbineTorque;     
        double der_turbineSpeed;     
        double old_turbineSpeed;     
        double der_old_turbineSpeed;     
        Fdouble ad_turbineSpeed;     
        Fdouble der_ad_turbineSpeed;     
        double der_impellerTorque;     
        double old_impellerTorque;     
        double der_old_impellerTorque;     
        Fdouble ad_impellerTorque;     
        Fdouble der_ad_impellerTorque;     
        double der_impellerSpeed;     
        double old_impellerSpeed;     
        double der_old_impellerSpeed;     
        Fdouble ad_impellerSpeed;     
        Fdouble der_ad_impellerSpeed;     
        double c[10];     
        RtsTorque_ConverterTorque_Converter_States RtsCurrent_Torque_Converter;     
        RtsMutex RtsBusy;     
        HRESULT r_TMM_ImpellerTorque(double *res);             
        HRESULT r_TMM_TurbineTorque(double *res);             
        HRESULT r_FCM_ImpellerTorque(double *res);             
        HRESULT r_FCM_TurbineTorque(double *res);             
        void es_TMM();             
        void es_FCM();             
        HRESULT z_TorqueRatio_gt_one(double *res);             
        void init();             
        HRESULT r_ImpellerSpeed(double *res);             
        HRESULT r_ImpellerNewton(double *res);             
        HRESULT r_TurbineSpeed(double *res);             
        HRESULT r_TurbineNewton(double *res);             
        void clean();             
        HRESULT z_TorqueRatio_lt_one(double *res);             
        HRESULT ad_z_TorqueRatio_lt_one(Fdouble *res);             
        void handle_turbineInertia(const double t, double *val);             
        void handle_impellerInertia(const double t, double *val);             
    protected:
        HRESULT InitEsos();             
        HRESULT InitLocalEqns();             
        HRESULT InitLocalADEqns();             
        HRESULT InitEqnForm(OnEqnForm* *form, OnEqnDiffForm* *diff_form);             
        HRESULT InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly);
        HRESULT InitLocalRPars(const _TCHAR* prefix, ppdouble *pars, ppchar *Names, long *nPars, long *dPars);             
        HRESULT InitTransitions();             
        HRESULT InitStates();             
        HRESULT OnTransition();             
        HRESULT TriggerEvent(const double EventTime, const BSTR bstrEventId);             
        HRESULT EvalStateCondition(const bool* EqnState, const double* x, const double* xdot, const double EventTime, const long iDisEqn, const long iTransition, bool *bEvent);             
    public:
        HRESULT ad_r_TMM_ImpellerTorque(Fdouble *res);             
        HRESULT ad_r_TMM_TurbineTorque(Fdouble *res);             
        HRESULT ad_r_FCM_ImpellerTorque(Fdouble *res);             
        HRESULT ad_r_FCM_TurbineTorque(Fdouble *res);             
        HRESULT ad_z_TorqueRatio_gt_one(Fdouble *res);             
        HRESULT ad_r_ImpellerSpeed(Fdouble *res);             
        HRESULT ad_r_ImpellerNewton(Fdouble *res);             
        HRESULT ad_r_TurbineSpeed(Fdouble *res);             
        HRESULT ad_r_TurbineNewton(Fdouble *res);             
        void es_Lock();             
        HRESULT ad_r_SpeedLocked(Fdouble *res);             
        HRESULT ad_z_Speed_gt_LockedSpeed(Fdouble *res);             
        HRESULT ad_z_Speed_lt_LockedSpeed(Fdouble *res);             
        bool Load(FILE *fs);             
        HRESULT r_SpeedLocked(double *res);             
        void Save(FILE *fs);             
        HRESULT z_Speed_gt_LockedSpeed(double *res);             
        HRESULT z_Speed_lt_LockedSpeed(double *res);    
        
        HRESULT z_ImpellerTorque_lt_TurbineTorque(double *res);
        HRESULT ad_z_ImpellerTorque_lt_TurbineTorque(Fdouble *res);

    private:
        void RtsEnter_Fluid_Coupling();             
        void RtsExit_Fluid_Coupling();             
        void RtsEnter_Locked();             
        void RtsExit_Locked();             
        void RtsEnter_Torque_Multiplication();             
        void RtsExit_Torque_Multiplication();             
    public:
        Torque_Converter();             
        ~Torque_Converter();             
    private:
        void RtsRunToCompletion();             
    #ifdef RTS_SIMULATION
    static int RtsInjectEvent(const char* Event, const int NumParams, const StringArray params, Torque_Converter *pInstance);             
#endif

    #ifdef RTS_SIMULATION
    static int RtsGetAttributeValue(const char* Name, char* Value, const int buflen, Torque_Converter *pInstance);             
#endif

    #ifdef RTS_SIMULATION
    static int RtsSetAttributeValue(const char* Name, const char* Value, Torque_Converter *pInstance);             
#endif

    //}}SCG_CLASS_PROPS
};

//}}SCG_CLASS

//}}SCG_HEADER      
#endif










