#ifndef __PLANETARYCOUPLER_H
#define __PLANETARYCOUPLER_H

//{{SCG_HEADER(PlanetaryCoupler.h) [0]

#include "OnAD.h"                    
#include "ShiftLogic.h"


//{{SCG_INCLUDE                     
#include "IOnVarInit.h"
#include "RtsOnTransmissionExport.h"

//}}SCG_INCLUDE

//{{SCG_FORWARD                    
class IOnVarInit;
//}}SCG_FORWARD


//{{SCG_CLASS(0)
//{{SCG_CLASS_INFO(0)

class RTSONTRANSMISSION_API PlanetaryCoupler 
                  :public IOnVarInit
//}}SCG_CLASS_INFO
{
    //{{SCG_CLASS_PROPS(0)
public:
    PlanetaryCoupler();
    ~PlanetaryCoupler();
    public:
        double torque;     
        double speed;     
        double inertia;     
        double acceleration;     
    public:
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
        double der_acceleration;     
        double old_acceleration;     
        double der_old_acceleration;     
        Fdouble ad_acceleration;     
        Fdouble der_ad_acceleration;     
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










