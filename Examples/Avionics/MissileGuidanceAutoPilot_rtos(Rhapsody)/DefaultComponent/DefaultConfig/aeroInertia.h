/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: aeroInertia
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\aeroInertia.h
*********************************************************************/


#ifndef aeroInertia_H 

#define aeroInertia_H 


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
#define AirframePkg_aeroInertia_aeroInertia_SERIALIZE OM_NO_OP
//#]

//----------------------------------------------------------------------------
// aeroInertia.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
template <class  T> class OMAnimatedaeroInertia;
#endif // _OMINSTRUMENT


//## class aeroInertia 
template <class T> class aeroInertia : public OMReactive, public matrix<T> {
public :
    
        
        
    #ifdef _OMINSTRUMENT
        //## ignore 
        typedef OMAnimatedaeroInertia<T> OMAnimatedaeroInertiaType;
        
    #endif // _OMINSTRUMENT
    
//## class aeroInertia 


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedaeroInertia<T> ;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation aeroInertia() 
    aeroInertia(OMThread*  p_thread = OMDefaultThread);
    
    //## auto_generated 
    ~aeroInertia();


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

//## class aeroInertia 



template <class T> aeroInertia<T> ::aeroInertia(OMThread*  p_thread) : Matrix(VEC_SIZE,VEC_SIZE)
   {
    NOTIFY_REACTIVE_CONSTRUCTOR_T(aeroInertia, aeroInertia(), 0, AirframePkg_aeroInertia_aeroInertia_SERIALIZE, OMAnimatedaeroInertiaType);
    setThread(p_thread, FALSE);
    //#[ operation aeroInertia() 
    Units u(uINERTIA); 
    units=u;
    //#]
}

template <class T> aeroInertia<T> ::~aeroInertia() {
    NOTIFY_DESTRUCTOR(~aeroInertia, TRUE);
}

template <class T> Units* aeroInertia<T> ::getUnits() const {
    return (Units*) &units;
}

template <class T> OMBoolean aeroInertia<T> ::startBehavior() {
    OMBoolean done = FALSE;
    done = OMReactive::startBehavior();
    return done;
}







#ifdef _OMINSTRUMENT

DECLARE_META_PREFIX(aeroInertia)

//## ignore 
template <class T> class OMAnimatedaeroInertia : virtual public AOMInstance {
public :
    
        
        typedef aeroInertia<T> OMaeroInertiaType;
        
    

    
    DECLARE_REACTIVE_META_T(aeroInertia, OMaeroInertiaType, OMAnimatedaeroInertia)
//## ignore 


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};



template <class T> void OMAnimatedaeroInertia<T> ::serializeRelations(AOMSRelations*  aomsRelations) const {
    aomsRelations->addRelation("units", TRUE, TRUE);
    if((Units*) &myReal->units)
        aomsRelations->ADD_ITEM((Units*) &myReal->units);
}






#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\aeroInertia.h
*********************************************************************/

