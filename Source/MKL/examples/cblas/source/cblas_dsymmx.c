/*
*     C B L A S _ D S Y M M  Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;
enum {rmaxa=6, cmaxa=5};
enum {rmaxb=6, cmaxb=5};
enum {rmaxc=6, cmaxc=5};

void GetInputData(FILE*, int*, int*, double*, double*, CBLAS_SIDE*,
                  CBLAS_UPLO*, CBLAS_ORDER*);

void main(int argc, char *argv[])
{
      int             m, n;
      int             lda, ldb, ldc;
      double          alpha, beta;
      double          a[rmaxa][cmaxa], b[rmaxb][cmaxb],
                      c[rmaxc][cmaxc];
      CBLAS_ORDER     order;
      CBLAS_SIDE      side;
      CBLAS_UPLO      uplo;

      printf("\n     C B L A S _ D S Y M M  EXAMPLE PROGRAM\n");
      
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
      GetInputData(in_file, &m, &n, &alpha, &beta, &side, 
                   &uplo, &order);
      if (order == CblasRowMajor) {
         lda=cmaxa;
         ldb=cmaxb;
         ldc=cmaxc;
      } else {
         lda=rmaxa;
         ldb=rmaxb;
         ldc=rmaxc;
      }
      if (side == CblasLeft) 
        if (uplo == CblasUpper)
          GetArrayD(in_file, &order, 1, &m, &m, &a[0][0], &lda);
        else
          GetArrayD(in_file, &order, -1, &m, &m, &a[0][0], &lda);
      else
        if (uplo == CblasUpper)
          GetArrayD(in_file, &order, 1, &n, &n, &a[0][0], &lda);
        else
          GetArrayD(in_file, &order, -1, &n, &n, &a[0][0], &lda);
      GetArrayD(in_file, &order, 0, &m, &n, &b[0][0], &ldb);
      GetArrayD(in_file, &order, 0, &m, &n, &c[0][0], &ldc);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       M=%1d  N=%1d", m, n);
      printf("\n       ALPHA=%6.2f  BETA=%6.2f", alpha, beta);
      PrintSide(&side, &uplo, NULL);
      PrintOrder(&order);
      if (side == CblasLeft)
         if (uplo == CblasUpper)
            PrintArrayD(&order, 0, 1, &m, &m, &a[0][0], &lda, "A");
         else
            PrintArrayD(&order, 0, -1, &m, &m, &a[0][0], &lda, "A");
      else
         if (uplo == CblasUpper)
            PrintArrayD(&order, 0, 1, &n, &n, &a[0][0], &lda, "A");
         else
            PrintArrayD(&order, 0, -1, &n, &n, &a[0][0], &lda, "A");
      PrintArrayD(&order, 0, 0, &m, &n, &b[0][0], &ldb, "B");
      PrintArrayD(&order, 0, 0, &m, &n, &c[0][0], &ldc, "C");

/*      Call CBLAS_DSYMM subroutine ( C Interface )                  */
      cblas_dsymm(order, side, uplo, m, n, alpha, &a[0][0], lda,
                  &b[0][0], ldb, beta, &c[0][0], ldc);
                                                             
/*       Print output data                                      */
      printf("\n\n     OUTPUT DATA");
      PrintArrayD(&order, 1, 0, &m, &n, &c[0][0], &ldc, "C");
end:  return;
}

void GetInputData(FILE *in_file, int *m, int *n, double *alpha, 
                  double *beta, CBLAS_SIDE *side, CBLAS_UPLO *uplo,
                  CBLAS_ORDER *order)
{

/*     Read input data from input file                       */
      fseek(in_file,46,0);
      fscanf(in_file,"%1d %1d", m, n);  
      fseek(in_file,35,1); 
      fscanf(in_file,"%lf %lf", alpha, beta);
      fseek(in_file,36,1);
      fscanf(in_file, "%3d %3d %3d", side, uplo, order);
      fseek(in_file,41,1);
     return;
}