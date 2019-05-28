/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: GimbalControllerCoeff
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\GimbalControllerCoeff.h
*********************************************************************/


#ifndef GimbalControllerCoeff_H 

#define GimbalControllerCoeff_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "TrackingSubsystemPkg.h"

//## package TrackingSubsystemPkg 

//----------------------------------------------------------------------------
// GimbalControllerCoeff.h                                                                  
//----------------------------------------------------------------------------

//## class GimbalControllerCoeff 
class GimbalControllerCoeff  {


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
    
    //## operation setPeriod(long) 
    void setPeriod(long  val);


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
    long getPeriod() const;
    
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
    
    long period;		//## attribute period 
    
    // Ks
    double rateLoopBandwidth;		//## attribute rateLoopBandwidth 
    

};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\GimbalControllerCoeff.h
*********************************************************************/

