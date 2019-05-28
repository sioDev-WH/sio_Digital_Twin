/*
*     C B L A S _ C G E M V  Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;
enum {rmaxa=6, cmaxa=5};
enum {xmax=10, ymax=10};

void GetInputData(FILE*, int*, int*, int*, int*, MKL_Complex8*, MKL_Complex8*,
                  CBLAS_TRANSPOSE*, CBLAS_ORDER*);

void main(int argc, char *argv[])
{
      int             m, n, lda, incx, incy;
      MKL_Complex8         alpha, beta;
      MKL_Complex8         a[rmaxa][cmaxa], x[xmax], y[ymax];
      CBLAS_ORDER     order;
      CBLAS_TRANSPOSE trans;

      printf("\n     C B L A S _ C G E M V  EXAMPLE PROGRAM\n");
      
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
         GetVectorC(in_file, n, x, incx);
         GetVectorC(in_file, m, y, incy);
      } else {
         GetVectorC(in_file, m, x, incx);
         GetVectorC(in_file, n, y, incy);
      }
      GetArrayC(in_file, &order, 0, &m, &n, &a[0][0], &lda);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       M=%2d  N=%2d", m, n);
      printf("\n       ALPHA=(%5.1f, %5.1f )  BETA=(%5.1f, %5.1f )",
              alpha.real, alpha.imag, beta.real, beta.imag);
      PrintTrans(1, &trans, NULL);
      PrintOrder(&order);
      if (trans == CblasNoTrans) {
         PrintVectorC(0, n, x, incx, "X");
         PrintVectorC(0, m, y, incy, "Y");
      } else {
         PrintVectorC(0, m, x, incx, "X");
         PrintVectorC(0, n, y, incy, "Y");
      }
      PrintArrayC(&order, 0, 0, &m, &n, &a[0][0], &lda, "A");

/*      Call CBLAS_CGEMV subroutine ( C Interface )                  */
      cblas_cgemv(order, trans, m, n, &alpha, &a[0][0], lda, x, incx,
                  &beta, y, incy);
                                                             
/*       Print output data                                      */
      printf("\n\n     OUTPUT DATA");
      if (trans == CblasNoTrans)
         PrintVectorC(1, m, y, incy, "Y");
      else
         PrintVectorC(1, n, y, incy, "Y");
end:  return;
}

void GetInputData(FILE *in_file, int *m, int *n, int *incx, int *incy, 
                  MKL_Complex8 *alpha, MKL_Complex8 *beta, CBLAS_TRANSPOSE *trans,
                  CBLAS_ORDER *order)
{

/*     Read input data from input file                       */
      fseek(in_file,46,0);
      fscanf(in_file,"%1d %1d", m, n);  
      fseek(in_file,34,1); 
      fscanf(in_file,"%2d %2d", incx, incy);  
      fseek(in_file,38,1); 
      fscanf(in_file,"%f %f %f %f", &(alpha->real), &(alpha->imag),
             &(beta->real), &(beta->imag));
      fseek(in_file,24,1);
      fscanf(in_file, "%3d %3d", trans, order);
      fseek(in_file,38,1);
      return;
}