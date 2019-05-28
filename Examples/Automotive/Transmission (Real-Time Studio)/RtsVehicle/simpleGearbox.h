#ifndef __SIMPLEGEARBOX_H
#define __SIMPLEGEARBOX_H

//{{SCG_HEADER(simpleGearbox.h) [0]

//{{SCG_INCLUDE  
#include "OnUMLDaeEsoImpl.h"
#include "ShiftLogic.h"

class CRigidConnector;
// Include for Template Class should go here.
#include "RtsSmInt.h"
//}}SCG_INCLUDE

//{{SCG_FORWARD                    

//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

class simpleGearbox 
                  :public COnUMLDaeEsoImpl<simpleGearbox>
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)
    public:
        long gear;     
        double rate;     
        double tolerance;  
        long gearRatioCount;
        double gearRatio[6]; 
        double oldRatio;
        double newRatio;
        
        double shiftPeriod;
        long lastGear;     

        double shiftTime;     
        double ratio;  
        double p_Speed;
        double n_Speed;

        CRigidConnector* p;     
        CRigidConnector* n;     
        RtssimpleGearboxsimpleGearbox_States RtsCurrent_simpleGearbox;     
        RtsMutex RtsBusy;     
    public:
        double der_shiftTime;     
        double old_shiftTime;     
        double der_old_shiftTime;     
        Fdouble ad_shiftTime;     
        Fdouble der_ad_shiftTime;     
        double der_ratio;     
        double old_ratio;     
        double der_old_ratio;     
        Fdouble ad_ratio;     
        Fdouble der_ad_ratio;     

        double der_p_Speed;     
        double old_p_Speed;     
        double der_old_p_Speed;     
        Fdouble ad_p_Speed;     
        Fdouble der_ad_p_Speed;     

        double der_n_Speed;     
        double old_n_Speed;     
        double der_old_n_Speed;     
        Fdouble ad_n_Speed;     
        Fdouble der_ad_n_Speed;     


        void ec_downShift();             
        void ec_upShift();             
        void init();             
        void clean();             
        HRESULT r_shiftTime(double *res);             
        HRESULT r_shiftProfile(double *res);             
        HRESULT s_shiftTime(double *res);             
        void handle_shiftEvent(const double t, long *val); 
        HRESULT TriggerEvent(const double EventTime, const BSTR bstrEventId);

        void Save(FILE* fs);
        bool Load(FILE* fs);

    private:
        void RtsEnter_Neutral();             
        void RtsExit_Neutral();             
        void RtsEnter_First();             
        void RtsExit_First();             
        void RtsEnter_Second();             
        void RtsExit_Second();             
        void RtsEnter_Third();             
        void RtsExit_Third();             
        void RtsEnter_Fourth();             
        void RtsExit_Fourth();             
        void RtsEnter_Reverse();             
        void RtsExit_Reverse();             
    public:
        simpleGearbox();             
        ~simpleGearbox();             
    private:
        void RtsRunToCompletion();             
    #ifdef RTS_SIMULATION
    static int RtsInjectEvent(const char* Event, const int NumParams, const StringArray params, simpleGearbox *pInstance);             
#endif

    #ifdef RTS_SIMULATION
    static int RtsGetAttributeValue(const char* Name, char* Value, const int buflen, simpleGearbox *pInstance);             
#endif

    #ifdef RTS_SIMULATION
    static int RtsSetAttributeValue(const char* Name, const char* Value, simpleGearbox *pInstance);             
#endif

    public:
        HRESULT r_forceRatio(double *res);  
        HRESULT r_p_Speed(double* res);
        HRESULT r_n_Speed(double* res);
        HRESULT r_speedRatio(double* res);
        
        void handle_tolerance(const double t, const double* val);             
        void handle_shiftPeriod(const double t, const double* val);

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
    public:
        HRESULT ad_r_shiftTime(Fdouble *res);             
        HRESULT ad_r_shiftProfile(Fdouble *res);             
        HRESULT ad_s_shiftTime(Fdouble *res);  
        
        HRESULT ad_r_forceRatio(Fdouble *res);  
        HRESULT ad_r_p_Speed(Fdouble* res);
        HRESULT ad_r_n_Speed(Fdouble* res);
        HRESULT ad_r_speedRatio(Fdouble* res);

    //}}SCG_CLASS_PROPS
};

//}}SCG_CLASS

//}}SCG_HEADER      
#endif










