/*
*     C B L A S _ D T R S V  Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;
enum {rmaxa=6, cmaxa=5};
enum {xmax=10, ymax=10};

void GetInputData(FILE*, int*, int*, CBLAS_UPLO*, CBLAS_TRANSPOSE*,
				  CBLAS_DIAG*, CBLAS_ORDER*);

void main(int argc, char *argv[])
{
      int             n, lda, incx;
      double          a[rmaxa][cmaxa], x[xmax];
      CBLAS_ORDER     order;
      CBLAS_UPLO      uplo;
      CBLAS_TRANSPOSE trans;
      CBLAS_DIAG      diag;

      printf("\n     C B L A S _ D T R S V  EXAMPLE PROGRAM\n");
      
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
      PrintSide(NULL, &uplo, &diag);
      PrintTrans(1, &trans, NULL);
      PrintOrder(&order);
      PrintVectorD(0, n, x, incx, "X");
      if (uplo == CblasUpper)
            PrintArrayD(&order, 0, 1, &n, &n, &a[0][0], &lda, "A");
      else
            PrintArrayD(&order, 0, -1, &n, &n, &a[0][0], &lda, "A");

/*      Call CBLAS_DTRSV subroutine ( C Interface )                  */
      cblas_dtrsv(order, uplo, trans, diag, n, &a[0][0], lda,
                  x, incx);
                                                             
/*       Print output data                                      */
      printf("\n\n     OUTPUT DATA");
      PrintVectorD(1, n, x, incx, "X");
end:  return;
}

void GetInputData(FILE *in_file, int *n, int *incx, CBLAS_UPLO *uplo,
                  CBLAS_TRANSPOSE *trans, CBLAS_DIAG *diag, CBLAS_ORDER *order)
{

/*     Read input data from input file                       */
      fseek(in_file,46,0);
      fscanf(in_file,"%1d", n);  
      fseek(in_file,29,1); 
      fscanf(in_file,"%2d", incx);  
      fseek(in_file,31,1); 
      fscanf(in_file, "%3d %3d %3d %3d", uplo, trans, diag, order);
      fseek(in_file,38,1);
     return;
}