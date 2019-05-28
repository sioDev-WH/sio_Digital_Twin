/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: transformAngle_DMC2Euler
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\transformAngle_DMC2Euler.h
*********************************************************************/


#ifndef transformAngle_DMC2Euler_H 

#define transformAngle_DMC2Euler_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "AvionicsPkg.h"

//## package LibraryPkg::AvionicsPkg 

//----------------------------------------------------------------------------
// transformAngle_DMC2Euler.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedtransformAngle_DMC2Euler;
#endif // _OMINSTRUMENT


//## class transformAngle_DMC2Euler 
class transformAngle_DMC2Euler  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedtransformAngle_DMC2Euler;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation transformAngle_DMC2Euler() 
    transformAngle_DMC2Euler();
    
    //## operation ~transformAngle_DMC2Euler() 
    ~transformAngle_DMC2Euler();


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
    double* getDMC() const;
    
    //## auto_generated 
    void setDMC(double*  p_DMC);
    
    //## auto_generated 
    int getDMC_size() const;
    
    //## auto_generated 
    void setDMC_size(int  p_DMC_size);
    
    //## auto_generated 
    double* getEulerAngles() const;
    
    //## auto_generated 
    void setEulerAngles(double*  p_eulerAngles);
    
    //## auto_generated 
    int getSize() const;
    
    //## auto_generated 
    void setSize(int  p_size);


////    Attributes    ////
protected :
    
    double* DMC;		//## attribute DMC 
    
    int DMC_size;		//## attribute DMC_size 
    
    double* eulerAngles;		//## attribute eulerAngles 
    
    int size;		//## attribute size 
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedtransformAngle_DMC2Euler : virtual public AOMInstance {

    
    DECLARE_META(transformAngle_DMC2Euler, OMAnimatedtransformAngle_DMC2Euler)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\transformAngle_DMC2Euler.h
*********************************************************************/

