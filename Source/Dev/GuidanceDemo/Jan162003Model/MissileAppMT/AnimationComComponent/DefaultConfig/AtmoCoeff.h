/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: AtmoCoeff
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\AtmoCoeff.h
*********************************************************************/


#ifndef AtmoCoeff_H 

#define AtmoCoeff_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "AirframePkg.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// AtmoCoeff.h                                                                  
//----------------------------------------------------------------------------

//## class AtmoCoeff 
class AtmoCoeff  {


////    Constructors and destructors    ////
public :
    
    //## operation AtmoCoeff() 
    AtmoCoeff();
    
    //## auto_generated 
    ~AtmoCoeff();


////    Operations    ////
public :
    
    //## operation init() 
    void init();


////    Additional operations    ////
public :
    
    //## auto_generated 
    void setR(double  p_R);
    
    //## auto_generated 
    void setGravity(double  p_gravity);
    
    //## auto_generated 
    void setLapseRate(double  p_lapseRate);
    
    //## auto_generated 
    void setMaxHeightRange(double  p_maxHeightRange);
    
    //## auto_generated 
    void setSeaLevelDensity(double  p_seaLevelDensity);
    
    //## auto_generated 
    void setSeaLevelPressure(double  p_seaLevelPressure);
    
    //## auto_generated 
    void setSeaLevelTemperature(double  p_seaLevelTemperature);
    
    //## auto_generated 
    void setSpecificHeatRatio(double  p_specificHeatRatio);
    
    //## auto_generated 
    void setTroposphere(double  p_troposphere);


////    Attributes    ////
public :
    
    double R;		//## attribute R 
    
    double gravity;		//## attribute gravity 
    
    double lapseRate;		//## attribute lapseRate 
    
    double maxHeightRange;		//## attribute maxHeightRange 
    
    double seaLevelDensity;		//## attribute seaLevelDensity 
    
    double seaLevelPressure;		//## attribute seaLevelPressure 
    
    double seaLevelTemperature;		//## attribute seaLevelTemperature 
    
    double specificHeatRatio;		//## attribute specificHeatRatio 
    
    double troposphere;		//## attribute troposphere 
    

};


#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\AtmoCoeff.h
*********************************************************************/

