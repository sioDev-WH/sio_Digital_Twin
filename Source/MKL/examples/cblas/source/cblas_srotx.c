/*
*     C B L A S _ S R O T   Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;
enum {xmax=20, ymax=20};

void GetInputData(FILE*, int*, int*, int*, float*, float*);

void main(int argc, char *argv[])
{
      int        n, incx, incy;
      float      c, s;
      float      x[xmax], y[ymax];

      printf("\n     C B L A S _ S R O T  EXAMPLE PROGRAM\n");
      
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
      GetInputData(in_file, &n, &incx, &incy, &c, &s);
      GetVectorS(in_file, n, x, incx);
      GetVectorS(in_file, n, y, incy);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       N=%d", n);
      printf("\n       C=%5.2f  S=%5.2f", c, s);
      PrintVectorS(0, n, x, incx, "X");
      PrintVectorS(0, n, y, incy, "Y");

/*      Call CBLAS_SROT subroutine ( C Interface )            */
      cblas_srot(n, x, incx, y, incy, c, s);
                                                             
/*       Print output data                                     */
      printf("\n\n     OUTPUT DATA");
      PrintVectorS(1, n, x, incx, "X");
      PrintVectorS(1, n, y, incy, "Y");
end:  return;
}

void GetInputData(FILE *in_file, int *n, int *incx, int *incy, 
                  float *c, float *s)
{

/*     Read input data from input file  */
      fseek(in_file,46,0);
      fscanf(in_file,"%d", n);  
      fseek(in_file,22,1); 
      fscanf(in_file,"%d %d", incx, incy);  
      fseek(in_file,29,1); 
      fscanf(in_file,"%f %f", c, s);  
      fseek(in_file,17,1); 
      return;
}