/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: aeroPort
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\aeroPort.h
*********************************************************************/


#ifndef aeroPort_H 

#define aeroPort_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AirframePkg.h"
#include "OnStlConnBase.h"
#include "aeroAngle.h"
#include "aeroForce.h"
#include "aeroPos.h"
#include "aeroRotAcc.h"
#include "aeroRotVel.h"
#include "aeroTorque.h"
#include "aeroVel.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// aeroPort.h                                                                  
//----------------------------------------------------------------------------

//## class aeroPort 
class aeroPort : public OnStlConnBase<aeroPort> {


////    Constructors and destructors    ////
public :
    
    //## auto_generated 
    aeroPort();
    
    //## auto_generated 
    ~aeroPort();


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
    Angle getAngle() const;
    
    //## auto_generated 
    void setAngle(Angle  p_angle);
    
    //## auto_generated 
    Force getForce() const;
    
    //## auto_generated 
    void setForce(Force  p_force);
    
    //## auto_generated 
    Moment getMoment() const;
    
    //## auto_generated 
    void setMoment(Moment  p_moment);
    
    //## auto_generated 
    Pos getPosition() const;
    
    //## auto_generated 
    void setPosition(Pos  p_position);
    
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
    
    Angle angle;		//## attribute angle 
    
    Force force;		//## attribute force 
    
    Moment moment;		//## attribute moment 
    
    Pos position;		//## attribute position 
    
    RotVel rate;		//## attribute rate 
    
    Vel velocity;		//## attribute velocity 
    

};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\aeroPort.h
*********************************************************************/

