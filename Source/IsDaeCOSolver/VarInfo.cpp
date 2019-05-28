
#include "StdAfx.h"
#include "VarInfo.h"
#include "OnDaeCOSolverMacros.h"
#include "stdio.h"

#if 0
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)   
#endif
#endif

VarInfo::VarInfo(long nVars)
{
  m_varSize = 0;
  m_psa_var_init = NULL;
  m_psa_varDot_init = NULL;
  m_psa_varVal = NULL;
  m_psa_varDeltaVal = NULL;
  m_psa_varLastVal = NULL;
  m_psa_varDotVal = NULL;
  m_psa_varDeltaDotVal = NULL;
  m_psa_varLastDotVal = NULL;
  m_psa_residualVal = NULL;

  m_var_init = NULL;
  m_varDot_init = NULL;
  m_varVal = NULL;
  m_varDeltaVal = NULL;
  m_varLastVal = NULL;
  m_varDotVal = NULL;
  m_varDeltaDotVal = NULL;
  m_varLastDotVal = NULL;
  m_residualVal = NULL;

  CommonConstruction(nVars);
}

void VarInfo::Init(long nVars)
{ 
  CommonConstruction(nVars); 
}

void VarInfo::CommonConstruction(long nVars)
{
  SAFEARRAY* t_psa_var_init = NULL;
  SAFEARRAY* t_psa_varDot_init = NULL;
  SAFEARRAY* t_psa_varVal = NULL;
  SAFEARRAY* t_psa_varDeltaVal = NULL;
  SAFEARRAY* t_psa_varLastVal = NULL;
  SAFEARRAY* t_psa_varDotVal = NULL;
  SAFEARRAY* t_psa_varDeltaDotVal = NULL;
  SAFEARRAY* t_psa_varLastDotVal = NULL;
  SAFEARRAY* t_psa_residualVal = NULL;

  double* t_var_init = NULL;
  double* t_varDot_init = NULL;
  double* t_varVal = NULL;
  double* t_varDeltaVal = NULL;
  double* t_varLastVal = NULL;
  double* t_varDotVal = NULL;
  double* t_varDeltaDotVal = NULL;
  double* t_varLastDotVal = NULL;
  double* t_residualVal = NULL;

  bool bResize = false;
  long size = IMIN(m_varSize, nVars);
  long i;

  if (m_varSize != 0) bResize = true;
  m_varSize=nVars;

  t_psa_var_init = SafeArrayCreateVector(VT_R8, 0, m_varSize);
  t_psa_varDot_init = SafeArrayCreateVector(VT_R8, 0, m_varSize);
  t_psa_varVal = SafeArrayCreateVector(VT_R8, 0, m_varSize);
  t_psa_varDeltaVal = SafeArrayCreateVector(VT_R8, 0, m_varSize);
  t_psa_varLastVal = SafeArrayCreateVector(VT_R8, 0, m_varSize);
  t_psa_varDotVal = SafeArrayCreateVector(VT_R8, 0, m_varSize);
  t_psa_varDeltaDotVal = SafeArrayCreateVector(VT_R8, 0, m_varSize);
  t_psa_varLastDotVal = SafeArrayCreateVector(VT_R8, 0, m_varSize);
  t_psa_residualVal = SafeArrayCreateVector(VT_R8, 0, m_varSize);

  SafeArrayAccessData(t_psa_var_init, (void HUGEP* FAR*)& t_var_init);
  SafeArrayAccessData(t_psa_varDot_init, (void HUGEP* FAR*)& t_varDot_init);
  SafeArrayAccessData(t_psa_varVal, (void HUGEP* FAR*)& t_varVal);
  SafeArrayAccessData(t_psa_varDeltaVal, (void HUGEP* FAR*)& t_varDeltaVal);
  SafeArrayAccessData(t_psa_varLastVal, (void HUGEP* FAR*)& t_varLastVal);
  SafeArrayAccessData(t_psa_varDotVal, (void HUGEP* FAR*)& t_varDotVal);
  SafeArrayAccessData(t_psa_varDeltaDotVal, (void HUGEP* FAR*)& t_varDeltaDotVal);
  SafeArrayAccessData(t_psa_varLastDotVal, (void HUGEP* FAR*)& t_varLastDotVal);
  SafeArrayAccessData(t_psa_residualVal, (void HUGEP* FAR*)& t_residualVal);

  if (bResize)
  {
    for (i = 0; i < size; i++)
    {
      t_var_init[i] = m_var_init[i];
      t_varDot_init[i] = m_varDot_init[i];
      t_varVal[i] = m_varVal[i];
      t_varDeltaVal[i] = m_varDeltaVal[i];
      t_varLastVal[i] = m_varLastVal[i];
      t_varDotVal[i] = m_varDotVal[i];
      t_varDeltaDotVal[i] = m_varDeltaDotVal[i];
      t_varLastDotVal[i] = m_varLastDotVal[i];
      t_residualVal[i] = m_residualVal[i];
    }
    SA_DESTROY(m_psa_var_init)
    SA_DESTROY(m_psa_varDot_init)
    SA_DESTROY(m_psa_varVal)
    SA_DESTROY(m_psa_varDeltaVal)
    SA_DESTROY(m_psa_varLastVal)
    SA_DESTROY(m_psa_varDotVal)
    SA_DESTROY(m_psa_varDeltaDotVal)
    SA_DESTROY(m_psa_varLastDotVal)
    SA_DESTROY(m_psa_residualVal)
  }
  
  m_psa_var_init = t_psa_var_init;
  m_psa_varDot_init = t_psa_varDot_init;
  m_psa_varVal = t_psa_varVal;
  m_psa_varDeltaVal = t_psa_varDeltaVal;
  m_psa_varLastVal = t_psa_varLastVal;
  m_psa_varDotVal = t_psa_varDotVal;
  m_psa_varDeltaDotVal = t_psa_varDeltaDotVal;
  m_psa_varLastDotVal = t_psa_varLastDotVal;
  m_psa_residualVal = t_psa_residualVal;

  m_var_init = t_var_init;
  m_varDot_init = t_varDot_init;
  m_varVal = t_varVal;
  m_varDeltaVal = t_varDeltaVal;
  m_varLastVal = t_varLastVal;
  m_varDotVal = t_varDotVal;
  m_varDeltaDotVal = t_varDeltaDotVal;
  m_varLastDotVal = t_varLastDotVal;
  m_residualVal = t_residualVal;
}

VarInfo::~VarInfo()
{
  SA_DESTROY(m_psa_var_init)
  SA_DESTROY(m_psa_varDot_init)
  SA_DESTROY(m_psa_varVal)
  SA_DESTROY(m_psa_varDeltaVal)
  SA_DESTROY(m_psa_varLastVal)
  SA_DESTROY(m_psa_varDotVal)
  SA_DESTROY(m_psa_varDeltaDotVal)
  SA_DESTROY(m_psa_varLastDotVal)
  SA_DESTROY(m_psa_residualVal)
}

bool VarInfo::Load(FILE* fs)
{
  const long m_classId = 1014;
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
	  READ_SCALAR( size )
  
    if (size != m_varSize) { _ASSERTE(0); return false; }

	  READ_VECTOR( m_varVal, double, m_varSize )
	  READ_VECTOR( m_varDeltaVal, double, m_varSize )
	  READ_VECTOR( m_varLastVal, double, m_varSize )
	  READ_VECTOR( m_varDotVal, double, m_varSize )
	  READ_VECTOR( m_varDeltaDotVal, double, m_varSize )
	  READ_VECTOR( m_varLastDotVal, double, m_varSize )
    bRet = true;
    break;
  }
  return bRet;
}

void VarInfo::Save(FILE* fs)
{
  const long m_classId = 1014;
  const long m_schema = 1;

  WRITE_SCALAR( m_classId )
  WRITE_SCALAR( m_schema )

  WRITE_SCALAR( m_varSize )
	WRITE_VECTOR( m_varVal, double, m_varSize )
	WRITE_VECTOR( m_varDeltaVal, double, m_varSize )
	WRITE_VECTOR( m_varLastVal, double, m_varSize )
	WRITE_VECTOR( m_varDotVal, double, m_varSize )
	WRITE_VECTOR( m_varDeltaDotVal, double, m_varSize )
	WRITE_VECTOR( m_varLastDotVal, double, m_varSize )

}
