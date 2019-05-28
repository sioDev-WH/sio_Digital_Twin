/*
*     C B L A S _ S S B M V  Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;
enum {rmaxa=6, cmaxa=5};
enum {xmax=20, ymax=20};

void GetInputData(FILE*, int*, int*, int*, int*, float*, float*,
                  CBLAS_UPLO*, CBLAS_ORDER*);

void main(int argc, char *argv[])
{
      int             n, k, incx, incy;
      int             lda;
      float           alpha, beta;
      float           a[rmaxa][cmaxa], x[xmax], y[ymax];
      CBLAS_ORDER     order;
      CBLAS_UPLO      uplo;
      int             i, j;

      printf("\n     C B L A S _ S S B M V  EXAMPLE PROGRAM\n");
      
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
      GetInputData(in_file, &n, &k, &incx, &incy, &alpha, &beta, &uplo,
                   &order);
      if (order == CblasRowMajor) 
         lda=cmaxa;
      else
         lda=rmaxa;
      GetVectorS(in_file, n, x, incx);
      GetVectorS(in_file, n, y, incy);
      if (uplo == CblasUpper) 
        GetBandArrayS(in_file, &order, 0, k, n, n, &a[0][0], lda);
      else
        GetBandArrayS(in_file, &order, k, 0, n, n, &a[0][0], lda);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       N=%1d  K=%1d", n, k);
      printf("\n       ALPHA =%4.1f  BETA =%4.1f", alpha, beta);
      PrintSide(NULL, &uplo, NULL);
      PrintOrder(&order);
      PrintVectorS(0, n, x, incx, "X");
      PrintVectorS(0, n, y, incy, "Y");
      if (uplo == CblasUpper) 
        PrintBandArrayS(&order, 1, 0, k, n, n, &a[0][0], lda, "A");
      else
        PrintBandArrayS(&order, 1, k, 0, n, n, &a[0][0], lda, "A");

/*      Call CBLAS_SSBMV subroutine ( C Interface )                  */
      cblas_ssbmv(order, uplo, n, k, alpha, &a[0][0], lda, x, incx,
                  beta, y, incy);
                                                             
/*       Print output data                                      */
      printf("\n\n     OUTPUT DATA");
      PrintVectorS(1, n, y, incy, "Y");
end:  return;
}

void GetInputData(FILE *in_file, int *n, int *k, int *incx, int *incy,
                  float *alpha, float *beta, CBLAS_UPLO *uplo,
                  CBLAS_ORDER *order)
{

/*     Read input data from input file  */
      fseek(in_file,46,0);
      fscanf(in_file,"%1d %1d", n, k);  
      fseek(in_file,27,1); 
      fscanf(in_file,"%2d %2d", incx, incy);  
      fseek(in_file,31,1); 
      fscanf(in_file,"%f %f", alpha, beta);
      fseek(in_file,30,1);
      fscanf(in_file, "%3d %3d", uplo, order);
      fseek(in_file,30,1);
      return;
}