/*
*     C B L A S _ D S C T R  Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;

enum {nmax=20, ymax=20};

void GetInputParameter(FILE*, int*);

void main(int argc, char *argv[])
{
      int        n;
      int        indx[nmax];
      double     x[nmax], y[ymax];

      int        indmax;

      printf("\n     C B L A S _ D S C T R  EXAMPLE PROGRAM\n");
      
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
      GetInputParameter(in_file, &n);
      GetVectorD(in_file, n, x, 1);
      GetVectorI(in_file, n, indx);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       N=%d", n);
      PrintVectorD(1, n, x, 1, "X");
      PrintVectorI(n, indx, "INDX");

/*      Call CBLAS_DSCTR subroutine ( C Interface )            */
      cblas_dsctr(n, x, indx, y);
                                                             
/*       Print output data                                     */
      printf("\n\n     OUTPUT DATA");
      indmax = MaxValue(n, indx);
      PrintVectorD(1, indmax, y, 1, "Y");
end:  return;
}

void GetInputParameter(FILE *in_file, int *n)
{

/*     Read input data from input file  */
      fseek(in_file,46,0);
      fscanf(in_file,"%d", n);  
      fseek(in_file,20,1); 
      return;
}
