/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: aeroRotAcc
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\aeroRotAcc.h
*********************************************************************/


#ifndef aeroRotAcc_H 

#define aeroRotAcc_H 


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
#define AirframePkg_aeroRotAcc_aeroRotAcc_SERIALIZE OM_NO_OP


#define OM_AirframePkg_aeroRotAcc_aeroRotAcc_1_SERIALIZE OM_NO_OP


#define AirframePkg_aeroRotAcc_GetPhysicalType_SERIALIZE OM_NO_OP


#define AirframePkg_aeroRotAcc_operator_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// aeroRotAcc.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
template <class  T> class OMAnimatedaeroRotAcc;
#endif // _OMINSTRUMENT


//## class aeroRotAcc 
template <class T> class aeroRotAcc : public OMReactive, public OnStlVec<T> {
public :
    
        
        
    #ifdef _OMINSTRUMENT
        //## ignore 
        typedef OMAnimatedaeroRotAcc<T> OMAnimatedaeroRotAccType;
        
    #endif // _OMINSTRUMENT
    
//## class aeroRotAcc 


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedaeroRotAcc<T> ;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation aeroRotAcc() 
    aeroRotAcc(OMThread*  p_thread = OMDefaultThread);
    
    //## operation aeroRotAcc(OnStlVec<T> ) 
    aeroRotAcc(OnStlVec<T> src, OMThread*  p_thread = OMDefaultThread);
    
    //## auto_generated 
    virtual ~aeroRotAcc();


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

//## class aeroRotAcc 



template <class T> aeroRotAcc<T> ::aeroRotAcc(OMThread*  p_thread) : OnStlVec<T>(VEC_SIZE)
   {
    NOTIFY_REACTIVE_CONSTRUCTOR_T(aeroRotAcc, aeroRotAcc(), 0, AirframePkg_aeroRotAcc_aeroRotAcc_SERIALIZE, OMAnimatedaeroRotAccType);
    setThread(p_thread, FALSE);
    //#[ operation aeroRotAcc() 
    Units u(uANGULAR_ACCELERATION);
    units=u;
    //#]
}

template <class T> aeroRotAcc<T> ::aeroRotAcc(OnStlVec<T> src, OMThread*  p_thread) : OnStlVec<T>(VEC_SIZE)
   {
    NOTIFY_REACTIVE_CONSTRUCTOR_T(aeroRotAcc, aeroRotAcc(OnStlVec<T> ), 0, OM_AirframePkg_aeroRotAcc_aeroRotAcc_1_SERIALIZE, OMAnimatedaeroRotAccType);
    setThread(p_thread, FALSE);
    //#[ operation aeroRotAcc(OnStlVec<T> ) 
    for(int i=0;i<size();i++)
      (*this)[i]=src[i];
    //#]
}

template <class T> aeroRotAcc<T> ::~aeroRotAcc() {
    NOTIFY_DESTRUCTOR(~aeroRotAcc, TRUE);
}

template <class T> OnPhysicalType aeroRotAcc<T> ::GetPhysicalType() {
    NOTIFY_OPERATION(GetPhysicalType, GetPhysicalType(), 0, AirframePkg_aeroRotAcc_GetPhysicalType_SERIALIZE);
    //#[ operation GetPhysicalType() 
    return OnPhysicalType_Equal;
    //#]
}

template <class T> void aeroRotAcc<T> ::operator=(OnStlVec<T> src) {
    NOTIFY_OPERATION(operator=, operator=(OnStlVec<T> ), 0, AirframePkg_aeroRotAcc_operator_SERIALIZE);
    //#[ operation operator=(OnStlVec<T> ) 
    if(size()==src.size()) for(int i=0;i<size();i++)(*this)[i]=src[i];
    //#]
}

template <class T> Units* aeroRotAcc<T> ::getUnits() const {
    return (Units*) &units;
}

template <class T> OMBoolean aeroRotAcc<T> ::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}







#ifdef _OMINSTRUMENT

DECLARE_META_PREFIX(aeroRotAcc)

//## ignore 
template <class T> class OMAnimatedaeroRotAcc : virtual public AOMInstance {
public :
    
        
        typedef aeroRotAcc<T> OMaeroRotAccType;
        
    

    
    DECLARE_REACTIVE_META_T(aeroRotAcc, OMaeroRotAccType, OMAnimatedaeroRotAcc)
//## ignore 


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};



template <class T> void OMAnimatedaeroRotAcc<T> ::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("units", TRUE, TRUE);
    if((Units*) &myReal->units)
        aomsRelations->ADD_ITEM((Units*) &myReal->units);
}






#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\aeroRotAcc.h
*********************************************************************/

