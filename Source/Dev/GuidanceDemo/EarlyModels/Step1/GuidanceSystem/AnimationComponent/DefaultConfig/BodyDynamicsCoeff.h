/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: AnimationComponent 
	Configuration 	: DefaultConfig
	Model Element	: BodyDynamicsCoeff
//!	Generated Date	: Tue, 10, Dec 2002  
	File Path	: AnimationComponent\DefaultConfig\BodyDynamicsCoeff.h
*********************************************************************/


#ifndef BodyDynamicsCoeff_H 

#define BodyDynamicsCoeff_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "GuidancePkg.h"
#include <IOnVarInit.h>

//## package GuidancePkg 

//----------------------------------------------------------------------------
// BodyDynamicsCoeff.h                                                                  
//----------------------------------------------------------------------------

#ifdef _OMINSTRUMENT
class OMAnimatedBodyDynamicsCoeff;
#endif // _OMINSTRUMENT


//## class BodyDynamicsCoeff 
class BodyDynamicsCoeff : public IOnVarInit {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedBodyDynamicsCoeff;
#endif // _OMINSTRUMENT


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
    void setIxx(double  p_Ixx);
    
    //## auto_generated 
    void setIyy(double  p_Iyy);
    
    //## auto_generated 
    void setIzz(double  p_Izz);
    
    //## auto_generated 
    void setMass(double  p_Mass);
    
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


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedBodyDynamicsCoeff : virtual public AOMInstance {

    
    DECLARE_META(BodyDynamicsCoeff, OMAnimatedBodyDynamicsCoeff)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComponent\DefaultConfig\BodyDynamicsCoeff.h
*********************************************************************/

