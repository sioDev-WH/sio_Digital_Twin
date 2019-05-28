/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Engine
//!	Generated Date	: Wed, 8, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Engine.h
*********************************************************************/


#ifndef Engine_H 

#define Engine_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "TransmissionModels.h"
#include <oxf/omthread.h>
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "LookupTable.h"
#include "TransmissionControlModels.h"
#include "OnUMLDaeEsoImpl.h"

//## package TransmissionModels 

//----------------------------------------------------------------------------
// Engine.h                                                                  
//----------------------------------------------------------------------------
class CRigidConnector;

#ifdef _OMINSTRUMENT
class OMAnimatedEngine;
#endif // _OMINSTRUMENT


//## class Engine 
struct IOnEnv;class Engine : public OMReactive, public COnUMLDaeEsoImpl<Engine> {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedEngine;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation Engine() 
    Engine(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~Engine() 
    ~Engine();


////    Operations    ////
public :
    
    //## operation Load(FILE * ) 
    bool Load(FILE * fs);
    
    //## operation Save(FILE * ) 
    void Save(FILE * fs);
    
    //## operation ad_r_EngineDynamics(Fdouble * ) 
    HRESULT ad_r_EngineDynamics(Fdouble * res);
    
    //## operation ad_r_OffTorque(Fdouble * ) 
    HRESULT ad_r_OffTorque(Fdouble * res);
    
    //## operation ad_r_OnTorque(Fdouble * ) 
    HRESULT ad_r_OnTorque(Fdouble * res);
    
    //## operation ad_r_RPM(Fdouble * ) 
    HRESULT ad_r_RPM(Fdouble * res);
    
    //## operation ad_r_StartupTorque(Fdouble * ) 
    HRESULT ad_r_StartupTorque(Fdouble * res);
    
    //## operation ad_z_OnRPM(Fdouble * ) 
    HRESULT ad_z_OnRPM(Fdouble * res);
    
    //## operation clean() 
    void clean();
    
    //## operation getRPM(const double ,double * ) 
    void getRPM(const double t, double * val);
    
    //## operation handle_Start(const double ,long * ) 
    void handle_Start(const double t, long * val);
    
    //## operation handle_inertia(const double ,const double * ) 
    void handle_inertia(const double t, const double * val);
    
    //## operation handle_throttle(const double ,double * ) 
    void handle_throttle(const double t, double * val);
    
    //## operation init() 
    void init();
    
    //## operation r_EngineDynamics(double * ) 
    HRESULT r_EngineDynamics(double * res);
    
    //## operation r_OffTorque(double * ) 
    HRESULT r_OffTorque(double * res);
    
    //## operation r_OnTorque(double * ) 
    HRESULT r_OnTorque(double * res);
    
    //## operation r_RPM(double * ) 
    HRESULT r_RPM(double * res);
    
    //## operation r_StartupTorque(double * ) 
    HRESULT r_StartupTorque(double * res);
    
    //## operation z_OnRPM(double * ) 
    HRESULT z_OnRPM(double * res);

protected :
    
    //## operation EvalStateCondition(const bool * ,const double * ,const double * ,const double ,const long ,const long ,bool * ) 
    HRESULT EvalStateCondition(const bool * EqnState, const double * x, const double * xdot, const double EventTime, const long iDisEqn, const long iTransition, bool * bEvent);
    
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
    double getRPM() const;
    
    //## auto_generated 
    void setRPM(double  p_RPM);
    
    //## auto_generated 
    double getEngineThrottleLag() const;
    
    //## auto_generated 
    void setEngineThrottleLag(double  p_engineThrottleLag);
    
    //## auto_generated 
    double getEngineTorque() const;
    
    //## auto_generated 
    void setEngineTorque(double  p_engineTorque);
    
    //## auto_generated 
    double getInertia() const;
    
    //## auto_generated 
    void setInertia(double  p_inertia);
    
    //## auto_generated 
    double getThrottle() const;
    
    //## auto_generated 
    void setThrottle(double  p_throttle);
    
    //## auto_generated 
    CRigidConnector* getN() const;
    
    //## auto_generated 
    void setN(CRigidConnector*  p_CRigidConnector);
    
    //## auto_generated 
    LookupTable* getTorqueMap() const;

protected :
    
    //## auto_generated 
    VarEx get_RPM() const;
    
    //## auto_generated 
    void set_RPM(VarEx  p__RPM);
    
    //## auto_generated 
    VarEx get_engineTorque() const;
    
    //## auto_generated 
    void set_engineTorque(VarEx  p__engineTorque);
    
    //## auto_generated 
    IOnEnv* getM_pOnEnv() const;
    
    //## auto_generated 
    void setM_pOnEnv(IOnEnv*  p_m_pOnEnv);


////    Framework operations    ////
public :
    
    //es_Start();
    
    //es_On();
    
    //es_Stop();
    
    //rootState:
    
    //## statechart_method 
    inline int rootState_IN() const;
    
    //## statechart_method 
    virtual void rootState_entDef();
    
    //## statechart_method 
    virtual int rootState_dispatchEvent(short  id);
    
    //Starting:
    
    //## statechart_method 
    inline int Starting_IN() const;
    
    //On:
    
    //## statechart_method 
    inline int On_IN() const;
    
    //Off:
    
    //## statechart_method 
    inline int Off_IN() const;
    
    //## auto_generated 
    virtual OMBoolean startBehavior();

protected :
    
    //## auto_generated 
    void initStatechart();
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
public :
    
    double RPM;		//## attribute RPM 
    
    double engineThrottleLag;		//## attribute engineThrottleLag 
    
    double engineTorque;		//## attribute engineTorque 
    
    double inertia;		//## attribute inertia 
    
    double throttle;		//## attribute throttle 
    
protected :
    
    VarEx _RPM;		//## attribute _RPM 
    
    VarEx _engineTorque;		//## attribute _engineTorque 
    
    IOnEnv* m_pOnEnv;		//## attribute m_pOnEnv 
    

////    Relations and components    ////
public :
    
    CRigidConnector* n;		//## link n 
    
    
    LookupTable torqueMap;		//## classInstance torqueMap 
    


////    Framework    ////
protected :
    
    //## ignore 
    //states enumeration: 
    enum Engine_Enum{ OMNonState=0, Starting=1, On=2, Off=3 };
    
    int rootState_subState;		//## ignore 
    
    
    int rootState_active;		//## ignore 
    

};
//---------------------------------------------------------------------------- 
// inline operations for Engine
//---------------------------------------------------------------------------- 

inline int Engine::rootState_IN() const {
    return 1;
}

inline int Engine::Starting_IN() const {
    return rootState_subState == Starting;
}

inline int Engine::On_IN() const {
    return rootState_subState == On;
}

inline int Engine::Off_IN() const {
    return rootState_subState == Off;
}



#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedEngine : virtual public AOMInstance {

    
    DECLARE_REACTIVE_META(Engine, OMAnimatedEngine)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;
    
    //## statechart_method 
    void rootState_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Starting_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void On_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Off_serializeStates(AOMSState*  aomsState) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Engine.h
*********************************************************************/

