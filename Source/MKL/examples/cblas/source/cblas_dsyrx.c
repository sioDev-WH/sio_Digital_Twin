/*
*     C B L A S _ D S Y R  Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;
enum {rmaxa=6, cmaxa=5};
enum {xmax=10, ymax=10};

void GetInputData(FILE*, int*, int*, double*, CBLAS_UPLO*, CBLAS_ORDER*);

void main(int argc, char *argv[])
{
      int             n, lda, incx;
      double          alpha;
      double          a[rmaxa][cmaxa], x[xmax];
      CBLAS_ORDER     order;
      CBLAS_UPLO      uplo;

      printf("\n     C B L A S _ D S Y R  EXAMPLE PROGRAM\n");
      
/*       Get input parameters                                  */
      if (argc == 1) {
         printf("\n You must specify in_file data file as 1-st parameter");
         goto end;
      }
      in_file_name = argv[1];

/*       Get input data                                       */
      if ( (in_file = fopen( in_file_name, "r" )) == NULL ) {     
         printf("\nERROR on OPEN '%s' with mode=%s\n",     
                in_file_name, "r");
         goto end;
      }
      GetInputData(in_file, &n, &incx, &alpha, &uplo, &order);

      if (order == CblasRowMajor) 
         lda=cmaxa;
      else
         lda=rmaxa;

      GetVectorD(in_file, n, x, incx);
      if (uplo == CblasUpper)
          GetArrayD(in_file, &order, 1, &n, &n, &a[0][0], &lda);
      else
          GetArrayD(in_file, &order, -1, &n, &n, &a[0][0], &lda);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       N=%2d", n);
      printf("\n       ALPHA=%5.1f", alpha);
      PrintSide(NULL, &uplo, NULL);
      PrintOrder(&order);
      PrintVectorD(0, n, x, incx, "X");
      if (uplo == CblasUpper)
            PrintArrayD(&order, 0, 1, &n, &n, &a[0][0], &lda, "A");
      else
            PrintArrayD(&order, 0, -1, &n, &n, &a[0][0], &lda, "A");

/*      Call CBLAS_DSYR subroutine ( C Interface )                  */
      cblas_dsyr(order, uplo, n, alpha, x, incx, &a[0][0], lda);
                                                             
/*       Print output data                                      */
      printf("\n\n     OUTPUT DATA");
      if (uplo == CblasUpper)
            PrintArrayD(&order, 1, 1, &n, &n, &a[0][0], &lda, "A");
      else
            PrintArrayD(&order, 1, -1, &n, &n, &a[0][0], &lda, "A");
end:  return;
}

void GetInputData(FILE *in_file, int *n, int *incx, double *alpha,
                  CBLAS_UPLO *uplo, CBLAS_ORDER *order)
{

/*     Read input data from input file                       */
      fseek(in_file,46,0);
      fscanf(in_file,"%1d", n);  
      fseek(in_file,26,1); 
      fscanf(in_file,"%2d", incx);  
      fseek(in_file,28,1); 
      fscanf(in_file,"%lf", alpha);
      fseek(in_file,28,1);
      fscanf(in_file, "%3d %3d", uplo, order);
      fseek(in_file,30,1);
     return;
}