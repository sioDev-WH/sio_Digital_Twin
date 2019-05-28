/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: BodyDynamicsCoeff
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\BodyDynamicsCoeff.h
*********************************************************************/


#ifndef BodyDynamicsCoeff_H 

#define BodyDynamicsCoeff_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "AirframePkg.h"
#include "IOnVarInit.h"

//## package AirframePkg 

//----------------------------------------------------------------------------
// BodyDynamicsCoeff.h                                                                  
//----------------------------------------------------------------------------

//## class BodyDynamicsCoeff 
class BodyDynamicsCoeff : public IOnVarInit {


////    Constructors and destructors    ////
public :
    
    //## operation BodyDynamicsCoeff() 
    BodyDynamicsCoeff();
    
    //## auto_generated 
    ~BodyDynamicsCoeff();


////    Operations    ////
public :
    
    //## operation InitLocalIPars(const _TCHAR * ,pplong * ,ppchar * ,long * ,long * ) 
    HRESULT InitLocalIPars(const _TCHAR * prefix, pplong * pars, ppchar * Names, long * nPars, long * dPars);
    
    //## operation InitLocalRPars(const _TCHAR * ,ppdouble * ,ppchar * ,long * ,long * ) 
    HRESULT InitLocalRPars(const _TCHAR * prefix, ppdouble * pars, ppchar * Names, long * nPars, long * dPars);
    
    //## operation InitLocalVars(const _TCHAR * ,VarCont * ,const bool ) 
    HRESULT InitLocalVars(const _TCHAR * prefix, VarCont * varC, const bool bADOnly);
    
    //## operation init() 
    void init();


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getIxx() const;
    
    //## auto_generated 
    void setIxx(double  p_Ixx);
    
    //## auto_generated 
    double getIyy() const;
    
    //## auto_generated 
    void setIyy(double  p_Iyy);
    
    //## auto_generated 
    double getIzz() const;
    
    //## auto_generated 
    void setIzz(double  p_Izz);
    
    //## auto_generated 
    double getMass() const;
    
    //## auto_generated 
    void setMass(double  p_Mass);
    
    //## auto_generated 
    double getAccPos() const;
    
    //## auto_generated 
    void setAccPos(double  p_accPos);


////    Attributes    ////
public :
    
    double Ixx;		//## attribute Ixx 
    
    double Iyy;		//## attribute Iyy 
    
    double Izz;		//## attribute Izz 
    
    double Mass;		//## attribute Mass 
    
    // Accelerometer distance in front of CG
    double accPos;		//## attribute accPos 
    

};


#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\BodyDynamicsCoeff.h
*********************************************************************/

