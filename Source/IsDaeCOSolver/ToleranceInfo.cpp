#include "StdAfx.h"
#include "ToleranceInfo.h"
#include "OnDaeCOSolverMacros.h"
#include "stdio.h"

ToleranceInfo::ToleranceInfo()
{
  m_scalar=true; 
  m_atol = NULL;
  m_rtol = NULL;
  m_Size = 0;
}

ToleranceInfo::~ToleranceInfo() 
{ 
  Destroy(); 
}

void ToleranceInfo::Destroy()
{
  Destroy_rtol();
  Destroy_atol();
}

void ToleranceInfo::Destroy_atol()
{
  DESTROY_VECTOR(m_atol)
}

void ToleranceInfo::Destroy_rtol()
{
  DESTROY_VECTOR(m_rtol)
}

void ToleranceInfo::Init(bool bScalar, long nVars)
{
  m_Size = nVars;
  Init_atol(bScalar, nVars);
  Init_rtol(bScalar, nVars);
}

void ToleranceInfo::Init_atol(bool bScalar, long nVars)
{
  long i;
  m_Size = nVars;
  long nSize = bScalar ? 1 : nVars;
  DESTROY_VECTOR(m_atol)
  m_atol = new double[nSize];
  for (i = 0; i < nSize; i++) m_atol[i] = 1e-4;
  if (!bScalar && m_scalar)
  {
    DESTROY_VECTOR(m_rtol)
    m_rtol = new double[nSize];
    for (i = 0; i < nSize; i++) m_rtol[i] = 1e-4;
  }
  m_scalar = bScalar;
}

void ToleranceInfo::Init_rtol(bool bScalar, long nVars)
{
  long i;
  m_Size = nVars;
  long nSize = bScalar ? 1 : nVars;
  DESTROY_VECTOR(m_rtol)
  m_rtol = new double[nSize];
  for (i = 0; i < nSize; i++) m_rtol[i] = 1e-4;
  if (!bScalar && m_scalar)
  {
    DESTROY_VECTOR(m_atol)
    m_atol = new double[nSize];
    for (i = 0; i < nSize; i++) m_atol[i] = 1e-4;
  }
  m_scalar = bScalar;
}


bool ToleranceInfo::Load(FILE* fs)
{
  const long m_classId = 1013;
  const long m_schema = 1;

  long classId;
  long schema;
  long size;
  bool bRet = false;

  READ_SCALAR( classId )
  if (classId != m_classId) { _ASSERTE(0); return false; }

  READ_SCALAR( schema )

  switch (schema)
  {
  case 1:
    READ_SCALAR( m_scalar )
	  READ_SCALAR( size )

    if (size != m_Size) { _ASSERTE(0); return false; }

    READ_VECTOR( m_atol, double, m_Size )
    READ_VECTOR( m_rtol, double, m_Size )
    bRet = true;

    break;

  }

  return bRet;
}

void ToleranceInfo::Save(FILE* fs)
{
  const long m_classId = 1013;
  const long m_schema = 1;

  WRITE_SCALAR( m_classId )
  WRITE_SCALAR( m_schema )

  WRITE_SCALAR( m_scalar )
	WRITE_SCALAR( m_Size )

  WRITE_VECTOR( m_atol, double, m_Size )
  WRITE_VECTOR( m_rtol, double, m_Size )
}
