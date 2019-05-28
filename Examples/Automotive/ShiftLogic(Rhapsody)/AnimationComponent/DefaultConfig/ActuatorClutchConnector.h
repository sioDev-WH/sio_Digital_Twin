/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: ActuatorClutchConnector
//!	Generated Date	: Wed, 8, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\ActuatorClutchConnector.h
*********************************************************************/


#ifndef ActuatorClutchConnector_H 

#define ActuatorClutchConnector_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "TransmissionModels.h"
#include "TransmissionControlModels.h"
#include "OnUMLConnectorImpl.h"

//## package TransmissionModels 

//----------------------------------------------------------------------------
// ActuatorClutchConnector.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedActuatorClutchConnector;
#endif // _OMINSTRUMENT


// 
//## class ActuatorClutchConnector 
class ActuatorClutchConnector : public COnUMLConnectorImpl<ActuatorClutchConnector> {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedActuatorClutchConnector;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation ActuatorClutchConnector() 
    ActuatorClutchConnector();
    
    //## operation ~ActuatorClutchConnector() 
    ~ActuatorClutchConnector();


////    Operations    ////
public :
    
    //## operation GetADResidual(long,double,Fdouble * ) 
    HRESULT GetADResidual(long  iEqn, double  t, Fdouble * residual);
    
    //## operation GetResiduals(long * ,long,double,double * ) 
    HRESULT GetResiduals(long * iEqns, long  nEqn, double  t, double * residuals);
    
    //## operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
    HRESULT InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form);
    
    //## operation InitLocalADEqns() 
    HRESULT InitLocalADEqns();
    
    //## operation InitLocalEqns() 
    HRESULT InitLocalEqns();
    
    //## operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    HRESULT InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly);
    
    //## operation Load(FILE * ) 
    bool Load(FILE * fs);
    
    //## operation Save(FILE * ) 
    void Save(FILE * fs);
    
    //## operation clean() 
    void clean();
    
    //## operation init() 
    void init();


////    Additional operations    ////
public :
    
    //## auto_generated 
    VarEx get_pressure() const;
    
    //## auto_generated 
    void set_pressure(VarEx  p__pressure);
    
    //## auto_generated 
    double getPressure() const;
    
    //## auto_generated 
    void setPressure(double  p_pressure);


////    Attributes    ////
public :
    
    VarEx _pressure;		//## attribute _pressure 
    
    double pressure;		//## attribute pressure 
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedActuatorClutchConnector : virtual public AOMInstance {

    
    DECLARE_META(ActuatorClutchConnector, OMAnimatedActuatorClutchConnector)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\ActuatorClutchConnector.h
*********************************************************************/

