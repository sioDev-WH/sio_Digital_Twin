/*
*     C B L A S _ D D O T   Example Program Text ( C Interface )
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
      double     x[xmax], y[ymax];
      double     res;

      printf("\n     C B L A S _ D D O T  EXAMPLE PROGRAM\n");
      
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
      GetVectorD(in_file, n, x, incx);
      GetVectorD(in_file, n, y, incy);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       N=%d", n);
      PrintVectorD(0, n, x, incx, "X");
      PrintVectorD(0, n, y, incy, "Y");

/*      Call CBLAS_DDOT subroutine ( C Interface )            */
      res = cblas_ddot(n, x, incx, y, incy);
                                                             
/*       Print output data                                     */
      printf("\n\n     OUTPUT DATA");
      printf("\n       DDOT = %8.3f", res);
end:  return;
}

void GetInputData(FILE *in_file, int *n, int *incx, int *incy)
{

/*     Read input data from input file  */
      fseek(in_file,45,0);
      fscanf(in_file,"%d", n);  
      fseek(in_file,25,1); 
      fscanf(in_file,"%d %d", incx, incy);  
      fseek(in_file,32,1); 
      return;
}