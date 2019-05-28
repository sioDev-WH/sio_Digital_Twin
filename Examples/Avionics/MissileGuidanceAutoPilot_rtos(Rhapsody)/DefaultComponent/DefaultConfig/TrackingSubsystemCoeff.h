/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: TrackingSubsystemCoeff
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\TrackingSubsystemCoeff.h
*********************************************************************/


#ifndef TrackingSubsystemCoeff_H 

#define TrackingSubsystemCoeff_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "TrackingSubsystemPkg.h"

//## package TrackingSubsystemPkg 

//----------------------------------------------------------------------------
// TrackingSubsystemCoeff.h                                                                  
//----------------------------------------------------------------------------

//## class TrackingSubsystemCoeff 
class TrackingSubsystemCoeff  {


////    Constructors and destructors    ////
public :
    
    //## operation TrackingSubsystemCoeff() 
    TrackingSubsystemCoeff();
    
    //## auto_generated 
    ~TrackingSubsystemCoeff();


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
    long getPeriod() const;
    
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
    
    long period;		//## attribute period 
    
    double radarFrameRate;		//## attribute radarFrameRate 
    

};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\TrackingSubsystemCoeff.h
*********************************************************************/

