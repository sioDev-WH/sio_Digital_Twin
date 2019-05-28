/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: ScheduledController_1D_Coeff
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\ScheduledController_1D_Coeff.h
*********************************************************************/


#ifndef ScheduledController_1D_Coeff_H 

#define ScheduledController_1D_Coeff_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "AvionicsPkg.h"

//## package LibraryPkg::AvionicsPkg 

//----------------------------------------------------------------------------
// ScheduledController_1D_Coeff.h                                                                  
//----------------------------------------------------------------------------
class ControlDesigner;

#ifdef _OMINSTRUMENT
class OMAnimatedScheduledController_1D_Coeff;
#endif // _OMINSTRUMENT


//## class ScheduledController_1D_Coeff 
class ScheduledController_1D_Coeff  {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedScheduledController_1D_Coeff;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation ScheduledController_1D_Coeff() 
    ScheduledController_1D_Coeff();
    
    //## operation ~ScheduledController_1D_Coeff() 
    ~ScheduledController_1D_Coeff();


////    Operations    ////
public :
    
    //## operation clean() 
    void clean();
    
    //## operation init(int,double [],double,int,int,int,double [],double [],double [],double [],double []) 
    void init(int  Nv, double V[], double  V0, int  Nx, int  Nu, int  Ny, double Ac[], double Bc[], double Cc[], double Dc[], double X0[]);
    
    //## operation locate(double,int* ) 
    void locate(double  val, int*  index);
    
    //## operation update(double) 
    void update(double  val);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double* getA() const;
    
    //## auto_generated 
    void setA(double*  p_A);
    
    //## auto_generated 
    double* getAv() const;
    
    //## auto_generated 
    void setAv(double*  p_Av);
    
    //## auto_generated 
    double* getB() const;
    
    //## auto_generated 
    void setB(double*  p_B);
    
    //## auto_generated 
    double* getBv() const;
    
    //## auto_generated 
    void setBv(double*  p_Bv);
    
    //## auto_generated 
    double* getC() const;
    
    //## auto_generated 
    void setC(double*  p_C);
    
    //## auto_generated 
    double* getCv() const;
    
    //## auto_generated 
    void setCv(double*  p_Cv);
    
    //## auto_generated 
    double *  getD() const;
    
    //## auto_generated 
    void setD(double * p_D);
    
    //## auto_generated 
    double *  getDv() const;
    
    //## auto_generated 
    void setDv(double * p_Dv);
    
    //## auto_generated 
    int getNu() const;
    
    //## auto_generated 
    void setNu(int  p_nu);
    
    //## auto_generated 
    int getNv() const;
    
    //## auto_generated 
    void setNv(int  p_nv);
    
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
    double* getV() const;
    
    //## auto_generated 
    void setV(double*  p_v);
    
    //## auto_generated 
    double getV0() const;
    
    //## auto_generated 
    void setV0(double  p_v0);
    
    //## auto_generated 
    double* getX0() const;
    
    //## auto_generated 
    void setX0(double*  p_x0);
    
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
    
    double* Av;		//## attribute Av 
    
    double* B;		//## attribute B 
    
    double* Bv;		//## attribute Bv 
    
    double* C;		//## attribute C 
    
    double* Cv;		//## attribute Cv 
    
    double * D;		//## attribute D 
    
    double * Dv;		//## attribute Dv 
    
    int nu;		//## attribute nu 
    
    int ny;		//## attribute ny 
    
    double period;		//## attribute period 
    
protected :
    
    int nv;		//## attribute nv 
    
    int nx;		//## attribute nx 
    
    double* v;		//## attribute v 
    
    double v0;		//## attribute v0 
    
    double* x0;		//## attribute x0 
    

////    Relations and components    ////
protected :
    
    ControlDesigner* itsControlDesigner;		//## link itsControlDesigner 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedScheduledController_1D_Coeff : virtual public AOMInstance {

    
    DECLARE_META(ScheduledController_1D_Coeff, OMAnimatedScheduledController_1D_Coeff)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\ScheduledController_1D_Coeff.h
*********************************************************************/

