/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: AeroCoeff
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\AeroCoeff.h
*********************************************************************/


#ifndef AeroCoeff_H 

#define AeroCoeff_H 


//## package AirframePkg 

//----------------------------------------------------------------------------
// AeroCoeff.h                                                                  
//----------------------------------------------------------------------------

//## class AeroCoeff 
class AeroCoeff {


////    Constructors and destructors    ////
public :
    
    //## operation AeroCoeff() 
    AeroCoeff();
    
    //## auto_generated 
    ~AeroCoeff();


////    Operations    ////
public :
    
      
    //## operation init() 
    void init();

public :
    
  
////    Attributes    ////
public :
    
    double Cm_alpha;		//## attribute Cm_alpha 
    
    double Cm_el;		//## attribute Cm_el 
    
    double Cm_q;		//## attribute Cm_q 
    
    double Cx_alpha;		//## attribute Cx_alpha 
    
    double Cx_el;		//## attribute Cx_el 
    
    double Cz_alpha;		//## attribute Cz_alpha 
    
    double Cz_el;		//## attribute Cz_el 
    
    double Mach;		//## attribute Mach 
    
    double S_ref;		//## attribute S_ref 
    
    // Velocity
    double V;		//## attribute V 
    
    // variables
    // Angle of attack
    double alpha;		//## attribute alpha 
    
    // Moment Coefficients
    double am;		//## attribute am 
    
    // Normal Force Coefficients
    double an;		//## attribute an 
    
    double bm;		//## attribute bm 
    
    double bn;		//## attribute bn 
    
    double cm;		//## attribute cm 
    
    double cn;		//## attribute cn 
    
    double d_ref;		//## attribute d_ref 
    

};


#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\AeroCoeff.h
*********************************************************************/

