/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: SimpleGearbox
//!	Generated Date	: Wed, 11, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\SimpleGearbox.h
*********************************************************************/


#ifndef SimpleGearbox_H 

#define SimpleGearbox_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "DiscreteTransmissionModels.h"
#include <oxf/omthread.h>
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "OnModelBase.h"

//## package DiscreteTransmissionModels 

//----------------------------------------------------------------------------
// SimpleGearbox.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedSimpleGearbox;
#endif // _OMINSTRUMENT


//## class SimpleGearbox 
class SimpleGearbox : public OMReactive, public COnModelBase {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedSimpleGearbox;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## auto_generated 
    SimpleGearbox(OMThread*  p_thread = OMDefaultThread);
    
    //## auto_generated 
    ~SimpleGearbox();


////    Operations    ////
public :
    
    //## operation DC_Shift(const double ,long * ) 
    void DC_Shift(const double t, long * val);
    
    //## operation FC_Shift(const double ,long * ) 
    void FC_Shift(const double t, long * val);
    
    //## operation IOC_Shift(const double ,long * ) 
    void IOC_Shift(const double t, long * val);
    
    //## operation IsAny() 
    int IsAny();
    
    //## operation IsFirst() 
    int IsFirst();
    
    //## operation IsFourth() 
    int IsFourth();
    
    //## operation IsInvalid() 
    int IsInvalid();
    
    //## operation IsNone() 
    int IsNone();
    
    //## operation IsReverse() 
    int IsReverse();
    
    //## operation IsSecond() 
    int IsSecond();
    
    //## operation IsThird() 
    int IsThird();
    
    //## operation LRB_Shift(const double ,long * ) 
    void LRB_Shift(const double t, long * val);
    
    //## operation OB_Shift(const double ,long * ) 
    void OB_Shift(const double t, long * val);
    
    //## operation POC_Shift(const double ,long * ) 
    void POC_Shift(const double t, long * val);
    
    //## operation RC_Shift(const double ,long * ) 
    void RC_Shift(const double t, long * val);
    
    //## operation TCC_Shift(const double ,long * ) 
    void TCC_Shift(const double t, long * val);
    
    //## operation handle_tick() 
    void handle_tick();


////    Additional operations    ////
public :
    
    //## auto_generated 
    long getDC() const;
    
    //## auto_generated 
    void setDC(long  p_DC);
    
    //## auto_generated 
    long getFC() const;
    
    //## auto_generated 
    void setFC(long  p_FC);
    
    //## auto_generated 
    long getIOC() const;
    
    //## auto_generated 
    void setIOC(long  p_IOC);
    
    //## auto_generated 
    long getLRB() const;
    
    //## auto_generated 
    void setLRB(long  p_LRB);
    
    //## auto_generated 
    long getOB() const;
    
    //## auto_generated 
    void setOB(long  p_OB);
    
    //## auto_generated 
    long getPOC() const;
    
    //## auto_generated 
    void setPOC(long  p_POC);
    
    //## auto_generated 
    long getRC() const;
    
    //## auto_generated 
    void setRC(long  p_RC);
    
    //## auto_generated 
    long getT() const;
    
    //## auto_generated 
    void setT(long  p_T);
    
    //## auto_generated 
    long getTCC() const;
    
    //## auto_generated 
    void setTCC(long  p_TCC);
    
    //## auto_generated 
    long getGear() const;
    
    //## auto_generated 
    void setGear(long  p_gear);


////    Framework operations    ////
public :
    
    //evTick();
    
    //rootState:
    
    //## statechart_method 
    inline int rootState_IN() const;
    
    //## statechart_method 
    virtual void rootState_entDef();
    
    //## statechart_method 
    virtual int rootState_dispatchEvent(short  id);
    
    //Transition:
    
    //## statechart_method 
    inline int Transition_IN() const;
    
    //Third:
    
    //## statechart_method 
    inline int Third_IN() const;
    
    //Second:
    
    //## statechart_method 
    inline int Second_IN() const;
    
    //Reverse:
    
    //## statechart_method 
    inline int Reverse_IN() const;
    
    //Neutral:
    
    //## statechart_method 
    inline int Neutral_IN() const;
    
    //Invalid:
    
    //## statechart_method 
    inline int Invalid_IN() const;
    
    //Fourth:
    
    //## statechart_method 
    inline int Fourth_IN() const;
    
    //First:
    
    //## statechart_method 
    inline int First_IN() const;
    
    //## auto_generated 
    virtual OMBoolean startBehavior();
    
    //## statechart_method 
    int Transition_takeEvent(short  id);
    
    //## statechart_method 
    int TransitionTakeNull();
    
    //## statechart_method 
    void rootState_exit();

protected :
    
    //## auto_generated 
    void initStatechart();


////    Attributes    ////
public :
    
    long DC;		//## attribute DC 
    
    long FC;		//## attribute FC 
    
    long IOC;		//## attribute IOC 
    
    long LRB;		//## attribute LRB 
    
    long OB;		//## attribute OB 
    
    long POC;		//## attribute POC 
    
    long RC;		//## attribute RC 
    
    long T;		//## attribute T 
    
    long TCC;		//## attribute TCC 
    
    long gear;		//## attribute gear 
    


////    Framework    ////
protected :
    
    //## ignore 
    //states enumeration: 
    enum SimpleGearbox_Enum{ OMNonState=0, Transition=1, Third=2, Second=3, 
        Reverse=4, Neutral=5, Invalid=6, Fourth=7, First=8 };
    
    int rootState_subState;		//## ignore 
    
    
    int rootState_active;		//## ignore 
    

};
//---------------------------------------------------------------------------- 
// inline operations for SimpleGearbox
//---------------------------------------------------------------------------- 

inline int SimpleGearbox::rootState_IN() const {
    return 1;
}

inline int SimpleGearbox::Transition_IN() const {
    return rootState_subState == Transition;
}

inline int SimpleGearbox::Third_IN() const {
    return rootState_subState == Third;
}

inline int SimpleGearbox::Second_IN() const {
    return rootState_subState == Second;
}

inline int SimpleGearbox::Reverse_IN() const {
    return rootState_subState == Reverse;
}

inline int SimpleGearbox::Neutral_IN() const {
    return rootState_subState == Neutral;
}

inline int SimpleGearbox::Invalid_IN() const {
    return rootState_subState == Invalid;
}

inline int SimpleGearbox::Fourth_IN() const {
    return rootState_subState == Fourth;
}

inline int SimpleGearbox::First_IN() const {
    return rootState_subState == First;
}



#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedSimpleGearbox : virtual public AOMInstance {

    
    DECLARE_REACTIVE_META(SimpleGearbox, OMAnimatedSimpleGearbox)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    //## statechart_method 
    void rootState_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Transition_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Third_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Second_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Reverse_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Neutral_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Invalid_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Fourth_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void First_serializeStates(AOMSState*  aomsState) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\SimpleGearbox.h
*********************************************************************/

