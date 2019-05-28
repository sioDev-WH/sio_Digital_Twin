#define  YES    1
#define  NO     0

#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define spINSIDE_SPARSE
#include "spConfig.h"
#undef spINSIDE_SPARSE
#include "spmatrix.h"
#include <time.h>
#ifndef CLOCKS_PER_SEC
#define CLOCKS_PER_SEC 60
#endif

/* Declarations that should be in stdio.h. */
extern char *malloc();
extern free();
extern exit();

#define  BOOLEAN  int
#define  ALLOC(type,number) ((type *)malloc((unsigned)(sizeof(type)*(number))))
typedef  spREAL  RealNumber, *RealVector;
static RealNumber AbsThreshold = (RealNumber)0, RelThreshold = (RealNumber)0;
static RealNumber aZero= (RealNumber)0;
static BOOLEAN DiagPivoting = DIAGONAL_PIVOTING;
// WAH 8/11 static char  *Matrix = NULL;


int IS_spInit();
void IS_spFormMatrix(char** Matrix, int  Size, int nnz, int* rowIndex, int*
colIndex, double* pVals, int* Error);
void IS_spDecompose(char* Matrix, int* Error);
void IS_spReDecompose(char* Matrix, int* Error);
void IS_spSolve(char* Matrix, int Size, double* RHS, double* Solution);
void IS_spDestroy(char** Matrix);

double Time()
{
    return ((double)clock() / CLOCKS_PER_SEC);
}

void IS_spFormMatrix(char** Matrix, int  Size, int nnz, int* rowIndex, int* colIndex, double* pVals, int* Error)
{
  RealNumber *pElement;
  RealNumber *pInitInfo;
  int sp_nnz;
  int i;

  if (*Matrix == NULL)
    *Matrix = spCreate( Size, 0 /* real */, Error );  // Instantiation of Matrix structure -- no data memory is allocated yet

  sp_nnz = nnz +1; // element at rowIndex=0; and colIndex=0; must be set to zero
  for(i=0;i<sp_nnz;i++)
  {
    pElement = spGetElement( *Matrix, rowIndex[i], colIndex[i]);  // This actually allocates space of nnz within the matrix
    pInitInfo = (RealNumber *)spGetInitInfo( pElement );  // Use this in the automatic formation function
    if (pInitInfo == NULL)
      spInstallInitInfo( pElement, (char *) &(pVals[i]) ); 
    else
      *pInitInfo = pVals[i];
  }
}



// The following is more useful when "Fill in the matrix is more complicated than assigning values
static int
IS_spInit( pElement, pInitInfo, Row, Col)

RealNumber *pElement;
char *pInitInfo;
int Row, Col;
{
/* Begin `Init'. */
    *pElement = *(RealNumber *)pInitInfo;
    return 0;
}

void IS_spDecompose(char* Matrix, int* Error)
{
  // Currently our iteration matrices are scrambled during assembly
  // So, we may not benifit from DiagPivoting even if IM is diagnolizable or Banded!!
  // We may map through BLT (Tarjan) initially and then reuse the map over and over..
  (void)spInitialize(Matrix, IS_spInit);
  *Error = spOrderAndFactor( Matrix,         // First decompose -- most expensive operation call only once for each stage.
                            NULL, 
                            RelThreshold, 
                            AbsThreshold,
                            DiagPivoting);
}

void IS_spReDecompose(char* Matrix, int* Error)
{
  (void)spInitialize(Matrix, IS_spInit);
  *Error = spFactor(Matrix);
}

void IS_spSolve(char* Matrix, int Size, double* RHS, double* Solution)
{
  double *sp_Solution;
  int i;

  sp_Solution = ALLOC( double, (Size));
  spSolve(Matrix, RHS, sp_Solution);

  for(i=0;i<Size;i++)
    Solution[i] = sp_Solution[i];

  if(sp_Solution) free(sp_Solution);
}

void IS_spDestroy(char** Matrix)
{
  if (*Matrix)
  {
    spDestroy(*Matrix);  
    *Matrix = NULL;
  }
}

