/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Default
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\Default.h
*********************************************************************/


#ifndef Default_H 

#define Default_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <oxf/event.h>
#include "stdafx.h"

//## package Default 

//----------------------------------------------------------------------------
// Default.h                                                                  
//----------------------------------------------------------------------------
class App;
class App_task_0001ms;
class App_task_0010ms;
class App_task_0040ms;
class AppAirFrame;

#define evTick_Default_id 30001

//## event evTick() 
class evTick : public OMEvent {

////    Friends    ////
public :

////    Constructors and destructors    ////
public :
    
    evTick();

////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};



#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Default.h
*********************************************************************/

