/*
*     C B L A S _ D R O T M G   Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;

void GetInputData(FILE*, double*, double*, double*, double*);

void main(int argc, char *argv[])
{
      double     param[5];
      double     dd1, dd2, dx1, dy1;

      printf("\n     C B L A S _ D R O T M G  EXAMPLE PROGRAM\n");
      
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
      GetInputData(in_file, &dd1, &dd2, &dx1, &dy1);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       DD1=%5.2f  DD2=%5.2f  DX1=%5.2f  DY1=%5.2f",
               dd1, dd2, dx1, dy1);

/*      Call CBLAS_DROTMG subroutine ( C Interface )            */
      cblas_drotmg(&dd1, &dd2, &dx1, &dy1, param);
                                                             
/*       Print output data                                     */
      printf("\n\n     OUTPUT DATA");
      printf("\n       DD1=%6.3f  DD2=%6.3f  DX1=%6.3f",
               dd1, dd2, dx1);
      PrintVectorD(1, 5, param, 1, "PARAM");
end:  return;
}

void GetInputData(FILE *in_file, double *dd1, double *dd2, double *dx1, double *dy1)
{

/*     Read input data from input file  */
      fseek(in_file,48,0);
      fscanf(in_file,"%lf %lf %lf %lf", dd1, dd2, dx1, dy1);  
      return;
}