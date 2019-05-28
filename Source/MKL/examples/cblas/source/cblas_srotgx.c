/*
*     C B L A S _ S R O T G   Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;

void GetInputData(FILE*, float*, float*);

void main(int argc, char *argv[])
{
      float      c, s;
      float      sa, sb;

      printf("\n     C B L A S _ S R O T G  EXAMPLE PROGRAM\n");
      
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
      GetInputData(in_file, &sa, &sb);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       SA=%5.2f  SB=%5.2f", sa, sb);

/*      Call CBLAS_SROTG subroutine ( C Interface )            */
      cblas_srotg(&sa, &sb, &c, &s);
                                                             
/*       Print output data                                     */
      printf("\n\n     OUTPUT DATA");
      printf("\n       SA=%6.3f  SB=%6.3f", sa, sb);
      printf("\n        C=%6.3f   S=%6.3f", c, s);
end:  return;
}

void GetInputData(FILE *in_file, float *sa, float *sb)
{

/*     Read input data from input file  */
      fseek(in_file,46,0);
      fscanf(in_file,"%f %f", sa, sb);  
      fseek(in_file,21,1); 
      return;
}