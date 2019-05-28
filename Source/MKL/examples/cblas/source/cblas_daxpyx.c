/*
*     C B L A S _ D A X P Y   Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;
enum {xmax=20, ymax=20};

void GetInputData(FILE*, int*, int*, int*, double*);

void main(int argc, char *argv[])
{
      int        n, incx, incy;
      double     alpha;
      double     x[xmax], y[ymax];

      printf("\n     C B L A S _ D A X P Y  EXAMPLE PROGRAM\n");
      
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
      GetInputData(in_file, &n, &incx, &incy, &alpha);
      GetVectorD(in_file, n, x, incx);
      GetVectorD(in_file, n, y, incy);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       N=%d", n);
      printf("\n       ALPHA=%4.1f", alpha);
      PrintVectorD(0, n, x, incx, "X");
      PrintVectorD(0, n, y, incy, "Y");

/*      Call CBLAS_DAXPY subroutine ( C Interface )            */
      cblas_daxpy(n, alpha, x, incx, y, incy);
                                                             
/*       Print output data                                     */
      printf("\n\n     OUTPUT DATA");
      PrintVectorD(1, n, y, incy, "Y");
end:  return;
}

void GetInputData(FILE *in_file, int *n, int *incx, int *incy, double *alpha)
{

/*     Read input data from input file  */
      fseek(in_file,48,0);
      fscanf(in_file,"%2d %2d %2d", n, incx, incy);  
      fseek(in_file,30,1); 
      fscanf(in_file,"%lf", alpha);  
      fseek(in_file,27,1); 
      return;
}