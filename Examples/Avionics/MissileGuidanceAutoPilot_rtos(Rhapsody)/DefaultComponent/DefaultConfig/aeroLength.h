/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: aeroLength
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\aeroLength.h
*********************************************************************/


#ifndef aeroLength_H 

#define aeroLength_H 


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
#define AirframePkg_aeroLength_aeroLength_SERIALIZE OM_NO_OP


#define OM_AirframePkg_aeroLength_aeroLength_1_SERIALIZE OM_NO_OP


#define AirframePkg_aeroLength_GetPhysicalType_SERIALIZE OM_NO_OP


#define AirframePkg_aeroLength_operator_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// aeroLength.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
template <class  T> class OMAnimatedaeroLength;
#endif // _OMINSTRUMENT


//## class aeroLength 
template <class T> class aeroLength : public OMReactive, public OnStlVec<T> {
public :
    
        
        
    #ifdef _OMINSTRUMENT
        //## ignore 
        typedef OMAnimatedaeroLength<T> OMAnimatedaeroLengthType;
        
    #endif // _OMINSTRUMENT
    
//## class aeroLength 


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedaeroLength<T> ;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation aeroLength() 
    aeroLength(OMThread*  p_thread = OMDefaultThread);
    
    //## operation aeroLength(OnStlVec<T> ) 
    aeroLength(OnStlVec<T> src, OMThread*  p_thread = OMDefaultThread);
    
    //## auto_generated 
    virtual ~aeroLength();


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

//## class aeroLength 



template <class T> aeroLength<T> ::aeroLength(OMThread*  p_thread) : OnStlVec<T>(1)
   {
    NOTIFY_REACTIVE_CONSTRUCTOR_T(aeroLength, aeroLength(), 0, AirframePkg_aeroLength_aeroLength_SERIALIZE, OMAnimatedaeroLengthType);
    setThread(p_thread, FALSE);
    //#[ operation aeroLength() 
    
       Units u(uLENGTH); 
       units=u;
    //#]
}

template <class T> aeroLength<T> ::aeroLength(OnStlVec<T> src, OMThread*  p_thread) : OnStlVec<T>(1)
   {
    NOTIFY_REACTIVE_CONSTRUCTOR_T(aeroLength, aeroLength(OnStlVec<T> ), 0, OM_AirframePkg_aeroLength_aeroLength_1_SERIALIZE, OMAnimatedaeroLengthType);
    setThread(p_thread, FALSE);
    //#[ operation aeroLength(OnStlVec<T> ) 
    for(int i=0;i<size();i++)
      (*this)[i]=src[i];
    //#]
}

template <class T> aeroLength<T> ::~aeroLength() {
    NOTIFY_DESTRUCTOR(~aeroLength, TRUE);
}

template <class T> OnPhysicalType aeroLength<T> ::GetPhysicalType() {
    NOTIFY_OPERATION(GetPhysicalType, GetPhysicalType(), 0, AirframePkg_aeroLength_GetPhysicalType_SERIALIZE);
    //#[ operation GetPhysicalType() 
    return OnPhysicalType_Equal;
    //#]
}

template <class T> void aeroLength<T> ::operator=(OnStlVec<T> src) {
    NOTIFY_OPERATION(operator=, operator=(OnStlVec<T> ), 0, AirframePkg_aeroLength_operator_SERIALIZE);
    //#[ operation operator=(OnStlVec<T> ) 
    if(size()==src.size()) for(int i=0;i<size();i++)(*this)[i]=src[i];
    //#]
}

template <class T> Units* aeroLength<T> ::getUnits() const {
    return (Units*) &units;
}

template <class T> OMBoolean aeroLength<T> ::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}







#ifdef _OMINSTRUMENT

DECLARE_META_PREFIX(aeroLength)

//## ignore 
template <class T> class OMAnimatedaeroLength : virtual public AOMInstance {
public :
    
        
        typedef aeroLength<T> OMaeroLengthType;
        
    

    
    DECLARE_REACTIVE_META_T(aeroLength, OMaeroLengthType, OMAnimatedaeroLength)
//## ignore 


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};



template <class T> void OMAnimatedaeroLength<T> ::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("units", TRUE, TRUE);
    if((Units*) &myReal->units)
        aomsRelations->ADD_ITEM((Units*) &myReal->units);
}






#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\aeroLength.h
*********************************************************************/

