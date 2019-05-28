/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: GuidancePkg
//!	Generated Date	: Tue, 10, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\GuidancePkg.h
*********************************************************************/


#ifndef GuidancePkg_H 

#define GuidancePkg_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <oxf/event.h>

//## package GuidancePkg 


//#[ ignore 
#define evRun_GuidancePkg_id 6001


#define evDetonate_GuidancePkg_id 6002


#define evTargetAcquired_GuidancePkg_id 6003


#define evTimeout_GuidancePkg_id 6004
//#]

//----------------------------------------------------------------------------
// GuidancePkg.h                                                                  
//----------------------------------------------------------------------------
class AeroCoeff;
class AeroDynamics;
class AirFrame;
class AirFrameAutoPilotSystem;
class AtmoCoeff;
class Atmosphere;
class AutoPilot;
class AutoPilotCoeff;
class BodyDynamics;
class BodyDynamicsCoeff;
class FinActuator;
class FinActuatorCoeff;
class Guidance;
class myFactory;
class On1DConn;
class On3DConn;
class evDetonate;
class evRun;
class evTargetAcquired;
class evTimeout;

#ifdef _OMINSTRUMENT
class OMAnimatedevDetonate;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedevRun;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedevTargetAcquired;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedevTimeout;
#endif // _OMINSTRUMENT


//#[ ignore 
#define d2r 0.017453292519943295769236907684886

#define Kg2slug 0.0685218

#define M 2

#define m2ft 3.280840

#define N 5

#define P 1

#define PI 3.1415926535897932384626433832795

typedef _TCHAR * * ppchar;

typedef double * * ppdouble;

typedef long * * pplong;
//#]


//## attribute A 
extern double A[];

//## attribute B 
extern double B[];

//## attribute C 
extern double C[5];

//## attribute D 
extern double D[2];

//## event evRun() 
class evRun : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedevRun;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    evRun();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedevRun : virtual public AOMEvent {

    
    DECLARE_META_EVENT(evRun)


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
	File Path	: AnimationComponent\DefaultConfig\GuidancePkg.h
*********************************************************************/

