/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: AutoPilot
//!	Generated Date	: Tue, 10, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\AutoPilot.h
*********************************************************************/


#ifndef AutoPilot_H 

#define AutoPilot_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "GuidancePkg.h"
#include <oxf/omthread.h>
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "AutoPilotCoeff.h"

//## package GuidancePkg 

//----------------------------------------------------------------------------
// AutoPilot.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedAutoPilot;
#endif // _OMINSTRUMENT


//## class AutoPilot 
class AutoPilot : public OMReactive {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedAutoPilot;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation AutoPilot() 
    AutoPilot(OMThread*  p_thread = OMDefaultThread);
    
    //## auto_generated 
    ~AutoPilot();


////    Operations    ////
public :
    
    //## operation getFinControlSignal(double,double,double) 
    double getFinControlSignal(double  command, double  gyroData, double  accelData);
    
    //## operation init() 
    void init();


////    Additional operations    ////
public :
    
    //## auto_generated 
    void setOldGyroData(double  p_oldGyroData);
    
    //## auto_generated 
    void setOld_Fin(double  p_old_Fin);
    
    //## auto_generated 
    void setOld_u(int  i1, double  p_old_u);
    
    //## auto_generated 
    void setOld_x(int  i1, double  p_old_x);
    
    //## auto_generated 
    AutoPilotCoeff* getCoeff() const;


////    Framework operations    ////
public :
    
    //## auto_generated 
    virtual OMBoolean startBehavior();


////    Attributes    ////
public :
    
    double oldGyroData;		//## attribute oldGyroData 
    
    double old_Fin;		//## attribute old_Fin 
    
    double old_u[M];		//## attribute old_u 
    
    double old_x[N];		//## attribute old_x 
    

////    Relations and components    ////
public :
    
    AutoPilotCoeff Coeff;		//## classInstance Coeff 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedAutoPilot : virtual public AOMInstance {

    
    DECLARE_REACTIVE_META(AutoPilot, OMAnimatedAutoPilot)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\AutoPilot.h
*********************************************************************/

