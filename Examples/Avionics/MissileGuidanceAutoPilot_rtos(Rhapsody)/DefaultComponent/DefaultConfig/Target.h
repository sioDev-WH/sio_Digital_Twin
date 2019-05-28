/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Target
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\Target.h
*********************************************************************/


#ifndef Target_H 

#define Target_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "TargetPkg.h"
#include "OnModelBase.h"

//## package TargetPkg 

//----------------------------------------------------------------------------
// Target.h                                                                  
//----------------------------------------------------------------------------

//## class Target 
class Target : public COnModelBase {


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
    
    //## operation get_x(double *) 
    void get_x(double *val);
    
    //## operation get_z(double *) 
    void get_z(double *val);
    
    //## operation handle_tick() 
    void handle_tick();
    
    //## operation init() 
    void init();
    
    //## operation setPeriod(long) 
    void setPeriod(long  val);


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
    long getPeriod() const;
    
    //## auto_generated 
    double getX() const;
    
    //## auto_generated 
    void setX(double  p_x);
    
    //## auto_generated 
    double getZ() const;
    
    //## auto_generated 
    void setZ(double  p_z);


////    Attributes    ////
public :
    
    double V;		//## attribute V 
    
    double attitude;		//## attribute attitude 
    
    long period;		//## attribute period 
    
    double x;		//## attribute x 
    
    double z;		//## attribute z 
    

};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Target.h
*********************************************************************/

