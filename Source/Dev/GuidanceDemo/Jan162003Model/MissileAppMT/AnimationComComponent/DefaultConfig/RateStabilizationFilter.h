/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: RateStabilizationFilter
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\RateStabilizationFilter.h
*********************************************************************/


#ifndef RateStabilizationFilter_H 

#define RateStabilizationFilter_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "SeekerSubsystemPkg.h"
#include <oxf/omthread.h>
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "RateStabilizationFilterCoeff.h"

//## package SeekerSubsystemPkg 

//----------------------------------------------------------------------------
// RateStabilizationFilter.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedRateStabilizationFilter;
#endif // _OMINSTRUMENT


//## class RateStabilizationFilter 
class RateStabilizationFilter : public OMReactive {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedRateStabilizationFilter;
#endif // _OMINSTRUMENT


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
    
    //## operation updateStabilizedRate(double,double) 
    void updateStabilizedRate(double  gimbalAngleRateData, double  gyroData);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double *  getOld_u() const;
    
    //## auto_generated 
    void setOld_u(double * p_old_u);
    
    //## auto_generated 
    double *  getOld_x() const;
    
    //## auto_generated 
    void setOld_x(double * p_old_x);
    
    //## auto_generated 
    double getPeriod() const;
    
    //## auto_generated 
    void setPeriod(double  p_period);
    
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
    
    double * old_u;		//## attribute old_u 
    
    double * old_x;		//## attribute old_x 
    
    // qs
    double stabilizedRate;		//## attribute stabilizedRate 
    
    double * u;		//## attribute u 
    
    double * x;		//## attribute x 
    
protected :
    
    double period;		//## attribute period 
    

////    Relations and components    ////
public :
    
    RateStabilizationFilterCoeff Coeff;		//## classInstance Coeff 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedRateStabilizationFilter : virtual public AOMInstance {

    
    DECLARE_REACTIVE_META(RateStabilizationFilter, OMAnimatedRateStabilizationFilter)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\RateStabilizationFilter.h
*********************************************************************/

