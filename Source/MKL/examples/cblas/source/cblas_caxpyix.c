/*
*     C B L A S _ C A X P Y I  Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;
enum {nmax=20, ymax=20};

void GetInputParameter(FILE*, int*, MKL_Complex8*);

void main(int argc, char *argv[])
{
      int        n;
      MKL_Complex8    alpha;
      MKL_Complex8    x[nmax], y[ymax];
      int        indx[nmax];

      int        indmax;

      printf("\n     C B L A S _ C A X P Y I  EXAMPLE PROGRAM\n");
      
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
      GetVectorC(in_file, n, x, 1);
      GetVectorI(in_file, n, indx);
      indmax = MaxValue(n, indx);
      GetVectorC(in_file, indmax, y, 1);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       N=%2d", n);
      printf("\n       ALPHA=(%4.1f,%4.1f)", alpha.real, alpha.imag);
      PrintVectorC(1, n, x, 1, "X");
      PrintVectorI(n, indx, "INDX");
      PrintVectorC(1, indmax, y, 1, "Y");

/*      Call CBLAS_CAXPYI subroutine ( C Interface )            */
      cblas_caxpyi(n, &alpha, x, indx, y);
                                                             
/*       Print output data                                     */
      printf("\n\n     OUTPUT DATA");
      PrintVectorC(1, indmax, y, 1, "Y");
end:  return;
}

void GetInputParameter(FILE *in_file, int *n, MKL_Complex8 *alpha)
{

/*     Read input data from input file  */
      fseek(in_file,48,0);
      fscanf(in_file,"%d", n);  
      fseek(in_file,25,1); 
      fscanf(in_file,"%f %f", &(alpha->real), &(alpha->imag));  
      fseek(in_file,21,1);
      return;
}
