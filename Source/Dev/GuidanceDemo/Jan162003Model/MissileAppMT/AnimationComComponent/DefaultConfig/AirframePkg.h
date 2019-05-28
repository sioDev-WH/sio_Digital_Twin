/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: AirframePkg
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\AirframePkg.h
*********************************************************************/


#ifndef AirframePkg_H 

#define AirframePkg_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include <oxf/event.h>
#include "stdafx.h"
#include "units.h"

//## package AirframePkg 


//#[ ignore 
#define evRun_AirframePkg_id 6001
//#]

//----------------------------------------------------------------------------
// AirframePkg.h                                                                  
//----------------------------------------------------------------------------
class AeroCoeff;
class AeroDynamics;
class AtmoCoeff;
class Atmosphere;
class BodyDynamics;
class BodyDynamicsCoeff;
class FinActuator;
class FinActuatorCoeff;
class On1DConn;
class On3DConn;
class evRun;


//#[ ignore 
#define d2r 0.017453292519943295769236907684886

#define Kg2slug 0.0685218

#define m2ft 3.280840

#define PI 3.1415926535897932384626433832795

typedef _TCHAR * * ppchar;

typedef double * * ppdouble;

typedef long * * pplong;
//#]


//## event evRun() 
class evRun : public OMEvent {


////    Constructors and destructors    ////
public :
    
    evRun();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};



#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\AirframePkg.h
*********************************************************************/

