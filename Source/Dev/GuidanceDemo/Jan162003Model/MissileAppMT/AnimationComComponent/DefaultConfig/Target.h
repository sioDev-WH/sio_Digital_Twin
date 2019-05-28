/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: Target
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\Target.h
*********************************************************************/


#ifndef Target_H 

#define Target_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "TargetPkg.h"
#include "OnModelBase.h"

//## package TargetPkg 

//----------------------------------------------------------------------------
// Target.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedTarget;
#endif // _OMINSTRUMENT


//## class Target 
class Target : public COnModelBase {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedTarget;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation Target() 
    Target();
    
    //## operation ~Target() 
    ~Target();


////    Operations    ////
public :
    
    //## operation clean() 
    void clean();
    
    //## operation get_x(const double,double *) 
    void get_x(const double  t, double *val);
    
    //## operation get_z(const double,double *) 
    void get_z(const double  t, double *val);
    
    //## operation handle_tick(const double) 
    void handle_tick(const double  t);
    
    //## operation init() 
    void init();


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getV() const;
    
    //## auto_generated 
    void setV(double  p_V);
    
    //## auto_generated 
    double getAttitude() const;
    
    //## auto_generated 
    void setAttitude(double  p_attitude);
    
    //## auto_generated 
    double getPeriod() const;
    
    //## auto_generated 
    void setPeriod(double  p_period);
    
    //## auto_generated 
    double getX() const;
    
    //## auto_generated 
    void setX(double  p_x);
    
    //## auto_generated 
    double getZ() const;
    
    //## auto_generated 
    void setZ(double  p_z);


////    Attributes    ////
protected :
    
    double V;		//## attribute V 
    
    double attitude;		//## attribute attitude 
    
    double period;		//## attribute period 
    
    double x;		//## attribute x 
    
    double z;		//## attribute z 
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedTarget : virtual public AOMInstance {

    
    DECLARE_META(Target, OMAnimatedTarget)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\Target.h
*********************************************************************/

