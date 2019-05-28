/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: aeroFrame
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\aeroFrame.h
*********************************************************************/


#ifndef aeroFrame_H 

#define aeroFrame_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AirframePkg.h"
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "aeroPort.h"
#include "AtmoHeightPort.h"
#include "OnUMLDaeEsoImpl.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// aeroFrame.h                                                                  
//----------------------------------------------------------------------------

//## class aeroFrame 
class aeroFrame : public OMReactive, public COnUMLDaeEsoImpl<aeroFrame> {


////    Constructors and destructors    ////
public :
    
    //## operation aeroFrame() 
    aeroFrame(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~aeroFrame() 
    virtual ~aeroFrame();


////    Operations    ////
public :
    
    //## operation Load(FILE*) 
    bool Load(FILE*  fs);
    
    //## operation Save(FILE*) 
    void Save(FILE*  fs);
    
    //## operation clean() 
    void clean();
    
    //## operation handle_gravity(const double,const double*) 
    void handle_gravity(const double  t, const double*  val);
    
    //## operation handle_mass(const double,const double*) 
    void handle_mass(const double  t, const double*  val);
    
    //## operation init() 
    void init();
    
    //## operation r_Force(valarray<double>*) 
    HRESULT r_Force(valarray<double>*  res);
    
    //## operation r_Moments(valarray<double>*) 
    HRESULT r_Moments(valarray<double>*  res);
    
    //## operation r_Position(double * ) 
    HRESULT r_Position(double * res);

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
    
    //## operation ad_r_Force(valarray<Fdouble>*) 
    HRESULT ad_r_Force(valarray<Fdouble>*  res);
    
    //## operation ad_r_Moments(valarray<Fdouble>*) 
    HRESULT ad_r_Moments(valarray<Fdouble>*  res);
    
    //## operation ad_r_Position(Fdouble*) 
    HRESULT ad_r_Position(Fdouble*  res);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getGravity() const;
    
    //## auto_generated 
    void setGravity(double  p_gravity);
    
    //## auto_generated 
    double getMass() const;
    
    //## auto_generated 
    void setMass(double  p_mass);
    
    //## auto_generated 
    aeroPort* getP() const;
    
    //## auto_generated 
    AtmoHeightPort* getPh() const;


////    Framework operations    ////
public :
    
    //## auto_generated 
    virtual OMBoolean startBehavior();


////    Attributes    ////
protected :
    
    double gravity;		//## attribute gravity 
    
    double mass;		//## attribute mass 
    

////    Relations and components    ////
public :
    
    aeroPort p;		//## classInstance p 
    
    
    AtmoHeightPort ph;		//## classInstance ph 
    


};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\aeroFrame.h
*********************************************************************/

