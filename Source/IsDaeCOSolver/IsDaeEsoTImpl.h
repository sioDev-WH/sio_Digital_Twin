// IsDaeEsoTImpl.h : Declaration of the CIsDaeEsoImpl<T>

#ifndef _IsDaeEsoImpl_h_
#define _IsDaeEsoImpl_h_

#include "IsDaeEso.h"
#include "IIsDaeModelImpl.h"
#include "MatInfo.h"
#include "VarInfo.h"
#include "VirtualTimeInfo.h"
#include "ToleranceInfo.h"
#include "IndexInfo.h"
#include "ModelNavMaps.h"
#include "OnDaeCOSolverMacros.h"


#define RESIDUAL_FUNCTION_ARGS double t, double* y, double* ydot, double& residual, \
  bool& validVal, double* realParameters, long* integerParameters

#define JACOBIAN_FUNCTION_ARGS MatInfo& JacStruct, double t, double* y, double* ydot, \
  double& dfi_djVal, double* rPar, long* iPar

/////////////////////////////////////////////////////////////////////////////
// CIsDaeEsoTImpl<T>
template <class T>
class CIsDaeEsoTImpl : public CIsDaeEsoBase
{
public:
  typedef HRESULT (T::*residual_function)(RESIDUAL_FUNCTION_ARGS);
  typedef HRESULT (T::*jacobian_function)(JACOBIAN_FUNCTION_ARGS);

  CIsDaeEsoTImpl(long nEqns, long nVars, long nRPars, long nIPars) : CIsDaeEsoBase(nEqns, nVars, nRPars, nIPars)
  {

    long i, j;
    m_Equations = (residual_function*) new double[m_nEqns];
    m_JacEqns = (jacobian_function**) new double[m_nEqns];
    for (i = 0; i < m_nEqns; i++)
    {
      m_JacEqns[i] = (jacobian_function*) new double[m_nVars];
      for (j = 0; j < m_nVars; j++) m_JacEqns[i][j] = NULL;
    }
    m_DiffJacEqns = (jacobian_function**) new double[m_nEqns];
    for (i = 0; i < m_nEqns; i++)
    {
      m_DiffJacEqns[i] = (jacobian_function*) new double[m_nVars];
      for (j = 0; j < m_nVars; j++) m_DiffJacEqns[i][j] = NULL;
    }

  }
 
  virtual ~CIsDaeEsoTImpl()
  {

    long i;
    if (m_Equations)
      delete [] (double*) m_Equations;

    if (m_JacEqns)
    {
      for (i = 0; i < m_nEqns; i++)
      {
        if (m_JacEqns[i])
          delete [] (double*) m_JacEqns[i];
      }

      delete[] (double*) m_JacEqns;
    }

    if (m_DiffJacEqns)
    {
      for (i = 0; i < m_nEqns; i++)
      {
        if (m_DiffJacEqns[i])
          delete [] (double*) m_DiffJacEqns[i];
      }

      if (m_DiffJacEqns)
        delete [] (double*) m_DiffJacEqns;
    }

  }

//************************************************************************************
// pure virtual methods
//************************************************************************************
  virtual HRESULT ciGetEquationForm(EqnForm*& eqn_form, EqnDiffForm*& eqn_diff_form)
  { 
    long i;
    
    eqn_form = new EqnForm[m_nLocalEqns];
    eqn_diff_form = new EqnDiffForm[m_nLocalEqns];

    for (i = 0; i < m_nLocalEqns; i++) 
    {
      eqn_form[i] = EqnForm_Continuous;
      eqn_diff_form[i] = EqnDiffForm_Numeric;
    }

    return S_OK;
  }

  virtual HRESULT ciGetLocalJacobianStruct(MatInfo& JacStruct) = 0;
  virtual HRESULT ciGetLocalMassStruct(MatInfo& MassStruct) = 0;

//************************************************************************************
//************************************************************************************

  HRESULT iGetLocalJacobianStruct(MatInfo& JacStruct)
  {
    long i, j, k, l;
    long nColIndices;
    MatInfo LocalJacStruct;
    HRESULT hr = ciGetLocalJacobianStruct(LocalJacStruct);

    if (SUCCEEDED(hr))
    {
      nColIndices = LocalJacStruct.m_nColIndices + m_nLocalEqns;
      JacStruct.SetCompactSize(m_nLocalEqns, nColIndices);
      JacStruct.m_nColIndices = 0;

      k = 0;
      l = 0;
      for (i = 0; i < m_nLocalEqns; i++)
      {
        JacStruct.m_spRowPage[i] = k;
        JacStruct.m_cNZCols[i] = 0;
        if (m_EqnMap[i].bDiscontinuous)
        {
          // add z entries
          JacStruct.m_cNZCols[i]++;
          JacStruct.m_ColIndices[k] = m_EqnMap[i].iDiscVar; 
          JacStruct.m_compact_data[k] = JCM_CONST;
          JacStruct.m_compact_value[k] = 1.0;
          JacStruct.m_bValueSet[k] = true;
          JacStruct.m_nColIndices++;
          k++;
        }
        for (j = 0; j < LocalJacStruct.m_cNZCols[i]; j++)
        {
          JacStruct.m_ColIndices[k] = LocalJacStruct.m_ColIndices[l];
          JacStruct.m_compact_data[k] = LocalJacStruct.m_compact_data[l];
          JacStruct.m_compact_value[k] = 0.0;
          JacStruct.m_bValueSet[k] = false;
          JacStruct.m_cNZCols[i]++;
          JacStruct.m_nColIndices++;
          k++;
          l++;
        }
      }
    }
    return hr;
  }

  virtual HRESULT iGetLocalMassStruct(MatInfo& MassStruct)
  { return ciGetLocalMassStruct(MassStruct); }

  virtual HRESULT iGetEquationForm(EqnForm*& eqn_form, EqnDiffForm*& eqn_diff_form) 
  { return ciGetEquationForm(eqn_form, eqn_diff_form); }

  virtual HRESULT iGetLocalResiduals(
      long* iEqns, 
      long cEqns, 
      double t, 
      double* y, 
      double* ydot, 
      double* residuals, 
      bool& validVal,
      double* realParameters, 
      long* integerParameters)
  {
    HRESULT hr = S_OK;
    long iEqn;
    long i;
    T* p = static_cast<T*>(this);

    double* local_y = new double[m_nVars];
    double* local_ydot = new double[m_nVars];
    for (i = 0; i < m_nActiveVars; i++)
    {
      local_y[m_ActiveVars[i]] = y[i];
      local_ydot[m_ActiveVars[i]] = ydot[i];
    }

    for (i = 0; i < cEqns && SUCCEEDED(hr); i++)
    {
      iEqn = m_ActiveEqns[iEqns[i]];
      if (m_EqnMap[iEqn].bUndefined)
      {
        residuals[i] = 0.0;
      }
      else if ((m_Equations[iEqn]) != NULL)
      {
        hr = ( p->*(m_Equations[iEqn]) )(t, local_y, local_ydot, residuals[i], validVal, 
          realParameters, integerParameters);
      }
      else
      {
        residuals[i] = 0.0;
        hr = E_INVALIDARG;
      }

      // if this is a discontinuous function rp = g(), the actual residual is r = z - g(), (r = z - rp)
      if (m_EqnMap[iEqn].bDiscontinuous) residuals[i] = local_y[m_EqnMap[iEqn].iDiscVar] - residuals[i];
    }

    DESTROY_VECTOR(local_y)
    DESTROY_VECTOR(local_ydot)

    return hr;
  }

  virtual HRESULT iGetLocalJacobianValues(
    long* iJac,
    long cJac,
    MatInfo& JacStruct,
    double t, 
    double* y, 
    double* ydot,
		double* JacVals,
    double* rPar, 
    long* iPar,
    bool bIncludeConsts = true)
  {
    long i, iEqn, iVar;
    HRESULT hr = S_OK;
    T* p = static_cast<T*>(this);

    for (i = 0; i < cJac && SUCCEEDED(hr); i++)
    {
      iEqn = m_ActiveEqns[iJac[2*i]];
      iVar = m_ActiveVars[iJac[2*i+1]];
      JacVals[i] = 0.0;
    
      // cover the z variables
      if (m_EqnMap[iEqn].bDiscontinuous && m_EqnMap[iEqn].iDiscVar == iVar)
        JacVals[i] = 1.0;
      else if ( (m_JacEqns[iEqn][iVar]) != NULL)
      {
        hr = ( p->*(m_JacEqns[iEqn][iVar]) )(JacStruct, t, y, ydot, JacVals[i], rPar, iPar);
        if (m_EqnMap[iEqn].bDiscontinuous) JacVals[i] *= -1.0;
      }
      else
      {
        hr = numericJacobian(iEqn, iVar, t, y, ydot, rPar, iPar, JacVals[i]);
        if (m_EqnMap[iEqn].bDiscontinuous) JacVals[i] *= -1.0;
      }
    }

    return hr;
  }

  virtual HRESULT iGetLocalMassValues(
    long* iJac,
    long cJac,
    MatInfo& MassStruct,
    double t, 
    double* y, 
    double* ydot,
		double* MassVals,
    double* rPar, 
    long* iPar,
    bool bIncludeConsts = true)
  {
    long i, iEqn, iVar;
    HRESULT hr = S_OK;
    T* p = static_cast<T*>(this);

    for (i = 0; i < cJac && SUCCEEDED(hr); i++)
    {
      iEqn = m_ActiveEqns[iJac[2*i]];
      iVar = m_ActiveVars[iJac[2*i+1]];
      MassVals[i] = 0.0;

      if ( (m_DiffJacEqns[iEqn][iVar]) != NULL)
      {
        hr = ( p->*(m_DiffJacEqns[iEqn][iVar]) )(MassStruct, t, y, ydot, MassVals[i], rPar, iPar);
      }
      else
      {
        hr = numericDiffJacobian(iEqn, iVar, t, y, ydot, rPar, iPar, MassVals[i]);
      }
    }

    return hr;
  }

  virtual HRESULT TriggerEvent(double EventTime, BSTR EventId, long iEventEqn) { return E_NOTIMPL; }

protected:

  // equation function vectors
  residual_function* m_Equations;
  jacobian_function** m_JacEqns;
  jacobian_function** m_DiffJacEqns;
};

#endif // _IsDaeEsoImpl_h_