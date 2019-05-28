/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: aeroDynamics
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\aeroDynamics.h
*********************************************************************/


#ifndef aeroDynamics_H 

#define aeroDynamics_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AirframePkg.h"
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "aeroPort.h"
#include "AtmoPort.h"
#include "FinPort.h"
#include "OnUMLDaeEsoImpl.h"
#include "aeroInertia.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// aeroDynamics.h                                                                  
//----------------------------------------------------------------------------

//## class aeroDynamics 
class aeroDynamics : public OMReactive, public COnUMLDaeEsoImpl<aeroDynamics> {


////    Constructors and destructors    ////
public :
    
    //## operation aeroDynamics() 
    aeroDynamics(OMThread*  p_thread = OMDefaultThread);
    
    //## operation ~aeroDynamics() 
    virtual ~aeroDynamics();


////    Operations    ////
public :
    
    //## operation Load(FILE*) 
    bool Load(FILE*  fs);
    
    //## operation Save(FILE*) 
    void Save(FILE*  fs);
    
    //## operation clean() 
    void clean();
    
    //## operation getAlpha(const double ,double * ) 
    void getAlpha(const double t, double * val);
    
    // temporary methods to fit into original application
    //## operation getMach(const double ,double * ) 
    void getMach(const double t, double * val);
    
    //## operation get_AoA(const double,double*) 
    void get_AoA(const double  t, double*  pVal);
    
    //## operation get_Cm_alpha(const double,double*) 
    void get_Cm_alpha(const double  t, double*  pVal);
    
    //## operation get_Cx_alpha(const double,double*) 
    void get_Cx_alpha(const double  t, double*  pVal);
    
    //## operation get_Cz_alpha(const double,double*) 
    void get_Cz_alpha(const double  t, double*  pVal);
    
    //## operation get_Mach(const double,double*) 
    void get_Mach(const double  t, double*  pVal);
    
    //## operation get_SSA(const double,double*) 
    void get_SSA(const double  t, double*  pVal);
    
    //## operation get_V(const double,double*) 
    void get_V(const double  t, double*  pVal);
    
    //## operation get_der_AoA(const double,double*) 
    void get_der_AoA(const double  t, double*  pVal);
    
    //## operation get_der_Cm_alpha(const double,double*) 
    void get_der_Cm_alpha(const double  t, double*  pVal);
    
    //## operation get_der_Cx_alpha(const double,double*) 
    void get_der_Cx_alpha(const double  t, double*  pVal);
    
    //## operation get_der_Cz_alpha(const double,double*) 
    void get_der_Cz_alpha(const double  t, double*  pVal);
    
    //## operation get_der_Mach(const double,double*) 
    void get_der_Mach(const double  t, double*  pVal);
    
    //## operation get_der_SSA(const double,double*) 
    void get_der_SSA(const double  t, double*  pVal);
    
    //## operation get_der_V(const double,double*) 
    void get_der_V(const double  t, double*  pVal);
    
    //## operation handle_CX(const double,const double*) 
    void handle_CX(const double  t, const double*  val);
    
    //## operation handle_CY(const double,const double*) 
    void handle_CY(const double  t, const double*  val);
    
    //## operation handle_CZ(const double,const double*) 
    void handle_CZ(const double  t, const double*  val);
    
    //## operation handle_Cl(const double,const double*) 
    void handle_Cl(const double  t, const double*  val);
    
    //## operation handle_Cl_al(const double,const double*) 
    void handle_Cl_al(const double  t, const double*  val);
    
    //## operation handle_Cl_p(const double,const double*) 
    void handle_Cl_p(const double  t, const double*  val);
    
    //## operation handle_Cm(const double,const double*) 
    void handle_Cm(const double  t, const double*  val);
    
    //## operation handle_Cm_el(const double,const double*) 
    void handle_Cm_el(const double  t, const double*  val);
    
    //## operation handle_Cm_q(const double,const double*) 
    void handle_Cm_q(const double  t, const double*  val);
    
    //## operation handle_Cn(const double,const double*) 
    void handle_Cn(const double  t, const double*  val);
    
    //## operation handle_Cn_beta(const double,const double*) 
    void handle_Cn_beta(const double  t, const double*  val);
    
    //## operation handle_Cn_r(const double,const double*) 
    void handle_Cn_r(const double  t, const double*  val);
    
    //## operation handle_Cn_rudder(const double,const double*) 
    void handle_Cn_rudder(const double  t, const double*  val);
    
    //## operation handle_Cx_el(const double,const double*) 
    void handle_Cx_el(const double  t, const double*  val);
    
    //## operation handle_Cy_rudder(const double,const double*) 
    void handle_Cy_rudder(const double  t, const double*  val);
    
    //## operation handle_Cz_el(const double,const double*) 
    void handle_Cz_el(const double  t, const double*  val);
    
    //## operation handle_S_ref(const double,const double*) 
    void handle_S_ref(const double  t, const double*  val);
    
    //## operation handle_am(const double,const double*) 
    void handle_am(const double  t, const double*  val);
    
    //## operation handle_an(const double,const double*) 
    void handle_an(const double  t, const double*  val);
    
    //## operation handle_bm(const double,const double*) 
    void handle_bm(const double  t, const double*  val);
    
    //## operation handle_bn(const double,const double*) 
    void handle_bn(const double  t, const double*  val);
    
    //## operation handle_d_ref(const double,const double*) 
    void handle_d_ref(const double  t, const double*  val);
    
    //## operation handle_g(const double,const double*) 
    void handle_g(const double  t, const double*  val);
    
    //## operation handle_mass(const double,const double*) 
    void handle_mass(const double  t, const double*  val);
    
    //## operation init() 
    void init();
    
    // Algebraic relation
    //## operation r_AoA(double * ) 
    HRESULT r_AoA(double * res);
    
    // aeroDynamic Coefficients
    //## operation r_C(valarray<double>*) 
    HRESULT r_C(valarray<double>*  res);
    
    // aeroDynamic Forces
    //## operation r_Forces(valarray<double>*) 
    HRESULT r_Forces(valarray<double>*  res);
    
    // Algebraic relation
    //## operation r_Mach(double * ) 
    HRESULT r_Mach(double * res);
    
    // aeroDynamic Moments
    //## operation r_Moments(valarray<double>*) 
    HRESULT r_Moments(valarray<double>*  res);
    
    // Algebraic relation
    //## operation r_SSA(double * ) 
    HRESULT r_SSA(double * res);
    
    // Algebraic relation
    //## operation r_V(double * ) 
    HRESULT r_V(double * res);

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
    
    //## operation ad_r_AoA(Fdouble*) 
    HRESULT ad_r_AoA(Fdouble*  res);
    
    //## operation ad_r_C(valarray<Fdouble> *) 
    HRESULT ad_r_C(valarray<Fdouble> *  res);
    
    //## operation ad_r_Forces(valarray<Fdouble> *) 
    HRESULT ad_r_Forces(valarray<Fdouble> *  res);
    
    //## operation ad_r_Mach(Fdouble*) 
    HRESULT ad_r_Mach(Fdouble*  res);
    
    //## operation ad_r_Moments(valarray<Fdouble> *) 
    HRESULT ad_r_Moments(valarray<Fdouble> *  res);
    
    //## operation ad_r_SSA(Fdouble*) 
    HRESULT ad_r_SSA(Fdouble*  res);
    
    //## operation ad_r_V(Fdouble*) 
    HRESULT ad_r_V(Fdouble*  res);


////    Additional operations    ////
public :
    
    //## auto_generated 
    aeroPort* getP() const;
    
    //## auto_generated 
    AtmoPort* getPAtmosphere() const;
    
    //## auto_generated 
    FinPort* getPFin() const;


////    Framework operations    ////
public :
    
    //## auto_generated 
    virtual OMBoolean startBehavior();


////    Attributes    ////
public :
    
    // Sensors
    // Angle of Attack (alpha, incidence angle)
    double AoA;		//## attribute AoA 
    
    double CX;		//## attribute CX 
    
    double CY;		//## attribute CY 
    
    double CZ;		//## attribute CZ 
    
    double Cl;		//## attribute Cl 
    
    // roll moment from aileron deflection
    double Cl_al;		//## attribute Cl_al 
    
    // roll moment from roll rate,p, (damping)
    double Cl_p;		//## attribute Cl_p 
    
    double Cm;		//## attribute Cm 
    
    // pitch moment from AOA
    double Cm_alpha;		//## attribute Cm_alpha 
    
    // pitch moment from elevator deflection
    double Cm_el;		//## attribute Cm_el 
    
    // pitch moment from pitch rate, q, (damping)
    double Cm_q;		//## attribute Cm_q 
    
    double Cn;		//## attribute Cn 
    
    // yaw moment from side slip angle
    double Cn_beta;		//## attribute Cn_beta 
    
    // yaw moment from yaw rate, r, (damping)
    double Cn_r;		//## attribute Cn_r 
    
    // yaw moment from rudder deflection
    double Cn_rudder;		//## attribute Cn_rudder 
    
    // aerodynamic Coefficients
    // axial drag from AOA (constant in this case)
    double Cx_alpha;		//## attribute Cx_alpha 
    
    // axial drag from elevator defelction = 0
    double Cx_el;		//## attribute Cx_el 
    
    // side force from side slip angle
    double Cy_beta;		//## attribute Cy_beta 
    
    // side force from rudder deflection
    double Cy_rudder;		//## attribute Cy_rudder 
    
    // lift from AOA
    double Cz_alpha;		//## attribute Cz_alpha 
    
    // lift from elevator defelction
    double Cz_el;		//## attribute Cz_el 
    
    // Mach# = V/AirVelocity
    double Mach;		//## attribute Mach 
    
    // Side Slip Angle (beta)
    double SSA;		//## attribute SSA 
    
    // Speed 
    double V;		//## attribute V 
    
    // 3 dim element define a class for control surfaces
    valarray<double> deflectors;		//## attribute deflectors 
    
    aeroAngle<double> eulerAngles;		//## attribute eulerAngles 
    
    double g;		//## attribute g 
    
    aeroInertia<double> inertia;		//## attribute inertia 
    
    double mass;		//## attribute mass 
    
    aeroPos<double> position;		//## attribute position 
    
protected :
    
    double S_ref;		//## attribute S_ref 
    
    VarEx _AoA;		//## attribute _AoA 
    
    VarEx _Cm_alpha;		//## attribute _Cm_alpha 
    
    VarEx _Cx_alpha;		//## attribute _Cx_alpha 
    
    VarEx _Cz_alpha;		//## attribute _Cz_alpha 
    
    VarEx _Mach;		//## attribute _Mach 
    
    VarEx _SSA;		//## attribute _SSA 
    
    VarEx _V;		//## attribute _V 
    
    // Parameters for Coefficients
    double am;		//## attribute am 
    
    double an;		//## attribute an 
    
    double bm;		//## attribute bm 
    
    double bn;		//## attribute bn 
    
    double cm;		//## attribute cm 
    
    double cn;		//## attribute cn 
    
    double d_ref;		//## attribute d_ref 
    

////    Relations and components    ////
public :
    
    aeroPort p;		//## classInstance p 
    
    
    // for now, not using gust port.
    // GustPort pGust; // carries Wind velocity to compute airspeed Vaero(3)(used in aerodynamic equations)= Vbody(u,v,w)from body - WindSpeed(3)
    AtmoPort pAtmosphere;		//## classInstance pAtmosphere 
    
    
    FinPort pFin;		//## classInstance pFin 
    


};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\aeroDynamics.h
*********************************************************************/

