/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: AvionicsPkg
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\AvionicsPkg.h
*********************************************************************/


#ifndef AvionicsPkg_H 

#define AvionicsPkg_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include <oxf/event.h>
#include "LibraryPkg.h"
#include <math.h>

//## package LibraryPkg::AvionicsPkg 


//#[ ignore 
#define evGustWindTick_AvionicsPkg_LibraryPkg_id 201


#define evEnter_AvionicsPkg_LibraryPkg_id 202


#define evExit_AvionicsPkg_LibraryPkg_id 203
//#]

//----------------------------------------------------------------------------
// AvionicsPkg.h                                                                  
//----------------------------------------------------------------------------
class ControlDesigner;
class crossProduct;
class dotProduct;
class ScheduledController_1D;
class ScheduledController_1D_Coeff;
class transformAngle_DMC2Euler;
class transformAngle_Euler2Quaternion;
class transformAngleRate;
class transformPosition_B2I;
class transformPosition_I2B;
class WindGust;
class evEnter;
class evExit;
class evGustWindTick;

#ifdef _OMINSTRUMENT
class OMAnimatedevEnter;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedevExit;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedevGustWindTick;
#endif // _OMINSTRUMENT



//## event evGustWindTick() 
class evGustWindTick : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedevGustWindTick;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    evGustWindTick();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedevGustWindTick : virtual public AOMEvent {

    
    DECLARE_META_EVENT(evGustWindTick)


};

#endif // _OMINSTRUMENT
//## event evEnter() 
class evEnter : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedevEnter;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    evEnter();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedevEnter : virtual public AOMEvent {

    
    DECLARE_META_EVENT(evEnter)


};

#endif // _OMINSTRUMENT
//## event evExit() 
class evExit : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedevExit;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    evExit();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedevExit : virtual public AOMEvent {

    
    DECLARE_META_EVENT(evExit)


};

#endif // _OMINSTRUMENT


#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\AvionicsPkg.h
*********************************************************************/

