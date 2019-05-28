/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: finDynamics
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\finDynamics.h
*********************************************************************/


#ifndef finDynamics_H 

#define finDynamics_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AirframePkg.h"
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "FinPort.h"
#include "OnUMLDaeEsoImpl.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// finDynamics.h                                                                  
//----------------------------------------------------------------------------

//## class finDynamics 
class finDynamics : public OMReactive, public COnUMLDaeEsoImpl<finDynamics> {


////    Constructors and destructors    ////
public :
    
    // 
    // KAB
    //## operation finDynamics() 
    finDynamics(OMThread*  p_thread = OMDefaultThread);
    
    // KAB  
    //## operation ~finDynamics() 
    virtual ~finDynamics();


////    Operations    ////
public :
    
    //## operation Load(FILE*) 
    bool Load(FILE*  fs);
    
    //## operation Save(FILE*) 
    void Save(FILE*  fs);
    
    //## operation clean() 
    void clean();
    
    //## operation get_der_rate(const double ,double*) 
    void get_der_rate(const double t, double*  pVal);
    
    //## operation get_rate(const double ,double*) 
    void get_rate(const double t, double*  pVal);
    
    //## operation handle_AngleSetpoint(const double,const double*) 
    void handle_AngleSetpoint(const double  t, const double*  val);
    
    //## operation handle_bandwidth(const double,const double*) 
    void handle_bandwidth(const double  t, const double*  val);
    
    //## operation handle_damping(const double,const double*) 
    void handle_damping(const double  t, const double*  val);
    
    //## operation handle_gain(const double,const double*) 
    void handle_gain(const double  t, const double*  val);
    
    //## operation handle_max_angle(const double,const double*) 
    void handle_max_angle(const double  t, const double*  val);
    
    //## operation handle_max_rate(const double,const double*) 
    void handle_max_rate(const double  t, const double*  val);
    
    //## operation handle_min_angle(const double,const double*) 
    void handle_min_angle(const double  t, const double*  val);
    
    //## operation init() 
    void init();
    
    //## operation r_angle(double * ) 
    HRESULT r_angle(double * res);
    
    //## operation r_angle_aileron(double * ) 
    HRESULT r_angle_aileron(double * res);
    
    //## operation r_angle_rudder(double * ) 
    HRESULT r_angle_rudder(double * res);
    
    //## operation r_rate(double * ) 
    HRESULT r_rate(double * res);
    
    //## operation r_saturation_angle(double * ) 
    HRESULT r_saturation_angle(double * res);
    
    //## operation r_saturation_rate(double * ) 
    HRESULT r_saturation_rate(double * res);
    
    //## operation s_rate_eq_zero(double * ) 
    HRESULT s_rate_eq_zero(double * res);
    
    //## operation z_pos_gt_max(double * ) 
    HRESULT z_pos_gt_max(double * res);
    
    //## operation z_pos_lt_min(double * ) 
    HRESULT z_pos_lt_min(double * res);
    
    //## operation z_sp_gt_min(double * ) 
    HRESULT z_sp_gt_min(double * res);
    
    //## operation z_sp_lt_max(double * ) 
    HRESULT z_sp_lt_max(double * res);

protected :
    
    //## operation EvalStateCondition(const bool*,const double*,const double*,const double,const long,const long,bool*) 
    HRESULT EvalStateCondition(const bool*  EqnState, const double*  x, const double*  xdot, const double  EventTime, const long  iDisEqn, const long  iTransition, bool*  bEvent);
    
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
    
    //## operation InitStates() 
    HRESULT InitStates();
    
    //## operation InitTransitions() 
    HRESULT InitTransitions();
    
    //## operation OnTransition() 
    HRESULT OnTransition();
    
    //## operation TriggerEvent(const double,const BSTR) 
    HRESULT TriggerEvent(const double  EventTime, const BSTR  bstrEventId);
    
    //## operation ad_r_angle(Fdouble*) 
    HRESULT ad_r_angle(Fdouble*  res);
    
    //## operation ad_r_angle_aileron(Fdouble*) 
    HRESULT ad_r_angle_aileron(Fdouble*  res);
    
    //## operation ad_r_angle_rudder(Fdouble*) 
    HRESULT ad_r_angle_rudder(Fdouble*  res);
    
    //## operation ad_r_rate(Fdouble*) 
    HRESULT ad_r_rate(Fdouble*  res);
    
    //## operation ad_r_saturation_angle(Fdouble*) 
    HRESULT ad_r_saturation_angle(Fdouble*  res);
    
    //## operation ad_r_saturation_rate(Fdouble*) 
    HRESULT ad_r_saturation_rate(Fdouble*  res);
    
    //## operation ad_s_rate_eq_zero(Fdouble*) 
    HRESULT ad_s_rate_eq_zero(Fdouble*  res);
    
    //## operation ad_z_pos_gt_max(Fdouble*) 
    HRESULT ad_z_pos_gt_max(Fdouble*  res);
    
    //## operation ad_z_pos_lt_min(Fdouble*) 
    HRESULT ad_z_pos_lt_min(Fdouble*  res);
    
    //## operation ad_z_sp_gt_min(Fdouble*) 
    HRESULT ad_z_sp_gt_min(Fdouble*  res);
    
    //## operation ad_z_sp_lt_max(Fdouble*) 
    HRESULT ad_z_sp_lt_max(Fdouble*  res);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getAngleSetpoint() const;
    
    //## auto_generated 
    void setAngleSetpoint(double  p_AngleSetpoint);
    
    //## auto_generated 
    double getBandwidth() const;
    
    //## auto_generated 
    void setBandwidth(double  p_bandwidth);
    
    //## auto_generated 
    double getDamping() const;
    
    //## auto_generated 
    void setDamping(double  p_damping);
    
    //## auto_generated 
    double getGain() const;
    
    //## auto_generated 
    void setGain(double  p_gain);
    
    //## auto_generated 
    double getMax_angle() const;
    
    //## auto_generated 
    void setMax_angle(double  p_max_angle);
    
    //## auto_generated 
    double getMax_rate() const;
    
    //## auto_generated 
    void setMax_rate(double  p_max_rate);
    
    //## auto_generated 
    double getMin_angle() const;
    
    //## auto_generated 
    void setMin_angle(double  p_min_angle);
    
    //## auto_generated 
    double getRate() const;
    
    //## auto_generated 
    void setRate(double  p_rate);
    
    //## auto_generated 
    FinPort* getPFin() const;

protected :
    
    //## auto_generated 
    void set_rate(VarEx  p__rate);


////    Framework operations    ////
public :
    
    //evSL();
    
    //evSH();
    
    //evNorm();
    
    //rootState:
    
    //## statechart_method 
    inline int rootState_IN() const;
    
    //## statechart_method 
    virtual void rootState_entDef();
    
    //## statechart_method 
    virtual int rootState_dispatchEvent(short  id);
    
    //Normal:
    
    //## statechart_method 
    inline int Normal_IN() const;
    
    //LowSaturation:
    
    //## statechart_method 
    inline int LowSaturation_IN() const;
    
    //HighSaturation:
    
    //## statechart_method 
    inline int HighSaturation_IN() const;
    
    //## auto_generated 
    virtual OMBoolean startBehavior();

protected :
    
    //## auto_generated 
    void initStatechart();


////    Attributes    ////
public :
    
    // parameters
    double AngleSetpoint;		//## attribute AngleSetpoint 
    
    double bandwidth;		//## attribute bandwidth 
    
    double damping;		//## attribute damping 
    
    double gain;		//## attribute gain 
    
    double max_angle;		//## attribute max_angle 
    
    double max_rate;		//## attribute max_rate 
    
    double min_angle;		//## attribute min_angle 
    
    // variables
    double rate;		//## attribute rate 
    
protected :
    
    VarEx _rate;		//## attribute _rate 
    

////    Relations and components    ////
public :
    
    FinPort pFin;		//## classInstance pFin 
    


////    Framework    ////
protected :
    
    //## ignore 
    //states enumeration: 
    enum finDynamics_Enum{ OMNonState=0, Normal=1, LowSaturation=2, HighSaturation=3 };
    
    int rootState_subState;		//## ignore 
    
    
    int rootState_active;		//## ignore 
    

};
//---------------------------------------------------------------------------- 
// inline operations for finDynamics
//---------------------------------------------------------------------------- 

inline int finDynamics::rootState_IN() const {
    return 1;
}

inline int finDynamics::Normal_IN() const {
    return rootState_subState == Normal;
}

inline int finDynamics::LowSaturation_IN() const {
    return rootState_subState == LowSaturation;
}

inline int finDynamics::HighSaturation_IN() const {
    return rootState_subState == HighSaturation;
}



#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\finDynamics.h
*********************************************************************/

