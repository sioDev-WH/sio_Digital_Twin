/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: AirFrameAutoPilotSystem
//!	Generated Date	: Tue, 10, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\AirFrameAutoPilotSystem.h
*********************************************************************/


#ifndef AirFrameAutoPilotSystem_H 

#define AirFrameAutoPilotSystem_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "GuidancePkg.h"

//## package GuidancePkg 

//----------------------------------------------------------------------------
// AirFrameAutoPilotSystem.h                                                                  
//----------------------------------------------------------------------------
class AirFrame;
class AutoPilot;

#ifdef _OMINSTRUMENT
class OMAnimatedAirFrameAutoPilotSystem;
#endif // _OMINSTRUMENT


//## class AirFrameAutoPilotSystem 
struct IIsDaeEsoCImpl;
struct IOnModelExec;

class AirFrameAutoPilotSystem  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedAirFrameAutoPilotSystem;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation AirFrameAutoPilotSystem() 
    AirFrameAutoPilotSystem();
    
    //## operation ~AirFrameAutoPilotSystem() 
    virtual ~AirFrameAutoPilotSystem();


////    Operations    ////
public :
    
    //## operation Fire_Tick(const double ) 
    void Fire_Tick(const double t);
    
    //## operation Load(BSTR ) 
    bool Load(BSTR filename);
    
    //## operation Save(BSTR ) 
    void Save(BSTR filename);
    
    //## operation clean() 
    void clean();
    
    //## operation handle_tick(const double ) 
    HRESULT handle_tick(const double t);
    
    //## operation init() 
    void init();
    
    //## operation initSimulation() 
    void initSimulation();
    
    //## operation printData(const double ) 
    void printData(const double t);
    
    //## operation runSimulation() 
    void runSimulation();
    
    //## operation setCommand(double) 
    void setCommand(double  val);
    
    //## operation setThrust(double) 
    void setThrust(double  val);
    
    //## operation termSimulation() 
    void termSimulation();


////    Additional operations    ////
public :
    
    //## auto_generated 
    void setFinSetpoint(double  p_FinSetpoint);
    
    //## auto_generated 
    void setAccelData(double  p_accelData);
    
    //## auto_generated 
    void setGyroData(double  p_gyroData);
    
    //## auto_generated 
    void setM_endTime(double  p_m_endTime);
    
    //## auto_generated 
    void setM_startTime(double  p_m_startTime);
    
    //## auto_generated 
    void setM_stepSize(double  p_m_stepSize);
    
    //## auto_generated 
    void setM_t_last(double  p_m_t_last);
    
    //## auto_generated 
    void setNVars(long  p_nVars);
    
    //## auto_generated 
    void setOldFinSetpoint(double  p_oldFinSetpoint);
    
    //## auto_generated 
    void setPsaVarVals(SAFEARRAY * p_psaVarVals);
    
    //## auto_generated 
    void setSim_time(double  p_sim_time);
    
    //## auto_generated 
    void setVarVals(double * p_varVals);
    
    //## auto_generated 
    AutoPilot* getAutoPilot() const;
    
    //## auto_generated 
    void setAutoPilot(AutoPilot*  p_AutoPilot);
    
    //## auto_generated 
    IIsDaeEsoCImpl* getM_pModel() const;
    
    //## auto_generated 
    void setM_pModel(IIsDaeEsoCImpl*  p_IIsDaeEsoCImpl);
    
    //## auto_generated 
    IOnModelExec* getM_pModelExec() const;
    
    //## auto_generated 
    void setM_pModelExec(IOnModelExec*  p_IOnModelExec);
    
    //## auto_generated 
    AirFrame* getM_pUMLModel() const;
    
    //## auto_generated 
    void setM_pUMLModel(AirFrame*  p_AirFrame);


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
public :
    
    double FinSetpoint;		//## attribute FinSetpoint 
    
    double accelData;		//## attribute accelData 
    
    double command;		//## attribute command 
    
    double gyroData;		//## attribute gyroData 
    
    double m_endTime;		//## attribute m_endTime 
    
    double m_startTime;		//## attribute m_startTime 
    
    double m_stepSize;		//## attribute m_stepSize 
    
    double m_t_last;		//## attribute m_t_last 
    
    double oldFinSetpoint;		//## attribute oldFinSetpoint 
    
    double sim_time;		//## attribute sim_time 
    
    double thrust;		//## attribute thrust 
    
private :
    
    long nVars;		//## attribute nVars 
    
    SAFEARRAY * psaVarVals;		//## attribute psaVarVals 
    
    double * varVals;		//## attribute varVals 
    

////    Relations and components    ////
public :
    
    AutoPilot* autoPilot;		//## link autoPilot 
    
    
    IIsDaeEsoCImpl* m_pModel;		//## link m_pModel 
    
    
    IOnModelExec* m_pModelExec;		//## link m_pModelExec 
    
    
    AirFrame* m_pUMLModel;		//## link m_pUMLModel 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedAirFrameAutoPilotSystem : virtual public AOMInstance {

    
    DECLARE_META(AirFrameAutoPilotSystem, OMAnimatedAirFrameAutoPilotSystem)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\AirFrameAutoPilotSystem.h
*********************************************************************/

