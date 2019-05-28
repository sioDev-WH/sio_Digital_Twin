/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: UI
//!	Generated Date	: Tue, 21, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\UI.h
*********************************************************************/


#ifndef UI_H 

#define UI_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <oxf/event.h>
#include "stdafx.h"

//## package UI 


//#[ ignore 
#define evDriverTick_UI_id 801
//#]

//----------------------------------------------------------------------------
// UI.h                                                                  
//----------------------------------------------------------------------------
class Driver;
class evDriverTick;

#ifdef _OMINSTRUMENT
class OMAnimatedevDriverTick;
#endif // _OMINSTRUMENT


template <class A> class COnBroadcaster;//#[ ignore 
typedef COnBroadcaster<long> Port_Int;

typedef COnBroadcaster<double> Port_Double;
//#]


//## event evDriverTick() 
class evDriverTick : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedevDriverTick;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    evDriverTick();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedevDriverTick : virtual public AOMEvent {

    
    DECLARE_META_EVENT(evDriverTick)


};

#endif // _OMINSTRUMENT


#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\UI.h
*********************************************************************/

