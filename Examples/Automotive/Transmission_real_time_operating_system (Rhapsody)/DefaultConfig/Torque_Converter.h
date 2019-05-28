/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Torque_Converter
//!	Generated Date	: Wed, 8, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Torque_Converter.h
*********************************************************************/


#ifndef Torque_Converter_H 

#define Torque_Converter_H 


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
// Torque_Converter.h                                                                  
//----------------------------------------------------------------------------
class CRigidConnector;

#ifdef _OMINSTRUMENT
class OMAnimatedTorque_Converter;
#endif // _OMINSTRUMENT


//## class Torque_Converter 
class Torque_Converter : public OMReactive, public COnUMLDaeEsoImpl<Torque_Converter> {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedTorque_Converter;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation Torque_Converter() 
    Torque_Converter(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~Torque_Converter() 
    ~Torque_Converter();


////    Operations    ////
public :
    
    //## operation Load(FILE * ) 
    bool Load(FILE * fs);
    
    //## operation Save(FILE * ) 
    void Save(FILE * fs);
    
    //## operation ad_r_FCM_ImpellerTorque(Fdouble * ) 
    HRESULT ad_r_FCM_ImpellerTorque(Fdouble * res);
    
    //## operation ad_r_FCM_TurbineTorque(Fdouble * ) 
    HRESULT ad_r_FCM_TurbineTorque(Fdouble * res);
    
    //## operation ad_r_ImpellerNewton(Fdouble * ) 
    HRESULT ad_r_ImpellerNewton(Fdouble * res);
    
    //## operation ad_r_ImpellerSpeed(Fdouble * ) 
    HRESULT ad_r_ImpellerSpeed(Fdouble * res);
    
    //## operation ad_r_SpeedLocked(Fdouble * ) 
    HRESULT ad_r_SpeedLocked(Fdouble * res);
    
    //## operation ad_r_TMM_ImpellerTorque(Fdouble * ) 
    HRESULT ad_r_TMM_ImpellerTorque(Fdouble * res);
    
    //## operation ad_r_TMM_TurbineTorque(Fdouble * ) 
    HRESULT ad_r_TMM_TurbineTorque(Fdouble * res);
    
    //## operation ad_r_TurbineNewton(Fdouble * ) 
    HRESULT ad_r_TurbineNewton(Fdouble * res);
    
    //## operation ad_r_TurbineSpeed(Fdouble * ) 
    HRESULT ad_r_TurbineSpeed(Fdouble * res);
    
    //## operation ad_z_ImpellerTorque_lt_TurbineTorque(Fdouble * ) 
    HRESULT ad_z_ImpellerTorque_lt_TurbineTorque(Fdouble * res);
    
    //## operation ad_z_Speed_gt_LockedSpeed(Fdouble * ) 
    HRESULT ad_z_Speed_gt_LockedSpeed(Fdouble * res);
    
    //## operation ad_z_Speed_lt_LockedSpeed(Fdouble * ) 
    HRESULT ad_z_Speed_lt_LockedSpeed(Fdouble * res);
    
    //## operation ad_z_TorqueRatio_gt_one(Fdouble * ) 
    HRESULT ad_z_TorqueRatio_gt_one(Fdouble * res);
    
    //## operation ad_z_TorqueRatio_lt_one(Fdouble * ) 
    HRESULT ad_z_TorqueRatio_lt_one(Fdouble * res);
    
    //## operation clean() 
    void clean();
    
    //## operation handle_impellerInertia(const double ,double * ) 
    void handle_impellerInertia(const double t, double * val);
    
    //## operation handle_turbineInertia(const double ,double * ) 
    void handle_turbineInertia(const double t, double * val);
    
    //## operation init() 
    void init();
    
    //## operation r_FCM_ImpellerTorque(double * ) 
    HRESULT r_FCM_ImpellerTorque(double * res);
    
    //## operation r_FCM_TurbineTorque(double * ) 
    HRESULT r_FCM_TurbineTorque(double * res);
    
    //## operation r_ImpellerNewton(double * ) 
    HRESULT r_ImpellerNewton(double * res);
    
    //## operation r_ImpellerSpeed(double * ) 
    HRESULT r_ImpellerSpeed(double * res);
    
    //## operation r_SpeedLocked(double * ) 
    HRESULT r_SpeedLocked(double * res);
    
    //## operation r_TMM_ImpellerTorque(double * ) 
    HRESULT r_TMM_ImpellerTorque(double * res);
    
    //## operation r_TMM_TurbineTorque(double * ) 
    HRESULT r_TMM_TurbineTorque(double * res);
    
    //## operation r_TurbineNewton(double * ) 
    HRESULT r_TurbineNewton(double * res);
    
    //## operation r_TurbineSpeed(double * ) 
    HRESULT r_TurbineSpeed(double * res);
    
    //## operation z_ImpellerTorque_lt_TurbineTorque(double * ) 
    HRESULT z_ImpellerTorque_lt_TurbineTorque(double * res);
    
    //## operation z_Speed_gt_LockedSpeed(double * ) 
    HRESULT z_Speed_gt_LockedSpeed(double * res);
    
    //## operation z_Speed_lt_LockedSpeed(double * ) 
    HRESULT z_Speed_lt_LockedSpeed(double * res);
    
    //## operation z_TorqueRatio_gt_one(double * ) 
    HRESULT z_TorqueRatio_gt_one(double * res);
    
    //## operation z_TorqueRatio_lt_one(double * ) 
    HRESULT z_TorqueRatio_lt_one(double * res);

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
    double getC(int  i1) const;
    
    //## auto_generated 
    void setC(int  i1, double  p_c);
    
    //## auto_generated 
    double getImpellerInertia() const;
    
    //## auto_generated 
    void setImpellerInertia(double  p_impellerInertia);
    
    //## auto_generated 
    double getImpellerSpeed() const;
    
    //## auto_generated 
    void setImpellerSpeed(double  p_impellerSpeed);
    
    //## auto_generated 
    double getImpellerTorque() const;
    
    //## auto_generated 
    void setImpellerTorque(double  p_impellerTorque);
    
    //## auto_generated 
    double getTurbineInertia() const;
    
    //## auto_generated 
    void setTurbineInertia(double  p_turbineInertia);
    
    //## auto_generated 
    double getTurbineSpeed() const;
    
    //## auto_generated 
    void setTurbineSpeed(double  p_turbineSpeed);
    
    //## auto_generated 
    double getTurbineTorque() const;
    
    //## auto_generated 
    void setTurbineTorque(double  p_turbineTorque);
    
    //## auto_generated 
    CRigidConnector* getImpeller() const;
    
    //## auto_generated 
    void setImpeller(CRigidConnector*  p_CRigidConnector);
    
    //## auto_generated 
    CRigidConnector* getTurbine() const;
    
    //## auto_generated 
    void setTurbine(CRigidConnector*  p_CRigidConnector);

protected :
    
    //## auto_generated 
    VarEx get_impellerSpeed() const;
    
    //## auto_generated 
    void set_impellerSpeed(VarEx  p__impellerSpeed);
    
    //## auto_generated 
    VarEx get_impellerTorque() const;
    
    //## auto_generated 
    void set_impellerTorque(VarEx  p__impellerTorque);
    
    //## auto_generated 
    VarEx get_turbineSpeed() const;
    
    //## auto_generated 
    void set_turbineSpeed(VarEx  p__turbineSpeed);
    
    //## auto_generated 
    VarEx get_turbineTorque() const;
    
    //## auto_generated 
    void set_turbineTorque(VarEx  p__turbineTorque);


////    Framework operations    ////
public :
    
    //es_TMM();
    
    //es_FCM();
    
    //es_Lock();
    
    //rootState:
    
    //## statechart_method 
    inline int rootState_IN() const;
    
    //## statechart_method 
    virtual void rootState_entDef();
    
    //## statechart_method 
    virtual int rootState_dispatchEvent(short  id);
    
    //Torque_Multiplication:
    
    //## statechart_method 
    inline int Torque_Multiplication_IN() const;
    
    //Locked:
    
    //## statechart_method 
    inline int Locked_IN() const;
    
    //Fluid_Coupling:
    
    //## statechart_method 
    inline int Fluid_Coupling_IN() const;
    
    //## auto_generated 
    virtual OMBoolean startBehavior();

protected :
    
    //## auto_generated 
    void initStatechart();
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
public :
    
    double c[10];		//## attribute c 
    
    double impellerInertia;		//## attribute impellerInertia 
    
    double impellerSpeed;		//## attribute impellerSpeed 
    
    double impellerTorque;		//## attribute impellerTorque 
    
    double turbineInertia;		//## attribute turbineInertia 
    
    double turbineSpeed;		//## attribute turbineSpeed 
    
    double turbineTorque;		//## attribute turbineTorque 
    
protected :
    
    VarEx _impellerSpeed;		//## attribute _impellerSpeed 
    
    VarEx _impellerTorque;		//## attribute _impellerTorque 
    
    VarEx _turbineSpeed;		//## attribute _turbineSpeed 
    
    VarEx _turbineTorque;		//## attribute _turbineTorque 
    

////    Relations and components    ////
public :
    
    CRigidConnector* impeller;		//## link impeller 
    
    
    CRigidConnector* turbine;		//## link turbine 
    


////    Framework    ////
protected :
    
    //## ignore 
    //states enumeration: 
    enum Torque_Converter_Enum{ OMNonState=0, Torque_Multiplication=1, Locked=2, Fluid_Coupling=3 };
    
    int rootState_subState;		//## ignore 
    
    
    int rootState_active;		//## ignore 
    

};
//---------------------------------------------------------------------------- 
// inline operations for Torque_Converter
//---------------------------------------------------------------------------- 

inline int Torque_Converter::rootState_IN() const {
    return 1;
}

inline int Torque_Converter::Torque_Multiplication_IN() const {
    return rootState_subState == Torque_Multiplication;
}

inline int Torque_Converter::Locked_IN() const {
    return rootState_subState == Locked;
}

inline int Torque_Converter::Fluid_Coupling_IN() const {
    return rootState_subState == Fluid_Coupling;
}



#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedTorque_Converter : virtual public AOMInstance {

    
    DECLARE_REACTIVE_META(Torque_Converter, OMAnimatedTorque_Converter)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;
    
    //## statechart_method 
    void rootState_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Torque_Multiplication_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Locked_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Fluid_Coupling_serializeStates(AOMSState*  aomsState) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Torque_Converter.h
*********************************************************************/

