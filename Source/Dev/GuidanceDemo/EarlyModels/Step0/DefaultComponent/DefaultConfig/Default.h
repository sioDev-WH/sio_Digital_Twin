/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Default
//!	Generated Date	: Fri, 20, Dec 2002  
	File Path	: DefaultComponent\DefaultConfig\Default.h
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


#define evTargetLost_Default_id 18604
//#]

//----------------------------------------------------------------------------
// Default.h                                                                  
//----------------------------------------------------------------------------
class Guidance;
class myFactory;
class evDetonate;
class evTargetAcquired;
class evTargetLost;
class evTimeout;

#ifdef _OMINSTRUMENT
class OMAnimatedevDetonate;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedevTargetAcquired;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedevTargetLost;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedevTimeout;
#endif // _OMINSTRUMENT



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
//## event evTargetLost() 
class evTargetLost : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedevTargetLost;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    evTargetLost();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedevTargetLost : virtual public AOMEvent {

    
    DECLARE_META_EVENT(evTargetLost)


};

#endif // _OMINSTRUMENT


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Default.h
*********************************************************************/

