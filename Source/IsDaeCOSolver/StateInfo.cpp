
#include "StdAfx.h"
#include "StateInfo.h"
#include "OnDaeCOSolverMacros.h"

#if 0
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#endif

StateInfo::StateInfo() 
{ 
  EqnIndices = NULL;
  nEqns = 0;
  Name = NULL;
}

StateInfo::~StateInfo()
{
  DESTROY_VECTOR(EqnIndices)
  ::SysFreeString(Name);
}

BSTR StateInfo::getName() 
{ 
  return ::SysAllocString(Name); 
}

void StateInfo::setName(const TCHAR* val) 
{ 
  ::SysFreeString(Name); 
  Name = ::SysAllocString(val); 
}

void StateInfo::setEqns(const long* Indices, const long count) 
{ 
  long i;

  nEqns = count;
  DESTROY_VECTOR(EqnIndices)
  EqnIndices = new long[nEqns];
  for (i = 0; i < nEqns; i++) EqnIndices[i] = Indices[i];
}

void StateInfo::getEqns(long** Indices, long* count)
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

