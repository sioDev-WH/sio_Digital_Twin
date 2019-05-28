/*
*     C B L A S _ Z A X P Y   Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;
enum {xmax=20, ymax=20};

void GetInputData(FILE*, int*, int*, int*, MKL_Complex16*);

void main(int argc, char *argv[])
{
      int        n, incx, incy;
      MKL_Complex16   alpha;
      MKL_Complex16   x[xmax], y[ymax];

      printf("\n     C B L A S _ Z A X P Y  EXAMPLE PROGRAM\n");
      
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
	  GetVectorZ(in_file, n, x, incx);
      GetVectorZ(in_file, n, y, incy);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       N=%d", n);
      printf("\n       ALPHA=(%4.1f,%4.1f )", alpha.real, alpha.imag);
      PrintVectorZ(0, n, x, incx, "X");
      PrintVectorZ(0, n, y, incy, "Y");

/*      Call CBLAS_ZAXPY subroutine ( C Interface )            */
      cblas_zaxpy(n, &alpha, x, incx, y, incy);
                                                             
/*       Print output data                                     */
      printf("\n\n     OUTPUT DATA");
      PrintVectorZ(1, n, y, incy, "Y");
end:  return;
}

void GetInputData(FILE *in_file, int *n, int *incx, int *incy,
                  MKL_Complex16 *alpha)
{

/*     Read input data from input file  */
      fseek(in_file,46,0);
      fscanf(in_file,"%d", n);  
      fseek(in_file,24,1); 
      fscanf(in_file,"%2d %2d", incx, incy);  
      fseek(in_file,29,1); 
      fscanf(in_file,"%lf %lf", &(alpha->real), &(alpha->imag));  
      fseek(in_file,21,1); 
      return;
}