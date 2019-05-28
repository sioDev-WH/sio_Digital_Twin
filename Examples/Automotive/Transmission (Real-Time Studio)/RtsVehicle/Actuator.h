#ifndef __ACTUATOR_H
#define __ACTUATOR_H

// Cg_Add
#include "OnUMLDaeEsoImpl.h"
#include "ShiftLogic.h"
#include "RtsOnTransmissionExport.h"

class ActuatorClutchConnector;
class CRigidConnector;


//{{SCG_HEADER(Actuator.h) [0]

//{{SCG_INCLUDE                     
// Include for Template Class should go here.
#include "ShiftLogic.h"
#include "RtsSmInt.h"
//}}SCG_INCLUDE

//{{SCG_FORWARD                    

//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

class RTSONTRANSMISSION_API Actuator 
                  :public COnUMLDaeEsoImpl<Actuator>
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)
    public:
        ActuatorClutchConnector* clutchConnector;     
        double shiftTime;     
        double shiftPeriod;     
        double rate;     
        double tolerance;     
        double pressureMax; 
        
        void SetShiftPeriod(double val);

    public:
        double der_shiftTime;     
        double old_shiftTime;     
        double der_old_shiftTime;     
        Fdouble ad_shiftTime;     
        Fdouble der_ad_shiftTime;     
        RtsActuatorActuator_States RtsCurrent_Actuator;     
    private:
        RtsMutex RtsBusy;     
    public:
        void ec_Engage();             
        void ec_Disengage();             
        HRESULT r_ShiftTime(double *res);             
        HRESULT r_EngageProfile(double *res);             
        HRESULT r_DisengageProfile(double *res);             
        HRESULT s_ShiftTime(double *res);             
        void init();             
        void clean();             
        HRESULT r_WaitProfile(double *res);             
        void handle_shiftEvent(const double t, long *val);             
        void handle_shiftPeriod(const double t, double* val);             
        void handle_rate(const double t, double* val);             
        void handle_tolerance(const double t, double* val);             
        void handle_pressureMax(const double t, double* val);             
        void Save(FILE* fs);
        bool Load(FILE* fs);
    protected:


        HRESULT InitEsos();             
        HRESULT InitLocalEqns();             
        HRESULT InitLocalADEqns();             
        HRESULT InitEqnForm(OnEqnForm* *form, OnEqnDiffForm* *diff_form);             
        HRESULT InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly);
        HRESULT InitLocalRPars(const _TCHAR* prefix, ppdouble *pars, ppchar *Names, long *nPars, long *dPars);             
        HRESULT InitLocalIPars(const _TCHAR* prefix, pplong *pars, ppchar *Names, long *nPars, long *dPars);             
        HRESULT InitTransitions();             
        HRESULT InitStates();             
        HRESULT OnTransition();   
        HRESULT TriggerEvent(const double EventTime, const BSTR bstrEventId);

    public:
        HRESULT ad_r_ShiftTime(Fdouble *res);             
        HRESULT ad_r_EngageProfile(Fdouble *res);             
        HRESULT ad_r_DisengageProfile(Fdouble *res);             
        HRESULT ad_s_ShiftTime(Fdouble *res);             
        HRESULT ad_r_WaitProfile(Fdouble *res);             
    private:
        void RtsEnter_Disengaged();             
        void RtsExit_Disengaged();             
        void RtsEnter_Waiting();             
        void RtsExit_Waiting();             
        void RtsEnter_Engaged();             
        void RtsExit_Engaged();             
    public:
        Actuator();             
        ~Actuator();             
    private:
        void RtsRunToCompletion();             
    #ifdef RTS_SIMULATION
    static int RtsInjectEvent(const char* Event, const int NumParams, const StringArray params, Actuator *pInstance);             
#endif

    #ifdef RTS_SIMULATION
    static int RtsGetAttributeValue(const char* Name, char* Value, const int buflen, Actuator *pInstance);             
#endif

    #ifdef RTS_SIMULATION
    static int RtsSetAttributeValue(const char* Name, const char* Value, Actuator *pInstance);             
#endif

    //}}SCG_CLASS_PROPS
};
//}}SCG_CLASS

//}}SCG_HEADER      
#endif










