/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: AeroCoeff
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\AeroCoeff.h
*********************************************************************/


#ifndef AeroCoeff_H 

#define AeroCoeff_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "AirframePkg.h"
#include "IOnVarInit.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// AeroCoeff.h                                                                  
//----------------------------------------------------------------------------

//## class AeroCoeff 
class AeroCoeff : public IOnVarInit {


////    Constructors and destructors    ////
public :
    
    //## operation AeroCoeff() 
    AeroCoeff();
    
    //## auto_generated 
    ~AeroCoeff();


////    Operations    ////
public :
    
    //## operation FinalConstruct() 
    HRESULT FinalConstruct();
    
    //## operation FinalRelease() 
     FinalRelease();
    
    //## operation init() 
    void init();

protected :
    
    //## operation InitLocalIPars(const _TCHAR * ,pplong * ,ppchar * ,long * ,long * ) 
    HRESULT InitLocalIPars(const _TCHAR * prefix, pplong * pars, ppchar * Names, long * nPars, long * dPars);
    
    //## operation InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ) 
    HRESULT InitLocalRPars(const _TCHAR * prefix, ppdouble * pars, ppchar * Names, long * nPars, long * dPars);
    
    //## operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    HRESULT InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly);


////    Additional operations    ////
public :
    
    //## auto_generated 
    void setCm_alpha(double  p_Cm_alpha);
    
    //## auto_generated 
    void setCm_el(double  p_Cm_el);
    
    //## auto_generated 
    void setCm_q(double  p_Cm_q);
    
    //## auto_generated 
    void setCx_alpha(double  p_Cx_alpha);
    
    //## auto_generated 
    void setCx_el(double  p_Cx_el);
    
    //## auto_generated 
    void setCz_alpha(double  p_Cz_alpha);
    
    //## auto_generated 
    void setCz_el(double  p_Cz_el);
    
    //## auto_generated 
    void setMach(double  p_Mach);
    
    //## auto_generated 
    void setS_ref(double  p_S_ref);
    
    //## auto_generated 
    void setV(double  p_V);
    
    //## auto_generated 
    void set_Cm_alpha(VarEx p__Cm_alpha);
    
    //## auto_generated 
    void set_Cx_alpha(VarEx p__Cx_alpha);
    
    //## auto_generated 
    void set_Cz_alpha(VarEx p__Cz_alpha);
    
    //## auto_generated 
    void set_Mach(VarEx p__Mach);
    
    //## auto_generated 
    void set_V(VarEx p__V);
    
    //## auto_generated 
    void set_alpha(VarEx p__alpha);
    
    //## auto_generated 
    void setAlpha(double  p_alpha);
    
    //## auto_generated 
    void setAm(double  p_am);
    
    //## auto_generated 
    void setAn(double  p_an);
    
    //## auto_generated 
    void setBm(double  p_bm);
    
    //## auto_generated 
    void setBn(double  p_bn);
    
    //## auto_generated 
    void setCm(double  p_cm);
    
    //## auto_generated 
    void setCn(double  p_cn);
    
    //## auto_generated 
    void setD_ref(double  p_d_ref);


////    Attributes    ////
public :
    
    double Cm_alpha;		//## attribute Cm_alpha 
    
    double Cm_el;		//## attribute Cm_el 
    
    double Cm_q;		//## attribute Cm_q 
    
    double Cx_alpha;		//## attribute Cx_alpha 
    
    double Cx_el;		//## attribute Cx_el 
    
    double Cz_alpha;		//## attribute Cz_alpha 
    
    double Cz_el;		//## attribute Cz_el 
    
    double Mach;		//## attribute Mach 
    
    double S_ref;		//## attribute S_ref 
    
    // Velocity
    double V;		//## attribute V 
    
    VarEx _Cm_alpha;		//## attribute _Cm_alpha 
    
    VarEx _Cx_alpha;		//## attribute _Cx_alpha 
    
    VarEx _Cz_alpha;		//## attribute _Cz_alpha 
    
    VarEx _Mach;		//## attribute _Mach 
    
    VarEx _V;		//## attribute _V 
    
    VarEx _alpha;		//## attribute _alpha 
    
    // variables
    // Angle of attack
    double alpha;		//## attribute alpha 
    
    // Moment Coefficients
    double am;		//## attribute am 
    
    // Normal Force Coefficients
    double an;		//## attribute an 
    
    double bm;		//## attribute bm 
    
    double bn;		//## attribute bn 
    
    double cm;		//## attribute cm 
    
    double cn;		//## attribute cn 
    
    double d_ref;		//## attribute d_ref 
    

};


#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\AeroCoeff.h
*********************************************************************/

