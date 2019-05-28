/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: TrackingSubsystem
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\TrackingSubsystem.h
*********************************************************************/


#ifndef TrackingSubsystem_H 

#define TrackingSubsystem_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "TrackingSubsystemPkg.h"
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "GimbalController.h"
#include "RateStabilizationFilter.h"
#include "TrackingSubsystemCoeff.h"
#include "OnModelBase.h"
#include "OmEventBroadcast.h"

//## package TrackingSubsystemPkg 

//----------------------------------------------------------------------------
// TrackingSubsystem.h                                                                  
//----------------------------------------------------------------------------
class GuidanceLogic;


//## class TrackingSubsystem 
class TrackingSubsystem : public OMReactive, public COnModelBase {


////    Constructors and destructors    ////
public :
    
    //## operation TrackingSubsystem() 
    TrackingSubsystem(OMThread*  p_thread = OMDefaultThread);
    
    //## auto_generated 
    ~TrackingSubsystem();


////    Operations    ////
public :
    
    //## operation checkAcquisition() 
    void checkAcquisition();
    
    //## operation clean() 
    void clean();
    
    // Range and closing velocity
    //## operation computeSeparationData() 
    void computeSeparationData();
    
    //## operation getQS(double*) 
    void getQS(double*  val);
    
    //## operation handle_tick() 
    void handle_tick();
    
    //## operation init() 
    void init();
    
    //## operation setPeriod(long) 
    void setPeriod(long  val);


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
    COnEventBroadcaster* getEvToGuidance() const;
    
    //## auto_generated 
    void setEvToGuidance(COnEventBroadcaster*  p_evToGuidance);
    
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
    double getRangeRate() const;
    
    //## auto_generated 
    void setRangeRate(double  p_rangeRate);
    
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
    TrackingSubsystemCoeff* getCoeff() const;
    
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
    
    double dishCommand;		//## attribute dishCommand 
    
    double dishError;		//## attribute dishError 
    
    COnEventBroadcaster* evToGuidance;		//## attribute evToGuidance 
    
    double gimbalAngle;		//## attribute gimbalAngle 
    
    int guidanceMode;		//## attribute guidanceMode 
    
    double lookAngle;		//## attribute lookAngle 
    
    double missile_Attitude_Data;		//## attribute missile_Attitude_Data 
    
    double missile_Gyro_Data;		//## attribute missile_Gyro_Data 
    
    double missile_X;		//## attribute missile_X 
    
    double missile_X_Data;		//## attribute missile_X_Data 
    
    double missile_Z;		//## attribute missile_Z 
    
    double missile_Z_Data;		//## attribute missile_Z_Data 
    
    double range;		//## attribute range 
    
    double rangeRate;		//## attribute rangeRate 
    
    double target_X;		//## attribute target_X 
    
    double target_X_Data;		//## attribute target_X_Data 
    
    double target_Z;		//## attribute target_Z 
    
    double target_Z_Data;		//## attribute target_Z_Data 
    

////    Relations and components    ////
public :
    
    TrackingSubsystemCoeff Coeff;		//## classInstance Coeff 
    
    
    GimbalController itsGimbalController;		//## classInstance itsGimbalController 
    
    
    GuidanceLogic* itsGuidanceLogic;		//## link itsGuidanceLogic 
    
    
    RateStabilizationFilter itsRateStabilizationFilter;		//## classInstance itsRateStabilizationFilter 
    


};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\TrackingSubsystem.h
*********************************************************************/

