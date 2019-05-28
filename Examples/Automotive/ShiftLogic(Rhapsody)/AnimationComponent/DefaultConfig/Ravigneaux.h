/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Ravigneaux
//!	Generated Date	: Wed, 8, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Ravigneaux.h
*********************************************************************/


#ifndef Ravigneaux_H 

#define Ravigneaux_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "TransmissionModels.h"
#include <oxf/omthread.h>
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "Gear.h"
#include "PlanetaryCoupler.h"
#include "TransmissionControlModels.h"
#include "OnUMLDaeEsoImpl.h"

//## package TransmissionModels 

//----------------------------------------------------------------------------
// Ravigneaux.h                                                                  
//----------------------------------------------------------------------------
class CRigidConnector;

#ifdef _OMINSTRUMENT
class OMAnimatedRavigneaux;
#endif // _OMINSTRUMENT


//## class Ravigneaux 
class Ravigneaux : public OMReactive, public COnUMLDaeEsoImpl<Ravigneaux> {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedRavigneaux;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation Ravigneaux() 
    Ravigneaux(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~Ravigneaux() 
    ~Ravigneaux();


////    Operations    ////
public :
    
    //## operation Load(FILE * ) 
    bool Load(FILE * fs);
    
    //## operation Save(FILE * ) 
    void Save(FILE * fs);
    
    //## operation ad_r_CarrierDynamics(Fdouble * ) 
    HRESULT ad_r_CarrierDynamics(Fdouble * res);
    
    //## operation ad_r_ForwardSunDynamics(Fdouble * ) 
    HRESULT ad_r_ForwardSunDynamics(Fdouble * res);
    
    //## operation ad_r_ForwardToPinionKinematics(Fdouble * ) 
    HRESULT ad_r_ForwardToPinionKinematics(Fdouble * res);
    
    //## operation ad_r_LongPinionDynamics(Fdouble * ) 
    HRESULT ad_r_LongPinionDynamics(Fdouble * res);
    
    //## operation ad_r_PinionToPinionKinematics(Fdouble * ) 
    HRESULT ad_r_PinionToPinionKinematics(Fdouble * res);
    
    //## operation ad_r_PinionToRingKinematics(Fdouble * ) 
    HRESULT ad_r_PinionToRingKinematics(Fdouble * res);
    
    //## operation ad_r_ReverseSunDynamics(Fdouble * ) 
    HRESULT ad_r_ReverseSunDynamics(Fdouble * res);
    
    //## operation ad_r_ReverseToPinionKinematics(Fdouble * ) 
    HRESULT ad_r_ReverseToPinionKinematics(Fdouble * res);
    
    //## operation ad_r_RingDynamics(Fdouble * ) 
    HRESULT ad_r_RingDynamics(Fdouble * res);
    
    //## operation ad_r_ShortPinionDynamics(Fdouble * ) 
    HRESULT ad_r_ShortPinionDynamics(Fdouble * res);
    
    //## operation ad_r_iCouplerAcceleration(Fdouble * ) 
    HRESULT ad_r_iCouplerAcceleration(Fdouble * res);
    
    //## operation ad_r_iCouplerSpeed(Fdouble * ) 
    HRESULT ad_r_iCouplerSpeed(Fdouble * res);
    
    //## operation ad_r_iCouplerTorque(Fdouble * ) 
    HRESULT ad_r_iCouplerTorque(Fdouble * res);
    
    //## operation ad_r_ifSunAcceleration(Fdouble * ) 
    HRESULT ad_r_ifSunAcceleration(Fdouble * res);
    
    //## operation ad_r_ifSunSpeed(Fdouble * ) 
    HRESULT ad_r_ifSunSpeed(Fdouble * res);
    
    //## operation ad_r_ifSunTorque(Fdouble * ) 
    HRESULT ad_r_ifSunTorque(Fdouble * res);
    
    //## operation ad_r_irSunAcceleration(Fdouble * ) 
    HRESULT ad_r_irSunAcceleration(Fdouble * res);
    
    //## operation ad_r_irSunSpeed(Fdouble * ) 
    HRESULT ad_r_irSunSpeed(Fdouble * res);
    
    //## operation ad_r_irSunTorque(Fdouble * ) 
    HRESULT ad_r_irSunTorque(Fdouble * res);
    
    //## operation ad_r_longPinionSpeed(Fdouble * ) 
    HRESULT ad_r_longPinionSpeed(Fdouble * res);
    
    //## operation ad_r_longPinionTorque(Fdouble * ) 
    HRESULT ad_r_longPinionTorque(Fdouble * res);
    
    //## operation ad_r_oRingAcceleration(Fdouble * ) 
    HRESULT ad_r_oRingAcceleration(Fdouble * res);
    
    //## operation ad_r_oRingSpeed(Fdouble * ) 
    HRESULT ad_r_oRingSpeed(Fdouble * res);
    
    //## operation ad_r_oRingTorque(Fdouble * ) 
    HRESULT ad_r_oRingTorque(Fdouble * res);
    
    //## operation ad_r_shortPinionSpeed(Fdouble * ) 
    HRESULT ad_r_shortPinionSpeed(Fdouble * res);
    
    //## operation ad_r_shortPinionTorque(Fdouble * ) 
    HRESULT ad_r_shortPinionTorque(Fdouble * res);
    
    //## operation clean() 
    void clean();
    
    //## operation init() 
    void init();
    
    //## operation r_CarrierDynamics(double * ) 
    HRESULT r_CarrierDynamics(double * res);
    
    //## operation r_ForwardSunDynamics(double * ) 
    HRESULT r_ForwardSunDynamics(double * res);
    
    //## operation r_ForwardToPinionKinematics(double * ) 
    HRESULT r_ForwardToPinionKinematics(double * res);
    
    //## operation r_LongPinionDynamics(double * ) 
    HRESULT r_LongPinionDynamics(double * res);
    
    //## operation r_PinionToPinionKinematics(double * ) 
    HRESULT r_PinionToPinionKinematics(double * res);
    
    //## operation r_PinionToRingKinematics(double * ) 
    HRESULT r_PinionToRingKinematics(double * res);
    
    //## operation r_ReverseSunDynamics(double * ) 
    HRESULT r_ReverseSunDynamics(double * res);
    
    //## operation r_ReverseToPinionKinematics(double * ) 
    HRESULT r_ReverseToPinionKinematics(double * res);
    
    //## operation r_RingDynamics(double * ) 
    HRESULT r_RingDynamics(double * res);
    
    //## operation r_ShortPinionDynamics(double * ) 
    HRESULT r_ShortPinionDynamics(double * res);
    
    //## operation r_iCouplerAcceleration(double * ) 
    HRESULT r_iCouplerAcceleration(double * res);
    
    //## operation r_iCouplerSpeed(double * ) 
    HRESULT r_iCouplerSpeed(double * res);
    
    //## operation r_iCouplerTorque(double * ) 
    HRESULT r_iCouplerTorque(double * res);
    
    //## operation r_ifSunAcceleration(double * ) 
    HRESULT r_ifSunAcceleration(double * res);
    
    //## operation r_ifSunSpeed(double * ) 
    HRESULT r_ifSunSpeed(double * res);
    
    //## operation r_ifSunTorque(double * ) 
    HRESULT r_ifSunTorque(double * res);
    
    //## operation r_irSunAcceleration(double * ) 
    HRESULT r_irSunAcceleration(double * res);
    
    //## operation r_irSunSpeed(double * ) 
    HRESULT r_irSunSpeed(double * res);
    
    //## operation r_irSunTorque(double * ) 
    HRESULT r_irSunTorque(double * res);
    
    //## operation r_longPinionSpeed(double * ) 
    HRESULT r_longPinionSpeed(double * res);
    
    //## operation r_longPinionTorque(double * ) 
    HRESULT r_longPinionTorque(double * res);
    
    //## operation r_oRingAcceleration(double * ) 
    HRESULT r_oRingAcceleration(double * res);
    
    //## operation r_oRingSpeed(double * ) 
    HRESULT r_oRingSpeed(double * res);
    
    //## operation r_oRingTorque(double * ) 
    HRESULT r_oRingTorque(double * res);
    
    //## operation r_shortPinionSpeed(double * ) 
    HRESULT r_shortPinionSpeed(double * res);
    
    //## operation r_shortPinionTorque(double * ) 
    HRESULT r_shortPinionTorque(double * res);

protected :
    
    //## operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
    HRESULT InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form);
    
    //## operation InitEsos() 
    HRESULT InitEsos();
    
    //## operation InitLocalADEqns() 
    HRESULT InitLocalADEqns();
    
    //## operation InitLocalEqns() 
    HRESULT InitLocalEqns();
    
    //## operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    HRESULT InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getForwardToPinionForce() const;
    
    //## auto_generated 
    void setForwardToPinionForce(double  p_forwardToPinionForce);
    
    //## auto_generated 
    double getPinionToPinionForce() const;
    
    //## auto_generated 
    void setPinionToPinionForce(double  p_pinionToPinionForce);
    
    //## auto_generated 
    double getPinionToReverseForce() const;
    
    //## auto_generated 
    void setPinionToReverseForce(double  p_pinionToReverseForce);
    
    //## auto_generated 
    double getRingToPinionForce() const;
    
    //## auto_generated 
    void setRingToPinionForce(double  p_ringToPinionForce);
    
    //## auto_generated 
    PlanetaryCoupler* getCarrier() const;
    
    //## auto_generated 
    Gear* getForwardSun() const;
    
    //## auto_generated 
    CRigidConnector* getICoupler() const;
    
    //## auto_generated 
    void setICoupler(CRigidConnector*  p_CRigidConnector);
    
    //## auto_generated 
    CRigidConnector* getIfSun() const;
    
    //## auto_generated 
    void setIfSun(CRigidConnector*  p_CRigidConnector);
    
    //## auto_generated 
    CRigidConnector* getIrSun() const;
    
    //## auto_generated 
    void setIrSun(CRigidConnector*  p_CRigidConnector);
    
    //## auto_generated 
    Gear* getLongPinion() const;
    
    //## auto_generated 
    CRigidConnector* getORing() const;
    
    //## auto_generated 
    void setORing(CRigidConnector*  p_CRigidConnector);
    
    //## auto_generated 
    Gear* getReverseSun() const;
    
    //## auto_generated 
    Gear* getRing() const;
    
    //## auto_generated 
    Gear* getShortPinion() const;

protected :
    
    //## auto_generated 
    VarEx get_forwardToPinionForce() const;
    
    //## auto_generated 
    void set_forwardToPinionForce(VarEx  p__forwardToPinionForce);
    
    //## auto_generated 
    VarEx get_pinionToPinionForce() const;
    
    //## auto_generated 
    void set_pinionToPinionForce(VarEx  p__pinionToPinionForce);
    
    //## auto_generated 
    VarEx get_pinionToReverseForce() const;
    
    //## auto_generated 
    void set_pinionToReverseForce(VarEx  p__pinionToReverseForce);
    
    //## auto_generated 
    VarEx get_ringToPinionForce() const;
    
    //## auto_generated 
    void set_ringToPinionForce(VarEx  p__ringToPinionForce);


////    Framework operations    ////
public :
    
    //## auto_generated 
    virtual OMBoolean startBehavior();

protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
public :
    
    double forwardToPinionForce;		//## attribute forwardToPinionForce 
    
    double pinionToPinionForce;		//## attribute pinionToPinionForce 
    
    double pinionToReverseForce;		//## attribute pinionToReverseForce 
    
    double ringToPinionForce;		//## attribute ringToPinionForce 
    
protected :
    
    VarEx _forwardToPinionForce;		//## attribute _forwardToPinionForce 
    
    VarEx _pinionToPinionForce;		//## attribute _pinionToPinionForce 
    
    VarEx _pinionToReverseForce;		//## attribute _pinionToReverseForce 
    
    VarEx _ringToPinionForce;		//## attribute _ringToPinionForce 
    

////    Relations and components    ////
public :
    
    PlanetaryCoupler carrier;		//## classInstance carrier 
    
    
    Gear forwardSun;		//## classInstance forwardSun 
    
    
    CRigidConnector* iCoupler;		//## link iCoupler 
    
    
    CRigidConnector* ifSun;		//## link ifSun 
    
    
    CRigidConnector* irSun;		//## link irSun 
    
    
    Gear longPinion;		//## classInstance longPinion 
    
    
    CRigidConnector* oRing;		//## link oRing 
    
    
    Gear reverseSun;		//## classInstance reverseSun 
    
    
    Gear ring;		//## classInstance ring 
    
    
    Gear shortPinion;		//## classInstance shortPinion 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedRavigneaux : virtual public AOMInstance {

    
    DECLARE_REACTIVE_META(Ravigneaux, OMAnimatedRavigneaux)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Ravigneaux.h
*********************************************************************/

