/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: aeroForce
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\aeroForce.h
*********************************************************************/


#ifndef aeroForce_H 

#define aeroForce_H 


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
#define AirframePkg_aeroForce_aeroForce_SERIALIZE OM_NO_OP


#define OM_AirframePkg_aeroForce_aeroForce_1_SERIALIZE OM_NO_OP


#define AirframePkg_aeroForce_GetPhysicalType_SERIALIZE OM_NO_OP


#define AirframePkg_aeroForce_operator_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// aeroForce.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
template <class  T> class OMAnimatedaeroForce;
#endif // _OMINSTRUMENT


//## class aeroForce 
template <class T> class aeroForce : public OMReactive, public OnStlVec<T> {
public :
    
        
        
    #ifdef _OMINSTRUMENT
        //## ignore 
        typedef OMAnimatedaeroForce<T> OMAnimatedaeroForceType;
        
    #endif // _OMINSTRUMENT
    
//## class aeroForce 


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedaeroForce<T> ;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation aeroForce() 
    aeroForce(OMThread*  p_thread = OMDefaultThread);
    
    //## operation aeroForce(OnStlVec<T> ) 
    aeroForce(OnStlVec<T> src, OMThread*  p_thread = OMDefaultThread);
    
    //## auto_generated 
    virtual ~aeroForce();


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

//## class aeroForce 



template <class T> aeroForce<T> ::aeroForce(OMThread*  p_thread) : OnStlVec<T>(VEC_SIZE)
   {
    NOTIFY_REACTIVE_CONSTRUCTOR_T(aeroForce, aeroForce(), 0, AirframePkg_aeroForce_aeroForce_SERIALIZE, OMAnimatedaeroForceType);
    setThread(p_thread, FALSE);
    //#[ operation aeroForce() 
    Units u(uFORCE); 
    units=u;
    //#]
}

template <class T> aeroForce<T> ::aeroForce(OnStlVec<T> src, OMThread*  p_thread) : OnStlVec<T>(VEC_SIZE)
   {
    NOTIFY_REACTIVE_CONSTRUCTOR_T(aeroForce, aeroForce(OnStlVec<T> ), 0, OM_AirframePkg_aeroForce_aeroForce_1_SERIALIZE, OMAnimatedaeroForceType);
    setThread(p_thread, FALSE);
    //#[ operation aeroForce(OnStlVec<T> ) 
    for(int i=0;i<size();i++)
      (*this)[i]=src[i];
    //#]
}

template <class T> aeroForce<T> ::~aeroForce() {
    NOTIFY_DESTRUCTOR(~aeroForce, TRUE);
}

template <class T> OnPhysicalType aeroForce<T> ::GetPhysicalType() {
    NOTIFY_OPERATION(GetPhysicalType, GetPhysicalType(), 0, AirframePkg_aeroForce_GetPhysicalType_SERIALIZE);
    //#[ operation GetPhysicalType() 
    return OnPhysicalType_Sum;
    //#]
}

template <class T> void aeroForce<T> ::operator=(OnStlVec<T> src) {
    NOTIFY_OPERATION(operator=, operator=(OnStlVec<T> ), 0, AirframePkg_aeroForce_operator_SERIALIZE);
    //#[ operation operator=(OnStlVec<T> ) 
    if(size()==src.size()) for(int i=0;i<size();i++)(*this)[i]=src[i];
    //#]
}

template <class T> Units* aeroForce<T> ::getUnits() const {
    return (Units*) &units;
}

template <class T> OMBoolean aeroForce<T> ::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}







#ifdef _OMINSTRUMENT

DECLARE_META_PREFIX(aeroForce)

//## ignore 
template <class T> class OMAnimatedaeroForce : virtual public AOMInstance {
public :
    
        
        typedef aeroForce<T> OMaeroForceType;
        
    

    
    DECLARE_REACTIVE_META_T(aeroForce, OMaeroForceType, OMAnimatedaeroForce)
//## ignore 


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};



template <class T> void OMAnimatedaeroForce<T> ::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("units", TRUE, TRUE);
    if((Units*) &myReal->units)
        aomsRelations->ADD_ITEM((Units*) &myReal->units);
}






#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\aeroForce.h
*********************************************************************/

