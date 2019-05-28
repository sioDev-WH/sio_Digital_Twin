/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: theApp
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\theApp.h
*********************************************************************/


#ifndef theApp_H 

#define theApp_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "Application.h"
#include <oxf/omthread.h>
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>

//## package Application 

//----------------------------------------------------------------------------
// theApp.h                                                                  
//----------------------------------------------------------------------------
class App1_app;

#ifdef _OMINSTRUMENT
class OMAnimatedtheApp;
#endif // _OMINSTRUMENT


//## class theApp 
class theApp : public OMReactive {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedtheApp;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation theApp() 
    theApp(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~theApp() 
    ~theApp();


////    Additional operations    ////
public :
    
    //## auto_generated 
    long getGuidanceMode() const;
    
    //## auto_generated 
    void setGuidanceMode(long  p_guidanceMode);
    
    //## auto_generated 
    double getT() const;
    
    //## auto_generated 
    void setT(double  p_t);
    
    //## auto_generated 
    App1_app* getItsApp() const;
    
    //## auto_generated 
    void setItsApp(App1_app*  p_App1_app);


////    Framework operations    ////
public :
    
    //evTick();
    
    //rootState:
    
    //## statechart_method 
    inline int rootState_IN() const;
    
    //## statechart_method 
    inline OMBoolean rootState_isCompleted();
    
    //## statechart_method 
    virtual void rootState_entDef();
    
    //## statechart_method 
    virtual int rootState_dispatchEvent(short  id);
    
    //terminate:
    
    //## statechart_method 
    inline int terminate_IN() const;
    
    //Run:
    
    //## statechart_method 
    inline int Run_IN() const;
    
    //Init:
    
    //## statechart_method 
    inline int Init_IN() const;
    
    //Done:
    
    //## statechart_method 
    inline int Done_IN() const;
    
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
    
    long guidanceMode;		//## attribute guidanceMode 
    
    double t;		//## attribute t 
    

////    Relations and components    ////
protected :
    
    App1_app* itsApp;		//## link itsApp 
    


////    Framework    ////
protected :
    
    //## ignore 
    //states enumeration: 
    enum theApp_Enum{ OMNonState=0, terminate=1, Run=2, Init=3, Done=4 };
    
    int rootState_subState;		//## ignore 
    
    
    int rootState_active;		//## ignore 
    

};
//---------------------------------------------------------------------------- 
// inline operations for theApp
//---------------------------------------------------------------------------- 

inline int theApp::rootState_IN() const {
    return 1;
}

inline OMBoolean theApp::rootState_isCompleted() {
    return ( IS_IN(terminate) );
}

inline int theApp::terminate_IN() const {
    return rootState_subState == terminate;
}

inline int theApp::Run_IN() const {
    return rootState_subState == Run;
}

inline int theApp::Init_IN() const {
    return rootState_subState == Init;
}

inline int theApp::Done_IN() const {
    return rootState_subState == Done;
}



#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedtheApp : virtual public AOMInstance {

    
    DECLARE_REACTIVE_META(theApp, OMAnimatedtheApp)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;
    
    //## statechart_method 
    void rootState_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void terminate_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Run_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Init_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Done_serializeStates(AOMSState*  aomsState) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\theApp.h
*********************************************************************/

