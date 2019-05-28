/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: aeroRotVel
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\aeroRotVel.h
*********************************************************************/


#ifndef aeroRotVel_H 

#define aeroRotVel_H 


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
#define AirframePkg_aeroRotVel_aeroRotVel_SERIALIZE OM_NO_OP


#define OM_AirframePkg_aeroRotVel_aeroRotVel_1_SERIALIZE OM_NO_OP


#define AirframePkg_aeroRotVel_GetPhysicalType_SERIALIZE OM_NO_OP


#define AirframePkg_aeroRotVel_operator_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// aeroRotVel.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
template <class  T> class OMAnimatedaeroRotVel;
#endif // _OMINSTRUMENT


//## class aeroRotVel 
template <class T> class aeroRotVel : public OMReactive, public OnStlVec<T> {
public :
    
        
        
    #ifdef _OMINSTRUMENT
        //## ignore 
        typedef OMAnimatedaeroRotVel<T> OMAnimatedaeroRotVelType;
        
    #endif // _OMINSTRUMENT
    
//## class aeroRotVel 


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedaeroRotVel<T> ;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation aeroRotVel() 
    aeroRotVel(OMThread*  p_thread = OMDefaultThread);
    
    //## operation aeroRotVel(OnStlVec<T> ) 
    aeroRotVel(OnStlVec<T> src, OMThread*  p_thread = OMDefaultThread);
    
    //## auto_generated 
    virtual ~aeroRotVel();


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

//## class aeroRotVel 



template <class T> aeroRotVel<T> ::aeroRotVel(OMThread*  p_thread) : OnStlVec<T>(VEC_SIZE)
   {
    NOTIFY_REACTIVE_CONSTRUCTOR_T(aeroRotVel, aeroRotVel(), 0, AirframePkg_aeroRotVel_aeroRotVel_SERIALIZE, OMAnimatedaeroRotVelType);
    setThread(p_thread, FALSE);
    //#[ operation aeroRotVel() 
    Units u(uANGULAR_VELOCITY);
    units=u;
    //#]
}

template <class T> aeroRotVel<T> ::aeroRotVel(OnStlVec<T> src, OMThread*  p_thread) : OnStlVec<T>(VEC_SIZE)
   {
    NOTIFY_REACTIVE_CONSTRUCTOR_T(aeroRotVel, aeroRotVel(OnStlVec<T> ), 0, OM_AirframePkg_aeroRotVel_aeroRotVel_1_SERIALIZE, OMAnimatedaeroRotVelType);
    setThread(p_thread, FALSE);
    //#[ operation aeroRotVel(OnStlVec<T> ) 
    for(int i=0;i<size();i++)
      (*this)[i]=src[i];
    //#]
}

template <class T> aeroRotVel<T> ::~aeroRotVel() {
    NOTIFY_DESTRUCTOR(~aeroRotVel, TRUE);
}

template <class T> OnPhysicalType aeroRotVel<T> ::GetPhysicalType() {
    NOTIFY_OPERATION(GetPhysicalType, GetPhysicalType(), 0, AirframePkg_aeroRotVel_GetPhysicalType_SERIALIZE);
    //#[ operation GetPhysicalType() 
    return OnPhysicalType_Equal;
    //#]
}

template <class T> void aeroRotVel<T> ::operator=(OnStlVec<T> src) {
    NOTIFY_OPERATION(operator=, operator=(OnStlVec<T> ), 0, AirframePkg_aeroRotVel_operator_SERIALIZE);
    //#[ operation operator=(OnStlVec<T> ) 
    if(size()==src.size()) for(int i=0;i<size();i++)(*this)[i]=src[i];
    //#]
}

template <class T> Units* aeroRotVel<T> ::getUnits() const {
    return (Units*) &units;
}

template <class T> OMBoolean aeroRotVel<T> ::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}







#ifdef _OMINSTRUMENT

DECLARE_META_PREFIX(aeroRotVel)

//## ignore 
template <class T> class OMAnimatedaeroRotVel : virtual public AOMInstance {
public :
    
        
        typedef aeroRotVel<T> OMaeroRotVelType;
        
    

    
    DECLARE_REACTIVE_META_T(aeroRotVel, OMaeroRotVelType, OMAnimatedaeroRotVel)
//## ignore 


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};



template <class T> void OMAnimatedaeroRotVel<T> ::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("units", TRUE, TRUE);
    if((Units*) &myReal->units)
        aomsRelations->ADD_ITEM((Units*) &myReal->units);
}






#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\aeroRotVel.h
*********************************************************************/

