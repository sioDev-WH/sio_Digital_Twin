/*
*     C B L A S _ S T R M M  Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;
enum {rmaxa=6, cmaxa=5};
enum {rmaxb=6, cmaxb=5};

void GetInputData(FILE*, int*, int*, float*, CBLAS_SIDE*, CBLAS_UPLO*,
				  CBLAS_DIAG*, CBLAS_TRANSPOSE*, CBLAS_ORDER*);

void main(int argc, char *argv[])
{
      int             m, n;
      int             lda, ldb;
      float           alpha;
      float           a[rmaxa][cmaxa], b[rmaxb][cmaxb];
      CBLAS_ORDER     order;
      CBLAS_TRANSPOSE transA;
      CBLAS_SIDE      side;
      CBLAS_UPLO      uplo;
      CBLAS_DIAG      diag;

      printf("\n     C B L A S _ S T R M M  EXAMPLE PROGRAM\n");
      
/*       Get input parameters                                  */
	  if (argc == 1) {
		  printf("\n You must specify in_file data file as 1-st parameter");
		  goto end;
	  }
	  in_file_name = argv[1];

/*       Get input data                                       */
      if ((in_file = fopen( in_file_name, "r" )) == NULL ) {     
        printf("\nERROR on OPEN '%s' with mode=%s\n",     
                in_file_name, "r");
		goto end;
	  }
      GetInputData(in_file, &m, &n, &alpha, &side, &uplo,
                   &diag, &transA, &order);
	  if (order == CblasRowMajor) {
		  lda=cmaxa;
		  ldb=cmaxb;
	  } else {
		  lda=rmaxa;
		  ldb=rmaxb;
      }
      if (side == CblasLeft) 
        if (uplo == CblasUpper)
          GetArrayS(in_file, &order, 1, &m, &m, &a[0][0], &lda);
        else
          GetArrayS(in_file, &order, -1, &m, &m, &a[0][0], &lda);
      else
        if (uplo == CblasUpper)
          GetArrayS(in_file, &order, 1, &n, &n, &a[0][0], &lda);
        else
          GetArrayS(in_file, &order, -1, &n, &n, &a[0][0], &lda);
      GetArrayS(in_file, &order, 0, &m, &n, &b[0][0], &ldb);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       M=%1d  N=%1d", m, n);
      printf("\n       ALPHA =%4.1f", alpha);
      PrintSide(&side, &uplo, &diag);
	  PrintTrans(1, &transA, NULL);
      PrintOrder(&order);
      if (side == CblasLeft)
		 if (uplo == CblasUpper)
            PrintArrayS(&order, 0, 1, &m, &m, &a[0][0], &lda, "A");
		 else
            PrintArrayS(&order, 0, -1, &m, &m, &a[0][0], &lda, "A");
	  else
		 if (uplo == CblasUpper)
            PrintArrayS(&order, 0, 1, &n, &n, &a[0][0], &lda, "A");
		 else
            PrintArrayS(&order, 0, -1, &n, &n, &a[0][0], &lda, "A");
      PrintArrayS(&order, 0, 0, &m, &n, &b[0][0], &ldb, "B");

/*      Call CBLAS_STRMM subroutine ( C Interface )                  */
      cblas_strmm(order, side, uplo, transA, diag, m, n,
	              alpha, &a[0][0], lda, &b[0][0], ldb);
                                                             
/*       Print output data                                      */
      printf("\n\n     OUTPUT DATA");
      PrintArrayS(&order, 1, 0, &m, &n, &b[0][0], &ldb, "B");
end:  return;
}

void GetInputData(FILE *in_file, int *m, int *n, float *alpha, 
                  CBLAS_SIDE *side, CBLAS_UPLO *uplo, CBLAS_DIAG *diag,
                  CBLAS_TRANSPOSE *transA, CBLAS_ORDER *order)
{

/*     Read input data from input file  */
      fseek(in_file,47,0);
	  fscanf(in_file,"%1d %1d", m, n);  
      fseek(in_file,34,1); 
	  fscanf(in_file,"%f", alpha);
      fseek(in_file,35,1);
      fscanf(in_file, "%3d %3d %3d %3d %3d", side, uplo, transA,
		     diag, order);
      fseek(in_file,45,1);
      return;
}