/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: Vehicle
//!	Generated Date	: Wed, 8, Jan 2003  
	File Path	: AnimationComponent\DefaultConfig\Vehicle.h
*********************************************************************/


#ifndef Vehicle_H 

#define Vehicle_H 


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
// Vehicle.h                                                                  
//----------------------------------------------------------------------------
class CRigidConnector;

#ifdef _OMINSTRUMENT
class OMAnimatedVehicle;
#endif // _OMINSTRUMENT


// <CgModel ClassType="1" xmlns="x-schema:\xmldata\ModelDefinition.xml"> 
// <CgAttribute Name="p" sType="3" sSubType="1" Value="0" bSim="True" />
// <CgAttribute Name="wheelSpeed" sType="1" sSubType="1" Value="0" bSim="True" />
// <CgAttribute Name="speed" sType="1" sSubType="1" Value="0" bSim="True" />
// <CgAttribute Name="breakTorque" sType="2" sSubType="1" Value="0" bSim="True" />
// <CgAttribute Name="finalDriveRatio" sType="2" sSubType="1" Value="0" bSim="True" />
// <CgAttribute Name="wheelRadius" sType="2" sSubType="1" Value="0" bSim="True" />
// <CgAttribute Name="vehicleInertia" sType="2" sSubType="1" Value="0" bSim="True" />
// <CgAttribute Name="wheelFrictionDrag" sType="2" sSubType="1" Value="0" bSim="True" />
// <CgAttribute Name="aerodynamicDrag" sType="2" sSubType="1" Value="0" bSim="True" />
// <CgOperation Name="r_Newton" sType="1" sDiffType="2" />
// <CgOperation Name="r_Speed" sType="1" sDiffType="2" />
// <CgOperation Name="r_wheelSpeed" sType="1" sDiffType="2" />
// </CgModel>
// 
//## class Vehicle 
class Vehicle : public COnUMLDaeEsoImpl<Vehicle> {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedVehicle;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation Vehicle() 
    Vehicle();
    
    //## operation ~Vehicle() 
    ~Vehicle();


////    Operations    ////
public :
    
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
    
    //## operation handle_aerodynamicDrag(const double ,const double * ) 
    void handle_aerodynamicDrag(const double t, const double * val);
    
    //## operation handle_brakeTorque(const double ,const double * ) 
    void handle_brakeTorque(const double t, const double * val);
    
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

protected :
    
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


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getAerodynamicDrag() const;
    
    //## auto_generated 
    void setAerodynamicDrag(double  p_aerodynamicDrag);
    
    //## auto_generated 
    double getBrakeTorque() const;
    
    //## auto_generated 
    void setBrakeTorque(double  p_brakeTorque);
    
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
    
    double brakeTorque;		//## attribute brakeTorque 
    
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
    
    CRigidConnector* p;		//## link p 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedVehicle : virtual public AOMInstance {

    
    DECLARE_META(Vehicle, OMAnimatedVehicle)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\Vehicle.h
*********************************************************************/

