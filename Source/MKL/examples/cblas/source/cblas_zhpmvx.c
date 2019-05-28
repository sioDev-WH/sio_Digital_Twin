/*
*     C B L A S _ Z H P M V  Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;
enum {apmax=30, xmax=10, ymax=10};

void GetInputData(FILE*, int*, int*, int*, MKL_Complex16*, MKL_Complex16*,
                  CBLAS_UPLO*, CBLAS_ORDER*);

void main(int argc, char *argv[])
{
      int             n, incx, incy;
      MKL_Complex16        alpha, beta;
      MKL_Complex16        ap[apmax], x[xmax], y[ymax];
      CBLAS_ORDER     order;
      CBLAS_UPLO      uplo;

      printf("\n     C B L A S _ Z H P M V  EXAMPLE PROGRAM\n");
      
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
      GetInputData(in_file, &n, &incx, &incy, &alpha, &beta, &uplo, &order);

      GetVectorZ(in_file, n, x, incx);
      GetVectorZ(in_file, n, y, incy);
      GetVectorZ(in_file, (n*(n+1))/2, ap, 1);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       N=%2d", n);
      printf("\n       ALPHA=(%5.1f, %5.1f )  BETA=(%5.1f, %5.1f )",
              alpha.real, alpha.imag, beta.real, beta.imag);
      PrintSide(NULL, &uplo, NULL);
      PrintOrder(&order);
      PrintVectorZ(0, n, x, incx, "X");
      PrintVectorZ(0, n, y, incy, "Y");
      PrintVectorZ(1, (n*(n+1))/2, ap, 1, "AP");

/*      Call CBLAS_ZHPMV subroutine ( C Interface )                  */
      cblas_zhpmv(order, uplo, n, &alpha, ap, x, incx, &beta,
                  y, incy);
                                                             
/*       Print output data                                      */
      printf("\n\n     OUTPUT DATA");
      PrintVectorZ(1, n, y, incy, "Y");
end:  return;
}

void GetInputData(FILE *in_file, int *n, int *incx, int *incy, 
                  MKL_Complex16 *alpha, MKL_Complex16 *beta, CBLAS_UPLO *uplo,
                  CBLAS_ORDER *order)
{

/*     Read input data from input file                       */
      fseek(in_file,46,0);
      fscanf(in_file,"%1d", n);  
      fseek(in_file,33,1); 
      fscanf(in_file,"%2d %2d", incx, incy);  
      fseek(in_file,38,1); 
      fscanf(in_file,"%lf %lf %lf %lf", &(alpha->real), &(alpha->imag),
             &(beta->real), &(beta->imag));
      fseek(in_file,24,1);
      fscanf(in_file, "%3d %3d", uplo, order);
      fseek(in_file,37,1);
     return;
}