/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: AppAirFrame
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\AppAirFrame.h
*********************************************************************/


#ifndef AppAirFrame_H 

#define AppAirFrame_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "Default.h"
#include "OnUMLEso.h"
#include "fstream.h"
#include "OnSubsystemBase.h"
#include "aeroComposition.h"

//## package Default 

//----------------------------------------------------------------------------
// AppAirFrame.h                                                                  
//----------------------------------------------------------------------------

//## class AppAirFrame 
class AppAirFrame : public COnSubsystemBase<aeroComposition> {


////    Constructors and destructors    ////
public :
    
    //## auto_generated 
    AppAirFrame();
    
    //## auto_generated 
    ~AppAirFrame();


////    Operations    ////
public :
    
    //## operation Load(const BSTR) 
    bool Load(const BSTR  filename);
    
    //## operation Save(const BSTR) 
    void Save(const BSTR  filename);
    
    //## operation clean() 
    void clean();
    
    //## operation init() 
    void init();


};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\AppAirFrame.h
*********************************************************************/

