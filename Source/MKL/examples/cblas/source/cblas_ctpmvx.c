/*
*     C B L A S _ C T P M V  Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;
enum {apmax=30, xmax=10};

void GetInputData(FILE*, int*, int*, CBLAS_UPLO*, CBLAS_TRANSPOSE*,
                  CBLAS_DIAG*, CBLAS_ORDER*);

void main(int argc, char *argv[])
{
      int             n, incx;
      MKL_Complex8         ap[apmax], x[xmax];
      CBLAS_ORDER     order;
      CBLAS_UPLO      uplo;
      CBLAS_TRANSPOSE trans;
      CBLAS_DIAG      diag;

      printf("\n     C B L A S _ C T P M V  EXAMPLE PROGRAM\n");
      
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
      GetInputData(in_file, &n, &incx, &uplo, &trans, &diag, &order);

      GetVectorC(in_file, n, x, incx);
      GetVectorC(in_file, (n*(n+1))/2, ap, 1);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       N=%2d", n);
      PrintSide(NULL, &uplo, &diag);
      PrintTrans(1, &trans, NULL);
      PrintOrder(&order);
      PrintVectorC(0, n, x, incx, "X");
      PrintVectorC(1, (n*(n+1))/2, ap, 1, "AP");

/*      Call CBLAS_CTPMV subroutine ( C Interface )                  */
      cblas_ctpmv(order, uplo, trans, diag, n, ap, x, incx);
                                                             
/*       Print output data                                      */
      printf("\n\n     OUTPUT DATA");
      PrintVectorC(1, n, x, incx, "X");
end:  return;
}

void GetInputData(FILE *in_file, int *n, int *incx, CBLAS_UPLO *uplo,
                  CBLAS_TRANSPOSE *trans, CBLAS_DIAG *diag, CBLAS_ORDER *order)
{

/*     Read input data from input file                       */
      fseek(in_file,46,0);
      fscanf(in_file,"%1d", n);  
      fseek(in_file,28,1); 
      fscanf(in_file,"%2d", incx);  
      fseek(in_file,30,1); 
      fscanf(in_file, "%3d %3d %3d %3d", uplo, trans, diag, order);
      fseek(in_file,37,1);
     return;
}