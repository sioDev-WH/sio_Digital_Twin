#ifndef __ONEWAY_CLUTCH_H
#define __ONEWAY_CLUTCH_H


#include "OnUMLDaeEsoImpl.h"
class CRigidConnector;

//{{SCG_HEADER(Oneway_Clutch.h) [0]

//{{SCG_INCLUDE                     
#include "ClutchBase.h"
#include "ShiftLogic.h"
#include "RtsOnTransmissionExport.h"

//}}SCG_INCLUDE

//{{SCG_FORWARD                    
class ClutchBase;
//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

class RTSONTRANSMISSION_API Oneway_Clutch 
                  :public COnUMLDaeEsoImpl<Oneway_Clutch>, public ClutchBase
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)
    public:
        Direction direction;     
        long nSurfaces;     
    public:
        Oneway_Clutch();
        ~Oneway_Clutch();
        void init();             
        HRESULT r_StickFrictionTorque(double *res);             
        HRESULT r_cSlipFrictionTorque(double *res);             
        HRESULT r_ccSlipFrictionTorque(double *res);             
        HRESULT s_cSlipDisplacement(double* res);
        HRESULT s_ccSlipDisplacement(double* res);

        HRESULT z_cSlipTorque(double* res);
        HRESULT z_ccSlipTorque(double* res);

        void clean();             
        void handle_nSurfaces(const double t, const long* val);             
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
        HRESULT InitLocalIPars(const _TCHAR* prefix, pplong *pars, ppchar *Names, long *nPars, long *dPars);             
        HRESULT InitTransitions();             
        HRESULT InitStates();             
        HRESULT OnTransition();             
        HRESULT TriggerEvent(const double EventTime, const BSTR bstrEventId);             
        HRESULT EvalStateCondition(const bool* EqnState, const double* x, const double* xdot, const double EventTime, const long iDisEqn, const long iTransition, bool *bEvent);             
    public:
        HRESULT ad_r_StickFrictionTorque(Fdouble *res);             
        HRESULT ad_r_cSlipFrictionTorque(Fdouble *res);             
        HRESULT ad_r_ccSlipFrictionTorque(Fdouble *res);             
        HRESULT ad_s_cSlipDisplacement(Fdouble* res);
        HRESULT ad_s_ccSlipDisplacement(Fdouble* res);
        HRESULT ad_z_cSlipTorque(Fdouble* res);
        HRESULT ad_z_ccSlipTorque(Fdouble* res);

//}}SCG_CLASS_PROPS
};
//}}SCG_CLASS

//}}SCG_HEADER      
#endif










