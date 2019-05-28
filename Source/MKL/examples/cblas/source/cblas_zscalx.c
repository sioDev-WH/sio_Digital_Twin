/*
*     C B L A S _ Z S C A L   Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;
enum {xmax=20, ymax=20};

void GetInputData(FILE*, int*, int*, MKL_Complex16*);

void main(int argc, char *argv[])
{
      int        n, incx;
      MKL_Complex16   za;
      MKL_Complex16   x[xmax];

      printf("\n     C B L A S _ Z S C A L  EXAMPLE PROGRAM\n");
      
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
      GetInputData(in_file, &n, &incx, &za);
	  GetVectorZ(in_file, n, x, incx);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       N=%2d", n);
      printf("\n       ZA=(%5.2f,%5.2f )", za.real, za.imag);
      PrintVectorZ(0, n, x, incx, "X");

/*      Call CBLAS_ZSCAL subroutine ( C Interface )            */
      cblas_zscal(n, &za, x, incx);
                                                             
/*       Print output data                                     */
      printf("\n\n     OUTPUT DATA");
      PrintVectorZ(1, n, x, incx, "X");
end:  return;
}

void GetInputData(FILE *in_file, int *n, int *incx, 
                  MKL_Complex16 *za)
{

/*     Read input data from input file  */
      fseek(in_file,46,0);
      fscanf(in_file,"%d %2d", n, incx);  
      fseek(in_file,27,1); 
      fscanf(in_file,"%lf %lf", &(za->real), &(za->imag));  
      fseek(in_file,18,1); 
      return;
}