/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: TransmissionControlModels
//!	Generated Date	: Sun, 19, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\TransmissionControlModels.h
*********************************************************************/


#ifndef TransmissionControlModels_H 

#define TransmissionControlModels_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <oxf/event.h>
#include "stdafx.h"

//## package TransmissionControlModels 


//#[ ignore 
#define manualNeutralShift_TransmissionControlModels_id 19001


#define manualReverseShift_TransmissionControlModels_id 19002


#define manualForwardShift_TransmissionControlModels_id 19003


#define upshift_TransmissionControlModels_id 19004


#define downshift_TransmissionControlModels_id 19005


#define tic_TransmissionControlModels_id 19006


#define shift_TransmissionControlModels_id 19007
//#]

//----------------------------------------------------------------------------
// TransmissionControlModels.h                                                                  
//----------------------------------------------------------------------------
class Clutch_Schedule;
class Controller;
class GearInfo;
class ShiftData;
class downshift;
class manualForwardShift;
class manualNeutralShift;
class manualReverseShift;

#ifdef _OMINSTRUMENT
class OMAnimateddownshift;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedmanualForwardShift;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedmanualNeutralShift;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedmanualReverseShift;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedshift;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedtic;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedupshift;
#endif // _OMINSTRUMENT
class shift;
class tic;
class upshift;


template <class A> class COnBroadcaster;
class COnEventBroadcaster;
//#[ ignore 
typedef COnBroadcaster<long> Port_Int;
//#]


//## event manualNeutralShift() 
class manualNeutralShift : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedmanualNeutralShift;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    manualNeutralShift();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedmanualNeutralShift : virtual public AOMEvent {

    
    DECLARE_META_EVENT(manualNeutralShift)


};

#endif // _OMINSTRUMENT
//## event manualReverseShift() 
class manualReverseShift : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedmanualReverseShift;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    manualReverseShift();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedmanualReverseShift : virtual public AOMEvent {

    
    DECLARE_META_EVENT(manualReverseShift)


};

#endif // _OMINSTRUMENT
//## event manualForwardShift() 
class manualForwardShift : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedmanualForwardShift;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    manualForwardShift();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedmanualForwardShift : virtual public AOMEvent {

    
    DECLARE_META_EVENT(manualForwardShift)


};

#endif // _OMINSTRUMENT
//## event upshift() 
class upshift : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedupshift;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    upshift();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedupshift : virtual public AOMEvent {

    
    DECLARE_META_EVENT(upshift)


};

#endif // _OMINSTRUMENT
//## event downshift() 
class downshift : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimateddownshift;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    downshift();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimateddownshift : virtual public AOMEvent {

    
    DECLARE_META_EVENT(downshift)


};

#endif // _OMINSTRUMENT
//## event tic() 
class tic : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedtic;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    tic();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedtic : virtual public AOMEvent {

    
    DECLARE_META_EVENT(tic)


};

#endif // _OMINSTRUMENT
//## event shift() 
class shift : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedshift;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    shift();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedshift : virtual public AOMEvent {

    
    DECLARE_META_EVENT(shift)


};

#endif // _OMINSTRUMENT


#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\TransmissionControlModels.h
*********************************************************************/

