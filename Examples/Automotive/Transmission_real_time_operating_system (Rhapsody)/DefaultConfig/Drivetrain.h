/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Drivetrain
//!	Generated Date	: Sun, 19, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Drivetrain.h
*********************************************************************/


#ifndef Drivetrain_H 

#define Drivetrain_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "Application.h"
#include "TransmissionControlModels.h"
#include "OnUMLDaeEsoImpl.h"

//## package Application 

//----------------------------------------------------------------------------
// Drivetrain.h                                                                  
//----------------------------------------------------------------------------
class Actuator;
class Band_Brake;
class CFrame;
class Clutch;
class Engine;

#ifdef _OMINSTRUMENT
class OMAnimatedDrivetrain;
#endif // _OMINSTRUMENT
class Oneway_Clutch;
class Ravigneaux;
class Torque_Converter;
class Vehicle5;


//## class Drivetrain 
class Drivetrain : public COnUMLDaeEsoImpl<Drivetrain> {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedDrivetrain;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation Drivetrain() 
    Drivetrain();
    
    //## operation ~Drivetrain() 
    ~Drivetrain();


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
    
    Clutch* DC;		//## link DC 
    
    
    Clutch* FC;		//## link FC 
    
    
    Oneway_Clutch* IOC;		//## link IOC 
    
    
    Band_Brake* OB;		//## link OB 
    
    
    Oneway_Clutch* POC;		//## link POC 
    
    
    Actuator* aDC;		//## link aDC 
    
    
    Actuator* aFC;		//## link aFC 
    
    
    Actuator* aIOC;		//## link aIOC 
    
    
    Actuator* aOB;		//## link aOB 
    
    
    Actuator* aPOC;		//## link aPOC 
    
    
    CFrame* gIOC;		//## link gIOC 
    
    
    CFrame* gOB;		//## link gOB 
    
    
    CFrame* gPOC;		//## link gPOC 
    
    
    Vehicle5* itsCar;		//## link itsCar 
    
    
    Engine* itsEngine;		//## link itsEngine 
    
    
    Ravigneaux* itsGearbox;		//## link itsGearbox 
    
    
    Torque_Converter* itsTC;		//## link itsTC 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedDrivetrain : virtual public AOMInstance {

    
    DECLARE_META(Drivetrain, OMAnimatedDrivetrain)


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Drivetrain.h
*********************************************************************/

