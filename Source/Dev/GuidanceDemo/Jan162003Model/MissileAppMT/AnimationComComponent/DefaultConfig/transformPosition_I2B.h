/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: transformPosition_I2B
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\transformPosition_I2B.h
*********************************************************************/


#ifndef transformPosition_I2B_H 

#define transformPosition_I2B_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "AvionicsPkg.h"

//## package LibraryPkg::AvionicsPkg 

//----------------------------------------------------------------------------
// transformPosition_I2B.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedtransformPosition_I2B;
#endif // _OMINSTRUMENT


//## class transformPosition_I2B 
class transformPosition_I2B  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedtransformPosition_I2B;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation transformPosition_I2B() 
    transformPosition_I2B();
    
    //## operation ~transformPosition_I2B() 
    ~transformPosition_I2B();


////    Operations    ////
public :
    
    //## operation broadcast() 
    void broadcast();
    
    //## operation clean() 
    void clean();
    
    //## operation handle_tick() 
    void handle_tick();
    
    //## operation init() 
    void init();
    
    //## operation receive() 
    void receive();
    
    //## operation update() 
    void update();


////    Additional operations    ////
public :
    
    //## auto_generated 
    double* getBody() const;
    
    //## auto_generated 
    void setBody(double*  p_body);
    
    //## auto_generated 
    double* getEulerAngles() const;
    
    //## auto_generated 
    void setEulerAngles(double*  p_eulerAngles);
    
    //## auto_generated 
    double* getInertial() const;
    
    //## auto_generated 
    void setInertial(double*  p_inertial);
    
    //## auto_generated 
    int getSize() const;
    
    //## auto_generated 
    void setSize(int  p_size);


////    Attributes    ////
protected :
    
    double* body;		//## attribute body 
    
    double* eulerAngles;		//## attribute eulerAngles 
    
    double* inertial;		//## attribute inertial 
    
    int size;		//## attribute size 
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedtransformPosition_I2B : virtual public AOMInstance {

    
    DECLARE_META(transformPosition_I2B, OMAnimatedtransformPosition_I2B)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\transformPosition_I2B.h
*********************************************************************/

