/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: BodyDynamics
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\BodyDynamics.h
*********************************************************************/


#ifndef BodyDynamics_H 

#define BodyDynamics_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "AirframePkg.h"
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "OnUMLDaeEsoImpl.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// BodyDynamics.h                                                                  
//----------------------------------------------------------------------------
class BodyDynamicsCoeff;
class On3DConn;


//## class BodyDynamics 
class BodyDynamics : public OMReactive, public COnUMLDaeEsoImpl<BodyDynamics> {


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
    //## operation getAccData(const double,double*) 
    void getAccData(const double  t, double*  val);
    
    //## operation getGyroData(const double,double*) 
    void getGyroData(const double  t, double*  val);
    
    //## operation getSpeed(const double,double*) 
    void getSpeed(const double  t, double*  val);
    
    //## operation get_theta(const double,double*) 
    void get_theta(const double  t, double*  val);
    
    //## operation get_x(const double,double *) 
    void get_x(const double  t, double *  val);
    
    //## operation get_z(const double,double *) 
    void get_z(const double  t, double *  val);
    
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
    VarEx  get_theta() const;
    
    //## auto_generated 
    void set_theta(VarEx p__theta);
    
    //## auto_generated 
    VarEx  get_x() const;
    
    //## auto_generated 
    void set_x(VarEx p__x);
    
    //## auto_generated 
    VarEx  get_z() const;
    
    //## auto_generated 
    void set_z(VarEx p__z);
    
    //## auto_generated 
    double getTheta() const;
    
    //## auto_generated 
    void setTheta(double  p_theta);
    
    //## auto_generated 
    double getX() const;
    
    //## auto_generated 
    void setX(double  p_x);
    
    //## auto_generated 
    double getZ() const;
    
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



#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\BodyDynamics.h
*********************************************************************/

