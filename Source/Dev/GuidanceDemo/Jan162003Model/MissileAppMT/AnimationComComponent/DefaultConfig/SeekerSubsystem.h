/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: SeekerSubsystem
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\SeekerSubsystem.h
*********************************************************************/


#ifndef SeekerSubsystem_H 

#define SeekerSubsystem_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "SeekerSubsystemPkg.h"
#include <oxf/omthread.h>
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "GimbalController.h"
#include "RateStabilizationFilter.h"
#include "SeekerSubsystemCoeff.h"
#include "OnModelBase.h"

//## package SeekerSubsystemPkg 

//----------------------------------------------------------------------------
// SeekerSubsystem.h                                                                  
//----------------------------------------------------------------------------
class GuidanceLogic;

#ifdef _OMINSTRUMENT
class OMAnimatedSeekerSubsystem;
#endif // _OMINSTRUMENT


//## class SeekerSubsystem 
class SeekerSubsystem : public OMReactive, public COnModelBase {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedSeekerSubsystem;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation SeekerSubsystem() 
    SeekerSubsystem(OMThread*  p_thread = OMDefaultThread);
    
    //## auto_generated 
    ~SeekerSubsystem();


////    Operations    ////
public :
    
    //## operation checkAcquisition() 
    void checkAcquisition();
    
    //## operation clean() 
    void clean();
    
    // Range and closing velocity
    //## operation computeSeparationData() 
    void computeSeparationData();
    
    //## operation estimateLOSRate() 
    void estimateLOSRate();
    
    //## operation get_LOS(const double,double *) 
    void get_LOS(const double  t, double *val);
    
    //## operation get_closingVelocity(const double,double *) 
    void get_closingVelocity(const double  t, double *val);
    
    //## operation get_dishError(const double,double *) 
    void get_dishError(const double  t, double *val);
    
    //## operation get_gimbalAngle(const double,double *) 
    void get_gimbalAngle(const double  t, double *val);
    
    //## operation get_range(const double,double *) 
    void get_range(const double  t, double *val);
    
    //## operation get_stabilizedRate(const double,double *) 
    void get_stabilizedRate(const double  t, double *val);
    
    //## operation handle_tick(const double) 
    void handle_tick(const double  t);
    
    //## operation init() 
    void init();
    
    //## operation set_dishCommand(const double,double *) 
    void set_dishCommand(const double  t, double *val);
    
    //## operation set_guidanceMode(const double,long *) 
    void set_guidanceMode(const double  t, long *val);
    
    //## operation set_missile_Attitude_Data(const double,double *) 
    void set_missile_Attitude_Data(const double  t, double *val);
    
    //## operation set_missile_Gyro_Data(const double,double *) 
    void set_missile_Gyro_Data(const double  t, double *val);
    
    //## operation set_missile_X_Data(const double,double *) 
    void set_missile_X_Data(const double  t, double *val);
    
    //## operation set_missile_Z_Data(const double,double *) 
    void set_missile_Z_Data(const double  t, double *val);
    
    //## operation set_target_X_Data(const double,double *) 
    void set_target_X_Data(const double  t, double *val);
    
    //## operation set_target_Z_Data(const double,double *) 
    void set_target_Z_Data(const double  t, double *val);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getLOS() const;
    
    //## auto_generated 
    void setLOS(double  p_LOS);
    
    //## auto_generated 
    double getLOSRate_Data() const;
    
    //## auto_generated 
    void setLOSRate_Data(double  p_LOSRate_Data);
    
    //## auto_generated 
    int getBTargetAcquired() const;
    
    //## auto_generated 
    void setBTargetAcquired(int  p_bTargetAcquired);
    
    //## auto_generated 
    double getClosingVelocity() const;
    
    //## auto_generated 
    void setClosingVelocity(double  p_closingVelocity);
    
    //## auto_generated 
    double getDishCommand() const;
    
    //## auto_generated 
    void setDishCommand(double  p_dishCommand);
    
    //## auto_generated 
    double getDishError() const;
    
    //## auto_generated 
    void setDishError(double  p_dishError);
    
    //## auto_generated 
    double getGimbalAngle() const;
    
    //## auto_generated 
    void setGimbalAngle(double  p_gimbalAngle);
    
    //## auto_generated 
    int getGuidanceMode() const;
    
    //## auto_generated 
    void setGuidanceMode(int  p_guidanceMode);
    
    //## auto_generated 
    double getLookAngle() const;
    
    //## auto_generated 
    void setLookAngle(double  p_lookAngle);
    
    //## auto_generated 
    double getMissile_Attitude_Data() const;
    
    //## auto_generated 
    void setMissile_Attitude_Data(double  p_missile_Attitude_Data);
    
    //## auto_generated 
    double getMissile_Gyro_Data() const;
    
    //## auto_generated 
    void setMissile_Gyro_Data(double  p_missile_Gyro_Data);
    
    //## auto_generated 
    double getMissile_X() const;
    
    //## auto_generated 
    void setMissile_X(double  p_missile_X);
    
    //## auto_generated 
    double getMissile_X_Data() const;
    
    //## auto_generated 
    void setMissile_X_Data(double  p_missile_X_Data);
    
    //## auto_generated 
    double getMissile_Z() const;
    
    //## auto_generated 
    void setMissile_Z(double  p_missile_Z);
    
    //## auto_generated 
    double getMissile_Z_Data() const;
    
    //## auto_generated 
    void setMissile_Z_Data(double  p_missile_Z_Data);
    
    //## auto_generated 
    double getRange() const;
    
    //## auto_generated 
    void setRange(double  p_range);
    
    //## auto_generated 
    double getTarget_X() const;
    
    //## auto_generated 
    void setTarget_X(double  p_target_X);
    
    //## auto_generated 
    double getTarget_X_Data() const;
    
    //## auto_generated 
    void setTarget_X_Data(double  p_target_X_Data);
    
    //## auto_generated 
    double getTarget_Z() const;
    
    //## auto_generated 
    void setTarget_Z(double  p_target_Z);
    
    //## auto_generated 
    double getTarget_Z_Data() const;
    
    //## auto_generated 
    void setTarget_Z_Data(double  p_target_Z_Data);
    
    //## auto_generated 
    SeekerSubsystemCoeff* getCoeff() const;
    
    //## auto_generated 
    GimbalController* getItsGimbalController() const;
    
    //## auto_generated 
    GuidanceLogic* getItsGuidanceLogic() const;
    
    //## auto_generated 
    void setItsGuidanceLogic(GuidanceLogic*  p_GuidanceLogic);
    
    //## auto_generated 
    RateStabilizationFilter* getItsRateStabilizationFilter() const;


////    Framework operations    ////
public :
    
    //## auto_generated 
    virtual OMBoolean startBehavior();

protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
public :
    
    double LOS;		//## attribute LOS 
    
    double LOSRate_Data;		//## attribute LOSRate_Data 
    
    int bTargetAcquired;		//## attribute bTargetAcquired 
    
    double closingVelocity;		//## attribute closingVelocity 
    
    double dishError;		//## attribute dishError 
    
    double gimbalAngle;		//## attribute gimbalAngle 
    
    double lookAngle;		//## attribute lookAngle 
    
    double missile_X;		//## attribute missile_X 
    
    double missile_Z;		//## attribute missile_Z 
    
    double range;		//## attribute range 
    
protected :
    
    double dishCommand;		//## attribute dishCommand 
    
    int guidanceMode;		//## attribute guidanceMode 
    
    double missile_Attitude_Data;		//## attribute missile_Attitude_Data 
    
    double missile_Gyro_Data;		//## attribute missile_Gyro_Data 
    
    double missile_X_Data;		//## attribute missile_X_Data 
    
    double missile_Z_Data;		//## attribute missile_Z_Data 
    
    double target_X;		//## attribute target_X 
    
    double target_X_Data;		//## attribute target_X_Data 
    
    double target_Z;		//## attribute target_Z 
    
    double target_Z_Data;		//## attribute target_Z_Data 
    

////    Relations and components    ////
public :
    
    SeekerSubsystemCoeff Coeff;		//## classInstance Coeff 
    
    
    GimbalController itsGimbalController;		//## classInstance itsGimbalController 
    
    
    GuidanceLogic* itsGuidanceLogic;		//## link itsGuidanceLogic 
    
    
    RateStabilizationFilter itsRateStabilizationFilter;		//## classInstance itsRateStabilizationFilter 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedSeekerSubsystem : virtual public AOMInstance {

    
    DECLARE_REACTIVE_META(SeekerSubsystem, OMAnimatedSeekerSubsystem)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\SeekerSubsystem.h
*********************************************************************/

