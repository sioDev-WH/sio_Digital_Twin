/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: transformAngleRate
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\transformAngleRate.h
*********************************************************************/


#ifndef transformAngleRate_H 

#define transformAngleRate_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "AvionicsPkg.h"

//## package LibraryPkg::AvionicsPkg 

//----------------------------------------------------------------------------
// transformAngleRate.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedtransformAngleRate;
#endif // _OMINSTRUMENT


//## class transformAngleRate 
class transformAngleRate  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedtransformAngleRate;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation transformAngleRate() 
    transformAngleRate();
    
    //## operation ~transformAngleRate() 
    ~transformAngleRate();


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
    double* getBodyRates() const;
    
    //## auto_generated 
    void setBodyRates(double*  p_bodyRates);
    
    //## auto_generated 
    double* getEulerAngles() const;
    
    //## auto_generated 
    void setEulerAngles(double*  p_eulerAngles);
    
    //## auto_generated 
    double* getEulerRates() const;
    
    //## auto_generated 
    void setEulerRates(double*  p_eulerRates);
    
    //## auto_generated 
    int getSize() const;
    
    //## auto_generated 
    void setSize(int  p_size);


////    Attributes    ////
protected :
    
    double* bodyRates;		//## attribute bodyRates 
    
    double* eulerAngles;		//## attribute eulerAngles 
    
    double* eulerRates;		//## attribute eulerRates 
    
    int size;		//## attribute size 
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedtransformAngleRate : virtual public AOMInstance {

    
    DECLARE_META(transformAngleRate, OMAnimatedtransformAngleRate)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\transformAngleRate.h
*********************************************************************/

