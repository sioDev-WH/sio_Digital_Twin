/*
*     C B L A S _ S R O T M G   Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;

void GetInputData(FILE*, float*, float*, float*, float*);

void main(int argc, char *argv[])
{
      float      param[5];
      float      sd1, sd2, sx1, sy1;

      printf("\n     C B L A S _ S R O T M G  EXAMPLE PROGRAM\n");
      
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
      GetInputData(in_file, &sd1, &sd2, &sx1, &sy1);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       SD1=%5.2f  SD2=%5.2f  SX1=%5.2f  SY1=%5.2f",
               sd1, sd2, sx1, sy1);

/*      Call CBLAS_SROTMG subroutine ( C Interface )            */
      cblas_srotmg(&sd1, &sd2, &sx1, &sy1, param);
                                                             
/*       Print output data                                     */
      printf("\n\n     OUTPUT DATA");
      printf("\n       SD1=%5.2f  SD2=%5.2f  SX1=%5.2f",
               sd1, sd2, sx1);
      PrintVectorS(1, 5, param, 1, "PARAM");
end:  return;
}

void GetInputData(FILE *in_file, float *sd1, float *sd2, float *sx1, float *sy1)
{

/*     Read input data from input file  */
      fseek(in_file,48,0);
      fscanf(in_file,"%f %f %f %f", sd1, sd2, sx1, sy1);  
      fseek(in_file,33,1); 
      return;
}