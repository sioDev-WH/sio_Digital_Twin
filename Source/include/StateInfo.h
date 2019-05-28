#ifndef _STATEINFO_
#define _STATEINFO_

#include "OnDaeCOSolverExport.h"

class ONDAECOSOLVER_API StateInfo
{
public:
  StateInfo(); 
  ~StateInfo();

  BSTR getName();
  void setName(const TCHAR* val);

  void setEqns(const long* Indices, const long count);
  void getEqns(long** Indices, long* count);

public:
  long* EqnIndices;
  long nEqns;

protected:
  BSTR Name;
};

#endif // _STATEINFO_
