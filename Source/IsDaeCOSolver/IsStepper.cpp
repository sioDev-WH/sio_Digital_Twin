// IsStepper.cpp: implementation of the CIsStepper class.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "ISDaeCOSolver.h"
#include "IsStepper.h"
//#include "IsDaeSolver.h"
#include < math.h  >
#include "IsDaeEso.h"
#include "ConsistentInitialization.h"
#include "IsCINlaEso.h"
#include "IsNlaSolver.h"
#include "triangularization.h"
#include "CommonTools.h"

#include "OnDaeCOSolverMacros.h"
#include "TransitionInfo.h"
#include "StateInfo.h"
#include "VarInfo.h"
#include "ModelNavMaps.h"
#include "MatInfo.h"
#include "VirtualTimeInfo.h"
#include "ToleranceInfo.h"
#include "ReportInfo.h"
#include "StepSizeInfo.h"
#include "ConvergenceInfo.h"
#include "IndexInfo.h"

#include <float.h>
#include <fstream.h>
#include "stdio.h"

// BLAS includes
#include "mkl.h"

#if 1 // temporary include for testing
#include "IsDaeEsoCImpl.h"
#endif

#if 0
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#endif


#if 0
//static long _run_residual_test = 0;
#endif

extern "C"
{
  double DDOT( int *n, double *x, int *incx, double *y, int *incy);
  void   DSCAL(int *n, double *a, double *x, int *incx);
  void   DAXPY(int *n, double *alpha, double *x, int *incx, double *y, int *incy);
  void   VDDIV(int *n, double *a, double *b, double *r);
  double DNRM2(int *n, double *x,int *incx);
  void   DCOPY(int *n, double *x, int *incx, double *y, int *incy);
  void   DGEMM(char *transa,char *transb,int *m,int *n,int *k,
              double *alpha,double *a,int *lda,
              double *b,int *ldb,
              double *beta,double *c,int *ldc);

}
// end BLAS includes


void messagePump()
{
	MSG msg;

	while(PeekMessage(&msg,NULL,NULL,NULL,PM_REMOVE))
	{
		TranslateMessage(&msg);
	  DispatchMessage(&msg);
	}
}


#ifndef CLOCKS_PER_SEC
#define CLOCKS_PER_SEC 60.0
#endif

/*
// sparse library references
#include ".\..\SparseMatrices\sparse\compcol_double.h"
#include ".\..\SparseMatrices\sparse\comprow_double.h"
#include ".\..\SparseMatrices\sparse\ilupre_double.h"
#include ".\..\SparseMatrices\sparse\diagpre_double.h"
#include ".\..\SparseMatrices\sparse\iohb_double.h"
#include ".\..\SparseMatrices\mv\mvblasd.h"
#include ".\..\SparseMatrices\mv\mvvd.h"
#include ".\..\SparseMatrices\mv\mvmd.h"
#include ".\..\SparseMatrices\mv\mv.h"
#include ".\..\SparseMatrices\sparse\sparse.h"
#include ".\..\SparseMatrices\IML\gmres.h"
*/

//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////



CIsStepper::CIsStepper()
{
  m_MaxStepSize = 1.0e100;
  m_M = NULL;
  initAlgorithmMatrices();

  // sparse iteration matrix variables
  m_JacIMMap = NULL;
  m_MassIMMap = NULL;

  m_dJacIMMap = 0;
  m_dMassIMMap = 0;
  m_nJacIMMap = 0;
  m_nMassIMMap = 0;

  m_sparseIMReinitialize = true;

  m_nStages = 4;

  // initialize compute variations variables
  m_info = NULL;
  m_ierrs = NULL;
  m_tgs = NULL;
  m_udys = NULL;
  m_tudys = NULL;
#if _NOT_USING_BLAS3 == 0
  m_temp_udys = NULL;
#endif
  m_tempVecx = NULL;
  m_tempVecy = NULL;

  // scaled norm variables
  m_normTolerance = NULL;
  m_normHighIndexScale = NULL;
  m_vNorm = NULL;

#if 0
  fs.open( "ravMSF.txt", ios::out, filebuf::openprot );
  fs_count = 0;
#endif

  // newton start variables
  m_v = NULL;
  m_w = NULL;
  m_diff = NULL;


  // BLAS3
  m_cv_transa='T';
	m_cv_transb='T';
	m_cv_lda = 0;
  m_cv_ldb = 0;
  m_cv_ldc = 0;
  m_cv_m = 0;
  m_cv_n = 0;
  m_cv_k = 0;
 //End of BLAS3


}

CIsStepper::~CIsStepper()
{
  long i;

  // sparse iteraction matrix variables
  if (m_JacIMMap)
  {
    for (i = 0; i < m_dJacIMMap; i++) DESTROY_VECTOR(m_JacIMMap[i])
    DESTROY_VECTOR(m_JacIMMap)
  }

  if (m_MassIMMap)
  {
    for (i = 0; i < m_dMassIMMap; i++) DESTROY_VECTOR(m_MassIMMap[i])
    DESTROY_VECTOR(m_MassIMMap)
  }

  // clean compute variations variables
  DESTROY_VECTOR(m_info)
  DESTROY_VECTOR(m_ierrs)
  DESTROY_VECTOR(m_tempVecx)
  DESTROY_VECTOR(m_tempVecy)
  
  if (m_tgs)
  {
#if _NOT_USING_BLAS3
    // before BLAS3
    for (i = 0; i < m_nStages; i++)
    {
      DESTROY_VECTOR(m_tgs[i])
      DESTROY_VECTOR(m_udys[i])
      DESTROY_VECTOR(m_tudys[i])
    }
#endif

    DESTROY_VECTOR(m_tgs)
    DESTROY_VECTOR(m_udys)
    DESTROY_VECTOR(m_tudys)
#if _NOT_USING_BLAS3 == 0
    DESTROY_VECTOR(m_temp_udys)
#endif
  }

  // scaled norm variables
  DESTROY_VECTOR(m_normTolerance)
  DESTROY_VECTOR(m_normHighIndexScale)
  DESTROY_VECTOR(m_vNorm)


  // newton start variables
  // prefict Newton start variables
  if (m_v)
  {
    for (i = 0; i < m_nStages; i++) DESTROY_VECTOR(m_v[i])
    DESTROY_VECTOR(m_v)
  }

  if (m_w)
  {
    for (i = 0; i < m_nStages; i++) DESTROY_VECTOR(m_w[i])
    DESTROY_VECTOR(m_w)
  }
  DESTROY_VECTOR(m_diff)
}

void CIsStepper::initAlgorithmMatrices(){
  
  C[0] =8.85879595127039430E-02;
  C[1] = 4.09466864440734710E-01;
  C[2] = 7.87659461760847110E-01;
  C[3] = 1.0000000000000000000;
  
  A[0][0] = 1.12999479323156150E-01;
  A[0][1] = -4.03092207235221240E-02;
  A[0][2] = 2.58023774203363160E-02;
  A[0][3] = -9.90467650726640190E-03;
  A[1][0] = 2.34383995747400210E-01;
  A[1][1] = 2.06892573935359120E-01;
  A[1][2] = -4.78571280485409760E-02;
  A[1][3] = 1.60474228065163730E-02;
  A[2][0] = 2.16681784623249830E-01;
  A[2][1] = 4.06123263867374850E-01;
  A[2][2] = 1.89036518170054850E-01;
  A[2][3] = -2.41821048998323020E-02;
  A[3][0] = 2.20462211176767560E-01;
  A[3][1] = 3.88193468843174740E-01;
  A[3][2] = 3.28844319980056810E-01;
  A[3][3] = 6.25000000000008880E-02;
  
  D[0] = 1.52077368976571730E-01;
  D[1] = 1.98631665602052860E-01;
  D[2] = 1.73704821245586140E-01;
  D[3] = 2.26879766524847200E-01;
  
  B[0][0] = -3.36398745680207070E+00;
  B[0][1] = -4.46547007540097850E-01;
  B[0][2] = 0.000000000000000000000;
  B[0][3] = 0.000000000000000000000;
  B[1][0] = 2.53420388412422460E+01;
  B[1][1] = 3.36398745680206800E+00;
  B[1][2] = 0.000000000000000000000;
  B[1][3] = 0.000000000000000000000;
  B[2][0] = 0.000000000000000000000;
  B[2][1] = 0.000000000000000000000;
  B[2][2] = -4.37367276825310510E-01;
  B[2][3] = -5.80576031184040710E-02;
  B[3][0] = 0.000000000000000000000;
  B[3][1] = 0.000000000000000000000;
  B[3][2] = 3.29483348541735400E+00;
  B[3][3] = 4.37367276825312510E-01;

#if _NOT_USING_BLAS3
// before BLAS3  
  Q[0][0] = 2.95256291376448490E+00;
  Q[0][1] = 3.15939676526544260E-01;
  Q[0][2] = 1.53250361857358990E+00;
  Q[0][3] = 2.76001773070919800E-02;
  Q[1][0] = -7.26638442522609210E+00;
  Q[1][1] = -8.75577120872169210E-01;
  Q[1][2] = -1.05525925554083820E+00;
  Q[1][3] = -3.11277680445624430E-01;
  Q[2][0] = 3.42060134189704890E+00;
  Q[2][1] = 9.49331950091266920E-01;
  Q[2][2] = -1.07997190626525940E+01;
  Q[2][3] = -2.13491394363750460E+00;
  Q[3][0] = 3.48973092842014550E+01;
  Q[3][1] = 4.37528029636525950E+00;
  Q[3][2] = -4.29039265780423160E+01;
  Q[3][3] = -5.89600020104458620E+00;
  
  QINV[0][0] = 4.94042191453623210E-01;
  QINV[0][1] = 2.69406327540352320E-01;
  QINV[0][2] = -2.07753732935469560E-01;
  QINV[0][3] = 6.33161132809504090E-02;
  QINV[1][0] = -3.53358212942913720E+00;
  QINV[1][1] = -2.98582140519829590E+00;
  QINV[1][2] = 1.75646748288234010E+00;
  QINV[1][3] = -4.94914306872105080E-01;
  QINV[2][0] = 4.87641455081039950E-01;
  QINV[2][1] = 1.23938205146711190E-01;
  QINV[2][2] = 4.23770339324015460E-02;
  QINV[2][3] = -1.96050751500893220E-02;
  QINV[3][0] = -3.24650638473406870E+00;
  QINV[3][1] = -1.52301305545598620E+00;
  QINV[3][2] = -2.34591215977400570E-01;
  QINV[3][3] = -1.94525303087971780E-02;

#else
  
// after BLAS3
  Q[0]  = 2.95256291376448490E+00;
  Q[1]  = 3.15939676526544260E-01;
  Q[2]  = 1.53250361857358990E+00;
  Q[3]  = 2.76001773070919800E-02;
  Q[4]  = -7.26638442522609210E+00;
  Q[5]  = -8.75577120872169210E-01;
  Q[6]  = -1.05525925554083820E+00;
  Q[7]  = -3.11277680445624430E-01;
  Q[8]  = 3.42060134189704890E+00;
  Q[9]  = 9.49331950091266920E-01;
  Q[10] = -1.07997190626525940E+01;
  Q[11] = -2.13491394363750460E+00;
  Q[12] = 3.48973092842014550E+01;
  Q[13] = 4.37528029636525950E+00;
  Q[14] = -4.29039265780423160E+01;
  Q[15] = -5.89600020104458620E+00;
  
  QINV[0]  = 4.94042191453623210E-01;
  QINV[1]  = 2.69406327540352320E-01;
  QINV[2]  = -2.07753732935469560E-01;
  QINV[3]  = 6.33161132809504090E-02;
  QINV[4]  = -3.53358212942913720E+00;
  QINV[5]  = -2.98582140519829590E+00;
  QINV[6]  = 1.75646748288234010E+00;
  QINV[7]  = -4.94914306872105080E-01;
  QINV[8]  = 4.87641455081039950E-01;
  QINV[9]  = 1.23938205146711190E-01;
  QINV[10] = 4.23770339324015460E-02;
  QINV[11] = -1.96050751500893220E-02;
  QINV[12] = -3.24650638473406870E+00;
  QINV[13] = -1.52301305545598620E+00;
  QINV[14] = -2.34591215977400570E-01;
  QINV[15] = -1.94525303087971780E-02;
#endif
  
  B0 = 1.00000000000000000E-02;
  
  V[0] = 1.57753763977411530E-02;
  V[1] = -9.73676595200762000E-03;
  V[2] = 6.46138955426500680E-03;
  V[3] = 2.24379766524848060E-01;
  
  UINV[0][0] =    0.0                ;
  UINV[0][1] =    0.0                ;
  UINV[0][2] =    0.0                ;
  UINV[0][3] =    1.0                ;
  UINV[1][0] =   -0.6133376973486749 ;
  UINV[1][1] =    2.700531288824063  ;
  UINV[1][2] =   -9.587193591475394  ;
  UINV[1][3] =    7.5                ;
  UINV[2][0] =   -3.927079477247392  ;
  UINV[2][1] =   15.68094527819332   ;
  UINV[2][2] =  -26.75386580094595   ;
  UINV[2][3] =   15.0                ;
  UINV[3][0] =   -4.891279419672913  ;
  UINV[3][1] =   13.95409058457028   ;
  UINV[3][2] =  -17.81281116489738   ;
  UINV[3][3] =    8.75               ;
}

HRESULT CIsStepper::Step()
{
  HRESULT hr = S_OK;
  long loop_counter = 0;

  
  m_M->m_report->m_StepperCalls++;
  m_M->iDirectSetLastTime(m_M->m_time->m_curVal);

  // calculate the tolerance for the scaledNorm function (recalculated before each newton step)
  calcNormTolerance(); 

  loop_counter = 0;
  do 
  {
    loop_counter++;

    updateJacobians();

    formIterationMatrix(); // First call also allocates mem and sets decomp flag
    decomposeIterationMatrix();

    if (m_M->m_report->m_idid == 1)
    {
      performNewtonIteration();
      performIterationControl();
      m_M->m_time->m_curIteration++;
    
      if (loop_counter > 10) goto step_failure;
    }
    if (m_M->m_report->m_idid == -1) goto step_failure;
  } while (!m_M->m_convergance->m_solved);

  m_M->m_report->m_TotalSteps = m_M->m_time->m_curIteration;

  return S_OK;

step_failure:
  return E_FAIL;
}


bool CIsStepper::updateJacobians()
{
  if(m_M->m_Jac->m_updateRequired){
    m_M->m_Mass->m_updateRequired=true;// to avoid updating m_M->m_Mass flag all over the code
    m_M->UpdateAllJacobianValues(); 
    m_M->m_Jac->m_dataUpToDate=true;
    m_M->m_report->m_jacobiansCalls++;
  }
  if(m_M->m_Mass->m_updateRequired){ 
    m_M->UpdateAllDiffJacobianValues(); 
    m_M->m_Mass->m_dataUpToDate=true;
  }

#if 0
  long i, j;
  double val;
  ATLTRACE("\nJacobian:");
  for (i = 0; i < m_M->m_nActiveEqns; i++)
  {
    ATLTRACE("\n%d",m_M->m_ActiveEqns[i]);
    for (j = 0; j < m_M->m_nActiveVars; j++)
    {
      m_M->m_Jac->GetValue(i,j,val);
      if (val != 0.0)
        ATLTRACE("\t[%d] %2.2e", j, val);
    }
    
  }

  ATLTRACE("\nMass:\n");
  for (i = 0; i < m_M->m_nActiveEqns; i++)
  {
    ATLTRACE("\n%d",m_M->m_ActiveEqns[i]);
    for (j = 0; j < m_M->m_nActiveVars; j++)
    {
      m_M->m_Mass->GetValue(i,j,val);
      if (val != 0.0)
        ATLTRACE("\t[%d] %2.2e", j, val);
    }
  }

#endif

  return true;
}


bool CIsStepper::formIterationMatrix()
{
  long i,j,k;
  long nlj,nuj;
  long nlm,num;
  long kmin,kmax;
  MatInfo* pIM;
  double hlu= m_M->m_step->m_LUVal;


  //cerr << setiosflags( ios::scientific )<< setprecision( 10 )<< setw( 16 );

  if(!m_M->m_iterationMatrix){  

    // BLAS3
	  m_cv_lda = m_nStages;
    m_cv_ldb = m_M->m_nActiveVars;
    m_cv_ldc = m_nStages;
    m_cv_m = m_nStages;
    m_cv_n = m_M->m_nActiveVars;
    m_cv_k = m_nStages;
    // End of BLAS3

    m_M->m_iterationMatrix = (MatInfo**) new MatInfo*[m_nStages];
    for(i=0;i<m_nStages;i++)
    {
      m_M->m_iterationMatrix[i]  = (MatInfo*) new MatInfo(m_M->m_nActiveEqns,m_M->m_nActiveVars,false,NULL); // KAB added active
      if (m_M->m_Jac->m_form== BANDED && m_M->m_Mass->m_form== BANDED)
        m_M->m_iterationMatrix[i]->m_form=BANDED;
      else if (m_M->m_Jac->m_form== SPARSE && m_M->m_Mass->m_form== SPARSE)
        m_M->m_iterationMatrix[i]->m_form = SPARSE;
      else
        m_M->m_iterationMatrix[i]->m_form=FULL;

      m_M->m_iterationMatrix[i]->m_lowerBandwidth=m_M->m_Jac->m_lowerBandwidth;
      m_M->m_iterationMatrix[i]->m_upperBandwidth=m_M->m_Jac->m_upperBandwidth;
      m_M->m_iterationMatrix[i]->Init();
      m_M->m_iterationMatrix[i]->m_decompositionRequired = true;
      m_M->m_iterationMatrix[i]->m_bFullDecompositionRequired = true;
    }
  }

  nuj=m_M->m_Jac->m_upperBandwidth;
  nlj=m_M->m_Jac->m_lowerBandwidth;
  nlm =  m_M->m_Mass->m_lowerBandwidth;
  num =  m_M->m_Mass->m_upperBandwidth;

  if (m_M->m_iterationMatrix[0]->m_decompositionRequired)
  {
    if ( (m_M->m_Jac->m_form == SPARSE) && (m_M->m_Mass->m_form == SPARSE) )
    {
      if (m_sparseIMReinitialize) 
        initSparseIterationMatrix();
      for(i=0;i<m_nStages;i++)
      {
        pIM = m_M->m_iterationMatrix[i];
        for (j = 0; j < pIM->m_nColIndices; j++) pIM->m_compact_value[j] = 0.0;
        for (j = 0; j < m_nMassIMMap; j++) pIM->m_compact_value[m_MassIMMap[j][1]] = m_M->m_Mass->m_compact_value[m_MassIMMap[j][0]];
        for (j = 0; j < m_nJacIMMap; j++) pIM->m_compact_value[m_JacIMMap[j][1]] += hlu*D[i]*m_M->m_Jac->m_compact_value[m_JacIMMap[j][0]];
      }
      pIM->m_dataUpToDate = true;
      pIM->m_decompositionRequired = true;
    }
    else if(m_M->m_Jac->m_form == BANDED && m_M->m_Mass->m_form == BANDED){    
      //  ************** Wassim 6/25/01 changed condition to both are banded
      for(i=0;i<m_nStages;i++){
        pIM = m_M->m_iterationMatrix[i];
        for(j=0;j<m_M->m_nActiveEqns;j++){  // KAB added active
          kmin= LMAX(0,nlj-j );
          kmax= LMIN(nuj+nlj+1,nlj+m_M->m_nActiveEqns-j); // KAB added active
          for(k=kmin;k<kmax;k++){
            pIM->m_data[j][k] = hlu*D[i]*m_M->m_Jac->m_data[j][k];
#if 0
            // TODO: The above assignment to pIM goes outside the bounds of the pIM matrix for
            // nlj = 5, nuj = 3, nlm = 0, num = 4.  This needs to be fixed in some way.
            ATLTRACE("\n%e",pIM->m_data[j][k]);
#endif
          }
        }
        for(j=0;j<m_M->m_nActiveEqns;j++){  // KAB added active
          kmin= LMAX(0,nlm-j);
          kmax= LMIN(num+nlm+1,nlm+m_M->m_nActiveEqns-j); // KAB added active
          for(k=kmin;k<kmax;k++){
            pIM->m_data[j][k+(nlj-nlm)] += m_M->m_Mass->m_data[j][k];
#if 0
            ATLTRACE("\n%e",pIM->m_data[j][k+(nlj-nlm)]);
#endif
          }
        }
        pIM->m_dataUpToDate= true;// Flag is updated here because generating function is NULL

      }
    }
    else if(m_M->m_Jac->m_form == BANDED && m_M->m_Mass->m_form != BANDED){
//  **************  Wassim 6/25/01 added section to support ONLY J is banded
      for(i=0;i<m_nStages;i++){
//  ***************
        pIM = m_M->m_iterationMatrix[i];                               //  ***************

        for(j=0;j<m_M->m_nActiveEqns;j++){  // KAB added active
//  ***************
          kmin= LMAX(0,nlj-j );                                        //  ***************

          kmax= LMIN(nuj+nlj+1,nlj+m_M->m_nActiveEqns-j); // KAB added active
          for(k=kmin;k<kmax;k++){
            pIM->m_data[j][k] = hlu*D[i]*m_M->m_Jac->m_data[j][k];
#if 0
            // TODO: The above assignment to pIM goes outside the bounds of the pIM matrix for
            // nlj = 5, nuj = 3, nlm = 0, num = 4.  This needs to be fixed in some way.
            ATLTRACE("\n%e",pIM->m_data[j][k]);
#endif
          }
        }
        for(j=0;j<m_M->m_nActiveEqns;j++){  // KAB added active
          kmin= 0 ;
          kmax= m_M->m_nActiveVars;
          for(k=kmin;k<kmax;k++){
            pIM->m_data[j][k+(nlj-nlm)] += m_M->m_Mass->m_data[j][k];
#if 0
            ATLTRACE("\n%e",pIM->m_data[j][k+(nlj-nlm)]);
#endif
          }
        }
        pIM->m_dataUpToDate= true;// Flag is updated here because generating function is NULL

      }
    }                                                        
    // **************************** End of 6/25/01 Fix
    else if(m_M->m_Jac->m_form != BANDED && m_M->m_Mass->m_form == BANDED){
      for(i=0;i<m_nStages;i++){
        pIM = m_M->m_iterationMatrix[i];
        for(j=0;j<m_M->m_nActiveEqns;j++){  // KAB added active
          kmin= 0 ;
          kmax= m_M->m_nActiveVars;
          for(k=kmin;k<kmax;k++)
            pIM->m_data[j][k] = hlu*D[i]*m_M->m_Jac->m_data[j][k];
        }
        for(j=0;j<m_M->m_nActiveEqns;j++){   // KAB added active
          kmin= LMAX(0,nlm-j);
          kmax= LMIN(num+nlm+1,nlm+m_M->m_nActiveEqns-j); // KAB added active
          for(k=kmin;k<kmax;k++)
            pIM->m_data[j][k+j-nlm] += m_M->m_Mass->m_data[j][k];
        }
#ifdef _Testing

        for(j=0;j<m_M->m_nActiveEqns;j++){   // KAB added active
          long kmin= LMAX(0,nlj-j);
          long kmax= LMIN(nuj+nlj+1,nlj+m_M->m_nActiveEqns-j);  // KAB added active
          for(k=0;k<nlj+nuj+1;k++){
            if(k>=kmin && k<kmax)
              cerr << pIM->m_data[j][k]<<"\t";
            else
              cerr << "X" <<"\t\t";
          }
          cerr << "\n";
        }
#endif
        m_M->m_iterationMatrix[i]->m_dataUpToDate= true;// Flag is updated here because generating function is NULL
      }
    }
    else
    { 
      // Full matrix Case
      for(i=0;i<m_nStages;i++){
        pIM = m_M->m_iterationMatrix[i];
        for(j=0;j<m_M->m_nActiveEqns;j++){  // KAB added active
          kmin= 0 ;
          kmax= m_M->m_nActiveVars;
          for(k=kmin;k<kmax;k++)
            pIM->m_data[j][k] = m_M->m_Mass->m_data[j][k] + hlu*D[i]*m_M->m_Jac->m_data[j][k];
        }
#ifdef _Report
        cerr << "Iteration Matrix "<<i << "\n";
        for(j=0;j<m_M->m_nActiveEqns;j++){ // KAB added active
          for(k =0;k <m_M->m_nActiveVars ;k++){
            cerr << pIM->m_data[j][k]<< "\t";
          }
          cerr << "\n";
        }
#endif
        m_M->m_iterationMatrix[i]->m_dataUpToDate= true;// Flag is updated here because generating function is NULL
      }
    }
    return true;
  }
  else{
    // cerr << "Warning: Attempt to update ietration matrix using old Jacobians\n";
    return false;
  }
}

bool CIsStepper::initSparseIterationMatrix()
{
  long i, j;
  long iRow, cJCol, cMCol, spJCol, spMCol;
  double hlu = m_M->m_step->m_LUVal;  
  long nColIndices;
  MatInfo* pIM;

  bool* bCol = NULL;
  long* cNZ = NULL;
  long* colIndices = NULL;
  long* spRowPage = NULL;

  // initialize jacobian and mass matrix maps into iteration matrix for fast copying for matrix values into the 
  // iteration matrix
  long JacSize;
  long MassSize;
  long JacGrowBy;
  long MassGrowBy;

  JacSize = m_dJacIMMap;
  JacGrowBy = m_M->m_JacStruct->m_nColIndices - m_dJacIMMap;
  if (JacGrowBy < 0) JacGrowBy = 0;
  size_ptr_array(0, JacSize, m_dJacIMMap, m_JacIMMap, JacGrowBy);

  MassSize = m_dMassIMMap;
  MassGrowBy = m_M->m_MassStruct->m_nColIndices - m_dMassIMMap;
  if (MassGrowBy < 0) MassGrowBy = 0;
  size_ptr_array(0, MassSize, m_dMassIMMap, m_MassIMMap, MassGrowBy);

  if (JacGrowBy > 0)
    for (i = JacSize; i < m_dJacIMMap; i++) m_JacIMMap[i] = new long[2];
  
  if (MassGrowBy > 0)  
    for (i = MassSize; i < m_dMassIMMap; i++) m_MassIMMap[i] = new long[2];

  m_nJacIMMap = 0;
  m_nMassIMMap = 0;

  bCol = new bool[m_M->m_nActiveVars];
  cNZ = new long[m_M->m_nActiveEqns];
  colIndices = new long[m_M->m_JacStruct->m_nColIndices + m_M->m_MassStruct->m_nColIndices];
  spRowPage = new long[m_M->m_nActiveEqns+1];
  
  nColIndices = 0;
  // determine the size of m_M->m_Mass + m_M->m_Jac
  for (iRow = 0; iRow < m_M->m_nActiveEqns; iRow++)
  {
    spRowPage[iRow] = nColIndices;
    cNZ[iRow] = 0;
    for (i = 0; i < m_M->m_nActiveVars; i++) bCol[i] = false;
    cJCol = m_M->m_Jac->m_cNZCols[iRow];
    cMCol = m_M->m_Mass->m_cNZCols[iRow];
    spJCol = m_M->m_Jac->m_spRowPage[iRow];
    spMCol = m_M->m_Mass->m_spRowPage[iRow];

    for (i = 0; i < cJCol; i++) 
    {
      bCol[m_M->m_Jac->m_ColIndices[spJCol + i]] = true;
      m_JacIMMap[m_nJacIMMap+i][0] = spJCol + i;
    }

    for (i = 0; i < cMCol; i++) 
    {
      bCol[m_M->m_Mass->m_ColIndices[spMCol + i]] = true;
      m_MassIMMap[m_nMassIMMap+i][0] = spMCol+i;
    }

    for (i = 0; i < m_M->m_nActiveVars; i++) 
    {
      if (bCol[i])
      {
        cNZ[iRow]++;
        colIndices[nColIndices++] = i;
      }
    }

    for (i = 0; i < cJCol; i++)
    {
      for (j = spRowPage[iRow]; j < nColIndices; j++)
      {
        if (m_M->m_Jac->m_ColIndices[spJCol + i] == colIndices[j]) 
        {
          m_JacIMMap[m_nJacIMMap++][1] = j;
          break;
        }
      }
    }

    for (i = 0; i < cMCol; i++)
    {
      for (j = spRowPage[iRow]; j < nColIndices; j++)
      {
        if (m_M->m_Mass->m_ColIndices[spMCol + i] == colIndices[j]) 
        {
          m_MassIMMap[m_nMassIMMap++][1] = j;
          break;
        }
      }
    }
  }

  for(i=0;i<m_nStages;i++)
  {
    pIM = m_M->m_iterationMatrix[i];
    pIM->SetCompactSize(m_M->m_nActiveEqns, nColIndices);
    for (j = 0; j < pIM->m_nRows; j++) 
    {
      pIM->m_cNZCols[j] = cNZ[j];
      pIM->m_spRowPage[j] = spRowPage[j];
    }
    for (j = 0; j < nColIndices; j++) pIM->m_ColIndices[j] = colIndices[j];

    pIM->spMatrixInit(); 
    pIM->m_decompositionRequired = true;
    pIM->m_dataUpToDate = false;
  }

  m_sparseIMReinitialize = false;

  DESTROY_VECTOR(bCol)
  DESTROY_VECTOR(cNZ)
  DESTROY_VECTOR(colIndices)
  DESTROY_VECTOR(spRowPage)

  return true;
}

bool CIsStepper::decomposeIterationMatrix(){
  
  long  i; 
  MatInfo* pIM;  	 
  

#if 0 // timing
  double startTime = ((double)clock() / CLOCKS_PER_SEC);
#endif

  if(m_M->m_iterationMatrix[0]->m_decompositionRequired){
#ifdef _Testing
    cerr << setiosflags( ios::scientific )<< setprecision( 2 )<< setw( 16 );
#endif
    for(i=0;i<m_nStages;i++){
      pIM = m_M->m_iterationMatrix[i];
#ifdef _Testing 
      // Testing LU decomposition of banded matrices in compact form 
      long  k;
      double* a; 
      double* b;
      double* c;
      a=(double*) new double[m_M->m_nActiveEqns]; // KAB added active
      b=(double*) new double[m_M->m_nActiveEqns];
      c=(double*) new double[m_M->m_nActiveEqns];
      for(long j=0;j<m_M->m_nActiveEqns;j++){  // KAB added active
        a[j]= (double)rand()/RAND_MAX;
        c[j]= a[j];
        b[j] = 0.0;
      } 
      
      
      cerr << "Iteration Matrix "<<i << "\n";
      if(pIM->m_form==BANDED){
        long nuj=m_M->m_Jac->m_upperBandwidth;
        long nlj=m_M->m_Jac->m_lowerBandwidth;
        for(j=0;j<m_M->m_nActiveEqns;j++){   // KAB added active
          long kmin= LMAX(0,nlj-j);
          long kmax= LMIN(nuj+nlj+1,nlj+m_M->m_nActiveEqns-j); // KAB added active
          for(k=0;k<nlj+nuj+1;k++){
            if(k>=kmin && k<kmax)
              cerr << pIM->m_data[j][k]<<"\t";
            else
              cerr << "X" <<"\t\t";
          }
          cerr << "\n";
        }
      }
      else{
        for(j=0;j<m_M->m_nActiveEqns;j++){ // KAB added active
          for( k =0;k <m_M->m_nActiveVars ;k++){
            cerr << pIM->m_data[j][k]<< " "; 
          }
          cerr << "\n";  
        }
      }
      
      
      pIM->multiplyVec(a, b);
      
      for(j=0;j<m_M->m_nActiveEqns;j++) // KAB added active
        cerr << "a[" << j << "] = " << a [j] << " \t " << "b [" << j << "] = " << b[j] << "\n";
      
      pIM->decompose();
      m_M->m_report->m_DecompCalls++;
      pIM->SolveEquation(b);
      cerr << "Residuals "<< "\n";
      for(j=0;j<m_M->m_nActiveEqns;j++) // KAB added active
        cerr << "(x - inv(A)*b)[" << j << "] = " << c[j] << " - " << b[j] << " = " << c[j]-b[j] << "\n";
      
#else // not debugging

#if 0
      printMat3(pIM->m_nRows, pIM->m_nRows, pIM->m_cNZCols, pIM->m_ColIndices, pIM->m_compact_value);
#endif

      pIM->decompose();

#endif 
    } 

    m_M->m_report->m_DecompCalls++;

#if 0 // timing
      double endTime =  ((double)clock() / CLOCKS_PER_SEC);
      ATLTRACE("\ndecomp time:\t%f", endTime - startTime);
#endif // timing

    return true;
  }
  else{
    // cerr << "Warning: Attempt to unnecessairly factorize iteration matrix\n";
    return false;
  }
}

bool CIsStepper::performNewtonIteration(){
  // Computes Y, YDot, alpha, growth, driver, conver
  
  bool ready = false;
  
  m_M->m_convergance->m_newtonIterationIndex=0;
  predictNewtonStart(); // Calculates YDot
  checkConvergence();
  do{
    m_M->m_convergance->m_newtonIterationIndex++;
    computeVariations();
    updateStageVars();
    checkConvergence();
  }
  while(!m_M->m_convergance->m_ready);
  
  return false;
  
}

bool CIsStepper::performIterationControl(){
  
  //-------------------------------------------------------------------------------------------------------
  //     Updates m_M->m_step->m_currVal, m_M->m_Jac->m_updateRequired and m_M->m_iterationMatrix->m_decompositionRequired
  //-------------------------------------------------------------------------------------------------------
  //
  double hnew,halpha; //,remain;
  
  m_M->m_Jac->m_updateRequired = false;
  // m_M->m_Mass->m_updateRequired = false; // KAB 01/25/01
  //m_M->m_Mass->m_updateRequired = false; // KAB 16/12/02

  if (!m_M->m_convergance->m_growing) 
    halpha=m_M->m_step->m_curVal*m_M->m_convergance->m_desiredRate
    /DMAX(m_M->m_convergance->m_curRate,m_M->m_convergance->m_desiredRate/m_M->m_step->m_maxChangeFactor);
  if (m_M->m_report->m_ierr)
  { 
    // ierr indicates failure in calculating the implicit function values
    hnew=m_M->m_step->m_curVal/m_M->m_step->m_rigidChangeFactor;
    m_M->m_report->m_funcRejectedSteps++;			// rejected
    m_M->m_report->m_ierr = false; 
  }
  else if (m_M->m_convergance->m_solved)
  {
    computeLocalErrorEstimate(); // will suggest m_M->m_step->m_predictedVal as hr
    if (m_M->m_report->m_ierr)
    {  
      hnew=m_M->m_step->m_curVal/m_M->m_step->m_rigidChangeFactor;
      m_M->m_report->m_funcRejectedSteps++;   // rejected
      m_M->m_report->m_ierr = false; 
    }
    else 
    { // if (fabs(m_M->m_time->m_endVal-m_M->m_time->m_curVal) > 10.E0*m_M->m_convergance->m_uround*fabs(m_M->m_time->m_curVal)){
      
      if (m_M->m_Jac->m_dataUpToDate && (m_M->m_convergance->m_curRate > m_M->m_convergance->m_desiredRate))
      {
        hnew = DMIN(m_M->m_step->m_predictedVal,halpha);
        hnew = DMAX(m_M->m_step->m_minChangeFactor*m_M->m_step->m_curVal,hnew);
        hnew = DMIN(m_M->m_step->m_maxChangeFactor*m_M->m_step->m_curVal,hnew);
      }
      else
      {
        hnew = DMAX(m_M->m_step->m_minChangeFactor*m_M->m_step->m_curVal,m_M->m_step->m_predictedVal);
        hnew = DMIN(m_M->m_step->m_maxChangeFactor*m_M->m_step->m_curVal,hnew);
      }
      
      if ((!m_M->m_convergance->m_exact) && 
        ((m_M->m_convergance->m_curRate-fabs(m_M->m_step->m_curVal-m_M->m_step->m_LUVal)/m_M->m_step->m_LUVal)
        > m_M->m_convergance->m_updateThresholdRate))
      {
        if (m_M->m_Jac->m_dataUpToDate)
          hnew=m_M->m_step->m_curVal/m_M->m_step->m_rigidChangeFactor;
        else
          m_M->m_Jac->m_updateRequired=true;
      }
    }
  }
  else if (m_M->m_convergance->m_growing)
  {
    hnew=m_M->m_step->m_curVal/m_M->m_step->m_rigidChangeFactor;
    m_M->m_report->m_growthRejectedSteps++;
  }
  else if (m_M->m_convergance->m_diverged)
  {
    hnew = DMAX(m_M->m_step->m_minChangeFactor*m_M->m_step->m_curVal,halpha);
    hnew=DMIN(m_M->m_step->m_maxChangeFactor*m_M->m_step->m_curVal,hnew);
    m_M->m_Jac->m_updateRequired = !m_M->m_Jac->m_dataUpToDate;
    m_M->m_report->m_newtonRejectedSteps++; // Rejected
  }
  else if (m_M->m_convergance->m_slow)
  {
    if (m_M->m_Jac->m_dataUpToDate){
      if (m_M->m_convergance->m_curRate > m_M->m_convergance->m_rateFactor*m_M->m_convergance->m_desiredRate){
        hnew = DMAX(m_M->m_step->m_minChangeFactor*m_M->m_step->m_curVal,halpha);
        hnew = DMIN(m_M->m_step->m_maxChangeFactor*m_M->m_step->m_curVal,hnew);
      }
      else
        hnew=m_M->m_step->m_curVal/m_M->m_step->m_rigidChangeFactor;
    }
    else
    {
      hnew=m_M->m_step->m_curVal;
      m_M->m_Jac->m_updateRequired=true;
    }
    m_M->m_report->m_newtonRejectedSteps++; // Rejected
  }
  else
  {
    //cerr << "pside: error: impossible(?) error in ctrl \n";
    return false;
  }
  // if (fabs(m_M->m_time->m_endVal-m_M->m_time->m_curVal) > 10.E0*m_M->m_convergance->m_uround*fabs(m_M->m_time->m_curVal)){
  if (hnew < 10E0*m_M->m_convergance->m_uround*fabs(m_M->m_time->m_curVal)){ // very small step size (underflow)
    m_M->m_report->m_idid=-1;
    return false;
  }
  /*
  // Alignment so that remaining integration interval is a multiple of the step size.
  remain=(m_M->m_time->m_endVal-m_M->m_time->m_curVal)/hnew;
  if ((remain-floor(remain) > m_M->m_step->m_alignmentFactor) || (floor(remain) == 0E0))
  remain=floor(remain) + 1E0;
  else
  remain=floor(remain);
  m_M->m_step->m_curVal=(m_M->m_time->m_endVal-m_M->m_time->m_curVal)/remain; // Final assignment to m_M->m_step->m_curVal
  */
  
  // event change factor enhancement to improve recovery speed from step size drop back after events
  if ( (hnew >= m_M->m_step->m_maxChangeFactor*m_M->m_step->m_curVal) &&
       (m_M->m_report->m_StepperCalls - m_M->m_step->m_eventStepCount - m_M->m_step->m_maxEventStepCount >= 0) )
  {
    hnew *= m_M->m_step->m_eventChangeFactor;   
    m_M->m_step->m_eventChangeFactorApplied = true;
  }
  else if (hnew < m_M->m_step->m_curVal && m_M->m_step->m_eventChangeFactorApplied)
  {
    m_M->m_step->m_eventStepCount = m_M->m_report->m_StepperCalls - m_M->m_step->m_maxEventStepCount - 1;
  }

  SetStepSize(hnew);
  // }


  return true;
}

void CIsStepper::GetMaxStepSize(double* hmax)
{
  *hmax = m_MaxStepSize;
}

void CIsStepper::SetMaxStepSize(double hmax)
{
  m_MaxStepSize = hmax;
  if (hmax > m_M->m_step->m_curVal)
    SetStepSize(hmax);
}

void CIsStepper::SetStepSize(double hnew)
{
  long i;

  // NOTE: m_step->m_lastVal is not updated here.  It is only updated after a successful newton step
  if (hnew > m_MaxStepSize)
    hnew = m_MaxStepSize;

  if (hnew != m_M->m_step->m_curVal)
  {
    m_M->m_report->m_nStepSizeChanges++;
    m_M->m_step->m_curVal = hnew;
  }

  if (m_M->m_iterationMatrix)
  {
    m_M->m_iterationMatrix[0]->m_decompositionRequired = ( (m_M->m_Jac->m_updateRequired) ||
      (fabs(m_M->m_step->m_curVal-m_M->m_step->m_LUVal) > 
      m_M->m_convergance->m_decompositionThresholdRate * m_M->m_step->m_LUVal) );

    for(i = 1; i < m_nStages; i++) 
      m_M->m_iterationMatrix[i]->m_decompositionRequired = m_M->m_iterationMatrix[0]->m_decompositionRequired;

    if (m_M->m_iterationMatrix[0]->m_decompositionRequired) 
      m_M->m_step->m_LUVal = m_M->m_step->m_curVal;
  }
  else
  {
    m_M->m_step->m_LUVal = m_M->m_step->m_curVal;
  }

  // high index scale factor for the scaledNorm() function must be recalculated when the step size changes
  if (m_M->m_index->m_isHighIndex) 
    calcNormHighIndexScale(); 

  // predictNewtonStart uses m_v and m_w vectors which are dependent on step size
  calcPredictNewtonStartVars();
}


// non-BLAS version of computeVariations()
#if _NOT_USING_BLAS3
bool CIsStepper::computeVariations()
{
  long i;
  short nInnerIterations;
  long km,kb,ks,ks2,kn;
  bool valInvalid = false;
  short ierr = 0;
  long nEqns = m_M->m_nActiveEqns;

  if (!m_info)
  {
    m_info = new long[m_nStages];
    m_ierrs= new long[m_nStages];
    m_tgs = new double*[m_nStages];
    m_udys = new double*[m_nStages];
    m_tudys = new double*[m_nStages];
  
    for (i = 0; i < m_nStages; i++)
    {
      m_tgs[i] = new double[nEqns];
      m_udys[i] = new double[nEqns];
      m_tudys[i] = new double[nEqns];
    }

    m_tempVecx = new double[nEqns];
    m_tempVecy = new double[nEqns];
  }

  if (!m_M->m_K) initStageVars();

  if(m_M->m_index->m_isHighIndex) 
    nInnerIterations = 2; 
  else 
    nInnerIterations = 1;
  
  m_M->m_report->m_ierr = false;
  for(ks=0;ks<m_nStages;ks++)
  {

    m_M->m_K[ks]->m_valInvalid = false;

    m_M->iDirectGetAllResiduals(
      m_M->m_time->m_curVal+C[ks]*m_M->m_step->m_curVal,
      m_M->m_K[ks]->m_varVal,
      m_M->m_K[ks]->m_varDotVal,
      m_udys[ks],
      m_M->m_K[ks]->m_valInvalid,
      m_M->m_realParameters,
      m_M->m_integerParameters);
    
    m_M->m_report->m_ierr |= m_M->m_K[ks]->m_valInvalid; // combines all invalid flags at the report object to be checked by control module
  }

#if 0
  ATLTRACE("\n\nudys");
  for (kn = 0; kn < nEqns; kn++)
    ATLTRACE("\n%i\t%f", kn, m_udys[0][kn]);

  messagePump();
#endif

  m_M->m_report->m_functionCalls += m_nStages;
  for (ks=0;ks<m_nStages;ks++)
  {
    if (m_M->m_K[ks]->m_valInvalid)
    {
      valInvalid = true;
      return false;
    }
  }
  
  for(ks=0;ks<m_nStages;ks++)
  {
    for(kn=0;kn<m_M->m_nActiveEqns;kn++) m_tgs[ks][kn]=0.E0;
    for(kn=0;kn<m_M->m_nActiveEqns;kn++)
    {
      for(ks2=0;ks2<m_nStages;ks2++)
        m_tgs[ks][kn] -= QINV[ks][ks2]*m_udys[ks2][kn];
    }
    for(kn=0;kn<m_M->m_nActiveEqns;kn++)
      m_tudys[ks][kn]=m_tgs[ks][kn];

      m_M->m_iterationMatrix[ks]->SolveEquation(m_tudys[ks]);
  }

#if 0
  ATLTRACE("\n\ntudys");
  for (kn = 0; kn < nEqns; kn++)
    ATLTRACE("\n%i\t%f", kn, m_tudys[0][kn]);

  messagePump();
#endif


  m_M->m_report->m_Substitutions += m_nStages;
  
  for(km=2;km<=nInnerIterations;km++)
  {
    //  -(lu)^(-1)((b x m)tudys+tgs)
    for(ks=0;ks<m_nStages;ks++)
    {
      kb=ks-(ks)%2;	
      for(kn=0;kn<nEqns;kn++) // KAB added active
        m_udys[ks][kn]=m_tgs[ks][kn];
      for(kn=0;kn<nEqns;kn++) // KAB added active
        m_tempVecx[kn] = (B[ks][kb]*m_tudys[kb][kn]+B[ks][kb+1]*m_tudys[kb+1][kn]);
      m_M->m_Mass->multiplyVec(m_tempVecx, m_tempVecy);
      for(kn=0;kn<nEqns;kn++)
        m_udys[ks][kn] -= m_tempVecy[kn]; // using (BxI).DelV + (LU)^-1.(-BxM.DelV + tgs) because tgs contains -G instead of G by the time we get here.

      m_M->m_iterationMatrix[ks]->SolveEquation(m_udys[ks]);
    }

    for(ks=0;ks<m_nStages;ks++)
    { 
      kb = ks - (ks) % 2;
      for(kn=0;kn<nEqns;kn++)
      {
        m_udys[ks][kn] += (B[ks][kb]*m_tudys[kb][kn] + B[ks][kb+1]*m_tudys[kb+1][kn]);
      }
    }
    for(ks=0;ks<m_nStages;ks++)
    {
      for(kn=0;kn<nEqns;kn++)
        m_tudys[ks][kn]=m_udys[ks][kn]; // Get ready for next inner iteration
    }
    m_M->m_report->m_Substitutions += m_nStages;
  }
  
  //    transform tudys to m_M->m_K[ks2]->m_varDeltaDotVal (delta K dot's -- i.e., derivatives of stage vars)
  for (ks = 0; ks < m_nStages; ks++)
  {
    for (kn = 0; kn < nEqns; kn++)
    { 
      m_M->m_K[ks]->m_varDeltaDotVal[kn] = 0.0; 
      for (ks2=0;ks2<m_nStages;ks2++)
        m_M->m_K[ks]->m_varDeltaDotVal[kn] += Q[ks][ks2]*m_tudys[ks2][kn];
    }
  }

#if 0
  ATLTRACE("\n\nvarDeltaDotVal");
  for (kn = 0; kn < nEqns; kn++)
    ATLTRACE("\n%i\t%f", kn, m_M->m_K[0]->m_varDeltaDotVal[kn]);

  messagePump();
#endif

  // Compute Delta K from Delta K Dot
  for(ks=0;ks<m_nStages;ks++)
  {
    for(kn=0;kn<nEqns;kn++) // KAB added active
      m_M->m_K[ks]->m_varDeltaVal[kn] = 0.E0;
    for(ks2=0;ks2<m_nStages;ks2++){
      for(kn=0;kn<nEqns;kn++) // KAB added active
        m_M->m_K[ks]->m_varDeltaVal[kn] += 
        m_M->m_step->m_curVal*A[ks][ks2]*m_M->m_K[ks2]->m_varDeltaDotVal[kn];
    }
  }
  
  return true;
}


#else // using BLAS3


// BLAS3 version of computeVariations()
bool CIsStepper::computeVariations()
{
  short nInnerIterations;
  long km,kb,ks,ks2,kn;
  bool valInvalid = false;
  short ierr = 0;
  long nEqns = m_M->m_nActiveEqns;
  long iEqnBase;
  int incx = 1;
  int incy = 1;
  int size;

  if (!m_info)
  {
    m_info = new long[m_nStages];
    m_ierrs= new long[m_nStages];
    
    m_tgs = new double[m_nStages*nEqns];
    m_udys = new double[m_nStages*nEqns];
    m_tudys = new double[m_nStages*nEqns];
    m_temp_udys = new double[m_nStages*nEqns];

    m_tempVecx = new double[nEqns];
    m_tempVecy = new double[nEqns];
  }

  if (!m_M->m_K) initStageVars();

  if(m_M->m_index->m_isHighIndex) 
    nInnerIterations = 2; 
  else 
    nInnerIterations = 1;
  
  m_M->m_report->m_ierr = false;
  for(ks=0;ks<m_nStages;ks++)
  {

    m_M->m_K[ks]->m_valInvalid = false;

    m_M->iDirectGetAllResiduals(
      m_M->m_time->m_curVal+C[ks]*m_M->m_step->m_curVal,
      m_M->m_K[ks]->m_varVal,
      m_M->m_K[ks]->m_varDotVal,
      &m_udys[ks*nEqns],
      m_M->m_K[ks]->m_valInvalid,
      m_M->m_realParameters,
      m_M->m_integerParameters);

    m_M->m_report->m_ierr |= m_M->m_K[ks]->m_valInvalid; // combines all invalid flags at the report object to be checked by control module
  }

#if 1
  bool printResults = false;
  if (printResults)
  {
    ATLTRACE("\n\nudys");
    for (kn = 0; kn < nEqns; kn++)
      ATLTRACE("\n%i\t%f", kn, m_udys[kn]);
  }
  messagePump();
#endif

  m_M->m_report->m_functionCalls += m_nStages;
  for (ks=0;ks<m_nStages;ks++)
  {
    if (m_M->m_K[ks]->m_valInvalid)
    {
      valInvalid = true;
      return false;
    }
  }

	m_cv_alpha = -1.0;
	m_cv_beta = 0.0;

  DGEMM(&m_cv_transa,&m_cv_transb,
    &m_cv_m,&m_cv_n,&m_cv_k,
    &m_cv_alpha, 
    QINV,
    &m_cv_lda,
    m_udys,
    &m_cv_ldb,&m_cv_beta,
    m_tgs,
    &m_cv_ldc); 

  for (ks = 0; ks < m_nStages; ks++)
  {
    iEqnBase = ks*nEqns;
    for (kn = 0; kn < nEqns; kn++)
      m_tudys[iEqnBase+kn] = m_tgs[ks+kn*m_nStages];

    //m_M->m_iterationMatrix[ks]->SolveEquation(&m_tudys[iEqnBase]);
  }

  // m_tgs was in the wrong order as a result of DGEMM.  The above code
  // corrects the order and assigns the results to m_tudys.  The following
  // code copies the corrected m_tgs back to m_tgs.
  size = m_nStages * nEqns;
  DCOPY(&size, m_tudys, &incx, m_tgs, &incy);

  // the deferred calls to solve are calculated below.
  for (ks = 0; ks < m_nStages; ks++)
  {
    iEqnBase = ks*nEqns;
    m_M->m_iterationMatrix[ks]->SolveEquation(&m_tudys[iEqnBase]);
  }


#if 0
  ATLTRACE("\n\ntudys");
  for (kn = 0; kn < nEqns; kn++)
    ATLTRACE("\n%i\t%f", kn, m_tudys[kn]);

  messagePump();
#endif

  m_M->m_report->m_Substitutions += m_nStages;
  
  for(km=2;km<=nInnerIterations;km++)
  {
    //  -(lu)^(-1)((b x m)tudys+tgs)
    size = m_nStages * nEqns;
    DCOPY(&size, m_tgs, &incx, m_udys, &incy);

    for(ks=0;ks<m_nStages;ks++)
    {
      iEqnBase = ks*nEqns;
      kb=ks-(ks)%2;	
      for(kn=0;kn<nEqns;kn++) 
        m_tempVecx[kn] = (B[ks][kb]*m_tudys[kb*nEqns+kn]+B[ks][kb+1]*m_tudys[(kb+1)*nEqns+kn]);
      m_M->m_Mass->multiplyVec(m_tempVecx, m_tempVecy);
      for(kn=0;kn<nEqns;kn++)
        m_udys[iEqnBase+kn] -= m_tempVecy[kn];
      // using (BxI).DelV + (LU)^-1.(-BxM.DelV + tgs) because tgs contains -G instead of G by the time we get here.

      m_M->m_iterationMatrix[ks]->SolveEquation(&m_udys[iEqnBase]);
    }

    for(ks=0;ks<m_nStages;ks++)
    { 
      iEqnBase = ks*nEqns;
      kb = ks - (ks) % 2;
      for(kn=0;kn<nEqns;kn++)
      {
        m_udys[iEqnBase+kn] += (B[ks][kb]*m_tudys[kb*nEqns+kn] + B[ks][kb+1]*m_tudys[(kb+1)*nEqns+kn]);
      }
    }

    // Get ready for next inner iteration
    size = m_nStages * nEqns;
    DCOPY(&size, m_udys, &incx, m_tudys, &incy);

    m_M->m_report->m_Substitutions += m_nStages;
  }
  
  //    transform tudys to m_M->m_K[ks2]->m_varDeltaDotVal (delta K dot's -- i.e., derivatives of stage vars)
	m_cv_alpha = 1.0;
	m_cv_beta = 0.0;

  DGEMM(&m_cv_transa,&m_cv_transb,
    &m_cv_m,&m_cv_n,&m_cv_k,
    &m_cv_alpha, 
    Q,
    &m_cv_lda,
    m_tudys,
    &m_cv_ldb,&m_cv_beta,
    m_temp_udys,
    &m_cv_ldc); 

  for (ks = 0; ks < m_nStages; ks++)
  {
    for (kn = 0; kn < nEqns; kn++)
      m_M->m_K[ks]->m_varDeltaDotVal[kn] = m_temp_udys[ks+kn*m_nStages];
  }

#if 0
  ATLTRACE("\n\nvarDeltaDotVal");
  for (kn = 0; kn < nEqns; kn++)
    ATLTRACE("\n%i\t%f", kn, m_M->m_K[0]->m_varDeltaDotVal[kn]);

  messagePump();
#endif

  // Compute Delta K from Delta K Dot
  for(ks=0;ks<m_nStages;ks++)
  {
    for(kn=0;kn<nEqns;kn++) 
      m_M->m_K[ks]->m_varDeltaVal[kn] = 0.E0;
    for(ks2=0;ks2<m_nStages;ks2++){
      for(kn=0;kn<nEqns;kn++) 
        m_M->m_K[ks]->m_varDeltaVal[kn] += 
        m_M->m_step->m_curVal*A[ks][ks2]*m_M->m_K[ks2]->m_varDeltaDotVal[kn];
    }
  }
  
  return true;
}
#endif





// called each time the step size changes
bool CIsStepper::calcPredictNewtonStartVars()
{
  long i, j, k;
  double ratio;
  long nEqns = m_M->m_nActiveEqns;

  if (!m_v)
  {
    m_v = new double*[m_nStages];
    m_w = new double*[m_nStages];
    for (i = 0; i < m_nStages; i++)
    { 
      m_v[i] = new double[m_nStages];
      m_w[i] = new double[m_nStages];
    } 
    m_diff = new double[nEqns];
  }

  ratio = m_M->m_step->m_curVal/m_M->m_step->m_lastVal; 
  for(i=0;i<m_nStages ;i++)
  {
    for(j=1;j<m_nStages;j++)
      m_v[i][j] = pow((ratio*C[i]),(double)j);  	
  }
  
  for(i=0;i<m_nStages ;i++)
  {
    for(j=0;j<m_nStages;j++)
    { 
      m_w[i][j]= 0.0;
      for(k=0;k<m_nStages;k++)
        m_w[i][j] += m_v[i][k]*UINV[k][j]; 
    } 
  }
  return true;
}


#if 0 // old newton start
bool CIsStepper::predictNewtonStart(){
  
  // Computes initial YDot using 4th order extrapolation
  long i, j, k; 
  double ratio; 
  double** v; 
  double** w;
  
  if (!m_M->m_K) initStageVars();

  v = (double**) new double*[m_M->m_nStages];
  w = (double**) new double*[m_M->m_nStages];
  for(i=0;i<m_M->m_nStages ;i++){ 
    v[i] = (double*) new double[m_M->m_nStages];
    w[i] = (double*) new double[m_M->m_nStages];
  } 
  ratio = m_M->m_step->m_curVal/m_M->m_step->m_lastVal; 
  for(i=0;i<m_M->m_nStages ;i++){
    for(j=0;j<m_M->m_nStages;j++)
      v[i][j]= pow((ratio*C[i]),(double)j);  	
  }
  for(i=0;i<m_M->m_nStages ;i++)
    for(j=0;j<m_M->m_nStages;j++){ 
      w[i][j]= 0.0;
      for(k=0;k<m_M->m_nStages;k++)
        w[i][j] += v[i][k]*UINV[k][j]; 
    } 
    
    for(j=0;j<m_M->m_nStages;j++)
      for(i=0;i<m_M->m_nActiveEqns;i++){  // KAB added active
        m_M->m_K[j]->m_varDotVal[i]= m_M->m_K[m_M->m_nStages-1]->m_varLastDotVal[i];
        for(k=0;k<m_M->m_nStages;k++)
          m_M->m_K[j]->m_varDotVal[i] += w[j][k]*(m_M->m_K[k]->m_varLastDotVal[i]
          -m_M->m_K[m_M->m_nStages-1]->m_varLastDotVal[i]); 
      } 
      
      for(j=0;j<m_M->m_nStages;j++){
        for(i=0;i<m_M->m_nActiveEqns;i++) // KAB added active
          m_M->m_K[j]->m_varVal[i] = m_M->m_y->m_varVal[m_M->m_ActiveVars[i]];
        for(k=0;k<m_M->m_nStages;k++)
          for(i=0;i<m_M->m_nActiveEqns;i++) // KAB added active
            m_M->m_K[j]->m_varVal[i] += m_M->m_step->m_curVal*A[j][k]*m_M->m_K[k]->m_varDotVal[i]; 
      }
      
      if(v){
        for(i=0;i<m_M->m_nStages;i++) if(v[i]) delete v[i];
        delete v;
      }
      if(w){
        for(i=0;i<m_M->m_nStages;i++) if(w[i]) delete w[i];
        delete w;
      }
      return true;
}
#endif



bool CIsStepper::predictNewtonStart()
{
  // Computes initial YDot using 4th order extrapolation
  long j, k; 
  int nEqns = m_M->m_nActiveEqns;
  int incx = 1;
  int incy = 1;
  double scale; 

  if (!m_M->m_K) initStageVars();

  for(j=0;j<m_nStages;j++)
  {
    DCOPY(&nEqns, m_M->m_K[m_nStages-1]->m_varLastDotVal, &incx, m_M->m_K[j]->m_varDotVal, &incy);

    for(k=0;k<m_nStages;k++)
    {
      DCOPY(&nEqns, m_M->m_K[m_nStages-1]->m_varLastDotVal, &incx, m_diff, &incy);
      scale = -1.0;
      DAXPY(&nEqns, &scale, m_M->m_K[k]->m_varLastDotVal, &incx, m_diff, &incy);
      scale = -1.0 * m_w[j][k];
      DAXPY(&nEqns, &scale, m_diff, &incx, m_M->m_K[j]->m_varDotVal, &incy);
    }
  } 
  for(j=0;j<m_nStages;j++)
  {
    DCOPY(&nEqns, m_M->m_y->m_varVal, &incx, m_M->m_K[j]->m_varVal, &incy);
    for(k=0;k<m_nStages;k++)
    {
      scale = m_M->m_step->m_curVal*A[j][k];
      DAXPY(&nEqns, &scale, m_M->m_K[k]->m_varDotVal, &incx, m_M->m_K[j]->m_varVal, &incy);
    }
  }
  
  return true;
}

bool	CIsStepper::checkConvergence()
{
  long i,k, iVar;
  // TODO: the following static variable will have to be modified as a class variable to support multiple solvers
  static double u;
  double up, delta_K_norm, y_norm;

  m_M->m_convergance->m_growing=  false;
  m_M->m_convergance->m_diverged=  false;
  m_M->m_convergance->m_slow= false; 
  m_M->m_convergance->m_solved =  false; 
  m_M->m_convergance->m_exact=  false;
  
  if (!m_M->m_K) initStageVars();

  if(!m_M->m_tolerance->m_scalar){
    if(m_M->m_index->m_isHighIndex){ 
      for(i=0;i<m_M->m_nActiveEqns;i++){  // KAB added active
        iVar = m_M->m_ActiveVars[i];
        if(m_M->m_index->m_daeIndex[iVar] <= 1){
          if(fabs(m_M->m_K[m_nStages-1]->m_varVal[i])  > 
            m_M->m_convergance->m_gfac*DMAX(fabs(m_M->m_y->m_varVal[iVar]), m_M->m_tolerance->m_atol[iVar])){ 
#if 0
  ATLTRACE( "\nnew_y:%e", fabs(m_M->m_K[m_nStages-1]->m_varVal[i]) );
  ATLTRACE( "\nmax_y:%e", m_M->m_convergance->m_gfac*DMAX(fabs(m_M->m_y->m_varVal[iVar]), m_M->m_tolerance->m_atol[iVar]) );
#endif
            m_M->m_convergance->m_growing = true;
            
            break;
          } 
        } 
      }			
    }
    else{
      for(i=0;i<m_M->m_nActiveEqns;i++){ // KAB added active
        iVar = m_M->m_ActiveVars[i];
        if(fabs(m_M->m_K[m_nStages-1]->m_varVal[i])  > 
          m_M->m_convergance->m_gfac*DMAX(fabs(m_M->m_y->m_varVal[iVar]), m_M->m_tolerance->m_atol[iVar])){ 

#if 0
  ATLTRACE( "\nnew_y%e", fabs(m_M->m_K[m_nStages-1]->m_varVal[i]) );
  ATLTRACE( "\nmax_y%e", m_M->m_convergance->m_gfac*DMAX(fabs(m_M->m_y->m_varVal[iVar]), m_M->m_tolerance->m_atol[iVar]) );
#endif
          m_M->m_convergance->m_growing = true;
          
          break;
        } 
      } 
    } 
  }
  else{
    if(m_M->m_index->m_isHighIndex){ 
      for(i=0;i<m_M->m_nActiveEqns;i++){ // KAB added active
        iVar = m_M->m_ActiveVars[i];
        if(m_M->m_index->m_daeIndex[iVar] <= 1){
          if(fabs(m_M->m_K[m_nStages-1]->m_varVal[i])  > 
            m_M->m_convergance->m_gfac*DMAX(fabs(m_M->m_y->m_varVal[iVar]),m_M->m_tolerance->m_atol[0])){ 

#if 0
  ATLTRACE( "\nnew_y%e", fabs(m_M->m_K[m_nStages-1]->m_varVal[i]) );
  ATLTRACE( "\nmax_y%e", m_M->m_convergance->m_gfac*DMAX(fabs(m_M->m_y->m_varVal[iVar]), m_M->m_tolerance->m_atol[iVar]) );
#endif

            m_M->m_convergance->m_growing = true;
            
            break;
          } 
        } 
      }			
    }
    else{
      for(i=0;i<m_M->m_nActiveEqns;i++){ // KAB added active
        iVar = m_M->m_ActiveVars[i];
        if(fabs(m_M->m_K[m_nStages-1]->m_varVal[i])  > 
          m_M->m_convergance->m_gfac*DMAX(fabs(m_M->m_y->m_varVal[iVar]),m_M->m_tolerance->m_atol[0])){ 

#if 0
  ATLTRACE( "\nnew_y%e", fabs(m_M->m_K[m_nStages-1]->m_varVal[i]) );
  ATLTRACE( "\nmax_y%e", m_M->m_convergance->m_gfac*DMAX(fabs(m_M->m_y->m_varVal[iVar]), m_M->m_tolerance->m_atol[iVar]) );
#endif

          m_M->m_convergance->m_growing = true;
          
          break;
        } 
      } 
    } 
  } 
  
  if(!m_M->m_convergance->m_growing){
    if(m_M->m_convergance->m_newtonIterationIndex == 1 ){// If first iteration 
      delta_K_norm = 0.0;
      for(k=0;k<m_nStages;k++)
      {
        delta_K_norm += scaledNorm(m_M->m_K[k]->m_varDeltaVal);
      }
      u = sqrt(delta_K_norm/(m_nStages*m_M->m_nActiveEqns)); // KAB added active
      m_M->m_convergance->m_curRate = m_M->m_convergance->m_initialRate;
      m_M->m_convergance->m_exact = (u == 0.0e0);
      m_M->m_convergance->m_solved = m_M->m_convergance->m_exact;
    }
    else if(m_M->m_convergance->m_newtonIterationIndex > 1){
      up = u;
      delta_K_norm = 0.0;
      for(k=0;k<m_nStages;k++) 
      {
        delta_K_norm += scaledNorm(m_M->m_K[k]->m_varDeltaVal);
      }
      u = sqrt(delta_K_norm/(m_nStages*m_M->m_nActiveEqns));  // KAB added active
      m_M->m_convergance->m_curRate = pow(m_M->m_convergance->m_curRate,m_M->m_convergance->m_theta)
        * pow(u/up,1-m_M->m_convergance->m_theta);

      y_norm = scaledNorm(m_M->m_y->m_varVal);
      y_norm = sqrt(y_norm/m_M->m_nActiveEqns); // KAB added active
      if(m_M->m_convergance->m_curRate >= m_M->m_convergance->m_gamma)
        m_M->m_convergance->m_diverged = true;
      else if(
        (u*m_M->m_convergance->m_curRate < (1.e0-m_M->m_convergance->m_curRate)*m_M->m_convergance->m_tau)
        || 
        (u < m_M->m_convergance->m_kappa*m_M->m_convergance->m_uround*y_norm)
        )
        m_M->m_convergance->m_solved = true;
      else if(
        (m_M->m_convergance->m_newtonIterationIndex 
        == m_M->m_convergance->m_newtonIterationMaxIndex)
        || 
        u * pow(m_M->m_convergance->m_curRate,
        (m_M->m_convergance->m_newtonIterationMaxIndex
        -m_M->m_convergance->m_newtonIterationIndex)) 			
        > ( m_M->m_convergance->m_tau * (1.0e0-m_M->m_convergance->m_curRate) )
        )
        m_M->m_convergance->m_slow = true;
    }
  }
  m_M->m_convergance->m_ready = m_M->m_convergance->m_growing ||
    m_M->m_convergance->m_diverged	 ||
    m_M->m_convergance->m_slow     ||
    m_M->m_convergance->m_solved   ||
    m_M->m_convergance->m_exact;

#if 0
  ATLTRACE("\nu\t%e", u);
#endif

  return true;
}


bool  CIsStepper::initStageVars()
{
  long ks,kn,iVar;

  if (!m_M->m_K)
  {
    m_M->m_K = new VarInfo*[m_nStages];
    for (ks = 0; ks < m_nStages; ks++)
      m_M->m_K[ks] = new VarInfo(m_M->m_nActiveVars);

    for(ks=0;ks<m_nStages;ks++)
    {
      for(kn=0;kn<m_M->m_nActiveVars;kn++) // KAB added active
      {
        iVar = m_M->m_ActiveVars[kn];
        m_M->m_K[ks]->m_varVal[kn] = m_M->m_y->m_varVal[iVar];
        m_M->m_K[ks]->m_varDotVal[kn] = m_M->m_y->m_varDotVal[iVar];
      }
    }
  }

  return true;
}

bool	CIsStepper::updateStageVars()
{
  int nEqns = m_M->m_nActiveEqns;
  int incx = 1;
  int incy = 1;
  double scale = 1.0;
  long ks;

  // Computes Y and YDot using delta(Y) and delta(YDot)
  for(ks=0;ks<m_nStages;ks++)
  {
    DAXPY(&nEqns, &scale, m_M->m_K[ks]->m_varDeltaVal, &incx, m_M->m_K[ks]->m_varVal, &incy);
    DAXPY(&nEqns, &scale, m_M->m_K[ks]->m_varDeltaDotVal, &incx, m_M->m_K[ks]->m_varDotVal, &incy);
  }
  return false;
}



bool	CIsStepper::computeLocalErrorEstimate(){
  
  long ks,kn,iVar;
  double  errorEstimate,estimatedExponent;
  double *aux;
  // TODO: the following static variables must become a class variable
  static bool successivelyRejected;
  static double lastErrorEstimate,rejectedStepSize,rejectedErrorEstimate; // Keep between calls
  double dsinv;

  if (!m_M->m_K) initStageVars();

  // Calculate residuals
  aux = (double*) new double[m_M->m_nActiveEqns]; // KAB added active
  for(kn=0;kn<m_M->m_nActiveEqns;kn++) // KAB added active
    aux[kn]=-B0*m_M->m_y->m_varDotVal[m_M->m_ActiveVars[kn]];
  
  for(ks=0;ks<m_nStages;ks++){
    for(kn=0;kn<m_M->m_nActiveEqns;kn++) // KAB added active
      aux[kn] += V[ks] * m_M->m_K[ks]->m_varDotVal[kn];
  }
  dsinv=1E0/D[m_nStages-1];
  for(kn=0;kn<m_M->m_nActiveEqns;kn++) // KAB added active
    aux[kn]=dsinv*aux[kn];
  
  m_M->m_report->m_ierr = false;
  /*
  m_M->m_fcn(m_M->m_nActiveEqns, // m_M->m_ierr is also used in control routine to adjust step size
  m_M->m_time->m_curVal+m_M->m_step->m_curVal,
  m_M->m_K[m_nStages-1]->m_varVal,	//  this should be y(n+1)?
  aux,
  m_M->m_y->m_residualVal,	
  m_M->m_report->m_ierr); 
  */

#if 0 // timing test for residuals
  double startTime = ((double)clock() / CLOCKS_PER_SEC);
  for (long i = 0; i < 100000; i++)
  {
#endif

#if 1
  m_M->iDirectGetAllResiduals(
    m_M->m_time->m_curVal+m_M->m_step->m_curVal,
    m_M->m_K[m_nStages-1]->m_varVal,
    aux,
    m_M->m_y->m_residualVal,
    m_M->m_report->m_ierr,
    m_M->m_realParameters,
    m_M->m_integerParameters);
#endif

#if 0
  m_M->iGetAllResiduals(
    m_M->m_time->m_curVal+m_M->m_step->m_curVal,
    m_M->m_K[m_nStages-1]->m_varVal,
    aux,
    m_M->m_y->m_residualVal,
    m_M->m_report->m_ierr,
    m_M->m_realParameters,
    m_M->m_integerParameters);
#endif

#if 0 // end of timing test for residuals
  }
  double endTime = ((double)clock() / CLOCKS_PER_SEC);
  ATLTRACE("\n%f", endTime - startTime);
#endif

#if 0
  bool bPrint = false;
  if (bPrint)
  {
    ATLTRACE("\nresiduals:\n");
    for (long i = 0; i < m_M->m_nActiveVars; i++)
      ATLTRACE("\n%d\t%e",i, m_M->m_y->m_residualVal[i]);
  }
#endif

#if 0
  ATLTRACE("\ny:\n");
  for (long i = 0; i < m_M->m_nActiveVars; i++)
    ATLTRACE("\n%d\t%e",i, m_M->m_K[m_nStages-1]->m_varVal[i]);

  ATLTRACE("\nydot:\n");
  for (i = 0; i < m_M->m_nActiveVars; i++)
    ATLTRACE("\n%d\t%e",i, aux[i]);
  
#endif
  
  m_M->m_report->m_functionCalls++;
  if (m_M->m_report->m_ierr) return false;

  m_M->m_iterationMatrix[m_nStages-1]->SolveEquation(m_M->m_y->m_residualVal);
#if 0
    for (i = 0; i < m_M->m_nActiveEqns; i++)
      ATLTRACE("\n%e",m_M->m_y->m_residualVal[i]);
#endif
  
  m_M->m_report->m_Substitutions++;
  for(kn=0;kn<m_M->m_nActiveEqns;kn++) // KAB added active
    m_M->m_y->m_residualVal[kn]=- m_M->m_step->m_curVal*D[m_nStages-1]*m_M->m_y->m_residualVal[kn];
  
  errorEstimate=scaledNorm(m_M->m_y->m_residualVal);

  errorEstimate=sqrt(errorEstimate/m_M->m_nActiveEqns); // KAB added active
  if (errorEstimate < 1E0){
    if (errorEstimate == 0.E0)
      m_M->m_step->m_predictedVal = m_M->m_step->m_maxChangeFactor*m_M->m_step->m_curVal;
    else if ((m_M->m_time->m_curIteration==0) || successivelyRejected) 
      m_M->m_step->m_predictedVal = m_M->m_step->m_updateFormulaCoeff*m_M->m_step->m_curVal*pow(errorEstimate,(-0.2E0));
    else
      m_M->m_step->m_predictedVal = m_M->m_step->m_updateFormulaCoeff*pow(m_M->m_step->m_curVal,2)
      / m_M->m_step->m_lastVal
      * pow((lastErrorEstimate/pow(errorEstimate,2)),(0.2E0));
    
    for(kn=0;kn<m_M->m_nActiveVars;kn++){ // KAB added active
      iVar = m_M->m_ActiveVars[kn];
      m_M->SetLastVariable(kn, m_M->m_y->m_varVal[iVar]);
      m_M->SetVariable(kn, m_M->m_K[m_nStages-1]->m_varVal[kn]);
      m_M->SetLastDerivative(kn, m_M->m_y->m_varDotVal[iVar]);
      m_M->SetDerivative(kn, m_M->m_K[m_nStages-1]->m_varDotVal[kn]);
#if 0
      ATLTRACE("\n[%d]:\t%e\t%e",kn,m_M->m_K[m_nStages-1]->m_varVal[kn],m_M->m_K[m_nStages-1]->m_varDotVal[kn]);
#endif
    }
    for(ks=0;ks<m_nStages;ks++)
      for(kn=0;kn<m_M->m_nActiveVars;kn++) // KAB added active
        m_M->m_K[ks]->m_varLastDotVal[kn] = m_M->m_K[ks]->m_varDotVal[kn];

    // m_M->m_time->m_curVal += m_M->m_step->m_curVal;
    m_M->SetTime(m_M->m_time->m_curVal + m_M->m_step->m_curVal);
    /*
    if (fabs(m_M->m_time->m_endVal-m_M->m_time->m_curVal) 
    < 10E0* m_M->m_convergance->m_uround*fabs(m_M->m_time->m_curVal))
    m_M->m_time->m_curVal = m_M->m_time->m_endVal;
    */   
    m_M->m_step->m_lastVal = m_M->m_step->m_curVal;
    lastErrorEstimate = errorEstimate;
    successivelyRejected = false;
    m_M->m_Jac->m_dataUpToDate = false;
  }
  else{
    if ((m_M->m_time->m_curIteration>0) && successivelyRejected){
      double denominator = log10(m_M->m_step->m_curVal/rejectedStepSize);
      if (denominator == 0.0) 
      {
        estimatedExponent = 5.0;
      }
      else
      {
        double temp = log10(errorEstimate/rejectedErrorEstimate)/denominator;
        temp = DMAX(m_M->m_step->m_updateFormulaMinExponent,temp);
        estimatedExponent=DMIN(5.E0,temp);
      }
      m_M->m_step->m_predictedVal=m_M->m_step->m_updateFormulaCoeff*m_M->m_step->m_curVal*
        pow(errorEstimate,(-1E0/estimatedExponent));
    }
    else
      m_M->m_step->m_predictedVal=m_M->m_step->m_updateFormulaCoeff*m_M->m_step->m_curVal*
      pow(errorEstimate,(-0.2E0));
    rejectedStepSize = m_M->m_step->m_curVal;
    rejectedErrorEstimate = errorEstimate;
    successivelyRejected = true;
    m_M->m_report->m_errorRejectedSteps++;
  }
  if(aux) delete aux;
  return true;
}


// tolerance used in scaledNorm (recalculated after each successful Newton step)
void CIsStepper::calcNormTolerance()
{
  long i;
  int nEqns = (int) m_M->m_nActiveEqns;
  int incx = 1;
  int incy = 1;
  double scale = 1.0;

  if (!m_normTolerance)
  {
    m_normTolerance = new double[nEqns];
    m_vNorm = new double[nEqns];
  }

  for (i = 0; i < nEqns; i++) m_normTolerance[i] = fabs(m_M->m_y->m_varVal[i]);

  if (m_M->m_tolerance->m_scalar)
  {
    DSCAL(&nEqns, &m_M->m_tolerance->m_rtol[0], m_normTolerance, &incx);
    for (i = 0; i < nEqns; i++) m_normTolerance[i] += m_M->m_tolerance->m_atol[0];
  }
  else
  {
    for (i = 0; i < nEqns; i++) m_normTolerance[i] *= m_M->m_tolerance->m_rtol[i];
    DAXPY(&nEqns, &scale, m_M->m_tolerance->m_atol, &incx, m_normTolerance, &incy);
  }

#if 0 // testing scaled norm
  for (i = 0; i < nEqns; i++) 
  {
    if (m_normTolerance[i] < 1.0e-10)
      _ASSERTE(0);
  }
#endif

}



// for high index problems only (recalculated when step size changes)
void CIsStepper::calcNormHighIndexScale()
{
  long i;
  long nEqns = m_M->m_nActiveEqns;

  if (!m_normHighIndexScale)
    m_normHighIndexScale = new double[nEqns];

  for (i = 0; i < nEqns; i++) 
    m_normHighIndexScale[i] = pow(m_M->m_step->m_curVal, m_M->m_index->m_daeIndex[i] - 1.0);
}


double	CIsStepper::scaledNorm(double *x)
{  
  long i;
  double sNorm;
  int nEqns = (int) m_M->m_nActiveEqns;
  int incx = 1;


  // the following line crashes for some reason
  //VDDIV(&nEqns, x, m_normTolerance, m_vNorm);
  for (i = 0; i < nEqns; i++) m_vNorm[i] = x[i] / m_normTolerance[i];

  if (m_M->m_index->m_isHighIndex)
    for (i = 0; i < nEqns; i++) m_vNorm[i] *= m_normHighIndexScale[i];

  sNorm = pow( DNRM2(&nEqns, m_vNorm, &incx), 2.0 );

  return sNorm;
}



#if 0 // old slow version of scaledNorm
double	CIsStepper::scaledNorm(double *x)
{
  
  long i,iVar;
  double sNorm, temp1, temp2;
  short* x_index = m_M->m_index->m_daeIndex;
  bool bActiveVar = true;

  sNorm = 0.0;
  if(m_M->m_index->m_isHighIndex){
    if(m_M->m_tolerance->m_scalar){
      for(i=0;i<m_M->m_nActiveEqns;i++){ // KAB added active
        iVar = m_M->m_ActiveVars[i];
        temp1 = pow(m_M->m_step->m_curVal,x_index[iVar]-1.0);
        if (bActiveVar)
          temp2 = x[i]/(m_M->m_tolerance->m_atol[0]+m_M->m_tolerance->m_rtol[0]*fabs(m_M->m_y->m_varVal[iVar]));
        else
          temp2 = x[iVar]/(m_M->m_tolerance->m_atol[0]+m_M->m_tolerance->m_rtol[0]*fabs(m_M->m_y->m_varVal[iVar]));

        sNorm += pow(temp1*temp2, 2.0);
      }
    }
    else{
      for(i=0;i<m_M->m_nActiveEqns;i++){ // KAB added active
        iVar = m_M->m_ActiveVars[i];
        temp1 = pow(m_M->m_step->m_curVal,x_index[iVar]-1.0);
        if (bActiveVar)
          temp2 = x[i]/(m_M->m_tolerance->m_atol[iVar]+m_M->m_tolerance->m_rtol[iVar]*fabs(m_M->m_y->m_varVal[iVar]));
        else
          temp2 = x[iVar]/(m_M->m_tolerance->m_atol[iVar]+m_M->m_tolerance->m_rtol[iVar]*fabs(m_M->m_y->m_varVal[iVar]));

        sNorm += pow(temp1*temp2, 2.0);
      }
    }
  }
  else{
    if(m_M->m_tolerance->m_scalar){
      for(i=0;i<m_M->m_nActiveEqns;i++){ // KAB added active
        iVar = m_M->m_ActiveVars[i];
        if (bActiveVar)
          temp2 = x[i]/(m_M->m_tolerance->m_atol[0]+m_M->m_tolerance->m_rtol[0]*fabs(m_M->m_y->m_varVal[iVar]));
        else
          temp2 = x[iVar]/(m_M->m_tolerance->m_atol[0]+m_M->m_tolerance->m_rtol[0]*fabs(m_M->m_y->m_varVal[iVar]));

        sNorm += pow(temp2, 2.0);
      }
    }
    else{
      for(i=0;i<m_M->m_nActiveEqns;i++){ // KAB added active
        iVar = m_M->m_ActiveVars[i];
        if (bActiveVar)
          temp2 = x[i]/(m_M->m_tolerance->m_atol[iVar]+m_M->m_tolerance->m_rtol[iVar]*fabs(m_M->m_y->m_varVal[iVar]));
        else
          temp2 = x[iVar]/(m_M->m_tolerance->m_atol[iVar]+m_M->m_tolerance->m_rtol[iVar]*fabs(m_M->m_y->m_varVal[iVar]));

        sNorm += pow(temp2, 2.0);
      }
    }
  }
  return sNorm;
}
#endif

void CIsStepper::EstimateInitialStepSize(int nVars,double* yDot, double t0, bool bReverse, double* hEst, double* rPar, long* iPar)
{
  double hDef = 1.0e-5;
  double zeta = 0.5;
  double fH = 1.e-5;
  int incx = 1;

  // *hEst = DMIN(hDef,fH*fabs(tEnd - t0));
  *hEst = hDef;
  double norm_yDot = 0.0;

/* replaced with DNRM2
  for(long i = 0; i<nVars;i++) 
  {
    y = yDot[m_M->m_ActiveVars[i]];
    norm_yDot += y*y;
  }
  norm_yDot = sqrt(norm_yDot);
*/

  norm_yDot = DNRM2(&nVars, yDot, &incx);

  if(norm_yDot > 1.e-30){
    if(norm_yDot > (zeta / *hEst)) *hEst = zeta/norm_yDot;
    // *hEst = SIGN((*hEst), (tEnd-t0));
    *hEst = bReverse ? -fabs(*hEst) : fabs(*hEst);
  }
  else{
    //cout << "Zero initial derivative\n";
    *hEst = 1.0e-10; //1.e-30;  
  }

  // KAB patch
  if (*hEst < 1.0e-10) *hEst = 1.0e-10;

#if 0
  for (i = 0; i < m_M->m_nActiveVars; i++)
    ATLTRACE("\n%e", yDot[i]);
#endif

}


void CIsStepper::OnEvent(bool bStateEvent)
{
  // reset the eventStepCount to the current stepper calls count to enable the 
  // eventChangeFactor 
  m_M->m_step->m_eventStepCount = m_M->m_report->m_StepperCalls;
  m_M->m_step->m_eventChangeFactorApplied = false;

  // estimate and initialize the step size
  EstimateInitialStepSize(
    m_M->m_nActiveVars,
    m_M->m_y->m_varDot_init,
    m_M->m_time->m_initVal,
    m_M->m_time->m_reverse,
    &(m_M->m_step->m_initVal), 
    m_M->m_realParameters,
    m_M->m_integerParameters);
  
  if (m_M->m_step->m_lastVal == 0.0 || m_M->m_step->m_LUVal == 0.0)
    m_M->m_step->m_LUVal = m_M->m_step->m_lastVal = m_M->m_step->m_initVal;

  SetStepSize(m_M->m_step->m_initVal);

  // reinitialize the sparse iteration matrix (to handle structural changes after events)
  if (bStateEvent)
    m_sparseIMReinitialize = true;
}



void CIsStepper::dump(_TCHAR* filename)
{
  ofstream fs;
  long i, j, sp, iter;
  MatInfo* mat;
  CIsDaeEsoCImpl* pEso = static_cast<CIsDaeEsoCImpl*> (m_M);
  SAFEARRAY* psaEqnNames = NULL;
  BSTR* EqnNames = NULL;
  SAFEARRAY* psaVarNames = NULL;
  BSTR* varNames = NULL;
  USES_CONVERSION;

  fs.open(W2CA(filename), ios::out, filebuf::openprot);


  fs << "\ntime:" << m_M->m_time->m_curVal << "\n";

  fs << "\nEquation names\n";
  pEso->GetEqnNames(&psaEqnNames);
  SafeArrayAccessData(psaEqnNames, (void HUGEP* FAR*)& EqnNames);
  for (i = 0; i < m_M->m_nActiveEqns; i++)
  {
    if (EqnNames[i])
      fs << i << "\t" << W2CA(EqnNames[m_M->m_ActiveEqns[i]]) << "\n";
    else
      fs << i << "\n";
  }
  SafeArrayUnaccessData(psaEqnNames);
  SafeArrayDestroy(psaEqnNames);

  fs << "\nVariable names\n";
  pEso->GetVarNames(&psaVarNames);
  SafeArrayAccessData(psaVarNames, (void HUGEP* FAR*)& varNames);
  for (i = 0; i < m_M->m_nActiveEqns; i++)
  {
    if (varNames[i])
      fs << i << "\t" << W2CA(varNames[i]) << "\n";
    else
      fs << i << "\n";
    }
  fs << "\n";
  SafeArrayUnaccessData(psaVarNames);
  SafeArrayDestroy(psaVarNames);


  for (iter = 0; iter < 2; iter++)
  {
    if (iter == 0) 
    {
      mat = m_M->m_Jac;
      fs << "\nJacobian matrix\n";
    }
    else 
    {
      mat = m_M->m_Mass;
      fs << "\nMass matrix\n";
    }
    for (i = 0; i < mat->m_nRows; i++)
    {
      sp = mat->m_spRowPage[i];
      fs << "\n[" << i << "]";
      for (j = 0; j < mat->m_cNZCols[i]; j++)
        fs << mat->m_ColIndices[sp+j] << ":" << mat->m_compact_value[sp+j] << "\t";    
    }
  }

  fs << "\nresiduals\n";
  for (i = 0; i < m_M->m_nActiveEqns; i++)
    fs << i << "\t" << m_udys[i] << "\n";

  fs << "\nx\n";
  for (i = 0; i < m_M->m_nActiveEqns; i++)
    fs << i << "\t" << m_M->m_y->m_varVal[i] << "\n";

  fs << "\nxdot\n";
  for (i = 0; i < m_M->m_nActiveEqns; i++)
    fs << i << "\t" << m_M->m_y->m_varDotVal[i] << "\n";

  fs.close();
}

bool CIsStepper::Load(FILE* fs)
{
  const long m_schema = 1;
  const long m_classId = 1008;

  long classId;
  long schema;
  bool bRet = false;

  READ_SCALAR( classId )
  if (classId != m_classId) { _ASSERTE(0); return false; }

  READ_SCALAR( schema )

  switch (schema)
  {
  case 1:
    m_sparseIMReinitialize = true;
    bRet = m_M->Load(fs);
    SetStepSize(m_M->m_step->m_curVal);
    bRet = true;
    break;

  }

  return bRet;
}

void CIsStepper::Save(FILE* fs)
{
  const long m_schema = 1;
  const long m_classId = 1008;

  WRITE_SCALAR( m_classId )
  WRITE_SCALAR( m_schema )

  m_M->Save(fs);
}