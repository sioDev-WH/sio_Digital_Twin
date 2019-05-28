/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: atmosphere
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\atmosphere.h
*********************************************************************/


#ifndef atmosphere_H 

#define atmosphere_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AirframePkg.h"
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "AtmoHeightPort.h"
#include "AtmoPort.h"
#include "OnUMLDaeEsoImpl.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// atmosphere.h                                                                  
//----------------------------------------------------------------------------

//## class atmosphere 
class atmosphere : public OMReactive, public COnUMLDaeEsoImpl<atmosphere> {


////    Constructors and destructors    ////
public :
    
    //## operation atmosphere() 
    atmosphere(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~atmosphere() 
    virtual ~atmosphere();


////    Operations    ////
public :
    
    //## operation Load(FILE*) 
    bool Load(FILE*  fs);
    
    //## operation Save(FILE*) 
    void Save(FILE*  fs);
    
    //## operation clean() 
    void clean();
    
    //## operation handle_R(const double,const double*) 
    void handle_R(const double  t, const double*  val);
    
    //## operation handle_gravity(const double,const double*) 
    void handle_gravity(const double  t, const double*  val);
    
    //## operation handle_lapseRate(const double,const double*) 
    void handle_lapseRate(const double  t, const double*  val);
    
    //## operation handle_maxHeightRange(const double,const double*) 
    void handle_maxHeightRange(const double  t, const double*  val);
    
    //## operation handle_seaLevelDensity(const double,const double*) 
    void handle_seaLevelDensity(const double  t, const double*  val);
    
    //## operation handle_seaLevelPressure(const double,const double*) 
    void handle_seaLevelPressure(const double  t, const double*  val);
    
    //## operation handle_seaLevelTemperature(const double,const double*) 
    void handle_seaLevelTemperature(const double  t, const double*  val);
    
    //## operation handle_specificHeatRatio(const double,const double*) 
    void handle_specificHeatRatio(const double  t, const double*  val);
    
    //## operation handle_troposphere(const double,const double*) 
    void handle_troposphere(const double  t, const double*  val);
    
    //## operation init() 
    void init();
    
    //## operation r_airDensity(double * ) 
    HRESULT r_airDensity(double * res);
    
    //## operation r_speedOfSound(double * ) 
    HRESULT r_speedOfSound(double * res);

protected :
    
    //## operation InitEqnForm(OnEqnForm**,OnEqnDiffForm**) 
    HRESULT InitEqnForm(OnEqnForm**  form, OnEqnDiffForm**  diff_form);
    
    //## operation InitEsos() 
    HRESULT InitEsos();
    
    //## operation InitLocalADEqns() 
    HRESULT InitLocalADEqns();
    
    //## operation InitLocalEqns() 
    HRESULT InitLocalEqns();
    
    //## operation InitLocalRPars(const _TCHAR*,ppdouble*,ppchar*,long*,long*) 
    HRESULT InitLocalRPars(const _TCHAR*  prefix, ppdouble*  pars, ppchar*  Names, long*  nPars, long*  dPars);
    
    //## operation InitLocalVars(const _TCHAR*,VarCont*,const bool) 
    HRESULT InitLocalVars(const _TCHAR*  prefix, VarCont*  varC, const bool  bADOnly);
    
    //## operation ad_r_airDensity(Fdouble*) 
    HRESULT ad_r_airDensity(Fdouble*  res);
    
    //## operation ad_r_speedOfSound(Fdouble*) 
    HRESULT ad_r_speedOfSound(Fdouble*  res);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getR() const;
    
    //## auto_generated 
    void setR(double  p_R);
    
    //## auto_generated 
    double getGravity() const;
    
    //## auto_generated 
    void setGravity(double  p_gravity);
    
    //## auto_generated 
    double getLapseRate() const;
    
    //## auto_generated 
    void setLapseRate(double  p_lapseRate);
    
    //## auto_generated 
    double getMaxHeightRange() const;
    
    //## auto_generated 
    void setMaxHeightRange(double  p_maxHeightRange);
    
    //## auto_generated 
    double getSeaLevelDensity() const;
    
    //## auto_generated 
    void setSeaLevelDensity(double  p_seaLevelDensity);
    
    //## auto_generated 
    double getSeaLevelPressure() const;
    
    //## auto_generated 
    void setSeaLevelPressure(double  p_seaLevelPressure);
    
    //## auto_generated 
    double getSeaLevelTemperature() const;
    
    //## auto_generated 
    void setSeaLevelTemperature(double  p_seaLevelTemperature);
    
    //## auto_generated 
    double getSpecificHeatRatio() const;
    
    //## auto_generated 
    void setSpecificHeatRatio(double  p_specificHeatRatio);
    
    //## auto_generated 
    double getTroposphere() const;
    
    //## auto_generated 
    void setTroposphere(double  p_troposphere);
    
    //## auto_generated 
    AtmoPort* getPAtmo() const;
    
    //## auto_generated 
    AtmoHeightPort* getPh() const;


////    Framework operations    ////
public :
    
    //## auto_generated 
    virtual OMBoolean startBehavior();


////    Attributes    ////
protected :
    
    double R;		//## attribute R 
    
    double gravity;		//## attribute gravity 
    
    double lapseRate;		//## attribute lapseRate 
    
    double maxHeightRange;		//## attribute maxHeightRange 
    
    double seaLevelDensity;		//## attribute seaLevelDensity 
    
    double seaLevelPressure;		//## attribute seaLevelPressure 
    
    double seaLevelTemperature;		//## attribute seaLevelTemperature 
    
    double specificHeatRatio;		//## attribute specificHeatRatio 
    
    double troposphere;		//## attribute troposphere 
    

////    Relations and components    ////
public :
    
    // ports
    AtmoPort pAtmo;		//## classInstance pAtmo 
    
    
    AtmoHeightPort ph;		//## classInstance ph 
    


};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\atmosphere.h
*********************************************************************/

