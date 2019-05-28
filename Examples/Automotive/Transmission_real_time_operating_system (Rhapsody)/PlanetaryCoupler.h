/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: PlanetaryCoupler
//!	Generated Date	: Wed, 8, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\PlanetaryCoupler.h
*********************************************************************/


#ifndef PlanetaryCoupler_H 

#define PlanetaryCoupler_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "TransmissionModels.h"
#include "TransmissionControlModels.h"
#include "IOnVarInit.h"

//## package TransmissionModels 

//----------------------------------------------------------------------------
// PlanetaryCoupler.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedPlanetaryCoupler;
#endif // _OMINSTRUMENT


//## class PlanetaryCoupler 
class PlanetaryCoupler : public IOnVarInit {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedPlanetaryCoupler;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation PlanetaryCoupler() 
    PlanetaryCoupler();
    
    //## operation ~PlanetaryCoupler() 
    ~PlanetaryCoupler();


////    Operations    ////
public :
    
    //## operation init() 
    void init();

protected :
    
    //## operation InitLocalIPars(const _TCHAR * ,pplong * ,ppchar * ,long * ,long * ) 
    HRESULT InitLocalIPars(const _TCHAR * prefix, pplong * pars, ppchar * Names, long * nPars, long * dPars);
    
    //## operation InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ) 
    HRESULT InitLocalRPars(const _TCHAR * prefix, ppdouble * pars, ppchar * Names, long * nPars, long * dPars);
    
    //## operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    HRESULT InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getAcceleration() const;
    
    //## auto_generated 
    void setAcceleration(double  p_acceleration);
    
    //## auto_generated 
    double getInertia() const;
    
    //## auto_generated 
    void setInertia(double  p_inertia);
    
    //## auto_generated 
    double getSpeed() const;
    
    //## auto_generated 
    void setSpeed(double  p_speed);
    
    //## auto_generated 
    double getTorque() const;
    
    //## auto_generated 
    void setTorque(double  p_torque);

protected :
    
    //## auto_generated 
    VarEx get_acceleration() const;
    
    //## auto_generated 
    void set_acceleration(VarEx  p__acceleration);
    
    //## auto_generated 
    VarEx get_speed() const;
    
    //## auto_generated 
    void set_speed(VarEx  p__speed);
    
    //## auto_generated 
    VarEx get_torque() const;
    
    //## auto_generated 
    void set_torque(VarEx  p__torque);


////    Attributes    ////
public :
    
    VarEx _acceleration;		//## attribute _acceleration 
    
    VarEx _speed;		//## attribute _speed 
    
    VarEx _torque;		//## attribute _torque 
    
    double acceleration;		//## attribute acceleration 
    
    double inertia;		//## attribute inertia 
    
    double speed;		//## attribute speed 
    
    double torque;		//## attribute torque 
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedPlanetaryCoupler : virtual public AOMInstance {

    
    DECLARE_META(PlanetaryCoupler, OMAnimatedPlanetaryCoupler)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\PlanetaryCoupler.h
*********************************************************************/

