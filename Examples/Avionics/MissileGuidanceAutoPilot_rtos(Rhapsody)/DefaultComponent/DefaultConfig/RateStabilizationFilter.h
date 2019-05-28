/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: RateStabilizationFilter
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\RateStabilizationFilter.h
*********************************************************************/


#ifndef RateStabilizationFilter_H 

#define RateStabilizationFilter_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "TrackingSubsystemPkg.h"
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "RateStabilizationFilterCoeff.h"

//## package TrackingSubsystemPkg 

//----------------------------------------------------------------------------
// RateStabilizationFilter.h                                                                  
//----------------------------------------------------------------------------

//## class RateStabilizationFilter 
class RateStabilizationFilter : public OMReactive {


////    Constructors and destructors    ////
public :
    
    //## operation RateStabilizationFilter() 
    RateStabilizationFilter(OMThread*  p_thread = OMDefaultThread);
    
    //## auto_generated 
    ~RateStabilizationFilter();


////    Operations    ////
public :
    
    //## operation clean() 
    void clean();
    
    //## operation init() 
    void init();
    
    //## operation setPeriod(long) 
    void setPeriod(long  val);
    
    //## operation updateStabilizedRate(double,double) 
    void updateStabilizedRate(double  gimbalAngleRateData, double  gyroData);


////    Additional operations    ////
public :
    
    //## auto_generated 
    long getPeriod() const;
    
    //## auto_generated 
    double getStabilizedRate() const;
    
    //## auto_generated 
    void setStabilizedRate(double  p_stabilizedRate);
    
    //## auto_generated 
    double *  getU() const;
    
    //## auto_generated 
    void setU(double * p_u);
    
    //## auto_generated 
    double *  getX() const;
    
    //## auto_generated 
    void setX(double * p_x);
    
    //## auto_generated 
    RateStabilizationFilterCoeff* getCoeff() const;


////    Framework operations    ////
public :
    
    //## auto_generated 
    virtual OMBoolean startBehavior();


////    Attributes    ////
public :
    
    // qs
    double stabilizedRate;		//## attribute stabilizedRate 
    
    double * u;		//## attribute u 
    
    double * x;		//## attribute x 
    
protected :
    
    long period;		//## attribute period 
    

////    Relations and components    ////
public :
    
    RateStabilizationFilterCoeff Coeff;		//## classInstance Coeff 
    


};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\RateStabilizationFilter.h
*********************************************************************/

