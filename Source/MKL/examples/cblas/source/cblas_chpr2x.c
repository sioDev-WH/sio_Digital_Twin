/*
*     C B L A S _ C H P R 2  Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;
enum {apmax=30, xmax=10, ymax=10};

void GetInputData(FILE*, int*, int*, int*, MKL_Complex8*, CBLAS_UPLO*,
                  CBLAS_ORDER*);

void main(int argc, char *argv[])
{
      int             n, incx, incy;
      MKL_Complex8         alpha;
      MKL_Complex8         ap[apmax], x[xmax], y[ymax];
      CBLAS_ORDER     order;
      CBLAS_UPLO      uplo;

      printf("\n     C B L A S _ C H P R 2  EXAMPLE PROGRAM\n");
      
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
      GetInputData(in_file, &n, &incx, &incy, &alpha, &uplo, &order);

      GetVectorC(in_file, n, x, incx);
      GetVectorC(in_file, n, y, incy);
      GetVectorC(in_file, (n*(n+1))/2, ap, 1);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       N=%2d", n);
      printf("\n       ALPHA=(%4.1f, %4.1f )", alpha.real, alpha.imag);
      PrintSide(NULL, &uplo, NULL);
      PrintOrder(&order);
      PrintVectorC(0, n, x, incx, "X");
      PrintVectorC(0, n, y, incy, "Y");
      PrintVectorC(1, (n*(n+1))/2, ap, 1, "AP");

/*      Call CBLAS_CHPR2 subroutine ( C Interface )                  */
      cblas_chpr2(order, uplo, n, &alpha, x, incx, y, incy, ap);
                                                             
/*       Print output data                                      */
      printf("\n\n     OUTPUT DATA");
      PrintVectorC(1, (n*(n+1))/2, ap, 1, "AP");
end:  return;
}

void GetInputData(FILE *in_file, int *n, int *incx, int *incy, 
                  MKL_Complex8 *alpha, CBLAS_UPLO *uplo, CBLAS_ORDER *order)
{

/*     Read input data from input file                       */
      fseek(in_file,46,0);
      fscanf(in_file,"%1d", n);  
      fseek(in_file,25,1); 
      fscanf(in_file,"%2d %2d", incx, incy);  
      fseek(in_file,30,1); 
      fscanf(in_file,"%f %f", &(alpha->real), &(alpha->imag));
      fseek(in_file,22,1);
      fscanf(in_file, "%3d %3d", uplo, order);
      fseek(in_file,29,1);
     return;
}