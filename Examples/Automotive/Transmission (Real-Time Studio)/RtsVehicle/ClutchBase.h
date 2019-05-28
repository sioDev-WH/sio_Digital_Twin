#ifndef __CLUTCHBASE_H
#define __CLUTCHBASE_H

//{{SCG_HEADER(ClutchBase.h) [0]
#include "OnUMLDaeEsoImpl.h"
class ActuatorClutchConnector;
class CRigidConnector;

//{{SCG_INCLUDE                     
#include "ShiftLogic.h"
#include "RtsSmInt.h"
//}}SCG_INCLUDE

//{{SCG_FORWARD                    

//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)



class ClutchBase 
                  
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)
    public:
        ActuatorClutchConnector* actuatorConnector;     
        CRigidConnector* n;     
        CRigidConnector* p;     
        double area;     
        double radius;     
        double relativeVelocity;     
        double cBreakfreeDisp;     
        double torqueRatio;     
        double damping;     
        double stiffness;     
        double displacement;     
        double frictionCoefficient;     
        double ccBreakfreeDisp;     
        double pressureMax;     
        double cBreakfreeDispMax;     
        double ccBreakfreeDispMax;     
        Fdouble ad_cBreakfreeDisp;     
        Fdouble ad_ccBreakfreeDisp;     
        Fdouble ad_displacement;     
        Fdouble ad_relativeVelocity;     
        bool bInConstruction;     
        double ccOilDisp;     
        double cOilDisp;     
        Fdouble der_ad_cBreakfreeDisp;     
        Fdouble der_ad_ccBreakfreeDisp;     
        Fdouble der_ad_displacement;     
        Fdouble der_ad_relativeVelocity;     
        double der_cBreakfreeDisp;     
        double der_ccBreakfreeDisp;     
        double der_displacement;     
        double der_old_cBreakfreeDisp;     
        double der_old_ccBreakfreeDisp;     
        double der_old_displacement;     
        double der_old_relativeVelocity;     
        double der_relativeVelocity;     
        double old_cBreakfreeDisp;     
        double old_ccBreakfreeDisp;     
        double old_displacement;     
        double old_relativeVelocity;     
        RtsClutchBaseClutch_States RtsCurrent_Clutch;     
        RtsMutex RtsBusy;     
        void es_LockToCCSlip();             
        HRESULT r_clockwiseBreakfreeDisp(double *res);             
        HRESULT r_counterclockwiseBreakfreeDisp(double *res);             
        void es_LockToCSlip();             
        void init();             
        HRESULT r_cSlipDisplacement(double *res);             
        HRESULT r_stickDisplacement(double *res);             
        HRESULT z_velocity_neg(double *res);             
        HRESULT z_velocity_pos(double *res);             
        HRESULT z_disp_pos_slip(double *res);             
        HRESULT z_disp_neg_slip(double *res);             
        void es_SlipToLock();             
        void clean();             
        HRESULT r_ccSlipDisplacement(double *res);             
        HRESULT r_forceBalance(double *res);             
        HRESULT r_relativeVelocity(double *res);             
        HRESULT ad_r_ccSlipDisplacement(Fdouble *res);             
        HRESULT ad_r_clockwiseBreakfreeDisp(Fdouble *res);             
        HRESULT ad_r_counterclockwiseBreakfreeDisp(Fdouble *res);             
        HRESULT ad_r_cSlipDisplacement(Fdouble *res);             
        HRESULT ad_r_forceBalance(Fdouble *res);             
        HRESULT ad_r_relativeVelocity(Fdouble *res);             
        HRESULT ad_r_stickDisplacement(Fdouble *res);             
        HRESULT ad_s_ccLockDisplacement(Fdouble *res);             
        HRESULT ad_s_cLockDisplacement(Fdouble *res);             
        HRESULT ad_z_disp_neg_slip(Fdouble *res);             
        HRESULT ad_z_disp_pos_slip(Fdouble *res);             
        HRESULT ad_z_velocity_neg(Fdouble *res);             
        HRESULT ad_z_velocity_pos(Fdouble *res);             
        virtual HRESULT OnTransition() = 0;             
    private:
        void RtsEnter_cSlip();             
        void RtsExit_cSlip();             
        void RtsEnter_Lock();             
        void RtsExit_Lock();             
        void RtsEnter_ccSlip();             
        void RtsExit_ccSlip();             
    public:
        ClutchBase();             
        ~ClutchBase();             
    private:
        void RtsRunToCompletion();             
    #ifdef RTS_SIMULATION
    static int RtsInjectEvent(const char* Event, const int NumParams, const StringArray params, ClutchBase *pInstance);             
#endif

    #ifdef RTS_SIMULATION
    static int RtsGetAttributeValue(const char* Name, char* Value, const int buflen, ClutchBase *pInstance);             
#endif

    #ifdef RTS_SIMULATION
    static int RtsSetAttributeValue(const char* Name, const char* Value, ClutchBase *pInstance);             
#endif

    public:
        HRESULT s_cLockDisplacement(double *res);             
        HRESULT s_ccLockDisplacement(double *res);             
    //}}SCG_CLASS_PROPS
};

//}}SCG_CLASS

//}}SCG_HEADER      
#endif










