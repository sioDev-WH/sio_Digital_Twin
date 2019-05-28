#ifndef __GEAR_H
#define __GEAR_H

//{{SCG_HEADER(Gear.h) [0]

#include "OnAD.h"                    
#include "IOnVarInit.h"
#include "ShiftLogic.h"
#include "RtsOnTransmissionExport.h"

class Fdouble;
                 

//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

class RTSONTRANSMISSION_API Gear 
                  :public IOnVarInit
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)
public:
  Gear();
  ~Gear();
    public:
        double acceleration;     
        double radius;     
        double torque;     
        double speed;     
        long nTeeth;     
        double inertia;     
    public:
        double der_acceleration;     
        double old_acceleration;     
        double der_old_acceleration;     
        Fdouble ad_acceleration;     
        Fdouble der_ad_acceleration;     
        double der_torque;     
        double old_torque;     
        double der_old_torque;     
        Fdouble ad_torque;     
        Fdouble der_ad_torque;     
        double der_speed;     
        double old_speed;     
        double der_old_speed;     
        Fdouble ad_speed;     
        Fdouble der_ad_speed;     
        void init();             
    protected:

        HRESULT InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly);
        HRESULT InitLocalRPars(const _TCHAR* prefix, ppdouble *pars, ppchar *Names, long *nPars, long *dPars);             
        HRESULT InitLocalIPars(const _TCHAR* prefix, pplong *pars, ppchar *Names, long *nPars, long *dPars);             
    //}}SCG_CLASS_PROPS
};
//}}SCG_CLASS

//}}SCG_HEADER      
#endif










