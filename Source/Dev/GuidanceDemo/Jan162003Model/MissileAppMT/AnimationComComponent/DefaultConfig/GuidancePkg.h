/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: GuidancePkg
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\GuidancePkg.h
*********************************************************************/


#ifndef GuidancePkg_H 

#define GuidancePkg_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include <oxf/event.h>

//## package GuidancePkg 


//#[ ignore 
#define evTargetAcquired_GuidancePkg_id 18601


#define evDetonate_GuidancePkg_id 18602


#define evTimeout_GuidancePkg_id 18603


#define evTargetLost_GuidancePkg_id 18604


#define evGuidanceTick_GuidancePkg_id 18605
//#]

//----------------------------------------------------------------------------
// GuidancePkg.h                                                                  
//----------------------------------------------------------------------------
class GuidanceLogic;
class evDetonate;
class evGuidanceTick;
class evTargetAcquired;
class evTargetLost;
class evTimeout;

#ifdef _OMINSTRUMENT
class OMAnimatedevDetonate;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedevGuidanceTick;
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
//## event evGuidanceTick() 
class evGuidanceTick : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedevGuidanceTick;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    evGuidanceTick();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedevGuidanceTick : virtual public AOMEvent {

    
    DECLARE_META_EVENT(evGuidanceTick)


};

#endif // _OMINSTRUMENT


#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\GuidancePkg.h
*********************************************************************/

