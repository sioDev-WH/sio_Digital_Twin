/********************************************************************
	Rhapsody	: 4.0 
	Login		: Bradshaw
	Component	: DefaultComponent 
	Configuration 	: DefaultConfig
	Model Element	: Controller
//!	Generated Date	: Sun, 15, Sep 2002  
	File Path	: DefaultComponent\DefaultConfig\Controller.cpp
*********************************************************************/

#include "stdafx.h"
#include <oxf/omthread.h>
#include "Controller.h"
#include "OnAD.h"
#include "Reactor.h"
#include "Heater.h"

//## package ProcessModels 

//----------------------------------------------------------------------------
// Controller.cpp                                                                  
//----------------------------------------------------------------------------
//## class Controller 



Controller::Controller(OMThread*  p_thread) : S_integrator(223.0) ,T_data_in(740.0) ,Setpoint(740.0) ,Kp(20.0) ,Ki(0.3) ,K(1.0) {
    setThread(p_thread, FALSE);

    itsHeater = NULL;
    itsReactor = NULL;
    t_last = 0.0;
}

Controller::~Controller() {
}


double Controller::get_Output(double t)
{
  double delta_t = t - t_last;

  t_last = t;
  T_data_in = itsReactor->getT_reactor(t); 
  S_integrator += delta_t * 0.05 * (Kp * (Setpoint - K * T_data_in) / Ki);
  return 0.1 * Kp * ( Setpoint - K * T_data_in) + S_integrator;
}


void Controller::Save(FILE* fs)
{
  WRITE_SCALAR( K )
  WRITE_SCALAR( Ki )
  WRITE_SCALAR( Kp )
  WRITE_SCALAR( S_integrator )
  WRITE_SCALAR( Setpoint )
  WRITE_SCALAR( T_data_in )
  WRITE_SCALAR( t_last )
}

bool Controller::Load(FILE* fs)
{
  READ_SCALAR( K )
  READ_SCALAR( Ki )
  READ_SCALAR( Kp )
  READ_SCALAR( S_integrator )
  READ_SCALAR( Setpoint )
  READ_SCALAR( T_data_in )
  READ_SCALAR( t_last )

  return true;
}

/*********************************************************************
	File Path	: DefaultComponent\DefaultConfig\Controller.cpp
*********************************************************************/

