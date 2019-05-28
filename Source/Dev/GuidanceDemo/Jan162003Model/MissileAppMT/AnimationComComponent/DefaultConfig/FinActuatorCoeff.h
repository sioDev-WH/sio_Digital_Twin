/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: FinActuatorCoeff
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\FinActuatorCoeff.h
*********************************************************************/


#ifndef FinActuatorCoeff_H 

#define FinActuatorCoeff_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "AirframePkg.h"
#include "IOnVarInit.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// FinActuatorCoeff.h                                                                  
//----------------------------------------------------------------------------

//## class FinActuatorCoeff 
class FinActuatorCoeff : public IOnVarInit {


////    Constructors and destructors    ////
public :
    
    //## operation FinActuatorCoeff() 
    FinActuatorCoeff();
    
    //## auto_generated 
    ~FinActuatorCoeff();


////    Operations    ////
public :
    
    //## operation InitLocalIPars(const _TCHAR * ,pplong * ,ppchar * ,long * ,long * ) 
    HRESULT InitLocalIPars(const _TCHAR * prefix, pplong * pars, ppchar * Names, long * nPars, long * dPars);
    
    //## operation InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ) 
    HRESULT InitLocalRPars(const _TCHAR * prefix, ppdouble * pars, ppchar * Names, long * nPars, long * dPars);
    
    //## operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    HRESULT InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly);
    
    //## operation init() 
    void init();


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getBandwidth() const;
    
    //## auto_generated 
    void setBandwidth(double  p_bandwidth);
    
    //## auto_generated 
    double getDamping() const;
    
    //## auto_generated 
    void setDamping(double  p_damping);
    
    //## auto_generated 
    double getGain() const;
    
    //## auto_generated 
    void setGain(double  p_gain);
    
    //## auto_generated 
    double getMax_angle() const;
    
    //## auto_generated 
    void setMax_angle(double  p_max_angle);
    
    //## auto_generated 
    double getMax_rate() const;
    
    //## auto_generated 
    void setMax_rate(double  p_max_rate);
    
    //## auto_generated 
    double getMin_angle() const;
    
    //## auto_generated 
    void setMin_angle(double  p_min_angle);


////    Attributes    ////
public :
    
    double bandwidth;		//## attribute bandwidth 
    
    double damping;		//## attribute damping 
    
    double gain;		//## attribute gain 
    
    // Max Fin Defelction (create a class that inherits from FinActuator, with saturations on demand and rates)
    double max_angle;		//## attribute max_angle 
    
    // Max rate of Fin Defelction
    double max_rate;		//## attribute max_rate 
    
    // Min Fin Defelction
    double min_angle;		//## attribute min_angle 
    

};


#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\FinActuatorCoeff.h
*********************************************************************/

