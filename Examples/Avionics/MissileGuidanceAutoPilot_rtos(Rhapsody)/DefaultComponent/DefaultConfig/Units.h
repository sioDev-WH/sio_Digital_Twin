/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Units
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\Units.h
*********************************************************************/


#ifndef Units_H 

#define Units_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AirframePkg.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// Units.h                                                                  
//----------------------------------------------------------------------------

//## class Units 
class Units  {


////    Constructors and destructors    ////
public :
    
    //## operation Units() 
    Units();
    
    //## operation Units(UNITS_T) 
    Units(UNITS_T  Type);
    
    //## operation Units(const char [] ) 
    Units(const char unitSymbol[]);
    
    //## operation ~Units() 
    ~Units();


////    Operations    ////
public :
    
    //## operation operator=(Units & ) 
    void operator=(Units & u);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getBias() const;
    
    //## auto_generated 
    void setBias(double  p_bias);
    
    //## auto_generated 
    char getName(int  i1) const;
    
    //## auto_generated 
    void setName(int  i1, char  p_name);
    
    //## auto_generated 
    double getSlope() const;
    
    //## auto_generated 
    void setSlope(double  p_slope);
    
    //## auto_generated 
    UNITS_T getType() const;
    
    //## auto_generated 
    void setType(UNITS_T  p_type);


////    Attributes    ////
public :
    
    double bias;		//## attribute bias 
    
    char name[NAME_SIZE];		//## attribute name 
    
    double slope;		//## attribute slope 
    
    UNITS_T type;		//## attribute type 
    

};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Units.h
*********************************************************************/

