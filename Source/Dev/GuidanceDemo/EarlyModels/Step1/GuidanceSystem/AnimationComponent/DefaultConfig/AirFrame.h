/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: AirFrame
//!	Generated Date	: Tue, 10, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\AirFrame.h
*********************************************************************/


#ifndef AirFrame_H 

#define AirFrame_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "GuidancePkg.h"
#include "OnModel_AirFrame.h"

//## package GuidancePkg 

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
class AirFrame : public OnModel_AirFrame {


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
    virtual ~AirFrame();


////    Operations    ////
public :
    
    //## operation Load(FILE * ) 
    bool Load(FILE * fs);
    
    //## operation Save(FILE * ) 
    void Save(FILE * fs);
    
    //## operation clean() 
    void clean();
    
    //## operation getAccData(double) 
    double getAccData(double  time);
    
    //## operation getGyroData(double) 
    double getGyroData(double  time);
    
    //## operation getSpeed(double) 
    double getSpeed(double  time);
    
    //## operation init() 
    void init();
    
    //## operation setFinAngleSetpoint(const double ,double * ) 
    void setFinAngleSetpoint(const double t, double * val);
    
    //## operation setThrust(const double ,double * ) 
    void setThrust(const double t, double * val);

protected :
    
    //## operation GetAssociations(long * * ,long * * ,long * ) 
    HRESULT GetAssociations(long * * Assoc, long * * Size, long * nSize);
    
    //## operation InitEsos() 
    HRESULT InitEsos();


////    Additional operations    ////
public :
    
    //## auto_generated 
    AeroDynamics* getPAero() const;
    
    //## auto_generated 
    void setPAero(AeroDynamics*  p_AeroDynamics);
    
    //## auto_generated 
    BodyDynamics* getPBody() const;
    
    //## auto_generated 
    void setPBody(BodyDynamics*  p_BodyDynamics);
    
    //## auto_generated 
    FinActuator* getPFin() const;
    
    //## auto_generated 
    void setPFin(FinActuator*  p_FinActuator);


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Relations and components    ////
public :
    
    AeroDynamics* pAero;		//## link pAero 
    
    
    BodyDynamics* pBody;		//## link pBody 
    
    
    FinActuator* pFin;		//## link pFin 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedAirFrame : virtual public AOMInstance {

    
    DECLARE_META(AirFrame, OMAnimatedAirFrame)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\AirFrame.h
*********************************************************************/

