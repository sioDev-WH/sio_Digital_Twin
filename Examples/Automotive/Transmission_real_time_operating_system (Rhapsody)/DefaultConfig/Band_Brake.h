/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Band_Brake
//!	Generated Date	: Wed, 8, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Band_Brake.h
*********************************************************************/


#ifndef Band_Brake_H 

#define Band_Brake_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "TransmissionModels.h"
#include "ClutchBase.h"
#include "TransmissionControlModels.h"
#include "OnUMLDaeEsoImpl.h"

//## package TransmissionModels 

//----------------------------------------------------------------------------
// Band_Brake.h                                                                  
//----------------------------------------------------------------------------
class ActuatorClutchConnector;
class CRigidConnector;

#ifdef _OMINSTRUMENT
class OMAnimatedBand_Brake;
#endif // _OMINSTRUMENT


//## class Band_Brake 
class Band_Brake : public ClutchBase, public COnUMLDaeEsoImpl<Band_Brake> {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedBand_Brake;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation Band_Brake() 
    Band_Brake(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~Band_Brake() 
    ~Band_Brake();


////    Operations    ////
public :
    
    //## operation Load(FILE * ) 
    bool Load(FILE * fs);
    
    //## operation Save(FILE * ) 
    void Save(FILE * fs);
    
    //## operation ad_r_StickFrictionTorque(Fdouble * ) 
    HRESULT ad_r_StickFrictionTorque(Fdouble * res);
    
    //## operation ad_r_cSlipFrictionTorque(Fdouble * ) 
    HRESULT ad_r_cSlipFrictionTorque(Fdouble * res);
    
    //## operation ad_r_ccSlipFrictionTorque(Fdouble * ) 
    HRESULT ad_r_ccSlipFrictionTorque(Fdouble * res);
    
    //## operation clean() 
    void clean();
    
    //## operation handle_area(const double ,const double * ) 
    void handle_area(const double t, const double * val);
    
    //## operation handle_cBreakfreeDispMax(const double ,const double * ) 
    void handle_cBreakfreeDispMax(const double t, const double * val);
    
    //## operation handle_ccBreakfreeDispMax(const double ,const double * ) 
    void handle_ccBreakfreeDispMax(const double t, const double * val);
    
    //## operation handle_damping(const double ,const double * ) 
    void handle_damping(const double t, const double * val);
    
    //## operation handle_frictionCoefficient(const double ,const double * ) 
    void handle_frictionCoefficient(const double t, const double * val);
    
    //## operation handle_pressureMax(const double ,const double * ) 
    void handle_pressureMax(const double t, const double * val);
    
    //## operation handle_radius(const double ,const double * ) 
    void handle_radius(const double t, const double * val);
    
    //## operation handle_stiffness(const double ,const double * ) 
    void handle_stiffness(const double t, const double * val);
    
    //## operation handle_torqueRatio(const double ,const double * ) 
    void handle_torqueRatio(const double t, const double * val);
    
    //## operation handle_wrapAngle(const double ,const double * ) 
    void handle_wrapAngle(const double t, const double * val);
    
    //## operation init() 
    void init();
    
    //## operation r_StickFrictionTorque(double * ) 
    HRESULT r_StickFrictionTorque(double * res);
    
    //## operation r_cSlipFrictionTorque(double * ) 
    HRESULT r_cSlipFrictionTorque(double * res);
    
    //## operation r_ccSlipFrictionTorque(double * ) 
    HRESULT r_ccSlipFrictionTorque(double * res);

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
    virtual HRESULT OnTransition();
    
    //## operation TriggerEvent(const double ,const BSTR ) 
    HRESULT TriggerEvent(const double EventTime, const BSTR bstrEventId);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getWrapAngle() const;
    
    //## auto_generated 
    void setWrapAngle(double  p_wrapAngle);


////    Framework operations    ////
public :
    
    //rootState:
    
    //## statechart_method 
    virtual void rootState_entDef();
    
    //## statechart_method 
    virtual int rootState_dispatchEvent(short  id);
    
    //Lock:
    
    //cSlip:
    
    //ccSlip:
    
    //## auto_generated 
    virtual OMBoolean startBehavior();

protected :
    
    //## auto_generated 
    void initStatechart();


////    Attributes    ////
public :
    
    double wrapAngle;		//## attribute wrapAngle 
    


////    Framework    ////
protected :
    
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedBand_Brake : public OMAnimatedClutchBase {

    
    DECLARE_REACTIVE_META(Band_Brake, OMAnimatedBand_Brake)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;
    
    //## statechart_method 
    void rootState_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Lock_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void cSlip_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void ccSlip_serializeStates(AOMSState*  aomsState) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Band_Brake.h
*********************************************************************/

