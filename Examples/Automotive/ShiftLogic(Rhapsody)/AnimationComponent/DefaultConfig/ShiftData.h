/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: ShiftData
//!	Generated Date	: Sun, 19, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\ShiftData.h
*********************************************************************/


#ifndef ShiftData_H 

#define ShiftData_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "TransmissionControlModels.h"
#include <oxf/omthread.h>
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "LookupTable.h"

//## package TransmissionControlModels 

//----------------------------------------------------------------------------
// ShiftData.h                                                                  
//----------------------------------------------------------------------------
class Clutch_Schedule;

#ifdef _OMINSTRUMENT
class OMAnimatedShiftData;
#endif // _OMINSTRUMENT


//## class ShiftData 
struct IOnEnv;class ShiftData : public OMReactive {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedShiftData;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation ShiftData() 
    ShiftData(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~ShiftData() 
    ~ShiftData();


////    Operations    ////
public :
    
    //## operation clean() 
    void clean();
    
    //## operation getDownShiftThreshold(const double ,const long ,double * ) 
    void getDownShiftThreshold(const double throttle, const long gear, double * threshold);
    
    //## operation getUpShiftThreshold(const double ,const long ,double * ) 
    void getUpShiftThreshold(const double throttle, const long gear, double * threshold);
    
    //## operation init() 
    void init();


////    Additional operations    ////
public :
    
    //## auto_generated 
    Clutch_Schedule* getClutchSchedule() const;
    
    //## auto_generated 
    void setClutchSchedule(Clutch_Schedule*  p_Clutch_Schedule);
    
    //## auto_generated 
    LookupTable* getDownShiftTable() const;
    
    //## auto_generated 
    LookupTable* getUpShiftTable() const;

protected :
    
    //## auto_generated 
    IOnEnv* getM_pOnEnv() const;
    
    //## auto_generated 
    void setM_pOnEnv(IOnEnv*  p_m_pOnEnv);


////    Framework operations    ////
public :
    
    //## auto_generated 
    virtual OMBoolean startBehavior();

protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
protected :
    
    IOnEnv* m_pOnEnv;		//## attribute m_pOnEnv 
    

////    Relations and components    ////
public :
    
    Clutch_Schedule* clutchSchedule;		//## link clutchSchedule 
    
    
    LookupTable downShiftTable;		//## classInstance downShiftTable 
    
    
    LookupTable upShiftTable;		//## classInstance upShiftTable 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedShiftData : virtual public AOMInstance {

    
    DECLARE_REACTIVE_META(ShiftData, OMAnimatedShiftData)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\ShiftData.h
*********************************************************************/

