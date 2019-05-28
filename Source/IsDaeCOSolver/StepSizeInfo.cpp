#include "StdAfx.h"
#include "StepSizeInfo.h"
#include "OnDaeCOSolverMacros.h"
#include "stdio.h"

StepSizeInfo::StepSizeInfo() 
{
  m_adaptive = true; 
	m_initVal = m_maxVal = m_min_Val = m_curVal = m_lastVal = 0.0;
	m_minChangeFactor = 0.2E0;
  m_maxChangeFactor = 2.0E0;
  m_eventChangeFactor = 4.0E0; // step size increase factor applied after events
  m_maxEventStepCount = 10;    // eventchangeFactor active for 10 successful newton steps
  m_eventStepCount = 0;
  m_eventChangeFactorApplied = false;
	m_rigidChangeFactor = 2.0E0;
  m_alignmentFactor = 0.05e0;
	m_updateFormulaCoeff = 0.8E0;
  m_updateFormulaMinExponent = 0.1E0;
}

StepSizeInfo::~StepSizeInfo() 
{ 

}

bool StepSizeInfo::Load(FILE* fs)
{
  const long m_classId = 1012;
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
    READ_SCALAR( m_adaptive )
    READ_SCALAR( m_lastVal )
    READ_SCALAR( m_maxVal )
    READ_SCALAR( m_min_Val )
    READ_SCALAR( m_curVal )
    READ_SCALAR( m_predictedVal )
    READ_SCALAR( m_LUVal )
    READ_SCALAR( m_minChangeFactor )
    READ_SCALAR( m_maxChangeFactor )
    READ_SCALAR( m_eventChangeFactor )
    READ_SCALAR( m_eventStepCount )
    READ_SCALAR( m_maxEventStepCount )
    READ_SCALAR( m_eventChangeFactorApplied )
    READ_SCALAR( m_rigidChangeFactor )
    READ_SCALAR( m_alignmentFactor )
    READ_SCALAR( m_updateFormulaCoeff )
    READ_SCALAR( m_updateFormulaMinExponent )
    bRet = true;

    break;

  }
  return bRet;
}

void StepSizeInfo::Save(FILE* fs)
{
  const long m_classId = 1012;
  const long m_schema = 1;

  WRITE_SCALAR( m_classId )
  WRITE_SCALAR( m_schema )

  WRITE_SCALAR( m_adaptive )
  WRITE_SCALAR( m_lastVal )
  WRITE_SCALAR( m_maxVal )
  WRITE_SCALAR( m_min_Val )
  WRITE_SCALAR( m_curVal )
  WRITE_SCALAR( m_predictedVal )
  WRITE_SCALAR( m_LUVal )
  WRITE_SCALAR( m_minChangeFactor )
  WRITE_SCALAR( m_maxChangeFactor )
  WRITE_SCALAR( m_eventChangeFactor )
  WRITE_SCALAR( m_eventStepCount )
  WRITE_SCALAR( m_maxEventStepCount )
  WRITE_SCALAR( m_eventChangeFactorApplied )
  WRITE_SCALAR( m_rigidChangeFactor )
  WRITE_SCALAR( m_alignmentFactor )
  WRITE_SCALAR( m_updateFormulaCoeff )
  WRITE_SCALAR( m_updateFormulaMinExponent )
}