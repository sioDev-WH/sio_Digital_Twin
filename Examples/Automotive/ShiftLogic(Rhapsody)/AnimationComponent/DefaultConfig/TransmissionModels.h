/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: TransmissionModels
//!	Generated Date	: Fri, 3, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\TransmissionModels.h
*********************************************************************/


#ifndef TransmissionModels_H 

#define TransmissionModels_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <oxf/event.h>
#include "stdafx.h"

//## package TransmissionModels 


//#[ ignore 
#define es_SlipToLock_TransmissionModels_id 18201


#define es_LockTocSlip_TransmissionModels_id 18202


#define es_LockToccSlip_TransmissionModels_id 18203


#define ec_Engage_TransmissionModels_id 18204


#define ec_Disengage_TransmissionModels_id 18205


#define es_Start_TransmissionModels_id 18206


#define es_On_TransmissionModels_id 18207


#define es_Stop_TransmissionModels_id 18208


#define es_TMM_TransmissionModels_id 18209


#define es_FCM_TransmissionModels_id 18210


#define es_Lock_TransmissionModels_id 18211
//#]

//----------------------------------------------------------------------------
// TransmissionModels.h                                                                  
//----------------------------------------------------------------------------
class Actuator;
class ActuatorClutchConnector;
class Band_Brake;
class BrakeActuator;
class Clutch;
class ClutchBase;
class CRigidConnector;
class Engine;
class Gear;
class Oneway_Clutch;
class PlanetaryCoupler;
class Ravigneaux;
class Torque_Converter;
class ec_Disengage;
class ec_Engage;
class es_FCM;
class es_Lock;
class es_LockToccSlip;
class es_LockTocSlip;
class es_On;
class es_SlipToLock;
class es_Start;
class es_Stop;
class es_TMM;

#ifdef _OMINSTRUMENT
class OMAnimatedec_Disengage;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedec_Engage;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedes_FCM;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedes_Lock;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedes_LockToccSlip;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedes_LockTocSlip;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedes_On;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedes_SlipToLock;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedes_Start;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedes_Stop;
#endif // _OMINSTRUMENT

#ifdef _OMINSTRUMENT
class OMAnimatedes_TMM;
#endif // _OMINSTRUMENT


class Fdouble;//#[ ignore 
typedef double** ppdouble;

typedef Fdouble** ppfdouble;

typedef long** pplong;

typedef _TCHAR** ppchar;

typedef enum { Direction_COUNTERCLOCKWISE, Direction_CLOCKWISE} Direction;
//#]


//## event es_SlipToLock() 
class es_SlipToLock : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedes_SlipToLock;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    es_SlipToLock();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedes_SlipToLock : virtual public AOMEvent {

    
    DECLARE_META_EVENT(es_SlipToLock)


};

#endif // _OMINSTRUMENT
//## event es_LockTocSlip() 
class es_LockTocSlip : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedes_LockTocSlip;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    es_LockTocSlip();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedes_LockTocSlip : virtual public AOMEvent {

    
    DECLARE_META_EVENT(es_LockTocSlip)


};

#endif // _OMINSTRUMENT
//## event es_LockToccSlip() 
class es_LockToccSlip : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedes_LockToccSlip;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    es_LockToccSlip();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedes_LockToccSlip : virtual public AOMEvent {

    
    DECLARE_META_EVENT(es_LockToccSlip)


};

#endif // _OMINSTRUMENT
//## event ec_Engage() 
class ec_Engage : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedec_Engage;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    ec_Engage();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedec_Engage : virtual public AOMEvent {

    
    DECLARE_META_EVENT(ec_Engage)


};

#endif // _OMINSTRUMENT
//## event ec_Disengage() 
class ec_Disengage : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedec_Disengage;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    ec_Disengage();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedec_Disengage : virtual public AOMEvent {

    
    DECLARE_META_EVENT(ec_Disengage)


};

#endif // _OMINSTRUMENT
//## event es_Start() 
class es_Start : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedes_Start;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    es_Start();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedes_Start : virtual public AOMEvent {

    
    DECLARE_META_EVENT(es_Start)


};

#endif // _OMINSTRUMENT
//## event es_On() 
class es_On : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedes_On;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    es_On();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedes_On : virtual public AOMEvent {

    
    DECLARE_META_EVENT(es_On)


};

#endif // _OMINSTRUMENT
//## event es_Stop() 
class es_Stop : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedes_Stop;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    es_Stop();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedes_Stop : virtual public AOMEvent {

    
    DECLARE_META_EVENT(es_Stop)


};

#endif // _OMINSTRUMENT
//## event es_TMM() 
class es_TMM : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedes_TMM;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    es_TMM();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedes_TMM : virtual public AOMEvent {

    
    DECLARE_META_EVENT(es_TMM)


};

#endif // _OMINSTRUMENT
//## event es_FCM() 
class es_FCM : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedes_FCM;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    es_FCM();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedes_FCM : virtual public AOMEvent {

    
    DECLARE_META_EVENT(es_FCM)


};

#endif // _OMINSTRUMENT
//## event es_Lock() 
class es_Lock : public OMEvent {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedes_Lock;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    es_Lock();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedes_Lock : virtual public AOMEvent {

    
    DECLARE_META_EVENT(es_Lock)


};

#endif // _OMINSTRUMENT


#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\TransmissionModels.h
*********************************************************************/

