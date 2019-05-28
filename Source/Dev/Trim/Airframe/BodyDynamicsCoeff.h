/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: BodyDynamicsCoeff
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\BodyDynamicsCoeff.h
*********************************************************************/


#ifndef BodyDynamicsCoeff_H 

#define BodyDynamicsCoeff_H 

//## package AirframePkg 

//----------------------------------------------------------------------------
// BodyDynamicsCoeff.h                                                                  
//----------------------------------------------------------------------------

//## class BodyDynamicsCoeff 
class BodyDynamicsCoeff {


////    Constructors and destructors    ////
public :
    
    //## operation BodyDynamicsCoeff() 
    BodyDynamicsCoeff();
    
    //## auto_generated 
    ~BodyDynamicsCoeff();


////    Operations    ////
public :

    //## operation init() 
    void init();


////    Attributes    ////
public :
    
    double Ixx;		//## attribute Ixx 
    
    double Iyy;		//## attribute Iyy 
    
    double Izz;		//## attribute Izz 
    
    double Mass;		//## attribute Mass 
    
    // Accelerometer distance in front of CG
    double accPos;		//## attribute accPos 
    

};


#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\BodyDynamicsCoeff.h
*********************************************************************/

