/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: GuidanceLogic
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\GuidanceLogic.h
*********************************************************************/


#ifndef GuidanceLogic_H 

#define GuidanceLogic_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "GuidancePkg.h"
#include <oxf/omthread.h>
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "OnModelBase.h"

//## package GuidancePkg 

//----------------------------------------------------------------------------
// GuidanceLogic.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedGuidanceLogic;
#endif // _OMINSTRUMENT


//## class GuidanceLogic 
class GuidanceLogic : public OMReactive, public COnModelBase {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedGuidanceLogic;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation GuidanceLogic() 
    GuidanceLogic(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~GuidanceLogic() 
    ~GuidanceLogic();


////    Operations    ////
public :
    
    //## operation get_Az_Demand(const double,double *) 
    void get_Az_Demand(const double  t, double *val);
    
    //## operation get_dishAngleCommand(const double,double *) 
    void get_dishAngleCommand(const double  t, double *val);
    
    //## operation get_guidanceMode(const double,long *) 
    void get_guidanceMode(const double  t, long *val);
    
    // Inputs: closingVelocity, LOSRate, Range
    //## operation handle_tick(const double) 
    void handle_tick(const double  t);
    
    //## operation set_LOSRate(const double,double *) 
    void set_LOSRate(const double  t, double *val);
    
    //## operation set_Range(const double,double *) 
    void set_Range(const double  t, double *val);
    
    //## operation set_closingVelocity(const double,double *) 
    void set_closingVelocity(const double  t, double *val);


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
    double getHitTime() const;
    
    //## auto_generated 
    void setHitTime(double  p_HitTime);
    
    //## auto_generated 
    double getLOSRate() const;
    
    //## auto_generated 
    void setLOSRate(double  p_LOSRate);
    
    //## auto_generated 
    double getMissDistance() const;
    
    //## auto_generated 
    void setMissDistance(double  p_MissDistance);
    
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
    double getClosingVelocity() const;
    
    //## auto_generated 
    void setClosingVelocity(double  p_closingVelocity);
    
    //## auto_generated 
    double getDishAngleCommand() const;
    
    //## auto_generated 
    void setDishAngleCommand(double  p_dishAngleCommand);
    
    //## auto_generated 
    int getGuidanceMode() const;
    
    //## auto_generated 
    void setGuidanceMode(int  p_guidanceMode);
    
    //## auto_generated 
    int getNTicks() const;
    
    //## auto_generated 
    void setNTicks(int  p_nTicks);
    
    //## auto_generated 
    double getPeriod() const;
    
    //## auto_generated 
    void setPeriod(double  p_period);


////    Framework operations    ////
public :
    
    //evTargetAcquired();
    
    //evTargetLost();
    
    //evGuidanceTick();
    
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
    
    //GuidanceMode:
    
    //## statechart_method 
    inline int GuidanceMode_IN() const;
    
    //## statechart_method 
    int GuidanceMode_dispatchEvent(short  id);
    
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
    
    //Detonate:
    
    //## statechart_method 
    inline int Detonate_IN() const;
    
    //blindRange:
    
    //## statechart_method 
    inline int blindRange_IN() const;
    
    //abort:
    
    //## statechart_method 
    inline int abort_IN() const;
    
    //FuzeMode:
    
    //## statechart_method 
    inline int FuzeMode_IN() const;
    
    //## statechart_method 
    int FuzeMode_dispatchEvent(short  id);
    
    //FuzeMode_init:
    
    //## statechart_method 
    inline int FuzeMode_init_IN() const;
    
    //inert:
    
    //## statechart_method 
    inline int inert_IN() const;
    
    //armed:
    
    //## statechart_method 
    inline int armed_IN() const;
    
    //## auto_generated 
    virtual OMBoolean startBehavior();
    
    //## statechart_method 
    int targetSearch_takeEvent(short  id);
    
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

protected :
    
    //## auto_generated 
    void initStatechart();


////    Attributes    ////
protected :
    
    double AcquireTime;		//## attribute AcquireTime 
    
    double Az_Demand;		//## attribute Az_Demand 
    
    double Az_Fixed;		//## attribute Az_Fixed 
    
    double Az_max;		//## attribute Az_max 
    
    double Az_min;		//## attribute Az_min 
    
    double HitTime;		//## attribute HitTime 
    
    double LOSRate;		//## attribute LOSRate 
    
    double MissDistance;		//## attribute MissDistance 
    
    double MissionTime;		//## attribute MissionTime 
    
    double PropNavGain;		//## attribute PropNavGain 
    
    double Range;		//## attribute Range 
    
    int ScanningSteps;		//## attribute ScanningSteps 
    
    double closingVelocity;		//## attribute closingVelocity 
    
    double dishAngleCommand;		//## attribute dishAngleCommand 
    
    int guidanceMode;		//## attribute guidanceMode 
    
    int nTicks;		//## attribute nTicks 
    
    double period;		//## attribute period 
    


////    Framework    ////
protected :
    
    //## ignore 
    //states enumeration: 
    enum GuidanceLogic_Enum{ OMNonState=0, Running=1, GuidanceMode=2, targetSearch=3, 
        targetLock=4, radarGuided=5, init=6, Detonate=7, 
        blindRange=8, abort=9, FuzeMode=10, FuzeMode_init=11, inert=12, armed=13 };
    
    int rootState_subState;		//## ignore 
    
    
    int rootState_active;		//## ignore 
    
    
    int GuidanceMode_subState;		//## ignore 
    
    
    int GuidanceMode_active;		//## ignore 
    
    
    int FuzeMode_subState;		//## ignore 
    
    
    int FuzeMode_active;		//## ignore 
    

};
//---------------------------------------------------------------------------- 
// inline operations for GuidanceLogic
//---------------------------------------------------------------------------- 

inline int GuidanceLogic::rootState_IN() const {
    return 1;
}

inline int GuidanceLogic::Running_IN() const {
    return rootState_subState == Running;
}

inline int GuidanceLogic::GuidanceMode_IN() const {
    return Running_IN();
}

inline int GuidanceLogic::targetSearch_IN() const {
    return GuidanceMode_subState == targetSearch;
}

inline int GuidanceLogic::targetLock_IN() const {
    return GuidanceMode_subState == targetLock;
}

inline int GuidanceLogic::radarGuided_IN() const {
    return GuidanceMode_subState == radarGuided;
}

inline int GuidanceLogic::init_IN() const {
    return GuidanceMode_subState == init;
}

inline int GuidanceLogic::Detonate_IN() const {
    return GuidanceMode_subState == Detonate;
}

inline int GuidanceLogic::blindRange_IN() const {
    return GuidanceMode_subState == blindRange;
}

inline int GuidanceLogic::abort_IN() const {
    return GuidanceMode_subState == abort;
}

inline int GuidanceLogic::FuzeMode_IN() const {
    return Running_IN();
}

inline int GuidanceLogic::FuzeMode_init_IN() const {
    return FuzeMode_subState == FuzeMode_init;
}

inline int GuidanceLogic::inert_IN() const {
    return FuzeMode_subState == inert;
}

inline int GuidanceLogic::armed_IN() const {
    return FuzeMode_subState == armed;
}



#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedGuidanceLogic : virtual public AOMInstance {

    
    DECLARE_REACTIVE_META(GuidanceLogic, OMAnimatedGuidanceLogic)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    //## statechart_method 
    void rootState_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Running_serializeStates(AOMSState*  aomsState) const;
    
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
    void Detonate_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void blindRange_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void abort_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void FuzeMode_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void FuzeMode_init_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void inert_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void armed_serializeStates(AOMSState*  aomsState) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\GuidanceLogic.h
*********************************************************************/

