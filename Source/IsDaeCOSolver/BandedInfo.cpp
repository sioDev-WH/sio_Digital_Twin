#include "stdafx.h"
#include "BandedInfo.h"
#include <math.h>
#include "MatInfo.h"

#if 0
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#endif

bool isBanded(long nRows, long nCols, double** StructureMatrix, long& lowerBandwidth, long& upperBandwidth)
{
  long lb=0 ;
  long ub = 0;
  for(long i=0;i<nRows;i++){
    for(long j=0;j<nCols;j++){
      if((i > j) && (lb <  i-j)  && (StructureMatrix)[i][j]>0){
        lb = i-j; 
        break; 
      }
      if((j  > i ) && (ub < j-i)  && (StructureMatrix)[i][j]>0){
        ub = j-i ; 
        break; 
      }
    }

  }
  if(lb<(nRows -1) && ub < (nCols-1)){
    lowerBandwidth= lb;
    upperBandwidth= ub;
    return true;
  } 
  else{
    lowerBandwidth= nRows-1;  // - improvision 
    upperBandwidth= nCols-1;
    return false; 
  } 
}


bool isBandedCompact(MatInfo& mat, long* ActiveRows, long nActiveRows, long* itActiveCols)
{
  long lb = 0;
  long ub = 0;
  long iActiveRow;
  long iRow;
  long iCol;
  long i, j;
  bool bRet;

  for (iActiveRow = 0; iActiveRow < nActiveRows; iActiveRow++)
  {
    iRow = ActiveRows[iActiveRow];
    if (mat.m_spRowPage && mat.m_cNZCols)
    {
      for (i = mat.m_spRowPage[iRow], j = 0; j < mat.m_cNZCols[iRow]; i++, j++) 
      {
        iCol = itActiveCols[mat.m_ColIndices[i]];
        if((iActiveRow > iCol) && (lb < (iActiveRow-iCol))) lb = iActiveRow-iCol; 
        if((iCol > iActiveRow) && (ub < (iCol - iActiveRow))) ub = iCol - iActiveRow; 
      }
    }
  }
  
  // change June 12, 2001: resulting matrix must be smaller than nRows*nCols to qualify as BANDED
  //if (lb < (nActiveRows - 1) && ub < (mat.m_nCols - 1))
  if ( (lb < (nActiveRows - 1)) && (ub < (mat.m_nCols - 1)) && ((lb+ub) <= mat.m_nCols) )
  {
    mat.m_lowerBandwidth= lb;
    mat.m_upperBandwidth= ub;
    bRet = true;
  } 
  else
  {
    mat.m_lowerBandwidth= nActiveRows-1;  // - improvision 
    mat.m_upperBandwidth= mat.m_nCols-1;
    bRet = false; 
  } 

  return bRet;
}

