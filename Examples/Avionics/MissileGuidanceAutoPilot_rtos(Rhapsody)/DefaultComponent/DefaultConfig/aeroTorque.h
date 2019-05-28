/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: aeroTorque
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\aeroTorque.h
*********************************************************************/


#ifndef aeroTorque_H 

#define aeroTorque_H 


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
#define AirframePkg_aeroTorque_aeroTorque_SERIALIZE OM_NO_OP


#define OM_AirframePkg_aeroTorque_aeroTorque_1_SERIALIZE OM_NO_OP


#define AirframePkg_aeroTorque_GetPhysicalType_SERIALIZE OM_NO_OP


#define AirframePkg_aeroTorque_operator_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// aeroTorque.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
template <class  T> class OMAnimatedaeroTorque;
#endif // _OMINSTRUMENT


//## class aeroTorque 
template <class T> class aeroTorque : public OMReactive, public OnStlVec<T> {
public :
    
        
        
    #ifdef _OMINSTRUMENT
        //## ignore 
        typedef OMAnimatedaeroTorque<T> OMAnimatedaeroTorqueType;
        
    #endif // _OMINSTRUMENT
    
//## class aeroTorque 


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedaeroTorque<T> ;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation aeroTorque() 
    aeroTorque(OMThread*  p_thread = OMDefaultThread);
    
    //## operation aeroTorque(OnStlVec<T> ) 
    aeroTorque(OnStlVec<T> src, OMThread*  p_thread = OMDefaultThread);
    
    //## auto_generated 
    virtual ~aeroTorque();


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

//## class aeroTorque 



template <class T> aeroTorque<T> ::aeroTorque(OMThread*  p_thread) : OnStlVec<T>(VEC_SIZE)
   {
    NOTIFY_REACTIVE_CONSTRUCTOR_T(aeroTorque, aeroTorque(), 0, AirframePkg_aeroTorque_aeroTorque_SERIALIZE, OMAnimatedaeroTorqueType);
    setThread(p_thread, FALSE);
    //#[ operation aeroTorque() 
    Units u(uTORQUE); 
    units=u;
    //#]
}

template <class T> aeroTorque<T> ::aeroTorque(OnStlVec<T> src, OMThread*  p_thread) : OnStlVec<T>(VEC_SIZE)
   {
    NOTIFY_REACTIVE_CONSTRUCTOR_T(aeroTorque, aeroTorque(OnStlVec<T> ), 0, OM_AirframePkg_aeroTorque_aeroTorque_1_SERIALIZE, OMAnimatedaeroTorqueType);
    setThread(p_thread, FALSE);
    //#[ operation aeroTorque(OnStlVec<T> ) 
    for(int i=0;i<size();i++) 
      (*this)[i]=src[i];
    //#]
}

template <class T> aeroTorque<T> ::~aeroTorque() {
    NOTIFY_DESTRUCTOR(~aeroTorque, TRUE);
}

template <class T> OnPhysicalType aeroTorque<T> ::GetPhysicalType() {
    NOTIFY_OPERATION(GetPhysicalType, GetPhysicalType(), 0, AirframePkg_aeroTorque_GetPhysicalType_SERIALIZE);
    //#[ operation GetPhysicalType() 
    return OnPhysicalType_Sum;
    //#]
}

template <class T> void aeroTorque<T> ::operator=(OnStlVec<T> src) {
    NOTIFY_OPERATION(operator=, operator=(OnStlVec<T> ), 0, AirframePkg_aeroTorque_operator_SERIALIZE);
    //#[ operation operator=(OnStlVec<T> ) 
    if(size()==src.size()) for(int i=0;i<size();i++)(*this)[i]=src[i];
    //#]
}

template <class T> Units* aeroTorque<T> ::getUnits() const {
    return (Units*) &units;
}

template <class T> OMBoolean aeroTorque<T> ::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}







#ifdef _OMINSTRUMENT

DECLARE_META_PREFIX(aeroTorque)

//## ignore 
template <class T> class OMAnimatedaeroTorque : virtual public AOMInstance {
public :
    
        
        typedef aeroTorque<T> OMaeroTorqueType;
        
    

    
    DECLARE_REACTIVE_META_T(aeroTorque, OMaeroTorqueType, OMAnimatedaeroTorque)
//## ignore 


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};



template <class T> void OMAnimatedaeroTorque<T> ::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("units", TRUE, TRUE);
    if((Units*) &myReal->units)
        aomsRelations->ADD_ITEM((Units*) &myReal->units);
}






#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\aeroTorque.h
*********************************************************************/

