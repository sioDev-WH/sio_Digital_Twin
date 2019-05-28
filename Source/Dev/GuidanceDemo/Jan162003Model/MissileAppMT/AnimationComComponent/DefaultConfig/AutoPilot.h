/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Hafezw
	Component	: AnimationComComponent 
	Configuration 	: DefaultConfig
	Model Element	: AutoPilot
//!	Generated Date	: Thu, 16, Jan 2003  
	File Path	: AnimationComComponent\DefaultConfig\AutoPilot.h
*********************************************************************/


#ifndef AutoPilot_H 

#define AutoPilot_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include <stdafx.h>
#include "AutopilotPkg.h"
#include "OnModelBase.h"

//## package AutopilotPkg 

//----------------------------------------------------------------------------
// AutoPilot.h                                                                  
//----------------------------------------------------------------------------
class AutoPilotCoeff;

#ifdef _OMINSTRUMENT
class OMAnimatedAutoPilot;
#endif // _OMINSTRUMENT


//## class AutoPilot 
class AutoPilot : public COnModelBase {


////    Friends    ////
public :
    
    
#ifdef _OMINSTRUMENT
    friend  class OMAnimatedAutoPilot;
#endif // _OMINSTRUMENT


////    Constructors and destructors    ////
public :
    
    //## operation AutoPilot() 
    AutoPilot();
    
    //## auto_generated 
    ~AutoPilot();


////    Operations    ////
public :
    
    //## operation clean() 
    void clean();
    
    //## operation computeFinControlSignal(const double) 
    void computeFinControlSignal(const double  t);
    
    //## operation get_Fin(const double,double *) 
    void get_Fin(const double  t, double *val);
    
    // perform discrete state updates (including computation of sub-blocks, calling their corresponding update methods and communicating input/output data directly through get and set accessors/mutators)
    //## operation handle_tick(const double) 
    void handle_tick(const double  t);
    
    //## operation init() 
    void init();
    
    //## operation set_accelData(const double,double *) 
    void set_accelData(const double  t, double *val);
    
    //## operation set_command(const double,double *) 
    void set_command(const double  t, double *val);
    
    //## operation set_gyroData(const double,double *) 
    void set_gyroData(const double  t, double *val);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getFin() const;
    
    //## auto_generated 
    void setFin(double  p_Fin);
    
    //## auto_generated 
    double getAccelData() const;
    
    //## auto_generated 
    void setAccelData(double  p_accelData);
    
    //## auto_generated 
    double getCommand() const;
    
    //## auto_generated 
    void setCommand(double  p_command);
    
    //## auto_generated 
    double getGyroData() const;
    
    //## auto_generated 
    void setGyroData(double  p_gyroData);
    
    //## auto_generated 
    double getOldGyroData() const;
    
    //## auto_generated 
    void setOldGyroData(double  p_oldGyroData);
    
    //## auto_generated 
    double getOld_Fin() const;
    
    //## auto_generated 
    void setOld_Fin(double  p_old_Fin);
    
    //## auto_generated 
    double* getOld_u() const;
    
    //## auto_generated 
    void setOld_u(double*  p_old_u);
    
    //## auto_generated 
    double* getOld_x() const;
    
    //## auto_generated 
    void setOld_x(double*  p_old_x);
    
    //## auto_generated 
    double* getU() const;
    
    //## auto_generated 
    void setU(double*  p_u);
    
    //## auto_generated 
    double* getX() const;
    
    //## auto_generated 
    void setX(double*  p_x);
    
    //## auto_generated 
    AutoPilotCoeff* getCoeff() const;
    
    //## auto_generated 
    void setCoeff(AutoPilotCoeff*  p_AutoPilotCoeff);


////    Framework operations    ////
protected :
    
    //## auto_generated 
    void cleanUpRelations();


////    Attributes    ////
public :
    
    double oldGyroData;		//## attribute oldGyroData 
    
    double old_Fin;		//## attribute old_Fin 
    
    double* old_u;		//## attribute old_u 
    
    double* old_x;		//## attribute old_x 
    
protected :
    
    double Fin;		//## attribute Fin 
    
    double accelData;		//## attribute accelData 
    
    double command;		//## attribute command 
    
    double gyroData;		//## attribute gyroData 
    
    double* u;		//## attribute u 
    
    double* x;		//## attribute x 
    

////    Relations and components    ////
protected :
    
    AutoPilotCoeff* Coeff;		//## link Coeff 
    


};


#ifdef _OMINSTRUMENT
//## ignore 
class OMAnimatedAutoPilot : virtual public AOMInstance {

    
    DECLARE_META(AutoPilot, OMAnimatedAutoPilot)


////    Framework operations    ////
public :
    
    virtual void serializeAttributes(AOMSAttributes*  aomsAttributes) const;
    
    virtual void serializeRelations(AOMSRelations*  aomsRelations) const;


};

#endif // _OMINSTRUMENT

#endif  
/*********************************************************************
	File Path	: AnimationComComponent\DefaultConfig\AutoPilot.h
*********************************************************************/

