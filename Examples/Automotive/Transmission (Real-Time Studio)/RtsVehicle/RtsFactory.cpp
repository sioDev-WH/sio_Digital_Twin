#include "StdAfx.h"
#include "RtsSmSim.h"
#include "TestHarness.h"

const static RtsClassInfo RtsModelInfo("eafa134c-6337-11d5-b148-00c04f680d9d", RTS_MODEL);

PTR_STATE_MACHINE RtsStateMachineFactory()
{
     return new TestHarness;
}
void RtsDestroyStateMachine(PTR_STATE_MACHINE pObject)
{
     delete (TestHarness*)pObject;
}
