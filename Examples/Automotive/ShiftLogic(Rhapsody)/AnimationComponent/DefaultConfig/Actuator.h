/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Actuator
//!	Generated Date	: Wed, 8, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Actuator.h
*********************************************************************/


#ifndef Actuator_H 

#define Actuator_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "TransmissionModels.h"
#include <oxf/omthread.h>
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "TransmissionControlModels.h"
#include "OnUMLDaeEsoImpl.h"

//## package TransmissionModels 

//----------------------------------------------------------------------------
// Actuator.h                                                                  
//----------------------------------------------------------------------------
class ActuatorClutchConnector;

#ifdef _OMINSTRUMENT
class OMAnimatedActuator;
#endif // _OMINSTRUMENT


//## class Actuator 
class Actuator : public OMReactive, public COnUMLDaeEsoImpl<Actuator> {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedActuator;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation Actuator() 
    Actuator(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~Actuator() 
    ~Actuator();


////    Operations    ////
public :
    
    //## operation Load(FILE * ) 
    bool Load(FILE * fs);
    
    //## operation Save(FILE * ) 
    void Save(FILE * fs);
    
    //## operation SetShiftPeriod(double) 
    void SetShiftPeriod(double  val);
    
    //## operation ad_r_DisengageProfile(Fdouble * ) 
    HRESULT ad_r_DisengageProfile(Fdouble * res);
    
    //## operation ad_r_EngageProfile(Fdouble * ) 
    HRESULT ad_r_EngageProfile(Fdouble * res);
    
    //## operation ad_r_ShiftTime(Fdouble * ) 
    HRESULT ad_r_ShiftTime(Fdouble * res);
    
    //## operation ad_r_WaitProfile(Fdouble * ) 
    HRESULT ad_r_WaitProfile(Fdouble * res);
    
    //## operation ad_s_ShiftTime(Fdouble * ) 
    HRESULT ad_s_ShiftTime(Fdouble * res);
    
    //## operation clean() 
    void clean();
    
    //## operation handle_pressureMax(const double ,double * ) 
    void handle_pressureMax(const double t, double * val);
    
    //## operation handle_rate(const double ,double * ) 
    void handle_rate(const double t, double * val);
    
    //## operation handle_shiftEvent(const double ,long * ) 
    void handle_shiftEvent(const double t, long * val);
    
    //## operation handle_shiftPeriod(const double ,double * ) 
    void handle_shiftPeriod(const double t, double * val);
    
    //## operation handle_tolerance(const double ,double * ) 
    void handle_tolerance(const double t, double * val);
    
    //## operation init() 
    void init();
    
    //## operation r_DisengageProfile(double * ) 
    HRESULT r_DisengageProfile(double * res);
    
    //## operation r_EngageProfile(double * ) 
    HRESULT r_EngageProfile(double * res);
    
    //## operation r_ShiftTime(double * ) 
    HRESULT r_ShiftTime(double * res);
    
    //## operation r_WaitProfile(double * ) 
    HRESULT r_WaitProfile(double * res);
    
    //## operation s_ShiftTime(double * ) 
    HRESULT s_ShiftTime(double * res);

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
    
    //## operation InitStates() 
    HRESULT InitStates();
    
    //## operation InitTransitions() 
    HRESULT InitTransitions();
    
    //## operation OnTransition() 
    HRESULT OnTransition();
    
    //## operation TriggerEvent(const double ,const BSTR ) 
    HRESULT TriggerEvent(const double EventTime, const BSTR bstrEventId);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getPressureMax() const;
    
    //## auto_generated 
    void setPressureMax(double  p_pressureMax);
    
    //## auto_generated 
    double getRate() const;
    
    //## auto_generated 
    void setRate(double  p_rate);
    
    //## auto_generated 
    double getShiftPeriod() const;
    
    //## auto_generated 
    void setShiftPeriod(double  p_shiftPeriod);
    
    //## auto_generated 
    double getShiftTime() const;
    
    //## auto_generated 
    void setShiftTime(double  p_shiftTime);
    
    //## auto_generated 
    double getTolerance() const;
    
    //## auto_generated 
    void setTolerance(double  p_tolerance);
    
    //## auto_generated 
    ActuatorClutchConnector* getClutchConnector() const;
    
    //## auto_generated 
    void setClutchConnector(ActuatorClutchConnector*  p_ActuatorClutchConnector);

protected :
    
    //## auto_generated 
    VarEx get_shiftTime() const;
    
    //## auto_generated 
    void set_shiftTime(VarEx  p__shiftTime);


////    Framework operations    ////
public :
    
    //ec_Engage();
    
    //ec_Disengage();
    
    //rootState:
    
    //## statechart_method 
    inline int rootState_IN() const;
    
    //## statechart_method 
    virtual void rootState_entDef();
    
    //## statechart_method 
    virtual int rootState_dispatchEvent(short  id);
    
    //Waiting:
    
    //## statechart_method 
    inline int Waiting_IN() const;
    
    //Engaged:
    
    //## statechart_method 
    inline int Engaged_IN() const;
    
    //Disengaged:
    
    //## statechart_method 
    inline int Disengaged_IN() const;
    
    //## auto_generated 
    virtual OMBoolean startBehavior();

protected :
    
    //## auto_generated 
    void initStatechart();
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
public :
    
    double pressureMax;		//## attribute pressureMax 
    
    double rate;		//## attribute rate 
    
    double shiftPeriod;		//## attribute shiftPeriod 
    
    double shiftTime;		//## attribute shiftTime 
    
    double tolerance;		//## attribute tolerance 
    
protected :
    
    VarEx _shiftTime;		//## attribute _shiftTime 
    

////    Relations and components    ////
public :
    
    ActuatorClutchConnector* clutchConnector;		//## link clutchConnector 
    


////    Framework    ////
protected :
    
    //## ignore 
    //states enumeration: 
    enum Actuator_Enum{ OMNonState=0, Waiting=1, Engaged=2, Disengaged=3 };
    
    int rootState_subState;		//## ignore 
    
    
    int rootState_active;		//## ignore 
    

};
//---------------------------------------------------------------------------- 
// inline operations for Actuator
//---------------------------------------------------------------------------- 

inline int Actuator::rootState_IN() const {
    return 1;
}

inline int Actuator::Waiting_IN() const {
    return rootState_subState == Waiting;
}

inline int Actuator::Engaged_IN() const {
    return rootState_subState == Engaged;
}

inline int Actuator::Disengaged_IN() const {
    return rootState_subState == Disengaged;
}



#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedActuator : virtual public AOMInstance {

    
    DECLARE_REACTIVE_META(Actuator, OMAnimatedActuator)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;
    
    //## statechart_method 
    void rootState_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Waiting_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Engaged_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Disengaged_serializeStates(AOMSState*  aomsState) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Actuator.h
*********************************************************************/

