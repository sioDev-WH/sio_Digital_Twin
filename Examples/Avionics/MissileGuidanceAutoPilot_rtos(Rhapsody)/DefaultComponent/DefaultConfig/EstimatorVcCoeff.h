/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: EstimatorVcCoeff
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\EstimatorVcCoeff.h
*********************************************************************/


#ifndef EstimatorVcCoeff_H 

#define EstimatorVcCoeff_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "GuidancePkg.h"

//## package GuidancePkg 

//----------------------------------------------------------------------------
// EstimatorVcCoeff.h                                                                  
//----------------------------------------------------------------------------

//## class EstimatorVcCoeff 
class EstimatorVcCoeff  {


////    Constructors and destructors    ////
public :
    
    //## operation EstimatorVcCoeff() 
    EstimatorVcCoeff();
    
    //## auto_generated 
    ~EstimatorVcCoeff();


////    Operations    ////
public :
    
    //## operation clean() 
    void clean();
    
    //## operation design(double) 
    void design(double  bandwidth);
    
    //## operation init() 
    void init();
    
    //## operation setBandwidth(double) 
    void setBandwidth(double  omega);
    
    //## operation setPeriod(long) 
    void setPeriod(long  val);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getA() const;
    
    //## auto_generated 
    void setA(double  p_A);
    
    //## auto_generated 
    double getB() const;
    
    //## auto_generated 
    void setB(double  p_B);
    
    //## auto_generated 
    double getBandwidth() const;
    
    //## auto_generated 
    long getPeriod() const;


////    Attributes    ////
public :
    
    double Bandwidth;		//## attribute Bandwidth 
    
    // Sampling Interval 40 mSec
    long period;		//## attribute period 
    
protected :
    
    double A;		//## attribute A 
    
    double B;		//## attribute B 
    

};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\EstimatorVcCoeff.h
*********************************************************************/
