/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: GuidancePkg
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\GuidancePkg.h
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
#define evTargetAcquired_GuidancePkg_id 18601


#define evDetonate_GuidancePkg_id 18602


#define evTimeout_GuidancePkg_id 18603


#define evTargetLost_GuidancePkg_id 18604


#define evGuidanceTick_GuidancePkg_id 18605


#define evRadarTick_GuidancePkg_id 18606
//#]

//----------------------------------------------------------------------------
// GuidancePkg.h                                                                  
//----------------------------------------------------------------------------
class EstimatorLOS;
class EstimatorLOSCoeff;
class EstimatorVc;
class EstimatorVcCoeff;
class GuidanceLogic;
class evDetonate;
class evGuidanceTick;
class evRadarTick;
class evTargetAcquired;
class evTargetLost;
class evTimeout;



//## event evTargetAcquired() 
class evTargetAcquired : public OMEvent {


////    Constructors and destructors    ////
public :
    
    evTargetAcquired();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};

//## event evDetonate() 
class evDetonate : public OMEvent {


////    Constructors and destructors    ////
public :
    
    evDetonate();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};

//## event evTimeout() 
class evTimeout : public OMEvent {


////    Constructors and destructors    ////
public :
    
    evTimeout();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};

//## event evTargetLost() 
class evTargetLost : public OMEvent {


////    Constructors and destructors    ////
public :
    
    evTargetLost();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};

//## event evGuidanceTick() 
class evGuidanceTick : public OMEvent {


////    Constructors and destructors    ////
public :
    
    evGuidanceTick();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};

//## event evRadarTick() 
class evRadarTick : public OMEvent {


////    Constructors and destructors    ////
public :
    
    evRadarTick();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};



#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\GuidancePkg.h
*********************************************************************/

