/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: AtmoPort
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\AtmoPort.h
*********************************************************************/


#ifndef AtmoPort_H 

#define AtmoPort_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AirframePkg.h"
#include "aeroDensity.h"
#include "aeroSpeedOfSound.h"
#include "OnStlConnBase.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// AtmoPort.h                                                                  
//----------------------------------------------------------------------------

//## class AtmoPort 
class AtmoPort : public OnStlConnBase<AtmoPort> {


////    Constructors and destructors    ////
public :
    
    //## auto_generated 
    AtmoPort();
    
    //## auto_generated 
    ~AtmoPort();


////    Operations    ////
public :
    
    //## operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    HRESULT InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly);
    
    //## operation Load(FILE * ) 
    bool Load(FILE * fs);
    
    //## operation Save(FILE * ) 
    void Save(FILE * fs);
    
    //## operation enumVars(OnStlVec<double> * * & ,long & ) 
    void enumVars(OnStlVec<double> * * & vec, long & size);


////    Additional operations    ////
public :
    
    //## auto_generated 
    aeroDensity<double>  getAirDensity() const;
    
    //## auto_generated 
    void setAirDensity(aeroDensity<double> p_airDensity);
    
    //## auto_generated 
    aeroSpeedOfSound<double>  getSpeedOfSound() const;
    
    //## auto_generated 
    void setSpeedOfSound(aeroSpeedOfSound<double> p_speedOfSound);


////    Attributes    ////
public :
    
    aeroDensity<double> airDensity;		//## attribute airDensity 
    
    aeroSpeedOfSound<double> speedOfSound;		//## attribute speedOfSound 
    

};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\AtmoPort.h
*********************************************************************/

