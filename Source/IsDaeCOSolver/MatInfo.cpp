
#include "StdAfx.h"
#include "MatInfo.h"
#include "OnDaeCOSolverMacros.h"
#include <math.h>
#include "sparseInterface.h"
#include "stdio.h"

#if 0
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#endif

MatInfo::MatInfo()
{
  m_updateRequired=false;
  m_dataUpToDate = false;
  m_decompositionRequired=false;
  m_nRows = 0;
  m_nCols = 0;
  m_form= FULL;  
  m_data=NULL;
  m_L=NULL; 
  m_index=NULL; 
  m_sign=1;
  m_psa_data = NULL;
  m_pv_data = NULL;
  m_psa_L = NULL;
  m_pv_L = NULL;

  // compact form
  m_nColIndices = 0; 
  m_dColIndices = 0;
  m_ColIndices = NULL;
  m_cNZCols = NULL;
  m_spRowPage = NULL;
  m_compact_data = NULL;
  m_compact_value = NULL;
  m_bValueSet = NULL;

  // sparse solver support
  m_spMatrix = NULL;
  m_spRowIndex = NULL;
  m_spColIndex = NULL;
  m_bFullDecompositionRequired = true;
}

MatInfo::MatInfo(long nRows , long nCols , bool bNumeric, double*  vec)
{
  m_updateRequired=false;
  m_dataUpToDate = false;
  m_decompositionRequired=false;
  m_nRows =nRows;
  m_nCols =nCols;
  m_form= FULL;  
  m_data=NULL;
  m_L=NULL; 
  m_index=NULL; 
  m_sign=1;
  m_psa_data = NULL;
  m_pv_data = NULL;
  m_psa_L = NULL;
  m_pv_L = NULL;

  // compact form
  m_nColIndices = 0; 
  m_dColIndices = 0;
  m_ColIndices = NULL;
  m_cNZCols = NULL;
  m_spRowPage = NULL;
  m_compact_data = NULL;
  m_compact_value = NULL;
  m_bValueSet = NULL;

  // sparse solver support
  m_spMatrix = NULL;
  m_spRowIndex = NULL;
  m_spColIndex = NULL;
  m_bFullDecompositionRequired = true;

}

MatInfo::~MatInfo()
{
  long i;

  if (m_pv_data)
  {
    for (i = 0; i < m_nCols; i++)
      SafeArrayUnaccessData(m_pv_data[i].parray);

    SafeArrayUnaccessData(m_psa_data);
    SafeArrayDestroy(m_psa_data);
    m_psa_data = NULL;
    m_pv_data = NULL;
  }
  if (m_data)
  {
    delete[] m_data;
    m_data = NULL;
  }

  if (m_pv_L)
  {
    for (i = 0; i < m_lowerBandwidth; i++)
      SafeArrayUnaccessData(m_pv_L[i].parray);

    SafeArrayUnaccessData(m_psa_L);
    SafeArrayDestroy(m_psa_L);
    m_psa_L = NULL;
    m_pv_L = NULL;
  }
  if (m_L)
  {
    delete[] m_L; 
    m_L = NULL;
  }

  DESTROY_VECTOR(m_index)

  // sparse form
  // WAH to get the profiler going on exit
  IS_spDestroy(&m_spMatrix);
  DESTROY_VECTOR(m_spRowIndex);
  DESTROY_VECTOR(m_spColIndex);


  DESTROY_VECTOR(m_ColIndices)
  DESTROY_VECTOR(m_cNZCols)
  DESTROY_VECTOR(m_spRowPage)
  DESTROY_VECTOR(m_compact_data)
  DESTROY_VECTOR(m_compact_value)
  DESTROY_VECTOR(m_bValueSet)

  // sparse solver support
}

/* 
NOTE:  In the case of a banded matrix, set:  m_form, m_lowerBandwidth, and m_upperBandwidth
       before calling Init()
*/

MatInfo& MatInfo::operator=(const MatInfo& other)
{
  long i, j;

  m_nRows = other.m_nRows;
  m_nCols = other.m_nCols;
  m_form = other.m_form;

  if (m_form == BANDED)
  {
    m_lowerBandwidth = other.m_lowerBandwidth;
    m_upperBandwidth = other.m_upperBandwidth;
  }
  else
  {
    m_lowerBandwidth = m_nRows;
    m_upperBandwidth = m_nCols;
  }
  
  if (m_form == BANDED || m_form == FULL)
  {
    Init();
    for (i = 0; i < other.m_nRows; i++)
    {
      for (j = 0; j < m_nCols; j++)
        m_data[i][j] = other.m_data[i][j];
    }

    for (i = 0; i < m_nRows; i++)
    {
      for (j = 0; j < m_lowerBandwidth; j++)
        m_L[i][j] = other.m_L[i][j];
    }
  }
  else if (m_form == SPARSE)
  {
    m_nColIndices = other.m_nColIndices;
    SetCompactSize(m_nRows, m_nColIndices);
    for (i = 0; i < m_nRows; i++)
    {
      if (i < other.m_nRows)
      {
        m_cNZCols[i] = other.m_cNZCols[i];
        m_spRowPage[i] = other.m_spRowPage[i];
      }
      else
      {
        m_cNZCols[i] = 0;
        m_spRowPage[i] = 0;
      }
    }

    for (i = 0; i < m_nColIndices; i++)
    {
      m_ColIndices[i] = other.m_ColIndices[i];
      m_compact_data[i] = other.m_compact_data[i];
      m_compact_value[i] = other.m_compact_value[i];
    }
  }
  return *this;
}

void MatInfo::Init()
{
  long i, j;

  if (m_form == BANDED)
  {
    m_nRows = m_nRows; 
    m_nCols = m_lowerBandwidth + m_upperBandwidth + 1;    // Leading dim of Jacobian [neqn][ldj]
  } 

  if (m_form == SPARSE) return;

  if(!m_data)
  {
    m_data = (double**) new double[m_nRows];

    // allocate SAs and access members rather than allocate C arrays of doubles.
    VARIANT* pVarData = NULL;
    m_psa_data = SafeArrayCreateVector(VT_VARIANT, 0, m_nRows);
    SafeArrayAccessData(m_psa_data, (void HUGEP* FAR*)& pVarData);
    for (i = 0; i < m_nRows; i++)
    {
      VariantInit(&pVarData[i]);
      pVarData[i].vt = VT_R8 | VT_ARRAY;
      pVarData[i].parray = SafeArrayCreateVector(VT_R8, 0, m_nCols);
      SafeArrayAccessData(pVarData[i].parray, (void HUGEP* FAR*)& m_data[i]);
      for (j = 0; j < m_nCols; j++)
        m_data[i][j] = 0.0;
    }
  }

  if (!m_L)
  {
    m_L = (double**) new double*[m_nRows];

    VARIANT* pVarData = NULL;
    m_psa_L = SafeArrayCreateVector(VT_VARIANT, 0, m_nRows);
    SafeArrayAccessData(m_psa_L, (void HUGEP* FAR*)& pVarData);
    for (i = 0; i < m_nRows; i++)
    {
      VariantInit(&pVarData[i]);
      pVarData[i].vt = VT_R8 | VT_ARRAY;
      pVarData[i].parray = SafeArrayCreateVector(VT_R8, 0, m_lowerBandwidth);
      SafeArrayAccessData(pVarData[i].parray, (void HUGEP* FAR*)& m_L[i]);
      for (j = 0; j < m_lowerBandwidth; j++)
        m_L[i][j] = 0.0;
    }
  }
}

void MatInfo::SetCompactSize(long nEqns, long nColIndices)
{
  long i;
  const long grow_by_buffer = 50;
  bool bReInit = (nEqns > m_nRows || (nEqns > 0 && m_cNZCols == NULL) || nColIndices > m_dColIndices);

  m_nRows = nEqns;
  m_nCols = nEqns;
  m_nColIndices = nColIndices;
  
  if (bReInit)
  {
    DESTROY_VECTOR(m_ColIndices)
    DESTROY_VECTOR(m_compact_data)
    DESTROY_VECTOR(m_compact_value)
    DESTROY_VECTOR(m_bValueSet)
    DESTROY_VECTOR(m_cNZCols)
    DESTROY_VECTOR(m_spRowPage)


    if (nColIndices > 0) 
    {
      m_dColIndices = nColIndices + grow_by_buffer; // buffered dimension
      m_ColIndices = new long[m_dColIndices];
      m_compact_data = new long[m_dColIndices];
      m_compact_value = new double[m_dColIndices];
      m_bValueSet = new bool[m_dColIndices];
    }
  
    if (nEqns > 0)
    {
      m_cNZCols = new long[nEqns+1];     // pad count with 1 for applications requiring the n+1 entry
      m_spRowPage = new long[nEqns+1];
    }

    for (i = 0; i < m_dColIndices; i++)
    {
      m_ColIndices[i] = -1;
      m_compact_data[i] = 0;
      m_compact_value[i] = 0.0;
      m_bValueSet[i] = false;
    }

    for (i = 0; i < nEqns; i++)
    {
      m_cNZCols[i] = 0;
      m_spRowPage[i] = 0;
    }
  }

}

void MatInfo::SetActiveCompactSize(MatInfo& other, long* activeRows, long nActiveRows)
{
  long i, j;
  long spRowPage;
  long cNZ;

  j = 0;
  for (i = 0; i < nActiveRows; i++) j += other.m_cNZCols[activeRows[i]];

  SetCompactSize(nActiveRows, j);

  m_nColIndices = 0;
  for (i = 0; i < nActiveRows; i++)
  {
    spRowPage = other.m_spRowPage[activeRows[i]];
    cNZ = other.m_cNZCols[activeRows[i]];

    m_spRowPage[i] = m_nColIndices;
    m_cNZCols[i] = cNZ; 
    
    for (j = 0; j < cNZ; j++)
    {
      m_compact_data[m_nColIndices] = other.m_compact_data[spRowPage + j];
      m_compact_value[m_nColIndices] = other.m_compact_value[spRowPage + j];
      m_ColIndices[m_nColIndices] = other.m_ColIndices[spRowPage + j];
      m_nColIndices++;
    }
  }
}

/*
bool MatInfo::update(double** structureData, double t, double*  y, double* ydot)
{
  if(!m_data)
  {
    Init();
    if (!m_data)
      return false;
  }

  if (m_data && m_pMatGen){
    m_pMatGen(m_nRows,m_nRows,structureData,t,y,ydot, &m_data, NULL,NULL);
  }
  if (!m_pMatGen)
  {
#ifdef _Report
    cerr << "\n ================== \n ";
    cerr << "Error= NULL Matrix Generator \n ";
#endif
    return false;  
  }
  m_dataUpToDate= true;
  return true;
}
*/

void MatInfo::decompose()
{
  long i,j,k,l;
  int mm;
  double dum;
  int imax;
  double  big,sum,temp;
  double  *vv;
  int errorFlag = 0;

  if (!m_index)
  {
    m_index = new long[m_nRows];
    for (i = 0; i < m_nRows; i++)
      m_index[i] = -1;
  }

  if (m_form == SPARSE)
  {
    if (!m_bFullDecompositionRequired)
    {
      IS_spReDecompose(m_spMatrix, &errorFlag);
      if (errorFlag != 0) m_bFullDecompositionRequired = true;
    }

    if (m_bFullDecompositionRequired)
    {
      IS_spDecompose(m_spMatrix, &errorFlag);
      _ASSERTE(errorFlag == 0);
      if (errorFlag == 0)
        m_bFullDecompositionRequired = false;
    }
  }
  else if(m_form==BANDED)
  {
    mm= m_lowerBandwidth+m_upperBandwidth+1;
    if(!m_L)
      Init();

    l=m_lowerBandwidth;
    for (i=0;i<m_lowerBandwidth;i++) {
      for (j=m_lowerBandwidth-i;j<mm;j++) 
        m_data[i][j-l]=m_data[i][j];
      l--; 
      for (j=mm-1-l;j<mm;j++) m_data[i][j]=0.0;
    }
    m_sign=1.0;
    l=m_lowerBandwidth;
    for (k=0;k<m_nRows;k++) {
      dum=m_data[k][0];
      i=k;
      if (l < m_nRows) l++;
      for (j=k+1;j<l;j++) {
        if (fabs(m_data[j][0]) > fabs(dum)) {
          dum=m_data[j][0];
          i=j;
        }
      }
      m_index[k]=i;
      if (dum == 0.0) m_data[k][0]=TINY;
      if (i != k) {
        m_sign = -(m_sign);
        for (j=0;j<mm;j++){  
          SWAP(m_data[k][j],m_data[i][j])
        } 
      }
      for (i=k+1;i<l;i++) {
        dum=m_data[i][0]/m_data[k][0];
        m_L[k][i-k-1]=dum;
        for (j=1;j<mm;j++) m_data[i][j-1]=m_data[i][j]-dum*m_data[k][j];
        m_data[i][mm-1]=0.0;
      }
    }

#ifdef _Report
    //cerr << "*** Upper \n ";
    long nu=m_upperBandwidth;
    long nl=0;    // Notice that Upper has nlj=0
    for(j=0;j<m_nRows;j++){   
      long kmin= LMAX(0,nl-j);
      long kmax= LMIN(nu+nl+1,nl+m_nRows-j); 
      // for(k=kmin;k<kmax;k++)
      for(k=0;k<nl+nu+1;k++){
        if(k>=kmin && k<kmax)
          //cerr << m_data[j][k]<<"\t";
        else
          //cerr << "X" <<"\t\t";
      }
      //cerr << "\n";
    }
    //cerr << "*** Lower  \n ";
    nu=0;
    nl=m_lowerBandwidth;    // Notice that Upper has nuj=0
    for(j=0;j<m_nRows;j++){   
      long kmin= LMAX(0,nl-j);
      long kmax= LMIN(nu+nl+1,nl+m_nRows-j); 
      for(k=0;k<nl;k++){
        if(k>=kmin && k<kmax)
          //cerr << m_L[j][k]<<"\t";
        else
          //cerr << "X" <<"\t\t";
      }
      //cerr << "\n";
    }

    //cerr << "\n ================== \n ";
#endif
  } 
  else if( m_form== FULL)
  {
    vv=(double*) new double [m_nRows];
    m_sign=1.0;
    for (i=0;i<m_nRows;i++) {
      big=0.0;
      for (j=0;j<m_nRows;j++)
        if ((temp=fabs(m_data[i][j])) > big) big=temp;
      if (big == 0.0) 
      {
        ATLTRACE(L"Singular matrix in routine ludcmp \n");
        _ASSERTE(0);
      }
      vv[i]=1.0/big;
    }
    for (j=0;j<m_nRows;j++) {
      for (i=0;i<j;i++) {
        sum=m_data[i][j];
        for (k=0;k<i;k++) sum -= m_data[i][k]*m_data[k][j];
        m_data[i][j]=sum;
      }
      big=0.0;
      for (i=j;i<m_nRows;i++) {
        sum=m_data[i][j];
        for (k=0;k<j;k++)
          sum -= m_data[i][k]*m_data[k][j];
        m_data[i][j]=sum;
        if ( (dum=vv[i]*fabs(sum)) >= big) {
          big=dum;
          imax=i;
        }
      }
      if (j != imax) {
        for (k=0;k<m_nRows;k++) {
          dum=m_data[imax][k];
          m_data[imax][k]=m_data[j][k];
          m_data[j][k]=dum;
        }
        m_sign = -m_sign;
        vv[imax]=vv[j];
      }
      m_index[j]=imax;
      if (m_data[j][j] == 0.0) m_data[j][j]=TINY;
      if (j != m_nRows-1) {
        dum=1.0/(m_data[j][j]);
        for (i=j+1;i<m_nRows;i++) m_data[i][j] *= dum;
      }
    }
    delete vv;
  } 
}
void MatInfo::SolveEquation(double* b)
{
  long i,j,k,l;
  long  mm;
  double dum;
  long ii=-1,ip;
  double sum;

  if (m_form == SPARSE)
  {
    IS_spSolve(m_spMatrix, m_nRows, b, b);
  }
  else if(m_form==BANDED){
    mm=m_lowerBandwidth+m_upperBandwidth+1;
    l=m_lowerBandwidth;
    for (k=0;k<m_nRows;k++){
      i=m_index[k];
      if (i != k) SWAP(b[k],b[i])
      if (l < m_nRows) l++;
      for (i=k+1;i<l;i++){  
        b[i] -= m_L[k][i-k-1]*b[k];
      } 
    }
    l=1;
    for (i=m_nRows-1;i>=0;i--) {
      dum=b[i];
      for (k=1;k<l;k++)
        dum -= m_data[i][k]*b[k+i];
      b[i]=dum/m_data[i][0];
      if (l < mm) l++;
    }
  }
  else if(m_form==FULL){

    for (i=0;i<m_nRows;i++){
      ip=m_index[i];
      sum=b[ip];
      b[ip]=b[i];
      if (ii>-1)
        for (j=ii;j<=i-1;j++) sum -= m_data[i][j]*b[j];
      else if (sum) ii=i;
      b[i]=sum;
    }
    for (i=m_nRows-1;i>=0;i--) {
      sum=b[i];
      for (j=i+1;j<m_nRows;j++) sum -= m_data[i][j]*b[j];
      b[i]=sum/m_data[i][i];
    }
  }
}

bool MatInfo::GetValue(long iRow, long iCol, double& val)
{
  long lower;
  long upper;
  long i;
  bool bRet = true;
  val = 0.0;

  switch(m_form)
  {
  case SPARSE:
    bRet = false;
    for (i = 0; i < m_cNZCols[iRow]; i++)
    {
      if (iCol == m_ColIndices[m_spRowPage[iRow] + i])
      {
        val = m_compact_value[m_spRowPage[iRow] + i];
        bRet = true;
        break;
      }
    }
    break;

  case BANDED:
    lower = LMAX(0, iRow-m_lowerBandwidth);
    upper = LMIN(m_nRows-1, iRow+m_upperBandwidth);
    if (iRow >= 0 && iRow < m_nRows && iCol >= lower && iCol <= upper)
      val = m_data[iRow][m_lowerBandwidth - (iRow-iCol)];
    else
      bRet = false;

  break;

  case FULL:
    if (iRow >= 0 && iRow < m_nRows && iCol >= 0 && iCol < m_nCols)
      val = m_data[iRow][iCol];
    else
      bRet = false;
    break;
  }

  return bRet;
}

bool MatInfo::SetValue(long iRow, long iCol, double val)
{
  long lower;
  long upper;
  bool bRet = true;
  long i;

  switch(m_form)
  {
  case SPARSE:
    bRet = false;
    for (i = 0; i < m_cNZCols[iRow]; i++)
    {
      if (iCol == m_ColIndices[m_spRowPage[iRow] + i])
      {
        m_compact_value[m_spRowPage[iRow] + i] = val;
        bRet = true;
        break;
      }
    }
    break;
  
  case BANDED:
    lower = LMAX(0, iRow-m_lowerBandwidth);
    upper = LMIN(m_nRows-1, iRow+m_upperBandwidth);
    if (iRow >= 0 && iRow < m_nRows && iCol >= lower && iCol <= upper)
      m_data[iRow][m_lowerBandwidth - (iRow-iCol)] = val;
    else
      bRet = false;

  break;

  case FULL:
    if (iRow >= 0 && iRow < m_nRows && iCol >= 0 && iCol < m_nCols)
      m_data[iRow][iCol] = val;
    else
      bRet = false;
  }

  return bRet;
}

void MatInfo::multiplyVec(double* x, double* &b)
{
  long i,j,k;
  long startPoint;

  // Comment Check inputs here 
  if (m_form == SPARSE)
  {
    for (i = 0; i < m_nRows; i++) 
    {
      b[i] = 0.0;
      startPoint = m_spRowPage[i];
      for (j = 0; j < m_cNZCols[i]; j++) 
        b[i] += m_compact_value[startPoint+j] * x[j];
    }
  }
  else if (m_form==BANDED)
  {
    long mm= m_lowerBandwidth+m_upperBandwidth+1;
    for (i=0;i<m_nRows;i++) {
      k=i-m_lowerBandwidth;
      long tmploop=LMIN(mm,m_nRows-k);
      b[i]=0.0;
      for (j=LMAX(0,-k);j<tmploop;j++) 
        b[i] += m_data[i][j]*x[j+k];
    }
  }
  else if(m_form==FULL)
  {
    for (i=0;i<m_nRows;i++) 
    {
      b[i]=0.0;
      for (j=0;j<m_nRows;j++) b[i] += m_data[i][j]*x[j];
    }
  }
} 

void MatInfo::spMatrixDestroy()
{
  IS_spDestroy(&m_spMatrix);
}

void MatInfo::spMatrixInit()
{
  long iRow, startPoint, j;
  int errorFlag = 0;

  IS_spDestroy(&m_spMatrix);

  // initialize the spRowIndex vector
  if (!m_spRowIndex) m_spRowIndex = new int[m_dColIndices];
  if (!m_spColIndex) m_spColIndex = new int[m_dColIndices];

  // fortran-like null terminator
  m_spRowIndex[m_nColIndices] = 0;
  m_spColIndex[m_nColIndices] = 0;
  m_compact_value[m_nColIndices] = 0.0;

  for (iRow = 0; iRow < m_nRows; iRow++)
  {
    startPoint = m_spRowPage[iRow];
    for (j = 0; j < m_cNZCols[iRow]; j++)
    {
      m_spRowIndex[startPoint+j] = iRow + 1; // make row vector 1 based
    }
  }

  for (j = 0; j < m_nColIndices; j++) 
    m_spColIndex[j] = m_ColIndices[j] + 1; // make col vector 1 based

#if 0
  ATLTRACE("\n rowindex[] = ");
  for (j = 0; j < m_nColIndices; j++)
    ATLTRACE("%d ", m_spRowIndex[j]);

  ATLTRACE("\n colindex[] = ");
  for (j = 0; j < m_nColIndices; j++)
    ATLTRACE("%d ", m_spColIndex[j]);

  ATLTRACE("\n spRowPage[] = ");
  for (j = 0; j < m_nRows; j++)
    ATLTRACE("%d ", m_spRowPage[j]);
#endif

  IS_spFormMatrix(&m_spMatrix, m_nRows, m_nColIndices, m_spRowIndex, m_spColIndex, m_compact_value, &errorFlag);
  _ASSERTE(errorFlag == 0);
  m_bFullDecompositionRequired = true;
}


void MatInfo::Save(FILE* fs)
{
  const long m_schema = 1;
  const long m_classId = 1009;

  long i;
  bool bm_data = m_data != NULL; 
  bool bm_L = m_L != NULL;
  bool bm_index = m_index != NULL;
  bool bm_ColIndices = m_ColIndices != NULL;
  bool bm_cNZCols = m_cNZCols != NULL;
  bool bm_spRowPage = m_spRowPage != NULL;
  bool bm_compact_data = m_compact_data != NULL;
  bool bm_compact_value = m_compact_value != NULL;
  bool bm_bValueSet = m_bValueSet != NULL;

  WRITE_SCALAR( m_classId )
  WRITE_SCALAR( m_schema )

  WRITE_SCALAR( m_updateRequired )
	WRITE_SCALAR( m_dataUpToDate )
	WRITE_SCALAR( m_decompositionRequired )
	WRITE_SCALAR( m_nRows )
	WRITE_SCALAR( m_nCols )
	WRITE_SCALAR( m_lowerBandwidth )
	WRITE_SCALAR( m_upperBandwidth )
	
  WRITE_SCALAR( bm_data )
  if (m_data)
  {
    for (i = 0; i < m_nRows; i++)
    {
      WRITE_VECTOR( m_data[i], double, m_nCols )
    }
  }

  WRITE_SCALAR( bm_L )
  if (m_L)
  {
    for (i = 0; i < m_nRows; i++)
    {
      WRITE_VECTOR( m_L[i], double, m_lowerBandwidth )
    }
  }

  WRITE_SCALAR( bm_index )
  if (m_index)
  {
    WRITE_VECTOR( m_index, long, m_nRows )
  }

  WRITE_SCALAR( m_sign )  

  WRITE_SCALAR( m_nColIndices )
  WRITE_SCALAR( bm_ColIndices )
  if (m_ColIndices)
  {
    WRITE_VECTOR( m_ColIndices, long, m_nColIndices )
  }

  WRITE_SCALAR( bm_cNZCols )
  if (m_cNZCols)
  {
    WRITE_VECTOR( m_cNZCols, long, m_nRows )
  }

  WRITE_SCALAR( bm_spRowPage )
  if (m_spRowPage)
  {
    WRITE_VECTOR( m_spRowPage, long, m_nRows )
  }

  WRITE_SCALAR( bm_compact_data )
  if (m_compact_data)
  {
    WRITE_VECTOR( m_compact_data, long, m_nColIndices )
  }

  WRITE_SCALAR( bm_compact_value )
  if (m_compact_value)
  {
    WRITE_VECTOR( m_compact_value, double, m_nColIndices )
  }

  WRITE_SCALAR( bm_bValueSet )
  if (m_bValueSet)
  {
    WRITE_VECTOR( m_bValueSet, bool, m_nColIndices )
  }
}

bool MatInfo::Load(FILE* fs)
{
  const long m_schema = 1;
  const long m_classId = 1009;

  long i;
  long classId;
  long schema;

  bool bm_data;
  bool bm_L;
  bool bm_index;
  bool bm_ColIndices;
  bool bm_cNZCols;
  bool bm_spRowPage;
  bool bm_compact_data;
  bool bm_compact_value;
  bool bm_bValueSet;

  long nRows;
  long nCols;
  bool bRet = false;


  READ_SCALAR( classId )
  if (classId != m_classId) { _ASSERTE(0); return false; }

  READ_SCALAR( schema )

  switch (schema)
  {
  case 1:
    READ_SCALAR( m_updateRequired )
	  READ_SCALAR( m_dataUpToDate )
	  READ_SCALAR( m_decompositionRequired )
	  READ_SCALAR( nRows )
	  READ_SCALAR( nCols )
	  READ_SCALAR( m_lowerBandwidth )
	  READ_SCALAR( m_upperBandwidth )
	  
    if (nRows != m_nRows || nCols != m_nCols) { _ASSERTE(0); return false; }

    READ_SCALAR( bm_data )
    if (bm_data && !m_data) { _ASSERTE(0); return false; }
    if (m_data)
    {
      for (i = 0; i < m_nRows; i++)
      {
        READ_VECTOR( m_data, double, m_nCols )
      }
    }

    READ_SCALAR( bm_L )
    if (bm_L && !m_L) { _ASSERTE(0); return false; }
    if (m_L)
    {
      for (i = 0; i < m_nRows; i++)
      {
        READ_VECTOR( m_L, double, m_lowerBandwidth )
      }
    }

    READ_SCALAR( bm_index )
    if (bm_index && !m_index) { _ASSERTE(0); return false; }
    if (m_index)
    {
      READ_VECTOR( m_index, long, m_nRows )
    }

    READ_SCALAR( m_sign )

    READ_SCALAR( m_nColIndices )
    READ_SCALAR( bm_ColIndices )
    if (bm_ColIndices && !m_ColIndices) { _ASSERTE(0); return false; }
    if (m_ColIndices)
    {
      READ_VECTOR( m_ColIndices, long, m_nColIndices )
    }

    READ_SCALAR( bm_cNZCols )
    if (bm_cNZCols && !m_cNZCols) { _ASSERTE(0); return false; }
    if (m_cNZCols)
    {
      READ_VECTOR( m_cNZCols, long, m_nRows )
    }

    READ_SCALAR( bm_spRowPage )
    if (bm_spRowPage && !m_spRowPage) { _ASSERTE(0); return false; }
    if (m_spRowPage)
    {
      READ_VECTOR( m_spRowPage, long, m_nRows )
    }

    READ_SCALAR( bm_compact_data )
    if (bm_compact_data && !m_compact_data) { _ASSERTE(0); return false; }
    if (m_compact_data)
    {
      READ_VECTOR( m_compact_data, long, m_nColIndices )
    }

    READ_SCALAR( bm_compact_value )
    if (bm_compact_value && !m_compact_value) { _ASSERTE(0); return false; }
    if (m_compact_value)
    {
      READ_VECTOR( m_compact_value, double, m_nColIndices )
    }

    READ_SCALAR( bm_bValueSet )
    if (bm_bValueSet && !m_bValueSet) { _ASSERTE(0); return false; }
    if (m_bValueSet)
    {
      READ_VECTOR( m_bValueSet, bool, m_nColIndices )
    }

    bRet = true;
    break;

  }

  // initialize all update required variables to true
  m_bFullDecompositionRequired = true;
  m_decompositionRequired = true;

  return bRet;
}  