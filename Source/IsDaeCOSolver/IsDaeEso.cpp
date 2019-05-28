// IsDaeEsoImpl.cpp : Implementation of CIsDaeEso
#include "stdafx.h"
#include "ISDaeCOSolver.h"
#include "IsDaeEso.h"
#include "OnDaeCOSolverMacros.h"
#include "ModelNavMaps.h"
#include "IndexInfo.h"
#include "MatInfo.h"
#include "VarInfo.h"
#include "VirtualTimeInfo.h"
#include "ToleranceInfo.h"
#include "ConvergenceInfo.h"
#include "StepSizeInfo.h"
#include "ReportInfo.h"
#include "StateInfo.h"
#include "TransitionInfo.h"
#include "BandedInfo.h"
#include "triangularization.h"

#include < math.h >
#include "MSS.h"
#include "ConsistentInitialization.h"
#include "CommonTools.h"
#include "IsInterval.h"
#include <time.h>

#include "IsDaeEsoCImpl.h"
#include "IOnUMLDaeEsoBase.h"
#include "stdio.h"

#if 0
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#endif

#if 0
//static long _run_residual_test = 0;
#endif

extern double dlamch(char);

#define _NOT_USING_SPARSE 0

/////////////////////////////////////////////////////////////////////////////
// CIsDaeEso

CIsDaeEsoBase::CIsDaeEsoBase(long nEqns, long nVars, long nRPars, long nIPars)
{
  m_pModelExec = NULL;
  m_pParent = NULL;

  m_bMasterNode = false;
  m_bGlobalNode = false;

  m_nEqns = nEqns;
  m_nVars = nVars;
  m_nLocalEqns = nEqns;
  m_nLocalVars = nVars;
  m_nDiscontinuousEqns = 0;

  m_nRealParameters = nRPars;
  m_nIntegerParameters = nIPars;
  m_nLocalRPars = nRPars;
  m_nLocalIPars = nIPars;

	m_realParameters = NULL;
	m_integerParameters = NULL;

  m_EqnMap = NULL;
  m_VarMap = NULL;
  m_IParMap = NULL;
  m_RParMap = NULL;

  m_ActiveEqns = NULL;
  m_itActiveEqns = NULL;
  m_nActiveEqns = 0;

  m_ActiveVars = NULL;
  m_itActiveVars = NULL;
  m_nActiveVars = 0;

	m_tolerance = new ToleranceInfo;
	m_y = NULL;
	m_index = new IndexInfo;
  m_VariableMap = NULL;
  m_MNVariableMap = NULL;
  m_time = new VirtualTimeInfo;
	m_step = new StepSizeInfo;

  // jacobians
	m_Jac = NULL;
	m_JacStruct = NULL;
	m_Mass = NULL;
	m_MassStruct = NULL;	
  m_bJacobiansInitialized = false;
  m_bEsoInitialized = false;

  // stepper environment variables
  m_K = NULL;
	m_iterationMatrix = NULL;
  m_nStages = 4;

  uround = 2.220446E-16; // WAH 08/21/01 profiler --  to eliminate expensive dlamch('E');
  epsilon = 1.49E-8; // WAH 08/21/01 profiler -- sqrt(uround);
	m_convergance = new ConverganceInfo;
	m_convergance->m_uround =  uround;
	m_report = new ReportInfo;
  m_report->m_idid = 1;

  // initialize external reference index properties
  m_Level = -1;

  m_DirectEsos = NULL;
  m_DirectEqnMap = NULL;
  m_DirectResMap = NULL;
  m_DirectDiscVarMap = NULL;
  m_nDirectEqnMap = NULL;
  m_DirectRes = NULL;
  m_nDirectUndefDiscEqns = 0;
  m_DirectUndefDiscEqns = NULL;
  m_DirectUndefDiscVars = NULL;

  m_ContainerIndex = -1;
  m_GlobalIndex = -1;

  // flat Eso data (only applicable if Eso is the global Eso
  m_fm = NULL;

  m_IIsEsos = NULL;
  m_Esos = NULL;
  m_nEsos = 0;
  m_EsoDim = 0;
  m_IIsEsoDim = 0;
  size_ptr_array(5, m_nEsos, m_IIsEsoDim, m_IIsEsos);
  size_ptr_array(5, m_nEsos, m_EsoDim, m_Esos);
  m_Esos[0] = this;
  m_IIsEsos[0] = NULL;
  m_nEsos = 1;

  m_spEsoEqns = NULL;
  m_spEsoVars = NULL;
  m_spEsoRPars = NULL;
  m_spEsoIPars = NULL;

  m_nStates = 0;
  m_nTransitions = 0;
  m_StateInfo = NULL;
  m_TransitionInfo = NULL;

  // variables used for numeric differentiation
  nominalVal = NULL;
  nominalTime = NULL;

  // cached equation indices for jacobian and mass calculations
  JacIndices = NULL;
  nJacIndices = 0;
  MassIndices = NULL;
  nMassIndices = 0;

  // event handler
  m_EventTime = 0.0;
  m_EventId = NULL;
  m_EventEqn = -1;

  if (nEqns > 0)
    SetLocalSize(nEqns, nVars, nRPars, nIPars);
}

STDMETHODIMP CIsDaeEsoBase::SetLocalSize(long nEqns, long nVars, long nRPars, long nIPars)
{
  long i;
  // equations
  if (nEqns != m_nLocalEqns)
  {
    if (m_EqnMap && m_nLocalEqns > 0)
    {
      ModelEqnMap* t_EqnMap = new ModelEqnMap[nEqns];
      for (i = 0; i < m_nLocalEqns; i++) t_EqnMap[i] = m_EqnMap[i];
      DESTROY_VECTOR(m_EqnMap)
      m_EqnMap = t_EqnMap;
    }
    else
    {
      m_EqnMap = new ModelEqnMap[nEqns];
    }
    m_nLocalEqns = nEqns;
    m_nEqns = nEqns;
  

    for (i = 0; i < nEqns; i++) 
    {
      m_EqnMap[i].iModel = 0;
      m_EqnMap[i].iEqn = i;
    }
  }

  // variables
  if (nVars != m_nLocalVars)
  {
    if (m_VarMap && m_nLocalVars > 0)
    {
      ModelVarMap* t_VarMap = new ModelVarMap[nVars];
      for (i = 0; i < m_nLocalVars; i++) t_VarMap[i] = m_VarMap[i];
      DESTROY_VECTOR(m_VarMap)
      m_VarMap = t_VarMap;
    }
    else
    {
      m_VarMap = new ModelVarMap[nVars];
    }
    m_nLocalVars = nVars;
    m_nVars = nVars;

    for (i = 0; i < nVars; i++)
    {
      m_VarMap[i].iModel = 0;
      m_VarMap[i].iVar = i;
    }
  }

  DESTROY_VECTOR(m_RParMap)
  if (nRPars) m_RParMap = new long[nRPars];
  for (i = 0; i < nRPars; i++) m_RParMap[i] = -1;

  // real parameters
  if (nRPars != m_nLocalRPars)
  {
    if (m_realParameters)
    {
      double* t_realParameters = new double[nRPars];
      for (i = 0; i < nRPars; i++) t_realParameters[i] = 0.0;
      for (i = 0; i < m_nRealParameters; i++) t_realParameters[i] = m_realParameters[i];
      DESTROY_VECTOR(m_realParameters)
      m_realParameters = t_realParameters;
    }
    else
    {
      if (nRPars > 0)
      {
        m_realParameters = new double[nRPars];
        for (i = 0; i < nRPars; i++) m_realParameters[i] = 0.0;
      }
    }
    m_nLocalRPars = nRPars;
    m_nRealParameters = nRPars;
  }

  DESTROY_VECTOR(m_IParMap)
  if (nIPars) m_IParMap = new long[nIPars];
  for (i = 0; i < nIPars; i++) m_IParMap[i] = -1;

  // integer paramters
  if (nIPars != m_nLocalIPars)
  {
    if (m_integerParameters)
    {
      long* t_integerParameters = new long[nIPars];
      for (i = 0; i < nIPars; i++) t_integerParameters[i] = 0;
      for (i = 0; i < m_nIntegerParameters; i++) t_integerParameters[i] = m_integerParameters[i];
      DESTROY_VECTOR(m_integerParameters)
      m_integerParameters = t_integerParameters;
    }
    else
    {
      if (nIPars > 0)
      {
        m_integerParameters = new long[nIPars];
        for (i = 0; i < nIPars; i++) m_integerParameters[i] = 0;
      }
    }
    m_nLocalIPars = nIPars;
    m_nIntegerParameters = nIPars;
  }

  if (m_y)
	  m_y->Init(nVars); // VarInfo is smart enough to resize itself
  else
    m_y = new VarInfo(nVars);
  
  DESTROY_VECTOR(m_VariableMap)
  m_VariableMap = new long[nVars];
  for (i = 0; i < nVars; i++) m_VariableMap[i] = i;

  DESTROY_VECTOR(m_MNVariableMap)
  m_MNVariableMap = new long[nVars];
  for (i = 0; i < nVars; i++) m_MNVariableMap[i] = i;

  m_index->Init(nVars);

  m_tolerance->Init(true, nVars);
  m_tolerance->m_atol[0] = 1.E-4;
  m_tolerance->m_rtol[0] = 1.E-4;

  return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::SetSize(long nEqns, long nVars, long nRPars, long nIPars)
{
  long i;

  // preserve maps in case this is a reinitilization
  if (m_EqnMap && m_nEqns > 0)
  {
    ModelEqnMap* t_EqnMap = new ModelEqnMap[nEqns];
    for (i = 0; i < m_nEqns; i++) t_EqnMap[i] = m_EqnMap[i];
    DESTROY_VECTOR(m_EqnMap)
    m_EqnMap = t_EqnMap;
  }
  else
  {
    m_EqnMap = new ModelEqnMap[nEqns];
    for (i = 0; i < nEqns; i++)
    {
      m_EqnMap[i].iModel = 0;
      m_EqnMap[i].iEqn = i;
    }
  }
  
  DESTROY_VECTOR(m_ActiveEqns)
  DESTROY_VECTOR(m_itActiveEqns);
  m_ActiveEqns = new long[nEqns];
  m_itActiveEqns = new long[nEqns];
  m_nActiveEqns = nEqns;

  for (i = 0; i < nEqns; i++)
  {
    m_ActiveEqns[i] = i;
    m_itActiveEqns[i] = i;
  }

  if (m_VarMap && m_nVars > 0)
  {
    ModelVarMap* t_VarMap = new ModelVarMap[nVars];
    for (i = 0; i < m_nVars; i++) t_VarMap[i] = m_VarMap[i];
    DESTROY_VECTOR(m_VarMap)
    m_VarMap = t_VarMap;
  }
  else
  {
    m_VarMap = new ModelVarMap[nVars];
  }

  DESTROY_VECTOR(m_ActiveVars)
  DESTROY_VECTOR(m_itActiveVars);
  m_ActiveVars = new long[nVars];
  m_itActiveVars = new long[nVars];
  m_nActiveVars = nVars;

  for (i = 0; i < nVars; i++)
  {
    m_ActiveVars[i] = i;
    m_itActiveVars[i] = i;
  }

  DESTROY_VECTOR(m_RParMap)
  if (nRPars) m_RParMap = new long[nRPars];
  for (i = 0; i < nRPars; i++) m_RParMap[i] = -1;

  if (m_realParameters)
  {
    double* t_realParameters = new double[nRPars];
    for (i = 0; i < nRPars; i++) t_realParameters[i] = 0.0;
    for (i = 0; i < m_nRealParameters; i++) t_realParameters[i] = m_realParameters[i];
    DESTROY_VECTOR(m_realParameters)
    m_realParameters = t_realParameters;
  }
  else
  {
    if (nRPars > 0)
    {
      m_realParameters = new double[nRPars];
      for (i = 0; i < nRPars; i++) m_realParameters[i] = 0.0;
    }
  }
  m_nRealParameters = nRPars;

  DESTROY_VECTOR(m_IParMap)
  if (nIPars) m_IParMap = new long[nIPars];
  for (i = 0; i < nIPars; i++) m_IParMap[i] = -1;

  if (m_integerParameters)
  {
    long* t_integerParameters = new long[nIPars];
    for (i = 0; i < nIPars; i++) t_integerParameters[i] = 0;
    for (i = 0; i < m_nIntegerParameters; i++) t_integerParameters[i] = m_integerParameters[i];
    DESTROY_VECTOR(m_integerParameters)
    m_integerParameters = t_integerParameters;
  }
  else
  {
    if (nIPars > 0)
    {
      m_integerParameters = new long[nIPars];
      for (i = 0; i < nIPars; i++) m_integerParameters[i] = 0;
    }
  }
  m_nIntegerParameters = nIPars;

  if (m_y)
	  m_y->Init(nVars); // VarInfo is smart enough to resize itself
  else
    m_y = new VarInfo(nVars);

  i = m_nVars;
  size_array(0, m_nVars, i, m_VariableMap, nVars - m_nVars);
  for (i = m_nVars; i < nVars; i++) m_VariableMap[i] = i;

  i = m_nVars;
  size_array(0, m_nVars, i, m_MNVariableMap, nVars - m_nVars);
  for (i = m_nVars; i < nVars; i++) m_MNVariableMap[i] = i;

  // resizing matrices is impossible in the case of banded or sparse, so not bothering
  DESTROY_MEMBER(m_Jac)
  DESTROY_MEMBER(m_JacStruct)
  DESTROY_MEMBER(m_Mass)
  DESTROY_MEMBER(m_MassStruct)
  m_Jac = new MatInfo(nEqns, nVars, false, NULL);
	m_Mass = new MatInfo(nEqns, nVars, false, NULL);
  m_JacStruct = new MatInfo(nEqns, nVars, false, NULL);
  m_MassStruct = new MatInfo(nEqns, nVars, false, NULL);

  if (m_K)
  {
    for (i = 0; i < m_nStages; i++) DESTROY_MEMBER(m_K[i])
    DESTROY_VECTOR(m_K)
  }

  if (m_iterationMatrix)
  {
    for (i = 0; i < m_nStages; i++) DESTROY_MEMBER(m_iterationMatrix[i])
    DESTROY_VECTOR(m_iterationMatrix)
  }

  m_nEqns = nEqns;
  m_nVars = nVars;

  m_index->Init(m_nVars);

  m_tolerance->Init(true, nVars);
  m_tolerance->m_atol[0] = 1.E-4;
  m_tolerance->m_rtol[0] = 1.E-4;

  // initialization status flags
  m_bJacobiansInitialized = false;
  m_bEsoInitialized = false;

  return S_OK;
}


CIsDaeEsoBase::~CIsDaeEsoBase()
{
  Destroy();
}

void CIsDaeEsoBase::Destroy()
{
  long i;

  if (m_pModelExec)
  {
    m_pModelExec->Release();
    m_pModelExec = NULL;
  }

  if (m_bGlobalNode)
  {
    // clean out direct residual calculation vectors
    if (m_DirectEqnMap)
    {
      for (i = 0; i < m_fm->EsoCount; i++) DESTROY_VECTOR(m_DirectEqnMap[i])
      DESTROY_VECTOR(m_DirectEqnMap)
    }
  
    if (m_DirectResMap)
    {
      for (i = 0; i < m_fm->EsoCount; i++) DESTROY_VECTOR(m_DirectResMap[i])
      DESTROY_VECTOR(m_DirectResMap)
    }
  
    if (m_DirectDiscVarMap)
    {
      for (i = 0; i < m_fm->EsoCount; i++) DESTROY_VECTOR(m_DirectDiscVarMap[i])
      DESTROY_VECTOR(m_DirectDiscVarMap)
    }

    DESTROY_VECTOR(m_DirectEsos)
    DESTROY_VECTOR(m_nDirectEqnMap)
    DESTROY_VECTOR(m_DirectRes)

    DESTROY_VECTOR(m_DirectUndefDiscEqns)
    DESTROY_VECTOR(m_DirectUndefDiscVars)

  }

  DESTROY_VECTOR(m_EqnMap)
  DESTROY_VECTOR(m_VarMap)
  DESTROY_VECTOR(m_IParMap)
  DESTROY_VECTOR(m_RParMap)

  DESTROY_VECTOR(m_ActiveEqns)
  DESTROY_VECTOR(m_itActiveEqns)
  DESTROY_VECTOR(m_ActiveVars)
  DESTROY_VECTOR(m_itActiveVars)

  DESTROY_MEMBER(m_convergance)
  DESTROY_MEMBER(m_report)
	DESTROY_MEMBER(m_tolerance)
	DESTROY_MEMBER(m_index)
	DESTROY_MEMBER(m_time)
	DESTROY_MEMBER(m_step)
	DESTROY_MEMBER(m_y)
  DESTROY_VECTOR(m_VariableMap)
  DESTROY_VECTOR(m_MNVariableMap)
  DESTROY_VECTOR(m_realParameters)
	DESTROY_VECTOR(m_integerParameters)
	DESTROY_MEMBER(m_Jac)
	DESTROY_MEMBER(m_Mass)
	DESTROY_MEMBER(m_JacStruct)
	DESTROY_MEMBER(m_MassStruct)
  if (m_K)
  {
    for (i = 0; i < m_nStages; i++) DESTROY_MEMBER(m_K[i])
    DESTROY_VECTOR(m_K)
  }
  if (m_iterationMatrix)
  {
    for (i = 0; i < m_nStages; i++) DESTROY_MEMBER(m_iterationMatrix[i])
    DESTROY_VECTOR(m_iterationMatrix)
  }

  DESTROY_VECTOR(nominalVal)
  DESTROY_VECTOR(nominalTime)
  DESTROY_VECTOR(JacIndices)
  DESTROY_VECTOR(MassIndices)

  // flat Eso data (only applicable if Eso is the global Eso
  DESTROY_MEMBER(m_fm)

  // begin composite
  if (m_IIsEsos)
  {
    for (i = 1; i < m_nEsos; i++)
    {
      if (m_IIsEsos[i]) 
      {
        m_IIsEsos[i]->Release();
        m_IIsEsos[i] = NULL;
      }
    }

    DESTROY_VECTOR(m_IIsEsos)
  }
  DESTROY_VECTOR(m_Esos)
  m_nEsos = 0;
  m_EsoDim = 0;
  m_IIsEsoDim = 0;

  // variable map
  DESTROY_VECTOR(m_spEsoEqns)
  DESTROY_VECTOR(m_spEsoVars)
  DESTROY_VECTOR(m_spEsoRPars)
  DESTROY_VECTOR(m_spEsoIPars)

  // end composite

  DESTROY_VECTOR(m_StateInfo)
  DESTROY_VECTOR(m_TransitionInfo)

}


HRESULT CIsDaeEsoBase::iInitialize()
{
  HRESULT hr = S_OK;
  long i, j, k, iEqn;
  CIsDaeEsoBase* pEso;

  if (!m_bEsoInitialized)
  {
    // initialize all child Esos
    for (i = 1; i < m_nEsos; i++) 
    {
#if 0
      BSTR Name = NULL;
      CIsDaeEsoCImpl* pCIsDaeEsoCImpl = static_cast<CIsDaeEsoCImpl*> (this);
      if (pCIsDaeEsoCImpl) 
      {
        pCIsDaeEsoCImpl->m_pEsoImpl->GetEsoName(i-1, &Name);
        ATLTRACE("\n\n *** Eso[%d] %S", i, Name );
        ::SysFreeString(Name);
      }
      else
      {
        ATLTRACE("\n\n *** Eso[%d] ", i);
      }
#endif
      m_Esos[i]->iInitialize();
    }
    initializeEqns();

    if (m_nTransitions > 0) // STN
    {
      // size the discontinuity equations so the number of equations in all states is equal
      m_CurrentState = m_DefaultState;
      // TODO: move the initialization so member Esos can be included
      SizeDiscontinuousVars();

      for (i = 0; i < m_nStates; i++)
      {
        for (j = 0; j < m_StateInfo[i].nEqns; j++)
          m_EqnMap[m_StateInfo[i].EqnIndices[j]].bActive = false;
      }

      for (i = 0; i < m_StateInfo[m_CurrentState].nEqns; i++)
        m_EqnMap[m_StateInfo[m_CurrentState].EqnIndices[i]].bActive = true;

      for (i = 0; i < m_nTransitions; i++)
      {
        for (j = 0; j < m_TransitionInfo[i].nEqns; j++)
        {
          iEqn = m_TransitionInfo[i].EqnIndices[j];
          _ASSERTE(abs(iEqn) < m_nEqns);
          m_EqnMap[iEqn].bActive = false;
        }
      }

      for (i = 0; i < m_nTransitions; i++)
      {
        if (m_TransitionInfo[i].SourceState == m_CurrentState)
        {
          for (j = 0; j < m_TransitionInfo[i].nEqns; j++)
          {
            iEqn = m_TransitionInfo[i].EqnIndices[j];
            m_EqnMap[iEqn].bActive = m_EqnMap[iEqn].bDiscontinuous;
          }
        }
      }

    }


    // reset the variable and parameter maps on each member Eso to default values
    long EquationCount;
    long VariableCount;
    long RParCount;
    long IParCount;
    long nAssignedVars = m_nLocalVars;
    iInitializePageMaps(EquationCount, VariableCount, RParCount, IParCount);

    for (i = 1; i < m_nEsos; i++)
    {
      pEso = m_Esos[i];
    
      if (pEso->m_bMasterNode)
      {
        for (j = 0; j < pEso->m_nLocalVars; j++) pEso->m_VariableMap[j] = nAssignedVars++;
      }
      else
      {
        if (m_bMasterNode)
          for (j = 0; j < pEso->m_nVars; j++) pEso->m_MNVariableMap[j] = nAssignedVars++;
        else
          for (j = 0; j < pEso->m_nVars; j++) pEso->m_VariableMap[j] = nAssignedVars++;
      }
    }

    // initialize the size of the variable, equation, jacobian, mass, index ... vectors
    SetSize(EquationCount, VariableCount, RParCount, IParCount);

    // get variable and parameter defaults from child objects
    long iVar = m_nLocalVars;
    long iRPar = m_nLocalRPars;
    long iIPar = m_nLocalIPars;
    
    for (i = 1; i < m_nEsos; i++)
    {
      pEso = m_Esos[i];
      if (pEso->m_bMasterNode)
      {
        for (j = 0; j < pEso->m_nLocalVars; j++)
        {
          m_y->m_var_init[iVar] = pEso->m_y->m_var_init[j];
          m_y->m_varVal[iVar] = pEso->m_y->m_var_init[j];
          m_y->m_varLastVal[iVar] = pEso->m_y->m_var_init[j];
          m_y->m_varDot_init[iVar] = pEso->m_y->m_varDot_init[j];
          m_y->m_varDotVal[iVar] = pEso->m_y->m_varDot_init[j];
          m_y->m_varLastDotVal[iVar] = pEso->m_y->m_varDot_init[j];
          iVar++;
        }

        for (j = 0; j < pEso->m_nLocalRPars; j++)
          m_realParameters[iRPar++] = pEso->m_realParameters[j]; 

        for (j = 0; j < pEso->m_nLocalIPars; j++)
          m_integerParameters[iIPar++] = pEso->m_integerParameters[j]; 
      }
      else
      {
        for (j = 0; j < pEso->m_nVars; j++)
        {
          m_y->m_var_init[iVar] = pEso->m_y->m_var_init[j];
          m_y->m_varVal[iVar] = pEso->m_y->m_var_init[j];
          m_y->m_varLastVal[iVar] = pEso->m_y->m_var_init[j];
          m_y->m_varDot_init[iVar] = pEso->m_y->m_varDot_init[j];
          m_y->m_varDotVal[iVar] = pEso->m_y->m_varDot_init[j];
          m_y->m_varLastDotVal[iVar] = pEso->m_y->m_varDot_init[j];
          iVar++;
        }

        for (j = 0; j < pEso->m_nRealParameters; j++)
          m_realParameters[iRPar++] = pEso->m_realParameters[j]; 

        for (j = 0; j < pEso->m_nIntegerParameters; j++)
          m_integerParameters[iIPar++] = pEso->m_integerParameters[j]; 
      }
    }

    // initialize the standard equation vector
    // ensure local equation section of equation map has been initialized 
    //for (i = 0; i < m_nLocalEqns; i++)
    //{
    //  m_EqnMap[i].iEqn = i;
    //  m_EqnMap[i].iModel = 0;
    //}

    // add member Eso equations
    k = m_nLocalEqns;
    for (i = 1; i < m_nEsos; i++)
    {
      pEso = m_Esos[i];
      if (!pEso->m_bMasterNode)
      {
        for (j = 0; j < pEso->m_nEqns; j++)
        {
          m_EqnMap[k] = pEso->m_EqnMap[j];
          m_EqnMap[k].iModel = i;
          m_EqnMap[k].iEqn = j;
          if (m_EqnMap[k].iDiscVar >= 0) 
            m_EqnMap[k].iDiscVar = pEso->m_VariableMap[pEso->m_EqnMap[j].iDiscVar];
      
          k++;
        }
      }
    }

    // initialize the standard variable vector
    // ensure local variable section of equation map has been initialized 
    for (i = 0; i < m_nLocalVars; i++)
    {
      m_VarMap[i].iVar = i;
      m_VarMap[i].iModel = 0;
    }

    // add member variables
    k = m_nLocalVars;
    for (i = 1; i < m_nEsos; i++)
    {
      pEso = m_Esos[i];
      if (pEso->m_bMasterNode)
      {
        for (j = 0; j < pEso->m_nLocalVars; j++)
        {
          m_VarMap[k] = pEso->m_VarMap[j];
          m_VarMap[k].iModel = i;
          m_VarMap[k].iVar = j;
          k++;
        }
      }

      else

      {
        for (j = 0; j < pEso->m_nVars; j++)
        {
          m_VarMap[k] = pEso->m_VarMap[j];
          m_VarMap[k].iModel = i;
          m_VarMap[k].iVar = j;
          k++;
        }
      }
    }

    // initialize the active equation vector
    initActiveEqns();

    // need to adjust the number of eqns and vars in m_Jac and m_Mass to m_nActiveEqns (which shouldn't change)
    m_Jac->m_nRows = m_nActiveEqns;
    m_Jac->m_nCols = m_nActiveVars;
    m_Mass->m_nRows = m_nActiveEqns;
    m_Mass->m_nCols = m_nActiveVars;

	  initializeVars();
	  initializeJacobians(); 
    m_bEsoInitialized = true;
  }
  return hr;
}

void CIsDaeEsoBase::iInitializePageMaps(long& EquationCount, long& VariableCount, long& RParCount, long& IParCount)
{
  long i;
  CIsDaeEsoBase* pEso;
  long spEsoVars = m_nLocalVars;

  EquationCount = m_nLocalEqns;
  VariableCount = m_nLocalVars;
  RParCount = m_nLocalRPars;
  IParCount = m_nLocalIPars;

  DESTROY_VECTOR(m_spEsoEqns)
  DESTROY_VECTOR(m_spEsoVars)
  DESTROY_VECTOR(m_spEsoRPars)
  DESTROY_VECTOR(m_spEsoIPars)

  m_spEsoEqns = new long[m_nEsos];
  m_spEsoVars = new long[m_nEsos];
  m_spEsoRPars = new long[m_nEsos];
  m_spEsoIPars = new long[m_nEsos];

  m_spEsoEqns[0] = 0;
  m_spEsoVars[0] = 0;
  m_spEsoRPars[0] = 0;
  m_spEsoIPars[0] = 0;

  for (i = 1; i < m_nEsos; i++)
  {
    pEso = m_Esos[i];
  
    m_spEsoEqns[i] = EquationCount;
    m_spEsoVars[i] = spEsoVars;
    m_spEsoRPars[i] = RParCount;
    m_spEsoIPars[i] = IParCount;

    if (m_bGlobalNode) 
    {
      EquationCount += pEso->m_nEqns;
      if (!pEso->m_bMasterNode)
      {
        VariableCount += pEso->m_nVars;
        spEsoVars += pEso->m_nActiveVars; 
        RParCount += pEso->m_nRealParameters;
        IParCount += pEso->m_nIntegerParameters;
      }
    }
    else // !m_bGlobalNode
    {
      if (pEso->m_bMasterNode)
      {
        VariableCount += pEso->m_nLocalVars;
        spEsoVars += pEso->m_nLocalVars;
        RParCount += pEso->m_nLocalRPars;
        IParCount += pEso->m_nLocalIPars;
      }
      else
      {
        EquationCount += pEso->m_nEqns;
        VariableCount += pEso->m_nVars;
        spEsoVars += pEso->m_nActiveVars; 
        RParCount += pEso->m_nRealParameters;
        IParCount += pEso->m_nIntegerParameters;
      }
    }
  }
}

HRESULT CIsDaeEsoBase::iInitializeMasterNodes()
{
  long i, j, k;
  long nNodes = 0;
  long nEqns = 0;
  CIsDaeEsoBase** pNodes = NULL;

  // build a list of master nodes
  GetNumMasterNodes(nNodes);
  if (nNodes == 0) return S_OK;

  pNodes = new CIsDaeEsoBase*[nNodes];
  i = 0;
  GetMasterNodes(i, pNodes);
  _ASSERTE(i == nNodes);

  // resize the m_Esos vector
  size_ptr_array(50, m_nEsos, m_EsoDim, m_Esos, nNodes);
  for (i = 0; i < m_nEsos; i++) m_Esos[m_nEsos + nNodes - i - 1] = m_Esos[m_nEsos - i - 1];
  for (i = 0; i < nNodes; i++) m_Esos[i+1] = pNodes[i];

  size_ptr_array(50, m_nEsos, m_IIsEsoDim, m_IIsEsos, nNodes);
  for (i = 0; i < m_nEsos; i++) m_IIsEsos[m_nEsos + nNodes - i - 1] = m_IIsEsos[m_nEsos - i - 1];
  for (i = 0; i < nNodes; i++) m_IIsEsos[i+1] = NULL;

  m_nEsos += nNodes;

  for (i = nNodes+1; i < m_nEsos; i++) m_Esos[i]->m_ContainerIndex = i;

  // resize the equation map
  nEqns = 0;
  for (i = 0; i < nNodes; i++) nEqns += pNodes[i]->m_nEqns; // keep local equations first
  ModelEqnMap* t_EqnMap = new ModelEqnMap[nEqns + m_nEqns];

  k = 0;
  for (i = 0; i < m_nLocalEqns; i++) t_EqnMap[k++] = m_EqnMap[i];
  for (i = 0; i < nNodes; i++)
  {
    for (j = 0; j < pNodes[i]->m_nEqns; j++)
    {
      t_EqnMap[k] = pNodes[i]->m_EqnMap[j];
      t_EqnMap[k].iModel = i+1;
      t_EqnMap[k].iEqn = j;
      k++;
    }
  }

  // correct the iModel indices in the equation map
  for (i = m_nLocalEqns; i < m_nEqns; i++) 
  {
    t_EqnMap[k] = m_EqnMap[i];
    t_EqnMap[k].iModel += nNodes;
    k++;
  }
  for (i = 0; i < m_nVars; i++) m_VarMap[i].iModel += nNodes;

  DESTROY_VECTOR(m_EqnMap)
  m_EqnMap = t_EqnMap;
  m_nEqns += nEqns;


  // resize the variable and parameter page maps
  long EquationCount;
  long VariableCount;
  long RParCount;
  long IParCount;
  iInitializePageMaps(EquationCount, VariableCount, RParCount, IParCount);

  // resize the active equation vectors
  DESTROY_VECTOR(m_ActiveEqns)
  DESTROY_VECTOR(m_itActiveEqns);
  m_ActiveEqns = new long[m_nEqns];
  m_itActiveEqns = new long[m_nEqns];
  initActiveEqns();

  // resize m_K and m_iterationMatrix
  if (m_K)
  {
    for (i = 0; i < m_nStages; i++) DESTROY_MEMBER(m_K[i])
    DESTROY_VECTOR(m_K)
  }

  if (m_iterationMatrix)
  {
    for (i = 0; i < m_nStages; i++) DESTROY_MEMBER(m_iterationMatrix[i])
    DESTROY_VECTOR(m_iterationMatrix)
  }

  // cleanup
  DESTROY_VECTOR(pNodes)

  // note: further initialization is performed in iComplateMasterNodeInit().  It can't be done
  // until after the flat model has been initialized and the global indices have been assigned
  // to all Esos, Eqns, and Vars.
  return S_OK;
}


static int __cdecl LevelCompare(const void * pElem1, const void * pElem2)
{
  CIsDaeEsoBase* u1 = ((CIsDaeEsoBase*)*(void **)pElem1);
  CIsDaeEsoBase* u2 = ((CIsDaeEsoBase*)*(void **)pElem2);

  if (u1->m_Level == u2->m_Level)
    return 0;
  else if (u1->m_Level > u2->m_Level)
    return -1;
  else
    return 1;
}

void CIsDaeEsoBase::iCompleteMasterNodeInit()
{
  long i, j, k;
  long nNodes;
  CIsDaeEsoBase** pNodes = NULL;
  long iModel, iVar;

  nNodes = 0;
  pNodes = new CIsDaeEsoBase*[m_nEsos];
  for (i = 0; i < m_nEsos; i++)
  {
    if (m_Esos[i]->m_bMasterNode) pNodes[nNodes++] = m_Esos[i];
  }

  // initialize variable map of all master nodes
  for (i = 0; i < nNodes; i++)
  {
    for (j = 0; j < pNodes[i]->m_nVars; j++)
    {
      if (pNodes[i]->m_VarMap[j].iModel != 0)
      {
        iModel = pNodes[i]->m_VarMap[j].iModel;
        iVar = pNodes[i]->m_VarMap[j].iVar;
        pNodes[i]->m_VarMap[j].iGlobalVar = pNodes[i]->m_Esos[iModel]->m_VarMap[iVar].iGlobalVar; 
      }
      pNodes[i]->m_MNVariableMap[j] = pNodes[i]->m_VarMap[j].iGlobalVar;

      // set the iMNModel and iMNVar references on the global node
      for (k = 0; k < m_nVars; k++)
      {
        if (m_VarMap[k].iGlobalVar == pNodes[i]->m_MNVariableMap[j])
        {
          m_VarMap[k].iMNModel = i+1; // based on the assumption that super nodes come first
          m_VarMap[k].iMNVar = j;
          break;
        }
      }
    }
  }

  // merge jacobian and mass structures
  MergeJacobianStructures(nNodes, pNodes);
  MergeMassStructures(nNodes, pNodes);

  // resize jacobian and mass matrices
  DESTROY_MEMBER(m_Jac)
  DESTROY_MEMBER(m_Mass)
  m_Jac = new MatInfo(m_nActiveEqns, m_nActiveVars, false, NULL);
	m_Mass = new MatInfo(m_nActiveEqns, m_nActiveVars, false, NULL);

#if _NOT_USING_SPARSE
  if ( isBandedCompact(*m_JacStruct, m_ActiveEqns, m_nActiveEqns, m_itActiveVars) )
    m_Jac->m_form = BANDED;
  else
    m_Jac->m_form = FULL;

  // TODO: take this out
  m_Jac->m_form = FULL;

	m_Jac->m_lowerBandwidth = m_JacStruct->m_lowerBandwidth;
	m_Jac->m_upperBandwidth = m_JacStruct->m_upperBandwidth;
  m_Jac->Init();
#else
  m_Jac->m_form = SPARSE;
  m_Jac->SetActiveCompactSize(*m_JacStruct, m_ActiveEqns, m_nActiveEqns);
#endif


#if _NOT_USING_SPARSE
  if ( isBandedCompact(*m_MassStruct, m_ActiveEqns, m_nActiveEqns, m_itActiveVars) )
    m_Mass->m_form = BANDED;
  else
    m_Mass->m_form = FULL;

  // TODO: take this out
  m_Mass->m_form = FULL;

	m_Mass->m_lowerBandwidth = m_MassStruct->m_lowerBandwidth;
	m_Mass->m_upperBandwidth = m_MassStruct->m_upperBandwidth;
  m_Mass->Init();
#else
  m_Mass->m_form = SPARSE;
  m_Mass->SetActiveCompactSize(*m_MassStruct, m_ActiveEqns, m_nActiveEqns);
#endif

  // initialize level index of each model, and the sorted m_DirectEsos
  LevelInit(0);
  if (!m_DirectEsos) m_DirectEsos = new CIsDaeEsoBase*[m_fm->EsoCount];
  for (i = 0; i < m_fm->EsoCount; i++) m_DirectEsos[i] = m_fm->EsoList[i];
  qsort(m_DirectEsos, m_fm->EsoCount, sizeof *(m_DirectEsos), LevelCompare);
  
  // cleanup
  DESTROY_VECTOR(pNodes)
}

void CIsDaeEsoBase::initDirectEqnMap()
{
  long i, j, iModel;
  long spModelEqn;
  long size;

  // allocate direct vectors if necessary
  if (!m_DirectEqnMap) 
  {
    m_DirectEqnMap = new long*[m_fm->EsoCount];
    m_DirectResMap = new long*[m_fm->EsoCount];
    m_DirectDiscVarMap = new long*[m_fm->EsoCount];
    m_DirectUndefDiscEqns = new long[m_nActiveEqns];
    m_DirectUndefDiscVars = new long[m_nActiveEqns];

    for (i = 0; i < m_fm->EsoCount; i++) 
    {
      size = m_DirectEsos[i]->m_nLocalEqns;
      if (size > 0)
      {
        m_DirectEqnMap[i] = new long[size];
        m_DirectResMap[i] = new long[size];
        m_DirectDiscVarMap[i] = new long[size];
      }
      else
      {
        m_DirectEqnMap[i] = NULL;
        m_DirectResMap[i] = NULL;
        m_DirectDiscVarMap[i] = NULL;
      }
    }
    m_nDirectEqnMap = new long[m_fm->EsoCount];
    m_DirectRes = new double[m_nVars];
  }

  m_nDirectUndefDiscEqns = 0;
  for (i = 0; i < m_fm->EsoCount; i++)
  {
    iModel = m_DirectEsos[i]->m_GlobalIndex;
    m_nDirectEqnMap[i] = 0;
    spModelEqn = m_fm->spModelEqn[iModel];
    size = m_fm->cNZModelEqn[iModel];
    for (j = 0; j < size; j++)
    {
      if (m_DirectEsos[i]->m_EqnMap[j].iModel > 0) break;  // capture local equations only
      if (m_fm->EqnMap[spModelEqn+j]->bActive)
      {
        if (m_fm->EqnMap[spModelEqn+j]->bUndefined)
        {
          m_DirectUndefDiscEqns[m_nDirectUndefDiscEqns] = m_itActiveEqns[spModelEqn+j];
          m_DirectUndefDiscVars[m_nDirectUndefDiscEqns] = m_fm->EqnMap[spModelEqn+j]->iDiscVar;
          m_nDirectUndefDiscEqns++;
        }
        else
        {
          _ASSERTE(m_itActiveEqns[spModelEqn+j] >= 0);
          m_DirectEqnMap[i][m_nDirectEqnMap[i]] = m_DirectEsos[i]->m_EqnMap[j].iEqn;
          m_DirectResMap[i][m_nDirectEqnMap[i]] = m_itActiveEqns[spModelEqn+j];
          m_DirectDiscVarMap[i][m_nDirectEqnMap[i]] = m_fm->EqnMap[spModelEqn+j]->iDiscVar;
          m_nDirectEqnMap[i]++;
        }
      }
    }
  }

#if 0 // test the results
  long count = 0;

  for (i = 0; i < m_fm->EsoCount; i++)
    count += m_nDirectEqnMap[i];

  for (i = 0; i < m_fm->EqnMapSize; i++)
    if (m_fm->EqnMap[i]->bActive && m_fm->EqnMap[i]->bUndefined) count++;

  _ASSERTE(count == m_nActiveEqns);

  for (i = 0; i < m_fm->EsoCount; i++)
  {
    for (j = 0; j < m_nDirectEqnMap[i]; j++)
      _ASSERTE(m_DirectResMap[i][j] >= 0 && m_DirectResMap[i][j] < m_nActiveEqns);
  }

#endif


#if 0
  long iA;

  ATLTRACE("\ni\tiModel\tiEqn\tbDisc\tbUndef");
  for (i = 0; i < m_nActiveEqns; i++)
  {
    iA = m_ActiveEqns[i];
    ATLTRACE("\n%d\t%d\t%d\t%d\t%d\t%d", i, iA, m_fm->EqnMap[iA]->iModel, m_fm->EqnMap[iA]->iEqn, m_fm->EqnMap[iA]->bDiscontinuous, m_fm->EqnMap[iA]->bUndefined);
  }

  ATLTRACE("\n\ni\tiModel\tiEqn\tiRes\tiDisc");
  for (i = 0; i < m_fm->EsoCount; i++)
  {
    iModel = m_DirectEsos[i]->m_GlobalIndex;
    for (j = 0; j < m_nDirectEqnMap[i]; j++)
      ATLTRACE("\n%d\t%d\t%d\t%d\t%d", j, iModel, m_DirectEqnMap[i][j], m_DirectResMap[i][j], m_DirectDiscVarMap[i][j]);
  }
#endif

#if 0
  ATLTRACE("\n\ni\tiModel\tiLevel");
  for (i = 0; i < m_fm->EsoCount; i++)
    ATLTRACE("\n%d\t%d\t%d", i, m_DirectEsos[i]->m_GlobalIndex, m_DirectEsos[i]->m_Level);
#endif
}

HRESULT CIsDaeEsoBase::iDirectGetAllResiduals(
	double t,
	double* y,
	double* ydot,
  double* residuals,
	bool& validVal,
	double* realParameters, 
	long* integerParameters)
{
  long i, j;
  HRESULT hr = S_OK;
  CIsDaeEsoBase* pEso;
  CIsDaeEsoCImpl* pCEso;
  IOnUMLDaeEsoBase* pModel;

  for (i = 0; i < m_nDirectUndefDiscEqns; i++) 
    residuals[m_DirectUndefDiscEqns[i]] = y[m_DirectUndefDiscVars[i]];

  for (i = 0; i < m_fm->EsoCount && SUCCEEDED(hr); i++)
  {
    pEso = m_DirectEsos[i];
    pCEso = static_cast<CIsDaeEsoCImpl*> (pEso);
    pModel = pCEso->m_pEsoImpl;

    // copy the vars and pars from the global vectors
    for (j = 0; j < pCEso->m_nx; j++)
    {
      *(pCEso->m_x[j]) = y[pEso->m_VarMap[j].iGlobalVar];
      *(pCEso->m_xdot[j]) = ydot[pEso->m_VarMap[j].iGlobalVar];
    }
    for (j = 0; j < pCEso->m_nrpar; j++) *(pCEso->m_rpar[j]) = realParameters[pEso->m_RParMap[j]];
    for (j = 0; j < pCEso->m_nipar; j++) *(pCEso->m_ipar[j]) = integerParameters[pEso->m_IParMap[j]];
   
    // call get residuals on the model
    if (m_nDirectEqnMap[i] > 0)
    {
      hr = pModel->GetResiduals(
        m_DirectEqnMap[i], m_nDirectEqnMap[i], t, m_DirectRes);
    
      // copy the residuals to the global residual vector
      for (j = 0; j < m_nDirectEqnMap[i]; j++)
      {
        if (m_DirectDiscVarMap[i][j] < 0)
          residuals[m_DirectResMap[i][j]] = m_DirectRes[j];
        else
          residuals[m_DirectResMap[i][j]] = y[m_DirectDiscVarMap[i][j]] - m_DirectRes[j];
      }
    }
  }

  return hr;
}

void CIsDaeEsoBase::MergeJacobianStructures(long nNodes, CIsDaeEsoBase** pNodes)
{
  long i, j, k, l, m;
  long iEqn;
  long nNodeEqns;

  MatInfo* t_JacStruct = new MatInfo(m_nEqns, m_nVars, false, NULL);
  t_JacStruct->m_form = SPARSE;
  t_JacStruct->m_nColIndices = m_JacStruct->m_nColIndices;
  for (i = 0; i < nNodes; i++) t_JacStruct->m_nColIndices += pNodes[i]->m_JacStruct->m_nColIndices;
  t_JacStruct->SetCompactSize(m_nEqns, t_JacStruct->m_nColIndices);

  // copy the jacobian structure for the local equations
  k = 0;
  iEqn = 0;
  for (i = 0; i < m_nLocalEqns; i++)
  {
    t_JacStruct->m_spRowPage[iEqn] = k;
    t_JacStruct->m_cNZCols[iEqn] = m_JacStruct->m_cNZCols[i];
    for (j = 0; j < m_JacStruct->m_cNZCols[i]; j++)
    {
      t_JacStruct->m_ColIndices[k] = m_JacStruct->m_ColIndices[k];
      t_JacStruct->m_compact_data[k] = m_JacStruct->m_compact_data[k];
      t_JacStruct->m_compact_value[k] = m_JacStruct->m_compact_value[k];
      t_JacStruct->m_bValueSet[k] = m_JacStruct->m_bValueSet[k];
      k++;
    }
    iEqn++;
  }

  // copy the jacobian structures from the master nodes
  nNodeEqns = 0;
  for (i = 0; i < nNodes; i++)
  {
    m = 0;
    nNodeEqns += pNodes[i]->m_nEqns;
    for (j = 0; j < pNodes[i]->m_nEqns; j++)
    {
      t_JacStruct->m_spRowPage[iEqn] = k;
      t_JacStruct->m_cNZCols[iEqn] = pNodes[i]->m_JacStruct->m_cNZCols[j];
      for (l = 0; l < t_JacStruct->m_cNZCols[iEqn]; l++)
      {
        t_JacStruct->m_ColIndices[k] = pNodes[i]->m_MNVariableMap[pNodes[i]->m_JacStruct->m_ColIndices[m]];
        t_JacStruct->m_compact_data[k] = pNodes[i]->m_JacStruct->m_compact_data[m];
        t_JacStruct->m_compact_value[k] = pNodes[i]->m_JacStruct->m_compact_value[m];
        t_JacStruct->m_bValueSet[k] = pNodes[i]->m_JacStruct->m_bValueSet[m];
        k++;
        m++;
      }
      iEqn++;
    }
  }

  // copy the remaining structures
  // copy the jacobian structure for the local equations
  for (i = m_nLocalEqns; i < (m_nEqns - nNodeEqns); i++)
  {
    t_JacStruct->m_spRowPage[iEqn] = k;
    m = m_JacStruct->m_spRowPage[i];
    t_JacStruct->m_cNZCols[iEqn] = m_JacStruct->m_cNZCols[i];
    for (j = 0; j < m_JacStruct->m_cNZCols[i]; j++)
    {
      t_JacStruct->m_ColIndices[k] = m_JacStruct->m_ColIndices[m];
      t_JacStruct->m_compact_data[k] = m_JacStruct->m_compact_data[m];
      t_JacStruct->m_compact_value[k] = m_JacStruct->m_compact_value[m];
      t_JacStruct->m_bValueSet[k] = m_JacStruct->m_bValueSet[m];
      k++;
      m++;
    }
    iEqn++;
  }

  delete m_JacStruct;
  m_JacStruct = t_JacStruct;

#if 0
  ATLTRACE("\n\nEquations [iEqn], [iModel, iEqn]");
  for (i = 0; i < m_nEqns; i++) ATLTRACE("\n[%d] [%d, %d]", i, m_EqnMap[i].iModel, m_EqnMap[i].iEqn);
  printMat2(m_nEqns, m_nVars, m_JacStruct->m_cNZCols, m_JacStruct->m_ColIndices); 
#endif

}

void CIsDaeEsoBase::MergeMassStructures(long nNodes, CIsDaeEsoBase** pNodes)
{
  long i, j, k, l, m;
  long iEqn;
  long nNodeEqns;

  MatInfo* t_MassStruct = new MatInfo(m_nEqns, m_nVars, false, NULL);
  t_MassStruct->m_form = SPARSE;
  t_MassStruct->m_nColIndices = m_MassStruct->m_nColIndices;
  for (i = 0; i < nNodes; i++) t_MassStruct->m_nColIndices += pNodes[i]->m_MassStruct->m_nColIndices;
  t_MassStruct->SetCompactSize(m_nEqns, t_MassStruct->m_nColIndices);

  // copy the Massobian structure for the local equations
  k = 0;
  iEqn = 0;
  for (i = 0; i < m_nLocalEqns; i++)
  {
    t_MassStruct->m_spRowPage[iEqn] = k;
    t_MassStruct->m_cNZCols[iEqn] = m_MassStruct->m_cNZCols[i];
    for (j = 0; j < m_MassStruct->m_cNZCols[i]; j++)
    {
      t_MassStruct->m_ColIndices[k] = m_MassStruct->m_ColIndices[k];
      t_MassStruct->m_compact_data[k] = m_MassStruct->m_compact_data[k];
      t_MassStruct->m_compact_value[k] = m_MassStruct->m_compact_value[k];
      t_MassStruct->m_bValueSet[k] = m_MassStruct->m_bValueSet[k];
      k++;
    }
    iEqn++;
  }

  // copy the Massobian structures from the master nodes
  nNodeEqns = 0;
  for (i = 0; i < nNodes; i++)
  {
    m = 0;
    nNodeEqns += pNodes[i]->m_nEqns;
    for (j = 0; j < pNodes[i]->m_nEqns; j++)
    {
      t_MassStruct->m_spRowPage[iEqn] = k;
      t_MassStruct->m_cNZCols[iEqn] = pNodes[i]->m_MassStruct->m_cNZCols[j];
      for (l = 0; l < t_MassStruct->m_cNZCols[iEqn]; l++)
      {
        t_MassStruct->m_ColIndices[k] = pNodes[i]->m_MNVariableMap[pNodes[i]->m_MassStruct->m_ColIndices[m]];
        t_MassStruct->m_compact_data[k] = pNodes[i]->m_MassStruct->m_compact_data[m];
        t_MassStruct->m_compact_value[k] = pNodes[i]->m_MassStruct->m_compact_value[m];
        t_MassStruct->m_bValueSet[k] = pNodes[i]->m_MassStruct->m_bValueSet[m];
        k++;
        m++;
      }
      iEqn++;
    }
  }

  // copy the remaining structures
  // copy the Massobian structure for the local equations
  for (i = m_nLocalEqns; i < (m_nEqns - nNodeEqns); i++)
  {
    t_MassStruct->m_spRowPage[iEqn] = k;
    m = m_MassStruct->m_spRowPage[i];
    t_MassStruct->m_cNZCols[iEqn] = m_MassStruct->m_cNZCols[i];
    for (j = 0; j < m_MassStruct->m_cNZCols[i]; j++)
    {
      t_MassStruct->m_ColIndices[k] = m_MassStruct->m_ColIndices[m];
      t_MassStruct->m_compact_data[k] = m_MassStruct->m_compact_data[m];
      t_MassStruct->m_compact_value[k] = m_MassStruct->m_compact_value[m];
      t_MassStruct->m_bValueSet[k] = m_MassStruct->m_bValueSet[m];
      k++;
      m++;
    }
    iEqn++;
  }

  delete m_MassStruct;
  m_MassStruct = t_MassStruct;

#if 0
  ATLTRACE("\n\nEquations [iEqn], [iModel, iEqn]");
  for (i = 0; i < m_nEqns; i++) ATLTRACE("\n[%d] [%d, %d]", i, m_EqnMap[i].iModel, m_EqnMap[i].iEqn);
  printMat2(m_nEqns, m_nVars, m_MassStruct->m_cNZCols, m_MassStruct->m_ColIndices); 
#endif

}


void CIsDaeEsoBase::GetNumMasterNodes(long& nNodes)
{
  if (m_bMasterNode) nNodes++;
  for (long i = 1; i < m_nEsos; i++) m_Esos[i]->GetNumMasterNodes(nNodes);
}

void CIsDaeEsoBase::GetMasterNodes(long& nNodes, CIsDaeEsoBase** pNodes)
{
  if (m_bMasterNode) pNodes[nNodes++] = this;
  for (long i = 1; i < m_nEsos; i++) m_Esos[i]->GetMasterNodes(nNodes, pNodes);
}

void CIsDaeEsoBase::initializeVars()
{
  long i;

	for(i = 0; i < m_nVars; i++)
  {
		m_y->m_varVal[i] = m_y->m_var_init[i];
		m_y->m_varDotVal[i] = m_y->m_varDot_init[i];
	}
}

void CIsDaeEsoBase::initializeJacobians()
{

  if (!m_bJacobiansInitialized)
  {
    m_JacStruct->m_form = SPARSE;
    iGetJacobianStruct(*m_JacStruct);
  
    m_MassStruct->m_form = SPARSE;
    iGetMassStruct(*m_MassStruct);

#if _NOT_USING_SPARSE
    if ( isBandedCompact(*m_JacStruct, m_ActiveEqns, m_nActiveEqns, m_itActiveVars) )
      m_Jac->m_form = BANDED;
    else
      m_Jac->m_form = FULL;

    // TODO: take this out
    m_Jac->m_form = FULL;

	  m_Jac->m_lowerBandwidth = m_JacStruct->m_lowerBandwidth;
	  m_Jac->m_upperBandwidth = m_JacStruct->m_upperBandwidth;
    m_Jac->Init();
#else
    m_Jac->m_form = SPARSE;
    m_Jac->SetActiveCompactSize(*m_JacStruct, m_ActiveEqns, m_nActiveEqns);
#endif

#if _NOT_USING_SPARSE
    if ( isBandedCompact(*m_MassStruct, m_ActiveEqns, m_nActiveEqns, m_itActiveVars) )
      m_Mass->m_form = BANDED;
    else
      m_Mass->m_form = FULL;

    // TODO: take this out
    m_Mass->m_form = FULL;

    m_Mass->m_lowerBandwidth = m_MassStruct->m_lowerBandwidth;
	  m_Mass->m_upperBandwidth = m_MassStruct->m_upperBandwidth;

    m_Mass->Init();
#else
    m_Mass->m_form = SPARSE;
    m_Mass->SetActiveCompactSize(*m_MassStruct, m_ActiveEqns, m_nActiveEqns);
#endif

    m_Jac->m_updateRequired = true;
    m_bJacobiansInitialized = true;
  }

}

HRESULT CIsDaeEsoBase::iGetJacobianStruct(MatInfo& JacStruct)
{
  HRESULT hr = S_OK;
  CIsDaeEsoBase* pEso;
  long i, j, k;
  long iEqn;
  long iModel, iDaeEqn, iDaeVar;
  long cNZ;
  MatInfo** J = NULL;


  if (m_nEqns == 0) return S_OK;

  MatInfo LocalJacStruct;
  if (FAILED( iGetLocalJacobianStruct(LocalJacStruct) ))
    hr = numericJacobianStruct(LocalJacStruct, false);

  if (SUCCEEDED(hr))
  {
    J = new MatInfo*[m_nEsos];
    J[0] = &LocalJacStruct;
    for (i = 1; i < m_nEsos; i++)
    {
      pEso = m_Esos[i];
      if (!pEso->m_bMasterNode)
        J[i] = pEso->m_JacStruct;
      else
        J[i] = NULL;
    }

    JacStruct.m_nColIndices = 0;
    for (i = 0; i < m_nEsos; i++)
      JacStruct.m_nColIndices += (J[i] == NULL) ? 0 : J[i]->m_nColIndices;

    DESTROY_VECTOR(JacStruct.m_ColIndices)
    DESTROY_VECTOR(JacStruct.m_compact_data)
    DESTROY_VECTOR(JacStruct.m_compact_value)
    DESTROY_VECTOR(JacStruct.m_bValueSet)
    DESTROY_VECTOR(JacStruct.m_cNZCols)
    DESTROY_VECTOR(JacStruct.m_spRowPage)

    JacStruct.SetCompactSize(m_nEqns, JacStruct.m_nColIndices);

    k = 0;
    for (iEqn = 0; iEqn < m_nEqns; iEqn++)
    {
      JacStruct.m_spRowPage[iEqn] = k;
      iModel = m_EqnMap[iEqn].iModel;
      iDaeEqn = (iModel == 0) ? iEqn : m_EqnMap[iEqn].iEqn;
      pEso = m_Esos[iModel]; 
      cNZ = 0;
      JacStruct.m_cNZCols[iEqn] = 0;
      if (J[iModel])
      {
        if (J[iModel]->m_cNZCols) cNZ = J[iModel]->m_cNZCols[iDaeEqn];
        j = 0;
        if (J[iModel]->m_spRowPage) j = J[iModel]->m_spRowPage[iDaeEqn];
        for (i = 0; i < cNZ; i++)
        {
          iDaeVar = J[iModel]->m_ColIndices[j];
          if (m_bMasterNode)
            JacStruct.m_ColIndices[k] = (iModel == 0) ? iDaeVar : pEso->m_MNVariableMap[iDaeVar];
          else
            JacStruct.m_ColIndices[k] = (iModel == 0) ? iDaeVar : pEso->m_VariableMap[iDaeVar];

          JacStruct.m_compact_data[k] = J[iModel]->m_compact_data[j];
          JacStruct.m_compact_value[k] = J[iModel]->m_compact_value[j];
          JacStruct.m_bValueSet[k] = J[iModel]->m_bValueSet[j];
          JacStruct.m_cNZCols[iEqn]++;
          k++;
          j++;
        }
      }
    }
  }

#if 0
  ATLTRACE("\n\nEquations [iEqn], [iModel, iEqn]");
  for (i = 0; i < m_nEqns; i++) ATLTRACE("\n[%d] [%d, %d]", i, m_EqnMap[i].iModel, m_EqnMap[i].iEqn);
  printMat2(m_nEqns, m_nVars, JacStruct.m_cNZCols, JacStruct.m_ColIndices); 
#endif

  // cleanup
  DESTROY_VECTOR(J)

  return hr;
}

HRESULT CIsDaeEsoBase::iGetMassStruct(MatInfo& MassStruct)
{
  HRESULT hr = S_OK;
  CIsDaeEsoBase* pEso;
  long i, j, k;
  long iEqn;
  long iModel, iDaeEqn, iDaeVar;
  long cNZ;
  MatInfo** J = NULL;

  if (m_nEqns == 0) return S_OK;

  MatInfo LocalMassStruct;

  if (FAILED( iGetLocalMassStruct(LocalMassStruct) ))
    hr = numericJacobianStruct(LocalMassStruct, true);

  if (SUCCEEDED(hr))
  {
    J = new MatInfo*[m_nEsos];
    J[0] = &LocalMassStruct;
    for (i = 1; i < m_nEsos; i++)
    {
      pEso = m_Esos[i];
      if (!pEso->m_bMasterNode) 
        J[i] = pEso->m_MassStruct;
      else
        J[i] = NULL;
    }

    MassStruct.m_nColIndices = 0;
    for (i = 0; i < m_nEsos; i++)
      MassStruct.m_nColIndices += (J[i] == NULL) ? 0 : J[i]->m_nColIndices;

    DESTROY_VECTOR(MassStruct.m_ColIndices)
    DESTROY_VECTOR(MassStruct.m_compact_data)
    DESTROY_VECTOR(MassStruct.m_compact_value)
    DESTROY_VECTOR(MassStruct.m_bValueSet)
    DESTROY_VECTOR(MassStruct.m_cNZCols)
    DESTROY_VECTOR(MassStruct.m_spRowPage)

    MassStruct.SetCompactSize(m_nEqns, MassStruct.m_nColIndices);

    k = 0;
    for (iEqn = 0; iEqn < m_nEqns; iEqn++)
    {
      MassStruct.m_spRowPage[iEqn] = k;
      iModel = m_EqnMap[iEqn].iModel;
      iDaeEqn = (iModel == 0) ? iEqn : m_EqnMap[iEqn].iEqn;
      pEso = m_Esos[iModel]; 
      cNZ = 0;
      MassStruct.m_cNZCols[iEqn] = 0;
      if (J[iModel])
      {
        if (J[iModel]->m_cNZCols) cNZ = J[iModel]->m_cNZCols[iDaeEqn];
        j = 0;
        if (J[iModel]->m_spRowPage) j = J[iModel]->m_spRowPage[iDaeEqn];
        for (i = 0; i < cNZ; i++)
        {
          iDaeVar = J[iModel]->m_ColIndices[j];
          if (m_bMasterNode)
            MassStruct.m_ColIndices[k] = (iModel == 0) ? iDaeVar : pEso->m_MNVariableMap[iDaeVar];
          else
            MassStruct.m_ColIndices[k] = (iModel == 0) ? iDaeVar : pEso->m_VariableMap[iDaeVar];

          MassStruct.m_compact_data[k] = J[iModel]->m_compact_data[j];
          MassStruct.m_compact_value[k] = J[iModel]->m_compact_value[j];
          MassStruct.m_bValueSet[k] = J[iModel]->m_bValueSet[j];
          MassStruct.m_cNZCols[iEqn]++;
          k++;
          j++;
        }
      }
    }
  }

  // cleanup
  DESTROY_VECTOR(J)

#if 0
  ATLTRACE("\n\nEquations [iEqn], [iModel, iEqn]");
  for (i = 0; i < m_nEqns; i++) ATLTRACE("\n[%d] [%d, %d]", i, m_EqnMap[i].iModel, m_EqnMap[i].iEqn);
  printMat2(m_nEqns, m_nVars, m_MassStruct->m_cNZCols, m_MassStruct->m_ColIndices); 
#endif

  return hr;
}


void CIsDaeEsoBase::initializeConstantJacobians()
{
  long iActiveEqn, iMapEqn, iVar, iActiveVar;
  long i, j, k;
  Jac_Calc_Method cm;
  long* indices = NULL;
  long count;
  HRESULT hr = S_OK;
  double* JacVals = new double[IMAX(m_JacStruct->m_nColIndices, m_MassStruct->m_nColIndices)];
  
  // zero the jacobian
  if (m_Jac->m_form != SPARSE)
  {
    for (i = 0; i < m_Jac->m_nRows; i++)
    {
      for (j = 0; j < m_Jac->m_nCols; j++)
        m_Jac->m_data[i][j] = 0.0;
    }
  }

  // clear the static jacobian and mass indices cache
  DESTROY_VECTOR(JacIndices)
  nJacIndices = 0;
  DESTROY_VECTOR(MassIndices)
  nMassIndices = 0;

  // initialize the constant jacobian values
  if (m_JacStruct->m_spRowPage)
  {
    count = 0;
    indices = new long[m_JacStruct->m_nColIndices*2];
    for (iActiveEqn = 0; iActiveEqn < m_nActiveEqns; iActiveEqn++)
    {
      iMapEqn = m_ActiveEqns[iActiveEqn];
      for (i = m_JacStruct->m_spRowPage[iMapEqn]; i < (m_JacStruct->m_spRowPage[iMapEqn] + m_JacStruct->m_cNZCols[iMapEqn]); i++)
      {
        iVar = m_JacStruct->m_ColIndices[i]; 
        iActiveVar = m_itActiveVars[iVar];
        cm = (Jac_Calc_Method) m_JacStruct->m_compact_data[i];
        if (cm == JCM_CONST)
        {
          if (m_JacStruct->m_bValueSet[i]) 
          {
            if (m_Jac->m_form != SPARSE)
              m_Jac->SetValue(iActiveEqn, iActiveVar, m_JacStruct->m_compact_value[i]);
          }
          else
          {
            indices[2*count] = iActiveEqn;
            indices[2*count+1] = iActiveVar;
            count++;
          }
        }
      }
    }
    
    hr = iGetJacobianValues(
      indices, 
      count, 
      *m_JacStruct, 
      m_time->m_curVal, 
      m_y->m_varVal, 
      m_y->m_varDotVal, 
      JacVals, 
      m_realParameters, 
      m_integerParameters, 
      true);

    for (i = 0; i < count; i++) 
    {
      iMapEqn = m_ActiveEqns[indices[2*i]];
      iVar = m_ActiveVars[indices[2*i+1]];
      k = m_JacStruct->m_spRowPage[iMapEqn];
      for (j = 0; j < m_JacStruct->m_cNZCols[iMapEqn]; j++)
      {
        if (m_JacStruct->m_ColIndices[j+k] == iVar)
        {
          m_JacStruct->m_compact_value[j+k] = JacVals[i];
          m_JacStruct->m_bValueSet[j+k] = true;
          break;
        }
      }

      if (m_Jac->m_form != SPARSE)
        m_Jac->SetValue(indices[2*i],indices[2*i+1],JacVals[i]);
    }

    DESTROY_VECTOR(indices)
  }

  if (m_Jac->m_form == SPARSE)
    m_Jac->SetActiveCompactSize(*m_JacStruct, m_ActiveEqns, m_nActiveEqns);

  // zero the diff jacobian
  if (m_Mass->m_form != SPARSE)
  {
    for (i = 0; i < m_Mass->m_nRows; i++)
    {
      for (j = 0; j < m_Mass->m_nCols; j++)
        m_Mass->m_data[i][j] = 0.0;
    }
  }
  
  // initialize the constant mass values
  if (m_MassStruct->m_spRowPage) 
  {
    count = 0;
    indices = new long[m_MassStruct->m_nColIndices*2];
    for (iActiveEqn = 0; iActiveEqn < m_nActiveEqns; iActiveEqn++)
    {
      iMapEqn = m_ActiveEqns[iActiveEqn];
      for (i = m_MassStruct->m_spRowPage[iMapEqn]; i < (m_MassStruct->m_spRowPage[iMapEqn] + m_MassStruct->m_cNZCols[iMapEqn]); i++)
      {
        iVar = m_MassStruct->m_ColIndices[i]; 
        iActiveVar = m_itActiveVars[iVar];
        cm = (Jac_Calc_Method) m_MassStruct->m_compact_data[i];
        if (cm == JCM_CONST)
        {
          if (m_MassStruct->m_bValueSet[i])
          {
            if (m_Mass->m_form != SPARSE)
              m_Mass->SetValue(iActiveEqn, iActiveVar, m_MassStruct->m_compact_value[i]);
          }
          else
          {
            indices[2*count] = iActiveEqn;
            indices[2*count+1] = iActiveVar;
            count++;
          }
        }
      }
    }
    
    iGetMassValues(
      indices,
      count,
      *m_MassStruct, 
      m_time->m_curVal, 
      m_y->m_varVal, 
      m_y->m_varDotVal, 
      JacVals, 
      m_realParameters, 
      m_integerParameters, 
      true);

    for (i = 0; i < count; i++) 
    {
      iMapEqn = m_ActiveEqns[indices[2*i]];
      iVar = m_ActiveVars[indices[2*i+1]];
      k = m_MassStruct->m_spRowPage[iMapEqn];
      for (j = 0; j < m_MassStruct->m_cNZCols[iMapEqn]; j++)
      {
        if (m_MassStruct->m_ColIndices[j+k] == iVar)
        {
          m_MassStruct->m_compact_value[j+k] = JacVals[i];
          m_MassStruct->m_bValueSet[j+k] = true;
          break;
        }
      }

      if (m_Mass->m_form != SPARSE)
        m_Mass->SetValue(indices[2*i],indices[2*i+1],JacVals[i]);
    }
    DESTROY_VECTOR(indices)
  }
 
  DESTROY_VECTOR(JacVals)

  if (m_Mass->m_form == SPARSE)
    m_Mass->SetActiveCompactSize(*m_MassStruct, m_ActiveEqns, m_nActiveEqns);
}


STDMETHODIMP CIsDaeEsoBase::InitTime(double StartTime, VARIANT_BOOL Reverse)
{
  long ks;
  long kn;
  long iVar;

  m_time->m_initVal = StartTime;
  m_time->m_reverse = (Reverse == VARIANT_TRUE) ? true : false;

	m_time->m_curVal = m_time->m_lastVal = m_time->m_initVal;
	m_time->m_curIteration = 0;

  if (m_Jac)
    m_Jac->m_updateRequired = true;

  if (!m_K)
  {
	  m_K = (VarInfo**) new VarInfo*[m_nStages];
	  for(ks = 0; ks < m_nStages; ks++) 
		  m_K[ks]= new VarInfo(m_nActiveVars); 
  }

	for (ks = 0; ks < m_nStages; ks++)
  {
		for(kn = 0; kn < m_nActiveVars; kn++)
    {
      iVar = m_ActiveVars[kn];
      m_K[ks]->m_varVal[kn] = m_y->m_varVal[iVar];
			m_K[ks]->m_varLastVal[kn] = m_y->m_varVal[iVar];
      m_K[ks]->m_varDotVal[kn] = m_y->m_varDotVal[iVar];
			m_K[ks]->m_varLastDotVal[kn] = m_y->m_varDotVal[iVar];
    }
  }

	m_report->m_idid = 1;
  return S_OK;
}

// initialize tolerance from executive
STDMETHODIMP CIsDaeEsoBase::SetRelTolerance(SAFEARRAY** relTolValue)
{
  double* pvData = NULL;
  long lbound, ubound, count;
  long i, idx;
  bool bScalar;
  HRESULT hr = E_INVALIDARG;

  if (*relTolValue)
  {
    SafeArrayGetLBound(*relTolValue, 1, &lbound);
    SafeArrayGetUBound(*relTolValue, 1, &ubound);
    count = ubound - lbound + 1;
    bScalar = (count == 1) ? true : false;
    m_tolerance->Init_rtol(bScalar, m_nVars);

    SafeArrayAccessData(*relTolValue, (void HUGEP* FAR*)& pvData);

    for (i = 0, idx = lbound; idx <= ubound && i < m_nVars; i++, idx++)
      m_tolerance->m_rtol[i] = pvData[idx];

    SafeArrayUnaccessData(*relTolValue);
    hr = S_OK;
  }

  return hr;
}

STDMETHODIMP CIsDaeEsoBase::GetRelTolerance(SAFEARRAY** relTolValue)
{
  double* pvData = NULL;
  long lbound, ubound;
  long i, idx;

  if (!m_tolerance->m_rtol)
    return E_FAIL;

  long count = m_tolerance->m_scalar ? 1 : m_nVars;
  ALLOC_SAFE_ARRAY(*relTolValue, count, VT_R8)
  SafeArrayAccessData(*relTolValue, (void HUGEP* FAR*)& pvData);

  for (i = 0, idx = lbound; idx <= ubound; i++, idx++)
    pvData[idx] = m_tolerance->m_rtol[i];

  SafeArrayUnaccessData(*relTolValue);

  return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::SetAbsTolerance(SAFEARRAY** absTolValues)
{
  double* pvData = NULL;
  long lbound, ubound, count;
  long i, idx;
  bool bScalar;
  HRESULT hr = E_INVALIDARG;

  if (*absTolValues)
  {
    SafeArrayGetLBound(*absTolValues, 1, &lbound);
    SafeArrayGetUBound(*absTolValues, 1, &ubound);
    count = ubound - lbound + 1;
    bScalar = (count == 1) ? true : false;
    m_tolerance->Init_atol(bScalar, m_nVars);

    SafeArrayAccessData(*absTolValues, (void HUGEP* FAR*)& pvData);

    for (i = 0, idx = lbound; idx <= ubound && i < m_nVars; i++, idx++)
      m_tolerance->m_atol[i] = pvData[idx];

    SafeArrayUnaccessData(*absTolValues);
    hr = S_OK;
  }

  return hr;
}

void CIsDaeEsoBase::iGetAbsTolerance(long iVar, double& atol)
{
  if (m_tolerance->m_scalar)
    atol = m_tolerance->m_atol[0];
  else
    atol = m_tolerance->m_atol[iVar];
}

void CIsDaeEsoBase::iGetRelTolerance(long iVar, double& rtol)
{
  if (m_tolerance->m_scalar)
    rtol = m_tolerance->m_rtol[0];
  else
    rtol = m_tolerance->m_rtol[iVar];
}

STDMETHODIMP CIsDaeEsoBase::GetAbsTolerance(SAFEARRAY** absTolValues)
{
  double* pvData = NULL;
  long lbound, ubound;
  long i, idx;

  if (!m_tolerance->m_atol)
    return E_FAIL;
  long count = m_tolerance->m_scalar ? 1l : m_nVars;
  ALLOC_SAFE_ARRAY(*absTolValues, count, VT_R8)
  SafeArrayAccessData(*absTolValues, (void HUGEP* FAR*)& pvData);

  for (i = 0, idx = lbound; idx <= ubound; i++, idx++)
    pvData[idx] = m_tolerance->m_atol[i];

  SafeArrayUnaccessData(*absTolValues);

  return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::GetAllResiduals(SAFEARRAY** residuals, VARIANT_BOOL* validVal)
{
  double* residuals_data = NULL;
  bool valid = false;
  long lbound, ubound;

  ALLOC_SAFE_ARRAY(*residuals, m_nVars, VT_R8)

  SafeArrayAccessData(*residuals, (void HUGEP* FAR*)& residuals_data);

  HRESULT hr = iGetAllResiduals(
    m_time->m_curVal, 
    m_y->m_varVal, 
    m_y->m_varDotVal, 
    residuals_data,
    valid,
    m_realParameters, 
    m_integerParameters);
  
  *validVal = valid ? VARIANT_TRUE : VARIANT_FALSE;

  SafeArrayUnaccessData(*residuals);

  return hr;
}

	// evaluate some equations
STDMETHODIMP CIsDaeEsoBase::GetResiduals(
		SAFEARRAY** indices, 
		SAFEARRAY** residuals,
		VARIANT_BOOL* validVal)
{
  long* indices_data = NULL;
  double* residuals_data = NULL;
  bool valid = false;
  long lbound, ubound;
  long cIndices;

  SafeArrayGetLBound(*indices, 1, &lbound);
  SafeArrayGetUBound(*indices, 1, &ubound);
  cIndices = ubound - lbound + 1;
  SafeArrayAccessData(*indices, (void HUGEP* FAR*)& indices_data);
  ALLOC_SAFE_ARRAY(*residuals, cIndices, VT_R8);
  SafeArrayAccessData(*residuals, (void HUGEP* FAR*)& residuals_data);

  HRESULT hr = iGetResiduals(
    indices_data,
    cIndices,
    m_time->m_curVal,
    m_y->m_varVal,
    m_y->m_varDotVal,
    residuals_data, 
    valid,
    m_realParameters, 
    m_integerParameters);
  
  *validVal = valid ? VARIANT_TRUE : VARIANT_FALSE;
  SafeArrayUnaccessData(*indices);
  SafeArrayUnaccessData(*residuals);

  return hr;
}

HRESULT CIsDaeEsoBase::iGetAllResiduals(
	double t,
	double* y,
	double* ydot,
  double* residuals,
	bool& validVal,
	double* realParameters, 
	long* integerParameters)
{
  HRESULT hr;
  long i;
  long* iEqns = NULL;
  
  iEqns = new long[m_nActiveEqns];
  for (i = 0; i < m_nActiveEqns; i++) iEqns[i] = i;

#if 0 // testing
  if (_run_residual_test)
  {
    for (i = 0; i < m_nActiveEqns; i++)
    {
      y[i] = (double) i;
      ydot[i] = (double) i;
    }

    for (i = 0; i < m_nRealParameters; i++) realParameters[i] = (double) i;
    for (i = 0; i < m_nIntegerParameters; i++) integerParameters[i] = i;
  }
#endif

  hr = iGetResiduals(
    iEqns, 
    m_nActiveEqns,
    t,
    y,
    ydot,
    residuals,
    validVal, 
    realParameters,
    integerParameters);

  DESTROY_VECTOR(iEqns)

#if 0
  if (_run_residual_test)
  {
    ATLTRACE("\n");
    for (i = 0; i < m_nActiveEqns; i++)
      ATLTRACE("\n%d\t%e", i, residuals[i]);
  }
#endif 

  return hr;
}

HRESULT CIsDaeEsoBase::iGetResiduals(
	long* Indices,                // equation indices
  long cIndices,                // count of equation indices
	double t,                     // time
	double* y,                    // y variable values
	double* ydot,                 // dy/dt values
  double* residuals,            // equation residuals
	bool& validVal,               // result validation
	double* realParameters,       // real parameters
	long* integerParameters)      // integer parameters
{
  HRESULT hr = S_OK;
  long i, j;
  CIsDaeEsoBase* pEso;
  long iActiveEqn, iMapEqn, iChildMapEqn, iModel;
  long* iEqns = NULL;
  long cEqns = 0;
  long* iLocalEqns = NULL;
  long cLocalEqns = 0;
  long spVar;
  long spRPar;
  long spIPar;
  long spRes;
  bool* iModels = NULL;
  
  double* pRPar = NULL;
  long* pIPar = NULL;

  iModels = new bool[m_nEsos];
  for (i = 0; i < m_nEsos; i++) iModels[i] = false;

  if (cIndices > 0)
  {
    iActiveEqn = Indices[0];
    iMapEqn = m_ActiveEqns[iActiveEqn];
    iModel = m_EqnMap[iMapEqn].iModel;
    pEso = m_Esos[iModel];
    spVar = m_spEsoVars[iModel];
    spRPar = m_spEsoRPars[iModel];
    spIPar = m_spEsoIPars[iModel];
    spRes = 0;

    cEqns = 0;
    iEqns = new long[cIndices];
    cLocalEqns = 0;
    iLocalEqns = new long[m_nLocalEqns];

    for (i = 0; i < cIndices && SUCCEEDED(hr); i++)
    {
      iActiveEqn = Indices[i];
      iMapEqn = m_ActiveEqns[iActiveEqn];
      iChildMapEqn = m_EqnMap[iMapEqn].iEqn;
      iModels[m_EqnMap[iMapEqn].iModel] = true;

      if (m_EqnMap[iMapEqn].iModel != iModel)
      {
        if (iModel == 0)
        {
          // defer calling local equations to the end so local equations are always executed last
          cLocalEqns = cEqns;
          for (j = 0; j < cEqns; j++) iLocalEqns[j] = iEqns[j];
        }
        else
        {
          if (pEso->m_bMasterNode)
          {
            double* ty = new double[pEso->m_nVars];
            double* tydot = new double[pEso->m_nVars];

            for (j = 0; j < pEso->m_nVars; j++)
            {
              ty[j] = y[pEso->m_MNVariableMap[j]];
              tydot[j] = ydot[pEso->m_MNVariableMap[j]];
            }

            // TODO: deal with the parameters as well.  I don't think that master nodes should take parameters
            hr = pEso->iGetResiduals(iEqns, cEqns, t, ty, tydot, &residuals[spRes], validVal, NULL, NULL);
            DESTROY_VECTOR(ty)
            DESTROY_VECTOR(tydot)
          }
          else
          {
            hr = pEso->iGetResiduals(iEqns, cEqns, t, &y[spVar], &ydot[spVar], &residuals[spRes], validVal, 
              &realParameters[spRPar], &integerParameters[spIPar]);
          }
        }

        cEqns = 0;
        iModel = m_EqnMap[iMapEqn].iModel;
        spVar = m_spEsoVars[iModel];
        spRPar = m_spEsoRPars[iModel];
        spIPar = m_spEsoIPars[iModel];
        pEso = m_Esos[iModel];
        spRes = i;
      }

      iEqns[cEqns++] = iModel == 0 ? iActiveEqn : pEso->m_itActiveEqns[iChildMapEqn];
    }
  }

  // call residuals for models that won't get called to force the update of the local variables
  if (cIndices > 0 || !m_bMasterNode)
  {
    for (i = 1; i < m_nEsos; i++)
    {
      if (!iModels[i])
      {
        if (realParameters) pRPar = &realParameters[m_spEsoRPars[i]];
        if (integerParameters) pIPar = &integerParameters[m_spEsoIPars[i]];
        m_Esos[i]->iGetResiduals(
          0,
          0,
          t, 
          &y[m_spEsoVars[i]],
          &ydot[m_spEsoVars[i]],
          residuals, 
          validVal, 
          pRPar, 
          pIPar);
      }
    }
  }

  if (cEqns > 0 && SUCCEEDED(hr))
  {
    if (iModel == 0)
    {
      hr = iGetLocalResiduals(iEqns, cEqns, t, y, ydot, residuals, validVal, 
        realParameters, integerParameters);
    }
    else
      hr = pEso->iGetResiduals(iEqns, cEqns, t, &y[spVar], &ydot[spVar], &residuals[spRes], validVal, 
        &realParameters[spRPar], &integerParameters[spIPar]);
  }

  if ((cLocalEqns > 0 || cIndices == 0) && SUCCEEDED(hr))
  {
    hr = iGetLocalResiduals(iLocalEqns, cLocalEqns, t, y, ydot, residuals, validVal, 
      realParameters, integerParameters);
  }

  DESTROY_VECTOR(iEqns)
  DESTROY_VECTOR(iLocalEqns)
  DESTROY_VECTOR(iModels)

  return hr;
}

HRESULT CIsDaeEsoBase::iGetAllJacobianValues(
  MatInfo& JacStruct,
  double t, 
  double* y, 
  double* ydot,
	double* JacVals,
  long*& Indices,
  long& nIndices,
  double* rPar, 
  long* iPar,
  bool bIncludeConst)
{
  HRESULT hr = S_OK;
  long i;
  long iActiveEqn, iMapEqn, iActiveVar, iVar;
  Jac_Calc_Method cm;

  // build vector of jacobian {iEqn, iVar} indices for jacobians requiring calculation
  Indices = new long[JacStruct.m_nColIndices * 2];
  nIndices = 0;
  for (iActiveEqn = 0; iActiveEqn < m_nActiveEqns && SUCCEEDED(hr); iActiveEqn++)
  {
    iMapEqn = m_ActiveEqns[iActiveEqn];
    for (i = JacStruct.m_spRowPage[iMapEqn]; i < (JacStruct.m_spRowPage[iMapEqn] + JacStruct.m_cNZCols[iMapEqn]) && SUCCEEDED(hr); i++)
    {
      iVar = JacStruct.m_ColIndices[i];
      iActiveVar = m_itActiveVars[iVar];
      cm = (Jac_Calc_Method) JacStruct.m_compact_data[i]; 
      if (cm != JCM_CONST || bIncludeConst)
      {
        Indices[2*nIndices] = iActiveEqn;
        Indices[2*nIndices+1] = iActiveVar;
        nIndices++;
      }
    }
  }
  
#if 0
  ATLTRACE("\nindices of non-constant jacobian values\n");
  long j;
  long k = 0;

  for (i = 0; i < m_nEqns; i++)
  {
    _ASSERTE(m_JacStruct->m_spRowPage[i] == k);
    ATLTRACE("\n%d", i);
    for (j = 0; j < m_JacStruct->m_cNZCols[i]; j++)
    {
      if (m_JacStruct->m_compact_data[k] != JCM_CONST) { ATLTRACE("\t%d", m_JacStruct->m_ColIndices[k]); }
      k++;
    }
  }
#endif

  hr = iGetJacobianValues(
    Indices, 
    nIndices, 
    JacStruct, 
    t,
    y, 
    ydot, 
    JacVals, 
    rPar, 
    iPar, 
    bIncludeConst);

  //DESTROY_VECTOR(Indices)

  return hr;
}

HRESULT CIsDaeEsoBase::iGetJacobianValues(
  long* indices,
  long cIndices,
  MatInfo& JacStruct,
  double t, 
  double* y, 
  double* ydot,
	double* JacVals, 
  double* rPar, 
  long* iPar,
  bool bIncludeConst)
{
  HRESULT hr = S_OK;
  long i, j;
  long iActiveEqn;
  long iMapEqn, iChildMapEqn;
  long iModel;
  long iActiveVar;
  long iVar, iDaeVar;
  long spVars;
  long spRPars;
  long spIPars;
  long spJac;
  CIsDaeEsoBase* pEso;
  long* loc_indices = NULL;
  long loc_count = 0;

  if (cIndices == 0) return S_OK;

  loc_indices = new long[2*cIndices];

  // get first model index, and Eso pointer
  iActiveEqn = indices[0];
  iMapEqn = m_ActiveEqns[iActiveEqn];
  iModel = m_EqnMap[iMapEqn].iModel;
  pEso = m_Esos[iModel];
  spVars = m_spEsoVars[iModel];
  spRPars = m_spEsoRPars[iModel];
  spIPars = m_spEsoIPars[iModel];
  spJac = 0;

  for (i = 0; i < cIndices && SUCCEEDED(hr); i++) 
  {
    iActiveEqn = indices[2*i];
    iMapEqn = m_ActiveEqns[iActiveEqn];
    iChildMapEqn = m_EqnMap[iMapEqn].iEqn;
    iActiveVar = indices[2*i+1];
    iDaeVar = iVar = m_ActiveVars[iActiveVar];

    if (m_EqnMap[iMapEqn].iModel != 0)
    {
      iDaeVar = m_VarMap[iVar].iVar;
      // TODO: find a way to make this more efficient
      if (pEso->m_bMasterNode)
      {
        for (j = 0; j < pEso->m_nVars; j++)
        {
          if (m_VarMap[iVar].iGlobalVar == pEso->m_VarMap[j].iGlobalVar) 
          {
            iDaeVar = j;
            break;
          }
        }
      }
    }

    if (m_EqnMap[iMapEqn].iModel != iModel)
    {
      if (iModel == 0)
      {
        hr = iGetLocalJacobianValues(loc_indices, loc_count, *m_JacStruct, t, 
          y, ydot, JacVals, rPar, iPar, bIncludeConst);
      }
      else
      {
        // member Eso
        if (pEso->m_bMasterNode)
        {
          double* ty = new double[pEso->m_nVars];
          double* tydot = new double[pEso->m_nVars];

          for (j = 0; j < pEso->m_nVars; j++)
          {
            ty[j] = y[pEso->m_MNVariableMap[j]];
            tydot[j] = ydot[pEso->m_MNVariableMap[j]];
          }

          hr = pEso->iGetJacobianValues(loc_indices, loc_count, *pEso->m_JacStruct, t, 
            ty, tydot, &JacVals[spJac], NULL, NULL, bIncludeConst);

          DESTROY_VECTOR(ty)
          DESTROY_VECTOR(tydot)
        }
        else
        {
          hr = pEso->iGetJacobianValues(loc_indices, loc_count, *pEso->m_JacStruct, t, 
            &y[spVars], &ydot[spVars], &JacVals[spJac], &rPar[spRPars], &iPar[spIPars], bIncludeConst);
        }
      }
      loc_count = 0;
      iModel = m_EqnMap[iMapEqn].iModel;
      spVars = m_spEsoVars[iModel];
      spRPars = m_spEsoRPars[iModel];
      spIPars = m_spEsoIPars[iModel];
      pEso = m_Esos[iModel];
      spJac = i;
    }
    loc_indices[2*loc_count] = iModel == 0 ? iActiveEqn : pEso->m_itActiveEqns[iChildMapEqn];
    loc_indices[2*loc_count+1] = pEso->m_itActiveVars[iDaeVar];
    loc_count++;
  }

  // complete last model entry
  if (loc_count > 0 && SUCCEEDED(hr))
  {
    if (iModel == 0)
    {
      hr = iGetLocalJacobianValues(loc_indices, loc_count, *m_JacStruct, t, 
        y, ydot, JacVals, rPar, iPar, bIncludeConst);
    }
    else
    {
      hr = pEso->iGetJacobianValues(loc_indices, loc_count, *pEso->m_JacStruct, t, 
        &y[spVars], &ydot[spVars], &JacVals[spJac], &rPar[spRPars], &iPar[spIPars], bIncludeConst);
    }
  }

  DESTROY_VECTOR(loc_indices)

  return hr;
}

HRESULT CIsDaeEsoBase::iGetAllMassValues(
  MatInfo& MassStruct,
  double t, 
  double* y, 
  double* ydot,
	double* MassVals,
  long*& Indices,
  long& nIndices,
  double* rPar, 
  long* iPar,
  bool bIncludeConst)
{
  HRESULT hr = S_OK;
  long i;
  long iActiveEqn, iMapEqn, iActiveVar, iVar;
  Jac_Calc_Method cm;

  // build vector of Mass {iEqn, iVar} indices for Masss requiring calculation
  Indices = new long[MassStruct.m_nColIndices * 2];
  nIndices = 0;
  for (iActiveEqn = 0; iActiveEqn < m_nActiveEqns && SUCCEEDED(hr); iActiveEqn++)
  {
    iMapEqn = m_ActiveEqns[iActiveEqn];
    for (i = MassStruct.m_spRowPage[iMapEqn]; i < (MassStruct.m_spRowPage[iMapEqn] + MassStruct.m_cNZCols[iMapEqn]) && SUCCEEDED(hr); i++)
    {
      iVar = MassStruct.m_ColIndices[i];
      iActiveVar = m_itActiveVars[iVar];
      cm = (Jac_Calc_Method) MassStruct.m_compact_data[i]; 
      if (cm != JCM_CONST || bIncludeConst)
      {
        Indices[2*nIndices] = iActiveEqn;
        Indices[2*nIndices+1] = iActiveVar;
        nIndices++;
      }
    }
  }

#if 0
  ATLTRACE("\nindices of non-constant mass values\n");
  long j;
  long k = 0;

  for (i = 0; i < m_nEqns; i++)
  {
    _ASSERTE(m_MassStruct->m_spRowPage[i] == k);
    ATLTRACE("\n%d", i);
    for (j = 0; j < m_MassStruct->m_cNZCols[i]; j++)
    {
      if (m_MassStruct->m_compact_data[k] != JCM_CONST) { ATLTRACE("\t%d", m_MassStruct->m_ColIndices[k]); }
      k++;
    }
  }
#endif

  hr = iGetMassValues(
    Indices, 
    nIndices, 
    MassStruct, 
    t, 
    y,
    ydot, 
    MassVals, 
    rPar, 
    iPar, 
    bIncludeConst);

  return hr;
}

HRESULT CIsDaeEsoBase::iGetMassValues(
  long* indices,
  long cIndices,
  MatInfo& MassStruct,
  double t, 
  double* y, 
  double* ydot,
	double* MassVals, 
  double* rPar, 
  long* iPar,
  bool bIncludeConst)
{
  HRESULT hr = S_OK;
  long i, j;
  long iActiveEqn;
  long iMapEqn;
  long iChildMapEqn;
  long iModel;
  long iActiveVar;
  long iVar;
  long iDaeVar;
  long spVars;
  long spRPars;
  long spIPars;
  long spJac;
  CIsDaeEsoBase* pEso;
  long* loc_indices = NULL;
  long loc_count = 0;

  if (cIndices == 0) return S_OK;
 
  loc_indices = new long[2*cIndices];
  // get first model index, and Eso pointer
  iActiveEqn = indices[0];
  iMapEqn = m_ActiveEqns[iActiveEqn];
  iModel = m_EqnMap[iMapEqn].iModel;
  pEso = m_Esos[iModel];
  spVars = m_spEsoVars[iModel];
  spRPars = m_spEsoRPars[iModel];
  spIPars = m_spEsoIPars[iModel];
  spJac = 0;

  for (i = 0; i < cIndices && SUCCEEDED(hr); i++) 
  {
    iActiveEqn = indices[2*i];
    iMapEqn = m_ActiveEqns[iActiveEqn];
    iChildMapEqn = m_EqnMap[iMapEqn].iEqn;
    iActiveVar = indices[2*i+1];
    iDaeVar = iVar = m_ActiveVars[iActiveVar];

    if (m_EqnMap[iMapEqn].iModel != 0)
    {
      iDaeVar = m_VarMap[iVar].iVar;
      // TODO: find a way to make this more efficient
      if (pEso->m_bMasterNode)
      {
        for (j = 0; j < pEso->m_nVars; j++)
        {
          if (m_VarMap[iVar].iGlobalVar == pEso->m_VarMap[j].iGlobalVar) 
          {
            iDaeVar = j;
            break;
          }
        }
      }
    }

    if (m_EqnMap[iMapEqn].iModel != iModel)
    {
      if (iModel == 0)
      {
        hr = iGetLocalMassValues(loc_indices, loc_count, *m_MassStruct, t, 
          y, ydot, MassVals, rPar, iPar, bIncludeConst);
      }
      else
      {
        if (pEso->m_bMasterNode)
        {
          double* ty = new double[pEso->m_nVars];
          double* tydot = new double[pEso->m_nVars];

          for (j = 0; j < pEso->m_nVars; j++)
          {
            ty[j] = y[pEso->m_MNVariableMap[j]];
            tydot[j] = ydot[pEso->m_MNVariableMap[j]];
          }

          hr = pEso->iGetMassValues(loc_indices, loc_count, *pEso->m_MassStruct, t, 
            ty, tydot, &MassVals[spJac], NULL, NULL, bIncludeConst);

          DESTROY_VECTOR(ty)
          DESTROY_VECTOR(tydot)
        }
        else
        {
          // member Eso
          hr = pEso->iGetMassValues(loc_indices, loc_count, *pEso->m_MassStruct, t, 
            &y[spVars], &ydot[spVars], &MassVals[spJac], &rPar[spRPars], &iPar[spIPars], bIncludeConst);
        }
      }
      loc_count = 0;
      iModel = m_EqnMap[iMapEqn].iModel;
      spVars = m_spEsoVars[iModel];
      spRPars = m_spEsoRPars[iModel];
      spIPars = m_spEsoIPars[iModel];
      pEso = m_Esos[iModel];
      spJac = i;
    }
    loc_indices[2*loc_count] = iModel == 0 ? iActiveEqn : pEso->m_itActiveEqns[iChildMapEqn];
    loc_indices[2*loc_count+1] = pEso->m_itActiveVars[iDaeVar];
    loc_count++;
  }

  // complete last model entry
  if (loc_count > 0 && SUCCEEDED(hr))
  {
    if (iModel == 0)
    {
      hr = iGetLocalMassValues(loc_indices, loc_count, *m_MassStruct, t, 
        y, ydot, MassVals, rPar, iPar, bIncludeConst);
    }
    else
    {
      hr = pEso->iGetMassValues(loc_indices, loc_count, *pEso->m_MassStruct, t, 
        &y[spVars], &ydot[spVars], &MassVals[spJac], &rPar[spRPars], &iPar[spIPars], bIncludeConst);
    }
  }

  DESTROY_VECTOR(loc_indices)

  return hr;
}

	// Jacobian matrix
STDMETHODIMP CIsDaeEsoBase::GetJacobianStruct(
    long* nColIndices, 
    SAFEARRAY** ppsaColIndices, 
    SAFEARRAY** ppsacNZCols, 
    SAFEARRAY** ppsaCalcMethod)
{
  long i;

  long ubound;
  long lbound;

  MatInfo* JacStruct = new MatInfo();
  HRESULT hr = iGetJacobianStruct(*JacStruct);

  ALLOC_SAFE_ARRAY(*ppsaColIndices, *nColIndices, VT_I4)
  ALLOC_SAFE_ARRAY(*ppsaCalcMethod, *nColIndices, VT_I4)
  ALLOC_SAFE_ARRAY(*ppsacNZCols, m_nEqns, VT_I4)

  long* vColIndices = NULL;
  long* vCalcMethod = NULL;
  long* vcNZCols = NULL;

  SafeArrayAccessData(*ppsaColIndices, (void HUGEP* FAR*)& vColIndices);
  SafeArrayAccessData(*ppsaCalcMethod, (void HUGEP* FAR*)& vCalcMethod);
  SafeArrayAccessData(*ppsacNZCols, (void HUGEP* FAR*)& vcNZCols);

  *nColIndices = JacStruct->m_nColIndices;
  for (i = 0; i < (*nColIndices); i++)
  {
    vColIndices[i] = JacStruct->m_ColIndices[i];
    vCalcMethod[i] = JacStruct->m_compact_data[i];
  }

  for (i = 0; i < m_nEqns; i++)
    vcNZCols[i] = JacStruct->m_cNZCols[i];

  SafeArrayUnaccessData(*ppsaColIndices);
  SafeArrayUnaccessData(*ppsaCalcMethod);
  SafeArrayUnaccessData(*ppsacNZCols);

  delete JacStruct;

  return hr;
}

STDMETHODIMP CIsDaeEsoBase::GetJacobianValues(SAFEARRAY** Indices, SAFEARRAY** JacVals)
{
  return E_NOTIMPL;
}

STDMETHODIMP CIsDaeEsoBase::GetAllJacobianValues(IIsMatrix** ppJacVals)
{
  return E_NOTIMPL;
}

	// Mass matrix
STDMETHODIMP CIsDaeEsoBase::GetDiffJacobianStruct(
    long* nColIndices, 
    SAFEARRAY** ppsaColIndices, 
    SAFEARRAY** ppsacNZCols, 
    SAFEARRAY** ppsaCalcMethod)
{
  long i;

  long ubound;
  long lbound;
  MatInfo* MassStruct = new MatInfo();

  HRESULT hr = iGetMassStruct(*MassStruct);

  ALLOC_SAFE_ARRAY(*ppsaColIndices, *nColIndices, VT_I4)
  ALLOC_SAFE_ARRAY(*ppsaCalcMethod, *nColIndices, VT_I4)
  ALLOC_SAFE_ARRAY(*ppsacNZCols, m_nEqns, VT_I4)

  long* vColIndices = NULL;
  long* vCalcMethod = NULL;
  long* vcNZCols = NULL;

  SafeArrayAccessData(*ppsaColIndices, (void HUGEP* FAR*)& vColIndices);
  SafeArrayAccessData(*ppsaCalcMethod, (void HUGEP* FAR*)& vCalcMethod);
  SafeArrayAccessData(*ppsacNZCols, (void HUGEP* FAR*)& vcNZCols);

  *nColIndices = MassStruct->m_nColIndices;
  for (i = 0; i < (*nColIndices); i++)
  {
    vColIndices[i] = MassStruct->m_ColIndices[i];
    vCalcMethod[i] = MassStruct->m_compact_data[i];
  }

  for (i = 0; i < m_nEqns; i++)
    vcNZCols[i] = MassStruct->m_cNZCols[i];

  SafeArrayUnaccessData(*ppsaColIndices);
  SafeArrayUnaccessData(*ppsaCalcMethod);
  SafeArrayUnaccessData(*ppsacNZCols);

  delete MassStruct;
  return hr;
}

STDMETHODIMP CIsDaeEsoBase::GetDiffJacobianValues(SAFEARRAY** Indices, SAFEARRAY** MassVals)
{
  return E_NOTIMPL;
}

STDMETHODIMP CIsDaeEsoBase::GetAllDiffJacobianValues(IIsMatrix** ppMassVals)
{
  return E_NOTIMPL;
}

STDMETHODIMP CIsDaeEsoBase::GetVariables(SAFEARRAY** Indices, double t, SAFEARRAY** Vals)
{
  return Interpolate(Indices, t, Vals);
}

STDMETHODIMP CIsDaeEsoBase::GetVariable(long iActiveVar, double t, double* val)
{
  iInterpolate(&iActiveVar, 1, t, val);
  return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::GetVariableId(BSTR Name, long* idx)
{
  return iGetVariableId(Name, idx);
}

STDMETHODIMP CIsDaeEsoBase::get_VariableMap(SAFEARRAY** pVal)
{
  long* pvData;
  long i;

	*pVal = SafeArrayCreateVector(VT_I4, 0, m_nVars);
  SafeArrayAccessData(*pVal, (void HUGEP* FAR*)& pvData);
  for (i = 0; i < m_nVars; i++) pvData[i] = m_VariableMap[i];
  SafeArrayUnaccessData(*pVal);
	return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::put_VariableMap(SAFEARRAY** newVal)
{
  long i;
  long* pvData;
  
  SafeArrayAccessData(*newVal, (void HUGEP* FAR*)& pvData);
  for (i = 0; i < m_nVars; i++) m_VariableMap[i] = pvData[i];
  SafeArrayUnaccessData(*newVal);

	return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::SetVariables(SAFEARRAY** Indices, SAFEARRAY** Vals)
{
  long* pIndices = NULL;
  double* pVals = NULL;
  long lbound, ubound, count;
  long i;

  SafeArrayGetLBound(*Indices, 1, &lbound);
  SafeArrayGetUBound(*Indices, 1, &ubound);

  SafeArrayAccessData(*Indices, (void HUGEP* FAR*)& pIndices);
  SafeArrayAccessData(*Vals, (void HUGEP* FAR*)& pVals);

  count = ubound - lbound + 1;

  for (i = 0; i < count; i++)
    SetVariable(pIndices[i], pVals[i]);

  SafeArrayUnaccessData(*Indices);
  SafeArrayUnaccessData(*Vals);

  return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::GetAllVariables(double t, SAFEARRAY** Vals)
{
  return InterpolateAll(t, Vals);
}

STDMETHODIMP CIsDaeEsoBase::SetAllVariables(SAFEARRAY** Vals)
{
  long i;
  double* pVals = NULL;
  long lbound, ubound, count;

  SafeArrayGetLBound(*Vals, 1, &lbound);
  SafeArrayGetUBound(*Vals, 1, &ubound);
  count = ubound - lbound + 1;

  HRESULT hr = E_INVALIDARG;
  if (count == m_nVars && lbound == 0)
  {
    SafeArrayAccessData(*Vals, (void HUGEP* FAR*)& pVals);
    for (i = 0; i < count; i++) 
      SetVariable(i, pVals[i]);

    SafeArrayUnaccessData(*Vals);
    hr = S_OK;
  }

  return hr;
}

STDMETHODIMP CIsDaeEsoBase::GetNumRealPars(long* nRPars)
{
  *nRPars = m_nRealParameters;
  return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::GetRealPar(long index, double* Val)
{
  HRESULT hr = E_INVALIDARG;
  
  if (index >= 0 && index < m_nRealParameters)
  {
    *Val = m_realParameters[index];
    hr = S_OK;
  }

  return hr;
}

STDMETHODIMP CIsDaeEsoBase::GetRealParId(BSTR Name, long* idx)
{
  return iGetRealParId(Name, idx);
}

STDMETHODIMP CIsDaeEsoBase::SetRealPar(long index, double newVal)
{
  HRESULT hr = E_INVALIDARG;
  long iModel;
  long iPar;

  if (index >= 0 && index < m_nRealParameters)
  {
    m_realParameters[index] = newVal;

    if (m_fm)
    {
      iModel = m_fm->RParMap[index].iModel;
      iPar = m_fm->RParMap[index].iPar;
      m_fm->EsoList[iModel]->SetRealPar(iPar, newVal);
    }
    hr = S_OK;
  }

  return hr;
}

STDMETHODIMP CIsDaeEsoBase::GetNumIntPars(long* nIPars)
{
  *nIPars = m_nIntegerParameters;
  return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::GetIntPar(long index, long* Val)
{
  HRESULT hr = E_INVALIDARG;
  
  if (index >= 0 && index < m_nIntegerParameters)
  {
    *Val = m_integerParameters[index];
    hr = S_OK;
  }

  return hr;
}

STDMETHODIMP CIsDaeEsoBase::GetIntParId(BSTR Name, long* idx)
{
  return iGetIntParId(Name, idx);
}

STDMETHODIMP CIsDaeEsoBase::SetIntPar(long index, long newVal)
{
  HRESULT hr = E_INVALIDARG;
  long iModel;
  long iPar;

  if (index >= 0 && index < m_nIntegerParameters)
  {
    m_integerParameters[index] = newVal;

    if (m_fm)
    {
      iModel = m_fm->IParMap[index].iModel;
      iPar = m_fm->IParMap[index].iPar;
      m_fm->EsoList[iModel]->SetRealPar(iPar, newVal);
    }

    hr = S_OK;
  }

  return hr;
}

STDMETHODIMP CIsDaeEsoBase::SetVariable(long iActiveVar, double val)
{
  CIsDaeEsoBase* pEso;
  long iVar = m_ActiveVars[iActiveVar];
  m_y->m_var_init[iVar] = val;
  m_y->m_varVal[iVar] = val;
  if (m_VarMap[iVar].iModel > 0)
  {
    pEso = m_Esos[m_VarMap[iVar].iModel];
    pEso->SetVariable(pEso->m_itActiveVars[m_VarMap[iVar].iVar], val);
  }

  if (m_VarMap[iVar].iMNModel > 0)
  {
    pEso = m_Esos[m_VarMap[iVar].iMNModel];
    pEso->SetVariable(m_VarMap[iVar].iMNVar, val);
  }

  return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::SetLastVariable(long iActiveVar, double val)
{
  CIsDaeEsoBase* pEso;
  long iVar = m_ActiveVars[iActiveVar];
  m_y->m_varLastVal[iVar] = val;
  if (m_VarMap[iVar].iModel > 0)
  {
    pEso = m_Esos[m_VarMap[iVar].iModel];
    pEso->SetLastVariable(pEso->m_itActiveVars[m_VarMap[iVar].iVar], val);
  }

  if (m_VarMap[iVar].iMNModel > 0)
  {
    pEso = m_Esos[m_VarMap[iVar].iMNModel];
    pEso->SetLastVariable(m_VarMap[iVar].iMNVar, val);
  }

  return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::GetDerivatives(SAFEARRAY** Indices, double t, SAFEARRAY** Vals)
{
  long* pIndices = NULL;
  double* pVals = NULL;
  long lbound, ubound, count;

  SafeArrayGetLBound(*Indices, 1, &lbound);
  SafeArrayGetUBound(*Indices, 1, &ubound);
  SafeArrayAccessData(*Indices, (void HUGEP* FAR*)& pIndices);
  ALLOC_SAFE_ARRAY(*Vals, ubound - lbound + 1, VT_R8)
  SafeArrayAccessData(*Vals, (void HUGEP* FAR*)& pVals);

  count = ubound - lbound + 1;
  iDerivInterpolate(pIndices, count, t, pVals); 
  
  SafeArrayUnaccessData(*Indices);
  SafeArrayUnaccessData(*Vals);

  return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::GetDerivative(long iActiveVar, double t, double* val)
{
  iDerivInterpolate(&iActiveVar, 1, t, val);

  return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::SetDerivatives(SAFEARRAY** psaIndices, SAFEARRAY** psaVals)
{
  long* pIndices = NULL;
  double* pVals = NULL;
  long lbound, ubound, count;
  long i;

  SafeArrayAccessData(*psaIndices, (void HUGEP* FAR*)& pIndices);
  SafeArrayAccessData(*psaVals, (void HUGEP* FAR*)& pVals);

  SafeArrayGetLBound(*psaIndices, 1, &lbound);
  SafeArrayGetUBound(*psaIndices, 1, &ubound);
  count = ubound - lbound + 1;

  for (i = 0; i < count; i++)
    SetDerivative(pIndices[i], pVals[i]);

  SafeArrayUnaccessData(*psaIndices);
  SafeArrayUnaccessData(*psaVals);

  return S_OK;
}


STDMETHODIMP CIsDaeEsoBase::SetTime(double time)
{
  long i;
  m_time->m_curVal = time;
  if (!m_bMasterNode)
    for (i = 1; i < m_nEsos; i++) m_Esos[i]->SetTime(time);

  return S_OK;
}

HRESULT CIsDaeEsoBase::iDirectSetTime(double time)
{
  long i;

  if (m_bGlobalNode)
  {
    for (i = 0; i < m_fm->EsoCount; i++)
      m_fm->EsoList[i]->m_time->m_curVal = time;
  }
  return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::SetLastTime(double time)
{
  long i;
  m_time->m_lastVal = time;
  if (!m_bMasterNode)
    for (i = 1; i < m_nEsos; i++) m_Esos[i]->SetLastTime(time);

  return S_OK;
}

HRESULT CIsDaeEsoBase::iDirectSetLastTime(double time)
{
  long i;

  if (m_bGlobalNode)
  {
    for (i = 0; i < m_fm->EsoCount; i++)
      m_fm->EsoList[i]->m_time->m_lastVal = time;
  }
  return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::SetDerivative(long iActiveVar, double val)
{
  long iVar;
  CIsDaeEsoBase* pEso;

  iVar = m_ActiveVars[iActiveVar];
  m_y->m_varDot_init[iVar] = val;
  m_y->m_varDotVal[iVar] = val;
  if (m_VarMap[iVar].iModel > 0)
  {
    pEso = m_Esos[m_VarMap[iVar].iModel];
    pEso->SetDerivative(pEso->m_itActiveVars[m_VarMap[iVar].iVar], val);
  }

  if (m_VarMap[iVar].iMNModel > 0)
  {
    pEso = m_Esos[m_VarMap[iVar].iMNModel];
    pEso->SetDerivative(m_VarMap[iVar].iMNVar, val);
  }

  return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::SetLastDerivative(long iActiveVar, double val)
{
  long iVar;
  CIsDaeEsoBase* pEso;

  iVar = m_ActiveVars[iActiveVar];
  m_y->m_varLastDotVal[iVar] = val;
  if (m_VarMap[iVar].iModel > 0)
  {
    pEso = m_Esos[m_VarMap[iVar].iModel];
    pEso->SetLastDerivative(pEso->m_itActiveVars[m_VarMap[iVar].iVar], val);
  }

  if (m_VarMap[iVar].iMNModel > 0)
  {
    pEso = m_Esos[m_VarMap[iVar].iMNModel];
    pEso->SetLastDerivative(m_VarMap[iVar].iMNVar, val);
  }

  return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::GetAllDerivatives(double t, SAFEARRAY** ppsaVals)
{
  long lbound, ubound;

  ALLOC_SAFE_ARRAY(*ppsaVals, m_nVars, VT_R8)
  double* pvData = NULL;

  SafeArrayAccessData(*ppsaVals, (void HUGEP* FAR*)& pvData);
  iDerivInterpolateAll(t, pvData); 
  SafeArrayUnaccessData(*ppsaVals);

  return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::SetAllDerivatives(SAFEARRAY** ppsaVals)
{
  long i, idx;
  double* pVals = NULL;
  long lbound, ubound;

  SafeArrayAccessData(*ppsaVals, (void HUGEP* FAR*)& pVals);

  SafeArrayGetLBound(*ppsaVals, 1, &lbound);
  SafeArrayGetUBound(*ppsaVals, 1, &ubound);

  for (i = 0, idx = lbound; idx <= ubound; i++, idx++)
    SetDerivative(i, pVals[i]);

  SafeArrayUnaccessData(*ppsaVals);

  return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::GetNumVars(long* nVars)
{
  *nVars = m_nActiveVars;
  return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::GetNumEqns(long* nEqns)
{
  *nEqns = m_nActiveEqns;
  return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::GetNumLocalVars(long* nVars)
{
  *nVars = m_nLocalVars;
  return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::GetNumLocalEqns(long* nEqns)
{
  *nEqns = m_nLocalEqns;
  return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::GetLastTime(double* t)
{
  *t = m_time->m_lastVal;
  return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::GetTime(double* t)
{
  *t = m_time->m_curVal;
  return S_OK;
}

HRESULT CIsDaeEsoBase::InterpolateAll(double t, SAFEARRAY** pVals)
{
  long lbound, ubound;
  double* pvSample = NULL;

  ALLOC_SAFE_ARRAY(*pVals, m_nVars, VT_R8)
  SafeArrayAccessData(*pVals, (void HUGEP* FAR*)& pvSample);
  iInterpolateAll(t, pvSample);
  SafeArrayUnaccessData(*pVals);

  return S_OK;
}

HRESULT CIsDaeEsoBase::Interpolate(SAFEARRAY** Indices, double t, SAFEARRAY** pVals)
{
  double* pvSample = NULL;
  long* pvIndices = NULL;
  long lbound, ubound;
  long cIndices;
  long i;

  SafeArrayGetLBound(*Indices, 1, &lbound);
  SafeArrayGetUBound(*Indices, 1, &ubound);
  cIndices = ubound - lbound + 1;

  ALLOC_SAFE_ARRAY(*pVals, cIndices, VT_R8)
  SafeArrayAccessData(*pVals, (void HUGEP* FAR*)& pvSample);
  SafeArrayAccessData(*Indices, (void HUGEP* FAR*)& pvIndices);

  long* indices = new long[cIndices];
  for (i = 0; i < cIndices; i++) indices[i] = m_ActiveVars[pvIndices[i]];

  iInterpolate(indices, cIndices, t, pvSample);

  DESTROY_VECTOR(indices)
  SafeArrayUnaccessData(*pVals);
  SafeArrayUnaccessData(*Indices);
  return S_OK;
}

void CIsDaeEsoBase::iInterpolateAll(double tau, double* u)
{
  // reference the class variables using local variables to keep this function readable.
  double t0 = m_time->m_lastVal;
  double t1 = m_time->m_curVal;
  double* y0 = m_y->m_varLastVal;
  double* y1 = m_y->m_varVal;
  double* ydot0 = m_y->m_varLastDotVal;
  double* ydot1 = m_y->m_varDotVal;

	double h, theta;
	long iActiveVar, iVar;

	h= t1 - t0;
	if (h == 0.0)
  {
	  for (iActiveVar = 0; iActiveVar < m_nActiveVars; iActiveVar++)
    {
      iVar = m_ActiveVars[iActiveVar];
		  u[iActiveVar] = y1[iVar];
    }
	}
  else
  {
    theta = (tau - t0) / h;

	  for (iActiveVar = 0; iActiveVar < m_nActiveVars; iActiveVar++)
    {
      iVar = m_ActiveVars[iActiveVar];
		  u[iActiveVar] = (1-theta)*y0[iVar]+theta*y1[iVar]
			     +theta*(theta-1)*((1-2*theta)*(y1[iVar]-y0[iVar])+(theta-1)*h*ydot0[iVar]+theta*h*ydot1[iVar]);
	  }
  }
}


void CIsDaeEsoBase::iInterpolate(long* Idx, long cIdx, double tau, double* u)
{
  // reference the class variables using local variables to keep this function readable.
  double t0 = m_time->m_lastVal;
  double t1 = m_time->m_curVal;
  double* y0 = m_y->m_varLastVal;
  double* y1 = m_y->m_varVal;
  double* ydot0 = m_y->m_varLastDotVal;
  double* ydot1 = m_y->m_varDotVal;

	double h, theta;
  long i;
	long iVar;

	h= t1 - t0;
  if (h == 0.0)
  {
	  for (i = 0; i < cIdx; i++)    
    {
      if (Idx[i] < 0) iVar = Idx[i] + DIRECT_OFFSET;
      else iVar = m_ActiveVars[Idx[i]];

      u[i] = y1[iVar];
    }
  }
  else
  {
	  theta = (tau - t0) / h;
    // note: the alternate method of calculating udot can only be used when all 
    //       values are interpolated at once.
	  for (i = 0; i < cIdx; i++)
    {
      if (Idx[i] < 0) iVar = Idx[i] + DIRECT_OFFSET;
      else iVar = m_ActiveVars[Idx[i]];
		  
      u[i] = (1-theta)*y0[iVar]+theta*y1[iVar]
			     +theta*(theta-1)*((1-2*theta)*(y1[iVar]-y0[iVar])+(theta-1)*h*ydot0[iVar]+theta*h*ydot1[iVar]);
	  }
  }
}

void CIsDaeEsoBase::iDerivInterpolate(long* Idx, long cIdx, double tau, double* u, double* udot)
{
  // reference the class variables using local variables to keep this function readable.
  double t0 = m_time->m_lastVal;
  double t1 = m_time->m_curVal;
  double* y0 = m_y->m_varLastVal;
  double* y1 = m_y->m_varVal;
  double* ydot0 = m_y->m_varLastDotVal;
  double* ydot1 = m_y->m_varDotVal;

	double h, theta;
	long i;
  long iVar;

	h= t1 - t0;
  if (h == 0.0)
  {
    for (i = 0; i < cIdx; i++)
    {
      if (Idx[i] < 0) iVar = Idx[i] + DIRECT_OFFSET;
      else iVar = m_ActiveVars[Idx[i]];
      u[i] = y1[iVar];
      udot[i] = ydot1[iVar];
    }
  }
  else
  {
	  theta = (tau - t0) / h;
	  for (i = 0; i < cIdx; i++)
    {
      if (Idx[i] < 0) iVar = Idx[i] + DIRECT_OFFSET;
      else iVar = m_ActiveVars[Idx[i]];

      u[i] = (1-theta)*y0[iVar]+theta*y1[iVar]
			     +theta*(theta-1)*((1-2*theta)*(y1[iVar]-y0[iVar])+(theta-1)*h*ydot0[iVar]+theta*h*ydot1[iVar]);
  /* 
    keep this around in case we ever want second derivatives
		  udotdot[i] = 1/h*(6*(1.0-2.0*theta)*(y1[i]-y0[i])/h 
					  + (6.0*theta-4)*ydot0[i] 
					  + (6.0*theta-2.0)*ydot1[i]);
  */		
  	  udot[i] = 6*theta*(1.0-theta)*(y1[iVar]-y0[iVar])/h 
					  + (3.0*theta-1)*(theta-1)*ydot0[iVar] 
					  + theta*(3.0*theta -2.0)*ydot1[iVar];
	  }
  }
}

void CIsDaeEsoBase::iDerivInterpolate(long* Idx, long cIdx, double tau, double* udot)
{
  // reference the class variables using local variables to keep this function readable.
  double t0 = m_time->m_lastVal;
  double t1 = m_time->m_curVal;
  double* y0 = m_y->m_varLastVal;
  double* y1 = m_y->m_varVal;
  double* ydot0 = m_y->m_varLastDotVal;
  double* ydot1 = m_y->m_varDotVal;

	double h, theta;
  long i;
	long iVar;

	h= t1 - t0;
  if (h == 0.0)
  {
    for (i = 0; i < cIdx; i++)
    {
      if (Idx[i] < 0) iVar = Idx[i] + DIRECT_OFFSET;
      else iVar = m_ActiveVars[Idx[i]];
      udot[i] = ydot1[iVar];
    }
  }
  else
  {
	  theta = (tau - t0) / h;
	  for (i = 0; i < cIdx; i++)
    {
  /* 
    keep this around in case we ever want second derivatives
		  udotdot[i] = 1/h*(6*(1.0-2.0*theta)*(y1[i]-y0[i])/h 
					  + (6.0*theta-4)*ydot0[i] 
					  + (6.0*theta-2.0)*ydot1[i]);
  */		
      if (Idx[i] < 0) iVar = Idx[i] + DIRECT_OFFSET;
      else iVar = m_ActiveVars[Idx[i]];

  	  udot[i] = 6*theta*(1.0-theta)*(y1[iVar]-y0[iVar])/h 
					  + (3.0*theta-1)*(theta-1)*ydot0[iVar] 
					  + theta*(3.0*theta -2.0)*ydot1[iVar];
	  }
  }
}

void CIsDaeEsoBase::iDerivInterpolateAll(double tau, double* u, double* udot)
{
  // reference the class variables using local variables to keep this function readable.
  double t0 = m_time->m_lastVal;
  double t1 = m_time->m_curVal;
  double* y0 = m_y->m_varLastVal;
  double* y1 = m_y->m_varVal;
  double* ydot0 = m_y->m_varLastDotVal;
  double* ydot1 = m_y->m_varDotVal;

	double h, theta;
  long iActiveVar, iVar;

	h= t1 - t0;
  if (h == 0)
  {
    for (iActiveVar = 0; iActiveVar < m_nActiveVars; iActiveVar++)
    {
      iVar = m_ActiveVars[iActiveVar];
      u[iActiveVar] = y0[iVar];
      udot[iActiveVar] = ydot0[iVar];
    }
  }
  else
  {
	  theta = (tau - t0) / h;

	  for (iActiveVar = 0; iActiveVar < m_nActiveVars; iActiveVar++)
    {
      iVar = m_ActiveVars[iActiveVar];

		  u[iActiveVar] = (1-theta)*y0[iVar]+theta*y1[iVar]
			     +theta*(theta-1)*((1-2*theta)*(y1[iVar]-y0[iVar])+(theta-1)*h*ydot0[iVar]+theta*h*ydot1[iVar]);

      udot[iActiveVar] = 6*theta*(1.0-theta)*(y1[iVar]-y0[iVar])/h 
				  + (3.0*theta-1)*(theta-1)*ydot0[iVar] 
				  + theta*(3.0*theta -2.0)*ydot1[iVar];

//      udotdot[i] = 1/h*(6*(1.0-2.0*theta)*(y1[i]-y0[i])/h 
//					  + (6.0*theta-4)*ydot0[i] 
//					  + (6.0*theta-2.0)*ydot1[i]);
	  }
  }
}

void CIsDaeEsoBase::iDerivInterpolateAll(double tau, double* udot)
{
  // reference the class variables using local variables to keep this function readable.
  double t0 = m_time->m_lastVal;
  double t1 = m_time->m_curVal;
  double* y0 = m_y->m_varLastVal;
  double* y1 = m_y->m_varVal;
  double* ydot0 = m_y->m_varLastDotVal;
  double* ydot1 = m_y->m_varDotVal;

	double h, theta;
	long iActiveVar, iVar;

	h= t1 - t0;
  if (h == 0)
  {
    for (iActiveVar = 0; iActiveVar < m_nActiveVars; iActiveVar++)
    {
      iVar = m_ActiveVars[iActiveVar];
      udot[iActiveVar] = ydot0[iVar];
    }
  }
  else
  {
	  theta = (tau - t0) / h;

	  for (iActiveVar = 0; iActiveVar < m_nActiveVars; iActiveVar++)
    {
      iVar = m_ActiveVars[iActiveVar];
      udot[iActiveVar] = 6*theta*(1.0-theta)*(y1[iVar]-y0[iVar])/h 
				  + (3.0*theta-1)*(theta-1)*ydot0[iVar] 
				  + theta*(3.0*theta -2.0)*ydot1[iVar];
    }
  }
}

HRESULT CIsDaeEsoBase::UpdateAllJacobianValues()
{
  HRESULT hr = S_OK;
  long i;

  double* JacVals = new double[m_JacStruct->m_nColIndices];
  if (JacIndices == NULL)
  {
    // the following function does the necessary jacobian calculations, and it returns the 
    // indices of the jacobians that need to be evaluated in the future.
    hr = iGetAllJacobianValues(
      *m_JacStruct,
      m_time->m_curVal,
      m_y->m_varVal,
      m_y->m_varDotVal,
		  JacVals,
      JacIndices,
      nJacIndices,
      m_realParameters,
      m_integerParameters,
      false);
  }
  else
  {
    // having the indices of the jacobians that need to be calculated, the more efficient 
    // iGetJacobianValues() can be used.
    hr = iGetJacobianValues(
      JacIndices,
      nJacIndices,
      *m_JacStruct,
      m_time->m_curVal,
      m_y->m_varVal,
      m_y->m_varDotVal,
		  JacVals,
      m_realParameters,
      m_integerParameters,
      false);
  }

  if (SUCCEEDED(hr))
  {
    for (i = 0; i < nJacIndices; i++) 
      m_Jac->SetValue(JacIndices[2*i], JacIndices[2*i+1], JacVals[i]);

    m_Jac->m_dataUpToDate = true;
  }

  DESTROY_VECTOR(JacVals)

  return hr;
}

HRESULT CIsDaeEsoBase::UpdateAllDiffJacobianValues()
{
  HRESULT hr = S_OK;
  long i;

  double* MassVals = new double[m_MassStruct->m_nColIndices];
  if (MassIndices == NULL)
  {
    // the following function does the necessary Mass calculations, and it returns the 
    // indices of the Masss that need to be evaluated in the future.
    hr = iGetAllMassValues(
      *m_MassStruct,
      m_time->m_curVal,
      m_y->m_varVal,
      m_y->m_varDotVal,
		  MassVals,
      MassIndices,
      nMassIndices,
      m_realParameters,
      m_integerParameters,
      false);
  }
  else
  {
    // having the indices of the Masss that need to be calculated, the more efficient 
    // iGetMassValues() can be used.
    hr = iGetMassValues(
      MassIndices,
      nMassIndices,
      *m_MassStruct,
      m_time->m_curVal,
      m_y->m_varVal,
      m_y->m_varDotVal,
		  MassVals,
      m_realParameters,
      m_integerParameters,
      false);
  }

  if (SUCCEEDED(hr))
  {
    for (i = 0; i < nMassIndices; i++) 
      m_Mass->SetValue(MassIndices[2*i], MassIndices[2*i+1], MassVals[i]);

    m_Mass->m_dataUpToDate = true;
  }

  DESTROY_VECTOR(MassVals)

  return hr;
}

STDMETHODIMP CIsDaeEsoBase::GetVariablesIndex(SAFEARRAY** Index)
{
  long i, idx, ubound, lbound;
  short* differentialIndex = NULL;
  short* pvData = NULL;

  HRESULT hr = iGetVariablesIndex(differentialIndex);
  if (SUCCEEDED(hr))
  {
    ALLOC_SAFE_ARRAY(*Index, m_nVars, VT_I2)
    SafeArrayAccessData(*Index, (void HUGEP* FAR*)& pvData);
    for (i = 0, idx = lbound; i < m_nVars; i++, idx++)
      pvData[idx] = differentialIndex[i];

    SafeArrayUnaccessData(*Index);
  }

  // cleanup
  DESTROY_VECTOR(differentialIndex)

  return hr;
}

/*************************************************************************
/ Memory allocation:
/    Argument    Allocation()             Deallocation()
/
/    VAL         iGetEquationStructure    iGetVariablesIndex
/    assignedEqn iCalculateMSS            iGetVariablesIndex
/    EAL         iCalculateMSS            iGetVariablesIndex
/    diffIndex   iCalculateMSS            caller
**************************************************************************/
HRESULT CIsDaeEsoBase::iGetVariablesIndex(short*& differentialIndex)
{
	long nAugmentedVars = 0;
  long nEqns;
  long nVars;
	long* VAL = NULL;
  long* assignedEqn = NULL;
  long nColIndices = 0;
  long* cRowNZ = NULL;
  long* spRowPage = NULL;
  long* ColIndices = NULL;
  long* EqnOrder = NULL;
  long* VarOrder = NULL;
  long nDiscEqns = 0;
  long* DiscEqns = NULL;
  long* DiscVars = NULL;
  short* loc_differentialIndex = NULL;
  
  long* out_VAL = NULL;
  long* out_EAL = NULL;
  long out_edgeList_nColumnIndices = 0;
  long* out_edgeList_spRowPage = NULL; 
  long* out_edgeList_cRowNZ = NULL;
  long* out_edgeList_iColIndices = NULL; 
  long i;
  long iRet = 0;

  HRESULT hr = iGetNlaStruct(
    nEqns, nVars, nAugmentedVars, VAL, EqnOrder, VarOrder, 
    nColIndices, cRowNZ, spRowPage, ColIndices);

  if (SUCCEEDED(hr))
    iRet = iCalculateMSS(nAugmentedVars, nEqns, VAL, cRowNZ, ColIndices, 
      out_VAL, out_EAL, 
      out_edgeList_nColumnIndices, out_edgeList_spRowPage, out_edgeList_cRowNZ, out_edgeList_iColIndices, 
      assignedEqn, loc_differentialIndex);

  differentialIndex = new short[m_nVars];
  for (i = 0; i < m_nVars; i++) differentialIndex[i] = 1;
  for (i = 0; i < nVars; i++) differentialIndex[VarOrder[i]] = loc_differentialIndex[i];

  // cleanup
  DESTROY_VECTOR(VarOrder)
  DESTROY_VECTOR(EqnOrder)
  DESTROY_VECTOR(DiscEqns)
  DESTROY_VECTOR(DiscVars)

  DESTROY_VECTOR(VAL)
  DESTROY_VECTOR(cRowNZ)
  DESTROY_VECTOR(spRowPage)
  DESTROY_VECTOR(ColIndices)

  DESTROY_VECTOR(out_VAL)
  DESTROY_VECTOR(out_EAL)
  DESTROY_VECTOR(out_edgeList_cRowNZ)
  DESTROY_VECTOR(out_edgeList_iColIndices) 
  DESTROY_VECTOR(assignedEqn)
  DESTROY_VECTOR(loc_differentialIndex)

  if (FAILED(hr))
    return hr;
  else if (iRet == iMSS_MaxCalls)
    return E_FAIL;
  else
    return hr;
}

HRESULT CIsDaeEsoBase::iGetNlaStruct(
    long& nEqns,
    long& nVars,
    long& nAugmentedVars,
    long*& VAL,
    long*& EqnOrder,
    long*& VarOrder,
    long& edgeList_nColumnIndices,
    long*& edgeList_cRowNZ,
    long*& edgeList_spRowPage,
    long*& edgeList_ColumnIndices)
{
  long i, j, k, l, m;
  long* iDifferentialVars = new long[m_nVars];
  long* itDiscVars = NULL;
  long* itVarOrder = NULL;
  long nDiscVars = 0;
  long iMapEqn;
  long nDifferentialVars;

  // include all continuous equations, and exlude discontinuous equations
  EqnOrder = new long[2*m_nEqns];

  // determine row order
  nEqns = 0;
  for (i = 0; i < 2*m_nEqns; i++) EqnOrder[i] = -1;

  if (m_fm)
  {
    for (i = 0; i < m_fm->nEqns; i++)
      if (m_fm->EqnMap[i]->bActive && !m_fm->EqnMap[i]->bDiscontinuous) EqnOrder[nEqns++] = i;
  }
  else
  {
    for (i = 0; i < m_nEqns; i++)
      if (m_EqnMap[i].bActive && !m_EqnMap[i].bDiscontinuous) EqnOrder[nEqns++] = i;
  }

#if 0
  printVec("EqnOrder",EqnOrder,nEqns);
#endif

  for (i = 0; i < m_nVars; i++)
    iDifferentialVars[i] = 0;

  for (i  = 0; i < m_nActiveEqns; i++)
  {
    iMapEqn = m_ActiveEqns[i];
    k = m_MassStruct->m_spRowPage[iMapEqn];
    for (j = 0; j < m_MassStruct->m_cNZCols[iMapEqn]; j++)
    {
      if (m_MassStruct->m_ColIndices[k] >= 0 && m_MassStruct->m_ColIndices[k] < m_nVars)
        iDifferentialVars[m_MassStruct->m_ColIndices[k]]++;

      k++;
    }
  }

#if 0
  printVec("iDifferentialVars",iDifferentialVars,m_nVars);
#endif

  // determine the number of discontinuous variables
  nDiscVars = 0;
  if (m_fm)
  {
    for (i = 0; i < m_fm->nVars; i++)
      if (m_fm->VarMap[i]->bDiscontinuous && m_fm->VarMap[i]->bActive) nDiscVars++;
  }
  else
  {
    for (i = 0; i < m_nVars; i++)
      if (m_VarMap[i].bDiscontinuous && m_VarMap[i].bActive) nDiscVars++;
  }

  nAugmentedVars = nVars = m_nActiveVars - nDiscVars;
  nDifferentialVars = 0;
  for (i = 0; i < m_nVars; i++)
  {
    if (iDifferentialVars[i] > 0)
    {
      nAugmentedVars++;
      nDifferentialVars++;
    }
  }

  // determine column order
  VarOrder = new long[nAugmentedVars];
  j = 0;
  if (m_fm)
  {
    for (i = 0; i < (m_nVars + nDifferentialVars); i++)
    {
      if (i < m_nVars)
      {
        if (m_fm->VarMap[i]->bActive && !m_fm->VarMap[i]->bDiscontinuous) 
          VarOrder[j++] = i;
      }
      else
      {
        VarOrder[j++] = i;
      }
    }
  }
  else
  {
    for (i = 0; i < (m_nVars + nDifferentialVars); i++)
    {
      if (i < m_nVars)
      {
        if (m_VarMap[i].bActive && !m_VarMap[i].bDiscontinuous) 
          VarOrder[j++] = i;
      }
      else
      {
        VarOrder[j++] = i;
      }
    }
  }

  // calculate the transpose of the column vector
  TransposeVector(VarOrder, nAugmentedVars, itVarOrder, m_nVars + nDifferentialVars);

#if 0
  printVec("VarOrder",VarOrder, nAugmentedVars);
  printVec("itVarOrder", itVarOrder, m_nVars + nDifferentialVars);
#endif

  j = nVars;
  VAL = new long[nAugmentedVars];
  for (i = 0; i < nVars; i++)
  {
    VAL[i] = -1;
    if (iDifferentialVars[VarOrder[i]] > 0)
    {
      VAL[i] = j;
      VAL[j] = -1;
      j++;
    }
  }


#if 0
  printVec("VAL",VAL,nAugmentedVars);
#endif

  edgeList_nColumnIndices = m_JacStruct->m_nColIndices + m_MassStruct->m_nColIndices; 
  edgeList_ColumnIndices = new long[edgeList_nColumnIndices];
  edgeList_cRowNZ = new long[nEqns];
  edgeList_spRowPage = new long[nEqns];
  
  k = 0, l = 0, m = 0;
  for (i = 0; i < nEqns; i++)
  {
    edgeList_cRowNZ[i] = 0;
    edgeList_spRowPage[i] = k;
    l = m_JacStruct->m_spRowPage[EqnOrder[i]];
    for (j = 0; j < m_JacStruct->m_cNZCols[EqnOrder[i]]; j++)
    {
      if (itVarOrder[m_JacStruct->m_ColIndices[l]] >= 0)
      {
        edgeList_ColumnIndices[k++] = itVarOrder[m_JacStruct->m_ColIndices[l]];
        edgeList_cRowNZ[i]++;
      }
      l++;
    }
    if (m_MassStruct->m_cNZCols && m_MassStruct->m_ColIndices)
    {
      m = m_MassStruct->m_spRowPage[EqnOrder[i]]; 
      for (j = 0; j < m_MassStruct->m_cNZCols[EqnOrder[i]]; j++)
      {
        if (itVarOrder[m_MassStruct->m_ColIndices[m]] >= 0)
        {
          edgeList_ColumnIndices[k++] = VAL[itVarOrder[m_MassStruct->m_ColIndices[m]]];
          edgeList_cRowNZ[i]++;
        }
        m++;
      }
    }
  }

  // return the actual number of column indices in the edgeList matrix
  edgeList_nColumnIndices = 0;
  for (i = 0; i < nEqns; i++) edgeList_nColumnIndices += edgeList_cRowNZ[i];

  // cleanup
  DESTROY_VECTOR(iDifferentialVars)
  DESTROY_VECTOR(itVarOrder)
  DESTROY_VECTOR(itDiscVars)

#if 0
  printMat2(nEqns, nAugmentedVars, edgeList_cRowNZ, edgeList_ColumnIndices);
#endif

  return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::GetReportInfo(
	  long* StepperCalls,
	  long* functionCalls,
	  long* jacobiansCalls,
	  long* DecompCalls,
	  long* Substitutions,
	  long* TotalSteps,
	  long* errorRejectedSteps,
	  long* newtonRejectedSteps,
	  long* growthRejectedSteps,
	  long* funcRejectedSteps,
    long* nStateEvents,
    long* nParameterEvents,
    long* nStepSizeChanges)
{
  *StepperCalls = m_report->m_StepperCalls;
  *functionCalls = m_report->m_functionCalls;
  *jacobiansCalls = m_report->m_jacobiansCalls;
  *DecompCalls = m_report->m_DecompCalls;
  *Substitutions = m_report->m_Substitutions;
  *TotalSteps = m_report->m_TotalSteps;
  *errorRejectedSteps = m_report->m_errorRejectedSteps;
  *newtonRejectedSteps = m_report->m_newtonRejectedSteps;
  *growthRejectedSteps = m_report->m_growthRejectedSteps;
  *funcRejectedSteps = m_report->m_funcRejectedSteps;
  *nStateEvents = m_report->m_nStateEvents;
  *nParameterEvents = m_report->m_nParameterEvents;
  *nStepSizeChanges = m_report->m_nStepSizeChanges;

  return S_OK;
}

HRESULT CIsDaeEsoBase::numericJacobian(
  long iActiveEqn,
  long iVar,
  double t, 
  double* y, 
  double* ydot,
  double* rPar, 
  long* iPar,
  double& jacobian)
{
  HRESULT hr = S_OK;
  double delta;
  long i;
  double perturbedVal;
  double original_value;
  bool validVal;

  _ASSERTE(iActiveEqn >= 0 && iActiveEqn < m_nEqns);

  if (nominalVal == NULL)
  {
    // initialize numeric differentiation variables
    nominalVal = new double[m_nEqns];
    nominalTime = new double[m_nEqns];
    for (i = 0; i < m_nEqns; i++) 
    {
      nominalVal[i] = 0.0;
      nominalTime[i] = -1e200;
    }
  }

  // only calculate the base residual value if time has changed.  This stops the number of function calls
  // from doubling to support individual residual calculations

// TODO: this method needs to be made dramatically more efficient anyways
//  if (t != nominalTime[iActiveEqn])
//  {
    hr = iGetResiduals(
      &iActiveEqn, 
      1,
      t,
      y,
      ydot,
      &nominalVal[iActiveEqn],
      validVal,
      rPar,
      iPar);

    nominalTime[iActiveEqn] = t;
//  }

  if (SUCCEEDED(hr))
  {
    original_value = y[iVar];
    // KAB Sept 27, 2001 dropped multiplier to 1.0e-2
    delta = epsilon * DMAX(fabs(original_value),1.0e-2); //DMAX(fabs(original_value),1.0e-5);
    y[iVar] = original_value + delta;
    hr = iGetResiduals(
      &iActiveEqn, 
      1,
      t,
      y,
      ydot,
      &perturbedVal,
      validVal,
      rPar,
      iPar);

    y[iVar] = original_value;
    if (SUCCEEDED(hr))
      jacobian = (perturbedVal - nominalVal[iActiveEqn]) / delta;
  }
  return hr;
}

HRESULT CIsDaeEsoBase::numericDiffJacobian(
  long iActiveEqn,
  long iVar,
  double t, 
  double* y, 
  double* ydot,
  double* rPar, 
  long* iPar,
  double& jacobian)
{
  HRESULT hr = S_OK;
  double delta;
  long i;
  double perturbedVal;
  double original_value;
  bool validVal;

  _ASSERTE(iActiveEqn >= 0 && iActiveEqn < m_nEqns);

  if (nominalVal == NULL)
  {
    // initialize numeric differentiation variables
    nominalVal = new double[m_nEqns];
    nominalTime = new double[m_nEqns];
    for (i = 0; i < m_nEqns; i++) 
    {
      nominalVal[i] = 0.0;
      nominalTime[i] = -1e200;
    }
  }

  // only calculate the base residual value if time has changed.  This stops the number of function calls
  // from doubling to support individual residual calculations

// TODO: take out this garbage code and put in something efficient
//  if (t != nominalTime[iActiveEqn])
//  {
    hr = iGetResiduals(
      &iActiveEqn,
      1,
      t, 
      y, 
      ydot, 
      &nominalVal[iActiveEqn], 
      validVal, 
      rPar, 
      iPar);

    nominalTime[iActiveEqn] = t;
//  }

  if (SUCCEEDED(hr))
  {
    original_value = ydot[iVar];
    delta = epsilon * DMAX(fabs(original_value),1E-5);
    ydot[iVar] = original_value + delta;
    hr = iGetResiduals(
      &iActiveEqn,
      1,
      t,
      y,
      ydot,
      &perturbedVal,
      validVal,
      rPar,
      iPar);

    ydot[iVar] = original_value;
    if (SUCCEEDED(hr))
      jacobian = (perturbedVal - nominalVal[iActiveEqn]) / delta;
  }
  return hr;
}

#define DRAND(val) \
{ \
val = 0.0; \
while (val < 0.01 || val > 0.99) val = ((double) rand()) / ((double) RAND_MAX); \
}

#define IRAND(val) \
{ \
val = 0; \
while (val < 100 || val > 10000) val = rand(); \
}


HRESULT CIsDaeEsoBase::numericJacobianStruct(MatInfo& JacStruct, bool bDiffJacobian)
{
  long i, k, iEqn, iVar;

  double* x = new double[m_nVars];
  double* xdot = new double[m_nVars];
  double* y = new double[m_nVars];
  double* ydot = new double[m_nVars];
  long nEqns;
  long nADEqns;
  long* iEqns = new long[m_nLocalEqns];
  long* itEqns = new long[m_nLocalEqns];
  long* iADEqns = new long[m_nLocalEqns];
  double* nominal_res = new double[m_nLocalEqns];
  double* res = new double[m_nLocalEqns];
  bool* bActive = new bool[m_nLocalEqns];
  double t;
  bool validVal;
  double** Jac = new double*[m_nLocalEqns];
  double jacVal;
  Jac_Calc_Method** Pattern = new Jac_Calc_Method*[m_nLocalEqns];
  long nColIndices = 0;
  const double factor = 1.5;
  double original_value;
  double delta;
  double difference;
  long nJac;
  long* iJac = NULL;
  double* JacVals = NULL;
  double* rPar = NULL;
  long* iPar = NULL;
  
  if (m_nRealParameters > 0)
    rPar = new double[m_nRealParameters];
  
  if (m_nIntegerParameters > 0)
    iPar = new long[m_nIntegerParameters];

#if 0
  ATLTRACE(_T("\nnumericJacobianStruct::DiffJacobian: %d"), bDiffJacobian);
#endif

  // declare full jacobian matrix
  for (i = 0; i < m_nLocalEqns; i++) 
  {
    Jac[i] = new double[m_nVars];
    Pattern[i] = new Jac_Calc_Method[m_nVars];
  }

  // make all equations active
  nEqns = 0;
  nADEqns = 0;
  for (i = 0; i < m_nLocalEqns; i++) 
  {
	  if (m_EqnMap[i].diff_form == EqnDiffForm_Numeric) 
		  iEqns[nEqns++] = i;
	  else
      iADEqns[nADEqns++] = i;

    bActive[i] = m_EqnMap[i].bActive;
    m_EqnMap[i].bActive = true;
  }
  initActiveEqns();

  // generate random values
  unsigned temp;
  time_t ltime;
  temp = (unsigned) time(&ltime);
  srand(temp);
  for (i = 0; i < m_nVars; i++)
  {
    DRAND(x[i]);
    DRAND(xdot[i])
    y[i] = x[i] * factor;
    ydot[i] = xdot[i] * factor;
  }

  for (i = 0; i < m_nRealParameters; i++) DRAND(rPar[i])
  for (i = 0; i < m_nIntegerParameters; i++) IRAND(iPar[i])

  // calculate jacobian at first point
  DRAND(t)
  if (nEqns > 0)
  {
	  iGetResiduals(iEqns, nEqns, t, x, xdot, nominal_res, validVal, rPar, iPar);
	  for (iVar = 0; iVar < m_nVars; iVar++)
	  {
		  if (bDiffJacobian) original_value = xdot[iVar];
		  else original_value = x[iVar];
    
		  delta = epsilon * DMAX(fabs(original_value), 1E-5);
    
		  if (bDiffJacobian) xdot[iVar] = original_value + delta;
		  else x[iVar] = original_value + delta;
    
		  iGetResiduals(iEqns, nEqns, t, x, xdot, res, validVal, rPar, iPar);
    
		  if (bDiffJacobian) xdot[iVar] = original_value;
		  else x[iVar] = original_value;
    
		  for (i = 0; i < nEqns; i++) 
		  {
		    iEqn = iEqns[i];
		    Jac[iEqn][iVar] = (res[i] - nominal_res[i]) / delta;
		    if (fabs(Jac[iEqn][iVar]) < 1e-20)
		    {
			    Pattern[iEqn][iVar] = JCM_NC;
	      }
	      else
	      {
			    Pattern[iEqn][iVar] = JCM_NUM;
			    nColIndices++;
		    }
		  }
	  }
  }

  // calculate the jacobians using the symbolic or AD differentiation
  if (nADEqns > 0) 
  {
    iJac = new long[2*nADEqns*m_nVars];
    JacVals = new double[nADEqns*m_nVars];

    nJac = 0;
    for (i = 0; i < nADEqns; i++)
    { 
      iEqn = iADEqns[i];
      for (iVar = 0; iVar < m_nVars; iVar++)
      {
        iJac[2*nJac] = iEqn;
        iJac[2*nJac+1] = iVar;
        nJac++;
      }
    }

    if (bDiffJacobian)
      iGetLocalMassValues(iJac, nJac, JacStruct, m_time->m_curVal, x, xdot, JacVals, rPar, iPar, true);
    else
      iGetLocalJacobianValues(iJac, nJac, JacStruct, m_time->m_curVal, x, xdot, JacVals, rPar, iPar, true);

    long nNewJac = 0;
    for (i = 0; i < nJac; i++)
    {
      iEqn = iJac[2*i];
      iVar = iJac[2*i+1];
      Jac[iEqn][iVar] = JacVals[i];

      if (fabs(Jac[iEqn][iVar]) < 1e-20)
      {
        Pattern[iEqn][iVar] = JCM_NC;
      }
      else
      {
        iJac[2*nNewJac] = iEqn;
        iJac[2*nNewJac+1] = iVar;
        nNewJac++;
        Pattern[iEqn][iVar] = JCM_AD;
        nColIndices++;
      }
    }
    nJac = nNewJac;
  }

  // calculate jacobian at second point
  for (i = 0; i < m_nRealParameters; i++) DRAND(rPar[i])
  for (i = 0; i < m_nIntegerParameters; i++) IRAND(iPar[i])


  DRAND(t)
  if (nEqns > 0)
  {
    iGetResiduals(iEqns, nEqns, t, y, ydot, nominal_res, validVal, rPar, iPar);
    TransposeVector(iEqns, nEqns, itEqns, m_nLocalEqns);
    for (iVar = 0; iVar < m_nVars; iVar++)
    {
      nEqns = 0;
      for (iEqn = 0; iEqn < m_nLocalEqns; iEqn++) if (Pattern[iEqn][iVar] == JCM_NUM) iEqns[nEqns++] = iEqn;

      if (nEqns > 0)
      {
        if (bDiffJacobian) original_value = ydot[iVar];
        else original_value = y[iVar];

        delta = epsilon * DMAX(fabs(original_value), 1E-5);

        if (bDiffJacobian) ydot[iVar] = original_value + delta;
        else y[iVar] = original_value + delta;

        iGetResiduals(iEqns, nEqns, t, y, ydot, res, validVal, rPar, iPar);
      
        if (bDiffJacobian) ydot[iVar] = original_value;
        else y[iVar] = original_value;

        for (i = 0; i < nEqns; i++) 
        {
          iEqn = iEqns[i];
          jacVal = (res[i] - nominal_res[itEqns[iEqn]]) / delta;
          difference = fabs( (Jac[iEqn][iVar] - jacVal) / (fabs(Jac[iEqn][iVar]) + fabs(jacVal)) );
          if ( difference < 100*epsilon)
          {
            Pattern[iEqn][iVar] = JCM_CONST;
            Jac[iEqn][iVar] = (Jac[iEqn][iVar] + jacVal) / 2.0;
          }
        }
      }
    }
  }

  if (nJac > 0) 
  {
    if (bDiffJacobian)
      iGetLocalMassValues(iJac, nJac, JacStruct, m_time->m_curVal, y, ydot, JacVals, rPar, iPar, true);
    else
      iGetLocalJacobianValues(iJac, nJac, JacStruct, m_time->m_curVal, y, ydot, JacVals, rPar, iPar, true);

    for (i = 0; i < nJac; i++)
    {
      iEqn = iJac[2*i];
      iVar = iJac[2*i+1];

      difference = fabs( (Jac[iEqn][iVar] - JacVals[i]) / (fabs(Jac[iEqn][iVar]) + fabs(JacVals[i])) );
      if ( difference < epsilon)
      {
        Pattern[iEqn][iVar] = JCM_CONST;
        Jac[iEqn][iVar] = (Jac[iEqn][iVar] + JacVals[i]) / 2.0;
      }
    }
  }

  JacStruct.SetCompactSize(m_nLocalEqns, nColIndices); 


  k = 0;
  for (iEqn = 0; iEqn < m_nLocalEqns; iEqn++)
  {
    JacStruct.m_spRowPage[iEqn] = k;
    JacStruct.m_cNZCols[iEqn] = 0;
    for (iVar = 0; iVar < m_nVars; iVar++)
    {
      if (Pattern[iEqn][iVar] != JCM_NC)
      {
        JacStruct.m_ColIndices[k] = iVar;
        JacStruct.m_compact_data[k] = Pattern[iEqn][iVar];
        JacStruct.m_compact_value[k] = Jac[iEqn][iVar];
        if (Pattern[iEqn][iVar] == JCM_CONST) JacStruct.m_bValueSet[k] = true;
        JacStruct.m_cNZCols[iEqn]++;
        k++;

#if 0
        ATLTRACE("\n%d\t%d\t%e", iEqn, iVar, Jac[iEqn][iVar]);
#endif

      }
    }
  }

  // put active equations back as they were
  for (i = 0; i < m_nLocalEqns; i++) m_EqnMap[i].bActive = bActive[i];
  initActiveEqns();

  // cleanup

  DESTROY_VECTOR(x)
  DESTROY_VECTOR(xdot)
  DESTROY_VECTOR(y)
  DESTROY_VECTOR(ydot)
  DESTROY_VECTOR(rPar)
  DESTROY_VECTOR(iPar)
  DESTROY_VECTOR(iEqns)
  DESTROY_VECTOR(itEqns)
  DESTROY_VECTOR(iADEqns)
  DESTROY_VECTOR(nominal_res)
  DESTROY_VECTOR(res)
  DESTROY_VECTOR(bActive)
  for (i = 0; i < m_nLocalEqns; i++) DESTROY_VECTOR(Jac[i])
  DESTROY_VECTOR(Jac)
  for (i = 0; i < m_nLocalEqns; i++) DESTROY_VECTOR(Pattern[i])
  DESTROY_VECTOR(Pattern)
  DESTROY_VECTOR(iJac)
  DESTROY_VECTOR(JacVals)

  return S_OK;
}

HRESULT CIsDaeEsoBase::GetLocalFlatModel(
  FlatModel& fm,
  long* EqnIndices,
  long* VarIndices,
  long* RParIndices,
  long* IParIndices,
  bool bParentIsGlobal)
{
  long i;

  if (bParentIsGlobal || !m_bMasterNode)
  {
    m_GlobalIndex = fm.EsoCount++;
    fm.EsoList[m_GlobalIndex] = this;

    if (m_nLocalEqns > 0)
    {
      fm.spModelEqn[m_GlobalIndex] = EqnIndices[0];
      fm.cNZModelEqn[m_GlobalIndex] = m_nEqns;
      for (i = 0; i < m_nLocalEqns; i++)
      {
        fm.EqnMapSize++;
        if (!fm.EqnMap[EqnIndices[i]]) fm.EqnMap[EqnIndices[i]] = new ModelEqnMap();
        (*fm.EqnMap[EqnIndices[i]]) = m_EqnMap[i];
        fm.EqnMap[EqnIndices[i]]->iModel = m_GlobalIndex;
        fm.EqnMap[EqnIndices[i]]->iEqn = i;
        m_EqnMap[i].iGlobalEqn = EqnIndices[i];
        if (m_EqnMap[i].bDiscontinuous) 
          fm.EqnMap[EqnIndices[i]]->iDiscVar = VarIndices[m_EqnMap[i].iDiscVar];
      }
    }
    else
    {
      fm.spModelEqn[m_GlobalIndex] = 0;
      fm.cNZModelEqn[m_GlobalIndex] = 0;
    }
  }

  if (!bParentIsGlobal || !m_bMasterNode)
  {
    // add variables at the provided indices
    for (i = 0; i < m_nLocalVars; i++)
    {
      fm.VarMapSize++;
      if (!fm.VarMap[VarIndices[i]]) fm.VarMap[VarIndices[i]] = new ModelVarMap();
      m_VarMap[i].iGlobalVar = VarIndices[i];
      (*fm.VarMap[VarIndices[i]]) = m_VarMap[i];
      fm.VarMap[VarIndices[i]]->iModel = m_GlobalIndex;
      fm.VarMap[VarIndices[i]]->iVar = i;
    }

    for (i = 0; i < m_nLocalIPars; i++)
    {
      m_IParMap[i] = IParIndices[i];
      fm.IParMap[IParIndices[i]].iModel = m_GlobalIndex;
      fm.IParMap[IParIndices[i]].iPar = i;
    }

    for (i = 0; i < m_nLocalRPars; i++)
    {
      m_RParMap[i] = RParIndices[i];
      fm.RParMap[RParIndices[i]].iModel = m_GlobalIndex;
      fm.RParMap[RParIndices[i]].iPar = i;
    }
  }

  return S_OK;
}

HRESULT CIsDaeEsoBase::GetFlatModel(
  FlatModel& fm,
  long* EqnIndices,
  long* VarIndices,
  long* RParIndices,
  long* IParIndices,
  bool bParentIsGlobal)
{
  // add the active Eso, and the Active EsoX's
  HRESULT hr = S_OK;
  long i;
  long Dim;

  long spEqn;
  long spVar;
  long spRPar;
  long spIPar;
  CIsDaeEsoBase* pEso;

  // resize the EsoList array
  Dim = fm.EsoDim;
  size_ptr_array(50, fm.EsoCount, Dim, fm.EsoList, m_nEsos);
  Dim = fm.EsoDim;
  size_array(50, fm.EsoCount, Dim, fm.cNZModelEqn, m_nEsos);
  size_array(50, fm.EsoCount, fm.EsoDim, fm.spModelEqn, m_nEsos);

  size_ptr_array(50, fm.EqnMapSize, fm.EqnMapDim, fm.EqnMap, m_nEqns);

  spEqn = m_nLocalEqns;
  spVar = m_nLocalVars;
  spRPar = m_nLocalRPars;
  spIPar = m_nLocalIPars;

  hr = GetLocalFlatModel(
    fm,
    EqnIndices,
    VarIndices,
    RParIndices,
    IParIndices,
    bParentIsGlobal);

  // don't count the children of a master node.  They are counted by their parent Esos
  if (SUCCEEDED(hr) && !m_bMasterNode)
  {
    for (i = 1; i < m_nEsos && SUCCEEDED(hr); i++)
    {
      pEso = m_Esos[i];
      _ASSERTE(pEso);
      hr = pEso->GetFlatModel(
        fm, 
        &EqnIndices[spEqn],
        &VarIndices[spVar],
        &RParIndices[spRPar],
        &IParIndices[spIPar],
        m_bGlobalNode);

      if (!pEso->m_bMasterNode || m_bGlobalNode)
        spEqn += pEso->m_nEqns;

      // count the variables if the child is not a master node, or the parent is not the global node
      if (!pEso->m_bMasterNode || !m_bGlobalNode)
      {
        spVar += pEso->m_bMasterNode ? pEso->m_nLocalVars : pEso->m_nVars;
        spRPar += pEso->m_nRealParameters;
        spIPar += pEso->m_nIntegerParameters;
      }
    }
  }

  // update global variable indices on member variables
  long iModel;
  long iVar;
  for (i = 0; i < m_nVars; i++)
  {
    iModel = m_VarMap[i].iModel;
    iVar = m_VarMap[i].iVar;
    if (iModel > 0) m_VarMap[i].iGlobalVar = m_Esos[iModel]->m_VarMap[iVar].iGlobalVar; 
  }

  return hr;
}


HRESULT CIsDaeEsoBase::RefreshEqnMap(FlatModel& fm)
{
  long i, j, k;
  long spEsoVars = m_nLocalVars;
  CIsDaeEsoBase* pEso;

  for (i = 0; i < m_nLocalEqns; i++) m_EqnMap[i].bActive = fm.EqnMap[m_EqnMap[i].iGlobalEqn]->bActive;

  for (i = 1; i < m_nEsos; i++)
  {
    pEso = m_Esos[i];
    pEso->RefreshEqnMap(fm);
    
    m_spEsoVars[i] = spEsoVars;
    if (m_bGlobalNode)
    {
      if (!pEso->m_bMasterNode) 
        spEsoVars += pEso->m_nActiveVars;
    }
    else // !m_bGlobalNode
    {
      if (pEso->m_bMasterNode)
        spEsoVars += pEso->m_nLocalVars;
      else
        spEsoVars += pEso->m_nActiveVars; 
    }

    if (!pEso->m_bMasterNode || m_bGlobalNode)
    {
      k = m_spEsoEqns[i];
      for (j = 0; j < pEso->m_nEqns; j++)
        m_EqnMap[k++].bActive = pEso->m_EqnMap[j].bActive;
    }

    if (m_bGlobalNode)
    {
      k = m_spEsoVars[i];
      if (!pEso->m_bMasterNode)
        for (j = 0; j < pEso->m_nVars; j++) m_VarMap[k++].bActive = pEso->m_VarMap[j].bActive;
    }
    else // !m_bGlobalNode
    {
      k = m_spEsoVars[i];
      if (pEso->m_bMasterNode)
        for (j = 0; j < pEso->m_nLocalVars; j++) m_VarMap[k++].bActive = pEso->m_VarMap[j].bActive;
      else
        for (j = 0; j < pEso->m_nVars; j++) m_VarMap[k++].bActive = pEso->m_VarMap[j].bActive;
    }
  }

  initActiveEqns();

  return S_OK;
}


void CIsDaeEsoBase::initActiveEqns()
{
  long i;
  m_nActiveEqns = 0;
  for (i = 0; i < m_nEqns; i++) if (m_EqnMap[i].bActive) m_ActiveEqns[m_nActiveEqns++] = i;
  TransposeVector(m_ActiveEqns, m_nActiveEqns, m_itActiveEqns, m_nEqns);

  m_nActiveVars = 0;
  for (i = 0; i < m_nVars; i++) if (m_VarMap[i].bActive) m_ActiveVars[m_nActiveVars++] = i;
  TransposeVector(m_ActiveVars, m_nActiveVars, m_itActiveVars, m_nVars);
}

HRESULT CIsDaeEsoBase::initFlatModel()
{
  long i;
  long* EqnIndices = NULL;
  long* VarIndices = NULL;
  long* RParIndices = NULL;
  long* IParIndices = NULL;
  long Dim;

  if (!m_fm)
  {
    EqnIndices = new long[m_nEqns];
    VarIndices = new long[m_nVars];
    RParIndices = new long[m_nRealParameters];
    IParIndices = new long[m_nIntegerParameters];
  
    for (i = 0; i < m_nEqns; i++) EqnIndices[i] = i;
    for (i = 0; i < m_nVars; i++) VarIndices[i] = i;
    for (i = 0; i < m_nRealParameters; i++) RParIndices[i] = i;
    for (i = 0; i < m_nIntegerParameters; i++) IParIndices[i] = i;

    m_fm = new FlatModel(m_nEqns, m_nVars, m_nRealParameters, m_nIntegerParameters);

    // resize the EsoList array
    Dim = m_fm->EsoDim;
    size_ptr_array(50, m_fm->EsoCount, Dim, m_fm->EsoList, 1);
    Dim = m_fm->EsoDim;
    size_array(50, m_fm->EsoCount, Dim, m_fm->cNZModelEqn, 1);
    Dim = m_fm->EsoDim;
    size_array(50, m_fm->EsoCount, Dim, m_fm->spModelEqn, 1);
    size_ptr_array(50, m_fm->EqnMapSize, m_fm->EqnMapDim, m_fm->EqnMap, m_nEqns);

    GetFlatModel(*m_fm, EqnIndices, VarIndices, RParIndices, IParIndices, false);

#if 0
  for (i = 0; i < m_fm->nEqns; i++)
  {
    ATLTRACE("\n[%d] [%d, %d]", i, m_fm->EqnMap[i]->iModel, m_fm->EqnMap[i]->iEqn); 
  }

  ATLTRACE("\nEso variable map");
  for (i = 0; i < m_nVars; i++)
  {
    ATLTRACE("\n[%d] [%d, %d]", i, m_VarMap[i].iModel, m_VarMap[i].iVar);
  }

  ATLTRACE("\nFlat model variable map");
  for (i = 0; i < m_fm->nVars; i++)
  {
    ATLTRACE("\n[%d] [%d, %d]", i, m_fm->VarMap[i]->iModel, m_fm->VarMap[i]->iVar); 
  }

#endif

    DESTROY_VECTOR(EqnIndices)
    DESTROY_VECTOR(VarIndices)
    DESTROY_VECTOR(RParIndices)
    DESTROY_VECTOR(IParIndices)
  }

  return S_OK;
}

STDMETHODIMP CIsDaeEsoBase::SetModelExec(IOnModelExec* pModelExec)
{
  long i;

  if (m_pModelExec) m_pModelExec->Release();

  m_pModelExec = pModelExec;
  pModelExec->AddRef();

  for (i = 1; i < m_nEsos; i++)
  {
    if (m_Esos[i]->m_pModelExec != m_pModelExec)
      m_Esos[i]->SetModelExec(pModelExec);
  }
  return S_OK;
}


STDMETHODIMP CIsDaeEsoBase::AddEso(IIsDaeEso* pIIsEso)
{
  if (pIIsEso)
  {
    size_ptr_array(20, m_nEsos, m_EsoDim, m_Esos, 1);
    size_ptr_array(20, m_nEsos, m_IIsEsoDim, m_IIsEsos, 1);
    m_IIsEsos[m_nEsos] = pIIsEso;
    pIIsEso->AddRef();
    pIIsEso->GetCPPPtr( reinterpret_cast<DWORD*> (&m_Esos[m_nEsos]) );
    m_Esos[m_nEsos]->m_ContainerIndex = m_nEsos;
    if (!m_bMasterNode)
      m_Esos[m_nEsos]->m_pParent = this;

    if (m_pModelExec && m_Esos[m_nEsos]->m_pModelExec != m_pModelExec)
      m_Esos[m_nEsos]->SetModelExec(m_pModelExec);

    m_nEsos++;
  }
  return S_OK;
}


STDMETHODIMP CIsDaeEsoBase::GetEso(long index, IIsDaeEso** pEso)
{ 
  HRESULT hr = E_INVALIDARG;
  if (index >= 0 && index < m_nEsos)
  {
    *pEso = m_IIsEsos[index];
    (*pEso)->AddRef();
    hr = S_OK;
  }
  return hr;
}

STDMETHODIMP CIsDaeEsoBase::RemoveEso(long index)
{ 
  long i;
  HRESULT hr = E_INVALIDARG;
  if (index >= 0 && index < m_nEsos)
  {
    m_IIsEsos[index]->Release();
    compress_ptr_array(index, m_nEsos, m_Esos);
    for (i = index; i < m_nEsos; i++)
      m_Esos[i]->put_ContainerIndex(i);
  }
  return hr;
}

STDMETHODIMP CIsDaeEsoBase::GetNumEso(long* count)
{ 
  *count = m_nEsos;
  return S_OK;
}

bool CIsDaeEsoBase::iEventDetection(
      event_item**& events,
      long& count,
      long& dim)
{
  bool bRet = false;

  if (m_nTransitions > 0) // STN
  {
    long iEqn, iVar;
    long iTransition, j, iRoot;
    double vZero[20]; // fixed value (assuming there would never be more than 20 zeros)
    long cZero = 0;
    double t = m_time->m_curVal;
    double varLastVal, varVal, varLastDotVal, varDotVal;
    VARIANT_BOOL bEvent = VARIANT_FALSE;

    for (iTransition = 0; iTransition < m_nTransitions; iTransition++)
    {
      if (m_TransitionInfo[iTransition].SourceState == m_CurrentState)
      {
        for (j = 0; j < m_TransitionInfo[iTransition].nEqns; j++)
        {
          iEqn = m_TransitionInfo[iTransition].EqnIndices[j];
          iVar = m_EqnMap[iEqn].iDiscVar;
          if (m_EqnMap[iEqn].bDiscontinuous && !m_EqnMap[iEqn].bUndefined) 
          {
            GetVariable(iVar, m_time->m_lastVal, &varLastVal);
            GetVariable(iVar, m_time->m_curVal, &varVal);
            GetDerivative(iVar, m_time->m_lastVal, &varLastDotVal);
            GetDerivative(iVar, m_time->m_curVal, &varDotVal);


            // added July 15, 2001
            if (varVal > varLastVal) // ensure positive zero crossing
            {
              // TODO: remove this patch
              if ( (varVal > 0.0) != (varLastVal > 0.0) )
              {

                if ( CalculateZeros(
                  varLastVal, varVal, varLastDotVal, varDotVal,
                  m_time->m_lastVal, m_time->m_curVal,
                  cZero, vZero) )
                {
                  for (iRoot = 0; iRoot < cZero; iRoot++)
                  {
                    EvalStateCondition(vZero[iRoot], iEqn, iTransition, &bEvent);
                    if (bEvent == VARIANT_TRUE)
                    {
                      size_ptr_array(5, count, dim, events);
                      state_event_item* se = new state_event_item();
                      bRet = true;
                      se->event_time = vZero[iRoot];
                      se->bExternal = false;
                      se->EventId = m_TransitionInfo[iTransition].getEventId();
                      se->iEventEqn = m_EqnMap[iEqn].iGlobalEqn;
                      se->iTransition = iTransition;
                      se->bZeroCrossing = true;
                      se->pEventEso = this;
                      events[count++] = se;

#if 1
                      ATLTRACE("\n internal post event: time, id, iEqn, iTransition");
                      ATLTRACE("\n %f, %S, %d, %d", se->event_time, se->EventId, se->iEventEqn, se->iTransition);
#endif
                    }
                  }
                }
              }
            }

            // added May 24, 2002 to handle events that were not detected during zero crossing tests above

            // if no event detected above, see if state condition is satisfied (non-zero crossing event)
            if (!bRet)
            {
              // TODO: tie this value into the same value used for the transition nudge
              // just doing to hardcode a value for now
              if (varVal > 1.0e-5) // an event should have been detected, but it wasn't --> post it as a non-zero-crossing event
              {
                EvalStateCondition(m_time->m_curVal, iEqn, iTransition, &bEvent);
                if (bEvent == VARIANT_TRUE)
                {
                  size_ptr_array(5, count, dim, events);
                  state_event_item* se = new state_event_item();
                  bRet = true;
                  se->event_time = m_time->m_curVal;
                  se->bExternal = false;
                  se->EventId = m_TransitionInfo[iTransition].getEventId();
                  se->iEventEqn = -1; // m_EqnMap[iEqn].iGlobalEqn;
                  se->iTransition = iTransition;
                  se->bZeroCrossing = false;
                  se->pEventEso = this;
                  events[count++] = se;

#if 1
                  //ATLTRACE("\n ***** NON ZERO CROSSING EVENT *****");
                  ATLTRACE("\n internal post event: time, id, iEqn, iTransition");
                  ATLTRACE("\n %f, %S, %d, %d", se->event_time, se->EventId, se->iEventEqn, se->iTransition);
#endif
                }
                 
              }
            }

          }
        }
      }
    }
  }
  else // composite Eso
  {
    long i;
    CIsDaeEsoBase* pEso;

    for (i = 1; i < m_nEsos; i++)
    {
      pEso = m_Esos[i];
      bRet |= pEso->iEventDetection(events, count, dim);
    }
  }

  return bRet;
}

bool CIsDaeEsoBase::iCIEventDetection(
      event_item**& events,
      long& count,
      long& dim,
      double* global_last_x,
      double* global_last_xdot,
      double* global_x,
      double* global_xdot)
{
  bool bRet = false;

  if (m_nTransitions > 0) // STN
  {
    long iEqn, iVar, iGlobalVar;
    long iTransition, j;
    double t = m_time->m_curVal;
    double varLastVal, varVal, varLastDotVal, varDotVal;
    VARIANT_BOOL bEvent = VARIANT_FALSE;

    for (iTransition = 0; iTransition < m_nTransitions; iTransition++)
    {
      if (m_TransitionInfo[iTransition].SourceState == m_CurrentState)
      {
        for (j = 0; j < m_TransitionInfo[iTransition].nEqns; j++)
        {
          iEqn = m_TransitionInfo[iTransition].EqnIndices[j];
          iVar = m_EqnMap[iEqn].iDiscVar;
          if (iVar >= 0)
          {
            iGlobalVar = m_VarMap[iVar].iGlobalVar;
            if (m_EqnMap[iEqn].bDiscontinuous && !m_EqnMap[iEqn].bUndefined) 
            {
              varLastVal = global_last_x[iGlobalVar];
              varVal = global_x[iGlobalVar];
              varLastDotVal = global_last_xdot[iGlobalVar];
              varDotVal = global_xdot[iGlobalVar];

              if (varVal > varLastVal && ((varVal > 0.0) != (varLastVal > 0.0)) )
              {
                CIEvalStateCondition(t, iEqn, iTransition, &bEvent, global_x, global_xdot);
                if (bEvent == VARIANT_TRUE)
                {
                  size_ptr_array(5, count, dim, events);
                  state_event_item* se = new state_event_item();
                  bRet = true;
                  se->event_time = t;
                  se->bExternal = false;
                  se->EventId = m_TransitionInfo[iTransition].getEventId();
                  se->iEventEqn = m_EqnMap[iEqn].iGlobalEqn;
                  se->iTransition = iTransition;
                  se->pEventEso = this;
                  events[count++] = se;
                }
              }
            }
          }
        }
      }
    }
  }
  else // composite Eso
  {
    long i;
    CIsDaeEsoBase* pEso;

    for (i = 1; i < m_nEsos; i++)
    {
      pEso = m_Esos[i];
      bRet |= pEso->iCIEventDetection(events, count, dim, global_last_x, global_last_xdot, global_x, global_xdot);
    }
  }

  return bRet;
}



HRESULT CIsDaeEsoBase::OnEventInitEqnMap(CIsDaeEsoBase* pChild)
{
  long i;

  DESTROY_VECTOR(JacIndices)
  nJacIndices = 0;
  DESTROY_VECTOR(MassIndices)
  nMassIndices = 0;

  for (i = 0; i < m_nEqns; i++)
  {
    if (m_EqnMap[i].iModel == pChild->m_ContainerIndex)
      m_EqnMap[i].bActive = pChild->m_EqnMap[m_EqnMap[i].iEqn].bActive;
  }

  if (m_pParent)
    m_pParent->OnEventInitEqnMap(this);

  return S_OK;
}

HRESULT CIsDaeEsoBase::EventInitialization(
  double event_time, 
  long iEventEqn, 
  BSTR bstrEventId,
  long iNewState,
  long*& oldEqns,
  long& nOldEqns,
  long*& newEqns,
  long& nNewEqns)
{
  HRESULT hr = S_OK;
  CComBSTR EventId = bstrEventId;
  BSTR transitionEventId = NULL;
  long i, j;
  long iEqn;

  // reset the cached jacobian values
  DESTROY_VECTOR(JacIndices)
  nJacIndices = 0;
  DESTROY_VECTOR(MassIndices)
  nMassIndices = 0;

  long iBeforeState = m_CurrentState;
  long iAfterState = m_CurrentState = iNewState;

  DESTROY_VECTOR(oldEqns)
  oldEqns = new long[m_nEqns];
  nOldEqns = 0;

  for (i = 0; i < m_StateInfo[iBeforeState].nEqns; i++) 
    oldEqns[nOldEqns++] = m_EqnMap[m_StateInfo[iBeforeState].EqnIndices[i]].iGlobalEqn;

  for (i = 0; i < m_nTransitions; i++)
  {
    transitionEventId = m_TransitionInfo[i].getEventId();
    if (m_TransitionInfo[i].SourceState == iBeforeState)
    {
      for (j = 0; j < m_TransitionInfo[i].nEqns; j++)
      {
        iEqn = m_TransitionInfo[i].EqnIndices[j];
        // only take reset equations from the current transition
        if (!m_EqnMap[iEqn].bReset)
          oldEqns[nOldEqns++] = m_EqnMap[iEqn].iGlobalEqn;
        else if (EventId == transitionEventId)
          oldEqns[nOldEqns++] = m_EqnMap[iEqn].iGlobalEqn;
      }
    }
    ::SysFreeString(transitionEventId);
  }

  
  DESTROY_VECTOR(newEqns)
  newEqns = new long[m_nEqns]; // number of equations doesn't change
  nNewEqns = 0;

  for (i = 0; i < m_StateInfo[iNewState].nEqns; i++) 
    newEqns[nNewEqns++] = m_EqnMap[m_StateInfo[iNewState].EqnIndices[i]].iGlobalEqn;

  for (i = 0; i < m_nTransitions; i++)
  {
    if (m_TransitionInfo[i].SourceState == iNewState)
    {
      for (j = 0; j < m_TransitionInfo[i].nEqns; j++)
        newEqns[nNewEqns++] = m_EqnMap[m_TransitionInfo[i].EqnIndices[j]].iGlobalEqn;
    }
  }

  // TODO: deterine if this is even necessary
  if (m_pParent)
    m_pParent->OnEventInitEqnMap(this);

  return hr;
}

STDMETHODIMP CIsDaeEsoBase::SizeDiscontinuousVars()
{
  HRESULT hr = S_OK;
  long i, j, k;
  long iEqn;
  long nEqns;
  long nAddedEqns;
  long min_disc_eqns = m_nEqns*2;
  long max_disc_eqns = 0;
  long initial_z = m_nLocalVars;
  long next_z;
  long oldEqnCount = m_nEqns;

  ModelEqnMap* oldEqnMap = new ModelEqnMap[m_nEqns];
  for (i = 0; i < m_nEqns; i++) oldEqnMap[i] = m_EqnMap[i];
  long* spStateEqns = new long[m_nStates];
  long* Indices = new long[m_nEqns*5];
  long* MapIndices = new long[m_nEqns*5];
  bool** StateEqns = new bool*[m_nStates];
  long* cStateEqns = new long[m_nStates];
  long* cStateDiscEqns = new long[m_nStates];
  for (i = 0; i < m_nStates; i++) 
  {
    StateEqns[i] = new bool[m_nEqns*5];
    for (j = 0; j < m_nEqns*5; j++) StateEqns[i][j] = false;
    cStateEqns[i] = 0;
    cStateDiscEqns[i] = 0;
  }


#if 0
  for (i = 0; i < m_nStates; i++)
  {
    ATLTRACE("\nState %d", i);
    for (j = 0; j < m_StateInfo[i].nEqns; j++)
      ATLTRACE("\n eqn[%d] = %d -- %d", j, m_StateInfo[i].EqnIndices[j], m_EqnMap[m_StateInfo[i].EqnIndices[j]].iEqn);
  }

  for (i = 0; i < m_nTransitions; i++)
  {
    ATLTRACE("\nTransition %d", i);
    for (j = 0; j < m_TransitionInfo[i].nEqns; j++)
      ATLTRACE("\n eqn[%d] = %d -- %d", j, m_TransitionInfo[i].EqnIndices[j], m_EqnMap[m_TransitionInfo[i].EqnIndices[j]].iEqn);
  }

#endif




  for (i = 0; i < m_nStates; i++)
  {
    // collect the equations out of the transitions
    for (j = 0; j < m_nTransitions; j++)
    {
      if (m_TransitionInfo[j].SourceState == i)
      {
        for (k = 0; k < m_TransitionInfo[j].nEqns; k++)
        {
          iEqn = m_TransitionInfo[j].EqnIndices[k];
          if (!StateEqns[i][iEqn]) 
          {
            StateEqns[i][iEqn] = true;
            cStateEqns[i]++;
            if (m_EqnMap[iEqn].bDiscontinuous) cStateDiscEqns[i]++;
          }
        }
      }
    }
    min_disc_eqns = IMIN(min_disc_eqns, cStateDiscEqns[i]);
    max_disc_eqns = IMAX(max_disc_eqns, cStateDiscEqns[i]);

    // collect the equations out of the states
    for (j = 0; j < m_StateInfo[i].nEqns; j++)
    {
      iEqn = m_StateInfo[i].EqnIndices[j]; 
      if (!StateEqns[i][iEqn]) 
      {
        StateEqns[i][iEqn] = true;
        cStateEqns[i]++;
      }
    }
  }

  nEqns = 0;
  for (i = 0; i < m_nStates; i++) 
  {
    spStateEqns[i] = nEqns;
    nEqns += cStateEqns[i] - cStateDiscEqns[i] + max_disc_eqns; // square up active eqns in each state
  }

  // TODO: move the initialization so member Esos can be included
  hr = CIsDaeEsoBase::SetLocalSize(
    nEqns, 
    m_nLocalVars + max_disc_eqns, 
    m_nRealParameters, 
    m_nIntegerParameters);

  for (i = 0; i < max_disc_eqns; i++) m_VarMap[initial_z + i].bDiscontinuous = true;

  for (i = 0; i < m_nStates; i++)
  {
    nEqns = 0;
    next_z = initial_z;
    for (j = 0; j < oldEqnCount; j++)
    {
      if (StateEqns[i][j])
      {
        iEqn = spStateEqns[i] + nEqns;
        MapIndices[j] = iEqn;
        m_EqnMap[iEqn] = oldEqnMap[j];
        if (m_EqnMap[iEqn].bDiscontinuous) m_EqnMap[iEqn].iDiscVar = next_z++; 
        nEqns++;
      }
    }

    nAddedEqns = 0;
    for (j = 0; j < (max_disc_eqns - cStateDiscEqns[i]); j++)
    {
      iEqn = spStateEqns[i] + nEqns;
      MapIndices[oldEqnCount+j] = iEqn;
      m_EqnMap[iEqn].bUndefined = true;
      m_EqnMap[iEqn].bDiscontinuous = true;
      m_EqnMap[iEqn].iDiscVar = next_z++;
      nAddedEqns++;
      nEqns++;
    }

    // update equation indices for states
    for (j = 0; j < m_StateInfo[i].nEqns; j++)
    {
      Indices[j] = MapIndices[m_StateInfo[i].EqnIndices[j]];
    }
    m_StateInfo[i].setEqns(Indices, m_StateInfo[i].nEqns);

    // update equation indices for transitions
    for (j = 0; j < m_nTransitions; j++)
    {
      if (m_TransitionInfo[j].SourceState == i)
      {
        for (k = 0; k < m_TransitionInfo[j].nEqns; k++)
        {
          Indices[k] = MapIndices[m_TransitionInfo[j].EqnIndices[k]];
        }

        // add the extra undefined transition equations if they haven't been added already
        if (nAddedEqns > 0)
        {
          for (k = 0; k < nAddedEqns; k++)
          {
            Indices[k + m_TransitionInfo[j].nEqns] = MapIndices[oldEqnCount+k];
          }
          m_TransitionInfo[j].nEqns += nAddedEqns;
          nAddedEqns = 0;
        }
        m_TransitionInfo[j].setEqns(Indices, m_TransitionInfo[j].nEqns);
      }
    }
  }

  // cleanup
  DESTROY_VECTOR(oldEqnMap)
  DESTROY_VECTOR(spStateEqns)
  DESTROY_VECTOR(Indices)
  DESTROY_VECTOR(MapIndices)
  for (i = 0; i < m_nStates; i++) DESTROY_VECTOR(StateEqns[i])
  DESTROY_VECTOR(StateEqns)
  DESTROY_VECTOR(cStateEqns)
  DESTROY_VECTOR(cStateDiscEqns)

#if 0
  for (i = 0; i < m_nStates; i++)
  {
    ATLTRACE("\nState %d", i);
    for (j = 0; j < m_StateInfo[i].nEqns; j++)
      ATLTRACE("\n eqn[%d] = %d -- %d", j, m_StateInfo[i].EqnIndices[j], m_EqnMap[m_StateInfo[i].EqnIndices[j]].iEqn);
  }

  for (i = 0; i < m_nTransitions; i++)
  {
    ATLTRACE("\nTransition %d", i);
    for (j = 0; j < m_TransitionInfo[i].nEqns; j++)
      ATLTRACE("\n eqn[%d] = %d -- %d", j, m_TransitionInfo[i].EqnIndices[j], m_EqnMap[m_TransitionInfo[i].EqnIndices[j]].iEqn);
  }

#endif

  return hr;
}


STDMETHODIMP CIsDaeEsoBase::EvalStateCondition(double EventTime, long iDisEqn, long iTransition, VARIANT_BOOL* bEvent)
{
  // NOTE: To compensate for the fact that z* = 0 +/- noise; near the event time calculated from g*, 
  //       the iDisEqn (g*) is evaluated true automatically.  This supports initial event detection.
  long i, iMapEqn;
  bool* EqnState = NULL;
  HRESULT hr = S_OK;

  if (m_nDiscontinuousEqns > 0)
  {
    EqnState = new bool[m_nEqns];
    for (i = 0; i < m_nEqns; i++) EqnState[i] = false;
    for (i = 0; i < m_nActiveEqns; i++)
    {
      iMapEqn = m_ActiveEqns[i];
      if (m_EqnMap[iMapEqn].bDiscontinuous && !m_EqnMap[iMapEqn].bUndefined)
      {
        if (iMapEqn == iDisEqn)
          EqnState[m_EqnMap[iMapEqn].iEqn] = true;
        else
          EqnState[m_EqnMap[iMapEqn].iEqn] = (m_y->m_varVal[m_EqnMap[iMapEqn].iDiscVar] > 0.0);
      }
    }

    hr = iEvalStateCondition(EqnState, EventTime, iDisEqn, iTransition, bEvent);
    DESTROY_VECTOR(EqnState);
  }

  return hr;
}

STDMETHODIMP CIsDaeEsoBase::CIEvalStateCondition(
  double EventTime, 
  long iDisEqn, 
  long iTransition, 
  VARIANT_BOOL* bEvent,
  double* global_x,
  double* global_xdot)
{
  long i, iMapEqn;
  bool* EqnState = NULL;
  HRESULT hr = S_OK;
  long iDiscVar;
  long iGlobalDiscVar;

  if (m_nDiscontinuousEqns > 0)
  {
    EqnState = new bool[m_nEqns];
    for (i = 0; i < m_nEqns; i++) EqnState[i] = false;
    for (i = 0; i < m_nActiveEqns; i++)
    {
      iMapEqn = m_ActiveEqns[i];
      if (m_EqnMap[iMapEqn].bDiscontinuous && !m_EqnMap[iMapEqn].bUndefined)
      {
        if (iMapEqn == iDisEqn)
          EqnState[m_EqnMap[iMapEqn].iEqn] = true;
        else
        {
          iDiscVar = m_EqnMap[iMapEqn].iDiscVar;
          iGlobalDiscVar = m_VarMap[iDiscVar].iGlobalVar;
          EqnState[m_EqnMap[iMapEqn].iEqn] = (global_x[iGlobalDiscVar] > 0.0);
        }
      }
    }

    hr = iCIEvalStateCondition(EqnState, EventTime, iDisEqn, iTransition, bEvent, global_x, global_xdot);
    DESTROY_VECTOR(EqnState);
  }

  return hr;
}


void CIsDaeEsoBase::initializeEqns()
{
  long i;
  EqnForm* eqn_form = NULL;
  EqnDiffForm* eqn_diff_form = NULL;

  m_nDiscontinuousEqns = 0;
  iGetEquationForm(eqn_form, eqn_diff_form);
  
  for (i = 0; i < m_nEqns; i++) 
  {
    if (eqn_form[i] == EqnForm_Discontinuous) 
    {
      m_EqnMap[i].bDiscontinuous = true;
      m_nDiscontinuousEqns++;
    }
    else if (eqn_form[i] == EqnForm_Reset) 
    {
      m_EqnMap[i].bReset = true;        // default reset equations to inactive
      m_EqnMap[i].bActive = false;  
    }
    
    m_EqnMap[i].diff_form = eqn_diff_form[i];
  }

  DESTROY_VECTOR(eqn_form)
  DESTROY_VECTOR(eqn_diff_form)
}

STDMETHODIMP CIsDaeEsoBase::PostRealParameter(double t, long Id, double newVal)
{
  HRESULT hr = E_FAIL;

  if (m_pModelExec)
  {
    if (Id >= 0 && Id < m_nRealParameters)
      hr = m_pModelExec->PostRPar(t, m_RParMap[Id], newVal);
    else
      hr = E_INVALIDARG;
  }

  return hr;
}


STDMETHODIMP CIsDaeEsoBase::PostIntegerParameter(double t, long Id, long newVal)
{
  HRESULT hr = E_FAIL;

  if (m_pModelExec)
  {
    if (Id >= 0 && Id < m_nIntegerParameters)
      hr = m_pModelExec->PostIPar(t, m_IParMap[Id], newVal);
    else
      hr = E_INVALIDARG;
  }

  return hr;
}


void CIsDaeEsoBase::LevelInit(const long Level)
{
  if (Level > m_Level) 
  {
    m_Level = Level;
    for (long i = 1; i < m_nEsos; i++)
      m_Esos[i]->LevelInit(Level + 1);
  }
}


bool CIsDaeEsoBase::Load(FILE* fs)
{
  const long m_schema = 1;
  const long m_classId = 1003;

  long i;
  long classId;
  long schema;
  short bm_K;
  short bm_fm;
  bool bRet = false;
  long nEqns, nVars;
  long nRealPars, nIntegerPars;

  READ_SCALAR( classId )
  if (classId != m_classId) { _ASSERTE(0); return false; }

  READ_SCALAR( schema )
  switch (schema)
  {
  case 1:
    READ_SCALAR( nEqns )
    READ_SCALAR( nVars )

    if (nEqns != m_nEqns || nVars != m_nVars) { _ASSERTE(0); return false; }
    
    if (!m_ActiveEqns || !m_itActiveEqns) { _ASSERTE(0); return false; }

    READ_SCALAR( m_nActiveEqns )
    READ_VECTOR( m_ActiveEqns, long, m_nActiveEqns )
    READ_VECTOR( m_itActiveEqns, long, m_nEqns )

    for (i = 0; i < m_nEqns; i++)
    {
      READ_SCALAR( m_EqnMap[i].bActive )
    }

    if (! m_y->Load(fs) ) { _ASSERTE(0); return false; }
	  if (! m_index->Load(fs) ) { _ASSERTE(0); return false; }
	  if (! m_tolerance->Load(fs) ) { _ASSERTE(0); return false; }

    if (! m_Jac->Load(fs) ) { _ASSERTE(0); return false; }
	  if (! m_Mass->Load(fs) ) { _ASSERTE(0); return false; }

    READ_SCALAR( nRealPars )
    if (m_nRealParameters != nRealPars) { _ASSERTE(0); return false; }
    READ_VECTOR( m_realParameters, double, m_nRealParameters )

    READ_SCALAR( nIntegerPars )
    if (nIntegerPars != m_nIntegerParameters) { _ASSERTE(0); return false; }
    if (m_nIntegerParameters > 0)
      READ_VECTOR( m_integerParameters, long, m_nIntegerParameters )

    if (! m_time->Load(fs) ) { _ASSERTE(0); return false; }
	  if (! m_convergance->Load(fs) ) { _ASSERTE(0); return false; }
	  if (! m_step->Load(fs) ) { _ASSERTE(0); return false; }
	  if (! m_report->Load(fs) ) { _ASSERTE(0); return false; }

    READ_SCALAR( bm_K )

    if (!m_K && bm_K) { _ASSERTE(0); return false; }

    if (bm_K)
      for (i = 0; i < m_nStages; i++) if (! m_K[i]->Load(fs) ) { _ASSERTE(0); return false; }

    READ_SCALAR( bm_fm )
    if (!m_fm && bm_fm) { _ASSERTE(0); return false; }
    
    if (bm_fm)  
      m_fm->Load(fs);

    
    READ_SCALAR( m_CurrentState )
    bRet = true;

    break;

  }

  // post initialization
  DESTROY_VECTOR(JacIndices)
  nJacIndices = 0;
  DESTROY_VECTOR(MassIndices)
  nMassIndices = 0;

  if (m_fm)
  {
    RefreshEqnMap(*m_fm);
    initializeConstantJacobians();
    initDirectEqnMap();
    for(i = 0; i < m_nVars; i++)
    {
      iDirectSetLastTime(m_time->m_lastVal);
      iDirectSetTime(m_time->m_curVal);
      SetLastVariable(i, m_y->m_varLastVal[i]);
      SetVariable(i, m_y->m_varVal[i]);
      SetLastDerivative(i, m_y->m_varLastDotVal[i]);
      SetDerivative(i, m_y->m_varDotVal[i]);
    }
  }

  return bRet;
}

void CIsDaeEsoBase::Save(FILE* fs)
{
  const long m_schema = 1;
  const long m_classId = 1003;

  long i;
  short bm_K = m_K != NULL;
  short bm_fm = m_fm != NULL;

  WRITE_SCALAR( m_classId )
  WRITE_SCALAR( m_schema )

  WRITE_SCALAR( m_nEqns )
  WRITE_SCALAR( m_nVars )

  WRITE_SCALAR( m_nActiveEqns )
  WRITE_VECTOR( m_ActiveEqns, long, m_nActiveEqns )
  WRITE_VECTOR( m_itActiveEqns, long, m_nEqns )
  
  for (i = 0; i < m_nEqns; i++) 
  {
    WRITE_SCALAR( m_EqnMap[i].bActive )
  }

  m_y->Save(fs);
	m_index->Save(fs);
	m_tolerance->Save(fs);

  m_Jac->Save(fs);
	m_Mass->Save(fs);

  WRITE_SCALAR( m_nRealParameters )
  if (m_realParameters)
  {
    WRITE_VECTOR( m_realParameters, double, m_nRealParameters )
  }

  WRITE_SCALAR( m_nIntegerParameters )
  if (m_integerParameters)
  {
    WRITE_VECTOR( m_integerParameters, long, m_nIntegerParameters)
  }

  m_time->Save(fs);
	m_convergance->Save(fs);
	m_step->Save(fs);
	m_report->Save(fs);

  WRITE_SCALAR( bm_K )
  if (m_K)
    for (i = 0; i < m_nStages; i++) m_K[i]->Save(fs);

  WRITE_SCALAR( bm_fm )
  if (m_fm)  
    m_fm->Save(fs);

  WRITE_SCALAR( m_CurrentState )

}




state_event_item::state_event_item()
{
  type = state_event;
  event_time = 0.0;
  bExternal = false;
  EventId = NULL;
  iEventEqn = -1;
  iTransition = -1;
  bZeroCrossing = true;
  pEventEso = NULL;
}

state_event_item::~state_event_item()
{
  if (EventId) ::SysFreeString(EventId);
}

void state_event_item::Save(FILE* fs)
{
  const long m_classId = 1004;
  const long m_schema = 1;
  
  long size = 0;
  USES_CONVERSION;
  char* Id = NULL;

  if (EventId) 
  {
    Id = W2A(EventId);
    size = strlen(Id);
  }

  WRITE_SCALAR( m_classId )
  WRITE_SCALAR( m_schema )

  WRITE_SCALAR( event_time )
  WRITE_SCALAR( bExternal )

  WRITE_SCALAR( size )
  if (size > 0) { WRITE_VECTOR( Id, char, size ) }
  WRITE_SCALAR( iEventEqn )
  WRITE_SCALAR( iTransition )
  WRITE_SCALAR( bZeroCrossing )
  WRITE_SCALAR( pEventEso->m_GlobalIndex )
}

bool state_event_item::Load(FILE* fs, CIsDaeEsoBase** pEsos, long cEsos)
{
  const long m_classId = 1004;
  const long m_schema = 1;

  long classId;
  long schema;
  long size;
  bool bRet = false;
  char* Id = NULL;
  long globalIndex;
  long i;

  USES_CONVERSION;

  READ_SCALAR( classId )
  if (classId != m_classId) { _ASSERTE(0); return false; }

  READ_SCALAR( schema )
  switch (schema)
  {
  case 1:
    READ_SCALAR( event_time )
    READ_SCALAR( bExternal )
    READ_SCALAR( size )
    if (size > 0) 
    {
      Id = new char[size+1];
      READ_VECTOR( Id, char, size )
      Id[size] = '\0';
    }
    READ_SCALAR( iEventEqn )
    READ_SCALAR( iTransition )
    READ_SCALAR( bZeroCrossing )
    READ_SCALAR( globalIndex )

    pEventEso = NULL;
    for (i = 0; i < cEsos; i++)
    {
      if (pEsos[i]->m_GlobalIndex == globalIndex)
      {
        pEventEso = pEsos[i];
        break;
      }
    }

    if (!pEventEso) _ASSERTE(0);

    if (Id) 
    {
      EventId = A2BSTR(Id);
      delete[] Id;
    }

    bRet = true;
    break;

  }
  return bRet;
}

rpar_event_item::rpar_event_item()
{
  type = rpar_event;
  event_time = 0.0;
  bExternal = false;
  iGlobalId = -1;
  value = 0.0;
}

void rpar_event_item::Save(FILE* fs)
{
  const long m_classId = 1005;
  const long m_schema = 1;

  WRITE_SCALAR( m_classId )
  WRITE_SCALAR( m_schema )

  WRITE_SCALAR( event_time )
  WRITE_SCALAR( bExternal )
  WRITE_SCALAR( iGlobalId )
  WRITE_SCALAR( value )
}

bool rpar_event_item::Load(FILE* fs, CIsDaeEsoBase** pEsos, long cEsos)
{
  const long m_classId = 1005;
  const long m_schema = 1;
  bool bRet = false;

  long classId;
  long schema;

  READ_SCALAR( classId )
  if (classId != m_classId) { _ASSERTE(0); return false; }

  READ_SCALAR( schema )
  switch (schema)
  {
  case 1:
    READ_SCALAR( event_time )
    READ_SCALAR( bExternal )
    READ_SCALAR( iGlobalId )
    READ_SCALAR( value )
    bRet = true;
    break;

  }
  return bRet;
}


ipar_event_item::ipar_event_item()
{
  type = ipar_event;
  event_time = 0.0;
  bExternal = false;
  iGlobalId = -1;
  value = 0;
}

void ipar_event_item::Save(FILE* fs)
{
  const long m_classId = 1006;
  const long m_schema = 1;

  WRITE_SCALAR( m_classId )
  WRITE_SCALAR( m_schema )

  WRITE_SCALAR( event_time )
  WRITE_SCALAR( bExternal )
  WRITE_SCALAR( iGlobalId )
  WRITE_SCALAR( value )
}

bool ipar_event_item::Load(FILE* fs, CIsDaeEsoBase** pEsos, long cEsos)
{
  const long m_classId = 1006;
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
    READ_SCALAR( event_time )
    READ_SCALAR( bExternal )
    READ_SCALAR( iGlobalId )
    READ_SCALAR( value )
    bRet = true;
    break;

  }
  return bRet;
}
