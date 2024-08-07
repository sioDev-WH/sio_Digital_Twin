/*
*     C B L A S _ C T B S V  Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;
enum {rmaxa=6, cmaxa=5};
enum {xmax=20, ymax=20};

void GetInputData(FILE*, int*, int*, int*, CBLAS_UPLO*, 
				  CBLAS_TRANSPOSE*, CBLAS_DIAG*, CBLAS_ORDER*);

void main(int argc, char *argv[])
{
      int             n, k, incx;
      int             lda;
      MKL_Complex8         a[rmaxa][cmaxa], x[xmax];
      CBLAS_ORDER     order;
      CBLAS_UPLO      uplo;
      CBLAS_TRANSPOSE trans;
      CBLAS_DIAG      diag;
      int             i, j;

      printf("\n     C B L A S _ C T B S V  EXAMPLE PROGRAM\n");
      
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
      GetInputData(in_file, &n, &k, &incx, &uplo, &trans, &diag, &order);
      if (order == CblasRowMajor) 
         lda=cmaxa;
      else
         lda=rmaxa;
      GetVectorC(in_file, n, x, incx);
      if (uplo == CblasUpper) 
        GetBandArrayC(in_file, &order, 0, k, n, n, &a[0][0], lda);
      else
        GetBandArrayC(in_file, &order, k, 0, n, n, &a[0][0], lda);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       N=%1d  K=%1d", n, k);
      PrintSide(NULL, &uplo, &diag);
      PrintTrans(1, &trans, NULL);
      PrintOrder(&order);
      PrintVectorC(0, n, x, incx, "X");
      if (uplo == CblasUpper) 
        PrintBandArrayC(&order, 1, 0, k, n, n, &a[0][0], lda, "A");
      else
        PrintBandArrayC(&order, 1, k, 0, n, n, &a[0][0], lda, "A");

/*      Call CBLAS_CTBSV subroutine ( C Interface )                  */
      cblas_ctbsv(order, uplo, trans, diag, n, k, &a[0][0], lda,
                  x, incx);
                                                             
/*       Print output data                                      */
      printf("\n\n     OUTPUT DATA");
      PrintVectorC(1, n, x, incx, "X");
end:  return;
}

void GetInputData(FILE *in_file, int *n, int *k, int *incx, CBLAS_UPLO *uplo,
                  CBLAS_TRANSPOSE *trans, CBLAS_DIAG *diag, CBLAS_ORDER *order)
{

/*     Read input data from input file  */
      fseek(in_file,46,0);
      fscanf(in_file,"%1d %1d", n, k);  
      fseek(in_file,29,1); 
      fscanf(in_file,"%2d", incx);  
      fseek(in_file,30,1); 
      fscanf(in_file, "%3d %3d %3d %3d", uplo, trans, diag, order);
      fseek(in_file,37,1);
      return;
}