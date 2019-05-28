/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: ClutchBase
//!	Generated Date	: Thu, 9, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\ClutchBase.cpp
*********************************************************************/


//#[ ignore 
#define NAMESPACE_PREFIX 


#define _OMSTATECHART_ANIMATED 
//#]

#include "ClutchBase.h"
#include "ActuatorClutchConnector.h"
#include "CRigidConnector.h"
#include "stdafx.h"
#include "math.h"

//## package TransmissionModels 


//#[ ignore 
#define TransmissionModels_ClutchBase_ClutchBase_SERIALIZE OM_NO_OP


#define TransmissionModels_ClutchBase_OnTransition_SERIALIZE OM_NO_OP


#define TransmissionModels_ClutchBase_clean_SERIALIZE OM_NO_OP


#define TransmissionModels_ClutchBase_init_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// ClutchBase.cpp                                                                  
//----------------------------------------------------------------------------
DECLARE_META_PACKAGE(TransmissionModels)
//## class ClutchBase 



ClutchBase::ClutchBase(OMThread*  p_thread) : bInConstruction(false),ccOilDisp(1.0e-3),cOilDisp(1.0e-3)  
//}}SCG_OP_INFO
 {
    NOTIFY_REACTIVE_CONSTRUCTOR(ClutchBase, ClutchBase(), 0, TransmissionModels_ClutchBase_ClutchBase_SERIALIZE);
    setThread(p_thread, FALSE);
    actuatorConnector = NULL;
    n = NULL;
    p = NULL;
    initStatechart();
    //#[ operation ClutchBase() 
        bInConstruction = true;
    
        // initialization
    
        bInConstruction = false;
    
    //#]
}

ClutchBase::~ClutchBase() {
    NOTIFY_DESTRUCTOR(~ClutchBase, TRUE);
    //#[ operation ~ClutchBase() 
    //#]
    cleanUpRelations();
}

HRESULT ClutchBase::ad_r_cSlipDisplacement(Fdouble * res) {
    //#[ operation ad_r_cSlipDisplacement(Fdouble * ) 
    *res= DER_AD(displacement);
    return S_OK;
    
    //#]
}

HRESULT ClutchBase::ad_r_ccSlipDisplacement(Fdouble * res) {
    //#[ operation ad_r_ccSlipDisplacement(Fdouble * ) 
    *res= DER_AD(displacement);
    return S_OK;
    
    //#]
}

HRESULT ClutchBase::ad_r_clockwiseBreakfreeDisp(Fdouble * res) {
    //#[ operation ad_r_clockwiseBreakfreeDisp(Fdouble * ) 
    *res = AD(cBreakfreeDisp) - cOilDisp - cBreakfreeDispMax*actuatorConnector->AD(pressure)/pressureMax;
    return S_OK;
    
    //#]
}

HRESULT ClutchBase::ad_r_counterclockwiseBreakfreeDisp(Fdouble * res) {
    //#[ operation ad_r_counterclockwiseBreakfreeDisp(Fdouble * ) 
    *res = AD(ccBreakfreeDisp) - ccOilDisp - ccBreakfreeDispMax*actuatorConnector->AD(pressure)/pressureMax;
    return S_OK;
    
    //#]
}

HRESULT ClutchBase::ad_r_forceBalance(Fdouble * res) {
    //#[ operation ad_r_forceBalance(Fdouble * ) 
    *res = p->AD(torque) + n->AD(torque);
      return S_OK;
    
    //#]
}

HRESULT ClutchBase::ad_r_relativeVelocity(Fdouble * res) {
    //#[ operation ad_r_relativeVelocity(Fdouble * ) 
    *res = DER_AD(relativeVelocity) - (p->AD(acceleration) - n->AD(acceleration));
    return S_OK;
    
    //#]
}

HRESULT ClutchBase::ad_r_stickDisplacement(Fdouble * res) {
    //#[ operation ad_r_stickDisplacement(Fdouble * ) 
    *res = DER_AD(displacement) - AD(relativeVelocity);
    return S_OK;
    
    //#]
}

HRESULT ClutchBase::ad_s_cLockDisplacement(Fdouble * res) {
    //#[ operation ad_s_cLockDisplacement(Fdouble * ) 
      *res = AD(displacement) - (OLD(cBreakfreeDisp) - 1.0e-5);
      return S_OK;
    
    //#]
}

HRESULT ClutchBase::ad_s_ccLockDisplacement(Fdouble * res) {
    //#[ operation ad_s_ccLockDisplacement(Fdouble * ) 
      *res = AD(displacement) - (-OLD(ccBreakfreeDisp) + 1.0e-5);
      return S_OK;
    
    //#]
}

HRESULT ClutchBase::ad_z_disp_neg_slip(Fdouble * res) {
    //#[ operation ad_z_disp_neg_slip(Fdouble * ) 
    *res= - AD(displacement) - AD(ccBreakfreeDisp);
    return S_OK;
    
    //#]
}

HRESULT ClutchBase::ad_z_disp_pos_slip(Fdouble * res) {
    //#[ operation ad_z_disp_pos_slip(Fdouble * ) 
    *res = AD(displacement) - AD(cBreakfreeDisp);
    return S_OK;
    
    //#]
}

HRESULT ClutchBase::ad_z_velocity_neg(Fdouble * res) {
    //#[ operation ad_z_velocity_neg(Fdouble * ) 
    *res = - AD(relativeVelocity);
    return S_OK;
    
    //#]
}

HRESULT ClutchBase::ad_z_velocity_pos(Fdouble * res) {
    //#[ operation ad_z_velocity_pos(Fdouble * ) 
    *res = AD(relativeVelocity);
    return S_OK;
    
    //#]
}

void ClutchBase::clean() {
    NOTIFY_OPERATION(clean, clean(), 0, TransmissionModels_ClutchBase_clean_SERIALIZE);
    //#[ operation clean() 
      p->Release();
      n->Release();
      actuatorConnector->Release();
    
    //#]
}

void ClutchBase::init() {
    NOTIFY_OPERATION(init, init(), 0, TransmissionModels_ClutchBase_init_SERIALIZE);
    //#[ operation init() 
      p = new CRigidConnector();
      n = new CRigidConnector();
      actuatorConnector = new ActuatorClutchConnector();     
      p->AddRef();
      n->AddRef();
      actuatorConnector->AddRef();
    
    //#]
}

HRESULT ClutchBase::r_cSlipDisplacement(double * res) {
    //#[ operation r_cSlipDisplacement(double * ) 
    *res= DER(displacement);
    return S_OK;
    
    //#]
}

HRESULT ClutchBase::r_ccSlipDisplacement(double * res) {
    //#[ operation r_ccSlipDisplacement(double * ) 
    *res= DER(displacement);
    return S_OK;
    
    //#]
}

HRESULT ClutchBase::r_clockwiseBreakfreeDisp(double * res) {
    //#[ operation r_clockwiseBreakfreeDisp(double * ) 
    *res = cBreakfreeDisp - cOilDisp - cBreakfreeDispMax*actuatorConnector->pressure/pressureMax;
    
    return S_OK;
    
    //#]
}

HRESULT ClutchBase::r_counterclockwiseBreakfreeDisp(double * res) {
    //#[ operation r_counterclockwiseBreakfreeDisp(double * ) 
    *res = ccBreakfreeDisp - ccOilDisp - ccBreakfreeDispMax*actuatorConnector->pressure/pressureMax;
    
    return S_OK;
    
    //#]
}

HRESULT ClutchBase::r_forceBalance(double * res) {
    //#[ operation r_forceBalance(double * ) 
    *res = p->torque + n->torque;
      return S_OK;
    
    //#]
}

HRESULT ClutchBase::r_relativeVelocity(double * res) {
    //#[ operation r_relativeVelocity(double * ) 
    *res = DER(relativeVelocity) - (p->acceleration - n->acceleration);
    return S_OK;
    
    //#]
}

HRESULT ClutchBase::r_stickDisplacement(double * res) {
    //#[ operation r_stickDisplacement(double * ) 
    *res=DER(displacement) - relativeVelocity;
    return S_OK;
    
    //#]
}

HRESULT ClutchBase::s_cLockDisplacement(double * res) {
    //#[ operation s_cLockDisplacement(double * ) 
      *res = displacement - (OLD(cBreakfreeDisp) - 1.0e-5);
      return S_OK;
    
    //#]
}

HRESULT ClutchBase::s_ccLockDisplacement(double * res) {
    //#[ operation s_ccLockDisplacement(double * ) 
      *res = displacement - (-OLD(ccBreakfreeDisp) + 1.0e-5);
      return S_OK;
    
    //#]
}

HRESULT ClutchBase::z_disp_neg_slip(double * res) {
    //#[ operation z_disp_neg_slip(double * ) 
    *res= -displacement - ccBreakfreeDisp;
    return S_OK;
    
    //#]
}

HRESULT ClutchBase::z_disp_pos_slip(double * res) {
    //#[ operation z_disp_pos_slip(double * ) 
    *res = displacement - cBreakfreeDisp;
    return S_OK;
    
    //#]
}

HRESULT ClutchBase::z_velocity_neg(double * res) {
    //#[ operation z_velocity_neg(double * ) 
    *res = -relativeVelocity;
    return S_OK;
    
    //#]
}

HRESULT ClutchBase::z_velocity_pos(double * res) {
    //#[ operation z_velocity_pos(double * ) 
    *res = relativeVelocity;
    return S_OK;
    
    //#]
}

VarEx ClutchBase::get_cBreakfreeDisp() const {
    return _cBreakfreeDisp;
}

void ClutchBase::set_cBreakfreeDisp(VarEx  p__cBreakfreeDisp) {
    _cBreakfreeDisp = p__cBreakfreeDisp;
}

VarEx ClutchBase::get_ccBreakfreeDisp() const {
    return _ccBreakfreeDisp;
}

void ClutchBase::set_ccBreakfreeDisp(VarEx  p__ccBreakfreeDisp) {
    _ccBreakfreeDisp = p__ccBreakfreeDisp;
}

VarEx ClutchBase::get_displacement() const {
    return _displacement;
}

void ClutchBase::set_displacement(VarEx  p__displacement) {
    _displacement = p__displacement;
}

VarEx ClutchBase::get_relativeVelocity() const {
    return _relativeVelocity;
}

void ClutchBase::set_relativeVelocity(VarEx  p__relativeVelocity) {
    _relativeVelocity = p__relativeVelocity;
}

double ClutchBase::getArea() const {
    return area;
}

void ClutchBase::setArea(double  p_area) {
    area = p_area;
}

bool  ClutchBase::getBInConstruction() const {
    return bInConstruction;
}

void ClutchBase::setBInConstruction(bool p_bInConstruction) {
    bInConstruction = p_bInConstruction;
}

double ClutchBase::getCBreakfreeDisp() const {
    return cBreakfreeDisp;
}

void ClutchBase::setCBreakfreeDisp(double  p_cBreakfreeDisp) {
    cBreakfreeDisp = p_cBreakfreeDisp;
}

double ClutchBase::getCBreakfreeDispMax() const {
    return cBreakfreeDispMax;
}

void ClutchBase::setCBreakfreeDispMax(double  p_cBreakfreeDispMax) {
    cBreakfreeDispMax = p_cBreakfreeDispMax;
}

double ClutchBase::getCOilDisp() const {
    return cOilDisp;
}

void ClutchBase::setCOilDisp(double  p_cOilDisp) {
    cOilDisp = p_cOilDisp;
}

double ClutchBase::getCcBreakfreeDisp() const {
    return ccBreakfreeDisp;
}

void ClutchBase::setCcBreakfreeDisp(double  p_ccBreakfreeDisp) {
    ccBreakfreeDisp = p_ccBreakfreeDisp;
}

double ClutchBase::getCcBreakfreeDispMax() const {
    return ccBreakfreeDispMax;
}

void ClutchBase::setCcBreakfreeDispMax(double  p_ccBreakfreeDispMax) {
    ccBreakfreeDispMax = p_ccBreakfreeDispMax;
}

double ClutchBase::getCcOilDisp() const {
    return ccOilDisp;
}

void ClutchBase::setCcOilDisp(double  p_ccOilDisp) {
    ccOilDisp = p_ccOilDisp;
}

double ClutchBase::getDamping() const {
    return damping;
}

void ClutchBase::setDamping(double  p_damping) {
    damping = p_damping;
}

double ClutchBase::getDisplacement() const {
    return displacement;
}

void ClutchBase::setDisplacement(double  p_displacement) {
    displacement = p_displacement;
}

double ClutchBase::getFrictionCoefficient() const {
    return frictionCoefficient;
}

void ClutchBase::setFrictionCoefficient(double  p_frictionCoefficient) {
    frictionCoefficient = p_frictionCoefficient;
}

double ClutchBase::getPressureMax() const {
    return pressureMax;
}

void ClutchBase::setPressureMax(double  p_pressureMax) {
    pressureMax = p_pressureMax;
}

double ClutchBase::getRadius() const {
    return radius;
}

void ClutchBase::setRadius(double  p_radius) {
    radius = p_radius;
}

double ClutchBase::getRelativeVelocity() const {
    return relativeVelocity;
}

void ClutchBase::setRelativeVelocity(double  p_relativeVelocity) {
    relativeVelocity = p_relativeVelocity;
}

double ClutchBase::getStiffness() const {
    return stiffness;
}

void ClutchBase::setStiffness(double  p_stiffness) {
    stiffness = p_stiffness;
}

double ClutchBase::getTorqueRatio() const {
    return torqueRatio;
}

void ClutchBase::setTorqueRatio(double  p_torqueRatio) {
    torqueRatio = p_torqueRatio;
}

ActuatorClutchConnector* ClutchBase::getActuatorConnector() const {
    return actuatorConnector;
}

void ClutchBase::setActuatorConnector(ActuatorClutchConnector*  p_ActuatorClutchConnector) {
    actuatorConnector = p_ActuatorClutchConnector;
    if(p_ActuatorClutchConnector != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("actuatorConnector", p_ActuatorClutchConnector, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("actuatorConnector");
        }
}

CRigidConnector* ClutchBase::getN() const {
    return n;
}

void ClutchBase::setN(CRigidConnector*  p_CRigidConnector) {
    n = p_CRigidConnector;
    if(p_CRigidConnector != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("n", p_CRigidConnector, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("n");
        }
}

CRigidConnector* ClutchBase::getP() const {
    return p;
}

void ClutchBase::setP(CRigidConnector*  p_CRigidConnector) {
    p = p_CRigidConnector;
    if(p_CRigidConnector != NULL)
        {
            NOTIFY_RELATION_ITEM_ADDED("p", p_CRigidConnector, FALSE, TRUE);
        }
    else
        {
            NOTIFY_RELATION_CLEARED("p");
        }
}

void ClutchBase::rootState_entDef() {
    {
        NOTIFY_STATE_ENTERED("ROOT");
        NOTIFY_TRANSITION_STARTED("0");
        NOTIFY_STATE_ENTERED("ROOT.Lock");
        rootState_subState = Lock;
        rootState_active = Lock;
        //#[ state ROOT.Lock.(Entry) 
        if (!bInConstruction) OnTransition();
        //#]
        NOTIFY_TRANSITION_TERMINATED("0");
    }
}

int ClutchBase::rootState_dispatchEvent(short  id) {
    int res = eventNotConsumed;
    switch (rootState_active) {
        case cSlip:
        {
            if(IS_EVENT_TYPE_OF(es_SlipToLock_TransmissionModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("1");
                    NOTIFY_STATE_EXITED("ROOT.cSlip");
                    NOTIFY_STATE_ENTERED("ROOT.Lock");
                    rootState_subState = Lock;
                    rootState_active = Lock;
                    //#[ state ROOT.Lock.(Entry) 
                    if (!bInConstruction) OnTransition();
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("1");
                    res = eventConsumed;
                }
            
            break;
        };
        case ccSlip:
        {
            if(IS_EVENT_TYPE_OF(es_SlipToLock_TransmissionModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("3");
                    NOTIFY_STATE_EXITED("ROOT.ccSlip");
                    NOTIFY_STATE_ENTERED("ROOT.Lock");
                    rootState_subState = Lock;
                    rootState_active = Lock;
                    //#[ state ROOT.Lock.(Entry) 
                    if (!bInConstruction) OnTransition();
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("3");
                    res = eventConsumed;
                }
            
            break;
        };
        case Lock:
        {
            if(IS_EVENT_TYPE_OF(es_LockTocSlip_TransmissionModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("2");
                    NOTIFY_STATE_EXITED("ROOT.Lock");
                    NOTIFY_STATE_ENTERED("ROOT.cSlip");
                    rootState_subState = cSlip;
                    rootState_active = cSlip;
                    //#[ state ROOT.cSlip.(Entry) 
                    if (!bInConstruction) OnTransition();
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("2");
                    res = eventConsumed;
                }
            else if(IS_EVENT_TYPE_OF(es_LockToccSlip_TransmissionModels_id))
                {
                    NOTIFY_TRANSITION_STARTED("4");
                    NOTIFY_STATE_EXITED("ROOT.Lock");
                    NOTIFY_STATE_ENTERED("ROOT.ccSlip");
                    rootState_subState = ccSlip;
                    rootState_active = ccSlip;
                    //#[ state ROOT.ccSlip.(Entry) 
                    if (!bInConstruction) OnTransition();
                    //#]
                    NOTIFY_TRANSITION_TERMINATED("4");
                    res = eventConsumed;
                }
            
            break;
        };
        default:
            break;
    };
    return res;
}

void ClutchBase::initStatechart() {
    rootState_subState = OMNonState;
    rootState_active = OMNonState;
}

void ClutchBase::cleanUpRelations() {
    if(actuatorConnector != NULL)
        {
            NOTIFY_RELATION_CLEARED("actuatorConnector");
            actuatorConnector = NULL;
        }
    if(n != NULL)
        {
            NOTIFY_RELATION_CLEARED("n");
            n = NULL;
        }
    if(p != NULL)
        {
            NOTIFY_RELATION_CLEARED("p");
            p = NULL;
        }
}

OMBoolean ClutchBase::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}



#ifdef _OMINSTRUMENT


void OMAnimatedClutchBase::serializeAttributes(AOMSAttributes*  aomsAttributes) const {
}

void OMAnimatedClutchBase::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("actuatorConnector", FALSE, TRUE);
    if(myReal->actuatorConnector)
        aomsRelations->ADD_ITEM(myReal->actuatorConnector);
    aomsRelations->addRelation("n", FALSE, TRUE);
    if(myReal->n)
        aomsRelations->ADD_ITEM(myReal->n);
    aomsRelations->addRelation("p", FALSE, TRUE);
    if(myReal->p)
        aomsRelations->ADD_ITEM(myReal->p);
}

void OMAnimatedClutchBase::rootState_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT");
    switch (myReal->rootState_subState) {
        case ClutchBase::cSlip:
        {
            cSlip_serializeStates(aomsState);
            break;
        };
        case ClutchBase::ccSlip:
        {
            ccSlip_serializeStates(aomsState);
            break;
        };
        case ClutchBase::Lock:
        {
            Lock_serializeStates(aomsState);
            break;
        };
        default:
            break;
    };
}

void OMAnimatedClutchBase::Lock_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.Lock");
}

void OMAnimatedClutchBase::cSlip_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.cSlip");
}

void OMAnimatedClutchBase::ccSlip_serializeStates(AOMSState*  aomsState) const {
    aomsState->addState("ROOT.ccSlip");
}

IMPLEMENT_REACTIVE_META(ClutchBase, TransmissionModels, FALSE, OMAnimatedClutchBase)
#endif // _OMINSTRUMENT


/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\ClutchBase.cpp
*********************************************************************/

