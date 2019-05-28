/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Clutch
//!	Generated Date	: Wed, 8, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Clutch.h
*********************************************************************/


#ifndef Clutch_H 

#define Clutch_H 


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
// Clutch.h                                                                  
//----------------------------------------------------------------------------
class ActuatorClutchConnector;
class CRigidConnector;

#ifdef _OMINSTRUMENT
class OMAnimatedClutch;
#endif // _OMINSTRUMENT


//## class Clutch 
class Clutch : public ClutchBase, public COnUMLDaeEsoImpl<Clutch> {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedClutch;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation Clutch() 
    Clutch(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~Clutch() 
    ~Clutch();


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
    
    //## operation handle_nSurfaces(const double ,const long * ) 
    void handle_nSurfaces(const double t, const long * val);
    
    //## operation handle_pressureMax(const double ,const double * ) 
    void handle_pressureMax(const double t, const double * val);
    
    //## operation handle_radius(const double ,const double * ) 
    void handle_radius(const double t, const double * val);
    
    //## operation handle_stiffness(const double ,const double * ) 
    void handle_stiffness(const double t, const double * val);
    
    //## operation handle_torqueRatio(const double ,const double * ) 
    void handle_torqueRatio(const double t, const double * val);
    
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
    
    //## operation InitLocalIPars(const _TCHAR * ,pplong * ,ppchar * ,long * ,long * ) 
    HRESULT InitLocalIPars(const _TCHAR * prefix, pplong * pars, ppchar * Names, long * nPars, long * dPars);
    
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
    long getNSurfaces() const;
    
    //## auto_generated 
    void setNSurfaces(long  p_nSurfaces);


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
    
    long nSurfaces;		//## attribute nSurfaces 
    


////    Framework    ////
protected :
    
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedClutch : public OMAnimatedClutchBase {

    
    DECLARE_REACTIVE_META(Clutch, OMAnimatedClutch)


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
	File Path	: AnimationComponent\DefaultConfig\Clutch.h
*********************************************************************/

