/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: ClutchBase
//!	Generated Date	: Wed, 8, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\ClutchBase.h
*********************************************************************/


#ifndef ClutchBase_H 

#define ClutchBase_H 


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
#include "IOnVarInit.h"

//## package TransmissionModels 

//----------------------------------------------------------------------------
// ClutchBase.h                                                                  
//----------------------------------------------------------------------------
class ActuatorClutchConnector;
class CRigidConnector;

#ifdef _OMINSTRUMENT
class OMAnimatedClutchBase;
#endif // _OMINSTRUMENT


//## class ClutchBase 
class ClutchBase : public OMReactive {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedClutchBase;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation ClutchBase() 
    ClutchBase(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~ClutchBase() 
    ~ClutchBase();


////    Operations    ////
public :
    
    //## operation OnTransition() 
    virtual HRESULT OnTransition()=0;
    
    //## operation ad_r_cSlipDisplacement(Fdouble * ) 
    HRESULT ad_r_cSlipDisplacement(Fdouble * res);
    
    //## operation ad_r_ccSlipDisplacement(Fdouble * ) 
    HRESULT ad_r_ccSlipDisplacement(Fdouble * res);
    
    //## operation ad_r_clockwiseBreakfreeDisp(Fdouble * ) 
    HRESULT ad_r_clockwiseBreakfreeDisp(Fdouble * res);
    
    //## operation ad_r_counterclockwiseBreakfreeDisp(Fdouble * ) 
    HRESULT ad_r_counterclockwiseBreakfreeDisp(Fdouble * res);
    
    //## operation ad_r_forceBalance(Fdouble * ) 
    HRESULT ad_r_forceBalance(Fdouble * res);
    
    //## operation ad_r_relativeVelocity(Fdouble * ) 
    HRESULT ad_r_relativeVelocity(Fdouble * res);
    
    //## operation ad_r_stickDisplacement(Fdouble * ) 
    HRESULT ad_r_stickDisplacement(Fdouble * res);
    
    //## operation ad_s_cLockDisplacement(Fdouble * ) 
    HRESULT ad_s_cLockDisplacement(Fdouble * res);
    
    //## operation ad_s_ccLockDisplacement(Fdouble * ) 
    HRESULT ad_s_ccLockDisplacement(Fdouble * res);
    
    //## operation ad_z_disp_neg_slip(Fdouble * ) 
    HRESULT ad_z_disp_neg_slip(Fdouble * res);
    
    //## operation ad_z_disp_pos_slip(Fdouble * ) 
    HRESULT ad_z_disp_pos_slip(Fdouble * res);
    
    //## operation ad_z_velocity_neg(Fdouble * ) 
    HRESULT ad_z_velocity_neg(Fdouble * res);
    
    //## operation ad_z_velocity_pos(Fdouble * ) 
    HRESULT ad_z_velocity_pos(Fdouble * res);
    
    //## operation clean() 
    void clean();
    
    //## operation init() 
    void init();
    
    //## operation r_cSlipDisplacement(double * ) 
    HRESULT r_cSlipDisplacement(double * res);
    
    //## operation r_ccSlipDisplacement(double * ) 
    HRESULT r_ccSlipDisplacement(double * res);
    
    //## operation r_clockwiseBreakfreeDisp(double * ) 
    HRESULT r_clockwiseBreakfreeDisp(double * res);
    
    //## operation r_counterclockwiseBreakfreeDisp(double * ) 
    HRESULT r_counterclockwiseBreakfreeDisp(double * res);
    
    //## operation r_forceBalance(double * ) 
    HRESULT r_forceBalance(double * res);
    
    //## operation r_relativeVelocity(double * ) 
    HRESULT r_relativeVelocity(double * res);
    
    //## operation r_stickDisplacement(double * ) 
    HRESULT r_stickDisplacement(double * res);
    
    //## operation s_cLockDisplacement(double * ) 
    HRESULT s_cLockDisplacement(double * res);
    
    //## operation s_ccLockDisplacement(double * ) 
    HRESULT s_ccLockDisplacement(double * res);
    
    //## operation z_disp_neg_slip(double * ) 
    HRESULT z_disp_neg_slip(double * res);
    
    //## operation z_disp_pos_slip(double * ) 
    HRESULT z_disp_pos_slip(double * res);
    
    //## operation z_velocity_neg(double * ) 
    HRESULT z_velocity_neg(double * res);
    
    //## operation z_velocity_pos(double * ) 
    HRESULT z_velocity_pos(double * res);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getArea() const;
    
    //## auto_generated 
    void setArea(double  p_area);
    
    //## auto_generated 
    bool  getBInConstruction() const;
    
    //## auto_generated 
    void setBInConstruction(bool p_bInConstruction);
    
    //## auto_generated 
    double getCBreakfreeDisp() const;
    
    //## auto_generated 
    void setCBreakfreeDisp(double  p_cBreakfreeDisp);
    
    //## auto_generated 
    double getCBreakfreeDispMax() const;
    
    //## auto_generated 
    void setCBreakfreeDispMax(double  p_cBreakfreeDispMax);
    
    //## auto_generated 
    double getCOilDisp() const;
    
    //## auto_generated 
    void setCOilDisp(double  p_cOilDisp);
    
    //## auto_generated 
    double getCcBreakfreeDisp() const;
    
    //## auto_generated 
    void setCcBreakfreeDisp(double  p_ccBreakfreeDisp);
    
    //## auto_generated 
    double getCcBreakfreeDispMax() const;
    
    //## auto_generated 
    void setCcBreakfreeDispMax(double  p_ccBreakfreeDispMax);
    
    //## auto_generated 
    double getCcOilDisp() const;
    
    //## auto_generated 
    void setCcOilDisp(double  p_ccOilDisp);
    
    //## auto_generated 
    double getDamping() const;
    
    //## auto_generated 
    void setDamping(double  p_damping);
    
    //## auto_generated 
    double getDisplacement() const;
    
    //## auto_generated 
    void setDisplacement(double  p_displacement);
    
    //## auto_generated 
    double getFrictionCoefficient() const;
    
    //## auto_generated 
    void setFrictionCoefficient(double  p_frictionCoefficient);
    
    //## auto_generated 
    double getPressureMax() const;
    
    //## auto_generated 
    void setPressureMax(double  p_pressureMax);
    
    //## auto_generated 
    double getRadius() const;
    
    //## auto_generated 
    void setRadius(double  p_radius);
    
    //## auto_generated 
    double getRelativeVelocity() const;
    
    //## auto_generated 
    void setRelativeVelocity(double  p_relativeVelocity);
    
    //## auto_generated 
    double getStiffness() const;
    
    //## auto_generated 
    void setStiffness(double  p_stiffness);
    
    //## auto_generated 
    double getTorqueRatio() const;
    
    //## auto_generated 
    void setTorqueRatio(double  p_torqueRatio);
    
    //## auto_generated 
    ActuatorClutchConnector* getActuatorConnector() const;
    
    //## auto_generated 
    void setActuatorConnector(ActuatorClutchConnector*  p_ActuatorClutchConnector);
    
    //## auto_generated 
    CRigidConnector* getN() const;
    
    //## auto_generated 
    void setN(CRigidConnector*  p_CRigidConnector);
    
    //## auto_generated 
    CRigidConnector* getP() const;
    
    //## auto_generated 
    void setP(CRigidConnector*  p_CRigidConnector);

protected :
    
    //## auto_generated 
    VarEx get_cBreakfreeDisp() const;
    
    //## auto_generated 
    void set_cBreakfreeDisp(VarEx  p__cBreakfreeDisp);
    
    //## auto_generated 
    VarEx get_ccBreakfreeDisp() const;
    
    //## auto_generated 
    void set_ccBreakfreeDisp(VarEx  p__ccBreakfreeDisp);
    
    //## auto_generated 
    VarEx get_displacement() const;
    
    //## auto_generated 
    void set_displacement(VarEx  p__displacement);
    
    //## auto_generated 
    VarEx get_relativeVelocity() const;
    
    //## auto_generated 
    void set_relativeVelocity(VarEx  p__relativeVelocity);


////    Framework operations    ////
public :
    
    //es_SlipToLock();
    
    //es_LockTocSlip();
    
    //es_LockToccSlip();
    
    //rootState:
    
    //## statechart_method 
    inline int rootState_IN() const;
    
    //## statechart_method 
    virtual void rootState_entDef();
    
    //## statechart_method 
    virtual int rootState_dispatchEvent(short  id);
    
    //Lock:
    
    //## statechart_method 
    inline int Lock_IN() const;
    
    //cSlip:
    
    //## statechart_method 
    inline int cSlip_IN() const;
    
    //ccSlip:
    
    //## statechart_method 
    inline int ccSlip_IN() const;
    
    //## auto_generated 
    virtual OMBoolean startBehavior();

protected :
    
    //## auto_generated 
    void initStatechart();
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
public :
    
    double area;		//## attribute area 
    
    bool bInConstruction;		//## attribute bInConstruction 
    
    double cBreakfreeDisp;		//## attribute cBreakfreeDisp 
    
    double cBreakfreeDispMax;		//## attribute cBreakfreeDispMax 
    
    double cOilDisp;		//## attribute cOilDisp 
    
    double ccBreakfreeDisp;		//## attribute ccBreakfreeDisp 
    
    double ccBreakfreeDispMax;		//## attribute ccBreakfreeDispMax 
    
    double ccOilDisp;		//## attribute ccOilDisp 
    
    double damping;		//## attribute damping 
    
    double displacement;		//## attribute displacement 
    
    double frictionCoefficient;		//## attribute frictionCoefficient 
    
    double pressureMax;		//## attribute pressureMax 
    
    double radius;		//## attribute radius 
    
    double relativeVelocity;		//## attribute relativeVelocity 
    
    double stiffness;		//## attribute stiffness 
    
    double torqueRatio;		//## attribute torqueRatio 
    
protected :
    
    VarEx _cBreakfreeDisp;		//## attribute _cBreakfreeDisp 
    
    VarEx _ccBreakfreeDisp;		//## attribute _ccBreakfreeDisp 
    
    VarEx _displacement;		//## attribute _displacement 
    
    VarEx _relativeVelocity;		//## attribute _relativeVelocity 
    

////    Relations and components    ////
public :
    
    ActuatorClutchConnector* actuatorConnector;		//## link actuatorConnector 
    
    
    CRigidConnector* n;		//## link n 
    
    
    CRigidConnector* p;		//## link p 
    


////    Framework    ////
protected :
    
    //## ignore 
    //states enumeration: 
    enum ClutchBase_Enum{ OMNonState=0, Lock=1, cSlip=2, ccSlip=3 };
    
    int rootState_subState;		//## ignore 
    
    
    int rootState_active;		//## ignore 
    

};
//---------------------------------------------------------------------------- 
// inline operations for ClutchBase
//---------------------------------------------------------------------------- 

inline int ClutchBase::rootState_IN() const {
    return 1;
}

inline int ClutchBase::Lock_IN() const {
    return rootState_subState == Lock;
}

inline int ClutchBase::cSlip_IN() const {
    return rootState_subState == cSlip;
}

inline int ClutchBase::ccSlip_IN() const {
    return rootState_subState == ccSlip;
}



#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedClutchBase : virtual public AOMInstance {

    
    DECLARE_REACTIVE_META(ClutchBase, OMAnimatedClutchBase)


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
	File Path	: AnimationComponent\DefaultConfig\ClutchBase.h
*********************************************************************/

