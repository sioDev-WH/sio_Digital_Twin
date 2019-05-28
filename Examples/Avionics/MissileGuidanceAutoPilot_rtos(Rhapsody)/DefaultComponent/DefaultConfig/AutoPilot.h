/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: AutoPilot
//!	Generated Date	: Mon, 13, Oct 2003  
	File Path	: DefaultComponent\DefaultConfig\AutoPilot.h
*********************************************************************/


#ifndef AutoPilot_H 

#define AutoPilot_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "AutopilotPkg.h"
#include "OnModelBase.h"

//## package AutopilotPkg 

//----------------------------------------------------------------------------
// AutoPilot.h                                                                  
//----------------------------------------------------------------------------
class AutoPilotCoeff;


//## class AutoPilot 
class AutoPilot : public COnModelBase {


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
    
    //## operation computeFinControlSignal() 
    void computeFinControlSignal();
    
    // perform discrete state updates (including computation of sub-blocks, calling their corresponding update methods and communicating input/output data directly through get and set accessors/mutators)
    //## operation handle_tick() 
    void handle_tick();
    
    //## operation init() 
    void init();
    
    //## operation setPeriod(long) 
    void setPeriod(long  val);


////    Additional operations    ////
public :
    
    //## auto_generated 
    double getAlpha() const;
    
    //## auto_generated 
    void setAlpha(double  p_Alpha);
    
    //## auto_generated 
    double getFin() const;
    
    //## auto_generated 
    void setFin(double  p_Fin);
    
    //## auto_generated 
    double getMach() const;
    
    //## auto_generated 
    void setMach(double  p_Mach);
    
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
    double* getX() const;
    
    //## auto_generated 
    void setX(double*  p_x);
    
    //## auto_generated 
    double getY() const;
    
    //## auto_generated 
    void setY(double  p_y);
    
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
    
    double Alpha;		//## attribute Alpha 
    
    double Fin;		//## attribute Fin 
    
    double Mach;		//## attribute Mach 
    
    double accelData;		//## attribute accelData 
    
    double command;		//## attribute command 
    
    double gyroData;		//## attribute gyroData 
    
    double* x;		//## attribute x 
    
    double y;		//## attribute y 
    

////    Relations and components    ////
protected :
    
    AutoPilotCoeff* Coeff;		//## link Coeff 
    


};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\AutoPilot.h
*********************************************************************/

