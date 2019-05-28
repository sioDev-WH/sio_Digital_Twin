/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: ControlledReactor
//!	Generated Date	: Sun, 15, Sep 2002  
	File Path	: DefaultComponent\DefaultConfig\ControlledReactor.h
*********************************************************************/


#ifndef ControlledReactor_H 

#define ControlledReactor_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "ProcessModels.h"
#include "OnModel_ControlledReactor.h"

//## package ProcessModels 

//----------------------------------------------------------------------------
// ControlledReactor.h                                                                  
//----------------------------------------------------------------------------
class Controller;
class Fdouble;
class Heater;
class Reactor;


//## class ControlledReactor 
class ControlledReactor : public OnModel_ControlledReactor {


////    Constructors and destructors    ////
public :
    
    //## auto_generated 
    ControlledReactor();
    
    //## auto_generated 
    ~ControlledReactor();

    void init();
    void clean();

////    Operations    ////
public :
    
    //## operation r_ControllerTempBalance(double*) 
    HRESULT r_ControllerTempBalance(double*  res);
    
    //## operation r_FlowBalance(double) 
    HRESULT r_FlowBalance(double*  res);
    
    //## operation r_HeaterTempBalance(double*) 
    HRESULT r_HeaterTempBalance(double*  res);
    
    //## operation r_RecycleTempBalance(double*) 
    HRESULT r_RecycleTempBalance(double*  res);

protected :
    
    //## operation InitEqnForm(OnEqnForm**,OnEqnDiffForm**) 
    HRESULT InitEqnForm(OnEqnForm**  form, OnEqnDiffForm**  diff_form);
    
    //## operation InitEsos() 
    HRESULT InitEsos();
    
    //## operation InitLocalADEqns() 
    HRESULT InitLocalADEqns();
    
    //## operation InitLocalEqns() 
    HRESULT InitLocalEqns();
    
    //## operation InitLocalVars(_TCHAR*,ppdouble*,ppdouble*,ppdouble*,ppdouble*,ppfdouble*,ppfdouble*,ppchar*,long*,long*,long*,long*,bool) 
    HRESULT InitLocalVars(const _TCHAR* prefix, VarCont* varC, const bool bADOnly);
    
    //## operation Load(FILE*) 
    bool Load(FILE*  fs);
    
    //## operation Save(FILE*) 
    void Save(FILE*  fs);
    
    //## operation ad_r_ControllerTempBalance(Fdouble*) 
    HRESULT ad_r_ControllerTempBalance(Fdouble*  res);
    
    //## operation ad_r_FlowBalance(Fdouble*) 
    HRESULT ad_r_FlowBalance(Fdouble*  res);
    
    //## operation ad_r_HeaterTempBalance(Fdouble*) 
    HRESULT ad_r_HeaterTempBalance(Fdouble*  res);
    
    //## operation ad_r_RecycleTempBalance(Fdouble*) 
    HRESULT ad_r_RecycleTempBalance(Fdouble*  res);


////    Additional operations    ////
public :
    
    //## auto_generated 
    Controller* getItsController() const;
    
    //## auto_generated 
    void setItsController(Controller*  p_Controller);
    
    //## auto_generated 
    Heater* getItsHeater() const;
    
    //## auto_generated 
    void setItsHeater(Heater*  p_Heater);
    
    //## auto_generated 
    Reactor* getItsReactor() const;
    
    //## auto_generated 
    void setItsReactor(Reactor*  p_Reactor);


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Relations and components    ////
protected :
    
    Controller* itsController;		//## link itsController 
    
    
    Heater* itsHeater;		//## link itsHeater 
    
    
    Reactor* itsReactor;		//## link itsReactor 
    


};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\ControlledReactor.h
*********************************************************************/

