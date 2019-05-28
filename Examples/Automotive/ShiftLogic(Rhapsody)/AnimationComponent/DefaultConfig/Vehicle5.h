/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Vehicle5
//!	Generated Date	: Wed, 8, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Vehicle5.h
*********************************************************************/


#ifndef Vehicle5_H 

#define Vehicle5_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "VehicleModels.h"
#include "StandardModels.h"
#include "TransmissionControlModels.h"
#include "OnUMLDaeEsoImpl.h"

//## package VehicleModels 

//----------------------------------------------------------------------------
// Vehicle5.h                                                                  
//----------------------------------------------------------------------------
class BrakeActuator;
class CFrame;
class Clutch;
class CRigidConnector;

#ifdef _OMINSTRUMENT
class OMAnimatedVehicle5;
#endif // _OMINSTRUMENT


// 
//## class Vehicle5 
class Vehicle5 : public COnUMLDaeEsoImpl<Vehicle5> {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedVehicle5;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation Vehicle5() 
    Vehicle5();
    
    //## operation ~Vehicle5() 
    virtual ~Vehicle5();


////    Operations    ////
public :
    
    //## operation GetAssociations(long * * ,long * * ,long * ) 
    HRESULT GetAssociations(long * * Assoc, long * * Size, long * nSize);
    
    //## operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
    HRESULT InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form);
    
    //## operation InitEsos() 
    HRESULT InitEsos();
    
    //## operation InitLocalADEqns() 
    HRESULT InitLocalADEqns();
    
    //## operation InitLocalEqns() 
    HRESULT InitLocalEqns();
    
    //## operation InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ) 
    HRESULT InitLocalRPars(const _TCHAR * prefix, ppdouble * pars, ppchar * Names, long * nPars, long * dPars);
    
    //## operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    HRESULT InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly);
    
    //## operation Load(FILE * ) 
    bool Load(FILE * fs);
    
    //## operation Save(FILE * ) 
    void Save(FILE * fs);
    
    //## operation ad_r_Newton(Fdouble * ) 
    HRESULT ad_r_Newton(Fdouble * res);
    
    //## operation ad_r_Speed(Fdouble * ) 
    HRESULT ad_r_Speed(Fdouble * res);
    
    //## operation ad_r_wheelSpeed(Fdouble * ) 
    HRESULT ad_r_wheelSpeed(Fdouble * res);
    
    //## operation clean() 
    void clean();
    
    //## operation getSpeed(const double ,double * ) 
    void getSpeed(const double t, double * val);
    
    //## operation handle_aerodynamicDrag(const double ,const double * ) 
    void handle_aerodynamicDrag(const double t, const double * val);
    
    //## operation handle_brakePedal(const double ,double * ) 
    void handle_brakePedal(const double t, double * val);
    
    //## operation handle_finalDriveRatio(const double ,const double * ) 
    void handle_finalDriveRatio(const double t, const double * val);
    
    //## operation handle_vehicleInertia(const double ,const double * ) 
    void handle_vehicleInertia(const double t, const double * val);
    
    //## operation handle_wheelFrictionDrag(const double ,const double * ) 
    void handle_wheelFrictionDrag(const double t, const double * val);
    
    //## operation handle_wheelRadius(const double ,const double * ) 
    void handle_wheelRadius(const double t, const double * val);
    
    //## operation init() 
    void init();
    
    //## operation r_Newton(double * ) 
    HRESULT r_Newton(double * res);
    
    //## operation r_Speed(double * ) 
    HRESULT r_Speed(double * res);
    
    //## operation r_wheelSpeed(double * ) 
    HRESULT r_wheelSpeed(double * res);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getAerodynamicDrag() const;
    
    //## auto_generated 
    void setAerodynamicDrag(double  p_aerodynamicDrag);
    
    //## auto_generated 
    double getFinalDriveRatio() const;
    
    //## auto_generated 
    void setFinalDriveRatio(double  p_finalDriveRatio);
    
    //## auto_generated 
    double getSpeed() const;
    
    //## auto_generated 
    void setSpeed(double  p_speed);
    
    //## auto_generated 
    double getVehicleInertia() const;
    
    //## auto_generated 
    void setVehicleInertia(double  p_vehicleInertia);
    
    //## auto_generated 
    double getWheelFrictionDrag() const;
    
    //## auto_generated 
    void setWheelFrictionDrag(double  p_wheelFrictionDrag);
    
    //## auto_generated 
    double getWheelRadius() const;
    
    //## auto_generated 
    void setWheelRadius(double  p_wheelRadius);
    
    //## auto_generated 
    double getWheelSpeed() const;
    
    //## auto_generated 
    void setWheelSpeed(double  p_wheelSpeed);
    
    //## auto_generated 
    Clutch* getBrake() const;
    
    //## auto_generated 
    void setBrake(Clutch*  p_Clutch);
    
    //## auto_generated 
    BrakeActuator* getABrakeActuator() const;
    
    //## auto_generated 
    void setABrakeActuator(BrakeActuator*  p_BrakeActuator);
    
    //## auto_generated 
    CFrame* getGBrake() const;
    
    //## auto_generated 
    void setGBrake(CFrame*  p_CFrame);
    
    //## auto_generated 
    CRigidConnector* getP() const;
    
    //## auto_generated 
    void setP(CRigidConnector*  p_CRigidConnector);

protected :
    
    //## auto_generated 
    VarEx get_speed() const;
    
    //## auto_generated 
    void set_speed(VarEx  p__speed);
    
    //## auto_generated 
    VarEx get_wheelSpeed() const;
    
    //## auto_generated 
    void set_wheelSpeed(VarEx  p__wheelSpeed);


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
public :
    
    double aerodynamicDrag;		//## attribute aerodynamicDrag 
    
    double finalDriveRatio;		//## attribute finalDriveRatio 
    
    double speed;		//## attribute speed 
    
    double vehicleInertia;		//## attribute vehicleInertia 
    
    double wheelFrictionDrag;		//## attribute wheelFrictionDrag 
    
    double wheelRadius;		//## attribute wheelRadius 
    
    double wheelSpeed;		//## attribute wheelSpeed 
    
protected :
    
    VarEx _speed;		//## attribute _speed 
    
    VarEx _wheelSpeed;		//## attribute _wheelSpeed 
    

////    Relations and components    ////
public :
    
    Clutch* Brake;		//## link Brake 
    
    
    BrakeActuator* aBrakeActuator;		//## link aBrakeActuator 
    
    
    CFrame* gBrake;		//## link gBrake 
    
    
    CRigidConnector* p;		//## link p 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedVehicle5 : virtual public AOMInstance {

    
    DECLARE_META(Vehicle5, OMAnimatedVehicle5)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Vehicle5.h
*********************************************************************/

