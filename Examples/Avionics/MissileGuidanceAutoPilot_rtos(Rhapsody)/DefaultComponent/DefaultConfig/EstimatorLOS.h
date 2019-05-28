/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: EstimatorLOS
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\EstimatorLOS.h
*********************************************************************/


#ifndef EstimatorLOS_H 

#define EstimatorLOS_H 


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
// EstimatorLOS.h                                                                  
//----------------------------------------------------------------------------
class EstimatorLOSCoeff;


//## class EstimatorLOS 
class EstimatorLOS : public OMReactive, public COnModelBase {


////    Constructors and destructors    ////
public :
    
    //## operation EstimatorLOS(double) 
    EstimatorLOS(double  bandwidth, OMThread*  p_thread = OMDefaultThread);
    
    //## operation EstimatorLOS() 
    EstimatorLOS(OMThread*  p_thread = OMDefaultThread);
    
    //## auto_generated 
    ~EstimatorLOS();


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
    double getL() const;
    
    //## auto_generated 
    void setL(double  p_L);
    
    //## auto_generated 
    double getLOSRate() const;
    
    //## auto_generated 
    void setLOSRate(double  p_LOSRate);
    
    //## auto_generated 
    double getEpsilon() const;
    
    //## auto_generated 
    void setEpsilon(double  p_epsilon);
    
    //## auto_generated 
    int getGuidanceMode() const;
    
    //## auto_generated 
    void setGuidanceMode(int  p_guidanceMode);
    
    //## auto_generated 
    double getQf() const;
    
    //## auto_generated 
    void setQf(double  p_qf);
    
    //## auto_generated 
    double getQs() const;
    
    //## auto_generated 
    void setQs(double  p_qs);
    
    //## auto_generated 
    EstimatorLOSCoeff* getCoeff() const;
    
    //## auto_generated 
    void setCoeff(EstimatorLOSCoeff*  p_EstimatorLOSCoeff);


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
    
    // qs = filtered stabilized pitch rate
    double L;		//## attribute L 
    
    double LOSRate;		//## attribute LOSRate 
    
    // dish error
    double epsilon;		//## attribute epsilon 
    
    int guidanceMode;		//## attribute guidanceMode 
    
    // qs = filtered stabilized pitch rate
    double qf;		//## attribute qf 
    
    // qs = stabilized pitch rate
    double qs;		//## attribute qs 
    

////    Relations and components    ////
protected :
    
    EstimatorLOSCoeff* Coeff;		//## link Coeff 
    


////    Framework    ////
protected :
    
    //## ignore 
    //states enumeration: 
    enum EstimatorLOS_Enum{ OMNonState=0, On=1, Off=2 };
    
    int rootState_subState;		//## ignore 
    
    
    int rootState_active;		//## ignore 
    

};
//---------------------------------------------------------------------------- 
// inline operations for EstimatorLOS
//---------------------------------------------------------------------------- 

inline int EstimatorLOS::rootState_IN() const {
    return 1;
}

inline int EstimatorLOS::On_IN() const {
    return rootState_subState == On;
}

inline int EstimatorLOS::Off_IN() const {
    return rootState_subState == Off;
}



#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\EstimatorLOS.h
*********************************************************************/

