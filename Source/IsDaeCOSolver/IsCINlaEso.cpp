// IsCINlaEso.cpp : Implementation of CIsCINlaEso
#include "stdafx.h"
#include "ISDaeCOSolver.h"
#include "IsCINlaEso.h"
#include "IsDaeEso.h"
#include "math.h"

#include "OnDaeCOSolverMacros.h"
#include "ModelNavMaps.h"
#include "IndexInfo.h"
#include "MatInfo.h"
#include "VarInfo.h"
#include "VirtualTimeInfo.h"
#include "triangularization.h"

#ifdef _DEBUG
#include "time.h"
#endif

#if 0
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#endif

char buff[256];
/////////////////////////////////////////////////////////////////////////////
// CIsCINlaEso

CIsCINlaEso::CIsCINlaEso()
{
  // from consistent initialization module
  m_nAugmentedVars = 0;
  m_nAugmentedEqns = 0;
  m_pDaeEso = NULL;
  m_pTransitionEso = NULL;
  
  m_VarOrder = NULL;
  m_EqnOrder = NULL;
  m_VAL = NULL;
  m_itVAL = NULL;
  m_itEqnOrder = NULL;
  m_fm = NULL;

  // block triangularization data
  m_tr_spRowPage = NULL;
  m_tr_cNZCols = NULL;
  m_tr_ColIndices = NULL;
  m_tr_assignedEqn = NULL;
  m_tr_columnOrder = NULL;
  m_tr_rowOrder = NULL;
  m_tr_cBlocks = 0;
  m_tr_blockSizes = NULL;
  m_tr_orderMap = NULL;

  // allocated locally
  m_Vars = NULL;
  m_BlockVarMap = NULL;
  m_BlockEqnMap = NULL;
  m_tr_AssignedVar = NULL;
  
  m_JacStruct = NULL;
  m_Jac = NULL;
}

CIsCINlaEso::~CIsCINlaEso()
{
  DESTROY_VECTOR(m_VarOrder)
  DESTROY_VECTOR(m_EqnOrder)
  DESTROY_VECTOR(m_VAL)
  DESTROY_VECTOR(m_itVAL)
  DESTROY_VECTOR(m_itEqnOrder)

  DESTROY_VECTOR(m_tr_spRowPage)
  DESTROY_VECTOR(m_tr_cNZCols)
  DESTROY_VECTOR(m_tr_ColIndices)
  DESTROY_VECTOR(m_tr_assignedEqn)
  DESTROY_VECTOR(m_tr_columnOrder)
  DESTROY_VECTOR(m_tr_rowOrder)
  DESTROY_VECTOR(m_tr_blockSizes)
  DESTROY_VECTOR(m_tr_orderMap)

  DESTROY_VECTOR(m_Vars)
  DESTROY_VECTOR(m_tr_AssignedVar)
  DESTROY_VECTOR(m_BlockVarMap)
  DESTROY_VECTOR(m_BlockEqnMap)

  DESTROY_MEMBER(m_JacStruct)
  DESTROY_MEMBER(m_Jac)
}


STDMETHODIMP CIsCINlaEso::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IIsNlaEso
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

// blocked interface
STDMETHODIMP CIsCINlaEso::GetNumEqns(long* nEqns)
{
  *nEqns = m_cBlockVars;  
  return S_OK;
}


STDMETHODIMP CIsCINlaEso::GetNumVars(long* nVars)
{
  *nVars = m_cBlockVars;  // tossing out unassigned variables
  return S_OK;
}

STDMETHODIMP CIsCINlaEso::GetAllVariables(SAFEARRAY** Vals)
{
  double* v = NULL;
  long i;

  SafeArrayAccessData(*Vals, (void HUGEP* FAR*)& v);
  for (i = 0; i < m_cBlockVars; i++) 
    v[i] = m_Vars[m_BlockVarMap[i]];

  SafeArrayUnaccessData(*Vals);

  return S_OK;
}

STDMETHODIMP CIsCINlaEso::SetAllVariables(SAFEARRAY** Vals)
{
  double* v = NULL;
  long i;

  SafeArrayAccessData(*Vals, (void HUGEP* FAR*)& v);
  for (i = 0; i < m_cBlockVars; i++) 
    m_Vars[m_BlockVarMap[i]] = v[i];

  SafeArrayUnaccessData(*Vals);

  return S_OK;
}

STDMETHODIMP CIsCINlaEso::SetVariable(long index, double Val)
{
  HRESULT hr = E_INVALIDARG;

  if (index >= 0 && index < m_nAugmentedVars)
  {
    m_Vars[m_BlockVarMap[index]] = Val;
    hr = S_OK;
  }

  return hr;
}

STDMETHODIMP CIsCINlaEso::GetJacobianStruct(
  long* nColIndices,
  SAFEARRAY** psa_ColIndices,
  SAFEARRAY** psa_cNZCols,
  SAFEARRAY** psa_CalcMethod)
{
  long i;
  long* ColIndices = NULL;
  long* cNZCols = NULL;
  long* CalcMethod = NULL;

  if (*psa_ColIndices) SafeArrayDestroy(*psa_ColIndices);
  if (*psa_CalcMethod) SafeArrayDestroy(*psa_CalcMethod);
  if (*psa_cNZCols) SafeArrayDestroy(*psa_cNZCols);

  *nColIndices = m_JacStruct->m_nColIndices; 
  *psa_ColIndices = SafeArrayCreateVector(VT_I4, 0, m_JacStruct->m_nColIndices);
  *psa_CalcMethod = SafeArrayCreateVector(VT_I4, 0, m_JacStruct->m_nColIndices);
  *psa_cNZCols = SafeArrayCreateVector(VT_I4, 0, m_cBlockVars);
  
  SafeArrayAccessData(*psa_ColIndices, (void HUGEP* FAR*)& ColIndices);
  SafeArrayAccessData(*psa_CalcMethod, (void HUGEP* FAR*)& CalcMethod);
  SafeArrayAccessData(*psa_cNZCols, (void HUGEP* FAR*)& cNZCols);

  for (i = 0; i < m_JacStruct->m_nColIndices; i++)
  {
    ColIndices[i] = m_JacStruct->m_ColIndices[i];
    CalcMethod[i] = m_JacStruct->m_compact_data[i]; 
  }

  for (i = 0; i < m_cBlockVars; i++)
    cNZCols[i] = m_JacStruct->m_cNZCols[i];

  SafeArrayUnaccessData(*psa_ColIndices);
  SafeArrayUnaccessData(*psa_CalcMethod);
  SafeArrayUnaccessData(*psa_cNZCols);

  return S_OK;
}

STDMETHODIMP CIsCINlaEso::GetJacobianValues(SAFEARRAY** ppsaIndices, SAFEARRAY** ppsaJacVals)
{
  long i, j, k;
  long ubound;
  long lbound;
  long cIndices;
  long* Indices = NULL;
  double* JacVals = NULL;
  long iNlaEqn;
  long iNlaVar;
  long iEqn;
  long iMapEqn;
  long iVar;
  long iDaeVar;
  long iModel;
  CIsDaeEsoBase* pEso = NULL;
  double dj_dtVal;
  long idxEqn, idxVar;
  long iJac[2];

  SafeArrayGetUBound(*ppsaIndices, 1, &ubound);
  SafeArrayGetLBound(*ppsaIndices, 1, &lbound);
  cIndices = (ubound - lbound + 1) / 2;

  SafeArrayAccessData(*ppsaIndices, (void HUGEP* FAR*)& Indices);
  SafeArrayAccessData(*ppsaJacVals, (void HUGEP* FAR*)& JacVals);
  j = 0;
  for (i = 0; i < cIndices; i++)
  {
    idxEqn = Indices[2*i+lbound];
    idxVar = Indices[2*i+lbound+1];
    iNlaEqn = m_BlockEqnMap[idxEqn];
    iNlaVar = m_BlockVarMap[idxVar];
    iEqn = m_EqnOrder[iNlaEqn];
    iVar = m_VarOrder[iNlaVar];
    iDaeVar = -1;
    JacVals[j] = 0.0;

    if (!m_fm->EqnMap[iEqn]->bAugmented)
    {
      iModel = m_fm->EqnMap[iEqn]->iModel;
      pEso = m_fm->EsoList[iModel];
      iMapEqn = m_fm->EqnMap[iEqn]->iEqn;

      if (iVar < m_pDaeEso->m_nVars) 
      {
        // iDaeVar = m_fm->VarMap[iVar]->iVar;
        // TODO: verify change entered April 9, 2001
        // reasoning: the flat model returns the variable index of the variable in the Eso
        // in which the variable is implemented, which may not be the Eso from which the 
        // variable is used.  The following modified code gets the variable index for the 
        // variable in the Eso where the equation is implemented
        // end change
        if (iModel == m_fm->VarMap[iVar]->iModel)
        {
          iDaeVar = m_fm->VarMap[iVar]->iVar;
        }
        else
        {
          for (k = 0; k < pEso->m_nVars; k++)
          {
            if (pEso->m_VarMap[k].iGlobalVar == iVar)
            {
              iDaeVar = k;
              break;
            }
          }
        }

        _ASSERTE(iDaeVar >= 0);

        iJac[0] = pEso->m_itActiveEqns[iMapEqn];
        iJac[1] = pEso->m_itActiveVars[iDaeVar];
#if 0
        ATLTRACE("\n%d\t%d\t%d\t%d\tjac", i, iModel, iDaeEqn, iDaeVar);
#endif
        // TODO: the following code retrieves jacobians individually.  This is inefficient and should be reviewed.
        pEso->iGetJacobianValues(
          iJac, 
          1, 
          *pEso->m_JacStruct, 
          pEso->m_time->m_curVal, 
          pEso->m_y->m_varVal,
          pEso->m_y->m_varDotVal, 
          &JacVals[j], 
          pEso->m_realParameters, 
          pEso->m_integerParameters);

#if 0
            ATLTRACE("\t%e", JacVals[j]);
#endif

        m_Jac->m_data[idxEqn][idxVar] = JacVals[j];
        j++;
      }
      else
      {
        k = m_itVAL[iNlaVar];
        if (k >= 0)
        {
          iVar = m_VarOrder[k];
          if (!m_fm->VarMap[iVar]->bAugmented)
          {
            // iDaeVar = m_fm->VarMap[iVar]->iVar;
            // same change as noted above ******************************
            if (iModel == m_fm->VarMap[iVar]->iModel)
            {
              iDaeVar = m_fm->VarMap[iVar]->iVar;
            }
            else
            {
              for (k = 0; k < pEso->m_nVars; k++)
              {
                if (pEso->m_VarMap[k].iGlobalVar == iVar)
                {
                  iDaeVar = k;
                  break;
                }
              }
            }

            _ASSERTE(iDaeVar >= 0); 
            
            iJac[0] = pEso->m_itActiveEqns[iMapEqn];
            iJac[1] = iDaeVar;
#if 0
        ATLTRACE("\n%d\t%d\t%d\t%d\tmass", i, iModel, iDaeEqn, iDaeVar);
#endif
            // TODO: review inefficiency
            pEso->iGetMassValues(
              iJac, 
              1, 
              *pEso->m_MassStruct, 
              pEso->m_time->m_curVal, 
              pEso->m_y->m_varVal,
              pEso->m_y->m_varDotVal, 
              &JacVals[j], 
              pEso->m_realParameters, 
              pEso->m_integerParameters);

#if 0
            ATLTRACE("\t%e", JacVals[j]);
#endif

            m_Jac->m_data[idxEqn][idxVar] = JacVals[j];
            j++;
          }
        }
      }
    }
    else
    {
      if (m_VAL[iNlaVar] >= 0)
        dj_dtVal = m_Vars[m_VAL[iNlaVar]];
      else
        dj_dtVal = 1.0;

      compute_dfi_dj(iNlaEqn, iNlaVar, dj_dtVal, JacVals[j]);
      m_Jac->m_data[idxEqn][idxVar] = JacVals[j];
      j++;
    }
  }


#if 0
  // hardcoded solution for pendulum
  for (i = 0; i < m_nAugmentedEqns; i++) 
  {
    for (j = 0; j < m_nAugmentedVars; j++) mat[i][j] = 0.0;
  }

  mat[0][2] = -1;
  mat[0][5] = 1;
  mat[1][6] = 1;
  mat[1][3] = -1;
  mat[2][0] = m_Vars[4];
  mat[2][4] = m_Vars[0];
  mat[2][7] = 1;
  mat[3][1] = m_Vars[4];
  mat[3][4] = m_Vars[1];
  mat[3][8] = 1;
  mat[4][0] = 2*m_Vars[0];
  mat[4][1] = 2*m_Vars[1];
  mat[5][0] = 2*m_Vars[5];
  mat[5][1] = 2*m_Vars[6];
  mat[5][5] = 2*m_Vars[0];
  mat[5][6] = 2*m_Vars[1];
  mat[6][7] = -1;
  mat[6][9] = 1;
  mat[7][8] = -1;
  mat[7][10] = 1;
  mat[8][0] = 2*m_Vars[9];
  mat[8][1] = 2*m_Vars[10];
  mat[8][5] = 4*m_Vars[5];
  mat[8][6] = 4*m_Vars[6];
  mat[8][9] = 2*m_Vars[0];
  mat[8][10] = 2*m_Vars[1];

  ATLTRACE("\n\n hand crafted values\n");
  printMat(m_nAugmentedEqns, m_nAugmentedVars, mat);

  for (i = 0; i < m_nAugmentedEqns; i++) 
  {
    DESTROY_VECTOR(mat[i])
  }
  DESTROY_VECTOR(mat)

#endif

  SafeArrayUnaccessData(*ppsaIndices);
  SafeArrayUnaccessData(*ppsaJacVals);

  return S_OK;
}

STDMETHODIMP CIsCINlaEso::GetAllJacobianValues(SAFEARRAY** ppsaIndices, SAFEARRAY** ppsaJacVals)
{
  HRESULT hr = S_OK;
  SAFEARRAY* psaIndices = NULL;
  long* Indices = NULL;
  long i, j, k;

  if (*ppsaIndices) SafeArrayDestroy(*ppsaIndices);
  *ppsaIndices = SafeArrayCreateVector(VT_I4, 0, m_JacStruct->m_nColIndices * 2);
  SafeArrayAccessData(*ppsaIndices, (void HUGEP* FAR*)& Indices);
  k = 0;
  for (i = 0; i < m_cBlockVars; i++)
  {
    for (j = m_JacStruct->m_spRowPage[i]; j < (m_JacStruct->m_spRowPage[i] + m_JacStruct->m_cNZCols[i]); j++)
    {
      Indices[2*k] = i;
      Indices[2*k+1] = m_JacStruct->m_ColIndices[j];
      k++;
    }
  }
  SafeArrayUnaccessData(psaIndices);

  hr = GetJacobianValues(&psaIndices, ppsaJacVals);
  return hr;
}

STDMETHODIMP CIsCINlaEso::GetResiduals(SAFEARRAY** x, SAFEARRAY** residuals)
{
  // copy the values into local variable array removing assigned variables
  HRESULT hr = S_OK;
  double* v;
  double* res;
  long i;
  long iEqn;

  // read the x values into local m_Vars vector
  SafeArrayAccessData(*x, (void HUGEP* FAR*)& v);
  for (i = 0; i < m_cBlockVars; i++) 
    m_Vars[m_BlockVarMap[i]] = v[i];
  
  SafeArrayUnaccessData(*x);

  // initialize variables on Dae
  SafeArrayAccessData(*residuals, (void HUGEP* FAR*)& res);

  // write the data to the Eso object
  WriteBlockVariables();

  // get remaining residuals from derivative calculations
  bool bOK = true;
  for (i = 0; (i < m_cBlockVars) && bOK; i++)
  {
    iEqn = m_BlockEqnMap[i];
    bOK = evalEqn(iEqn, res[i]);
#if 0
    ATLTRACE("\n[%d]\t%e;",iEqn,res[i]);
#endif

  }

#if 0
  // pendulum problem hard coded results
  double f[9];
  ATLTRACE("\n\nhard coded values \n");
  f[0] = m_Vars[5] - m_Vars[2];
  f[1] = m_Vars[6] - m_Vars[3];
  f[2] = m_Vars[7]+m_Vars[0]*m_Vars[4];
  f[3] = m_Vars[8]+m_Vars[1]*m_Vars[4]+1;
  f[4] = m_Vars[0]*m_Vars[0] + m_Vars[1]*m_Vars[1] - 1;
  f[5] = 2*m_Vars[0]*m_Vars[5] + 2*m_Vars[1]*m_Vars[6];
  f[6] = -1 * m_Vars[7] + 1 * m_Vars[9];
  f[7] = -1 * m_Vars[8] + 1 * m_Vars[10];
  f[8] = 2*m_Vars[5]*m_Vars[5] + 2*m_Vars[6]*m_Vars[6] + 2*m_Vars[0]*m_Vars[9] + 2*m_Vars[1]*m_Vars[10];

  for (i = 0; i < m_cBlockVars; i++)
    ATLTRACE("\nres[%d] = %e;",m_BlockEqnMap[i],f[m_BlockEqnMap[i]]);

#endif

  SafeArrayUnaccessData(*residuals);
  if (!bOK) hr = E_FAIL;
  return hr;
}

HRESULT CIsCINlaEso::OneVarSolver()
{
  long iEqn = m_BlockEqnMap[0];
  long iVar = m_BlockVarMap[0];
  double res;
  HRESULT hr;
  long counter = 0;
  double theta_old;
  
  long* indices;
  double* jacVals;
  double* x;
  double factor = 1.0;

  SAFEARRAY* psaIndices = SafeArrayCreateVector(VT_I4, 0, 2);
  SAFEARRAY* psaJacVals = SafeArrayCreateVector(VT_R8, 0, 1);
  SAFEARRAY* psaX = SafeArrayCreateVector(VT_R8, 0, 1);

  SafeArrayAccessData(psaIndices, (void HUGEP* FAR*)& indices);
  SafeArrayAccessData(psaJacVals, (void HUGEP* FAR*)& jacVals);
  SafeArrayAccessData(psaX, (void HUGEP* FAR*)& x);

  *x = m_Vars[iVar];
  indices[0] = 0;
  indices[1] = 0;

  do 
  {
    counter++;
    theta_old = *x;
    if (SUCCEEDED( hr = GetResidual(iEqn, &psaX, &res) ))
    {
      if (fabs(res) < 1e-10) break;

      if (SUCCEEDED( hr = GetJacobianValues(&psaIndices, &psaJacVals) ))      
      {
        *x = theta_old - factor * res / (*jacVals);
      }
    }
  } while (SUCCEEDED(hr) && fabs(*x - theta_old) > 1e-10 && counter < 20);

#if 0
  ATLTRACE("\n%e", *x);
#endif
  
  // cleanup
  SafeArrayUnaccessData(psaIndices);
  SafeArrayUnaccessData(psaJacVals);
  SafeArrayUnaccessData(psaX);

  SafeArrayDestroy(psaIndices);
  SafeArrayDestroy(psaJacVals);
  SafeArrayDestroy(psaX);


  return hr;
}

void CIsCINlaEso::ReadEsoVariables()
{
  long i;
  long iVar;

  for (i = 0; i < m_nAugmentedVars; i++)
  {
    iVar = m_VarOrder[i];
    if (iVar < m_pDaeEso->m_nVars)
    {
      m_Vars[i] = m_pDaeEso->m_y->m_varVal[iVar];
    }
    else
    {
      if (m_itVAL[i] >= 0)
      {
        iVar = m_VarOrder[m_itVAL[i]];
        if (!m_fm->VarMap[iVar]->bAugmented)
          m_Vars[i] = m_pDaeEso->m_y->m_varDotVal[iVar];
      }
    }
  }

#if 0
  for (i = 0; i < m_nAugmentedVars; i++) ATLTRACE("\n%d %e", i, m_Vars[i]);
#endif

}

void CIsCINlaEso::WriteEsoVariables()
{
  long i;
  long iVar;
  long iActiveVar;

#if 0
  for (i = 0; i < m_nAugmentedVars; i++) ATLTRACE("\n%d %e", i, m_Vars[i]);
#endif

  for (i = 0; i < m_nAugmentedVars; i++)
  {
    iVar = m_VarOrder[i];

    if (iVar < m_pDaeEso->m_nVars)
    {
      iActiveVar = m_pDaeEso->m_itActiveVars[iVar];
      m_pDaeEso->SetVariable(iActiveVar, m_Vars[i]);
      m_pDaeEso->SetLastVariable(iActiveVar, m_Vars[i]);
    }
    else
    {
      if (m_itVAL[i] >= 0)
      {
        iVar = m_VarOrder[m_itVAL[i]];
        iActiveVar = m_pDaeEso->m_itActiveVars[iVar];
        if (!m_fm->VarMap[iVar]->bAugmented)
        {
          m_pDaeEso->SetDerivative(iActiveVar, m_Vars[i]);
          m_pDaeEso->SetLastDerivative(iActiveVar, m_Vars[i]);
        }
      }
    }
  }

}


void CIsCINlaEso::WriteBlockVariables()
{
  long i;
  long iVar;
  long iNlaVar;
  long iActiveVar;

#if 0
  for (i = 0; i < m_nAugmentedVars; i++) ATLTRACE("\n%d %e", i, m_Vars[i]);
#endif

  for (i = 0; i < m_cBlockVars; i++)
  {
    iNlaVar = m_BlockVarMap[i];
    iVar = m_VarOrder[iNlaVar];
    if (iVar < m_pDaeEso->m_nVars)
    {
      iActiveVar = m_pDaeEso->m_itActiveVars[iVar]; 
      m_pDaeEso->SetVariable(iActiveVar, m_Vars[iNlaVar]);
      m_pDaeEso->SetLastVariable(iActiveVar, m_Vars[iNlaVar]);
    }
    else
    {
      if (m_itVAL[iNlaVar] >= 0)
      {
        iVar = m_VarOrder[m_itVAL[iNlaVar]];
        iActiveVar = m_pDaeEso->m_itActiveVars[iVar]; 
        if (!m_fm->VarMap[iVar]->bAugmented)
        {
          m_pDaeEso->SetDerivative(iActiveVar, m_Vars[iNlaVar]);
          m_pDaeEso->SetLastDerivative(iActiveVar, m_Vars[iNlaVar]);
        }
      }
    }
  }

}

void CIsCINlaEso::WriteBlockVariable(long iNlaVar)
{
  long iVar;
  long iActiveVar;

  iVar = m_VarOrder[iNlaVar];

  if (iVar < m_pDaeEso->m_nVars)
  {
    iActiveVar = m_pDaeEso->m_itActiveVars[iVar];
    m_pDaeEso->SetVariable(iActiveVar, m_Vars[iNlaVar]);
    m_pDaeEso->SetLastVariable(iActiveVar, m_Vars[iNlaVar]);
  }
  else
  {
    if (m_itVAL[iNlaVar] >= 0)
    {
      iVar = m_VarOrder[m_itVAL[iNlaVar]];
      iActiveVar = m_pDaeEso->m_itActiveVars[iVar];
      if (!m_fm->VarMap[iVar]->bAugmented)
      {
        m_pDaeEso->SetDerivative(iActiveVar, m_Vars[iNlaVar]);
        m_pDaeEso->SetLastDerivative(iActiveVar, m_Vars[iNlaVar]);
      }
    }
  }
}

STDMETHODIMP CIsCINlaEso::GetResidual(long iEqn, SAFEARRAY** x, double* residual)
{
  // copy the values into local variable array removing assigned variables
  HRESULT hr = S_OK;
  double* v;
  long i;

  // read the x values into local m_Vars vector
  SafeArrayAccessData(*x, (void HUGEP* FAR*)& v);
  for (i = 0; i < m_cBlockVars; i++) 
    m_Vars[m_BlockVarMap[i]] = v[i];
  
  SafeArrayUnaccessData(*x);

  // write the data to the Eso object
  WriteBlockVariables();

  // get remaining residuals from derivative calculations
  bool bOK = evalEqn(iEqn, *residual);
  if (!bOK) hr = E_FAIL;
  return hr;
}

/////////////////////////////////////////////////////////////////////
// if iVar < 0, it is ignored
// if iVar >= 0, the value is temporarily set to varVal
bool CIsCINlaEso::evalEqn(long idxEqn, double& residual, long iVar /* =-1 */, double varVal /* = 0.0 */)
{
  bool bRet;
  double temp;
  long iEqn;
  long iModel;
  long iDaeVar;
  long iMapEqn;

  CIsDaeEsoBase* pEso;
  ModelEqnMap* pEqn;

  iEqn = m_EqnOrder[idxEqn];
  pEqn = m_fm->EqnMap[iEqn];
  iModel = pEqn->iModel;
  iMapEqn = pEqn->iEqn;

  // if iVar > 0, temporarily replace variable value
  if (iVar >= 0)
  {
    temp = m_Vars[iVar];
    m_Vars[iVar] = varVal;
    WriteBlockVariable(iVar);
  }

  bool validVal;

  if (!pEqn->bAugmented) 
  {
    pEso = m_fm->EsoList[iModel]; 
    // TODO: The following code calls residuals individually.  This is inefficient and should be 
    // reviewed if the inefficiency causes problems.
    bRet = SUCCEEDED( pEso->iGetResiduals(
      &pEso->m_itActiveEqns[iMapEqn],
      1,
      pEso->m_time->m_curVal,
      pEso->m_y->m_varVal,
      pEso->m_y->m_varDotVal, 
      &residual,
      validVal,
      pEso->m_realParameters,
      pEso->m_integerParameters) );

    if (iEqn == m_iEventEqn) // g()
    {
      // need to give the residual a nudge to ensure we don't hit the event again
      m_dg_dt_for_g_star = 0.0;
      double delta_g = 0.0;
      iDaeVar = pEso->m_EqnMap[iMapEqn].iDiscVar;
      compute_dg_dt(pEso->m_time->m_curVal, pEso->m_y->m_varVal, pEso->m_y->m_varDotVal, m_dg_dt_for_g_star, iMapEqn, iDaeVar); 
      compute_deltaG(pEso->m_time->m_curVal, pEso->m_y->m_varDotVal[iDaeVar], 1.0E-10, delta_g);

#if 0
      bool dumpData = true;
      long i;

      if (dumpData)
      {
        ATLTRACE("\nvars:\t");
        for (i = 0; i < pEso->m_nVars; i++)
          ATLTRACE("%e\t", pEso->m_y->m_varVal[i]);

        ATLTRACE("\nders:\t");
        for (i = 0; i < pEso->m_nVars; i++)
          ATLTRACE("%e\t", pEso->m_y->m_varDotVal[i]);
      }

#endif


      // March 10, 2002, KAB removed the comments on the first 3 lines below
      // TODO: take this patch out
      if (m_dg_dt_for_g_star < 0.0) 
        residual -= delta_g; // g positive
      else
        residual += delta_g; // g negative
    }
  }
  else
  {
    bRet = evalDiffEqn(idxEqn, residual);
  }

  if (iVar >= 0) // put value back
  {
    m_Vars[iVar] = temp;
    WriteBlockVariable(iVar);
  }  

  return bRet;
}

bool CIsCINlaEso::evalDiffEqn(long iEqn, double& residual)
{
  long iVar;
  double dfi_djVal;
  double dj_dtVal;
  bool bRet = true;
  CIsDaeEsoBase* pEso;
  long iMapEqn;
  long iDaeVar;

  long idxVar;
  long idxDotVar;
  long i, j, k;
  ModelEqnMap* pEqnMap;
  long iSourceEqn;
  long iModel;
  long iDiffOrder;
  long iRow;
  long iJac[2];

  // TODO: cache the following calculations so the second run doensn't have to do all these lookups
  residual = 0.0;
  dj_dtVal = 0.0;
  pEqnMap = m_fm->EqnMap[m_EqnOrder[iEqn]];
  iSourceEqn = pEqnMap->itEAL; 

  // KAB June 26 --> changed m_nEqns to m_nAugmentedEqns.  Can't recall what this does, but it is looping
  // over the wrong row in the edge list if it stops at m_nEqns if iEqn >= m_nEqns
  for (iRow = 0; iRow < m_nAugmentedEqns; iRow++) { if (m_tr_rowOrder[iRow] == iEqn) break; }

  j = m_tr_spRowPage[iRow];
  for (i = 0; i < m_tr_cNZCols[iRow]; i++)
  {
    idxVar = m_tr_columnOrder[m_tr_ColIndices[j++]];
    iVar = m_VarOrder[idxVar];
    iDiffOrder = m_fm->VarMap[m_VarOrder[idxVar]]->iDiffOrder;
    idxDotVar = m_VAL[idxVar];
    if (idxDotVar >= 0) dj_dtVal = m_Vars[idxDotVar];
    if (iSourceEqn < m_pDaeEso->m_nEqns) 
    {
      iModel = m_fm->EqnMap[iSourceEqn]->iModel;
      iMapEqn = m_fm->EqnMap[iSourceEqn]->iEqn;
      pEso = m_fm->EsoList[iModel];
      
      if (iDiffOrder == 0)
      {
        // iDaeVar = m_fm->VarMap[iVar]->iVar;
        // TODO: verify April 9 fix below
        if (iModel == m_fm->VarMap[iVar]->iModel)
        {
          iDaeVar = m_fm->VarMap[iVar]->iVar;
        }
        else
        {
          for (k = 0; k < pEso->m_nVars; k++)
          {
            if (pEso->m_VarMap[k].iGlobalVar == iVar)
            {
              iDaeVar = k;
              break;
            }
          }
        }

        _ASSERTE(iDaeVar >= 0);

        // TODO: review efficiency
        iJac[0] = pEso->m_itActiveEqns[iMapEqn];
        iJac[1] = iDaeVar;
        pEso->iGetJacobianValues(
          iJac, 
          1,
          *pEso->m_JacStruct,
          pEso->m_time->m_curVal, 
          pEso->m_y->m_varVal, 
          pEso->m_y->m_varDotVal,
          &dfi_djVal, 
          pEso->m_realParameters, 
          pEso->m_integerParameters);

        residual += dfi_djVal * dj_dtVal;
      }
      else if (iDiffOrder == 1)
      {
        iDaeVar = -1;

        // TODO: validate this change further with other high index problems.
        // iVar = m_itVAL[iVar]; // KAB April 8, 2001
        // TODO: validate JAN 2002 fix 
        //iVar = m_itVAL[idxVar];
        // changed to:
         iVar = m_VarOrder[m_itVAL[idxVar]];
        
        
        
        //iDaeVar = m_fm->VarMap[iVar]->iVar; 
        if (iModel == m_fm->VarMap[iVar]->iModel)
        {
          iDaeVar = m_fm->VarMap[iVar]->iVar;
        }
        else
        {
          for (k = 0; k < pEso->m_nVars; k++)
          {
            if (pEso->m_VarMap[k].iGlobalVar == iVar)
            {
              iDaeVar = k;
              break;
            }
          }
        }

        _ASSERTE(iDaeVar >= 0);

        iJac[0] = pEso->m_itActiveEqns[iMapEqn];
        iJac[1] = iDaeVar;
        pEso->iGetMassValues(
          iJac, 
          1,
          *pEso->m_MassStruct,
          pEso->m_time->m_curVal, 
          pEso->m_y->m_varVal, 
          pEso->m_y->m_varDotVal,
          &dfi_djVal, 
          pEso->m_realParameters, 
          pEso->m_integerParameters);

        residual += dfi_djVal * dj_dtVal;
      }
      else
      {
        bRet = compute_dfi_dj(iSourceEqn, idxVar, dj_dtVal, dfi_djVal);
        if (bRet) residual += dfi_djVal * dj_dtVal;
       }
    }
    else
    {
      bRet = compute_dfi_dj(iSourceEqn, idxVar, dj_dtVal, dfi_djVal);
      if (bRet) residual += dfi_djVal * dj_dtVal;
    }
  }
  return bRet;
}

void CIsCINlaEso::compute_dg_dt(
		double t,
		double* y,
		double* ydot,
		double& dg_dt,
    long iMapEqn,
    long iEventVar)
{
	double JacVal;
  long iVar;
  long i, j;
  long iJac[2];
  CIsDaeEsoBase* pEso = m_pTransitionEso;

	dg_dt = 0.0;
  j = m_pTransitionEso->m_JacStruct->m_spRowPage[iMapEqn];
  _ASSERTE(pEso->m_itActiveEqns[iMapEqn] >= 0);
  for (i = 0; i < m_pTransitionEso->m_JacStruct->m_cNZCols[iMapEqn]; i++)
	{
    iVar = m_pTransitionEso->m_JacStruct->m_ColIndices[j++];
    if (iVar != iEventVar)
    {
      // TODO: review efficiency
      iJac[0] = pEso->m_itActiveEqns[iMapEqn];
      iJac[1] = iVar;
      pEso->iGetJacobianValues(
        iJac, 
        1,
        *m_pTransitionEso->m_JacStruct,
        t,
        m_pTransitionEso->m_y->m_varVal,
        m_pTransitionEso->m_y->m_varDotVal,
        &JacVal, 
        m_pTransitionEso->m_realParameters, 
        m_pTransitionEso->m_integerParameters);

      dg_dt += -1.0 * JacVal * ydot[iVar];

#if 0
      ATLTRACE("\n%e\t%d\t%e\t%e\t%d\t%d", 
        pEso->m_time->m_curVal,
        pEso->m_CurrentState,
        dg_dt,
        JacVal,
        iMapEqn,
        iVar);
#endif

    }
	}
}

void CIsCINlaEso::compute_deltaG(double t_event, double dg_dt, double t_event_tol, double& delta_g)
{
	delta_g = ((double) 0.5) * fabs(dg_dt) * t_event_tol;
	delta_g = DMAX(delta_g, m_delta_g_min);
	delta_g = DMIN(delta_g, m_delta_g_max);
}


#define EPS 1.0e-4
bool CIsCINlaEso::compute_dfi_dj(long iSourceEqn, long iVar, double dj_dt, double& dfi_djVal)
{
	double h;
  double v;
  double res0, res1;
  bool bRet;

  v = m_Vars[iVar];
	h = EPS * (dj_dt == 0.0 ? 1.0 : dj_dt);
  v += h;
  bRet = evalEqn(iSourceEqn, res0);
  if (bRet) bRet = evalEqn(iSourceEqn, res1, iVar, v);
  dfi_djVal = (res1-res0) / h;
  return bRet;
}
#undef EPS


void CIsCINlaEso::SetCIData( 
      long nVars, long nEqns,
      long nAugmentedVars, long nAugmentedEqns,
      long* VarOrder, long* EqnOrder, long* VAL, long* itVAL,
      CIsDaeEsoBase* pDaeEso, CIsDaeEsoBase* pTransitionEso, long iEventEqn)
{
  long i;

  m_nVars = nVars;
  m_nEqns = nEqns;
  m_nAugmentedVars = nAugmentedVars;
  m_nAugmentedEqns = nAugmentedEqns;

  m_fm = pDaeEso->m_fm;

  DESTROY_VECTOR(m_VarOrder)
  m_VarOrder = new long[nAugmentedVars];
  for (i = 0; i < nAugmentedVars; i++) m_VarOrder[i] = VarOrder[i];

  DESTROY_VECTOR(m_EqnOrder)
  m_EqnOrder = new long[nAugmentedEqns];
  for (i = 0; i < nAugmentedEqns; i++) m_EqnOrder[i] = EqnOrder[i];

  DESTROY_VECTOR(m_itEqnOrder)
  TransposeVector(m_EqnOrder, nAugmentedEqns, m_itEqnOrder, m_fm->nEqns+m_fm->nMSSEqns);

  DESTROY_VECTOR(m_VAL)
  m_VAL = new long[nAugmentedVars];
  for (i = 0; i < nAugmentedVars; i++) m_VAL[i] = VAL[i];

  DESTROY_VECTOR(m_itVAL)
  m_itVAL = new long[nAugmentedVars];
  for (i = 0; i < nAugmentedVars; i++) m_itVAL[i] = itVAL[i];

  m_pDaeEso = pDaeEso;
  m_pTransitionEso = pTransitionEso;

  m_iEventEqn = iEventEqn;

  // initialize variable vector
  DESTROY_VECTOR(m_Vars)
  m_Vars = new double[m_nAugmentedVars];
  for (i = 0; i < m_nAugmentedVars; i++) 
    m_Vars[i] = 0.0;

  // read the data from the DaeEso object
  ReadEsoVariables();
}

// assumption: SetCIData called first
void CIsCINlaEso::SetTriangularizationData(
    long* tr_spRowPage, long* tr_cNZCols, long* tr_ColIndices,
    long* tr_assignedEqn, long* tr_columnOrder, long* tr_rowOrder, 
    long tr_cBlocks, long* tr_blockSizes, long* tr_orderMap)
{
  long i;
  long nColIndices = 0;

  m_tr_spRowPage = new long[m_nAugmentedEqns];
  m_tr_cNZCols = new long[m_nAugmentedEqns];
  for (i = 0; i < m_nAugmentedEqns; i++) 
  {
    m_tr_spRowPage[i] = tr_spRowPage[i];
    m_tr_cNZCols[i] = tr_cNZCols[i];
  }

  for (i = 0; i < m_nAugmentedEqns; i++) nColIndices += tr_cNZCols[i];
  m_tr_ColIndices = new long[nColIndices];
  for (i = 0; i < nColIndices; i++) m_tr_ColIndices[i] = tr_ColIndices[i];

  m_tr_assignedEqn = new long[m_nAugmentedVars];
  for (i = 0; i < m_nAugmentedVars; i++) m_tr_assignedEqn[i] = tr_assignedEqn[i];

  m_tr_columnOrder = new long[m_nAugmentedVars];
  for (i = 0; i < m_nAugmentedVars; i++) m_tr_columnOrder[i] = tr_columnOrder[i];

  m_tr_rowOrder = new long[m_nAugmentedEqns];
  for (i = 0; i < m_nAugmentedEqns; i++) m_tr_rowOrder[i] = tr_rowOrder[i];

  m_tr_cBlocks = tr_cBlocks;

  m_tr_blockSizes = new long[tr_cBlocks];
  for (i = 0; i < tr_cBlocks; i++) m_tr_blockSizes[i] = tr_blockSizes[i];

  m_tr_orderMap = new long[m_nAugmentedVars];
  for (i = 0; i < m_nAugmentedVars; i++) m_tr_orderMap[i] = tr_orderMap[i];

  m_tr_AssignedVar = new long[m_nAugmentedVars];
  for (i = 0; i < m_nAugmentedVars; i++)
    m_tr_AssignedVar[i] = -1;

  for (i = 0; i < m_nAugmentedVars; i++)
  {
    if (m_tr_assignedEqn[i] >= 0 && m_tr_assignedEqn[i] < m_nAugmentedVars) 
      m_tr_AssignedVar[m_tr_assignedEqn[i]] = i;
  }

}

STDMETHODIMP CIsCINlaEso::Solve()
{
  long i;
  long iVar;
  long iEqn;
  long size;
  long iBlock;
  bool SecondPass = false;

  initialize_dg_dt();

solve_cycle:

#if 0
  ATLTRACE("\n initial values for x:");
  for (i = 0; i < m_nAugmentedVars; i++)
    ATLTRACE("\n%d\t%e", i, m_Vars[i]);
#endif

  m_spBlock = 0;
  for (iBlock = 0; iBlock < m_tr_cBlocks; iBlock++)
  {
    // initialize variable map
    DESTROY_VECTOR(m_BlockVarMap)
    DESTROY_VECTOR(m_BlockEqnMap)
    size = m_tr_blockSizes[iBlock];
    m_BlockVarMap = new long[size];
    m_BlockEqnMap = new long[size];
    m_cBlockVars = 0;
    srand( (unsigned)time( NULL ) );
    for (i = 0; i < size; i++)
    {
      iEqn = m_tr_orderMap[m_spBlock + i];     // equation solved in this block
      iVar = m_tr_AssignedVar[iEqn];           // variable assigned to this equation
      // randomize variable if not triggered from an event
      // if (m_iEventEqn < 0) m_Vars[iVar] = ((double)rand())/RAND_MAX;
      m_BlockVarMap[m_cBlockVars] = iVar;
      m_BlockEqnMap[m_cBlockVars] = iEqn;
      m_cBlockVars++;
    }

#if 0
    ATLTRACE("\nVars\tEqns");
    for (i = 0; i < m_cBlockVars; i++)
      ATLTRACE("\n%d\t\t%d", m_VarOrder[m_BlockVarMap[i]], m_EqnOrder[m_BlockEqnMap[i]]);
#endif

    initializeJacobian();

    //if (m_cBlockVars == 1)
    //{
    //  OneVarSolver();
    //}
    //else if (m_cBlockVars > 1)
    if (m_cBlockVars > 0)
    {
      //try
      //{
        m_pNlaSolver->Solve();
      //}
      //catch (...)
      //{
      //  _ASSERTE(0);
      //}
    }

#if 0
    ATLTRACE("\n initial values for x:");
    for (i = 0; i < m_nAugmentedVars; i++)
    {
      if (m_Vars[i] > 1.0e4)
        ATLTRACE("\n%d\t%e", i, m_Vars[i]);
    }
#endif

    m_spBlock += size;
  }

  if (m_iEventEqn >= 0)
  {
    // offset time
    double dg_dt = 0.0;
    double delta_g = 0.0;
    long iDaeVar;
    long iGlobalVar;
    long iMapEqn;
    double dg_dt_tol;

    iMapEqn = m_fm->EqnMap[m_iEventEqn]->iEqn;
    iDaeVar = m_pTransitionEso->m_EqnMap[iMapEqn].iDiscVar;
    iGlobalVar = m_pTransitionEso->m_VarMap[iDaeVar].iGlobalVar;
    m_pDaeEso->iGetAbsTolerance(iGlobalVar, dg_dt_tol);

    compute_dg_dt(
      m_pTransitionEso->m_time->m_curVal, 
      m_pTransitionEso->m_y->m_varVal, 
      m_pTransitionEso->m_y->m_varDotVal, 
      dg_dt,
      iMapEqn,
      iDaeVar);

    compute_deltaG(
      m_pTransitionEso->m_time->m_curVal, 
      m_pTransitionEso->m_y->m_varDotVal[iDaeVar],
      1.0E-10, 
      delta_g);

    // ensure dg_dt used for g* has the same sign as dg_dt now
    // if not, the g* must have been evaluated before a reset equation that would 
    // affect the direction of event polishing
    //_ASSERTE(!( (dg_dt > 0.0) != (m_dg_dt_for_g_star > 0.0) && SecondPass));

    if ( (fabs(dg_dt) > dg_dt_tol) && ((dg_dt > 0.0) != (m_dg_dt_for_g_star > 0.0)) && !SecondPass) 
    {
      SecondPass = true;
#if 0
      ATLTRACE("\npass2\t%e\t%e", dg_dt, m_dg_dt_for_g_star);
#endif
      goto solve_cycle;
    }

    m_pDaeEso->SetDerivative(m_fm->EqnMap[m_iEventEqn]->iDiscVar, -1*dg_dt);
    m_pDaeEso->SetLastDerivative(m_fm->EqnMap[m_iEventEqn]->iDiscVar, -1*dg_dt);

    if (dg_dt != 0)
    {
      // TODO: the following is a stability patch.  In cases where dg_dt is very small, and 
      // delta_g is propped up by virtue of a minimum setting, the following code would
      // push time ahead by minutes or hours which was clearly not the intention.
      if ( fabs(delta_g/dg_dt) < 1e-2 )
      {
        if (m_pDaeEso->m_time->m_reverse)
          m_pDaeEso->SetTime( m_pDaeEso->m_time->m_curVal - fabs(delta_g/dg_dt) ); 
        else
          m_pDaeEso->SetTime( m_pDaeEso->m_time->m_curVal + fabs(delta_g/dg_dt) ); 
      }
    }
    else
    {
      // _ASSERTE(0);
    }
  }

  // WriteEsoVariables();

  return S_OK;
}

void CIsCINlaEso::initialize_dg_dt()
{
  long i;

  m_delta_g_min = 1.0E100;
  m_delta_g_max = 0.0;
  
  double* atol = new double[m_pDaeEso->m_nVars];
  for (i = 0; i < m_pDaeEso->m_nVars; i++)
  {
    m_pDaeEso->iGetAbsTolerance(i, atol[i]);
    m_delta_g_min = DMIN(atol[i], m_delta_g_min);
  }
  // June 16, 2001 KB (delta_g originally did not produce enough of a nudge.
  //m_delta_g_min /= 100;
  m_delta_g_min /= 10;
  m_delta_g_max = 10 * m_delta_g_min;
  DESTROY_VECTOR(atol)
}

void CIsCINlaEso::initializeJacobian()
{
  long i, j, k, m, n;
  long iVar;

  DESTROY_MEMBER(m_JacStruct)
  DESTROY_MEMBER(m_Jac)
  m_JacStruct = new MatInfo(m_cBlockVars, m_cBlockVars, false, NULL);
  m_JacStruct->m_form = SPARSE;
  m_Jac = new MatInfo(m_cBlockVars, m_cBlockVars, false, NULL);
  m_Jac->m_form = FULL;
  m_Jac->Init();

  m_JacStruct->m_nColIndices = 0;
  for (i = m_spBlock; i < (m_spBlock+m_cBlockVars); i++)
    m_JacStruct->m_nColIndices += m_tr_cNZCols[i];

  m_JacStruct->SetCompactSize(m_cBlockVars, m_JacStruct->m_nColIndices);

  long* itBlockVarMap = new long[m_nAugmentedVars];
  for (i = 0; i < m_nAugmentedVars; i++) itBlockVarMap[i] = -1;
  for (i = 0; i < m_cBlockVars; i++) itBlockVarMap[m_BlockVarMap[i]] = i;

#if 0
  printVec("BlockEqnMap", m_BlockEqnMap, m_cBlockVars);
  printVec("BlockVarMap", m_BlockVarMap, m_cBlockVars);
  printVec("itBlockVarMap", itBlockVarMap, m_nAugmentedVars);
  printVec("m_tr_rowOrder",m_tr_rowOrder,m_nAugmentedEqns);
  printVec("m_tr_orderMap",m_tr_orderMap,m_nAugmentedEqns);
#endif

  m = 0;
  for (i = 0; i < m_cBlockVars; i++)
  {
    m_JacStruct->m_cNZCols[i] = 0;
    m_JacStruct->m_spRowPage[i] = m;

    // get the index j where the block equation number == the order map equation number
    // this index j will be the correct row index to read the cNZRow and the spColumnPageNumber
    for (j = 0; j < m_nAugmentedVars; j++)
    {
      if (m_tr_rowOrder[j] == m_BlockEqnMap[i]) // if (m_tr_orderMap[j] == m_BlockEqnMap[i])
        break;
    }

    n = m_tr_spRowPage[j];
    for (k = 0; k < m_tr_cNZCols[j]; k++)
    {
      iVar = itBlockVarMap[m_tr_columnOrder[m_tr_ColIndices[n++]]];
      if (iVar >= 0)
      {
        m_JacStruct->m_ColIndices[m] = iVar;
        m_JacStruct->m_compact_data[m] = (long) JCM_SYM;
        m_JacStruct->m_cNZCols[i]++;
        m++;
      }
    }
  }
  m_JacStruct->m_nColIndices = m;

#if 0
  printMat(m_nAugmentedEqns, m_nAugmentedVars, m_tr_cNZCols, m_tr_ColIndices);
  printMat(m_cBlockVars, m_cBlockVars, m_JacStruct->m_cNZCols, m_JacStruct->m_ColIndices); 
#endif

  DESTROY_VECTOR(itBlockVarMap);
}

