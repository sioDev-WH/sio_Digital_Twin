/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: aeroPos
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\aeroPos.h
*********************************************************************/


#ifndef aeroPos_H 

#define aeroPos_H 


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
#define AirframePkg_aeroPos_aeroPos_SERIALIZE OM_NO_OP


#define OM_AirframePkg_aeroPos_aeroPos_1_SERIALIZE OM_NO_OP


#define AirframePkg_aeroPos_GetPhysicalType_SERIALIZE OM_NO_OP


#define AirframePkg_aeroPos_operator_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// aeroPos.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
template <class  T> class OMAnimatedaeroPos;
#endif // _OMINSTRUMENT


//## class aeroPos 
template <class T> class aeroPos : public OMReactive, public OnStlVec<T> {
public :
    
        
        
    #ifdef _OMINSTRUMENT
        //## ignore 
        typedef OMAnimatedaeroPos<T> OMAnimatedaeroPosType;
        
    #endif // _OMINSTRUMENT
    
//## class aeroPos 


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedaeroPos<T> ;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation aeroPos() 
    aeroPos(OMThread*  p_thread = OMDefaultThread);
    
    //## operation aeroPos(OnStlVec<T> ) 
    aeroPos(OnStlVec<T> src, OMThread*  p_thread = OMDefaultThread);
    
    //## auto_generated 
    virtual ~aeroPos();


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

//## class aeroPos 



template <class T> aeroPos<T> ::aeroPos(OMThread*  p_thread) : OnStlVec<T>(VEC_SIZE)
   {
    NOTIFY_REACTIVE_CONSTRUCTOR_T(aeroPos, aeroPos(), 0, AirframePkg_aeroPos_aeroPos_SERIALIZE, OMAnimatedaeroPosType);
    setThread(p_thread, FALSE);
    //#[ operation aeroPos() 
    Units u(uLENGTH);
    units=u;
    //#]
}

template <class T> aeroPos<T> ::aeroPos(OnStlVec<T> src, OMThread*  p_thread) : OnStlVec<T>(VEC_SIZE)
   {
    NOTIFY_REACTIVE_CONSTRUCTOR_T(aeroPos, aeroPos(OnStlVec<T> ), 0, OM_AirframePkg_aeroPos_aeroPos_1_SERIALIZE, OMAnimatedaeroPosType);
    setThread(p_thread, FALSE);
    //#[ operation aeroPos(OnStlVec<T> ) 
    for(int i=0;i<size();i++)
      (*this)[i]=src[i];
    //#]
}

template <class T> aeroPos<T> ::~aeroPos() {
    NOTIFY_DESTRUCTOR(~aeroPos, TRUE);
}

template <class T> OnPhysicalType aeroPos<T> ::GetPhysicalType() {
    NOTIFY_OPERATION(GetPhysicalType, GetPhysicalType(), 0, AirframePkg_aeroPos_GetPhysicalType_SERIALIZE);
    //#[ operation GetPhysicalType() 
    return OnPhysicalType_Equal;
    //#]
}

template <class T> void aeroPos<T> ::operator=(OnStlVec<T> src) {
    NOTIFY_OPERATION(operator=, operator=(OnStlVec<T> ), 0, AirframePkg_aeroPos_operator_SERIALIZE);
    //#[ operation operator=(OnStlVec<T> ) 
    if(size()==src.size()) 
      for(int i=0;i<size();i++)(*this)[i]=src[i];
    //#]
}

template <class T> Units* aeroPos<T> ::getUnits() const {
    return (Units*) &units;
}

template <class T> OMBoolean aeroPos<T> ::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}







#ifdef _OMINSTRUMENT

DECLARE_META_PREFIX(aeroPos)

//## ignore 
template <class T> class OMAnimatedaeroPos : virtual public AOMInstance {
public :
    
        
        typedef aeroPos<T> OMaeroPosType;
        
    

    
    DECLARE_REACTIVE_META_T(aeroPos, OMaeroPosType, OMAnimatedaeroPos)
//## ignore 


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};



template <class T> void OMAnimatedaeroPos<T> ::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("units", TRUE, TRUE);
    if((Units*) &myReal->units)
        aomsRelations->ADD_ITEM((Units*) &myReal->units);
}






#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\aeroPos.h
*********************************************************************/

