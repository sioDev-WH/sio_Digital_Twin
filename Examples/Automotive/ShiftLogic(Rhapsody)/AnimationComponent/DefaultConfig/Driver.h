/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Driver
//!	Generated Date	: Sun, 16, Feb 2003  
	File Path	: AnimationComponent\DefaultConfig\Driver.h
*********************************************************************/


#ifndef Driver_H 

#define Driver_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "UI.h"
#include <oxf/omthread.h>
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "OnModelBase.h"

//## package UI 

//----------------------------------------------------------------------------
// Driver.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedDriver;
#endif // _OMINSTRUMENT


//## class Driver 
class Driver : public OMReactive, public COnModelBase {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedDriver;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation Driver() 
    Driver(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~Driver() 
    ~Driver();


////    Operations    ////
public :
    
    //## operation clean() 
    void clean();
    
    //## operation fast() 
    void fast();
    
    //## operation handle_tick() 
    void handle_tick();
    
    //## operation init() 
    void init();
    
    //## operation shiftForward() 
    void shiftForward();
    
    //## operation slow() 
    void slow();
    
    //## operation updateActionTime() 
    void updateActionTime();


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getAcceleratorVal() const;
    
    //## auto_generated 
    void setAcceleratorVal(double  p_acceleratorVal);
    
    //## auto_generated 
    double getBrakeVal() const;
    
    //## auto_generated 
    void setBrakeVal(double  p_brakeVal);
    
    //## auto_generated 
    long getShiftVal() const;
    
    //## auto_generated 
    void setShiftVal(long  p_shiftVal);


////    Framework operations    ////
public :
    
    //evDriverTick();
    
    //rootState:
    
    //## statechart_method 
    inline int rootState_IN() const;
    
    //## statechart_method 
    virtual void rootState_entDef();
    
    //## statechart_method 
    virtual int rootState_dispatchEvent(short  id);
    
    //ShiftForward:
    
    //## statechart_method 
    inline int ShiftForward_IN() const;
    
    //Init:
    
    //## statechart_method 
    inline int Init_IN() const;
    
    //Brake:
    
    //## statechart_method 
    inline int Brake_IN() const;
    
    //Accelerate:
    
    //## statechart_method 
    inline int Accelerate_IN() const;
    
    //## auto_generated 
    virtual OMBoolean startBehavior();
    
    //## statechart_method 
    void rootState_exit();

protected :
    
    //## auto_generated 
    void initStatechart();


////    Attributes    ////
public :
    
    Port_Double * accelerator;		//## attribute accelerator 
    
    double actionTime;		//## attribute actionTime 
    
    Port_Double * brakes;		//## attribute brakes 
    
    double currentTime;		//## attribute currentTime 
    
    Port_Int * shiftLever;		//## attribute shiftLever 
    
protected :
    
    double acceleratorVal;		//## attribute acceleratorVal 
    
    double brakeVal;		//## attribute brakeVal 
    
    long shiftVal;		//## attribute shiftVal 
    


////    Framework    ////
protected :
    
    //## ignore 
    //states enumeration: 
    enum Driver_Enum{ OMNonState=0, ShiftForward=1, Init=2, Brake=3, Accelerate=4 };
    
    int rootState_subState;		//## ignore 
    
    
    int rootState_active;		//## ignore 
    

};
//---------------------------------------------------------------------------- 
// inline operations for Driver
//---------------------------------------------------------------------------- 

inline int Driver::rootState_IN() const {
    return 1;
}

inline int Driver::ShiftForward_IN() const {
    return rootState_subState == ShiftForward;
}

inline int Driver::Init_IN() const {
    return rootState_subState == Init;
}

inline int Driver::Brake_IN() const {
    return rootState_subState == Brake;
}

inline int Driver::Accelerate_IN() const {
    return rootState_subState == Accelerate;
}



#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedDriver : virtual public AOMInstance {

    
    DECLARE_REACTIVE_META(Driver, OMAnimatedDriver)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    //## statechart_method 
    void rootState_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void ShiftForward_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Init_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Brake_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Accelerate_serializeStates(AOMSState*  aomsState) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Driver.h
*********************************************************************/

