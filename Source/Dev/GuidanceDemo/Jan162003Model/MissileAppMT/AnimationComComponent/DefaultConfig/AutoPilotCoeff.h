/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: AutoPilotCoeff
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\AutoPilotCoeff.h
*********************************************************************/


#ifndef AutoPilotCoeff_H 

#define AutoPilotCoeff_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "AutopilotPkg.h"

//## package AutopilotPkg 

//----------------------------------------------------------------------------
// AutoPilotCoeff.h                                                                  
//----------------------------------------------------------------------------
class ControlDesigner;


//## class AutoPilotCoeff 
class AutoPilotCoeff  {


////    Constructors and destructors    ////
public :
    
    //## operation AutoPilotCoeff() 
    AutoPilotCoeff();
    
    //## auto_generated 
    ~AutoPilotCoeff();


////    Operations    ////
public :
    
    //## operation init() 
    void init();


////    Additional operations    ////
public :
    
    //## auto_generated 
    double* getA() const;
    
    //## auto_generated 
    void setA(double*  p_A);
    
    //## auto_generated 
    double* getB() const;
    
    //## auto_generated 
    void setB(double*  p_B);
    
    //## auto_generated 
    double* getC() const;
    
    //## auto_generated 
    void setC(double*  p_C);
    
    //## auto_generated 
    double *  getD() const;
    
    //## auto_generated 
    void setD(double * p_D);
    
    //## auto_generated 
    double getAccelGain() const;
    
    //## auto_generated 
    void setAccelGain(double  p_accelGain);
    
    //## auto_generated 
    double getAntiAliasGain() const;
    
    //## auto_generated 
    void setAntiAliasGain(double  p_antiAliasGain);
    
    //## auto_generated 
    double getAntiAliasPole() const;
    
    //## auto_generated 
    void setAntiAliasPole(double  p_antiAliasPole);
    
    //## auto_generated 
    double getGyroFilterPole() const;
    
    //## auto_generated 
    void setGyroFilterPole(double  p_gyroFilterPole);
    
    //## auto_generated 
    double getGyroFilterZero() const;
    
    //## auto_generated 
    void setGyroFilterZero(double  p_gyroFilterZero);
    
    //## auto_generated 
    double getGyroGain() const;
    
    //## auto_generated 
    void setGyroGain(double  p_gyroGain);
    
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
    ControlDesigner* getItsControlDesigner() const;
    
    //## auto_generated 
    void setItsControlDesigner(ControlDesigner*  p_ControlDesigner);


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
public :
    
    double* A;		//## attribute A 
    
    double* B;		//## attribute B 
    
    double* C;		//## attribute C 
    
    double * D;		//## attribute D 
    
    // W2
    double accelGain;		//## attribute accelGain 
    
    // = 100
    double antiAliasGain;		//## attribute antiAliasGain 
    
    // -100
    double antiAliasPole;		//## attribute antiAliasPole 
    
    // -W4
    double gyroFilterPole;		//## attribute gyroFilterPole 
    
    // -W3
    double gyroFilterZero;		//## attribute gyroFilterZero 
    
    // W1
    double gyroGain;		//## attribute gyroGain 
    
    int nu;		//## attribute nu 
    
    int nx;		//## attribute nx 
    
    int ny;		//## attribute ny 
    
    double period;		//## attribute period 
    

////    Relations and components    ////
protected :
    
    ControlDesigner* itsControlDesigner;		//## link itsControlDesigner 
    


};


#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\AutoPilotCoeff.h
*********************************************************************/

