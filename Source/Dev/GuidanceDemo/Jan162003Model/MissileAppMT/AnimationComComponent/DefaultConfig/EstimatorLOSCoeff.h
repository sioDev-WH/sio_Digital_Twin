/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: EstimatorLOSCoeff
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\EstimatorLOSCoeff.h
*********************************************************************/


#ifndef EstimatorLOSCoeff_H 

#define EstimatorLOSCoeff_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "SeekerSubsystemPkg.h"

//## package SeekerSubsystemPkg 

//----------------------------------------------------------------------------
// EstimatorLOSCoeff.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedEstimatorLOSCoeff;
#endif // _OMINSTRUMENT


//## class EstimatorLOSCoeff 
class EstimatorLOSCoeff  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedEstimatorLOSCoeff;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation EstimatorLOSCoeff() 
    EstimatorLOSCoeff();
    
    //## auto_generated 
    ~EstimatorLOSCoeff();


////    Operations    ////
public :
    
    //## operation clean() 
    void clean();
    
    //## operation design(double,double) 
    void design(double  damping, double  bandwidth);
    
    //## operation init() 
    void init();


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getL1() const;
    
    //## auto_generated 
    void setL1(double  p_L1);
    
    //## auto_generated 
    double getL2() const;
    
    //## auto_generated 
    void setL2(double  p_L2);
    
    //## auto_generated 
    double getPeriod() const;
    
    //## auto_generated 
    void setPeriod(double  p_period);
    
    //## auto_generated 
    double getTau() const;
    
    //## auto_generated 
    void setTau(double  p_tau);


////    Attributes    ////
public :
    
    // Observer gain
    double L1;		//## attribute L1 
    
    // observer gain
    double L2;		//## attribute L2 
    
    // Sampling Interval 40 mSec
    double period;		//## attribute period 
    
    // time delay (due to image capturing and processing)
    double tau;		//## attribute tau 
    

};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedEstimatorLOSCoeff : virtual public AOMInstance {

    
    DECLARE_META(EstimatorLOSCoeff, OMAnimatedEstimatorLOSCoeff)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\EstimatorLOSCoeff.h
*********************************************************************/

