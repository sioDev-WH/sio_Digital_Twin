#ifndef __TESTHARNESS_H
#define __TESTHARNESS_H

// =====================================================================================
// NOTE: Modifications for new test applications
//
// insert your application class name and header file reference here!
//

#define APP_HARNESS_CAR_APP 0

#if APP_HARNESS_CAR_APP 
  #define APP_CLASS_NAME Car_app
  #include "Car_app.h"
#else


  #define APP_CLASS_NAME Car_app5
  #include "Car_app5.h"

  //#define APP_CLASS_NAME Demo_ECMSD_app
  //#include "Demo_ECMSD_app.h"



#endif

#include "RtsOnTransmissionExport.h"

//
// =====================================================================================


#include "AppHarness.h"

class TestHarness : public AppHarness<APP_CLASS_NAME>
{
};

#endif










