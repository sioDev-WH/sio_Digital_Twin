/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: CRigidConnector
//!	Generated Date	: Wed, 8, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\CRigidConnector.h
*********************************************************************/


#ifndef CRigidConnector_H 

#define CRigidConnector_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "TransmissionModels.h"
#include "TransmissionControlModels.h"
#include "OnUMLConnectorImpl.h"

//## package TransmissionModels 

//----------------------------------------------------------------------------
// CRigidConnector.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedCRigidConnector;
#endif // _OMINSTRUMENT


// 
//## class CRigidConnector 
class CRigidConnector : public COnUMLConnectorImpl<CRigidConnector> {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedCRigidConnector;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation CRigidConnector() 
    CRigidConnector();
    
    //## operation ~CRigidConnector() 
    virtual ~CRigidConnector();


////    Operations    ////
public :
    
    //## operation GetADResidual(long,double,Fdouble * ) 
    HRESULT GetADResidual(long  iEqn, double  t, Fdouble * residual);
    
    //## operation GetResiduals(long * ,long,double,double * ) 
    HRESULT GetResiduals(long * iEqns, long  nEqn, double  t, double * residuals);
    
    //## operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
    HRESULT InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form);
    
    //## operation InitLocalADEqns() 
    HRESULT InitLocalADEqns();
    
    //## operation InitLocalEqns() 
    HRESULT InitLocalEqns();
    
    //## operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    HRESULT InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly);
    
    //## operation Load(FILE * ) 
    bool Load(FILE * fs);
    
    //## operation Save(FILE * ) 
    void Save(FILE * fs);


////    Additional operations    ////
public :
    
    //## auto_generated 
    VarEx get_acceleration() const;
    
    //## auto_generated 
    void set_acceleration(VarEx  p__acceleration);
    
    //## auto_generated 
    VarEx get_torque() const;
    
    //## auto_generated 
    void set_torque(VarEx  p__torque);
    
    //## auto_generated 
    double getAcceleration() const;
    
    //## auto_generated 
    void setAcceleration(double  p_acceleration);
    
    //## auto_generated 
    double getTorque() const;
    
    //## auto_generated 
    void setTorque(double  p_torque);


////    Attributes    ////
public :
    
    VarEx _acceleration;		//## attribute _acceleration 
    
    VarEx _torque;		//## attribute _torque 
    
    // rotational acceleration
    double acceleration;		//## attribute acceleration 
    
    // torque
    double torque;		//## attribute torque 
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedCRigidConnector : virtual public AOMInstance {

    
    DECLARE_META(CRigidConnector, OMAnimatedCRigidConnector)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\CRigidConnector.h
*********************************************************************/

