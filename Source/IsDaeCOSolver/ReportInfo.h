#ifndef _REPORT_INFO_H_
#define _REPORT_INFO_H_


class ReportInfo 
{

public:
	ReportInfo();
  ~ReportInfo();

  bool Load(FILE* fs);
  void Save(FILE* fs);

public:
	long	m_StepperCalls;
	long	m_functionCalls;
	long	m_jacobiansCalls; // DfDy and DfDydot
	long	m_DecompCalls;	// e.g., LU decomp
	long	m_Substitutions;
	long	m_TotalSteps;
	long	m_errorRejectedSteps;
	long	m_newtonRejectedSteps;
	long	m_growthRejectedSteps;
	long	m_funcRejectedSteps;	// func call failed
	long	m_idid;	// Error codes for failure
	bool	m_ierr; // last m_fcn call failed
  long  m_nStateEvents;
  long  m_nParameterEvents;
  long  m_nStepSizeChanges;
};

#endif // _REPORT_INFO_H_