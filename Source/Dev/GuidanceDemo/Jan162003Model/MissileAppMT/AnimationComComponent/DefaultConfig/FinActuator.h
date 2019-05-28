/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: FinActuator
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\FinActuator.h
*********************************************************************/


#ifndef FinActuator_H 

#define FinActuator_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "AirframePkg.h"
#include "OnUMLDaeEsoImpl.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// FinActuator.h                                                                  
//----------------------------------------------------------------------------
class FinActuatorCoeff;
class On1DConn;


//## class FinActuator 
class FinActuator : public COnUMLDaeEsoImpl<FinActuator> {


////    Constructors and destructors    ////
public :
    
    //## operation FinActuator() 
    FinActuator();
    
    //## operation ~FinActuator() 
    virtual ~FinActuator();


////    Operations    ////
public :
    
    //## operation Load(FILE * ) 
    bool Load(FILE * fs);
    
    // simulation load / save
    //## operation Save(FILE * ) 
    void Save(FILE * fs);
    
    //## operation clean() 
    void clean();
    
    //## operation init() 
    void init();
    
    //## operation r_angle(double * ) 
    HRESULT r_angle(double * res);
    
    //## operation r_rate(double * ) 
    HRESULT r_rate(double * res);
    
    //## operation setAngleSetpoint(const double ,double * ) 
    void setAngleSetpoint(const double time, double * val);

protected :
    
    //## operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
    HRESULT InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form);
    
    // model initialization
    //## operation InitEsos() 
    HRESULT InitEsos();
    
    //## operation InitLocalADEqns() 
    HRESULT InitLocalADEqns();
    
    //## operation InitLocalEqns() 
    HRESULT InitLocalEqns();
    
    //## operation InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ) 
    HRESULT InitLocalRPars(const _TCHAR * prefix, ppdouble * pars, ppchar * Names, long * nPars, long * dPars);
    
    //## operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    HRESULT InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly);
    
    //## operation ad_r_angle(Fdouble * ) 
    HRESULT ad_r_angle(Fdouble * res);
    
    //## operation ad_r_rate(Fdouble * ) 
    HRESULT ad_r_rate(Fdouble * res);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getAngleSetpoint() const;
    
    //## auto_generated 
    void setAngleSetpoint(double  p_AngleSetpoint);
    
    //## auto_generated 
    VarEx  get_rate() const;
    
    //## auto_generated 
    void set_rate(VarEx p__rate);
    
    //## auto_generated 
    double getRate() const;
    
    //## auto_generated 
    void setRate(double  p_rate);
    
    //## auto_generated 
    FinActuatorCoeff* getPCoeff() const;
    
    //## auto_generated 
    void setPCoeff(FinActuatorCoeff*  p_FinActuatorCoeff);
    
    //## auto_generated 
    On1DConn* getPFinConn() const;
    
    //## auto_generated 
    void setPFinConn(On1DConn*  p_On1DConn);


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
public :
    
    // parameter
    double AngleSetpoint;		//## attribute AngleSetpoint 
    
    VarEx _rate;		//## attribute _rate 
    
    // variables
    double rate;		//## attribute rate 
    

////    Relations and components    ////
public :
    
    FinActuatorCoeff* pCoeff;		//## link pCoeff 
    
    
    On1DConn* pFinConn;		//## link pFinConn 
    


};


#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\FinActuator.h
*********************************************************************/

