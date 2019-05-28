#include "stdafx.h"
#include "ConsistentInitialization.h"
#include "triangularization.h"
#include "ISDaeCOSolver.h"
#include "IsCINlaEso.h"
#include "IsDaeEso.h"
#include "IsNlaSolver.h"
#include <iostream.h>
#include <fstream.h>
#include "MSS.h"
#include "CommonTools.h"

#include "OnDaeCOSolverMacros.h"
#include "ModelNavMaps.h"
#include "IndexInfo.h"
#include "MatInfo.h"
#include "VarInfo.h"
#include "VirtualTimeInfo.h"


#include "IsDaeEsoCImpl.h"

#ifdef _DEBUG
#include "time.h"
static ofstream* fs = NULL;
char buffer[255];
#endif

#ifndef CLOCKS_PER_SEC
#define CLOCKS_PER_SEC 60.0
#endif

#if 0
#ifdef _DEBUG
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)
#endif
#endif


#ifdef _DEBUG
/*****************************************************************
*
*  matrix printing functions
*
*****************************************************************/

/////////////////////////////////////////////////////////////////
// printMat
//
// - Expands sparse matrix into a nXn character matrix.
//
/////////////////////////////////////////////////////////////////
void printMat(long nEqns, long nVars, long* cNZ, long** Indices)
{
  long i, j, k;
  long nI = 0;
  long* cI = NULL;
  for (i = 0; i < nEqns; i++) nI += cNZ[i];
  cI = new long[nI];
  k = 0;
  for (i = 0; i < nEqns; i++)
  {
    for (j = 0; j < cNZ[i]; j++)
      cI[k++] = Indices[i][j];
  }
  printMat(nEqns, nVars, cNZ, cI);
  DESTROY_VECTOR(cI)
}

void printMat2(long nEqns, long nVars, long* cNZ, long* Indices)
{
  long i, j, k;
  k = 0;
  for (i = 0; i < nEqns; i++)
  {
    ATLTRACE("\nrow[%d]: ", i);
    for (j = 0; j < cNZ[i]; j++) ATLTRACE("%d ", Indices[k++]);
  }
}

void printMat3(long nEqns, long nVars, long* cNZ, long* colIndices, double* vals)
{
  long i, j, k;
  k = 0;
  for (i = 0; i < nEqns; i++)
  {
    ATLTRACE("\nrow[%d]: ", i);
    for (j = 0; j < cNZ[i]; j++) 
    {
      ATLTRACE("[%d] %e ", colIndices[k], vals[k]);
      k++;
    }
  }
}

void printMat(long nEqns, long nVars, long* cNZ, long* Indices)
{
  long i,j,k;
  // build mapping matrix
  char** mat = new char*[nEqns];
  for (i = 0; i < nEqns; i++)
  {
    mat[i] = new char[nVars];
    for (j = 0; j < nVars; j++)
      mat[i][j] = '0';
  }

  // read data into mapping matrix
  k = 0;
  for (i = 0; i < nEqns; i++)
  {
    for (j = 0; j < cNZ[i]; j++)
    {
      mat[i][Indices[k++]] = '1';
    }
  }

  // print mapping matrix
  // heading
  sprintf(buffer, "\n   "); ATLTRACE(buffer);
  if (fs) (*fs) << "   ";
  for (i = 0; i < nVars; i++)
  {
    sprintf(buffer, "%d ", i); ATLTRACE(buffer);
    if (fs) (*fs) << i << " ";
  }
  sprintf(buffer, "\n\n"); ATLTRACE(buffer);
  if (fs) (*fs) << "\n\n";

  char matrix_buffer[2];
  matrix_buffer[1] = '\0';
  for (i = 0; i < nEqns; i++)
  {
    sprintf(buffer, "%d  ", i); ATLTRACE(buffer);
    if (fs) (*fs) << i << "  ";
    for (j = 0; j < nVars; j++)
    {
      matrix_buffer[0] = mat[i][j];
      sprintf(buffer, "%s ", matrix_buffer); ATLTRACE(buffer);
      if (fs) (*fs) << mat[i][j] << " ";
    }
    sprintf(buffer, "\n"); ATLTRACE(buffer);
    if (fs) (*fs) << "\n";
  }

  for (i = 0; i < nEqns; i++)
    delete mat[i];

  delete mat;
}

void printMat(long nEqns, long nVars, double** data)
{
  long i, j;
  for (i = 0; i < nEqns; i++)
  {
    ATLTRACE("\n");
    for (j = 0; j < nVars; j++)
      ATLTRACE("%e\t", data[i][j]);
  }
  ATLTRACE("\n");
}

void printMat(long nEqns, long nVars, bool** data)
{
  long i, j;
  ATLTRACE("\n");
  for (i = 0; i < nEqns; i++)
  {
    ATLTRACE("\n  ");
    for (j = 0; j < nVars; j++)
    {
      if (data[i][j])
        ATLTRACE(" 1");
      else
        ATLTRACE(" 0");
    }
  }
  ATLTRACE("\n");
}


/////////////////////////////////////////////////////////////////
// printMat
//
// - Expands sparse matrix into a nXn character matrix.
//
/////////////////////////////////////////////////////////////////
void printMatWithOrder(long nEqns, long nVars, long* cNZ, long* Indices, long* columnOrder, long* rowOrder)
{
  long i,j,k;
  // build mapping matrix
  char** mat = new char*[nEqns];
  for (i = 0; i < nEqns; i++)
  {
    mat[i] = new char[nVars];
    for (j = 0; j < nVars; j++)
      mat[i][j] = '0';
  }

  // read data into mapping matrix
  k = 0;
  for (i = 0; i < nEqns; i++)
    for (j = 0; j < cNZ[i]; j++)
      mat[i][Indices[k++]] = '1';

  // print mapping matrix
  // heading
  char matrix_buffer[2];
  matrix_buffer[1] = '\0';

  sprintf(buffer, "(matrix with column and row labels)\n   "); ATLTRACE(buffer);
  if (fs) (*fs) << "(matrix with column and row labels)\n";
  if (fs) (*fs) << "   ";
  for (i = 0; i < nVars; i++) 
  {
    if (i < 10)
    {
      sprintf(buffer, "%d ", columnOrder[i]/10); ATLTRACE(buffer);
    }
    else
    {
      sprintf(buffer, "%d ", columnOrder[i]/10); ATLTRACE(buffer);
    }

    if (fs) (*fs) << columnOrder[i] << " ";
  }
  sprintf(buffer, "\n\n"); ATLTRACE(buffer);
  if (fs) (*fs) << "\n";

  for (i = 0; i < nVars; i++) 
  {
    sprintf(buffer, "%d ", columnOrder[i] - (columnOrder[i]/10) * 10); ATLTRACE(buffer);
    if (fs) (*fs) << columnOrder[i] << " ";
  }
  sprintf(buffer, "\n\n"); ATLTRACE(buffer);
  if (fs) (*fs) << "\n\n";


  for (i = 0; i < nEqns; i++)
  {
    sprintf(buffer, "%d  ", rowOrder[i]); ATLTRACE(buffer);
    if (fs) (*fs) << rowOrder[i] << "  ";
    for (j = 0; j < nVars; j++)
    {
      matrix_buffer[0] = mat[i][j];
      sprintf(buffer, "%s ", matrix_buffer); ATLTRACE(buffer);
      if (fs) (*fs) << mat[i][j] << " ";
    }
    sprintf(buffer, "\n"); ATLTRACE(buffer);
    if (fs) (*fs) << "\n";
  }

  for (i = 0; i < nEqns; i++)
    delete mat[i];

  delete mat;
}


void printMatToConsole(long nEqns, long* cNZ, long* Indices)
{
  long i,j,k;
  // build mapping matrix
  char** mat = new char*[nEqns];
  for (i = 0; i < nEqns; i++)
  {
    mat[i] = new char[nEqns];
    for (j = 0; j < nEqns; j++)
      mat[i][j] = '0';
  }

  // read data into mapping matrix
  k = 0;
  for (i = 0; i < nEqns; i++)
    for (j = 0; j < cNZ[i]; j++)
      mat[i][Indices[k++]] = '1';

  // print mapping matrix
  // heading
  if (fs) (*fs) << "   ";
  for (i = 0; i < nEqns; i++) if (fs) (*fs) << i << " ";
  if (fs) (*fs) << "\n\n";

  for (i = 0; i < nEqns; i++)
  {
    if (fs) (*fs) << i << "  ";
    for (j = 0; j < nEqns; j++)
      if (fs) (*fs) << mat[i][j] << " ";

    if (fs) (*fs) << "\n";
  }

  for (i = 0; i < nEqns; i++)
    delete mat[i];

  delete mat;
}


/////////////////////////////////////////////////////////////////
// printMat
//
// - Prints blocks with their associated equations.
// - Assumes blockSizes and orderMap vectors are in reverse order, and 
//   corrects the order.
//
/////////////////////////////////////////////////////////////////
void printEqnBlocks(long nEqns, long cBlocks, long* blockSizes, long* orderMap)
{
	long iBlock;
  long iEqn;
  long i;

	i = 0;
	for (iBlock = 0; iBlock < cBlocks; iBlock++)
	{
    sprintf(buffer, "block[%d]\n", iBlock); ATLTRACE(buffer);
		if (fs) (*fs) << "block[" << iBlock << "]\n";
		for (iEqn = 0; iEqn < blockSizes[iBlock]; iEqn++)
		{
      sprintf(buffer, "    eqn[%d] = %d\n", iEqn, orderMap[i]); ATLTRACE(buffer);
			if (fs) (*fs) << "    eqn[" << iEqn << "] = " << orderMap[i] << "\n";
			i++;
		}
	}
}

void printNote(char* note)
{
  if (fs) (*fs) << "\n" << note << "\n";
  sprintf(buffer, "\n%s\n", note); ATLTRACE(buffer);
}

void printVec(char* heading, long* vec, long size)
{
  long i;

  sprintf(buffer, "\n\n%s: [ ", heading); ATLTRACE(buffer);
  if (fs) (*fs) << "\n" << heading << ": [ ";
  for (i = 0; i < size; i++) 
  {
    sprintf(buffer, "%d ", vec[i]); ATLTRACE(buffer);
    if (fs) (*fs) << vec[i] << " ";
  }
  if (fs) (*fs) << "]\n";
  sprintf(buffer, "]\n"); ATLTRACE(buffer);
}

void printVec(char* heading, bool* vec, long size)
{
  long i;

  ATLTRACE("\n%s: [ ", heading);
  for (i = 0; i < size; i++) 
  {
    if (vec[i])
      ATLTRACE("1 ");
    else
      ATLTRACE("0 ");
  }
  ATLTRACE("]\n");
}

void printVec(char* heading, long* map, long* vec, long size)
{
  long i;

  ATLTRACE("\n%s: [ ", heading);
  for (i = 0; i < size; i++) ATLTRACE("\t%d", map[vec[i]]);
  ATLTRACE("]\n");
}

void printVec(char* heading, double* vec, long size)
{
  long i;

  sprintf(buffer, "\n\n%s: [ ", heading); ATLTRACE(buffer);
  if (fs) (*fs) << "\n" << heading << ": [ ";
  for (i = 0; i < size; i++) 
  {
    sprintf(buffer, "%e\t", vec[i]); ATLTRACE(buffer);
    if (fs) (*fs) << vec[i] << " ";
  }
  if (fs) (*fs) << "]\n";
  sprintf(buffer, "]\n"); ATLTRACE(buffer);
}


void printOriginalOrder(long nEqns, long nVars, long nColIndices, long* out_columnPageNumber, 
                        long* out_cNZCols, long* out_ColIndices, long* columnOrder, long* rowOrder)
{
  long i;
  long* itCol = new long[nVars];
  for (i = 0; i < nVars; i++) itCol[columnOrder[i]] = i;
  long* itRow = new long[nEqns];
  for (i = 0; i < nEqns; i++) itRow[rowOrder[i]] = i;

  OrderMatrixColumns(nVars, nColIndices, itCol, out_ColIndices, out_ColIndices);
  OrderMatrixRows(nEqns, nVars, nColIndices, itRow, 
                  out_columnPageNumber, out_cNZCols, out_ColIndices, 
                  out_columnPageNumber, out_cNZCols, out_ColIndices);

  printNote("put matrix back in original order");
  printMat(nEqns, nVars, out_cNZCols, out_ColIndices);

  delete[] itCol;
  delete[] itRow;
}
#endif // _DEBUG


