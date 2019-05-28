#include "StdAfx.h"
//#include "RtsSmSim.h"
//#include "RtsSmTgt.h"
#include "TestHarness.h"

// NOTE: APP_CLASS_NAME is defined in TestHarness.h

//const static RtsClassInfo RtsModelInfo("eafa134c-6337-11d5-b148-00c04f680d9d", RTS_MODEL);
typedef void *PTR_STATE_MACHINE;

PTR_STATE_MACHINE RtsStateMachineFactory()
{
  return new AppHarness<APP_CLASS_NAME>;
}
void RtsDestroyStateMachine(PTR_STATE_MACHINE pObject)
{
  delete (AppHarness<APP_CLASS_NAME>*)pObject;
}




/*

Removed link settings:

  SMHarnessD.lib


Removed preprocessor settings:
  RTS_SIMULATION


Force symbol references (in link settings):
  _RtsStartTimers@0







*/