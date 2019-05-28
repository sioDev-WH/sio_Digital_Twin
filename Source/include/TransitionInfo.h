#ifndef _TRANSITIONINFO_
#define _TRANSITIONINFO_

#include "OnDaeCOSolverExport.h"


class ONDAECOSOLVER_API TransitionInfo
{
public:
  TransitionInfo(); 
  ~TransitionInfo();

  BSTR getName();
  void setName(const _TCHAR* val);

  BSTR getEventId();
  void setEventId(const _TCHAR* Id);
  void setEqns(const long* Indices, const long count); 
  void getEqns(long** Indices, long* count);

public:
  long SourceState;
  long* EqnIndices;
  long nEqns;

protected:
  BSTR EventId;
  BSTR Name;
};

#endif // _TRANSITIONINFO_
