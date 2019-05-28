/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: ScheduledController_1D
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\ScheduledController_1D.h
*********************************************************************/


#ifndef ScheduledController_1D_H 

#define ScheduledController_1D_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "AvionicsPkg.h"
#include <oxf/omthread.h>
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>

//## package LibraryPkg::AvionicsPkg 

//----------------------------------------------------------------------------
// ScheduledController_1D.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedScheduledController_1D;
#endif // _OMINSTRUMENT
class ScheduledController_1D_Coeff;


//## class ScheduledController_1D 
class ScheduledController_1D : public OMReactive {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedScheduledController_1D;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation ScheduledController_1D() 
    ScheduledController_1D(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~ScheduledController_1D() 
    ~ScheduledController_1D();


////    Operations    ////
public :
    
    //## operation broadcast() 
    void broadcast();
    
    //## operation handle_tick() 
    void handle_tick();
    
    //## operation init() 
    void init();
    
    //## operation receive() 
    void receive();
    
    //## operation update() 
    void update();


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getPeriod() const;
    
    //## auto_generated 
    void setPeriod(double  p_period);
    
    //## auto_generated 
    double* getU() const;
    
    //## auto_generated 
    void setU(double*  p_u);
    
    //## auto_generated 
    double* getU_old() const;
    
    //## auto_generated 
    void setU_old(double*  p_u_old);
    
    //## auto_generated 
    double getV() const;
    
    //## auto_generated 
    void setV(double  p_v);
    
    //## auto_generated 
    double* getX() const;
    
    //## auto_generated 
    void setX(double*  p_x);
    
    //## auto_generated 
    double* getX_old() const;
    
    //## auto_generated 
    void setX_old(double*  p_x_old);
    
    //## auto_generated 
    double* getY() const;
    
    //## auto_generated 
    void setY(double*  p_y);
    
    //## auto_generated 
    ScheduledController_1D_Coeff* getCoeff() const;
    
    //## auto_generated 
    ScheduledController_1D_Coeff* newCoeff();
    
    //## auto_generated 
    void deleteCoeff();


////    Framework operations    ////
public :
    
    //## auto_generated 
    virtual OMBoolean startBehavior();

protected :
    
    //## auto_generated 
    void initRelations();
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
public :
    
    double* u_old;		//## attribute u_old 
    
    double* x_old;		//## attribute x_old 
    
protected :
    
    double period;		//## attribute period 
    
    double* u;		//## attribute u 
    
    double v;		//## attribute v 
    
    double* x;		//## attribute x 
    
    double* y;		//## attribute y 
    

////    Relations and components    ////
protected :
    
    ScheduledController_1D_Coeff* Coeff;		//## classInstance Coeff 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedScheduledController_1D : virtual public AOMInstance {

    
    DECLARE_REACTIVE_META(ScheduledController_1D, OMAnimatedScheduledController_1D)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\ScheduledController_1D.h
*********************************************************************/

