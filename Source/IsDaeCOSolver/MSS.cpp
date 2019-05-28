#include <valarray>
#include "triangularization.h"
#include "OnDaeCOSolverMacros.h"
#include "MSS.h"

#if 0
#ifdef _DEBUG
#include "crtdbg.h"
#define new new( _NORMAL_BLOCK, __FILE__, __LINE__)   
#endif
#endif

using namespace std;
typedef valarray<int> INTVECTOR;
typedef valarray<bool> BOOLVECTOR;
typedef	valarray<BOOLVECTOR> INCIDENCE;


#define MAX_NO_CALLS 10
#define IMAX(a,b) (a > b ? a : b)

#ifdef _DEBUG
#ifndef _MATRIX_PRINT_FUNCTIONS_
#define _MATRIX_PRINT_FUNCTIONS_
void printNote(char* note);
void printVec(char* heading, long* vec, long size);
void printVec(char* heading, bool* vec, long size);
void printMat(long nEqns, long nVars, long* cNZ, long* Indices);
void printMatWithOrder(long nEqns, long nVars, long* cNZ, long* Indices, long* columnOrder, long* rowOrder);
void printMatToConsole(long nEqns, long* cNZ, long* Indices);
void printEqnBlocks(long nEqns, long cBlocks, long* blockSizes, long* orderMap);
void printBlocksWithOrder(long nEqns, long* cNZ, long* Indices, long* columnOrder, long* rowOrder);
void printOriginalOrder(long nEqns, long nVars, long nColumnIndices, long* out_columnPageNumber, 
                        long* out_cRowNZ, long* out_columnIndices, long* columnOrder, long* rowOrder);
#endif // _MATRIX_PRINT_FUNCTIONS_
#endif // _DEBUG


void ShowIntArray(valarray<int> &theArray);
void ShowBoolArray(valarray<bool> &theArray);
long calculateMSS(
          long&	nAugmentedVars,        // (2*nVars+nAlgebraic) = M
				  long& nEqns,			           // (nVars+nAlgebraic) = N
				  INTVECTOR& VAL,			         // Variable Association List
				  INCIDENCE& edgeMatrix,	     // Rows==Equations, Cols==AugmentedVars (#cols is different for different equations)
				  INTVECTOR& assignedEqn,
				  INTVECTOR& EAL);

void iCalculateIndex(
  long nAugmentedEqns,
  long nAugmentedVars, 
  long edgeList_nColIndices, 
  long* edgeList_spRowPage, 
  long* edgeList_cNZCols, 
  long* edgeList_ColIndices,
  long* VAL,
  long* assignedEqn,
  short* differentialIndex);

void CalcVarIndex(
  long iVar, 
  long* iDiffOrder, 
  long* island_ColIndices, 
  long* island_cNZRow, 
  long* island_spRowPage,
  long* iDiffIndex);


long iCalculateMSS(
  long& nAugmentedVars,               // [in, out]
  long& nEqns,                        // [in, out]
  long* in_VAL,                       // [in]
  long* in_edgeList_cRowNZ,           // [in]
  long* in_edgeList_ColIndices,       // [in]
  long*& out_VAL,                     // [out]
  long*& out_EAL,                     // [out]
  long& out_edgeList_nColumnIndices,  // [out]
  long*& out_edgeList_spRowPage,      // [out]
  long*& out_edgeList_cRowNZ,         // [out]
  long*& out_edgeList_ColIndices,     // [out]
  long*& out_assignedEqn,             // [out]
  short*& out_differentialIndex)      // [out]
{
  long iReturn = iMSS_OK;
  long i, j, k;
	INTVECTOR VAL;
  INTVECTOR EAL;
  INCIDENCE edgeList;
  INTVECTOR assignedEqn;
  long edgeListSize;
  
  long in_nAugmentedEqns = nEqns;
  long in_nAugmentedVars = nAugmentedVars;

  // convert input variables
  VAL.resize(nAugmentedVars);
  for (i = 0; i < nAugmentedVars; i++) VAL[i] = in_VAL[i];

  k = 0;
  edgeList.resize(nEqns);
  for (i = 0; i < nEqns; i++)
  {
		edgeList[i].resize(nAugmentedVars);
    for (j = 0; j < nAugmentedVars; j++)
      edgeList[i][j] = false;

    for (j = 0; j < in_edgeList_cRowNZ[i]; j++) 
      edgeList[i][in_edgeList_ColIndices[k++]] = true;
  }

  // initialize internal variables
  assignedEqn.resize(nAugmentedVars);
  for (i = 0; i < nAugmentedVars; i++) assignedEqn[i] = -1;

  EAL.resize(nEqns);
  for (i = 0; i < nEqns; i++) EAL[i] = -1;

////////////////////////////////////////////////////////////////////////////////////////
// call to MSS code
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

  iReturn = calculateMSS(nAugmentedVars, nEqns, VAL, edgeList, assignedEqn, EAL);
  if (iReturn != iMSS_OK) goto clean_up;

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////

  out_assignedEqn = new long[nAugmentedVars];
  for (i = 0; i < nAugmentedVars; i++) out_assignedEqn[i] = assignedEqn[i];

  out_VAL = new long[nAugmentedVars];
  for (i = 0; i < nAugmentedVars; i++) out_VAL[i] = VAL[i];

  out_EAL = new long[nEqns];
  for (i = 0; i < nEqns; i++) out_EAL[i] = EAL[i];

  out_differentialIndex = new short[nAugmentedVars];
  for (i = 0; i < nAugmentedVars; i++) out_differentialIndex[i] = 1;

  edgeListSize = edgeList.size();
  out_edgeList_spRowPage = new long[edgeListSize];
  out_edgeList_cRowNZ = new long[edgeListSize];
  out_edgeList_nColumnIndices = 0;
  for (i = 0; i < edgeListSize; i++)
  {
    out_edgeList_cRowNZ[i] = 0;
    out_edgeList_spRowPage[i] = out_edgeList_nColumnIndices;
    for (j = 0; j < edgeList[i].size(); j++)
    {
      if (edgeList[i][j]) 
      {
        out_edgeList_cRowNZ[i]++;
        out_edgeList_nColumnIndices++;
      }
    }
  }

  out_edgeList_ColIndices = new long[out_edgeList_nColumnIndices];
  k = 0;
  for (i = 0; i < edgeListSize; i++)
  {
    for (j = 0; j < edgeList[i].size(); j++)
      if (edgeList[i][j]) out_edgeList_ColIndices[k++] = j;
  }

  iCalculateIndex(
    nEqns,
    nAugmentedVars, 
    out_edgeList_nColumnIndices, 
    out_edgeList_spRowPage, 
    out_edgeList_cRowNZ, 
    out_edgeList_ColIndices, 
    out_VAL,
    out_assignedEqn,
    out_differentialIndex);

clean_up:

  // TODO: come up with some good error messages
  return iReturn;
}

void graphAugmentPath(long		equationIndex,
					  long		nActiveVars,
					  INCIDENCE	edgeMatrix,
					  BOOLVECTOR&	varColor,
					  BOOLVECTOR&	eqnColor,
					  INTVECTOR&	assignedEqn,
					  INTVECTOR		activeVarIndexMap,	
					  bool&		bPathFound){

		long j,k;

	eqnColor[equationIndex]=true;
	for(j=0;j<nActiveVars;j++)
		if(edgeMatrix[equationIndex][j])
			if(assignedEqn[activeVarIndexMap[j]]==-1){
				bPathFound=true;
				assignedEqn[activeVarIndexMap[j]]=equationIndex;
				return;
			}
	for(j=0;j<nActiveVars;j++)
		if(edgeMatrix[equationIndex][j] && varColor[j]==0){
			varColor[j]=true;
			k = assignedEqn[activeVarIndexMap[j]];
			graphAugmentPath(k,nActiveVars,edgeMatrix,
							   varColor,eqnColor,assignedEqn,activeVarIndexMap,bPathFound);
			if(bPathFound){
				assignedEqn[activeVarIndexMap[j]] = equationIndex;
				return;
			}
		}
	return;
}

long calculateMSS(long&	nAugmentedVars, // (2*nVars+nAlgebraic) = M
				  long&  nEqns,			        // (nVars+nAlgebraic) = N
				  INTVECTOR& VAL,			      // Variable Association List
				  INCIDENCE& edgeMatrix,	  // Rows==Equations, Cols==AugmentedVars (#cols is different for different equations)
				  INTVECTOR& assignedEqn,
				  INTVECTOR& EAL)
{
  long iReturn = iMSS_OK;
	long N,M;
	long i,j,ii;
	long eqnIndex, varIndex;
	long exposedEqn;
	long nActiveEqns,nActiveVars;
	bool bPathFound;

	INTVECTOR varVector;
	INTVECTOR eqnVector;
	BOOLVECTOR	varColor;
	BOOLVECTOR	eqnColor;
	valarray<bool>  varMask;
	INCIDENCE activeEdges;
	valarray<bool> maskedEdge;
	INTVECTOR	activeVarIndexMap;
  // the following static variable must be replaced with a class variable
	static long nCalls = 0;
	INTVECTOR eqnDerivativeOrder;

	M = nAugmentedVars;
	N = nEqns;
	
	assignedEqn.resize(M);
	varMask.resize(M);
	activeVarIndexMap.resize(M);
	
	EAL.resize(N);
	eqnDerivativeOrder.resize(N);
	for(i=0;i<N;i++) eqnDerivativeOrder[i]=0;

	for(varIndex=0;varIndex<nAugmentedVars;varIndex++)
		varMask[varIndex]=true;

	for(eqnIndex=0;eqnIndex<nEqns;eqnIndex++)
  {
		exposedEqn = eqnIndex;
		nCalls=0;
		do{
			j=0;
			for(varIndex=0;varIndex<VAL.size();varIndex++) 
				if(VAL[varIndex] != -1) varMask[varIndex]=false;
				else activeVarIndexMap[j++]=varIndex;
#if 0 //#ifdef _DEBUG
			printNote("\nExposed Equation\n");
			ShowIntArray(VAL);
			printNote("Mask");
			ShowBoolArray(varMask);
      printNote("EAL");
			ShowIntArray(EAL);
			printNote("ASSIGN");
			ShowIntArray(assignedEqn);
#endif
			nActiveEqns = edgeMatrix.size();
			activeEdges.resize(nActiveEqns);
			for(i=0;i<nActiveEqns;i++)
				activeEdges[i] = (edgeMatrix[i])[varMask];
#if 0 //#ifdef _DEBUG
			printNote("Active Edges");
			for(i=0;i<activeEdges.size();i++) ShowBoolArray(activeEdges[i]);
#endif
			nActiveVars=activeEdges[0].size(); 

			varColor.resize(nActiveVars);
			eqnColor.resize(nActiveEqns);
			for(i=0;i<eqnColor.size();i++) eqnColor[i] = false;
			for(j=0;j<varColor.size();j++) varColor[j] = false;
			
			bPathFound=false;

			graphAugmentPath(exposedEqn,
							nActiveVars,
							activeEdges,
							varColor,
							eqnColor,
							assignedEqn,
							activeVarIndexMap,
							bPathFound);

			if(!bPathFound)
      {
				for(j=0;j<varColor.size();j++) if(varColor[j] != 0)
        {
					M++;
					assignedEqn.resize(M);
					assignedEqn[M-1] = -1;
					varMask.resize(M);
					varMask[M-1] = true;
					activeVarIndexMap.resize(M);
					VAL.resize(M);
					VAL[M-1] = -1;
					VAL[activeVarIndexMap[j]] = M-1;
				}
				for(i=0;i<eqnColor.size();i++) if(eqnColor[i] != 0)
        {
					N++;
					edgeMatrix.resize(N);
					for(ii=0;ii<N;ii++) if(edgeMatrix[ii].size() < M) edgeMatrix[ii].resize(M);
					EAL.resize(N);
					EAL[N-1] = -1;
					EAL[i] = N-1;
					eqnDerivativeOrder.resize(N);
					eqnDerivativeOrder[N-1] = eqnDerivativeOrder[i] + 1;
					for(j=0;j<edgeMatrix[i].size();j++)
          {
						if(edgeMatrix[i][j])
            {
							edgeMatrix[N-1][j] = true;
							edgeMatrix[N-1][VAL[j]] = true;
						}
          }
				}
				for(j=0;j<varColor.size();j++) if(varColor[j] != 0)
        {
					assignedEqn[VAL[activeVarIndexMap[j]]] = EAL[assignedEqn[activeVarIndexMap[j]]];
				}
				exposedEqn = EAL[exposedEqn];
			}

#if 0
      ShowIntArray(assignedEqn);
#endif
			nCalls++;
    } while(!bPathFound && nCalls < MAX_NO_CALLS);

 	  if (nCalls == MAX_NO_CALLS)
      iReturn = iMSS_MaxCalls;  // Warning: Inconsistent set of equations or Index is larger than 10

	}

#if 0
  printNote("\nVAL\n");
	ShowIntArray(VAL);
  printNote("\nEAL\n");
	ShowIntArray(EAL);
  printNote("\nASSIGN\n");
	ShowIntArray(assignedEqn);
  printNote("\nDiffIndex\n");
	ShowIntArray(differentialIndex);
#endif
  // return the resized vectors
  nAugmentedVars = M;
  nEqns = N;

  return iReturn;
}


void iCalculateIndex(
  long nAugmentedEqns,
  long nAugmentedVars, 
  long edgeList_nColIndices, 
  long* edgeList_spRowPage, 
  long* edgeList_cNZCols, 
  long* edgeList_ColIndices,
  long* VAL,
  long* assignedEqn,
  short* differentialIndex)
{
  long i, j, k;
  long island_cBlocks = 0;
  long island_nColIndices = 0;
  long iIsland = 0;
  long spIsland = 0;
  long iVar, iEqn, iOtherVar;
  long MaxDiffOrder;
  long nVars = 0;

  //////////////////////////////////////////////////////////////////////////////////////////////
  // 1. Using the final MSS bipartite graph run Tarjan to isolate its islands.
  //

  // take only the most derived variables
  // NOTE: VAL entries are -1 for most derived variables, otherwise, they point to the more derived variable
  for (i = 0; i < nAugmentedVars; i++) if (VAL[i] < 0) nVars++;


  long* VarMap               = new long[nVars];
  long* itVarMap             = NULL;             // allocated in transpose function below
  long* iDiffOrder           = new long[nVars];
  long* iVarRoot             = new long[nVars];
  long* island_ColIndices    = new long[edgeList_nColIndices];
  long* island_cNZRow        = new long[nVars];
  long* island_spRowPage     = new long[nVars];
  bool* islandLeaders        = new bool[nVars];
  long* island_orderMap      = new long[nVars];
  long* island_blockSizes    = new long[nVars];
  long* itVAL                = NULL;             // allocated in transpose function below
  long* diffIndex            = new long[nVars]; // define diff index in terms of map

  // nVars is the number of most differentiated variables (-1 in VAL)
  // VarMap[nVars] maps most derived variables to indices in nAugmentedVars
  // itVarMap[nAugmentedVars] maps nAugmentedVars to indices in nVars 
  for (i = 0, j = 0; i < nAugmentedVars; i++) if (VAL[i] < 0) VarMap[j++] = i;
  TransposeVector(VarMap, nVars, itVarMap, nAugmentedVars);

  for (i = 0; i < nVars; i++) diffIndex[i] = -1;

  // determine the differential order of each variable
  TransposeVector(VAL, nAugmentedVars, itVAL, nAugmentedVars);
  for (i = 0; i < nVars; i++)
  {
    k = 0;
    iVarRoot[i] = VarMap[i];
    j = itVAL[VarMap[i]];
    if (j >= 0) 
    { 
      do 
      { 
        iVarRoot[i] = j;
        j = itVAL[j]; 
        k++;
      } while (j >= 0); 
    }
    iDiffOrder[i] = k;
  }

  // iVarRoot[nVars] is the variable index in nAugmentedVars that is the root of the differentiation
  // iDiffOrder[nVars] is the number of times the variable has been differentiated.
#if 0
  printMat(nAugmentedEqns, nAugmentedVars, edgeList_cNZCols, edgeList_ColIndices);
  printVec("VarMap", VarMap, nVars);
  printVec("iVarRoot", iVarRoot, nVars);
  printVec("iDiffOrder", iDiffOrder, nVars);
#endif

  for (i = 0; i < nAugmentedVars; i++)
  {
    iVar = itVarMap[i];  // iVar = Variable index in nVars
    if (iVar >= 0)
    {
      // variable i in nAugmentedVars (iVar in nVars) is a most derived variable
      island_cNZRow[iVar] = 0;
      island_spRowPage[iVar] = island_nColIndices;
      iEqn = assignedEqn[i];
      // search the variables referenced by the equation assigned to iVar
      for (j = 0; j < edgeList_cNZCols[iEqn]; j++)
      {
        iOtherVar = itVarMap[edgeList_ColIndices[edgeList_spRowPage[iEqn]+j]];
        // iOtherVar is another variable referenced in the equation assigned to iVar
        // iOtherVar will be -1 (ignored) if it is not in nVars (a most derived variable)
        if (iOtherVar >= 0)
        {
          // add iOtherVar to the variable to variable edge list for iVar
          island_ColIndices[island_nColIndices++] = iOtherVar;
          island_cNZRow[iVar]++;
        }
      }
    }
  }

#if 0
  ATLTRACE("\nCount: %d", island_nColIndices);
  printMat2(nVars, nVars, island_cNZRow, island_ColIndices);
#endif

  // block triangularize the island variable to variable edge list.
  tarjan(nVars, island_ColIndices, island_nColIndices, island_spRowPage, island_cNZRow, 
    island_orderMap, island_cBlocks, island_blockSizes);

  // *** now have the islands identified for the variables
  k = 0;
  for (i = 0; i < nVars; i++) islandLeaders[i] = false;
  spIsland = 0;
  for (iIsland = 0; iIsland < island_cBlocks; iIsland++)
  {
    // find the highest derivative variables in each island
    MaxDiffOrder = 0;
    for (i = 0; i < island_blockSizes[iIsland]; i++)
    {
      iVar = island_orderMap[i+spIsland];
      MaxDiffOrder = IMAX(iDiffOrder[iVar], MaxDiffOrder);
    }

    for (i = 0; i < island_blockSizes[iIsland]; i++)
    {
      iVar = island_orderMap[i+spIsland];
      if (MaxDiffOrder == iDiffOrder[iVar])
      {
        islandLeaders[iVar] = true;
        diffIndex[iVar] = 1;     
      }
    }
    spIsland += island_blockSizes[iIsland];
  }

  spIsland = 0;
  for (iIsland = 0; iIsland < island_cBlocks; iIsland++)
  {
    for (i = 0; i < island_blockSizes[iIsland]; i++)
    {
      iVar = island_orderMap[i+spIsland];
      if (diffIndex[iVar] < 0)
        CalcVarIndex(iVar, iDiffOrder, island_ColIndices, island_cNZRow, island_spRowPage, diffIndex);
    }
    spIsland += island_blockSizes[iIsland];
  }

#if 0
  for (i = 0; i < nVars; i++)
    ATLTRACE("\n%d %d", i, diffIndex[i]);
#endif

#if 0
  for (i = 0; i < nVars; i++)
    ATLTRACE("\n %d %d", i, differentialIndex[i]);
#endif

  // write out results
  for (i = 0; i < nVars; i++)
    differentialIndex[iVarRoot[i]] = (short) (diffIndex[i]);

#if 0
  for (i = 0; i < nVars; i++)
    ATLTRACE("\n %d %d", i, differentialIndex[i]);
#endif

  // cleanup
  DESTROY_VECTOR(VarMap)
  DESTROY_VECTOR(itVarMap)
  DESTROY_VECTOR(iDiffOrder)
  DESTROY_VECTOR(iVarRoot)
  DESTROY_VECTOR(island_ColIndices)
  DESTROY_VECTOR(island_cNZRow)
  DESTROY_VECTOR(island_spRowPage)
  DESTROY_VECTOR(islandLeaders)
  DESTROY_VECTOR(island_orderMap)
  DESTROY_VECTOR(island_blockSizes)
  DESTROY_VECTOR(itVAL)
  DESTROY_VECTOR(diffIndex)
}

void CalcVarIndex(
  long iVar, 
  long* iDiffOrder, 
  long* island_ColIndices, 
  long* island_cNZRow, 
  long* island_spRowPage,
  long* iDiffIndex)
{
  long iOtherVar;
  long iMaxDiffIndex = 0;
  long iMaxDiffVar = -1;
  long i;

  for (i = 0; i < island_cNZRow[iVar]; i++)
  {
    iOtherVar = island_ColIndices[island_spRowPage[iVar]+i];
    if (iOtherVar != iVar)
    {
      if (iDiffIndex[iOtherVar] < 0)
        CalcVarIndex(iOtherVar, iDiffOrder, island_ColIndices, island_cNZRow, island_spRowPage, iDiffIndex);

      if (iDiffIndex[iOtherVar] > iMaxDiffIndex)
      {
        iMaxDiffIndex = iDiffIndex[iOtherVar];
        iMaxDiffVar = iOtherVar;
      }
    }
  }

  if (iMaxDiffVar >= 0)
    iDiffIndex[iVar] = iDiffIndex[iMaxDiffVar] + iDiffOrder[iMaxDiffVar] - iDiffOrder[iVar];
  else
    iDiffIndex[iVar] = 1;
}


void ShowBoolArray(valarray<bool> &theArray)
{
  long* v = new long[theArray.size()];
  int theIterator;
  
  for (theIterator =0; theIterator != theArray.size();theIterator++)
    v[theIterator] = (long) theArray[theIterator];
  
#if 0
  printVec("", v, theArray.size());
#endif
}

void ShowIntArray(valarray<int> &theArray)
{
  long* v = new long[theArray.size()];
  int theIterator;
  
  for (theIterator =0; theIterator != theArray.size();theIterator++)
    v[theIterator] = (long) theArray[theIterator];
  
#if 1
  printVec("", v, theArray.size());
#endif
}
