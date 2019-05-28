/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Gear
//!	Generated Date	: Wed, 8, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Gear.h
*********************************************************************/


#ifndef Gear_H 

#define Gear_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "TransmissionModels.h"
#include "TransmissionControlModels.h"
#include "IOnVarInit.h"

//## package TransmissionModels 

//----------------------------------------------------------------------------
// Gear.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedGear;
#endif // _OMINSTRUMENT


//## class Gear 
class Gear : public IOnVarInit {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedGear;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation Gear() 
    Gear();
    
    //## operation ~Gear() 
    ~Gear();


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
    long getNTeeth() const;
    
    //## auto_generated 
    void setNTeeth(long  p_nTeeth);
    
    //## auto_generated 
    double getRadius() const;
    
    //## auto_generated 
    void setRadius(double  p_radius);
    
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
    
    long nTeeth;		//## attribute nTeeth 
    
    double radius;		//## attribute radius 
    
    double speed;		//## attribute speed 
    
    double torque;		//## attribute torque 
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedGear : virtual public AOMInstance {

    
    DECLARE_META(Gear, OMAnimatedGear)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Gear.h
*********************************************************************/

