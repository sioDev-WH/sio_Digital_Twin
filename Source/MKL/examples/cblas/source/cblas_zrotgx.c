/*
*     C B L A S _ Z R O T G   Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;

void GetInputData(FILE*, MKL_Complex16*, MKL_Complex16*);

void main(int argc, char *argv[])
{
      double     c;
      MKL_Complex16   s, ca, cb;

      printf("\n     C B L A S _ Z R O T G  EXAMPLE PROGRAM\n");
      
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
      GetInputData(in_file, &ca, &cb);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       CA=(%5.2f,%5.2f )  CB=(%5.2f,%5.2f)",
               ca.real, ca.imag, cb.real, cb.imag);

/*      Call CBLAS_ZROTG subroutine ( C Interface )            */
      cblas_zrotg(&ca, &cb, &c, &s);
                                                             
/*       Print output data                                     */
      printf("\n\n     OUTPUT DATA");
      printf("\n       CA=(%6.3f,%6.3f)", ca.real, ca.imag);
      printf("\n        C= %6.3f          S=(%6.3f,%6.3f)", c, s.real,s.imag);
end:  return;
}

void GetInputData(FILE *in_file, MKL_Complex16 *ca, MKL_Complex16 *cb)
{

/*     Read input data from input file  */
      fseek(in_file,46,0);
      fscanf(in_file,"%lf %lf %lf %lf", &(ca->real), &(ca->imag),
             &(cb->real), &(cb->imag));
      fseek(in_file,21,1); 
      return;
}