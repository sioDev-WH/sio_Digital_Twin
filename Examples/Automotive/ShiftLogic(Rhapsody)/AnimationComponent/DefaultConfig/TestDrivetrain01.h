/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: TestDrivetrain01
//!	Generated Date	: Fri, 27, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\TestDrivetrain01.h
*********************************************************************/


#ifndef TestDrivetrain01_H 

#define TestDrivetrain01_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "Application.h"
#include "TransmissionControlModels.h"
#include "OnUMLDaeEsoImpl.h"

//## package Application 

//----------------------------------------------------------------------------
// TestDrivetrain01.h                                                                  
//----------------------------------------------------------------------------
class Actuator;
class Band_Brake;
class CFrame;
class Clutch;
class Engine;

#ifdef _OMINSTRUMENT
class OMAnimatedTestDrivetrain01;
#endif // _OMINSTRUMENT
class Oneway_Clutch;
class Ravigneaux;
class Torque_Converter;
class Vehicle5;


//## class TestDrivetrain01 
class TestDrivetrain01 : public COnUMLDaeEsoImpl<TestDrivetrain01> {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedTestDrivetrain01;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation TestDrivetrain01() 
    TestDrivetrain01();
    
    //## operation ~TestDrivetrain01() 
    ~TestDrivetrain01();


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
    
    
    Band_Brake* LRB;		//## link LRB 
    
    
    Band_Brake* OB;		//## link OB 
    
    
    Oneway_Clutch* POC;		//## link POC 
    
    
    Clutch* RC;		//## link RC 
    
    
    Actuator* aDC;		//## link aDC 
    
    
    Actuator* aFC;		//## link aFC 
    
    
    Actuator* aIOC;		//## link aIOC 
    
    
    Actuator* aLRB;		//## link aLRB 
    
    
    Actuator* aOB;		//## link aOB 
    
    
    Actuator* aPOC;		//## link aPOC 
    
    
    Actuator* aRC;		//## link aRC 
    
    
    CFrame* gIOC;		//## link gIOC 
    
    
    CFrame* gLRB;		//## link gLRB 
    
    
    CFrame* gOB;		//## link gOB 
    
    
    CFrame* gPOC;		//## link gPOC 
    
    
    Engine* itsEngine;		//## link itsEngine 
    
    
    Ravigneaux* itsRavigneaux;		//## link itsRavigneaux 
    
    
    Torque_Converter* itsTorqueConverter;		//## link itsTorqueConverter 
    
    
    Vehicle5* itsVehicle;		//## link itsVehicle 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedTestDrivetrain01 : virtual public AOMInstance {

    
    DECLARE_META(TestDrivetrain01, OMAnimatedTestDrivetrain01)


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\TestDrivetrain01.h
*********************************************************************/

