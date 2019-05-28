/*
*     C B L A S _ D R O T I  Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;

enum {nmax=20, ymax=20};

void GetInputParameter(FILE*, int*, double*, double*);

void main(int argc, char *argv[])
{
      int        n;
      double     c, s;
      int        indx[nmax];
      double     x[nmax], y[ymax];

      int        indmax;

      printf("\n     C B L A S _ D R O T I  EXAMPLE PROGRAM\n");
      
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
      GetInputParameter(in_file, &n, &c, &s);
      GetVectorD(in_file, n, x, 1);
      GetVectorI(in_file, n, indx);
      indmax = MaxValue(n, indx);
      GetVectorD(in_file, indmax, y, 1);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       N=%d", n);
      printf("\n       C=%4.1f  S=%4.1f", c, s);
      PrintVectorD(1, n, x, 1, "X");
      PrintVectorI(n, indx, "INDX");
      PrintVectorD(1, indmax, y, 1, "Y");

/*      Call CBLAS_DROTI subroutine ( C Interface )            */
      cblas_droti(n, x, indx, y, c, s);
                                                             
/*       Print output data                                     */
      printf("\n\n     OUTPUT DATA");
      PrintVectorD(1, n, x, 1, "X");
      PrintVectorD(1, indmax, y, 1, "Y");
end:  return;
}

void GetInputParameter(FILE *in_file, int *n, double *c, double *s)
{

/*     Read input data from input file  */
      fseek(in_file,46,0);
      fscanf(in_file,"%d", n);  
      fseek(in_file,22,1); 
      fscanf(in_file,"%lf %lf", c, s);  
      fseek(in_file,17,1); 
      return;
}
