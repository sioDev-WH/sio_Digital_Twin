#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>

#ifdef _DEBUG
#include <crtdbg.h>
#endif // _DEBUG

#include <iostream.h>
#include <fstream.h>
//#include <stdlib.h>
#include <time.h>
#include "OnDaeCOSolverExport.h"

class ModelVarMap;

typedef struct equationNode{

	long nVars;	// Egdes
	long *varIndices;
	long blockNumber;
	long order;
	long stackPtr;
	long nStackPosition;
	bool bHasBeenOnStack;
	bool bOrdered;
	bool bIsRoot;
	bool bIsOnStack;

} EQ_NODE;


typedef struct equationSet{
	long nEqns;
	equationNode *equations; // Array
	long nBlocks;
	long* blockSizes;
	long *orderMap;
} EQ_SET;

class equationPath{
public:
	EQ_SET* equationSet;
public:
	equationPath(EQ_SET* eqSet){equationSet = eqSet;}
  ~equationPath() { } 
	void add(long nEqIndex);
	void backtrack();
	void removeBlock();
};

class equationStack{

public:
	long nCount;
	EQ_SET* pSet;
	equationPath* pPath;
	long* items;
	long order;
public:
	equationStack(EQ_SET* eqSet, equationPath* pPath);
	~equationStack();
	void augmentPath(long index);
	void extractBlock();
};


void TransposeVector(long* s_vec, long s_size, long*& itVec, long it_size);

void TransposeMatrix(long nRows, long nCols, long nIndices, 
                     long* in_PageNumber, long* in_cNZ, long* in_Indices, 
                     long* out_PageNumber, long* out_cNZ, long* out_Indices);

void OrderMatrixColumns(long nVars, long nColumnIndices, long* columnTranspose,
                        long* in_Indices, long* out_Indices);

void OrderMatrixRows(long nEqns, long nVars, long nIndices, long* rowTranspose, 
                     long* in_PageNumber, long* in_cNZ, long* in_Indices,
                     long* out_PageNumber, long* out_cNZ, long* out_Indices);

void RandomVector(long n, long* vec);

void OrderVector(long n, long* colTranspose, long* in_vec, long* out_vec);

void ONDAECOSOLVER_API tarjan(long nEqns, long *columnIndices, long nColumnIndices,
			long *columnPageNumber,	long *cRowNZ,	long* orderMap,
			long& cBlocks, long* blockSizes);

bool assignVariables(long nEqns, long nVars, long* cNZ, long* spRowPage, long* Indices, long* assignedEqn);

void assignVariable(long equationIndex, long nEqns, long nVars, bool** edgeMatrix, bool* varColor,
					          bool* eqnColor, long* assignedEqn, bool& bPathFound);



#ifdef _DEBUG
#ifndef _MATRIX_PRINT_FUNCTIONS_
#define _MATRIX_PRINT_FUNCTIONS_
void printNote(char* note);
void printVec(char* heading, long* vec, long size);
void printVec(char* heading, bool* vec, long size);
void printVec(char* heading, long* map, long* vec, long size);
void printMat2(long nEqns, long nVars, long* cNZ, long* Indices);
void printMat3(long nEqns, long nVars, long* cNZ, long* colIndices, double* vals);
void printMat(long nEqns, long nVars, long* cNZ, long* Indices);
void printMat(long nEqns, long nVars, double** data);
void printMat(long nEqns, long nVars, bool** data);
void printMat(long nEqns, long nVars, long* cNZ, long** Indices);
void printMatWithOrder(long nEqns, long nVars, long* cNZ, long* Indices, long* columnOrder, long* rowOrder);
void printMatToConsole(long nEqns, long* cNZ, long* Indices);
void printEqnBlocks(long nEqns, long cBlocks, long* blockSizes, long* orderMap);
void printBlocksWithOrder(long nEqns, long* cNZ, long* Indices, long* columnOrder, long* rowOrder);
void printOriginalOrder(long nEqns, long nVars, long nColumnIndices, long* out_columnPageNumber, 
                        long* out_cRowNZ, long* out_columnIndices, long* columnOrder, long* rowOrder);
#endif // _MATRIX_PRINT_FUNCTIONS_
#endif // _DEBUG
