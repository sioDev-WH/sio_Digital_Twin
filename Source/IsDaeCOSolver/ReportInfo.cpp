#include "StdAfx.h"
#include "ReportInfo.h"
#include "OnDaeCOSolverMacros.h"
#include "stdio.h"

ReportInfo::ReportInfo()
{
  m_StepperCalls = m_functionCalls = m_jacobiansCalls = m_DecompCalls = m_Substitutions = m_TotalSteps
					= m_errorRejectedSteps = m_newtonRejectedSteps = m_growthRejectedSteps
					= m_funcRejectedSteps = m_idid = m_nStateEvents = m_nParameterEvents = m_nStepSizeChanges = 0;
  m_ierr=false;
}

ReportInfo::~ReportInfo() 
{ 

}

bool ReportInfo::Load(FILE* fs)
{
  const long m_classId = 1011;
  const long m_schema = 1;

  long classId;
  long schema;
  bool bRet = false;

  READ_SCALAR( classId )
  if (classId != m_classId) { _ASSERTE(0); return false; }

  READ_SCALAR( schema )

  switch (schema)
  {
  case 1:
    READ_SCALAR( m_StepperCalls )
	  READ_SCALAR( m_functionCalls )
	  READ_SCALAR( m_jacobiansCalls )
	  READ_SCALAR( m_DecompCalls )
	  READ_SCALAR( m_Substitutions )
	  READ_SCALAR( m_TotalSteps )
	  READ_SCALAR( m_errorRejectedSteps )
	  READ_SCALAR( m_newtonRejectedSteps )
	  READ_SCALAR( m_growthRejectedSteps )
	  READ_SCALAR( m_funcRejectedSteps )
	  READ_SCALAR( m_idid )
	  READ_SCALAR( m_ierr )
    READ_SCALAR( m_nStateEvents )
    READ_SCALAR( m_nParameterEvents )
    bRet = true;

    break;
  
  }

  return bRet;
}

void ReportInfo::Save(FILE* fs)
{
  const long m_classId = 1011;
  const long m_schema = 1;

  WRITE_SCALAR( m_classId )
  WRITE_SCALAR( m_schema )

  WRITE_SCALAR( m_StepperCalls )
	WRITE_SCALAR( m_functionCalls )
	WRITE_SCALAR( m_jacobiansCalls )
	WRITE_SCALAR( m_DecompCalls )
	WRITE_SCALAR( m_Substitutions )
	WRITE_SCALAR( m_TotalSteps )
	WRITE_SCALAR( m_errorRejectedSteps )
	WRITE_SCALAR( m_newtonRejectedSteps )
	WRITE_SCALAR( m_growthRejectedSteps )
	WRITE_SCALAR( m_funcRejectedSteps )
	WRITE_SCALAR( m_idid )
	WRITE_SCALAR( m_ierr )
  WRITE_SCALAR( m_nStateEvents )
  WRITE_SCALAR( m_nParameterEvents )
}