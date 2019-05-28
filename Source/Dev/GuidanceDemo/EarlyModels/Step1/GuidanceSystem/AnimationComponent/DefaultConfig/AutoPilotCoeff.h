/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: AutoPilotCoeff
//!	Generated Date	: Tue, 10, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\AutoPilotCoeff.h
*********************************************************************/


#ifndef AutoPilotCoeff_H 

#define AutoPilotCoeff_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "GuidancePkg.h"

//## package GuidancePkg 

//----------------------------------------------------------------------------
// AutoPilotCoeff.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedAutoPilotCoeff;
#endif // _OMINSTRUMENT


//## class AutoPilotCoeff 
class AutoPilotCoeff  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedAutoPilotCoeff;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation AutoPilotCoeff() 
    AutoPilotCoeff();
    
    //## auto_generated 
    ~AutoPilotCoeff();


////    Operations    ////
public :
    
    //## operation init() 
    void init();


////    Additional operations    ////
public :
    
    //## auto_generated 
    void setAccelGain(double  p_accelGain);
    
    //## auto_generated 
    void setAntiAliasGain(double  p_antiAliasGain);
    
    //## auto_generated 
    void setAntiAliasPole(double  p_antiAliasPole);
    
    //## auto_generated 
    void setGyroFilterPole(double  p_gyroFilterPole);
    
    //## auto_generated 
    void setGyroFilterZero(double  p_gyroFilterZero);
    
    //## auto_generated 
    void setGyroGain(double  p_gyroGain);
    
    //## auto_generated 
    void setSamplingPeriod(double  p_samplingPeriod);


////    Attributes    ////
public :
    
    // W2
    double accelGain;		//## attribute accelGain 
    
    // = 100
    double antiAliasGain;		//## attribute antiAliasGain 
    
    // -100
    double antiAliasPole;		//## attribute antiAliasPole 
    
    // -W4
    double gyroFilterPole;		//## attribute gyroFilterPole 
    
    // -W3
    double gyroFilterZero;		//## attribute gyroFilterZero 
    
    // W1
    double gyroGain;		//## attribute gyroGain 
    
    double samplingPeriod;		//## attribute samplingPeriod 
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedAutoPilotCoeff : virtual public AOMInstance {

    
    DECLARE_META(AutoPilotCoeff, OMAnimatedAutoPilotCoeff)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\AutoPilotCoeff.h
*********************************************************************/

