#ifndef __RAVIGNEAUX_H
#define __RAVIGNEAUX_H


#include "ClutchBase.h"
#include "OnUMLDaeEsoImpl.h"
#include "Gear.h"
#include "PlanetaryCoupler.h"
#include "RtsOnTransmissionExport.h"


//{{SCG_HEADER(Ravigneaux.h) [0]

//{{SCG_INCLUDE                     
//}}SCG_INCLUDE

//{{SCG_FORWARD                    
//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

class RTSONTRANSMISSION_API Ravigneaux 
                  :public COnUMLDaeEsoImpl<Ravigneaux>
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)

public:
  Ravigneaux();
  ~Ravigneaux();
    public:
        double pinionToPinionForce;     
        double ringToPinionForce;     
        double pinionToReverseForce;     
        double forwardToPinionForce;     
        CRigidConnector* ifSun;     
        CRigidConnector* irSun;     
        CRigidConnector* iCoupler;     
        CRigidConnector* oRing;     
    public:
        double der_pinionToPinionForce;     
        double old_pinionToPinionForce;     
        double der_old_pinionToPinionForce;     
        Fdouble ad_pinionToPinionForce;     
        Fdouble der_ad_pinionToPinionForce;     
        double der_ringToPinionForce;     
        double old_ringToPinionForce;     
        double der_old_ringToPinionForce;     
        Fdouble ad_ringToPinionForce;     
        Fdouble der_ad_ringToPinionForce;     
        double der_pinionToReverseForce;     
        double old_pinionToReverseForce;     
        double der_old_pinionToReverseForce;     
        Fdouble ad_pinionToReverseForce;     
        Fdouble der_ad_pinionToReverseForce;     
        double der_forwardToPinionForce;     
        double old_forwardToPinionForce;     
        double der_old_forwardToPinionForce;     
        Fdouble ad_forwardToPinionForce;     
        Fdouble der_ad_forwardToPinionForce;     
    public:
        Gear forwardSun;     
        Gear reverseSun;     
        PlanetaryCoupler carrier;     
        Gear shortPinion;     
        Gear longPinion;     
        Gear ring;     
    public:
        HRESULT r_ifSunTorque(double *res);             
        HRESULT r_iCouplerAcceleration(double *res);             
        HRESULT r_ifSunSpeed(double *res);             
        HRESULT r_irSunAcceleration(double *res);             
        HRESULT r_irSunSpeed(double *res);             
        HRESULT r_irSunTorque(double *res);             
        HRESULT r_oRingTorque(double *res);             
        HRESULT r_oRingAcceleration(double *res);             
        HRESULT r_oRingSpeed(double *res);             
        HRESULT r_iCouplerSpeed(double *res);             
        HRESULT r_iCouplerTorque(double *res);             
        HRESULT r_ifSunAcceleration(double *res);             
        HRESULT r_longPinionSpeed(double *res);             
        HRESULT r_longPinionTorque(double *res);             
        HRESULT r_shortPinionSpeed(double *res);             
        HRESULT r_shortPinionTorque(double *res);             
        HRESULT r_ReverseToPinionKinematics(double *res);             
        HRESULT r_ForwardSunDynamics(double *res);             
        HRESULT r_ShortPinionDynamics(double *res);             
        HRESULT r_LongPinionDynamics(double *res);             
        void clean();             
        HRESULT r_ForwardToPinionKinematics(double *res);             
        HRESULT r_PinionToPinionKinematics(double *res);             
        HRESULT r_PinionToRingKinematics(double *res);             
        HRESULT r_CarrierDynamics(double *res);             
        HRESULT r_ReverseSunDynamics(double *res);             
        HRESULT r_RingDynamics(double *res);             
        void init();             
        void Save(FILE* fs) { }
        bool Load(FILE* fs) { return true; }
    protected:


        HRESULT InitEsos();             
        HRESULT InitLocalEqns();             
        HRESULT InitLocalADEqns();             
        HRESULT InitEqnForm(OnEqnForm* *form, OnEqnDiffForm* *diff_form);             
        HRESULT InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly);             
    public:
        HRESULT ad_r_ifSunTorque(Fdouble *res);             
        HRESULT ad_r_iCouplerAcceleration(Fdouble *res);             
        HRESULT ad_r_ifSunSpeed(Fdouble *res);             
        HRESULT ad_r_irSunAcceleration(Fdouble *res);             
        HRESULT ad_r_irSunSpeed(Fdouble *res);             
        HRESULT ad_r_irSunTorque(Fdouble *res);             
        HRESULT ad_r_oRingTorque(Fdouble *res);             
        HRESULT ad_r_oRingAcceleration(Fdouble *res);             
        HRESULT ad_r_oRingSpeed(Fdouble *res);             
        HRESULT ad_r_iCouplerSpeed(Fdouble *res);             
        HRESULT ad_r_iCouplerTorque(Fdouble *res);             
        HRESULT ad_r_ifSunAcceleration(Fdouble *res);             
        HRESULT ad_r_longPinionSpeed(Fdouble *res);             
        HRESULT ad_r_longPinionTorque(Fdouble *res);             
        HRESULT ad_r_shortPinionSpeed(Fdouble *res);             
        HRESULT ad_r_shortPinionTorque(Fdouble *res);             
        HRESULT ad_r_ReverseToPinionKinematics(Fdouble *res);             
        HRESULT ad_r_ForwardSunDynamics(Fdouble *res);             
        HRESULT ad_r_ShortPinionDynamics(Fdouble *res);             
        HRESULT ad_r_LongPinionDynamics(Fdouble *res);             
        HRESULT ad_r_ForwardToPinionKinematics(Fdouble *res);             
        HRESULT ad_r_PinionToPinionKinematics(Fdouble *res);             
        HRESULT ad_r_PinionToRingKinematics(Fdouble *res);             
        HRESULT ad_r_CarrierDynamics(Fdouble *res);             
        HRESULT ad_r_ReverseSunDynamics(Fdouble *res);             
        HRESULT ad_r_RingDynamics(Fdouble *res);             
    //}}SCG_CLASS_PROPS
};
//}}SCG_CLASS

//}}SCG_HEADER      
#endif










