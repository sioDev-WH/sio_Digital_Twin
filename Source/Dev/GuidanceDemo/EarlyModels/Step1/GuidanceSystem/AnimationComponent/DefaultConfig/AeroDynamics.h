/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: AeroDynamics
//!	Generated Date	: Tue, 10, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\AeroDynamics.h
*********************************************************************/


#ifndef AeroDynamics_H 

#define AeroDynamics_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "GuidancePkg.h"
#include "OnModel_AeroDynamics.h"

//## package GuidancePkg 

//----------------------------------------------------------------------------
// AeroDynamics.h                                                                  
//----------------------------------------------------------------------------
class AeroCoeff;
class Atmosphere;

#ifdef _OMINSTRUMENT
class OMAnimatedAeroDynamics;
#endif // _OMINSTRUMENT
class On1DConn;
class On3DConn;


//## class AeroDynamics 
class AeroDynamics : public OnModel_AeroDynamics {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedAeroDynamics;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation AeroDynamics() 
    AeroDynamics();
    
    //## operation ~AeroDynamics() 
    virtual ~AeroDynamics();


////    Operations    ////
public :
    
    //## operation Load(FILE * ) 
    bool Load(FILE * fs);
    
    // simulation load / save
    //## operation Save(FILE * ) 
    void Save(FILE * fs);
    
    //## operation clean() 
    void clean();
    
    //## operation init() 
    void init();
    
    //## operation r_Cm_alpha(double * ) 
    HRESULT r_Cm_alpha(double * res);
    
    //## operation r_Cx_alpha(double * ) 
    HRESULT r_Cx_alpha(double * res);
    
    //## operation r_Cz_alpha(double * ) 
    HRESULT r_Cz_alpha(double * res);
    
    //## operation r_Fx(double * ) 
    HRESULT r_Fx(double * res);
    
    //## operation r_Fz(double * ) 
    HRESULT r_Fz(double * res);
    
    //## operation r_Mach(double * ) 
    HRESULT r_Mach(double * res);
    
    //## operation r_My(double * ) 
    HRESULT r_My(double * res);
    
    //## operation r_V(double * ) 
    HRESULT r_V(double * res);
    
    // residual equations for dynamics
    //## operation r_alpha(double * ) 
    HRESULT r_alpha(double * res);
    
    // parameter update
    //## operation setThrust(const double ,double * ) 
    void setThrust(const double time, double * val);

protected :
    
    //## operation InitEqnForm(OnEqnForm * * ,OnEqnDiffForm * * ) 
    HRESULT InitEqnForm(OnEqnForm * * form, OnEqnDiffForm * * diff_form);
    
    // model initialization
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
    
    //## operation ad_r_Cm_alpha(Fdouble * ) 
    HRESULT ad_r_Cm_alpha(Fdouble * res);
    
    //## operation ad_r_Cx_alpha(Fdouble * ) 
    HRESULT ad_r_Cx_alpha(Fdouble * res);
    
    //## operation ad_r_Cz_alpha(Fdouble * ) 
    HRESULT ad_r_Cz_alpha(Fdouble * res);
    
    //## operation ad_r_Fx(Fdouble * ) 
    HRESULT ad_r_Fx(Fdouble * res);
    
    //## operation ad_r_Fz(Fdouble * ) 
    HRESULT ad_r_Fz(Fdouble * res);
    
    //## operation ad_r_Mach(Fdouble * ) 
    HRESULT ad_r_Mach(Fdouble * res);
    
    //## operation ad_r_My(Fdouble * ) 
    HRESULT ad_r_My(Fdouble * res);
    
    //## operation ad_r_V(Fdouble * ) 
    HRESULT ad_r_V(Fdouble * res);
    
    // AD verion of equations
    //## operation ad_r_alpha(Fdouble * ) 
    HRESULT ad_r_alpha(Fdouble * res);


////    Additional operations    ////
public :
    
    //## auto_generated 
    void setThrust(double  p_Thrust);
    
    //## auto_generated 
    Atmosphere* getPAtmosphere() const;
    
    //## auto_generated 
    void setPAtmosphere(Atmosphere*  p_Atmosphere);
    
    //## auto_generated 
    On3DConn* getPBody() const;
    
    //## auto_generated 
    void setPBody(On3DConn*  p_On3DConn);
    
    //## auto_generated 
    AeroCoeff* getPCoeff() const;
    
    //## auto_generated 
    void setPCoeff(AeroCoeff*  p_AeroCoeff);
    
    //## auto_generated 
    On1DConn* getPFinConn() const;
    
    //## auto_generated 
    void setPFinConn(On1DConn*  p_On1DConn);


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
public :
    
    // parameters
    double Thrust;		//## attribute Thrust 
    

////    Relations and components    ////
public :
    
    // to get speedOfSound and airDensity
    Atmosphere* pAtmosphere;		//## link pAtmosphere 
    
    
    // connectors
    On3DConn* pBody;		//## link pBody 
    
    
    // aggregated members
    AeroCoeff* pCoeff;		//## link pCoeff 
    
    
    On1DConn* pFinConn;		//## link pFinConn 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedAeroDynamics : virtual public AOMInstance {

    
    DECLARE_META(AeroDynamics, OMAnimatedAeroDynamics)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\AeroDynamics.h
*********************************************************************/

