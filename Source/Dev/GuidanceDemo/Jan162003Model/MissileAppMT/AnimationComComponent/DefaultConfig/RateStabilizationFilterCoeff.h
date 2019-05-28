/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: RateStabilizationFilterCoeff
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\RateStabilizationFilterCoeff.h
*********************************************************************/


#ifndef RateStabilizationFilterCoeff_H 

#define RateStabilizationFilterCoeff_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "SeekerSubsystemPkg.h"

//## package SeekerSubsystemPkg 

//----------------------------------------------------------------------------
// RateStabilizationFilterCoeff.h                                                                  
//----------------------------------------------------------------------------
class ControlDesigner;

#ifdef _OMINSTRUMENT
class OMAnimatedRateStabilizationFilterCoeff;
#endif // _OMINSTRUMENT


//## class RateStabilizationFilterCoeff 
class RateStabilizationFilterCoeff  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedRateStabilizationFilterCoeff;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation RateStabilizationFilterCoeff() 
    RateStabilizationFilterCoeff();
    
    //## auto_generated 
    ~RateStabilizationFilterCoeff();


////    Operations    ////
public :
    
    //## operation clean() 
    void clean();
    
    //## operation init() 
    void init();


////    Additional operations    ////
public :
    
    //## auto_generated 
    double *  getA() const;
    
    //## auto_generated 
    void setA(double * p_A);
    
    //## auto_generated 
    double *  getB() const;
    
    //## auto_generated 
    void setB(double * p_B);
    
    //## auto_generated 
    double *  getC() const;
    
    //## auto_generated 
    void setC(double * p_C);
    
    //## auto_generated 
    double *  getD() const;
    
    //## auto_generated 
    void setD(double * p_D);
    
    //## auto_generated 
    double getGyroBandwidth() const;
    
    //## auto_generated 
    void setGyroBandwidth(double  p_gyroBandwidth);
    
    //## auto_generated 
    double getGyroDamping() const;
    
    //## auto_generated 
    void setGyroDamping(double  p_gyroDamping);
    
    //## auto_generated 
    int getNu() const;
    
    //## auto_generated 
    void setNu(int  p_nu);
    
    //## auto_generated 
    int getNx() const;
    
    //## auto_generated 
    void setNx(int  p_nx);
    
    //## auto_generated 
    int getNy() const;
    
    //## auto_generated 
    void setNy(int  p_ny);
    
    //## auto_generated 
    double getPeriod() const;
    
    //## auto_generated 
    void setPeriod(double  p_period);
    
    //## auto_generated 
    ControlDesigner* getPDesigner() const;
    
    //## auto_generated 
    void setPDesigner(ControlDesigner*  p_ControlDesigner);


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
public :
    
    double * A;		//## attribute A 
    
    double * B;		//## attribute B 
    
    double * C;		//## attribute C 
    
    double * D;		//## attribute D 
    
    // Wgyro
    double gyroBandwidth;		//## attribute gyroBandwidth 
    
    // zeta
    double gyroDamping;		//## attribute gyroDamping 
    
    int nu;		//## attribute nu 
    
    int nx;		//## attribute nx 
    
    int ny;		//## attribute ny 
    
    double period;		//## attribute period 
    

////    Relations and components    ////
protected :
    
    ControlDesigner* pDesigner;		//## link pDesigner 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedRateStabilizationFilterCoeff : virtual public AOMInstance {

    
    DECLARE_META(RateStabilizationFilterCoeff, OMAnimatedRateStabilizationFilterCoeff)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\RateStabilizationFilterCoeff.h
*********************************************************************/

