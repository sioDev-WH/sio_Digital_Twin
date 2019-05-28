/*
*     C B L A S _ S A X P Y I  Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;
enum {nmax=20, ymax=20};

void GetInputParameter(FILE*, int*, float*);

void main(int argc, char *argv[])
{
      int        n;
      float      alpha;
      float      x[nmax], y[ymax];
      int        indx[nmax];

      int        indmax;

      printf("\n     C B L A S _ S A X P Y I  EXAMPLE PROGRAM\n");
      
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
      GetInputParameter(in_file, &n, &alpha);
      GetVectorS(in_file, n, x, 1);
      GetVectorI(in_file, n, indx);
      indmax = MaxValue(n, indx);
      GetVectorS(in_file, indmax, y, 1);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       N=%2d", n);
      printf("\n       ALPHA=%4.1f", alpha);
      PrintVectorS(1, n, x, 1, "X");
      PrintVectorI(n, indx, "INDX");
      PrintVectorS(1, indmax, y, 1, "Y");

/*      Call CBLAS_SAXPYI subroutine ( C Interface )            */
      cblas_saxpyi(n, alpha, x, indx, y);
                                                             
/*       Print output data                                     */
      printf("\n\n     OUTPUT DATA");
      PrintVectorS(1, indmax, y, 1, "Y");
end:  return;
}

void GetInputParameter(FILE *in_file, int *n, float *alpha)
{

/*     Read input data from input file  */
      fseek(in_file,48,0);
      fscanf(in_file,"%d", n);  
      fseek(in_file,19,1); 
      fscanf(in_file,"%f", alpha);  
      fseek(in_file,17,1);
      return;
}
