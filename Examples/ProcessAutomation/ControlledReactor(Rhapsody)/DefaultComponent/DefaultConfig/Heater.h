/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Heater
//!	Generated Date	: Sun, 15, Sep 2002  
	File Path	: DefaultComponent\DefaultConfig\Heater.h
*********************************************************************/


#ifndef Heater_H 

#define Heater_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "ProcessModels.h"
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "OnModel_Heater.h"

//## package ProcessModels 

//----------------------------------------------------------------------------
// Heater.h                                                                  
//----------------------------------------------------------------------------
class Controller;
class Fdouble;


//## class Heater 
class Heater : public OMReactive, public OnModel_Heater {


////    Constructors and destructors    ////
public :
    
    //## auto_generated 
    Heater(OMThread*  p_thread = OMDefaultThread);
    
    //## auto_generated 
    ~Heater();


////    Operations    ////
public :
    
    //## operation handle_Gain(double,double*) 
    void handle_Gain(double  t, double*  val);
    
    //## operation handle_Recycle_Ratio(double,double*) 
    void handle_Recycle_Ratio(double  t, double*  val);
    
    //## operation handle_Sh(double,double*) 
    void handle_Sh(double  t, double*  val);
    
    //## operation handle_tau(double,double*) 
    void handle_tau(double  t, double*  val);
    
    //## operation r_HeaterEnergyBalance(double*) 
    HRESULT r_HeaterEnergyBalance(double*  res);

public :    
    
    //## operation Load(FILE*) 
    bool Load(FILE*  fs);
    
    //## operation Save(FILE*) 
    void Save(FILE*  fs);

protected :
    
    //## operation InitEqnForm(OnEqnForm**,OnEqnDiffForm**) 
    HRESULT InitEqnForm(OnEqnForm**  form, OnEqnDiffForm**  diff_form);
    
    //## operation InitLocalADEqns() 
    HRESULT InitLocalADEqns();
    
    //## operation InitLocalEqns() 
    HRESULT InitLocalEqns();
    
    //## operation InitLocalRPars(_TCHAR*,ppdouble*,ppchar*,long*,long*) 
    HRESULT InitLocalRPars(const _TCHAR*  prefix, ppdouble*  pars, ppchar*  Names, long*  nPars, long*  dPars);
    
    //## operation InitLocalVars(_TCHAR*,ppdouble*,ppdouble*,ppdouble*,ppdouble*,ppfdouble*,ppfdouble*,ppchar*,long*,long*,long*,long*,bool) 
    HRESULT InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly);
    
    
    //## operation ad_r_HeaterEnergyBalance(Fdouble*) 
    HRESULT ad_r_HeaterEnergyBalance(Fdouble*  res);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getGain() const;
    
    //## auto_generated 
    void setGain(double  p_Gain);
    
    //## auto_generated 
    double getQ_in() const;
    
    //## auto_generated 
    void setQ_in(double  p_Q_in);
    
    //## auto_generated 
    double getRecycle_Ratio() const;
    
    //## auto_generated 
    void setRecycle_Ratio(double  p_Recycle_Ratio);
    
    //## auto_generated 
    double getSh() const;
    
    //## auto_generated 
    void setSh(double  p_Sh);
    
    //## auto_generated 
    double getT_heater() const;
    
    //## auto_generated 
    void setT_heater(double  p_T_heater);
    
    //## auto_generated 
    double getT_in() const;
    
    //## auto_generated 
    void setT_in(double  p_T_in);
    
    //## auto_generated 
    double getTau() const;
    
    //## auto_generated 
    void setTau(double  p_tau);
    
    //## auto_generated 
    Fdouble getAd_Q_in() const;
    
    //## auto_generated 
    Fdouble getAd_T_heater() const;
    
    //## auto_generated 
    Fdouble getAd_T_in() const;
    
    //## auto_generated 
    Fdouble getDer_ad_Q_in() const;
    
    //## auto_generated 
    Fdouble getDer_ad_T_heater() const;
    
    //## auto_generated 
    Fdouble getDer_ad_T_in() const;

protected :
    
    //## auto_generated 
    double getDer_Q_in() const;
    
    //## auto_generated 
    void setDer_Q_in(double  p_der_Q_in);
    
    //## auto_generated 
    double getDer_T_heater() const;
    
    //## auto_generated 
    void setDer_T_heater(double  p_der_T_heater);
    
    //## auto_generated 
    double getDer_T_in() const;
    
    //## auto_generated 
    void setDer_T_in(double  p_der_T_in);
    
    //## auto_generated 
    double getDer_old_Q_in() const;
    
    //## auto_generated 
    void setDer_old_Q_in(double  p_der_old_Q_in);
    
    //## auto_generated 
    double getDer_old_T_heater() const;
    
    //## auto_generated 
    void setDer_old_T_heater(double  p_der_old_T_heater);
    
    //## auto_generated 
    double getDer_old_T_in() const;
    
    //## auto_generated 
    void setDer_old_T_in(double  p_der_old_T_in);
    
    //## auto_generated 
    double getOld_Q_in() const;
    
    //## auto_generated 
    void setOld_Q_in(double  p_old_Q_in);
    
    //## auto_generated 
    double getOld_T_heater() const;
    
    //## auto_generated 
    void setOld_T_heater(double  p_old_T_heater);
    
    //## auto_generated 
    double getOld_T_in() const;
    
    //## auto_generated 
    void setOld_T_in(double  p_old_T_in);


////    Framework operations    ////
public :
    
    //## auto_generated 
    virtual OMBoolean startBehavior();

protected :
    
    //## auto_generated 
    void initRelations();
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
public :
    
    double Gain;		//## attribute Gain 
    
    double Q_in;		//## attribute Q_in 
    
    double Recycle_Ratio;		//## attribute Recycle_Ratio 
    
    double Sh;		//## attribute Sh 
    
    double T_heater;		//## attribute T_heater 
    
    double T_in;		//## attribute T_in 
    
    double der_Q_in;		//## attribute der_Q_in 
    
    double der_T_heater;		//## attribute der_T_heater 
    
    double der_T_in;		//## attribute der_T_in 
    
    double der_old_Q_in;		//## attribute der_old_Q_in 
    
    double der_old_T_heater;		//## attribute der_old_T_heater 
    
    double der_old_T_in;		//## attribute der_old_T_in 
    
    double old_Q_in;		//## attribute old_Q_in 
    
    double old_T_heater;		//## attribute old_T_heater 
    
    double old_T_in;		//## attribute old_T_in 
    
    double tau;		//## attribute tau 
    

////    Relations and components    ////
public :
    
    Fdouble ad_Q_in;		//## classInstance ad_Q_in 
    
    
    Fdouble ad_T_heater;		//## classInstance ad_T_heater 
    
    
    Fdouble ad_T_in;		//## classInstance ad_T_in 
    
    
    Fdouble der_ad_Q_in;		//## classInstance der_ad_Q_in 
    
    
    Fdouble der_ad_T_heater;		//## classInstance der_ad_T_heater 
    
    
    Fdouble der_ad_T_in;		//## classInstance der_ad_T_in 


};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Heater.h
*********************************************************************/

