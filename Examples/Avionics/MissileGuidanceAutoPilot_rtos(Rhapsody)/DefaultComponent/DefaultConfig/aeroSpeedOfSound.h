/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: aeroSpeedOfSound
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\aeroSpeedOfSound.h
*********************************************************************/


#ifndef aeroSpeedOfSound_H 

#define aeroSpeedOfSound_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AirframePkg.h"
#include <oxf/omthread.h>
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "Units.h"

//## package AirframePkg 


//#[ ignore 
#define AirframePkg_aeroSpeedOfSound_aeroSpeedOfSound_SERIALIZE OM_NO_OP


#define OM_AirframePkg_aeroSpeedOfSound_aeroSpeedOfSound_1_SERIALIZE OM_NO_OP


#define AirframePkg_aeroSpeedOfSound_GetPhysicalType_SERIALIZE OM_NO_OP


#define AirframePkg_aeroSpeedOfSound_operator_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// aeroSpeedOfSound.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
template <class  T> class OMAnimatedaeroSpeedOfSound;
#endif // _OMINSTRUMENT


//## class aeroSpeedOfSound 
template <class T> class aeroSpeedOfSound : public OMReactive, public OnStlVec<T> {
public :
    
        
        
    #ifdef _OMINSTRUMENT
        //## ignore 
        typedef OMAnimatedaeroSpeedOfSound<T> OMAnimatedaeroSpeedOfSoundType;
        
    #endif // _OMINSTRUMENT
    
//## class aeroSpeedOfSound 


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedaeroSpeedOfSound<T> ;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation aeroSpeedOfSound() 
    aeroSpeedOfSound(OMThread*  p_thread = OMDefaultThread);
    
    //## operation aeroSpeedOfSound(OnStlVec<T> ) 
    aeroSpeedOfSound(OnStlVec<T> src, OMThread*  p_thread = OMDefaultThread);
    
    //## auto_generated 
    virtual ~aeroSpeedOfSound();


////    Operations    ////
public :
    
    //## operation GetPhysicalType() 
    virtual OnPhysicalType GetPhysicalType();
    
    //## operation operator=(OnStlVec<T> ) 
    void operator=(OnStlVec<T> src);


////    Additional operations    ////
public :
    
    //## auto_generated 
    Units* getUnits() const;


////    Framework operations    ////
public :
    
    //## auto_generated 
    virtual OMBoolean startBehavior();


////    Relations and components    ////
public :
    
    Units units;		//## classInstance units 
    


};

//## class aeroSpeedOfSound 



template <class T> aeroSpeedOfSound<T> ::aeroSpeedOfSound(OMThread*  p_thread) : OnStlVec<T>(1)
   {
    NOTIFY_REACTIVE_CONSTRUCTOR_T(aeroSpeedOfSound, aeroSpeedOfSound(), 0, AirframePkg_aeroSpeedOfSound_aeroSpeedOfSound_SERIALIZE, OMAnimatedaeroSpeedOfSoundType);
    setThread(p_thread, FALSE);
    //#[ operation aeroSpeedOfSound() 
    
       Units u(uVELOCITY); 
       units=u;
    //#]
}

template <class T> aeroSpeedOfSound<T> ::aeroSpeedOfSound(OnStlVec<T> src, OMThread*  p_thread) : OnStlVec<T>(1)
   {
    NOTIFY_REACTIVE_CONSTRUCTOR_T(aeroSpeedOfSound, aeroSpeedOfSound(OnStlVec<T> ), 0, OM_AirframePkg_aeroSpeedOfSound_aeroSpeedOfSound_1_SERIALIZE, OMAnimatedaeroSpeedOfSoundType);
    setThread(p_thread, FALSE);
    //#[ operation aeroSpeedOfSound(OnStlVec<T> ) 
    for(int i=0;i<size();i++)
      (*this)[i]=src[i];
    //#]
}

template <class T> aeroSpeedOfSound<T> ::~aeroSpeedOfSound() {
    NOTIFY_DESTRUCTOR(~aeroSpeedOfSound, TRUE);
}

template <class T> OnPhysicalType aeroSpeedOfSound<T> ::GetPhysicalType() {
    NOTIFY_OPERATION(GetPhysicalType, GetPhysicalType(), 0, AirframePkg_aeroSpeedOfSound_GetPhysicalType_SERIALIZE);
    //#[ operation GetPhysicalType() 
    return OnPhysicalType_Equal;
    //#]
}

template <class T> void aeroSpeedOfSound<T> ::operator=(OnStlVec<T> src) {
    NOTIFY_OPERATION(operator=, operator=(OnStlVec<T> ), 0, AirframePkg_aeroSpeedOfSound_operator_SERIALIZE);
    //#[ operation operator=(OnStlVec<T> ) 
    if(size()==src.size()) for(int i=0;i<size();i++)(*this)[i]=src[i];
    //#]
}

template <class T> Units* aeroSpeedOfSound<T> ::getUnits() const {
    return (Units*) &units;
}

template <class T> OMBoolean aeroSpeedOfSound<T> ::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}







#ifdef _OMINSTRUMENT

DECLARE_META_PREFIX(aeroSpeedOfSound)

//## ignore 
template <class T> class OMAnimatedaeroSpeedOfSound : virtual public AOMInstance {
public :
    
        
        typedef aeroSpeedOfSound<T> OMaeroSpeedOfSoundType;
        
    

    
    DECLARE_REACTIVE_META_T(aeroSpeedOfSound, OMaeroSpeedOfSoundType, OMAnimatedaeroSpeedOfSound)
//## ignore 


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};



template <class T> void OMAnimatedaeroSpeedOfSound<T> ::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("units", TRUE, TRUE);
    if((Units*) &myReal->units)
        aomsRelations->ADD_ITEM((Units*) &myReal->units);
}






#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\aeroSpeedOfSound.h
*********************************************************************/

