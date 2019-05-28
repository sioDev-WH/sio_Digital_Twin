/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: CMass
//!	Generated Date	: Wed, 8, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\CMass.h
*********************************************************************/


#ifndef CMass_H 

#define CMass_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "StandardModels.h"
#include "TransmissionControlModels.h"
#include "OnUMLDaeEsoImpl.h"

//## package StandardModels 

//----------------------------------------------------------------------------
// CMass.h                                                                  
//----------------------------------------------------------------------------
class CRigidConnector;

#ifdef _OMINSTRUMENT
class OMAnimatedCMass;
#endif // _OMINSTRUMENT


// {{SCG_CLASS(0)
// {{SCG_CLASS_INFO(0)
//## class CMass 
class CMass : public COnUMLDaeEsoImpl<CMass> {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedCMass;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation CMass() 
    CMass();
    
    //## operation ~CMass() 
    ~CMass();


////    Operations    ////
public :
    
    //## operation Load(FILE * ) 
    bool Load(FILE * fs);
    
    //## operation Save(FILE * ) 
    void Save(FILE * fs);
    
    //## operation ad_res0(Fdouble * ) 
    HRESULT ad_res0(Fdouble * res);
    
    //## operation ad_res1(Fdouble * ) 
    HRESULT ad_res1(Fdouble * res);
    
    //## operation ad_res2(Fdouble * ) 
    HRESULT ad_res2(Fdouble * res);
    
    //## operation clean() 
    void clean();
    
    //## operation handle_J(const double ,const double * ) 
    void handle_J(const double t, const double * val);
    
    //## operation init() 
    void init();
    
    //## operation res0(double * ) 
    HRESULT res0(double * res);
    
    //## operation res1(double * ) 
    HRESULT res1(double * res);
    
    //## operation res2(double * ) 
    HRESULT res2(double * res);

protected :
    
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


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getJ() const;
    
    //## auto_generated 
    void setJ(double  p_J);
    
    //## auto_generated 
    double getVelocity() const;
    
    //## auto_generated 
    void setVelocity(double  p_velocity);
    
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
    VarEx get_velocity() const;
    
    //## auto_generated 
    void set_velocity(VarEx  p__velocity);


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
public :
    
    double J;		//## attribute J 
    
    double velocity;		//## attribute velocity 
    
protected :
    
    VarEx _velocity;		//## attribute _velocity 
    

////    Relations and components    ////
public :
    
    CRigidConnector* n;		//## link n 
    
    
    CRigidConnector* p;		//## link p 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedCMass : virtual public AOMInstance {

    
    DECLARE_META(CMass, OMAnimatedCMass)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\CMass.h
*********************************************************************/

