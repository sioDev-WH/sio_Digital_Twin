/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Clutch_Schedule
//!	Generated Date	: Sun, 19, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Clutch_Schedule.h
*********************************************************************/


#ifndef Clutch_Schedule_H 

#define Clutch_Schedule_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "TransmissionControlModels.h"

//## package TransmissionControlModels 

//----------------------------------------------------------------------------
// Clutch_Schedule.h                                                                  
//----------------------------------------------------------------------------
class GearInfo;

#ifdef _OMINSTRUMENT
class OMAnimatedClutch_Schedule;
#endif // _OMINSTRUMENT


//## class Clutch_Schedule 
struct IOnEnv;

class Clutch_Schedule  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedClutch_Schedule;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation Clutch_Schedule() 
    Clutch_Schedule();
    
    //## auto_generated 
    ~Clutch_Schedule();


////    Operations    ////
public :
    
    //## operation clean() 
    void clean();
    
    //## operation init() 
    void init();
    
    //## operation update(const long ,const long ) 
    void update(const long CurrentGear, const long NextGear);
    
    //## operation updateDisengage(const long,const long) 
    void updateDisengage(const long  CurrentGear, const long  TargetGear);
    
    //## operation updateEngage(const long,const long) 
    void updateEngage(const long  CurrentGear, const long  TargetGear);


////    Additional operations    ////
public :
    
    //## auto_generated 
    bool *  getDisengageList() const;
    
    //## auto_generated 
    void setDisengageList(bool * p_disengageList);
    
    //## auto_generated 
    bool *  getEngageList() const;
    
    //## auto_generated 
    void setEngageList(bool * p_engageList);
    
    //## auto_generated 
    long getNClutches() const;
    
    //## auto_generated 
    void setNClutches(long  p_nClutches);
    
    //## auto_generated 
    long getNGears() const;
    
    //## auto_generated 
    void setNGears(long  p_nGears);
    
    //## auto_generated 
    GearInfo* getGears() const;
    
    //## auto_generated 
    void setGears(GearInfo*  p_GearInfo);

protected :
    
    //## auto_generated 
    IOnEnv* getM_pOnEnv() const;
    
    //## auto_generated 
    void setM_pOnEnv(IOnEnv*  p_m_pOnEnv);


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
public :
    
    bool * disengageList;		//## attribute disengageList 
    
    bool * engageList;		//## attribute engageList 
    
    long nClutches;		//## attribute nClutches 
    
    long nGears;		//## attribute nGears 
    
protected :
    
    IOnEnv* m_pOnEnv;		//## attribute m_pOnEnv 
    

////    Relations and components    ////
public :
    
    GearInfo* Gears;		//## link Gears 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedClutch_Schedule : virtual public AOMInstance {

    
    DECLARE_META(Clutch_Schedule, OMAnimatedClutch_Schedule)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Clutch_Schedule.h
*********************************************************************/

