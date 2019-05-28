/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: AvionicsPkg
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\AvionicsPkg.h
*********************************************************************/


#ifndef AvionicsPkg_H 

#define AvionicsPkg_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <oxf/event.h>
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
class evEnter;
class evExit;
class evGustWindTick;


//#[ ignore 
// Stors current index search resukts to speedup searching for next index Re-search.
typedef struct _ScheduleHistory{
		int index[3]; // stores current index for speedup search
		double lambda[3];// stores current fractions for speedup search
		int bStatus[3];// tores current status for error detection
		int bReSearch[3];// stores current flags for speedup search	
} ScheduleHistory;
//#]


//## event evGustWindTick() 
class evGustWindTick : public OMEvent {


////    Constructors and destructors    ////
public :
    
    evGustWindTick();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};

//## event evEnter() 
class evEnter : public OMEvent {


////    Constructors and destructors    ////
public :
    
    evEnter();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};

//## event evExit() 
class evExit : public OMEvent {


////    Constructors and destructors    ////
public :
    
    evExit();


////    Framework operations    ////
public :
    
    OMBoolean isTypeOf(short  id) const;


};



#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\AvionicsPkg.h
*********************************************************************/

