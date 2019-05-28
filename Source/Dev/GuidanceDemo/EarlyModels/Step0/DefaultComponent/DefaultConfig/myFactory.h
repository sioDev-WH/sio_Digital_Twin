/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: myFactory
//!	Generated Date	: Thu, 19, Dec 2002  
	File Path	: DefaultComponent\DefaultConfig\myFactory.h
*********************************************************************/


#ifndef myFactory_H 

#define myFactory_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "Default.h"

//## package Default 

//----------------------------------------------------------------------------
// myFactory.h                                                                  
//----------------------------------------------------------------------------
class Guidance;

#ifdef _OMINSTRUMENT
class OMAnimatedmyFactory;
#endif // _OMINSTRUMENT


//## class myFactory 
class myFactory  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedmyFactory;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## auto_generated 
    myFactory();
    
    //## auto_generated 
    ~myFactory();


////    Additional operations    ////
public :
    
    //## auto_generated 
    Guidance* getItsGuidance() const;
    
    //## auto_generated 
    void setItsGuidance(Guidance*  p_Guidance);


////    Framework operations    ////
public :
    
    //## auto_generated 
    void __setItsGuidance(Guidance*  p_Guidance);
    
    //## auto_generated 
    void _setItsGuidance(Guidance*  p_Guidance);
    
    //## auto_generated 
    void _clearItsGuidance();

protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Relations and components    ////
protected :
    
    Guidance* itsGuidance;		//## link itsGuidance 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedmyFactory : virtual public AOMInstance {

    
    DECLARE_META(myFactory, OMAnimatedmyFactory)


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\myFactory.h
*********************************************************************/

