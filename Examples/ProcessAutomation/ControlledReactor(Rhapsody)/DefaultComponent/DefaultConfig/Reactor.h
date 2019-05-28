/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Reactor
//!	Generated Date	: Sun, 15, Sep 2002  
	File Path	: DefaultComponent\DefaultConfig\Reactor.h
*********************************************************************/


#ifndef Reactor_H 

#define Reactor_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "ProcessModels.h"
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "OnModel_Reactor.h"

//## package ProcessModels 

//----------------------------------------------------------------------------
// Reactor.h                                                                  
//----------------------------------------------------------------------------
class Fdouble;


//## class Reactor 
class Reactor : public OMReactive, public OnModel_Reactor {


////    Constructors and destructors    ////
public :
    
    //## auto_generated 
    Reactor(OMThread*  p_thread = OMDefaultThread);
    
    //## auto_generated 
    ~Reactor();


////    Operations    ////
public :
    
    //## operation get_Delta_H() 
    double get_Delta_H();
    
    //## operation get_K() 
    double get_K();
    
    //## operation handle_C_heptane_in(double,double*) 
    void handle_C_heptane_in(double  t, double*  val);
    
    //## operation handle_Cp(double,double*) 
    void handle_Cp(double  t, double*  val);
    
    //## operation handle_E0(double,double*) 
    void handle_E0(double  t, double*  val);
    
    //## operation handle_K0(double,double*) 
    void handle_K0(double  t, double*  val);
    
    //## operation handle_Q_heptane_in(double,double*) 
    void handle_Q_heptane_in(double  t, double*  val);
    
    //## operation handle_R(double,double*) 
    void handle_R(double  t, double*  val);
    
    //## operation handle_T_heptane_in(double,double*) 
    void handle_T_heptane_in(double  t, double*  val);
    
    //## operation handle_V(double,double*) 
    void handle_V(double  t, double*  val);
    
    //## operation handle_a(double,double*) 
    void handle_a(double  t, double*  val);
    
    //## operation handle_h(double,double*) 
    void handle_h(double  t, double*  val);
    
    //## operation handle_rho(double,double*) 
    void handle_rho(double  t, double*  val);
    
    //## operation r_ReactorEnergyBalance(double*) 
    HRESULT r_ReactorEnergyBalance(double*  res);
    
    //## operation r_ReactorMassBalance0(double*) 
    HRESULT r_ReactorMassBalance0(double*  res);
    
    //## operation r_ReactorMassBalance1(double*) 
    HRESULT r_ReactorMassBalance1(double*  res);
    
    //## operation r_ReactorMassBalance2(double*) 
    HRESULT r_ReactorMassBalance2(double*  res);

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
    
    
    //## operation ad_r_ReactorEnergyBalance(Fdouble*) 
    HRESULT ad_r_ReactorEnergyBalance(Fdouble*  res);
    
    //## operation ad_r_ReactorMassBalance0(Fdouble*) 
    HRESULT ad_r_ReactorMassBalance0(Fdouble*  res);
    
    //## operation ad_r_ReactorMassBalance1(Fdouble*) 
    HRESULT ad_r_ReactorMassBalance1(Fdouble*  res);
    
    //## operation ad_r_ReactorMassBalance2(Fdouble*) 
    HRESULT ad_r_ReactorMassBalance2(Fdouble*  res);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getC_heptane() const;
    
    //## auto_generated 
    void setC_heptane(double  p_C_heptane);
    
    //## auto_generated 
    double getC_heptane_in() const;
    
    //## auto_generated 
    void setC_heptane_in(double  p_C_heptane_in);
    
    //## auto_generated 
    double getC_hydrogen() const;
    
    //## auto_generated 
    void setC_hydrogen(double  p_C_hydrogen);
    
    //## auto_generated 
    double getC_toluene() const;
    
    //## auto_generated 
    void setC_toluene(double  p_C_toluene);
    
    //## auto_generated 
    double getCp() const;
    
    //## auto_generated 
    void setCp(double  p_Cp);
    
    //## auto_generated 
    double getDelta_H() const;
    
    //## auto_generated 
    void setDelta_H(double  p_Delta_H);
    
    //## auto_generated 
    double getE0() const;
    
    //## auto_generated 
    void setE0(double  p_E0);
    
    //## auto_generated 
    double getK() const;
    
    //## auto_generated 
    void setK(double  p_K);
    
    //## auto_generated 
    double getK0() const;
    
    //## auto_generated 
    void setK0(double  p_K0);
    
    //## auto_generated 
    double getQ_heptane_in() const;
    
    //## auto_generated 
    void setQ_heptane_in(double  p_Q_heptane_in);
    
    //## auto_generated 
    double getR() const;
    
    //## auto_generated 
    void setR(double  p_R);
    
    //## auto_generated 
    double getT_heptane_in() const;
    
    //## auto_generated 
    void setT_heptane_in(double  p_T_heptane_in);
    
    //## auto_generated 
    double getT_reactor(double t) const;
    
    //## auto_generated 
    void setT_reactor(double  p_T_reactor);
    
    //## auto_generated 
    double getT_recycle_in() const;
    
    //## auto_generated 
    void setT_recycle_in(double  p_T_recycle_in);
    
    //## auto_generated 
    double getV() const;
    
    //## auto_generated 
    void setV(double  p_V);
    
    //## auto_generated 
    double getA() const;
    
    //## auto_generated 
    void setA(double  p_a);
    
    //## auto_generated 
    double getH() const;
    
    //## auto_generated 
    void setH(double  p_h);
    
    //## auto_generated 
    double getRho() const;
    
    //## auto_generated 
    void setRho(double  p_rho);
    
    //## auto_generated 
    Fdouble getAd_C_heptane() const;
    
    //## auto_generated 
    Fdouble getAd_C_hydrogen() const;
    
    //## auto_generated 
    Fdouble getAd_C_toluene() const;
    
    //## auto_generated 
    Fdouble getAd_T_reactor() const;
    
    //## auto_generated 
    Fdouble getAd_T_recycle_in() const;
    
    //## auto_generated 
    Fdouble getDer_ad_C_heptane() const;
    
    //## auto_generated 
    Fdouble getDer_ad_C_hydrogen() const;
    
    //## auto_generated 
    Fdouble getDer_ad_C_toluene() const;
    
    //## auto_generated 
    Fdouble getDer_ad_T_reactor() const;
    
    //## auto_generated 
    Fdouble getDer_ad_T_recycle_in() const;

protected :
    
    //## auto_generated 
    double getDer_C_heptane() const;
    
    //## auto_generated 
    void setDer_C_heptane(double  p_der_C_heptane);
    
    //## auto_generated 
    double getDer_C_hydrogen() const;
    
    //## auto_generated 
    void setDer_C_hydrogen(double  p_der_C_hydrogen);
    
    //## auto_generated 
    double getDer_C_toluene() const;
    
    //## auto_generated 
    void setDer_C_toluene(double  p_der_C_toluene);
    
    //## auto_generated 
    double getDer_T_reactor() const;
    
    //## auto_generated 
    void setDer_T_reactor(double  p_der_T_reactor);
    
    //## auto_generated 
    double getDer_T_recycle_in() const;
    
    //## auto_generated 
    void setDer_T_recycle_in(double  p_der_T_recycle_in);
    
    //## auto_generated 
    double getDer_old_C_heptane() const;
    
    //## auto_generated 
    void setDer_old_C_heptane(double  p_der_old_C_heptane);
    
    //## auto_generated 
    double getDer_old_C_hydrogen() const;
    
    //## auto_generated 
    void setDer_old_C_hydrogen(double  p_der_old_C_hydrogen);
    
    //## auto_generated 
    double getDer_old_C_toluene() const;
    
    //## auto_generated 
    void setDer_old_C_toluene(double  p_der_old_C_toluene);
    
    //## auto_generated 
    double getDer_old_T_reactor() const;
    
    //## auto_generated 
    void setDer_old_T_reactor(double  p_der_old_T_reactor);
    
    //## auto_generated 
    double getDer_old_T_recycle_in() const;
    
    //## auto_generated 
    void setDer_old_T_recycle_in(double  p_der_old_T_recycle_in);
    
    //## auto_generated 
    double getOld_C_heptane() const;
    
    //## auto_generated 
    void setOld_C_heptane(double  p_old_C_heptane);
    
    //## auto_generated 
    double getOld_C_hydrogen() const;
    
    //## auto_generated 
    void setOld_C_hydrogen(double  p_old_C_hydrogen);
    
    //## auto_generated 
    double getOld_C_toluene() const;
    
    //## auto_generated 
    void setOld_C_toluene(double  p_old_C_toluene);
    
    //## auto_generated 
    double getOld_T_reactor() const;
    
    //## auto_generated 
    void setOld_T_reactor(double  p_old_T_reactor);
    
    //## auto_generated 
    double getOld_T_recycle_in() const;
    
    //## auto_generated 
    void setOld_T_recycle_in(double  p_old_T_recycle_in);


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
    
    double C_heptane;		//## attribute C_heptane 
    
    double C_heptane_in;		//## attribute C_heptane_in 
    
    double C_hydrogen;		//## attribute C_hydrogen 
    
    double C_toluene;		//## attribute C_toluene 
    
    double Cp;		//## attribute Cp 
    
    double Delta_H;		//## attribute Delta_H 
    
    double E0;		//## attribute E0 
    
    double K;		//## attribute K 
    
    double K0;		//## attribute K0 
    
    double Q_heptane_in;		//## attribute Q_heptane_in 
    
    double R;		//## attribute R 
    
    double T_heptane_in;		//## attribute T_heptane_in 
    
    // Temperature (K)
    double T_reactor;		//## attribute T_reactor 
    
    double T_recycle_in;		//## attribute T_recycle_in 
    
    double V;		//## attribute V 
    
    double a;		//## attribute a 
    
    double der_C_heptane;		//## attribute der_C_heptane 
    
    double der_C_hydrogen;		//## attribute der_C_hydrogen 
    
    double der_C_toluene;		//## attribute der_C_toluene 
    
    double der_T_reactor;		//## attribute der_T_reactor 
    
    double der_T_recycle_in;		//## attribute der_T_recycle_in 
    
    double der_old_C_heptane;		//## attribute der_old_C_heptane 
    
    double der_old_C_hydrogen;		//## attribute der_old_C_hydrogen 
    
    double der_old_C_toluene;		//## attribute der_old_C_toluene 
    
    double der_old_T_reactor;		//## attribute der_old_T_reactor 
    
    double der_old_T_recycle_in;		//## attribute der_old_T_recycle_in 
    
    double h;		//## attribute h 
    
    double old_C_heptane;		//## attribute old_C_heptane 
    
    double old_C_hydrogen;		//## attribute old_C_hydrogen 
    
    double old_C_toluene;		//## attribute old_C_toluene 
    
    double old_T_reactor;		//## attribute old_T_reactor 
    
    double old_T_recycle_in;		//## attribute old_T_recycle_in 
    
    double rho;		//## attribute rho 
    

////    Relations and components    ////
public :
    
    Fdouble ad_C_heptane;		//## classInstance ad_C_heptane 
    
    
    Fdouble ad_C_hydrogen;		//## classInstance ad_C_hydrogen 
    
    
    Fdouble ad_C_toluene;		//## classInstance ad_C_toluene 
    
    
    Fdouble ad_T_reactor;		//## classInstance ad_T_reactor 
    
    
    Fdouble ad_T_recycle_in;		//## classInstance ad_T_recycle_in 
    
    
    Fdouble der_ad_C_heptane;		//## classInstance der_ad_C_heptane 
    
    
    Fdouble der_ad_C_hydrogen;		//## classInstance der_ad_C_hydrogen 
    
    
    Fdouble der_ad_C_toluene;		//## classInstance der_ad_C_toluene 
    
    
    Fdouble der_ad_T_reactor;		//## classInstance der_ad_T_reactor 
    
    
    Fdouble der_ad_T_recycle_in;		//## classInstance der_ad_T_recycle_in 
    


};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Reactor.h
*********************************************************************/

