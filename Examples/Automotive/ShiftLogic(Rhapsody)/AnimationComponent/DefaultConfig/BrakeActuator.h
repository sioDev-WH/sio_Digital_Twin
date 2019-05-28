/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: BrakeActuator
//!	Generated Date	: Wed, 8, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\BrakeActuator.h
*********************************************************************/


#ifndef BrakeActuator_H 

#define BrakeActuator_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "TransmissionModels.h"
#include "TransmissionControlModels.h"
#include "OnUMLDaeEsoImpl.h"

//## package TransmissionModels 

//----------------------------------------------------------------------------
// BrakeActuator.h                                                                  
//----------------------------------------------------------------------------
class ActuatorClutchConnector;

#ifdef _OMINSTRUMENT
class OMAnimatedBrakeActuator;
#endif // _OMINSTRUMENT


//## class BrakeActuator 
class BrakeActuator : public COnUMLDaeEsoImpl<BrakeActuator> {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedBrakeActuator;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation BrakeActuator() 
    BrakeActuator();
    
    //## operation ~BrakeActuator() 
    ~BrakeActuator();


////    Operations    ////
public :
    
    //## operation ad_r_EngageProfile(Fdouble * ) 
    HRESULT ad_r_EngageProfile(Fdouble * res);
    
    //## operation clean() 
    void clean();
    
    //## operation handle_brakePedal(const double ,const double * ) 
    void handle_brakePedal(const double t, const double * val);
    
    //## operation handle_gain(const double ,const double * ) 
    void handle_gain(const double t, const double * val);
    
    //## operation handle_lag(const double ,const double * ) 
    void handle_lag(const double t, const double * val);
    
    //## operation handle_pressureMax(const double ,const double * ) 
    void handle_pressureMax(const double t, const double * val);
    
    //## operation init() 
    void init();
    
    //## operation r_EngageProfile(double * ) 
    HRESULT r_EngageProfile(double * res);

protected :
    
    //## operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
    HRESULT InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form);
    
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
    
    //## operation Load(FILE * ) 
    bool Load(FILE * fs);
    
    //## operation Save(FILE * ) 
    void Save(FILE * fs);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getBrakePedal() const;
    
    //## auto_generated 
    void setBrakePedal(double  p_brakePedal);
    
    //## auto_generated 
    double getGain() const;
    
    //## auto_generated 
    void setGain(double  p_gain);
    
    //## auto_generated 
    double getLag() const;
    
    //## auto_generated 
    void setLag(double  p_lag);
    
    //## auto_generated 
    double getPressureMax() const;
    
    //## auto_generated 
    void setPressureMax(double  p_pressureMax);
    
    //## auto_generated 
    ActuatorClutchConnector* getP() const;
    
    //## auto_generated 
    void setP(ActuatorClutchConnector*  p_ActuatorClutchConnector);


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
public :
    
    double brakePedal;		//## attribute brakePedal 
    
    double gain;		//## attribute gain 
    
    double lag;		//## attribute lag 
    
    double pressureMax;		//## attribute pressureMax 
    

////    Relations and components    ////
protected :
    
    ActuatorClutchConnector* p;		//## link p 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedBrakeActuator : virtual public AOMInstance {

    
    DECLARE_META(BrakeActuator, OMAnimatedBrakeActuator)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\BrakeActuator.h
*********************************************************************/

