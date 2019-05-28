#include "StdAfx.h"
#include "IndexInfo.h"
#include "OnDaeCOSolverMacros.h"
#include "stdio.h"

#if 0
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#endif

IndexInfo::IndexInfo()
{
  m_scalar = true; 
  m_daeIndex = NULL; 
  m_Size = 0;
}

IndexInfo::~IndexInfo() 
{ 
  Destroy(); 
}

void IndexInfo::Destroy()
{
  DESTROY_VECTOR(m_daeIndex)
}

void IndexInfo::Init(long nEqns)
{
  long i;
  m_Size = nEqns;
  DESTROY_VECTOR(m_daeIndex)
  m_daeIndex = new short[m_Size];
  for (i = 0; i < m_Size; i++) m_daeIndex[i] = 0;
}


bool IndexInfo::Load(FILE* fs)
{
  const long m_schema = 1;
  const long m_classId = 1002;

  long classId;
  long schema;
  bool bRet = false;

  READ_SCALAR( classId )
  if (classId != m_classId) { _ASSERTE(0); return false; }

  READ_SCALAR( schema )

  switch (schema)
  {
  case 1:
    READ_SCALAR( m_scalar )
    READ_VECTOR( m_daeIndex, short, m_Size )
    READ_SCALAR( m_isHighIndex )
    bRet = true;
    break;
  }

  return bRet;
}

void IndexInfo::Save(FILE* fs)
{
  const long m_schema = 1;
  const long m_classId = 1002;

  WRITE_SCALAR( m_classId )
  WRITE_SCALAR( m_schema )

  WRITE_SCALAR( m_scalar )
  WRITE_VECTOR( m_daeIndex, short, m_Size )
  WRITE_SCALAR( m_isHighIndex )
}

