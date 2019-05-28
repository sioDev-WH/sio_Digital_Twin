// OnTest.cpp : Implementation of COnTest
#include "stdafx.h"
#include "ISDaeCOSolver.h"
#include "OnTest.h"
#include "MatInfo.h"

#if 0
#include "EventBroadcast.h"
#include "OnDataCollector.h"
#endif

#if 0
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#endif

/////////////////////////////////////////////////////////////////////////////
// COnTest

COnTest::COnTest()
{
  DWORD dwMemContext = 1;
  IMalloc* pMalloc = NULL;
  HRESULT hr = CoGetMalloc( dwMemContext, &pMalloc );
#if 0
  IOnBroadcaster* test = new COnBroadcaster<COnTest, double>(this, &COnTest::getData);
#endif
}

COnTest::~COnTest()
{

}

STDMETHODIMP COnTest::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IOnTest
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP COnTest::SparseTest()
{
	long i, j, k;
  long nStages = 4;
  long nSize = 8;
  long nColIndices = 28;
  long nIterations = 1000;

  double* RHS = new double[nSize];
  double* solution = new double[nSize];
  MatInfo** pIM = new MatInfo*[nStages];
  for (i = 0; i < nStages; i++)
  {
    pIM[i] = new MatInfo();
    pIM[i]->m_form = SPARSE;
    pIM[i]->SetCompactSize(8, 28);
    fillTestData(*pIM[i], nSize, nColIndices, RHS);
    pIM[i]->spMatrixInit(); 
  }

  for (i = 0; i < nIterations; i++)
  {
    for (j = 0; j < nStages; j++)
    {
      pIM[j]->decompose();
      for (k = 0; k < nSize; k++) solution[k] = RHS[k];
      pIM[j]->SolveEquation(solution);
      //ATLTRACE("\n");
      //for (i = 0; i < nSize; i++) ATLTRACE("%e ", solution[i]);
    }
  }

  for (i = 0; i < nStages; i++)
    delete pIM[i];

  delete [] pIM;

	return S_OK;
}

void COnTest::fillTestData(MatInfo& m, long nSize, long nColIndices, double* RHS)
{
  m.m_spRowPage[0] = 0;   m.m_cNZCols[0] = 4;   
  m.m_spRowPage[1] = 4;   m.m_cNZCols[1] = 4;
  m.m_spRowPage[2] = 8;   m.m_cNZCols[2] = 4;
  m.m_spRowPage[3] = 12;  m.m_cNZCols[3] = 2;
  m.m_spRowPage[4] = 14;  m.m_cNZCols[4] = 4;
  m.m_spRowPage[5] = 18;  m.m_cNZCols[5] = 4;
  m.m_spRowPage[6] = 22;  m.m_cNZCols[6] = 3;
  m.m_spRowPage[7] = 25;  m.m_cNZCols[7] = 3;
  
  m.m_ColIndices[0]= 0;     m.m_compact_value[0] = 0.0010686;
  m.m_ColIndices[1]= 1;     m.m_compact_value[1] =  -1.66e-05;
  m.m_ColIndices[2]=  4;    m.m_compact_value[2] =  -0.001;
  m.m_ColIndices[3]=  5;    m.m_compact_value[3] =  -4.2e-05;
  m.m_ColIndices[4]=  0;    m.m_compact_value[4] =  5.9554e-05;
  m.m_ColIndices[5]=  1;    m.m_compact_value[5] =  0.000131298;
  m.m_ColIndices[6]=  5;    m.m_compact_value[6] =  -9.16434e-05;
  m.m_ColIndices[7]=  6;    m.m_compact_value[7] =  0.000148333;
  m.m_ColIndices[8]=  2;    m.m_compact_value[8] =  0.00213033;
  m.m_ColIndices[9]=  4;    m.m_compact_value[9] =  -0.002;
  m.m_ColIndices[10]=  6;   m.m_compact_value[10] =  0.000190213;
  m.m_ColIndices[11]=  7;   m.m_compact_value[11] =  -4.2e-05;
  m.m_ColIndices[12]=  3;   m.m_compact_value[12] =  0.000275862;
  m.m_ColIndices[13]=  5;   m.m_compact_value[13] =  -4.6936e-05;
  m.m_ColIndices[14]=  0;   m.m_compact_value[14] =  -0.001;
  m.m_ColIndices[15]=  2;   m.m_compact_value[15] =  -0.002;
  m.m_ColIndices[16]=  4;   m.m_compact_value[16] =  0.00308858;
  m.m_ColIndices[17]=  7;   m.m_compact_value[17] =  0.000666678;
  m.m_ColIndices[18]=  0;   m.m_compact_value[18] =  -0.000118154;
  m.m_ColIndices[19]=  1;   m.m_compact_value[19] =  -6.68894e-08;
  m.m_ColIndices[20]=  3;   m.m_compact_value[20] =  -4.71518e-05;
  m.m_ColIndices[21]=  5;   m.m_compact_value[21] =  0.000366644;
  m.m_ColIndices[22]=  1;   m.m_compact_value[22] =  -0.000200677;
  m.m_ColIndices[23]=  2;   m.m_compact_value[23] =  -1.8e-06;
  m.m_ColIndices[24]=  6;   m.m_compact_value[24] =  0.000333767;
  m.m_ColIndices[25]=  2;   m.m_compact_value[25] =  -0.000198585;
  m.m_ColIndices[26]=  4;   m.m_compact_value[26] =  -7.2e-06;
  m.m_ColIndices[27]=  7;   m.m_compact_value[27] =  0.000431315;

  RHS[0] = 4.03934e-07;
  RHS[1] = -3.044e-07;
  RHS[2] = -1.53475e-05;
  RHS[3] = 5.28676e-08;
  RHS[4] = 1.5958e-05;
  RHS[5] = -9.9608e-08;
  RHS[6] = -2.13155e-07;
  RHS[7] = 4.15313e-09;
}