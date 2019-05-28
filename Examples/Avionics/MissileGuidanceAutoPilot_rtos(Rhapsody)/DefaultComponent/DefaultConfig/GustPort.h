/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: GustPort
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\GustPort.h
*********************************************************************/


#ifndef GustPort_H 

#define GustPort_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AirframePkg.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// GustPort.h                                                                  
//----------------------------------------------------------------------------

//## class GustPort 
class GustPort : public OnStlConnBase<GustPort> {


////    Constructors and destructors    ////
public :
    
    //## auto_generated 
    GustPort();
    
    //## auto_generated 
    ~GustPort();


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
    RotVel getRate() const;
    
    //## auto_generated 
    void setRate(RotVel  p_rate);
    
    //## auto_generated 
    Vel getVelocity() const;
    
    //## auto_generated 
    void setVelocity(Vel  p_velocity);


////    Attributes    ////
public :
    
    RotVel rate;		//## attribute rate 
    
    Vel velocity;		//## attribute velocity 
    

};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\GustPort.h
*********************************************************************/

