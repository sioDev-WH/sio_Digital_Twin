/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: AutopilotPkg
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\AutopilotPkg.h
*********************************************************************/


#ifndef AutopilotPkg_H 

#define AutopilotPkg_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include <oxf/event.h>

//## package AutopilotPkg 


//#[ ignore 
#define evAutoPilotTick_AutopilotPkg_id 11201
//#]

//----------------------------------------------------------------------------
// AutopilotPkg.h                                                                  
//----------------------------------------------------------------------------
class AutoPilot;
class AutoPilotCoeff;
class evAutoPilotTick;

#ifdef _OMINSTRUMENT
class OMAnimatedevAutoPilotTick;
#endif // _OMINSTRUMENT


//#[ ignore 
#define d2r 0.017453292519943295769236907684886
//#]


//## event evAutoPilotTick() 
class evAutoPilotTick : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedevAutoPilotTick;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    evAutoPilotTick();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedevAutoPilotTick : virtual public AOMEvent {

    
    DECLARE_META_EVENT(evAutoPilotTick)


};

#endif // _OMINSTRUMENT


#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\AutopilotPkg.h
*********************************************************************/

