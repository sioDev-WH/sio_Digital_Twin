/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: theSimpleApp
//!	Generated Date	: Wed, 11, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\theSimpleApp.h
*********************************************************************/


#ifndef theSimpleApp_H 

#define theSimpleApp_H 


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
// theSimpleApp.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedtheSimpleApp;
#endif // _OMINSTRUMENT
class SimpleApp;


//## class theSimpleApp 
class theSimpleApp : public OMReactive {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedtheSimpleApp;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation theSimpleApp() 
    theSimpleApp(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~theSimpleApp() 
    ~theSimpleApp();


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getT() const;
    
    //## auto_generated 
    void setT(double  p_t);
    
    //## auto_generated 
    SimpleApp* getItsApp() const;
    
    //## auto_generated 
    void setItsApp(SimpleApp*  p_SimpleApp);


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
    
    //wait:
    
    //## statechart_method 
    inline int wait_IN() const;
    
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
    
    //## statechart_method 
    void rootState_exit();

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
    
    SimpleApp* itsApp;		//## link itsApp 
    


////    Framework    ////
protected :
    
    //## ignore 
    //states enumeration: 
    enum theSimpleApp_Enum{ OMNonState=0, wait=1, run=2, init=3, done=4 };
    
    int rootState_subState;		//## ignore 
    
    
    int rootState_active;		//## ignore 
    

};
//---------------------------------------------------------------------------- 
// inline operations for theSimpleApp
//---------------------------------------------------------------------------- 

inline int theSimpleApp::rootState_IN() const {
    return 1;
}

inline int theSimpleApp::wait_IN() const {
    return rootState_subState == wait;
}

inline int theSimpleApp::run_IN() const {
    return rootState_subState == run;
}

inline int theSimpleApp::init_IN() const {
    return rootState_subState == init;
}

inline int theSimpleApp::done_IN() const {
    return rootState_subState == done;
}



#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedtheSimpleApp : virtual public AOMInstance {

    
    DECLARE_REACTIVE_META(theSimpleApp, OMAnimatedtheSimpleApp)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;
    
    //## statechart_method 
    void rootState_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void wait_serializeStates(AOMSState*  aomsState) const;
    
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
	File Path	: AnimationComponent\DefaultConfig\theSimpleApp.h
*********************************************************************/

