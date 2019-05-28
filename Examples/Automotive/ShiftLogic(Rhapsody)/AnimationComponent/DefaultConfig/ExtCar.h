/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: ExtCar
//!	Generated Date	: Thu, 19, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\ExtCar.h
*********************************************************************/


#ifndef ExtCar_H 

#define ExtCar_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AppSimple.h"
#include "TransmissionControlModels.h"
#include "OnUMLDaeEsoImpl.h"

//## package AppSimple 

//----------------------------------------------------------------------------
// ExtCar.h                                                                  
//----------------------------------------------------------------------------
class Actuator;
class Band_Brake;
class CFrame;
class Clutch;
class Engine;

#ifdef _OMINSTRUMENT
class OMAnimatedExtCar;
#endif // _OMINSTRUMENT
class Oneway_Clutch;
class Ravigneaux;
class Torque_Converter;
class Vehicle5;


//## class ExtCar 
class ExtCar : public COnUMLDaeEsoImpl<ExtCar> {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedExtCar;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation ExtCar() 
    ExtCar();
    
    //## operation ~ExtCar() 
    ~ExtCar();


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
    
    
    Ravigneaux* itsGearbox;		//## link itsGearbox 
    
    
    Torque_Converter* itsTorqueConverter;		//## link itsTorqueConverter 
    
    
    Vehicle5* itsVehicle;		//## link itsVehicle 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedExtCar : virtual public AOMInstance {

    
    DECLARE_META(ExtCar, OMAnimatedExtCar)


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\ExtCar.h
*********************************************************************/

