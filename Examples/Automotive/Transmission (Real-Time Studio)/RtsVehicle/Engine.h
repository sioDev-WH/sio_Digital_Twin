#ifndef __ENGINE_H
#define __ENGINE_H


#include "OnUMLDaeEsoImpl.h"
#include "ShiftLogic.h"
#include "LookupTable.h"
#include "RtsOnTransmissionExport.h"

class CRigidConnector;
struct IOnEnv;


//{{SCG_HEADER(Engine.h) [0]

//{{SCG_INCLUDE                     
#include "ShiftLogic.h"
#include "RtsSmInt.h"
//}}SCG_INCLUDE

//{{SCG_FORWARD                    
class LookupTable;
//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

class RTSONTRANSMISSION_API Engine 
                  :public COnUMLDaeEsoImpl<Engine>
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)
    public:
        CRigidConnector* n;     
        double RPM;
        double engineTorque;
        double throttle;    
        double engineThrottleLag;
        LookupTable torqueMap;     
        double inertia;     
    public:
        double der_RPM;     
        double old_RPM;     
        double der_old_RPM;     
        Fdouble ad_RPM;     
        Fdouble der_ad_RPM;   
        
        double der_engineTorque;     
        double old_engineTorque;     
        double der_old_engineTorque;     
        Fdouble ad_engineTorque;     
        Fdouble der_ad_engineTorque;     
        RtsEngineEngine_States RtsCurrent_Engine;     
  
        // path helper
        IOnEnv* m_pOnEnv;

    private:
        RtsMutex RtsBusy;     
    public:
        void init();             
        void es_Stop();             
        HRESULT r_RPM(double *res); 
        HRESULT r_EngineDynamics(double* res);

        HRESULT r_OffTorque(double *res);             
        HRESULT r_StartupTorque(double *res);             
        HRESULT r_OnTorque(double *res);  
        
        HRESULT z_OnRPM(double *res);             
        void es_Start();             
        void es_On();             
        void clean();             
        void handle_throttle(const double t, double* val);             
        void handle_inertia(const double t, const double* val);             

        void Save(FILE* fs);
        bool Load(FILE* fs);
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
        
        HRESULT EvalStateCondition(
          const bool* EqnState, 
          const double* x, 
          const double* xdot, 
          const double EventTime, 
          const long iDisEqn, 
          const long iTransition, 
          bool* bEvent);

        HRESULT TriggerEvent(const double EventTime, const BSTR bstrEventId);

    public:
        HRESULT ad_r_RPM(Fdouble *res);   
        HRESULT ad_r_EngineDynamics(Fdouble* res);
        
        HRESULT ad_r_OffTorque(Fdouble *res);             
        HRESULT ad_r_StartupTorque(Fdouble *res);             
        HRESULT ad_r_OnTorque(Fdouble *res);   
        
        HRESULT ad_z_OnRPM(Fdouble *res);             
    private:
        void RtsEnter_Starting();             
        void RtsExit_Starting();             
        void RtsEnter_On();             
        void RtsExit_On();             
        void RtsEnter_Off();             
        void RtsExit_Off();             
    public:
	    void handle_Start(const double t, long* val);
        Engine();             
        ~Engine();             
    private:
        void RtsRunToCompletion();             
    #ifdef RTS_SIMULATION
    static int RtsInjectEvent(const char* Event, const int NumParams, const StringArray params, Engine *pInstance);             
#endif

    #ifdef RTS_SIMULATION
    static int RtsGetAttributeValue(const char* Name, char* Value, const int buflen, Engine *pInstance);             
#endif

    #ifdef RTS_SIMULATION
    static int RtsSetAttributeValue(const char* Name, const char* Value, Engine *pInstance);             
#endif

    //}}SCG_CLASS_PROPS
};
//}}SCG_CLASS

//}}SCG_HEADER      
#endif










