/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Guidance
//!	Generated Date	: Fri, 20, Dec 2002  
	File Path	: DefaultComponent\DefaultConfig\Guidance.h
*********************************************************************/


#ifndef Guidance_H 

#define Guidance_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "Default.h"
#include <oxf/omthread.h>
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>

//## package Default 

//----------------------------------------------------------------------------
// Guidance.h                                                                  
//----------------------------------------------------------------------------
class myFactory;

#ifdef _OMINSTRUMENT
class OMAnimatedGuidance;
#endif // _OMINSTRUMENT


//#[ ignore 
#define Guidance_Timeout_blindRange_id 4
//#]

//#[ ignore 
#define Guidance_Timeout_radarGuided_id 3
//#]

//#[ ignore 
#define Guidance_Timeout_targetLock_id 2
//#]

//#[ ignore 
#define Guidance_Timeout_targetSearch_id 1
//#]

//## class Guidance 
class Guidance : public OMReactive {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedGuidance;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation Guidance() 
    Guidance(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~Guidance() 
    ~Guidance();


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getAcquireTime() const;
    
    //## auto_generated 
    void setAcquireTime(double  p_AcquireTime);
    
    //## auto_generated 
    double getAz_Demand() const;
    
    //## auto_generated 
    void setAz_Demand(double  p_Az_Demand);
    
    //## auto_generated 
    double getAz_Fixed() const;
    
    //## auto_generated 
    void setAz_Fixed(double  p_Az_Fixed);
    
    //## auto_generated 
    double getAz_max() const;
    
    //## auto_generated 
    void setAz_max(double  p_Az_max);
    
    //## auto_generated 
    double getAz_min() const;
    
    //## auto_generated 
    void setAz_min(double  p_Az_min);
    
    //## auto_generated 
    double getDishAngle() const;
    
    //## auto_generated 
    void setDishAngle(double  p_DishAngle);
    
    //## auto_generated 
    double getLOSRate() const;
    
    //## auto_generated 
    void setLOSRate(double  p_LOSRate);
    
    //## auto_generated 
    double getMissionTime() const;
    
    //## auto_generated 
    void setMissionTime(double  p_MissionTime);
    
    //## auto_generated 
    double getPropNavGain() const;
    
    //## auto_generated 
    void setPropNavGain(double  p_PropNavGain);
    
    //## auto_generated 
    double getRange() const;
    
    //## auto_generated 
    void setRange(double  p_Range);
    
    //## auto_generated 
    int getScanningSteps() const;
    
    //## auto_generated 
    void setScanningSteps(int  p_ScanningSteps);
    
    //## auto_generated 
    int getBAcquired() const;
    
    //## auto_generated 
    void setBAcquired(int  p_bAcquired);
    
    //## auto_generated 
    int getBMissed() const;
    
    //## auto_generated 
    void setBMissed(int  p_bMissed);
    
    //## auto_generated 
    double getClosingVelocity() const;
    
    //## auto_generated 
    void setClosingVelocity(double  p_closingVelocity);
    
    //## auto_generated 
    double getDishAngleCommand() const;
    
    //## auto_generated 
    void setDishAngleCommand(double  p_dishAngleCommand);
    
    //## auto_generated 
    int getNTicks() const;
    
    //## auto_generated 
    void setNTicks(int  p_nTicks);
    
    //## auto_generated 
    double getSamplingInterval() const;
    
    //## auto_generated 
    void setSamplingInterval(double  p_samplingInterval);
    
    //## auto_generated 
    myFactory* getItsMyFactory() const;
    
    //## auto_generated 
    void setItsMyFactory(myFactory*  p_myFactory);


////    Framework operations    ////
public :
    
    //## auto_generated 
    void __setItsMyFactory(myFactory*  p_myFactory);
    
    //## auto_generated 
    void _setItsMyFactory(myFactory*  p_myFactory);
    
    //## auto_generated 
    void _clearItsMyFactory();
    
    //evTargetAcquired();
    
    //evTargetLost();
    
    //rootState:
    
    //## statechart_method 
    inline int rootState_IN() const;
    
    //## statechart_method 
    virtual void rootState_entDef();
    
    //## statechart_method 
    virtual int rootState_dispatchEvent(short  id);
    
    //Running:
    
    //## statechart_method 
    inline int Running_IN() const;
    
    //## statechart_method 
    int Running_dispatchEvent(short  id);
    
    //state_13:
    
    //## statechart_method 
    inline int state_13_IN() const;
    
    //## statechart_method 
    int state_13_dispatchEvent(short  id);
    
    //FuzeMode:
    
    //## statechart_method 
    inline int FuzeMode_IN() const;
    
    //FuzeMode_init:
    
    //## statechart_method 
    inline int FuzeMode_init_IN() const;
    
    //inert:
    
    //## statechart_method 
    inline int inert_IN() const;
    
    //armed:
    
    //## statechart_method 
    inline int armed_IN() const;
    
    //state_12:
    
    //## statechart_method 
    inline int state_12_IN() const;
    
    //## statechart_method 
    int state_12_dispatchEvent(short  id);
    
    //GuidanceMode:
    
    //## statechart_method 
    inline int GuidanceMode_IN() const;
    
    //targetSearch:
    
    //## statechart_method 
    inline int targetSearch_IN() const;
    
    //targetLock:
    
    //## statechart_method 
    inline int targetLock_IN() const;
    
    //radarGuided:
    
    //## statechart_method 
    inline int radarGuided_IN() const;
    
    //init:
    
    //## statechart_method 
    inline int init_IN() const;
    
    //Done:
    
    //## statechart_method 
    inline int Done_IN() const;
    
    //blindRange:
    
    //## statechart_method 
    inline int blindRange_IN() const;
    
    //abort:
    
    //## statechart_method 
    inline int abort_IN() const;
    
    //## auto_generated 
    virtual OMBoolean startBehavior();
    
    //## statechart_method 
    int targetSearch_takeEvent(short  id);
    
    //## statechart_method 
    void state_13_entDef();
    
    //## statechart_method 
    void FuzeMode_entDef();
    
    //## statechart_method 
    void Running_entDef();
    
    //## statechart_method 
    int radarGuided_takeEvent(short  id);
    
    //## statechart_method 
    void GuidanceMode_entDef();
    
    //## statechart_method 
    void Running_exit();
    
    //## statechart_method 
    void GuidanceMode_exit();
    
    //## statechart_method 
    void state_12_entDef();

protected :
    
    //## auto_generated 
    void initStatechart();
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
protected :
    
    double AcquireTime;		//## attribute AcquireTime 
    
    double Az_Demand;		//## attribute Az_Demand 
    
    double Az_Fixed;		//## attribute Az_Fixed 
    
    double Az_max;		//## attribute Az_max 
    
    double Az_min;		//## attribute Az_min 
    
    double DishAngle;		//## attribute DishAngle 
    
    double LOSRate;		//## attribute LOSRate 
    
    double MissionTime;		//## attribute MissionTime 
    
    double PropNavGain;		//## attribute PropNavGain 
    
    double Range;		//## attribute Range 
    
    int ScanningSteps;		//## attribute ScanningSteps 
    
    int bAcquired;		//## attribute bAcquired 
    
    int bMissed;		//## attribute bMissed 
    
    double closingVelocity;		//## attribute closingVelocity 
    
    double dishAngleCommand;		//## attribute dishAngleCommand 
    
    int nTicks;		//## attribute nTicks 
    
    double samplingInterval;		//## attribute samplingInterval 
    

////    Relations and components    ////
protected :
    
    myFactory* itsMyFactory;		//## link itsMyFactory 
    


////    Framework    ////
protected :
    
    //## ignore 
    //states enumeration: 
    enum Guidance_Enum{ OMNonState=0, Running=1, state_13=2, FuzeMode=3, 
        FuzeMode_init=4, inert=5, armed=6, state_12=7, 
        GuidanceMode=8, targetSearch=9, targetLock=10, radarGuided=11, 
        init=12, Done=13, blindRange=14, abort=15 };
    
    int rootState_subState;		//## ignore 
    
    
    int rootState_active;		//## ignore 
    
    
    int state_13_subState;		//## ignore 
    
    
    int state_13_active;		//## ignore 
    
    
    int FuzeMode_subState;		//## ignore 
    
    
    int state_12_subState;		//## ignore 
    
    
    int state_12_active;		//## ignore 
    
    
    int GuidanceMode_subState;		//## ignore 
    

};
//---------------------------------------------------------------------------- 
// inline operations for Guidance
//---------------------------------------------------------------------------- 

inline int Guidance::rootState_IN() const {
    return 1;
}

inline int Guidance::Running_IN() const {
    return rootState_subState == Running;
}

inline int Guidance::state_13_IN() const {
    return Running_IN();
}

inline int Guidance::FuzeMode_IN() const {
    return state_13_subState == FuzeMode;
}

inline int Guidance::FuzeMode_init_IN() const {
    return FuzeMode_subState == FuzeMode_init;
}

inline int Guidance::inert_IN() const {
    return FuzeMode_subState == inert;
}

inline int Guidance::armed_IN() const {
    return FuzeMode_subState == armed;
}

inline int Guidance::state_12_IN() const {
    return Running_IN();
}

inline int Guidance::GuidanceMode_IN() const {
    return state_12_subState == GuidanceMode;
}

inline int Guidance::targetSearch_IN() const {
    return GuidanceMode_subState == targetSearch;
}

inline int Guidance::targetLock_IN() const {
    return GuidanceMode_subState == targetLock;
}

inline int Guidance::radarGuided_IN() const {
    return GuidanceMode_subState == radarGuided;
}

inline int Guidance::init_IN() const {
    return GuidanceMode_subState == init;
}

inline int Guidance::Done_IN() const {
    return GuidanceMode_subState == Done;
}

inline int Guidance::blindRange_IN() const {
    return GuidanceMode_subState == blindRange;
}

inline int Guidance::abort_IN() const {
    return GuidanceMode_subState == abort;
}



#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedGuidance : virtual public AOMInstance {

    
    DECLARE_REACTIVE_META(Guidance, OMAnimatedGuidance)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;
    
    //## statechart_method 
    void rootState_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Running_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void state_13_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void FuzeMode_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void FuzeMode_init_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void inert_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void armed_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void state_12_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void GuidanceMode_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void targetSearch_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void targetLock_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void radarGuided_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void init_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Done_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void blindRange_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void abort_serializeStates(AOMSState*  aomsState) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Guidance.h
*********************************************************************/

