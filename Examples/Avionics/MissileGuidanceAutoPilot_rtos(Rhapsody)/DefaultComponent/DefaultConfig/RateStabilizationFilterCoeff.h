/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: RateStabilizationFilterCoeff
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\RateStabilizationFilterCoeff.h
*********************************************************************/


#ifndef RateStabilizationFilterCoeff_H 

#define RateStabilizationFilterCoeff_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "TrackingSubsystemPkg.h"

//## package TrackingSubsystemPkg 

//----------------------------------------------------------------------------
// RateStabilizationFilterCoeff.h                                                                  
//----------------------------------------------------------------------------
class ControlDesigner;


//## class RateStabilizationFilterCoeff 
class RateStabilizationFilterCoeff  {


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
    
    //## operation initData() 
    void initData();
    
    //## operation setPeriod(long) 
    void setPeriod(long  val);


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
    long getPeriod() const;
    
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
    
    long period;		//## attribute period 
    

////    Relations and components    ////
protected :
    
    ControlDesigner* pDesigner;		//## link pDesigner 
    


};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\RateStabilizationFilterCoeff.h
*********************************************************************/

