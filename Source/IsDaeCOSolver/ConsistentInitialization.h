#ifndef _ConsistentInitialization_h_
#define _ConsistentInitialization_h_

class CIsDaeEsoBase;
class FlatModel;
class CIsCINlaEso;

#if 0
struct EqnStruct;
#endif

#define NULL 0


#ifdef _DEBUG
#ifndef _MATRIX_PRINT_FUNCTIONS_
#define _MATRIX_PRINT_FUNCTIONS_
void printNote(char* note);
void printVec(char* heading, long* vec, long size);
void printVec(char* heading, bool* vec, long size);
void printVec(char* heading, double* vec, long size);
void printVec(char* heading, long* map, long* vec, long size);

void printMat(long nEqns, long nVars, long* cNZ, long** Indices);
void printMat(long nEqns, long nVars, long* cNZ, long* Indices);
void printMat2(long nEqns, long nVars, long* cNZ, long* Indices);
void printMat3(long nEqns, long nVars, long* cNZ, long* colIndices, double* vals);
void printMat(long nEqns, long nVars, double** data);
void printMat(long nEqns, long nVars, bool** data);
void printMatWithOrder(long nEqns, long nVars, long* cNZ, long* Indices, long* columnOrder, long* rowOrder);
void printMatToConsole(long nEqns, long* cNZ, long* Indices);
void printEqnBlocks(long nEqns, long cBlocks, long* blockSizes, long* orderMap);
void printBlocksWithOrder(long nEqns, long* cNZ, long* Indices, long* columnOrder, long* rowOrder);
void printOriginalOrder(long nEqns, long nVars, long nColumnIndices, long* out_columnPageNumber, 
                        long* out_cRowNZ, long* out_columnIndices, long* columnOrder, long* rowOrder);
#endif // _MATRIX_PRINT_FUNCTIONS_
#endif // _DEBUG

#endif // _ConsistentInitialization_h_