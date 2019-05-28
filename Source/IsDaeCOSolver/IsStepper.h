// IsStepper.h: interface for the CIsStepper class.
//
//////////////////////////////////////////////////////////////////////

// #if !defined(AFX_ISSTEPPER_H__BDF831D8_3309_11D4_AFDA_00C04F680D9D__INCLUDED_)
// #define AFX_ISSTEPPER_H__BDF831D8_3309_11D4_AFDA_00C04F680D9D__INCLUDED_

// #if _MSC_VER > 1000
// #pragma once
// #endif // _MSC_VER > 1000

class CIsDaeEsoBase;
class CIsDaeSolver;
class CompRow_Mat_double;
class CompRow_ILUPreconditioner_double;
class MV_Vector_double;

#define _NOT_USING_BLAS3 0

class CIsStepper  
{
public:
	CIsStepper();
	virtual ~CIsStepper();

  HRESULT Step();
  void OnEvent(bool bStateEvent);
  void GetMaxStepSize(double* hmax);
  void SetMaxStepSize(double hmax);
  void SetStepSize(double hnew);

  bool Load(FILE* fs);
  void Save(FILE* fs);

  CIsDaeEsoBase* m_M;   // current Eso

  // for debugging purposes
  void dump(_TCHAR* filename);

protected:

	void	initAlgorithmMatrices();
	bool	updateJacobians();
	bool	formIterationMatrix();
  bool  initSparseIterationMatrix();
  bool	decomposeIterationMatrix();
	bool	performNewtonIteration();
	bool	performIterationControl();
	bool	predictNewtonStart();
  bool  calcPredictNewtonStartVars();
  bool  initStageVars();
	bool	updateStageVars();
	bool	computeVariations();
	bool	checkConvergence();
	bool	computeLocalErrorEstimate();
  double	scaledNorm(double *x);
  void calcNormHighIndexScale();
  void calcNormTolerance();
	void EstimateInitialStepSize(int nVars,double* yDot, double t0, bool bReverse, double* hEst, double* rPar, long* iPar);


protected:

	// Algorithm Matrices
	double B0;
	double C[4];
	double A[4][4];
	double D[4];
	double B[4][4];

#if _NOT_USING_BLAS3
	// before BLAS3
  double Q[4][4];
	double QINV[4][4];
#else
  // after BLAS3
  double Q[16];
	double QINV[16];
#endif

	double V[4];
	double UINV[4][4];

  // maximum step size constraint
  double m_MaxStepSize;

  // sparse iteration matrix variables
  long m_dJacIMMap;
  long m_dMassIMMap;
  long m_nJacIMMap;
  long m_nMassIMMap;
  long** m_JacIMMap;
  long** m_MassIMMap;
  bool m_sparseIMReinitialize;

  long m_nStages;


  // compute variations variables
  long* m_info;
  long* m_ierrs;

#if _NOT_USING_BLAS3
  // before BLAS3
  double** m_tgs;
  double** m_udys;
  double** m_tudys;
#else
  // after BLAS3
  double* m_tgs;
  double* m_udys;
  double* m_tudys;
  double* m_temp_udys;
#endif

  double* m_tempVecx;
  double* m_tempVecy;

  // scaled norm variables
  double* m_normTolerance;
  double* m_normHighIndexScale;
  double* m_vNorm;

  // predict Newton start variables
  double** m_v;
  double** m_w;
  double* m_diff;


  // BLAS3
  char m_cv_transa;
	char m_cv_transb;
	int m_cv_lda;     // m_nStages;
  int m_cv_ldb;     // m_nActiveEqns
  int m_cv_ldc;     // m_nStages
  int m_cv_m;       // m_nStages;
  int m_cv_n;       // m_nActiveEqns
  int m_cv_k;       // m_nStages
	double m_cv_alpha;
	double m_cv_beta;
  //End of BLAS3


};

// #endif // !defined(AFX_ISSTEPPER_H__BDF831D8_3309_11D4_AFDA_00C04F680D9D__INCLUDED_)
