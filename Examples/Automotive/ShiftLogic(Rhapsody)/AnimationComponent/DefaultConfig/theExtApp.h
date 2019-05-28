/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: theExtApp
//!	Generated Date	: Thu, 19, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\theExtApp.h
*********************************************************************/


#ifndef theExtApp_H 

#define theExtApp_H 


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
// theExtApp.h                                                                  
//----------------------------------------------------------------------------
class ExtApp;

#ifdef _OMINSTRUMENT
class OMAnimatedtheExtApp;
#endif // _OMINSTRUMENT


//## class theExtApp 
class theExtApp : public OMReactive {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedtheExtApp;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation theExtApp() 
    theExtApp(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~theExtApp() 
    ~theExtApp();


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getT() const;
    
    //## auto_generated 
    void setT(double  p_t);
    
    //## auto_generated 
    ExtApp* getItsApp() const;
    
    //## auto_generated 
    void setItsApp(ExtApp*  p_ExtApp);


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
    
    ExtApp* itsApp;		//## link itsApp 
    


////    Framework    ////
protected :
    
    //## ignore 
    //states enumeration: 
    enum theExtApp_Enum{ OMNonState=0, run=1, init=2, done=3 };
    
    int rootState_subState;		//## ignore 
    
    
    int rootState_active;		//## ignore 
    

};
//---------------------------------------------------------------------------- 
// inline operations for theExtApp
//---------------------------------------------------------------------------- 

inline int theExtApp::rootState_IN() const {
    return 1;
}

inline int theExtApp::run_IN() const {
    return rootState_subState == run;
}

inline int theExtApp::init_IN() const {
    return rootState_subState == init;
}

inline int theExtApp::done_IN() const {
    return rootState_subState == done;
}



#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedtheExtApp : virtual public AOMInstance {

    
    DECLARE_REACTIVE_META(theExtApp, OMAnimatedtheExtApp)


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
	File Path	: AnimationComponent\DefaultConfig\theExtApp.h
*********************************************************************/

