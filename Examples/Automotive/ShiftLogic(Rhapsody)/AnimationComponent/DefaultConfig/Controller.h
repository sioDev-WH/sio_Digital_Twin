/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Controller
//!	Generated Date	: Wed, 11, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\Controller.h
*********************************************************************/


#ifndef Controller_H 

#define Controller_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "TransmissionControlModels.h"
#include <oxf/omthread.h>
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "ShiftData.h"
#include "OnModelBase.h"

//## package TransmissionControlModels 

//----------------------------------------------------------------------------
// Controller.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedController;
#endif // _OMINSTRUMENT


//## class Controller 
class Controller : public OMReactive, public COnModelBase {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedController;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation Controller() 
    Controller(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~Controller() 
    ~Controller();


////    Operations    ////
public :
    
    //## operation AddRef() 
    long AddRef();
    
    //## operation Load(FILE * ) 
    bool Load(FILE * fs);
    
    //## operation Release() 
    long Release();
    
    //## operation Save(FILE * ) 
    void Save(FILE * fs);
    
    //## operation SetName(LPCTSTR ) 
    void SetName(LPCTSTR cszName);
    
    //## operation SetShiftDelay(const bool,const long,const double) 
    void SetShiftDelay(const bool  bUp, const long  Gear, const double  delay);
    
    //## operation clean() 
    void clean();
    
    //## operation handle_ShiftLeverData(long * ) 
    void handle_ShiftLeverData(long * val);
    
    //## operation handle_SpeedData(double * ) 
    void handle_SpeedData(double * val);
    
    //## operation handle_ThrottleData(double * ) 
    void handle_ThrottleData(double * val);
    
    //## operation handle_tick() 
    void handle_tick();
    
    //## operation init() 
    void init();

private :
    
    //## operation Fire_DisengageEvents() 
    void Fire_DisengageEvents();
    
    //## operation Fire_EngageEvents() 
    void Fire_EngageEvents();
    
    //## operation duringGear() 
    void duringGear();
    
    //## operation enterGear(int) 
    void enterGear(int  iState);
    
    //## operation runShiftLogic() 
    void runShiftLogic();
    
    //## operation updateThresholds(int) 
    void updateThresholds(int  iState);


////    Additional operations    ////
public :
    
    //## auto_generated 
    Port_Int *  getPort_EngineStart() const;
    
    //## auto_generated 
    void setPort_EngineStart(Port_Int * p_Port_EngineStart);
    
    //## auto_generated 
    bool getBEngineStarted() const;
    
    //## auto_generated 
    void setBEngineStarted(bool  p_bEngineStarted);
    
    //## auto_generated 
    ShiftData* getShiftData() const;


////    Framework operations    ////
public :
    
    //manualNeutralShift();
    
    //manualReverseShift();
    
    //manualForwardShift();
    
    //upshift();
    
    //downshift();
    
    //tic();
    
    //rootState:
    
    //## statechart_method 
    inline int rootState_IN() const;
    
    //## statechart_method 
    virtual void rootState_entDef();
    
    //## statechart_method 
    virtual int rootState_dispatchEvent(short  id);
    
    //Third:
    
    //## statechart_method 
    inline int Third_IN() const;
    
    //Second:
    
    //## statechart_method 
    inline int Second_IN() const;
    
    //Reverse:
    
    //## statechart_method 
    inline int Reverse_IN() const;
    
    //Idle:
    
    //## statechart_method 
    inline int Idle_IN() const;
    
    //Fourth:
    
    //## statechart_method 
    inline int Fourth_IN() const;
    
    //First:
    
    //## statechart_method 
    inline int First_IN() const;
    
    //## auto_generated 
    virtual OMBoolean startBehavior();
    
    //## statechart_method 
    void rootState_exit();

protected :
    
    //## auto_generated 
    void initStatechart();


////    Attributes    ////
public :
    
    Port_Int * Port_DC;		//## attribute Port_DC 
    
    Port_Int * Port_EngineStart;		//## attribute Port_EngineStart 
    
    Port_Int * Port_FC;		//## attribute Port_FC 
    
    Port_Int * Port_IOC;		//## attribute Port_IOC 
    
    Port_Int * Port_LRB;		//## attribute Port_LRB 
    
    Port_Int * Port_OB;		//## attribute Port_OB 
    
    Port_Int * Port_POC;		//## attribute Port_POC 
    
    Port_Int * Port_RC;		//## attribute Port_RC 
    
    Port_Int * Port_TCC;		//## attribute Port_TCC 
    
    double downshiftDelay[6];		//## attribute downshiftDelay 
    
    Port_Int * pActuatorPorts[8];		//## attribute pActuatorPorts 
    
    long shiftLeverData;		//## attribute shiftLeverData 
    
    double throttleData;		//## attribute throttleData 
    
    double upshiftDelay[6];		//## attribute upshiftDelay 
    
    double vehicleSpeedData;		//## attribute vehicleSpeedData 
    
protected :
    
    bool bEngineStarted;		//## attribute bEngineStarted 
    
    double shiftTime;		//## attribute shiftTime 
    
private :
    
    long currentGear;		//## attribute currentGear 
    
    double downShiftThreshold;		//## attribute downShiftThreshold 
    
    long m_cRef;		//## attribute m_cRef 
    
    long targetGear;		//## attribute targetGear 
    
    double upShiftThreshold;		//## attribute upShiftThreshold 
    

////    Relations and components    ////
private :
    
    ShiftData shiftData;		//## classInstance shiftData 
    


////    Framework    ////
protected :
    
    //## ignore 
    //states enumeration: 
    enum Controller_Enum{ OMNonState=0, Third=1, Second=2, Reverse=3, Idle=4, Fourth=5, First=6 };
    
    int rootState_subState;		//## ignore 
    
    
    int rootState_active;		//## ignore 
    

};
//---------------------------------------------------------------------------- 
// inline operations for Controller
//---------------------------------------------------------------------------- 

inline int Controller::rootState_IN() const {
    return 1;
}

inline int Controller::Third_IN() const {
    return rootState_subState == Third;
}

inline int Controller::Second_IN() const {
    return rootState_subState == Second;
}

inline int Controller::Reverse_IN() const {
    return rootState_subState == Reverse;
}

inline int Controller::Idle_IN() const {
    return rootState_subState == Idle;
}

inline int Controller::Fourth_IN() const {
    return rootState_subState == Fourth;
}

inline int Controller::First_IN() const {
    return rootState_subState == First;
}



#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedController : virtual public AOMInstance {

    
    DECLARE_REACTIVE_META(Controller, OMAnimatedController)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;
    
    //## statechart_method 
    void rootState_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Third_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Second_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Reverse_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Idle_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void Fourth_serializeStates(AOMSState*  aomsState) const;
    
    //## statechart_method 
    void First_serializeStates(AOMSState*  aomsState) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Controller.h
*********************************************************************/

