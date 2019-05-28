/*
//     D Z F F T 2 D C  Example Program Text
//     CopyRight 1999 Intel Corporation
*/
#include <windows.h>
#include <stdio.h>
#include <math.h>

FILE *in_file;
char *in_file_name;

enum {row = 10, col = 6};  /* rmax = m+2, cmax = n+2 */

void GetInputData(FILE*, int*, int*, double*, int);

void main(int argc, char *argv[])
{
      int         m, n; 
      double      r[row][col], r0[row][col];
      double      temp;
      int         i, j;
/*                                
//    Executable Statementcs          
//                                
//    Get input parameters        

     MKLStart();
*/
      if (argc == 1) {
         printf("\n You must specify in_file data file as 1-st parameter");
         goto end;
      } /* if */
      in_file_name = argv[1];

      if( (in_file = fopen( in_file_name, "r" )) == NULL ) {     
         printf("\nERROR on OPEN '%s' with mode=%s\n", in_file_name, "r");            
         goto end;
      } /* if */
      GetInputData(in_file, &m, &n, &r[0][0], col);
      fclose(in_file);
      cblas_dcopy(row*col, r, 1, r0, 1);

/*      Call DZFFT2DC subroutine     */
      DZFFT2DC(r, m, n);  

      printf("\n        D Z F F T 2 D C  EXAMPLE PROGRAM");
      printf("\n\n       M=%d  N=%d", m, n);
      printf("\n\n       INPUT ARRAY  R(I,J)");
      for (i = 0; i < m; i++) {
          printf("\n         ");
          for (j = 0; j < n; j++)
              printf("%6.3f  ", r0[i][j]);
      } /* for */
      printf("\n\n       OUTPUT ARRAY  R(I,J)");
      for (i = 0; i < m; i++) {
          printf("\n         ");
          for (j = 0; j < n; j++)
              printf("%6.3f  ", r[i][j]);
      } /* for */
      printf("\n         %6.3f  ", r[m][0]);
      for (j = 1; j < n/2; j++)
          printf("        ");
      printf("%6.3f", r[m][n/2]);
      printf("\n         %6.3f  ", r[m+1][0]);
      for (j = 1; j < n/2; j++)
          printf("        ");
      printf("%6.3f", r[m+1][n/2]);
      printf("\n\n       MATHEMATICAL RESULT  Z(I,J)");
      for (i = 0; i < m/2+1; i++) {
          printf("\n       ");
              printf("(%6.3f,%6.3f)   ", r[i][0], r[m/2+1+i][0]);
          for (j = 1; j < n/2; j++)
              printf("(%6.3f,%6.3f)   ", r[i][j], r[i][n/2+1+j]);
          printf("(%6.3f,%6.3f)   ", r[i][n/2], r[m/2+1+i][n/2]);
          for (j = 1; j < n/2; j++) {
              temp = -r[i][n+1-j];
              printf("(%6.3f,%6.3f)   ", r[i][n/2-j], temp);
          } /* for */
      } /* for */
      for (i = 1; i < m/2; i++) {
          printf("\n       ");
          temp = -r[m+1-i][0];
          printf("(%6.3f,%6.3f)   ", r[m/2-i][0], temp);
          for (j = 1; j < n/2; j++)
              printf("(%6.3f,%6.3f)   ", r[m/2+i][j], r[m/2+i][n/2+1+j]);
          temp = -r[m+1-i][n/2];
          printf("(%6.3f,%6.3f)   ", r[m/2-i][n/2], temp);
          for (j = 1; j < n/2; j++) {
              temp = -r[m/2+i][n+1-j];
              printf("(%6.3f,%6.3f)   ", r[m/2+i][n/2-j], temp);
          } /* for */
      } /* for */
      printf("\n");
/*
     MKLEnd();
*/
end:  return;
}

void GetInputData(FILE *in_file, int *m, int *n, double *r, int col)
{
      int          i, j, indx;

/*     Read input data from input file  */
      fseek(in_file,41,0);
      fscanf(in_file,"%2d %2d", m, n);
      fseek(in_file,28,1);
      fclose(in_file);
      
      for (i = 0; i < (*m); i++) {
          indx = i*col;
          for (j = 0; j < (*n); j++)
              r[indx+j] = ((double)rand())/((double)RAND_MAX) - 0.5;
      } /* for */
      return;
}

