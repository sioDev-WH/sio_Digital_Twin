/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: engineDynamics
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\engineDynamics.h
*********************************************************************/


#ifndef engineDynamics_H 

#define engineDynamics_H 


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

//## package AirframePkg 

//----------------------------------------------------------------------------
// engineDynamics.h                                                                  
//----------------------------------------------------------------------------

//## class engineDynamics 
class engineDynamics : public OMReactive, public COnUMLDaeEsoImpl<engineDynamics> {


////    Constructors and destructors    ////
public :
    
    //## operation engineDynamics() 
    engineDynamics(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~engineDynamics() 
    virtual ~engineDynamics();


////    Operations    ////
public :
    
    //## operation Load(FILE*) 
    bool Load(FILE*  fs);
    
    //## operation Save(FILE*) 
    void Save(FILE*  fs);
    
    //## operation clean() 
    void clean();
    
    //## operation init() 
    void init();
    
    //## operation r_Force(valarray<double>*) 
    HRESULT r_Force(valarray<double>*  res);
    
    //## operation r_Moments(valarray<double>*) 
    HRESULT r_Moments(valarray<double>*  res);

protected :
    
    //## operation InitEqnForm(OnEqnForm**,OnEqnDiffForm**) 
    HRESULT InitEqnForm(OnEqnForm**  form, OnEqnDiffForm**  diff_form);
    
    //## operation InitEsos() 
    HRESULT InitEsos();
    
    //## operation InitLocalADEqns() 
    HRESULT InitLocalADEqns();
    
    //## operation InitLocalEqns() 
    HRESULT InitLocalEqns();
    
    //## operation InitLocalVars(const _TCHAR*,VarCont*,const bool) 
    HRESULT InitLocalVars(const _TCHAR*  prefix, VarCont*  varC, const bool  bADOnly);
    
    //## operation ad_r_Force(valarray<Fdouble>*) 
    HRESULT ad_r_Force(valarray<Fdouble>*  res);
    
    //## operation ad_r_Moments(valarray<Fdouble>*) 
    HRESULT ad_r_Moments(valarray<Fdouble>*  res);


////    Additional operations    ////
public :
    
    //## auto_generated 
    aeroPort* getP() const;


////    Framework operations    ////
public :
    
    //## auto_generated 
    virtual OMBoolean startBehavior();


////    Relations and components    ////
public :
    
    // ports
    aeroPort p;		//## classInstance p 
    


};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\engineDynamics.h
*********************************************************************/

