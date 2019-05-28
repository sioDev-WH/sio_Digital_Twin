/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: bodyDynamics
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\bodyDynamics.h
*********************************************************************/


#ifndef bodyDynamics_H 

#define bodyDynamics_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AirframePkg.h"
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "aeroPort.h"
#include "OnUMLDaeEsoImpl.h"
#include "aeroInertia.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// bodyDynamics.h                                                                  
//----------------------------------------------------------------------------

//## class bodyDynamics 
class bodyDynamics : public OMReactive, public COnUMLDaeEsoImpl<bodyDynamics> {


////    Constructors and destructors    ////
public :
    
    //## operation bodyDynamics() 
    bodyDynamics(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~bodyDynamics() 
    virtual ~bodyDynamics();


////    Operations    ////
public :
    
    //## operation Load(FILE*) 
    bool Load(FILE*  fs);
    
    //## operation Save(FILE*) 
    void Save(FILE*  fs);
    
    //## operation clean() 
    void clean();
    
    //## operation getAccel(const double ,double * ) 
    void getAccel(const double t, double * val);
    
    //## operation getAttitude(const double ,double * ) 
    void getAttitude(const double t, double * val);
    
    // temporary methods
    //## operation getGyro(const double ,double * ) 
    void getGyro(const double t, double * val);
    
    //## operation getX(const double ,double * ) 
    void getX(const double t, double * val);
    
    //## operation getZ(const double ,double * ) 
    void getZ(const double t, double * val);
    
    //## operation handle_mass(const double,const double*) 
    void handle_mass(const double  t, const double*  val);
    
    //## operation init() 
    void init();
    
    // Local Coordinates
    //## operation r_euler(valarray<double>*) 
    HRESULT r_euler(valarray<double>*  res);
    
    // Local Coordinates
    //## operation r_position(valarray<double>*) 
    HRESULT r_position(valarray<double>*  res);
    
    // Body Coordinates
    //## operation r_rate(valarray<double>*) 
    HRESULT r_rate(valarray<double>*  res);
    
    // Body Coordinates
    //## operation r_velocity(valarray<double>*) 
    HRESULT r_velocity(valarray<double>*  res);

protected :
    
    //## operation InitEqnForm(OnEqnForm**,OnEqnDiffForm**) 
    HRESULT InitEqnForm(OnEqnForm**  form, OnEqnDiffForm**  diff_form);
    
    //## operation InitEsos() 
    HRESULT InitEsos();
    
    //## operation InitLocalADEqns() 
    HRESULT InitLocalADEqns();
    
    //## operation InitLocalEqns() 
    HRESULT InitLocalEqns();
    
    //## operation InitLocalRPars(const _TCHAR*,ppdouble*,ppchar*,long*,long*) 
    HRESULT InitLocalRPars(const _TCHAR*  prefix, ppdouble*  pars, ppchar*  Names, long*  nPars, long*  dPars);
    
    //## operation InitLocalVars(const _TCHAR*,VarCont*,const bool) 
    HRESULT InitLocalVars(const _TCHAR*  prefix, VarCont*  varC, const bool  bADOnly);
    
    //## operation ad_r_euler(valarray<Fdouble>*) 
    HRESULT ad_r_euler(valarray<Fdouble>*  res);
    
    //## operation ad_r_position(valarray<Fdouble>*) 
    HRESULT ad_r_position(valarray<Fdouble>*  res);
    
    //## operation ad_r_rate(valarray<Fdouble>*) 
    HRESULT ad_r_rate(valarray<Fdouble>*  res);
    
    //## operation ad_r_velocity(valarray<Fdouble>*) 
    HRESULT ad_r_velocity(valarray<Fdouble>*  res);


////    Additional operations    ////
public :
    
    //## auto_generated 
    aeroInertia<double>  getInertia() const;
    
    //## auto_generated 
    void setInertia(aeroInertia<double> p_inertia);
    
    //## auto_generated 
    Matrix getInvInertia() const;
    
    //## auto_generated 
    void setInvInertia(Matrix  p_invInertia);
    
    //## auto_generated 
    bool  getInvReady() const;
    
    //## auto_generated 
    void setInvReady(bool p_invReady);
    
    //## auto_generated 
    double getMass() const;
    
    //## auto_generated 
    void setMass(double  p_mass);
    
    //## auto_generated 
    aeroPort* getP() const;


////    Framework operations    ////
public :
    
    //## auto_generated 
    virtual OMBoolean startBehavior();


////    Attributes    ////
public :
    
    aeroInertia<double> inertia;		//## attribute inertia 
    
    // coefficients
    double mass;		//## attribute mass 
    
protected :
    
    // coefficients
    Matrix invInertia;		//## attribute invInertia 
    
    bool invReady;		//## attribute invReady 
    

////    Relations and components    ////
public :
    
    // ports
    aeroPort p;		//## classInstance p 
    


};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\bodyDynamics.h
*********************************************************************/

