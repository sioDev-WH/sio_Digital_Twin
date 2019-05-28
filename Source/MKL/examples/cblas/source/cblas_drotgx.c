/*
*     C B L A S _ D R O T G   Example Program Text ( C Interface )
*     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>

#include "mkl_example.h"

FILE *in_file;
char *in_file_name;

void GetInputData(FILE*, double*, double*);

void main(int argc, char *argv[])
{
      double     c, s;
      double     da, db;

      printf("\n     C B L A S _ D R O T G  EXAMPLE PROGRAM\n");
      
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
      GetInputData(in_file, &da, &db);
      fclose(in_file);

/*       Print input data                                      */
      printf("\n     INPUT DATA");
      printf("\n       DA=%6.3f  DB=%6.3f", da, db);

/*      Call CBLAS_DROTG subroutine ( C Interface )            */
      cblas_drotg(&da, &db, &c, &s);
                                                             
/*       Print output data                                     */
      printf("\n\n     OUTPUT DATA");
      printf("\n       DA=%6.3f  DB=%6.3f", da, db);
      printf("\n        C=%6.3f   S=%6.3f", c, s);
end:  return;
}

void GetInputData(FILE *in_file, double *da, double *db)
{

/*     Read input data from input file  */
      fseek(in_file,46,0);
      fscanf(in_file,"%lf %lf", da, db);  
      fseek(in_file,19,1); 
      return;
}