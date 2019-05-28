/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: aeroDensity
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\aeroDensity.h
*********************************************************************/


#ifndef aeroDensity_H 

#define aeroDensity_H 


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
#define AirframePkg_aeroDensity_aeroDensity_SERIALIZE OM_NO_OP


#define OM_AirframePkg_aeroDensity_aeroDensity_1_SERIALIZE OM_NO_OP


#define AirframePkg_aeroDensity_GetPhysicalType_SERIALIZE OM_NO_OP


#define AirframePkg_aeroDensity_operator_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// aeroDensity.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
template <class  T> class OMAnimatedaeroDensity;
#endif // _OMINSTRUMENT


//## class aeroDensity 
template <class T> class aeroDensity : public OMReactive, public OnStlVec<T> {
public :
    
        
        
    #ifdef _OMINSTRUMENT
        //## ignore 
        typedef OMAnimatedaeroDensity<T> OMAnimatedaeroDensityType;
        
    #endif // _OMINSTRUMENT
    
//## class aeroDensity 


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedaeroDensity<T> ;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation aeroDensity() 
    aeroDensity(OMThread*  p_thread = OMDefaultThread);
    
    //## operation aeroDensity(OnStlVec<T> ) 
    aeroDensity(OnStlVec<T> src, OMThread*  p_thread = OMDefaultThread);
    
    //## auto_generated 
    virtual ~aeroDensity();


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

//## class aeroDensity 



template <class T> aeroDensity<T> ::aeroDensity(OMThread*  p_thread) : OnStlVec<T>(1)
   {
    NOTIFY_REACTIVE_CONSTRUCTOR_T(aeroDensity, aeroDensity(), 0, AirframePkg_aeroDensity_aeroDensity_SERIALIZE, OMAnimatedaeroDensityType);
    setThread(p_thread, FALSE);
    //#[ operation aeroDensity() 
    
       Units u(uDENSITY); 
       units=u;
    //#]
}

template <class T> aeroDensity<T> ::aeroDensity(OnStlVec<T> src, OMThread*  p_thread) : OnStlVec<T>(1)
   {
    NOTIFY_REACTIVE_CONSTRUCTOR_T(aeroDensity, aeroDensity(OnStlVec<T> ), 0, OM_AirframePkg_aeroDensity_aeroDensity_1_SERIALIZE, OMAnimatedaeroDensityType);
    setThread(p_thread, FALSE);
    //#[ operation aeroDensity(OnStlVec<T> ) 
    for(int i=0;i<size();i++)
      (*this)[i]=src[i];
    //#]
}

template <class T> aeroDensity<T> ::~aeroDensity() {
    NOTIFY_DESTRUCTOR(~aeroDensity, TRUE);
}

template <class T> OnPhysicalType aeroDensity<T> ::GetPhysicalType() {
    NOTIFY_OPERATION(GetPhysicalType, GetPhysicalType(), 0, AirframePkg_aeroDensity_GetPhysicalType_SERIALIZE);
    //#[ operation GetPhysicalType() 
    return OnPhysicalType_Equal;
    //#]
}

template <class T> void aeroDensity<T> ::operator=(OnStlVec<T> src) {
    NOTIFY_OPERATION(operator=, operator=(OnStlVec<T> ), 0, AirframePkg_aeroDensity_operator_SERIALIZE);
    //#[ operation operator=(OnStlVec<T> ) 
    if(size()==src.size()) for(int i=0;i<size();i++)(*this)[i]=src[i];
    //#]
}

template <class T> Units* aeroDensity<T> ::getUnits() const {
    return (Units*) &units;
}

template <class T> OMBoolean aeroDensity<T> ::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}







#ifdef _OMINSTRUMENT

DECLARE_META_PREFIX(aeroDensity)

//## ignore 
template <class T> class OMAnimatedaeroDensity : virtual public AOMInstance {
public :
    
        
        typedef aeroDensity<T> OMaeroDensityType;
        
    

    
    DECLARE_REACTIVE_META_T(aeroDensity, OMaeroDensityType, OMAnimatedaeroDensity)
//## ignore 


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};



template <class T> void OMAnimatedaeroDensity<T> ::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("units", TRUE, TRUE);
    if((Units*) &myReal->units)
        aomsRelations->ADD_ITEM((Units*) &myReal->units);
}






#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\aeroDensity.h
*********************************************************************/

