/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: AutopilotPkg
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\AutopilotPkg.h
*********************************************************************/


#ifndef AutopilotPkg_H 

#define AutopilotPkg_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
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


//#[ ignore 
#define d2r 0.017453292519943295769236907684886
//#]


//## event evAutoPilotTick() 
class evAutoPilotTick : public OMEvent {


////    Constructors and destructors    ////
public :
    
    evAutoPilotTick();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};



#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\AutopilotPkg.h
*********************************************************************/

