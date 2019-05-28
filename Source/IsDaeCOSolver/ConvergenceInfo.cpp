#include "StdAfx.h"
#include "ConvergenceInfo.h"
#include "OnDaeCOSolverMacros.h"
#include "stdio.h"

#if 0
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#endif


ConverganceInfo::ConverganceInfo()
{
  m_curVal = m_curRate = 0.0;
  m_growing=m_diverged = m_converged = false;
  m_newtonIterationIndex = 0;
  m_newtonIterationMaxIndex = 15;
  m_tau = 0.01;
  m_kappa = 100.0; 
  m_gamma = 1.0;
  m_theta = 0.5; 
  m_gfac = 100.0; //100.0;
  m_initialRate = 0.1;
  m_desiredRate = 0.15e0;
  m_updateThresholdRate = 0.1e0;
  m_decompositionThresholdRate = 0.2e0;
  m_rateFactor = 1.2e0;
}


ConverganceInfo::~ConverganceInfo() 
{ 

}

bool ConverganceInfo::Load(FILE* fs)
{
  const long m_schema = 1;
  const long m_classId = 1001;

  long classId;
  long schema;
  bool bRet = false;

  READ_SCALAR( classId )
  if (classId != m_classId) { _ASSERTE(0); return false; }

  READ_SCALAR( schema )

  switch (schema)
  {
  case 1:
    READ_SCALAR( m_ready )
    READ_SCALAR( m_slow )
    READ_SCALAR( m_solved )
    READ_SCALAR( m_exact )
    READ_SCALAR( m_curVal )
    READ_SCALAR( m_curRate )
    READ_SCALAR( m_initialRate )
    READ_SCALAR( m_rateFactor )
    READ_SCALAR( m_desiredRate )
    READ_SCALAR( m_updateThresholdRate ) 
    READ_SCALAR( m_decompositionThresholdRate ) 
	  READ_SCALAR( m_growing )
	  READ_SCALAR( m_diverged )
	  READ_SCALAR( m_converged )
	  READ_SCALAR( m_newtonIterationIndex )
	  READ_SCALAR( m_newtonIterationMaxIndex )
	  READ_SCALAR( m_tau )
	  READ_SCALAR( m_kappa ) 
	  READ_SCALAR( m_gamma ) 
	  READ_SCALAR( m_theta )
	  READ_SCALAR( m_gfac )  
	  READ_SCALAR( m_uround )
    bRet = true;
    break;
  }

  return bRet;
}


void ConverganceInfo::Save(FILE* fs)
{
  const long m_schema = 1;
  const long m_classId = 1001;

  WRITE_SCALAR( m_classId )
  WRITE_SCALAR( m_schema )

  WRITE_SCALAR( m_ready )
  WRITE_SCALAR( m_slow )
  WRITE_SCALAR( m_solved )
  WRITE_SCALAR( m_exact )
  WRITE_SCALAR( m_curVal )
  WRITE_SCALAR( m_curRate )
  WRITE_SCALAR( m_initialRate )
  WRITE_SCALAR( m_rateFactor )
  WRITE_SCALAR( m_desiredRate )
  WRITE_SCALAR( m_updateThresholdRate ) 
  WRITE_SCALAR( m_decompositionThresholdRate ) 
	WRITE_SCALAR( m_growing )
	WRITE_SCALAR( m_diverged )
	WRITE_SCALAR( m_converged )
	WRITE_SCALAR( m_newtonIterationIndex )
	WRITE_SCALAR( m_newtonIterationMaxIndex )
	WRITE_SCALAR( m_tau )
	WRITE_SCALAR( m_kappa ) 
	WRITE_SCALAR( m_gamma ) 
	WRITE_SCALAR( m_theta )
	WRITE_SCALAR( m_gfac )  
	WRITE_SCALAR( m_uround )
}
