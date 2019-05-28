/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: aeroAcc
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\aeroAcc.h
*********************************************************************/


#ifndef aeroAcc_H 

#define aeroAcc_H 


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
#define AirframePkg_aeroAcc_aeroAcc_SERIALIZE OM_NO_OP


#define OM_AirframePkg_aeroAcc_aeroAcc_1_SERIALIZE OM_NO_OP


#define AirframePkg_aeroAcc_GetPhysicalType_SERIALIZE OM_NO_OP


#define AirframePkg_aeroAcc_operator_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// aeroAcc.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
template <class  T> class OMAnimatedaeroAcc;
#endif // _OMINSTRUMENT


//## class aeroAcc 
template <class T> class aeroAcc : public OMReactive, public OnStlVec<T> {
public :
    
        
        
    #ifdef _OMINSTRUMENT
        //## ignore 
        typedef OMAnimatedaeroAcc<T> OMAnimatedaeroAccType;
        
    #endif // _OMINSTRUMENT
    
//## class aeroAcc 


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedaeroAcc<T> ;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation aeroAcc() 
    aeroAcc(OMThread*  p_thread = OMDefaultThread);
    
    //## operation aeroAcc(OnStlVec<T> ) 
    aeroAcc(OnStlVec<T> src, OMThread*  p_thread = OMDefaultThread);
    
    //## auto_generated 
    virtual ~aeroAcc();


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

//## class aeroAcc 



template <class T> aeroAcc<T> ::aeroAcc(OMThread*  p_thread) : OnStlVec<T>(VEC_SIZE)
   {
    NOTIFY_REACTIVE_CONSTRUCTOR_T(aeroAcc, aeroAcc(), 0, AirframePkg_aeroAcc_aeroAcc_SERIALIZE, OMAnimatedaeroAccType);
    setThread(p_thread, FALSE);
    //#[ operation aeroAcc() 
    Units u(uACCELERATION); 
    units=u;
    //#]
}

template <class T> aeroAcc<T> ::aeroAcc(OnStlVec<T> src, OMThread*  p_thread) : OnStlVec<T>(VEC_SIZE)
   {
    NOTIFY_REACTIVE_CONSTRUCTOR_T(aeroAcc, aeroAcc(OnStlVec<T> ), 0, OM_AirframePkg_aeroAcc_aeroAcc_1_SERIALIZE, OMAnimatedaeroAccType);
    setThread(p_thread, FALSE);
    //#[ operation aeroAcc(OnStlVec<T> ) 
    
       for(int i=0;i<size();i++)
         (*this)[i]=src[i];
    //#]
}

template <class T> aeroAcc<T> ::~aeroAcc() {
    NOTIFY_DESTRUCTOR(~aeroAcc, TRUE);
}

template <class T> OnPhysicalType aeroAcc<T> ::GetPhysicalType() {
    NOTIFY_OPERATION(GetPhysicalType, GetPhysicalType(), 0, AirframePkg_aeroAcc_GetPhysicalType_SERIALIZE);
    //#[ operation GetPhysicalType() 
    return OnPhysicalType_Equal;
    //#]
}

template <class T> void aeroAcc<T> ::operator=(OnStlVec<T> src) {
    NOTIFY_OPERATION(operator=, operator=(OnStlVec<T> ), 0, AirframePkg_aeroAcc_operator_SERIALIZE);
    //#[ operation operator=(OnStlVec<T> ) 
    if(size()==src.size()) for(int i=0;i<size();i++)(*this)[i]=src[i];
    //#]
}

template <class T> Units* aeroAcc<T> ::getUnits() const {
    return (Units*) &units;
}

template <class T> OMBoolean aeroAcc<T> ::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}







#ifdef _OMINSTRUMENT

DECLARE_META_PREFIX(aeroAcc)

//## ignore 
template <class T> class OMAnimatedaeroAcc : virtual public AOMInstance {
public :
    
        
        typedef aeroAcc<T> OMaeroAccType;
        
    

    
    DECLARE_REACTIVE_META_T(aeroAcc, OMaeroAccType, OMAnimatedaeroAcc)
//## ignore 


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};



template <class T> void OMAnimatedaeroAcc<T> ::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("units", TRUE, TRUE);
    if((Units*) &myReal->units)
        aomsRelations->ADD_ITEM((Units*) &myReal->units);
}






#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\aeroAcc.h
*********************************************************************/

