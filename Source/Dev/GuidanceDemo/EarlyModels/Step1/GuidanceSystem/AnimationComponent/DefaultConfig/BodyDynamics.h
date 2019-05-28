/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: BodyDynamics
//!	Generated Date	: Tue, 10, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\BodyDynamics.h
*********************************************************************/


#ifndef BodyDynamics_H 

#define BodyDynamics_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "GuidancePkg.h"
#include <oxf/omthread.h>
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "OnModel_BodyDynamics.h"

//## package GuidancePkg 

//----------------------------------------------------------------------------
// BodyDynamics.h                                                                  
//----------------------------------------------------------------------------
class BodyDynamicsCoeff;

#ifdef _OMINSTRUMENT
class OMAnimatedBodyDynamics;
#endif // _OMINSTRUMENT
class On3DConn;


//## class BodyDynamics 
class BodyDynamics : public OMReactive, public OnModel_BodyDynamics {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedBodyDynamics;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation BodyDynamics() 
    BodyDynamics(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~BodyDynamics() 
    virtual ~BodyDynamics();


////    Operations    ////
public :
    
    //## operation Load(FILE * ) 
    bool Load(FILE * fs);
    
    // simulation load / save
    //## operation Save(FILE * ) 
    void Save(FILE * fs);
    
    //## operation clean() 
    void clean();
    
    // Body Sensors
    //## operation getAccData(double) 
    double getAccData(double  time);
    
    //## operation getGyroData(double) 
    double getGyroData(double  time);
    
    //## operation getSpeed(double) 
    double getSpeed(double  time);
    
    //## operation get_theta(double) 
    double get_theta(double  time);
    
    //## operation get_x(double) 
    double get_x(double  time);
    
    //## operation get_z(double) 
    double get_z(double  time);
    
    // state machine implementation
    //## operation handle_Run(double) 
    void handle_Run(double  time);
    
    //## operation init() 
    void init();
    
    //## operation r_q(double * ) 
    HRESULT r_q(double * res);
    
    // residual equations
    //## operation r_theta(double * ) 
    HRESULT r_theta(double * res);
    
    //## operation r_u(double * ) 
    HRESULT r_u(double * res);
    
    //## operation r_w(double * ) 
    HRESULT r_w(double * res);
    
    //## operation r_x(double * ) 
    HRESULT r_x(double * res);
    
    //## operation r_z(double * ) 
    HRESULT r_z(double * res);
    
    // state machine implementation
    // reset equations
    //## operation s_alpha(double * ) 
    HRESULT s_alpha(double * res);
    
    //## operation s_u(double * ) 
    HRESULT s_u(double * res);

protected :
    
    //## operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
    HRESULT InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form);
    
    // model initialization
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
    
    //## operation ad_r_q(Fdouble * ) 
    HRESULT ad_r_q(Fdouble * res);
    
    //## operation ad_r_theta(Fdouble * ) 
    HRESULT ad_r_theta(Fdouble * res);
    
    //## operation ad_r_u(Fdouble * ) 
    HRESULT ad_r_u(Fdouble * res);
    
    //## operation ad_r_w(Fdouble * ) 
    HRESULT ad_r_w(Fdouble * res);
    
    //## operation ad_r_x(Fdouble * ) 
    HRESULT ad_r_x(Fdouble * res);
    
    //## operation ad_r_z(Fdouble * ) 
    HRESULT ad_r_z(Fdouble * res);
    
    // state machine implementation
    // reset equations
    //## operation ad_s_alpha(Fdouble * ) 
    HRESULT ad_s_alpha(Fdouble * res);
    
    //## operation ad_s_u(Fdouble * ) 
    HRESULT ad_s_u(Fdouble * res);
    
    // state machine implementation
    //## operation initStateMachine() 
    void initStateMachine();


////    Additional operations    ////
public :
    
    //## auto_generated 
    void set_theta(VarEx p__theta);
    
    //## auto_generated 
    void set_x(VarEx p__x);
    
    //## auto_generated 
    void set_z(VarEx p__z);
    
    //## auto_generated 
    void setTheta(double  p_theta);
    
    //## auto_generated 
    void setX(double  p_x);
    
    //## auto_generated 
    void setZ(double  p_z);
    
    //## auto_generated 
    On3DConn* getPAero() const;
    
    //## auto_generated 
    void setPAero(On3DConn*  p_On3DConn);
    
    //## auto_generated 
    BodyDynamicsCoeff* getPCoeff() const;
    
    //## auto_generated 
    void setPCoeff(BodyDynamicsCoeff*  p_BodyDynamicsCoeff);


////    Framework operations    ////
public :
    
    //evRun();
    
    //rootState:
    
    //## statechart_method 
    inline int rootState_IN() const;
    
    //## statechart_method 
    virtual void rootState_entDef();
    
    //## statechart_method 
    virtual int rootState_dispatchEvent(short  id);
    
    //Run:
    
    //## statechart_method 
    inline int Run_IN() const;
    
    //Init:
    
    //## statechart_method 
    inline int Init_IN() const;
    
    //## auto_generated 
    virtual OMBoolean startBehavior();

protected :
    
    //## auto_generated 
    void initStatechart();
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
public :
    
    // positions
    // (yaw, pitch, roll)[Local Frame] - rot(x) o rot(y) o rot(z)
    double theta;		//## attribute theta 
    
    // Inertial Xe, Ye, Ze positions
    double x;		//## attribute x 
    
    // Inertial Xe, Ye, Ze positions
    double z;		//## attribute z 
    
protected :
    
    // positions
    VarEx _theta;		//## attribute _theta 
    
    VarEx _x;		//## attribute _x 
    
    VarEx _z;		//## attribute _z 
    

////    Relations and components    ////
public :
    
    // connectors
    On3DConn* pAero;		//## link pAero 
    
    
    BodyDynamicsCoeff* pCoeff;		//## link pCoeff 
    


////    Framework    ////
protected :
    
    //## ignore 
    //states enumeration: 
    enum BodyDynamics_Enum{ OMNonState=0, Run=1, Init=2 };
    
    int rootState_subState;		//## ignore 
    
    
    int rootState_active;		//## ignore 
    

};
//---------------------------------------------------------------------------- 
// inline operations for BodyDynamics
//---------------------------------------------------------------------------- 

inline int BodyDynamics::rootState_IN() const {
    return 1;
}

inline int BodyDynamics::Run_IN() const {
    return rootState_subState == Run;
}

inline int BodyDynamics::Init_IN() const {
    return rootState_subState == Init;
}



#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedBodyDynamics : virtual public AOMInstance {

    
    DECLARE_REACTIVE_META(BodyDynamics, OMAnimatedBodyDynamics)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;
    
    //## statechart_method 
    void rootState_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Run_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Init_serializeStates(AOMSState*  aomsState) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\BodyDynamics.h
*********************************************************************/

