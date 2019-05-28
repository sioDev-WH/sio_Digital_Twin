// GuidanceApp2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <initguid.h>
#include "IsDaeCOSolver.h"
#include "IsDaeCOSolver_i.c"

#include "AirFrameAutoPilotSystem.h"

int main(int argc, char* argv[])
{
  double t = 0.0;
  AirFrameAutoPilotSystem* test = NULL;

  if(OXF::init(argc, argv, 6423))
  {
    //DefaultComponent initializer_DefaultComponent;
    //#[ configuration DefaultComponent::Animation 
    test = new AirFrameAutoPilotSystem();
    test->initSimulation(); 
    //#]
    
    while (t < 10.0)
    {
      test->handle_tick(t);
      t += 0.001;
    }
    
    test->termSimulation();
    delete test;
    OXF::start();
    
    return 0;
  }
  else
    return 1;
}
