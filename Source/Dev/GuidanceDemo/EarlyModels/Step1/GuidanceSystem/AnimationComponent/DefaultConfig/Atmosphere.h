/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Atmosphere
//!	Generated Date	: Tue, 10, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\Atmosphere.h
*********************************************************************/


#ifndef Atmosphere_H 

#define Atmosphere_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "GuidancePkg.h"

//## package GuidancePkg 

//----------------------------------------------------------------------------
// Atmosphere.h                                                                  
//----------------------------------------------------------------------------
class AtmoCoeff;

#ifdef _OMINSTRUMENT
class OMAnimatedAtmosphere;
#endif // _OMINSTRUMENT


//## class Atmosphere 
class Atmosphere  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedAtmosphere;
#endif // _OMINSTRUMENT


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
    void setAirDensity(double  p_airDensity);
    
    //## auto_generated 
    void setAirPressure(double  p_airPressure);
    
    //## auto_generated 
    void setSpeedOfSound(double  p_speedOfSound);
    
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


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedAtmosphere : virtual public AOMInstance {

    
    DECLARE_META(Atmosphere, OMAnimatedAtmosphere)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Atmosphere.h
*********************************************************************/

