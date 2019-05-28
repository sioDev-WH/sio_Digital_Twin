/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: theTest
//!	Generated Date	: Wed, 4, Jun 2003  
	File Path	: AnimationComComponent\DefaultConfig\theTest.h
*********************************************************************/


#ifndef theTest_H 

#define theTest_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "App.h"
#include <oxf/omthread.h>
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>

//## package Application3 

//----------------------------------------------------------------------------
// theTest.h                                                                  
//----------------------------------------------------------------------------
class App;
class App_task_0010ms;

#ifdef _OMINSTRUMENT
class OMAnimatedtheTest;
#endif // _OMINSTRUMENT


//## class theTest 
class theTest : public OMReactive {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedtheTest;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation theTest() 
    theTest(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~theTest() 
    ~theTest();


////    Additional operations    ////
public :
    
    //## auto_generated 
    long getGuidanceMode() const;
    
    //## auto_generated 
    void setGuidanceMode(long  p_guidanceMode);
    
    //## auto_generated 
    int getInterval() const;
    
    //## auto_generated 
    void setInterval(int  p_interval);
    
    //## auto_generated 
    double getT() const;
    
    //## auto_generated 
    void setT(double  p_t);
    
    //## auto_generated 
    App* getItsApp() const;
    
    //## auto_generated 
    void setItsApp(App*  p_App);
    
    //## auto_generated 
    App_task_0010ms* getItstask_0010ms() const;
    
    //## auto_generated 
    void setItstask_0010ms(App_task_0010ms*  p_App_task_0010ms);


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
    
    int interval;		//## attribute interval 
    
    double t;		//## attribute t 
    

////    Relations and components    ////
protected :
    
    App* itsApp;		//## link itsApp 
    
    
    App_task_0010ms* itstask_0010ms;		//## link itstask_0010ms 
    


////    Framework    ////
protected :
    
    //## ignore 
    //states enumeration: 
    enum theTest_Enum{ OMNonState=0, terminate=1, Run=2, Init=3, Done=4 };
    
    int rootState_subState;		//## ignore 
    
    
    int rootState_active;		//## ignore 
    

};
//---------------------------------------------------------------------------- 
// inline operations for theTest
//---------------------------------------------------------------------------- 

inline int theTest::rootState_IN() const {
    return 1;
}

inline OMBoolean theTest::rootState_isCompleted() {
    return ( IS_IN(terminate) );
}

inline int theTest::terminate_IN() const {
    return rootState_subState == terminate;
}

inline int theTest::Run_IN() const {
    return rootState_subState == Run;
}

inline int theTest::Init_IN() const {
    return rootState_subState == Init;
}

inline int theTest::Done_IN() const {
    return rootState_subState == Done;
}





#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\theTest.h
*********************************************************************/

