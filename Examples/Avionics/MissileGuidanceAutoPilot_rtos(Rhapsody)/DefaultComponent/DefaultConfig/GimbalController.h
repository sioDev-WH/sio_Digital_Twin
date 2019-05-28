/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: GimbalController
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\GimbalController.h
*********************************************************************/


#ifndef GimbalController_H 

#define GimbalController_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "TrackingSubsystemPkg.h"
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "GimbalControllerCoeff.h"

//## package TrackingSubsystemPkg 

//----------------------------------------------------------------------------
// GimbalController.h                                                                  
//----------------------------------------------------------------------------

//## class GimbalController 
class GimbalController : public OMReactive {


////    Constructors and destructors    ////
public :
    
    //## operation GimbalController() 
    GimbalController(OMThread*  p_thread = OMDefaultThread);
    
    //## auto_generated 
    ~GimbalController();


////    Operations    ////
public :
    
    //## operation adjustGimbalAngle(double,double) 
    void adjustGimbalAngle(double  dishError, double  stabilizedRate);
    
    //## operation clean() 
    void clean();
    
    //## operation computeDishError(double,double,int) 
    double computeDishError(double  lookAngle, double  dishCommand, int  guidanceMode);
    
    //## operation init() 
    void init();
    
    //## operation setPeriod(long) 
    void setPeriod(long  val);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getDishError() const;
    
    //## auto_generated 
    void setDishError(double  p_dishError);
    
    //## auto_generated 
    double getGimbalAngle() const;
    
    //## auto_generated 
    void setGimbalAngle(double  p_gimbalAngle);
    
    //## auto_generated 
    double getGimbalAngleRate() const;
    
    //## auto_generated 
    void setGimbalAngleRate(double  p_gimbalAngleRate);
    
    //## auto_generated 
    GimbalControllerCoeff* getCoeff() const;


////    Framework operations    ////
public :
    
    //## auto_generated 
    virtual OMBoolean startBehavior();


////    Attributes    ////
public :
    
    double dishError;		//## attribute dishError 
    
    double gimbalAngle;		//## attribute gimbalAngle 
    
    double gimbalAngleRate;		//## attribute gimbalAngleRate 
    

////    Relations and components    ////
public :
    
    GimbalControllerCoeff Coeff;		//## classInstance Coeff 
    


};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\GimbalController.h
*********************************************************************/

