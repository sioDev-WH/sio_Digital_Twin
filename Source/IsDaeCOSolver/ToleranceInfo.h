#ifndef _TOLERANCE_INFO_
#define _TOLERANCE_INFO_

#include "OnDaeCOSolverExport.h"


class ONDAECOSOLVER_API ToleranceInfo 
{
public:
	ToleranceInfo();
  ~ToleranceInfo();

  void Destroy();

  void Destroy_atol();
  void Destroy_rtol();
  void Init(bool bScalar, long nVars);
  void Init_atol(bool bScalar, long nVars);
  void Init_rtol(bool bScalar, long nVars);

  bool Load(FILE* fs);
  void Save(FILE* fs);

public:
	bool	m_scalar; // Tolerance is specified as a scalar
	double*	m_atol;	  // absolute tolerances to control local error
	double*	m_rtol;   // relative tolerances to control local error
  long m_Size;

};

#endif // _TOLERANCE_INFO_