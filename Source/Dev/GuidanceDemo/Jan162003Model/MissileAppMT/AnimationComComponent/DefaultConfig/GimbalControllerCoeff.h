/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: GimbalControllerCoeff
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\GimbalControllerCoeff.h
*********************************************************************/


#ifndef GimbalControllerCoeff_H 

#define GimbalControllerCoeff_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "SeekerSubsystemPkg.h"

//## package SeekerSubsystemPkg 

//----------------------------------------------------------------------------
// GimbalControllerCoeff.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedGimbalControllerCoeff;
#endif // _OMINSTRUMENT


//## class GimbalControllerCoeff 
class GimbalControllerCoeff  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedGimbalControllerCoeff;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation GimbalControllerCoeff() 
    GimbalControllerCoeff();
    
    //## auto_generated 
    ~GimbalControllerCoeff();


////    Operations    ////
public :
    
    //## operation clean() 
    void clean();
    
    //## operation init() 
    void init();


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getGimbalAngle_max() const;
    
    //## auto_generated 
    void setGimbalAngle_max(double  p_GimbalAngle_max);
    
    //## auto_generated 
    double getGimbalAngle_min() const;
    
    //## auto_generated 
    void setGimbalAngle_min(double  p_GimbalAngle_min);
    
    //## auto_generated 
    double getRadomeAberrtion() const;
    
    //## auto_generated 
    void setRadomeAberrtion(double  p_RadomeAberrtion);
    
    //## auto_generated 
    double getTrackingTimeConstant() const;
    
    //## auto_generated 
    void setTrackingTimeConstant(double  p_TrackingTimeConstant);
    
    //## auto_generated 
    double getPeriod() const;
    
    //## auto_generated 
    void setPeriod(double  p_period);
    
    //## auto_generated 
    double getRateLoopBandwidth() const;
    
    //## auto_generated 
    void setRateLoopBandwidth(double  p_rateLoopBandwidth);


////    Attributes    ////
public :
    
    double GimbalAngle_max;		//## attribute GimbalAngle_max 
    
    double GimbalAngle_min;		//## attribute GimbalAngle_min 
    
    double RadomeAberrtion;		//## attribute RadomeAberrtion 
    
    // tors
    double TrackingTimeConstant;		//## attribute TrackingTimeConstant 
    
    double period;		//## attribute period 
    
    // Ks
    double rateLoopBandwidth;		//## attribute rateLoopBandwidth 
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedGimbalControllerCoeff : virtual public AOMInstance {

    
    DECLARE_META(GimbalControllerCoeff, OMAnimatedGimbalControllerCoeff)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\GimbalControllerCoeff.h
*********************************************************************/

