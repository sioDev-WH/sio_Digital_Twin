#include "StdAfx.h"
#include "TransitionInfo.h"
#include "OnDaeCOSolverMacros.h"

#if 0
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#endif

TransitionInfo::TransitionInfo() 
{ 
  Name = NULL;
  EventId = NULL;
  SourceState = -1;
  EqnIndices = NULL;
  nEqns = 0;
}

TransitionInfo::~TransitionInfo()
{
  ::SysFreeString(EventId);
  ::SysFreeString(Name);
  DESTROY_VECTOR(EqnIndices)
}

BSTR TransitionInfo::getName()
{ 
  return SysAllocString(Name); 
}

void TransitionInfo::setName(const _TCHAR* val) 
{ 
  ::SysFreeString(Name);
  Name = SysAllocString(val); 
}

BSTR TransitionInfo::getEventId() 
{ 
  return SysAllocString(EventId); 
}

void TransitionInfo::setEventId(const _TCHAR* Id) 
{ 
  ::SysFreeString(EventId); 
  EventId = SysAllocString(Id); 
}

void TransitionInfo::setEqns(const long* Indices, const long count) 
{ 
  long i;

  nEqns = count;
  DESTROY_VECTOR(EqnIndices)
  EqnIndices = new long[nEqns];
  for (i = 0; i < nEqns; i++) EqnIndices[i] = Indices[i];
}

void TransitionInfo::getEqns(long** Indices, long* count)
{
  long i;

  *count = nEqns;
  *Indices = NULL;
  if (nEqns > 0)
  {
    *Indices = new long[nEqns];
    for (i = 0; i < nEqns; i++) (*Indices)[i] = EqnIndices[i];
  }
}

