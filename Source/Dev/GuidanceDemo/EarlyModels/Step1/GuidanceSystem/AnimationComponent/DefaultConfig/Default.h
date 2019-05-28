/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Default
//!	Generated Date	: Mon, 9, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\Default.h
*********************************************************************/


#ifndef Default_H 

#define Default_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <oxf/event.h>

//## package Default 


//#[ ignore 
#define evTargetAcquired_Default_id 18601


#define evDetonate_Default_id 18602


#define evTimeout_Default_id 18603
//#]

//----------------------------------------------------------------------------
// Default.h                                                                  
//----------------------------------------------------------------------------
template <class  T> class COnUMLConnectorImpl;
template <class  T> class COnUMLDaeEsoImpl;
class evDetonate;
class evTargetAcquired;
class evTimeout;

#ifdef _OMINSTRUMENT
class OMAnimatedevDetonate;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedevTargetAcquired;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedevTimeout;
#endif // _OMINSTRUMENT


//#[ ignore 
//#]


//## event evTargetAcquired() 
class evTargetAcquired : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedevTargetAcquired;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    evTargetAcquired();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedevTargetAcquired : virtual public AOMEvent {

    
    DECLARE_META_EVENT(evTargetAcquired)


};

#endif // _OMINSTRUMENT
//## event evDetonate() 
class evDetonate : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedevDetonate;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    evDetonate();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedevDetonate : virtual public AOMEvent {

    
    DECLARE_META_EVENT(evDetonate)


};

#endif // _OMINSTRUMENT
//## event evTimeout() 
class evTimeout : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedevTimeout;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    evTimeout();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedevTimeout : virtual public AOMEvent {

    
    DECLARE_META_EVENT(evTimeout)


};

#endif // _OMINSTRUMENT


#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Default.h
*********************************************************************/

