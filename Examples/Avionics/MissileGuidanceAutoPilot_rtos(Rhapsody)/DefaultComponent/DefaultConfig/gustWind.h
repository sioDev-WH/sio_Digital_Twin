/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: gustWind
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\gustWind.h
*********************************************************************/


#ifndef gustWind_H 

#define gustWind_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AirframePkg.h"
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "aeroPort.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// gustWind.h                                                                  
//----------------------------------------------------------------------------

//## class gustWind 
class gustWind : public OMReactive, public COnUMLDaeEsoImpl<gustWind> {


////    Constructors and destructors    ////
public :
    
    //## operation gustWind() 
    gustWind(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~gustWind() 
    virtual ~gustWind();


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
    
    //## operation r_thrust(valarray<double>*) 
    HRESULT r_thrust(valarray<double>*  res);

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
    
    //## operation ad_r_thrust(Fdouble*) 
    HRESULT ad_r_thrust(Fdouble*  res);


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
	File Path	: DefaultComponent\DefaultConfig\gustWind.h
*********************************************************************/

