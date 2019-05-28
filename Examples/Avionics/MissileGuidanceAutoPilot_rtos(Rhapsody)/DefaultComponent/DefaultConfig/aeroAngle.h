/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: aeroAngle
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\aeroAngle.h
*********************************************************************/


#ifndef aeroAngle_H 

#define aeroAngle_H 


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
#define AirframePkg_aeroAngle_aeroAngle_SERIALIZE OM_NO_OP


#define OM_AirframePkg_aeroAngle_aeroAngle_1_SERIALIZE OM_NO_OP


#define AirframePkg_aeroAngle_GetPhysicalType_SERIALIZE OM_NO_OP


#define AirframePkg_aeroAngle_operator_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// aeroAngle.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
template <class  T> class OMAnimatedaeroAngle;
#endif // _OMINSTRUMENT


//## class aeroAngle 
template <class T> class aeroAngle : public OMReactive, public OnStlVec<T> {
public :
    
        
        
    #ifdef _OMINSTRUMENT
        //## ignore 
        typedef OMAnimatedaeroAngle<T> OMAnimatedaeroAngleType;
        
    #endif // _OMINSTRUMENT
    
//## class aeroAngle 


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedaeroAngle<T> ;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation aeroAngle() 
    aeroAngle(OMThread*  p_thread = OMDefaultThread);
    
    //## operation aeroAngle(OnStlVec<T> ) 
    aeroAngle(OnStlVec<T> src, OMThread*  p_thread = OMDefaultThread);
    
    //## auto_generated 
    virtual ~aeroAngle();


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

//## class aeroAngle 



template <class T> aeroAngle<T> ::aeroAngle(OMThread*  p_thread) : OnStlVec<T>(VEC_SIZE)
   {
    NOTIFY_REACTIVE_CONSTRUCTOR_T(aeroAngle, aeroAngle(), 0, AirframePkg_aeroAngle_aeroAngle_SERIALIZE, OMAnimatedaeroAngleType);
    setThread(p_thread, FALSE);
    //#[ operation aeroAngle() 
    Units u(uANGLE);
    units=u;
    //#]
}

template <class T> aeroAngle<T> ::aeroAngle(OnStlVec<T> src, OMThread*  p_thread) : OnStlVec<T>(VEC_SIZE)
   {
    NOTIFY_REACTIVE_CONSTRUCTOR_T(aeroAngle, aeroAngle(OnStlVec<T> ), 0, OM_AirframePkg_aeroAngle_aeroAngle_1_SERIALIZE, OMAnimatedaeroAngleType);
    setThread(p_thread, FALSE);
    //#[ operation aeroAngle(OnStlVec<T> ) 
    for(int i=0;i<size();i++)
      (*this)[i]=src[i];
    //#]
}

template <class T> aeroAngle<T> ::~aeroAngle() {
    NOTIFY_DESTRUCTOR(~aeroAngle, TRUE);
}

template <class T> OnPhysicalType aeroAngle<T> ::GetPhysicalType() {
    NOTIFY_OPERATION(GetPhysicalType, GetPhysicalType(), 0, AirframePkg_aeroAngle_GetPhysicalType_SERIALIZE);
    //#[ operation GetPhysicalType() 
    return OnPhysicalType_Equal;
    //#]
}

template <class T> void aeroAngle<T> ::operator=(OnStlVec<T> src) {
    NOTIFY_OPERATION(operator=, operator=(OnStlVec<T> ), 0, AirframePkg_aeroAngle_operator_SERIALIZE);
    //#[ operation operator=(OnStlVec<T> ) 
    if(size()==src.size()) for(int i=0;i<size();i++)(*this)[i]=src[i];
    //#]
}

template <class T> Units* aeroAngle<T> ::getUnits() const {
    return (Units*) &units;
}

template <class T> OMBoolean aeroAngle<T> ::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}







#ifdef _OMINSTRUMENT

DECLARE_META_PREFIX(aeroAngle)

//## ignore 
template <class T> class OMAnimatedaeroAngle : virtual public AOMInstance {
public :
    
        
        typedef aeroAngle<T> OMaeroAngleType;
        
    

    
    DECLARE_REACTIVE_META_T(aeroAngle, OMaeroAngleType, OMAnimatedaeroAngle)
//## ignore 


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};



template <class T> void OMAnimatedaeroAngle<T> ::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("units", TRUE, TRUE);
    if((Units*) &myReal->units)
        aomsRelations->ADD_ITEM((Units*) &myReal->units);
}






#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\aeroAngle.h
*********************************************************************/

