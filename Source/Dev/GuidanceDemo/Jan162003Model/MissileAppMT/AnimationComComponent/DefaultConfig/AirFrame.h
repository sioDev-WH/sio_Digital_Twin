/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: AirFrame
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\AirFrame.h
*********************************************************************/


#ifndef AirFrame_H 

#define AirFrame_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "Application.h"
#include "OnUMLDaeEsoImpl.h"

//## package Application 

//----------------------------------------------------------------------------
// AirFrame.h                                                                  
//----------------------------------------------------------------------------
class AeroDynamics;
class BodyDynamics;
class FinActuator;

#ifdef _OMINSTRUMENT
class OMAnimatedAirFrame;
#endif // _OMINSTRUMENT


//## class AirFrame 
class AirFrame : public COnUMLDaeEsoImpl<AirFrame> {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedAirFrame;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation AirFrame() 
    AirFrame();
    
    //## operation ~AirFrame() 
    ~AirFrame();


////    Operations    ////
protected :
    
    //## operation GetAssociations(long**,long**,long*) 
    HRESULT GetAssociations(long**  Assoc, long**  Size, long*  nSize);
    
    //## operation InitEsos() 
    HRESULT InitEsos();
    
    //## operation Load(FILE*) 
    bool Load(FILE*  fs);
    
    //## operation Save(FILE*) 
    void Save(FILE*  fs);
    
    //## operation clean() 
    void clean();
    
    //## operation init() 
    void init();


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Relations and components    ////
public :
    
    AeroDynamics* itsAeroDynamics;		//## link itsAeroDynamics 
    
    
    BodyDynamics* itsBodyDynamics;		//## link itsBodyDynamics 
    
    
    FinActuator* itsFinDynamics;		//## link itsFinDynamics 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedAirFrame : virtual public AOMInstance {

    
    DECLARE_META(AirFrame, OMAnimatedAirFrame)


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\AirFrame.h
*********************************************************************/

