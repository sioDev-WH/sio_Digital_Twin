// IsDaeSolver.cpp : Implementation of CIsDaeSolver
#include "stdafx.h"
#include "ISDaeCOSolver.h"
#include "IsDaeSolver.h"
#include "IsStepper.h"
#include "IsDaeEso.h"
#include "ConsistentInitialization.h"
#include "IsCINlaEso.h"
#include "OnDaeCOSolverMacros.h"

#if 1 // temporary
#include "ModelNavMaps.h"
#endif

#if 0
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#endif

/////////////////////////////////////////////////////////////////////////////
// CIsDaeSolver

CIsDaeSolver::CIsDaeSolver()
{
  m_nAugmentedEqns = 0;
  m_nAugmentedVars = 0; 
  m_VAL = NULL;
  m_assignedEqn = NULL;
  m_pModel = NULL;
  m_pStepper = new CIsStepper();
}

CIsDaeSolver::~CIsDaeSolver()
{
  m_nAugmentedEqns = 0;
  m_nAugmentedVars = 0; 
  DESTROY_VECTOR(m_VAL)
  DESTROY_VECTOR(m_assignedEqn)
  m_pModel = NULL;
  delete m_pStepper;
}

STDMETHODIMP CIsDaeSolver::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IIsDaeSolver
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

// ICapeNumericSolver
// initialize time from executive

STDMETHODIMP CIsDaeSolver::Step()
{
  return m_pStepper->Step();
}

STDMETHODIMP CIsDaeSolver::SetEso(IIsDaeEso* pEso)
{
  DWORD pIsEsoImpl = NULL;
  CIsDaeEsoBase* pDaeEso = NULL;
  CComObject<CIsCINlaEso>* pCINlaEso = NULL;

  DESTROY_VECTOR(m_VAL)
  DESTROY_VECTOR(m_assignedEqn)

  HRESULT hr = pEso->GetCPPPtr(&pIsEsoImpl);
  if (SUCCEEDED(hr))
  {
    pDaeEso = m_pStepper->m_M = reinterpret_cast<CIsDaeEsoBase*> (pIsEsoImpl);
    pDaeEso->m_bGlobalNode = true;
    if (!pDaeEso->m_bEsoInitialized)
    {
      hr = pDaeEso->iInitialize();
      if (SUCCEEDED(hr))
      {
        pDaeEso->iInitializeMasterNodes();
        hr = pDaeEso->initFlatModel();
        if (SUCCEEDED(hr))
        {
          pDaeEso->iCompleteMasterNodeInit();
          pDaeEso->initializeConstantJacobians(); 
          hr = ConsistentInitialization(m_nAugmentedEqns, m_nAugmentedVars, m_assignedEqn, m_VAL, pDaeEso, pCINlaEso);
          pDaeEso->initDirectEqnMap();
          pCINlaEso->Release();

          if (SUCCEEDED(hr))
          {
            m_pStepper->OnEvent(true);
          }
        }
      }
    }
  }

  return hr;
}


