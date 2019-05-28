#include <iostream.h>
#include <iomanip.h>
#include "triangularization.h"
#include "ModelNavMaps.h"
#include "OnDaeCOSolverMacros.h"


#if 0
#ifdef _DEBUG
#include "crtdbg.h"
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)   
#endif
#endif

equationStack::equationStack(EQ_SET* eqSet, equationPath* pPath) {
	pSet = eqSet;
	pPath=pPath; 
	items = new long[pSet->nEqns];
	order = 0;
}
equationStack::~equationStack(){
	if(items) delete [] items;
}

void init(EQ_NODE& node){
		node.blockNumber = -1;
		node.bIsOnStack = false;
		node.bHasBeenOnStack = false;
		node.bIsRoot = false;
		node.bOrdered = false;	// equivalent to blockNumber = -1;
		node.nStackPosition = -1;
}

void tarjan(long nEqns,
			long *columnIndices,
			long nColumnIndices,
			long *columnPageNumber,
			long *cRowNZ,
			long* orderMap,
			long& cBlocks,
			long* blockSizes){

	long i,j;
	long nVars;
	EQ_SET pEqSet;
	equationStack *pStack;
	equationPath *pPath;

	pEqSet.nEqns = nEqns;
	pEqSet.equations = new EQ_NODE[nEqns];
	pPath = (equationPath*) new equationPath(&pEqSet);
	pStack = (equationStack*) new equationStack(&pEqSet,pPath);

	for(i=0;i<nEqns;i++){
		pEqSet.equations[i].nVars = nVars = cRowNZ[i];
		pEqSet.equations[i].varIndices = new long[nVars];
		for(j=0;j<nVars;j++)
		   pEqSet.equations[i].varIndices[j] = columnIndices[columnPageNumber[i]+j];
		init(pEqSet.equations[i]);
	}
	pEqSet.nBlocks = 0;
	pEqSet.orderMap = orderMap;
	pEqSet.blockSizes = blockSizes;
	pStack->nCount = -1;
	
	for(i=0;i<nEqns;i++)
		if(!pEqSet.equations[i].bOrdered)
			pStack->augmentPath(i);
	cBlocks = pEqSet.nBlocks;

  // cleanup
	for(i=0;i<nEqns;i++)
		if (pEqSet.equations[i].varIndices) delete [] pEqSet.equations[i].varIndices;
  
  delete [] pEqSet.equations;
  delete pPath;
  delete pStack;
}

void equationStack::augmentPath(long current){

	long j;
	long nVars;
	long target;
	long blockCounter;

	items[nCount+1] = current;
	pSet->equations[current].nStackPosition = nCount+1;
	pSet->equations[current].bHasBeenOnStack = true;
	pSet->equations[current].bIsOnStack = true;
	pSet->equations[current].stackPtr = nCount+1;
	nCount++;
	
	if((nVars = pSet->equations[current].nVars) > 0){
		for(j=0;j<nVars;j++){
			target = pSet->equations[current].varIndices[j];
			if(pSet->equations[target].bIsOnStack){
				if(pSet->equations[target].stackPtr 
					< pSet->equations[current].stackPtr)
					pSet->equations[current].stackPtr
					= pSet->equations[target].stackPtr;
			}
			else if(!pSet->equations[target].bHasBeenOnStack){
				augmentPath(target); 
				if(pSet->equations[target].stackPtr < pSet->equations[current].stackPtr)
					pSet->equations[current].stackPtr = pSet->equations[target].stackPtr;
			}
		}
		// Is it a root node (pointing to itself)? Then extract the block.
		if(pSet->equations[current].stackPtr >= pSet->equations[current].nStackPosition){
			pSet->blockSizes[pSet->nBlocks] = nCount - pSet->equations[current].nStackPosition + 1;
			blockCounter = pSet->blockSizes[pSet->nBlocks] -1;
			do{
				pSet->equations[items[nCount]].order = order;
				pSet->orderMap[order] = items[nCount];
				pSet->equations[items[nCount]].bOrdered = true;
				pSet->equations[items[nCount]].blockNumber = pSet->nBlocks;
				pSet->equations[items[nCount]].bIsOnStack = false;

				if(items[nCount] == current) pSet->equations[current].bIsRoot = true;
				nCount--;
				order++;
			}while(blockCounter--);
			pSet->nBlocks++;
		}
	}
}

const long FIXED_ASSIGNMENT = 1000000000;

bool assignVariables(
  long nEqns, 
  long nVars,
	long* cNZ,
  long* spRowPage,
  long* Indices,
	long* assignedEqn) 
{
  long i, j, k, iVar;
  long equationIndex;
  bool* varColor = new bool[nVars];
  bool* eqnColor = new bool[nEqns];
  bool** edgeMatrix = new bool*[nEqns];
  bool bColorLocal = false;
  bool bAlreadyAssigned;
  bool bPathFound = true;

  // build edge matrix
  for (i = 0; i < nEqns; i++)
  {
    edgeMatrix[i] = (bool*) new bool[nVars];
    //_ASSERTE(edgeMatrix[i] != NULL);
    for (j = 0; j < nVars; j++) edgeMatrix[i][j] = false;
  }

  // read data into edgeMatrix
  k = 0;
  for (i = 0; i < nEqns; i++)
  {
    for (j = 0; j < cNZ[i]; j++) edgeMatrix[i][Indices[k++]] = true;
  }

  bool bReturnPathFound = true;
  for (equationIndex = 0; equationIndex < nEqns; equationIndex++)
  {
    // see if equation is already assigned to an appropriate variable
    bAlreadyAssigned = false;
    for (iVar = 0; iVar < nVars; iVar++) 
    {
      if (assignedEqn[iVar] == equationIndex)
      {
        for (j = 0; j < cNZ[equationIndex]; j++)
        {
          if (Indices[spRowPage[equationIndex] + j] == iVar)
          {
            bAlreadyAssigned = true;
            break;
          }
        }
        break;
      }
    }
    
    if (!bAlreadyAssigned)
    {
      for (i = 0; i < nEqns; i++) eqnColor[i] = false;
      for (i = 0; i < nVars; i++) varColor[i] = false;
      assignVariable(equationIndex, nEqns, nVars, edgeMatrix, varColor, eqnColor, assignedEqn,	bPathFound);
      if (!bPathFound) bReturnPathFound = false;
    }
  }

  // cleanup
  for (i = 0; i < nEqns; i++) delete[] edgeMatrix[i];
  delete[] edgeMatrix;
  delete[] varColor; 
  delete[] eqnColor;

  return bReturnPathFound;
}


void assignVariable(long		equationIndex,
            long    nEqns,
					  long		nVars,
					  bool**	edgeMatrix,
					  bool*		varColor,
					  bool*		eqnColor,
					  long*		assignedEqn,	  // [in, out]
					  bool&		bPathFound){

	long j,k;

  bPathFound = false;
	eqnColor[equationIndex]=true;
	//for(j=0;j<nEqns;j++) // KAB changed December 11
  for(j=0;j<nVars;j++)
		if(edgeMatrix[equationIndex][j])
			if(assignedEqn[j]==-1)
      {
				bPathFound=true;
				assignedEqn[j]=equationIndex;
        return;
			}
	for(j=0;j<nVars;j++)
		if(edgeMatrix[equationIndex][j] && varColor[j]==false)
    {
			varColor[j]=true;
      if (assignedEqn[j] != FIXED_ASSIGNMENT)
      {
			  k = assignedEqn[j];
			  assignVariable(k, nEqns, nVars, edgeMatrix, varColor, eqnColor, assignedEqn, bPathFound);
			  if(bPathFound)
        {
				  assignedEqn[j] = equationIndex;
          return;
			  }
      }
		}
	return;
}



////////////////////////////////////////////////////////////////////
// TransposeVector
//
// calculates the transpose of a vector. (in [5] = 2, out [2] = 5)
// itVec is allocated automatically if NULL
//
void TransposeVector(long* s_vec, long s_size, long*& itVec, long it_size)
{
  long i;
  long* srcVec = NULL;
  bool bDelete = false;

  if (itVec == NULL) itVec = new long[it_size];
  if (itVec == s_vec)
  {
    srcVec = new long[s_size];
    for (i = 0; i < s_size; i++) srcVec[i] = s_vec[i];
    bDelete = true;
  }
  else
  {
    srcVec = s_vec;
  }

  for (i = 0; i < it_size; i++)
    itVec[i] = -1;

  for (i = 0; i < s_size; i++)
  {
    if (srcVec[i] >= 0 && srcVec[i] < it_size)
      itVec[srcVec[i]] = i;
  }

  if (bDelete) DESTROY_VECTOR(srcVec)
}


/*****************************************************************
*
*  matrix transform functions
*
*****************************************************************/



void TransposeMatrix(long nRows, long nCols, long nIndices, 
                     long* in_PageNumber, long* in_cNZ, long* in_Indices, 
                     long* out_PageNumber, long* out_cNZ, long* out_Indices)
{
  long i, j, k;
  long iRow, iCol;
  long* PageNumber = NULL;
  long* cNZ = NULL;
  long* Indices = NULL;
  bool bDelete = false;

  if (in_PageNumber == out_PageNumber ||
      in_cNZ == out_cNZ ||
      in_Indices == out_Indices)
  {
    bDelete = true;
    PageNumber = new long[nRows];
    cNZ = new long[nRows];
    Indices = new long[nIndices];
    for (i = 0; i < nRows; i++)
    {
      PageNumber[i] = in_PageNumber[i];
      cNZ[i] = in_cNZ[i];
    }
    for (i = 0; i < nIndices; i++)
      Indices[i] = in_Indices[i];
  }
  else
  {
    PageNumber = in_PageNumber;
    cNZ = in_cNZ;
    Indices = in_Indices;
  }

  // initialize output counts to 0
  for (i = 0; i < nCols; i++) 
    out_cNZ[i] = 0;

  // get the counts for each column
  for (i = 0; i < nIndices; i++) 
    out_cNZ[Indices[i]]++;

  // calculate the output page numbers, and reset the counts
  for (i = 0, j = 0; i < nCols; i++) 
  {
    out_PageNumber[i] = j;
    j += out_cNZ[i];
    out_cNZ[i] = 0;
  }
  
  k = 0;                                
  for (iRow = 0; iRow < nRows; iRow++)
  {
    for (j = 0; j < cNZ[iRow]; j++)      // j iterates over column indices in row i
    {
      iCol = Indices[k++];
      out_Indices[out_PageNumber[iCol] + out_cNZ[iCol]++] = iRow;
    }
  }

  // cleanup
  if (bDelete)
  {
    delete[] PageNumber;
    delete[] cNZ;
    delete[] Indices;
  }
}


/////////////////////////////////////////////////////////////////
// OrderMatrixColumns
//
// - Sorts columns using a colTranspose reorder vector
// - Uses an intermediate transpose vector that swaps value for position
//   in the original transpose vector.  There may be a more efficient way of doing this.
// - Only needs column indices vector because row counts are starting positions aren't
//   modified or required.
// - Limited by nColumnIndices.  in_Indices can be a larger matrix.
// - in_Indices is buffered if input matrix == output matrix
//
/////////////////////////////////////////////////////////////////
void OrderMatrixColumns(long nVars, long nColumnIndices, 
                        long* columnTranspose, long* in_Indices, long* out_Indices)
{
  long i;
  long* source_Indices = NULL;

  if (in_Indices == out_Indices)
  {
    source_Indices = new long[nColumnIndices];
    for (i = 0; i < nColumnIndices; i++) source_Indices[i] = in_Indices[i];
  }
  else
  {
    source_Indices = in_Indices;
  }

  long* it = new long[nVars]; // intermediate transpose
  for (i = 0; i < nVars; i++) 
    it[columnTranspose[i]] = i;

  for (i = 0; i < nColumnIndices; i++)
    out_Indices[i] = it[source_Indices[i]];

  if (in_Indices == out_Indices) delete[] source_Indices;
  delete[] it;
}

/////////////////////////////////////////////////////////////////
// OrderMatrixRows
//
// - Sorts rows using a rowTranspose reorder vector
// - Uses an intermediate transpose vector that swaps value for position
//   in the original transpose vector.  There may be a more efficient way of doing this.
// - Writes the original column indices vector into an nXn buffer, and writes the indices
//   back into the output column vector.  The nXn vector could get expensive on memory.
// - matrix is buffered so input matrix can be the output matrix
//
/////////////////////////////////////////////////////////////////
void OrderMatrixRows(long nEqns, long nVars, long nIndices, long* rowTranspose, 
                     long* in_PageNumber, long* in_cNZ, long* in_Indices,
                     long* out_PageNumber, long* out_cNZ, long* out_Indices)
{
  long* PageNumber = NULL;
  long* cNZ = NULL;
  long* Indices = NULL;
  long i, j, k;
  long iPageStart, iPageEnd;
  bool bDelete = false;

  if (in_PageNumber == out_PageNumber ||
      in_cNZ == out_cNZ ||
      in_Indices == out_Indices)
  {
    bDelete = true;
    PageNumber = new long[nEqns];
    cNZ = new long[nEqns];
    Indices = new long[nIndices];
    for (i = 0; i < nEqns; i++)
    {
      PageNumber[i] = in_PageNumber[i];
      cNZ[i] = in_cNZ[i];
    }
    for (i = 0; i < nIndices; i++)
      Indices[i] = in_Indices[i];
  }
  else
  {
    PageNumber = in_PageNumber;
    cNZ = in_cNZ;
    Indices = in_Indices;
  }

  // copy the members
  k = 0;
  for (i = 0; i < nEqns; i++)
  {
    out_PageNumber[i] = k;
    out_cNZ[i] = cNZ[rowTranspose[i]];
    iPageStart = PageNumber[rowTranspose[i]];
    iPageEnd = PageNumber[rowTranspose[i]] + cNZ[rowTranspose[i]];
    for (j = iPageStart; j < iPageEnd; j++)
      out_Indices[k++] = Indices[j];
  }

  // cleanup
  if (bDelete)
  {
    delete[] PageNumber;
    delete[] cNZ;
    delete[] Indices;
  }
}

/////////////////////////////////////////////////////////////////
// RandomVector
//
// - Generates a random vector of length n.  Assumes vec is already declared.
//
/////////////////////////////////////////////////////////////////

void RandomVector(long n, long* vec)
{
  long i, j;
  long testVal;
  bool bUsed;

  srand( (unsigned)time( NULL ) );
  for (i = 0; i < n; i++)
  {
    do
    {
      bUsed = false;
      testVal = (long) ((n * rand())/RAND_MAX);
      for (j = 0; j < i; j++)
      {
        if (vec[j] == testVal) 
        {
          bUsed = true;
          break;
        }
      }
    } while (bUsed);
    vec[i] = testVal;
  }
}

/////////////////////////////////////////////////////////////////
// OrderVector
//
// - Writes in_vec to out_vec in order defined by colTranspose
// - Buffers in_vec so in_vec can equal out_vec
//
/////////////////////////////////////////////////////////////////
void OrderVector(long n, long* colTranspose, long* in_vec, long* out_vec)
{
  long i;
  long* it = new long[n];
  long* source;
  bool bAllocatedSource = false;

  if (in_vec == out_vec)
  {
    source = new long[n];
    for (i = 0; i < n; i++) source[i] = in_vec[i];
    bAllocatedSource = true;
  }
  else
  {
    source = in_vec;
  }

  for (i = 0; i < n; i++) it[colTranspose[i]] = i;
  for (i = 0; i < n; i++) out_vec[it[i]] = source[i];

  // cleanup
  if (bAllocatedSource) delete[] source;
  delete[] it;
}



	