/*
*     C B L A S _ S G B M V  Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;
enum {rmaxa=10, cmaxa=5};
enum {xmax=20, ymax=20};

void GetInputData(FILE*, int*, int*, int*, int*, int*, int*, float*,
                  float*, CBLAS_TRANSPOSE*, CBLAS_ORDER*);

void main(int argc, char *argv[])
{
      int             m, n, kl, ku, incx, incy;
      int             lda;
      float           alpha, beta;
      float           a[rmaxa][cmaxa], x[xmax], y[ymax];
      CBLAS_ORDER     order;
      CBLAS_TRANSPOSE trans;
      int             i, j;

      printf("\n     C B L A S _ S G B M V  EXAMPLE PROGRAM\n");
      
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
      GetInputData(in_file, &m, &n, &kl, &ku, &incx, &incy, &alpha, &beta,
                   &trans, &order);
      if (order == CblasRowMajor) 
         lda=cmaxa;
      else
         lda=rmaxa;
      if (trans == CblasNoTrans) { 
         GetVectorS(in_file, n, x, incx);
         GetVectorS(in_file, m, y, incy);
      } else {
         GetVectorS(in_file, m, x, incx);
         GetVectorS(in_file, n, y, incy);
      }
      GetBandArrayS(in_file, &order, kl, ku, m, n, &a[0][0], lda);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       M=%d  N=%d", m, n);
      printf("\n       ALPHA =%4.1f  BETA =%4.1f", alpha, beta);
      PrintTrans(1, &trans, NULL);
      PrintOrder(&order);
      if (trans == CblasNoTrans) { 
         PrintVectorS(0, n, x, incx, "X");
         PrintVectorS(0, m, y, incy, "Y");
      } else {
         PrintVectorS(0, m, x, incx, "X");
         PrintVectorS(0, n, y, incy, "Y");
      }
      PrintBandArrayS(&order, 0, kl, ku, m, n, &a[0][0], lda, "A");

/*      Call CBLAS_SGBMV subroutine ( C Interface )                  */
      cblas_sgbmv(order, trans, m, n, kl, ku, alpha, &a[0][0], lda,
                  x, incx, beta, y, incy);
                                                             
/*       Print output data                                      */
      printf("\n\n     OUTPUT DATA");
      if (trans == CblasNoTrans)  
         PrintVectorS(1, m, y, incy, "Y");
      else
         PrintVectorS(1, n, y, incy, "Y");
end:  return;
}

void GetInputData(FILE *in_file, int *m, int *n, int *kl, int *ku,
                  int *incx, int *incy, float *alpha, float *beta, 
                  CBLAS_TRANSPOSE *trans, CBLAS_ORDER *order)
{

/*     Read input data from input file  */
      fseek(in_file,46,0);
      fscanf(in_file,"%1d %1d %1d %1d", m, n, kl, ku);  
      fseek(in_file,28,1); 
      fscanf(in_file,"%2d %2d", incx, incy);  
      fseek(in_file,29,1); 
      fscanf(in_file,"%f %f", alpha, beta);
      fseek(in_file,27,1);
      fscanf(in_file, "%3d %3d", trans, order);
      fseek(in_file,28,1);
      return;
}