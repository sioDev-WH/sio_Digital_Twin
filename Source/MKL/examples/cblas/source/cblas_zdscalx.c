/*
*     C B L A S _ Z D S C A L   Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;
enum {xmax=20, ymax=20};

void GetInputData(FILE*, int*, int*, double*);

void main(int argc, char *argv[])
{
      int        n, incx;
      double     da;
      MKL_Complex16   x[xmax];

      printf("\n     C B L A S _ Z D S C A L  EXAMPLE PROGRAM\n");
      
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
      GetInputData(in_file, &n, &incx, &da);
	  GetVectorZ(in_file, n, x, incx);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       N=%2d", n);
      printf("\n       DA=%5.2f", da);
      PrintVectorZ(0, n, x, incx, "X");

/*      Call CBLAS_ZDSCAL subroutine ( C Interface )            */
      cblas_zdscal(n, da, x, incx);
                                                             
/*       Print output data                                     */
      printf("\n\n     OUTPUT DATA");
      PrintVectorZ(1, n, x, incx, "X");
end:  return;
}

void GetInputData(FILE *in_file, int *n, int *incx, double *da)
{

/*     Read input data from input file  */
      fseek(in_file,48,0);
      fscanf(in_file,"%d %2d", n, incx);  
      fseek(in_file,27,1); 
      fscanf(in_file,"%lf", da);  
      fseek(in_file,23,1); 
      return;
}