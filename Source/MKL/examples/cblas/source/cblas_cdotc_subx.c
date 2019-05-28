/*
*     C B L A S _ C D O T C _ S U B   Example Program Text ( C Interface )
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
      MKL_Complex8    x[xmax], y[ymax];
      MKL_Complex8    res;

      printf("\n     C B L A S _ C D O T C _ S U B  EXAMPLE PROGRAM\n");
      
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
      GetVectorC(in_file, n, x, incx);
      GetVectorC(in_file, n, y, incy);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       N=%d", n);
      PrintVectorC(0, n, x, incx, "X");
      PrintVectorC(0, n, y, incy, "Y");

/*      Call CBLAS_CDOTC_SUB subroutine ( C Interface )        */
      cblas_cdotc_sub(n, x, incx, y, incy, &res);
                                                             
/*       Print output data                                     */
      printf("\n\n     OUTPUT DATA");
      printf("\n       CDOTC_SUB = (%7.3f,%7.3f)", res.real, res.imag);
end:  return;
}

void GetInputData(FILE *in_file, int *n, int *incx, int *incy)
{

/*     Read input data from input file  */
      fseek(in_file,54,0);
      fscanf(in_file,"%d", n);  
      fseek(in_file,20,1); 
      fscanf(in_file,"%2d %2d", incx, incy);  
      fseek(in_file,25,1); 
      return;
}