/*
*     C B L A S _ D G E M V  Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;
enum {rmaxa=6, cmaxa=5};
enum {xmax=10, ymax=10};

void GetInputData(FILE*, int*, int*, int*, int*, double*, double*,
                  CBLAS_TRANSPOSE*, CBLAS_ORDER*);

void main(int argc, char *argv[])
{
      int             m, n, lda, incx, incy;
      double          alpha, beta;
      double          a[rmaxa][cmaxa], x[xmax], y[ymax];
      CBLAS_ORDER     order;
      CBLAS_TRANSPOSE trans;

      printf("\n     C B L A S _ D G E M V  EXAMPLE PROGRAM\n");
      
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
      GetInputData(in_file, &m, &n, &incx, &incy, &alpha, &beta, &trans, &order);

      if (order == CblasRowMajor) 
         lda=cmaxa;
      else
         lda=rmaxa;

      if (trans == CblasNoTrans) {
         GetVectorD(in_file, n, x, incx);
         GetVectorD(in_file, m, y, incy);
	  } else {
         GetVectorD(in_file, m, x, incx);
         GetVectorD(in_file, n, y, incy);
      }
      GetArrayD(in_file, &order, 0, &m, &n, &a[0][0], &lda);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       M=%2d  N=%2d", m, n);
      printf("\n       ALPHA=%5.2f  BETA=%5.2f", alpha, beta);
      PrintTrans(1, &trans, NULL);
      PrintOrder(&order);
      if (trans == CblasNoTrans) {
         PrintVectorD(0, n, x, incx, "X");
         PrintVectorD(0, m, y, incy, "Y");
      } else {
         PrintVectorD(0, m, x, incx, "X");
         PrintVectorD(0, n, y, incy, "Y");
      }
      PrintArrayD(&order, 0, 0, &m, &n, &a[0][0], &lda, "A");

/*      Call CBLAS_DGEMV subroutine ( C Interface )                  */
      cblas_dgemv(order, trans, m, n, alpha, &a[0][0], lda, x, incx,
                  beta, y, incy);
                                                             
/*       Print output data                                      */
      printf("\n\n     OUTPUT DATA");
      if (trans == CblasNoTrans)
         PrintVectorD(1, m, y, incy, "Y");
      else
         PrintVectorD(1, n, y, incy, "Y");
end:  return;
}

void GetInputData(FILE *in_file, int *m, int *n, int *incx, int *incy, 
                  double *alpha, double *beta, CBLAS_TRANSPOSE *trans,
                  CBLAS_ORDER *order)
{

/*     Read input data from input file                       */
      fseek(in_file,46,0);
      fscanf(in_file,"%1d %1d", m, n);  
      fseek(in_file,26,1); 
      fscanf(in_file,"%2d %2d", incx, incy);  
      fseek(in_file,30,1); 
      fscanf(in_file,"%lf %lf", alpha, beta);
      fseek(in_file,28,1);
      fscanf(in_file, "%3d %3d", trans, order);
      fseek(in_file,30,1);
     return;
}