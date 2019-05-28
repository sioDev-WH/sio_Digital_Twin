/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: theStdApp
//!	Generated Date	: Thu, 12, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\theStdApp.h
*********************************************************************/


#ifndef theStdApp_H 

#define theStdApp_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AppSimple.h"
#include <oxf/omthread.h>
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>

//## package AppSimple 

//----------------------------------------------------------------------------
// theStdApp.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedtheStdApp;
#endif // _OMINSTRUMENT
class StdApp;


//## class theStdApp 
class theStdApp : public OMReactive {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedtheStdApp;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation theStdApp() 
    theStdApp(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~theStdApp() 
    ~theStdApp();


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getT() const;
    
    //## auto_generated 
    void setT(double  p_t);
    
    //## auto_generated 
    StdApp* getItsApp() const;
    
    //## auto_generated 
    void setItsApp(StdApp*  p_StdApp);


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
    
    //run:
    
    //## statechart_method 
    inline int run_IN() const;
    
    //init:
    
    //## statechart_method 
    inline int init_IN() const;
    
    //done:
    
    //## statechart_method 
    inline int done_IN() const;
    
    //## auto_generated 
    virtual OMBoolean startBehavior();

protected :
    
    //## auto_generated 
    void initStatechart();
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
protected :
    
    double t;		//## attribute t 
    

////    Relations and components    ////
protected :
    
    StdApp* itsApp;		//## link itsApp 
    


////    Framework    ////
protected :
    
    //## ignore 
    //states enumeration: 
    enum theStdApp_Enum{ OMNonState=0, run=1, init=2, done=3 };
    
    int rootState_subState;		//## ignore 
    
    
    int rootState_active;		//## ignore 
    

};
//---------------------------------------------------------------------------- 
// inline operations for theStdApp
//---------------------------------------------------------------------------- 

inline int theStdApp::rootState_IN() const {
    return 1;
}

inline int theStdApp::run_IN() const {
    return rootState_subState == run;
}

inline int theStdApp::init_IN() const {
    return rootState_subState == init;
}

inline int theStdApp::done_IN() const {
    return rootState_subState == done;
}



#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedtheStdApp : virtual public AOMInstance {

    
    DECLARE_REACTIVE_META(theStdApp, OMAnimatedtheStdApp)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;
    
    //## statechart_method 
    void rootState_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void run_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void init_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void done_serializeStates(AOMSState*  aomsState) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\theStdApp.h
*********************************************************************/

