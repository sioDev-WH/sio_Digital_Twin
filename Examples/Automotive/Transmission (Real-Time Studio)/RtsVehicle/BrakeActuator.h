#ifndef __BRAKEACTUATOR_H
#define __BRAKEACTUATOR_H

//{{SCG_HEADER(BrakeActuator.h) [0]

//{{SCG_INCLUDE                     
#include "ShiftLogic.h"
// Include for Template Class should go here.
#include "LinkTemplates.h"
//}}SCG_INCLUDE

//{{SCG_FORWARD                    
class ActuatorClutchConnector;
//}}SCG_FORWARD
#include "OnUMLDaeEsoImpl.h"
#include "RtsOnTransmissionExport.h"


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

class RTSONTRANSMISSION_API BrakeActuator 
                  :public COnUMLDaeEsoImpl<BrakeActuator>
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)
    public:
        BrakeActuator() { init(); }
        ~BrakeActuator() { clean(); }

        double pressureMax;     
        double brakePedal;     
        double lag;     
        double gain;     
    public:
        HRESULT r_EngageProfile(double *res);             
        void init();             
        void clean();             
        void handle_pressureMax(const double t, const double* val);             
        void handle_brakePedal(const double t, const double* val);             
        void handle_lag(const double t, const double* val);             
        void handle_gain(const double t, const double* val);             
    protected:
        HRESULT InitEsos();             
        HRESULT InitLocalEqns();             
        HRESULT InitLocalADEqns();             
        HRESULT InitEqnForm(OnEqnForm* *form, OnEqnDiffForm* *diff_form);             
        HRESULT InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly);
        HRESULT InitLocalRPars(const _TCHAR* prefix, ppdouble *pars, ppchar *Names, long *nPars, long *dPars);             
    public:
        HRESULT ad_r_EngageProfile(Fdouble *res);             
    protected:
        void Save(FILE *fs);             
        bool Load(FILE *fs);             
        ActuatorClutchConnector* p;             
    //}}SCG_CLASS_PROPS
};

//}}SCG_CLASS

//}}SCG_HEADER      
#endif










