// IsNlaSolver.cpp : Implementation of CIsNlaSolver
#include "stdafx.h"
#include "ISDaeCOSolver.h"
#include "IsNlaSolver.h"
#include <math.h>
#include <iostream.h>
#include "ConsistentInitialization.h"
#include "OnDaeCOSolverMacros.h"
#include "MatInfo.h"

#if 0
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#endif

double fmin(double*);

#define DMAX(a,b) (dblArg1=(a),dblArg2=(b),(dblArg1) > (dblArg2) ?  (dblArg1) : (dblArg2))
#define DMIN(a,b) (dblArg1=(a),dblArg2=(b),(dblArg1) < (dblArg2) ?  (dblArg1) : (dblArg2))
#define LMAX(a,b) (longArg1=(a),longArg2=(b),(longArg1) > (longArg2) ?  (longArg1) : (longArg2))
#define LMIN(a,b) (longArg1=(a),longArg2=(b),(longArg1) < (longArg2) ?  (longArg1) : (longArg2))
#define IMAX(a,b) (intArg1=(a),intArg2=(b),(intArg1) > (intArg2) ?  (intArg1) : (intArg2))
#define IMIN(a,b) (intArg1=(a),intArg2=(b),(intArg1) < (intArg2) ?  (intArg1) : (intArg2))
#define SQR(x) x*x
#define SIGN(a,b) ((b) >= 0.0 ? fabs(a) : -fabs(a))

#define PRINTVEC(m_xvec, size) for(ij=0;ij<size;ij++) cerr << m_xvec[ij] << "\t";cerr << "\n";

#define MAXITS 20000
#define EPS  1e-10          // 1.0e-7
#define TOLF 1e-10          // 1.0e-4
#define TOLX EPS
#define STPMX 1000.0
#define TOLMIN 1e-9         // 1.0e-6



/////////////////////////////////////////////////////////////////////////////
// CIsNlaSolver

CIsNlaSolver::CIsNlaSolver()
{
  m_pEso = NULL;
  m_psax = NULL;
  m_psaf = NULL;
  m_nVars = 0;
  m_xvec = NULL;
  m_fvec = NULL;
  ij = 0;

  m_nNumJac = 0;
  m_nEsoJac = 0;
  m_vNumJac = NULL;
  m_vNumJacVals = NULL;
  m_psaEsoJac = NULL;
  m_vEsoJac = NULL;
  m_psaEsoJacVals = NULL;
  m_vEsoJacVals = NULL;
  m_JacStruct = NULL;
  m_Jac = NULL;
}

CIsNlaSolver::~CIsNlaSolver()
{
  m_pEso = NULL;
  if (m_psax)
  {
    SafeArrayUnaccessData(m_psax);
    SafeArrayDestroy(m_psax);
    m_psax = NULL;
    m_xvec = NULL;
  }

  if (m_psaf)
  {
    SafeArrayUnaccessData(m_psaf);
    SafeArrayDestroy(m_psaf);
    m_psaf = NULL;
    m_fvec = NULL;
  }

  m_nVars = 0;
  ij = 0;
  m_nNumJac = 0;
  m_nEsoJac = 0;

  DESTROY_VECTOR(m_vNumJac)
  DESTROY_VECTOR(m_vNumJacVals)
  
  if (m_psaEsoJac)
  {
    SafeArrayUnaccessData(m_psaEsoJac);
    SafeArrayDestroy(m_psaEsoJac);
    m_psaEsoJac = NULL;
    m_vEsoJac = NULL;
  }

  if (m_psaEsoJacVals)
  {
    SafeArrayUnaccessData(m_psaEsoJacVals);
    SafeArrayDestroy(m_psaEsoJacVals);
    m_psaEsoJacVals = NULL;
    m_vEsoJacVals = NULL;
  }

  DESTROY_MEMBER(m_JacStruct)
  DESTROY_MEMBER(m_Jac)
}


STDMETHODIMP CIsNlaSolver::InterfaceSupportsErrorInfo(REFIID riid)
{
	static const IID* arr[] = 
	{
		&IID_IIsNlaSolver
	};
	for (int i=0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		if (InlineIsEqualGUID(*arr[i],riid))
			return S_OK;
	}
	return S_FALSE;
}

STDMETHODIMP CIsNlaSolver::Solve()
{
  HRESULT hr = S_OK;

  if (!m_pEso)
    return E_FAIL;

  long check[] = { 0 };
  m_pEso->GetNumVars(&m_nVars);
  m_psax = SafeArrayCreateVector(VT_R8, 0, m_nVars);
  m_psaf = SafeArrayCreateVector(VT_R8, 0, m_nVars);
  SafeArrayAccessData(m_psax, (void HUGEP* FAR*)& m_xvec);
  SafeArrayAccessData(m_psaf, (void HUGEP* FAR*)& m_fvec);

  m_pEso->GetAllVariables(&m_psax);

  InitJacStruct();
  InitJacValues();

  long nRetries = 0;
  long nExceptions = 0;
  do 
  { 
    //try
    //{
      broydn(check); 
    //}
    //catch ( ... )
    //{
    //  nExceptions++;
#if 0
    //  ATLTRACE("\nbroydn exception: %d\n", nExceptions);
#endif
    //}

#if 0
    ATLTRACE("\nbroydn try: %d\n", nRetries);
#endif

  } while (++nRetries < 10 && *check);

#if 0
  long i;
  char buff[256];
  sprintf(buff, "\nx  "); ATLTRACE(buff);
  for (i = 0; i < m_nVars; i++) 
  {
    sprintf(buff, "\t%e", m_xvec[i]); 
    ATLTRACE(buff);
  }

  sprintf(buff, "\nres"); ATLTRACE(buff);
  for (i = 0; i < m_nVars; i++) 
  {
    sprintf(buff, "\t%e", m_fvec[i]); 
    ATLTRACE(buff);
  }
#endif

  m_pEso->SetAllVariables(&m_psax);

  SafeArrayUnaccessData(m_psax);
  SafeArrayUnaccessData(m_psaf);
  SafeArrayDestroy(m_psax);
  SafeArrayDestroy(m_psaf);

  m_psax = NULL;
  m_psaf = NULL;
  m_xvec = NULL;
  m_fvec = NULL;

  return hr;
}

void CIsNlaSolver::broydn(long *check)
{

	long i,its,j,k,restrt,sing,skip;
	double den,f,fold,stpmax,sum,temp,test;

	double* c = NULL;
  double* d = NULL;
  double* fvcold = NULL;
	double* g = NULL;
  double* p = NULL;
  double* s = NULL;
  double* t = NULL;
  double* w = NULL;
  double* xold = NULL;
  double** qt = NULL;
  double** jac_buff = NULL;
  // double** r = NULL;

	c = new double[m_nVars];
  d = new double[m_nVars];
  fvcold = new double[m_nVars];
	g = new double[m_nVars];
  p = new double[m_nVars];
  s = new double[m_nVars];
  t = new double[m_nVars];
  w = new double[m_nVars];
  xold = new double[m_nVars];

  qt = new double*[m_nVars];
  // r = new double*[m_nVars];
	for(i=0;i<m_nVars;i++){
    qt[i] = new double[m_nVars];
    // r[i] = new double[m_nVars];
	}

  // initialize all variables to zero
  for (i = 0; i < m_nVars; i++)
  {
	  c[i] = 0.0;
    d[i] = 0.0;
    fvcold[i] = 0.0;
	  g[i] = 0.0;
    p[i] = 0.0;
    s[i] = 0.0;
    t[i] = 0.0;
    w[i] = 0.0;
    xold[i] = 0.0;
    for (j = 0; j < m_nVars; j++)
    {
      qt[i][j] = 0.0;
      // r[i][j] = 0.0;
    }
  }

	f=fmin(m_xvec);
	test=0.0;
	for (i=0;i<m_nVars;i++)
		if (fabs(m_fvec[i]) > test)test=fabs(m_fvec[i]);
		if (test<0.01*TOLF) 
    {
#if 0
      ATLTRACE("test<0.01*TOLF");
#endif
      goto FreeStuff;
    }
	for (sum=0.0,i=0;i<m_nVars;i++) sum += SQR(m_xvec[i]);
	stpmax=STPMX*DMAX(sqrt(sum),(double)m_nVars);
	restrt=1;
	for (its=1;its<=MAXITS;its++) {
		if (restrt) {
      UpdateJacobianValues();
			// fdjac(m_nVars,m_xvec,m_fvec,r);

			// qrdcmp(r,m_nVars,c,d,&sing);
      qrdcmp(m_Jac->m_data, m_nVars, c, d, &sing);
			if (sing) 
      {
#if 0
        ATLTRACE("\nsingular Jacobian in broydn\n");
        printMat(m_nVars, m_nVars, m_Jac->m_data);
#endif
        _ASSERTE(0);
        cerr << "singular Jacobian in broydn\n";
        goto FreeStuff;
      }
			for (i=0;i<m_nVars;i++) {
				for (j=0;j<m_nVars;j++) qt[i][j]=0.0;
				qt[i][i]=1.0;
			}
			for (k=0;k<m_nVars-1;k++) {
				if (c[k]) {
					for (j=0;j<m_nVars;j++) {
						sum=0.0;
						for (i=k;i<m_nVars;i++)
            {
							// sum += r[i][k]*qt[i][j];
              sum += (m_Jac->m_data[i][k])*qt[i][j];
            }
						sum /= c[k];
						for (i=k;i<m_nVars;i++)
            {
							// qt[i][j] -= sum*r[i][k];
              qt[i][j] -= sum*(m_Jac->m_data[i][k]);
            }
					}
				}
			}
			for (i=0;i<m_nVars;i++) 
      {
				// r[i][i]=d[i];
        m_Jac->m_data[i][i]=d[i];
				// for (j=0;j<i;j++) r[i][j]=0.0;
        for (j=0;j<i;j++) m_Jac->m_data[i][j] = 0.0;
			}
		} else {
			for (i=0;i<m_nVars;i++) s[i]=m_xvec[i]-xold[i];
			for (i=0;i<m_nVars;i++) {
				// for (sum=0.0,j=i;j<m_nVars;j++) sum += r[i][j]*s[j];
        for (sum=0.0,j=i;j<m_nVars;j++) sum += m_Jac->m_data[i][j]*s[j];
				t[i]=sum;
			}
			skip=1;
			for (i=0;i<m_nVars;i++) {
				for (sum=0.0,j=0;j<m_nVars;j++) sum += qt[j][i]*t[j];
				w[i]=m_fvec[i]-fvcold[i]-sum;
				if (fabs(w[i]) >= EPS*(fabs(m_fvec[i])+fabs(fvcold[i]))) skip=0;
				else w[i]=0.0;
			}
			if (!skip) {
				for (i=0;i<m_nVars;i++) {
					for (sum=0.0,j=0;j<m_nVars;j++) sum += qt[i][j]*w[j];
					t[i]=sum;
				}
				for (den=0.0,i=0;i<m_nVars;i++) den += SQR(s[i]);
				for (i=0;i<m_nVars;i++) s[i] /= den;
				// qrupdt(r,qt,m_nVars,t,s);
        qrupdt(m_Jac->m_data,qt,m_nVars,t,s);
				for (i=0;i<m_nVars;i++) {
					// if (r[i][i] == 0.0) cerr << "r singular in broydn\n";
          if (m_Jac->m_data[i][i] == 0.0) cerr << "r singular in broydn\n";
					// d[i]=r[i][i];
          d[i]=m_Jac->m_data[i][i];
				}
			}
		}
		for (i=0;i<m_nVars;i++) {
			for (sum=0.0,j=0;j<m_nVars;j++) sum += qt[i][j]*m_fvec[j];
			g[i]=sum;
		}
		for (i=m_nVars-1;i>=0;i--) {
			// for (sum=0.0,j=0;j<=i;j++) sum += r[j][i]*g[j];
      for (sum=0.0,j=0;j<=i;j++) sum += (m_Jac->m_data[j][i])*g[j];
			g[i]=sum;
		}
		for (i=0;i<m_nVars;i++) {
			xold[i]=m_xvec[i];
			fvcold[i]=m_fvec[i];
		}
		fold=f;
		for (i=0;i<m_nVars;i++) {
			for (sum=0.0,j=0;j<m_nVars;j++) sum += qt[i][j]*m_fvec[j];
			p[i] = -sum;
		}
		// rsolv(r,m_nVars,d,p);
    rsolv(m_Jac->m_data,m_nVars,d,p);
    lnsrch(m_nVars,xold,fold,g,p,m_xvec,&f,stpmax,check);
		test=0.0;
		for (i=0;i<m_nVars;i++)
			if (fabs(m_fvec[i]) > test) test=fabs(m_fvec[i]);
		if (test < TOLF) 
    {
			*check=0;
#if 0
      ATLTRACE("\ntest < TOLF");
#endif
			goto FreeStuff;
		}
		if (*check) 
    {
			if (restrt) 
      {
#if 0
        ATLTRACE("\nrestrt");
#endif
        goto FreeStuff;
      }
			else 
      {
				test=0.0;
				den=DMAX(f,0.5*m_nVars);
				for (i=0;i<m_nVars;i++) 
        {
					temp=fabs(g[i])*DMAX(fabs(m_xvec[i]),1.0)/den;
					if (temp > test) test=temp;
				}
				if (test < TOLMIN) 
        {
#if 0
          ATLTRACE("\ntest < TOLMIN");
#endif
          goto FreeStuff;
        }
				else 
        {
          restrt=1;
        }
			}
		}
    else 
    {
			restrt=0;
			test=0.0;
			for (i=0;i<m_nVars;i++) 
      {
				temp=(fabs(m_xvec[i]-xold[i]))/DMAX(fabs(m_xvec[i]),1.0);
				if (temp > test) test=temp;
			}
			if (test < TOLX) 
      {
#if 0
        ATLTRACE("\ntest < TOLX");
#endif
        goto FreeStuff;
      }
		}
	}
	cerr << "MAXITS exceeded in broydn\n";
#if 0
  ATLTRACE("\nMAXITS exceeded in broydn\n");
#endif

FreeStuff:
	delete[] c;
  delete[] d;
  delete[] fvcold;
	delete[] g;
  delete[] p;
  delete[] s;
  delete[] t;
  delete[] w;
  delete[] xold;

	for(i=0;i<m_nVars;i++)
    if (qt[i]) delete[] qt[i];

  delete[] qt;

  if (jac_buff)
  {
    for (i = 0; i < m_nVars; i++) { if (jac_buff[i]) delete[] jac_buff[i]; }
    delete[] jac_buff;
    jac_buff = NULL;
  }

}
#undef MAXITS
#undef EPS
#undef TOLF
#undef TOLMIN
#undef TOLX
#undef STPMX


#define EPS 1.0e-4

void CIsNlaSolver::UpdateJacobianValues()
{
  long i, j;

  // update the jacobian values calculated by the ESO
  m_pEso->GetJacobianValues(&m_psaEsoJac, &m_psaEsoJacVals);
  
  // update the jacobian values calculated numerically
  UpdateNumericJacobians();

  for (i = 0; i < m_nVars; i++)
  {
    for (j = 0; j < m_nVars; j++) m_Jac->m_data[i][j] = 0.0;
  }

  // write the results of the above calculations back into the jacobian matrix
  for (i = 0; i < m_nEsoJac; i++)
    m_Jac->m_data[m_vEsoJac[2*i]][m_vEsoJac[2*i+1]] = m_vEsoJacVals[i];

  for (i = 0; i < m_nNumJac; i++)
    m_Jac->m_data[m_vNumJac[2*i]][m_vNumJac[2*i+1]] = m_vNumJacVals[i];

#if 0
  ATLTRACE("\n\n");
  for (i = 0; i < m_nVars; i++)
  {
    for (j = 0; j < m_nVars; j++)
      ATLTRACE("%e\t",m_Jac->m_data[i][j]);

    ATLTRACE("\n");
  }
#endif

}

void CIsNlaSolver::UpdateNumericJacobians()
{
	long i;
	double h,temp;
  long iEqn, iVar;
  double residual;

  for (i = 0; i < m_nNumJac; i++)
  {
    iEqn = m_vNumJac[2*i];
    iVar = m_vNumJac[2*i+1];
		temp = m_xvec[iVar];
		h=EPS*fabs(temp);
    if (h < 1.0e-266) h=EPS;
		m_xvec[iVar] = temp + h;
		h = m_xvec[iVar] - temp;
    m_pEso->GetResidual(iEqn, &m_psax, &residual);
		m_xvec[iVar] = temp;
    m_vNumJacVals[i] = (residual - m_fvec[i]) / h;
  }
}

HRESULT CIsNlaSolver::InitJacValues()
{
  long i, j;
  long Col, Row;
  Jac_Calc_Method CalcMethod;

  // clean out the jacobian variables and vectors
  DESTROY_MEMBER(m_Jac)
  DESTROY_VECTOR(m_vNumJac)
  DESTROY_VECTOR(m_vNumJacVals)
  if (m_psaEsoJac) 
  {
    SafeArrayUnaccessData(m_psaEsoJac);
    SafeArrayDestroy(m_psaEsoJac);
    m_psaEsoJac = NULL;
    m_vEsoJac = NULL;
  }
  
  if (m_psaEsoJacVals)
  {
    SafeArrayUnaccessData(m_psaEsoJacVals);
    SafeArrayDestroy(m_psaEsoJacVals);
    m_psaEsoJacVals = NULL;
    m_vEsoJacVals = NULL;
  }

  // initialize the jacobian variables and vectors
  // TODO: verify this change
  //m_Jac = new MatInfo(m_nVars, m_nVars, false, NULL); // KAB April 8, 2001
  // working around crash in qrupdt when it uses hard coded references to row 1
  m_Jac = new MatInfo(m_nVars+1, m_nVars+1, false, NULL); // KAB April 8, 2001
  m_Jac->m_form = FULL;
  m_Jac->Init();

  m_nNumJac = 0;
  m_nEsoJac = 0;
  for (i = 0; i < m_JacStruct->m_nColIndices; i++)
  {
    if (m_JacStruct->m_compact_data[i] == JCM_NUM)
      m_nNumJac++;
    else if (m_JacStruct->m_compact_data[i] != JCM_CONST)
      m_nEsoJac++;
  }

  if (m_nNumJac > 0)
  {
    m_vNumJac = new long[m_nNumJac * 2];
    m_vNumJacVals = new double[m_nNumJac];
  }

  if (m_nEsoJac > 0)
  {
    m_psaEsoJac = SafeArrayCreateVector(VT_I4, 0, m_nEsoJac * 2);
    SafeArrayAccessData(m_psaEsoJac, (void HUGEP* FAR*)& m_vEsoJac);
    m_psaEsoJacVals = SafeArrayCreateVector(VT_R8, 0, m_nEsoJac);
    SafeArrayAccessData(m_psaEsoJacVals, (void HUGEP* FAR*)& m_vEsoJacVals);
  }

  m_nNumJac = 0;
  m_nEsoJac = 0;
  for (Row = 0; Row < m_nVars; Row++)
  {
    i = m_JacStruct->m_spRowPage[Row]; 
    for (j = 0; j < m_JacStruct->m_cNZCols[Row]; j++) 
    {
      Col = m_JacStruct->m_ColIndices[i];
      CalcMethod = (Jac_Calc_Method) m_JacStruct->m_compact_data[i];
      if (CalcMethod == JCM_NUM)
      {
        m_vNumJac[m_nNumJac*2] = Row;
        m_vNumJac[m_nNumJac*2+1] = Col;
        m_nNumJac++;
      }
      else if (CalcMethod != JCM_CONST)
      {
        m_vEsoJac[m_nEsoJac*2] = Row;
        m_vEsoJac[m_nEsoJac*2+1] = Col;
        m_nEsoJac++;
      }
      i++;
    }
  }
  return S_OK;
}

HRESULT CIsNlaSolver::InitJacStruct()
{
  HRESULT hr;
  long i, j, k;
  long nColIndices = 0;
  SAFEARRAY* psa_ColIndices = NULL;
  SAFEARRAY* psa_cNZCols = NULL;
  SAFEARRAY* psa_CalcMethod = NULL;
  long* ColIndices = NULL;
  long* cNZCols = NULL;
  long* CalcMethod = NULL;

  DESTROY_MEMBER(m_JacStruct)

  m_JacStruct = new MatInfo(m_nVars, m_nVars, false, NULL);
  hr = m_pEso->GetJacobianStruct(&nColIndices, &psa_ColIndices, &psa_cNZCols, &psa_CalcMethod);
  if (SUCCEEDED(hr))
  {
    SafeArrayAccessData(psa_ColIndices, (void HUGEP* FAR*)& ColIndices);
    SafeArrayAccessData(psa_cNZCols, (void HUGEP* FAR*)& cNZCols);
    SafeArrayAccessData(psa_CalcMethod, (void HUGEP* FAR*)& CalcMethod);

    m_JacStruct->m_form = SPARSE;
    m_JacStruct->SetCompactSize(m_nVars, nColIndices);

    k = 0;
    for (i = 0; i < m_nVars; i++)
    {
      m_JacStruct->m_spRowPage[i] = k;
      m_JacStruct->m_cNZCols[i] = 0;
      for (j = 0; j < cNZCols[i]; j++)
      {
        m_JacStruct->m_ColIndices[k] = ColIndices[k];
        m_JacStruct->m_compact_data[k] = CalcMethod[k];
        m_JacStruct->m_compact_value[k] = 0.0;
        m_JacStruct->m_bValueSet[k] = false;
        m_JacStruct->m_cNZCols[i]++;
        k++;
      }
    }

    SafeArrayUnaccessData(psa_ColIndices);
    SafeArrayUnaccessData(psa_cNZCols);
    SafeArrayUnaccessData(psa_CalcMethod);

    SafeArrayDestroy(psa_ColIndices);
    SafeArrayDestroy(psa_cNZCols);
    SafeArrayDestroy(psa_CalcMethod);
  }
  return hr;


// #if 0
//   printMat(m_nVars, m_nVars, m_JacStruct->m_cNZCols, m_JacStruct->m_ColIndices);
// #endif
}

#undef EPS


#define ALF 1.0e-4
#define TOLX 1.e-10 // 1.0e-7

void CIsNlaSolver::lnsrch(long n, double* xold, double fold, double* g, double* p, double* x,
			double *f, double stpmax, long *check)
{
	long i;
	double a,alam,alam2,alamin,b,disc,f2,fold2,rhs1,rhs2,slope,sum,temp,
		test,tmplam;

	*check=0;
	for (sum=0.0,i=0;i<n;i++) sum += p[i]*p[i];
	sum=sqrt(sum);
	if (sum > stpmax)
		for (i=0;i<n;i++) p[i] *= stpmax/sum;
	for (slope=0.0,i=0;i<n;i++)
		slope += g[i]*p[i];
	test=0.0;
	for (i=0;i<n;i++) 
  {
		temp=fabs(p[i])/DMAX(fabs(xold[i]),1.0);
		if (temp > test) test=temp;
	}
	alamin=TOLX/test;
	alam=1.0;
	for (;;) 
  {
		for (i=0;i<n;i++) x[i]=xold[i]+alam*p[i];
		*f=fmin(x);
		if (alam < alamin) 
    {
			for (i=0;i<n;i++) x[i]=xold[i];
			*check=1;
			return;
		} else if (*f <= fold+ALF*alam*slope) return;
		else 
    {
			if (alam == 1.0)
				tmplam = -slope/(2.0*(*f-fold-slope));
			else 
      {
				rhs1 = *f-fold-alam*slope;
				rhs2=f2-fold2-alam2*slope;
				a=(rhs1/(alam*alam)-rhs2/(alam2*alam2))/(alam-alam2);
				b=(-alam2*rhs1/(alam*alam)+alam*rhs2/(alam2*alam2))/(alam-alam2);
				if (a == 0.0) tmplam = -slope/(2.0*b);
				else 
        {
					disc=b*b-3.0*a*slope;
					if (disc<0.0) cerr << "Roundoff problem in lnsrch.\n";
					else tmplam=(-b+sqrt(disc))/(3.0*a);
				}
				if (tmplam>0.5*alam)
					tmplam=0.5*alam;
			}
		}
		alam2=alam;
		f2 = *f;
		fold2=fold;
		alam=DMAX(tmplam,0.1*alam);
	}
}
#undef ALF
#undef TOLX


void CIsNlaSolver::qrdcmp(double** a, long n, double* c, double* d, long *sing)
{
	long i,j,k;
	double scale=0.0,sigma,sum,tau;

	*sing=0;
	for (k=0;k<n-1;k++) 
  {
		for (i=k;i<n;i++) scale=DMAX(scale,fabs(a[i][k]));
		if (scale == 0.0) 
    {
			*sing=1;
			c[k]=d[k]=0.0;
		} 
    else 
    {
			for (i=k;i<n;i++) a[i][k] /= scale;
			for (sum=0.0,i=k;i<n;i++) sum += SQR(a[i][k]);
			sigma=SIGN(sqrt(sum),a[k][k]);
			a[k][k] += sigma;
			c[k]=sigma*a[k][k];
			d[k] = -scale*sigma;
			for (j=k+1;j<n;j++) 
      {
				for (sum=0.0,i=k;i<n;i++) sum += a[i][k]*a[i][j];
				tau=sum/c[k];
				for (i=k;i<n;i++) a[i][j] -= tau*a[i][k];
			}
		}
	}
	d[n-1]=a[n-1][n-1];
	if (d[n-1] == 0.0) *sing=1;
}


void CIsNlaSolver::qrupdt(double** r, double** qt, long n, double* u, double* v)
{
	
	long i,j,k;

	for (k=n-1;k>=0;k--) 
  {
		if (u[k]) break;
	}
	if (k < 0) k=0;
	for (i=k-1;i>=0;i--) 
  {
		rotate(r,qt,n,i,u[i],-u[i+1]);
		if (u[i] == 0.0) u[i]=fabs(u[i+1]);
		else if (fabs(u[i]) > fabs(u[i+1]))
			u[i]=fabs(u[i])*sqrt(1.0+SQR(u[i+1]/u[i]));
		else u[i]=fabs(u[i+1])*sqrt(1.0+SQR(u[i]/u[i+1]));
	}
  // KAB Feb 17, 2003 added the following if condition
  if (n > 1)
	  for (j=0;j<n;j++) r[1][j] += u[1]*v[j];

	for (i=0;i<k;i++)
		rotate(r,qt,n,i,r[i][i],-r[i+1][i]);
}


void CIsNlaSolver::rotate(double** r, double** qt, long n, long i, double a, double b)
{
	int j;
	double c,fact,s,w,y;

	if (a == 0.0) 
  {
		c=0.0;
		s=(b >= 0.0 ? 1.0 : -1.0);
	} 
  else if (fabs(a) > fabs(b)) 
  {
		fact=b/a;
		c=SIGN(1.0/sqrt(1.0+(fact*fact)),a);
		s=fact*c;
	} else 
  {
		fact=a/b;
		s=SIGN(1.0/sqrt(1.0+(fact*fact)),b);
		c=fact*s;
	}
	for (j=i;j<n;j++) 
  {
		y=r[i][j];
		w=r[i+1][j];
		r[i][j]=c*y-s*w;
		r[i+1][j]=s*y+c*w;
	}
	for (j=0;j<n;j++) 
  {
		y=qt[i][j];
		w=qt[i+1][j];
		qt[i][j]=c*y-s*w;
		qt[i+1][j]=s*y+c*w;
	}
}


void CIsNlaSolver::rsolv(double** a, long n, double* d, double* b)
{
	long i,j;
	double sum;

	b[n-1] /= d[n-1];
	for (i=n-2;i>=0;i--) {
		for (sum=0.0,j=i+1;j<n;j++) sum += a[i][j]*b[j];
		b[i]=(b[i]-sum)/d[i];
	}
}

double CIsNlaSolver::fmin(double* x)
{
	long i;
	double sum;

  m_pEso->GetResiduals(&m_psax, &m_psaf);
	for (sum=0.0,i=0;i<m_nVars;i++) sum += SQR(m_fvec[i]);
	return 0.5*sum;
}
