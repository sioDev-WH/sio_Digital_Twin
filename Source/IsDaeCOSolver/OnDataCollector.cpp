// OnDataCollector.cpp: implementation of the COnDataCollector class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "ISDaeCOSolver.h"
#include "OnDataCollector.h"
#include "IsDaeEsoCImpl.h"
#include "CommonTools.h"

#if 0
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#endif

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

// initialize size on the COnBroadcaster<A> base class to 0, so size can be initialized properly later
COnDataCollector::COnDataCollector(_TCHAR* Name, IIsDaeEsoCImpl* pSrc) : COnBroadcaster<double>(Name, NULL, 0),
  m_psaVarIds(NULL), m_pVarIds(NULL), m_psaVarVals1(NULL), m_psaVarVals2(NULL), m_psaActiveBuffer(NULL),
  m_varCount(0), m_pSrcModel(NULL)
{
  m_pSrcModel = pSrc;
}

bool COnDataCollector::broadcast()
{
  bool bRet = true;

  if (m_pSrcModel && m_pOwner)
  {
    m_pSrcModel->GetVariables(&(m_psaVarIds), m_pOwner->getTime(), &(m_psaActiveBuffer) );
    // flip the buffers
    if (m_psaActiveBuffer == m_psaVarVals1) 
    {
      m_psaActiveBuffer = m_psaVarVals2;
    }
    else 
    {
      m_psaActiveBuffer = m_psaVarVals1;
    }

    double* temp = m_pInBuff;
    m_pInBuff = m_pOutBuff;
    m_pOutBuff = temp;

    bRet = COnBroadcaster<double>::broadcast();
  }
  return bRet;
}

bool COnDataCollector::SetVariables(_TCHAR** varNames, long varCount)
{
  long i, j;
  long count = 0;
  long cFound = 0;
  CComBSTR compareName;
  SAFEARRAY* psaVarNames = NULL;
  BSTR* pVarNames = NULL;

  if (m_psaVarIds)
  {
    SafeArrayUnaccessData(m_psaVarIds);
    SafeArrayDestroy(m_psaVarIds);
    m_pVarIds = NULL;
  }

  if (m_psaVarVals1)
  {
    SafeArrayUnaccessData(m_psaVarVals1);
    SafeArrayDestroy(m_psaVarVals1);
    m_psaVarVals1 = NULL;
    m_pInBuff = NULL;
  }

  if (m_psaVarVals2)
  {
    SafeArrayUnaccessData(m_psaVarVals2);
    SafeArrayDestroy(m_psaVarVals2);
    m_psaVarVals2 = NULL;
    m_pOutBuff = NULL;
  }

  if (m_pSrcModel)
  {
    COnBroadcaster<double>::m_size = varCount;
    m_psaVarIds = SafeArrayCreateVector(VT_I4, 0, m_size);
    SafeArrayAccessData(m_psaVarIds, (void HUGEP* FAR*)& m_pVarIds); 

    m_psaVarVals1 = SafeArrayCreateVector(VT_R8, 0, m_size);
    SafeArrayAccessData(m_psaVarVals1, (void HUGEP* FAR*)& m_pInBuff); 

    m_psaVarVals2 = SafeArrayCreateVector(VT_R8, 0, COnBroadcaster<double>::m_size);
    SafeArrayAccessData(m_psaVarVals2, (void HUGEP* FAR*)& m_pOutBuff); 
    
    m_psaActiveBuffer = m_psaVarVals1;

    m_pSrcModel->GetVarNames(&psaVarNames);
    SafeArrayAccessData(psaVarNames, (void HUGEP* FAR*)& pVarNames);
    SafeArrayGetUBound(psaVarNames, 1, &count);
    for (i = 0; i < count; i++)
    {
      compareName = pVarNames[i];
      for (j = 0; j < varCount; j++)
      {
        if (compareName == varNames[j])
        {
          m_pVarIds[j] = i;
          cFound++;
          break;
        }
      }
    }
    SafeArrayUnaccessData(psaVarNames);
    SafeArrayDestroy(psaVarNames);

    _ASSERTE(cFound == m_size);
  }
  return (cFound == m_size);
}

COnDataCollector::~COnDataCollector()
{
  clean();
}

void COnDataCollector::clean()
{
  if (m_psaVarIds)
  {
    SafeArrayUnaccessData(m_psaVarIds);
    SafeArrayDestroy(m_psaVarIds);
    m_psaVarIds = NULL;
    m_pVarIds = NULL;
  }

  if (m_psaVarVals1)
  {
    SafeArrayUnaccessData(m_psaVarVals1);
    SafeArrayDestroy(m_psaVarVals1);
    m_psaVarVals1 = NULL;
    m_pInBuff = NULL;
  }

  if (m_psaVarVals2)
  {
    SafeArrayUnaccessData(m_psaVarVals2);
    SafeArrayDestroy(m_psaVarVals2);
    m_psaVarVals2 = NULL;
    m_pOutBuff = NULL;
  }
  
  m_pSrcModel = NULL;
}

