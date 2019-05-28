#include "StdAfx.h"
#include "VirtualTimeInfo.h"
#include "OnDaeCOSolverMacros.h"
#include "stdio.h"

#if 0
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)   
#endif
#endif

VirtualTimeInfo::VirtualTimeInfo() 
{
  m_initVal= m_curVal= m_endVal= 0.0; 
  m_reverse = false; 
  m_curIteration = m_size = 0; 
  m_sequence = NULL;
}
	
VirtualTimeInfo::VirtualTimeInfo(long nSize) 
{
  m_initVal= m_curVal= m_endVal= 0.0; 
  m_reverse = false; 
  m_curIteration=0; 
  m_size = nSize; 
  m_sequence = new double[nSize];
}
  
VirtualTimeInfo::~VirtualTimeInfo()
{
  DESTROY_VECTOR(m_sequence)
}


bool VirtualTimeInfo::Load(FILE* fs)
{
  const long m_classId = 1015;
  const long m_schema = 1;

  long classId;
  long schema;
  long size;
  short bm_sequence;
  bool bRet = false;

  READ_SCALAR( classId )
  if (classId != m_classId) { _ASSERTE(0); return false; }

  READ_SCALAR( schema )

  switch (schema)
  {
  case 1:

	  READ_SCALAR( m_curVal )
	  READ_SCALAR( m_lastVal )
	  READ_SCALAR( m_curIteration )
	  READ_SCALAR( m_endVal )
	  
    READ_SCALAR( size )

    if (size != m_size) { _ASSERTE(0); return false; }
    READ_SCALAR( bm_sequence )
    if (bm_sequence && !m_sequence) { _ASSERTE(0); return false; }
    if (m_sequence)
    {
      READ_VECTOR( m_sequence, double, m_size ) 
    }

    READ_SCALAR( m_samplingRate )
	  READ_SCALAR( m_curSampleIndex )	
    READ_SCALAR( m_reverse )
    bRet = true;
    break;
  }
  return bRet;
}

void VirtualTimeInfo::Save(FILE* fs)
{
  const long m_classId = 1015;
  const long m_schema = 1;

  short bm_sequence = m_sequence != NULL;

  WRITE_SCALAR( m_classId )
  WRITE_SCALAR( m_schema )

	WRITE_SCALAR( m_curVal )
	WRITE_SCALAR( m_lastVal )
	WRITE_SCALAR( m_curIteration )
	WRITE_SCALAR( m_endVal )
	
  WRITE_SCALAR( m_size )
  WRITE_SCALAR( bm_sequence )
  if (m_sequence)
  {
    WRITE_VECTOR( m_sequence, double, m_size )
  }

  WRITE_SCALAR( m_samplingRate )
	WRITE_SCALAR( m_curSampleIndex )	
  WRITE_SCALAR( m_reverse )
}