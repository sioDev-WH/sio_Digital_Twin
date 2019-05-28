#include "StdAfx.h"
#include "IsCompactMatrix.h"


CIsCompactMatrix::CIsCompactMatrix() 
{ 
  m_nRows = 0;
  m_nCols = NULL;
  m_iColIndices = NULL; 
  m_vals = NULL;
}

CIsCompactMatrix::~CIsCompactMatrix()
{ 
  Destroy(); 
}

void CIsCompactMatrix::Destroy()
{
  long i;
  if (m_nRows)
  {
    for (i = 0; i < m_nRows; i++)
    {
      if (m_iColIndices[i]) delete[] m_iColIndices[i];
      if (m_vals[i]) delete[] m_vals[i];
    }
    delete[] m_nCols;
    delete[] m_iColIndices;
    delete[] m_vals;
  }

  m_nRows = 0;
  m_nCols = 0;
  m_iColIndices = NULL; 
  m_vals = NULL;
}

void CIsCompactMatrix::SetRowCount(long nRows)
{
  long i;
  if (nRows > m_nRows)
  {
    Destroy();
  
    m_nRows = nRows;
    m_nCols = new long[m_nRows];
    m_iColIndices = new long*[m_nRows];
    m_vals = new double*[m_nRows];
 
    for (i = 0; i < m_nRows; i++)
    {
      m_nCols[i] = 0;
      m_iColIndices[i] = NULL;
      m_vals[i] = NULL;
    }
  }
}
  
void CIsCompactMatrix::InitRow( long iRow, long count, ... )
{
  long i;
  va_list list;

  if (m_iColIndices[iRow]) delete[] m_iColIndices[iRow];
  if (m_vals[iRow]) delete[] m_vals[iRow];

  m_nCols[iRow] = count;
  m_iColIndices[iRow] = new long[count];
  m_vals[iRow] = new double[count];
  
  va_start(list, count);
  for (i = 0; i < count; i++)
  {
    m_iColIndices[iRow][i] = va_arg(list, long);
    m_vals[iRow][i] = 0.0;
  }

  va_end( list );
}

void CIsCompactMatrix::InitCompact(long nRows, long* inzCol, long* ispRow, long* cnzCol)
{
  long j, iRow, iCol;
  SetRowCount(nRows);
  
  for (iRow = 0; iRow < nRows; iRow++)
  {
    m_nCols[iRow] = cnzCol[iRow];
    DESTROY_VECTOR(m_iColIndices[iRow])
    DESTROY_VECTOR(m_vals[iRow])
    m_iColIndices[iRow] = new long[cnzCol[iRow]];
    m_vals[iRow] = new double[cnzCol[iRow]];
    for (j = 0, iCol = ispRow[iRow]; j < cnzCol[iRow]; j++, iCol++)
    {
      m_iColIndices[iRow][j] = inzCol[iCol];
      m_vals[iRow][j] = 0.0;
    }
  }
}

