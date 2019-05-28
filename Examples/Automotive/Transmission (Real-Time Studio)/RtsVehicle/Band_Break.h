#ifndef __BAND_BREAK_H
#define __BAND_BREAK_H


// Cg_Add
#include "ClutchBase.h"
#include "OnUMLDaeEsoImpl.h"
#include "RtsOnTransmissionExport.h"


class ClutchBase;
class ActuatorClutchConnector;



//{{SCG_HEADER(Band_Break.h) [0]



//{{SCG_INCLUDE                     
#include "ClutchBase.h"
//}}SCG_INCLUDE

//{{SCG_FORWARD                    
//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

class RTSONTRANSMISSION_API Band_Break 
                  :public COnUMLDaeEsoImpl<Band_Break>, public ClutchBase
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)
    public:
        double wrapAngle;     
    public:
        Band_Break();
        ~Band_Break();
        HRESULT r_StickFrictionTorque(double *res);             
        HRESULT r_cSlipFrictionTorque(double *res); 
        HRESULT r_ccSlipFrictionTorque(double *res); 

        void init();             
        void clean();             
        void handle_wrapAngle(const double t, const double* val);             
        void handle_area(const double t, const double* val);             
        void handle_radius(const double t, const double* val);             
        void handle_torqueRatio(const double t, const double* val);             
        void handle_damping(const double t, const double* val);             
        void handle_stiffness(const double t, const double* val);             
        void handle_frictionCoefficient(const double t, const double* val);             
        void handle_pressureMax(const double t, const double* val);             
        void handle_cBreakfreeDispMax(const double t, const double* val);             
        void handle_ccBreakfreeDispMax(const double t, const double* val);             
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
        HRESULT TriggerEvent(const double EventTime, const BSTR bstrEventId);             
        HRESULT EvalStateCondition(const bool* EqnState, const double* x, const double* xdot, const double EventTime, const long iDisEqn, const long iTransition, bool *bEvent);             
    public:
        HRESULT ad_r_StickFrictionTorque(Fdouble *res);             
        HRESULT ad_r_cSlipFrictionTorque(Fdouble *res);
        HRESULT ad_r_ccSlipFrictionTorque(Fdouble *res);
    //}}SCG_CLASS_PROPS
};
//}}SCG_CLASS

//}}SCG_HEADER      
#endif










