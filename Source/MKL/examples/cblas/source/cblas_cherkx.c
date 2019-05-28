/*
*     C B L A S _ C H E R K  Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;
enum {rmaxa=6, cmaxa=5};
enum {rmaxc=6, cmaxc=5};

void GetInputData(FILE*, int*, int*, float*, float*, CBLAS_UPLO*,
				  CBLAS_TRANSPOSE*, CBLAS_ORDER*);

void main(int argc, char *argv[])
{
      int             n, k;
      int             lda, ldc;
      float           alpha, beta;
      MKL_Complex8         a[rmaxa][cmaxa], c[rmaxc][cmaxc];
      CBLAS_ORDER     order;
      CBLAS_TRANSPOSE trans;
      CBLAS_UPLO      uplo;

      printf("\n     C B L A S _ C H E R K  EXAMPLE PROGRAM\n");
      
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
      GetInputData(in_file, &n, &k, &alpha, &beta, &uplo,
                   &trans, &order);
      if (order == CblasRowMajor) {
         lda=cmaxa;
         ldc=cmaxc;
      } else {
         lda=rmaxa;
         ldc=rmaxc;
      }
      if (trans == CblasNoTrans) 
          GetArrayC(in_file, &order, 0, &n, &k, &a[0][0], &lda);
      else
          GetArrayC(in_file, &order, 0, &k, &n, &a[0][0], &lda);
      if (uplo == CblasUpper) 
        GetArrayC(in_file, &order, 1, &n, &n, &c[0][0], &ldc);
      else
        GetArrayC(in_file, &order, -1, &n, &n, &c[0][0], &ldc);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       N=%1d  K=%1d", n, k);
      printf("\n       ALPHA =%4.1f  BETA =%4.1f", alpha, beta);
      PrintSide(NULL, &uplo, NULL);
	  PrintTrans(1, &trans, NULL);
      PrintOrder(&order);
      if (trans == CblasNoTrans) 
          PrintArrayC(&order, 0, 0, &n, &k, &a[0][0], &lda, "A");
      else
          PrintArrayC(&order, 0, 0, &k, &n, &a[0][0], &lda, "A");
      if (uplo == CblasUpper) 
        PrintArrayC(&order, 0, 1, &n, &n, &c[0][0], &ldc, "C");
      else
        PrintArrayC(&order, 0, -1, &n, &n, &c[0][0], &ldc, "C");

/*      Call CBLAS_CHERK subroutine ( C Interface )                  */
      cblas_cherk(order, uplo, trans, n, k, alpha, &a[0][0], lda,
                  beta, &c[0][0], ldc);
                                                             
/*       Print output data                                      */
      printf("\n\n     OUTPUT DATA");
      if (uplo == CblasUpper) 
        PrintArrayC(&order, 1, 1, &n, &n, &c[0][0], &ldc, "C");
      else
        PrintArrayC(&order, 1, -1, &n, &n, &c[0][0], &ldc, "C");
end:  return;
}

void GetInputData(FILE *in_file, int *n, int *k, float *alpha, 
                  float *beta, CBLAS_UPLO *uplo, CBLAS_TRANSPOSE *trans,
                  CBLAS_ORDER *order)
{

/*     Read input data from input file  */
      fseek(in_file,46,0);
      fscanf(in_file,"%1d %1d", n, k);  
      fseek(in_file,27,1); 
      fscanf(in_file,"%f %f", alpha, beta);
      fseek(in_file,30,1);
      fscanf(in_file, "%3d %3d %3d", uplo, trans, order);
      fseek(in_file,33,1);
      return;
}