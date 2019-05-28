/*
*     C B L A S _ S G E R  Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;
enum {rmaxa=6, cmaxa=5};
enum {xmax=10, ymax=10};

void GetInputData(FILE*, int*, int*, int*, int*, float*, CBLAS_ORDER*);

void main(int argc, char *argv[])
{
      int             m, n, lda, incx, incy;
      float           alpha;
      float           a[rmaxa][cmaxa], x[xmax], y[ymax];
      CBLAS_ORDER     order;

      printf("\n     C B L A S _ S G E R   EXAMPLE PROGRAM\n");
      
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
      GetInputData(in_file, &m, &n, &incx, &incy, &alpha, &order);

      if (order == CblasRowMajor) 
         lda=cmaxa;
      else
         lda=rmaxa;

      GetVectorS(in_file, m, x, incx);
      GetVectorS(in_file, n, y, incy);
      GetArrayS(in_file, &order, 0, &m, &n, &a[0][0], &lda);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       M=%2d  N=%2d", m, n);
      printf("\n       ALPHA=%5.1f", alpha);
      PrintOrder(&order);
      PrintVectorS(0, m, x, incx, "X");
      PrintVectorS(0, n, y, incy, "Y");
      PrintArrayS(&order, 0, 0, &m, &n, &a[0][0], &lda, "A");

/*      Call CBLAS_SGER subroutine ( C Interface )                  */
      cblas_sger(order, m, n, alpha, x, incx, y, incy,
                 &a[0][0], lda);
                                                             
/*       Print output data                                      */
      printf("\n\n     OUTPUT DATA");
      PrintArrayS(&order, 1, 0, &m, &n, &a[0][0], &lda, "A");
end:  return;
}

void GetInputData(FILE *in_file, int *m, int *n, int *incx, int *incy, 
                  float *alpha, CBLAS_ORDER *order)
{

/*     Read input data from input file                       */
      fseek(in_file,46,0);
      fscanf(in_file,"%1d %1d", m, n);  
      fseek(in_file,26,1); 
      fscanf(in_file,"%2d %2d", incx, incy);  
      fseek(in_file,30,1); 
      fscanf(in_file,"%f", alpha);
      fseek(in_file,27,1);
      fscanf(in_file, "%3d", order);
      fseek(in_file,27,1);
     return;
}