/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: AeroDynamics
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\AeroDynamics.h
*********************************************************************/


#ifndef AeroDynamics_H 

#define AeroDynamics_H 


//## package AirframePkg 

//----------------------------------------------------------------------------
// AeroDynamics.h                                                                  
//----------------------------------------------------------------------------
class AeroCoeff;
class Atmosphere;
class BodyDynamics;


//## class AeroDynamics 
class AeroDynamics {


////    Constructors and destructors    ////
public :
    
    //## operation AeroDynamics() 
    AeroDynamics();
    
    //## operation ~AeroDynamics() 
    virtual ~AeroDynamics();


////    Operations    ////
public :
    
    
    //## operation clean() 
    void clean();
    
    //## operation init() 
    void init();
    
    //## operation r_Cm_alpha(double * ) 
    void r_Cm_alpha(double * res);
    
    //## operation r_Cx_alpha(double * ) 
    void r_Cx_alpha(double * res);
    
    //## operation r_Cz_alpha(double * ) 
    void r_Cz_alpha(double * res);
    
    //## operation r_Fx(double * ) 
    void r_Fx(double * res);
    
    //## operation r_Fz(double * ) 
    void r_Fz(double * res);
    
    //## operation r_Mach(double * ) 
    void r_Mach(double * res);
    
    //## operation r_My(double * ) 
    void r_My(double * res);
    
    //## operation r_V(double * ) 
    void r_V(double * res);
    
    // residual equations for dynamics
    //## operation r_alpha(double * ) 
    void r_alpha(double * res);
    
    // parameter update
    //## operation setThrust(const double ,double * ) 
    void setThrust(const double time, double * val);


///    Attributes    ////
public :
    
    // parameters
    double Thrust;		//## attribute Thrust 
    

////    Relations and components    ////
public :
    
    // to get speedOfSound and airDensity
    Atmosphere* pAtmosphere;		//## link pAtmosphere 
    
    BodyDynamics* pBody;
	double FinPosition;
    // aggregated members
    AeroCoeff* pCoeff;		//## link pCoeff 
    
    


};


#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\AeroDynamics.h
*********************************************************************/

