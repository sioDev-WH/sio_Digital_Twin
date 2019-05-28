/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: aeroVel
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\aeroVel.h
*********************************************************************/


#ifndef aeroVel_H 

#define aeroVel_H 


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
#define AirframePkg_aeroVel_aeroVel_SERIALIZE OM_NO_OP


#define OM_AirframePkg_aeroVel_aeroVel_1_SERIALIZE OM_NO_OP


#define AirframePkg_aeroVel_GetPhysicalType_SERIALIZE OM_NO_OP


#define AirframePkg_aeroVel_operator_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// aeroVel.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
template <class  T> class OMAnimatedaeroVel;
#endif // _OMINSTRUMENT


//## class aeroVel 
template <class T> class aeroVel : public OMReactive, public OnStlVec<T> {
public :
    
        
        
    #ifdef _OMINSTRUMENT
        //## ignore 
        typedef OMAnimatedaeroVel<T> OMAnimatedaeroVelType;
        
    #endif // _OMINSTRUMENT
    
//## class aeroVel 


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedaeroVel<T> ;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation aeroVel() 
    aeroVel(OMThread*  p_thread = OMDefaultThread);
    
    //## operation aeroVel(OnStlVec<T> ) 
    aeroVel(OnStlVec<T> src, OMThread*  p_thread = OMDefaultThread);
    
    //## auto_generated 
    virtual ~aeroVel();


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

//## class aeroVel 



template <class T> aeroVel<T> ::aeroVel(OMThread*  p_thread) : OnStlVec<T>(VEC_SIZE)
   {
    NOTIFY_REACTIVE_CONSTRUCTOR_T(aeroVel, aeroVel(), 0, AirframePkg_aeroVel_aeroVel_SERIALIZE, OMAnimatedaeroVelType);
    setThread(p_thread, FALSE);
    //#[ operation aeroVel() 
    
       Units u(uVELOCITY); 
       units=u;
    //#]
}

template <class T> aeroVel<T> ::aeroVel(OnStlVec<T> src, OMThread*  p_thread) : OnStlVec<T>(VEC_SIZE)
   {
    NOTIFY_REACTIVE_CONSTRUCTOR_T(aeroVel, aeroVel(OnStlVec<T> ), 0, OM_AirframePkg_aeroVel_aeroVel_1_SERIALIZE, OMAnimatedaeroVelType);
    setThread(p_thread, FALSE);
    //#[ operation aeroVel(OnStlVec<T> ) 
    for(int i=0;i<size();i++)
      (*this)[i]=src[i];
    //#]
}

template <class T> aeroVel<T> ::~aeroVel() {
    NOTIFY_DESTRUCTOR(~aeroVel, TRUE);
}

template <class T> OnPhysicalType aeroVel<T> ::GetPhysicalType() {
    NOTIFY_OPERATION(GetPhysicalType, GetPhysicalType(), 0, AirframePkg_aeroVel_GetPhysicalType_SERIALIZE);
    //#[ operation GetPhysicalType() 
    return OnPhysicalType_Equal;
    //#]
}

template <class T> void aeroVel<T> ::operator=(OnStlVec<T> src) {
    NOTIFY_OPERATION(operator=, operator=(OnStlVec<T> ), 0, AirframePkg_aeroVel_operator_SERIALIZE);
    //#[ operation operator=(OnStlVec<T> ) 
    if(size()==src.size()) for(int i=0;i<size();i++)(*this)[i]=src[i];
    //#]
}

template <class T> Units* aeroVel<T> ::getUnits() const {
    return (Units*) &units;
}

template <class T> OMBoolean aeroVel<T> ::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}







#ifdef _OMINSTRUMENT

DECLARE_META_PREFIX(aeroVel)

//## ignore 
template <class T> class OMAnimatedaeroVel : virtual public AOMInstance {
public :
    
        
        typedef aeroVel<T> OMaeroVelType;
        
    

    
    DECLARE_REACTIVE_META_T(aeroVel, OMaeroVelType, OMAnimatedaeroVel)
//## ignore 


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};



template <class T> void OMAnimatedaeroVel<T> ::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("units", TRUE, TRUE);
    if((Units*) &myReal->units)
        aomsRelations->ADD_ITEM((Units*) &myReal->units);
}






#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\aeroVel.h
*********************************************************************/

