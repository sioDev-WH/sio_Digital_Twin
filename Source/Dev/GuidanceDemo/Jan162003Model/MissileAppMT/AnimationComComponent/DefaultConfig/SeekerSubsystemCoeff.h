/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: SeekerSubsystemCoeff
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\SeekerSubsystemCoeff.h
*********************************************************************/


#ifndef SeekerSubsystemCoeff_H 

#define SeekerSubsystemCoeff_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "SeekerSubsystemPkg.h"

//## package SeekerSubsystemPkg 

//----------------------------------------------------------------------------
// SeekerSubsystemCoeff.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedSeekerSubsystemCoeff;
#endif // _OMINSTRUMENT


//## class SeekerSubsystemCoeff 
class SeekerSubsystemCoeff  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedSeekerSubsystemCoeff;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation SeekerSubsystemCoeff() 
    SeekerSubsystemCoeff();
    
    //## auto_generated 
    ~SeekerSubsystemCoeff();


////    Operations    ////
public :
    
    //## operation clean() 
    void clean();
    
    //## operation init() 
    void init();


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getPeriod() const;
    
    //## auto_generated 
    void setPeriod(double  p_period);
    
    //## auto_generated 
    double getRadarBeamWidth() const;
    
    //## auto_generated 
    void setRadarBeamWidth(double  p_radarBeamWidth);
    
    //## auto_generated 
    double getRadarFrameRate() const;
    
    //## auto_generated 
    void setRadarFrameRate(double  p_radarFrameRate);


////    Attributes    ////
public :
    
    // rad
    double radarBeamWidth;		//## attribute radarBeamWidth 
    
protected :
    
    double period;		//## attribute period 
    
    double radarFrameRate;		//## attribute radarFrameRate 
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedSeekerSubsystemCoeff : virtual public AOMInstance {

    
    DECLARE_META(SeekerSubsystemCoeff, OMAnimatedSeekerSubsystemCoeff)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\SeekerSubsystemCoeff.h
*********************************************************************/

