#include "StdAfx.h"
#include "ISDaeCOSolver.h"
#include "ModelNavMaps.h"
#include "OnDaeCOSolverMacros.h"
#include "IsDaeEso.h"
#include "stdio.h"

#if 0
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#endif

ModelEqnMap::ModelEqnMap() 
{ 
  iModel = -1;
  iEqn = -1;
  iGlobalEqn = -1;
  iEAL = -1;
  itEAL = -1;
  bAugmented = false;
  bReset = false;
  iAssignedVar = -1;
  bDiscontinuous = false;
  iDiscVar = -1;
  bActive = true;
  bUndefined = false;
  diff_form = EqnDiffForm_Numeric;
}


ModelEqnMap& ModelEqnMap::operator=(const ModelEqnMap& other)
{
  iModel = other.iModel;
  iEqn = other.iEqn;
  iGlobalEqn = other.iGlobalEqn;
  iEAL = other.iEAL;
  itEAL = other.itEAL;
  bAugmented = other.bAugmented;
  bReset = other.bReset;
  iAssignedVar = other.iAssignedVar;
  bDiscontinuous = other.bDiscontinuous;
  iDiscVar = other.iDiscVar;
  bActive = other.bActive;
  bUndefined = other.bUndefined;
  diff_form = other.diff_form;

  return *this;
}


ModelVarMap::ModelVarMap() 
{ 
  iModel = -1; 
  iMNModel = -1;
  iVar = -1; 
  iMNVar = -1;
  iGlobalVar = -1;
  iVAL = -1; 
  itVAL = -1; 
  bAugmented = false; 
  bDiscontinuous = false; 
  iDiffOrder = -1;
  bActive = true;
}


ModelVarMap& ModelVarMap::operator=(const ModelVarMap& other)
{
  iModel = other.iModel;
  iMNModel = other.iMNModel;
  iVar = other.iVar;  
  iMNVar = other.iMNVar;
  iGlobalVar = other.iGlobalVar;
  iVAL = other.iVAL;     
  itVAL = other.itVAL;    
  bAugmented = other.bAugmented;
  bDiscontinuous = other.bDiscontinuous;
  iDiffOrder = other.iDiffOrder;
  bActive = other.bActive;
  return *this;
}


ModelParMap::ModelParMap() 
{ 
  iModel = -1; 
  iPar = -1; 
  iGlobalPar = -1;
}

ModelParMap& ModelParMap::operator=(const ModelParMap& other)
{
  iModel = other.iModel;
  iPar = other.iPar;  
  iGlobalPar = other.iGlobalPar;
  return *this;
}



FlatModel::FlatModel(long cEqns, long cVars, long cRPars, long cIPars)
{
  long i;

  nEqns = cEqns;
  nMSSEqns = 0;
  nAugmentedEqns = 0;
  nVars = cVars;
  nAugmentedVars = 0;
  nMSSVars = 0;
  nRPars = 0;
  nIPars = 0;
  EsoCount = 0;
  EsoDim = 0;
  EsoList = NULL;
  EqnMapSize = 0;
  EqnMapDim = cEqns * 2;
  EqnMap = new ModelEqnMap*[EqnMapDim];
  for (i = 0; i < EqnMapDim; i++) EqnMap[i] = NULL;
  spModelEqn = NULL;
  cNZModelEqn = NULL;

  VarMapSize = 0;
  VarMapDim = cVars * 2;
  VarMap = new ModelVarMap*[VarMapDim];
  for (i = 0; i < VarMapDim; i++) VarMap[i] = NULL;
  RParMap = NULL;
  IParMap = NULL;
  if (cRPars) RParMap = new ModelParMap[cRPars];
  if (cIPars) IParMap = new ModelParMap[cIPars];
}
  
FlatModel::~FlatModel()
{
  long i;
  DESTROY_VECTOR(EsoList)
  if (EqnMap) 
  {
    for (i = 0; i < EqnMapDim; i++) DESTROY_MEMBER(EqnMap[i])
  }
  DESTROY_VECTOR(EqnMap)
  DESTROY_VECTOR(spModelEqn)
  DESTROY_VECTOR(cNZModelEqn)
  
  if (VarMap)
  {
    for (i = 0; i < VarMapDim; i++) DESTROY_MEMBER(VarMap[i])
  }
  DESTROY_VECTOR(VarMap)
  DESTROY_VECTOR(RParMap)
  DESTROY_VECTOR(IParMap)
}

bool FlatModel::Load(FILE* fs)
{
  const long m_classId = 1010;
  const long m_schema = 1;

  long i;
  long classId;
  long schema;
  long numberOfEqns;
  bool bRet = false;

  READ_SCALAR( classId )
  if (classId != m_classId) { _ASSERTE(0); return false; }

  READ_SCALAR( schema )

  switch (schema)
  {
  case 1:
    READ_SCALAR( numberOfEqns )
    READ_SCALAR( nMSSEqns )
    READ_SCALAR( nAugmentedEqns )
    READ_SCALAR( nVars )
    READ_SCALAR( nAugmentedVars )
    READ_SCALAR( nMSSVars )
    READ_SCALAR( nRPars )
    READ_SCALAR( nIPars )
    READ_SCALAR( EsoCount )

    if (numberOfEqns != nEqns) { _ASSERTE(0); return false; }

    for (i = 0; i < nEqns; i++)
    {
      READ_SCALAR( EqnMap[i]->bActive )
    }

    for (i = 0; i < EsoCount; i++) 
    {
      READ_SCALAR( EsoList[i]->m_CurrentState )
    }
    
    bRet = true;
    break;

  }

  return bRet;
}

void FlatModel::Save(FILE* fs)
{
  const long m_classId = 1010;
  const long m_schema = 1;

  long i;

  WRITE_SCALAR( m_classId )
  WRITE_SCALAR( m_schema )

  WRITE_SCALAR( nEqns )
  WRITE_SCALAR( nMSSEqns )
  WRITE_SCALAR( nAugmentedEqns )
  WRITE_SCALAR( nVars )
  WRITE_SCALAR( nAugmentedVars )
  WRITE_SCALAR( nMSSVars )
  WRITE_SCALAR( nRPars )
  WRITE_SCALAR( nIPars )
  WRITE_SCALAR( EsoCount )

  for (i = 0; i < nEqns; i++) 
  {
    WRITE_SCALAR( EqnMap[i]->bActive )
  }

  for (i = 0; i < EsoCount; i++) 
  {
    WRITE_SCALAR( EsoList[i]->m_CurrentState )
  }

}