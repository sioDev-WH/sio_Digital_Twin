/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: WindGust
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\WindGust.h
*********************************************************************/


#ifndef WindGust_H 

#define WindGust_H 


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
// WindGust.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedWindGust;
#endif // _OMINSTRUMENT


//## class WindGust 
class WindGust : public OMReactive {
public :
    //#[ ignore 
    #define PI 3.1415926535897932384626433832795
    //#]
    
    


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedWindGust;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation WindGust() 
    WindGust(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~WindGust() 
    ~WindGust();


////    Operations    ////
public :
    
    //## operation broadcast() 
    void broadcast();
    
    //## operation clean() 
    void clean();
    
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
    double* getAircraftVelocity() const;
    
    //## auto_generated 
    void setAircraftVelocity(double*  p_aircraftVelocity);
    
    //## auto_generated 
    double* getAmplitude() const;
    
    //## auto_generated 
    void setAmplitude(double*  p_amplitude);
    
    //## auto_generated 
    double* getLength() const;
    
    //## auto_generated 
    void setLength(double*  p_length);
    
    //## auto_generated 
    double getPeriod() const;
    
    //## auto_generated 
    void setPeriod(double  p_period);
    
    //## auto_generated 
    int getSize() const;
    
    //## auto_generated 
    void setSize(int  p_size);
    
    //## auto_generated 
    double* getVelocity() const;
    
    //## auto_generated 
    void setVelocity(double*  p_velocity);
    
    //## auto_generated 
    double* getX() const;
    
    //## auto_generated 
    void setX(double*  p_x);


////    Framework operations    ////
public :
    
    //evGustWindTick();
    
    //evEnter();
    
    //evExit();
    
    //rootState:
    
    //## statechart_method 
    inline int rootState_IN() const;
    
    //## statechart_method 
    virtual void rootState_entDef();
    
    //## statechart_method 
    virtual int rootState_dispatchEvent(short  id);
    
    //Wait:
    
    //## statechart_method 
    inline int Wait_IN() const;
    
    //Run:
    
    //## statechart_method 
    inline int Run_IN() const;
    
    //## auto_generated 
    virtual OMBoolean startBehavior();

protected :
    
    //## auto_generated 
    void initStatechart();


////    Attributes    ////
protected :
    
    double* aircraftVelocity;		//## attribute aircraftVelocity 
    
    double* amplitude;		//## attribute amplitude 
    
    double* length;		//## attribute length 
    
    double period;		//## attribute period 
    
    int size;		//## attribute size 
    
    double* velocity;		//## attribute velocity 
    
    double* x;		//## attribute x 
    


////    Framework    ////
protected :
    
    //## ignore 
    //states enumeration: 
    enum WindGust_Enum{ OMNonState=0, Wait=1, Run=2 };
    
    int rootState_subState;		//## ignore 
    
    
    int rootState_active;		//## ignore 
    

};
//---------------------------------------------------------------------------- 
// inline operations for WindGust
//---------------------------------------------------------------------------- 

inline int WindGust::rootState_IN() const {
    return 1;
}

inline int WindGust::Wait_IN() const {
    return rootState_subState == Wait;
}

inline int WindGust::Run_IN() const {
    return rootState_subState == Run;
}



#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedWindGust : virtual public AOMInstance {

    
    DECLARE_REACTIVE_META(WindGust, OMAnimatedWindGust)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    //## statechart_method 
    void rootState_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Wait_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Run_serializeStates(AOMSState*  aomsState) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\WindGust.h
*********************************************************************/

