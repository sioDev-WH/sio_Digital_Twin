/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: aeroComposition
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\aeroComposition.h
*********************************************************************/


#ifndef aeroComposition_H 

#define aeroComposition_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AirframePkg.h"
#include "OnUMLDaeEsoImpl.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// aeroComposition.h                                                                  
//----------------------------------------------------------------------------
class aeroDynamics;
class aeroFrame;
class atmosphere;
class bodyDynamics;
class engineDynamics;
class finDynamics;


//## class aeroComposition 
class aeroComposition : public COnUMLDaeEsoImpl<aeroComposition> {


////    Constructors and destructors    ////
public :
    
    //## operation aeroComposition() 
    aeroComposition();
    
    //## operation ~aeroComposition() 
    ~aeroComposition();


////    Operations    ////
public :
    
    //## operation aeroDynamicsBlock_getAlpha(const double,double *) 
    void aeroDynamicsBlock_getAlpha(const double  t, double *  val);
    
    //## operation aeroDynamicsBlock_getMach(const double,double *) 
    void aeroDynamicsBlock_getMach(const double  t, double *  val);
    
    //## operation bodyDynamicsBlock_getAccel(const double,double *) 
    void bodyDynamicsBlock_getAccel(const double  t, double *  val);
    
    //## operation bodyDynamicsBlock_getAttitude(const double,double *) 
    void bodyDynamicsBlock_getAttitude(const double  t, double *  val);
    
    //## operation bodyDynamicsBlock_getGyro(const double,double *) 
    void bodyDynamicsBlock_getGyro(const double  t, double *  val);
    
    //## operation bodyDynamicsBlock_getX(const double,double *) 
    void bodyDynamicsBlock_getX(const double  t, double *  val);
    
    //## operation bodyDynamicsBlock_getZ(const double,double *) 
    void bodyDynamicsBlock_getZ(const double  t, double *  val);
    
    //## operation finDynamics_handle_AngleSetpoint(const double ,double * ) 
    void finDynamics_handle_AngleSetpoint(const double t, double * val);

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
    
    aeroDynamics* aeroDynamicsBlock;		//## link aeroDynamicsBlock 
    
    
    aeroFrame* aeroFrameBlock;		//## link aeroFrameBlock 
    
    
    atmosphere* atmosphereBlock;		//## link atmosphereBlock 
    
    
    bodyDynamics* bodyDynamicsBlock;		//## link bodyDynamicsBlock 
    
    
    engineDynamics* engineDynamicsBlock;		//## link engineDynamicsBlock 
    
    
    finDynamics* finDynamicsBlock;		//## link finDynamicsBlock 
    


};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\aeroComposition.h
*********************************************************************/

