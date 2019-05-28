/*
//     C S F F T 2 D C  Example Program Text
//     CopyRight 1999 Intel Corporation
*/
#include <stdio.h>
#include <math.h>

FILE *in_file;
char *in_file_name;

enum {row = 10, col = 6};  /* row = m+2, col = n+2 */

void GetInputData(FILE*, int*, int*, float*, int);

void main(int argc, char *argv[])
{
      int         m, n; 
      float       r[row][col], r0[row][col];
      float       temp;
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
      cblas_scopy(row*col, r, 1, r0, 1);

/*      Call CSFFT2DC subroutine     */
      CSFFT2DC(r, m, n);  

      printf("\n        C S F F T 2 D C  EXAMPLE PROGRAM");
      printf("\n\n       M=%d  N=%d", m, n);
      printf("\n\n       TWO-DIMENSIONAL COMPLEX SEQUENCE  Z(I,J)");
      for (i = 0; i < m/2+1; i++) {
          printf("\n       ");
              printf("(%6.3f,%6.3f)   ", r0[i][0], r0[m/2+1+i][0]);
          for (j = 1; j < n/2; j++)
              printf("(%6.3f,%6.3f)   ", r0[i][j], r0[i][n/2+1+j]);
          printf("(%6.3f,%6.3f)   ", r0[i][n/2], r0[m/2+1+i][n/2]);
          for (j = 1; j < n/2; j++) {
              temp = -r0[i][n+1-j];
              printf("(%6.3f,%6.3f)   ", r0[i][n/2-j], temp);
          } /* for */
      } /* for */
      for (i = 1; i < m/2; i++) {
          printf("\n       ");
          temp = -r0[m+1-i][0];
          printf("(%6.3f,%6.3f)   ", r0[m/2-i][0], temp);
          for (j = 1; j < n/2; j++)
              printf("(%6.3f,%6.3f)   ", r0[m/2+i][j], r0[m/2+i][n/2+1+j]);
          temp = -r0[m+1-i][n/2];
          printf("(%6.3f,%6.3f)   ", r0[m/2-i][n/2], temp);
          for (j = 1; j < n/2; j++) {
              temp = -r0[m/2+i][n+1-j];
              printf("(%6.3f,%6.3f)   ", r0[m/2+i][n/2-j], temp);
          } /* for */
      } /* for */
      printf("\n\n       INPUT ARRAY  R(I,J)");
      for (i = 0; i < m; i++) {
          printf("\n         ");
          for (j = 0; j < n+1; j++)
              printf("%6.3f   ", r0[i][j]);
      } /* for */
      printf("\n         %6.3f            %6.3f", r0[m][0], r0[m][n/2]); 
      printf("\n         %6.3f            %6.3f", r0[m+1][0], r0[m+1][n/2]); 
      printf("\n\n       OUTPUT ARRAY  R(I,J)");
      for (i = 0; i < m; i++) {
          printf("\n         ");
          for (j = 0; j < n; j++)
              printf("%6.3f   ", r[i][j]); 
      } /* for */
      printf("\n");
/*
     MKLEnd();
*/
end:  return;
}

void GetInputData(FILE *in_file, int *m, int *n, float *r, int col)
{
      int         i, j, indx;
      float       z_real, z_imag;

/*     Read input data from input file  */
      fseek(in_file,41,0);
      fscanf(in_file,"%2d %2d", m, n);
      fseek(in_file,24,1);
	  for (i = 0; i < (*m)/2+1; i++) {
          fscanf(in_file, "%f %f", &z_real, &z_imag);
          indx = i*col;
          r[indx] = z_real;
          r[((*m)/2+1+i)*col] = z_imag;
          for (j = 1; j < (*n)/2; j++) {
              fscanf(in_file, "%f %f", &z_real, &z_imag);
              r[indx+j] = z_real;
              r[indx+(*n)/2+1+j] = z_imag;
          } /* for */
          fscanf(in_file, "%f %f", &z_real, &z_imag);
          r[indx+(*n)/2] = z_real;
          r[((*m)/2+1+i)*col+(*n)/2] = z_imag;
          r[indx+(*n)/2+1] = 0.0;
      } /* for */
	  for (i = 1; i < (*m)/2; i++) {
          indx = ((*m)/2+i)*col;
          for (j = 1; j < (*n)/2; j++) {
              fscanf(in_file, "%f %f", &z_real, &z_imag);
              r[indx+j] = z_real;
              r[indx+(*n)/2+1+j] = z_imag;
          } /* for */
          r[indx+(*n)/2+1] = 0.0;
      } /* for */
      fclose(in_file);
      return;
}