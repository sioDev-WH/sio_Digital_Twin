/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: Atmosphere
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\Atmosphere.h
*********************************************************************/


#ifndef Atmosphere_H 

#define Atmosphere_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "AirframePkg.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// Atmosphere.h                                                                  
//----------------------------------------------------------------------------
class AtmoCoeff;


//## class Atmosphere 
class Atmosphere  {


////    Constructors and destructors    ////
public :
    
    //## operation Atmosphere() 
    Atmosphere();
    
    //## operation ~Atmosphere() 
    virtual ~Atmosphere();


////    Operations    ////
public :
    
    //## operation clean() 
    void clean();
    
    //## operation init() 
    void init();
    
    //## operation setCoeff(AtmoCoeff * ) 
    void setCoeff(AtmoCoeff * pC);
    
    //## operation setHeight(double) 
    void setHeight(double  h);
    
    //## operation updateData(double) 
    void updateData(double  height);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getAirDensity() const;
    
    //## auto_generated 
    void setAirDensity(double  p_airDensity);
    
    //## auto_generated 
    double getAirPressure() const;
    
    //## auto_generated 
    void setAirPressure(double  p_airPressure);
    
    //## auto_generated 
    double getHeight() const;
    
    //## auto_generated 
    double getSpeedOfSound() const;
    
    //## auto_generated 
    void setSpeedOfSound(double  p_speedOfSound);
    
    //## auto_generated 
    double getTemperature() const;
    
    //## auto_generated 
    void setTemperature(double  p_temperature);
    
    //## auto_generated 
    AtmoCoeff* getPCoeff() const;
    
    //## auto_generated 
    void setPCoeff(AtmoCoeff*  p_AtmoCoeff);


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
public :
    
    double airDensity;		//## attribute airDensity 
    
    double airPressure;		//## attribute airPressure 
    
    double height;		//## attribute height 
    
    double speedOfSound;		//## attribute speedOfSound 
    
    double temperature;		//## attribute temperature 
    

////    Relations and components    ////
public :
    
    AtmoCoeff* pCoeff;		//## link pCoeff 
    


};


#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\Atmosphere.h
*********************************************************************/

