/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: StdCar
//!	Generated Date	: Wed, 18, Jun 2003  
	File Path	: AnimationComponent\DefaultConfig\StdCar.h
*********************************************************************/


#ifndef StdCar_H 

#define StdCar_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AppSimple.h"
#include "TransmissionControlModels.h"
#include "OnUMLDaeEsoImpl.h"

//## package AppSimple 

//----------------------------------------------------------------------------
// StdCar.h                                                                  
//----------------------------------------------------------------------------
class Actuator;
class Band_Brake;
class CFrame;
class Clutch;
class Engine;

#ifdef _OMINSTRUMENT
class OMAnimatedStdCar;
#endif // _OMINSTRUMENT
class Oneway_Clutch;
class Ravigneaux;
class Torque_Converter;
class Vehicle5;


//## class StdCar 
class StdCar : public COnUMLDaeEsoImpl<StdCar> {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedStdCar;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation StdCar() 
    StdCar();
    
    //## operation ~StdCar() 
    ~StdCar();


////    Operations    ////
public :
    
    //## operation aDC_Shift(const double ,long * ) 
    void aDC_Shift(const double t, long * val);
    
    //## operation aFC_Shift(const double ,long * ) 
    void aFC_Shift(const double t, long * val);
    
    //## operation aIOC_Shift(const double ,long * ) 
    void aIOC_Shift(const double t, long * val);
    
    //## operation aOB_Shift(const double ,long * ) 
    void aOB_Shift(const double t, long * val);
    
    //## operation aPOC_Shift(const double ,long * ) 
    void aPOC_Shift(const double t, long * val);
    
    //## operation itsEngine_getRPM(const double ,double * ) 
    void itsEngine_getRPM(const double t, double * val);
    
    //## operation itsEngine_handle_Start(const double ,long * ) 
    void itsEngine_handle_Start(const double t, long * val);
    
    //## operation itsEngine_handle_throttle(const double ,double * ) 
    void itsEngine_handle_throttle(const double t, double * val);
    
    //## operation itsVehicle_getSpeed(const double ,double * ) 
    void itsVehicle_getSpeed(const double t, double * val);
    
    //## operation itsVehicle_handle_brakePedal(const double ,double * ) 
    void itsVehicle_handle_brakePedal(const double t, double * val);

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
     init();


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
    
    
    Engine* itsEngine;		//## link itsEngine 
    
    
    Ravigneaux* itsGearbox;		//## link itsGearbox 
    
    
    Torque_Converter* itsTorqueConverter;		//## link itsTorqueConverter 
    
    
    Vehicle5* itsVehicle;		//## link itsVehicle 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedStdCar : virtual public AOMInstance {

    
    DECLARE_META(StdCar, OMAnimatedStdCar)


////    Framework operations    ////
public :
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\StdCar.h
*********************************************************************/

