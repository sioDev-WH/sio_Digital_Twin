/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: theExtApp2
//!	Generated Date	: Sun, 22, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\theExtApp2.h
*********************************************************************/


#ifndef theExtApp2_H 

#define theExtApp2_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AppSimple.h"
#include <oxf/omthread.h>
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "fstream.h"

//## package AppSimple 

//----------------------------------------------------------------------------
// theExtApp2.h                                                                  
//----------------------------------------------------------------------------
class ExtApp;

#ifdef _OMINSTRUMENT
class OMAnimatedtheExtApp2;
#endif // _OMINSTRUMENT


//## class theExtApp2 
class theExtApp2 : public OMReactive {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedtheExtApp2;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation theExtApp2() 
    theExtApp2(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~theExtApp2() 
    ~theExtApp2();


////    Operations    ////
public :
    
    //## operation Load() 
    void Load();
    
    //## operation Save() 
    void Save();
    
    //## operation UpdateParameters() 
    void UpdateParameters();


////    Additional operations    ////
public :
    
    //## auto_generated 
    int getBDataSaved() const;
    
    //## auto_generated 
    void setBDataSaved(int  p_bDataSaved);
    
    //## auto_generated 
    int getCycles() const;
    
    //## auto_generated 
    void setCycles(int  p_cycles);
    
    //## auto_generated 
    ofstream getFs() const;
    
    //## auto_generated 
    void setFs(ofstream  p_fs);
    
    //## auto_generated 
    double getShiftTime() const;
    
    //## auto_generated 
    void setShiftTime(double  p_shiftTime);
    
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
    
    //SaveData:
    
    //## statechart_method 
    inline int SaveData_IN() const;
    
    //run:
    
    //## statechart_method 
    inline int run_IN() const;
    
    //LoadData:
    
    //## statechart_method 
    inline int LoadData_IN() const;
    
    //init:
    
    //## statechart_method 
    inline int init_IN() const;
    
    //done:
    
    //## statechart_method 
    inline int done_IN() const;
    
    //## auto_generated 
    virtual OMBoolean startBehavior();
    
    //## statechart_method 
    int run_takeEvent(short  id);
    
    //## statechart_method 
    int runTakeevTick();
    
    //## statechart_method 
    void rootState_exit();

protected :
    
    //## auto_generated 
    void initStatechart();
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
protected :
    
    int bDataSaved;		//## attribute bDataSaved 
    
    int cycles;		//## attribute cycles 
    
    ofstream fs;		//## attribute fs 
    
    double shiftTime;		//## attribute shiftTime 
    
    double t;		//## attribute t 
    

////    Relations and components    ////
protected :
    
    ExtApp* itsApp;		//## link itsApp 
    


////    Framework    ////
protected :
    
    //## ignore 
    //states enumeration: 
    enum theExtApp2_Enum{ OMNonState=0, SaveData=1, run=2, LoadData=3, init=4, done=5 };
    
    int rootState_subState;		//## ignore 
    
    
    int rootState_active;		//## ignore 
    

};
//---------------------------------------------------------------------------- 
// inline operations for theExtApp2
//---------------------------------------------------------------------------- 

inline int theExtApp2::rootState_IN() const {
    return 1;
}

inline int theExtApp2::SaveData_IN() const {
    return rootState_subState == SaveData;
}

inline int theExtApp2::run_IN() const {
    return rootState_subState == run;
}

inline int theExtApp2::LoadData_IN() const {
    return rootState_subState == LoadData;
}

inline int theExtApp2::init_IN() const {
    return rootState_subState == init;
}

inline int theExtApp2::done_IN() const {
    return rootState_subState == done;
}



#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedtheExtApp2 : virtual public AOMInstance {

    
    DECLARE_REACTIVE_META(theExtApp2, OMAnimatedtheExtApp2)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;
    
    //## statechart_method 
    void rootState_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void SaveData_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void run_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void LoadData_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void init_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void done_serializeStates(AOMSState*  aomsState) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\theExtApp2.h
*********************************************************************/

