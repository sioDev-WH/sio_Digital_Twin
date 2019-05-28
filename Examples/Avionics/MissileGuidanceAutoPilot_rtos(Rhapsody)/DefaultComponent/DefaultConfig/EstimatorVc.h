/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: EstimatorVc
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\EstimatorVc.h
*********************************************************************/


#ifndef EstimatorVc_H 

#define EstimatorVc_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "GuidancePkg.h"
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "OnModelBase.h"

//## package GuidancePkg 

//----------------------------------------------------------------------------
// EstimatorVc.h                                                                  
//----------------------------------------------------------------------------
class EstimatorVcCoeff;


//## class EstimatorVc 
class EstimatorVc : public OMReactive, public COnModelBase {


////    Constructors and destructors    ////
public :
    
    //## operation EstimatorVc(double) 
    EstimatorVc(double  bandwidth, OMThread*  p_thread = OMDefaultThread);
    
    //## operation EstimatorVc() 
    EstimatorVc(OMThread*  p_thread = OMDefaultThread);
    
    //## auto_generated 
    ~EstimatorVc();


////    Operations    ////
public :
    
    //## operation clean() 
    void clean();
    
    //## operation handle_tick() 
    void handle_tick();
    
    //## operation init() 
    void init();
    
    //## operation setPeriod(long) 
    void setPeriod(long  val);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getR() const;
    
    //## auto_generated 
    void setR(double  p_R);
    
    //## auto_generated 
    double getRange() const;
    
    //## auto_generated 
    void setRange(double  p_Range);
    
    //## auto_generated 
    double getVc() const;
    
    //## auto_generated 
    void setVc(double  p_Vc);
    
    //## auto_generated 
    int getBTargetAcquired() const;
    
    //## auto_generated 
    void setBTargetAcquired(int  p_bTargetAcquired);
    
    //## auto_generated 
    EstimatorVcCoeff* getCoeff() const;
    
    //## auto_generated 
    void setCoeff(EstimatorVcCoeff*  p_EstimatorVcCoeff);


////    Framework operations    ////
public :
    
    //evRadarTick();
    
    //rootState:
    
    //## statechart_method 
    inline int rootState_IN() const;
    
    //## statechart_method 
    virtual void rootState_entDef();
    
    //## statechart_method 
    virtual int rootState_dispatchEvent(short  id);
    
    //On:
    
    //## statechart_method 
    inline int On_IN() const;
    
    //Off:
    
    //## statechart_method 
    inline int Off_IN() const;
    
    //## auto_generated 
    virtual OMBoolean startBehavior();

protected :
    
    //## auto_generated 
    void initStatechart();
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
public :
    
    // x[1] = pitch pointing error (= target - gimbal angle)
    double R;		//## attribute R 
    
    double Range;		//## attribute Range 
    
    double Vc;		//## attribute Vc 
    
    int bTargetAcquired;		//## attribute bTargetAcquired 
    

////    Relations and components    ////
protected :
    
    EstimatorVcCoeff* Coeff;		//## link Coeff 
    


////    Framework    ////
protected :
    
    //## ignore 
    //states enumeration: 
    enum EstimatorVc_Enum{ OMNonState=0, On=1, Off=2 };
    
    int rootState_subState;		//## ignore 
    
    
    int rootState_active;		//## ignore 
    

};
//---------------------------------------------------------------------------- 
// inline operations for EstimatorVc
//---------------------------------------------------------------------------- 

inline int EstimatorVc::rootState_IN() const {
    return 1;
}

inline int EstimatorVc::On_IN() const {
    return rootState_subState == On;
}

inline int EstimatorVc::Off_IN() const {
    return rootState_subState == Off;
}



#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\EstimatorVc.h
*********************************************************************/

