/*********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Controller
//!	Generated Date	: Sun, 15, Sep 2002  
	File Path	: DefaultComponent\DefaultConfig\Controller.h
*********************************************************************/


#ifndef Controller_H 

#define Controller_H 


//#[ ignore 
#define _OMFLAT_IMPLEMENTATION 1
//#]

#include <oxf/oxf.h>
#include "ProcessModels.h"
#include <oxf/omreactive.h>
#include <oxf/state.h>
#include <oxf/event.h>
#include "OnModel_Controller.h"

//## package ProcessModels 

//----------------------------------------------------------------------------
// Controller.h                                                                  
//----------------------------------------------------------------------------
class Fdouble;


//## class Controller 
class Controller : public OMReactive {


////    Constructors and destructors    ////
public :
    
    //## auto_generated 
    Controller(OMThread*  p_thread = OMDefaultThread);
    
    //## auto_generated 
    ~Controller();


////    Operations    ////
public :
    
    //## operation get_Output() 
    double get_Output(double t);
    void Save(FILE* fs);
    bool Load(FILE* fs);

////    Attributes    ////
public :
    
    double K;		//## attribute K 
    
    double Ki;		//## attribute Ki 
    
    double Kp;		//## attribute Kp 
    
    double S_integrator;		//## attribute S_integrator 
    
    double Setpoint;		//## attribute Setpoint 
    
    double T_data_in;		//## attribute T_data_in 
    
    double t_last;

////    Relations and components    ////
public :
    
    Heater* itsHeater;
    Reactor* itsReactor;

};


#endif  
/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Controller.h
*********************************************************************/

