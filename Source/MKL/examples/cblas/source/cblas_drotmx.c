/*
*     C B L A S _ D R O T M   Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;
enum {xmax=20, ymax=20};

void GetInputData(FILE*, int*, int*, int*);

void main(int argc, char *argv[])
{
      int        n, incx, incy;
      double     param[5];
      double     x[xmax], y[ymax];

      printf("\n     C B L A S _ D R O T M  EXAMPLE PROGRAM\n");
      
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
      GetInputData(in_file, &n, &incx, &incy);
      GetVectorD(in_file, 5, param, 1);
      GetVectorD(in_file, n, x, incx);
      GetVectorD(in_file, n, y, incy);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       N=%d", n);
      PrintVectorD(1, 5, param, 1, "PARAM");
      PrintVectorD(0, n, x, incx, "X");
      PrintVectorD(0, n, y, incy, "Y");

/*      Call CBLAS_DROTM subroutine ( C Interface )            */
      cblas_drotm(n, x, incx, y, incy, param);
                                                             
/*       Print output data                                     */
      printf("\n\n     OUTPUT DATA");
      PrintVectorD(1, n, x, incx, "X");
      PrintVectorD(1, n, y, incy, "Y");
end:  return;
}

void GetInputData(FILE *in_file, int *n, int *incx, int *incy)
{

/*     Read input data from input file  */
      fseek(in_file,46,0);
      fscanf(in_file,"%d", n);  
      fseek(in_file,22,1); 
      fscanf(in_file,"%d %d", incx, incy);  
      fseek(in_file,29,1); 
      return;
}