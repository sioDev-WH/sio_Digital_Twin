/*
*     C B L A S _ Z A X P Y I  Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;
enum {nmax=20, ymax=20};

void GetInputParameter(FILE*, int*, MKL_Complex16*);

void main(int argc, char *argv[])
{
      int        n;
      MKL_Complex16   alpha;
      MKL_Complex16   x[nmax], y[ymax];
      int        indx[nmax];

      int        indmax;

      printf("\n     C B L A S _ Z A X P Y I  EXAMPLE PROGRAM\n");
      
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
      GetVectorZ(in_file, n, x, 1);
      GetVectorI(in_file, n, indx);
      indmax = MaxValue(n, indx);
      GetVectorZ(in_file, indmax, y, 1);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       N=%d", n);
      printf("\n       ALPHA=(%4.1f,%4.1f)", alpha.real, alpha.imag);
      PrintVectorZ(1, n, x, 1, "X");
      PrintVectorI(n, indx, "INDX");
      PrintVectorZ(1, indmax, y, 1, "Y");

/*      Call CBLAS_ZAXPYI subroutine ( C Interface )            */
      cblas_zaxpyi(n, &alpha, x, indx, y);
                                                             
/*       Print output data                                     */
      printf("\n\n     OUTPUT DATA");
      PrintVectorZ(1, indmax, y, 1, "Y");
end:  return;
}

void GetInputParameter(FILE *in_file, int *n, MKL_Complex16 *alpha)
{

/*     Read input data from input file  */
      fseek(in_file,48,0);
      fscanf(in_file,"%d", n);  
      fseek(in_file,25,1); 
      fscanf(in_file,"%lf %lf", &(alpha->real), &(alpha->imag));  
      fseek(in_file,21,1);
      return;
}
