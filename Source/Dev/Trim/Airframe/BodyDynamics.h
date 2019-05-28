/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: BodyDynamics
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\BodyDynamics.h
*********************************************************************/


#ifndef BodyDynamics_H 

#define BodyDynamics_H 




//----------------------------------------------------------------------------
// BodyDynamics.h                                                                  
//----------------------------------------------------------------------------
class BodyDynamicsCoeff;


//## class BodyDynamics 
class BodyDynamics {


////    Constructors and destructors    ////
public :
    
    //## operation BodyDynamics() 
    BodyDynamics();
    
    //## operation ~BodyDynamics() 
    virtual ~BodyDynamics();


////    Operations    ////
public :
    
   
    //## operation clean() 
    void clean();
    
   
    //## operation init() 
    void init();
    
    //## operation r_q(double * ) 
    void r_q(double * res);
    
    // residual equations
    //## operation r_theta(double * ) 
    void r_theta(double * res);
    
    //## operation r_u(double * ) 
    void r_u(double * res);
    
    //## operation r_w(double * ) 
    void r_w(double * res);
    
    //## operation r_x(double * ) 
    void r_x(double * res);
    
    //## operation r_z(double * ) 
    void r_z(double * res);
    
    // state machine implementation
    // reset equations
    //## operation s_alpha(double * ) 
    void s_alpha(double * res);
    
    //## operation s_u(double * ) 
    void s_u(double * res);




////    Additional operations    ////
public :
    
   
////    Attributes    ////
public :
    
    // positions
    // (yaw, pitch, roll)[Local Frame] - rot(x) o rot(y) o rot(z)
    double theta;		//## attribute theta 
    
    // Inertial Xe, Ye, Ze positions
    double x;		//## attribute x 
    
    // Inertial Xe, Ye, Ze positions
    double z;		//## attribute z 
    
public :
    
    // connectors
    // On3DConn* pAero;		//## link pAero 
  
    
    BodyDynamicsCoeff* pCoeff;		//## link pCoeff 
    


};


#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\BodyDynamics.h
*********************************************************************/

