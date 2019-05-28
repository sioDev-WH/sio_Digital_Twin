/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: EstimatorLOS
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\EstimatorLOS.h
*********************************************************************/


#ifndef EstimatorLOS_H 

#define EstimatorLOS_H 


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
#include "EstimatorLOSCoeff.h"
#include "OnModelBase.h"

//## package SeekerSubsystemPkg 

//----------------------------------------------------------------------------
// EstimatorLOS.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedEstimatorLOS;
#endif // _OMINSTRUMENT


//## class EstimatorLOS 
class EstimatorLOS : public OMReactive, public COnModelBase {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedEstimatorLOS;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation EstimatorLOS(double,double) 
    EstimatorLOS(double  damping, double  bandwidth, OMThread*  p_thread = OMDefaultThread);
    
    //## operation EstimatorLOS() 
    EstimatorLOS(OMThread*  p_thread = OMDefaultThread);
    
    //## auto_generated 
    ~EstimatorLOS();


////    Operations    ////
public :
    
    //## operation clean() 
    void clean();
    
    //## operation get_LOSRate(const double,double *) 
    void get_LOSRate(const double  t, double *val);
    
    //## operation handle_tick(const double) 
    void handle_tick(const double  t);
    
    //## operation init() 
    void init();
    
    //## operation set_LOS(const double,double *) 
    void set_LOS(const double  t, double *val);
    
    //## operation set_dishError(const double,double *) 
    void set_dishError(const double  t, double *val);
    
    //## operation set_guidanceMode(const double,long *) 
    void set_guidanceMode(const double  t, long *val);
    
    //## operation set_stabilizedRate(const double,double *) 
    void set_stabilizedRate(const double  t, double *val);
    
    //## operation update() 
    void update();


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getLOS() const;
    
    //## auto_generated 
    void setLOS(double  p_LOS);
    
    //## auto_generated 
    double getLOSRate() const;
    
    //## auto_generated 
    void setLOSRate(double  p_LOSRate);
    
    //## auto_generated 
    double getLOS_old() const;
    
    //## auto_generated 
    void setLOS_old(double  p_LOS_old);
    
    //## auto_generated 
    double getDishError() const;
    
    //## auto_generated 
    void setDishError(double  p_dishError);
    
    //## auto_generated 
    double getEpsilon() const;
    
    //## auto_generated 
    void setEpsilon(double  p_epsilon);
    
    //## auto_generated 
    int getGuidanceMode() const;
    
    //## auto_generated 
    void setGuidanceMode(int  p_guidanceMode);
    
    //## auto_generated 
    double getStabilizedRate() const;
    
    //## auto_generated 
    void setStabilizedRate(double  p_stabilizedRate);
    
    //## auto_generated 
    EstimatorLOSCoeff* getCoeff() const;


////    Framework operations    ////
public :
    
    //## auto_generated 
    virtual OMBoolean startBehavior();


////    Attributes    ////
public :
    
    // x[2] = LOS rate
    // y = PointingError: measured epsilon (from image processing)
    // u = stabilized pitchRate:	  input pitch rate
    double LOSRate;		//## attribute LOSRate 
    
    // x[1] = pitch pointing error (= target - gimbal angle)
    double epsilon;		//## attribute epsilon 
    
protected :
    
    // Temporary Patch
    double LOS;		//## attribute LOS 
    
    // Temp Patch for test only
    double LOS_old;		//## attribute LOS_old 
    
    double dishError;		//## attribute dishError 
    
    int guidanceMode;		//## attribute guidanceMode 
    
    double stabilizedRate;		//## attribute stabilizedRate 
    

////    Relations and components    ////
public :
    
    EstimatorLOSCoeff Coeff;		//## classInstance Coeff 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedEstimatorLOS : virtual public AOMInstance {

    
    DECLARE_REACTIVE_META(EstimatorLOS, OMAnimatedEstimatorLOS)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\EstimatorLOS.h
*********************************************************************/

