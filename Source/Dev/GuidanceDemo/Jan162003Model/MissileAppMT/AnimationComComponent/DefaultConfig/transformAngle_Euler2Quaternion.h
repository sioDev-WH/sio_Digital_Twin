/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: transformAngle_Euler2Quaternion
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\transformAngle_Euler2Quaternion.h
*********************************************************************/


#ifndef transformAngle_Euler2Quaternion_H 

#define transformAngle_Euler2Quaternion_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "AvionicsPkg.h"

//## package LibraryPkg::AvionicsPkg 

//----------------------------------------------------------------------------
// transformAngle_Euler2Quaternion.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedtransformAngle_Euler2Quaternion;
#endif // _OMINSTRUMENT


//## class transformAngle_Euler2Quaternion 
class transformAngle_Euler2Quaternion  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedtransformAngle_Euler2Quaternion;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation transformAngle_Euler2Quaternion() 
    transformAngle_Euler2Quaternion();
    
    //## operation ~transformAngle_Euler2Quaternion() 
    ~transformAngle_Euler2Quaternion();


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
    double* getEulerAngles() const;
    
    //## auto_generated 
    void setEulerAngles(double*  p_eulerAngles);
    
    //## auto_generated 
    double* getQ() const;
    
    //## auto_generated 
    void setQ(double*  p_q);
    
    //## auto_generated 
    int getQ_size() const;
    
    //## auto_generated 
    void setQ_size(int  p_q_size);
    
    //## auto_generated 
    int getSize() const;
    
    //## auto_generated 
    void setSize(int  p_size);


////    Attributes    ////
protected :
    
    double* eulerAngles;		//## attribute eulerAngles 
    
    double* q;		//## attribute q 
    
    int q_size;		//## attribute q_size 
    
    int size;		//## attribute size 
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedtransformAngle_Euler2Quaternion : virtual public AOMInstance {

    
    DECLARE_META(transformAngle_Euler2Quaternion, OMAnimatedtransformAngle_Euler2Quaternion)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\transformAngle_Euler2Quaternion.h
*********************************************************************/

