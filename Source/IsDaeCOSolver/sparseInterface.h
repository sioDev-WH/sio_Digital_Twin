#ifndef _sparseInterface_h_
#define _sparseInterface_h_

extern "C" 
{
 // int IS_spInit();
  void IS_spFormMatrix(char** Matrix, int  Size, int nnz, int* rowIndex, int* colIndex, double* pVals, int* Error);
  void IS_spDecompose(char* Matrix, int* Error);
  void IS_spReDecompose(char* Matrix, int* Error);
  void IS_spSolve(char* Matrix, int Size, double* RHS, double* Solution);
  void IS_spDestroy(char** Matrix);
}

#endif // _sparseInterface_h_