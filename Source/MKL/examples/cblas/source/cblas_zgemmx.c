/*
*     C B L A S _ Z G E M M  Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;
enum {rmaxa=6, cmaxa=5};
enum {rmaxb=6, cmaxb=5};
enum {rmaxc=6, cmaxc=5};

void GetInputData(FILE*, int*, int*, int*, MKL_Complex16*, MKL_Complex16*,
                  CBLAS_TRANSPOSE*, CBLAS_TRANSPOSE*,
                  CBLAS_ORDER*); 

void main(int argc, char *argv[])
{
      int             m, n, k;
      int             lda, ldb, ldc;
      MKL_Complex16        alpha, beta;
      MKL_Complex16        a[rmaxa][cmaxa], b[rmaxb][cmaxb], c[rmaxc][cmaxc];
      CBLAS_ORDER     order;
      CBLAS_TRANSPOSE transA, transB;

      printf("\n     C B L A S _ Z G E M M  EXAMPLE PROGRAM\n");
      
/*       Get input parameters                                  */
	  if (argc == 1) {
		  printf("\n You must specify in_file data file as 1-st parameter");
		  goto end;
	  }
	  in_file_name = argv[1];

/*       Get input data                                       */
      if( (in_file = fopen( in_file_name, "r" )) == NULL ) {     
        printf("\nERROR on OPEN '%s' with mode=%s\n",     
                in_file_name, "r");
		goto end;
	  }
      GetInputData(in_file, &m, &n, &k, &alpha, &beta, &transA, 
		           &transB, &order);
	  if (order == CblasRowMajor) {
		  lda=cmaxa;
		  ldb=cmaxb;
		  ldc=cmaxc;
	  } else {
		  lda=rmaxa;
		  ldb=rmaxb;
		  ldc=rmaxc;
      }
      if (transA == CblasNoTrans)
         GetArrayZ(in_file, &order, 0, &m, &k, &a[0][0],  &lda);
      else
         GetArrayZ(in_file, &order, 0, &k, &m, &a[0][0], &lda);
      if (transB == CblasNoTrans)
         GetArrayZ(in_file, &order, 0, &k, &n, &b[0][0], &ldb);
      else
	     GetArrayZ(in_file, &order, 0, &n, &k, &b[0][0], &ldb);
      GetArrayZ(in_file, &order, 0, &m, &n, &c[0][0], &ldc);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       M=%1d  N=%1d  K=%1d", m, n, k);
      printf("\n       ALPHA =(%5.1f,%5.1f )  BETA =(%5.1f,%5.1f )",
              alpha.real, alpha.imag, beta.real, beta.imag);
      PrintTrans(2, &transA, &transB);
      PrintOrder(&order);
      if (transA == CblasNoTrans)
         PrintArrayZ(&order, 0, 0, &m, &k, &a[0][0], &lda, "A");
      else
         PrintArrayZ(&order, 0, 0, &k, &m, &a[0][0], &lda, "A");
      if (transB == CblasNoTrans)
         PrintArrayZ(&order, 0, 0, &k, &n, &b[0][0], &ldb, "B");
      else
         PrintArrayZ(&order, 0, 0, &n, &k, &b[0][0], &ldb, "B");
      PrintArrayZ(&order, 0, 0, &m, &n, &c[0][0], &ldc, "C");

/*      Call ZGEMM subroutine ( C Interface )                  */
      cblas_zgemm(order, transA, transB, m, n, k, &alpha,
		          &a[0][0], lda, &b[0][0], ldb, &beta, &c[0][0], ldc);
                                                             
/*       Print output data                                      */
      printf("\n\n     OUTPUT DATA");
      PrintArrayZ(&order, 1, 0, &m, &n, &c[0][0], &ldc, "C");
end:  return;
}

void GetInputData(FILE *in_file, int *m, int *n, int *k, 
				  MKL_Complex16 *alpha, MKL_Complex16 *beta, 
                  CBLAS_TRANSPOSE *transA, CBLAS_TRANSPOSE *transB,
				  CBLAS_ORDER *order)
{
/*     Read input data from input file                       */

	  fseek(in_file,46,0);
	  fscanf(in_file,"%1d %1d %1d", m, n, k);  
      fseek(in_file,37,1); 
	  fscanf(in_file,"%lf %lf %lf %lf", &(*alpha).real, &(*alpha).imag,
             &(*beta).real, &(*beta).imag);
	  fseek(in_file,23,1);
      fscanf(in_file, "%3d %3d %3d", transA, transB, order);
      fseek(in_file,45,1);
      return;
}