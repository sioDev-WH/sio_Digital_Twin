#include "stdafx.h"
#include "ISDaeCOSolver.h"
#include "IsDaeEsoIImpl.h"
#include "math.h"

#include "OnDaeCOSolverMacros.h"
#include "TransitionInfo.h"
#include "StateInfo.h"
#include "VarInfo.h"
#include "ModelNavMaps.h"
#include "MatInfo.h"
#include "VirtualTimeInfo.h"
#include "ToleranceInfo.h"

#if 0
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#endif

CIsDaeEsoIImpl::CIsDaeEsoIImpl() : CIsDaeEsoBase(0,0,0,0) 
{ 
  m_pEsoImpl = NULL;
  m_psa_x = NULL;
  m_psa_xdot = NULL;
  m_psa_rpar = NULL;
  m_psa_ipar = NULL;
  m_psa_iEqn = NULL;
  m_psa_vEqn = NULL;
  m_psa_iJac = NULL;
  m_psa_iActiveJac = NULL;
  m_psa_vJac = NULL;
  m_x = NULL;
  m_xdot = NULL;
  m_rpar = NULL;
  m_ipar = NULL;
  m_iEqn = NULL;
  m_vEqn = NULL;
  m_iActiveJac = NULL;
  m_iJac = NULL;
  m_vJac = NULL;
}

CIsDaeEsoIImpl::~CIsDaeEsoIImpl() 
{ 
  if (m_pEsoImpl) 
  {
    m_pEsoImpl->Release();
    m_pEsoImpl = NULL;
  }
  DestroySafeArrays();
}

#define SA_UNACCESS_DATA(PSA) \
if (PSA) { \
SafeArrayUnaccessData(PSA); \
SafeArrayDestroy(PSA); \
PSA = NULL; }

// access the data, get the bounds and the count
#define SA_ACCESS_DATA(PSA, PVDATA) \
SafeArrayAccessData(PSA, (void HUGEP* FAR*)& PVDATA); \
SafeArrayGetLBound(PSA, 1, &lbound); \
SafeArrayGetUBound(PSA, 1, &ubound); \
count = ubound - lbound + 1;


void CIsDaeEsoIImpl::DestroySafeArrays()
{
  SA_UNACCESS_DATA(m_psa_x)
  SA_UNACCESS_DATA(m_psa_xdot)
  SA_UNACCESS_DATA(m_psa_rpar)
  SA_UNACCESS_DATA(m_psa_ipar)
  SA_UNACCESS_DATA(m_psa_iEqn)
  SA_UNACCESS_DATA(m_psa_vEqn)
  SA_UNACCESS_DATA(m_psa_iJac)
  SA_UNACCESS_DATA(m_psa_iActiveJac)
  SA_UNACCESS_DATA(m_psa_vJac)
  m_x = NULL;
  m_xdot = NULL;
  m_rpar = NULL;
  m_ipar = NULL;
  m_iEqn = NULL;
  m_vEqn = NULL;
  m_iJac = NULL;
  m_iActiveJac = NULL;
  m_vJac = NULL;
}

HRESULT CIsDaeEsoIImpl::SetEso(IIsDaeEsoImpl *pEso)
{
  HRESULT hr = S_OK;
  long i, j;
	long nEqns;
  long nVars;
  long nRPars;
  long nIPars;
  double t = 0.0; 
	SAFEARRAY* psa_atol = NULL;
  SAFEARRAY* psa_rtol = NULL; 
	SAFEARRAY* psa_x = NULL;
  SAFEARRAY* psa_xdot = NULL;
	SAFEARRAY* psa_rpar = NULL;
  SAFEARRAY* psa_ipar = NULL;
	double* atol = NULL;
  double* rtol = NULL; 
	double* x = NULL;
  double* xdot = NULL;
	double* rpar = NULL;
  long* ipar = NULL;

  long lbound, ubound;
  long count;

  long nEsos = 0;
  SAFEARRAY* psa_Esos = NULL;
  IIsDaeEsoImpl** Esos = NULL;
  CComObject<CIsDaeEsoIImpl>* pEsoCont = NULL;
  IIsDaeEso* pIIsDaeEso = NULL;

  long nStates = 0;
  long nTransitions = 0; 
  long iDefaultState = -1; 
  SAFEARRAY* psaTransEventIds = NULL;
  SAFEARRAY* psaSrcStates = NULL; 
  SAFEARRAY* psaStateToEqnMap = NULL; 
  SAFEARRAY* psaTransToEqnMap = NULL;
  VARIANT* vStateToEqnMap = NULL; 
  VARIANT* vTransToEqnMap = NULL;
  long* StateToEqnMap = NULL; 
  long* TransToEqnMap = NULL;

  BSTR* TransEventIds = NULL;
  long* SrcStates = NULL; 
  long* EqnIndices;
  long EqnCount;
  VARIANT_BOOL bMasterNodeStatus = VARIANT_FALSE;

  if (m_pEsoImpl) 
  {
    m_pEsoImpl->Release();
    m_pEsoImpl = NULL;
  }

  m_pEsoImpl = pEso;

  if (pEso) 
  {
    pEso->AddRef();
    nEqns = 0;
    nVars = 0;
    nRPars = 0;
    nIPars = 0;
		hr = m_pEsoImpl->Initialize(&nEqns, &nVars, &nRPars, &nIPars, &t, &psa_atol, &psa_rtol, &psa_x, &psa_xdot, &psa_rpar, &psa_ipar);
    if (SUCCEEDED(hr))
    {
      m_pEsoImpl->GetMasterNodeStatus(&bMasterNodeStatus);
      m_bMasterNode = bMasterNodeStatus == VARIANT_TRUE ? true : false;

      SetLocalSize(nEqns, nVars, nRPars, nIPars);

      // add member Esos if any are defined
      if (SUCCEEDED( m_pEsoImpl->GetMemberEsos(&nEsos, &psa_Esos) ))
      {
        if (psa_Esos && nEsos > 0)
        {
          SA_ACCESS_DATA(psa_Esos, Esos)
          for (i = 0; i < nEsos; i++)
          {
            CComObject<CIsDaeEsoIImpl>::CreateInstance(&pEsoCont);
            pEsoCont->SetEso(Esos[i]);
            pEsoCont->QueryInterface(IID_IIsDaeEso, reinterpret_cast<void**> (&pIIsDaeEso) );
            AddEso(pIIsDaeEso);
            pEsoCont->Release();
          }
          SafeArrayUnaccessData(psa_Esos);
          SafeArrayDestroy(psa_Esos);
        }
      }

      // add STN information if defined
  		if (SUCCEEDED( m_pEsoImpl->GetSTNStruct(&nStates, &nTransitions, &iDefaultState, &psaTransEventIds, &psaSrcStates, &psaStateToEqnMap, &psaTransToEqnMap) ))
      {
        if (nStates > 0 && nTransitions > 0 && iDefaultState >= 0 && psaTransEventIds && psaSrcStates && psaStateToEqnMap && psaTransToEqnMap)
        {
          m_nStates = nStates;
          m_nTransitions = nTransitions;
          m_DefaultState = iDefaultState;
          m_CurrentState = iDefaultState;
          SafeArrayAccessData(psaTransEventIds, (void HUGEP* FAR*)& TransEventIds);
          SafeArrayAccessData(psaSrcStates, (void HUGEP* FAR*)& SrcStates);
          SafeArrayAccessData(psaTransToEqnMap, (void HUGEP* FAR*)& vTransToEqnMap);
          SafeArrayAccessData(psaStateToEqnMap, (void HUGEP* FAR*)& vStateToEqnMap);

          m_TransitionInfo = new TransitionInfo[nTransitions];
          for (i = 0; i < nTransitions; i++)
          {
            m_TransitionInfo[i].SourceState = SrcStates[i];
            m_TransitionInfo[i].setEventId(TransEventIds[i]);
            SA_ACCESS_DATA(vTransToEqnMap[i].parray, EqnIndices)
            EqnCount = count;
            m_TransitionInfo[i].setEqns(EqnIndices, EqnCount);
            SafeArrayUnaccessData(vTransToEqnMap[i].parray);
          }
          m_StateInfo = new StateInfo[nStates];
          for (i = 0; i < nStates; i++) 
          {
            SA_ACCESS_DATA(vStateToEqnMap[i].parray, EqnIndices)
            EqnCount = count;
            m_StateInfo[i].setEqns(EqnIndices, EqnCount);
            SafeArrayUnaccessData(vStateToEqnMap[i].parray);
          }

          SafeArrayUnaccessData(psaTransEventIds);
          SafeArrayUnaccessData(psaSrcStates);
          SafeArrayUnaccessData(psaStateToEqnMap);
          SafeArrayUnaccessData(psaTransToEqnMap);
          SafeArrayDestroy(psaTransEventIds);
          SafeArrayDestroy(psaSrcStates);
          SafeArrayDestroy(psaStateToEqnMap);
          SafeArrayDestroy(psaTransToEqnMap);
        }
      }

      m_time->m_initVal = m_time->m_curVal = t;

      if (psa_atol)
      {
        SA_ACCESS_DATA(psa_atol, atol)
        if (count >= m_nVars) 
        { 
          m_tolerance->Init_atol(false, m_nVars);
          for (i = lbound, j = 0; i <= ubound && j < m_nVars; i++, j++) m_tolerance->m_atol[j] = atol[i];
        }
        else 
        {
          m_tolerance->Init_atol(true, m_nVars);
          m_tolerance->m_atol[0] = atol[0];
        }
        SafeArrayUnaccessData(psa_atol);
      }
      else
      {
        m_tolerance->Init_atol(true, m_nVars);
        m_tolerance->m_atol[0] = 1e-4;
      }
      
      if (psa_rtol)
      {
        SA_ACCESS_DATA(psa_rtol, rtol)
        if (count >= m_nVars) 
        { 
          m_tolerance->Init_rtol(false, m_nVars);
          for (i = lbound, j = 0; i <= ubound && j < m_nVars; i++, j++) m_tolerance->m_rtol[j] = rtol[i];
        }
        else 
        {
          m_tolerance->Init_rtol(true, m_nVars);
          m_tolerance->m_rtol[0] = rtol[0];
        }
        SafeArrayUnaccessData(psa_rtol);
      }
      else
      {
        m_tolerance->Init_rtol(true, m_nVars);
        m_tolerance->m_rtol[0] = 1e-4;
      }

      if (psa_x)
      {
        SA_ACCESS_DATA(psa_x, x)
        for (i = lbound, j = 0; i <= ubound && j < m_nVars; i++, j++) m_y->m_var_init[j] = m_y->m_varVal[j] = x[i];
        SafeArrayUnaccessData(psa_x);
      }
      else
      {
        for (i = 0; i < m_nVars; i++)
          m_y->m_var_init[j] = m_y->m_varVal[j] = 0.0;
      }

      if (psa_xdot)
      {
        SA_ACCESS_DATA(psa_xdot, xdot)
        for (i = lbound, j = 0; i <= ubound && j < m_nVars; i++, j++) m_y->m_varDot_init[j] = m_y->m_varDotVal[j] = xdot[i];
        SafeArrayUnaccessData(psa_xdot);
      }
      else
      {
        for (i = 0; i < m_nVars; i++) 
          m_y->m_varDot_init[i] = m_y->m_varDotVal[i] = 0.0;
      }

      if (psa_rpar)
      {
        SA_ACCESS_DATA(psa_rpar, rpar)
        for (i = 0; i < m_nLocalRPars; i++) 
          m_realParameters[i] = rpar[i];

        SafeArrayUnaccessData(psa_rpar);
      }

      if (psa_ipar)
      {
        SA_ACCESS_DATA(psa_ipar, ipar)
        for (i = 0; i < m_nLocalIPars; i++) 
          m_integerParameters[i] = ipar[i];

        SafeArrayUnaccessData(psa_ipar);
      }
    }
  }

  initSafeArrays();

	return S_OK;
}

void CIsDaeEsoIImpl::initSafeArrays()
{
  DestroySafeArrays();
  long nVars = m_nVars;
  long nEqns = m_nEqns;

  m_psa_x = SafeArrayCreateVector(VT_R8, 0, nVars);
  m_psa_xdot = SafeArrayCreateVector(VT_R8, 0, nVars);
  m_psa_rpar = SafeArrayCreateVector(VT_R8, 0, m_nRealParameters);
  m_psa_ipar = SafeArrayCreateVector(VT_I4, 0, m_nIntegerParameters);
  m_psa_iEqn = SafeArrayCreateVector(VT_I4, 0, nEqns);
  m_psa_vEqn = SafeArrayCreateVector(VT_R8, 0, nEqns);
  m_psa_iJac = SafeArrayCreateVector(VT_I4, 0, nEqns*nVars*2);
  m_psa_iActiveJac = SafeArrayCreateVector(VT_I4, 0, nEqns*nVars*2);
  m_psa_vJac = SafeArrayCreateVector(VT_R8, 0, nEqns*nVars);

  SafeArrayAccessData(m_psa_x, (void HUGEP* FAR*)& m_x);
  SafeArrayAccessData(m_psa_xdot, (void HUGEP* FAR*)& m_xdot);
  SafeArrayAccessData(m_psa_rpar, (void HUGEP* FAR*)& m_rpar);
  SafeArrayAccessData(m_psa_ipar, (void HUGEP* FAR*)& m_ipar);
  SafeArrayAccessData(m_psa_iEqn, (void HUGEP* FAR*)& m_iEqn);
  SafeArrayAccessData(m_psa_vEqn, (void HUGEP* FAR*)& m_vEqn);
  SafeArrayAccessData(m_psa_iJac, (void HUGEP* FAR*)& m_iJac);
  SafeArrayAccessData(m_psa_iActiveJac, (void HUGEP* FAR*)& m_iActiveJac);
  SafeArrayAccessData(m_psa_vJac, (void HUGEP* FAR*)& m_vJac);
}

void CIsDaeEsoIImpl::SetArrays(
  double* y,
  double* ydot,
  double* rPar, 
  long* iPar,
  SAFEARRAY*& psa_x,
  SAFEARRAY*& psa_xdot,
  SAFEARRAY*& psa_rpar,
  SAFEARRAY*& psa_ipar)
{
  long i;

  if (y == m_y->m_varVal)
    psa_x = m_y->m_psa_varVal;
  else
  {
    psa_x = m_psa_x;
    for (i = 0; i < m_nActiveVars; i++) m_x[m_ActiveVars[i]] = y[i];
  }

  if (ydot == m_y->m_varDotVal)
    psa_xdot = m_y->m_psa_varDotVal;
  else
  {
    psa_xdot = m_psa_xdot;
    for (i = 0; i < m_nActiveVars; i++) m_xdot[m_ActiveVars[i]] = ydot[i];
  }

  psa_rpar = m_psa_rpar;
  for (i = 0; i < m_nRealParameters; i++) m_rpar[i] = rPar[i];

  psa_ipar = m_psa_ipar;
  for (i = 0; i < m_nIntegerParameters; i++) m_ipar[i] = iPar[i];

}

STDMETHODIMP CIsDaeEsoIImpl::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IIsDaeEsoImpl,
    &IID_IIsDaeEso,
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CIsDaeEsoIImpl::SetSize(long nEqns, long nVars, long nRPars, long nIPars)
{
  HRESULT hr = CIsDaeEsoBase::SetSize(nEqns, nVars, nRPars, nIPars);
  initSafeArrays();
  return hr;
}


HRESULT CIsDaeEsoIImpl::iEvalStateCondition(bool* EqnState, double EventTime, long iActiveDisEqn, long iTransition, VARIANT_BOOL* bEvent)
{
  if (!m_pEsoImpl) return E_FAIL;

  long i;
  long iMapEqn;
  double* x;
  double* xdot;
  VARIANT_BOOL* eqn_state = NULL;

  SAFEARRAY* psa_x = SafeArrayCreateVector(VT_R8, 0, m_nVars);
  SAFEARRAY* psa_xdot = SafeArrayCreateVector(VT_R8, 0, m_nVars);
  SAFEARRAY* psa_eqn_state = SafeArrayCreateVector(VT_BOOL, 0, m_nLocalEqns);

  SafeArrayAccessData(psa_eqn_state, (void HUGEP* FAR*)& eqn_state);
  for (i = 0; i < m_nLocalEqns; i++) eqn_state[i] = EqnState[i] ? VARIANT_TRUE : VARIANT_FALSE;
  SafeArrayUnaccessData(psa_eqn_state);

  SafeArrayAccessData(psa_x, (void HUGEP* FAR*)& x);
  SafeArrayAccessData(psa_xdot, (void HUGEP* FAR*)& xdot);
  iDerivInterpolateAll(EventTime, x, xdot);
  SafeArrayUnaccessData(psa_x);
  SafeArrayUnaccessData(psa_xdot);
  
  iMapEqn = m_ActiveEqns[iActiveDisEqn];
    
  HRESULT hr = m_pEsoImpl->EvalStateCondition(&psa_eqn_state, &psa_x, &psa_xdot, EventTime, iMapEqn, iTransition, bEvent);

  SafeArrayDestroy(psa_x);
  SafeArrayDestroy(psa_xdot);
  SafeArrayDestroy(psa_eqn_state);

  return hr;
}

HRESULT CIsDaeEsoIImpl::iGetLocalJacobianStruct(MatInfo& JacStruct)
{
  long i, j, k, l;
  if (!m_pEsoImpl) return E_FAIL;

  long lbound, ubound, count;

  SAFEARRAY* psa_ColIndices = NULL; 
  SAFEARRAY* psa_cNZCols = NULL;
  SAFEARRAY* psa_CalcMethod = NULL;

  long nColIndices = 0;
  long* ColIndices = NULL; 
  long* cNZCols = NULL;
  long* CalcMethod = NULL;

  HRESULT hr = m_pEsoImpl->GetJacobianStruct(&nColIndices, &psa_ColIndices, &psa_cNZCols, &psa_CalcMethod);

  if (SUCCEEDED(hr))
  {
    if (nColIndices > 0)
    {
      // allow room for z entries for discontinuous functions
      JacStruct.SetCompactSize(m_nEqns, nColIndices + m_nEqns);
      JacStruct.m_nColIndices = 0;

      if (psa_ColIndices && psa_CalcMethod && psa_cNZCols)
      {
        SA_ACCESS_DATA(psa_ColIndices, ColIndices)
        SA_ACCESS_DATA(psa_CalcMethod, CalcMethod)
        SA_ACCESS_DATA(psa_cNZCols, cNZCols)

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
          for (j = 0; j < cNZCols[i]; j++)
          {
            JacStruct.m_ColIndices[k] = ColIndices[l];
            JacStruct.m_compact_data[k] = CalcMethod[l];
            JacStruct.m_compact_value[k] = 0.0;
            JacStruct.m_bValueSet[k] = false;
            JacStruct.m_cNZCols[i]++;
            JacStruct.m_nColIndices++;
            k++;
            l++;
          }
        }
        SafeArrayUnaccessData(psa_ColIndices);
        SafeArrayUnaccessData(psa_CalcMethod);
        SafeArrayUnaccessData(psa_cNZCols);
      }

    }
  }
  return hr;
}


HRESULT CIsDaeEsoIImpl::iGetLocalMassStruct(MatInfo& MassStruct)
{
  long i, j, k;
  if (!m_pEsoImpl) return E_FAIL;

  long lbound, ubound, count;

  SAFEARRAY* psa_ColIndices = NULL; 
  SAFEARRAY* psa_cNZCols = NULL;
  SAFEARRAY* psa_CalcMethod = NULL;

  long nColIndices = 0;
  long* ColIndices = NULL; 
  long* cNZCols = NULL;
  long* CalcMethod = NULL;

  HRESULT hr = m_pEsoImpl->GetDiffJacobianStruct(&nColIndices, &psa_ColIndices, &psa_cNZCols, &psa_CalcMethod);

  if (SUCCEEDED(hr))
  {
    if (nColIndices > 0)
    {
      MassStruct.SetCompactSize(m_nEqns, nColIndices);
      MassStruct.m_nColIndices = 0;

      if (psa_ColIndices && psa_CalcMethod && psa_cNZCols)
      {
        SA_ACCESS_DATA(psa_ColIndices, ColIndices)
        SA_ACCESS_DATA(psa_CalcMethod, CalcMethod)
        SA_ACCESS_DATA(psa_cNZCols, cNZCols)

        k = 0;
        for (i = 0; i < m_nLocalEqns; i++)
        {
          MassStruct.m_spRowPage[i] = k;
          MassStruct.m_cNZCols[i] = 0;
          for (j = 0; j < cNZCols[i]; j++)
          {
            MassStruct.m_ColIndices[k] = ColIndices[k];
            MassStruct.m_compact_data[k] = CalcMethod[k];
            MassStruct.m_compact_value[k] = 0.0;
            MassStruct.m_bValueSet[k] = false;
            MassStruct.m_cNZCols[i]++;
            MassStruct.m_nColIndices++;
            k++;
          }
        }
        SafeArrayUnaccessData(psa_ColIndices);
        SafeArrayUnaccessData(psa_CalcMethod);
        SafeArrayUnaccessData(psa_cNZCols);
      }

    }
  }
  return hr;
}

HRESULT CIsDaeEsoIImpl::iGetLocalResiduals(
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

  SAFEARRAY* psa_x;
  SAFEARRAY* psa_xdot;
  SAFEARRAY* psa_rpar;
  SAFEARRAY* psa_ipar;

  SetArrays(y, ydot, realParameters, integerParameters, psa_x, psa_xdot, psa_rpar, psa_ipar);
  
  long i, iMapEqn;
  long* loc_indices = new long[cIndices];
  long count = 0;
  for (i = 0; i < cIndices; i++) 
  {
    residuals[i] = 0.0;
    iMapEqn = m_ActiveEqns[Indices[i]];
    if (!m_EqnMap[iMapEqn].bUndefined)
    {
      residuals[i] = 0.0;
      m_iEqn[count] = m_EqnMap[iMapEqn].iEqn;
      loc_indices[count] = i;
      count++;
    }
  }

  hr = m_pEsoImpl->GetResiduals(&m_psa_iEqn, count, t, &psa_x, &psa_xdot, &psa_rpar, &psa_ipar, &m_psa_vEqn);
  for (i = 0; i < count; i++) residuals[loc_indices[i]] = m_vEqn[i];

  if (SUCCEEDED(hr))
  {
    // correct the residuals for the discontinuous functions
    // rp = g(), but r = z - g() ==> r = z - rp
    for (i = 0; i < cIndices; i++)
    {
      iMapEqn = m_ActiveEqns[Indices[i]];
      if (m_EqnMap[iMapEqn].bDiscontinuous)
        residuals[i] = y[m_itActiveVars[m_EqnMap[iMapEqn].iDiscVar]] - residuals[i];
    }
  } 

  DESTROY_VECTOR(loc_indices)

  return hr;
}

HRESULT CIsDaeEsoIImpl::iGetLocalJacobianValues(
  long* ActiveIndices,
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

  SAFEARRAY* psa_x;
  SAFEARRAY* psa_xdot;
  SAFEARRAY* psa_rpar;
  SAFEARRAY* psa_ipar;

  long i, j, k;
  long iActiveEqn, iMapEqn, iDaeEqn, iActiveVar, iVar; 
  Jac_Calc_Method cm;
  long count = 0;
  bool bFound;
  long* iJac = new long[2*cIndices];

  SetArrays(y, ydot, rPar, iPar, psa_x, psa_xdot, psa_rpar, psa_ipar);
  for (i = 0; i < cIndices && SUCCEEDED(hr); i++) 
  {
    iActiveEqn = ActiveIndices[2*i];
    iMapEqn = m_ActiveEqns[iActiveEqn]; 
    iDaeEqn = m_EqnMap[iMapEqn].iEqn;
    iActiveVar = ActiveIndices[2*i+1];
    iVar = m_ActiveVars[iActiveVar];

    if (m_EqnMap[iMapEqn].iDiscVar == iVar)
    {
      JacVals[i] = 1.0;
    }
    else
    {
      bFound = false;
      for (j = 0; j < JacStruct.m_cNZCols[iMapEqn]; j++)
      {
        k = JacStruct.m_spRowPage[iMapEqn]+j;
        if (JacStruct.m_ColIndices[k] == iVar)
        {
          cm = (Jac_Calc_Method) JacStruct.m_compact_data[k];
          if (cm == JCM_CONST)
            JacVals[i] = JacStruct.m_compact_value[k];
          else
            bFound = true;

          break;
        }
      }

      if (bFound)
      {
        if (cm == JCM_NUM)
        {
          hr = numericJacobian(iActiveEqn, iVar, t, y, ydot, rPar, iPar, JacVals[i]);
          if (SUCCEEDED(hr))
          {
            if (m_EqnMap[iMapEqn].bDiscontinuous) 
              JacVals[i] *= -1.0;
          }
        }
        else if (cm == JCM_SYM || cm == JCM_AD)
        {
          m_iJac[2*count] = iDaeEqn;
          m_iJac[2*count+1] = iVar;
          iJac[2*count] = iMapEqn;
          iJac[2*count+1] = iVar;
          m_iActiveJac[count] = i;
          count++;
        }
      }
      else if (cm != JCM_CONST)
      {
        _ASSERTE(0);
      }
    }
  }
  
  hr = m_pEsoImpl->GetJacobianValues(&m_psa_iJac, count, t, &psa_x, &psa_xdot, &psa_rpar, &psa_ipar, &m_psa_vJac);
  if (SUCCEEDED(hr))
  {
    for (i = 0; i < count; i++)
    {
      iMapEqn = iJac[2*i];
      if (m_EqnMap[iMapEqn].bDiscontinuous) m_vJac[i] *= -1.0;
      JacVals[m_iActiveJac[i]] = m_vJac[i];
    }
  }

  DESTROY_VECTOR(iJac)
  return hr;
}


HRESULT CIsDaeEsoIImpl::iGetLocalMassValues(
  long* ActiveIndices,
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

  SAFEARRAY* psa_x;
  SAFEARRAY* psa_xdot;
  SAFEARRAY* psa_rpar;
  SAFEARRAY* psa_ipar;

  long i, j, k;
  long iActiveEqn, iMapEqn, iDaeEqn, iActiveVar, iVar; 
  Jac_Calc_Method cm;
  long count = 0;
  bool bFound;

  SetArrays(y, ydot, rPar, iPar, psa_x, psa_xdot, psa_rpar, psa_ipar);
  for (i = 0; i < cIndices && SUCCEEDED(hr); i++) 
  {
    iActiveEqn = ActiveIndices[2*i];
    iMapEqn = m_ActiveEqns[iActiveEqn];
    iDaeEqn = m_EqnMap[iMapEqn].iEqn;
    iActiveVar = ActiveIndices[2*i+1];
    iVar = m_ActiveVars[iActiveVar];

    bFound = false;
    for (j = 0; j < MassStruct.m_cNZCols[iMapEqn]; j++)
    {
      k = MassStruct.m_spRowPage[iMapEqn]+j;
      if (MassStruct.m_ColIndices[k] == iVar)
      {
        cm = (Jac_Calc_Method) MassStruct.m_compact_data[k];
        if (cm == JCM_CONST)
          MassVals[i] = MassStruct.m_compact_value[k];
        else
          bFound = true;

        break;
      }
    }

    if (bFound)
    {
      if (cm == JCM_NUM)
      {
        hr = numericDiffJacobian(iActiveEqn, iVar, t, y, ydot, rPar, iPar, MassVals[i]);
      }
      else if (cm == JCM_SYM)
      {
        m_iJac[2*count] = iDaeEqn;
        m_iJac[2*count+1] = iVar;
        m_iActiveJac[count] = i;
        count++;
      }
    }
    else if (cm != JCM_CONST)
    {
      _ASSERTE(0);
    }
  }

  hr = m_pEsoImpl->GetDiffJacobianValues(&m_psa_iJac, count, t, &psa_x, &psa_xdot, &psa_rpar, &psa_ipar, &m_psa_vJac);
  if (SUCCEEDED(hr))
  {
    for (i = 0; i < count; i++)
      MassVals[m_iActiveJac[i]] = m_vJac[i];
  }

  return hr;
}

HRESULT CIsDaeEsoIImpl::iGetEquationForm(EqnForm*& iEqnForm, EqnDiffForm*& iEqnDiffForm)
{
  long i;
  SAFEARRAY* psaForm = NULL;
  SAFEARRAY* psaDiffForm = NULL;
  EqnForm* form = NULL;
  EqnDiffForm* diff_form = NULL;

  if (!m_pEsoImpl) return E_FAIL;

  iEqnForm = new EqnForm[m_nEqns];
  iEqnDiffForm = new EqnDiffForm[m_nEqns];

  for (i = 0; i < m_nEqns; i++) 
  {
    iEqnForm[i] = EqnForm_Continuous;
    iEqnDiffForm[i] = EqnDiffForm_Numeric;
  }

  psaForm = SafeArrayCreateVector(VT_I4, 0, m_nEqns);
  psaDiffForm = SafeArrayCreateVector(VT_I4, 0, m_nEqns);

  HRESULT hr = m_pEsoImpl->GetEqnForm(&psaForm, &psaDiffForm);
  if (SUCCEEDED(hr))
  {
    SafeArrayAccessData(psaForm, (void HUGEP* FAR*)& form);
    SafeArrayAccessData(psaDiffForm, (void HUGEP* FAR*)& diff_form);
    for (i = 0; i < m_nEqns; i++)
    {
      iEqnForm[i] = form[i];
      iEqnDiffForm[i] = diff_form[i];
    }
  }

  SafeArrayDestroy(psaForm);
  SafeArrayDestroy(psaDiffForm);

  return hr;
}

HRESULT CIsDaeEsoIImpl::TriggerEvent(double EventTime, BSTR EventId, long iEventEqn)
{
  if (!m_pEsoImpl) return E_FAIL;

  m_EventTime = EventTime;
  m_EventId = EventId;
  m_EventEqn = iEventEqn;

  HRESULT hr = m_pEsoImpl->TriggerEvent(EventTime, EventId, iEventEqn);

  m_EventTime = 0.0;
  m_EventId = NULL;
  m_EventEqn = -1;

  return hr;
}

STDMETHODIMP CIsDaeEsoIImpl::PostTransition(long iNewState)
{
  HRESULT hr = E_FAIL;

  if (m_pModelExec)
  {
    hr = m_pModelExec->OnTransition(m_EventTime, m_EventEqn, m_EventId, iNewState, static_cast<IIsDaeEso*> (this));
  }

  return hr;
}

STDMETHODIMP CIsDaeEsoIImpl::PostStateEvent(double t, BSTR EventId)
{
  // TODO: bring this up to date
  return E_NOTIMPL;
}